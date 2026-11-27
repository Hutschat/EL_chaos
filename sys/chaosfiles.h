// chaosfiles.h - Die Pfade fuer die Chaosgilde
//
// Letzte Aenderung:
//
// 11.03.2019 It@Efferdland            SHADOWS, ARMOURS, ARENA
// 27.11.2026 It@Efferdland            Burg Zwielichtstein

#ifndef CHAOS___FILES
#define CHAOS___FILES

#define CHAOS_GILDE(x) "/gilden/chaos/"+x

#define CHAOS_GILDEN_MASTER(x)     CHAOS_GILDE("master/")+x
#define CHAOS_GILDEN_OBJ(x)        CHAOS_GILDE("obj/")+x
#define CHAOS_GILDEN_KOMPONENTE(x) "/p/pool/kompos/"+x
#define CHAOS_GILDEN_MON(x)        CHAOS_GILDE("npc/")+x
#define CHAOS_GILDEN_LOG(x)        CHAOS_GILDE("log/")+x
#define CHAOS_GILDEN_ROOM(x)       CHAOS_GILDE("room/")+x
#define CHAOS_GILDEN_TXT(x)        CHAOS_GILDE("texte/")+x
#define CHAOS_GILDEN_SHADOWS(x)    CHAOS_GILDE("shadows/")+x
#define CHAOS_GILDEN_ARMOUR(x)     CHAOS_GILDE("armour/")+x
#define CHAOS_GILDEN_ARENA(x)      CHAOS_GILDE("chaosarena/")+x

// Master
#define CHAOS_GILDENMASTER (CHAOS_GILDEN_MASTER("gilden_master"))
#define CHAOS_HAUTMASTER   (CHAOS_GILDEN_MASTER("haut_master"))
#define CHAOS_GILDENROOM   (CHAOS_GILDE("gilde"))
#define CHAOS_CHAOSHAUT    (CHAOS_GILDEN_ARMOUR("chaosruestung"))

// Burg Zwielichtstein (VC in room/, Liste in sys/chaosburg.h)
#define CHAOS_BURG_STD(x)  CHAOS_GILDEN_ROOM("std/")+x
#define CHAOS_BURGTOR      (CHAOS_GILDEN_ROOM("[+007+051+08]"))
#define CHAOS_SCHAENKE     (CHAOS_GILDEN_ROOM("[+009+051+07]"))
#define CHAOS_RITTERSAAL   (CHAOS_GILDEN_ROOM("[+009+051+08]"))
  // Der Pfad im Schattental, der zum Burgtor hinaufführt
#define CHAOS_BURGPFAD     "/d/nordland/schattental/room/[+006+051+08:O]"

// Misc
#define CHAOS_DEATHMARK "/room/death/death_mark"
#define CHAOS_CORPSE    "/std/corpse"

#define TRIB(x) tell_room(CHAOS_GILDEN_ROOM("ctrib"), \
  break_string( "Der unsichtbare Arenasprecher verkuendet:\n"+x,0,0,1))
  

#endif
