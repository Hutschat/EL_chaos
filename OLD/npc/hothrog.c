// hothrog.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_MON("std/aggdaem");  

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(17,230);
  SetProp(P_SHORT, "Hothrog der Schakalkoepfige" );
  SetProp(P_LONG,
  "Vor Dir steht Hothrog, der schakalkoepfige Daemon, auf dessen "
  "menschlichem Koerper ein mit aus dem aufgerissenen Maul hervorstehenden "
  "speicheltriefenden Zaehnen bewehrten Schakalkopf sitzt. Seine Klauen "
  "bestehen nur aus zwei krallenbestueckten Fingern, so dass er zwar keine "
  "Waffe benutzen, dafuer aber seinen Gegner zerreissen kann.");

  SetProp(P_NAME, "Hothrog");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE, 0);
  SetProp(P_ALIGN, - 150);
  SetProp(P_HANDS, ({" mit langen Krallen", 170, ({DT_SLASH,DT_RIP}) }));
  SetProp(P_BODY, 160);
  SetProp(P_MMSGIN, "hetzt herein" );
  SetProp(P_MSGIN,  "hetzt blutriechend herein");
  SetProp(P_MSGOUT, "wittert Blut und hetzt davon" );
  SetProp(P_DIE_MSG," beendet seine schaebige Daseinsform.\n");
  SetProp(P_NOCORPSE, 1);
  SetProp(P_SIZE, 165);
  SetProp(P_WEIGHT,60000);
  SetProp(P_RESISTANCE,
  ([
    DT_SLASH:   -0.4,
    DT_PIERCE:  -0.4,
    DT_LIGHT:    0.3, 
    DT_DARKNESS:-0.3
  ]));
  SetProp(AGG_CHANCE, 2);
  SetProp(DAEM_HUNTING_TIME, 22);
  AddId(({"hothrog","schakal","daemonen"}));
}
