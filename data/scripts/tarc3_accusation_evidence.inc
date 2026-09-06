tarc3_Accusation_EventScript_ScoreIchiroT1::
# 9 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_ScoreIchiroT1_2
tarc3_Accusation_EventScript_ScoreIchiroT1_1:
	return

tarc3_Accusation_EventScript_ScoreIchiroT1_2:
# 10 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 2
# 11 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 2
	goto tarc3_Accusation_EventScript_ScoreIchiroT1_1


tarc3_Accusation_EventScript_ScoreIchiroT2::
# 17 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_ScoreIchiroT2_2
tarc3_Accusation_EventScript_ScoreIchiroT2_1:
	return

tarc3_Accusation_EventScript_ScoreIchiroT2_2:
# 18 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 5
# 19 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 5
# 20 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_HITS, 1
	goto tarc3_Accusation_EventScript_ScoreIchiroT2_1


tarc3_Accusation_EventScript_ScoreIchiroT3::
# 26 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_ScoreIchiroT3_2
tarc3_Accusation_EventScript_ScoreIchiroT3_1:
	return

tarc3_Accusation_EventScript_ScoreIchiroT3_2:
# 27 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 13
# 28 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 13
# 29 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_HITS, 1
	goto tarc3_Accusation_EventScript_ScoreIchiroT3_1


tarc3_Accusation_EventScript_ScoreTakeshiT1::
# 35 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_ScoreTakeshiT1_2
tarc3_Accusation_EventScript_ScoreTakeshiT1_1:
	return

tarc3_Accusation_EventScript_ScoreTakeshiT1_2:
# 36 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 2
# 37 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 2
	goto tarc3_Accusation_EventScript_ScoreTakeshiT1_1


tarc3_Accusation_EventScript_ScoreTakeshiT2::
# 43 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_ScoreTakeshiT2_2
tarc3_Accusation_EventScript_ScoreTakeshiT2_1:
	return

tarc3_Accusation_EventScript_ScoreTakeshiT2_2:
# 44 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 5
# 45 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 5
# 46 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_HITS, 1
	goto tarc3_Accusation_EventScript_ScoreTakeshiT2_1


tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1::
# 54 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_2
tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_2:
# 55 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 56 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_1
# 57 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_2
# 58 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 59 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 60 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_1


tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2::
# 66 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_2
tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_2:
# 67 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 68 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_0
# 69 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_1
# 70 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 71 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 72 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_1


tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1::
# 78 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_2
tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_2:
# 79 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 80 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_Text_0
# 81 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 82 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 83 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_1


tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2::
# 89 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_2
tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_2:
# 90 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 91 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_0
# 92 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_1
# 93 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 94 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 95 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_1


tarc3_Accusation_EventScript_Fz_OffQuestion::
# 103 "data/scripts/tarc3_accusation_evidence.pory"
	evidencetoitem VAR_RESULT
# 104 "data/scripts/tarc3_accusation_evidence.pory"
	bufferitemname STR_VAR_1, VAR_RESULT
# 105 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 106 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffQuestion_Text_0
# 107 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffQuestion_Text_1
# 108 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 109 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 110 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_RawClue::
# 117 "data/scripts/tarc3_accusation_evidence.pory"
	evidencetoitem VAR_RESULT
# 118 "data/scripts/tarc3_accusation_evidence.pory"
	bufferitemname STR_VAR_1, VAR_RESULT
# 119 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 120 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RawClue_Text_1
# 121 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 122 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RawClue_Text_2
# 123 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 124 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 125 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_Sketchbook::
# 132 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 133 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 134 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_0
# 135 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 136 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 137 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 138 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_4
# 139 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 140 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 141 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 142 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_RefusedSuitor::
# 147 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 148 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 149 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_0
# 150 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 151 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_2
# 152 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 153 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 154 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 155 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TuitionFunds::
# 160 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 161 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 162 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_0
# 163 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 164 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_2
# 165 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 166 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 167 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 168 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_IchiroSponsorship::
# 173 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 174 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 175 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_0
# 176 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 177 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_2
# 178 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 179 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 180 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 181 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_BreadEraser::
# 186 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 187 "data/scripts/tarc3_accusation_evidence.pory"
	setflag FLAG_TARC3_ACCUSE_CRUMBS
# 188 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 189 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_0
# 190 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 191 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_1
# 192 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 193 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_2
# 194 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 195 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_3
# 196 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_4
# 197 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 198 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 199 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_UnrequitedLove::
# 204 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 205 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 206 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_0
# 207 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 208 "data/scripts/tarc3_accusation_evidence.pory"
	delay 30
# 209 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_Ev_UnrequitedLove_Movement_0
# 210 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 211 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 212 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 213 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_1
# 214 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 215 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 216 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 217 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 218 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 219 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal::
# 224 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 225 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 226 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_0
# 227 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 228 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_1
# 229 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 230 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_2
# 231 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 232 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 233 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 234 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor::
# 239 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 240 "data/scripts/tarc3_accusation_evidence.pory"
	setflag FLAG_TARC3_ACCUSE_CRUMBS
# 241 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 242 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_0
# 243 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 244 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_1
# 245 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 246 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_2
# 247 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 248 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_3
# 249 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 250 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 251 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 252 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_TwinRefusal::
# 257 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT3
# 258 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_TwinRefusal_3
tarc3_Accusation_EventScript_Ev_TwinRefusal_1:
# 261 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 262 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_0
# 263 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_1
# 264 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_2
# 265 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_3
# 266 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 267 "data/scripts/tarc3_accusation_evidence.pory"
	playse SE_PIN
# 268 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_Ev_TwinRefusal_Movement_0
# 269 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 270 "data/scripts/tarc3_accusation_evidence.pory"
	delay 40
# 271 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 272 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 273 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 274 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_4
# 275 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_TwinRefusal_7
# 280 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 281 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_7
# 282 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_8
tarc3_Accusation_EventScript_Ev_TwinRefusal_6:
# 284 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 285 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
	return

tarc3_Accusation_EventScript_Ev_TwinRefusal_2:
# 259 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_T3, TARC3_T3_TWIN_REFUSAL
	goto tarc3_Accusation_EventScript_Ev_TwinRefusal_1

tarc3_Accusation_EventScript_Ev_TwinRefusal_3:
# 258 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSE_T3, 0
	goto_if_eq tarc3_Accusation_EventScript_Ev_TwinRefusal_2
	goto tarc3_Accusation_EventScript_Ev_TwinRefusal_1

tarc3_Accusation_EventScript_Ev_TwinRefusal_7:
# 276 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 277 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_5
# 278 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_6
	goto tarc3_Accusation_EventScript_Ev_TwinRefusal_6


tarc3_Accusation_EventScript_Ev_TakeshisMeeting::
# 290 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 291 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 292 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_0
# 293 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 294 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_1
# 295 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 296 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 297 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 298 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_TakeshisHistory::
# 303 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 304 "data/scripts/tarc3_accusation_evidence.pory"
	setflag FLAG_TARC3_ACCUSE_HISTORY
# 305 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 306 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_0
# 307 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 308 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_1
# 309 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 310 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 311 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 312 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_FamilyPicture::
# 317 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 318 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 319 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_0
# 320 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 321 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_1
# 322 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 323 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_2
# 324 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 325 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 326 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_OverheardArgument::
# 331 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 332 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 333 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_0
# 334 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 335 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_1
# 336 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 337 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 338 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 339 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_GozosFinalMeeting::
# 344 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 345 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 346 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_0
# 347 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 348 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_1
# 349 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 350 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_2
# 351 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_2
# 358 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 359 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_7
tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_1:
# 361 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 362 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 363 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 364 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_2:
# 352 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 353 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_4
# 354 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_5
# 355 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 356 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_6
	goto tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_1


tarc3_Accusation_EventScript_Ev_TakeshisRevenge::
# 369 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 370 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 371 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_0
# 372 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 373 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_1
# 374 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 375 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_2
# 376 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_TakeshisRevenge_2
tarc3_Accusation_EventScript_Ev_TakeshisRevenge_1:
# 380 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 381 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 382 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 383 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_2:
# 377 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 378 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
	goto tarc3_Accusation_EventScript_Ev_TakeshisRevenge_1


tarc3_Accusation_EventScript_Ev_CharcoalOnBolt::
# 390 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 391 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 392 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_0
# 393 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 394 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_1
# 395 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 396 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_2
# 397 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 398 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 399 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_LongAbsence::
# 404 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 405 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 406 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_LongAbsence_Text_0
# 407 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 408 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_LongAbsence_Text_1
# 409 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 410 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_LongAbsence_Text_2
# 411 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 412 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 413 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_AnAccomplice::
# 418 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 419 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 420 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_0
# 421 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 422 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_1
# 423 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 424 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_2
# 425 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_3
# 426 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 427 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 428 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_OpenStorageDoor::
# 433 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 434 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 435 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_0
# 436 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 437 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_1
# 438 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 439 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 440 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 441 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_BloodOnTheStair::
# 446 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 447 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 448 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_0
# 449 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_1
# 450 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 451 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_2
# 452 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 453 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_3
# 454 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 455 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 456 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 457 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_SilencedWitness::
# 462 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 463 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 464 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_0
# 465 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_1
# 466 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_2
# 467 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 468 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_3
# 469 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 470 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_4
# 471 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5
# 472 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 473 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 474 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_AKIE, tarc3_Accusation_EventScript_Ev_SilencedWitness_Movement_0
# 475 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 476 "data/scripts/tarc3_accusation_evidence.pory"
	delay 30
# 477 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5
# 478 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_6
# 479 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 480 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 481 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_TheAccompliceTheory::
# 486 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 487 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 488 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_0
# 489 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 490 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_1
# 491 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_2
# 497 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 498 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_4
tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_1:
# 500 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 501 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 502 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 503 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_2:
# 492 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 493 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_2
# 494 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 495 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_3
	goto tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_1


tarc3_Accusation_EventScript_Ev_SmeargleRepertoire::
# 510 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 511 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 512 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_0
# 513 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 514 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_1
# 515 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 516 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 517 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 518 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TheOddBattle::
# 523 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 524 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 525 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_0
# 526 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 527 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_1
# 528 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 529 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 530 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 531 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_BrokenLatch::
# 536 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 537 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 538 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BrokenLatch_Text_0
# 539 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 540 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BrokenLatch_Text_1
# 541 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 542 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 543 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 544 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TheHoldAdjoins::
# 549 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 550 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 551 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_0
# 552 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 553 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_1
# 554 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 555 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 556 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 557 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge::
# 562 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 563 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 564 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_0
# 565 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 566 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_1
# 567 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 568 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_2
# 569 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 570 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 571 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 572 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_PanelStruck::
# 577 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 578 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 579 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_PanelStruck_Text_0
# 580 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 581 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_PanelStruck_Text_1
# 582 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_PanelStruck_Text_2
# 583 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 584 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 585 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 586 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_TheNearestHand::
# 591 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 592 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 593 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_0
# 594 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 595 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_1
# 596 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_TheNearestHand_2
tarc3_Accusation_EventScript_Ev_TheNearestHand_1:
# 604 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 605 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 606 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 607 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_TheNearestHand_2:
# 597 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 598 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_2
# 599 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 600 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_3
# 601 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 602 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_2
	goto tarc3_Accusation_EventScript_Ev_TheNearestHand_1


tarc3_Accusation_EventScript_Ev_SketchedDischarge::
# 612 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT3
# 613 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SketchedDischarge_3
tarc3_Accusation_EventScript_Ev_SketchedDischarge_1:
# 616 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 617 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_0
# 618 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_1
# 619 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_2
# 620 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_3
# 621 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 622 "data/scripts/tarc3_accusation_evidence.pory"
	playse SE_PIN
# 623 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_KITARO, tarc3_Accusation_EventScript_Ev_TwinRefusal_Movement_0
# 624 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 625 "data/scripts/tarc3_accusation_evidence.pory"
	delay 40
# 626 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 627 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 628 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_4
# 629 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_5
# 630 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SketchedDischarge_7
# 635 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 636 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_8
# 637 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_9
tarc3_Accusation_EventScript_Ev_SketchedDischarge_6:
# 639 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 640 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
	return

tarc3_Accusation_EventScript_Ev_SketchedDischarge_2:
# 614 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_T3, TARC3_T3_SKETCHED_DISCHARGE
	goto tarc3_Accusation_EventScript_Ev_SketchedDischarge_1

tarc3_Accusation_EventScript_Ev_SketchedDischarge_3:
# 613 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSE_T3, TARC3_T3_SKETCHED_DISCHARGE
	goto_if_lt tarc3_Accusation_EventScript_Ev_SketchedDischarge_2
	goto tarc3_Accusation_EventScript_Ev_SketchedDischarge_1

tarc3_Accusation_EventScript_Ev_SketchedDischarge_7:
# 631 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 632 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_6
# 633 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_7
	goto tarc3_Accusation_EventScript_Ev_SketchedDischarge_6


tarc3_Accusation_EventScript_Ev_NoDefensiveWounds::
# 647 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 648 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 649 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_0
# 650 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 651 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_1
# 652 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 653 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 654 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 655 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TheSecondStory::
# 660 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 661 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 662 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_0
# 663 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_1
# 664 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 665 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_2
# 666 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 667 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 668 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 669 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_ImpossiblePrecision::
# 674 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 675 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 676 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_0
# 677 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 678 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_1
# 679 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 680 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 681 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 682 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_InconsistentDisposal::
# 687 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 688 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 689 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_0
# 690 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 691 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_1
# 692 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 693 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_2
# 694 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 695 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_3
# 696 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 697 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_4
# 698 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 699 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 700 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 701 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_SelfInflictedWound::
# 706 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT3
# 707 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SelfInflictedWound_3
tarc3_Accusation_EventScript_Ev_SelfInflictedWound_1:
# 710 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 711 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_0
# 712 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 713 "data/scripts/tarc3_accusation_evidence.pory"
	delay 50
# 714 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_1
# 715 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_2
# 716 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_3
# 717 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_4
# 718 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_5
# 719 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 720 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_Ev_UnrequitedLove_Movement_0
# 721 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 722 "data/scripts/tarc3_accusation_evidence.pory"
	delay 60
# 723 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SelfInflictedWound_7
# 727 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 728 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_7
# 729 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_8
tarc3_Accusation_EventScript_Ev_SelfInflictedWound_6:
# 731 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 732 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
	return

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_2:
# 708 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_T3, TARC3_T3_SELF_INFLICTED
	goto tarc3_Accusation_EventScript_Ev_SelfInflictedWound_1

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_3:
# 707 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSE_T3, TARC3_T3_SELF_INFLICTED
	goto_if_lt tarc3_Accusation_EventScript_Ev_SelfInflictedWound_2
	goto tarc3_Accusation_EventScript_Ev_SelfInflictedWound_1

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_7:
# 724 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 725 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_6
	goto tarc3_Accusation_EventScript_Ev_SelfInflictedWound_6


tarc3_Accusation_EventScript_Ev_HiddenPipe::
# 737 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 738 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 739 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_0
# 740 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_1
# 741 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5
# 742 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_2
# 743 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 744 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_3
# 745 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_4
# 746 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 747 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 748 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 749 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_KnivesCounted::
# 754 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 755 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 756 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_KnivesCounted_Text_0
# 757 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 758 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_KnivesCounted_Text_1
# 759 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 760 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_KnivesCounted_Text_2
# 761 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 762 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 763 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 764 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


# 209 "data/scripts/tarc3_accusation_evidence.pory"
tarc3_Accusation_EventScript_Ev_UnrequitedLove_Movement_0:
# 209 "data/scripts/tarc3_accusation_evidence.pory"
	face_right
	step_end

# 268 "data/scripts/tarc3_accusation_evidence.pory"
tarc3_Accusation_EventScript_Ev_TwinRefusal_Movement_0:
# 268 "data/scripts/tarc3_accusation_evidence.pory"
	emote_exclamation_mark
	step_end

# 474 "data/scripts/tarc3_accusation_evidence.pory"
tarc3_Accusation_EventScript_Ev_SilencedWitness_Movement_0:
# 474 "data/scripts/tarc3_accusation_evidence.pory"
	face_left
	step_end

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0:
# 55 "data/scripts/tarc3_accusation_evidence.pory"
	.string "{RIVAL}$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_1:
# 56 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You named Takeshi. You are describing\n"
	.string "Ichiro.$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_2:
# 57 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Choose a case and prosecute it,\n"
	.string "{PLAYER} Edgeworth.$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_0:
# 68 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A competent deduction, spent entirely\n"
	.string "upon a man you did not accuse.$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_1:
# 69 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You are dismantling your own case.\n"
	.string "Foolish.$"

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_Text_0:
# 80 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You named Ichiro, and you hand this\n"
	.string "room Takeshi.\p"
	.string "Which is it to be?$"

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_0:
# 91 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have just built the case against\n"
	.string "the wrong man - and built it well.$"

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_1:
# 92 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I hope you are proud of yourself.$"

tarc3_Accusation_EventScript_Fz_OffQuestion_Text_0:
# 106 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The {STR_VAR_1}?\l"
	.string "That feels hardly relevant.$"

tarc3_Accusation_EventScript_Fz_OffQuestion_Text_1:
# 107 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Address what is before this room,\n"
	.string "{PLAYER} Edgeworth.$"

tarc3_Accusation_EventScript_Ev_RawClue_Text_0:
# 119 "data/scripts/tarc3_accusation_evidence.pory"
	.string "{PLAYER}$"

tarc3_Accusation_EventScript_Ev_RawClue_Text_1:
# 120 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The {STR_VAR_1}.$"

tarc3_Accusation_EventScript_Ev_RawClue_Text_2:
# 122 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A fact, and a true one. It is not yet\n"
	.string "an argument.\p"
	.string "Find what it means, {PLAYER}\n"
	.string "Edgeworth, and bring me that instead.$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_0:
# 134 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's sketchbook. Dozens of\n"
	.string "studies.\p"
	.string "And all throughout, the same face.\n"
	.string "Natsue's.$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1:
# 135 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Natsue$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2:
# 136 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3:
# 137 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Joji$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_4:
# 138 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He's an art student. He draws what's in\n"
	.string "front of him.$"

tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_0:
# 149 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A man approached Gozo for Natsue's\n"
	.string "hand.\p"
	.string "He was refused - and not kindly.$"

tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1:
# 150 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Mariko$"

tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_2:
# 151 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Who? If you know the name, say the\n"
	.string "name.$"

tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_0:
# 162 "data/scripts/tarc3_accusation_evidence.pory"
	.string "On the deck this afternoon, Gozo\n"
	.string "declared himself finished with paying\l"
	.string "for the boy's schooling.$"

tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1:
# 163 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Kitaro$"

tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_2:
# 164 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He wielded words like weapons. It was\n"
	.string "cruel.$"

tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_0:
# 175 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo funded Ichiro's art training.\p"
	.string "Not a gesture. Years of it.$"

tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1:
# 176 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Suzuki$"

tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_2:
# 177 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Eleven years, paid each term. I\n"
	.string "handled the arrangements myself.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_0:
# 189 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is a dry loaf in Ichiro's art bag.\p"
	.string "Artists use bread to lift charcoal\n"
	.string "from a page.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_1:
# 191 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There's bread in my cabin too.\p"
	.string "I'm a chef, {PLAYER} - I made bread\n"
	.string "for the entire wedding party.\p"
	.string "Are you accusing me, too?$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_2:
# 193 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Absurd, Joji.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_3:
# 195 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Bread. You have brought this room\n"
	.string "bread.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_4:
# 196 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Do continue, {PLAYER} Edgeworth. It\n"
	.string "is riveting.$"

tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_0:
# 206 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The man who asked for Natsue's hand\n"
	.string "drew no other subject.\p"
	.string "It was Ichiro. Four years of art,\n"
	.string "primarily of her.$"

tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_1:
# 213 "data/scripts/tarc3_accusation_evidence.pory"
	.string "What?! Ichiro and... Natsue?$"

tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_0:
# 226 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The sponsorship was not lapsing\n"
	.string "quietly.\p"
	.string "Gozo was severing the very career he\n"
	.string "had spent eleven years paying to\l"
	.string "build.$"

tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_1:
# 228 "data/scripts/tarc3_accusation_evidence.pory"
	.string "And he made certain it was heard. That\n"
	.string "was his way.$"

tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_2:
# 230 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...It was.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_0:
# 242 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Inside that doorway, in the blood\n"
	.string "itself, there were crumbs.\p"
	.string "Dry, and black with charcoal. They\n"
	.string "came off an artist's eraser.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_1:
# 244 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Crumbs. You are standing amongst a\n"
	.string "dead man's family, telling us about\l"
	.string "crumbs.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_2:
# 246 "data/scripts/tarc3_accusation_evidence.pory"
	.string "In the blood, Joji. Not beside it. The\n"
	.string "distinction is the entire point.\p"
	.string "They fell while it was still wet - from\n"
	.string "the cuff of the hand holding the\l"
	.string "knife.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_3:
# 248 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Ah.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_0:
# 262 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have all settled on a sponsorship\n"
	.string "that simply ran its course.\p"
	.string "Discard that.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_1:
# 263 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He asked Gozo for permission to court\n"
	.string "Natsue, and was refused.\p"
	.string "In that same week, Gozo announced her\n"
	.string "engagement to Takeshi.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_2:
# 264 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Then, on the deck this afternoon,\n"
	.string "Gozo told us he was finished paying\l"
	.string "for the boy.\p"
	.string "Not privately. He performed it, before\n"
	.string "his family, with Ichiro standing eight\l"
	.string "feet away.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_3:
# 265 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo refused him twice over. His love,\n"
	.string "and his art.\p"
	.string "Two humiliations - and to Ichiro, they\n"
	.string "were one and the same wound.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_4:
# 274 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Twice refused. I can... I can see the\n"
	.string "source of his anger.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_5:
# 277 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A motive. At last, a motive.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_6:
# 278 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Do not preen, {PLAYER} Edgeworth.\n"
	.string "It took you all evening.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_7:
# 281 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have just proved that Ichiro had\n"
	.string "every reason to kill him.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_8:
# 282 "data/scripts/tarc3_accusation_evidence.pory"
	.string "And you named Takeshi.\p"
	.string "Do you hear yourself?$"

tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_0:
# 292 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo summoned Takeshi to his cabin\n"
	.string "before dinner.$"

tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_1:
# 294 "data/scripts/tarc3_accusation_evidence.pory"
	.string "So the last appointment my father\n"
	.string "ever kept was with him.$"

tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_0:
# 306 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo ruined Takeshi's father.\p"
	.string "The man lost his company, and took his\n"
	.string "own life the spring after.$"

tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_1:
# 308 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Yes. A cruel tale, and one not easily\n"
	.string "forgotten.$"

tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_0:
# 319 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A photograph from Takeshi's cabin.\p"
	.string "A boy, smiling, flanked by his father.$"

tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_1:
# 321 "data/scripts/tarc3_accusation_evidence.pory"
	.string "But why is this relevant?$"

tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_2:
# 323 "data/scripts/tarc3_accusation_evidence.pory"
	.string "It is not.\p"
	.string "A photograph of a man proves nothing,\n"
	.string "and you know it.$"

tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_0:
# 333 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Mariko overheard Gozo and Takeshi in\n"
	.string "argument before dinner.$"

tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_1:
# 335 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I did. Through the cabin wall, and\n"
	.string "neither voice was calm.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_0:
# 346 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo summoned him to that cabin\n"
	.string "before dinner.\p"
	.string "And a little while later, Suzuki found\n"
	.string "his flower lying outside the door.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_1:
# 348 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There. That is the whole of it, and we\n"
	.string "have known it all night.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_2:
# 350 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He lost that garland before that\n"
	.string "point! He told you that!$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3:
# 352 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Takeshi$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_4:
# 353 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I did go in. I'm not going to pretend I\n"
	.string "didn't.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_5:
# 354 "data/scripts/tarc3_accusation_evidence.pory"
	.string "But he was alive when I left him.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_6:
# 356 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Sure.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_7:
# 359 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He told us a great many things.$"

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_0:
# 371 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Takeshi entered Hatamoto Corp two\n"
	.string "years ago.\p"
	.string "The company belonging to the man who\n"
	.string "destroyed his father.$"

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_1:
# 373 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Nobody does that by accident.$"

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_2:
# 375 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He came to us on purpose. He was\n"
	.string "always here on purpose.$"

tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_0:
# 392 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The bolt on the hold door carries a\n"
	.string "smear of black dust.\p"
	.string "Charcoal.$"

tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_1:
# 394 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Are you certain? It would have rubbed\n"
	.string "off when you inspected it, surely?$"

tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_2:
# 396 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He is right, and you have no answer for\n"
	.string "him.\p"
	.string "Do not present what you cannot\n"
	.string "defend.$"

tarc3_Accusation_EventScript_Ev_LongAbsence_Text_0:
# 406 "data/scripts/tarc3_accusation_evidence.pory"
	.string "By all accounts, Ichiro left the table\n"
	.string "well before the lights failed.\p"
	.string "He was absent long enough.$"

tarc3_Accusation_EventScript_Ev_LongAbsence_Text_1:
# 408 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The poor boy was stressed. We all have\n"
	.string "been, tonight.$"

tarc3_Accusation_EventScript_Ev_LongAbsence_Text_2:
# 410 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You would do well to remember,\n"
	.string "{PLAYER} Edgeworth, that an\l"
	.string "absence alone is not a crime.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_0:
# 420 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Mariko has maintained it all evening.\n"
	.string "Takeshi had help from someone aboard.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_1:
# 422 "data/scripts/tarc3_accusation_evidence.pory"
	.string "At last. Thank you.\p"
	.string "An accomplice explains every locked\n"
	.string "door on this ship.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_2:
# 424 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have agreed with the loudest\n"
	.string "person in the room.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_3:
# 425 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That is not deduction. That is\n"
	.string "surrender.$"

tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_0:
# 435 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The storeroom door was opened. Suzuki\n"
	.string "bolted it in front of all of us, yet\l"
	.string "someone drew it back.$"

tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_1:
# 437 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Someone opened it from the outside.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_0:
# 448 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is a smear on the steps down to\n"
	.string "the hold.\p"
	.string "Blood, with black dust worked through\n"
	.string "it.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_1:
# 449 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The same charcoal that is on the bolt\n"
	.string "at the bottom of those stairs.\p"
	.string "One pair of hands left both marks.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_2:
# 451 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Or the boy left them climbing up.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_3:
# 453 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Takeshi was still bolted in. Someone\n"
	.string "came down these stairs to let him out.\p"
	.string "And he was already carrying Tatsuo\n"
	.string "with him.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_0:
# 464 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Natsue, Franziska and I heard two\n"
	.string "sounds from the deck.\p"
	.string "A splash, and then something heavy\n"
	.string "striking the floor.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_1:
# 465 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The order is decisive. The splash came\n"
	.string "first.\p"
	.string "Someone stood at that rail, disposing\n"
	.string "of the knife that killed Gozo.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_2:
# 466 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Tatsuo saw the weapon go over the\n"
	.string "side. That is the entire reason he is\l"
	.string "dead.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_3:
# 468 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Or, an accomplice.\p"
	.string "It has always been an accomplice, and\n"
	.string "you have never once dealt with it!$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_4:
# 470 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is no accomplice.\p"
	.string "There is one man disposing of a\n"
	.string "weapon, and the misfortune of being\l"
	.string "observed.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5:
# 471 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Akie$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_6:
# 478 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I yelled at him.\p"
	.string "He went to the deck to give me space...\n"
	.string "I did this.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_0:
# 488 "data/scripts/tarc3_accusation_evidence.pory"
	.string "On the matter of the supposed\n"
	.string "accomplice.\p"
	.string "Takeshi heard his door unbolted, and\n"
	.string "footsteps departing. Someone\l"
	.string "released him.\p"
	.string "From that moment, a man moved freely\n"
	.string "about this ship whom nobody could\l"
	.string "account for.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_1:
# 490 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Someone let him out. I have said so\n"
	.string "from the start.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_2:
# 493 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I didn't unlock that door. I've told\n"
	.string "you. I heard it open.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_3:
# 495 "data/scripts/tarc3_accusation_evidence.pory"
	.string "By itself.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_4:
# 498 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Then where is this accomplice? Name\n"
	.string "one person in this room.$"

tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_0:
# 512 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's Smeargle battled me this\n"
	.string "afternoon. It possessed no Electric\l"
	.string "move.\p"
	.string "I have the notes.$"

tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_1:
# 514 "data/scripts/tarc3_accusation_evidence.pory"
	.string "It's an artist, like its trainer. It\n"
	.string "never needed one.$"

tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_0:
# 525 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro asked you for a battle, but\n"
	.string "barely attacked.\p"
	.string "His Smeargle stood and studied your\n"
	.string "moves.$"

tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_1:
# 527 "data/scripts/tarc3_accusation_evidence.pory"
	.string "My Pawmot used Discharge in front of\n"
	.string "it... But I didn't think anything of it.$"

tarc3_Accusation_EventScript_Ev_BrokenLatch_Text_0:
# 538 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The breaker housing had a latch. It\n"
	.string "was broken off and thrown in a bin\l"
	.string "nearby.$"

tarc3_Accusation_EventScript_Ev_BrokenLatch_Text_1:
# 540 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Someone forced it open deliberately.$"

tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_0:
# 551 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The storeroom in which Takeshi was\n"
	.string "locked sits on the same deck as the\l"
	.string "breaker panel.$"

tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_1:
# 553 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...That is true. Once out, he had easy\n"
	.string "access.$"

tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_0:
# 564 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's Smeargle acquired an Electric\n"
	.string "move during this voyage.\p"
	.string "It sketched Discharge from Kitaro's\n"
	.string "Pawmot - and it did so on Ichiro's\l"
	.string "instruction.$"

tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_1:
# 566 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I didn't notice it, and Ichiro surely\n"
	.string "wouldn't think to do that in a battle.$"

tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_2:
# 568 "data/scripts/tarc3_accusation_evidence.pory"
	.string "So at best, either of them could have\n"
	.string "done it.\p"
	.string "We are all still in the dark. How\n"
	.string "appropriate.$"

tarc3_Accusation_EventScript_Ev_PanelStruck_Text_0:
# 579 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That panel did not short.\p"
	.string "It was struck once, from outside the\n"
	.string "casing, by a single focused jolt of\l"
	.string "electricity.$"

tarc3_Accusation_EventScript_Ev_PanelStruck_Text_1:
# 581 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I said the wiring was old. I believed\n"
	.string "it, too.$"

tarc3_Accusation_EventScript_Ev_PanelStruck_Text_2:
# 582 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...I am less certain now.$"

tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_0:
# 593 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The hold shares a deck with the\n"
	.string "breaker, and the service door nearest\l"
	.string "it does not latch.\p"
	.string "The escaped man was at liberty\n"
	.string "precisely where the lights died.$"

tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_1:
# 595 "data/scripts/tarc3_accusation_evidence.pory"
	.string "So he walked out of a room he was\n"
	.string "locked in and just put his hand on a\l"
	.string "switch.$"

tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_2:
# 602 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...I know how it sounds.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_0:
# 617 "data/scripts/tarc3_accusation_evidence.pory"
	.string "We have all heard of the ship's alleged\n"
	.string "old wiring. Discard it.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_1:
# 618 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That panel did not short.\p"
	.string "It was struck once, from outside the\n"
	.string "casing, by a focused jolt of\l"
	.string "electricity.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_2:
# 619 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's Smeargle carried no Electric\n"
	.string "move when it battled me this\l"
	.string "afternoon.\p"
	.string "I have the notes. Tonight it knows\n"
	.string "Discharge - sketched from Kitaro's\l"
	.string "Pawmot, on Ichiro's instruction.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_3:
# 620 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The blackout was a Pokemon's move,\n"
	.string "aimed at a breaker.\p"
	.string "And precisely one Pokemon aboard this\n"
	.string "ship learned to produce it today.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_4:
# 628 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I said the wiring was old. I was so\n"
	.string "confident it was a coincidence.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_5:
# 629 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I... was wrong.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_6:
# 632 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A Pokemon's move, aimed at a breaker.\n"
	.string "That is incontrovertible.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_7:
# 633 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Adequate, {PLAYER} Edgeworth.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_8:
# 636 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That was flawless, and it points\n"
	.string "squarely at a man you did not accuse.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_9:
# 637 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You are prosecuting your own case\n"
	.string "into the ground.$"

tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_0:
# 649 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There are no defensive wounds on his\n"
	.string "hands. No cuts to the forearms.\p"
	.string "Nothing whatsoever.$"

tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_1:
# 651 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You're saying he did that to himself.\p"
	.string "Say it properly, if you're going to say\n"
	.string "it in front of him.$"

tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_0:
# 662 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro told us he saw nothing at all.\p"
	.string "Yet pressed upon it, he described the\n"
	.string "knife coming down - in a room with no\l"
	.string "light in it.$"

tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_1:
# 663 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro$"

tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_2:
# 665 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I heard it. I must have heard it.$"

tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_0:
# 676 "data/scripts/tarc3_accusation_evidence.pory"
	.string "One clean, careful wound, in a\n"
	.string "non-vital place.\p"
	.string "Placed in total darkness, upon a man\n"
	.string "who claims he never saw his attacker.$"

tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_1:
# 678 "data/scripts/tarc3_accusation_evidence.pory"
	.string "In the dark, into a struggling man...\n"
	.string "no.\p"
	.string "That cut was placed slowly.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_0:
# 689 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The first knife went into the sea, and\n"
	.string "the man who threw it killed to keep\l"
	.string "that quiet.\p"
	.string "The second was left lying on a\n"
	.string "bathroom floor, six feet from Ichiro.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_1:
# 691 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He was on the floor. There was blood\n"
	.string "on the tiles - I saw it, I was there.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_2:
# 693 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I know you were.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_3:
# 695 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Why hide one blade and abandon the\n"
	.string "other?$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_4:
# 697 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Yes. Why indeed.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_0:
# 711 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He did it to himself.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_1:
# 714 "data/scripts/tarc3_accusation_evidence.pory"
	.string "One cut. Clean, and in a non-vital\n"
	.string "location.\p"
	.string "Delivered in a room with no light in it\n"
	.string "whatsoever.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_2:
# 715 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Consider the others. Gozo was stabbed\n"
	.string "relentlessly.\p"
	.string "Tatsuo took a vicious blow to the\n"
	.string "back of the head.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_3:
# 716 "data/scripts/tarc3_accusation_evidence.pory"
	.string "And yet there is not one defensive\n"
	.string "mark upon Ichiro's hands.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_4:
# 717 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The knife then presents itself six\n"
	.string "feet from him, on the bathroom floor.\p"
	.string "The first weapon went into the sea,\n"
	.string "and the man who threw it killed to\l"
	.string "keep that quiet.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_5:
# 718 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He did not conceal the second blade,\n"
	.string "because he never intended to leave\l"
	.string "that room carrying it.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_6:
# 725 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Fools. Every last one of you.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_7:
# 728 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have just told this room that\n"
	.string "Ichiro wounded himself.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_8:
# 729 "data/scripts/tarc3_accusation_evidence.pory"
	.string "And you named Takeshi.\p"
	.string "I have no words for you.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_0:
# 739 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is a sack of maintenance\n"
	.string "equipment on the foredeck, with two\l"
	.string "lengths of pipe jutting out of the top\l"
	.string "of it.\p"
	.string "Every one of you has walked past it\n"
	.string "all evening and taken it for ship's\l"
	.string "stores.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_1:
# 740 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Tatsuo broke those fittings himself\n"
	.string "this afternoon and hid them in there.\p"
	.string "He told me so, laughing.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_2:
# 742 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...That is exactly the sort of thing he\n"
	.string "would do.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_3:
# 744 "data/scripts/tarc3_accusation_evidence.pory"
	.string "One of those two pipes has his blood\n"
	.string "on it, and it is still in that sack.\p"
	.string "The weapon that killed him was lying a\n"
	.string "step from where he stood.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_4:
# 745 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Nothing was carried out onto that\n"
	.string "deck. Whoever went out to be rid of\l"
	.string "the knife took up the first heavy\l"
	.string "thing he stumbled over - because he\l"
	.string "had not gone out there to kill\l"
	.string "anybody.$"

tarc3_Accusation_EventScript_Ev_KnivesCounted_Text_0:
# 756 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Before dinner Joji told me he had used\n"
	.string "his knives when preparing dinner.$"

tarc3_Accusation_EventScript_Ev_KnivesCounted_Text_1:
# 758 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I had all eight. I would swear to it.\p"
	.string "I count them the way you'd count your\n"
	.string "fingers.$"

tarc3_Accusation_EventScript_Ev_KnivesCounted_Text_2:
# 760 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Then both of the missing knives left\n"
	.string "that roll tonight.\p"
	.string "Nothing came aboard for this.\n"
	.string "Everything used was found here.$"
