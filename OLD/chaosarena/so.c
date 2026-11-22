// so.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 12.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit

#include "def.h"

inherit CHAOS_GILDEN_ARENA("std/arena");

static int halm, a_time;

protected void create() {
  ::create();
  SetProp(P_INT_LONG,
  "Die suedoestliche Ecke der runden Duellarena sieht auch nicht viel "
  "ansprechender aus, als der restliche Kampfplatz. Die hohe Mauer mit "
  "ihren bedrohlichen Klappen und Oeffnungen, der blutgetraenkte Sand... "
  "All dies macht einen Aufenthalt nicht gerade angenehm.");

  AddDetail("ecke",
  "Ja ja ja. Ein runder Raum hat keine Ecken.");

  AddDetail(({"wand","waende"}),
  "Die Sandsteinwand ist mit huebschen Klappen und Oeffnungen verziert, "
  "die mit absoluter Sicherheit voellig ungefaehrlich und harmlos sind. ");

  AddDetail(({"stein","sandstein"}),
  "Der hellbraune Sandstein ist recht hart. Um dies zu testen, rammst Du "
  "Deinen Kopf kraeftig gegen die Wand, die keinen Zentimeter nachgibt "
  "(Dein harter Schaedel allerdings auch nicht :-)).");

  AddDetail(({"klappe","klappen"}),
  "Die Klappen sind alle geschlossen und Du kannst keinen Mechanismus "
  "entdecken, mit dem diese zu oeffnen waeren.");

  AddDetail(({"oeffnungen","oeffnung"}),
  "Kleine Oeffnungen unbestimmbarer Tiefe sind ueberall in die Wand "
  "eingelassen und strahlen eine unterschwellige Bedrohung aus, die Du Dir "
  "nicht so recht erklaeren kannst.");

  AddDetail(({"boden","fussboden"}),
  "Der Boden ist auch hier mit einer dicken Sandschicht bedeckt, die das "
  "Blut aufnehmen soll.");

  AddSpecialDetail(({"sandschicht","schicht","sand"}),"sand" );
  AddSpecialDetail(({"grashalm","pflanze","halm"}),"halm2" );


  halm = 1;

  AddCmd(({"ziehe","zieh","pfluecke","pflueck"}),"halm");

  AddExit("westen",     CHAOS_GILDEN_ARENA("sw"));
  AddExit("norden",     CHAOS_GILDEN_ARENA("no"));
  AddExit("nordwesten", CHAOS_GILDEN_ARENA("nw"));
}

void init() {
  ::init();
  if(find_call_out("action")==-1) {
    call_out("action",10+random(50));
  }
}

static int halm( string str) {
  object opfer;
  string ob;

  if(!str) {
    return 0;
  }
  if(str!="halm" && str!="grashalm" && str!="an grashalm" && str!="an halm") {
    return 0;
  }
  if(a_time + 80 < time()) {
    halm=1;
  }
  if(!halm) {
    return 0;
  }
  halm = 0;

  a_time = time();

  write(break_string("Du pflueckst den einzelnen Grashalm, der versteckt "
        "im Sand waechst und loest dabei eine Falle aus, die allerdings "
        "nicht Dich trifft. Vielmehr schiesst ploetzlich aus der Wand ein "
        "Schwarm von schweren Pfeilen, der geschwind nach Norden fliegt."));

  say(break_string(capitalize(getuid(PL))+" pflueckt einen einzelnen "
      "Grashalm vom Boden. Damit loesst "+
      (PL->QueryProp(P_GENDER)==FEMALE?"sie":"er")+" eine Falle aus und es "
      "fliegen einige Pfeile aus der suedlichen Wand. Zum Glueck treffen "
      "sie Dich nicht, sondern fliegen weiter nach Norden."));

  foreach(ob:get_targets(({"no"}))) {
    if(!opfer = find_player(ob)) {
      continue;
    }
    tell_object(opfer,break_string("Von Norden fliegen ploetzlich mehrere "
                      "dicke Pfeile herein. Leider kannst Du einem "
                      "davon nicht mehr ausweichen!"));

    opfer->Defend(150+random(300),DT_PIERCE,([SP_PHYSICAL_ATTACK:1]),PL);
  }
  return 1;
}

string halm2() {
  if(!halm) {
    return "Was fuer ein Halm? Sowas findest Du hier nicht!\n";
  }
  return break_string("Ja gibt es denn sowas? Selbst in diesem Ort des "
         "Schreckens und des Todes waechst eine (wenn auch kleine) Pflanze. "
         "Sie ist nicht sehr hoch und besteht nur aus einem einzigen "
         "Halm.");
}

string sand() {
  if(!halm) {
    return break_string("Der feine Sand ist blutdurchtraenkt.");
  }
  return  break_string("Im feinen, blutdurchtraenkten Sand entdeckst "
          "Du ein einzelnen Grashalm.");
}

void action() {
  switch(random(3)) {
    case 0:
    tell_room(ME,break_string("Aus dem Sand erhebt sich ein seltsam "
                 "geformtes Rohr. Es scheint Dich irgendwie anzustarren."));

    call_out("attack_1", 2+random(5));
    break;

  case 1:
    tell_room(ME,break_string("Mit einem lauten Zischen stroemt ploetzlich "
                 "dichter Nebel aus zahlreichen Oeffnungen der Waende."));

    call_out("attack_2", 2+random(5));
    break;

  case 2:
    tell_room(ME,break_string("Mehrere kleine Oeffnungen entstehen in der "
                 "Mauer. Du hoerst es Rumpeln."));

    call_out("attack_3", 2+random(5));
    break;
  }
}

void attack_1() {
  tell_room(ME,break_string("Aus dem Rohr schiesst ploetzlich ein Schwall "
               "aetzender Saeure, die Dich genau trifft!"));

  SetProp(P_NAME, "Saeure" );

  room_damage(10+random(20));
}

void attack_2() {
  tell_room(ME,break_string("Der Nebel huellt Dich ein und nimmt Dir die "
               "Sicht. Doch das ist harmlos im Vergleich zu der Wirkung, "
               "die dieser Nebel auf Deine Lunge ausuebt. Dir wird schlecht "
               "und uebel, Du hustest fuerchterlich!"));

  SetProp(P_NAME,"Der Nebel des Todes");

  room_damage(20+random(10));
}

void attack_3() {
  object ob;

  tell_room(ME,break_string("Aus den zahlreichen Oeffnungen fliegen mit "
               "unglaublicher Geschwindigkeit kleine Stahlkugeln heraus, "
               "wobei eine Dich genau an der Schlaefe trifft!"));

  foreach(ob:filter(all_inventory(),#'living)) {
    ob->SetProp(P_DISABLE_ATTACK, ob->QueryProp(P_DISABLE_ATTACK)+
                                  10+random(20));
  }
}
