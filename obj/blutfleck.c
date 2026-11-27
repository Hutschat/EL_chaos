// blutfleck.c
//
// Letzte Aenderung:
//
// 11.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit

#include "def.h"

inherit "/std/thing";

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT,"Ein grosser Blutfleck");
  SetProp(P_LONG,
  "Dieser grosse Blutfleck ist das Einzige, was vom grossen Blutdaemon "
  "Tutszt uebrig geblieben ist, als er wieder in seine Daemonen-Dimension "
  "zurueckkehrte. Pass auf, dass Du nicht darauf ausrutschst!");
  SetProp(P_NAME,"Blutfleck" );
  SetProp(P_GENDER,1);
  SetProp(P_NOGET,1);
  SetProp(P_KILL_NAME,"Das Blut eines Daemons");
  SetProp(P_MATERIAL,([
    MAT_BLOOD:95,
    MAT_UNHOLY:5
  ]));
  AddId(({"fleck","blutfleck","blut"}));
  AddId("\nzar_blutfleck");
  AddCmd(({"iss","ess","esse","friss","fresse"}),"essen_act");
  AddCmd(({"trink","trinke","sauf","saufe"}),    "trinken_act");
}

static int trinken_act(string str) {
  notify_fail("Was moechtest Du trinken?\n");

  if(!str) {
    return 0;
  }
  if(id(str)) {
    if(PL->QueryProp(P_GHOST)) {
      write("Das Blut rinnt durch deinen Koerper einfach hindurch.\n");
      return 1;
    }
    say(PL->Name(WER,1)+" kniet sich nieder und trinkt das Blut von dem "
        "Blutfleck.\n",({PL}));
 
    int i = 20+random(20);

    if(PL->QueryProp(P_ALIGN) < -300) {
      write("Du kniest Dich nieder und trinkst das Blut. Uuuuaaaaah! Das tut "
            "gut!\n");
      PL->heal_self(i);
    }
    else {
      write("Wuha! Das war gar nicht gut. Du fuehlst dich elend!\n");
      PL->do_damage(i,ME);
    }
    remove();
    return 1;
  } 
  return 0;
}
    
static int nix_da(string str) {
  notify_fail("Was moechtest Du essen?\n");

  if(!str) {
    return 0;
  }
  if(!id(str)) {
    write("Nene, so wird das nichts, den kann man doch nicht essen!\n");
    return 1;
  }
  return 0;
}
     
protected void reset() {
  if(environment()) {
    tell_room(environment(),"Der Blutfleck versickert im Boden.\n");
  }
  remove();
}
