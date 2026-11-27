// chaosburg.h - Die Räume der Burg Zwielichtstein
//
// Die Burg liegt auf einem Felssporn östlich der Menagerie im
// Schattental. Alle Räume außer der Gildenhalle (gilde.c) sind
// virtuell (room/virtual_compiler.c, Details in room/dmaker.c).
//
// Erdgeschoss (+08), x nach Osten, y nach Norden:
//
//              k r T              k Schänke im Gesindehaus
//              | | |              r Ruine (Ställe, Werkstatt, Kapelle)
//              o-o-o   h h h C    T Turm (frei stehend, bis +12)
//              | | |   | | | |    o Burgplatz
//          o-h-o-o-o-h-h-h-h-h-g  g Gildenhalle (gilde.c)
//              | | |   | | | |    C Chaoskapelle
//              o-o-o   h h h R    R Treppe in den Keller
//              | | |
//              h r r
//
//   Torhaus +007, Burgplatz +008..+010, Hauptgebäude: Eingangshalle
//   +011, Mittelgang +012..+014 (Norden: Küche, Bibliothek, Treppe;
//   Süden: Vorratskammer, Schreibstube, Wachstube), Rittersaal +015
//
// Obergeschoss (+09): Wehrgang über dem Torhaus; Söller, oberer Gang
//   (Norden: Gästezimmer, Gemach des Meisters, Treppe; Süden: x,
//   Gemach der Herrin, Kammer der Zofe), Galerie über dem Rittersaal
// Turm +010/+053: +08 bis +10, Spitze mit dem Riss +11, im Riss +12
// Keller (+07) unter dem Hauptgebäude: Treppe, Weinkeller, Kellergang
//   (Norden: Waffenkammer, Folterraum, x; Süden: Rüstungskammer,
//   Verlies, Wachraum), Gruft mit Grabkammer
//
// x = eingestürzt (sichtbarer Ausgang mit EX_FUNC "versperrt")
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu
// 27.11.2026 It@Efferdland            ausgebaut
// 27.11.2026 It@Efferdland            neuer Grundriss

#ifndef __CHAOS_BURG_H__
#define __CHAOS_BURG_H__

#define CHAOS_VC_BURG ([\
  "[+007+051+08]": CHAOS_BURG_STD("drinnen"),     /* Torhaus        */\
  "[+008+052+08]": CHAOS_BURG_STD("draussen"),    /* Platz NW       */\
  "[+009+052+08]": CHAOS_BURG_STD("draussen"),    /* Platz N        */\
  "[+010+052+08]": CHAOS_BURG_STD("draussen"),    /* Platz NO       */\
  "[+008+051+08]": CHAOS_BURG_STD("draussen"),    /* Platz W        */\
  "[+009+051+08]": CHAOS_BURG_STD("draussen"),    /* Platz Brunnen  */\
  "[+010+051+08]": CHAOS_BURG_STD("draussen"),    /* Platz O        */\
  "[+008+050+08]": CHAOS_BURG_STD("draussen"),    /* Platz SW       */\
  "[+009+050+08]": CHAOS_BURG_STD("draussen"),    /* Platz S        */\
  "[+010+050+08]": CHAOS_BURG_STD("draussen"),    /* Platz SO       */\
  "[+008+053+08]": CHAOS_BURG_STD("schaenke"),    /* Schänke        */\
  "[+009+053+08]": CHAOS_BURG_STD("draussen"),    /* Ställe         */\
  "[+008+049+08]": CHAOS_BURG_STD("drinnen"),     /* Schmiede       */\
  "[+009+049+08]": CHAOS_BURG_STD("draussen"),    /* Werkstatt      */\
  "[+010+049+08]": CHAOS_BURG_STD("draussen"),    /* Kapelle        */\
  "[+010+053+08]": CHAOS_BURG_STD("drinnen"),     /* Turm           */\
  "[+010+053+09]": CHAOS_BURG_STD("drinnen"),     /* Turm 1         */\
  "[+010+053+10]": CHAOS_BURG_STD("drinnen"),     /* Turm 2         */\
  "[+010+053+11]": CHAOS_BURG_STD("draussen"),    /* Turmspitze     */\
  "[+010+053+12]": CHAOS_BURG_STD("draussen"),    /* Im Riss        */\
  "[+011+051+08]": CHAOS_BURG_STD("drinnen"),     /* Eingangshalle  */\
  "[+012+051+08]": CHAOS_BURG_STD("drinnen"),     /* Gang W         */\
  "[+013+051+08]": CHAOS_BURG_STD("drinnen"),     /* Gang M         */\
  "[+014+051+08]": CHAOS_BURG_STD("drinnen"),     /* Gang O         */\
  "[+012+052+08]": CHAOS_BURG_STD("drinnen"),     /* Küche          */\
  "[+012+050+08]": CHAOS_BURG_STD("drinnen"),     /* Vorratskammer  */\
  "[+013+052+08]": CHAOS_BURG_STD("bibliothek"),  /* Bibliothek     */\
  "[+013+050+08]": CHAOS_BURG_STD("drinnen"),     /* Schreibstube   */\
  "[+014+052+08]": CHAOS_BURG_STD("drinnen"),     /* Treppenhaus    */\
  "[+014+050+08]": CHAOS_BURG_STD("drinnen"),     /* Wachstube      */\
  "[+015+051+08]": CHAOS_BURG_STD("drinnen"),     /* Rittersaal     */\
  "[+015+052+08]": CHAOS_BURG_STD("drinnen"),     /* Chaoskapelle   */\
  "[+015+050+08]": CHAOS_BURG_STD("drinnen"),     /* Kellertreppe   */\
  "[+007+051+09]": CHAOS_BURG_STD("draussen"),    /* Wehrgang       */\
  "[+011+051+09]": CHAOS_BURG_STD("draussen"),    /* Söller         */\
  "[+012+051+09]": CHAOS_BURG_STD("drinnen"),     /* Gang oben W    */\
  "[+013+051+09]": CHAOS_BURG_STD("drinnen"),     /* Gang oben M    */\
  "[+014+051+09]": CHAOS_BURG_STD("drinnen"),     /* Gang oben O    */\
  "[+012+052+09]": CHAOS_BURG_STD("drinnen"),     /* Gästezimmer    */\
  "[+013+052+09]": CHAOS_BURG_STD("drinnen"),     /* Gemach Meister */\
  "[+013+050+09]": CHAOS_BURG_STD("drinnen"),     /* Gemach Herrin  */\
  "[+014+052+09]": CHAOS_BURG_STD("drinnen"),     /* Treppenabsatz  */\
  "[+014+050+09]": CHAOS_BURG_STD("drinnen"),     /* Zofe           */\
  "[+015+051+09]": CHAOS_BURG_STD("drinnen"),     /* Galerie        */\
  "[+015+050+07]": CHAOS_BURG_STD("drinnen"),     /* Kellertreppe   */\
  "[+015+051+07]": CHAOS_BURG_STD("drinnen"),     /* Weinkeller     */\
  "[+014+051+07]": CHAOS_BURG_STD("drinnen"),     /* Kellergang O   */\
  "[+013+051+07]": CHAOS_BURG_STD("drinnen"),     /* Kellergang M   */\
  "[+012+051+07]": CHAOS_BURG_STD("drinnen"),     /* Kellergang W   */\
  "[+014+052+07]": CHAOS_BURG_STD("drinnen"),     /* Waffenkammer   */\
  "[+014+050+07]": CHAOS_BURG_STD("drinnen"),     /* Rüstungskammer */\
  "[+013+052+07]": CHAOS_BURG_STD("drinnen"),     /* Folterraum     */\
  "[+013+050+07]": CHAOS_BURG_STD("drinnen"),     /* Verlies        */\
  "[+012+050+07]": CHAOS_BURG_STD("drinnen"),     /* Wachraum       */\
  "[+011+051+07]": CHAOS_BURG_STD("drinnen"),     /* Gruft          */\
  "[+011+052+07]": CHAOS_BURG_STD("drinnen"),     /* Grabkammer     */\
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
