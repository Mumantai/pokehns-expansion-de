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
        .header = COMPOUND_STRING("Information: More Options"),
        .desc = COMPOUND_STRING("The clock can be changed from any\n"
                                "POKéMON CENTER with no penalty.\n"
                                "Make sure to check your BAG's KEY ITEMS\n"
                                "and your OPTIONS MENU for even more\n"
                                "ways to customize your experience.\n"
                                "Enjoy!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
        .header = COMPOUND_STRING("WARNUNG: KOMPATIBILITÄT"),
        .desc = COMPOUND_STRING("Um Schäden am Spielstand zu meiden, achte\n"
                                "vor der Verbindung auf Folgendes:\n"
                                "Ihr spielt beide Herz & Seele.\n"
                                "Eure Spiele haben die gleiche Version.\n"
                                "Ihr habt die gleichen Herausf.-Einst.\n"
                                "Ihr benutzt KEINE Randomizer-Einst."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 4, 5},
    },
    [HELP_TELEPORTER_WINDOW] =
    {
        .header = COMPOUND_STRING("OPTIONAL BONUS CONTENT: TELEPORTER"),
        .desc = COMPOUND_STRING("The TELEPORTER can PERMANENTLY change\n"
                                "POKéMON into their GALARIAN forms.\n"
                                "GALARIAN forms are NOT required\n"
                                "for story progression or\n"
                                "NATIONAL POKéDEX completion.\n"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_SINJOH_WINDOW] =
    {
        .header = COMPOUND_STRING("OPTIONAL BONUS CONTENT: SINJOH"),
        .desc = COMPOUND_STRING("This NPC grants access to optional\n"
                                "bonus content: SINJOH.\n"
                                "It is NOT required for story\n"
                                "or NATIONAL POKéDEX completion.\n"
                                "\n"
                                "It's just a bonus. If you want it."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
        .header = COMPOUND_STRING("OPTIONAL BONUS CONTENT: ISLES"),
        .desc = COMPOUND_STRING("This NPC grants access to optional\n"
                                "bonus content: ISLES.\n"
                                "It is NOT required for story\n"
                                "or NATIONAL POKéDEX completion.\n"
                                "\n"
                                "It's just a bonus. If you want it."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY POKéMON ABILITIES"),
        .desc = COMPOUND_STRING("PICHU's ability is STATIC.\n"
                                "CLEFFA's ability is CUTE CHARM.\n"
                                "IGGLYBUFF's ability is CUTE CHARM.\n"
                                "TYROGUE's ability is GUTS.\n"
                                "SMOOCHUM's ability is OBLIVIOUS.\n"
                                "ELEKID's ability is STATIC.\n"
                                "MAGBY's ability is FLAME BODY."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY POKéMON TYPES"),
        .desc = COMPOUND_STRING("PICHU is ELECTRIC type.\n"
                                "CLEFFA is NORMAL type.\n"
                                "IGGLYBUFF is NORMAL type.\n"
                                "TYROGUE is FIGHTING type.\n"
                                "SMOOCHUM is ICE type.\n"
                                "ELEKID is ELECTRIC type.\n"
                                "MAGBY is FIRE type."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY POKéMON CRIES"),
        .desc = COMPOUND_STRING("PICHU says WAAAH.\n"
                                "CLEFFA says EEK.\n"
                                "IGGLYBUFF says LALALA.\n"
                                "TYROGUE says HIYAH.\n"
                                "SMOOCHUM says EHEHE.\n"
                                "ELEKID says OI, OI, OI.\n"
                                "MAGBY says TCH."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
        .header = COMPOUND_STRING("BABY POKéMON ACTIONS"),
        .desc = COMPOUND_STRING("PICHU likes to PLAY all day.\n"
                                "CLEFFA LOOKS at the moon.\n"
                                "IGGLYBUFF puts them to SLEEP.\n"
                                "TYROGUE TRAINS constantly.\n"
                                "SMOOCHUM likes to SHOW off.\n"
                                "ELEKID STORES up charge.\n"
                                "MAGBY often ANGERS."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("TRÖGE: NORMALE POKéRIEGEL"),
        .desc = COMPOUND_STRING("Farben locken perfekte IS an:\n"
                                "ROT: KP,ANG,INI   BLU: KP,SPA,INI\n"
                                "PNK: ANG,SPA,INI  GRN: KP,VER,SPV\n"
                                "GLB: KP,ANG,VER   PUR: ANG,VER,SPV\n"
                                "IND: KP,SPA,SPV   BRN: VER,INI,SPV\n"
                                "LBL: SPA,INI,SPV  OLV: ANG,VER,INI\n"
                                "GRA: KP,ANG,SPA\n"
                                "Jeder POKéRIEGEL  lockt POKéMON mit\n"
                                "VERSTECKTER FÄHIGKEIT an."

                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_GOLD_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("TRÖGE: GOLDENE POKéRIEGEL"),
        .desc = COMPOUND_STRING("GOLDENE POKéRIEGEL locken POKéMON mit\n"
                                "5 perfekten IS an. Der Geschmack bestimmt\n"
                                "welche IS nicht perfekt ist.\n"
                                "SCHARF: SP.ANG    TROCKEN:    ANGRIFF\n"
                                "SÜSS: SP.VERT     BITTER: INITIATIVE\n"
                                "SAUER: KP\n"
                                "Jeder POKéRIEGEL  lockt POKéMON mit\n"
                                "VERSTECKTER FÄHIGKEIT an."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
