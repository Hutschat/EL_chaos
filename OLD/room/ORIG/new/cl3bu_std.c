#include "/gilden/files.chaos/gilde.h"
#include <moving.h>

inherit "/std/room";


create() {
  ::create();
  AddCmd(({"oben"}),"up_up");
}

int up_up(string whut) {
  object o;
  
  say(this_player()->Name(WER)+" hebt beschwoernd die Haende.\n",
      this_player());
  
  if (!QueryProp("chaos_float_room"))
    return write("Es will einfach nicht gehen! Bug!\n"),1;
  if (!(o=present("\nchaos_ruestung",this_player())))
    return write("Dir fehlt die noetige Kraft ohne eine Chaosruestung.\n"),1;
  if (o->QueryProp(DAEM_FALSE))
    return write("Deine Chaosruestung behindert Dich zu sehr.\n"),1;
  
  write("Du beschwoerst ureigenste chaotische Energien.\n"+
  "Die Chaosruestung durchflutet Dich, verwandelt Dich, verfluechtigt Dich.\n"+
  "Als grauer Nebel dringst Du durch die Decke ueber Dir.\n");
  
  say(this_player()->name(WER)+" verfluechtigt sich zu grauem Nebel, der durch die Decke verschwindet.\n",
      this_player());
  this_player()->move(QueryProp("chaos_float_room"),M_GO | M_SILENT);
  tell_room(environment(this_player()),
  break_string("Ein grauer Nebel steigt von den "+
  "Steinen auf und verwandelt sich in "+this_player()->Name(WER),78),
  ({this_player()}));
  return 1;
}
 