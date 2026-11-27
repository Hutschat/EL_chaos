// virtual_compiler.c - Die Räume der Burg Zwielichtstein
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma no_clone
#pragma no_inherit
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/virtual/it_compiler";

protected void create() {
  ::create();
  SetProp(P_VC_FILELIST,CHAOS_VC_BURG);
  seteuid(getuid());
}
