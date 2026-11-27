// koch.c - Schmorbold, der Koch der Burg Zwielichtstein
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
  create_default_npc(12,260);

  SetProp(P_NAME,"Schmorbold");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_SHORT,"Schmorbold, der Koch");
  SetProp(P_LONG,
  "Schmorbold ist ein hagerer Chaot mit fleckiger Kochmütze und "
  "Augenbrauen, die eindeutig schon einmal abgebrannt sind. Er rührt in "
  "seinem Kessel, schnuppert, verzieht das Gesicht und rührt weiter. In "
  "der anderen Hand hält er ein großes Messer.");
  SetProp(P_HANDS,({" mit seinen rußigen Händen",110,({DT_BLUDGEON})}));
  AddId(({"schmorbold","koch",CHAOS_ID_KOCH}));
  AddAdjective(({"hager","hageren"}));

  AddDetail(({"kochmuetze","kochmütze","muetze","mütze"}),
  "Einmal war sie weiß.");
  AddDetail(({"augenbrauen"}),
  "Stoppelig nachgewachsen.");

  bewohner_geld(20+random(30));
  AddWeapon(POOL_WEAPON_KNIFE "fleischer_messer",REFRESH_REMOVE|CLONE_WIELD);

  SetChats(8,({
    "Schmorbold ruehrt im Kessel und murmelt: Noch ein bisschen Schwefel.\n",
    "Schmorbold schnuppert am Kessel und verzieht das Gesicht.\n",
    "Schmorbold haut mit dem Loeffel auf einen Tentakel, der aus dem "
    "Kessel greift.\n",
    "Schmorbold stapelt noch einen Teller auf einen Geschirrturm.\n",
    "Schmorbold blaettert im Kochbuch und flucht leise.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Hm? Ich koche gerade.",
    "Keine Zeit, die Suppe brennt an.",
  }),"murmelt: ");

  AddInfo(({"essen","kessel","suppe","schwefelsuppe"}),
  "Schwefelsuppe. Das Geheimnis ist der Schwefel. Und dass man nicht zu "
  "genau hinschaut.","sagt: ");

  AddInfo(({"kochbuch","schwefel"}),
  "»Kochen mit Schwefel«. Ein Klassiker. Seite zwölf ist leider "
  "verbrannt.","sagt: ");

  AddInfo(({"tentakel"}),
  "Der gehört nicht in die Suppe. Er will aber nicht wieder raus.",
  "seufzt: ");

  AddInfo(({"geschirr","abwasch","spuelen","spülen"}),
  "Wird gespült, wenn keine Teller mehr da sind. Also bald.","sagt: ");

  AddInfo(({"schmorbold","koch"}),
  "Das bin ich. Bester Koch der Burg. Einziger Koch der Burg.","sagt: ");
}
