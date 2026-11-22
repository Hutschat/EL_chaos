/*
   Dieser winzige Std-Raum dient der Unterstuetzung unseres wunderbaren
   Globalen Masters cl2w_mas. Der macht so eine Art globalen Coller 
   (aeh globales tell_room).
*/

#include "/gilden/files.chaos/gilde.h"
inherit "/std/room";

int PlayerQuit(object me) {
  (CHAOS_GILDEN_ROOM("cl2w_mas"))->delete(me);
}
int NotifyPlayerDeath(object opfer, object killer,int xp) {
  (CHAOS_GILDEN_ROOM("cl2w_mas"))->delete(opfer);
}
int BecomesNetAlive(object me) {
  (CHAOS_GILDEN_ROOM("cl2w_mas"))->add(me);
}
int BecomesNetDead(object me) {
  (CHAOS_GILDEN_ROOM("cl2w_mas"))->delete(me);
}
