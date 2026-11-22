// flaxtri.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

static string *txt;

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(18,360);
  SetProp(P_SHORT,capitalize(CHAOS_ID_FLAXTRI)+" der aetzende Saeuredaemon");
  SetProp(P_LONG,
  "Dieser Saeuredaemon ist etwas anders als seine Artgenossen, denn er "
  "kann laengere Zeit ohne ein Bad in einem Saeuresee auskommen, da seine "
  "Haut mit einer besonders dicken Schleimschicht geschuetzt ist. Auch fuer "
  "ihn gilt das Gleiche wie bei allen Saeuredaemonen: Man sollte ihn niemals "
  "knuddeln.");
  SetProp(P_NAME,capitalize(CHAOS_ID_FLAXTRI));
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE, 0);
  SetProp(P_ATTRIBUTES, ([ A_STR:22, A_DEX:22, A_INT:22, A_CON:22 ]) );
  SetProp(P_ALIGN, - 150);
  SetProp(P_HANDS, ({" mit aetzenden Krallen", 180, ({DT_ACID,DT_RIP}) }));
  SetProp(P_BODY, 90);
  SetProp(DAEM_PROZENT,80);
  SetProp(P_SIZE, 253);
  SetProp(P_WEIGHT,140000);
  SetProp(P_MSGIN,  "schleimt aetzend herein");
  SetProp(P_MSGOUT, "schleimt aetzend davon" );
  SetProp(P_MMSGIN, "erscheint in einem Saeureregen");
  SetProp(P_NOCORPSE, 1);
  SetProp(P_RESISTANCE,
  ([
    DT_ACID:     -0.9,
    DT_WATER:     0.8,
    DT_LIGHT:     0.3, 
    DT_DARKNESS: -0.3
  ]));
  SetProp(P_MATERIAL,
  ([
    MAT_ACID: 80,
    MAT_SLIME:10,
    MAT_MAGIC_BLACK:10,
  ]));
  SetProp(P_DIE_MSG, " verschwindet brodelnd im Erdreich.\n");

  AddId(({CHAOS_ID_FLAXTRI,CHAOS_ID_GILDENDAEMON,"saeuredaemon",
          CHAOS_ID_KAMPFDAEMON}));

  AddCmd(({"knuddel","knuddle","wuschel","wuschle","umarme","umarm",
           "wuerge","wuerg","streichel","streichle","kuess","kuesse"}),
           "saeure");
}

static int saeure(string str)
{
  if(!str)
    return 0;

  if(!id(str) && str != "alle" )
    return 0;

  if(present("schleim",PL))
    return 0;

  write(break_string("Du beruehrst den aetzenden "+Name(WEN)+". Ploetzlich "
        "spuerst Du einen brennenden Schmerz auf der Haut! Der Saeuredaemon "
        "veraetzt Dich sehr stark!"));

  say(break_string(PL->Name(WER)+" war so wahnsinnig, "+Name(WEN)+" zu "
      "knuddeln! Dieser Fehler wird mit Lebensentzug nicht unter 10 Punkten "
      "bestraft!"),({PL}));

  PL->reduce_hit_points(10+random(20));

  return 1;
}
