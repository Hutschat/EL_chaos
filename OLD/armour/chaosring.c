// chaosring.c
//
// Letzte Aenderung:
//
// 11.03.2019 It@Efferdland            neu

inherit "/std/armour";

#include "def.h"

string *metzel_en;
#define METZEL_EN ({ "/d/polar/bendeigid/mon/leronis",\
        "/d/polar/troy/q2p/mon/lofwyr",\
	"/d/gebirge/boing/sm/mon/schlammdrache",\
	"/d/ebene/mon/odrache", "/d/polar/alle/mon/untier",\
	"/d/gebirge/boing/sm/mon/wschamane",\
	"/players/rochus/mon/etwas",\
	"/d/polar/terrorist/npc/lilith" })

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT,"Der Ring des Chaos");
  SetProp(P_LONG, 
  "Diesen Ring musst Du waehrend der Metzel-Master-Quest tragen. Er "
  "besteht aus flackerndem Chaos, das um Deinen Finger tanzt.");
  SetProp(P_NAME,"Chaos-Ring");
  SetProp(P_GENDER,1);
  SetProp(P_AUTOLOADOBJ,1);
  SetProp(P_NODROP,1);
  SetProp(P_MATERIAL,MAT_MAGIC_BLACK);
  SetProp(P_NEVERDROP,1);
  SetProp(P_AC,0);
  SetProp(P_ARMOUR_TYPE,AT_MISC);
  AddId(({"ring","q_obj","\nchaos_metzel_quest_ring","chaos-ring", 
	  "ring des chaos" }));
  SetProp(P_DEFEND_FUNC,ME);
}

int DefendFunc(mixed dam_type, int spell, object enemy)
{
  object ob;
  string fname, bla, blub;

  if(!objectp(enemy))
    return 0;

  if(sscanf(file_name(enemy), "%s#%s", bla, blub) )
    fname = explode(file_name(enemy), "#")[0];
  
  else
    fname=file_name(enemy);
  
  if(member(METZEL_EN, fname)==-1)
    return 0;
  
  if(present("\nchaos_metzel_obj",enemy))
    return 0;
  
  ob = clone_object(CHAOS_GILDEN_OBJ("metz_obj"));
  
  ob->CreateMetzelObject(fname);
  ob->move(enemy);
  return 0;
}
