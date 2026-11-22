// graiop.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(12,300);
  SetProp(P_SHORT, capitalize(CHAOS_ID_GRAIOP)+" der rasende Feuerdaemon");
  SetProp(P_LONG,
  capitalize(CHAOS_ID_GRAIOP)+" ist ein gar flammiger Feuerdaemon. Seine "
  "lodernde Gestalt leuchtet grell. Zuengelnde Flammen lassen seine Formen "
  "verschwinden und heisser Atem steigt aus seinen Nuestern. ");
  SetProp(P_NAME,capitalize(CHAOS_ID_GRAIOP));
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_ALIGN,-100);
  SetProp(P_HANDS,({" mit flammenden Krallen",180,({DT_FIRE,DT_RIP}) }));
  SetProp(P_BODY,100);
  SetProp(DAEM_PROZENT,70);
  SetProp(P_SIZE,213);
  SetProp(P_WEIGHT,120000);
  SetProp(P_MSGIN, "erscheint in einem Meer aus Flammen");
  SetProp(P_MSGOUT, "lodert flammend davon");
  SetProp(P_NOCORPSE,1);
  SetProp(P_LIGHT,2);
  SetProp(P_RESISTANCE,
  ([
    DT_FIRE:     -1.0, 
    DT_WATER:     1.0,
    DT_DARKNESS: -0.3,
    DT_LIGHT:     0.3
  ]));
  SetProp(P_MATERIAL,
  ([
    MAT_LIVING:80,
    MAT_FIRE:10,
    MAT_MAGIC_BLACK:10,
  ]));
  SetProp(P_DIE_MSG," verschwindet in einer Feuerexplosion.\n");
  SetProp(P_MMSGIN,"erscheint in einem Meer aus Flammen");

  AddId(({CHAOS_ID_GRAIOP,CHAOS_ID_GILDENDAEMON,"feuerdaemon",
          CHAOS_ID_KAMPFDAEMON}));

  AddCmd(({"knuddel","knuddle","wuschel","wuschle","umarme","umarm",
           "wuerge","wuerg","streichel","streichle","kuesse",
           "kuess"}), "feuer" );
        
}

static int feuer(string str)
{
  if(!str)
    return 0;

  if(!id(str) && str != "alle" )
    return 0;
 
  write(break_string("Du beruehrst den lodernden "+name(WEN)+". Ploetzlich "
        "spuerst Du einen brennenden Schmerz auf der Haut! Der Feuerdaemon "
        "verbrennst Dich!"));

  say(break_string(PL->Name(WER)+" war so bescheuert, "+name(WEN)+" zu "
      "beruehren! Dieser Fehler wird mit 3 Punkten auf der nach oben offenen "
     "Dummkopf-Skala mitgelogt und mit irrsinnigen Schmerzen nicht unter "
     "10 Punkten bestraft!"), ({PL}));
 
  PL->reduce_hit_points(10+random(20));
 
  return 1;
}
