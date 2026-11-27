// lehrling.c - Ein Chaoslehrling, der durch die Burg Zwielichtstein läuft
//
// Läuft herum (mnpc), streitet sich, verliert Dämonen.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"
#include <npc/mnpc.h>

inherit CHAOS_GILDEN_MON("std/bewohner");

protected void create() {
  string *adj = ({"verkohlt","zerzaust","nervös","grinsend"});
  string *lang = ({
    "Seine Robe ist an mehreren Stellen verkohlt, die Haare stehen ab.",
    "Seine Haare sehen aus, als wäre ein Blitz hineingefahren. "
    "Vermutlich ist einer.",
    "Er schaut sich ständig um, als würde ihn etwas verfolgen.",
    "Er grinst, als hätte er gerade etwas angestellt.",
  });
  int i;

  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(8,140);

  i = random(sizeof(adj));

  SetProp(P_NAME,"Chaoslehrling");
  SetProp(P_GENDER,MALE);
  SetProp(P_NAME_ADJ,adj[i]);
  SetProp(P_SHORT,"Ein "+adj[i]+"er Chaoslehrling");
  SetProp(P_LONG,
  "Ein junger Chaot, der die Kunst der Beschwörung noch lernt. Man sieht "
  "es ihm an. "+lang[i]);
  SetProp(P_HANDS,({" mit seinen Fäusten",80,({DT_BLUDGEON})}));
  AddId(({"lehrling","chaoslehrling",CHAOS_ID_LEHRLING}));
  AddAdjective(({"jung","jungen"}));

  bewohner_geld(5+random(20));
  AddWeapon(POOL_WEAPON_KNIFE "dolch",REFRESH_REMOVE|CLONE_WIELD);
  if(!random(2)) {
    AddItem(POOL_KOMPOS "CHAOS_kreide",REFRESH_REMOVE);
  }

  SetProp(P_MNPC_AREA,CHAOS_GILDE("room/"));
  SetProp(P_MNPC_AREA_EXCLUDE,({
    CHAOS_GILDE("room/[+010+053+1"),  // Turmspitze und Riss
  }));
  SetProp(P_MNPC_WALK,1);
  SetProp(P_MNPC_DELAY,40);
  SetProp(P_MNPC_RANDOM,40);
  SetProp(P_MNPC_WALK_IN_FIGHT,0);

  SetChats(6,({
    "Der Chaoslehrling kritzelt ein Pentagramm auf den Boden und wischt "
    "es schnell wieder weg.\n",
    "Der Chaoslehrling ruft: Hat jemand einen kleinen roten Daemon "
    "gesehen?\n",
    "Der Chaoslehrling murmelt eine Beschwoerungsformel und erschrickt, "
    "als es knallt.\n",
    "Der Chaoslehrling schaut unter einen Stein. Kein Daemon.\n",
    "Der Chaoslehrling klopft sich Asche von der Robe.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Weiß ich nicht. Ich bin noch Lehrling.",
    "Frag Kruuolq. Oder lieber nicht.",
    "Hast du meinen Dämon gesehen? Klein, rot, beißt.",
  }),"sagt: ");

  AddInfo(({"lehrling","lernen","beschwoeren","beschwören"}),
  "Ich lerne noch. Das Beschwören klappt schon. Das Zurückschicken "
  "nicht so.","seufzt: ");

  AddInfo(({"roter daemon","roter dämon","belohnung","zettel"}),
  "Er ist mir gestern entwischt. Klein, rot, beißt. Wenn du ihn siehst, "
  "sag Bescheid!","sagt: ");
}
