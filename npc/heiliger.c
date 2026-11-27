// heiliger.c
//
// Letzte Aenderung:
//
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit "/std/npc";

mixed maybe()
{
  if (!objectp(previous_object(2))) 
    return 0;
  
  if (interactive(previous_object(2)))
    return "Doch bitte nicht den armen Kerl.\n";
  return 0;
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(12,50);
  SetProp(P_SHORT, "Ein heiliger Mann");
  SetProp(P_LONG, 
  "Vor Dir steht ein heiliger Mann. Mehr ist nicht zu sagen.");
  AddId(({"mann","heiligermann"}));
  AddAdjective("heilig");
  SetProp(P_NAME_ADJ,"heilig");
  SetProp(P_NAME, "Mann");
  SetProp(P_ARTICLE,1);
  SetProp(P_GENDER,MALE);
  SetProp(P_INFO, break_string("Der Kerl ist heilig!"));
  SetProp(P_RACE,CL_HUMAN);
  SetProp(P_HANDS,({" mit bibelfesten Fingern",100,DT_BLUDGEON}));
  SetProp(P_ALIGN,1500);
  SetProp(P_BODY,0);
  AddClass(({
    CL_HAIR,
    CL_SKIN,
    CL_HUMAN,
    CL_WALKING,
    CL_BREATH_AIR
  }));
  SetProp(P_NOFIRSTKILL,1);
  SetProp(P_XP,1);
  SetProp(P_AGGRESSIVE, 0);
  SetProp(P_NOCORPSE, 0);
  SetProp(P_SIZE, 180);
  SetProp(P_WEIGHT,76000);
  SetProp(P_DIE_MSG, " bricht tot zusammen.\n");

  SetProp(P_REJECT, ({REJECT_DROP, "Der Mann sagt: Das kann ich nicht "
                                   "annehmen.\n"}));

  SetProp(P_MSGIN,"schreitet herein");
  SetProp(P_MSGOUT,"schreitet");
  SetProp(P_RESISTANCE,
  ([
    DT_DARKNESS:2,
  ]));
  AddInfo(DEFAULT_INFO, "betet vor sich hin.\n");
}

void reset()
{
  ::reset();
  if(!is_clone(ME))
    return;
  die();
}
