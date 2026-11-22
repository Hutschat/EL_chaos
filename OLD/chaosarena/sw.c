// no.c
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
  "Du stehst vor dem westlichen Tor der Duellarena. Dies ist vielleicht "
  "noch nichts besonderes, doch leider stehst Du eindeutig auf der "
  "falschen Seite dieses Tores, denn Du bist nun IN der Arena, in der "
  "schon so mancher seinen ewigen Schlaf gefunden hat (bis zum Aufwachen "
  "in der Kapelle natuerlich). Die hohe Sandsteinmauer, die die Arena "
  "umgibt, soll feige Kaempfer vom unehrenhaften Verlassen dieses "
  "gefuerchteten Kampfplatzes abhalten, was ihr auch vervorragend zu "
  "gelingen scheint. Denn das viele Blut spricht eine eindeutige Sprache.");

  AddDetail(({"wand","waende"}),
   "Die Waende sind aus hartem Sandstein gearbeitet, der schon zahlreiche "
   "Spuren heftiger Kaempfe traegt. Was es mit den Klappen und Oeffnungen "
   "auf sich hat, willst Du gar nicht so genaus wissen. Von ihnen geht "
   "eine Bedrohung aus, die Dir einen Schauer ueber den Ruecken jagt.");

  AddDetail("tor",
  "Das Tor steht offen, Du koenntest jederzeit diesen Ort verlassen.");

  AddDetail(({"spur","kampfspuren","kampfspur","spuren"}),
  "Spuren von unzaehligen Kaempfen zeichnen diese Waende.");

  AddDetail(({"stein","sandstein"}),
  "Der harte Sandstein hat nur eine Aufgabe und diese vollbringt er in "
  "Form einer Mauer, die Fluchtversuche verhindern soll, hervorragend.");

  AddDetail(({"klappe","klappen"}),
  "Ploetzlich oeffnet sich eine der Klappen und eine riesige Faust "
  "schiesst heraus, die Dich hart am Kopf trifft und ihn zu einem Brei "
  "aus Knochensplitter und Gehirn vermatscht..... Man, hast Du eine "
  "seltsame Phantasie! Wie kannst Du Dir sowas nur einbilden? Erschreckt "
  "von Deinen eigenen Gedanken schaust Du nochmal genau hin und siehst "
  "nur zahlreiche, gewoehnliche Klappen.");

  AddDetail(({"oeffnungen","oeffnung","loecher"}),
  "Viele kleine Oeffnungen sind in den Waenden hinein gebohrt. Ihre "
  "Bedeutung ist nicht leicht zu erkennen, aber vielleicht hilft ja das "
  "Schild weiter, das neben einem der Loecher haengt.");

  AddDetail("loch",
  "Das Loch, neben dem das Schild haengt, ist etwas groesser, so dass man "
  "leicht hineingreifen koennte.");

  AddDetail("schild",
  "Auf dem Schild befindet sich ein grosser, roter Pfeil, der genau auf "
  "ein Loch zeigt. Ueber diesem Pfeil steht etwas geschrieben.");

  AddReadDetail("schild",
  "Bitte greifen sie in dieses Loch!");

  AddDetail(({"boden","fussboden"}),
  "Wie es fuer Duellarenen ueblich ist, so ist auch hier der Boden mit "
  "einer Schicht aus feinem Sand bedeckt. Wenn nicht ueberall soviel Blut "
  "waere, so koennte sich ein Sandtiger hier sicherlich wohl fuehlen.");

  AddDetail(({"sandschicht","schicht","sand"}),
  "Der rote Sand ist an einigen Stellen noch hellbraun.");

  AddDetail("blut",
  GetDetail("blut",0,1)+" Direkt vor Dir befindet sich eine besonders "
  "grosse Pfuetze.");

  AddDetail(({"pfuetze","blutpfuetze"}),
  "Huch, was ist denn das? Aus der Pfuetze ragt doch tatsaechlich ein "
  "kleiner, roter Hebel, den Du jetzt erst bemerkst.");

  AddDetail("hebel",
  "Was wohl passiert, wenn man an diesem Hebel zieht? Vielleicht solltest "
  "Du es besser nicht ausprobieren.");

  AddCmd(({"ziehe","zieh"}),   "hebel");
  AddCmd(({"greife","greif"}), "loch");

  AddExit("osten",     CHAOS_GILDEN_ARENA("so"));
  AddExit("norden",    CHAOS_GILDEN_ARENA("nw"));
  AddExit("nordosten", CHAOS_GILDEN_ARENA("no"));

  AddSpecialExit("westen","go_west");
}

void init() {
  ::init();
  if(find_call_out( "action")==-1) {
    call_out( "action", 30+ random(60));
  }
}

static int loch(string str) {
  string ob;

  if(!str) {
    return 0;
  }
  if(str != "loch" && str != "in loch") {
    return 0;
  }
  if(a_time + 30 > time()) {
    write("Du greifst in das Loch. Leider ist es vollkommen leer.\n");
    return 1;
  }
  switch(random(2)) {
    case 0:
    write(break_string("Du greifst in das Loch und ertastest einen kleinen "
          "Knopf, den Du, wahnsinnig wie Du bist, sofort drueckst. Du hast "
          "aber mal wieder viel Glueck gehabt, denn die gewaltige "
          "Feuersaeule, die aus der Wand nach Osten schiesst, erwischt "
          "Dich nicht."));

    say(break_string(capitalize(getuid(PL))+" greift in ein kleines Loch. "
        "Ploetzlich schiesst aus der Wand eine gewaltige Feuersaeule, die "
        "nach Osten braust und dort explodiert!"));

    foreach(ob:get_targets(({"so"}))) {
      tell_object(find_player(ob),break_string("Von Westen schiesst eine "
                  "gewaltige Feuersaeule herein und explodiert mit einem "
                  "lauten Knall. Seltsam, aber die Explosion formt das "
                  "Wort: "+capitalize(getuid(PL))+"."));

      find_player(ob)->Defend(150+random(300),DT_FIRE,
                                              ([SP_SHOW_DAMAGE:1]),PL);
    }
    a_time = time();
    break;

    case 1:
    write(break_string("Du greifst in das kleine Loch und spuerst einen "
          "stechenden Schmerz in Deiner Hand. Irgendwas hat Dich "
          "gestochen!"));

    PL->reduce_hit_point(5+random(10));

    break;
  }
  return 1;
}

static int hebel(string str) {
  object opfer;
  string ob;

  if(!str) {
    return 0;
  }
  if(str!="hebel" && str!="an hebel") {
    return 0;
  }
  if(PL->QueryProp(P_ATTACK_BUSY)) {
    write("Nicht so schnell! Immer schoen langsam!\n");
    return 1;
  }
  PL->SetProp(P_ATTACK_BUSY, 1);

  if(a_time + 100 > time())
  {
    write("Du ziehst am Hebel aber nichts passiert.\n");
    return 1;
  }

  a_time = time();

  write(break_string("Der Hebel loest einen maechtigen Zauber aus, der die "
        "westliche Haelfte der Arena erfuellt und dort Magie aufsaugt."));

  call_other(CHAOS_GILDEN_ARENA("nw"),"irgend_ein_bloeder_mist_was_sonst?",0);

  foreach(ob:get_targets(({"nw","sw"}))) {
    if(!opfer = find_player(ob)) {
      continue;
    }
    if(opfer == PL) {
      continue;
    }
    tell_object(opfer,break_string("Ploetzlich wird die ganze westliche "
                     "Haelfte der Arena in ein schimmerndes Licht maechtiger "
                     "Magie gehuellt und Du spuerst, wie Dir Deine eigene Magie "
                     "entzogen wird."));

    opfer->SetProp(P_SP,opfer->QueryProp(P_SP)/3 );
  }
  return 1;
}

void action() {
  switch(random(3)) {
    case 0:
    tell_room(ME,"Du hoerst ein Rumpeln. Was das wohl sein mag?\n");
    call_out("attack_1", 2+ random(5) );
    break;

    case 1:
    tell_room(ME,break_string("Eine Klappe oeffnet sich und schliesst sich "
                 "dann dann wieder. Merkwuerdig."));
    call_out("attack_2", 2 + random(5) );
    break;

    case 2:
    tell_room(ME,break_string("Eine oelige, schmierige Fluessigkeit fliesst "
                 "aus zahlreichen Oeffnungen und breitet sich in der Arena "
                 "aus!"));
    call_out("attack_3", 2 + random(5) );
    break;
  }
}

void attack_1()
{
  tell_room(ME,break_string("Alle Klappen oeffnen sich und mit einem lauten "
              "Poltern fallen einige grosse Steine heraus. Leider fallen sie "
              "nicht zu Boden, sondern genau auf Dich!"));

  SetProp(P_NAME, "Ein Stein" );

  room_damage(10+random(20));
}

void attack_2() {
  tell_room(ME,"Irgendetwas Unsichtbares trifft Dich hart!\n");

  SetProp(P_NAME, "Irgendetwas Unsichtbares" );

  room_damage(20+random(10));
}

void attack_3() {

  tell_room(ME,break_string("Die Fluessigkeit entzuendet sich und brennt "
               "mit vernichtender Hitze. Du empfindest diese Hitze als "
               "recht unangenehm."));

  SetProp(P_NAME, "Eine zu hohe Tempertatur" );

  room_damage(5+random(25));
}

int go_west() {
  write("Das Tor ist grundsaetzlich immer verschlossen!\n");
  return 1;
}
