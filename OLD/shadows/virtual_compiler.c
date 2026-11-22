#include "def.h"

inherit "/std/virtual/v_compiler";

void create()
{
  ::create();
  SetProp(P_STD_OBJECT,CHAOS_GILDEN_SHADOWS("mask_shadow"));
}

mixed Validate(string file) 
{
  return file;
}

static mixed AddObject(string file)
{
  object ob;
  string err,f;

  objects = filter_indices(objects,function int (string f)
            { return (objectp(objects[f])); } );

  // register new object
  if(ob = clone_object(QueryProp(P_STD_OBJECT)))
  {
    sscanf(file,"%s.c",f);
    
    objects[f] = ob;
    
    ob->Set("vc_name",f);
  }
  return ob;
}

static void clear()
{
  foreach(string ob:m_indices(objects))
  {
  dtell("it",ob);
    if(!objectp(objects[ob]))
      objects -= ([ob]);
  }
}

public void destruct_shadow(object ob)
{
//  dtell("it",({load_name(ob)}));
//  ob = QueryObjectMap()[file+".c"];

dtell("it",({1,ob}));  
  if(objectp(ob))
    destruct(ob);

  clear();
}
