#include "gilde.h"

inherit CHAOS_GILDEN_ROOM("cl2_std_kneipe");
#include <properties.h>
#include <rooms.h>
#include <combat.h>
 
create() {
  cl2_std_kneipe::create();
  RemoveExit("sueden");
  AddExit( "osten", C_112_ROOM( "cl2bu5" ) );  
}

