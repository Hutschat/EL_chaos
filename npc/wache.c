// wache.c - Gähnulf, die Wache im Keller der Burg Zwielichtstein
//
// Schläft meistens.
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
  create_default_npc(14,320);

  SetProp(P_NAME,"Gähnulf");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_SHORT,"Gähnulf, die Wache");
  SetProp(P_LONG,
  "Gähnulf soll den Keller bewachen. Meistens schläft er dabei, den Kopf "
  "auf dem Tisch und die Hand an seiner Gleve. Sein Helm ist ihm über "
  "die Augen gerutscht, und er murmelt im Schlaf Zahlen.");
  SetProp(P_HANDS,({" mit seinen Fäusten",130,({DT_BLUDGEON})}));
  AddId(({"gaehnulf","gähnulf","wache","waechter","wächter",
          CHAOS_ID_WACHE}));
  AddAdjective(({"schlafend","schlafende","schlafenden"}));

  AddDetail(({"helm","augen"}),
  "Der Helm ist ihm über die Augen gerutscht.");
  AddDetail(({"zahlen"}),
  "Er zählt im Schlaf. Bei elf fängt er wieder von vorn an.");

  bewohner_geld(30+random(30));
  AddWeapon(POOL_WEAPON_POLEARM "gleve",REFRESH_REMOVE|CLONE_WIELD);

  SetChats(6,({
    "Gaehnulf schnarcht.\n",
    "Gaehnulf murmelt im Schlaf: ...neun, zehn, elf... eins...\n",
    "Gaehnulf schreckt hoch, sieht sich um und schlaeft wieder ein.\n",
    "Gaehnulf gaehnt so laut, dass es im Gang widerhallt.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Hrrmpf... wasn? ...schlaf weiter...",
    "Ich wach! Ich bin ganz wach! ...zzz.",
  }),"murmelt: ");

  AddInfo(({"keller","wache","bewachen"}),
  "Ich pass auf, dass nix aus dem Verlies rauskommt. Und dass keiner "
  "den Wein klaut. Der Wein ist trotzdem alle.","gähnt: ");

  AddInfo(({"schluessel","schlüssel","schluesselbund","schlüsselbund"}),
  "Passt nirgends. Aber man weiß ja nie.","murmelt: ");

  AddInfo(({"wuerfel","würfel","sieben"}),
  "Die Würfel zeigen immer Sieben. Deswegen spiel ich nicht mehr.",
  "brummt: ");

  AddInfo(({"verlies","gefangene"}),
  "Da sind die entlaufenen Dämonen drin. Füttern verboten. Wirklich.",
  "sagt: ");

  AddInfo(({"gaehnulf","gähnulf"}),
  "Hm? Ja. Das bin ich. Hab nicht geschlafen.","gähnt: ");
}
