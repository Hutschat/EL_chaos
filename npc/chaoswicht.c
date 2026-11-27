// chaoswicht.c - Ein kleines Wesen, das bei einem Chaosblitz in der Burg
//                Zwielichtstein entsteht (room/std/dets.c)
//
// Harmlos, kichert, schneidet Grimassen und verschwindet nach ein paar
// Minuten wieder.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/npc";

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(3,40);

  SetProp(P_NAME,"Chaoswicht");
  SetProp(P_GENDER,MALE);
  SetProp(P_SHORT,"Ein kichernder Chaoswicht");
  SetProp(P_LONG,
  "Ein winziges, krummbeiniges Wesen mit zu großen Ohren und Augen, die "
  "in allen Farben schillern. Es ist aus einem Chaosblitz entstanden und "
  "weiß offenbar selbst nicht so recht, was es hier soll. Also kichert "
  "es.");
  SetProp(P_RACE,CL_DEMON);
  SetProp(P_ALIGN,-50);
  SetProp(P_SIZE,40);
  SetProp(P_WEIGHT,4000);
  SetProp(P_NOCORPSE,1);
  SetProp(P_HANDS,({" mit spitzen Fingernägeln",20,({DT_RIP})}));
  SetProp(P_DIE_MSG," löst sich in violetten Funken auf.\n");
  SetProp(P_MSGIN,"hüpft kichernd herein");
  SetProp(P_MSGOUT,"hüpft kichernd davon");

  AddClass(({CL_DEMON,CL_SKIN,CL_WALKING}));
  AddId(({"wicht","chaoswicht","wesen"}));

  AddDetail(({"ohren","ohr"}),
  "Viel zu groß für den kleinen Kopf. Sie wackeln, wenn er kichert.");

  AddDetail(({"augen","auge"}),
  "Sie schillern in allen Farben, manchmal in solchen, die es gar nicht "
  "gibt.");

  AddDetail(({"beine","bein"}),
  "Krumm und dünn, aber erstaunlich flink.");

  AddDetail(({"chaosblitz","blitz"}),
  "Aus so einem ist er entstanden.");

  AddDetail(({"farben","farbe"}),
  "Bunt. Sehr bunt.");

  SetChats(15,({
    "Der Chaoswicht kichert.\n",
    "Der Chaoswicht schneidet eine Grimasse.\n",
    "Der Chaoswicht wackelt mit den Ohren.\n",
    "Der Chaoswicht schlaegt einen Purzelbaum und landet auf dem Kopf.\n",
    "Der Chaoswicht zupft dich am Aermel und kichert.\n",
    "Der Chaoswicht starrt eine Wand an, als haette sie etwas gesagt.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Hihihi!",
    "Weiß nicht! Hihi!",
    "Chaos! Chaos! Hihihi!",
  }),"kichert: ");

  // Nach ein paar Minuten löst er sich wieder auf
  call_out(function void() {
    if(environment()) {
      tell_room(environment(),break_string(Name(WER,1)+" kichert ein "
        "letztes Mal, dreht sich einmal um sich selbst und löst sich in "
        "violetten Funken auf."));
    }
    remove();
  },120+random(180));
}
