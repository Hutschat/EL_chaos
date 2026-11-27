// chaosburg.h - Die Räume der Burg Zwielichtstein
//
// Die Burg liegt auf einem Felssporn östlich der Menagerie im
// Schattental. Alle Räume außer der Gildenhalle (gilde.c) sind
// virtuell (room/virtual_compiler.c, Details in room/dmaker.c).
//
// Erdgeschoss (+08), x von +007 bis +012, * = eingestürzt/versperrt:
//
//                   Zw-N*
//                    |
//  Wache  Ställe*  Zw-N    Bergfr.  Küche-Vorrat*
//    |      |       |        |       |
//  Tor*--Vorburg--I.Tor---Burghof--Vorhalle--Rittersaal--Gildenhalle
//           |       |        |
//       Schmiede  Zw-S    Kapelle--Sakristei*
//                   |
//                 Zw-S*
//
// Obergeschoss (+09): Wehrgang* über der Wachstube, Bergfried 1. Stock,
//   Bibliothek -- Galerie (über der Vorhalle und dem Rittersaal) --
//   Schlafgemach* (nördlich der Galerie)
// Bergfried: 2. Stock (+10), Turmspitze mit dem Riss (+11), im Riss (+12)
// Keller (+07): Brunnenkammer* -- Kellergang* -- Schänke, Kerker* im
//   Süden des Kellergangs
//
// * mit eingestürzten oder versperrten Ausgängen
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu
// 27.11.2026 It@Efferdland            ausgebaut

#ifndef __CHAOS_BURG_H__
#define __CHAOS_BURG_H__

#define CHAOS_VC_BURG ([\
  "[+007+051+08]": CHAOS_BURG_STD("drinnen"),    /* Torhaus        */\
  "[+007+052+08]": CHAOS_BURG_STD("drinnen"),    /* Wachstube      */\
  "[+008+051+08]": CHAOS_BURG_STD("draussen"),   /* Vorburg        */\
  "[+008+052+08]": CHAOS_BURG_STD("drinnen"),    /* Ställe         */\
  "[+008+050+08]": CHAOS_BURG_STD("drinnen"),    /* Schmiede       */\
  "[+009+051+08]": CHAOS_BURG_STD("drinnen"),    /* Inneres Tor    */\
  "[+009+052+08]": CHAOS_BURG_STD("draussen"),   /* Zwinger Nord   */\
  "[+009+053+08]": CHAOS_BURG_STD("draussen"),   /* Zwinger Nord 2 */\
  "[+009+050+08]": CHAOS_BURG_STD("draussen"),   /* Zwinger Süd    */\
  "[+009+049+08]": CHAOS_BURG_STD("draussen"),   /* Zwinger Süd 2  */\
  "[+010+051+08]": CHAOS_BURG_STD("draussen"),   /* Burghof        */\
  "[+010+052+08]": CHAOS_BURG_STD("drinnen"),    /* Bergfried      */\
  "[+010+052+09]": CHAOS_BURG_STD("drinnen"),    /* Bergfried 1    */\
  "[+010+052+10]": CHAOS_BURG_STD("drinnen"),    /* Bergfried 2    */\
  "[+010+052+11]": CHAOS_BURG_STD("draussen"),   /* Turmspitze     */\
  "[+010+052+12]": CHAOS_BURG_STD("draussen"),   /* Im Riss        */\
  "[+010+050+08]": CHAOS_BURG_STD("draussen"),   /* Kapelle        */\
  "[+011+050+08]": CHAOS_BURG_STD("drinnen"),    /* Sakristei      */\
  "[+011+051+08]": CHAOS_BURG_STD("drinnen"),    /* Vorhalle       */\
  "[+012+051+08]": CHAOS_BURG_STD("drinnen"),    /* Rittersaal     */\
  "[+011+052+08]": CHAOS_BURG_STD("drinnen"),    /* Küche          */\
  "[+012+052+08]": CHAOS_BURG_STD("drinnen"),    /* Vorratskammer  */\
  "[+007+052+09]": CHAOS_BURG_STD("draussen"),   /* Wehrgang       */\
  "[+011+051+09]": CHAOS_BURG_STD("bibliothek"), /* Bibliothek     */\
  "[+012+051+09]": CHAOS_BURG_STD("drinnen"),    /* Galerie        */\
  "[+012+052+09]": CHAOS_BURG_STD("drinnen"),    /* Schlafgemach   */\
  "[+011+051+07]": CHAOS_BURG_STD("drinnen"),    /* Kellergang     */\
  "[+012+051+07]": CHAOS_BURG_STD("schaenke"),   /* Schänke        */\
  "[+011+050+07]": CHAOS_BURG_STD("drinnen"),    /* Kerker         */\
  "[+011+052+07]": CHAOS_BURG_STD("drinnen"),    /* Brunnenkammer  */\
])

// Höhe des Erdgeschosses in Metern
#define CHAOS_BURG_HOEHE  610

// Chaosmagie in der Burg (room/std/dets.c)
  // Prozent: Bei einem Reset bekommt ein Raum eine wechselnde Zeile
#define CHAOS_VARIANTE_CHANCE   70
  // Prozent: Beim Betreten passiert einem Spieler etwas Seltsames
#define CHAOS_EFFEKT_CHANCE     8
  // Prozent: Beim Betreten schlägt ein Chaosblitz ein und hinterlässt
  // einen Chaoswicht (npc/chaoswicht.c)
#define CHAOS_AUSBRUCH_CHANCE   2
  // Im Riss ist alles viel stärker
#define CHAOS_RISS_EFFEKT       40
#define CHAOS_RISS_AUSBRUCH     10
  // Bonus auf Pentagramm und Bannkreis beim Beschwören am Riss
#define CHAOS_RISS_BONUS        10

// Props der Burgräume
  // Wechselnde Zeilen des Raums (string*)
#define P_CHAOS_VARIANTEN       "chaos_varianten"
  // Versperrte Ausgänge: ([richtung: text])
#define P_CHAOS_VERSPERRT       "chaos_versperrt"
  // Der Raum liegt am Riss (Beschwörungsbonus, stärkere Effekte)
#define P_CHAOS_RISS            "chaos_riss"

#endif
