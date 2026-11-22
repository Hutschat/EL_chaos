
inherit "std/room";

#include <properties.h>
#include <moving.h>
#include <wizlevels.h>
#include <new_skills.h>
#include "/players/zardoz/gilde/chaos.h"


void create()
{
  ::create();
  SetProp( P_INT_SHORT, "Die Gilde der Daemonen");
  SetProp( P_INT_LONG,
  "Die Gilde der Daemonen.\n" );
  AddExit( "", "" );
}

