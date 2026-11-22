#include "/gilden/files.chaos/gilde.h"
#include <moving.h>

inherit "/std/room";


create() {
  ::create();
  AddCmd(({"unten"}),"sink_in");
}

int sink_in(string whut) {
  object o;
  
  say(this_player()->Name(WER)+" hebt beschwoernd die Haende.\n",
      this_player());
  
  if (!QueryProp("chaos_sink_room"))
    return write("Es will einfach nicht gehen! Bug!\n"),1;
  if (!(o=present("\nchaos_ruestung",this_player())))
    return write("Dir fehlt die noetige Kraft ohne eine Chaosruestung.\n"),1;
  if (o->QueryProp(DAEM_FALSE))
    return write("Deine Chaosruestung behindert Dich zu sehr.\n"),1;
  
  write("Du beschwoerst ureigenste chaotische Energien.\n"+
        "Du versinkst.\n");
  say("Die Steine oeffnen sich fuer "+this_player()->name(WEN)+".\n",
      this_player());
  this_player()->move(QueryProp("chaos_sink_room"),M_GO,"im Boden",
  "versinkt","sinkt durch die Decke");
  return 1;
}
 