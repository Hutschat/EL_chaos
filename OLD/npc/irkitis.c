// intarbir.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(15,300);
  SetProp(P_SHORT,capitalize(CHAOS_ID_IRKITIS)+" der wilde Halbdunkeldaemon");
  SetProp(P_LONG,
  capitalize(CHAOS_ID_IRKITIS)+"  ist ein kleiner, aber recht wilder "
  "Halbdunkeldaemon, der ueber seine Brueder in den Kerkern der Daemonenburg "
  "nur spoettisch laechelt.");
  SetProp(P_NAME, capitalize(CHAOS_ID_IRKITIS));
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_ALIGN,-90);
  SetProp(P_HANDS,({" mit klauenhaften Krallen",150,({DT_RIP})}));
  SetProp(P_BODY,120);
  SetProp(P_SIZE,140);
  SetProp(P_WEIGHT,60000);
  SetProp(P_RESISTANCE,
  ([
    DT_DARKNESS: -1.0, 
    DT_LIGHT:     0.4
  ]));
  SetProp(P_MSGIN,  "stolpert wild herein");
  SetProp(P_MSGOUT, "stolpert wild davon");
  SetProp(P_MMSGIN,  "erscheint in einer dunklen Wolke"); 
  SetProp(P_NOCORPSE,1);
  SetProp(P_DIE_MSG, " oeffnet eine unsichtbare Tuer und verschwindet.\n");
  SetProp(P_REJECT,({ REJECT_GIVE, 
    "Irkitis sagt irgendetwas daemonisches.\n" }));
  AddId(({CHAOS_ID_IRKITIS,CHAOS_ID_GILDENDAEMON,"halbdunkeldaemon", 
	  CHAOS_ID_KAMPFDAEMON }));
}
