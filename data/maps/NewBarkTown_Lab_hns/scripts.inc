.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}!\p"
	.string "Was machst du noch hier?\p"
	.string "Mein Assistent wartet auf dich\n"
	.string "in VIOLA CITY!$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "Besser nicht anfassen!$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "LIND: Ah, da bist du ja, {PLAYER}!\p"
	.string "Ich muss dich um etwas bitten.\p"
	.string "Ich führe gerade neue Forschungen\n"
	.string "durch und habe mich gefragt, ob du mir\l"
	.string "dabei helfen möchtest, {PLAYER}.\p"
	.string "Verstehst du…\p"
	.string "Ich schreibe an etwas, das ich bei\n"
	.string "einer Konferenz vorlegen möchte.\p"
	.string "Es gibt da aber noch einige Dinge,\n"
	.string "die ich nicht ganz verstehe.\p"
	.string "Deshalb…\p"
	.string "Möchte ich, dass du eines der POKéMON\n"
	.string "trainierst, die ich vor kurzem\l"
	.string "gefangen habe.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "Danke, {PLAYER}!\n"
	.string "Du bist mir eine große Hilfe!$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Aber… Bitte, ich brauche\n"
	.string "deine Hilfe!$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Wenn ich meine Ergebnisse vorlege,\n"
	.string "werden wir sicher noch weiter in\l"
	.string "die Geheimnisse der POKéMON vorstoßen.\p"
	.string "Darauf kannst du dich verlassen!$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "Oh, hey! Ich habe eine E-mail!\p"
	.string "… … … … … … … …\n"
	.string "Aha… hm…\p"
	.string "Na sieh mal einer an…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Hör gut zu!\p"
	.string "Ich habe einen Bekannten, den alle nur\n"
	.string "MR. POKéMON nennen.\p"
	.string "Ständig findet er eigenartiges Zeugs\n"
	.string "und fängt an darüber zu fantasieren.\p"
	.string "Gerade eben hat er mir eine E-Mail\n"
	.string "geschickt, in der er mir versichert,\l"
	.string "diesmal wirklich etwas Besonderes\l"
	.string "gefunden zu haben.\p"
	.string "Das klingt zwar faszinierend, aber\n"
	.string "wir sind derzeit mitten in unseren\l"
	.string "eigenen POKéMON-Forschungen.\p"
	.string "Hm, was mach ich jetzt nur…\n"
	.string "Ich hab's!\p"
	.string "{PLAYER}, du könntest der Sache\n"
	.string "doch für mich nachgehen, oder?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Ich möchte, dass du eines der\n"
	.string "POKéMON aus einem dieser BÄLLE\l"
	.string "trainierst.\p"
	.string "Du wirst der erste Kamerad\n"
	.string "dieses POKéMON sein, {PLAYER}!\p"
	.string "Los. Such dir eins aus!$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "LIND: Warte! Wo willst du denn hin?\n"
	.string "Die POKéBÄLLE befinden sich\l"
	.string "doch gleich hier.$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "LIND: Willst du {COLOR RED}{STR_VAR_1}{COLOR DARK_GRAY}, das\n"
	.string "{STR_VAR_2} POKéMON?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "LIND: Wählst du {COLOR BLUE}{STR_VAR_1}{COLOR DARK_GRAY}, das\n"
	.string "{STR_VAR_2} POKéMON?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "LIND: Entscheidest du dich für\n"
	.string "{COLOR GREEN}{STR_VAR_1}{COLOR DARK_GRAY}, das {STR_VAR_2} POKéMON?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "LIND: Überlege es dir gut!\p"
	.string "Die Wahl deines Partners\n"
	.string "ist sehr wichtig.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "LIND: Ich bin auch der Meinung,\n"
	.string "dass dieses POKéMON seht gut ist!$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER} erhält {STR_VAR_1}!$"

NewBarkTown_Lab_Text_Nickname:
	.string "Möchtest du {STR_VAR_1}\n"
	.string "einen Spitznamen geben?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "MR. POKéMON wohnt ein kleines\n"
	.string "Stück nördlich von ROSALIA CITY,\l"
	.string "dem nächsten Ort.\p"
	.string "Der Weg führt dich fast direkt\n"
	.string "dorthin, du kannst es nicht verfehlen.\p"
	.string "Aber nur für den Fall, gebe ich dir\n"
	.string "noch meine Nummer.\p"
	.string "Ruf mich an, wenn es etwas gibt!$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Wenn du einem wilden POKéMON, begegnest,\n"
	.string "lass deine POKéMON für dich kämpfen!$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "Erscheint ein wildes POKéMON,\n"
	.string "lass deine POKéMON dagegen kämpfen!\p"
	.string "Ist dein POKéMON verletzt, solltest\n"
	.string "du es mit Hilfe dieser Maschine oder\l"
	.string "in einem POKéMON-CENTER heilen.\p"
	.string "Ich zähle auf dich!$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} erhält LINDs Nummer.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "Jedes Mal, wenn MR. POKéMON auf Reisen geht,\n"
	.string "kommt er mit irgeneinem seltenen\l"
	.string "Fund im Gepäck zurück.\p"
	.string "Es ist nur dumm, dass sie nur\n"
	.string "selten, aber nicht brauchbar sind…$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Er beinhaltet ein von PROF. LIND\n"
	.string "gefangenes POKéMON.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "LIND: Oh, {PLAYER}, es ist schrecklich…\p"
	.string "Aber erzähl mir doch, was es mit MR. POKéMONs\n"
	.string "großem Fund auf sich hatte.$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} übergibt PROF. LIND\n"
	.string "das RÄTSEL-EI.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "LIND: Das sieht mir ganz… nach einem EI aus!$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Aber… ist das auch ein POKéMON-EI?\p"
	.string "Falls ja, dann ist es in der Tat\n"
	.string "eine große Entdeckung!\p"
	.string "LIND: Was?\p"
	.string "PROF. EICH hat dir einen POKéDEX gegeben?!\p"
	.string "Ist das wahr, {PLAYER}?\n"
	.string "D-das ist ja unglaublich!\p"
	.string "Er besitzt das einzigartige Talent, das wahre\n"
	.string "Potenzial eines Trainers erkennen zu können.\p"
	.string "Wow, {PLAYER}. Vielleicht ist es ja deine\n"
	.string "Bestimmung, der CHAMP zu werden?\p"
	.string "Es sieht jedenfalls so aus, als könntest du\n"
	.string "hervorragend mit POKéMON umgehen.\p"
	.string "Du solltest dich an den verschiedenen\n"
	.string "POKéMON-ARENEN dieser Region versuchen.\p"
	.string "Die nächste POKéMON-ARENA\n"
	.string "befindet sich in VIOLA CITY.\p"
	.string "… In Ordnung, {PLAYER}. Dann mach dich auf\n"
	.string "eine lange und beschwerliche Reise gefasst.\p"
	.string "Bevor du aufbrichst, solltest du aber\n"
	.string "noch mit deiner Mutter sprechen.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "LIND: Gib nicht auf!\n"
	.string "Ich rufe dich an, sobald ich etwas\l"
	.string "über dieses EI herausgefunden habe!$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "LIND: {PLAYER}? Hast du zufällig\n"
	.string "meinen Assistenten getroffen?\p"
	.string "Er sollte mit dem EI im POKéMON-CENTER\n"
	.string "von VIOLA CITY auf dich warten…\p"
	.string "Du musst ihn wohl verpasst haben.\n"
	.string "Guck doch mal, ob er noch dort ist.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "LIND: Hey, hat sich das EI\n"
	.string "irgendwie verändert?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "Nanu? Ich dachte, etwas wäre\n"
	.string "aus dem EI geschlüft, {PLAYER}.\p"
	.string "Wo ist das POKéMON denn?\n"
	.string "Zeig es mir doch bitte, {PLAYER}!$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "LIND: {PLAYER}, du siehst großartig aus!$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "Was? Dieses POKéMON!?!$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "Es ist aus dem EI geschlüpft?!\n"
	.string "Also schlüpfen alle POKéMON aus EIERN…\p"
	.string "Nein, vermutlich trifft das nicht\n"
	.string "auf alle POKéMON zu.\p"
	.string "Es wartet wohl noch jede Menge\n"
	.string "Forschungsarbeit auf uns!$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Danke, {PLAYER}! Du hilfst uns beim\n"
	.string "Aufklären vieler POKéMON-Mysterien!\p"
	.string "Hier, nimm das als Zeichen\n"
	.string "unserer Wertschätzung.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "Das ist ein EWIGSTEIN!\p"
	.string "Einige POKéMON entwickeln sich weiter,\n"
	.string "wenn sie einen bestimmten Level erreichen.\p"
	.string "Ein POKéMON, das einen EWIGSTEIN trägt,\n"
	.string "wird sich aber nicht entwickeln.\p"
	.string "Gib ihn einem POKéMON, das sich noch\n"
	.string "nicht weiterentwickeln soll!$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "LIND: Ich rufe dich an, wenn sich\n"
	.string "etwas tut, {PLAYER}.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "…Seufz… Das gestohlene POKéMON.\p"
	.string "Ich frage mich, wie es ihm geht.\p"
	.string "Man sagt, dass ein POKéMON, das von\n"
	.string "einem bösen Menschen aufgezogen wird,\l"
	.string "selber böse wird.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "LIND: Oh, hallo {PLAYER}!\p"
	.string "Dank dir macht meine Forschung\n"
	.string "ganz ausgezeichnete Fortschritte!\p"
	.string "Hier, bitte nimm dies als Zeichen\n"
	.string "meiner Dankbarkeit!$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "Das ist ein MEISTERBALL!\p"
	.string "Egal mit welchem POKéMON du es auch\n"
	.string "zu tun hast, einem MEISTERBALL\l"
	.string "wird es nicht entwischen!\p"
	.string "Er wird angeblich nur anerkannten\n"
	.string "POKéMON-Forschern überreicht…\p"
	.string "Aber ich glaube, du kannst damit\n"
	.string "mehr anfangen als ich, {PLAYER}!$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "Übrigens…\n"
	.string "Ein paar wirklich hübsche KIMONO-\l"
	.string "GIRLS haben nach dir gesucht.\p"
	.string "Sie sagten, sie würden im\n"
	.string "TANZTHEATER von TEAK CITY\l"
	.string "auf dich warten!\p"
	.string "Ich weiß, du hast viel durchgemacht,\n"
	.string "seit dieses EI dich in all diese\l"
	.string "Angelegenheiten gezogen hat…\p"
	.string "Ich hoffe, du schaffst das alles.$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "LIND: Die KIMONO-GIRLS warten auf\n"
	.string "dich im TANZTHEATER von TEAK CITY.$"

NewBarkTown_Lab_Text_League:
	.string "LIND: Haha, gute Arbeit!\p"
	.string "Zuerst dachte ich, dieses EI sei\n"
	.string "einfach nur selten und nicht weiter,\p"
	.string "aber die Sache hat inzwischen vollig andere\n"
	.string "Dimensionen angenommen, was?\p"
	.string "Was haben die KIMONO-GIRLS erzählt?\n"
	.string "Ach, aber das geht mich nichts an.\p"
	.string "Das war ganz allein dein Verdienst.\p"
	.string "Du hast dich mit Herz und Seele\n"
	.string "durch alles durchgekämpft.\p"
	.string "Jemand der aus eigener Kraft so viel\n"
	.string "erreicht hat, schafft es sicher auch\l"
	.string "an die Spitze der POKéMON LIGA!\p"
	.string "Mach dich nun also auf den Weg\n"
	.string "zum INDIGO-PLATEAU!\p"
	.string "Weißt du wo das ist? Nimm von hier aus\n"
	.string "Route 27, bis du auf Route 26 gelangst.\p"
	.string "Du musst immer geradeaus Richtung Norden!$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "LIND: {PLAYER}! Da bist du ja!\p"
	.string "Ich habe dich angerufen, weil ich\n"
	.string "dir etwas geben möchte.\p"
	.string "Hier! Das ist ein BOOTSTICKET.\p"
	.string "Damit kannst du auch in KANTO\n"
	.string "auf POKéMON-Jagd gehen!$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "Das Schnellboot, für das dieses Ticket\n"
	.string "gilt, legt in OLIVIANA CITY ab.\p"
	.string "Aber das weißt du bestimmt schon,\n"
	.string "{PLAYER}.\p"
	.string "Schileßlich bist du mit deinen\n"
	.string "POKéMON schon viel herumgekommen.\p"
	.string "Wenn du nach KANTO gehst, grüße\n"
	.string "bitte PROF. EICH von mir!$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "Dies ist das POKéMON-EI, das\n"
	.string "von PROF. LIND untersucht wird.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "Nimm das hier doch bitte mit\n"
	.string "auf deine Reise, {PLAYER}.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "Wir sind nur zu dritt und\n"
	.string "sind stets beschäftigt.$"

NewBarkTown_Lab_Text_AideSave:
	.string "Vergiss nicht regelmäßig dein\n"
	.string "Spiel zu speichern!\p"
	.string "Drücke den START Knopf und\n"
	.string "wähle SICHERN!$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Wir haben ein lautes Geräusch\n"
	.string "gehört…\p"
	.string "Als wir nach dem Rechten sahen,\n"
	.string "wurde ein POKéMON gestohlen.\p"
	.string "Ich kann nicht glauben, dass\n"
	.string "jemand zu so etwas fähig ist!\p"
	.string "…Seufz… Das gestohlene POKéMON.\p"
	.string "Ich frage mich, wie es ihm geht.\p"
	.string "Man sagt, dass ein POKéMON, das von\n"
	.string "einem bösen Menschen aufgezogen wird,\l"
	.string "selber böse wird.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER}!\p"
	.string "Benutze die hier doch bitte\n"
	.string "auf deiner POKéDEX-Reise!$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Um deinen POKéDEX zu vervollständigen,\n"
	.string "musst du POKéMON fangen.\p"
	.string "Wirf einen POKéBALL nach einem\n"
	.string "wilden POKéMON, um es fangen.$"

NewBarkTown_Lab_Text_Officer1:
	.string "Jemand soll hier eingebrochen und\n"
	.string "ein POKéMON gestohlen haben…\p"
	.string "Ich habe von PROF. LIND einige\n"
	.string "Informationen erhalten.\p"
	.string "Bei dem Dieb handelt es sich um einen\n"
	.string "jungen Mann mit langen roten Haaren…\p"
	.string "Wie?\p"
	.string "Gegen so jemanden hast du vor\n"
	.string "kurzem erst gekämpft?\p"
	.string "Hat er dich auch seinen Namen\n"
	.string "verraten?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "O.K.! Sein Name war also {RIVAL}.$"

NewBarkTown_Lab_Text_Officer2:
	.string "Danke, dass du mir bei den\n"
	.string "Ermittlungen geholfen hast!$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "Er hat doch sicher seinen Namen genannt?!$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "Ah, {PLAYER}!\p"
	.string "Wie geht es mit deinem POKéDEX voran?\n"
	.string "Ich bin gerade beschäftigt, ruf mich später\l"
	.string "an, dann überprüfe ich deinen Fortschritt!$"
