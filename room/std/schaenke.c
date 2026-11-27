// schaenke.c - Std-Raum für die Schänke der Burg Zwielichtstein
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

inherit "/std/kneipe";
inherit CHAOS_BURG_STD("dets");

// Der Chaos-Becher: Für Chaoten ein Genuss, für alle anderen nicht
public void chaos_becher(object zahler, object empfaenger, string ident,
                         mapping info) {
  if(!objectp(empfaenger)) {
    return;
  }
  if(empfaenger->QueryProp(P_GUILD) == "chaos") {
    tell_object(empfaenger,break_string("Der Becher voll Chaos ist genau "
      "das Richtige für einen hartgesottenen Krieger des Chaos. Er "
      "schmeckt dir nicht nur sehr gut, er tut dir auch gut."));
    tell_room(ME,break_string(empfaenger->Name(WER)+" trinkt hastig "
      "einen Becher Chaos und fühlt sich sichtlich wohl."),({empfaenger}));
    return;
  }
  tell_object(empfaenger,break_string("Als Nicht-Mitglied der Gilde des "
    "Chaos hättest du ihr stärkstes Gebräu besser nicht bestellt. Dir "
    "dreht sich der Magen um, und mit einem Schlag wird dir furchtbar "
    "übel."));
  tell_room(ME,break_string(empfaenger->Name(WER)+" trinkt einen Becher "
    "Chaos und schaut sehr seltsam drein."),({empfaenger}));

  SetProp(P_KILL_NAME,"Ein Becher voller Chaos");
  SetProp(P_KILL_MSG,"Prost!");
  empfaenger->do_damage(40+random(50),ME);

  if(objectp(empfaenger)) {
    empfaenger->restore_spell_points(-80);
  }
}

void reset() {
  kneipe::reset();
  chaos_reset();
}

varargs void init() {
  kneipe::init();
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
  SetProp(P_LIGHT_TYPE,LT_FIRE);
  SetProp(P_TERRAIN,T_BUILDING|T_CAVE);
  SetProp(P_ENVIRONMENT,
  ([
    ENV_ALTITUDE:    CHAOS_BURG_HOEHE-5,
    ENV_TEMPERATURE: 16,
  ]));

  AddDetail(({"boden","fussboden","fußboden"}),
  "Der Boden ist klebrig und voller Flecken.");

  AddDetail(({"flecken"}),
  "Du willst gar nicht wissen, wovon.");

  AddDetail(({"decke","gewölbe","gewoelbe"}),
  "Ein niedriges, rußgeschwärztes Gewölbe.");

  AddDetail(({"wand","waende","wände"}),
  "Die Wände sind rußgeschwärzt, durch eine sickert violettes Licht.");
}
