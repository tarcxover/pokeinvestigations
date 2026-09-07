tarc3_Accusation_EventScript_ScoreIchiroT1::
# 7 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_ScoreIchiroT1_2
tarc3_Accusation_EventScript_ScoreIchiroT1_1:
	return

tarc3_Accusation_EventScript_ScoreIchiroT1_2:
# 8 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 2
# 9 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 2
	goto tarc3_Accusation_EventScript_ScoreIchiroT1_1


tarc3_Accusation_EventScript_ScoreIchiroT2::
# 15 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_ScoreIchiroT2_2
tarc3_Accusation_EventScript_ScoreIchiroT2_1:
	return

tarc3_Accusation_EventScript_ScoreIchiroT2_2:
# 16 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 5
# 17 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 5
# 18 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_HITS, 1
	goto tarc3_Accusation_EventScript_ScoreIchiroT2_1


tarc3_Accusation_EventScript_ScoreIchiroT3::
# 24 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_ScoreIchiroT3_2
tarc3_Accusation_EventScript_ScoreIchiroT3_1:
	return

tarc3_Accusation_EventScript_ScoreIchiroT3_2:
# 25 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 13
# 26 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 13
# 27 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_HITS, 1
	goto tarc3_Accusation_EventScript_ScoreIchiroT3_1


tarc3_Accusation_EventScript_ScoreTakeshiT1::
# 33 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_ScoreTakeshiT1_2
tarc3_Accusation_EventScript_ScoreTakeshiT1_1:
	return

tarc3_Accusation_EventScript_ScoreTakeshiT1_2:
# 34 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 2
# 35 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 2
	goto tarc3_Accusation_EventScript_ScoreTakeshiT1_1


tarc3_Accusation_EventScript_ScoreTakeshiT2::
# 41 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_ScoreTakeshiT2_2
tarc3_Accusation_EventScript_ScoreTakeshiT2_1:
	return

tarc3_Accusation_EventScript_ScoreTakeshiT2_2:
# 42 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_QSCORE, 5
# 43 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_SCORE, 5
# 44 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_HITS, 1
	goto tarc3_Accusation_EventScript_ScoreTakeshiT2_1


tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1::
# 52 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_2
tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_2:
# 53 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 54 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_1
# 55 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_2
# 56 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 57 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 58 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_1


tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2::
# 64 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_2
tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_2:
# 65 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 66 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_0
# 67 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_1
# 68 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 69 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 70 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_1


tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1::
# 76 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_2
tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_2:
# 77 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 78 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_Text_0
# 79 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 80 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 81 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_1


tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2::
# 87 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_ne tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_2
tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_1:
	return

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_2:
# 88 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 89 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_0
# 90 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_1
# 91 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 92 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 93 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	goto tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_1


tarc3_Accusation_EventScript_Fz_OffQuestion::
# 99 "data/scripts/tarc3_accusation_evidence.pory"
	evidencetoitem VAR_RESULT
# 100 "data/scripts/tarc3_accusation_evidence.pory"
	bufferitemname STR_VAR_1, VAR_RESULT
# 101 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 102 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffQuestion_Text_0
# 103 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Fz_OffQuestion_Text_1
# 104 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 105 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 106 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_RawClue::
# 113 "data/scripts/tarc3_accusation_evidence.pory"
	evidencetoitem VAR_RESULT
# 114 "data/scripts/tarc3_accusation_evidence.pory"
	bufferitemname STR_VAR_1, VAR_RESULT
# 115 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 116 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RawClue_Text_1
# 117 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 118 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RawClue_Text_2
# 119 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 120 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 121 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_Sketchbook::
# 128 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 129 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 130 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_0
# 131 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 132 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 133 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 134 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_4
# 135 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 136 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 137 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 138 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_RefusedSuitor::
# 143 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 144 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 145 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_0
# 146 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 147 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_2
# 148 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 149 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 150 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 151 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TuitionFunds::
# 156 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 157 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 158 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_0
# 159 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 160 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_2
# 161 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 162 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 163 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 164 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_IchiroSponsorship::
# 169 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 170 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 171 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_0
# 172 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 173 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_2
# 174 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 175 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 176 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 177 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_BreadEraser::
# 182 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 183 "data/scripts/tarc3_accusation_evidence.pory"
	setflag FLAG_TARC3_ACCUSE_CRUMBS
# 184 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 185 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_0
# 186 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 187 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_1
# 188 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 189 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_2
# 190 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 191 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_3
# 192 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BreadEraser_Text_4
# 193 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 194 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 195 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_UnrequitedLove::
# 200 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 201 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 202 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_0
# 203 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 204 "data/scripts/tarc3_accusation_evidence.pory"
	delay 30
# 205 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_Ev_UnrequitedLove_Movement_0
# 206 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 207 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 208 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 209 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_1
# 210 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 211 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 212 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 213 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 214 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 215 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal::
# 220 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 221 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 222 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_0
# 223 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 224 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_1
# 225 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 226 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_2
# 227 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 228 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 229 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 230 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor::
# 235 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 236 "data/scripts/tarc3_accusation_evidence.pory"
	setflag FLAG_TARC3_ACCUSE_CRUMBS
# 237 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 238 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_0
# 239 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 240 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_1
# 241 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 242 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_2
# 243 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 244 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_3
# 245 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 246 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 247 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 248 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_TwinRefusal::
# 253 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT3
# 254 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_TwinRefusal_2
tarc3_Accusation_EventScript_Ev_TwinRefusal_1:
# 257 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 258 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_0
# 259 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_1
# 260 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_2
# 261 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_3
# 262 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 263 "data/scripts/tarc3_accusation_evidence.pory"
	playse SE_PIN
# 264 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_Ev_TwinRefusal_Movement_0
# 265 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 266 "data/scripts/tarc3_accusation_evidence.pory"
	delay 40
# 267 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 268 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 269 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 270 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_4
# 271 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_TwinRefusal_5
# 276 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 277 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_7
# 278 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_8
tarc3_Accusation_EventScript_Ev_TwinRefusal_4:
# 280 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 281 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
	return

tarc3_Accusation_EventScript_Ev_TwinRefusal_2:
# 255 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_T3, TARC3_T3_TWIN_REFUSAL
	goto tarc3_Accusation_EventScript_Ev_TwinRefusal_1

tarc3_Accusation_EventScript_Ev_TwinRefusal_5:
# 272 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 273 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_5
# 274 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_6
	goto tarc3_Accusation_EventScript_Ev_TwinRefusal_4


tarc3_Accusation_EventScript_Ev_TakeshisMeeting::
# 286 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 287 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 288 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_0
# 289 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 290 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_1
# 291 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 292 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 293 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 294 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_TakeshisHistory::
# 299 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 300 "data/scripts/tarc3_accusation_evidence.pory"
	setflag FLAG_TARC3_ACCUSE_HISTORY
# 301 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 302 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_0
# 303 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 304 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_1
# 305 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 306 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 307 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 308 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_FamilyPicture::
# 313 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 314 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 315 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_0
# 316 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 317 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_1
# 318 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 319 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_2
# 320 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 321 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 322 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_OverheardArgument::
# 327 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 328 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 329 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_0
# 330 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 331 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_1
# 332 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 333 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 334 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 335 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_GozosFinalMeeting::
# 340 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 341 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 342 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_0
# 343 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 344 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_1
# 345 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 346 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_2
# 347 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_2
# 354 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 355 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_7
tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_1:
# 357 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 358 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 359 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 360 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_2:
# 348 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 349 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_4
# 350 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_5
# 351 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 352 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_6
	goto tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_1


tarc3_Accusation_EventScript_Ev_TakeshisRevenge::
# 365 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 366 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 367 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_0
# 368 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 369 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_1
# 370 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 371 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_2
# 372 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_TakeshisRevenge_2
tarc3_Accusation_EventScript_Ev_TakeshisRevenge_1:
# 376 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 377 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 378 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 379 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_2:
# 373 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 374 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
	goto tarc3_Accusation_EventScript_Ev_TakeshisRevenge_1


tarc3_Accusation_EventScript_Ev_CharcoalOnBolt::
# 386 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 387 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 388 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_0
# 389 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 390 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_1
# 391 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 392 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_2
# 393 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 394 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 395 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_LongAbsence::
# 400 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 401 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 402 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_LongAbsence_Text_0
# 403 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 404 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_LongAbsence_Text_1
# 405 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 406 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_LongAbsence_Text_2
# 407 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 408 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 409 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_AnAccomplice::
# 414 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 415 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 416 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_0
# 417 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 418 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_1
# 419 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 420 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_2
# 421 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_3
# 422 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 423 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 424 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
	return


tarc3_Accusation_EventScript_Ev_OpenStorageDoor::
# 429 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 430 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 431 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_0
# 432 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 433 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_1
# 434 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 435 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 436 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 437 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_BloodOnTheStair::
# 442 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 443 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 444 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_0
# 445 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_1
# 446 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 447 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_2
# 448 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 449 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_3
# 450 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 451 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 452 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 453 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_SilencedWitness::
# 458 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 459 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 460 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_0
# 461 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_1
# 462 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_2
# 463 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 464 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_3
# 465 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 466 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_4
# 467 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5
# 468 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 469 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 470 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_AKIE, tarc3_Accusation_EventScript_Ev_SilencedWitness_Movement_0
# 471 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 472 "data/scripts/tarc3_accusation_evidence.pory"
	delay 30
# 473 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5
# 474 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_6
# 475 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 476 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 477 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_TheAccompliceTheory::
# 482 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 483 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 484 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_0
# 485 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 486 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_1
# 487 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_2
# 493 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 494 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_4
tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_1:
# 496 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 497 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 498 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 499 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_2:
# 488 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 489 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_2
# 490 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 491 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_3
	goto tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_1


tarc3_Accusation_EventScript_Ev_SmeargleRepertoire::
# 506 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 507 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 508 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_0
# 509 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 510 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_1
# 511 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 512 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 513 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 514 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TheOddBattle::
# 519 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 520 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 521 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_0
# 522 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 523 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_1
# 524 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 525 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 526 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 527 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TheHoldAdjoins::
# 533 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT1
# 534 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 535 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_0
# 536 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 537 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_1
# 538 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 539 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 540 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 541 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1
	return


tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge::
# 546 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 547 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 548 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_0
# 549 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1
# 550 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_1
# 551 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 552 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_2
# 553 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 554 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 555 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 556 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_PanelStruck::
# 561 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 562 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 563 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_PanelStruck_Text_0
# 564 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 565 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_PanelStruck_Text_1
# 566 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 567 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 568 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 569 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_TheNearestHand::
# 574 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreTakeshiT2
# 575 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 576 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_0
# 577 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 578 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_1
# 579 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_TAKESHI
	goto_if_eq tarc3_Accusation_EventScript_Ev_TheNearestHand_2
tarc3_Accusation_EventScript_Ev_TheNearestHand_1:
# 587 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 588 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 589 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 590 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2
	return

tarc3_Accusation_EventScript_Ev_TheNearestHand_2:
# 580 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 581 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_2
# 582 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1
# 583 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_3
# 584 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3
# 585 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_2
	goto tarc3_Accusation_EventScript_Ev_TheNearestHand_1


tarc3_Accusation_EventScript_Ev_SketchedDischarge::
# 595 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT3
# 596 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SketchedDischarge_2
tarc3_Accusation_EventScript_Ev_SketchedDischarge_1:
# 599 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 600 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_0
# 601 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_1
# 602 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_2
# 603 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_3
# 604 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 605 "data/scripts/tarc3_accusation_evidence.pory"
	playse SE_PIN
# 606 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_KITARO, tarc3_Accusation_EventScript_Ev_TwinRefusal_Movement_0
# 607 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 608 "data/scripts/tarc3_accusation_evidence.pory"
	delay 40
# 609 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1
# 610 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 611 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_4
# 612 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_5
# 613 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SketchedDischarge_5
# 618 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 619 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_8
# 620 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_9
tarc3_Accusation_EventScript_Ev_SketchedDischarge_4:
# 622 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 623 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
	return

tarc3_Accusation_EventScript_Ev_SketchedDischarge_2:
# 597 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_T3, TARC3_T3_SKETCHED_DISCHARGE
	goto tarc3_Accusation_EventScript_Ev_SketchedDischarge_1

tarc3_Accusation_EventScript_Ev_SketchedDischarge_5:
# 614 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 615 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_6
# 616 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_7
	goto tarc3_Accusation_EventScript_Ev_SketchedDischarge_4


tarc3_Accusation_EventScript_Ev_NoDefensiveWounds::
# 630 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 631 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 632 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_0
# 633 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 634 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_1
# 635 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 636 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 637 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 638 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_TheSecondStory::
# 643 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 644 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 645 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_0
# 646 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_1
# 647 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2
# 648 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_2
# 649 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 650 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 651 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 652 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


tarc3_Accusation_EventScript_Ev_ImpossiblePrecision::
# 657 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 658 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 659 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_0
# 660 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 661 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_1
# 662 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 663 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 664 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 665 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_InconsistentDisposal::
# 670 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT2
# 671 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 672 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_0
# 673 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1
# 674 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_1
# 675 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 676 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_2
# 677 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3
# 678 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_3
# 679 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 680 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_4
# 681 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 682 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 683 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 684 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2
	return


tarc3_Accusation_EventScript_Ev_SelfInflictedWound::
# 689 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT3
# 690 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SelfInflictedWound_2
tarc3_Accusation_EventScript_Ev_SelfInflictedWound_1:
# 693 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 694 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_0
# 695 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 696 "data/scripts/tarc3_accusation_evidence.pory"
	delay 50
# 697 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_1
# 698 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_2
# 699 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_3
# 700 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_4
# 701 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_5
# 702 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 703 "data/scripts/tarc3_accusation_evidence.pory"
	applymovement LOCALID_CABINS_NATSUE, tarc3_Accusation_EventScript_Ev_UnrequitedLove_Movement_0
# 704 "data/scripts/tarc3_accusation_evidence.pory"
	waitmovement 0
# 705 "data/scripts/tarc3_accusation_evidence.pory"
	delay 60
# 706 "data/scripts/tarc3_accusation_evidence.pory"
	compare VAR_TARC3_ACCUSED, TARC3_ACCUSED_ICHIRO
	goto_if_eq tarc3_Accusation_EventScript_Ev_SelfInflictedWound_5
# 710 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 711 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_7
# 712 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_8
tarc3_Accusation_EventScript_Ev_SelfInflictedWound_4:
# 714 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 715 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
	return

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_2:
# 691 "data/scripts/tarc3_accusation_evidence.pory"
	addvar VAR_TARC3_ACCUSE_T3, TARC3_T3_SELF_INFLICTED
	goto tarc3_Accusation_EventScript_Ev_SelfInflictedWound_1

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_5:
# 707 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0
# 708 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_6
	goto tarc3_Accusation_EventScript_Ev_SelfInflictedWound_4


tarc3_Accusation_EventScript_Ev_HiddenPipe::
# 720 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_ScoreIchiroT1
# 721 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 722 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_0
# 723 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_1
# 724 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5
# 725 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_2
# 726 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker tarc3_Accusation_EventScript_Ev_RawClue_Text_0
# 727 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_3
# 728 "data/scripts/tarc3_accusation_evidence.pory"
	msgbox tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_4
# 729 "data/scripts/tarc3_accusation_evidence.pory"
	setspeaker NULL
# 730 "data/scripts/tarc3_accusation_evidence.pory"
	closemessage
# 731 "data/scripts/tarc3_accusation_evidence.pory"
	delay 20
# 732 "data/scripts/tarc3_accusation_evidence.pory"
	call tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1
	return


# 205 "data/scripts/tarc3_accusation_evidence.pory"
tarc3_Accusation_EventScript_Ev_UnrequitedLove_Movement_0:
# 205 "data/scripts/tarc3_accusation_evidence.pory"
	face_right
	step_end

# 264 "data/scripts/tarc3_accusation_evidence.pory"
tarc3_Accusation_EventScript_Ev_TwinRefusal_Movement_0:
# 264 "data/scripts/tarc3_accusation_evidence.pory"
	emote_exclamation_mark
	step_end

# 470 "data/scripts/tarc3_accusation_evidence.pory"
tarc3_Accusation_EventScript_Ev_SilencedWitness_Movement_0:
# 470 "data/scripts/tarc3_accusation_evidence.pory"
	face_left
	step_end

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_0:
# 53 "data/scripts/tarc3_accusation_evidence.pory"
	.string "{RIVAL}$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_1:
# 54 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You named Takeshi. You are describing\n"
	.string "Ichiro.$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT1_Text_2:
# 55 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Choose a case and prosecute it,\n"
	.string "{PLAYER} Edgeworth.$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_0:
# 66 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A competent deduction, spent entirely\n"
	.string "upon a man you did not accuse.$"

tarc3_Accusation_EventScript_Fz_OffTargetIchiroT2_Text_1:
# 67 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You are dismantling your own case.\n"
	.string "Foolish.$"

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT1_Text_0:
# 78 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You named Ichiro, and you hand this\n"
	.string "room Takeshi.\p"
	.string "Which is it to be?$"

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_0:
# 89 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have just built the case against\n"
	.string "the wrong man - and built it well.$"

tarc3_Accusation_EventScript_Fz_OffTargetTakeshiT2_Text_1:
# 90 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I hope you are proud of yourself.$"

tarc3_Accusation_EventScript_Fz_OffQuestion_Text_0:
# 102 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The {STR_VAR_1}?\l"
	.string "That feels hardly relevant.$"

tarc3_Accusation_EventScript_Fz_OffQuestion_Text_1:
# 103 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Address what is before this room,\n"
	.string "{PLAYER} Edgeworth.$"

tarc3_Accusation_EventScript_Ev_RawClue_Text_0:
# 115 "data/scripts/tarc3_accusation_evidence.pory"
	.string "{PLAYER}$"

tarc3_Accusation_EventScript_Ev_RawClue_Text_1:
# 116 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The {STR_VAR_1}.$"

tarc3_Accusation_EventScript_Ev_RawClue_Text_2:
# 118 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That's a fact. However, this evidence\n"
	.string "doesn't implicate anyone.$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_0:
# 130 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's sketchbook. Dozens of\n"
	.string "artworks.\p"
	.string "And consistently, the same face.\n"
	.string "Natsue's.$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_1:
# 131 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Natsue$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_2:
# 132 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_3:
# 133 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Joji$"

tarc3_Accusation_EventScript_Ev_Sketchbook_Text_4:
# 134 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He's an artist. He draws what's in\n"
	.string "front of him.$"

tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_0:
# 145 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A man approached Gozo for Natsue's\n"
	.string "hand.\p"
	.string "He was refused - and not kindly.$"

tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_1:
# 146 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Mariko$"

tarc3_Accusation_EventScript_Ev_RefusedSuitor_Text_2:
# 147 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Who? If you know the name, say the\n"
	.string "name.$"

tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_0:
# 158 "data/scripts/tarc3_accusation_evidence.pory"
	.string "On the deck this afternoon, Gozo\n"
	.string "declared himself finished with paying\l"
	.string "for the boy's schooling.$"

tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_1:
# 159 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Kitaro$"

tarc3_Accusation_EventScript_Ev_TuitionFunds_Text_2:
# 160 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He wielded words like weapons. It was\n"
	.string "cruel.$"

tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_0:
# 171 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo funded Ichiro's art training.\p"
	.string "It wasn't a one-off gesture. Years of\n"
	.string "it.$"

tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_1:
# 172 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Suzuki$"

tarc3_Accusation_EventScript_Ev_IchiroSponsorship_Text_2:
# 173 "data/scripts/tarc3_accusation_evidence.pory"
	.string "It's true. I handled the arrangements\n"
	.string "myself, for eleven years.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_0:
# 185 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is a dry loaf in Ichiro's art bag.\p"
	.string "Artists use bread to lift charcoal\n"
	.string "from a page.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_1:
# 187 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There's bread in my cabin too.\p"
	.string "I'm a chef, {PLAYER} - I made bread\n"
	.string "for the entire wedding party.\p"
	.string "Are you accusing me, too?$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_2:
# 189 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Absurd, Joji.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_3:
# 191 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Bread. You have brought this room\n"
	.string "bread.$"

tarc3_Accusation_EventScript_Ev_BreadEraser_Text_4:
# 192 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Do continue, {PLAYER} Edgeworth. It\n"
	.string "is riveting.$"

tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_0:
# 202 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The man who asked for Natsue's hand\n"
	.string "drew no other subject.\p"
	.string "It was Ichiro. Four years of art,\n"
	.string "primarily of her.$"

tarc3_Accusation_EventScript_Ev_UnrequitedLove_Text_1:
# 209 "data/scripts/tarc3_accusation_evidence.pory"
	.string "What?! Ichiro and... Natsue?$"

tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_0:
# 222 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The sponsorship was not lapsing\n"
	.string "quietly.\p"
	.string "Gozo was severing the very career he\n"
	.string "had spent eleven years paying to\l"
	.string "build.$"

tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_1:
# 224 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He made certain it was heard. That was\n"
	.string "his way.$"

tarc3_Accusation_EventScript_Ev_SponsorshipWithdrawal_Text_2:
# 226 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...It was.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_0:
# 238 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Inside that doorway, in the blood\n"
	.string "itself, there were crumbs.\p"
	.string "Dry, and black with charcoal. They\n"
	.string "came off an artist's eraser.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_1:
# 240 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Crumbs. You are standing amongst a\n"
	.string "dead man's family, telling us about\l"
	.string "crumbs.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_2:
# 242 "data/scripts/tarc3_accusation_evidence.pory"
	.string "In the blood, Joji. Not beside it. The\n"
	.string "distinction is the entire point.\p"
	.string "They fell while it was still wet - from\n"
	.string "the cuff of the hand holding the\l"
	.string "knife.$"

tarc3_Accusation_EventScript_Ev_ArtistAtTheDoor_Text_3:
# 244 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...I see.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_0:
# 258 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have all accepted Ichiro's\n"
	.string "sponsorship had simply ran its course.\p"
	.string "Discard that.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_1:
# 259 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He asked Gozo for permission to court\n"
	.string "Natsue, and was refused.\p"
	.string "In that same week, Gozo announced her\n"
	.string "engagement to Takeshi.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_2:
# 260 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Then, on the deck this afternoon,\n"
	.string "Gozo told us he was finished paying\l"
	.string "for the boy.\p"
	.string "He performed it before us on the deck,\n"
	.string "with Ichiro standing eight feet away.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_3:
# 261 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo refused him twice over. His love,\n"
	.string "and his art.\p"
	.string "Two humiliations - and to Ichiro, they\n"
	.string "were the same wound.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_4:
# 270 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Twice refused. I can... I can see the\n"
	.string "source of his anger.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_5:
# 273 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A motive. At last, a motive.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_6:
# 274 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Do not preen, {PLAYER} Edgeworth.\n"
	.string "It took you all evening.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_7:
# 277 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have just proved that Ichiro had\n"
	.string "every reason to kill him.$"

tarc3_Accusation_EventScript_Ev_TwinRefusal_Text_8:
# 278 "data/scripts/tarc3_accusation_evidence.pory"
	.string "And you named Takeshi.\p"
	.string "Do you hear yourself?$"

tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_0:
# 288 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo summoned Takeshi to his cabin\n"
	.string "before dinner.$"

tarc3_Accusation_EventScript_Ev_TakeshisMeeting_Text_1:
# 290 "data/scripts/tarc3_accusation_evidence.pory"
	.string "So the last appointment my father\n"
	.string "ever kept was with him.$"

tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_0:
# 302 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo ruined Takeshi's father.\p"
	.string "The man lost his company, and took his\n"
	.string "own life the spring after.$"

tarc3_Accusation_EventScript_Ev_TakeshisHistory_Text_1:
# 304 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Yes. A cruel tale, and one not easily\n"
	.string "forgotten.$"

tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_0:
# 315 "data/scripts/tarc3_accusation_evidence.pory"
	.string "See this, a photograph from Takeshi's\n"
	.string "cabin.\p"
	.string "A boy, smiling, flanked by his father.$"

tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_1:
# 317 "data/scripts/tarc3_accusation_evidence.pory"
	.string "But why is this relevant?$"

tarc3_Accusation_EventScript_Ev_FamilyPicture_Text_2:
# 319 "data/scripts/tarc3_accusation_evidence.pory"
	.string "It is not.\p"
	.string "A photograph of a man proves nothing,\n"
	.string "and you know it.$"

tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_0:
# 329 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Mariko told me she overheard Gozo and\n"
	.string "Takeshi in argument before dinner.$"

tarc3_Accusation_EventScript_Ev_OverheardArgument_Text_1:
# 331 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I did. Through the cabin wall.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_0:
# 342 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Gozo summoned him to that cabin\n"
	.string "before dinner.\p"
	.string "And a little while later, Suzuki found\n"
	.string "his flower lying outside the door.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_1:
# 344 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There. We have known it all night.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_2:
# 346 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He lost that garland before that\n"
	.string "point! He told you that!$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_3:
# 348 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Takeshi$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_4:
# 349 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I did go in. I'm not going to pretend I\n"
	.string "didn't.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_5:
# 350 "data/scripts/tarc3_accusation_evidence.pory"
	.string "But he was alive when I left him.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_6:
# 352 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Sure.$"

tarc3_Accusation_EventScript_Ev_GozosFinalMeeting_Text_7:
# 355 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He told us a great many things.$"

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_0:
# 367 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Takeshi entered Hatamoto Corp two\n"
	.string "years ago.\p"
	.string "The company belonging to the man who\n"
	.string "destroyed his father.$"

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_1:
# 369 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Nobody does that by accident.$"

tarc3_Accusation_EventScript_Ev_TakeshisRevenge_Text_2:
# 371 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He came to us on purpose. He was\n"
	.string "always here on purpose.$"

tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_0:
# 388 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The bolt on the hold door carries a\n"
	.string "smear of black dust.\p"
	.string "Charcoal.$"

tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_1:
# 390 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Are you certain? It would have rubbed\n"
	.string "off when you inspected it, surely?$"

tarc3_Accusation_EventScript_Ev_CharcoalOnBolt_Text_2:
# 392 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He is right.\p"
	.string "Do not present what you cannot\n"
	.string "defend.$"

tarc3_Accusation_EventScript_Ev_LongAbsence_Text_0:
# 402 "data/scripts/tarc3_accusation_evidence.pory"
	.string "By all accounts, Ichiro left the table\n"
	.string "well before the lights failed.\p"
	.string "He was absent long enough.$"

tarc3_Accusation_EventScript_Ev_LongAbsence_Text_1:
# 404 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The poor boy was stressed. We all have\n"
	.string "been, tonight.$"

tarc3_Accusation_EventScript_Ev_LongAbsence_Text_2:
# 406 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You would do well to remember,\n"
	.string "{PLAYER} Edgeworth, that an\l"
	.string "absence alone is not a crime.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_0:
# 416 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Mariko has maintained it all evening.\n"
	.string "Takeshi had help from someone aboard.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_1:
# 418 "data/scripts/tarc3_accusation_evidence.pory"
	.string "At last. Thank you.\p"
	.string "An accomplice explains every locked\n"
	.string "door on this ship.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_2:
# 420 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have agreed with the loudest\n"
	.string "person in the room.$"

tarc3_Accusation_EventScript_Ev_AnAccomplice_Text_3:
# 421 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That is not deduction. That is\n"
	.string "surrender.$"

tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_0:
# 431 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The storeroom door was opened. Suzuki\n"
	.string "bolted it in front of all of us, yet\l"
	.string "someone drew it back.$"

tarc3_Accusation_EventScript_Ev_OpenStorageDoor_Text_1:
# 433 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Someone opened it from the outside.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_0:
# 444 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is a smear on the steps down to\n"
	.string "the hold.\p"
	.string "Blood, with black dust worked through\n"
	.string "it.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_1:
# 445 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The same charcoal that is on the bolt\n"
	.string "at the bottom of those stairs.\p"
	.string "One pair of hands left both marks.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_2:
# 447 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Or the boy left them climbing up.$"

tarc3_Accusation_EventScript_Ev_BloodOnTheStair_Text_3:
# 449 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Takeshi was still bolted in. Someone\n"
	.string "came down these stairs to let him out.\p"
	.string "And he was already carrying Tatsuo\n"
	.string "with him.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_0:
# 460 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Natsue, Franziska and I heard two\n"
	.string "sounds from the deck.\p"
	.string "A splash, and then something heavy\n"
	.string "striking the floor.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_1:
# 461 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The order is important. The splash\n"
	.string "came first.\p"
	.string "Someone stood at that rail, disposing\n"
	.string "of the knife that killed Gozo.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_2:
# 462 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Tatsuo saw the weapon go over the\n"
	.string "side. That is the entire reason he is\l"
	.string "dead.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_3:
# 464 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Or, an accomplice.\p"
	.string "It has always been an accomplice, and\n"
	.string "you have never once dealt with it!$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_4:
# 466 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is no accomplice.\p"
	.string "There is one man disposing of a\n"
	.string "weapon, and the misfortune of being\l"
	.string "observed.$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_5:
# 467 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Akie$"

tarc3_Accusation_EventScript_Ev_SilencedWitness_Text_6:
# 474 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I yelled at him.\p"
	.string "He went to the deck to give me space...\n"
	.string "I did this.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_0:
# 484 "data/scripts/tarc3_accusation_evidence.pory"
	.string "On the matter of the supposed\n"
	.string "accomplice.\p"
	.string "Takeshi heard his door unbolted, and\n"
	.string "footsteps departing. Someone\l"
	.string "released him.\p"
	.string "From that moment, a man moved freely\n"
	.string "about this ship whom nobody could\l"
	.string "account for.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_1:
# 486 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Someone let him out. I have said so\n"
	.string "from the start.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_2:
# 489 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I didn't unlock that door. I've told\n"
	.string "you. I heard it open.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_3:
# 491 "data/scripts/tarc3_accusation_evidence.pory"
	.string "By itself.$"

tarc3_Accusation_EventScript_Ev_TheAccompliceTheory_Text_4:
# 494 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Then where is this accomplice? Name\n"
	.string "one person in this room.$"

tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_0:
# 508 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's Smeargle battled me this\n"
	.string "afternoon, but I didn't see all of its\l"
	.string "moves.$"

tarc3_Accusation_EventScript_Ev_SmeargleRepertoire_Text_1:
# 510 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Smeargle can Sketch any move. What is\n"
	.string "your argument?$"

tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_0:
# 521 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro asked you for a battle, but\n"
	.string "barely attacked.\p"
	.string "His Smeargle stood and studied your\n"
	.string "moves.$"

tarc3_Accusation_EventScript_Ev_TheOddBattle_Text_1:
# 523 "data/scripts/tarc3_accusation_evidence.pory"
	.string "My Pawmot used Discharge in front of\n"
	.string "it... But I didn't think anything of it.$"

tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_0:
# 535 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The storeroom in which Takeshi was\n"
	.string "locked sits on the same deck as the\l"
	.string "breaker panel.$"

tarc3_Accusation_EventScript_Ev_TheHoldAdjoins_Text_1:
# 537 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...That is true. Once out, he had easy\n"
	.string "access.$"

tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_0:
# 548 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's Smeargle sketched Discharge\n"
	.string "from Kitaro's Pawmot - and it did so on\l"
	.string "Ichiro's instruction.$"

tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_1:
# 550 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I didn't notice it. Surely, Ichiro\n"
	.string "wouldn't think to do that in a battle?$"

tarc3_Accusation_EventScript_Ev_SmeargleKnowsDischarge_Text_2:
# 552 "data/scripts/tarc3_accusation_evidence.pory"
	.string "So what if it did?\p"
	.string "We are all still in the dark. How\n"
	.string "appropriate.$"

tarc3_Accusation_EventScript_Ev_PanelStruck_Text_0:
# 563 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That panel did not short.\p"
	.string "It was struck once, from outside the\n"
	.string "casing, by a single focused jolt of\l"
	.string "electricity.$"

tarc3_Accusation_EventScript_Ev_PanelStruck_Text_1:
# 565 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I said the wiring was old. I believed\n"
	.string "it, too, but I am less certain now.$"

tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_0:
# 576 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The storage room is located next to\n"
	.string "the breaker room.\p"
	.string "The escaped man was at liberty\n"
	.string "precisely where the lights died.$"

tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_1:
# 578 "data/scripts/tarc3_accusation_evidence.pory"
	.string "So he escaped from a room he was\n"
	.string "locked in, and just put his hand on a\l"
	.string "switch.$"

tarc3_Accusation_EventScript_Ev_TheNearestHand_Text_2:
# 585 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...I know how it sounds.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_0:
# 600 "data/scripts/tarc3_accusation_evidence.pory"
	.string "We have all heard of the ship's alleged\n"
	.string "old wiring. Discard it.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_1:
# 601 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That panel did not short.\p"
	.string "It was struck once, from outside the\n"
	.string "casing, by a focused jolt of\l"
	.string "electricity.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_2:
# 602 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro's Smeargle sketched Discharge\n"
	.string "from Kitaro's Pawmot, on Ichiro's\l"
	.string "instruction. We witnessed this battle.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_3:
# 603 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The blackout was a Pokemon's move,\n"
	.string "aimed at a breaker.\p"
	.string "And precisely one Pokemon aboard this\n"
	.string "ship learned to produce it today.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_4:
# 611 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I said the wiring was old. I was so\n"
	.string "confident it was a coincidence.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_5:
# 612 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I... was wrong.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_6:
# 615 "data/scripts/tarc3_accusation_evidence.pory"
	.string "A Pokemon's move, aimed at a breaker.\n"
	.string "That is incontrovertible.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_7:
# 616 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...Flawless, {PLAYER} Edgeworth.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_8:
# 619 "data/scripts/tarc3_accusation_evidence.pory"
	.string "That was flawless, and it points\n"
	.string "squarely at a man you did not accuse.$"

tarc3_Accusation_EventScript_Ev_SketchedDischarge_Text_9:
# 620 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You are prosecuting your own case\n"
	.string "into the ground.$"

tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_0:
# 632 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There are no defensive wounds on his\n"
	.string "hands. No cuts to the forearms.\p"
	.string "Nothing whatsoever.$"

tarc3_Accusation_EventScript_Ev_NoDefensiveWounds_Text_1:
# 634 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You're saying he did that to himself?\n"
	.string "Surely not.$"

tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_0:
# 645 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro told us he saw nothing at all.\p"
	.string "Yet pressed upon it, he described the\n"
	.string "knife coming down - in a room with no\l"
	.string "light in it.$"

tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_1:
# 646 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Ichiro$"

tarc3_Accusation_EventScript_Ev_TheSecondStory_Text_2:
# 648 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I heard it. I must have heard it.$"

tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_0:
# 659 "data/scripts/tarc3_accusation_evidence.pory"
	.string "One clean, careful wound, in a\n"
	.string "non-vital place.\p"
	.string "Placed in total darkness, upon a man\n"
	.string "who claims he never saw his attacker.$"

tarc3_Accusation_EventScript_Ev_ImpossiblePrecision_Text_1:
# 661 "data/scripts/tarc3_accusation_evidence.pory"
	.string "In the dark, into a struggling man...\n"
	.string "no.\p"
	.string "That cut was placed slowly.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_0:
# 672 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The first knife went into the sea, and\n"
	.string "the man who threw it killed to keep\l"
	.string "that quiet.\p"
	.string "The second was left lying on a\n"
	.string "bathroom floor, six feet from Ichiro.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_1:
# 674 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He was on the floor. There was blood\n"
	.string "on the tiles - I saw it, I was there.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_2:
# 676 "data/scripts/tarc3_accusation_evidence.pory"
	.string "I know you were.$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_3:
# 678 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Why hide one blade and abandon the\n"
	.string "other?$"

tarc3_Accusation_EventScript_Ev_InconsistentDisposal_Text_4:
# 680 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Yes. Why indeed.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_0:
# 694 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He did it to himself.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_1:
# 697 "data/scripts/tarc3_accusation_evidence.pory"
	.string "One cut. Clean, and in a non-vital\n"
	.string "location.\p"
	.string "Delivered in a room with no light in it\n"
	.string "whatsoever.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_2:
# 698 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Consider the others. Gozo was stabbed\n"
	.string "relentlessly.\p"
	.string "Tatsuo took a vicious blow to the\n"
	.string "back of the head.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_3:
# 699 "data/scripts/tarc3_accusation_evidence.pory"
	.string "And yet there is not one defensive\n"
	.string "mark upon Ichiro's hands.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_4:
# 700 "data/scripts/tarc3_accusation_evidence.pory"
	.string "The knife then presents itself six\n"
	.string "feet from him, on the bathroom floor.\p"
	.string "The first weapon went into the sea,\n"
	.string "and the man who threw it killed to\l"
	.string "keep that quiet.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_5:
# 701 "data/scripts/tarc3_accusation_evidence.pory"
	.string "He did not conceal the second blade,\n"
	.string "because he never intended to leave\l"
	.string "that room carrying it.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_6:
# 708 "data/scripts/tarc3_accusation_evidence.pory"
	.string "An impressive deduction, {PLAYER}\n"
	.string "Edgeworth. It makes sense.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_7:
# 711 "data/scripts/tarc3_accusation_evidence.pory"
	.string "You have just told this room that\n"
	.string "Ichiro wounded himself.$"

tarc3_Accusation_EventScript_Ev_SelfInflictedWound_Text_8:
# 712 "data/scripts/tarc3_accusation_evidence.pory"
	.string "And you named Takeshi.\p"
	.string "I have no words for you.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_0:
# 722 "data/scripts/tarc3_accusation_evidence.pory"
	.string "There is a sack of maintenance\n"
	.string "equipment on the foredeck, with two\l"
	.string "lengths of pipe jutting out of the top\l"
	.string "of it.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_1:
# 723 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Tatsuo broke those fittings himself\n"
	.string "this afternoon and hid them in there.\p"
	.string "He told me so, laughing.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_2:
# 725 "data/scripts/tarc3_accusation_evidence.pory"
	.string "...That is exactly the sort of thing he\n"
	.string "would do.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_3:
# 727 "data/scripts/tarc3_accusation_evidence.pory"
	.string "One of those two pipes has his blood\n"
	.string "on it, and it is still in that sack.\p"
	.string "The weapon that killed him was lying a\n"
	.string "step from where he stood.$"

tarc3_Accusation_EventScript_Ev_HiddenPipe_Text_4:
# 728 "data/scripts/tarc3_accusation_evidence.pory"
	.string "Nothing was carried out onto that\n"
	.string "deck. Ichiro took up the first heavy\l"
	.string "thing he found - he did not intend to\l"
	.string "kill again.$"
