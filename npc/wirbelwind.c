// wirbelwind.c
//
// Letzte Aenderung:
//
// 12.03.2019 It@Efferdland            ueberarbeitet

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/npc";

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(3);
  SetProp(P_SHORT, "Ein Wirbelwind");
  SetProp(P_LONG,  "Wow, ein Wirbelwind.");
  SetProp(P_NAME, "Wirbelwind");
  SetProp(P_GENDER,MALE);
  SetProp(P_INFO,"Das issn Wirbelwind.\n");
  SetProp(P_RACE,CL_FREAK);
  SetProp(P_HANDS,({" wirbelig",60,DT_AIR}));
  SetProp(P_ALIGN,0);
  SetProp(P_CLASS,({CL_FREAK}));
  SetProp(P_MATERIAL,([ MAT_AIR: 100 ]));
  SetProp(P_AGGRESSIVE, 0);
  SetProp(P_NOCORPSE, 1);
  SetProp(P_SIZE, 80);
  SetProp(P_WEIGHT,1);
  SetProp(P_DIE_MSG, " verweht.\n");
  SetProp(P_REJECT, ({REJECT_DROP, "Das geht nicht.\n"}));
  SetProp(P_MSGIN,"wirbelt herein");
  SetProp(P_MSGOUT,"wirbelt");
  SetProp(P_RESISTANCE,
  ([
    DT_AIR: -1.0,
  ]));
  SetProp(P_NO_ATTACK,"Das issn Wirbelwind, Du Idiot.\n");
  AddId(({"\nwirbelwind","wirbelwind"}));
  AddInfo(DEFAULT_INFO, "wirbelt nur rum.\n");
}
