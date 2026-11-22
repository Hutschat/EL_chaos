// masken_shadow.c fuer die Chaosmasken
//
// Letzte Aenderung:
//
// 11.03.2019 It@Efferdland            neu

#pragma no_inherit

#include "def.h"

inherit "/std/shadow";

static object  player;
static mapping args;

public void on(object pl,mapping map)
{ 
  AddShadow(pl,NO_MULTI_SHADOW);
  
  args   = map;
  player = query_shadow_owner();
  
  call_other(CHAOS_GILDEN_MASTER("shadow_master"),"RegisterShadow",ME);
}

public void off()
{
  if(objectp(ME))
    destruct_shadow();
}

string* _query_ids()
{
  return args[P_IDS]+({"daemon"});
}

string _query_race()
{
  return args[P_RACE];
}

int _query_gender()
{
  return args[P_GENDER];
  return MALE;
}

varargs string name(int a,int b)
{
  return args[P_NAME];
}
varargs string Name(int a,int b)
{
  return args[P_NAME];
}

varargs int CannotSee( int silent )
{
  return 0;
}

string short()
{
  return replace_personal(args[P_SHORT],({player}));;
}

varargs string long()
{
  return replace_personal(args[P_LONG],({player}));;
}

string _query_presay()
{
  return "";
}

mixed  _query_title()
{
  return 0;
}

string _query_msgin()
{
  return args[P_MSGIN];
}

string _query_msgout()
{
  return args[P_MSGOUT];
}
