
inherit "/std/virtual/v_compiler";

#include <v_compiler.h>
#include "/gilden/files.chaos/gilde.h"


create()
{
  v_compiler::create();
  SetProp(P_STD_OBJECT, CHAOS_GILDEN_ROOM("vc/stop"));
}

// Falls wir hier FP's vergeben :)
Validate(string file)
{
  if (strstr(file,"^",0)>-1) return 0;
  if (file[0..8] == "cteletime") 
    SetProp(P_STD_OBJECT,CHAOS_GILDEN_ROOM("vc/cteletime"));
  if (file[0..3] == "stop")
    SetProp(P_STD_OBJECT,CHAOS_GILDEN_ROOM("vc/stop"));
  return ::Validate(file);
}

// Fuer die Interna :)
CustomizeObject()
{
  string file;
  if(!(file = ::CustomizeObject())) return 0;
  return file;
}


