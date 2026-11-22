#include "../def.h"

inherit "/std/thing";

static object  shadow;
static mapping args;

public void setup(mapping args)
{

}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();

  SetProp(P_SHORT,"Eine Daemonen Maske");
  SetProp(P_LONG, "Eine Maske");
  SetProp(P_GENDER,FEMALE);
  AddId(({"maske"}));
  
  AddCmd("an","an");
  AddCmd("aus","aus");
}

static int an(string str)
{
  shadow = clone_object("/gilden/chaos/shadows/mask_shadow");
  
  if(objectp(shadow))
    shadow -> on(PL);

  return 1;
}

static int aus(string str)
{
  shadow->off();
  return 1;
}

