tarc3_TatsuoRecon_EventScript_Begin::
# 5 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setvar VAR_TEMP_8, 0
# 6 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setvar VAR_TEMP_9, 3
# 7 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_SUZUKI_2, tarc3_TatsuoRecon_EventScript_Begin_Movement_0
# 8 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_AKIE_2, tarc3_TatsuoRecon_EventScript_Begin_Movement_1
# 9 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_KITARO_2, tarc3_TatsuoRecon_EventScript_Begin_Movement_0
# 10 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_JOJI_2, tarc3_TatsuoRecon_EventScript_Begin_Movement_1
# 11 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_ICHIRO_2, tarc3_TatsuoRecon_EventScript_Begin_Movement_0
# 12 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_MARIKO_2, tarc3_TatsuoRecon_EventScript_Begin_Movement_1
# 13 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmovement 0
# 14 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 15 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 16 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Begin_Text_1
# 17 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Begin_Text_2
# 18 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 19 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 20 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 21 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1
	return


tarc3_TatsuoRecon_EventScript_Q1::
# 27 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 28 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1_Text_0
# 29 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1_Text_1
# 30 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 31 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1_Text_2
# 32 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1_Text_3
# 33 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 34 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 35 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 36 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1Ask
	return


tarc3_TatsuoRecon_EventScript_Q1Ask::
# 40 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 41 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	message tarc3_TatsuoRecon_EventScript_Q1Ask_Text_0
# 42 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmessage
# 43 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q1Ask_Text_1, 1
# 44 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q1Ask_Text_2, 2
# 45 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q1Ask_Text_3, 3
# 46 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 47 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 48 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	switch VAR_RESULT
# 49 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 1, tarc3_TatsuoRecon_EventScript_Q1Ask_2
# 51 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 2, tarc3_TatsuoRecon_EventScript_Q1Ask_3
# 54 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1Right
	return

tarc3_TatsuoRecon_EventScript_Q1Ask_2:
# 50 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1WrongAfter
	return

tarc3_TatsuoRecon_EventScript_Q1Ask_3:
# 52 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1WrongMon
	return


tarc3_TatsuoRecon_EventScript_Q1WrongAfter::
# 59 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 60 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_1
# 61 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_2
# 62 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 63 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 64 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1Miss
	return


tarc3_TatsuoRecon_EventScript_Q1WrongMon::
# 68 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 69 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1WrongMon_Text_0
# 70 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1WrongMon_Text_1
# 71 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 72 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 73 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1Miss
	return


tarc3_TatsuoRecon_EventScript_Q1Miss::
# 77 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 78 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_TatsuoRecon_EventScript_Q1Give
# 79 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 80 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1Ask
	return


tarc3_TatsuoRecon_EventScript_Q1Right::
# 84 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_TatsuoRecon_EventScript_Q1Right_2
tarc3_TatsuoRecon_EventScript_Q1Right_1:
# 87 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 88 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1Right_Text_0
# 89 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1Right_Text_1
# 90 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1Right_Text_2
# 91 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 92 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 93 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 94 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q1React
	return

tarc3_TatsuoRecon_EventScript_Q1Right_2:
# 85 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_TatsuoRecon_EventScript_Q1Right_1


tarc3_TatsuoRecon_EventScript_Q1React::
# 98 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	playse SE_PIN
# 99 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_SUZUKI_2, tarc3_TatsuoRecon_EventScript_Q1React_Movement_0
# 100 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmovement 0
# 101 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1React_Text_0
# 102 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1React_Text_1
# 103 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 104 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 105 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 106 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2Gate
	return


tarc3_TatsuoRecon_EventScript_Q1Give::
# 110 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 111 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1Give_Text_0
# 112 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q1Give_Text_1
# 113 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 114 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 115 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 116 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2Gate
	return


tarc3_TatsuoRecon_EventScript_Q2Gate::
# 122 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	checkevidence EVD_BLOODY_CLOTH
# 123 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_eq VAR_RESULT, TRUE, tarc3_TatsuoRecon_EventScript_Q2
# 124 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3
	return


tarc3_TatsuoRecon_EventScript_Q2::
# 128 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 129 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setvar VAR_TEMP_9, 4
# 130 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2_Text_0
# 131 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2_Text_1
# 132 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 133 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2_Text_2
# 134 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 135 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 136 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 137 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2Ask
	return


tarc3_TatsuoRecon_EventScript_Q2Ask::
# 141 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 142 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	message tarc3_TatsuoRecon_EventScript_Q2Ask_Text_0
# 143 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmessage
# 144 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q2Ask_Text_1, 1
# 145 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q2Ask_Text_2, 2
# 146 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q2Ask_Text_3, 3
# 147 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 148 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 149 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	switch VAR_RESULT
# 150 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 1, tarc3_TatsuoRecon_EventScript_Q2Ask_2
# 152 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 2, tarc3_TatsuoRecon_EventScript_Q2Ask_3
# 155 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2Right
	return

tarc3_TatsuoRecon_EventScript_Q2Ask_2:
# 151 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2WrongPipe
	return

tarc3_TatsuoRecon_EventScript_Q2Ask_3:
# 153 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2WrongHis
	return


tarc3_TatsuoRecon_EventScript_Q2WrongPipe::
# 160 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 161 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2WrongPipe_Text_0
# 162 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2WrongPipe_Text_1
# 163 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 164 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 165 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2Miss
	return


tarc3_TatsuoRecon_EventScript_Q2WrongHis::
# 169 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_0
# 170 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_1
# 171 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 172 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_2
# 173 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 174 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 175 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2Miss
	return


tarc3_TatsuoRecon_EventScript_Q2Miss::
# 179 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 180 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_TatsuoRecon_EventScript_Q2Give
# 181 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 182 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q2Ask
	return


tarc3_TatsuoRecon_EventScript_Q2Right::
# 186 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_TatsuoRecon_EventScript_Q2Right_2
tarc3_TatsuoRecon_EventScript_Q2Right_1:
# 189 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 190 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2Right_Text_0
# 191 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2Right_Text_1
# 192 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2Right_Text_2
# 193 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 194 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 195 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 196 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	playse SE_PIN
# 197 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_JOJI_2, tarc3_TatsuoRecon_EventScript_Q1React_Movement_0
# 198 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmovement 0
# 199 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2Right_Text_3
# 200 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2Right_Text_4
# 201 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 202 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 203 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 204 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3
	return

tarc3_TatsuoRecon_EventScript_Q2Right_2:
# 187 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_TatsuoRecon_EventScript_Q2Right_1


tarc3_TatsuoRecon_EventScript_Q2Give::
# 208 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 209 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2Give_Text_0
# 210 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q2Give_Text_1
# 211 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 212 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 213 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 214 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3
	return


tarc3_TatsuoRecon_EventScript_Q3::
# 220 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 221 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1_Text_0
# 222 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3_Text_0
# 223 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 224 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3_Text_1
# 225 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 226 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 227 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 228 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3Ask
	return


tarc3_TatsuoRecon_EventScript_Q3Ask::
# 232 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 233 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	message tarc3_TatsuoRecon_EventScript_Q3Ask_Text_0
# 234 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmessage
# 235 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q3Ask_Text_1, 1
# 236 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q3Ask_Text_2, 2
# 237 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q3Ask_Text_3, 3
# 238 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 239 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 240 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	switch VAR_RESULT
# 241 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 1, tarc3_TatsuoRecon_EventScript_Q3Ask_2
# 243 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 2, tarc3_TatsuoRecon_EventScript_Q3Ask_3
# 246 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3Right
	return

tarc3_TatsuoRecon_EventScript_Q3Ask_2:
# 242 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3WrongCarried
	return

tarc3_TatsuoRecon_EventScript_Q3Ask_3:
# 244 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3Hands
	return


tarc3_TatsuoRecon_EventScript_Q3WrongCarried::
# 251 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 252 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3WrongCarried_Text_0
# 253 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3WrongCarried_Text_1
# 254 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 255 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 256 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3Miss
	return


tarc3_TatsuoRecon_EventScript_Q3Hands::
# 260 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 261 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Hands_Text_0
# 262 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Hands_Text_1
# 263 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 264 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 265 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3Miss
	return


tarc3_TatsuoRecon_EventScript_Q3Miss::
# 269 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 270 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_TatsuoRecon_EventScript_Q3Give
# 271 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 272 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3Ask
	return


tarc3_TatsuoRecon_EventScript_Q3Right::
# 276 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_TatsuoRecon_EventScript_Q3Right_2
tarc3_TatsuoRecon_EventScript_Q3Right_1:
# 279 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 280 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Right_Text_0
# 281 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 282 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 283 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	checkevidence EVD_HIDDEN_PIPE
# 284 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_eq VAR_RESULT, TRUE, tarc3_TatsuoRecon_EventScript_Q3Hidden
# 285 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3React
	return

tarc3_TatsuoRecon_EventScript_Q3Right_2:
# 277 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_TatsuoRecon_EventScript_Q3Right_1


tarc3_TatsuoRecon_EventScript_Q3Hidden::
# 291 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 292 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Hidden_Text_0
# 293 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_0
# 294 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Hidden_Text_1
# 295 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 296 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 297 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 298 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q3React
	return


tarc3_TatsuoRecon_EventScript_Q3React::
# 302 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	playse SE_PIN
# 303 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	applymovement LOCALID_FOREDECK_AKIE_2, tarc3_TatsuoRecon_EventScript_Q1React_Movement_0
# 304 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmovement 0
# 305 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 306 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3React_Text_0
# 307 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 308 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 309 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_set FLAG_TARC3_DECK2_FOUND_WEAPON, tarc3_TatsuoRecon_EventScript_Q3Weapon
# 310 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 311 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4
	return


tarc3_TatsuoRecon_EventScript_Q3Weapon::
# 317 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 318 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Weapon_Text_0
# 319 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1_Text_0
# 320 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Weapon_Text_1
# 321 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 322 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Weapon_Text_2
# 323 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 324 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 325 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 326 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4
	return


tarc3_TatsuoRecon_EventScript_Q3Give::
# 330 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 331 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Give_Text_0
# 332 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q3Give_Text_1
# 333 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 334 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 335 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 336 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4
	return


tarc3_TatsuoRecon_EventScript_Q4::
# 342 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 343 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2_Text_0
# 344 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4_Text_0
# 345 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 346 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4_Text_1
# 347 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 348 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 349 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 350 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4Ask
	return


tarc3_TatsuoRecon_EventScript_Q4Ask::
# 354 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 355 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	message tarc3_TatsuoRecon_EventScript_Q4Ask_Text_0
# 356 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	waitmessage
# 357 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q4Ask_Text_1, 1
# 358 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q4Ask_Text_2, 2
# 359 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultipush tarc3_TatsuoRecon_EventScript_Q4Ask_Text_3, 3
# 360 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 361 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 362 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	switch VAR_RESULT
# 363 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 1, tarc3_TatsuoRecon_EventScript_Q4Ask_2
# 365 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	case 2, tarc3_TatsuoRecon_EventScript_Q4Ask_3
# 368 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4Right
	return

tarc3_TatsuoRecon_EventScript_Q4Ask_2:
# 364 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4WrongEstate
	return

tarc3_TatsuoRecon_EventScript_Q4Ask_3:
# 366 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4WrongMistake
	return


tarc3_TatsuoRecon_EventScript_Q4WrongEstate::
# 373 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_0
# 374 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4WrongEstate_Text_0
# 375 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 376 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4WrongEstate_Text_1
# 377 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 378 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 379 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4Miss
	return


tarc3_TatsuoRecon_EventScript_Q4WrongMistake::
# 383 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 384 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4WrongMistake_Text_0
# 385 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4WrongMistake_Text_1
# 386 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 387 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 388 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4Miss
	return


tarc3_TatsuoRecon_EventScript_Q4Miss::
# 392 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 393 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_TatsuoRecon_EventScript_Q4Give
# 394 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 395 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Q4Ask
	return


tarc3_TatsuoRecon_EventScript_Q4Right::
# 399 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_TatsuoRecon_EventScript_Q4Right_2
tarc3_TatsuoRecon_EventScript_Q4Right_1:
# 402 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 403 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4Right_Text_0
# 404 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 405 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 406 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 30
# 407 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 408 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4Right_Text_1
# 409 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4Right_Text_2
# 410 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_set FLAG_TARC3_DECK2_FOUND_BODY, tarc3_TatsuoRecon_EventScript_Q4Right_5
tarc3_TatsuoRecon_EventScript_Q4Right_4:
# 413 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 414 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 415 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 416 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Closing
	return

tarc3_TatsuoRecon_EventScript_Q4Right_2:
# 400 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_TatsuoRecon_EventScript_Q4Right_1

tarc3_TatsuoRecon_EventScript_Q4Right_5:
# 411 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4Right_Text_3
	goto tarc3_TatsuoRecon_EventScript_Q4Right_4


tarc3_TatsuoRecon_EventScript_Q4Give::
# 420 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 421 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Q4Give_Text_0
# 422 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 423 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 424 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 425 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_Closing
	return


tarc3_TatsuoRecon_EventScript_Closing::
# 431 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 432 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Closing_Text_0
# 433 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Closing_Text_1
# 434 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Closing_Text_2
# 435 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 436 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 437 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 438 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Begin_Text_0
# 439 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_Closing_Text_3
# 440 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 441 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 442 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 443 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_ClosingGrade
	return


tarc3_TatsuoRecon_EventScript_ClosingGrade::
# 447 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_eq VAR_TEMP_9, 4, tarc3_TatsuoRecon_EventScript_ClosingGrade4
# 448 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_8, 3, tarc3_TatsuoRecon_EventScript_ClosingBest
# 449 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_8, 2, tarc3_TatsuoRecon_EventScript_ClosingFair
# 450 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_ClosingPoor
	return


tarc3_TatsuoRecon_EventScript_ClosingGrade4::
# 454 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_8, 4, tarc3_TatsuoRecon_EventScript_ClosingBest
# 455 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto_if_ge VAR_TEMP_8, 2, tarc3_TatsuoRecon_EventScript_ClosingFair
# 456 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	goto tarc3_TatsuoRecon_EventScript_ClosingPoor
	return


tarc3_TatsuoRecon_EventScript_ClosingBest::
# 460 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	fadeoutbgm 4
# 461 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 60
# 462 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_0
# 463 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingBest_Text_0
# 464 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingBest_Text_1
# 465 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 466 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingBest_Text_2
# 467 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 468 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 469 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 470 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setflag FLAG_TARC3_TATSUO_RECONSTRUCTED
	return


tarc3_TatsuoRecon_EventScript_ClosingFair::
# 475 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1_Text_0
# 476 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingFair_Text_0
# 477 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2_Text_0
# 478 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingFair_Text_1
# 479 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 480 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingFair_Text_2
# 481 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 482 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 483 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 484 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setflag FLAG_TARC3_TATSUO_RECONSTRUCTED
	return


tarc3_TatsuoRecon_EventScript_ClosingPoor::
# 489 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q2_Text_0
# 490 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingPoor_Text_0
# 491 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0
# 492 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	msgbox tarc3_TatsuoRecon_EventScript_ClosingPoor_Text_1
# 493 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setspeaker NULL
# 494 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	closemessage
# 495 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	delay 20
# 496 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	setflag FLAG_TARC3_TATSUO_RECONSTRUCTED
	return


# 7 "data/scripts/tarc3_tatsuo_reconstruction.pory"
tarc3_TatsuoRecon_EventScript_Begin_Movement_0:
# 7 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	walk_in_place_fast_right
	step_end

# 8 "data/scripts/tarc3_tatsuo_reconstruction.pory"
tarc3_TatsuoRecon_EventScript_Begin_Movement_1:
# 8 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	walk_in_place_fast_down
	step_end

# 99 "data/scripts/tarc3_tatsuo_reconstruction.pory"
tarc3_TatsuoRecon_EventScript_Q1React_Movement_0:
# 99 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	emote_exclamation_mark
	step_end

tarc3_TatsuoRecon_EventScript_Begin_Text_0:
# 15 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "{PLAYER}$"

tarc3_TatsuoRecon_EventScript_Begin_Text_1:
# 16 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "I do not know the identity of the\n"
	.string "murderer. Yet.$"

tarc3_TatsuoRecon_EventScript_Begin_Text_2:
# 17 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "However, I believe I can give you a\n"
	.string "reason for this cruelty.$"

tarc3_TatsuoRecon_EventScript_Q1_Text_0:
# 28 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Kitaro$"

tarc3_TatsuoRecon_EventScript_Q1_Text_1:
# 29 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "You heard it, then. The two of them, one\n"
	.string "after the other.$"

tarc3_TatsuoRecon_EventScript_Q1_Text_2:
# 31 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "A splash. Then, some seconds after it, a\n"
	.string "heavy thing striking this deck.$"

tarc3_TatsuoRecon_EventScript_Q1_Text_3:
# 32 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The second of those was Tatsuo. Nobody\n"
	.string "in this family disputes that.$"

tarc3_TatsuoRecon_EventScript_Q1Ask_Text_0:
# 41 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "{FONT_NARROW}Then what was the splash?$"

tarc3_TatsuoRecon_EventScript_Q1Ask_Text_1:
# 43 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The weapon, thrown over afterwards$"

tarc3_TatsuoRecon_EventScript_Q1Ask_Text_2:
# 44 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "A Pelipper out in the water$"

tarc3_TatsuoRecon_EventScript_Q1Ask_Text_3:
# 45 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Something he was already disposing of$"

tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_0:
# 59 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "{RIVAL}$"

tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_1:
# 60 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Afterwards. You have put the disposal\n"
	.string "after the killing.$"

tarc3_TatsuoRecon_EventScript_Q1WrongAfter_Text_2:
# 61 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The splash was first. Either that order\n"
	.string "means something or you have wasted an\l"
	.string "hour of my evening.$"

tarc3_TatsuoRecon_EventScript_Q1WrongMon_Text_0:
# 69 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "So a Pelipper struck the water.\p"
	.string "And four seconds later, by mere\n"
	.string "coincidence, a man died on this deck?$"

tarc3_TatsuoRecon_EventScript_Q1WrongMon_Text_1:
# 70 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Coincidence is what people reach for\n"
	.string "when they have stopped thinking.\p"
	.string "Reach further.$"

tarc3_TatsuoRecon_EventScript_Q1Right_Text_0:
# 88 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Something he was already getting rid\n"
	.string "of.$"

tarc3_TatsuoRecon_EventScript_Q1Right_Text_1:
# 89 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "A man who comes out here to kill strikes\n"
	.string "first and drops the weapon after.\p"
	.string "That gives you a thud, and then a\n"
	.string "splash.$"

tarc3_TatsuoRecon_EventScript_Q1Right_Text_2:
# 90 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "We heard the reverse. Whoever stood at\n"
	.string "this rail was disposing of something\l"
	.string "before Tatsuo was ever touched.$"

tarc3_TatsuoRecon_EventScript_Q1React_Text_0:
# 101 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Suzuki$"

tarc3_TatsuoRecon_EventScript_Q1React_Text_1:
# 102 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "...Of course.$"

tarc3_TatsuoRecon_EventScript_Q1Give_Text_0:
# 111 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The splash came first, so it cannot\n"
	.string "have been the weapon that killed him. He\l"
	.string "was already disposing of something.$"

tarc3_TatsuoRecon_EventScript_Q1Give_Text_1:
# 112 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "That is one sentence, {PLAYER}\n"
	.string "Edgeworth, and you had all of the\l"
	.string "pieces of it.$"

tarc3_TatsuoRecon_EventScript_Q2_Text_0:
# 130 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Mariko$"

tarc3_TatsuoRecon_EventScript_Q2_Text_1:
# 131 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Then say what went into the sea, if you\n"
	.string "are so certain of the order of it.$"

tarc3_TatsuoRecon_EventScript_Q2_Text_2:
# 133 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "I intend to. Cramorant brought a piece\n"
	.string "of it back.$"

tarc3_TatsuoRecon_EventScript_Q2Ask_Text_0:
# 142 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "{FONT_NARROW}What went over that rail?$"

tarc3_TatsuoRecon_EventScript_Q2Ask_Text_1:
# 144 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The pipe that killed him$"

tarc3_TatsuoRecon_EventScript_Q2Ask_Text_2:
# 145 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Something of Tatsuo's$"

tarc3_TatsuoRecon_EventScript_Q2Ask_Text_3:
# 146 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The knife that killed Gozo$"

tarc3_TatsuoRecon_EventScript_Q2WrongPipe_Text_0:
# 161 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The order, again. A splash was heard\n"
	.string "first. The thud followed.\p"
	.string "A murder weapon can only become a\n"
	.string "murder weapon after it has murdered.$"

tarc3_TatsuoRecon_EventScript_Q2WrongPipe_Text_1:
# 162 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "You have established one fact tonight.\n"
	.string "Kindly stop walking back over it.$"

tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_0:
# 169 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Akie$"

tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_1:
# 170 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He... He is lying there. Nothing of his\n"
	.string "went anywhere.$"

tarc3_TatsuoRecon_EventScript_Q2WrongHis_Text_2:
# 172 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Contradicted by his widow, and by your\n"
	.string "own eyes. Think before you speak.$"

tarc3_TatsuoRecon_EventScript_Q2Right_Text_0:
# 190 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The knife that killed Gozo Hatamoto.$"

tarc3_TatsuoRecon_EventScript_Q2Right_Text_1:
# 191 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "There is no blade in that cabin. I\n"
	.string "expect that blade is no longer anywhere\l"
	.string "on this ship.$"

tarc3_TatsuoRecon_EventScript_Q2Right_Text_2:
# 192 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "What caught on this rail is not a\n"
	.string "weapon. It is a cloth, dark along one\l"
	.string "edge.\p"
	.string "I submit that this bloody rag was\n"
	.string "wrapped around the blade as it went\l"
	.string "over the side.$"

tarc3_TatsuoRecon_EventScript_Q2Right_Text_3:
# 199 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Joji$"

tarc3_TatsuoRecon_EventScript_Q2Right_Text_4:
# 200 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "...No one should have been able to\n"
	.string "access my knives.$"

tarc3_TatsuoRecon_EventScript_Q2Give_Text_0:
# 209 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The knife, you fool. Gozo's knife,\n"
	.string "missing since the cabin was opened.\p"
	.string "A bloodied cloth snagged on this rail.$"

tarc3_TatsuoRecon_EventScript_Q2Give_Text_1:
# 210 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Two facts that were never more than a\n"
	.string "sentence apart, and you could not\l"
	.string "bridge them.$"

tarc3_TatsuoRecon_EventScript_Q3_Text_0:
# 222 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Then he came out here armed. He came\n"
	.string "out here intending to kill.$"

tarc3_TatsuoRecon_EventScript_Q3_Text_1:
# 224 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "No. Look deeper at the evidence.$"

tarc3_TatsuoRecon_EventScript_Q3Ask_Text_0:
# 233 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "{FONT_NARROW}Where did the thing that killed him come from?$"

tarc3_TatsuoRecon_EventScript_Q3Ask_Text_1:
# 235 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He carried it out with him$"

tarc3_TatsuoRecon_EventScript_Q3Ask_Text_2:
# 236 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He used his bare hands$"

tarc3_TatsuoRecon_EventScript_Q3Ask_Text_3:
# 237 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "It was already lying on this deck$"

tarc3_TatsuoRecon_EventScript_Q3WrongCarried_Text_0:
# 252 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "A man disposing of one murder weapon,\n"
	.string "with a second in his other hand.$"

tarc3_TatsuoRecon_EventScript_Q3WrongCarried_Text_1:
# 253 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Say that sentence aloud and hear what\n"
	.string "is wrong with it.$"

tarc3_TatsuoRecon_EventScript_Q3Hands_Text_0:
# 261 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Tatsuo's cause of death was blunt\n"
	.string "force trauma.\p"
	.string "Bare fists do not produce wounds of\n"
	.string "that severity.$"

tarc3_TatsuoRecon_EventScript_Q3Hands_Text_1:
# 262 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "That answer was beneath you,\n"
	.string "{PLAYER} Edgeworth.$"

tarc3_TatsuoRecon_EventScript_Q3Right_Text_0:
# 280 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "It was already out here. In the\n"
	.string "equipment sack, four paces from where\l"
	.string "he was standing.$"

tarc3_TatsuoRecon_EventScript_Q3Hidden_Text_0:
# 292 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "And it was Tatsuo who put it there. He\n"
	.string "broke some deck fittings this\l"
	.string "afternoon.\p"
	.string "He hid the pieces in that sack, where\n"
	.string "they would pass for ship's equipment.\p"
	.string "He told me so himself, and was proud of\n"
	.string "it.$"

tarc3_TatsuoRecon_EventScript_Q3Hidden_Text_1:
# 294 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "...That is exactly the sort of thing he\n"
	.string "would do.$"

tarc3_TatsuoRecon_EventScript_Q3React_Text_0:
# 306 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Nothing was carried onto this deck. He\n"
	.string "took up the first heavy thing he\l"
	.string "stumbled over.\p"
	.string "Which is what a man does when he did not\n"
	.string "come out here to kill.$"

tarc3_TatsuoRecon_EventScript_Q3Weapon_Text_0:
# 318 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "And it is still aboard. Back in the\n"
	.string "equipment sack, with his blood dried\l"
	.string "along it. Whoever used it put it back.$"

tarc3_TatsuoRecon_EventScript_Q3Weapon_Text_1:
# 320 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "...He put it back. He stood out here\n"
	.string "afterwards and he put it back.$"

tarc3_TatsuoRecon_EventScript_Q3Weapon_Text_2:
# 322 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He carried the knife the length of this\n"
	.string "deck to drown it.\p"
	.string "The pipe he left where he found it.\p"
	.string "The knife was the errand. The pipe was\n"
	.string "the accident, and he heard us coming.$"

tarc3_TatsuoRecon_EventScript_Q3Give_Text_0:
# 331 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "It was already on this deck, in that\n"
	.string "equipment sack.\p"
	.string "He snatched it up where he stood.$"

tarc3_TatsuoRecon_EventScript_Q3Give_Text_1:
# 332 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Nothing about this was prepared. The\n"
	.string "most useful thing this deck has told us.\p"
	.string "And you walked past it twice.$"

tarc3_TatsuoRecon_EventScript_Q4_Text_0:
# 344 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Unprepared. Improvised. You are\n"
	.string "describing an unlucky man, not a reason.$"

tarc3_TatsuoRecon_EventScript_Q4_Text_1:
# 346 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Then let me give you a reason. You will\n"
	.string "not like how small it is.$"

tarc3_TatsuoRecon_EventScript_Q4Ask_Text_0:
# 355 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "{FONT_NARROW}Then why is Tatsuo Kaneko dead?$"

tarc3_TatsuoRecon_EventScript_Q4Ask_Text_1:
# 357 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "For his share of the estate$"

tarc3_TatsuoRecon_EventScript_Q4Ask_Text_2:
# 358 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He was mistaken for somebody else$"

tarc3_TatsuoRecon_EventScript_Q4Ask_Text_3:
# 359 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He was nearby$"

tarc3_TatsuoRecon_EventScript_Q4WrongEstate_Text_0:
# 374 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "His share. The murderer wanted a larger\n"
	.string "share for themselves.$"

tarc3_TatsuoRecon_EventScript_Q4WrongEstate_Text_1:
# 376 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Killing him does not alter any\n"
	.string "distribution by a single dollar.\p"
	.string "You should know that.$"

tarc3_TatsuoRecon_EventScript_Q4WrongMistake_Text_0:
# 384 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Mistaken identity.\p"
	.string "On a ship where every soul aboard knows\n"
	.string "every other by name.$"

tarc3_TatsuoRecon_EventScript_Q4WrongMistake_Text_1:
# 385 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Absurd.$"

tarc3_TatsuoRecon_EventScript_Q4Right_Text_0:
# 403 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Because he was watching.$"

tarc3_TatsuoRecon_EventScript_Q4Right_Text_1:
# 408 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He was at that rail when a man threw a\n"
	.string "bloody rag into the sea.\p"
	.string "They saw each other.$"

tarc3_TatsuoRecon_EventScript_Q4Right_Text_2:
# 409 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He was not a target.\p"
	.string "He was struck before he had finished\n"
	.string "turning round.$"

tarc3_TatsuoRecon_EventScript_Q4Right_Text_3:
# 411 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He did not turn, he did not get an arm\n"
	.string "up, and he did not run.\p"
	.string "He was not given the time to do any of\n"
	.string "it.$"

tarc3_TatsuoRecon_EventScript_Q4Give_Text_0:
# 421 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He saw it. That is the whole of it.$"

tarc3_TatsuoRecon_EventScript_Closing_Text_0:
# 432 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "So. A man came out onto this deck\n"
	.string "tonight with the knife that killed Gozo\l"
	.string "Hatamoto.\p"
	.string "Wrapped, and meant for the sea.$"

tarc3_TatsuoRecon_EventScript_Closing_Text_1:
# 433 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He did that first. The sea has it, and\n"
	.string "the wrapping tore off on the rail on the\l"
	.string "way down.$"

tarc3_TatsuoRecon_EventScript_Closing_Text_2:
# 434 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Tatsuo was already out here. He saw it\n"
	.string "happen.$"

tarc3_TatsuoRecon_EventScript_Closing_Text_3:
# 439 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Nobody planned this death.\p"
	.string "He died for standing in the wrong place\n"
	.string "at the wrong minute.\p"
	.string "The man who did it escaped afterwards.$"

tarc3_TatsuoRecon_EventScript_ClosingBest_Text_0:
# 463 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He was standing there minding his own\n"
	.string "business and somebody killed him for it.$"

tarc3_TatsuoRecon_EventScript_ClosingBest_Text_1:
# 464 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "For nothing. For being in the way.$"

tarc3_TatsuoRecon_EventScript_ClosingBest_Text_2:
# 466 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Adequate, {PLAYER} Edgeworth. Twice\n"
	.string "in one night.$"

tarc3_TatsuoRecon_EventScript_ClosingFair_Text_0:
# 476 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "...It holds together.$"

tarc3_TatsuoRecon_EventScript_ClosingFair_Text_1:
# 478 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "It holds together and it names nobody.\n"
	.string "You have described a rail to us.$"

tarc3_TatsuoRecon_EventScript_ClosingFair_Text_2:
# 480 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "He has described a man improvising.\p"
	.string "This family decided first, and went\n"
	.string "looking for reasons after.$"

tarc3_TatsuoRecon_EventScript_ClosingPoor_Text_0:
# 490 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "Most of that came out of her mouth\n"
	.string "again.$"

tarc3_TatsuoRecon_EventScript_ClosingPoor_Text_1:
# 492 "data/scripts/tarc3_tatsuo_reconstruction.pory"
	.string "The reconstruction is sound. How much\n"
	.string "of it I had to hand him is a matter\l"
	.string "between him and me.$"
