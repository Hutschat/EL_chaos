#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Vor einem grossen Baum");
  SetProp(P_INT_LONG,BS(
  "Vor Dir steht ein grosser Baum. Bevor der nicht umgefallen ist, "+
  "gehts hier erstmal nicht weiter."));
  AddDetail(({"boden","decke"}),BS("Ist da."));
  AddDetail(({"wand","waende"}),BS("Sind nicht da."));
  AddDetail(({"baum"}),BS("Gross. Bis er weg ist ist hier Schluss."));
  
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl2w7"));
}
