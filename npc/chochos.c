// chaos.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

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
  create_default_npc(9,120);
  SetProp(P_SHORT, "Chochos der schwarze Daemon" );
  SetProp(P_LONG,
  "Chochos ist ein schwarzer Daemon, auch Schatten-Assassine genannt. Er "
  "jagt normalerweise des Nachts seine Opfer und lauert ihnen hinterhaeltig "
  "auf. Seine Gestalt ist nie klar zu erkennen, er scheint keine feste "
  "Form zu besitzen und ist in Schatten unsichtbar. ");

  SetProp(P_NAME, "Chochos");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE, 0);
  SetProp(P_ALIGN, -200);
  SetProp(P_HANDS, ({" meuchlerisch", 110,DT_TERROR }));
  SetProp(P_BODY, 70);
  SetProp(P_MMSGIN, "erscheint urploetzlich aus den Schatten" );
  SetProp(P_MSGIN,  "schleicht leise herein");
  SetProp(P_MSGOUT, "schleicht leise und unauffaellig davon" );
  SetProp(P_DIE_MSG," ist einfach weg.\n");
  SetProp(P_NOCORPSE, 1);
  SetProp(P_MATERIAL,
  ([
    MAT_SHADOW: 90,
    MAT_MAGIC_BLACK:10,
  ]));
  
  SetProp(P_RESISTANCE,
  ([
    DT_SLASH:    -0.4, 
    DT_PIERCE:   -0.4, 
    DT_BLUDGEON: -0.4, 
    DT_LIGHTNING: 0.3,
    DT_LIGHT:     0.3, 
    DT_DARKNESS: -0.3
  ]));
  SetProp(P_SIZE, 194);
  SetProp(P_WEIGHT,85000);
  SetProp(AGG_CHANCE, 5);
  SetProp(DAEM_HUNTING_TIME, 14);
  AddId(({"chochos", "schwarzer daemon", "schwarzen daemonen","daemonen" }));
}
