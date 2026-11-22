#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit "/std/room";

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"leer");
  SetProp(P_INT_LONG,BS("Dieser Raum ist noch nicht fertig. Lass Dich "+
  "Rausteleportieren."));
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
}
