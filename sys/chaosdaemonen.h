// chaosdaemonen.h - Die Dämonentypen der Chaosgilde
//
// Jeder Dämon hat einen Typ und bekommt seinen Namen erst bei der
// Beschwörung aus master/namen.c. Beschworen wird mit
// 'beschwöre <typ>', der Typ ist zugleich der Name des Spruchs (in
// ASCII, so wie die Mudlib die Eingabe umwandelt).
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#ifndef __CHAOS_DAEMONEN_H__
#define __CHAOS_DAEMONEN_H__

// Schlüssel der Typtabelle
  // Name des Typs, männlich und weiblich
#define CD_NAME          "name"
#define CD_NAME_W        "name_w"
  // Beiwort in der Kurzbeschreibung ("der rasende Feuerdämon")
#define CD_BEIWORT       "beiwort"
  // Titelworte, eins davon wird an den Namen gehängt
#define CD_TITEL         "titel"
  // Spruch: Gildenstufe, Kosten, SI_DIFFICULTY, SI_SPELLFATIGUE,
  // SR_GOOD beim Lernen und beim Benutzen
#define CD_STUFE         "stufe"
#define CD_KOSTEN        "kosten"
#define CD_SCHWIERIGKEIT "schwierigkeit"
#define CD_PAUSE         "pause"
#define CD_GUT_LERNEN    "gut_lernen"
#define CD_GUT_BENUTZEN  "gut_benutzen"
  // Nur Kampfdämonen brauchen eine Chaosrüstung
#define CD_KAMPF         "kampf"
  // Nur der Erzmeister darf ihn beschwören
#define CD_ERZMEISTER    "erzmeister"
  // Mindestwerte für Pentagramm und Bannkreis, sonst wird der Dämon
  // aggressiv ({pentagramm, bannkreis})
#define CD_MIN_PENTA     "min_penta"
  // Wahrscheinlichkeiten (DAEM_AGGRESSIVE, DAEM_DISAPPEAR, DAEM_FALSE,
  // WRONG_DAEM), siehe sys/chaosnpc.h
#define CD_FAKTOREN      "faktoren"
  // Prozent der Schläge, die der Dämon nicht abfängt (100 = keine)
#define CD_ABFANGEN      "abfangen"
  // Folgezeit in Sekunden: ({grundwert, pro 1000 Erfolg})
#define CD_FOLGEZEIT     "folgezeit"
  // Statt einer Folgezeit eine Zahl von Kampfrunden:
  // A_INT des Beschwörers + faktor * Erfolg/1000
#define CD_RUNDEN        "runden"
  // Verschwindet nicht beim Reset
#define CD_BLEIBT        "bleibt"
  // Stärke hängt von Pentagramm und Skill ab (setPower)
#define CD_POWER         "power"
  // Werte des NPCs
#define CD_NPC_LEVEL     "npc_level"
#define CD_NPC_HP        "npc_hp"
#define CD_ATTRIBUTE     "attribute"
#define CD_PROZENT       "prozent"
#define CD_HANDS         "hands"
#define CD_BODY          "body"
#define CD_SIZE          "size"
#define CD_WEIGHT        "weight"
#define CD_ALIGN         "align"
#define CD_LIGHT         "light"
#define CD_RESISTANCE    "resistance"
#define CD_MATERIAL      "material"
#define CD_LONG          "long"
#define CD_MSGIN         "msgin"
#define CD_MSGOUT        "msgout"
#define CD_MMSGIN        "mmsgin"
#define CD_DIE_MSG       "die_msg"
#define CD_IDS           "ids"
  // Text an die anderen im Raum bei der Beschwörung, @WER1 ist der
  // Beschwörer
#define CD_SAY           "say"

// Die Tabelle steht in master/daemonen.c (CHAOS_DAEMONEN_MASTER).

// Prop im Dämon: sein Typ (Schlüssel in CHAOS_DAEMONEN)
#define CHAOS_DAEMON_TYP     "chaos_daemon_typ"

// Der Master mit der Typtabelle
#define CHAOS_DAEMONEN_MASTER (CHAOS_GILDEN_MASTER("daemonen"))

// Der Master mit den Namen
#define CHAOS_NAMEN_MASTER (CHAOS_GILDEN_MASTER("namen"))

// Der Spruch, über den man alle Dämonen beschwört
#define CHAOS_SPRUCH_BESCHWOERE "beschwoere"

#endif
