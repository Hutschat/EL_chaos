// tutszt.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet
  
#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

static object caster;

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(22);
  SetProp(P_SHORT, "Tutszt der Blutdaemon" );
  SetProp(P_LONG, 
  "Tutszt ist einer der ganz wenigen Blutdaemonen. Er ist ein finsterer, "
  "boese dreinblickender Daemon, dessen unglaubliche Gier nach Blut ihm "
  "seinen Namen gab. Seine langen Reisszaehne und seine spitzen Klauen "
  "sind die Werkzeuge seiner Sucht nach dem roten Saft des Lebens.");
  SetProp(P_NAME,"Tutszt");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_MAX_HP,400);
  SetProp(P_HP,200);
  SetProp(P_ATTRIBUTES, ([ A_STR:25, A_DEX:25, A_INT:25, A_CON:25 ]));
  SetProp(P_ALIGN,-200);
  SetProp(P_HANDS,({" mit Reisszaehnen und Krallen",200,({DT_SLASH,DT_RIP})}));
  SetProp(P_BODY,120);
  SetProp(DAEM_PROZENT,90);
  SetProp(P_MSGIN,  "schleicht blutgierig herein");
  SetProp(P_MSGOUT, "wittert Blut und schleicht davon" );
  SetProp(P_MMSGIN, "entsteigt den finstersten Daemonendimensionen");
  SetProp(P_SIZE,219);
  SetProp(P_WEIGHT,130000);
  SetProp(P_RESISTANCE,
  ([
    DT_SLASH:    -1.5,
    DT_LIGHT:     0.3, 
    DT_DARKNESS: -0.3
  ]));
  SetProp(P_DIE_MSG," bildet einen grossen Blutfleck.\n");
  SetProp(P_CORPSE,CHAOS_GILDEN_OBJ("blutfleck"));
  AddId(({"tutszt","chaos_gilden_daemon","blutdaemon","\nkampfdaemon"}));
}  

void Attack(object enemy)
{
  int hp, maxhp;
  string msg;

  if (!caster && !random(5))
     caster = find_player(QueryProp(CHAOS_DAEM_BESCHWOERER));

  if(!objectp(caster)||!interactive(caster))
    return::Attack(enemy);

  if(enemy==caster)
    return::Attack(enemy);

  if(QueryProp(DAEM_FALSE) || QueryProp(DAEM_AGGRESSIVE) || 
     QueryProp(KILL_ALL)) 
    return::Attack(enemy);
  
  if(random(3)||QueryProp(DAEM_DONT_SPEAK)) 
    return ::Attack(enemy);
  
  hp    = enemy->QueryProp(P_HP);
  maxhp = enemy->QueryProp(P_MAX_HP);
  
  if(hp<maxhp/10)
    msg = " steht auf der Schwelle zu einer besseren Welt.";
  else if( hp < maxhp/5) 
    msg = " braucht den beruehmten Arzt.";
  else if( hp < maxhp*3/10 ) 
    msg = " hats mit der Verfassung.";
  else if( hp < maxhp*4/10) 
    msg = " wankt und schwankt. Sieht gut fuer uns aus :-)";
  else if( hp < maxhp/2) 
    msg = " sieht zum Mitnehmen aus.";
  else if( hp < maxhp*6/10) 
    msg = " ist nicht mehr frisch. Und wie Tau schon gar nicht!";
  else if( hp < maxhp*7/10) 
    msg = " hat schon einige Kratzer abbekommen.";
  else if( hp < maxhp*8/10) 
    msg = " fuehlte sich auch schon schlechter.";
  else if( hp < maxhp*9/10) 
    msg = " ist ganz ganz leicht angeschwaechlicht.";
  else 
    msg = " ist absolut fit. Was immer das heissen mag...";
  
  tell_object(caster, break_string(enemy->Name(WER,1)+msg,0, 
    "Tutszt teilt Dir mit: " ));
  
  return ::Attack(enemy);
}
