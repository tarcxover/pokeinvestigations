	@ Places the evidence item in VAR_RESULT
	.macro evidencetoitem evidence:req
	callnative ScrCmd_evidencetoitem
	.2byte \evidence
	.endm

	.macro giveevidence evidence:req
	evidencetoitem \evidence
	copyvar VAR_0x8004, VAR_RESULT
	checkitem VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE 2f
	giveitem VAR_0x8004
2:
	.endm

	.macro checkevidence evidence:req
	evidencetoitem \evidence
	checkitem VAR_RESULT
	.endm

	.macro getdeduction premise1:req, premise2:req
	callnative ScrCmd_getdeduction
	.2byte \premise1
	.2byte \premise2
	.endm

	.macro trydeduction premise1:req, premise2:req
	getdeduction \premise1, \premise2
	compare VAR_RESULT, EVD_COUNT
	goto_if_eq 1f
	giveevidence VAR_RESULT
	setvar VAR_RESULT, TRUE
	goto 2f
1:
	setvar VAR_RESULT, FALSE
2:
	.endm

  .macro getheldevidencecount
	  callnative ScrCmd_getheldevidencecount
  .endm

  .macro getevidenceatpos pos:req
	callnative ScrCmd_getevidenceatpos
	.2byte \pos
  .endm

  .macro dynmultipushheldevidence
	callnative ScrCmd_dynmultipushheldevidence, requests_effects=1
  .endm

  .macro overridetodblend hours:req, minutes=0
	callnative ScrCmd_overridetodblend
	.byte \hours
	.byte \minutes
  .endm

  .macro restoretodblend
	callnative ScrCmd_restoretodblend
  .endm

  .macro getaccuseevidence slot:req
	callnative ScrCmd_getaccuseevidence
	.byte \slot
  .endm

  .macro openaccusemenu question:req, suspect:req
	callnative ScrCmd_openaccusemenu
	.byte \question
	.byte \suspect
  .endm

  .macro createprogressbar id:req
	callnative ScrCmd_createprogressbar
	.byte \id
  .endm

  .macro destroyprogressbar
	callnative ScrCmd_destroyprogressbar
  .endm

  .macro showcredits cb=CB2_ReturnToFieldContinueScriptPlayMapMusic
	callnative ScrCmd_showcredits
	.4byte \cb
  .endm
