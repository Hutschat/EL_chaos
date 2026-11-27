// dets.c - Gemeinsame Details der Burg Zwielichtstein
//
// Erbt nichts. Die Std-Räume erben diese Datei zusätzlich und rufen
// "*"::create() auf.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma no_clone

#include "def.h"

protected void create() {
  ME->SetProp(P_INT_SHORT,"In der Burg Zwielichtstein");
  ME->SetProp(P_INT_LONG,"In der Burg Zwielichtstein.");

  ME->AddSpecialDetail(({"raum","umgebung","ort","stelle"}),
                       "_query_int_long");

  ME->AddDetail(({"burg","zwielichtstein","burg zwielichtstein","ruine"}),
  "Die Burg Zwielichtstein ist alt und halb verfallen. Chaotische Magie "
  "durchzieht jeden Stein, und nichts ist hier so, wie es auf den ersten "
  "Blick scheint.");

  ME->AddDetail(({"mauer","mauern","stein","steine","gemäuer","gemaeuer"}),
  "Die Mauern sind aus schwarzem Stein, rissig und an vielen Stellen "
  "eingestürzt. Manchmal flimmern sie seltsam, als wären sie nicht ganz "
  "da.");

  ME->AddDetail(({"riss","risse","spalt","spalten"}),
  "Durch die Risse in den Mauern sickert ein schwaches, violettes "
  "Leuchten.");

  ME->AddDetail(({"leuchten","schimmer","flimmern"}),
  "Ein violettes Leuchten, mal schwächer, mal stärker. Es kommt von der "
  "Chaosmagie, die die Burg durchzieht.");

  ME->AddDetail(({"magie","chaosmagie","chaos"}),
  "Die Chaosmagie ist überall in der Burg zu spüren. Sie kribbelt, "
  "knistert und flüstert.");

  ME->AddDetail(({"blick"}),
  "Auf den ersten Blick ist hier alles nur alt und verfallen. Auf den "
  "zweiten auch, aber irgendwie anders.");

  ME->AddSmell(({DEFAULT_SMELL,"luft"}),
  "Es riecht nach Staub und ein wenig nach Schwefel.");

  ME->AddSmell(({"schwefel","staub"}),
  "Alt, muffig und ein wenig schweflig.");

  ME->AddSound(({DEFAULT_SOUND}),
  "Irgendwo knistert es leise, und manchmal glaubst du, ein Flüstern zu "
  "hören.");

  ME->AddSound(({"flüstern","fluestern","knistern","magie"}),
  "Es ist zu leise, um etwas zu verstehen. Vielleicht bildest du es dir "
  "auch nur ein. Vielleicht.");

  ME->AddRoomMessage(({
    "Die Mauern um dich herum flimmern fuer einen Augenblick violett.\n",
    "Aus einem Riss in der Mauer dringt ein leises Fluestern.\n",
    "Ein kalter Hauch streicht an dir vorbei, obwohl kein Wind geht.\n",
    "Fuer einen Moment scheint ein Stein in der Mauer zu atmen.\n",
    "Irgendwo in der Burg lacht jemand, hoch und schrill.\n",
  }),90);
}
