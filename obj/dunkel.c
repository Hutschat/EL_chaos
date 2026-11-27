// dunkel.c
//
// Letzte Aenderung:
//
// 17.03.2019 It@Efferdland            neu

#pragma no_inherit

#include "def.h"

inherit "/std/thing";

static int my_time = 0;

public int _query_light() {
  if(my_time < time()) {
    call_out("remove",0);
    return 0;
  }
  return Query(P_LIGHT);
}

public int set_my_time(int val) {
  return (my_time = val + time());
}

public int my_light(int val) {
  SetProp(P_LIGHT,QueryProp(P_LIGHT)+val);
  return val;
}

static int _query_short() {
  if(my_time < time())  {
    call_out("remove",0);
    SetProp(P_LIGHT,0);
  }
  return 0;
}

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_LONG, 0);
  SetProp(P_NAME, 0);
  SetProp(P_NOGET,1);
}

protected void reset() {
  ME->remove();
}
