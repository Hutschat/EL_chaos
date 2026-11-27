// anthukt.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            init() für neuen Driver

#pragma no_inherit
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
  create_default_npc(7,90);
  SetProp(P_SHORT, "Der wuetende Anthukt" );
  SetProp(P_LONG,
  "Der Anthukt ist ein Daemon, der wie eine Mischung aus einer Spinne und "
  "einem Menschen mit Ziegenkopf aussieht. Diese Beschreibung laesst schon "
  "vermuten, dass er mit seiner Existenz nicht gerade gluecklich ist. "
  "Diesen Frust laesst er besonders gerne an Zwergen aus, da diese kleiner "
  "sind als er. ");
  
  SetProp(P_NAME, "Anthukt");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE, 0);
  SetProp(P_ALIGN, - 30);
  SetProp(P_HANDS, ({" mit einigen Spinnenbeinen", 90,DT_WHIP }));
  SetProp(P_BODY, 50);
  SetProp(P_MMSGIN, "krabbelt herein" );
  SetProp(P_MSGIN,  "krabbelt auf seinen Spinnenbeinen herein");
  SetProp(P_MSGOUT, "krabbelt auf seinen Spinnenbeinen davon" );
  
  SetProp(P_DIE_MSG," wickelt sich in ein Spinnennetz ein und verschwindet.\n");
  SetProp(P_NOCORPSE, 1);
  SetProp(P_SIZE, 163);
  SetProp(P_WEIGHT,100000);
  SetProp(AGG_CHANCE, 5);
  SetProp(DAEM_HUNTING_TIME, 14);
  AddId(({"anthukt","spinnenmensch","spinne"}));
}

public varargs void init(object origin)
{
  if(PL->is_class_memer(CL_DWARF) && PL->QueryProp( P_LEVEL) > 5 && 
      !random(5) && PL->QueryProp( P_HP ) > 80 ) 
    Kill(PL);
  ::init(origin);
}
