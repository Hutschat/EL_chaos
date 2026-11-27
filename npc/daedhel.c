// daedhel.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            init() für neuen Driver

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
  create_default_npc(12,160);
  SetProp(P_SHORT, "Daedhel der elfische Daemon" );
  SetProp(P_LONG,
  "Den Daedhel nennt man auch 'Schatten Elf' und erinnert wirklich an einen "
  "Elfen, denn er war wohl einmal ein Dunkelelf, der sich durch finstere "
  "Maechte in einen Daemonen verwandelt hat. Dies erklaert auch seinen "
  "besonderen Hass gegenueber Elfen, der ihn ohne Sinn und Verstand "
  "angreifen laesst.");
  SetProp(P_NAME, "Daedhel");
  SetProp(P_GENDER, 1);
  SetProp(P_ARTICLE, 0);
  SetProp(P_LIGHT, -1);
  SetProp(P_ALIGN, - 110);
  SetProp(P_HANDS, ({" mit schattenhaften Pranken", 130 }));
  SetProp(P_BODY, 120);
  SetProp(P_MMSGIN, "kriecht aus den Schatten hervor" );
  SetProp(P_MSGIN, "kriecht schattenhaft herein");
  SetProp(P_MSGOUT, "kriecht schattenhaft davon");
  SetProp(P_DIE_MSG, " verschwindet in die Schatten.\n");
  SetProp(P_NOCORPSE, 1);
  AddClass(({
   CL_ELF,
  }));
  SetProp(P_RESISTANCE,
  ([
    DT_COLD:    -0.4,
    DT_POISON:  -0.4,
    DT_AIR:      0.3,
    DT_LIGHT:    0.3,
    DT_DARKNESS:-0.4,
  ]));
  SetProp(P_MATERIAL,
  ([
    MAT_LIVING:60,
    MAT_SHADOW:30,
    MAT_MAGIC_BLACK:10,
  ]));
  SetProp(P_SIZE, 231);
  SetProp(P_WEIGHT,90000);
  SetProp(AGG_CHANCE, 1);
  SetProp(DAEM_HUNTING_TIME, 18);
  AddId(({"daedhel", "schattenelf", "schatten elf","schatten","daemonen" }));
}

public varargs void init(object origin)
{
  if(PL->is_class_memer(CL_ELF) && PL->QueryProp(P_LEVEL) > 5 && 
      !random(5) && PL->QueryProp(P_HP) > 100 ) 
    Kill(PL);
  ::init(origin);
}
