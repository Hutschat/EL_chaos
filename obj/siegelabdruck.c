// siegelabdruck.c - Abdruck des Siegelrings der Chaoten
//
// Letzte Aenderung:
//
// 12.03.2019 It@Efferdland            ueberarbeitet

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/thing";

static int resets = 3;

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT, 0);
  SetProp(P_NAME,  0);
  SetProp(P_GENDER,0);

  AddId(({"\nchaos_siegelabdruck"}));
  SetProp(P_WEIGHT, 0);
  SetProp(P_NEVERDROP,1);
}

string extra_look()
{
  string str;

  if (!environment()) return "";

  if (!query_once_interactive(environment()))
    str = environment()->Name(WER,1);

  else
    str = capitalize(getuid(environment()));

  return str+" hat einen Abdruck in Form eines Totenkopfs in der Stirn.\n";
}

void reset()
{
  resets--;

  if (resets)
  {
    ::reset();
    return;
  }
  if (!environment())
    return;

  tell_object(environment(),"Der Abdruck auf Deiner Stirn "
                            "verschwindet.\n");
  remove();
}
