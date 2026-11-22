// nw.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 12.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit

#include "def.h"

inherit CHAOS_GILDEN_ARENA("std/arena");

static int a_time;

protected void create() {
  ::create();
  SetProp(P_INT_LONG,
  "Du befindest Dich im nordwestlichen Rund der Duellarena. Die hohen, "
  "glatten Waende bieten keine Moeglichkeit zu entkommen, aber das "
  "viele Blut ueberall zeigt eindringlich, dass es besser waere, hier "
  "schnell zu verschwinden.");

  AddDetail(({"wand","waende"}),
  "Die Waende sind sehr glatt und unueberwindlich hoch. Sie bestehen aus "
  "einem harten Sandstein, der ueberall schon Spuren erbitterter Kaempfe "
  "zeigt. An mehreren Stellen erkennst Du Klappen und Oeffnungen, die "
  "im Stein eingelassen sind." );

  AddDetail(({"spur","spuren","kampfspur","kampfspuren"}),
  "Die Spuren des Kampfes bestehen zum groessten Teil aus Blut. "
  "Allerdings sind in den Waenden auch einige Scharten und Risse von "
  "Waffen, die von unvorsichtigen oder panischen Kaempfern ungeschickt "
  "geschwungen wurden.");

  AddDetail(({"scharte","scharten","riss","risse"}),
  "Diese Spuren von heftigsten Kaempfen haben die Waende nur "
  "oberflaechlich beschaedigt.");

  AddDetail(({"stein","sandstein"}),
  "Die Waende sind aus hartem Sandstein gemauert. Da selbst harter "
  "Sandstein nicht besonders haltbar ist, findest Du ueberall Spuren, "
  "die auf heftige Kaempfe hinweisen. Seltsam sind die vielen Klappen "
  "und kleinen Oeffnungen. Wofuer die wohl gut sind?");

  AddDetail(({"klappe","klappen"}),
  "Du untersuchst die Klappen gruendlich, kannst aber keinen Mechanismus "
  "erkennen, mit dem diese zu oeffnen waeren. Neben einer Klappe faellt "
  "Dir ein unscheinbarer Knopf auf.");

  AddDetail("knopf",
  "Der Knopf ist recht unauffaellig und Du findest ueberhaupt keinen "
  "Hinweis, was dieser Knopf wohl ausloesen koennte.");

  AddDetail(({"oeffnungen","oeffnung"}),
  "Was mag da wohl aus den Oeffnungen herauskommen? Jedenfalls sind sie "
  "viel zu klein, um sich darin zu verstecken.");

  AddDetail(({"boden","fussboden"}),
  "Du stehst im feinen Sand der Duellarena. Neben Blut, viel Blut und "
  "noch mehr Blut kannst Du auch noch angetrocknetes Blut, geronnenes "
  "Blut und verschimmeltes Blut entdecken.");

  AddDetail("sand",
  "Der Sand der Arena ist voller Blut. Du siehst wirklich nur Blut, Blut, "
  "Blut, einen Hebel und Blut.");

  AddDetail("hebel",
  "Was macht denn der Hebel da mitten im Sand? Ob man daran ziehen kann? "
  "Am Hebel kann man sicherlich ziehen, aber wenn das Geruecht wirklich "
  "stimmt und Zardoz diese Arena gebaut hat, dann sollte man es besser "
  "nicht versuchen.");

  AddCmd(({"druecke","drueck"}),"knopf");
  AddCmd(({ "zieh", "ziehe" }), "hebel" );

  AddExit("osten",     CHAOS_GILDEN_ARENA("no"));
  AddExit("sueden",    CHAOS_GILDEN_ARENA("sw"));
  AddExit("suedosten", CHAOS_GILDEN_ARENA("so"));
}

void init() {
  ::init();
  if(find_call_out( "action")==-1) {
    call_out("action", 30+ random(60));
  }
}

static int knopf(string str) {
  object ob;

  if(!str) {
    return 0;
  }
  if(str!="knopf") {
    return 0;
  }
  if(a_time + 40 > time()) {
    write("Du drueckst auf den Knopf aber nichts passiert.\n");
    return 1;
  }
  if(PL->QueryProp(P_ATTACK_BUSY)) {
    write("Immer schoen langsam! Nur nichts ueberstuerzen!\n");
    return 1;
  }
  PL->SetProp(P_ATTACK_BUSY,1);

  write(break_string("Du drueckst auf den Knopf und Pfeile schiessen aus "
        "den Waenden!"));

  say(break_string("Ploetzlich schiessen Pfeile aus den Waenden! Du wirst "
      "getroffen!"));

  foreach(ob:filter(all_inventory(this_object()), #'living)) {
    if(ob == PL) {
      continue;
    }
    ob->Defend(random(500),DT_PIERCE,([SP_SHOW_DAMAGE:1,
                                       SP_PHYSICAL_ATTACK:1]),PL);
  }
  a_time = time();
  return 1;
}


static int hebel(string str) {
  string en;
  object ob;

  if(!str) {
    return 0;
  }
  if(str!="hebel" && str!= "an hebel") {
    return 0;
  }
  if(PL->QueryProp(P_ATTACK_BUSY)) {
    write("Immer schoen langsam! Nur nichts ueberstuerzen!\n");
    return 1;
  }
  PL->SetProp(P_ATTACK_BUSY, 1);

  if(a_time +50 > time()) {
    write("Du ziehst am Hebel aber nichts passiert. Pech (oder Glueck) "
          "gehabt.\n");
    return 1;
  }
  write(break_string("Du ziehst am Hebel und loest eine wirklich "
        "heimtueckische Falle aus. Die ganze Arena, bis auf den Bereich, "
        "in dem Du gerade stehst, wird in eine dicke Giftwolke "
        "gehuellt!" ));

  foreach(en:get_targets(({"no","so","sw"}))) {
    ob = find_player(en);

    if(!ob) {
      continue;
    }
    tell_object(ob,break_string("Eine dichte Giftwolke steigt unerwartet "
                "empor! "+PL->name(WER)+" hat eine gemeine Falle "
                "ausgeloest!"));

    ob->Defend(200+random(400),DT_ACID,0,PL);
  }
  a_time = time();
  return 1;
}

void action() {
  switch(random(3)) {
    case 0:
    tell_room(ME,break_string("Aus einer Klappe faehrt eine lange Roehre "
                 "heraus, und verfolgt jede Deiner Bewegungen."));
    call_out("attack_1", 2+random(5));
    break;

    case 1:
    tell_room(ME,break_string("Mit einem lauten Zischen stroemt "
                 "ploetzlich dichter Nebel aus zahlreichen Oeffnungen der "
                 "Waende."));
    call_out("attack_2", 2+random(5));
    break;

    case 2:
    tell_room(ME,break_string("Ein Klappe oeffnet sich und ein langer "
                "Greifarm faehrt heraus. Am Ende dieses Armes ist ein "
                "riesiges Schwert befestigt, das nun in kreisfoermigen "
                "Bewegungen durch die Arena wandert und auf Dich "
                "zukommt!"));
    call_out("attack_3", 2+random(5));
    break;
  }
}

void attack_1() {
  tell_room(ME,break_string("Aus der Roehre schiesst ploetzlich ein "
               "gewaltiger Feuerball, der Dich sehr hart trifft!" ));

  SetProp(P_NAME, "Ein Feuerball" );

  room_damage(10+random(20));
}

void attack_2() {
  tell_room(ME,break_string("Der Nebel huellt Dich ein und nimmt Dir "
               "die Sicht. Doch das ist harmlos im Vergleich zu der "
               "Wirkung, die dieser Nebel auf Deine Lunge ausuebt. Dir "
               "wird schlecht und uebel, Du hustest fuerchterlich."));

  SetProp(P_NAME, "Der Nebel des Todes" );

  room_damage(20+random(10));
}

void attack_3() {
  tell_room(ME,break_string("Der Greifarm schwingt das Schwert wild "
               "herum und kommt genau auf Dich zu. Bevor Du ausweichen "
               "kannst, trifft Dich schon die scharfe Klinge!"));

  SetProp(P_NAME,"Ein riesiges Schwert" );

  room_damage(5+random(25));
}
