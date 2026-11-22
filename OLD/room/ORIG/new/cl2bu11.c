#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

inherit "/std/room";

#define BS(x) break_string(x,78)


create() {
  ::create();
  
  SetProp(P_INDOORS,1);
  SetProp(P_LIGHT,0);
  SetProp(P_INT_SHORT,"In der chaotischen Burg");
  SetProp(P_INT_LONG,BS("Du befindest Dich in einem weiss getuenchten "+
  "Raum. Wow. An der Wand, aufgereih, Reihe um Reihe, stehen grooosse "+
  "Eimer. Richtig viele Eimer. Dutzende, wenn nicht hunderte von ihnen. "+
  "Was mag sich dort nur alles drinn befinden?"));
  AddDetail(({"boden"}),BS("Der Boden ist mit Flecken uebersaeht. "+
  "Schwarzen Flecken. Auf dem weiss getuenchten Boden."));
  AddDetail(({"flecken","schwarze flecken"}),BS("Sie sehen pechschwarz "+
  "aus."));
  AddDetail(({"decke"}),BS("Die Decke wurde weiss getuencht."));
  AddDetail(({"wand","waende"}),BS("An der westlichen Wand entdeckst Du "+
  "einen Knopf!"));
  AddDetail(({"knopf"}),BS("Man koennte ihn druecken..."));
  AddDetail(({"westliche wand"}),BS("Huuuh, ein Loch! Aeh, Knopf. Ein Knopf!"));
  AddDetail(({"loch"}),BS("Nix Loch. Knopf!"));
  AddDetail(({"reihe","reihen"}),BS("Das sind wirklich viele Eimer. Sie "+
  "stehen dort, Reihe um Reihe. Wow sind das viele."));
  AddDetail(({"dutzende","hunderte"}),BS("Wow sind das viele Eimer!"));
  AddDetail(({"eimer"}),"Es sind verflucht viele Eimer. Sie sind alle"+
  "samt weiss und haben die folgende\nAufschrift:\n\n"+
  "         A L P I N A S C H W A R Z\n\n");
  
  AddCmd(({"drueck","druecke"}),"press");
  
}


int press(string was) {
  notify_fail("Was moechtest Du druecken?\n");
  if (was != "knopf") return 0;
  write("Du drueckst den Knopf.\nDie Wand dreht sich, und Du mit ihr.\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2bu9"),M_GO,"Wand","dreht sich mit der","erscheint quasi durch die Wand");
  return 1;
}
