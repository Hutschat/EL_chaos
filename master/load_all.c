// Letzte Aenderung:
//
// 22.11.2016 It@Efferdland     1. Version

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include <defines.h>

inherit "/std/virtual/it_compiler_load_all";

static string *keys;

void create()
{
  if(clonep())
  {
    destruct(ME);
    return;
  }
  ::create();
  seteuid(getuid(ME));
  load_rooms();
}
