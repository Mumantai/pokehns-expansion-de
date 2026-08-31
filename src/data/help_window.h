// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_DEMO_WINDOW] =
    {
        .header = COMPOUND_STRING("Information: Help Windows"),
        .desc = COMPOUND_STRING("This is a help window. You can put\n"
                                "lots of text on the screen that\n"
                                "players won't read!\n\nIsn't that great!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_GAMESTART_WINDOW] =
    {
        .header = COMPOUND_STRING("Information: Mehr Optionen"),
        .desc = COMPOUND_STRING("Die Uhr kann in jedem POKéMON-CENTER\n"
                                "problemlos geändert werden.\n"
                                "Prüfe auch die BASIS-ITEMS und das\n"
                                "OPTIONS-MENÜ um dein Spiel noch weiter\n"
                                "anpassen zu können.\n"
                                "Viel Spaß!\n"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
        .header = COMPOUND_STRING("WARNUNG: KOMPATIBILITÄT"),
        .desc = COMPOUND_STRING("Verbindest du dich mit einem Spiel,\n"
                                "das nicht Herz & Seele ist, kann\n"
                                "zu permanenten Schäden an deinem\n"
                                "Speicherstand führen. Fahre nur\n"
                                "fort, wenn du dich mit einer Kopie\n"
                                "von Herz & Seele verbindest, die\n"
                                "auf der gleichen Version ist."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_TELEPORTER_WINDOW] =
    {
        .header = COMPOUND_STRING("OPTIONALER BONUS-INHALT: TELEPORTER"),
        .desc = COMPOUND_STRING("Der TELEPORTER kann POKéMON\n"
                                "PERMANENT in ihre GALAR-Formen\n"
                                "verwandeln.\n"
                                "GALAR-Formen sind für die Geschichte\n"
                                "oder die Vervollständigung deines\n"
                                "NATIONALEN POKéDEX NICHT notwendig.\n"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_SINJOH_WINDOW] =
    {
        .header = COMPOUND_STRING("OPTIONALER BONUS-INHALT: SINJOH"),
        .desc = COMPOUND_STRING("Dieser NPC gewährt Zugriff auf optionalen\n"
                                "Bonusinhalt: SINJOH.\n"
                                "Er ist NICHT erforderlich für die Story\n"
                                "oder die Vervollständigung deines\n"
                                "NATIONALEN POKéDEX.\n"
                                "\n"
                                "Es ist nur ein Bonus und rein optional."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
        .header = COMPOUND_STRING("OPTIONALER BONUS-INHALT: INSELN"),
        .desc = COMPOUND_STRING("DIESER NPC gewährt Zugriff auf optionalen\n"
                                "Bonusinhalt: INSELN.\n"
                                "Er ist NICHT erforderlich für die Story\n"
                                "oder die Vervollständigung deines\n"
                                "NATIONALEN POKéDEX.\n"
                                "\n"
                                "Es ist nur ein Bonus und rein optional."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY-POKéMON FÄHIGKEITEN"),
        .desc = COMPOUND_STRING("PICHUs Fähigkeit ist STATIK.\n"
                                "PIIs Fähigkeit ist CHARMBOLZEN.\n"
                                "FLUFFELUFFs Fähigkeit ist CHARMBOLZEN.\n"
                                "RABAUZ Fähigkeit ist ADRENALIN.\n"
                                "KUSSILLAs Fähigkeit ist DÖSIGKEIT.\n"
                                "ELEKIDs Fähigkeit ist STATIK.\n"
                                "MAGBYs Fähigkeit ist FLAMMKÖRPER."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY-POKéMON TYPEN"),
        .desc = COMPOUND_STRING("PICHU ist vom TYP ELEKTRO.\n"
                                "PII ist vom TYP NORMAL.\n"
                                "FLUFFELUFF ist vom TYP NORMAL.\n"
                                "RABAUZ ist vom TYP KAMPF.\n"
                                "KUSSILLA ist vom TYP EIS.\n"
                                "ELEKID ist vom TYP ELEKTRO.\n"
                                "MAGBY ist vom TYP FEUER."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY-POKéMON RUFE"),
        .desc = COMPOUND_STRING("PICHU macht WAAAH.\n"
                                "PII macht IIE.\n"
                                "FLUFFELUFF macht LALALA.\n"
                                "RABAUZ macht HAIYAH.\n"
                                "KUSSILLA macht EHEHE.\n"
                                "ELEKID macht OI, OI, OI.\n"
                                "MAGBY macht TSS."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY-POKéMON HANDLUNGEN"),
        .desc = COMPOUND_STRING("PICHU SPIELT gerne den ganzen Tag.\n"
                                "PII SCHAUT auf den Mond.\n"
                                "FLUFFELUFF macht sie SCHLÄFRIG.\n"
                                "RABAUZ TRAINIERT ständig.\n"
                                "KUSSILLA POSIERT gerne.\n"
                                "ELEKID SAMMELT Ladung.\n"
                                "MAGBY REGT sicht oft auf."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
