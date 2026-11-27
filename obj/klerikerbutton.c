// klerikerbutton.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Bierchen@MorgenGrauen    neu
// 11.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit

#include "def.h"

inherit "std/armour";
 
protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_NAME, "'Kleriker sind Weicheier' Button");
  SetProp(P_GENDER, MALE);
  SetProp(P_SHORT,"Ein 'Kleriker sind Weicheier'-Button");
  SetProp(P_LONG, 
  "Dieser Button, ein Spezial-Import von Achtarch, nebenbei sei gesagt, dass "
  "er einst einem Kleriker gehoerte, der ein echtes Weichei war, sieht "
  "absolut billig aus. Wie allgemein bekannt sein duerfte, haben Kleriker eine "
  "aeusserst geringe Lebenserwartung, so dass Achtarch diese Buttons in "
  "grossen Mengen (und daher ziemlich kostenguenstig) aufkaufen konnte. "
  "Diesen Preisvorteil gibt er nun an seine Kunden weiter. Du kannst diesen "
  "Button doch tatsaechlich druecken, toll, was? :)");
   AddId("button");
   AddId("klerikerbutton");
   SetProp(P_WEIGHT,10);
   SetProp(P_SIZE,5);
   SetProp(P_MATERIAL,
   ([
     MAT_PAPER:20, 
     MAT_WOOD:40,
     MAT_SHIT:40
   ]));
   SetProp(P_BUY_VALUE,1);
   SetProp(P_AC,-1);
   SetProp(P_ARMOUR_TYPE,AT_MISC);
   SetProp(P_SHOW_INV,1);
   AddCmd(({"druecke","drueck"}),"druecken_act");
}

static druecken_act(string str) {
  if(environment(ME) != PL) {
    return 0;
  }
  notify_fail("Was willst Du denn druecken?\n");

  if(!str) {
    return 0;
  }
  if(id(str)) {
    if(PL->QueryProp(P_GUILD) != "klerus") {
      write("Du drueckst Deinen Button. Args, das scheiss Teil reagiert "
            "nicht auf Dich!\n");

      say(PL->Name(WER,1)+" drueckt einen Button. Nichts geschieht.\n");
      return 1;
    }
    if(PL->QueryProp(P_SP)<=10) {
      write(break_string("Fuer diesen Button fehlt Dir die noetige Magie."));
      return 1;
    }
    write(break_string("Du drueckst Deinen Button."));

    PL->SetProp(P_SP,PL->QueryProp(P_SP)-10);

    write("Du rufst: Kleriker sind WEICHEIER!\n");
    
    shout(capitalize(getuid(PL))+" ruft: Ich bin ein Weichei!!!\n");
    return 1;
  }  
  return 0;
}
