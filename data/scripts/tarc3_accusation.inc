tarc3_Accusation_EventScript_Begin::
# 2 "data/scripts/tarc3_accusation.pory"
	lockall
# 3 "data/scripts/tarc3_accusation.pory"
	hidefollower
# 4 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACT3, TARC3_ACT3_ACCUSATION
# 5 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSED, 0
# 6 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ENDING, 0
# 7 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_T3, 0
# 8 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_HITS, 0
# 9 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_SCORE, 0
# 10 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_QSCORE, 0
# 11 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_SLOT, 0
# 12 "data/scripts/tarc3_accusation.pory"
	clearflag FLAG_TARC3_ACCUSE_CRUMBS
# 13 "data/scripts/tarc3_accusation.pory"
	clearflag FLAG_TARC3_ACCUSE_HISTORY
# 14 "data/scripts/tarc3_accusation.pory"
	playbgm MUS_LOGIC, TRUE
# 15 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_TakeTheFloor
# 16 "data/scripts/tarc3_accusation.pory"
	delay 20
# 17 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 18 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Begin_Text_1
# 19 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 20 "data/scripts/tarc3_accusation.pory"
	closemessage
# 21 "data/scripts/tarc3_accusation.pory"
	delay 20
# 22 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Naming
	return


tarc3_Accusation_EventScript_TakeTheFloor::
# 26 "data/scripts/tarc3_accusation.pory"
	special StorePlayerCoordsInVars
# 27 "data/scripts/tarc3_accusation.pory"
	compare VAR_0x8005, 7
	goto_if_eq tarc3_Accusation_EventScript_TakeTheFloor_2
# 30 "data/scripts/tarc3_accusation.pory"
	applymovement OBJ_EVENT_ID_PLAYER, tarc3_Accusation_EventScript_TakeTheFloor_Movement_1
tarc3_Accusation_EventScript_TakeTheFloor_1:
# 32 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
	return

tarc3_Accusation_EventScript_TakeTheFloor_2:
# 28 "data/scripts/tarc3_accusation.pory"
	applymovement OBJ_EVENT_ID_PLAYER, tarc3_Accusation_EventScript_TakeTheFloor_Movement_0
	goto tarc3_Accusation_EventScript_TakeTheFloor_1


tarc3_Accusation_EventScript_Naming::
# 37 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 38 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Naming_Text_1
# 39 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Naming_Text_2
# 40 "data/scripts/tarc3_accusation.pory"
	closemessage
# 41 "data/scripts/tarc3_accusation.pory"
	delay 20
# 42 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_NameMenu
	return


tarc3_Accusation_EventScript_NameMenu::
# 46 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 47 "data/scripts/tarc3_accusation.pory"
	message tarc3_Accusation_EventScript_NameMenu_Text_0
# 48 "data/scripts/tarc3_accusation.pory"
	waitmessage
# 49 "data/scripts/tarc3_accusation.pory"
	dynmultipush tarc3_Accusation_EventScript_NameMenu_Text_1, 1
# 50 "data/scripts/tarc3_accusation.pory"
	dynmultipush tarc3_Accusation_EventScript_NameMenu_Text_2, 2
# 51 "data/scripts/tarc3_accusation.pory"
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 52 "data/scripts/tarc3_accusation.pory"
	closemessage
# 53 "data/scripts/tarc3_accusation.pory"
	compare VAR_RESULT, 2
	goto_if_eq tarc3_Accusation_EventScript_NameMenu_2
tarc3_Accusation_EventScript_NameMenu_1:
# 61 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 62 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameMenu_Text_4, MSGBOX_YESNO
# 63 "data/scripts/tarc3_accusation.pory"
	closemessage
# 64 "data/scripts/tarc3_accusation.pory"
	compare VAR_RESULT, NO
	goto_if_eq tarc3_Accusation_EventScript_NameMenu_5
tarc3_Accusation_EventScript_NameMenu_4:
# 67 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_NameIchiro
	return

tarc3_Accusation_EventScript_NameMenu_2:
# 54 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameMenu_Text_3, MSGBOX_YESNO
# 55 "data/scripts/tarc3_accusation.pory"
	closemessage
# 56 "data/scripts/tarc3_accusation.pory"
	compare VAR_RESULT, NO
	goto_if_eq tarc3_Accusation_EventScript_NameMenu_8
tarc3_Accusation_EventScript_NameMenu_7:
# 59 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_NameTakeshi
	goto tarc3_Accusation_EventScript_NameMenu_1

tarc3_Accusation_EventScript_NameMenu_5:
# 65 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_NameMenu
	goto tarc3_Accusation_EventScript_NameMenu_4

tarc3_Accusation_EventScript_NameMenu_8:
# 57 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_NameMenu
	goto tarc3_Accusation_EventScript_NameMenu_7


tarc3_Accusation_EventScript_NameIchiro::
# 71 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
# 72 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 73 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_0
# 74 "data/scripts/tarc3_accusation.pory"
	closemessage
# 75 "data/scripts/tarc3_accusation.pory"
	playse SE_PIN
# 76 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_JOJI, tarc3_Accusation_EventScript_NameIchiro_Movement_0
# 77 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 78 "data/scripts/tarc3_accusation.pory"
	delay 5
# 79 "data/scripts/tarc3_accusation.pory"
	playse SE_PIN
# 80 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_MARIKO, tarc3_Accusation_EventScript_NameIchiro_Movement_0
# 81 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 82 "data/scripts/tarc3_accusation.pory"
	delay 20
# 83 "data/scripts/tarc3_accusation.pory"
	playse SE_PIN
# 84 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_KITARO, tarc3_Accusation_EventScript_NameIchiro_Movement_0
# 85 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 86 "data/scripts/tarc3_accusation.pory"
	delay 60
# 87 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 88 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_2
# 89 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 90 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_4
# 91 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_5
# 92 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_6
# 93 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 94 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 95 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_8
# 96 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 97 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_9
# 98 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 99 "data/scripts/tarc3_accusation.pory"
	closemessage
# 100 "data/scripts/tarc3_accusation.pory"
	delay 30
# 101 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q1
	return


tarc3_Accusation_EventScript_NameTakeshi::
# 105 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
# 106 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 107 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_0
# 108 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 109 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_1
# 110 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 111 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_3
# 112 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_4
# 113 "data/scripts/tarc3_accusation.pory"
	closemessage
# 114 "data/scripts/tarc3_accusation.pory"
	delay 30
# 115 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_OpenCloset
# 116 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 117 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_5
# 118 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_6
# 119 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_7
# 120 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 121 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_8
# 122 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 123 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameTakeshi_Text_9
# 124 "data/scripts/tarc3_accusation.pory"
	delay 30
# 125 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q1
	return


tarc3_Accusation_EventScript_OpenCloset::
# 129 "data/scripts/tarc3_accusation.pory"
	playse SE_DOOR
# 130 "data/scripts/tarc3_accusation.pory"
	clearflag FLAG_HIDE_TARC3_CABIN_TAKESHI
# 131 "data/scripts/tarc3_accusation.pory"
	addobject LOCALID_CABINS_TAKESHI_CLOSET
# 132 "data/scripts/tarc3_accusation.pory"
	delay 30
# 133 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_OpenCloset_Movement_0
# 134 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 135 "data/scripts/tarc3_accusation.pory"
	delay 30
# 136 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_TAKESHI_CLOSET, tarc3_Accusation_EventScript_OpenCloset_Movement_1
# 137 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 138 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_OpenCloset_Movement_2
# 139 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 140 "data/scripts/tarc3_accusation.pory"
	delay 20
	return


tarc3_Accusation_EventScript_ReadSlot::
# 145 "data/scripts/tarc3_accusation.pory"
	switch VAR_TARC3_ACCUSE_SLOT
# 146 "data/scripts/tarc3_accusation.pory"
	case 0, tarc3_Accusation_EventScript_ReadSlot_3
# 148 "data/scripts/tarc3_accusation.pory"
	case 1, tarc3_Accusation_EventScript_ReadSlot_4
# 150 "data/scripts/tarc3_accusation.pory"
	case 2, tarc3_Accusation_EventScript_ReadSlot_5
# 152 "data/scripts/tarc3_accusation.pory"
	case 3, tarc3_Accusation_EventScript_ReadSlot_6
tarc3_Accusation_EventScript_ReadSlot_1:
	return

tarc3_Accusation_EventScript_ReadSlot_3:
# 147 "data/scripts/tarc3_accusation.pory"
	getaccuseevidence 0
	goto tarc3_Accusation_EventScript_ReadSlot_1

tarc3_Accusation_EventScript_ReadSlot_4:
# 149 "data/scripts/tarc3_accusation.pory"
	getaccuseevidence 1
	goto tarc3_Accusation_EventScript_ReadSlot_1

tarc3_Accusation_EventScript_ReadSlot_5:
# 151 "data/scripts/tarc3_accusation.pory"
	getaccuseevidence 2
	goto tarc3_Accusation_EventScript_ReadSlot_1

tarc3_Accusation_EventScript_ReadSlot_6:
# 153 "data/scripts/tarc3_accusation.pory"
	getaccuseevidence 3
	goto tarc3_Accusation_EventScript_ReadSlot_1


tarc3_Accusation_EventScript_Q1::
# 159 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 160 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1_Text_0
# 161 "data/scripts/tarc3_accusation.pory"
	closemessage
# 162 "data/scripts/tarc3_accusation.pory"
	delay 20
# 163 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_QSCORE, 0
# 164 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_SLOT, 0
# 165 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Q1_2
# 168 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_GOZO, SUSPECT_ICHIRO
tarc3_Accusation_EventScript_Q1_1:
# 170 "data/scripts/tarc3_accusation.pory"
	waitstate
# 171 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q1Loop
	return

tarc3_Accusation_EventScript_Q1_2:
# 166 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_GOZO, SUSPECT_TAKESHI
	goto tarc3_Accusation_EventScript_Q1_1


tarc3_Accusation_EventScript_Q1Loop::
# 175 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_SLOT, 4, tarc3_Accusation_EventScript_Q1Summary
# 176 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_ReadSlot
# 177 "data/scripts/tarc3_accusation.pory"
	switch VAR_RESULT
# 178 "data/scripts/tarc3_accusation.pory"
	case EVD_TWIN_REFUSAL, tarc3_Accusation_EventScript_Q1Loop_3
# 180 "data/scripts/tarc3_accusation.pory"
	case EVD_UNREQUITED_LOVE, tarc3_Accusation_EventScript_Q1Loop_4
# 182 "data/scripts/tarc3_accusation.pory"
	case EVD_SPONSORSHIP_WITHDRAWAL, tarc3_Accusation_EventScript_Q1Loop_5
# 184 "data/scripts/tarc3_accusation.pory"
	case EVD_ARTIST_AT_THE_DOOR, tarc3_Accusation_EventScript_Q1Loop_6
# 186 "data/scripts/tarc3_accusation.pory"
	case EVD_GOZOS_FINAL_MEETING, tarc3_Accusation_EventScript_Q1Loop_7
# 188 "data/scripts/tarc3_accusation.pory"
	case EVD_TAKESHIS_REVENGE, tarc3_Accusation_EventScript_Q1Loop_8
# 190 "data/scripts/tarc3_accusation.pory"
	case EVD_SKETCHBOOK, tarc3_Accusation_EventScript_Q1Loop_9
# 192 "data/scripts/tarc3_accusation.pory"
	case EVD_REFUSED_SUITOR, tarc3_Accusation_EventScript_Q1Loop_10
# 194 "data/scripts/tarc3_accusation.pory"
	case EVD_TUITION_FUNDS, tarc3_Accusation_EventScript_Q1Loop_11
# 196 "data/scripts/tarc3_accusation.pory"
	case EVD_ICHIRO_SPONSORSHIP, tarc3_Accusation_EventScript_Q1Loop_12
# 198 "data/scripts/tarc3_accusation.pory"
	case EVD_BREAD_ERASER, tarc3_Accusation_EventScript_Q1Loop_13
# 200 "data/scripts/tarc3_accusation.pory"
	case EVD_TAKESHIS_MEETING, tarc3_Accusation_EventScript_Q1Loop_14
# 202 "data/scripts/tarc3_accusation.pory"
	case EVD_TAKESHIS_HISTORY, tarc3_Accusation_EventScript_Q1Loop_15
# 204 "data/scripts/tarc3_accusation.pory"
	case EVD_FAMILY_PICTURE, tarc3_Accusation_EventScript_Q1Loop_16
# 206 "data/scripts/tarc3_accusation.pory"
	case EVD_OVERHEARD_ARGUMENT, tarc3_Accusation_EventScript_Q1Loop_17
# 208 "data/scripts/tarc3_accusation.pory"
	case EVD_BREADCRUMBS, tarc3_Accusation_EventScript_Q1Loop_18
# 210 "data/scripts/tarc3_accusation.pory"
	case EVD_DARK_RESIDUE, tarc3_Accusation_EventScript_Q1Loop_19
# 212 "data/scripts/tarc3_accusation.pory"
	case EVD_DROPPED_FLOWER, tarc3_Accusation_EventScript_Q1Loop_20
# 215 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_RESULT, EVD_COUNT, tarc3_Accusation_EventScript_Q1Summary
# 216 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Fz_OffQuestion
tarc3_Accusation_EventScript_Q1Loop_1:
# 218 "data/scripts/tarc3_accusation.pory"
	addvar VAR_TARC3_ACCUSE_SLOT, 1
# 219 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q1Loop
	return

tarc3_Accusation_EventScript_Q1Loop_3:
# 179 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TwinRefusal
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_4:
# 181 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_UnrequitedLove
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_5:
# 183 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_6:
# 185 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_7:
# 187 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_GozosFinalMeeting
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_8:
# 189 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TakeshisRevenge
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_9:
# 191 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_Sketchbook
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_10:
# 193 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RefusedSuitor
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_11:
# 195 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TuitionFunds
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_12:
# 197 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_IchiroSponsorship
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_13:
# 199 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_BreadEraser
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_14:
# 201 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TakeshisMeeting
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_15:
# 203 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TakeshisHistory
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_16:
# 205 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_FamilyPicture
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_17:
# 207 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_OverheardArgument
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_18:
# 209 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_19:
# 211 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q1Loop_1

tarc3_Accusation_EventScript_Q1Loop_20:
# 213 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q1Loop_1


tarc3_Accusation_EventScript_Q1Summary::
# 223 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 13, tarc3_Accusation_EventScript_Q1SummaryBest
# 224 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 5, tarc3_Accusation_EventScript_Q1SummaryGood
# 225 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 1, tarc3_Accusation_EventScript_Q1SummaryPoor
# 226 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_TARC3_ACCUSE_SLOT, 0, tarc3_Accusation_EventScript_Q1SummarySkipped
# 227 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q1SummaryNone
	return


tarc3_Accusation_EventScript_Q1SummaryBest::
# 231 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 232 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryBest_Text_0
# 233 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 234 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryBest_Text_2
# 235 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 236 "data/scripts/tarc3_accusation.pory"
	closemessage
# 237 "data/scripts/tarc3_accusation.pory"
	delay 30
# 238 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2
	return


tarc3_Accusation_EventScript_Q1SummaryGood::
# 242 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 243 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryGood_Text_0
# 244 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 245 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryGood_Text_1
# 246 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 247 "data/scripts/tarc3_accusation.pory"
	closemessage
# 248 "data/scripts/tarc3_accusation.pory"
	delay 30
# 249 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2
	return


tarc3_Accusation_EventScript_Q1SummaryPoor::
# 253 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 254 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryPoor_Text_0
# 255 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 256 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryPoor_Text_1
# 257 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 258 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryPoor_Text_2
# 259 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 260 "data/scripts/tarc3_accusation.pory"
	closemessage
# 261 "data/scripts/tarc3_accusation.pory"
	delay 30
# 262 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2
	return


tarc3_Accusation_EventScript_Q1SummaryNone::
# 266 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 267 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryNone_Text_0
# 268 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 269 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummaryNone_Text_1
# 270 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 271 "data/scripts/tarc3_accusation.pory"
	closemessage
# 272 "data/scripts/tarc3_accusation.pory"
	delay 30
# 273 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2
	return


tarc3_Accusation_EventScript_Q1SummarySkipped::
# 277 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 278 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummarySkipped_Text_0
# 279 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 280 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummarySkipped_Text_1
# 281 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 282 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q1SummarySkipped_Text_2
# 283 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 284 "data/scripts/tarc3_accusation.pory"
	closemessage
# 285 "data/scripts/tarc3_accusation.pory"
	delay 30
# 286 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2
	return


tarc3_Accusation_EventScript_Q2::
# 290 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 291 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2_Text_0
# 292 "data/scripts/tarc3_accusation.pory"
	closemessage
# 293 "data/scripts/tarc3_accusation.pory"
	delay 20
# 294 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_QSCORE, 0
# 295 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_SLOT, 0
# 296 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Q2_2
# 299 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_TATSUO, SUSPECT_ICHIRO
tarc3_Accusation_EventScript_Q2_1:
# 301 "data/scripts/tarc3_accusation.pory"
	waitstate
# 302 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2Loop
	return

tarc3_Accusation_EventScript_Q2_2:
# 297 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_TATSUO, SUSPECT_TAKESHI
	goto tarc3_Accusation_EventScript_Q2_1


tarc3_Accusation_EventScript_Q2Loop::
# 306 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_SLOT, 4, tarc3_Accusation_EventScript_Q2Summary
# 307 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_ReadSlot
# 308 "data/scripts/tarc3_accusation.pory"
	switch VAR_RESULT
# 309 "data/scripts/tarc3_accusation.pory"
	case EVD_SILENCED_WITNESS, tarc3_Accusation_EventScript_Q2Loop_3
# 311 "data/scripts/tarc3_accusation.pory"
	case EVD_THE_ACCOMPLICE_THEORY, tarc3_Accusation_EventScript_Q2Loop_4
# 313 "data/scripts/tarc3_accusation.pory"
	case EVD_CHARCOAL_ON_BOLT, tarc3_Accusation_EventScript_Q2Loop_5
# 315 "data/scripts/tarc3_accusation.pory"
	case EVD_LONG_ABSENCE, tarc3_Accusation_EventScript_Q2Loop_6
# 317 "data/scripts/tarc3_accusation.pory"
	case EVD_AN_ACCOMPLICE, tarc3_Accusation_EventScript_Q2Loop_7
# 319 "data/scripts/tarc3_accusation.pory"
	case EVD_OPEN_STORAGE_DOOR, tarc3_Accusation_EventScript_Q2Loop_8
# 321 "data/scripts/tarc3_accusation.pory"
	case EVD_BLOOD_ON_THE_STAIR, tarc3_Accusation_EventScript_Q2Loop_9
# 323 "data/scripts/tarc3_accusation.pory"
	case EVD_HIDDEN_PIPE, tarc3_Accusation_EventScript_Q2Loop_10
# 325 "data/scripts/tarc3_accusation.pory"
	case EVD_TWO_SOUNDS, tarc3_Accusation_EventScript_Q2Loop_11
# 327 "data/scripts/tarc3_accusation.pory"
	case EVD_BLOODY_CLOTH, tarc3_Accusation_EventScript_Q2Loop_12
# 329 "data/scripts/tarc3_accusation.pory"
	case EVD_UNLOCKED_CELL, tarc3_Accusation_EventScript_Q2Loop_13
# 332 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_RESULT, EVD_COUNT, tarc3_Accusation_EventScript_Q2Summary
# 333 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Fz_OffQuestion
tarc3_Accusation_EventScript_Q2Loop_1:
# 335 "data/scripts/tarc3_accusation.pory"
	addvar VAR_TARC3_ACCUSE_SLOT, 1
# 336 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2Loop
	return

tarc3_Accusation_EventScript_Q2Loop_3:
# 310 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_SilencedWitness
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_4:
# 312 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TheAccompliceTheory
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_5:
# 314 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_CharcoalOnBolt
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_6:
# 316 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_LongAbsence
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_7:
# 318 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_AnAccomplice
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_8:
# 320 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_OpenStorageDoor
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_9:
# 322 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_BloodOnTheStair
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_10:
# 324 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_HiddenPipe
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_11:
# 326 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_12:
# 328 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q2Loop_1

tarc3_Accusation_EventScript_Q2Loop_13:
# 330 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q2Loop_1


tarc3_Accusation_EventScript_Q2Summary::
# 340 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 5, tarc3_Accusation_EventScript_Q2SummaryGood
# 341 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 1, tarc3_Accusation_EventScript_Q2SummaryPoor
# 342 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_TARC3_ACCUSE_SLOT, 0, tarc3_Accusation_EventScript_Q2SummarySkipped
# 343 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q2SummaryNone
	return


tarc3_Accusation_EventScript_Q2SummaryGood::
# 347 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 348 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummaryGood_Text_1
# 349 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 350 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummaryGood_Text_2
# 351 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 352 "data/scripts/tarc3_accusation.pory"
	closemessage
# 353 "data/scripts/tarc3_accusation.pory"
	delay 30
# 354 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q3
	return


tarc3_Accusation_EventScript_Q2SummaryPoor::
# 358 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 359 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummaryPoor_Text_0
# 360 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 361 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummaryPoor_Text_1
# 362 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 363 "data/scripts/tarc3_accusation.pory"
	closemessage
# 364 "data/scripts/tarc3_accusation.pory"
	delay 30
# 365 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q3
	return


tarc3_Accusation_EventScript_Q2SummaryNone::
# 369 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 370 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummaryNone_Text_0
# 371 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 372 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummaryNone_Text_1
# 373 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 374 "data/scripts/tarc3_accusation.pory"
	closemessage
# 375 "data/scripts/tarc3_accusation.pory"
	delay 30
# 376 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q3
	return


tarc3_Accusation_EventScript_Q2SummarySkipped::
# 380 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 381 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummarySkipped_Text_0
# 382 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 383 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummarySkipped_Text_1
# 384 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummarySkipped_Text_2
# 385 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummarySkipped_Text_3
# 386 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 387 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q2SummarySkipped_Text_4
# 388 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 389 "data/scripts/tarc3_accusation.pory"
	closemessage
# 390 "data/scripts/tarc3_accusation.pory"
	delay 30
# 391 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q3
	return


tarc3_Accusation_EventScript_Q3::
# 395 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 396 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3_Text_0
# 397 "data/scripts/tarc3_accusation.pory"
	closemessage
# 398 "data/scripts/tarc3_accusation.pory"
	delay 20
# 399 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_QSCORE, 0
# 400 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_SLOT, 0
# 401 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Q3_2
# 404 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_LIGHTS, SUSPECT_ICHIRO
tarc3_Accusation_EventScript_Q3_1:
# 406 "data/scripts/tarc3_accusation.pory"
	waitstate
# 407 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q3Loop
	return

tarc3_Accusation_EventScript_Q3_2:
# 402 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_LIGHTS, SUSPECT_TAKESHI
	goto tarc3_Accusation_EventScript_Q3_1


tarc3_Accusation_EventScript_Q3Loop::
# 411 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_SLOT, 4, tarc3_Accusation_EventScript_Q3Summary
# 412 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_ReadSlot
# 413 "data/scripts/tarc3_accusation.pory"
	switch VAR_RESULT
# 414 "data/scripts/tarc3_accusation.pory"
	case EVD_SKETCHED_DISCHARGE, tarc3_Accusation_EventScript_Q3Loop_3
# 416 "data/scripts/tarc3_accusation.pory"
	case EVD_SMEARGLE_KNOWS_DISCHARGE, tarc3_Accusation_EventScript_Q3Loop_4
# 418 "data/scripts/tarc3_accusation.pory"
	case EVD_PANEL_STRUCK, tarc3_Accusation_EventScript_Q3Loop_5
# 420 "data/scripts/tarc3_accusation.pory"
	case EVD_THE_NEAREST_HAND, tarc3_Accusation_EventScript_Q3Loop_6
# 422 "data/scripts/tarc3_accusation.pory"
	case EVD_SMEARGLE_REPERTOIRE, tarc3_Accusation_EventScript_Q3Loop_7
# 424 "data/scripts/tarc3_accusation.pory"
	case EVD_THE_ODD_BATTLE, tarc3_Accusation_EventScript_Q3Loop_8
# 426 "data/scripts/tarc3_accusation.pory"
	case EVD_LONG_ABSENCE, tarc3_Accusation_EventScript_Q3Loop_9
# 428 "data/scripts/tarc3_accusation.pory"
	case EVD_THE_HOLD_ADJOINS, tarc3_Accusation_EventScript_Q3Loop_10
# 430 "data/scripts/tarc3_accusation.pory"
	case EVD_OPEN_STORAGE_DOOR, tarc3_Accusation_EventScript_Q3Loop_11
# 432 "data/scripts/tarc3_accusation.pory"
	case EVD_BROKEN_LATCH, tarc3_Accusation_EventScript_Q3Loop_12
# 434 "data/scripts/tarc3_accusation.pory"
	case EVD_SCORCHED_PANEL, tarc3_Accusation_EventScript_Q3Loop_13
# 437 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_RESULT, EVD_COUNT, tarc3_Accusation_EventScript_Q3Summary
# 438 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Fz_OffQuestion
tarc3_Accusation_EventScript_Q3Loop_1:
# 440 "data/scripts/tarc3_accusation.pory"
	addvar VAR_TARC3_ACCUSE_SLOT, 1
# 441 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q3Loop
	return

tarc3_Accusation_EventScript_Q3Loop_3:
# 415 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_SketchedDischarge
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_4:
# 417 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_5:
# 419 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_PanelStruck
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_6:
# 421 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TheNearestHand
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_7:
# 423 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_SmeargleRepertoire
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_8:
# 425 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TheOddBattle
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_9:
# 427 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_LongAbsence
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_10:
# 429 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TheHoldAdjoins
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_11:
# 431 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_OpenStorageDoor
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_12:
# 433 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q3Loop_1

tarc3_Accusation_EventScript_Q3Loop_13:
# 435 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q3Loop_1


tarc3_Accusation_EventScript_Q3Summary::
# 445 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 13, tarc3_Accusation_EventScript_Q3SummaryBest
# 446 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 5, tarc3_Accusation_EventScript_Q3SummaryGood
# 447 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 1, tarc3_Accusation_EventScript_Q3SummaryPoor
# 448 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_TARC3_ACCUSE_SLOT, 0, tarc3_Accusation_EventScript_Q3SummarySkipped
# 449 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q3SummaryNone
	return


tarc3_Accusation_EventScript_Q3SummaryBest::
# 453 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 454 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummaryBest_Text_0
# 455 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 456 "data/scripts/tarc3_accusation.pory"
	closemessage
# 457 "data/scripts/tarc3_accusation.pory"
	delay 30
# 458 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4
	return


tarc3_Accusation_EventScript_Q3SummaryGood::
# 462 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_5
# 463 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummaryGood_Text_0
# 464 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 465 "data/scripts/tarc3_accusation.pory"
	closemessage
# 466 "data/scripts/tarc3_accusation.pory"
	delay 30
# 467 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4
	return


tarc3_Accusation_EventScript_Q3SummaryPoor::
# 471 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 472 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummaryPoor_Text_0
# 473 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 474 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummaryPoor_Text_1
# 475 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 476 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummaryPoor_Text_2
# 477 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 478 "data/scripts/tarc3_accusation.pory"
	closemessage
# 479 "data/scripts/tarc3_accusation.pory"
	delay 30
# 480 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4
	return


tarc3_Accusation_EventScript_Q3SummaryNone::
# 484 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 485 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummaryNone_Text_0
# 486 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 487 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummaryNone_Text_1
# 488 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 489 "data/scripts/tarc3_accusation.pory"
	closemessage
# 490 "data/scripts/tarc3_accusation.pory"
	delay 30
# 491 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4
	return


tarc3_Accusation_EventScript_Q3SummarySkipped::
# 495 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 496 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummarySkipped_Text_0
# 497 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 498 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummarySkipped_Text_1
# 499 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 500 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummarySkipped_Text_2
# 501 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q3SummarySkipped_Text_3
# 502 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 503 "data/scripts/tarc3_accusation.pory"
	closemessage
# 504 "data/scripts/tarc3_accusation.pory"
	delay 30
# 505 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4
	return


tarc3_Accusation_EventScript_Q4::
# 509 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 510 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4_Text_0
# 511 "data/scripts/tarc3_accusation.pory"
	closemessage
# 512 "data/scripts/tarc3_accusation.pory"
	delay 30
# 513 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 514 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4_Text_1
# 515 "data/scripts/tarc3_accusation.pory"
	closemessage
# 516 "data/scripts/tarc3_accusation.pory"
	delay 20
# 517 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_QSCORE, 0
# 518 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACCUSE_SLOT, 0
# 519 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Q4_2
# 522 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_ICHIRO, SUSPECT_ICHIRO
tarc3_Accusation_EventScript_Q4_1:
# 524 "data/scripts/tarc3_accusation.pory"
	waitstate
# 525 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4Loop
	return

tarc3_Accusation_EventScript_Q4_2:
# 520 "data/scripts/tarc3_accusation.pory"
	openaccusemenu QUESTION_ICHIRO, SUSPECT_TAKESHI
	goto tarc3_Accusation_EventScript_Q4_1


tarc3_Accusation_EventScript_Q4Loop::
# 529 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_SLOT, 4, tarc3_Accusation_EventScript_Q4Summary
# 530 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_ReadSlot
# 531 "data/scripts/tarc3_accusation.pory"
	switch VAR_RESULT
# 532 "data/scripts/tarc3_accusation.pory"
	case EVD_SELF_INFLICTED_WOUND, tarc3_Accusation_EventScript_Q4Loop_3
# 534 "data/scripts/tarc3_accusation.pory"
	case EVD_IMPOSSIBLE_PRECISION, tarc3_Accusation_EventScript_Q4Loop_4
# 536 "data/scripts/tarc3_accusation.pory"
	case EVD_INCONSISTENT_DISPOSAL, tarc3_Accusation_EventScript_Q4Loop_5
# 538 "data/scripts/tarc3_accusation.pory"
	case EVD_THE_ACCOMPLICE_THEORY, tarc3_Accusation_EventScript_Q4Loop_6
# 540 "data/scripts/tarc3_accusation.pory"
	case EVD_NO_DEFENSIVE_WOUNDS, tarc3_Accusation_EventScript_Q4Loop_7
# 542 "data/scripts/tarc3_accusation.pory"
	case EVD_THE_SECOND_STORY, tarc3_Accusation_EventScript_Q4Loop_8
# 544 "data/scripts/tarc3_accusation.pory"
	case EVD_AN_ACCOMPLICE, tarc3_Accusation_EventScript_Q4Loop_9
# 546 "data/scripts/tarc3_accusation.pory"
	case EVD_OPEN_STORAGE_DOOR, tarc3_Accusation_EventScript_Q4Loop_10
# 548 "data/scripts/tarc3_accusation.pory"
	case EVD_KNIVES_COUNTED, tarc3_Accusation_EventScript_Q4Loop_11
# 550 "data/scripts/tarc3_accusation.pory"
	case EVD_INJURED_LEG, tarc3_Accusation_EventScript_Q4Loop_12
# 552 "data/scripts/tarc3_accusation.pory"
	case EVD_BATHROOM_BLACKOUT, tarc3_Accusation_EventScript_Q4Loop_13
# 554 "data/scripts/tarc3_accusation.pory"
	case EVD_BATHROOM_KNIFE, tarc3_Accusation_EventScript_Q4Loop_14
# 556 "data/scripts/tarc3_accusation.pory"
	case EVD_MISSING_KNIVES, tarc3_Accusation_EventScript_Q4Loop_15
# 559 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_RESULT, EVD_COUNT, tarc3_Accusation_EventScript_Q4Summary
# 560 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Fz_OffQuestion
tarc3_Accusation_EventScript_Q4Loop_1:
# 562 "data/scripts/tarc3_accusation.pory"
	addvar VAR_TARC3_ACCUSE_SLOT, 1
# 563 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4Loop
	return

tarc3_Accusation_EventScript_Q4Loop_3:
# 533 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_SelfInflictedWound
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_4:
# 535 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_ImpossiblePrecision
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_5:
# 537 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_InconsistentDisposal
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_6:
# 539 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TheAccompliceTheory
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_7:
# 541 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_NoDefensiveWounds
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_8:
# 543 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_TheSecondStory
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_9:
# 545 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_AnAccomplice
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_10:
# 547 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_OpenStorageDoor
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_11:
# 549 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_12:
# 551 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_13:
# 553 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_14:
# 555 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q4Loop_1

tarc3_Accusation_EventScript_Q4Loop_15:
# 557 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_Ev_RawClue
	goto tarc3_Accusation_EventScript_Q4Loop_1


tarc3_Accusation_EventScript_Q4Summary::
# 567 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 13, tarc3_Accusation_EventScript_Q4SummaryBest
# 568 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 5, tarc3_Accusation_EventScript_Q4SummaryGood
# 569 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_QSCORE, 1, tarc3_Accusation_EventScript_Q4SummaryPoor
# 570 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_TARC3_ACCUSE_SLOT, 0, tarc3_Accusation_EventScript_Q4SummarySkipped
# 571 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Q4SummaryNone
	return


tarc3_Accusation_EventScript_Q4SummaryBest::
# 575 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 576 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummaryBest_Text_0
# 577 "data/scripts/tarc3_accusation.pory"
	closemessage
# 578 "data/scripts/tarc3_accusation.pory"
	delay 40
# 579 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Resolve
	return


tarc3_Accusation_EventScript_Q4SummaryGood::
# 583 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 584 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummaryGood_Text_0
# 585 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 586 "data/scripts/tarc3_accusation.pory"
	closemessage
# 587 "data/scripts/tarc3_accusation.pory"
	delay 30
# 588 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Resolve
	return


tarc3_Accusation_EventScript_Q4SummaryPoor::
# 592 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 593 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummaryPoor_Text_0
# 594 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 595 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 596 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummaryPoor_Text_1
# 597 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 598 "data/scripts/tarc3_accusation.pory"
	closemessage
# 599 "data/scripts/tarc3_accusation.pory"
	delay 30
# 600 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Resolve
	return


tarc3_Accusation_EventScript_Q4SummaryNone::
# 604 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 605 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummaryNone_Text_0
# 606 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 607 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummaryNone_Text_1
# 608 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 609 "data/scripts/tarc3_accusation.pory"
	closemessage
# 610 "data/scripts/tarc3_accusation.pory"
	delay 30
# 611 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Resolve
	return


tarc3_Accusation_EventScript_Q4SummarySkipped::
# 615 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 616 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummarySkipped_Text_0
# 617 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummarySkipped_Text_1
# 618 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 619 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummarySkipped_Text_2
# 620 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Q4SummarySkipped_Text_3
# 621 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 622 "data/scripts/tarc3_accusation.pory"
	closemessage
# 623 "data/scripts/tarc3_accusation.pory"
	delay 30
# 624 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Resolve
	return


tarc3_Accusation_EventScript_Resolve::
# 629 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI, tarc3_Accusation_EventScript_BandWorst
# 630 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSE_SCORE, 43
	goto_if_ge tarc3_Accusation_EventScript_Resolve_3
tarc3_Accusation_EventScript_Resolve_1:
# 633 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSE_SCORE, 27
	goto_if_ge tarc3_Accusation_EventScript_Resolve_8
tarc3_Accusation_EventScript_Resolve_6:
# 636 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BandBad
	return

tarc3_Accusation_EventScript_Resolve_2:
# 631 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BandPerfect
	goto tarc3_Accusation_EventScript_Resolve_1

tarc3_Accusation_EventScript_Resolve_3:
# 630 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSE_T3, TARC3_T3_ALL
	goto_if_eq tarc3_Accusation_EventScript_Resolve_2
	goto tarc3_Accusation_EventScript_Resolve_1

tarc3_Accusation_EventScript_Resolve_7:
# 634 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BandGood
	goto tarc3_Accusation_EventScript_Resolve_6

tarc3_Accusation_EventScript_Resolve_8:
# 633 "data/scripts/tarc3_accusation.pory"
	compare VAR_TARC3_ACCUSE_HITS, 1
	goto_if_ge tarc3_Accusation_EventScript_Resolve_7
	goto tarc3_Accusation_EventScript_Resolve_6


tarc3_Accusation_EventScript_BandPerfect::
# 640 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ENDING, TARC3_ENDING_PERFECT
# 641 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_PerfectAnswer
	return


tarc3_Accusation_EventScript_BandGood::
# 645 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ENDING, TARC3_ENDING_GOOD
# 646 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodAnswer
	return


tarc3_Accusation_EventScript_BandBad::
# 650 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ENDING, TARC3_ENDING_BAD
# 651 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BadAnswer
	return


tarc3_Accusation_EventScript_BandWorst::
# 655 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ENDING, TARC3_ENDING_WORST
# 656 "data/scripts/tarc3_accusation.pory"
	goto_if_ge VAR_TARC3_ACCUSE_SCORE, 24, tarc3_Accusation_EventScript_WorstAnswer
# 657 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ENDING, TARC3_ENDING_WORST_REFUSED
# 658 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_WorstRefusedAnswer
	return


tarc3_Accusation_EventScript_PerfectAnswer::
# 664 "data/scripts/tarc3_accusation.pory"
	closemessage
# 665 "data/scripts/tarc3_accusation.pory"
	delay 50
# 666 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 667 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_0
# 668 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_1
# 669 "data/scripts/tarc3_accusation.pory"
	closemessage
# 670 "data/scripts/tarc3_accusation.pory"
	delay 20
# 671 "data/scripts/tarc3_accusation.pory"
	playse SE_PIN
# 672 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_NameIchiro_Movement_0
# 673 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 674 "data/scripts/tarc3_accusation.pory"
	delay 30
# 675 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_PerfectAnswer_Movement_0
# 676 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 677 "data/scripts/tarc3_accusation.pory"
	delay 20
# 678 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 679 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_2
# 680 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_3
# 681 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_4
# 682 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_5
# 683 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_6
# 684 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_7
# 685 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_8
# 686 "data/scripts/tarc3_accusation.pory"
	closemessage
# 687 "data/scripts/tarc3_accusation.pory"
	delay 50
# 688 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 689 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_9
# 690 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_10
# 691 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_11
# 692 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 693 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 694 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_12
# 695 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_13
# 696 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 697 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_14
# 698 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_15
# 699 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_16
# 700 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectAnswer_Text_17
# 701 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 702 "data/scripts/tarc3_accusation.pory"
	closemessage
# 703 "data/scripts/tarc3_accusation.pory"
	delay 60
# 704 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_PerfectCloset
	return


tarc3_Accusation_EventScript_PerfectCloset::
# 708 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 709 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_0
# 710 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 711 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_1
# 712 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 713 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_2
# 714 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 715 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_3
# 716 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 717 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_4
# 718 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 719 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_5
# 720 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 721 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_6
# 722 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_7
# 723 "data/scripts/tarc3_accusation.pory"
	closemessage
# 724 "data/scripts/tarc3_accusation.pory"
	delay 30
# 725 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_OpenCloset
# 726 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 727 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_8
# 728 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 729 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_9
# 730 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_5
# 731 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_10
# 732 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 733 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_11
# 734 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 735 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_12
# 736 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 737 "data/scripts/tarc3_accusation.pory"
	closemessage
# 738 "data/scripts/tarc3_accusation.pory"
	delay 30
# 739 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_PerfectTakeshi
	return


tarc3_Accusation_EventScript_PerfectTakeshi::
# 743 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 744 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_0
# 745 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 746 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_1
# 747 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_2
# 748 "data/scripts/tarc3_accusation.pory"
	goto_if_set FLAG_TARC3_ACCUSE_HISTORY, tarc3_Accusation_EventScript_PerfectTakeshi_2
tarc3_Accusation_EventScript_PerfectTakeshi_1:
# 751 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_4
# 752 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_5
# 753 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_6
# 754 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_7
# 755 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_8
# 756 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 757 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_9
# 758 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 759 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_10
# 760 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_11
# 761 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_12
# 762 "data/scripts/tarc3_accusation.pory"
	closemessage
# 763 "data/scripts/tarc3_accusation.pory"
	delay 20
# 764 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_TAKESHI_CLOSET, tarc3_Accusation_EventScript_OpenCloset_Movement_2
# 765 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 766 "data/scripts/tarc3_accusation.pory"
	delay 20
# 767 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_PerfectTakeshi_Movement_0
# 768 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 769 "data/scripts/tarc3_accusation.pory"
	delay 20
# 770 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 771 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_13
# 772 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_14
# 773 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_15
# 774 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 775 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_16
# 776 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_17
# 777 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 778 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 779 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 780 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_18
# 781 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 782 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 783 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_19
# 784 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 785 "data/scripts/tarc3_accusation.pory"
	closemessage
# 786 "data/scripts/tarc3_accusation.pory"
	delay 50
# 787 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_End
	return

tarc3_Accusation_EventScript_PerfectTakeshi_2:
# 749 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_3
	goto tarc3_Accusation_EventScript_PerfectTakeshi_1


tarc3_Accusation_EventScript_GoodAnswer::
# 793 "data/scripts/tarc3_accusation.pory"
	closemessage
# 794 "data/scripts/tarc3_accusation.pory"
	delay 40
# 795 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 796 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswer_Text_0
# 797 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 798 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswer_Text_1
# 799 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswer_Text_2
# 800 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 801 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswer_Text_3
# 802 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 803 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswer_Text_4
# 804 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswer_Text_5
# 805 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_5
# 806 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswer_Text_6
# 807 "data/scripts/tarc3_accusation.pory"
	closemessage
# 808 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_OpenCloset_Movement_0
# 809 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 810 "data/scripts/tarc3_accusation.pory"
	delay 20
# 811 "data/scripts/tarc3_accusation.pory"
	switch VAR_TARC3_ACCUSE_T3
# 812 "data/scripts/tarc3_accusation.pory"
	case TARC3_T3_REFUSAL_ONLY, tarc3_Accusation_EventScript_GoodAnswer_2
# 814 "data/scripts/tarc3_accusation.pory"
	case TARC3_T3_REFUSAL_LIGHTS, tarc3_Accusation_EventScript_GoodAnswer_3
# 816 "data/scripts/tarc3_accusation.pory"
	case TARC3_T3_REFUSAL_WOUND, tarc3_Accusation_EventScript_GoodAnswer_4
# 818 "data/scripts/tarc3_accusation.pory"
	case TARC3_T3_ALL, tarc3_Accusation_EventScript_GoodAnswer_5
# 821 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodMotiveKept
	return

tarc3_Accusation_EventScript_GoodAnswer_2:
# 813 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodMotiveDenied
	return

tarc3_Accusation_EventScript_GoodAnswer_3:
# 815 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodMotiveDenied
	return

tarc3_Accusation_EventScript_GoodAnswer_4:
# 817 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodMotiveDenied
	return

tarc3_Accusation_EventScript_GoodAnswer_5:
# 819 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodMotiveDenied
	return


tarc3_Accusation_EventScript_GoodMotiveKept::
# 828 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 829 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_0
# 830 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_1
# 831 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_2
# 832 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_3
# 833 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 834 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 835 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_4
# 836 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 837 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_4
# 838 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 839 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_5
# 840 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_18
# 841 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 842 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 843 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_19
# 844 "data/scripts/tarc3_accusation.pory"
	closemessage
# 845 "data/scripts/tarc3_accusation.pory"
	delay 40
# 846 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 847 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_6
# 848 "data/scripts/tarc3_accusation.pory"
	closemessage
# 849 "data/scripts/tarc3_accusation.pory"
	delay 20
# 850 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_7
# 851 "data/scripts/tarc3_accusation.pory"
	closemessage
# 852 "data/scripts/tarc3_accusation.pory"
	delay 20
# 853 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 854 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_8
# 855 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 856 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveKept_Text_9
# 857 "data/scripts/tarc3_accusation.pory"
	closemessage
# 858 "data/scripts/tarc3_accusation.pory"
	delay 20
# 859 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodAnswerEnough
	return


tarc3_Accusation_EventScript_GoodMotiveDenied::
# 865 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 866 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveDenied_Text_0
# 867 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 868 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveDenied_Text_1
# 869 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveDenied_Text_2
# 870 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 871 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveDenied_Text_3
# 872 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveDenied_Text_4
# 873 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 874 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 875 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 876 "data/scripts/tarc3_accusation.pory"
	closemessage
# 877 "data/scripts/tarc3_accusation.pory"
	delay 40
# 878 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodMotiveDenied_Text_5
# 879 "data/scripts/tarc3_accusation.pory"
	closemessage
# 880 "data/scripts/tarc3_accusation.pory"
	delay 20
# 881 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodAnswerEnough
	return


tarc3_Accusation_EventScript_GoodAnswerEnough::
# 885 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_PerfectAnswer_Movement_0
# 886 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 887 "data/scripts/tarc3_accusation.pory"
	delay 20
# 888 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 889 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswerEnough_Text_0
# 890 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 891 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodAnswerEnough_Text_1
# 892 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 893 "data/scripts/tarc3_accusation.pory"
	closemessage
# 894 "data/scripts/tarc3_accusation.pory"
	delay 40
# 895 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodCloset
	return


tarc3_Accusation_EventScript_GoodCloset::
# 899 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 900 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodCloset_Text_0
# 901 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 902 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodCloset_Text_1
# 903 "data/scripts/tarc3_accusation.pory"
	closemessage
# 904 "data/scripts/tarc3_accusation.pory"
	delay 20
# 905 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_OpenCloset
# 906 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 907 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodCloset_Text_2
# 908 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 909 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodCloset_Text_3
# 910 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 911 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodCloset_Text_4
# 912 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 913 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodCloset_Text_5
# 914 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 915 "data/scripts/tarc3_accusation.pory"
	closemessage
# 916 "data/scripts/tarc3_accusation.pory"
	delay 40
# 917 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_GoodStern
	return


tarc3_Accusation_EventScript_GoodStern::
# 921 "data/scripts/tarc3_accusation.pory"
	closemessage
# 922 "data/scripts/tarc3_accusation.pory"
	fadescreen FADE_TO_BLACK
# 923 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_ICHIRO
# 924 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_SUZUKI
# 925 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_AKIE
# 926 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_KITARO
# 927 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_JOJI
# 928 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_MARIKO
# 929 "data/scripts/tarc3_accusation.pory"
	delay 30
# 930 "data/scripts/tarc3_accusation.pory"
	fadescreen FADE_FROM_BLACK
# 931 "data/scripts/tarc3_accusation.pory"
	delay 30
# 932 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 933 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_0
# 934 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 935 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_0
# 936 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 937 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_1
# 938 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_2
# 939 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_3
# 940 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 941 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 942 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 943 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_4
# 944 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 945 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_5
# 946 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 947 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_6
# 948 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 949 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 950 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_7
# 951 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_GoodStern_Text_8
# 952 "data/scripts/tarc3_accusation.pory"
	closemessage
# 953 "data/scripts/tarc3_accusation.pory"
	delay 40
# 954 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_End
	return


tarc3_Accusation_EventScript_BadAnswer::
# 960 "data/scripts/tarc3_accusation.pory"
	closemessage
# 961 "data/scripts/tarc3_accusation.pory"
	delay 30
# 962 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 963 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_0
# 964 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 965 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 966 "data/scripts/tarc3_accusation.pory"
	goto_if_unset FLAG_TARC3_ACCUSE_CRUMBS, tarc3_Accusation_EventScript_BadAnswerGeneric
# 967 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 968 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_1
# 969 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_2
# 970 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_3
# 971 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 972 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_4
# 973 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 974 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_5
# 975 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_6
# 976 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_7
# 977 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 978 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 979 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 980 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_8
# 981 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_9
# 982 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 983 "data/scripts/tarc3_accusation.pory"
	closemessage
# 984 "data/scripts/tarc3_accusation.pory"
	delay 40
# 985 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BadNearMiss
	return


tarc3_Accusation_EventScript_BadAnswerGeneric::
# 991 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 992 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswerGeneric_Text_0
# 993 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswerGeneric_Text_1
# 994 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswerGeneric_Text_2
# 995 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 996 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswerGeneric_Text_3
# 997 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 998 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswerGeneric_Text_4
# 999 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 1000 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 1001 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 1002 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_8
# 1003 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadAnswer_Text_9
# 1004 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1005 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1006 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1007 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BadNearMiss
	return


tarc3_Accusation_EventScript_BadNearMiss::
# 1013 "data/scripts/tarc3_accusation.pory"
	checkevidence EVD_SKETCHBOOK
# 1014 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_RESULT, TRUE, tarc3_Accusation_EventScript_BadNearMissBook
# 1015 "data/scripts/tarc3_accusation.pory"
	checkevidence EVD_UNREQUITED_LOVE
# 1016 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_RESULT, TRUE, tarc3_Accusation_EventScript_BadNearMissBook
# 1017 "data/scripts/tarc3_accusation.pory"
	checkevidence EVD_TWIN_REFUSAL
# 1018 "data/scripts/tarc3_accusation.pory"
	goto_if_eq VAR_RESULT, TRUE, tarc3_Accusation_EventScript_BadNearMissBook
# 1019 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BadWall
	return


tarc3_Accusation_EventScript_BadNearMissBook::
# 1023 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 1024 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadNearMissBook_Text_0
# 1025 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1026 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1027 "data/scripts/tarc3_accusation.pory"
	playse SE_PIN
# 1028 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_NameIchiro_Movement_0
# 1029 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1030 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1031 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_OpenCloset_Movement_0
# 1032 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1033 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1034 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 1035 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadNearMissBook_Text_1
# 1036 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1037 "data/scripts/tarc3_accusation.pory"
	delay 20
# 1038 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_PerfectAnswer_Movement_0
# 1039 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1040 "data/scripts/tarc3_accusation.pory"
	delay 20
# 1041 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 1042 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadNearMissBook_Text_2
# 1043 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadNearMissBook_Text_3
# 1044 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1045 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1046 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BadWall
	return


tarc3_Accusation_EventScript_BadWall::
# 1050 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 1051 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadWall_Text_0
# 1052 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1053 "data/scripts/tarc3_accusation.pory"
	delay 20
# 1054 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1055 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadWall_Text_1
# 1056 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1057 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1058 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1059 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadWall_Text_2
# 1060 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadWall_Text_3
# 1061 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadWall_Text_4
# 1062 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadWall_Text_5
# 1063 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1064 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1065 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1066 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_BadCloset
	return


tarc3_Accusation_EventScript_BadCloset::
# 1070 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 1071 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_0
# 1072 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_1
# 1073 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1074 "data/scripts/tarc3_accusation.pory"
	delay 50
# 1075 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 1076 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_2
# 1077 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_3
# 1078 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 1079 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_4
# 1080 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1081 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_5
# 1082 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_6
# 1083 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 1084 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_7
# 1085 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_5
# 1086 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_8
# 1087 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1088 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1089 "data/scripts/tarc3_accusation.pory"
	call tarc3_Accusation_EventScript_OpenCloset
# 1090 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 1091 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_9
# 1092 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1093 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_10
# 1094 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_11
# 1095 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_12
# 1096 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1097 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1098 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 1099 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 1100 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_13
# 1101 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_14
# 1102 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_BadCloset_Text_15
# 1103 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1104 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1105 "data/scripts/tarc3_accusation.pory"
	delay 50
# 1106 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_End
	return


tarc3_Accusation_EventScript_WorstAnswer::
# 1112 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1113 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1114 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1115 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_0
# 1116 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 1117 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_1
# 1118 "data/scripts/tarc3_accusation.pory"
	goto_if_set FLAG_TARC3_ACCUSE_HISTORY, tarc3_Accusation_EventScript_WorstAnswer_2
tarc3_Accusation_EventScript_WorstAnswer_1:
# 1121 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_3
# 1122 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_4
# 1123 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_5
# 1124 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_5
# 1125 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_6
# 1126 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 1127 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_8
# 1128 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 1129 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_7
# 1130 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1131 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_8
# 1132 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_9
# 1133 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 1134 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectCloset_Text_4
# 1135 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_10
# 1136 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1137 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1138 "data/scripts/tarc3_accusation.pory"
	delay 50
# 1139 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_WorstRoom
	return

tarc3_Accusation_EventScript_WorstAnswer_2:
# 1119 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstAnswer_Text_2
	goto tarc3_Accusation_EventScript_WorstAnswer_1


tarc3_Accusation_EventScript_WorstRoom::
# 1143 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_1
# 1144 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRoom_Text_0
# 1145 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 1146 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRoom_Text_1
# 1147 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRoom_Text_2
# 1148 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1149 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_18
# 1150 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 1151 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 1152 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_19
# 1153 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1154 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1155 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1156 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_SUZUKI, tarc3_Accusation_EventScript_WorstRoom_Movement_0
# 1157 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1158 "data/scripts/tarc3_accusation.pory"
	playse SE_EXIT
# 1159 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_SUZUKI
# 1160 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1161 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_WorstIchiro
	return


tarc3_Accusation_EventScript_WorstIchiro::
# 1165 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_1
# 1166 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstIchiro_Text_0
# 1167 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstIchiro_Text_1
# 1168 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstIchiro_Text_2
# 1169 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 1170 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 1171 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1172 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1173 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1174 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_ICHIRO, tarc3_Accusation_EventScript_WorstIchiro_Movement_0
# 1175 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1176 "data/scripts/tarc3_accusation.pory"
	playse SE_EXIT
# 1177 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_ICHIRO
# 1178 "data/scripts/tarc3_accusation.pory"
	delay 20
# 1179 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_WorstIchiro_Movement_1
# 1180 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1181 "data/scripts/tarc3_accusation.pory"
	playse SE_EXIT
# 1182 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_NATSUE
# 1183 "data/scripts/tarc3_accusation.pory"
	delay 50
# 1184 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_End
	return


tarc3_Accusation_EventScript_WorstRefusedAnswer::
# 1190 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1191 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1192 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1193 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_0
# 1194 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 1195 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_1
# 1196 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1197 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_2
# 1198 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 1199 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_3
# 1200 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_4
# 1201 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_5
# 1202 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_5
# 1203 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1204 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1205 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1206 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_WorstRefusedTakeshi
	return


tarc3_Accusation_EventScript_WorstRefusedTakeshi::
# 1210 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 1211 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_0
# 1212 "data/scripts/tarc3_accusation.pory"
	goto_if_set FLAG_TARC3_ACCUSE_HISTORY, tarc3_Accusation_EventScript_WorstRefusedTakeshi_2
tarc3_Accusation_EventScript_WorstRefusedTakeshi_1:
# 1215 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_2
# 1216 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_3
# 1217 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1218 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_4
# 1219 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 1220 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_5
# 1221 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameTakeshi_Text_2
# 1222 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_0
# 1223 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameMenu_Text_2
# 1224 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_1
# 1225 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q2SummaryGood_Text_0
# 1226 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_6
# 1227 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_7
# 1228 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_NameIchiro_Text_3
# 1229 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_18
# 1230 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Q1SummaryBest_Text_1
# 1231 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 1232 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_PerfectTakeshi_Text_19
# 1233 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1234 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1235 "data/scripts/tarc3_accusation.pory"
	delay 50
# 1236 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_End
	return

tarc3_Accusation_EventScript_WorstRefusedTakeshi_2:
# 1213 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_1
	goto tarc3_Accusation_EventScript_WorstRefusedTakeshi_1


tarc3_Accusation_EventScript_End::
# 1240 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1241 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1242 "data/scripts/tarc3_accusation.pory"
	fadescreen FADE_TO_BLACK
# 1243 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_TAKESHI_CLOSET
# 1244 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_NATSUE
# 1245 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_ICHIRO
# 1246 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_SUZUKI
# 1247 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_AKIE
# 1248 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_KITARO
# 1249 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_JOJI
# 1250 "data/scripts/tarc3_accusation.pory"
	removeobject LOCALID_CABINS_MARIKO
# 1251 "data/scripts/tarc3_accusation.pory"
	delay 30
# 1252 "data/scripts/tarc3_accusation.pory"
	fadescreen FADE_FROM_BLACK
# 1253 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1254 "data/scripts/tarc3_accusation.pory"
	goto tarc3_Accusation_EventScript_Depart
	return


tarc3_Accusation_EventScript_Depart::
# 1258 "data/scripts/tarc3_accusation.pory"
	applymovement LOCALID_CABINS_RAN, tarc3_Accusation_EventScript_Depart_Movement_0
# 1259 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1260 "data/scripts/tarc3_accusation.pory"
	applymovement OBJ_EVENT_ID_PLAYER, tarc3_Accusation_EventScript_OpenCloset_Movement_2
# 1261 "data/scripts/tarc3_accusation.pory"
	waitmovement 0
# 1262 "data/scripts/tarc3_accusation.pory"
	delay 20
# 1263 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 1264 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Depart_Text_0
# 1265 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Depart_Text_1
# 1266 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Naming_Text_0
# 1267 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_NameIchiro_Text_7
# 1268 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1269 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1270 "data/scripts/tarc3_accusation.pory"
	delay 40
# 1271 "data/scripts/tarc3_accusation.pory"
	playse SE_RG_SS_ANNE_HORN
# 1272 "data/scripts/tarc3_accusation.pory"
	delay 80
# 1273 "data/scripts/tarc3_accusation.pory"
	setspeaker tarc3_Accusation_EventScript_Begin_Text_0
# 1274 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Depart_Text_2
# 1275 "data/scripts/tarc3_accusation.pory"
	msgbox tarc3_Accusation_EventScript_Depart_Text_3
# 1276 "data/scripts/tarc3_accusation.pory"
	setspeaker NULL
# 1277 "data/scripts/tarc3_accusation.pory"
	closemessage
# 1278 "data/scripts/tarc3_accusation.pory"
	delay 20
# 1279 "data/scripts/tarc3_accusation.pory"
	savebgm MUS_DUMMY
# 1280 "data/scripts/tarc3_accusation.pory"
	fadedefaultbgm
# 1281 "data/scripts/tarc3_accusation.pory"
	setvar VAR_TARC3_ACT3, TARC3_ACT3_COMPLETE
# 1282 "data/scripts/tarc3_accusation.pory"
	fwdtime TARC3_TOD_DAWN_HOUR, TARC3_TOD_DAWN_MINUTE
# 1283 "data/scripts/tarc3_accusation.pory"
	warp MAP_TARC3_DESTINATION, 14, 18
# 1284 "data/scripts/tarc3_accusation.pory"
	waitstate
	end


# 28 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_TakeTheFloor_Movement_0:
# 28 "data/scripts/tarc3_accusation.pory"
	walk_left
# 28 "data/scripts/tarc3_accusation.pory"
	walk_up
# 28 "data/scripts/tarc3_accusation.pory"
	walk_left
# 28 "data/scripts/tarc3_accusation.pory"
	face_up
	step_end

# 30 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_TakeTheFloor_Movement_1:
# 30 "data/scripts/tarc3_accusation.pory"
	walk_left
# 30 "data/scripts/tarc3_accusation.pory"
	face_up
	step_end

# 76 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_NameIchiro_Movement_0:
# 76 "data/scripts/tarc3_accusation.pory"
	emote_exclamation_mark
	step_end

# 133 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_OpenCloset_Movement_0:
# 133 "data/scripts/tarc3_accusation.pory"
	face_up
	step_end

# 136 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_OpenCloset_Movement_1:
# 136 "data/scripts/tarc3_accusation.pory"
	walk_down
	step_end

# 138 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_OpenCloset_Movement_2:
# 138 "data/scripts/tarc3_accusation.pory"
	face_right
	step_end

# 675 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_PerfectAnswer_Movement_0:
# 675 "data/scripts/tarc3_accusation.pory"
	face_down
	step_end

# 767 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_PerfectTakeshi_Movement_0:
# 767 "data/scripts/tarc3_accusation.pory"
	face_left
	step_end

# 1156 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_WorstRoom_Movement_0:
# 1156 "data/scripts/tarc3_accusation.pory"
	walk_right
# 1156 "data/scripts/tarc3_accusation.pory"
	walk_right
# 1156 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1156 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1156 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1156 "data/scripts/tarc3_accusation.pory"
	walk_left
	step_end

# 1174 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_WorstIchiro_Movement_0:
# 1174 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1174 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1174 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1174 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1174 "data/scripts/tarc3_accusation.pory"
	walk_left
	step_end

# 1179 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_WorstIchiro_Movement_1:
# 1179 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1179 "data/scripts/tarc3_accusation.pory"
	walk_right
# 1179 "data/scripts/tarc3_accusation.pory"
	walk_right
# 1179 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1179 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1179 "data/scripts/tarc3_accusation.pory"
	walk_down
# 1179 "data/scripts/tarc3_accusation.pory"
	walk_left
	step_end

# 1258 "data/scripts/tarc3_accusation.pory"
tarc3_Accusation_EventScript_Depart_Movement_0:
# 1258 "data/scripts/tarc3_accusation.pory"
	walk_left
	step_end

tarc3_Accusation_EventScript_Begin_Text_0:
# 17 "data/scripts/tarc3_accusation.pory"
	.string "{RIVAL}$"

tarc3_Accusation_EventScript_Begin_Text_1:
# 18 "data/scripts/tarc3_accusation.pory"
	.string "Begin, {PLAYER} Edgeworth.\p"
	.string "They have wasted quite enough of my\n"
	.string "evening already.$"

tarc3_Accusation_EventScript_Naming_Text_0:
# 37 "data/scripts/tarc3_accusation.pory"
	.string "{PLAYER}$"

tarc3_Accusation_EventScript_Naming_Text_1:
# 38 "data/scripts/tarc3_accusation.pory"
	.string "Two men were killed aboard this ship\n"
	.string "tonight.\p"
	.string "A third was attacked in a darkened\n"
	.string "room.$"

tarc3_Accusation_EventScript_Naming_Text_2:
# 39 "data/scripts/tarc3_accusation.pory"
	.string "One person is responsible for the\n"
	.string "whole of it.\p"
	.string "I intend to name that person, and to\n"
	.string "demonstrate - with evidence, not\l"
	.string "intuition - that it could have been\l"
	.string "no one else.$"

tarc3_Accusation_EventScript_NameMenu_Text_0:
# 47 "data/scripts/tarc3_accusation.pory"
	.string "{FONT_NARROW}Whose name am I about to place before\n"
	.string "this room?$"

tarc3_Accusation_EventScript_NameMenu_Text_1:
# 49 "data/scripts/tarc3_accusation.pory"
	.string "Ichiro$"

tarc3_Accusation_EventScript_NameMenu_Text_2:
# 50 "data/scripts/tarc3_accusation.pory"
	.string "Takeshi$"

tarc3_Accusation_EventScript_NameMenu_Text_3:
# 54 "data/scripts/tarc3_accusation.pory"
	.string "{FONT_NARROW}Takeshi. Am I certain on this?$"

tarc3_Accusation_EventScript_NameMenu_Text_4:
# 62 "data/scripts/tarc3_accusation.pory"
	.string "{FONT_NARROW}Ichiro. Am I certain on this?$"

tarc3_Accusation_EventScript_NameIchiro_Text_0:
# 73 "data/scripts/tarc3_accusation.pory"
	.string "It was Ichiro.$"

tarc3_Accusation_EventScript_NameIchiro_Text_1:
# 87 "data/scripts/tarc3_accusation.pory"
	.string "Joji$"

tarc3_Accusation_EventScript_NameIchiro_Text_2:
# 88 "data/scripts/tarc3_accusation.pory"
	.string "No. No! Absolutely not.$"

tarc3_Accusation_EventScript_NameIchiro_Text_3:
# 89 "data/scripts/tarc3_accusation.pory"
	.string "Mariko$"

tarc3_Accusation_EventScript_NameIchiro_Text_4:
# 90 "data/scripts/tarc3_accusation.pory"
	.string "...The one who was stabbed?$"

tarc3_Accusation_EventScript_NameIchiro_Text_5:
# 91 "data/scripts/tarc3_accusation.pory"
	.string "Kitaro$"

tarc3_Accusation_EventScript_NameIchiro_Text_6:
# 92 "data/scripts/tarc3_accusation.pory"
	.string "{PLAYER}, we found him bleeding on\n"
	.string "a bathroom floor.$"

tarc3_Accusation_EventScript_NameIchiro_Text_7:
# 94 "data/scripts/tarc3_accusation.pory"
	.string "...$"

tarc3_Accusation_EventScript_NameIchiro_Text_8:
# 95 "data/scripts/tarc3_accusation.pory"
	.string "You are... mistaken.$"

tarc3_Accusation_EventScript_NameIchiro_Text_9:
# 97 "data/scripts/tarc3_accusation.pory"
	.string "Then permit me to lay out the facts\n"
	.string "of each of tonight's incidents. In\l"
	.string "order.$"

tarc3_Accusation_EventScript_NameTakeshi_Text_0:
# 107 "data/scripts/tarc3_accusation.pory"
	.string "It was Takeshi who killed Gozo.\p"
	.string "Tatsuo observed him disposing of\n"
	.string "the evidence afterwards. That was\l"
	.string "reason enough to kill him also.$"

tarc3_Accusation_EventScript_NameTakeshi_Text_1:
# 109 "data/scripts/tarc3_accusation.pory"
	.string "Finally. Thank you.$"

tarc3_Accusation_EventScript_NameTakeshi_Text_2:
# 110 "data/scripts/tarc3_accusation.pory"
	.string "Natsue$"

tarc3_Accusation_EventScript_NameTakeshi_Text_3:
# 111 "data/scripts/tarc3_accusation.pory"
	.string "He isn't even in the room! He can't\n"
	.string "answer you!$"

tarc3_Accusation_EventScript_NameTakeshi_Text_4:
# 112 "data/scripts/tarc3_accusation.pory"
	.string "You're accusing a man who isn't here\n"
	.string "to speak!$"

tarc3_Accusation_EventScript_NameTakeshi_Text_5:
# 117 "data/scripts/tarc3_accusation.pory"
	.string "...I'm here.$"

tarc3_Accusation_EventScript_NameTakeshi_Text_6:
# 118 "data/scripts/tarc3_accusation.pory"
	.string "Don't, Natsue. Don't attempt to\n"
	.string "defend a man who your family know is\l"
	.string "guilty.$"

tarc3_Accusation_EventScript_NameTakeshi_Text_7:
# 119 "data/scripts/tarc3_accusation.pory"
	.string "You're better than that. You always\n"
	.string "have been.$"

tarc3_Accusation_EventScript_NameTakeshi_Text_8:
# 121 "data/scripts/tarc3_accusation.pory"
	.string "I will present the evidence of four\n"
	.string "incidents, and demonstrate that you\l"
	.string "are the killer.$"

tarc3_Accusation_EventScript_NameTakeshi_Text_9:
# 123 "data/scripts/tarc3_accusation.pory"
	.string "Make your accusations. I know the\n"
	.string "truth.\p"
	.string "If you proceed down this path, a\n"
	.string "killer will walk free.$"

tarc3_Accusation_EventScript_Q1_Text_0:
# 160 "data/scripts/tarc3_accusation.pory"
	.string "First. Gozo.$"

tarc3_Accusation_EventScript_Q1SummaryBest_Text_0:
# 232 "data/scripts/tarc3_accusation.pory"
	.string "...All night I have asked for one\n"
	.string "answer about my father that holds.\l"
	.string "That was it.$"

tarc3_Accusation_EventScript_Q1SummaryBest_Text_1:
# 233 "data/scripts/tarc3_accusation.pory"
	.string "Suzuki$"

tarc3_Accusation_EventScript_Q1SummaryBest_Text_2:
# 234 "data/scripts/tarc3_accusation.pory"
	.string "Go on, {PLAYER}.$"

tarc3_Accusation_EventScript_Q1SummaryGood_Text_0:
# 243 "data/scripts/tarc3_accusation.pory"
	.string "...It holds together. I don't like it,\n"
	.string "but it holds.$"

tarc3_Accusation_EventScript_Q1SummaryGood_Text_1:
# 245 "data/scripts/tarc3_accusation.pory"
	.string "Keep going.$"

tarc3_Accusation_EventScript_Q1SummaryPoor_Text_0:
# 254 "data/scripts/tarc3_accusation.pory"
	.string "Loose facts, and no thread through\n"
	.string "any of them.$"

tarc3_Accusation_EventScript_Q1SummaryPoor_Text_1:
# 256 "data/scripts/tarc3_accusation.pory"
	.string "You'll need better than that before\n"
	.string "this night is done.$"

tarc3_Accusation_EventScript_Q1SummaryPoor_Text_2:
# 258 "data/scripts/tarc3_accusation.pory"
	.string "A collection of facts is not an\n"
	.string "argument, {PLAYER} Edgeworth.\p"
	.string "Do endeavour to connect them.$"

tarc3_Accusation_EventScript_Q1SummaryNone_Text_0:
# 267 "data/scripts/tarc3_accusation.pory"
	.string "Nothing you have said touches the\n"
	.string "man you named.$"

tarc3_Accusation_EventScript_Q1SummaryNone_Text_1:
# 269 "data/scripts/tarc3_accusation.pory"
	.string "She is correct, and that is\n"
	.string "intolerable.\p"
	.string "Correct it.$"

tarc3_Accusation_EventScript_Q1SummarySkipped_Text_0:
# 278 "data/scripts/tarc3_accusation.pory"
	.string "...I will return to that one.$"

tarc3_Accusation_EventScript_Q1SummarySkipped_Text_1:
# 280 "data/scripts/tarc3_accusation.pory"
	.string "You'll come back to it.$"

tarc3_Accusation_EventScript_Q1SummarySkipped_Text_2:
# 282 "data/scripts/tarc3_accusation.pory"
	.string "Postponement is not deduction.$"

tarc3_Accusation_EventScript_Q2_Text_0:
# 291 "data/scripts/tarc3_accusation.pory"
	.string "Second. How Tatsuo died.$"

tarc3_Accusation_EventScript_Q2SummaryGood_Text_0:
# 347 "data/scripts/tarc3_accusation.pory"
	.string "Akie$"

tarc3_Accusation_EventScript_Q2SummaryGood_Text_1:
# 348 "data/scripts/tarc3_accusation.pory"
	.string "...So he only saw something he\n"
	.string "shouldn't have. That's all it ever\l"
	.string "was.$"

tarc3_Accusation_EventScript_Q2SummaryGood_Text_2:
# 350 "data/scripts/tarc3_accusation.pory"
	.string "Continue, {PLAYER}.$"

tarc3_Accusation_EventScript_Q2SummaryPoor_Text_0:
# 359 "data/scripts/tarc3_accusation.pory"
	.string "An accomplice still explains more\n"
	.string "than anything you have offered.$"

tarc3_Accusation_EventScript_Q2SummaryPoor_Text_1:
# 361 "data/scripts/tarc3_accusation.pory"
	.string "Two questions, and not one decisive\n"
	.string "word from you.\p"
	.string "This is mediocrity, {PLAYER}\n"
	.string "Edgeworth.$"

tarc3_Accusation_EventScript_Q2SummaryNone_Text_0:
# 370 "data/scripts/tarc3_accusation.pory"
	.string "None of that was about Tatsuo.$"

tarc3_Accusation_EventScript_Q2SummaryNone_Text_1:
# 372 "data/scripts/tarc3_accusation.pory"
	.string "A foolishly foolish detour,\n"
	.string "{PLAYER} Edgeworth.\p"
	.string "The man is dead and you have said\n"
	.string "nothing of him. Keep to the\l"
	.string "question.$"

tarc3_Accusation_EventScript_Q2SummarySkipped_Text_0:
# 381 "data/scripts/tarc3_accusation.pory"
	.string "...I cannot answer this one.$"

tarc3_Accusation_EventScript_Q2SummarySkipped_Text_1:
# 383 "data/scripts/tarc3_accusation.pory"
	.string "No.$"

tarc3_Accusation_EventScript_Q2SummarySkipped_Text_2:
# 384 "data/scripts/tarc3_accusation.pory"
	.string "No, you don't get to do that. That\n"
	.string "one was my husband.$"

tarc3_Accusation_EventScript_Q2SummarySkipped_Text_3:
# 385 "data/scripts/tarc3_accusation.pory"
	.string "Say something about Tatsuo or don't\n"
	.string "say anything else, at all.$"

tarc3_Accusation_EventScript_Q2SummarySkipped_Text_4:
# 387 "data/scripts/tarc3_accusation.pory"
	.string "She is owed an answer, and I will not\n"
	.string "soften that.\p"
	.string "Provide one, or surrender the floor.$"

tarc3_Accusation_EventScript_Q3_Text_0:
# 396 "data/scripts/tarc3_accusation.pory"
	.string "Third. The lights.$"

tarc3_Accusation_EventScript_Q3SummaryBest_Text_0:
# 454 "data/scripts/tarc3_accusation.pory"
	.string "...Then it was never the wiring. I will\n"
	.string "not suggest it again.$"

tarc3_Accusation_EventScript_Q3SummaryGood_Text_0:
# 463 "data/scripts/tarc3_accusation.pory"
	.string "...I take your point.$"

tarc3_Accusation_EventScript_Q3SummaryPoor_Text_0:
# 472 "data/scripts/tarc3_accusation.pory"
	.string "This is an old ship, {PLAYER}. Old\n"
	.string "ships have old wiring.$"

tarc3_Accusation_EventScript_Q3SummaryPoor_Text_1:
# 474 "data/scripts/tarc3_accusation.pory"
	.string "So it was the man, or it was the\n"
	.string "weather. Wonderful.$"

tarc3_Accusation_EventScript_Q3SummaryPoor_Text_2:
# 476 "data/scripts/tarc3_accusation.pory"
	.string "Old wiring. That is what you have\n"
	.string "left this room with.\p"
	.string "My father would have had them in\n"
	.string "hand an hour ago.$"

tarc3_Accusation_EventScript_Q3SummaryNone_Text_0:
# 485 "data/scripts/tarc3_accusation.pory"
	.string "So the lights went out on their own,\n"
	.string "then.$"

tarc3_Accusation_EventScript_Q3SummaryNone_Text_1:
# 487 "data/scripts/tarc3_accusation.pory"
	.string "Three questions. Three failures.\p"
	.string "I did not cross an ocean to watch\n"
	.string "this.$"

tarc3_Accusation_EventScript_Q3SummarySkipped_Text_0:
# 496 "data/scripts/tarc3_accusation.pory"
	.string "The lights... I cannot account for.$"

tarc3_Accusation_EventScript_Q3SummarySkipped_Text_1:
# 498 "data/scripts/tarc3_accusation.pory"
	.string "Then we are all still in the dark. How\n"
	.string "appropriate.$"

tarc3_Accusation_EventScript_Q3SummarySkipped_Text_2:
# 500 "data/scripts/tarc3_accusation.pory"
	.string "Cannot.$"

tarc3_Accusation_EventScript_Q3SummarySkipped_Text_3:
# 501 "data/scripts/tarc3_accusation.pory"
	.string "There is a word I never expected to\n"
	.string "hear in your mouth.$"

tarc3_Accusation_EventScript_Q4_Text_0:
# 510 "data/scripts/tarc3_accusation.pory"
	.string "And finally.$"

tarc3_Accusation_EventScript_Q4_Text_1:
# 514 "data/scripts/tarc3_accusation.pory"
	.string "Who attacked Ichiro.$"

tarc3_Accusation_EventScript_Q4SummaryBest_Text_0:
# 576 "data/scripts/tarc3_accusation.pory"
	.string "Everyone in the room is waiting on\n"
	.string "Ichiro's response.$"

tarc3_Accusation_EventScript_Q4SummaryGood_Text_0:
# 584 "data/scripts/tarc3_accusation.pory"
	.string "...In the bathroom I said a man\n"
	.string "couldn't do that to himself.\p"
	.string "I am no longer certain I believe me.$"

tarc3_Accusation_EventScript_Q4SummaryPoor_Text_0:
# 593 "data/scripts/tarc3_accusation.pory"
	.string "You've proven nothing. Nothing at\n"
	.string "all.$"

tarc3_Accusation_EventScript_Q4SummaryPoor_Text_1:
# 596 "data/scripts/tarc3_accusation.pory"
	.string "For once, {PLAYER} Edgeworth, I\n"
	.string "have nothing to add to that.$"

tarc3_Accusation_EventScript_Q4SummaryNone_Text_0:
# 605 "data/scripts/tarc3_accusation.pory"
	.string "And that was the last of your\n"
	.string "questions.$"

tarc3_Accusation_EventScript_Q4SummaryNone_Text_1:
# 607 "data/scripts/tarc3_accusation.pory"
	.string "Four questions, and a foolish fool\n"
	.string "has answered none of them.\p"
	.string "You have humiliated us both.$"

tarc3_Accusation_EventScript_Q4SummarySkipped_Text_0:
# 616 "data/scripts/tarc3_accusation.pory"
	.string "That was the last one, wasn't it.$"

tarc3_Accusation_EventScript_Q4SummarySkipped_Text_1:
# 617 "data/scripts/tarc3_accusation.pory"
	.string "That was your last question, and you\n"
	.string "didn't even attempt to answer it?$"

tarc3_Accusation_EventScript_Q4SummarySkipped_Text_2:
# 619 "data/scripts/tarc3_accusation.pory"
	.string "Do not look to me. You built this.$"

tarc3_Accusation_EventScript_Q4SummarySkipped_Text_3:
# 620 "data/scripts/tarc3_accusation.pory"
	.string "Stand in it.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_0:
# 667 "data/scripts/tarc3_accusation.pory"
	.string "I have Ichiro's sketchbook, and I do\n"
	.string "not intend to open it.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_1:
# 668 "data/scripts/tarc3_accusation.pory"
	.string "There is no need.\p"
	.string "Everyone in this room will learn what\n"
	.string "it contains - and it will not be from\l"
	.string "me.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_2:
# 679 "data/scripts/tarc3_accusation.pory"
	.string "It's drawings. Four years of them.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_3:
# 680 "data/scripts/tarc3_accusation.pory"
	.string "All the same person.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_4:
# 681 "data/scripts/tarc3_accusation.pory"
	.string "Natsue. Don't look at me. Please.\n"
	.string "Just... don't.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_5:
# 682 "data/scripts/tarc3_accusation.pory"
	.string "I asked him one year ago.\p"
	.string "I wrote it down beforehand so I\n"
	.string "wouldn't stumble over it.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_6:
# 683 "data/scripts/tarc3_accusation.pory"
	.string "He was polite. He waited until I'd\n"
	.string "said the whole thing.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_7:
# 684 "data/scripts/tarc3_accusation.pory"
	.string "'A local boy with borrowed tuition\n"
	.string "and a half-finished art career.'$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_8:
# 685 "data/scripts/tarc3_accusation.pory"
	.string "'Son, know your place.'$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_9:
# 689 "data/scripts/tarc3_accusation.pory"
	.string "I thanked him.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_10:
# 690 "data/scripts/tarc3_accusation.pory"
	.string "I thanked him, I left the room, and I\n"
	.string "never mentioned it again.\p"
	.string "Not to him. Not to anybody.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_11:
# 691 "data/scripts/tarc3_accusation.pory"
	.string "He announced her engagement to\n"
	.string "Takeshi the same week.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_12:
# 694 "data/scripts/tarc3_accusation.pory"
	.string "...I remember seeing you that week.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_13:
# 695 "data/scripts/tarc3_accusation.pory"
	.string "I thought you were ill.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_14:
# 697 "data/scripts/tarc3_accusation.pory"
	.string "You want to know what I am to this\n"
	.string "family? I can give you the figure.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_15:
# 698 "data/scripts/tarc3_accusation.pory"
	.string "I am not a close friend. I'm an\n"
	.string "expense.\p"
	.string "A plaything, one you might bring on a\n"
	.string "trip to Hoenn or Galar.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_16:
# 699 "data/scripts/tarc3_accusation.pory"
	.string "I was counting what I owed. $500,000\n"
	.string "per year.$"

tarc3_Accusation_EventScript_PerfectAnswer_Text_17:
# 700 "data/scripts/tarc3_accusation.pory"
	.string "He got eleven years of a person for\n"
	.string "it.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_0:
# 709 "data/scripts/tarc3_accusation.pory"
	.string "Akie. I must open your closet.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_1:
# 711 "data/scripts/tarc3_accusation.pory"
	.string "...What?$"

tarc3_Accusation_EventScript_PerfectCloset_Text_2:
# 713 "data/scripts/tarc3_accusation.pory"
	.string "You should have been told the\n"
	.string "moment I found him. You were not.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_3:
# 715 "data/scripts/tarc3_accusation.pory"
	.string "You searched my cabin.\p"
	.string "You opened that door, and you\n"
	.string "closed it again, and you said\l"
	.string "nothing to me.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_4:
# 717 "data/scripts/tarc3_accusation.pory"
	.string "Yes.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_5:
# 719 "data/scripts/tarc3_accusation.pory"
	.string "My husband is on the foredeck under\n"
	.string "a tablecloth, and you walked out of\l"
	.string "my room without a word.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_6:
# 721 "data/scripts/tarc3_accusation.pory"
	.string "I did. This room had to hear the case\n"
	.string "before it heard him, and I do not\l"
	.string "retract that judgement.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_7:
# 722 "data/scripts/tarc3_accusation.pory"
	.string "That does not make it a small thing\n"
	.string "to have done to you.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_8:
# 727 "data/scripts/tarc3_accusation.pory"
	.string "Takeshi...$"

tarc3_Accusation_EventScript_PerfectCloset_Text_9:
# 729 "data/scripts/tarc3_accusation.pory"
	.string "He's been in this cabin the entire\n"
	.string "time.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_10:
# 731 "data/scripts/tarc3_accusation.pory"
	.string "How long have you known?$"

tarc3_Accusation_EventScript_PerfectCloset_Text_11:
# 733 "data/scripts/tarc3_accusation.pory"
	.string "Since I searched this deck. He hid\n"
	.string "himself there hours before that,\l"
	.string "and told no one.$"

tarc3_Accusation_EventScript_PerfectCloset_Text_12:
# 735 "data/scripts/tarc3_accusation.pory"
	.string "Let the boy speak.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_0:
# 744 "data/scripts/tarc3_accusation.pory"
	.string "Do you still want revenge?$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_1:
# 746 "data/scripts/tarc3_accusation.pory"
	.string "...No.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_2:
# 747 "data/scripts/tarc3_accusation.pory"
	.string "But you should hear the whole story,\n"
	.string "and you should hear it from me.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_3:
# 749 "data/scripts/tarc3_accusation.pory"
	.string "{PLAYER} showed you a piece of it\n"
	.string "tonight. This is the whole of it.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_4:
# 751 "data/scripts/tarc3_accusation.pory"
	.string "My father was Isao Zaiki.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_5:
# 752 "data/scripts/tarc3_accusation.pory"
	.string "As you know, Hatamoto Corp took his\n"
	.string "company. He killed himself the\l"
	.string "spring after. I was fifteen.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_6:
# 753 "data/scripts/tarc3_accusation.pory"
	.string "I joined the Corporation under a\n"
	.string "name that wasn't mine, and I did it\l"
	.string "to take something from your\l"
	.string "grandfather.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_7:
# 754 "data/scripts/tarc3_accusation.pory"
	.string "Then I worked beside you, Natsue.\p"
	.string "I fell hopelessly in love.\p"
	.string "I slowly lost interest in revenge.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_8:
# 755 "data/scripts/tarc3_accusation.pory"
	.string "Gozo called me into that cabin\n"
	.string "before dinner because he knew.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_9:
# 757 "data/scripts/tarc3_accusation.pory"
	.string "He knew?$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_10:
# 759 "data/scripts/tarc3_accusation.pory"
	.string "For months. He had all of it. The\n"
	.string "name, my father, the year I joined.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_11:
# 760 "data/scripts/tarc3_accusation.pory"
	.string "He looked at me and he said, 'I see\n"
	.string "the man Natsue chose.'$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_12:
# 761 "data/scripts/tarc3_accusation.pory"
	.string "Then he told me to sit down and eat\n"
	.string "with his family.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_13:
# 771 "data/scripts/tarc3_accusation.pory"
	.string "...So why you.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_14:
# 772 "data/scripts/tarc3_accusation.pory"
	.string "I did everything he asked of me. I\n"
	.string "never asked him twice.\p"
	.string "I said thank you, and I left the\n"
	.string "room.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_15:
# 773 "data/scripts/tarc3_accusation.pory"
	.string "Why you, and not me?\p"
	.string "It isn't fair.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_16:
# 775 "data/scripts/tarc3_accusation.pory"
	.string "...No. It isn't.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_17:
# 776 "data/scripts/tarc3_accusation.pory"
	.string "You still didn't have to kill him.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_18:
# 780 "data/scripts/tarc3_accusation.pory"
	.string "Suzuki. Make arrangements with the\n"
	.string "police for when we arrive.$"

tarc3_Accusation_EventScript_PerfectTakeshi_Text_19:
# 783 "data/scripts/tarc3_accusation.pory"
	.string "...Madam.$"

tarc3_Accusation_EventScript_GoodAnswer_Text_0:
# 796 "data/scripts/tarc3_accusation.pory"
	.string "Well?$"

tarc3_Accusation_EventScript_GoodAnswer_Text_1:
# 798 "data/scripts/tarc3_accusation.pory"
	.string "...You're right.$"

tarc3_Accusation_EventScript_GoodAnswer_Text_2:
# 799 "data/scripts/tarc3_accusation.pory"
	.string "About all of it.$"

tarc3_Accusation_EventScript_GoodAnswer_Text_3:
# 801 "data/scripts/tarc3_accusation.pory"
	.string "Ichiro...$"

tarc3_Accusation_EventScript_GoodAnswer_Text_4:
# 803 "data/scripts/tarc3_accusation.pory"
	.string "I killed him.\p"
	.string "I killed Tatsuo as well - he saw me\n"
	.string "at the rail and he called out to me.$"

tarc3_Accusation_EventScript_GoodAnswer_Text_5:
# 804 "data/scripts/tarc3_accusation.pory"
	.string "You can all stop looking at Takeshi.$"

tarc3_Accusation_EventScript_GoodAnswer_Text_6:
# 806 "data/scripts/tarc3_accusation.pory"
	.string "But why? In Arceus' name, why?$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_0:
# 829 "data/scripts/tarc3_accusation.pory"
	.string "...It was the money.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_1:
# 830 "data/scripts/tarc3_accusation.pory"
	.string "Eleven years he paid for me, and he\n"
	.string "never let a month go past without\l"
	.string "reminding me of it.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_2:
# 831 "data/scripts/tarc3_accusation.pory"
	.string "On the deck he told you he was\n"
	.string "finished.\p"
	.string "He said it where I could hear him\n"
	.string "because he wanted me to hear him.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_3:
# 832 "data/scripts/tarc3_accusation.pory"
	.string "Two terms left and nothing behind\n"
	.string "me. I'd have gone home with nothing.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_4:
# 835 "data/scripts/tarc3_accusation.pory"
	.string "You killed my father over school\n"
	.string "fees.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_5:
# 839 "data/scripts/tarc3_accusation.pory"
	.string "Arceus help us.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_6:
# 847 "data/scripts/tarc3_accusation.pory"
	.string "{FONT_NARROW}That is not it.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_7:
# 850 "data/scripts/tarc3_accusation.pory"
	.string "{FONT_NARROW}That was never it - but the evidence I\n"
	.string "presented did not tell the full story.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_8:
# 854 "data/scripts/tarc3_accusation.pory"
	.string "That is not the whole reason.$"

tarc3_Accusation_EventScript_GoodMotiveKept_Text_9:
# 856 "data/scripts/tarc3_accusation.pory"
	.string "It's why.$"

tarc3_Accusation_EventScript_GoodMotiveDenied_Text_0:
# 866 "data/scripts/tarc3_accusation.pory"
	.string "...Money.$"

tarc3_Accusation_EventScript_GoodMotiveDenied_Text_1:
# 868 "data/scripts/tarc3_accusation.pory"
	.string "Money.$"

tarc3_Accusation_EventScript_GoodMotiveDenied_Text_2:
# 869 "data/scripts/tarc3_accusation.pory"
	.string "We all heard what it was, Ichiro.\n"
	.string "Every one of us, standing in this\l"
	.string "room.$"

tarc3_Accusation_EventScript_GoodMotiveDenied_Text_3:
# 871 "data/scripts/tarc3_accusation.pory"
	.string "You heard about some drawings.$"

tarc3_Accusation_EventScript_GoodMotiveDenied_Text_4:
# 872 "data/scripts/tarc3_accusation.pory"
	.string "Boys draw.\p"
	.string "It was money.$"

tarc3_Accusation_EventScript_GoodMotiveDenied_Text_5:
# 878 "data/scripts/tarc3_accusation.pory"
	.string "{FONT_NARROW}He will deny her to the last.$"

tarc3_Accusation_EventScript_GoodAnswerEnough_Text_0:
# 889 "data/scripts/tarc3_accusation.pory"
	.string "...Isn't it enough? You've got what\n"
	.string "you came for.$"

tarc3_Accusation_EventScript_GoodAnswerEnough_Text_1:
# 891 "data/scripts/tarc3_accusation.pory"
	.string "Let it be enough, {PLAYER}.$"

tarc3_Accusation_EventScript_GoodCloset_Text_0:
# 900 "data/scripts/tarc3_accusation.pory"
	.string "One further matter. Akie - your\n"
	.string "closet.\p"
	.string "I found Takeshi in it before I called\n"
	.string "you all in here. You should have been\l"
	.string "told then.$"

tarc3_Accusation_EventScript_GoodCloset_Text_1:
# 902 "data/scripts/tarc3_accusation.pory"
	.string "...Do what you like. It hardly matters\n"
	.string "now.$"

tarc3_Accusation_EventScript_GoodCloset_Text_2:
# 907 "data/scripts/tarc3_accusation.pory"
	.string "...Of course he was.$"

tarc3_Accusation_EventScript_GoodCloset_Text_3:
# 909 "data/scripts/tarc3_accusation.pory"
	.string "Nobody asks Takeshi anything. They\n"
	.string "have their killer, and they have\l"
	.string "stopped listening.$"

tarc3_Accusation_EventScript_GoodCloset_Text_4:
# 911 "data/scripts/tarc3_accusation.pory"
	.string "Takeshi.$"

tarc3_Accusation_EventScript_GoodCloset_Text_5:
# 913 "data/scripts/tarc3_accusation.pory"
	.string "...Not here.$"

tarc3_Accusation_EventScript_GoodStern_Text_0:
# 933 "data/scripts/tarc3_accusation.pory"
	.string "Later, at the stern rail. Only the\n"
	.string "four of them. The family stayed\l"
	.string "below.$"

tarc3_Accusation_EventScript_GoodStern_Text_1:
# 937 "data/scripts/tarc3_accusation.pory"
	.string "...No. Not since the first month I\n"
	.string "worked beside you.$"

tarc3_Accusation_EventScript_GoodStern_Text_2:
# 938 "data/scripts/tarc3_accusation.pory"
	.string "My father was Isao Zaiki.\p"
	.string "Hatamoto Corp took his company and\n"
	.string "he killed himself the spring after.$"

tarc3_Accusation_EventScript_GoodStern_Text_3:
# 939 "data/scripts/tarc3_accusation.pory"
	.string "I joined under a name that wasn't\n"
	.string "mine because I meant to take\l"
	.string "something from your grandfather.$"

tarc3_Accusation_EventScript_GoodStern_Text_4:
# 943 "data/scripts/tarc3_accusation.pory"
	.string "He knew before dinner. He'd known\n"
	.string "for months.$"

tarc3_Accusation_EventScript_GoodStern_Text_5:
# 945 "data/scripts/tarc3_accusation.pory"
	.string "And he said nothing?$"

tarc3_Accusation_EventScript_GoodStern_Text_6:
# 947 "data/scripts/tarc3_accusation.pory"
	.string "He said, 'I see the man Natsue\n"
	.string "chose.' Then he told me to go and\l"
	.string "eat.$"

tarc3_Accusation_EventScript_GoodStern_Text_7:
# 950 "data/scripts/tarc3_accusation.pory"
	.string "That's the kindest thing he ever\n"
	.string "did.$"

tarc3_Accusation_EventScript_GoodStern_Text_8:
# 951 "data/scripts/tarc3_accusation.pory"
	.string "And he did it where nobody could see\n"
	.string "it.$"

tarc3_Accusation_EventScript_BadAnswer_Text_0:
# 963 "data/scripts/tarc3_accusation.pory"
	.string "May I?$"

tarc3_Accusation_EventScript_BadAnswer_Text_1:
# 968 "data/scripts/tarc3_accusation.pory"
	.string "The crumbs. In the blood, by the\n"
	.string "door. That's the one you keep coming\l"
	.string "back to.$"

tarc3_Accusation_EventScript_BadAnswer_Text_2:
# 969 "data/scripts/tarc3_accusation.pory"
	.string "I've sketched on the salon deck\n"
	.string "every day since Florio. In the same\l"
	.string "chair.$"

tarc3_Accusation_EventScript_BadAnswer_Text_3:
# 970 "data/scripts/tarc3_accusation.pory"
	.string "Suzuki. Is that chair cleared each\n"
	.string "evening?$"

tarc3_Accusation_EventScript_BadAnswer_Text_4:
# 972 "data/scripts/tarc3_accusation.pory"
	.string "...It is.$"

tarc3_Accusation_EventScript_BadAnswer_Text_5:
# 974 "data/scripts/tarc3_accusation.pory"
	.string "Then it's anyone's shoe. Any one of\n"
	.string "you. Including me, walking to dinner.$"

tarc3_Accusation_EventScript_BadAnswer_Text_6:
# 975 "data/scripts/tarc3_accusation.pory"
	.string "You should also know the bread I use\n"
	.string "goes hard inside a day.$"

tarc3_Accusation_EventScript_BadAnswer_Text_7:
# 976 "data/scripts/tarc3_accusation.pory"
	.string "If the crumb you found was dry, it\n"
	.string "didn't come off my cuff tonight.$"

tarc3_Accusation_EventScript_BadAnswer_Text_8:
# 980 "data/scripts/tarc3_accusation.pory"
	.string "I'm trying to help you.$"

tarc3_Accusation_EventScript_BadAnswer_Text_9:
# 981 "data/scripts/tarc3_accusation.pory"
	.string "I want the man who did this as much\n"
	.string "as anyone in this room does.$"

tarc3_Accusation_EventScript_BadAnswerGeneric_Text_0:
# 992 "data/scripts/tarc3_accusation.pory"
	.string "Whatever you found, ask where else\n"
	.string "it could have come from. That's all\l"
	.string "I'd say.$"

tarc3_Accusation_EventScript_BadAnswerGeneric_Text_1:
# 993 "data/scripts/tarc3_accusation.pory"
	.string "Nine people have walked every\n"
	.string "corridor on this ship tonight.\p"
	.string "Eight of them are standing in this\n"
	.string "room.$"

tarc3_Accusation_EventScript_BadAnswerGeneric_Text_2:
# 994 "data/scripts/tarc3_accusation.pory"
	.string "Suzuki. When are the decks swept?$"

tarc3_Accusation_EventScript_BadAnswerGeneric_Text_3:
# 996 "data/scripts/tarc3_accusation.pory"
	.string "...Each evening.$"

tarc3_Accusation_EventScript_BadAnswerGeneric_Text_4:
# 998 "data/scripts/tarc3_accusation.pory"
	.string "I sketch on the salon deck every\n"
	.string "day, in the same chair.\p"
	.string "Anything I've touched could ride to\n"
	.string "a doorway on somebody's shoe.$"

tarc3_Accusation_EventScript_BadNearMissBook_Text_0:
# 1024 "data/scripts/tarc3_accusation.pory"
	.string "Then let us discuss the sketchbook\n"
	.string "I took from your cabin.$"

tarc3_Accusation_EventScript_BadNearMissBook_Text_1:
# 1035 "data/scripts/tarc3_accusation.pory"
	.string "That's enough.$"

tarc3_Accusation_EventScript_BadNearMissBook_Text_2:
# 1042 "data/scripts/tarc3_accusation.pory"
	.string "...That's my sketchbook, yes.$"

tarc3_Accusation_EventScript_BadNearMissBook_Text_3:
# 1043 "data/scripts/tarc3_accusation.pory"
	.string "I draw people. I'm an art student.$"

tarc3_Accusation_EventScript_BadWall_Text_0:
# 1051 "data/scripts/tarc3_accusation.pory"
	.string "He's had enough from this family for\n"
	.string "one voyage. Leave him be.$"

tarc3_Accusation_EventScript_BadWall_Text_1:
# 1055 "data/scripts/tarc3_accusation.pory"
	.string "{FONT_NARROW}He said that to me two hours ago, in the\n"
	.string "dining room.$"

tarc3_Accusation_EventScript_BadWall_Text_2:
# 1059 "data/scripts/tarc3_accusation.pory"
	.string "My father is dead. Tatsuo is dead.$"

tarc3_Accusation_EventScript_BadWall_Text_3:
# 1060 "data/scripts/tarc3_accusation.pory"
	.string "And I have spent six hours of my\n"
	.string "life waiting on you.$"

tarc3_Accusation_EventScript_BadWall_Text_4:
# 1061 "data/scripts/tarc3_accusation.pory"
	.string "Whatever you are where you come\n"
	.string "from, you are nothing here.\p"
	.string "You are a passenger my niece took\n"
	.string "pity on at a dock.$"

tarc3_Accusation_EventScript_BadWall_Text_5:
# 1062 "data/scripts/tarc3_accusation.pory"
	.string "Whoever told you that you were\n"
	.string "clever lied to you.$"

tarc3_Accusation_EventScript_BadCloset_Text_0:
# 1071 "data/scripts/tarc3_accusation.pory"
	.string "There is one more thing, and you had\n"
	.string "better hear it from me.$"

tarc3_Accusation_EventScript_BadCloset_Text_1:
# 1072 "data/scripts/tarc3_accusation.pory"
	.string "Takeshi is in this room. He is behind\n"
	.string "that closet door.$"

tarc3_Accusation_EventScript_BadCloset_Text_2:
# 1076 "data/scripts/tarc3_accusation.pory"
	.string "...In my closet.$"

tarc3_Accusation_EventScript_BadCloset_Text_3:
# 1077 "data/scripts/tarc3_accusation.pory"
	.string "He has been standing in my closet\n"
	.string "while we all stood here.$"

tarc3_Accusation_EventScript_BadCloset_Text_4:
# 1079 "data/scripts/tarc3_accusation.pory"
	.string "I found him when I searched these\n"
	.string "cabins, shortly before I asked you\l"
	.string "all to gather.$"

tarc3_Accusation_EventScript_BadCloset_Text_5:
# 1081 "data/scripts/tarc3_accusation.pory"
	.string "You found him.$"

tarc3_Accusation_EventScript_BadCloset_Text_6:
# 1082 "data/scripts/tarc3_accusation.pory"
	.string "You found him, and you said nothing.$"

tarc3_Accusation_EventScript_BadCloset_Text_7:
# 1084 "data/scripts/tarc3_accusation.pory"
	.string "He was in fear of his life. He asked\n"
	.string "me to prove it before I called\l"
	.string "anyone, and I judged...$"

tarc3_Accusation_EventScript_BadCloset_Text_8:
# 1086 "data/scripts/tarc3_accusation.pory"
	.string "You knew where he was, and you let\n"
	.string "us stand here.\p"
	.string "You pointed at every one of us with\n"
	.string "the man behind that door.$"

tarc3_Accusation_EventScript_BadCloset_Text_9:
# 1091 "data/scripts/tarc3_accusation.pory"
	.string "Don't. He was helping me.$"

tarc3_Accusation_EventScript_BadCloset_Text_10:
# 1093 "data/scripts/tarc3_accusation.pory"
	.string "Yes. I'm sure he was.$"

tarc3_Accusation_EventScript_BadCloset_Text_11:
# 1094 "data/scripts/tarc3_accusation.pory"
	.string "There's your accomplice, Suzuki.$"

tarc3_Accusation_EventScript_BadCloset_Text_12:
# 1095 "data/scripts/tarc3_accusation.pory"
	.string "He kept him for exactly as long as it\n"
	.string "suited him, and produced him the\l"
	.string "moment it did not.$"

tarc3_Accusation_EventScript_BadCloset_Text_13:
# 1100 "data/scripts/tarc3_accusation.pory"
	.string "I asked you to find him, {PLAYER}.$"

tarc3_Accusation_EventScript_BadCloset_Text_14:
# 1101 "data/scripts/tarc3_accusation.pory"
	.string "You found him, and you did not tell\n"
	.string "me.$"

tarc3_Accusation_EventScript_BadCloset_Text_15:
# 1102 "data/scripts/tarc3_accusation.pory"
	.string "...I think you had better go up on\n"
	.string "deck.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_0:
# 1115 "data/scripts/tarc3_accusation.pory"
	.string "Well? Say something. Anything at all.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_1:
# 1117 "data/scripts/tarc3_accusation.pory"
	.string "...There is a part of this you don't\n"
	.string "have.\p"
	.string "You should hear it from me, and not\n"
	.string "read it somewhere in a year.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_2:
# 1119 "data/scripts/tarc3_accusation.pory"
	.string "You heard tonight what Gozo did to\n"
	.string "my father. This is the rest of it.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_3:
# 1121 "data/scripts/tarc3_accusation.pory"
	.string "You know my father was Isao Zaiki.\p"
	.string "Hatamoto Corp took his company and\n"
	.string "he killed himself the spring after.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_4:
# 1122 "data/scripts/tarc3_accusation.pory"
	.string "I was fifteen.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_5:
# 1123 "data/scripts/tarc3_accusation.pory"
	.string "I joined the Corporation under a\n"
	.string "name that wasn't mine, to take\l"
	.string "something from your grandfather.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_6:
# 1125 "data/scripts/tarc3_accusation.pory"
	.string "...Arceus help us.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_7:
# 1129 "data/scripts/tarc3_accusation.pory"
	.string "Gozo called me into his cabin before\n"
	.string "dinner and told me he had known for\l"
	.string "months.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_8:
# 1131 "data/scripts/tarc3_accusation.pory"
	.string "He knew. And an hour later he was\n"
	.string "dead.$"

tarc3_Accusation_EventScript_WorstAnswer_Text_9:
# 1132 "data/scripts/tarc3_accusation.pory"
	.string "Do you hear yourself?$"

tarc3_Accusation_EventScript_WorstAnswer_Text_10:
# 1135 "data/scripts/tarc3_accusation.pory"
	.string "I hear myself.$"

tarc3_Accusation_EventScript_WorstRoom_Text_0:
# 1144 "data/scripts/tarc3_accusation.pory"
	.string "...I'm sorry. I can't. I can't stand\n"
	.string "here and say it isn't true.$"

tarc3_Accusation_EventScript_WorstRoom_Text_1:
# 1146 "data/scripts/tarc3_accusation.pory"
	.string "I don't care.$"

tarc3_Accusation_EventScript_WorstRoom_Text_2:
# 1147 "data/scripts/tarc3_accusation.pory"
	.string "My husband is on the deck under a\n"
	.string "tablecloth. Somebody put him there.\p"
	.string "If it's him, it's him.$"

tarc3_Accusation_EventScript_WorstIchiro_Text_0:
# 1166 "data/scripts/tarc3_accusation.pory"
	.string "Natsue.$"

tarc3_Accusation_EventScript_WorstIchiro_Text_1:
# 1167 "data/scripts/tarc3_accusation.pory"
	.string "Let me walk you back to your cabin.$"

tarc3_Accusation_EventScript_WorstIchiro_Text_2:
# 1168 "data/scripts/tarc3_accusation.pory"
	.string "You shouldn't have to watch this\n"
	.string "part.$"

tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_0:
# 1193 "data/scripts/tarc3_accusation.pory"
	.string "Well. There it is.$"

tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_1:
# 1195 "data/scripts/tarc3_accusation.pory"
	.string "There what is, madam?$"

tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_2:
# 1197 "data/scripts/tarc3_accusation.pory"
	.string "You heard the case.$"

tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_3:
# 1199 "data/scripts/tarc3_accusation.pory"
	.string "I heard a flower and a grudge.$"

tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_4:
# 1200 "data/scripts/tarc3_accusation.pory"
	.string "I bolted a man into a storeroom once\n"
	.string "tonight on the strength of that\l"
	.string "flower.\p"
	.string "I will not do it twice.$"

tarc3_Accusation_EventScript_WorstRefusedAnswer_Text_5:
# 1202 "data/scripts/tarc3_accusation.pory"
	.string "...He's right, Mariko. There is nothing\n"
	.string "here a court would touch.$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_0:
# 1211 "data/scripts/tarc3_accusation.pory"
	.string "You should still hear the rest of it.\n"
	.string "All of you.$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_1:
# 1213 "data/scripts/tarc3_accusation.pory"
	.string "You heard tonight what Gozo did to\n"
	.string "my father. Here is the rest.$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_2:
# 1215 "data/scripts/tarc3_accusation.pory"
	.string "You know my father was Isao Zaiki.$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_3:
# 1216 "data/scripts/tarc3_accusation.pory"
	.string "Gozo ruined him, and I joined this\n"
	.string "company under a false name to take\l"
	.string "something back.$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_4:
# 1218 "data/scripts/tarc3_accusation.pory"
	.string "There! Out of his own mouth!$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_5:
# 1220 "data/scripts/tarc3_accusation.pory"
	.string "A name is not a knife, madam.$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_6:
# 1226 "data/scripts/tarc3_accusation.pory"
	.string "I don't care what he wanted.$"

tarc3_Accusation_EventScript_WorstRefusedTakeshi_Text_7:
# 1227 "data/scripts/tarc3_accusation.pory"
	.string "My husband is under a tablecloth on\n"
	.string "that deck, and not one of you can\l"
	.string "tell me who put him there.$"

tarc3_Accusation_EventScript_Depart_Text_0:
# 1264 "data/scripts/tarc3_accusation.pory"
	.string "Well. The room is empty, and there is\n"
	.string "nobody left to perform for.$"

tarc3_Accusation_EventScript_Depart_Text_1:
# 1265 "data/scripts/tarc3_accusation.pory"
	.string "You may stop standing like that.$"

tarc3_Accusation_EventScript_Depart_Text_2:
# 1274 "data/scripts/tarc3_accusation.pory"
	.string "...There. The harbour.$"

tarc3_Accusation_EventScript_Depart_Text_3:
# 1275 "data/scripts/tarc3_accusation.pory"
	.string "Gather yourself, {PLAYER}\n"
	.string "Edgeworth.\p"
	.string "It is time to depart.$"
