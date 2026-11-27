// rythoth.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 11.03.2019 It@Efferdland            ueberarbeitet

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
  create_default_npc(20,300);
  SetProp(P_SHORT, "Der Hetzerdaemon Rythoth" );
  SetProp(P_LONG,
  "Rythoth ist ein Hetzerdaemon, der gnadenlos seine Opfer jagt und meistens "
  "auch faengt. Auf seinen staemmigen Beinen kann er sich schnell bewegen "
  "und mit einem nach vorne gebeugten Koerper, die Nase dicht am Boden, "
  "nimmt er jede Spur auf. Dabei schlurfen seine ueberlangen Arme mit den "
  "krallenbewehrten Fingern ueber den Boden und geben ein kratzendes Graeusch "
  "von sich.");
  SetProp(P_NAME, "Rythoth");
  SetProp(P_GENDER, MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_XP, 0);
  SetProp(P_ALIGN, -200);
  SetProp(P_HANDS, ({" mit blossen Klauen", 200,DT_RIP }));
  SetProp(P_BODY, 170);
  SetProp(P_MMSGIN,  "kriecht die Arme hinter sich herziehend herein" );
  SetProp(P_MSGIN,   "kriecht die Arme hinter sich herziehend herein" );
  SetProp(P_MSGOUT,  "kriecht davon, was Dir nur Recht sein kann" );
  SetProp(P_DIE_MSG, " verschwindet mit Knall und Schwefelduft.\n");
  SetProp(P_NOCORPSE, 1);
  SetProp(P_SIZE, 160);
  SetProp(P_WEIGHT,100000);
  SetProp(P_RESISTANCE,
  ([
    DT_LIGHTNING:-0.4,
    DT_WATER:    -0.4, 
    DT_FIRE:     -0.4, 
    DT_LIGHT:     0.3,
    DT_DARKNESS: -0.3, 
    DT_POISON:    0.3
  ]));
  SetProp(AGG_CHANCE, 10);
  SetProp(DAEM_HUNTING_TIME, 16);
  AddId(({ "rythoth", "hetzerdaemon", "daemon" }));
}
