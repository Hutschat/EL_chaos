// saeurefleck.c
//
// Letzte Aenderung:
//
// 11.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit
#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/thing";

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT,"Eine kleine Saeurepfuetze");
  SetProp(P_LONG,
  "Wow, wo kommt diese kleine Saeurepfuetze her?");
  SetProp(P_NAME,"Saeurepfuetze" );
  SetProp(P_GENDER,FEMALE);
  SetProp(P_NOGET,1);
  SetProp(P_MATERIAL,MAT_ACID);
  AddId(({"pfuetze","saeurepfuetze","saeure"}));
  AddId("\nsaeurefleck");
  AddCmd(({"trink","trinke","sauf","saufe"}),"trinken_act");
}

static int trinken_act(string str) {
  notify_fail("Was moechtest Du trinken?\n");

  if(!str) return 0;

  if(id(str)) {
    if(PL->QueryProp(P_GHOST)) {
      write("Geister haben gar keinen Magen!\n");
      return 1;
    }
    write(break_string("Du kniest Dich nieder und trinkst die Saeure. "
          "Uuuuaaaaah! Das tut nicht gut!"));
  
    say(PL->Name(WER)+" kniet sich nieder und trinkt die Saeure aus der "
        "Saeurepfuetze.\n",({PL}));
  
    if(PL->QueryProp(P_POISON) < 3) {
       PL->SetProp(P_POISON,3);
    }
    remove();
    return 1;
  } 
  return 0;
}
    
protected  void reset() {
  if(environment()) {
    tell_room(environment(),"Die Saeurepfuetze versickert im Boden.\n");
  }
  remove();
}
