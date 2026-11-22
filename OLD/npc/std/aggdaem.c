// aggdaem.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 10.12.2018 It@Efferdland            ueberarbeitet

#pragma no_clone

#include "def.h"

inherit "std/npc";

static int z;

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_NOFIRSTKILL,1);
  SetProp(P_XP,1);
  SetProp("chaos:remove_me_while_reset",1);
  AddId(({CHAOS_ID_AGGDAEMON,"daemon"}));
  AddClass(({
    CL_DEMON,
    CL_SKIN,
    CL_WALKING,
    CL_BREATH_AIR
  }));
  SetProp(P_RACE,CL_DEMON);
}

void reset()
{
  ::reset();
  
  if(!environment())
    return;
  
  if(QueryProp("chaos:remove_me_while_reset"))
  {
   tell_room(environment(),Name(WER,1)+QueryProp(P_DIE_MSG));
   remove();
   return;
  }
}

void Attack( object enemy)
{
  if( query_once_interactive( enemy) && !interactive( enemy))
  {
    enemy->StopHuntFor(ME);
    StopHuntFor(enemy);
    return;
  }
  ::Attack(enemy);
}


void init()
{
  string agg;
  ::init();

  if(QueryProp( "kill_all") && 
     member( VERBOTENE_RAEUME,object_name(environment(ME)))!=-1 &&
     this_player()->QueryProp( P_LEVEL) > 8 &&
     interactive(PL) && PL ->QueryProp( P_HP ) > 70 &&
     !IS_LEARNER(PL))
  {  
    if(query_idle(PL) < 60 ) 
      Kill( this_player());
  }
  if(agg = QueryProp(DAEM_AGGRESSIVE))
  {
    if( find_player( agg)) 
      Kill( find_player(agg));

    if(!random(100) < ME->QueryProp( AGG_CHANCE )) 
      SetProp("kill_all", 1);

    if(find_call_out( "folge_caster") == -1) 
      call_out( "folge_caster", 5, agg );
  }
}

void folge_caster(string agg)
{
  object pl;
  
  if(!stringp(agg))
    return;

  pl = find_player(agg);

  if(!pl || !objectp(pl))
  {
    this_object()->SetProp( "kill_all", 1);
    z ++;
  }
  if( z > 20 )
  {
    die();
    return;
  }
  if( objectp(pl))
  {
    if( pl->QueryProp( P_GHOST))
    {
      tell_room(environment(),Name(WER,1)+QueryProp(P_DIE_MSG));
      remove();
      return;
    }
    if(!present(pl, environment(ME))) 
      ME->move(environment(pl),M_TPORT);
  }
  SetProp(P_MSGOUT,"verfolgt "+capitalize(agg));
  call_out("folge_caster", random( QueryProp(DAEM_HUNTING_TIME) ), agg);
}


void setDaemBeschwoerer(object ob)
{ 
  if (!ob)
    return;
  
  SetProp(CHAOS_DAEM_BESCHWOERER,getuid(ob));
  
  if (query_once_interactive(ob))
    SetProp(CHAOS_DAEM_BESCHWOERER_NAME,getuid(ob));
  
  else
    SetProp(CHAOS_DAEM_BESCHWOERER_NAME,ob->name(WER));
}
