// bewohner.c - Std für die Bewohner der Burg Zwielichtstein
//
// Chaoten (und ein paar andere), die in der Burg wohnen. Alle sind
// angreifbar. Gemeinsam sind ihnen die Auskünfte über Burg und Gilde;
// eigene Infos setzt jeder NPC nach ::create() selbst.
//
// bewohner_geld(n): ein paar Kreuzer als Beute
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma no_clone

#include "def.h"

inherit "/std/npc";

// Ein paar Kreuzer, die man dem Bewohner abnehmen kann
protected void bewohner_geld(int n) {
  AddItem("/obj/currency/kreuzer",REFRESH_REMOVE,([P_AMOUNT: n]));
}

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();

  SetProp(P_RACE,"Mensch");
  SetProp(P_GUILD,"chaos");
  SetProp(P_ALIGN,-200);
  SetProp(P_SIZE,170+random(25));
  AddClass(({CL_HUMAN,CL_WALKING,CL_SKIN,CL_HAIR,CL_BREATH_AIR}));
  AddId(({"chaot","bewohner"}));

  AddInfo(({"burg","zwielichtstein","burg zwielichtstein","ruine"}),
  "Unsere Burg. Gut, sie fällt auseinander. Aber sie gehört uns, und "
  "keiner will sie uns wegnehmen.","sagt: ");

  AddInfo(({"chaos","gilde","chaoten","chaosgilde"}),
  "Die Gilde des Chaos. Wer beitreten will, muss in die Gildenhalle "
  "hinter dem Rittersaal.","sagt: ");

  AddInfo(({"gildenhalle","rittersaal"}),
  "Geh durch das Portal und dann immer geradeaus nach Osten. Durch den "
  "Rittersaal durch, dahinter ist die Gildenhalle.","sagt: ");

  AddInfo(({"riss","turm"}),
  "Der Turm steht im Nordosten auf dem Platz, ganz oben ist der Riss. "
  "Dort gelingen die Beschwörungen am besten. Und dort gehen sie am "
  "schönsten schief.","grinst: ");

  AddInfo(({"schaenke","schänke","kneipe","wirt","krummbart"}),
  "Die Schänke ist im alten Gesindehaus am Platz. Krummbart schenkt aus. "
  "Probier den Chaos-Becher, wenn du dich traust.","sagt: ");

  AddInfo(({"laden","achtarch","haendler","händler"}),
  "Achtarch hat seinen Laden in der alten Werkstatt am Platz. Kreide, "
  "Kerzen, Fackeln, alles, was man so braucht. Zu Wucherpreisen.",
  "sagt: ");

  AddInfo(({"kruuolq","meister"}),
  "Kruuolq ist der oberste Meister. Er wohnt oben im Gemach und will "
  "nicht gestört werden. Also stört ihn jeder.","kichert: ");

  AddInfo(({"hutschat","verwalter"}),
  "Hutschat verwaltet die Gilde. Und den Topf in der Vorratskammer.",
  "sagt: ");

  AddInfo(({"daemon","dämon","daemonen","dämonen"}),
  "Beschwören ist leicht. Wieder loswerden ist schwer. Und einfangen ist "
  "noch schwerer.","seufzt: ");
}
