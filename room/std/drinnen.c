// drinnen.c - Std-Raum für die Räume innerhalb der Burg Zwielichtstein
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu
// 27.11.2026 It@Efferdland            Chaosmagie

#pragma strong_types

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

  SetProp(P_INDOORS,1);
  SetProp(P_LIGHT,1);
  SetProp(P_LIGHT_TYPE,LT_MAGIC);
  SetProp(P_TERRAIN,T_BUILDING|T_MOUNTAIN);
  SetProp(P_ENVIRONMENT,
  ([
    ENV_ALTITUDE:    CHAOS_BURG_HOEHE,
    ENV_TEMPERATURE: 8,
  ]));

  AddDetail(({"decke","gewölbe","gewoelbe"}),
  "Die Decke ist gewölbt und rußgeschwärzt. Ein paar Risse ziehen sich "
  "durch das Gestein.");

  AddDetail(({"boden","fussboden","fußboden","steinboden"}),
  "Der Boden besteht aus großen, abgetretenen Steinplatten.");

  AddDetail(({"steinplatten","platten"}),
  "Die Platten sind uneben, alt und abgetreten.");

  AddDetail(({"gestein","russ","ruß"}),
  "Schwarzes Gestein, vom Ruß unzähliger Jahre geschwärzt.");

  AddDetail(({"wand","waende","wände"}),
  "Die Wände sind aus schwarzem Stein und von Rissen durchzogen.");

  AddDetail(({"jahre"}),
  "Wie alt die Burg ist, weiß niemand so genau.");
}
