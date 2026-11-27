// draussen.c - Std-Raum für die Räume der Burg Zwielichtstein unter
//              freiem Himmel
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu
// 27.11.2026 It@Efferdland            Chaosmagie

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/room";
inherit CHAOS_BURG_STD("dets");

void reset() {
  room::reset();
  chaos_reset();
}

varargs void init() {
  room::init();
  chaos_init();
}

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  "*"::create();

  SetProp(P_INDOORS,0);
  SetProp(P_LIGHT,1);
  SetProp(P_LIGHT_TYPE,LT_DIFFUSE);
  SetProp(P_TERRAIN,T_BUILDING|T_MOUNTAIN);
  SetProp(P_ENVIRONMENT,
  ([
    ENV_ALTITUDE:    CHAOS_BURG_HOEHE,
    ENV_TEMPERATURE: 2,
    ENV_ENVSPEED:    2,
  ]));

  AddDetail(({"himmel","dunst","nebel","wolken","wolke"}),
  "Über der Burg hängt ein schwerer, grauer Dunst, in dem violette "
  "Blitze zucken. Den Himmel siehst du nicht.");

  AddDetail(({"blitz","blitze"}),
  "Violette Blitze zucken lautlos durch den Dunst über der Burg.");

  AddDetail(({"boden","fussboden","fußboden","pflaster","pflastersteine"}),
  "Altes, holpriges Pflaster, zwischen dem dürres Gras wächst.");

  AddDetail(({"gras"}),
  "Dürr und grau, als hätte es seit Jahren kein Licht gesehen.");

  AddDetail(({"licht","jahren"}),
  "Durch den Dunst über dem Schattental dringt kaum Licht.");

  AddDetail(({"schattental","tal"}),
  "Das Schattental liegt im Westen tief unter der Burg, düster und vom "
  "Dunst verhangen.");

  AddSound(({"wind"}),
  "Er pfeift leise.");

  AddDetail(({"wind"}),
  "Ein kalter Wind streicht über die Burg.");

  AddDetail(({"sonne"}),
  "Die Sonne dringt nicht durch den Dunst.");
}
