// bibliothek.c - Die Bibliothek der Burg Zwielichtstein
//
// Die alten Schriften der Gilde liegen in texte/. Man liest sie mit
// 'lies <kürzel>', das Inhaltsverzeichnis mit 'lies inhalt'.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit CHAOS_BURG_STD("drinnen");

// Kürzel -> Datei in texte/
#define SCHRIFTEN ([\
  "inhalt": "inhalt.txt",\
  "m1":     "wuqour.txt",\
  "s1":     "sprueche.txt",\
  "d1":     "daemonen.txt",\
  "c1":     "chaos.txt",\
  "m2":     "hutschat.txt",\
  "q1":     "quest.txt",\
  "m3":     "kruuolq.txt",\
  "r1":     "raenge.txt",\
  "m4":     "achtarch.txt",\
  "c2":     "chaoshaut.txt",\
  "z1":     "zutaten.txt",\
  "p1":     "pentagramm.txt",\
  "n1":     "notizen.txt",\
  "n2":     "notizen2.txt",\
  "z2":     "zardoz.txt",\
])

static int lies(string str) {
  mapping schriften = SCHRIFTEN;
  string txt;

  notify_fail("Was willst du lesen? Das Verzeichnis liest du mit 'lies "
              "inhalt'.\n");

  if(!str) {
    return 0;
  }
  str = lower_case(str);

  if(str == "verzeichnis" || str == "inhaltsverzeichnis") {
    str = "inhalt";
  }
  if(!member(schriften,str)) {
    return 0;
  }
  txt = read_file(CHAOS_GILDEN_TXT(schriften[str]));

  if(!txt) {
    write("Die Seiten sind so verblasst, dass du nichts lesen kannst.\n");
    return 1;
  }
  say(PL->Name(WER)+" vertieft sich in eine alte Schrift.\n");
  PL->More(txt);
  return 1;
}

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();

  AddCmd(({"lies","lese"}),"lies");
}
