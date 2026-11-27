// ziumtu.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 12.03.2019 It@Efferdland            ueberarbeitet

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "std/npc";

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT,"Ziumtu der Hauptpruefer der Chaos-Gilde");
  SetProp(P_LONG,
  "Ziumtu ist der Hauptpruefer der Chaos-Gilde. Er ueberprueft die "
  "kaempferischen Faehigkeiten der Anwaerter auf eine hoehere Stufe "
  "innerhalb der Gilde.");
  SetProp(P_NAME,"Ziumtu");
  SetProp(P_GENDER,1);
  SetProp(P_ARTICLE,0);
  SetProp(P_XP,195000);
  SetProp(P_ALIGN,100);
  SetProp(P_SIZE,150);
  SetProp(P_WEIGHT,80000);
  SetProp(P_CLASS,
  ({
    CL_HAIR,
    CL_DWARF,
    CL_WALKING,
    CL_BREATH_AIR,
  }));
  SetProp(P_RACE,CL_DWARF);
  SetProp(P_DIE_MSG," gibt sich geschlagen und verschwindet.\n");
  SetProp(P_NOCORPSE,1);
  SetProp(P_AGGRESSIVE,1);
  AddId(({"pruefer","ziumtu","\nchaos_gilden_pruefungs_daemon"}));
}

string spells()
{
  object en;

  en = QueryEnemy();

  if(!environment()) return "";

  if(!QueryProp( "kann_finsternis" ))
  {
    tell_object( en, "Ziumtu wirft einen Chaosball nach Dir.\n");
    
    say("Ziumtu wirft einen Chaosball nach "+en->name()+".\n", en);
    
    en->Defend(100 + random(250), DT_ACID, 1,ME);
    
    return "";
  }
  switch( random(10))
  {
    case 0:
     tell_object( en, "Ziumtu huellt Dich in eine Wolke aus Finsternis ein.\n");
     say( "Ziumtu huellt "+en->name()+" in einer Wolke aus Finsterins ein.\n", en);
     en->SetProp( P_DISABLE_ATTACK, en->QueryProp( P_DISABLE_ATTACK ) +
     5 + random(10));
     break;
    case 1..9:
     tell_object( en, "Ziumtu wirft einen Chaosball nach Dir.\n");
     say( "Ziumtu wirft einen Chaosball nach "+en->name()+".\n", en);
     en->Defend( 100 + random(300), DT_ACID, 1, ME);
     break;
  }
  return "";
}

varargs void die()
{
  foreach(object tmp:filter(all_inventory(environment(ME)),#'living))
  {
    if(!interactive(tmp))
      continue;
    
    if(tmp->QueryProp(P_INVIS))
      continue;

   CHAOS_GILDENMASTER->SetzePruefung(getuid(tmp), 
                        tmp->QueryProp(P_GUILD_LEVEL)+1);
   break;
  }
  ::die();
}

void verschwinde() { call_out( "remove", 1); }
