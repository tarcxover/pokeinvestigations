#include "global.h"
#include "assertf.h"
#include "constants/characters.h"
#include "constants/evidence.h"
#include "constants/evidence_macros.h"
#include "constants/item.h"
#include "constants/items.h"
#include "event_data.h"
#include "evidence.h"
#include "gba/isagbprint.h"
#include "item.h"
#include "list_menu.h"
#include "malloc.h"
#include "script.h"
#include "script_menu.h"
#include "string_util.h"
#include "test/battle.h"
#include <stdint.h>

#define PREMISE_KEY(a, b)            \
    ({                               \
        u16 _a = (a);                \
        u16 _b = (b);                \
        if (_a > _b)                 \
            Swap(_a, _b);            \
        (((u32)_a << 16) | (u32)_b); \
    })

#define R_SUSPECT_LIST(...) R_FOR_EACH(_SUSPECT_HELPER, __VA_ARGS__)
#define SUSPECT_ARRAY_HELPER(_id, _name, _description, _details, _icon, _suspect,...) \
    const enum Suspects CAT(M_GET_LAST(__VA_ARGS__), SuspectArr[]) = {RECURSIVELY(R_SUSPECT_LIST(UNPACK_B(_suspect))) SUSPECT_COUNT};

#define R_QUESTION_LIST(...) R_FOR_EACH(_QUESTION_HELPER, __VA_ARGS__)
#define QUESTION_ARRAY_HELPER(_id, _name, _description, _details, _icon, _suspect, _question,...) \
    const enum Questions CAT(M_GET_LAST(__VA_ARGS__), QuestionArr[]) = {RECURSIVELY(R_QUESTION_LIST(UNPACK_B(_question))) QUESTION_COUNT};

#define _QUESTION_TEXT_HELPER(id, text) case QUESTION_##id: return text;

#define R_QUESTION_TEXT(...) R_FOR_EACH(_QUESTION_TEXT_HELPER, __VA_ARGS__)

FOREACH_EVIDENCE(SUSPECT_ARRAY_HELPER)
FOREACH_EVIDENCE(QUESTION_ARRAY_HELPER)

// Generates gEvidence from an X-Macro table
#define _GEVD_HELPER(id, _name, desc, det, _icon, s, q, _score, ...) \
    [EVD(id)] = {                                                    \
        .name = _name,                                               \
        .description = desc,                                         \
        .details = det,                                              \
        .itemId = EVD_ITEM(id),                                      \
        .suspects = CAT(M_GET_LAST(__VA_ARGS__), SuspectArr),        \
        .questions = CAT(M_GET_LAST(__VA_ARGS__), QuestionArr),      \
        .score = _score,                                             \
    },
const struct EvidenceInfo gEvidence[EVD_COUNT] = {
    FOREACH_EVIDENCE(_GEVD_HELPER)
};
#undef _GEVD_HELPER

// Generates gDeductions from an X-Macro table
#define _PREMISES_HELPER(x) APPEND_COMMA(EVD(x))
#define _PREMISES(...) RECURSIVELY(R_FOR_EACH(_PREMISES_HELPER, __VA_ARGS__))
#define _GDED_HELPER(c, ...)         \
    {.premises =                     \
         {                           \
             _PREMISES(__VA_ARGS__)  \
         },                          \
     .conclusion = EVD(c)},

const struct DeductionInfo gDeductions[DEDUCTION_COUNT] = {
    FOREACH_DEDUCTION(_GDED_HELPER)
};
#undef _PREMISES_HELPER
#undef _PREMISES
#undef _GDED_HELPER

const enum Item EvidenceToItem[EVD_COUNT] = {
    FOREACH_EVIDENCE(_EVD_TO_ITEM_HELPER)
};

enum Evidence GetDeduction(enum Evidence p1, enum Evidence p2)
{
    assertf(p1 != p2, "p1 (%d) is equal to p2 (%d)", p1, p2) { return EVD_COUNT; }
    u32 key = PREMISE_KEY(p1, p2);
    for (u32 i = 0; i < NELEMS(gDeductions); i++)
    {
        const struct DeductionInfo *d = &gDeductions[i];
        u32 candidate = PREMISE_KEY(d->premises[0], d->premises[1]);
        if (key == candidate)
            return d->conclusion;
    }
    return EVD_COUNT;
}

void Debug_EvidenceGetAll(void)
{
    for (enum Item itemId = ITEM_EVIDENCE_START; itemId < ITEM_EVIDENCE_START + EVD_COUNT; itemId++)
    {
        if (CheckBagHasSpace(itemId, 1))
            AddBagItem(itemId, 1);
    }
}

u32 GetHeldEvidenceCount(void)
{
    struct BagPocket *pocket = &gBagPockets[POCKET_EVIDENCE];
    u8 usedSlots = 0;

    for (u32 i = 0; i < pocket->capacity; i++)
    {
        if (BagPocket_GetSlotData(pocket, i).itemId != ITEM_NONE)
            usedSlots++;
    }
    return usedSlots;
}

void PushEvidenceToDynMultiStack()
{
    u32 count = GetHeldEvidenceCount();

    for (u32 pos = 0; pos < count; pos++)
    {
        enum Item itemId = GetBagItemId(POCKET_EVIDENCE, pos);
        u8* nameBuffer = Alloc(100);
        StringExpandPlaceholders(nameBuffer, GetItemName(itemId));
        struct ListMenuItem res = {nameBuffer, itemId};
        MultichoiceDynamic_PushElement(res);
    }
}

bool32 EvidenceAnswersQuestion(enum Evidence e, enum Questions q)
{
    for (const enum Questions *questions = gEvidence[e].questions; *questions != QUESTION_COUNT; questions++)
    {
        if (*questions == q)
            return TRUE;
    }
    return FALSE;
}

const u8* GetQuestionText(enum Questions q)
{
    switch (q) {
        FOREACH_QUESTION(_QUESTION_TEXT_HELPER)
        default:
            return COMPOUND_STRING("Who did it?");
    }
}


const u8* GetSuspectText(enum Suspects s)
{
    switch (s) {
        case SUSPECT_TAKESHI:
            return  COMPOUND_STRING("Accuse Takeshi");
        case SUSPECT_ICHIRO:
            return  COMPOUND_STRING("Accuse Ichiro");
        default:
            return COMPOUND_STRING("");
    }
}

bool32 ScrCmd_evidencetoitem(struct ScriptContext *ctx)
{
    enum Evidence evd = VarGet(ScriptReadHalfword(ctx));
    fatal_assertf(evd < EVD_COUNT);
    gSpecialVar_Result = gEvidence[evd].itemId;
    return FALSE;
}

bool32 ScrCmd_getdeduction(struct ScriptContext *ctx)
{
    enum Evidence p1 = ScriptReadHalfword(ctx);
    enum Evidence p2 = ScriptReadHalfword(ctx);
    enum Evidence c = GetDeduction(p1, p2);
    gSpecialVar_Result = c;
    return FALSE;
}

bool32 ScrCmd_getheldevidencecount(struct ScriptContext *ctx)
{
    gSpecialVar_Result = GetHeldEvidenceCount();
    return FALSE;
}

bool32 ScrCmd_bufferevidencecount(struct ScriptContext *ctx)
{
    u8 *dest = ConvertIntToDecimalStringN(gStringVar1, GetHeldEvidenceCount(), STR_CONV_MODE_LEFT_ALIGN, 3);
    *dest++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(dest, EVD_COUNT, STR_CONV_MODE_LEFT_ALIGN, 3);
    return FALSE;
}

bool32 ScrCmd_getevidenceatpos(struct ScriptContext *ctx)
{
    u32 pos = VarGet(ScriptReadHalfword(ctx));
    enum Item itemId = GetBagItemId(POCKET_EVIDENCE, pos);
    assertf(itemId > ITEM_EVIDENCE_START && itemId < ITEM_EVIDENCE_START + EVD_COUNT)
    {
        gSpecialVar_Result = UINT8_MAX;
        return FALSE;
    }
    gSpecialVar_Result = itemId - ITEM_EVIDENCE_START;
    return FALSE;
}

bool32 ScrCmd_dynmultipushheldevidence(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    PushEvidenceToDynMultiStack();
    return FALSE;
}

bool32 ScrCmd_getaccuseevidence(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    u32 slot = ScriptReadByte(ctx);
    gSpecialVar_Result = gAccuseEvidence[slot];
    return FALSE;
}
