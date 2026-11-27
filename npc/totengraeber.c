// totengraeber.c - Modrich, der Totengräber in der Gruft
//
// Sortiert die Knochen der Burgherren, damit die Chaoten sie für ihre
// Rituale nicht lange suchen müssen.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types

#include "def.h"

inherit CHAOS_GILDEN_MON("std/bewohner");

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(14,320);

  SetProp(P_NAME,"Modrich");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_SHORT,"Modrich, der Totengräber");
  SetProp(P_LONG,
  "Modrich ist ein krummer, alter Chaot mit erdigen Händen und einem "
  "zufriedenen Lächeln. Er hält einen Knochen ins Licht, prüft ihn "
  "fachmännisch und legt ihn dann in einen der Körbe. Über seine "
  "Schulter hängt eine Schaufel.");
  SetProp(P_HANDS,({" mit seinen knochigen Händen",130,({DT_BLUDGEON})}));
  AddId(({"modrich","totengraeber","totengräber",CHAOS_ID_TOTENGRAEBER}));
  AddAdjective(({"krumm","krummen","alt","alten"}));

  AddDetail(({"haende","hände","erde"}),
  "Erdig, mit schwarzen Rändern unter den Nägeln.");
  AddDetail(({"laecheln","lächeln"}),
  "Zufrieden. Er liebt seine Arbeit.");

  bewohner_geld(30+random(40));
  AddItem(POOL_MISC "schaufel",REFRESH_REMOVE);
  AddItem(POOL_KOMPOS "CHAOS_knochenmehl",REFRESH_REMOVE);

  SetChats(8,({
    "Modrich legt einen Schaedel in den Korb mit den Schaedeln.\n",
    "Modrich murmelt: Lange Knochen, lange Knochen... Kleinzeug.\n",
    "Modrich klopft dem Skelett in der Nische auf die Schulter: "
    "Irgendwann sortier ich dich auch.\n",
    "Modrich pfeift ein schiefes Lied und sortiert weiter.\n",
  }));

  AddInfo(DEFAULT_INFO,({
    "Lange Knochen oder Kleinzeug?",
    "Hm, hm. Frag mich was über Knochen.",
  }),"fragt: ");

  AddInfo(({"knochen","koerbe","körbe","sortieren"}),
  "Schädel, lange Knochen, Kleinzeug. Wer ein Ritual braucht, holt sich, "
  "was er braucht. Ordnung muss sein.","sagt: ");

  AddInfo(({"skelett"}),
  "Der da in der Nische will nicht sortiert werden. Respekt.",
  "kichert: ");

  AddInfo(({"grabkammer","sarkophag","herr","burgherr"}),
  "Der letzte Herr von Zwielichtstein. Sein Sarkophag ist leer. War er "
  "schon, als ich kam. Der Riss oben im Turm hat wohl mit ihm zu tun.",
  "flüstert: ");

  AddInfo(({"stern","gesprungener stern"}),
  "Das Wappen der Burgherren. Gebrochen, wie alles hier.","sagt: ");

  AddInfo(({"knochenmehl","ritual","rituale"}),
  "Aus dem Kleinzeug mache ich Knochenmehl. Das gibt die besten "
  "Pentagramme.","sagt stolz: ");

  AddInfo(({"modrich","totengraeber","totengräber"}),
  "Ich kümmere mich um die Toten. Die beschweren sich wenigstens nicht.",
  "sagt: ");
}
