// wirt.c - Krummbart, der Wirt der Schänke »Zum schiefen Pentagramm«
//
// Ohne ihn wird in der Schänke nichts ausgeschenkt (P_PUB_KEEPER).
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
  create_default_npc(18,450);

  SetProp(P_NAME,"Krummbart");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_SHORT,"Krummbart, der Wirt");
  SetProp(P_LONG,
  "Krummbart ist ein dicker, rußverschmierter Chaot mit einem Bart, der "
  "in drei Richtungen gleichzeitig wächst. Seine Schürze hat mehr "
  "Brandlöcher als Stoff, und auf seinem Unterarm ist ein schiefes "
  "Pentagramm tätowiert. Er wischt mit einem Lappen über den Tresen und "
  "macht ihn dabei eher schmutziger.");
  SetProp(P_HANDS,({" mit seinen Pranken",180,({DT_BLUDGEON})}));
  SetProp(P_SIZE,185);
  AddId(({"krummbart","wirt",CHAOS_ID_WIRT}));
  AddAdjective(({"dick","dicken","russverschmiert","russverschmierten"}));

  AddDetail(({"bart"}),
  "Er wächst in drei Richtungen. Mindestens.");
  AddDetail(({"schuerze","schürze","brandloecher","brandlöcher"}),
  "Mehr Loch als Schürze.");
  AddDetail(({"unterarm","pentagramm","taetowierung","tätowierung"}),
  "Ein schiefes Pentagramm. Wie das Schild über der Tür.");
  AddDetail(({"lappen"}),
  "Grau und speckig.");

  bewohner_geld(60+random(60));
  AddWeapon(POOL_WEAPON_CLUB "keule_klein",REFRESH_REMOVE|CLONE_WIELD);

  SetChats(8,({
    "Krummbart wischt mit einem speckigen Lappen ueber den Tresen.\n",
    "Krummbart brummt: Wer nicht trinkt, steht im Weg.\n",
    "Krummbart schnauzt einen kleinen Daemon an, der hinter dem Tresen "
    "Glaeser spuelt.\n",
    "Krummbart kratzt sich am Bart. Er findet darin einen Korken.\n",
    "Krummbart murmelt: Anschreiben gibt's nicht. Fuer niemanden.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Willst du was trinken oder nur reden?",
    "Keine Ahnung. Lies die Speisekarte.",
    "Frag jemand anderen, ich hab zu tun.",
  }),"brummt: ");

  AddInfo(({"speisekarte","karte","essen","trinken"}),
  "Hängt über dem Tresen. Lesen musst du schon selbst.","brummt: ");

  AddInfo(({"chaos-becher","becher","chaosbecher"}),
  "Mein bester Trunk. Chaoten tut er gut. Allen anderen tut er weh. "
  "Sag nachher nicht, ich hätte dich nicht gewarnt.","grinst: ");

  AddInfo(({"riss-schnaps","schnaps"}),
  "Gebrannt aus etwas, das am Riss wächst. Klärt den Kopf. Meistens.",
  "sagt: ");

  AddInfo(({"schwefelsuppe","suppe"}),
  "Schmorbold kocht sie. Stinkt, macht aber satt.","sagt: ");

  AddInfo(({"kerkerbrot","brot"}),
  "Hart, grau, billig. Wie das Leben.","brummt: ");

  AddInfo(({"wasser","leitungswasser"}),
  "Aus dem Brunnen. Ich würd's nicht trinken.","sagt: ");

  AddInfo(({"anschreiben","schulden"}),
  "Gibt's nicht. Für niemanden. Nicht mal für Erzmeister, egal was der "
  "Zettel sagt.","schnauzt: ");

  AddInfo(({"daemon","dämon","spueldaemon","spüldämon","glaeser",
            "gläser"}),
  "Der Kleine spült, weil er beim letzten Mal den Tresen angezündet hat. "
  "Strafarbeit.","sagt: ");

  AddInfo(({"krummbart"}),
  "Das bin ich. Und das hier ist meine Schänke.","sagt: ");

  AddInfo(({"schmorbold","koch"}),
  "Der Koch. Steht in der Küche im Hauptgebäude und kocht mit Schwefel.",
  "sagt: ");
}
