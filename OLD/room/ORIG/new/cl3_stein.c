#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit "/std/room";

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Im Stein");
  SetProp(P_INT_LONG,BS("Im Stein"));
}

string GetExits() {
  return "";
}

int unt(string was) {
 write("Stein ueberall.\n");
 return 1;
}

init() {
   ::init();
   add_action("unt","untersuch",0);
   add_action("unt","untersuche",0);
   add_action("unt","betr",0);
   add_action("unt","betracht",0);
   add_action("unt","betrachte",0);
   add_action("unt","schau",0);
   add_action("unt","schaue",0);
   add_action("unt","unt",0);

   if (this_player() && query_once_interactive(this_player()))
     call_out("raus",5,this_player());
}

raus(object ob) {
  if (!objectp(ob)) return;

  tell_object(ob,"Du wirst von der Wand wieder ausgespuckt.\n");
  ob->move(CHAOS_GILDEN_ROOM("cl3bu2"),M_GO | M_NO_SHOW,"","",
           "wird ausgespuckt");
}
  
  