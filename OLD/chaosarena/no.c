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
  "Dies ist das nordoestliche Ende der kleinen und feinen Duellarena. In "
  "der hohen, unueberwindlichen Mauer aus hartem Sandstein ist hier "
  "ein Tor eingelassen, das Dich hinaus aus diesem Ort des Schreckens "
  "bringt. Hier haben schon viele die Arena verlassen, die meisten "
  "allerdings in kleinen, hoelzernen Kisten, sofern ueberhaupt noch "
  "etwas von ihnen uebrig war.");

  AddSpecialDetail(({ "duellarena", "arena" }), "arena" );

  AddDetail(({"kiste","kisten"}),
  "Du kannst hier zwar keine Kisten sehen, Du kannst sie Dir aber "
  "bildlich vorstellen.");

  AddDetail(({"wand","waende"}),
  "Die Waende sind eigentlich nicht besonders interessant. Was aus den "
  "zahlreichen Klappen und Oeffnungen herauskommt, moechtest Du lieber "
  "gar nicht erst wissen. Den einzigen Hoffnungsschimmer neben den "
  "unzaehligen Spuren der vielen Kaempfe ist das Tor, das hinaus in "
  "eine bessere und gerechtere Welt fuehrt.");

  AddDetail("welt"
  "Die Welt soll draussen besser und gerecht sein? Wers glaubt wird "
  "seelig...");

  AddDetail("tor"
  "Das Tor steht offen, Du koenntest jederzeit diesen Ort verlassen.");

  AddDetail(({"spur","kampfspuren","kampfspur","spuren"}),
  "Hier haben schon wirklich schlimme und ueble Gestalten ihr Unwesen "
  "getrieben. Anders sind die tiefen Kerben und Kratzer im harten "
  "Gestein nicht zu erklaeren. Und dann ist da ja noch diese Unmenge an "
  "mehr oder weniger frischem Blut.");

  AddDetail("kerben",
  "Tiefe Kerben im Sandstein deuten auf maechtige Waffen hin, die hier "
  "schon verwendet worden sind. Vielleicht waere es besser, sich auch "
  "so eine Waffe zu besorgen (fragt sich bloss wo?).");

  AddDetail("kratzer",
  "Die Kratzer stammen von Waffen, die gegen die Waende aus Verzweiflung "
  "oder Ungeschick geschlagen wurden. Ein Kratzer sieht allerdings "
  "etwas ungewoehnlich aus. Er erinnert entfernt an eine krakelige "
  "Schrift, doch das ist wohl nur Zufall.");

  AddDetail(({"schrift","produkt","zufallsprodukt"}),
  "Diese Schrift ist wohl nur das Zufallsprodukt eines Kratzens mit "
  "einer harten Waffe an den Sandstein der Mauer. Es sieht jedenfalls "
  "nicht so aus, als ob man sie lesen koennte.");

  AddReadDetail(({"schrift","produkt","zufallsprodukt"}),
  "Die Schrift ist fast unmoeglich zu lesen, falls es ueberhaupt eine "
  "Schrift sein soll. Du fragst Dich naemlich, was 'goemwexx' bedeuten "
  "soll.");

  AddDetail(({"stein","sandstein"}),
  "Die Kampfspuren sind nicht das einzig seltsame an diesem Sandstein. "
  "Viellmehr irritieren Dich die unzaehligen Klappen und Oeffnungen.");

  AddDetail(({"klappe","klappen"}),
  "Die Klappen sind in den Waenden der Duellarena eingelassen und sehen "
  "sehr verdaechtig aus. Allerdings kannst Du keinen Mechanismus "
  "erkennen, mit dem sich diese Klappen oeffnen liessen.");

  AddDetail(({"oeffnungen","oeffnung"}),
  "Viele kleine Oeffnungen sind ueber die ganze Wand verteilt. Du "
  "weisst zwar nicht, was aus ihnen herauskommen mag, aber es wird "
  "sicherlich nicht angenehm sein.");

  AddDetail(({"boden","fussboden"}),
  "Der Boden der Arena ist mit einer dicken Sandschicht bedeckt, die "
  "ihre Funktion nicht verheimlicht.");

  AddDetail(({"sandschicht","schicht","sand"}),
  "Der Sand, der den Boden der Arena bedeckt, hat genau eine einzige "
  "und dazu auch noch wichtige Aufgabe: Er soll das ganze Blut "
  "aufsaugen, was im Laufe eines Kampfes so herumspritzt. Und wie man "
  "dem Sand leicht ansieht, ist dies eine ganze Menge.");

  AddDetail(({"menge"}),
  "Ganz schoen viel...");

  AddCmd(({"sag","sage","'"}),"zauberwort");

  AddExit("westen",     CHAOS_GILDEN_ARENA("nw"));
  AddExit("sueden",     CHAOS_GILDEN_ARENA("so"));
  AddExit("suedwesten", CHAOS_GILDEN_ARENA("sw"));


  AddSpecialExit("osten","go_east");
}

void init() {
  ::init();
  if(find_call_out( "action")==-1) {
    call_out("action", 30+ random(60));
  }
}

int zauberwort(string str) {
  object opfer;
  string ob;

  if(!str) {
    return 0;
  }
  if(str!="goemwexx" ) {
    return 0;
  }
  if(a_time +60 > time()) {
    return 0;
  }
  write(break_string("Du sagst dieses seltsame Wort. Doch noch bevor es "
        "Deinen Mund verlassen hat, bemerkst Du die starke Magie, die "
        "ploetzlich in der Duellarena flimmert. Was auch immer dieser "
        "Zauber bewirkt, er scheint jedenfalls recht maechtig zu sein."));

  foreach(ob:get_targets()) {
    if(!opfer = find_player(ob)) {
      continue;
    }
    if(getuid(PL) == ob) {
      continue;
    }
    tell_object(opfer,break_string("Irgendjemand muss in der Duellarena "
                "einen maechtigen Zauberspruch gesprochen haben, denn "
                "alles um Dich herum flimmert  und Du wirst davon richtig "
                "benommen."));

    opfer->SetProp(P_DISABLE_ATTACK,opfer->QueryProp(P_DISABLE_ATTACK)
                                    +5+random(30));
  }
  a_time = time();
  return 1;
}

void action() {
  switch(random(3)) {
    case 0:
    tell_room(ME,break_string("Wie eine Schlange windet sich ploetzlich "
                 "ein langer Schlauch aus einer der Klappen."));

    call_out("attack_1",2+random(5));
    break;

    case 1:
    tell_room(ME,break_string("Eine Klappe oeffnet sich und ein Trichter "
                 "erscheint. Er sieht nicht besonders gefaehrlich aus, "
                 "aber das will ja bekanntlich nichts heissen."));

    call_out("attack_2",2+random(5));
    break;

    case 2:
    tell_room(ME,break_string("Kalter Wind umweht Dich ganz unerwartet. "
                 "Er kommt aus den zahlreichen Oeffnungen in der Wand "
                 "und wird immer staerker."));

     call_out("attack_3",2+random(5));
     break;
  }
}

void attack_1() {
  tell_room(ME,"Aus dem wild sich windenden Schlauch schiesst ein "
               "Schwall Wasser heraus, der Dich mit unerwarteter Haerte "
               "trifft. Kurz danach verschwindet er wieder in der "
               "Klappe.");

  SetProp(P_NAME,"Kaltes Wasser");

  room_damage(10+random(20));
}

void attack_2() {
  tell_room(ME,break_string("\nAus dem Trichter erklingen seltsame Worte: "
               "Bljfow bls Bose!\nEin uebler Schmerz greift an Dein "
               "Herz!"));

  SetProp(P_NAME,"Zauberworte");

  room_damage(20+random(10));
}

void attack_3() {
  tell_room(ME,break_string("Der Wind wird zu einem Orkan, dessen Kaelte "
               "Dir in die Glieder faehrt und Dir die Lebensenergie "
               "entzieht."));

  SetProp(P_NAME,"Ein kaltes Lueftchen");

  room_damage(5+random(25));
}

int go_east() {
  write("Das Tor ist leider geschlossen!\n");
  return 1;
}
