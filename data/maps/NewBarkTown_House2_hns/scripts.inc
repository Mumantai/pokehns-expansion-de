NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "Hi, {PLAYER}! Mein Mann ist immer so\n"
	.string "beschäftigt. Ich hoffe, es geht ihm gut.\p"
	.string "Wenn er sich in seine POKéMON-\n"
	.string "Forschungen vertieft, vergisst er\l"
	.string "sogar zu essen.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "Wenn ich groß bin, helfe\n"
	.string "ich meinem Papa!!\p"
	.string "Ich werde ein großartiger\n"
	.string "POKéMON-Professor!$"
