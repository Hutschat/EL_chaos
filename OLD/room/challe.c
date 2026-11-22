// challe.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet
                         
#include "def.h"

inherit CHAOS_GILDEN_ROOM("std/std_chaos");

static int zahl;
static int healed = 2;

static string licht_det()
{
  if (healed>0) 
  {
    healed--;
    this_player()->heal_self(250);
    return "Das chaotische Leuchten erfasst dich, durchdringt dich, heilt "
           "dich.\n";
  }
  return "Wow ist das blau.\n";
}

static string muster_det()
{
  string s;
  
  if(zahl > 5)
    zahl = 0;

  switch(zahl)
  {
    case 0: 
    s = "\n"+
    "                       ::||||||||||::\n"+
    "                       ::::::::||::::\n"+
    "                       ::::::||::::::\n"+
    "                       ::::||::::::::\n"+
    "                       ::||||||||||::\n";
    break;

    case 1:
    s = "\n"+
    "                       ::||||||||||::\n"+
    "                       ::||::::::||::\n"+
    "                       ::||||||||||::\n"+
    "                       ::||::::::||::\n"+
    "                       ::||::::::||::\n";
    break;

    case 2:
    s = "\n"+
    "                       ::||||||||::::\n"+
    "                       ::||::::||::::\n"+
    "                       ::||||||::::::\n"+
    "                       ::||::::||::::\n"+
    "                       ::||::::::||::\n";
    break;

    case 3:
    s = "\n"+
    "                       ::||||||||::::\n"+
    "                       ::||::::::||::\n"+
    "                       ::||::::::||::\n"+
    "                       ::||::::::||::\n"+
    "                       ::||||||||::::\n";
    break;

    case 4:
    s = "\n"+
    "                       ::::||||||::::\n"+
    "                       ::||::::::||::\n"+
    "                       ::||::::::||::\n"+
    "                       ::||::::::||::\n"+
    "                       ::::||||||::::\n";
    break;

    case 5:
    s = "\n"+
    "                       ::||||||||||::\n"+
    "                       ::::::::||::::\n"+
    "                       ::::::||::::::\n"+
    "                       ::::||::::::::\n"+
    "                       ::||||||||||::\n";
    break;
  }
  zahl ++;
  return s;
}

protected void create()
{
  ::create();
  SetProp(P_LIGHT,0);
  SetProp(P_INT_SHORT, "In der Halle der Festung des Chaos");
  SetProp( P_INT_LONG,
  "Du stehst in einer riesigen gewoelbten Halle. Hoch ueber dir haengen "
  "mehrere Kronleuchter mit hunderten von schwarzen Kerzen, die in einem " 
  "schwachen Lufthauch unruhig flackern. Im Sueden befindet sich ein "
  "Portal, das hinaus in die Eiswueste fuehrt. In den kahlen "
  "Waenden befinden sich zahlreiche Durchgaenge, die in weitere "
  "Raeumlichkeiten der Festung fuehren.");

  AddDetail(({"raeumlichkeiten","raeumlichkeit"}),
  "Bewegung tut deinem mueden Koerper gut, also geh ihn und schau nach.");

  AddDetail("koerper",
  "Nerv nicht, sonst ist dein Koerper bald eine Leiche.");

  AddDetail("leiche",
  "Du hast es nicht anderes gewollt!!! In genau 60 Sekunden wirst du "
  "sterben!!\n");

  AddDetail(({"eiswueste","wueste"}),
  "Die Eiswueste lauert vor der Festung und wartet auf ihre Opfer.");

  AddDetail("opfer",
  "Du bist das naechste Opfer!");

  AddDetail("luft",
  "Du atmest noch, also gibts hier Luft.");

  AddDetail("gestein",
  "Das Gestein ist hart wie Stein.");

  AddDetail("stein",
  "Der Stein ist hart wie Fels.");

  AddDetail("fels",
  "Der Fels ist hart wie Gestein.");

  AddDetail(({"boden","fussboden"}),
  "Du stehst auf einem steinernen Boden mit schwarzen und roten Fliesen, "
  "die immer ihre Farbe wechseln und so staendig andere Muster bilden.");
  
  AddDetail(({"fliesen","fliese"}),
  "Der Boden besteht aus roten und schwarzen Fliesen, die in regelmaessigen "
  "Abstaenden ihre Farbe wechseln und so seltsame Muster bilden.");

  AddDetail("muster",#'muster_det);

  AddDetail(({"farben","farbe"}),
  "Die vorherrschende Farbe ist schwarz. Nur manche Fliesen sind rot.");
  
  AddDetail(({"durchgang","durchgaenge"}),
  "Es gibt hier vier Durchgaenge: Ueber dem Durchgang nach Westen liest du "
  "'Der Gildenraum', nach Norden geht es in den 'Beschwoerungs- und Ritual-"
  "Raum', waehrend im Osten der Laden 'Nuetzliche Zutaten fuer boese "
  "Zaubersprueche' sein soll. Nach Suedwesten geht es in die 'unheimliche "
  "Kampfarena'.");

  AddDetail("gildenraum",
  "Der Gildenraum befindet sich im Westen.");

  AddDetail("laden",
  "Der Laden ist im Osten.");

  AddDetail("halle",
  "Dies ist die Halle der Festung des Chaos.");

  AddDetail(({"beschwoerungsraum","ritualraum"}),
  "Der Beschwoerungs- und Ritual-Raum ist noerdlich von hier.");

  AddDetail(({"arena","kampfarena"}),
  "Die Kampfarena erreichst du durch den Durchgang nach Suedwesten.");

  AddDetail("decke",
  "Die gewoelbte Decke laesst die riesige Halle noch groesser erscheinen. "
  "Die vielen Kronleuchter mit ihren schwarzen Kerzen verbreiten ein "
  "duesteres Licht. Ein grosses Loch waere da noch zu erwaehnen.");

  AddDetail("loch",
  "Was hat nur dieses Loch in der Decke zu bedeuten? Es ist so hoch ueber "
  "dir, dass man schon fliegen muss, um es zu erreichen.");

  AddDetail(({"leuchter","kronleuchter","gestelle","gestell"}),
  "Die an der Decke haengenden Kronleuchter sind riesige Gestelle mit "
  "hunderten von duennen, meterlangen Armen an deren Enden sich je eine "
  "schwarze Kerze befindet. Sie machen den Eindruck von Spinnen, die "
  "ueber Deinem Kopf haengen und sich jederzeit herunter lassen koennten, "
  "um ihr unschuldiges Opfer zu packen. Durch das leichte Flackern der "
  "Kerzen scheinen sie sich wirklich zu bewegen und ihre Beine nach dir "
  "auszustrecken.");

  AddDetail("festung",
  "Die Festung schaust du dir am Besten von draussen an.");

  AddDetail("chaos",
  "Chaos ist immer und ueberall!");

  AddDetail(({"spinnen","spinne"}),
  "Deine Phantasie geht mal wieder mit dir durch.");

  AddDetail(({"arm","arme"}),
  "An den meterlangen Armen der Kronleuchter befindet sich je eine schwarze "
  "Kerze, die nur ein schwaches Licht verbreitet.");

  AddDetail(({"licht","flackern"}),
  "Von den hunderten schwarzen Kerzen geht ein duesteres, flackerndes Licht "
  "aus, das die grosse Halle noch unheimlicher wirken laesst. Es ist "
  "naemlich so duester, dass die Halle gar nicht erhellt wird.");

  AddDetail(({"kerze","kerzen"}),
  "Obwohl hunderte von Kerzen an den Kronleuchtern brennen, verbreiten sie "
  "kein Licht. Ausserdem kannst du keine einzige abgebrannte Kerze finden, "
  "als ob sie nie verloeschen wuerden.");
  
  AddDetail(({"wand","waende"}),
  "Die Waende sind voellig kahl, abgesehen von einem Portrait, das in "
  "seinen, fauligen Rahmen vor sich hin schimmelt. Ausserdem bestehen sie "
  "zum grossen Teil aus Luft, auch Durchgang genannt.");

  AddDetail(({"bilderrahmen","rahmen"}),
  "Dre schimmlige Rahmen fasst ein dreckiges und eingestaubtes Portrait.\n");

  AddDetail(({"bild","portrait"}),
  "Dieses Bild ziert einen muerrisch dreinblickenden, alten Mann. Sein "
  "wallendes und ergrautes Haar faellt lang bis zum Boden. Aus glaenzenden "
  "Augen scheint dich diese Gestalt abwartend zu mustern. Dir ist gar nicht "
  "wohl zumute bei dem Gedanken. Unter dem Portrait befindet sich noch eine "
  "winzige Inschrift: Gilden-Magier a.D. (Z)");

  AddSpecialDetail(({"leuchten","licht"}),"licht_det");

  AddExit("westen",     "/gilden/chaos/gilde" );
  AddExit("osten",      CHAOS_GILDEN_ROOM("claden") );
  AddExit("suedwesten", CHAOS_GILDEN_ROOM("ctrib" ));

  AddSpecialExit( "oben",   "nach_oben" );
  AddSpecialExit( "norden", "zum_beschwoerungs_raum" );

  NewDoor( "sueden", CHAOS_GILDEN_ROOM("ceingang"), 
  ({ "portal", "tuer" }),
  ({
    D_NAME, "Portal",
    D_SHORT, "Ein %ses Portal.",
    D_GENDER, 0,
    D_LONG, "Dieses grosse Portal fuehrt direkt in die toedliche Eiswueste.\n"
  }));
}

int zum_beschwoerungs_raum()
{
  if(PL->QueryProp(P_GUILD) != "chaos")
  {
    write( "Diesen Raum darfst Du nur als Gilden-Mitglied betreten.\n");
    return 1;
  }
  PL->move(CHAOS_GILDEN_ROOM("critual"), M_GO, "nach Norden" );
  return 1;
}

int nach_oben()
{
  if(PL->QueryProp(P_GUILD) != "chaos")
  {
    write( "Kannst Du fliegen?\n");
    return 1;
  }
  if(PL->QueryProp( P_GUILD_LEVEL) < 11 )
  {
    write("Du bist nicht maechtig genug um nach oben zu schweben.\n");
    return 1;
  } 
  PL->move( CHAOS_GILDEN_ROOM("cerz1"),M_GO,"nach oben","schwebt",
                                            "schwebt herein" );
  return 1;
}


void reset()
{
  ::reset();
  healed = 2;
}
