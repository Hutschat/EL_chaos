// csn.c
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

inherit "/std/npc";

#define LAUSCHER "\nlauscher"

static int hoere_auf();

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(1,50);
  SetProp(P_LONG,
  "Dies ist ein kleiner Spionage-Daemon, der ueberall herumschnueffelt. "
  "Seine gewaltigen Ohren fangen einfach jedes Wort auf. Still und "
  "unscheinbar, fast ein Schatten, steht er einfach nur da und hoert zu. "
  "Wenn Du willst, dass er verschwindet, so gibt einfach 'aufhoeren' ein.");
  SetProp(P_FOLLOW_SILENT,1);
  SetProp(P_HP,50);
  SetProp(P_MAX_HP,50);
  SetProp(P_ARTICLE,0);
  AddClass(({
   CL_SKIN,
   CL_DEMON,
   CL_WALKING,
   CL_BREATH_AIR 
  }));
  SetProp(P_SIZE,10);
  SetProp(P_WEIGHT,30);
  SetProp(P_RACE,CL_DEMON);
  AddId("\nchaos_lauscher");
  AddId(({"spinonagedaemon","daemon","spionage-daemon"}));
  AddCmd(({"aufhoeren","aufhoere","aufhoer"}),"hoere_auf");
}

varargs void die()
{
  hoere_auf();
}

void catch_tell(string str)
{
  object pl, opf;
  ::catch_tell(str);
  
  pl  = find_player(QueryProp(LAUSCHER));
  opf = find_player(QueryProp("opfer"));
  
  if(!opf || opf->QueryProp(P_GHOST))
  {
    remove();
    return;
  }
  if(!pl)
  {
    if(opf) 
      tell_object(opf,"Du wirst jetzt nicht mehr belauscht!\n");
    
    remove();
    return;
  }
  if(file_name(environment(pl)) != CHAOS_GILDEN_ROOM("cerz1"))
  {
    if(opf)
      tell_object(opf,pl->Name(WER)+" belauscht Dich nicht mehr.\n");
    
    remove();
    return;
  }
  if(!pl->QueryProp("lausch"))
  {
    if(opf) 
      tell_object(opf,pl->Name(WER)+" belauscht Dich nicht mehr.\n" );
    
    remove();
    return;
  } 
   tell_object(pl,break_string(str,0,"|->"));
}

static int hoere_auf()
{
  object pl; 

  pl = find_player(QueryProp(LAUSCHER));

  if(pl)
    tell_object(pl,capitalize(getuid(this_player()))+
                " unterbricht die Verbindung.\n");

  write("Du unterbrichst die Verbindung.\n");

  pl->SetProp("lausch",0);

  remove();

  return 1;
}  
