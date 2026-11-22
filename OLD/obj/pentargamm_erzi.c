// pentargamm_erzi.c
//
// Letzte Aenderung:
//
// 11.03.2019 It@Efferdland            ueberarbeitet
 
#pragma no_inherit

#include "def.h"

inherit "/std/thing";

string pent_zeichner() {
  if(!PL) {
    return "";
  }
  if(!query_once_interactive(PL)) {
    return "";
  }
  return capitalize(QueryProp(CHAOS_PENTAGRAMM_ZEICHNER));
}

string my_long() {
  string wer;

  wer = pent_zeichner();

  if(capitalize(getuid(PL)) == wer) {
    wer = "Du bist";
  }
  else {
    wer += " ist";
   }
  return break_string("Dieses Pentagramm ist einzigartig. Es ist aelter als "
  "die Zeit und scheint aus einer Dimension fern dieser Realitaet zu "
  "stammen. Fast koerperlich fuehlst Du die unheilige Magie, die davon "
  "ausgeht. Einzig "+wer+" in der Lage, diese Macht zu beherrschen. Du "
  "kannst es betreten.");
}

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT,
  "Ein unheiliges, waberndes Pentagramm schwebt in der Luft");
  Set(P_LONG,#'my_long,F_QUERY_METHOD);
  SetProp(CHAOS_BANNKREIS,2);
  SetProp(CHAOS_PENTAGRAMM_FAKTOR,155);
  SetProp(CHAOS_BANNKREIS_FAKTOR,200);
  SetProp(CHAOS_BANNKREIS_ART,
  "Ein mit reinster Chaosenergie gezeichnetes Pentagramm.");
  SetProp(P_NAME,"Pentagramm");
  SetProp(P_GENDER,0);
  SetProp(P_NOGET,1);
  SetProp(P_MATERIAL,
  ([
    MAT_SHADOW:50,
    MAT_MAGIC_BLACK:50
  ]));
  SetProp(P_INFO,
  break_string("Eine maechtige Magie liegt auf diesem Pentagramm "
  "und keine Macht des Universums ist faehig, es zu zerstoeren."));

  AddId(({"\nchaos_gilden_pentagramm","pentagramm"}));

  AddCmd(({"stelle","stell","setze","setz"}),"bestuecke_pentagramm");
  AddCmd(({"wische","wisch","loesche","loesch"}),"loesche_pentagramm");
}

void init() {
  string erz;
  ::init();

  SetProp(CHAOS_PENTAGRAMM_ZEICHNER,

  erz = call_other(CHAOS_GILDENMASTER,"query_erzmeister",0));

  if(!id("\nchaos_gilden_pentagramm_"+erz)) {
    AddId("\nchaos_gilden_pentagramm_"+erz);
  }
}

static int loesche_pentagramm(string str) {
  string penta;

  if(!str) {
    return 0;
  }
  notify_fail( "Was willst Du loeschen?\n");

  if(sscanf( str, "%s weg", penta) != 1) {
    return 0;
  }
  if(!id(penta)) {
    return 0;
  }
  if(QueryProp(CHAOS_PENTAGRAMM_ZEICHNER) != getuid(PL)) {
    notify_fail("Du darfst dieses Pentagramm nicht wegwischen!\n");
    return 0;
  }
  if(penta=="pentagramm") {
    write("Dieses Pentagramm kann man nicht wegwischen!\n");
    return 1;
  }
  if(penta == "bannkreis") {
    write("Der Bannkreis ist zu maechtig. Es gelingt Dir nicht.\n");
    return 1; 
  }
  return 0;
}
