// yrintri.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 07.06.1998 Bierchen                 (DT_UNHOLY und DT_TERROR eingefuegt)
// 21.06.1998 Bierchen                 (Hands)
// 12.03.2019 It@Efferdland            ueberarbeitet

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
  create_default_npc(25,600);
  SetProp(P_SHORT, "Yrintri der Wandler" );
  SetProp(P_LONG, 
  "Yrintri, der Wandlerdaemon, kann seine Gestalt beliebig veraendern "
  "und sich so auf seine Gegner einstellen. Mal ist er in tosende Flammen "
  "gehuellt, mal ist er kalt wie Eis. Dies muss man ihm natuerlich erst "
  "befehlen!");
  SetProp(P_NAME,"Yrintri");
  SetProp(P_GENDER,1);
  SetProp(P_ARTICLE, 0);
  SetProp(P_HP,300);
  SetProp(P_XP,0);
  SetProp(P_ALIGN,-200);
  SetProp(P_HANDS,({" mit Eis-Klauen",260,({DT_COLD,DT_RIP})}));
  SetProp(P_ATTRIBUTES, ([ A_STR:27, A_DEX:27, A_INT:27, A_CON:27 ]));
  SetProp(P_BODY,195);
  SetProp(DAEM_PROZENT,100);
  SetProp(P_MSGIN, "wandelt herein");
  SetProp(P_MSGOUT,"wandelt davon");
  SetProp(P_SIZE,156);
  SetProp(P_NOCORPSE,1); 
  SetProp(P_DIE_MSG," beendet seine Daseinsform.\n");
  SetProp(P_MMSGIN,"schaut mal eben vorbei");
  AddId(({"yrintri","chaos_gilden_daemon","wandler","wandlerdaemon", 
    "\nkampfdaemon"})); 
  AddCmd(({"befehle","befehl"}),"befehle_wandel");
}  

void Attack(object enemy)
{
  int hp, maxhp;
  string msg;

  if(!caster && !random(5))
     caster = find_player(QueryProp( CHAOS_DAEM_BESCHWOERER) );

  if(!objectp(caster) || !interactive(caster))
    return::Attack(enemy);

  if(enemy==caster)
    return::Attack(enemy);
  
  if(QueryProp(DAEM_FALSE) || QueryProp(DAEM_AGGRESSIVE) || 
     QueryProp(KILL_ALL)) 
    return::Attack(enemy);     

  if(random(3))
    return::Attack(enemy);
  
  hp    = enemy->QueryProp(P_HP);
  maxhp = enemy->QueryProp(P_MAX_HP);
  
  if( hp < maxhp/10) 
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
             "Yrintri teilt Dir mit: " ));

  return::Attack(enemy);
}          

string yhand_txt(string watdenn)
{
  mapping schaden;  
  schaden = ([ 
    "feuer":"brennenden", 
    "eis":"eisigen", 
    "sturm":"stuermischen",
    "magie":"magischen", 
    "wasser":"waessrigen", 
    "blitz":"blitzenden", 
    "saeure":"saeuretriefenden", 
    "gift":"giftigen",
    "boese":"unheiligen",
    "terror":"terrorverbreitenden"]);
    //tell_room(environment(this_object()),watdenn+"\n"); 
    if(!member(schaden,watdenn))
      return "unbekannten";
    
    return schaden[watdenn];
}

int befehle_wandel( string str)
{
  string ich, art;
  mapping schaden;

  if(!str) return befehle_daemon(str); 

  notify_fail("Yrintri versteht den Befehl nicht.\n");
  
  if( !sscanf(str,"%s verwandlung dich in %s", ich, art) && 
      !sscanf(str,"%s verwandel dich in %s", ich, art) &&
      !sscanf(str,"%s verwandle dich in %s", ich, art)) 
    return befehle_daemon(str);
  
  if(!id(ich))
    return befehle_daemon(str); 
  
  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER))
  {
    write("Yrintri sagt: Du hast mir gar nix zu sagen!\N");
    return 1;
  }
  if(QueryProp("kill_all") || QueryProp(DAEM_AGGRESSIVE))
  {
    write(ME->Name(WER,1)+" gehorcht Dir nicht.\n");
    return 1;
  }
  if(IsEnemy(PL))
  {
    write(Name(WER,1)+" lacht ueber Dich!\n");
    return 1;
  }
  schaden = ([
  "feuer": DT_FIRE,
  "eis":   DT_COLD,
  "sturm": DT_AIR,
  "magie": DT_MAGIC,
  "wasser":DT_WATER,
  "blitz": DT_LIGHTNING,
  "saeure":DT_ACID,
  "gift":  DT_POISON,
  "boese": DT_DARKNESS,
  "terror":DT_TERROR]);
                                          
  notify_fail("Yrintri kennt nur: boese, terror, feuer, eis, sturm, "
              "magie, wasser, blitz, saeure und gift.\n");
  
  if(!member(schaden,art))
    return 0;
  
  SetProp(P_HANDS,({" mit "+yhand_txt(art)+" Klauen", 260,schaden[art]})); 
  
  write( "Yrintri verwandelt seine Klauen.\n");

  return 1;
}

varargs int|string*|mapping* DefendOther(int dam, mixed dam_type, 
                                        mixed spell,object enemy)
{     
  object caster;

  if(!caster = find_player(QueryProp(CHAOS_DAEM_BESCHWOERER)))
    return ({dam,dam_type,spell});

  if(QueryProp(KILL_ALL) || QueryProp(DAEM_AGGRESSIVE) || 
     QueryProp(DAEM_FALSE))
    return ({dam,dam_type,spell});

  if(caster->QueryProp(P_HP) < dam/10)
  {
    tell_object(caster,"Yrintri wirft sich vor den den toedlichen "
                "Angriff und faengt ihn ab.\n");
    
    say("Yrintri rettet "+caster->name(WEM,1)+" das Leben!\n", caster);
    
    wech(QueryProp(CHAOS_DAEM_BESCHWOERER),5);

    return ({0,dam_type,spell});
  }                                                                  
  return ({dam,dam_type,spell});
}
