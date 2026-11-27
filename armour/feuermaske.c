// feuermaske.c - Die Maske eines Feuerdämons
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            erbt std/maske, Verwandlung per
//                                     Shadow

#pragma strong_types

#include "def.h"

inherit CHAOS_GILDEN_ARMOUR("std/maske");

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();

  SetProp(P_SHORT,"Eine feuerrote Maske");
  SetProp(P_LONG,
  "Diese Maske gehörte einst einem mächtigen und gefürchteten "
  "Feuerdämon. Die dämonische Haut seines Gesichts wurde abgezogen, in "
  "eine passende Maskenform gebracht und getrocknet. Die Maske ist "
  "deshalb feuerrot und gibt die gemeine Fratze des Dämons wieder.");

  AddDetail(({"daemon","feuerdaemon"}),
  "Feuerdaemonen sind sehr unangenehme, boesartige Gestalten. Das Feuer, "
  "welches sie umgibt, ist heiss, doch der Hass in ihren Herzen ist noch "
  "viel heisser.");
  
  AddDetail(({"gestalten"}),
  "Du meinst wohl Feuerdaemonen...");
  
  AddDetail(({"hitze","feuer","glut"}),
  "Diese Maske ist gluecklicherweise kuehl und leblos...");
  
  AddDetail(({"hass"}),
  "Daemonen werden von unirdischem Hass am Leben erhalten. Sie verhalten "
  "sich nicht immer so, doch ihr Innerstes ist zerfressen und erfuellt "
  "davon.");
  
  AddDetail(({"innerstes"}),
  "Du solltest das schwarze Herz eines Daemons einmal sehen! Dies ist "
  "natuerlich rein bildlich gesprochen, denn Daemonen haben kein Herz.");
  
  AddDetail(({"herz","daemonenherz"}),
  "Daemonen haben natuerlich kein Herz. Das war jetzt rein bildlich "
  "gesprochen.");
  
  AddDetail(({"macht"}),
  "Daemonen sind keineswegs alle gleich maechtig. Doch das wusstest du "
  "sicherlich schon.");
  
  AddDetail(({"haut","daemonenhaut"}),
  "Die Maske besteht aus einer daemonischen Haut. Du findest es erstaunlich, "
  "dass Feuerdaemonen eine Haut haben. Sachen gibts...");
  
  AddDetail(({"sachen"}),
  "Sachen halt...");
  
  AddDetail(({"gesicht","fratze"}),
  "Also, puuh, diese Fratze ist wirklich, also, WIRKLICH haesslich.");
  
  AddDetail(({"maskenform","form"}),
  "Maskenform halt. Du weisst schon.");

  AddDetail(({"wissen"}),
  "Du weisst schon. Du WEISST schon...");

  AddDetail(({"farbe","rot","feuerrot"}),
  "Wow. Eine feuerrote Maske. Cool.");
  
  AddId(({"feuermaske"}));

  SetProp(P_CHAOS_MASKE_DATEN,
  ([
    P_NAME:   "Feuerdämon",
    P_GENDER: MALE,
    P_RACE:   "Dämon",
    P_SHORT:  "@WER1, verwandelt in einen Feuerdämon",
    P_LONG:   "@WER1 hat rotglühende Augen und ist von einer feurigen "
              "Aura umgeben. Die Haut ist schwarz, die krallenbewehrten "
              "Fänge zucken unkontrolliert. An einigen Stellen tritt "
              "schwarzes Blut aus der Haut und fließt an ihr herab.",
    P_MSGIN:  "schleicht feurig herein",
    P_MSGOUT: "schleicht feurig",
    P_HANDS:  ({" mit feurigen Klauen",160,({DT_RIP,DT_FIRE})}),
    P_IDS:    ({"feuerdämon","dämon"}),
  ]));
}
