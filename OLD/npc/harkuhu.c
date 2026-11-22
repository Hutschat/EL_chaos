// harkuhu.c
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
  create_default_npc(5);
  SetProp(P_SHORT,"Harkuhu der Lichtdaemon");
  SetProp(P_LONG,
  "Harkuhu ist ein etwas klein geratener Lichtdaemon mit kurzen "
  "Stummelbeinen, einer gedrungenen Gestalt und etwas schwaechlichen "
  "Armen. Trotzdem hat er die typischen Eigenschaften eines Lichtdaemonen. "
  "Seine schwach leuchtende Haut und die kleinen Blitze, die seinen "
  "Kopf umkreisen sind ein typisches Zeichen seiner Herkunft.");
  SetProp(P_NAME,"Harkuhu");
  SetProp(P_GENDER,1);
  SetProp(P_ARTICLE,MALE);
  SetProp(P_MAX_HP,400);
  SetProp(P_LIGHT,1);
  SetProp(P_HP,800);
  AddMaterial(({MAT_LIGHT}));
  SetProp(P_ALIGN,100);
  SetProp(P_HANDS,({" mit blitzenden Krallen",-200,({DT_LIGHTNING,DT_RIP})}));
  SetProp(P_RESISTANCE,
  ([
    DT_LIGHTNING:-0.9,
    DT_DARKNESS: -0.3,
    DT_LIGHT:     0.3
  ]));
  SetProp(P_MATERIAL,
  ([
    MAT_LIVING:80,
    MAT_LIGHT:10,
    MAT_MAGIC_BLACK:10
  ]));
  
  SetProp(P_BODY,100);
  SetProp(DAEM_PROZENT,60);
  SetProp(P_SIZE,80);
  SetProp(P_WEIGHT,30000);
  SetProp(P_MSGIN, "schiesst wie ein Blitz herein");
  SetProp(P_MSGOUT,"schiesst wie ein Blitz davon" );
  SetProp(P_MMSGIN,"erscheint in einem Lichtblitz"); 
  SetProp(P_NOCORPSE,1);
  SetProp(P_DIE_MSG," verschwindet in einem Lichtblitz.\n");
  SetProp(P_REJECT,({REJECT_GIVE,({ "Harkuhu sagt: ?\n"})}));
  AddId(({"harkuhu","chaos_gilden_daemon","lichtdaemon", 
	"\nkampfdaemon" }));
}

void Attack(object enemy)
{
  if(interactive(enemy))
    SetProp(P_HANDS,({" mit blitzenden Krallen",140,({DT_LIGHTNING,DT_RIP})}));
  return ::Attack(enemy);
}
