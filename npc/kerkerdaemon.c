// kerkerdaemon.c - Ein entlaufener Dämon im Verlies der Burg
//
// Die Chaoten sperren ins Verlies, was ihnen entwischt ist und wieder
// eingefangen wurde.
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
  string *art  = ({"rote","graue","schwarze","schuppige"});
  string *lang = ({
    "Er ist klein, rot und hat sehr viele Zähne. Vermutlich ist er der "
    "Dämon, den alle suchen.",
    "Er ist grau, ledrig und hat eine Narbe quer über dem Gesicht.",
    "Er ist schwarz wie Ruß und raucht leicht an den Rändern.",
    "Seine Schuppen glänzen feucht, und er riecht nach Sumpf.",
  });
  int i;

  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(20,520);

  i = random(sizeof(art));

  SetProp(P_NAME,"Dämon");
  SetProp(P_GENDER,MALE);
  SetProp(P_NAME_ADJ,art[i]);
  SetProp(P_SHORT,"Ein "+art[i]+"r Dämon hinter Gittern");
  SetProp(P_LONG,
  "Ein entlaufener Dämon, den die Chaoten wieder eingefangen und ins "
  "Verlies gesperrt haben. "+lang[i]+" Er zerrt an den Gitterstäben "
  "und faucht dich an.");
  SetProp(P_RACE,"Dämon");
  SetProp(P_ALIGN,-600);
  SetProp(P_SIZE,90+random(80));
  SetProp(P_HANDS,({" mit seinen Klauen",200,({DT_RIP,DT_FIRE})}));
  AddClass(({CL_DEMON,CL_SKIN,CL_WALKING}));
  AddId(({"daemon","dämon","kerkerdaemon","kerkerdämon",
          CHAOS_ID_KERKERDAEMON}));
  AddAdjective(({"entlaufen","entlaufenen"}));

  AddDetail(({"klauen","zaehne","zähne"}),
  "Scharf und zahlreich.");
  AddDetail(({"gitter","gitterstaebe","gitterstäbe"}),
  "Er zerrt daran, aber sie halten.");

  SetChats(8,({
    "Der Daemon zerrt an den Gitterstaeben.\n",
    "Der Daemon faucht dich an.\n",
    "Der Daemon kratzt mit den Klauen ueber den Steinboden.\n",
    "Der Daemon starrt dich mit gluehenden Augen an.\n",
  }));

  AddInfo(DEFAULT_INFO,
  "faucht nur und zeigt die Zähne.\n");
}
