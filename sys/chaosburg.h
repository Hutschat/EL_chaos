// chaosburg.h - Die Räume der Burg Zwielichtstein
//
// Die Burg liegt auf einem Felssporn östlich der Menagerie im
// Schattental. Alle Räume außer der Gildenhalle (gilde.c) sind
// virtuell (room/virtual_compiler.c, Details in room/dmaker.c).
//
//        Wehrgang -- Turmspitze          (eine Ebene höher)
//                         |
//                       Turm
//                         |
//   Pfad -- Burgtor -- Burghof -- Rittersaal -- Gildenhalle (gilde.c)
//                         |           |
//                    Bibliothek    Schänke (unter dem Rittersaal)
//
//   Der Kerker liegt unter dem Burghof.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#ifndef __CHAOS_BURG_H__
#define __CHAOS_BURG_H__

#define CHAOS_VC_BURG ([\
  "[+007+051+08]": CHAOS_BURG_STD("draussen"),  /* Burgtor     */\
  "[+008+051+08]": CHAOS_BURG_STD("draussen"),  /* Burghof     */\
  "[+008+050+08]": CHAOS_BURG_STD("bibliothek"), /* Bibliothek  */\
  "[+008+051+07]": CHAOS_BURG_STD("drinnen"),   /* Kerker      */\
  "[+008+052+08]": CHAOS_BURG_STD("drinnen"),   /* Turm        */\
  "[+008+052+09]": CHAOS_BURG_STD("draussen"),  /* Turmspitze  */\
  "[+007+052+09]": CHAOS_BURG_STD("draussen"),  /* Wehrgang    */\
  "[+009+051+08]": CHAOS_BURG_STD("drinnen"),   /* Rittersaal  */\
  "[+009+051+07]": CHAOS_BURG_STD("schaenke"),  /* Schänke     */\
])

// Höhe des Burghofs in Metern
#define CHAOS_BURG_HOEHE  610

#endif
