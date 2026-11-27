// schreiber.c - Kritzel, der Schreiber der Gilde
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types

#include "def.h"

inherit CHAOS_GILDEN_MON("std/bewohner");

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(6,110);

  SetProp(P_NAME,"Kritzel");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_SHORT,"Kritzel, der Schreiber");
  SetProp(P_LONG,
  "Kritzel ist ein kleiner, kurzsichtiger Chaot mit Tintenflecken bis zu "
  "den Ellbogen. Er sitzt hinter einem Berg Papier und schreibt, "
  "streicht durch und schreibt wieder. Hinter seinem Ohr steckt eine "
  "angekaute Feder.");
  SetProp(P_HANDS,({" mit tintigen Fingern",50,({DT_BLUDGEON})}));
  SetProp(P_SIZE,155);
  AddId(({"kritzel","schreiber",CHAOS_ID_SCHREIBER}));
  AddAdjective(({"kurzsichtig","kurzsichtigen","klein","kleinen"}));

  AddDetail(({"tintenflecken","ellbogen"}),
  "Schwarz und blau, bis zu den Ellbogen.");
  AddDetail(({"feder","ohr"}),
  "Eine angekaute Feder hinter dem Ohr.");

  bewohner_geld(10+random(20));

  SetChats(8,({
    "Kritzel kritzelt etwas auf ein Blatt und streicht es wieder durch.\n",
    "Kritzel seufzt: Schon wieder ein Feuerdaemon verloren.\n",
    "Kritzel sortiert Antraege auf einen neuen Stapel. Der alte faellt "
    "um.\n",
    "Kritzel schiebt sich die Feder hinters Ohr und sucht sie dann.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Hast du einen Antrag? Nein? Dann stör nicht.",
    "Moment, ich muss das erst eintragen.",
  }),"murmelt: ");

  AddInfo(({"liste","verloren","dämon verloren","daemon verloren"}),
  "Wer welchen Dämon verloren hat. Die Liste ist inzwischen länger als "
  "die Mitgliederliste. Die meisten Feuerdämonen landen übrigens im "
  "Verlies.","seufzt: ");

  AddInfo(({"antrag","antraege","anträge","papier","papierkram"}),
  "Anträge auf Beitritt, auf Beschwörungen, auf ein neues Bett. Das mit "
  "dem Bett wird abgelehnt.","sagt: ");

  AddInfo(({"beschwerde","beschwerden"}),
  "Die meisten Beschwerden sind über Krummbarts Schnaps. Oder über "
  "Schmorbolds Suppe.","sagt: ");

  AddInfo(({"kritzel","schreiber"}),
  "Ich halte hier die Ordnung aufrecht. Jemand muss es ja tun.","sagt: ");
}
