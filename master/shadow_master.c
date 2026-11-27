// shadow_master.c
//
// Da man die Clones der Shadows schnell aus den Augen verliert, sind
// sie hier gespeichert.
//
// Letzte Aenderung:
//
// 12.03.2019 It@Efferdland            neu


#include "def.h"


static object *shadows = ({});

static void clear_chadows()
{
  shadows -= ({0});
}

public void RegisterShadow(object ob)
{
  shadows += ({ob});
  clear_chadows();
}

public object *get_shadows()
{
  return shadows;
}
