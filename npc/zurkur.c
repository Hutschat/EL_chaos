// zurkur.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 12.03.2019 It@Efferdland            ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_MON("std/aggdaem");  

static string aua()
{
  object en = QueryEnemy();

  switch(random(20))
  {
    case 0..7:
      tell_object(en,Name(WER,1)+" wirft eine flammende Feuerkugel nach "
                    "Dir.\n");
      
      say(Name(WER,1)+" wirft eine flammende Feuerkugel nach "
          +en->name(WEN)+".\n",en);
      
      en->Defend(random(300),DT_FIRE,([
                                       SP_NAME: "Feuerball",
                                       SP_SHOW_DAMAGE:1
                                     ]),ME);
      break;
    
    case 8..11:
      tell_object(en,Name(WER,1)+" Dich mit einer Wolke der Finsternis.\n");

      say(Name(WER,1)+" umhuellt "+en->name(WEN)+" mit einer Wolke der "
         "Finsternis.\n", en);
      
      en->SetProp(P_DISABLE_ATTACK, 5 + random(10));
      break;

    case 12..18:
      tell_object(en,Name(WER,1)+" feuert eine frostige Eiswolke nach "
                     "Dir ab.\n");

      say(Name(WER,1)+" feuert eine frostige Eiswolke nach "
         +en->name(WEM)+" ab.\n", en);
      
      en->Defend(random(350),DT_COLD,([
                                       SP_NAME: "Eiswolke",
                                       SP_SHOW_DAMAGE:1,
                                     ]),ME);
      break;

    case 19:
      tell_object(en,Name(WER,1)+" spritzt giftiges Gift nach Dir.\n");
      
      say(Name(WER,1)+" Chaosdaemon spritzt giftiges Gift nach "+
          en->name(WEN)+".\n", en);
      
      en->SetProp(P_POISON,en->QueryProp(P_POISON) + 1);
      break;
  }
  return "";
}
protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT, "Ein wilder Chaosdaemon" );
  SetProp(P_LONG,
  "Dieser Chaosdaemon ist gerade erst seinem Peiniger aus der Haut "
  "gefahren und ist demzufolge ziemlich sauer!");
  SetProp(P_NAME, "Chaosdaemon");
  SetProp(P_GENDER,MALE);
  SetProp(P_MMSGIN,   "erscheint in einem Schwall aus Blut" );
  SetProp(P_DIE_MSG,  " entschwindet den weltlichen Ebenen.\n");
  SetProp(P_NOCORPSE, 1);
  SetProp(P_WEIGHT,10000);
  SetProp(P_SIZE,70);
  AddId(({ "zurkur", "chaosdaemon","daemon"}));
}

void setze_stats(int level, object pl)
{
  create_default_npc(level * 2);

  SetProp(P_XP, 0);
  if(level < 5)
  {
    SetProp(P_MAX_HP, level * 20);
    SetProp(P_BODY, level * 10);
    SetProp(P_HANDS,({" mit der Macht des Chaos", 30 + level * 14,
                      DT_TERROR}));
  }
  else
  {
    SetProp(P_ALIGN, - level * 10);
    SetProp(P_MAX_HP, level * 25);
    SetProp(P_HANDS,({" mit der Macht des Chaos", 50 + level * 15,
                      DT_TERROR}));
    SetProp(P_BODY, level * 12);
  }
  if(level > 5 )
    SetProp(P_RESISTANCE,
    ([
      DT_FIRE:     -0.4,
      DT_COLD:     -0.4, 
      DT_ACID:     -0.4,
      DT_LIGHTNING:-0.4, 
      DT_MAGIC:    -0.4,
      DT_AIR:      -0.4, 
      DT_WATER:    -0.4,
      DT_LIGHT:     0.3,
      DT_DARKNESS: -0.3
    ]));
  if(level > 6) 
    SetAttackChats( level * 2, ({ "@@aua@@" }));

  if(level > 8)
    SetProp(P_RESISTANCE,QueryProp(P_RESISTANCE)+
            ([
              DT_SLASH:    -0.4,
              DT_PIERCE:   -0.4,
              DT_BLUDGEON: -0.4
            ]));
}
