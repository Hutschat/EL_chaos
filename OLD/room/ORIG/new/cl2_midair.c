#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit "/std/room";

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In der Luft");
}

string GetExits()
{
   return "";
}