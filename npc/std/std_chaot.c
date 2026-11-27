// std_chaot.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 10.12.2018 It@Efferdland            ueberarbeitet

#pragma no_clone
#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/npc";

static int last_heal;

protected void create()
{
  ::create();
  last_heal=time();
  
  AddClass(({
    CL_HUMAN,
    CL_WALKING,
    CL_SKIN,
    CL_HAIR,
    CL_BREATH_AIR
  }));
  
  SetProp(P_RACE,CL_HUMAN);
}

public void check_heal()
{
  if (time()-last_heal>1) 
  {
    ME->heal_self(time()-last_heal);
    last_heal = time();
  }
}

protected void heart_beat()
{
  ::heart_beat();
  last_heal = time();
}
