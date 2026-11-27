// Letzte Aenderung:
//
// 22.11.2016 It@Efferdland     1. Version

inherit "/std/virtual/it_compiler_load_all";

static string *keys;

void create()
{
  if(clonep())
  {
    destruct(this_object());
    return;
  }
  ::create();
  seteuid(getuid(this_object()));
  load_rooms();
}
