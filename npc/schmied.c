// schmied.c - Klonk, der Schmied der Burg Zwielichtstein
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit CHAOS_GILDEN_MON("std/bewohner");

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(16,400);

  SetProp(P_NAME,"Klonk");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_SHORT,"Klonk, der Schmied");
  SetProp(P_LONG,
  "Klonk ist ein breitschultriger Chaot mit Armen wie Baumstämme und "
  "einer Lederschürze voller violetter Flecken. Er schlägt auf das Ding "
  "auf dem Amboss ein und betrachtet es dann mit gerunzelter Stirn, als "
  "wäre er selbst nicht sicher, was es werden soll.");
  SetProp(P_HANDS,({" mit seinen schwieligen Fäusten",170,({DT_BLUDGEON})}));
  SetProp(P_SIZE,190);
  AddId(({"klonk","schmied",CHAOS_ID_SCHMIED}));
  AddAdjective(({"breitschultrig","breitschultrigen"}));

  AddDetail(({"arme","baumstaemme","baumstämme"}),
  "Dick und voller Brandnarben.");
  AddDetail(({"lederschuerze","lederschürze","schuerze","schürze",
              "flecken"}),
  "Dickes Leder, violett gesprenkelt.");

  bewohner_geld(40+random(40));
  AddWeapon(POOL_WEAPON_HATCHET "beil",REFRESH_REMOVE|CLONE_WIELD);

  SetChats(8,({
    "Klonk schlaegt auf das Ding auf dem Amboss ein. Klong!\n",
    "Klonk haelt das Ding hoch, dreht es hin und her und zuckt die "
    "Schultern.\n",
    "Klonk murmelt: Vielleicht wird's ja ein Kochloeffel.\n",
    "Klonk wirft eine Handvoll violettes Pulver in die Esse. Es zischt.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Hm.",
    "Frag nicht. Ich schmiede.",
  }),"brummt: ");

  AddInfo(({"ding","schwert","kochloeffel","kochlöffel"}),
  "Es sollte ein Schwert werden. Dann ein Kochlöffel. Jetzt ist es "
  "beides, und keins davon richtig.","brummt: ");

  AddInfo(({"esse","feuer","pulver"}),
  "Chaosfeuer. Wird nicht heiß, aber das Eisen glüht trotzdem. Frag mich "
  "nicht, warum.","sagt: ");

  AddInfo(({"waffe","waffen","schmieden"}),
  "Ich schmiede, was gebraucht wird. Meistens wird's was anderes.",
  "sagt: ");

  AddInfo(({"klonk","schmied"}),
  "Klonk. Wie das Geräusch.","sagt: ");
}
