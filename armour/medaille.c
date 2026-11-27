// medaille.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 25.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit
#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/armour";

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT,"Die Medaille der Vereinigung der Ladenbesitzer");
  SetProp(P_LONG,
  "Diese Medaille aus Bronze mit der Abbildung eines prall gefuellten "
  "Geldbeutels wird nur den besten und erfolgreichsten Haendlern des "
  "Efferdland verliehen.");
  SetProp(P_NAME,"Medaille der Vereinigung der Ladenbesitzer des "
    "Efferdlands fuer besonders herausragende Leistungen");
  SetProp(P_MATERIAL,MAT_BRONZE);
  SetProp(P_GENDER,2);
  SetProp(P_ARMOUR_TYPE,AT_MISC);
  SetProp(P_AC,0);
  SetProp(P_SIZE,5);
  SetProp(P_WEIGHT,134);
  SetProp(P_BUY_VALUE,78);
  SetProp(P_SELL_VALUE,300);
  AddId(({"medaille","medaille der vereinigung der ladenbesitzer"}));
}
