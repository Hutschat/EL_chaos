// daemonen.c - Die Dämonentypen der Chaosgilde
//
// Schlüssel siehe sys/chaosdaemonen.h. Im Langtext steht @NAME für den
// Namen des Dämons und @ART für die Art mit unbestimmtem Artikel
// ("ein Feuerdämon", "eine Feuerdämonin").
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma no_clone
#pragma no_inherit
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

static mapping typen = ([
  "orakeldaemon": ([
    CD_NAME:          "Orakeldämon",
    CD_NAME_W:        "Orakeldämonin",
    CD_BEIWORT:       "weise",
    CD_TITEL:         ({"Augur","Vates","Sibyl","Pythor","Omenis"}),
    CD_STUFE:         4,
    CD_KOSTEN:        10,
    CD_SCHWIERIGKEIT: -50,
    CD_PAUSE:         3,
    CD_GUT_LERNEN:    200,
    CD_FAKTOREN:      ({1,3,7,1}),
    CD_FOLGEZEIT:     ({60,30}),
    CD_NPC_LEVEL:     10,
    CD_NPC_HP:        200,
    CD_HANDS:         ({" mit blossen Klauen",40,({DT_RIP})}),
    CD_BODY:          30,
    CD_SIZE:          110,
    CD_WEIGHT:        30000,
    CD_ALIGN:         -100,
    CD_LONG:          "@NAME ist @ART mit einem großen Kopf, einer hohen "
                      "Stirn und fast durchsichtigen Augen. Zum Kämpfen "
                      "ist @NAME nicht geboren, sieht aber Dinge, die "
                      "anderen verborgen bleiben. Frag einfach nach.",
    CD_MSGIN:         "schwebt nachdenklich herein",
    CD_MSGOUT:        "schwebt nachdenklich davon",
    CD_MMSGIN:        "steigt aus einer Gedankenwolke empor",
    CD_DIE_MSG:       " verschwindet als Inspirationspartikel.\n",
    CD_IDS:           ({"orakeldämon","orakeldaemon","orakel"}),
    CD_SAY:           "@WER1 murmelt leise Worte einer gutturalen "
                      "Sprache und lässt eine rote, magische Wolke "
                      "entstehen, aus der eine finstere Gestalt "
                      "hervorkommt.",
  ]),
  "schattendaemon": ([
    CD_NAME:          "Schattendämon",
    CD_NAME_W:        "Schattendämonin",
    CD_BEIWORT:       "wilde",
    CD_TITEL:         ({"Umbra","Umbrax","Noctis","Tenebr","Umbrel"}),
    CD_STUFE:         7,
    CD_KOSTEN:        50,
    CD_SCHWIERIGKEIT: 20,
    CD_PAUSE:         6,
    CD_GUT_LERNEN:    300,
    CD_GUT_BENUTZEN:  -100,
    CD_KAMPF:         1,
    CD_FAKTOREN:      ({5,15,10,20}),
    CD_ABFANGEN:      100,
    CD_RUNDEN:        1,
    CD_NPC_LEVEL:     15,
    CD_NPC_HP:        300,
    CD_HANDS:         ({" mit klauenhaften Krallen",150,({DT_RIP})}),
    CD_BODY:          120,
    CD_SIZE:          140,
    CD_WEIGHT:        60000,
    CD_ALIGN:         -90,
    CD_RESISTANCE:    ([DT_DARKNESS:-1.0,DT_LIGHT:0.4]),
    CD_LONG:          "@NAME ist @ART aus dem Zwielicht zwischen den "
                      "Welten, klein, aber recht wild. Über die "
                      "Artgenossen in den Kerkern der Dämonenburg kann "
                      "@NAME nur spöttisch lächeln.",
    CD_MSGIN:         "stolpert wild herein",
    CD_MSGOUT:        "stolpert wild davon",
    CD_MMSGIN:        "erscheint in einer dunklen Wolke",
    CD_DIE_MSG:       " öffnet eine unsichtbare Tür und verschwindet.\n",
    CD_IDS:           ({"schattendämon","schattendaemon"}),
    CD_SAY:           "@WER1 beschwört unheimliche Kräfte und öffnet "
                      "ein Tor in andere Welten.",
  ]),
  "lichtdaemon": ([
    CD_NAME:          "Lichtdämon",
    CD_NAME_W:        "Lichtdämonin",
    CD_BEIWORT:       "blitzende",
    CD_TITEL:         ({"lith","leth","lethot","luxar","lumis"}),
    CD_STUFE:         8,
    CD_KOSTEN:        50,
    CD_SCHWIERIGKEIT: 30,
    CD_PAUSE:         10,
    CD_GUT_LERNEN:    400,
    CD_GUT_BENUTZEN:  -200,
    CD_KAMPF:         1,
    CD_FAKTOREN:      ({15,10,15,30}),
    CD_ABFANGEN:      50,
    CD_FOLGEZEIT:     ({240,58}),
    CD_POWER:         1,
    CD_NPC_LEVEL:     5,
    CD_NPC_HP:        400,
    CD_PROZENT:       60,
    CD_HANDS:         ({" mit blitzenden Krallen",140,
                        ({DT_LIGHTNING,DT_RIP})}),
    CD_BODY:          100,
    CD_SIZE:          80,
    CD_WEIGHT:        30000,
    CD_ALIGN:         100,
    CD_LIGHT:         1,
    CD_RESISTANCE:    ([DT_LIGHTNING:-0.9,DT_DARKNESS:-0.3,
                        DT_LIGHT:0.3]),
    CD_MATERIAL:      ([MAT_LIVING:80,MAT_LIGHT:10,MAT_MAGIC_BLACK:10]),
    CD_LONG:          "@NAME ist @ART, etwas klein geraten, mit kurzen "
                      "Stummelbeinen, gedrungener Gestalt und "
                      "schwächlichen Armen. Die schwach leuchtende Haut "
                      "und die kleinen Blitze, die um den Kopf kreisen, "
                      "verraten die Herkunft.",
    CD_MSGIN:         "schießt wie ein Blitz herein",
    CD_MSGOUT:        "schießt wie ein Blitz davon",
    CD_MMSGIN:        "erscheint in einem Lichtblitz",
    CD_DIE_MSG:       " verschwindet in einem Lichtblitz.\n",
    CD_IDS:           ({"lichtdämon","lichtdaemon"}),
    CD_SAY:           "@WER1 beschwört unheimliche Kräfte und öffnet "
                      "ein Tor in andere Welten.",
  ]),
  "feuerdaemon": ([
    CD_NAME:          "Feuerdämon",
    CD_NAME_W:        "Feuerdämonin",
    CD_BEIWORT:       "rasende",
    CD_TITEL:         ({"Ignis","Ignas","Ignal","Ignur","Ignasur"}),
    CD_STUFE:         9,
    CD_KOSTEN:        90,
    CD_SCHWIERIGKEIT: 50,
    CD_PAUSE:         15,
    CD_GUT_LERNEN:    200,
    CD_GUT_BENUTZEN:  -250,
    CD_KAMPF:         1,
    CD_FAKTOREN:      ({20,15,20,25}),
    CD_ABFANGEN:      60,
    CD_RUNDEN:        4,
    CD_POWER:         1,
    CD_NPC_LEVEL:     12,
    CD_NPC_HP:        300,
    CD_PROZENT:       70,
    CD_HANDS:         ({" mit flammenden Krallen",180,({DT_FIRE,DT_RIP})}),
    CD_BODY:          100,
    CD_SIZE:          213,
    CD_WEIGHT:        120000,
    CD_ALIGN:         -100,
    CD_LIGHT:         2,
    CD_RESISTANCE:    ([DT_FIRE:-1.0,DT_WATER:1.0,DT_DARKNESS:-0.3,
                        DT_LIGHT:0.3]),
    CD_MATERIAL:      ([MAT_LIVING:80,MAT_FIRE:10,MAT_MAGIC_BLACK:10]),
    CD_LONG:          "@NAME ist @ART, gar flammig. Die lodernde Gestalt "
                      "leuchtet grell, züngelnde Flammen lassen die "
                      "Formen verschwimmen, und heißer Atem steigt aus "
                      "den Nüstern.",
    CD_MSGIN:         "erscheint in einem Meer aus Flammen",
    CD_MSGOUT:        "lodert flammend davon",
    CD_MMSGIN:        "erscheint in einem Meer aus Flammen",
    CD_DIE_MSG:       " verschwindet in einer Feuerexplosion.\n",
    CD_IDS:           ({"feuerdämon","feuerdaemon"}),
    CD_SAY:           "@WER1 spricht magische Worte, die zusammen mit "
                      "abartigen Gesten einen wilden, gefährlichen "
                      "Dämon aus den Tiefen der niederen Dimensionen "
                      "rufen.",
  ]),
  "saeuredaemon": ([
    CD_NAME:          "Säuredämon",
    CD_NAME_W:        "Säuredämonin",
    CD_BEIWORT:       "ätzende",
    CD_TITEL:         ({"asir","asus","asure","asar","asis"}),
    CD_STUFE:         10,
    CD_KOSTEN:        120,
    CD_SCHWIERIGKEIT: 80,
    CD_PAUSE:         20,
    CD_GUT_LERNEN:    -100,
    CD_GUT_BENUTZEN:  -300,
    CD_KAMPF:         1,
    CD_FAKTOREN:      ({30,20,25,35}),
    CD_ABFANGEN:      50,
    CD_FOLGEZEIT:     ({300,300}),
    CD_BLEIBT:        1,
    CD_POWER:         1,
    CD_NPC_LEVEL:     18,
    CD_NPC_HP:        360,
    CD_PROZENT:       80,
    CD_ATTRIBUTE:     ([A_STR:22,A_DEX:22,A_INT:22,A_CON:22]),
    CD_HANDS:         ({" mit ätzenden Krallen",180,({DT_ACID,DT_RIP})}),
    CD_BODY:          90,
    CD_SIZE:          253,
    CD_WEIGHT:        140000,
    CD_ALIGN:         -150,
    CD_RESISTANCE:    ([DT_ACID:-0.9,DT_WATER:0.8,DT_LIGHT:0.3,
                        DT_DARKNESS:-0.3]),
    CD_MATERIAL:      ([MAT_ACID:80,MAT_SLIME:10,MAT_MAGIC_BLACK:10]),
    CD_LONG:          "@NAME ist @ART und kommt länger als die "
                      "Artgenossen ohne Bad in einem Säuresee aus, denn "
                      "eine dicke Schleimschicht schützt die Haut. Wie "
                      "bei allen Säuredämonen gilt: niemals knuddeln!",
    CD_MSGIN:         "schleimt ätzend herein",
    CD_MSGOUT:        "schleimt ätzend davon",
    CD_MMSGIN:        "erscheint in einem Säureregen",
    CD_DIE_MSG:       " verschwindet brodelnd im Erdreich.\n",
    CD_IDS:           ({"säuredämon","saeuredaemon"}),
    CD_SAY:           "@WER1 murmelt ein unheimliches Wort und beginnt "
                      "sofort mit einem abartigen Tanz, dessen wilde "
                      "Gesten geradezu obszön sind.",
  ]),
  "blutdaemon": ([
    CD_NAME:          "Blutdämon",
    CD_NAME_W:        "Blutdämonin",
    CD_BEIWORT:       "blutgierige",
    CD_TITEL:         ({"Sangus","Cruor","Sanguir","Haemor","Cruentis"}),
    CD_STUFE:         11,
    CD_KOSTEN:        140,
    CD_SCHWIERIGKEIT: 100,
    CD_PAUSE:         30,
    CD_GUT_LERNEN:    -500,
    CD_GUT_BENUTZEN:  -300,
    CD_KAMPF:         1,
    CD_MIN_PENTA:     ({21,11}),
    CD_FAKTOREN:      ({35,25,30,45}),
    CD_ABFANGEN:      30,
    CD_FOLGEZEIT:     ({1000,500}),
    CD_BLEIBT:        1,
    CD_POWER:         1,
    CD_NPC_LEVEL:     22,
    CD_NPC_HP:        400,
    CD_PROZENT:       90,
    CD_ATTRIBUTE:     ([A_STR:25,A_DEX:25,A_INT:25,A_CON:25]),
    CD_HANDS:         ({" mit Reißzähnen und Krallen",200,
                        ({DT_SLASH,DT_RIP})}),
    CD_BODY:          120,
    CD_SIZE:          219,
    CD_WEIGHT:        130000,
    CD_ALIGN:         -200,
    CD_RESISTANCE:    ([DT_SLASH:-1.5,DT_LIGHT:0.3,DT_DARKNESS:-0.3]),
    CD_LONG:          "@NAME ist @ART, finster und böse dreinblickend. "
                      "Blutdämonen sind selten, ihre unglaubliche Gier "
                      "nach Blut gab ihnen den Namen. Lange Reißzähne "
                      "und spitze Klauen sind die Werkzeuge dieser Sucht "
                      "nach dem roten Saft des Lebens.",
    CD_MSGIN:         "schleicht blutgierig herein",
    CD_MSGOUT:        "wittert Blut und schleicht davon",
    CD_MMSGIN:        "entsteigt den finstersten Dämonendimensionen",
    CD_DIE_MSG:       " bildet einen großen Blutfleck.\n",
    CD_IDS:           ({"blutdämon","blutdaemon"}),
    CD_SAY:           "@WER1 fuchtelt wie wild mit den Armen herum, "
                      "stößt bösartige Worte einer magischen Sprache "
                      "hervor und vollführt einen seltsamen Tanz.",
  ]),
  "wandler": ([
    CD_NAME:          "Wandler",
    CD_NAME_W:        "Wandlerin",
    CD_BEIWORT:       "unheimliche",
    CD_TITEL:         ({"Mutar","Variel","Proteon","Metamor","Versus"}),
    CD_STUFE:         12,
    CD_KOSTEN:        180,
    CD_SCHWIERIGKEIT: 150,
    CD_PAUSE:         60,
    CD_GUT_LERNEN:    -700,
    CD_GUT_BENUTZEN:  -300,
    CD_KAMPF:         1,
    CD_ERZMEISTER:    1,
    CD_MIN_PENTA:     ({22,12}),
    CD_FAKTOREN:      ({45,35,35,55}),
    CD_ABFANGEN:      15,
    CD_FOLGEZEIT:     ({2000,500}),
    CD_BLEIBT:        1,
    CD_POWER:         1,
    CD_NPC_LEVEL:     25,
    CD_NPC_HP:        600,
    CD_PROZENT:       100,
    CD_ATTRIBUTE:     ([A_STR:27,A_DEX:27,A_INT:27,A_CON:27]),
    CD_HANDS:         ({" mit Eisklauen",260,({DT_COLD,DT_RIP})}),
    CD_BODY:          195,
    CD_SIZE:          156,
    CD_WEIGHT:        90000,
    CD_ALIGN:         -200,
    CD_LONG:          "@NAME ist @ART und kann die eigene Gestalt beliebig "
                      "verändern und sich so auf die Gegner einstellen. "
                      "Mal in tosende Flammen gehüllt, mal kalt wie Eis "
                      "- das muss man allerdings erst befehlen!",
    CD_MSGIN:         "wandelt herein",
    CD_MSGOUT:        "wandelt davon",
    CD_MMSGIN:        "schaut mal eben vorbei",
    CD_DIE_MSG:       " beendet seine Daseinsform.\n",
    CD_IDS:           ({"wandler","wandlerdämon","wandlerdaemon"}),
    CD_SAY:           "@WER1 fuchtelt wie wild mit den Armen herum, "
                      "stößt bösartige Worte einer magischen Sprache "
                      "hervor und vollführt einen seltsamen Tanz.",
  ]),
]);

// Werte eines Typs, 0 wenn es ihn nicht gibt
public mapping QueryTyp(string typ) {
  return typen[typ] ? deep_copy(typen[typ]) : 0;
}

// Alle Typen, nach Gildenstufe sortiert
public string *QueryTypen() {
  return sort_array(m_indices(typen),
    function int (string a, string b) {
      return typen[a][CD_STUFE] > typen[b][CD_STUFE];
    });
}

// Typ zu einer Spielereingabe (schon in ASCII), z.B. "feuer",
// "feuerdaemon" oder "feuerdaemonin"
public string FindeTyp(string str) {
  if(!stringp(str)) {
    return 0;
  }
  str = lower_case(str);

  foreach(string typ : typen) {
    string kurz = regreplace(typ,"daemon$","",0);

    if(str == typ || str == typ+"in" || str == kurz) {
      return typ;
    }
  }
  return 0;
}
