tarc3_Recon_EventScript_Begin::
# 5 "data/scripts/tarc3_gozo_reconstruction.pory"
	setvar VAR_TEMP_8, 0
# 6 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 7 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Begin_Text_1
# 8 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Begin_Text_2
# 9 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 10 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 11 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 12 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1
	return


tarc3_Recon_EventScript_Q1::
# 18 "data/scripts/tarc3_gozo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 19 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 20 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1_Text_0
# 21 "data/scripts/tarc3_gozo_reconstruction.pory"
	applymovement OBJ_EVENT_ID_PLAYER, tarc3_Recon_EventScript_Q1_Movement_0
# 22 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1_Text_1
# 23 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1_Text_2
# 24 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 25 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 26 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 27 "data/scripts/tarc3_gozo_reconstruction.pory"
	applymovement OBJ_EVENT_ID_PLAYER, tarc3_Recon_EventScript_Q1_Movement_1
# 28 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmovement 0
# 29 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1Ask
	return


tarc3_Recon_EventScript_Q1Ask::
# 33 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 34 "data/scripts/tarc3_gozo_reconstruction.pory"
	message tarc3_Recon_EventScript_Q1Ask_Text_0
# 35 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmessage
# 36 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q1Ask_Text_1, 1
# 37 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q1Ask_Text_2, 2
# 38 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q1Ask_Text_3, 3
# 39 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 40 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 41 "data/scripts/tarc3_gozo_reconstruction.pory"
	switch VAR_RESULT
# 42 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 1, tarc3_Recon_EventScript_Q1Ask_2
# 44 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 2, tarc3_Recon_EventScript_Q1Ask_3
# 47 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1Right
	return

tarc3_Recon_EventScript_Q1Ask_2:
# 43 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1WrongWindow
	return

tarc3_Recon_EventScript_Q1Ask_3:
# 45 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1WrongKey
	return


tarc3_Recon_EventScript_Q1WrongWindow::
# 52 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 53 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1WrongWindow_Text_1
# 54 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 55 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 56 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1Miss
	return


tarc3_Recon_EventScript_Q1WrongKey::
# 60 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 61 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1WrongKey_Text_0
# 62 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1WrongKey_Text_1
# 63 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 64 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 65 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1Miss
	return


tarc3_Recon_EventScript_Q1Miss::
# 69 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 70 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_Recon_EventScript_Q1Give
# 71 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 72 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q1Ask
	return


tarc3_Recon_EventScript_Q1Right::
# 76 "data/scripts/tarc3_gozo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_Recon_EventScript_Q1Right_2
tarc3_Recon_EventScript_Q1Right_1:
# 79 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 80 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1Right_Text_0
# 81 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1Right_Text_1
# 82 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 83 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 84 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 85 "data/scripts/tarc3_gozo_reconstruction.pory"
	playse SE_PIN
# 86 "data/scripts/tarc3_gozo_reconstruction.pory"
	applymovement LOCALID_GOZOROOM_AKIE, tarc3_Recon_EventScript_Q1Right_Movement_0
# 87 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmovement 0
# 88 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1Right_Text_2
# 89 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1Right_Text_3
# 90 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 91 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 92 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 93 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2
	return

tarc3_Recon_EventScript_Q1Right_2:
# 77 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_Recon_EventScript_Q1Right_1


tarc3_Recon_EventScript_Q1Give::
# 97 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 98 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1Give_Text_0
# 99 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q1Give_Text_1
# 100 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 101 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 102 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 103 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2
	return


tarc3_Recon_EventScript_Q2::
# 109 "data/scripts/tarc3_gozo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 110 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1Right_Text_2
# 111 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2_Text_0
# 112 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 113 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2_Text_1
# 114 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 115 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 116 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 117 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2Ask
	return


tarc3_Recon_EventScript_Q2Ask::
# 121 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 122 "data/scripts/tarc3_gozo_reconstruction.pory"
	message tarc3_Recon_EventScript_Q2Ask_Text_0
# 123 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmessage
# 124 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q2Ask_Text_1, 1
# 125 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q2Ask_Text_2, 2
# 126 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q2Ask_Text_3, 3
# 127 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 128 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 129 "data/scripts/tarc3_gozo_reconstruction.pory"
	switch VAR_RESULT
# 130 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 1, tarc3_Recon_EventScript_Q2Ask_2
# 132 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 3, tarc3_Recon_EventScript_Q2Ask_3
# 135 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2Right
	return

tarc3_Recon_EventScript_Q2Ask_2:
# 131 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2WrongMotive
	return

tarc3_Recon_EventScript_Q2Ask_3:
# 133 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2WrongFrail
	return


tarc3_Recon_EventScript_Q2WrongMotive::
# 140 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1_Text_1
# 141 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2WrongMotive_Text_0
# 142 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 143 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2WrongMotive_Text_1
# 144 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 145 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 146 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2Miss
	return


tarc3_Recon_EventScript_Q2WrongFrail::
# 150 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 151 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2WrongFrail_Text_0
# 152 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2WrongFrail_Text_1
# 153 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 154 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 155 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2Miss
	return


tarc3_Recon_EventScript_Q2Miss::
# 159 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 160 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_Recon_EventScript_Q2Give
# 161 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 162 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q2Ask
	return


tarc3_Recon_EventScript_Q2Right::
# 166 "data/scripts/tarc3_gozo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_Recon_EventScript_Q2Right_2
tarc3_Recon_EventScript_Q2Right_1:
# 169 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 170 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Right_Text_0
# 171 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Right_Text_1
# 172 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Right_Text_2
# 173 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 174 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 175 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 176 "data/scripts/tarc3_gozo_reconstruction.pory"
	playse SE_PIN
# 177 "data/scripts/tarc3_gozo_reconstruction.pory"
	applymovement LOCALID_GOZOROOM_JOJI, tarc3_Recon_EventScript_Q1Right_Movement_0
# 178 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmovement 0
# 179 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q2Right_Text_3
# 180 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Right_Text_4
# 181 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1Right_Text_2
# 182 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Right_Text_5
# 183 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 184 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 185 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 186 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3
	return

tarc3_Recon_EventScript_Q2Right_2:
# 167 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_Recon_EventScript_Q2Right_1


tarc3_Recon_EventScript_Q2Give::
# 190 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 191 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Give_Text_0
# 192 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Give_Text_1
# 193 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 194 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 195 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 196 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3
	return


tarc3_Recon_EventScript_Q3::
# 202 "data/scripts/tarc3_gozo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 203 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1_Text_1
# 204 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3_Text_0
# 205 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 206 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3_Text_1
# 207 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 208 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 209 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 210 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3Ask
	return


tarc3_Recon_EventScript_Q3Ask::
# 214 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 215 "data/scripts/tarc3_gozo_reconstruction.pory"
	message tarc3_Recon_EventScript_Q3Ask_Text_0
# 216 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmessage
# 217 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q3Ask_Text_1, 1
# 218 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q3Ask_Text_2, 2
# 219 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q3Ask_Text_3, 3
# 220 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 221 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 222 "data/scripts/tarc3_gozo_reconstruction.pory"
	switch VAR_RESULT
# 223 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 1, tarc3_Recon_EventScript_Q3Ask_2
# 225 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 2, tarc3_Recon_EventScript_Q3Ask_3
# 228 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3Right
	return

tarc3_Recon_EventScript_Q3Ask_2:
# 224 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3WrongWall
	return

tarc3_Recon_EventScript_Q3Ask_3:
# 226 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3WrongCorridor
	return


tarc3_Recon_EventScript_Q3WrongWall::
# 233 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 234 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3WrongWall_Text_0
# 235 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3WrongWall_Text_1
# 236 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 237 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 238 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3Miss
	return


tarc3_Recon_EventScript_Q3WrongCorridor::
# 242 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 243 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3WrongCorridor_Text_0
# 244 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3WrongCorridor_Text_1
# 245 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 246 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 247 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3Miss
	return


tarc3_Recon_EventScript_Q3Miss::
# 251 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 252 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_Recon_EventScript_Q3Give
# 253 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 254 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q3Ask
	return


tarc3_Recon_EventScript_Q3Right::
# 258 "data/scripts/tarc3_gozo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_Recon_EventScript_Q3Right_2
tarc3_Recon_EventScript_Q3Right_1:
# 261 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 262 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3Right_Text_0
# 263 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3Right_Text_1
# 264 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3Right_Text_2
# 265 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 266 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 267 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 268 "data/scripts/tarc3_gozo_reconstruction.pory"
	playse SE_PIN
# 269 "data/scripts/tarc3_gozo_reconstruction.pory"
	applymovement LOCALID_GOZOROOM_SUZUKI, tarc3_Recon_EventScript_Q1Right_Movement_0
# 270 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmovement 0
# 271 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q3Right_Text_3
# 272 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3Right_Text_4
# 273 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 274 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 275 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 276 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4
	return

tarc3_Recon_EventScript_Q3Right_2:
# 259 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_Recon_EventScript_Q3Right_1


tarc3_Recon_EventScript_Q3Give::
# 280 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 281 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3Give_Text_0
# 282 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q3Give_Text_1
# 283 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 284 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 285 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 286 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4
	return


tarc3_Recon_EventScript_Q4::
# 292 "data/scripts/tarc3_gozo_reconstruction.pory"
	setvar VAR_TEMP_7, 0
# 293 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q4_Text_0
# 294 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4_Text_1
# 295 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 296 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 297 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 298 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4Ask
	return


tarc3_Recon_EventScript_Q4Ask::
# 302 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 303 "data/scripts/tarc3_gozo_reconstruction.pory"
	message tarc3_Recon_EventScript_Q4Ask_Text_0
# 304 "data/scripts/tarc3_gozo_reconstruction.pory"
	waitmessage
# 305 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q4Ask_Text_1, 1
# 306 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q4Ask_Text_2, 2
# 307 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultipush tarc3_Recon_EventScript_Q4Ask_Text_3, 3
# 308 "data/scripts/tarc3_gozo_reconstruction.pory"
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 309 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 310 "data/scripts/tarc3_gozo_reconstruction.pory"
	switch VAR_RESULT
# 311 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 1, tarc3_Recon_EventScript_Q4Ask_2
# 313 "data/scripts/tarc3_gozo_reconstruction.pory"
	case 3, tarc3_Recon_EventScript_Q4Ask_3
# 316 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4Right
	return

tarc3_Recon_EventScript_Q4Ask_2:
# 312 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4WrongKey
	return

tarc3_Recon_EventScript_Q4Ask_3:
# 314 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4WrongOpen
	return


tarc3_Recon_EventScript_Q4WrongKey::
# 321 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 322 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4WrongKey_Text_0
# 323 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4WrongKey_Text_1
# 324 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 325 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 326 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4Miss
	return


tarc3_Recon_EventScript_Q4WrongOpen::
# 330 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q3Right_Text_3
# 331 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4WrongOpen_Text_0
# 332 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q4WrongOpen_Text_1
# 333 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4WrongOpen_Text_2
# 334 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q2Right_Text_5
# 335 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 336 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4WrongOpen_Text_3
# 337 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 338 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 339 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4Miss
	return


tarc3_Recon_EventScript_Q4Miss::
# 343 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_7, 1
# 344 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto_if_ge VAR_TEMP_7, 2, tarc3_Recon_EventScript_Q4Give
# 345 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 346 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Q4Ask
	return


tarc3_Recon_EventScript_Q4Right::
# 350 "data/scripts/tarc3_gozo_reconstruction.pory"
	compare VAR_TEMP_7, 0
	goto_if_eq tarc3_Recon_EventScript_Q4Right_2
tarc3_Recon_EventScript_Q4Right_1:
# 353 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 354 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4Right_Text_0
# 355 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 356 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 357 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 30
# 358 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 359 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4Right_Text_1
# 360 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 361 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 362 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto_if_set FLAG_TARC3_GOZO_FOUND_TRAIL, tarc3_Recon_EventScript_Q4Trail
# 363 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Closing
	return

tarc3_Recon_EventScript_Q4Right_2:
# 351 "data/scripts/tarc3_gozo_reconstruction.pory"
	addvar VAR_TEMP_8, 1
	goto tarc3_Recon_EventScript_Q4Right_1


tarc3_Recon_EventScript_Q4Trail::
# 369 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 370 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4Trail_Text_0
# 371 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4Trail_Text_1
# 372 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 373 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 374 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 375 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Closing
	return


tarc3_Recon_EventScript_Q4Give::
# 379 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 380 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4Give_Text_0
# 381 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Q4Give_Text_1
# 382 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 383 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 384 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 385 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_Closing
	return


tarc3_Recon_EventScript_Closing::
# 391 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Begin_Text_0
# 392 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Closing_Text_0
# 393 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Closing_Text_1
# 394 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Closing_Text_2
# 395 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_Closing_Text_3
# 396 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 397 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 398 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 30
# 399 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto_if_ge VAR_TEMP_8, 4, tarc3_Recon_EventScript_ClosingBest
# 400 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto_if_ge VAR_TEMP_8, 2, tarc3_Recon_EventScript_ClosingFair
# 401 "data/scripts/tarc3_gozo_reconstruction.pory"
	goto tarc3_Recon_EventScript_ClosingPoor
	return


tarc3_Recon_EventScript_ClosingBest::
# 405 "data/scripts/tarc3_gozo_reconstruction.pory"
	fadeoutbgm 4
# 406 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 60
# 407 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 408 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingBest_Text_0
# 409 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 410 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 40
# 411 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q3Right_Text_3
# 412 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingBest_Text_1
# 413 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingBest_Text_2
# 414 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 415 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingBest_Text_3
# 416 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 417 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 418 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 419 "data/scripts/tarc3_gozo_reconstruction.pory"
	setflag FLAG_TARC3_GOZO_RECONSTRUCTED
	return


tarc3_Recon_EventScript_ClosingFair::
# 424 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q2Right_Text_3
# 425 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingFair_Text_0
# 426 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1_Text_1
# 427 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingFair_Text_1
# 428 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 429 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingFair_Text_2
# 430 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 431 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 432 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 433 "data/scripts/tarc3_gozo_reconstruction.pory"
	setflag FLAG_TARC3_GOZO_RECONSTRUCTED
	return


tarc3_Recon_EventScript_ClosingPoor::
# 438 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1_Text_1
# 439 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingPoor_Text_0
# 440 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_ClosingPoor_Text_1
# 441 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingPoor_Text_2
# 442 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker tarc3_Recon_EventScript_Q1WrongWindow_Text_0
# 443 "data/scripts/tarc3_gozo_reconstruction.pory"
	msgbox tarc3_Recon_EventScript_ClosingPoor_Text_3
# 444 "data/scripts/tarc3_gozo_reconstruction.pory"
	setspeaker NULL
# 445 "data/scripts/tarc3_gozo_reconstruction.pory"
	closemessage
# 446 "data/scripts/tarc3_gozo_reconstruction.pory"
	delay 20
# 447 "data/scripts/tarc3_gozo_reconstruction.pory"
	setflag FLAG_TARC3_GOZO_RECONSTRUCTED
	return


# 21 "data/scripts/tarc3_gozo_reconstruction.pory"
tarc3_Recon_EventScript_Q1_Movement_0:
# 21 "data/scripts/tarc3_gozo_reconstruction.pory"
	face_up
	step_end

# 27 "data/scripts/tarc3_gozo_reconstruction.pory"
tarc3_Recon_EventScript_Q1_Movement_1:
# 27 "data/scripts/tarc3_gozo_reconstruction.pory"
	face_down
	step_end

# 86 "data/scripts/tarc3_gozo_reconstruction.pory"
tarc3_Recon_EventScript_Q1Right_Movement_0:
# 86 "data/scripts/tarc3_gozo_reconstruction.pory"
	emote_exclamation_mark
	step_end

tarc3_Recon_EventScript_Begin_Text_0:
# 6 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "{PLAYER}$"

tarc3_Recon_EventScript_Begin_Text_1:
# 7 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "I will not tell you who did this. I\n"
	.string "cannot yet, and I will not guess in\l"
	.string "front of a family.$"

tarc3_Recon_EventScript_Begin_Text_2:
# 8 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "I will tell you what happened in that\n"
	.string "doorway. That much the room has\l"
	.string "already said.$"

tarc3_Recon_EventScript_Q1_Text_0:
# 20 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "First. This cabin.$"

tarc3_Recon_EventScript_Q1_Text_1:
# 22 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Mariko$"

tarc3_Recon_EventScript_Q1_Text_2:
# 23 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "The cabin was locked. Suzuki opened it\n"
	.string "in front of all of us.$"

tarc3_Recon_EventScript_Q1Ask_Text_0:
# 34 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "{FONT_NARROW}How did anybody get into that room, or out\n"
	.string "of it?$"

tarc3_Recon_EventScript_Q1Ask_Text_1:
# 36 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Through the window$"

tarc3_Recon_EventScript_Q1Ask_Text_2:
# 37 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Using the spare key$"

tarc3_Recon_EventScript_Q1Ask_Text_3:
# 38 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Nobody did, either way$"

tarc3_Recon_EventScript_Q1WrongWindow_Text_0:
# 52 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "{RIVAL}$"

tarc3_Recon_EventScript_Q1WrongWindow_Text_1:
# 53 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "You put your hands on that window\n"
	.string "yourself. It has not opened in years.$"

tarc3_Recon_EventScript_Q1WrongKey_Text_0:
# 61 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "There is one spare, it is in Suzuki's\n"
	.string "pocket, and nine of you watched him\l"
	.string "take it out of there.$"

tarc3_Recon_EventScript_Q1WrongKey_Text_1:
# 62 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "If you intend to accuse the butler, do\n"
	.string "it in a sentence and not in a shrug.$"

tarc3_Recon_EventScript_Q1Right_Text_0:
# 80 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Nobody. One door, and one window that\n"
	.string "has not opened in years.$"

tarc3_Recon_EventScript_Q1Right_Text_1:
# 81 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "The door takes a key from the corridor\n"
	.string "and a latch from the inside. When\l"
	.string "Suzuki reached it, it was shut.$"

tarc3_Recon_EventScript_Q1Right_Text_2:
# 88 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Akie$"

tarc3_Recon_EventScript_Q1Right_Text_3:
# 89 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Thank you. That is precisely what I\n"
	.string "have been saying.$"

tarc3_Recon_EventScript_Q1Give_Text_0:
# 98 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Nobody came through that window and\n"
	.string "nobody borrowed that key. The room\l"
	.string "was shut.$"

tarc3_Recon_EventScript_Q1Give_Text_1:
# 99 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "You walked past both of those facts\n"
	.string "to arrive at neither of them.$"

tarc3_Recon_EventScript_Q2_Text_0:
# 111 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Then he shut himself in and did it to\n"
	.string "himself. As I have said from the\l"
	.string "beginning.$"

tarc3_Recon_EventScript_Q2_Text_1:
# 113 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "No. And this room can prove it cannot\n"
	.string "have been that.$"

tarc3_Recon_EventScript_Q2Ask_Text_0:
# 122 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "{FONT_NARROW}What is wrong with a man doing this to\n"
	.string "himself in a sealed room?$"

tarc3_Recon_EventScript_Q2Ask_Text_1:
# 124 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He had no reason to$"

tarc3_Recon_EventScript_Q2Ask_Text_2:
# 125 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "There is no blade in here$"

tarc3_Recon_EventScript_Q2Ask_Text_3:
# 126 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He was too frail to manage it$"

tarc3_Recon_EventScript_Q2WrongMotive_Text_0:
# 141 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "You met my father this afternoon. Do\n"
	.string "not tell this family what he did and\l"
	.string "did not have reason to do.$"

tarc3_Recon_EventScript_Q2WrongMotive_Text_1:
# 143 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "She is correct, and I did not ask you\n"
	.string "for speculation. Show this room\l"
	.string "evidence.$"

tarc3_Recon_EventScript_Q2WrongFrail_Text_0:
# 151 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "A cabinet of medicine bottles tells\n"
	.string "you he was ill. It does not tell you\l"
	.string "what his arms could do.$"

tarc3_Recon_EventScript_Q2WrongFrail_Text_1:
# 152 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "You are guessing at what he could not\n"
	.string "do. Argue from what is in this room.$"

tarc3_Recon_EventScript_Q2Right_Text_0:
# 170 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "There is no knife in this cabin. Not\n"
	.string "under the bed, not behind the couch,\l"
	.string "not in the bin.$"

tarc3_Recon_EventScript_Q2Right_Text_1:
# 171 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He was struck again and again.\n"
	.string "Whoever did it was not being\l"
	.string "efficient, they were being furious.$"

tarc3_Recon_EventScript_Q2Right_Text_2:
# 172 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "And a dead man does not put the blade\n"
	.string "somewhere else and then lock the door\l"
	.string "on himself.$"

tarc3_Recon_EventScript_Q2Right_Text_3:
# 179 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Joji$"

tarc3_Recon_EventScript_Q2Right_Text_4:
# 180 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "That is the question I asked earlier,\n"
	.string "and not one of you would look at me.$"

tarc3_Recon_EventScript_Q2Right_Text_5:
# 182 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "...$"

tarc3_Recon_EventScript_Q2Give_Text_0:
# 191 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "The knife, {PLAYER} Edgeworth.\n"
	.string "There is no knife.$"

tarc3_Recon_EventScript_Q2Give_Text_1:
# 192 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "A man may do that to himself. Not one\n"
	.string "of them has ever tidied the blade away\l"
	.string "afterwards.$"

tarc3_Recon_EventScript_Q3_Text_0:
# 204 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Then somebody was in that room with\n"
	.string "him, and the room was locked. You are\l"
	.string "talking in circles.$"

tarc3_Recon_EventScript_Q3_Text_1:
# 206 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Only because you are all looking at\n"
	.string "the wrong side of that door.$"

tarc3_Recon_EventScript_Q3Ask_Text_0:
# 215 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "{FONT_NARROW}Where was Gozo standing when the first blow\n"
	.string "landed?$"

tarc3_Recon_EventScript_Q3Ask_Text_1:
# 217 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Where he fell$"

tarc3_Recon_EventScript_Q3Ask_Text_2:
# 218 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Out in the corridor$"

tarc3_Recon_EventScript_Q3Ask_Text_3:
# 219 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "In the open doorway$"

tarc3_Recon_EventScript_Q3WrongWall_Text_0:
# 234 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Then his attacker was inside a room\n"
	.string "that was locked from within, and left\l"
	.string "it without unlocking anything.$"

tarc3_Recon_EventScript_Q3WrongWall_Text_1:
# 235 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "You have just made this worse. Look at\n"
	.string "the frame of the door.$"

tarc3_Recon_EventScript_Q3WrongCorridor_Text_0:
# 243 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Close is not correct. In the corridor\n"
	.string "he is nowhere near that frame.$"

tarc3_Recon_EventScript_Q3WrongCorridor_Text_1:
# 244 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "The blood is on the frame itself,\n"
	.string "{PLAYER} Edgeworth. Be exact.$"

tarc3_Recon_EventScript_Q3Right_Text_0:
# 262 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "In the doorway. Look at the frame.$"

tarc3_Recon_EventScript_Q3Right_Text_1:
# 263 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Blood is thrown across the jamb at\n"
	.string "chest height. That can only happen\l"
	.string "while the door stands open.$"

tarc3_Recon_EventScript_Q3Right_Text_2:
# 264 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "It was shut and locked when Suzuki\n"
	.string "reached it. So the wound came first.\l"
	.string "The door came after.$"

tarc3_Recon_EventScript_Q3Right_Text_3:
# 271 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Suzuki$"

tarc3_Recon_EventScript_Q3Right_Text_4:
# 272 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "...I walked past that frame. I looked\n"
	.string "straight at it, and all I saw was a\l"
	.string "flower.$"

tarc3_Recon_EventScript_Q3Give_Text_0:
# 281 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "In the doorway, you fool. Look at the\n"
	.string "frame.$"

tarc3_Recon_EventScript_Q3Give_Text_1:
# 282 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Blood at chest height, and the door\n"
	.string "found shut. The wound came before the\l"
	.string "lock.$"

tarc3_Recon_EventScript_Q4_Text_0:
# 293 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Kitaro$"

tarc3_Recon_EventScript_Q4_Text_1:
# 294 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Cut in the doorway. Found behind a\n"
	.string "locked door. But who locked the door?$"

tarc3_Recon_EventScript_Q4Ask_Text_0:
# 303 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "{FONT_NARROW}Who locked the door?$"

tarc3_Recon_EventScript_Q4Ask_Text_1:
# 305 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "The killer, with a key$"

tarc3_Recon_EventScript_Q4Ask_Text_2:
# 306 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Gozo turned it himself$"

tarc3_Recon_EventScript_Q4Ask_Text_3:
# 307 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "It was never locked$"

tarc3_Recon_EventScript_Q4WrongKey_Text_0:
# 322 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "We have been over the key. It did not\n"
	.string "leave Suzuki's pocket, and you have\l"
	.string "offered this room no reason to think\l"
	.string "it did.$"

tarc3_Recon_EventScript_Q4WrongKey_Text_1:
# 323 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Stop reaching outside that doorway.\n"
	.string "There is somebody standing in it.$"

tarc3_Recon_EventScript_Q4WrongOpen_Text_0:
# 331 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Forgive me, but it was locked. Gozo\n"
	.string "conducts all of his affairs in privacy.$"

tarc3_Recon_EventScript_Q4WrongOpen_Text_1:
# 332 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Takeshi$"

tarc3_Recon_EventScript_Q4WrongOpen_Text_2:
# 333 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "When I spoke with him, he was sure to\n"
	.string "lock the door behind him.$"

tarc3_Recon_EventScript_Q4WrongOpen_Text_3:
# 336 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "I expect better, {PLAYER}\n"
	.string "Edgeworth.$"

tarc3_Recon_EventScript_Q4Right_Text_0:
# 354 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Gozo did.$"

tarc3_Recon_EventScript_Q4Right_Text_1:
# 359 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He was cut in his own doorway by\n"
	.string "someone he had opened the door to. He\l"
	.string "got that door shut, and he turned the\l"
	.string "latch against him.$"

tarc3_Recon_EventScript_Q4Trail_Text_0:
# 370 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "And the floor of that cabin says so.\n"
	.string "The smear runs inward from the\l"
	.string "threshold, even the whole way, with\l"
	.string "nothing pooled at the door.$"

tarc3_Recon_EventScript_Q4Trail_Text_1:
# 371 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He did not fall there and he was not\n"
	.string "dragged. He walked, bleeding, and he\l"
	.string "did not reach the far wall.$"

tarc3_Recon_EventScript_Q4Give_Text_0:
# 380 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Gozo turned it. Obviously Gozo turned\n"
	.string "it.$"

tarc3_Recon_EventScript_Q4Give_Text_1:
# 381 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He was cut in the doorway, he shut the\n"
	.string "door on the man who cut him, and he\l"
	.string "locked it. The sealed room is the\l"
	.string "victim's own work.$"

tarc3_Recon_EventScript_Closing_Text_0:
# 392 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "So. Gozo Hatamoto opened that door to\n"
	.string "somebody he was willing to open it to.$"

tarc3_Recon_EventScript_Closing_Text_1:
# 393 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He was struck in the doorway, more\n"
	.string "than once, and left standing. His\l"
	.string "attacker walked away with the blade.$"

tarc3_Recon_EventScript_Closing_Text_2:
# 394 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Gozo shut the door and locked it. Not\n"
	.string "to keep us out. To keep that man out.$"

tarc3_Recon_EventScript_Closing_Text_3:
# 395 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Nobody sealed this room in order to\n"
	.string "kill him. He sealed it trying to live.$"

tarc3_Recon_EventScript_ClosingBest_Text_0:
# 408 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Nobody in the corridor says anything\n"
	.string "at all.$"

tarc3_Recon_EventScript_ClosingBest_Text_1:
# 412 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "...He was thirty-one years my employer,\n"
	.string "and I never once heard that man ask\l"
	.string "anybody for help.$"

tarc3_Recon_EventScript_ClosingBest_Text_2:
# 413 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He would have shut that door. He would\n"
	.string "have shut it exactly like that.$"

tarc3_Recon_EventScript_ClosingBest_Text_3:
# 415 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Adequate, {PLAYER} Edgeworth.$"

tarc3_Recon_EventScript_ClosingFair_Text_0:
# 425 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "...It holds. I do not enjoy it, but it\n"
	.string "holds.$"

tarc3_Recon_EventScript_ClosingFair_Text_1:
# 427 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "It holds and it tells us nothing. You\n"
	.string "have described a door to us.$"

tarc3_Recon_EventScript_ClosingFair_Text_2:
# 429 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "He has described a murder to you,\n"
	.string "while some of you had characterised it\l"
	.string "as suicide moments earlier.$"

tarc3_Recon_EventScript_ClosingPoor_Text_0:
# 439 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Most of that came out of her mouth\n"
	.string "and not yours.$"

tarc3_Recon_EventScript_ClosingPoor_Text_1:
# 440 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "Tatsuo$"

tarc3_Recon_EventScript_ClosingPoor_Text_2:
# 441 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "It rather did, didn't it.$"

tarc3_Recon_EventScript_ClosingPoor_Text_3:
# 443 "data/scripts/tarc3_gozo_reconstruction.pory"
	.string "The conclusion is sound and it is his.\n"
	.string "Whether he arrived at it with any\l"
	.string "grace is a matter between him and me.$"
