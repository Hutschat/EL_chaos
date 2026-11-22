#include "/gilden/files.chaos/gilde.h"

inherit "/gilden/chaos";


create() {
  ::create();
  RemoveItem(CHAOS_GILDEN_MON("hutschat"));
  RemoveExit("nordwesten");
  RemoveExit("osten");
  AddExit("osten",CHAOS_GILDEN_ROOM("cl2_challe"));
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl2_hutschatraum"));
}