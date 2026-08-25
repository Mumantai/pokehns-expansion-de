NewBarkTown_PlayersHouse_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_PlayersHouse_1F_OnTransition
	.byte 0

NewBarkTown_PlayersHouse_1F_OnTransition::
	call_if_eq VAR_NEWBARK_TOWN_STATE, 1, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	end

NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT

	@add to newgame later
	clearflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_MOM_VISITED
	return

NewBarkTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_MOM_VISITED, NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular
	goto_if_set FLAG_ADVENTURE_STARTED, NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MovementFaceLeft
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsFriend::
	lock
	faceplayer
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomsFriend, MSGBOX_DEFAULT
	applymovement LOCALID_MOMS_FRIEND, NewBarkTown_PlayersHouse_1F_MovementFaceRight
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck::
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomLeaving, MSGBOX_DEFAULT
	setflag FLAG_MOM_VISITED
	clearflag FLAG_HIDE_ROUTE_30_NPCS
	setvar VAR_NEWBARK_TOWN_STATE, 5
	release
	end


NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_PlayersHouse_1F_EventScript_Mom_PokecenterChallenge
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	call NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_Mom_PokecenterChallenge::
	msgbox PlayersHouse_1F_Text_YouShouldRestABit_PokecenterChallenge, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu::
	special Special_MomEnsureInitialized
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomAnythingElse, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MOM_MENU, FALSE
	switch VAR_RESULT
	case 0, NewBarkTown_PlayersHouse_1F_EventScript_CheckSavings
	case 1, NewBarkTown_PlayersHouse_1F_EventScript_Deposit
	case 2, NewBarkTown_PlayersHouse_1F_EventScript_Withdraw
	case 3, NewBarkTown_PlayersHouse_1F_EventScript_ToggleSaving
	case 4, NewBarkTown_PlayersHouse_1F_EventScript_ExitSavings
	case MULTI_B_PRESSED, NewBarkTown_PlayersHouse_1F_EventScript_ExitSavings
	end

NewBarkTown_PlayersHouse_1F_EventScript_CheckSavings::
	special Special_MomGetBalance
	msgbox NewBarkTown_PlayersHouse_1F_Text_CurrentSavings, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_Deposit::
	checkmoney 1
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_DepositFailed
	closemessage
	special Special_MomOpenDepositInput
	waitstate
	compare VAR_0x8000, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	msgbox NewBarkTown_PlayersHouse_1F_Text_DepositSuccess, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_DepositFailed::
	msgbox NewBarkTown_PlayersHouse_1F_Text_NoMoneyToDeposit, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_Withdraw::
	special Special_MomGetBalance
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_WithdrawFailed
	closemessage
	special Special_MomOpenWithdrawInput
	waitstate
	compare VAR_0x8000, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	msgbox NewBarkTown_PlayersHouse_1F_Text_WithdrawSuccess, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_WithdrawFailed::
	msgbox NewBarkTown_PlayersHouse_1F_Text_NoMoneyToWithdraw, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ToggleSaving::
	special Special_MomIsSavingEnabled
	compare VAR_RESULT, TRUE
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_DisableSaving
	msgbox NewBarkTown_PlayersHouse_1F_Text_EnableSaving, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_ConfirmEnable
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ConfirmEnable::
	special Special_MomEnableSaving
	msgbox NewBarkTown_PlayersHouse_1F_Text_SavingEnabled, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_DisableSaving::
	msgbox NewBarkTown_PlayersHouse_1F_Text_DisableSaving, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_ConfirmDisable
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ConfirmDisable::
	special Special_MomDisableSaving
	msgbox NewBarkTown_PlayersHouse_1F_Text_SavingDisabled, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

NewBarkTown_PlayersHouse_1F_EventScript_ExitSavings::
	msgbox NewBarkTown_PlayersHouse_1F_Text_Goodbye, MSGBOX_DEFAULT
	return

NewBarkTown_PlayersHouse_1F_Text_MomAnythingElse:
	.string "Kann ich dir sonst irgendwie\n"
	.string "weiterhelfen, Liebling?$"

NewBarkTown_PlayersHouse_1F_Text_CurrentSavings:
	.string "Du hast zur Zeit {STR_VAR_2}\n"
	.string "angespart.$"

NewBarkTown_PlayersHouse_1F_Text_EnableSaving:
	.string "Möchtest du, dass ich ein wenig von\n"
	.string "dem Geld spare, das du verdienst?$"

NewBarkTown_PlayersHouse_1F_Text_SavingEnabled:
	.string "O.K.! Ich spare 25% des Geldes,\n"
	.string "das du in Kämpfen verdienst.$"

NewBarkTown_PlayersHouse_1F_Text_DisableSaving:
	.string "Möchtest du, dass ich aufhöre,\n"
	.string "für dich zu sparen?$"

NewBarkTown_PlayersHouse_1F_Text_SavingDisabled:
	.string "O.K. Ich höre auf, dein Geld zu sparen.$"

NewBarkTown_PlayersHouse_1F_Text_Goodbye:
	.string "Pass auf dich auf, Liebling!$"

NewBarkTown_PlayersHouse_1F_Text_DepositSuccess:
	.string "MAMA: Klingt gut! Ich lege das für\n"
	.string "dich zum Sparen zurück.$"

NewBarkTown_PlayersHouse_1F_Text_WithdrawSuccess:
	.string "MAMA: Hier, bitte sehr!$"

NewBarkTown_PlayersHouse_1F_Text_NoMoneyToDeposit:
	.string "MAMA: Du hast gar kein Geld, das ich\n"
	.string "für dich sparen könnte, Liebgling.$"

NewBarkTown_PlayersHouse_1F_Text_NoMoneyToWithdraw:
	.string "MAMA: Ich habe noch kein Geld\n"
	.string "für dich gespart, mein Schatz.$"

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end


NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro::
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_MOM
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_1
	waitmovement 0
	msgbox NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear
	call NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_2
	waitmovement 0
	setvar VAR_NEWBARK_TOWN_STATE, 2
	setvar VAR_NEWBARKTOWN_LABSTATE, 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	setflag FLAG_VISITED_NEWBARK_TOWN

	@former flagheap location

	releaseall
	end



NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear::
	playfanfare MUS_OBTAIN_ITEM
	message NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	return
	
NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes::
	msgbox NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1:
	delay_8
	walk_down
	walk_right
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2:
	delay_8
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_1:
	face_right
	walk_right
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_2:
	face_left
	walk_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceRight:
	face_right
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceLeft:
	face_left
	step_end

NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou:
	.string "Oh, {PLAYER}…! Unser Nachbar,\n"
	.string "PROF. LIND, hat nach dir gesucht.\p"
	.string "Er möchte, dass du etwas\n"
	.string "für ihn erledigst.\p"
	.string "Oh! Fast hätte ich es vergessen! Dein\n"
	.string "POKéCOM ist von der Reparatur zurück.\p"
	.string "Da hast du ihn!$"

NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear:
	.string "{PLAYER} erhält POKéCOM.$"

NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear:
	.string "MAMA: Telefonnummern werden gespeichert.\n"
	.string "Wähle einfach den Namen der Person,\p"
	.string "die du anrufen möchtest.\p"
	.string "Ist das nicht praktisch?$"

NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes:
	.string "Oh, und vergiss nicht deine\n"
	.string "TURBOTRETER!$"

NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} schlüpft in die neuen\n"
	.string "TURBOTRETER.$"

NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes:
	.string "MAMA: {PLAYER}, drücke den B Knopf\n"
	.string "um mit den TURBOTRETERn zu rennen!$"

NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting:
	.string "MAMA: PROF. LIND wartet auf dich.\p"
	.string "Beeile dich, Baby!$"

NewBarkTown_PlayersHouse_1F_Text_MomsFriend:
	.string "Hallo, {PLAYER}!\p"
	.string "Ich bin zu Besuch!\p"
	.string "Hast du schon gehört?\p"
	.string "Meine Tochter will unbedingt\n"
	.string "PROF. LINDs Assistentin werden.\p"
	.string "Sie liebt POKéMON von ganzem Herzen!$"

NewBarkTown_PlayersHouse_1F_Text_MomLeaving:
	.string "MAMA: Das ist ein niedliches POKéMON.\n"
	.string "Wo hast du es her??\p"
	.string "…\p"
	.string "Du beginnst also ein Abenteuer...\n"
	.string "Das klingt herausfordernd...\p"
	.string "Sei auf der Hut.\p"
	.string "POKéMON sind deine Kameraden.\n"
	.string "Ihr müsst als Team auftreten.\p"
	.string "Also, mach's gut!\n"
	.string "Ich stehe immer hinter dir!$"
