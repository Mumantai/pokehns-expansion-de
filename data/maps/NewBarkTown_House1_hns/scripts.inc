NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU ist ein entwickeltes POKéMON.\p"
	.string "PROF. LINDs Entdeckungen sind\n"
	.string "wirklich erstaunlich.\p"
	.string "Er ist berühmt für seine Forschungen\n"
	.string "auf dem Gebiet der POKéMON-Evolution.\p"
	.string "…Seufz…\p"
	.string "Ich wünschte, ich wäre auch ein Forscher\n"
	.string "wie er…$"


NewBarkTown_House1_Text_Neighbor:
	.string "Meine Tochter will unbedingt\n"
	.string "PROF. LINDs Assistentin werden.\p"
	.string "Sie liebt POKéMON! von ganzem Herzen!\p"
	.string "Aber das tue ich auch!$"

