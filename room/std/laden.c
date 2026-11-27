// laden.c - Std-Raum für Achtarchs Laden in der Burg Zwielichtstein
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types

#include "def.h"

inherit "/std/laden";
inherit CHAOS_BURG_STD("dets");

void reset() {
  laden::reset();
  chaos_reset();
}

varargs void init() {
  laden::init();
  chaos_init();
}

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  "*"::create();

  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_TERRAIN,T_BUILDING|T_MOUNTAIN);
  SetProp(P_ENVIRONMENT,
  ([
    ENV_ALTITUDE:    CHAOS_BURG_HOEHE,
    ENV_TEMPERATURE: 6,
  ]));
}
