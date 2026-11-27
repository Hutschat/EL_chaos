// dmaker.c - Die Räume der Burg Zwielichtstein
//
// Plan der Burg in sys/chaosburg.h. Langtexte über chaos_long(), damit
// bei jedem Reset eine wechselnde Zeile dazukommen kann (room/std/
// dets.c).
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu
// 27.11.2026 It@Efferdland            ausgebaut

#pragma strong_types
#pragma no_clone
#pragma no_inherit

#include "def.h"

inherit "/std/virtual/it_compiler_dmaker";

#define R(x) CHAOS_GILDEN_ROOM(x)

// Höhe eines Raums relativ zum Erdgeschoss
static void hoehe(object o, int diff) {
  o->SetProp(P_ENVIRONMENT,o->QueryProp(P_ENVIRONMENT)+
             ([ENV_ALTITUDE: CHAOS_BURG_HOEHE+diff]));
}

// Ein sichtbarer Ausgang, der eingestürzt oder versperrt ist
static void versperrt(object o, string file, string richtung, string txt) {
  o->SetProp(P_CHAOS_VERSPERRT,
             (o->QueryProp(P_CHAOS_VERSPERRT)||([]))+([richtung: txt]));
  o->AddExit(richtung,([
                         EX_DEST: R(file),
                         EX_FUNC: "versperrt",
                       ]));
}

public varargs void create_room(string file, object o) {
  if(!::create_room(file,o,CHAOS_VC_BURG)) {
    return;
  }
  switch(file) {

    // ---- Torhaus und Vorburg ---------------------------------------

    case "[+007+051+08]":
    o->SetProp(P_INT_SHORT,"Im Torhaus der Burg Zwielichtstein");
    o->chaos_long(
       "Du stehst im Torhaus der Burg Zwielichtstein, einem dunklen, "
       "gewölbten Durchgang. Über dir hängt das Fallgitter verbogen und "
       "rostig in seiner Führung. Im Westen führt das Tor hinaus auf den "
       "Weg ins Schattental, im Osten öffnet sich die Vorburg. Im Norden "
       "führt eine Tür in die Wachstube, der Durchgang nach Süden ist "
       "eingestürzt.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Das Fallgitter senkt sich lautlos eine Handbreit und hebt sich "
       "dann wieder.",
       "Im Gewölbe über dir hängen Fledermäuse, die violett leuchten.",
    }));

    o->AddDetail(({"torhaus","durchgang","gewoelbe","gewölbe"}),
       "Ein dunkler, gewölbter Durchgang durch die dicke Mauer.");

    o->AddDetail(({"fallgitter","gitter","fuehrung","führung"}),
       "Das Fallgitter hängt verbogen und rostig in seiner Führung. "
       "Hoffentlich hält es noch eine Weile.");

    o->AddDetail(({"rost","weile"}),
       "Rotbrauner Rost frisst sich durch das alte Eisen.");

    o->AddDetail(({"eisen"}),
       "Das Eisen sieht nicht mehr sehr vertrauenerweckend aus.");

    o->AddDetail(({"tor"}),
       "Das Tor im Westen ist halb eingestürzt, ein Torflügel liegt "
       "zerborsten am Boden.");

    o->AddDetail(({"torfluegel","torflügel"}),
       "Zersplittertes, schwarzes Holz.");

    o->AddDetail(({"holz"}),
       "Schwarz und morsch.");

    o->AddDetail(({"weg","schattental"}),
       "Im Westen führt der Weg hinunter ins Schattental.");

    o->AddDetail(({"vorburg"}),
       "Im Osten liegt die Vorburg.");

    o->AddDetail(({"tuer","tür","wachstube"}),
       "Im Norden führt eine schiefe Tür in die Wachstube.");

    o->AddDetail(({"fledermaeuse","fledermäuse"}),
       "Sie hängen kopfüber und leuchten schwach.");

    o->AddSound(({"fallgitter","gitter"}),
       "Das Fallgitter quietscht leise.");

    o->AddExit("westen",     CHAOS_BURGPFAD);
    o->AddExit("osten",      R("[+008+051+08]"));
    o->AddExit("norden",     R("[+007+052+08]"));
    versperrt(o,file,"sueden",
       "Der Durchgang nach Süden ist eingestürzt. Ein Haufen Steine und "
       "verkohlter Balken versperrt ihn bis unter die Decke.");
    break;

    case "[+007+052+08]":
    o->SetProp(P_INT_SHORT,"In der Wachstube des Torhauses");
    o->chaos_long(
       "Die Wachstube ist eng und verrußt. Ein umgestürzter Tisch liegt "
       "zwischen zerbrochenen Bänken, an der Wand hängen leere "
       "Waffenhaken. In der Ecke führt eine steile Treppe nach oben auf "
       "den Wehrgang. Im Süden geht es zurück ins Torhaus.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf dem umgestürzten Tisch liegen Würfel, die von selbst immer "
       "wieder eine Sieben zeigen.",
       "Ein Waffenhaken schwingt hin und her, obwohl nichts daran hängt.",
    }));

    o->AddDetail(({"wachstube"}),
       "Hier saßen einst die Wachen der Burg. Lange her.");

    o->AddDetail(({"tisch"}),
       "Ein schwerer Tisch aus schwarzem Holz, umgestürzt und zerkratzt.");

    o->AddDetail(({"baenke","bänke","bank"}),
       "Die Bänke sind zerbrochen.");

    o->AddDetail(({"waffenhaken","haken"}),
       "Die Haken sind leer. Die Waffen hat wohl längst jemand "
       "mitgenommen.");

    o->AddDetail(({"ecke"}),
       "In der Ecke führt eine Treppe nach oben.");

    o->AddDetail(({"treppe"}),
       "Die Treppe ist steil und führt hinauf auf den Wehrgang.");

    o->AddDetail(({"wehrgang"}),
       "Oben, über dem Torhaus.");

    o->AddDetail(({"wuerfel","würfel","sieben"}),
       "Sie zeigen immer eine Sieben. Auf einem Würfel.");

    o->AddDetail(({"holz"}),
       "Schwarz und schwer.");

    o->AddDetail(({"torhaus"}),
       "Im Süden liegt das Torhaus.");

    o->AddDetail(({"wachen"}),
       "Längst fort.");

    o->AddDetail(({"waffen"}),
       "Keine mehr da.");

    o->AddExit("sueden",     R("[+007+051+08]"));
    o->AddExit("oben",       R("[+007+052+09]"));
    break;

    case "[+007+052+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Auf dem Wehrgang über dem Torhaus");
    o->chaos_long(
       "Der Wehrgang zieht sich über dem Torhaus an der Westmauer "
       "entlang. Die Zinnen sind größtenteils abgebrochen. Tief unten im "
       "Westen liegt das Schattental mit dem Labyrinth der Menagerie. "
       "Nach Norden und Süden ist der Wehrgang eingestürzt, eine Treppe "
       "führt hinunter in die Wachstube.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Unten im Tal scheinen die Wände der Menagerie sich langsam zu "
       "verschieben.",
       "Ein Rabe sitzt auf einer Zinne und krächzt rückwärts.",
    }));

    o->AddDetail(({"wehrgang"}),
       "Schmal und zugig.");

    o->AddDetail(({"zinnen","zinne"}),
       "Die meisten Zinnen sind abgebrochen. Lehn dich besser nicht zu "
       "weit hinaus.");

    o->AddDetail(({"westmauer"}),
       "Die Westmauer ist rissig, hält aber noch.");

    o->AddDetail(({"labyrinth","menagerie","waende","wände"}),
       "Tief unten im Westen windet sich das Labyrinth der Menagerie "
       "zwischen schwarzen Wänden.");

    o->AddDetail(({"treppe","wachstube"}),
       "Die Treppe führt hinunter in die Wachstube.");

    o->AddDetail(({"rabe"}),
       "Ein zerzauster, schwarzer Rabe.");

    o->AddDetail(({"torhaus"}),
       "Du stehst direkt über dem Torhaus.");

    versperrt(o,file,"norden",
       "Nach Norden ist der Wehrgang eingestürzt. Dort klafft eine Lücke, "
       "tief unten liegen Trümmer.");
    versperrt(o,file,"sueden",
       "Nach Süden endet der Wehrgang an einem Haufen herabgestürzter "
       "Steine.");
    o->AddExit("unten",      R("[+007+052+08]"));
    break;

    case "[+008+051+08]":
    o->SetProp(P_INT_SHORT,"In der Vorburg der Burg Zwielichtstein");
    o->chaos_long(
       "Die Vorburg ist ein verwilderter Hof zwischen Außenmauer und "
       "Zwinger. Im Westen liegt das Torhaus, im Osten führt ein zweites "
       "Tor in die Hauptburg. Im Norden stehen die halb eingestürzten "
       "Ställe, im Süden die Schmiede, aus der kein Rauch mehr steigt.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Mitten im Hof wächst eine Distel, deren Blüte violett glüht.",
       "Ein Pferdeschädel liegt im Gras und dreht sich langsam nach dir "
       "um.",
    }));

    o->AddDetail(({"vorburg","hof"}),
       "Ein verwilderter Hof, voller Schutt und dürrem Gras.");

    o->AddDetail(({"aussenmauer","außenmauer"}),
       "Die Außenmauer ist hoch und rissig.");

    o->AddDetail(({"zwinger"}),
       "Der Zwinger liegt zwischen Außenmauer und Hauptburg, hinter dem "
       "zweiten Tor im Osten.");

    o->AddDetail(({"torhaus"}),
       "Im Westen liegt das Torhaus.");

    o->AddDetail(({"tor","hauptburg"}),
       "Im Osten führt ein zweites, kleineres Tor in die Hauptburg.");

    o->AddDetail(({"staelle","ställe"}),
       "Im Norden stehen die Ställe, ihr Dach ist halb eingestürzt.");

    o->AddDetail(({"schmiede","rauch"}),
       "Im Süden steht die Schmiede. Rauch steigt schon lange keiner mehr "
       "auf.");

    o->AddDetail(({"schutt"}),
       "Herabgefallene Steine und zerbrochene Balken.");

    o->AddDetail(({"balken"}),
       "Morsch und schwarz verkohlt.");

    o->AddDetail(({"distel","bluete","blüte"}),
       "Eine stachelige Distel mit einer violett glühenden Blüte.");

    o->AddDetail(({"pferdeschaedel","pferdeschädel","schaedel","schädel"}),
       "Bleich und alt. Und er schaut dich an.");

    o->AddDetail(({"dach"}),
       "Das Dach der Ställe ist halb eingestürzt.");

    o->AddExit("westen",     CHAOS_BURGTOR);
    o->AddExit("osten",      R("[+009+051+08]"));
    o->AddExit("norden",     R("[+008+052+08]"));
    o->AddExit("sueden",     R("[+008+050+08]"));
    break;

    case "[+008+052+08]":
    o->SetProp(P_INT_SHORT,"In den Ställen der Burg Zwielichtstein");
    o->chaos_long(
       "Die Ställe sind halb eingestürzt. Durch das zerfetzte Dach fällt "
       "graues Licht auf leere Boxen und vermoderte Strohhaufen. Der "
       "hintere Teil im Norden liegt unter dem eingestürzten Dach "
       "begraben. Im Süden geht es zurück in die Vorburg.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus einer leeren Box ist leises Wiehern zu hören.",
       "Im Stroh sind Hufspuren, die an der Wand hinauflaufen.",
    }));

    o->AddDetail(({"staelle","ställe","stall"}),
       "Lange stand hier kein Pferd mehr.");

    o->AddDetail(({"dach"}),
       "Das Dach ist zerfetzt, im Norden ist es ganz eingestürzt.");

    o->AddDetail(({"licht"}),
       "Graues, trübes Licht.");

    o->AddDetail(({"boxen","box"}),
       "Leere Pferdeboxen mit zerbrochenen Türen.");

    o->AddDetail(({"tueren","türen"}),
       "Zerbrochen und schief.");

    o->AddDetail(({"strohhaufen","stroh","haufen"}),
       "Vermodertes Stroh, das muffig riecht.");

    o->AddDetail(({"hufspuren","spuren"}),
       "Sie führen die Wand hinauf und verschwinden an der Decke.");

    o->AddDetail(({"vorburg"}),
       "Im Süden liegt die Vorburg.");

    o->AddSmell(({"stroh","strohhaufen"}),
       "Muffig und modrig.");

    o->AddSound(({"wiehern"}),
       "Leise und fern.");

    o->AddDetail(({"pferd","pferde"}),
       "Hier steht schon lange keins mehr.");

    o->AddDetail(({"pferdeboxen","pferdebox"}),
       "Leer und verfallen.");

    o->AddDetail(({"teil"}),
       "Der hintere Teil liegt unter dem eingestürzten Dach.");

    versperrt(o,file,"norden",
       "Der hintere Teil der Ställe ist unter dem eingestürzten Dach "
       "begraben. Da kommst du nicht durch.");
    o->AddExit("sueden",     R("[+008+051+08]"));
    break;

    case "[+008+050+08]":
    o->SetProp(P_INT_SHORT,"In der Schmiede der Burg Zwielichtstein");
    o->chaos_long(
       "Die Schmiede ist ein niedriger, verrußter Raum. Mitten darin "
       "steht ein Amboss, daneben eine Esse, in der längst kein Feuer "
       "mehr brennt. An der Wand hängen verrostete Zangen und Hämmer. Im "
       "Norden geht es zurück in die Vorburg.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "In der kalten Esse glimmt ein violettes Glutnest, das keine Wärme "
       "abgibt.",
       "Ab und zu erklingt ein Hammerschlag auf dem Amboss, aber niemand "
       "ist da.",
    }));

    o->AddDetail(({"schmiede"}),
       "Ein niedriger, verrußter Raum.");

    o->AddDetail(({"amboss"}),
       "Ein schwerer, eiserner Amboss mit tiefen Kerben.");

    o->AddDetail(({"kerben"}),
       "Spuren unzähliger Hammerschläge.");

    o->AddDetail(({"esse","feuer"}),
       "Die Esse ist kalt und voller Asche.");

    o->AddDetail(({"asche"}),
       "Grau und kalt.");

    o->AddDetail(({"zangen","hämmer","haemmer","zange","hammer"}),
       "Verrostet und unbrauchbar.");

    o->AddDetail(({"glutnest","glut"}),
       "Es glimmt violett und gibt keine Wärme ab.");

    o->AddDetail(({"hammerschlag","hammerschläge","hammerschlaege"}),
       "Du hörst sie, aber niemand schlägt.");

    o->AddDetail(({"vorburg"}),
       "Im Norden liegt die Vorburg.");

    o->AddSound(({"hammerschlag","amboss"}),
       "Klong.");

    o->AddDetail(({"waerme","wärme"}),
       "Keine. Nicht die geringste.");

    o->AddExit("norden",     R("[+008+051+08]"));
    break;

    // ---- Inneres Tor und Zwinger -----------------------------------

    case "[+009+051+08]":
    o->SetProp(P_INT_SHORT,"Im inneren Tor der Burg Zwielichtstein");
    o->chaos_long(
       "Das innere Tor trennt die Vorburg im Westen von der Hauptburg im "
       "Osten. Die Torflügel stehen offen und lassen sich nicht mehr "
       "bewegen. Nach Norden und Süden führen schmale Pforten in den "
       "Zwinger, den Gang zwischen den beiden Mauerringen.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Torflügel stehen heute ein Stück weiter offen als sonst. Oder "
       "weniger weit.",
       "Über dem Tor ist ein Wappen zu sehen, das du vorhin nicht "
       "bemerkt hast.",
    }));

    o->AddDetail(({"tor","torfluegel","torflügel"}),
       "Die Torflügel sind verzogen und stehen fest offen.");

    o->AddDetail(({"vorburg"}),
       "Im Westen liegt die Vorburg.");

    o->AddDetail(({"hauptburg"}),
       "Im Osten liegt die Hauptburg mit dem Burghof.");

    o->AddDetail(({"pforten","pforte","zwinger"}),
       "Schmale Pforten führen nach Norden und Süden in den Zwinger.");

    o->AddDetail(({"mauerringe","mauerring","gang"}),
       "Zwischen den beiden Mauerringen verläuft der Zwinger.");

    o->AddDetail(({"wappen"}),
       "Ein Wappen mit einem gesprungenen Stern. Es verschwimmt, wenn du "
       "genauer hinschaust.");

    o->AddDetail(({"stern"}),
       "Gesprungen und verblasst.");

    o->AddDetail(({"burghof"}),
       "Hinter dem Tor im Osten liegt der Burghof.");

    o->AddExit("westen",     R("[+008+051+08]"));
    o->AddExit("osten",      R("[+010+051+08]"));
    o->AddExit("norden",     R("[+009+052+08]"));
    o->AddExit("sueden",     R("[+009+050+08]"));
    break;

    case "[+009+052+08]":
    o->SetProp(P_INT_SHORT,"Im nördlichen Zwinger");
    o->chaos_long(
       "Du stehst im Zwinger, einem schmalen Gang zwischen der äußeren "
       "und der inneren Mauer. Im Westen und Osten ragen die Mauern hoch "
       "auf, über dir liegt ein Streifen grauer Dunst. Der Zwinger führt "
       "nach Norden weiter, im Süden geht es zurück zum inneren Tor.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die beiden Mauern scheinen heute ein wenig näher beieinander zu "
       "stehen.",
       "Im Gras liegt ein rostiger Helm, der leise summt.",
    }));

    o->AddDetail(({"zwinger","gang"}),
       "Ein schmaler Gang zwischen den beiden Mauerringen.");

    o->AddDetail(({"streifen"}),
       "Ein schmaler Streifen grauer Dunst, mehr ist vom Himmel nicht zu "
       "sehen.");

    o->AddDetail(({"tor"}),
       "Im Süden liegt das innere Tor.");

    o->AddDetail(({"helm"}),
       "Ein alter, verbeulter Helm. Er summt eine Melodie, die du nicht "
       "kennst.");

    o->AddDetail(({"melodie"}),
       "Traurig und schief.");

    o->AddDetail(({"mauerringe","mauerring"}),
       "Der äußere und der innere Mauerring.");

    o->AddExit("sueden",     R("[+009+051+08]"));
    o->AddExit("norden",     R("[+009+053+08]"));
    break;

    case "[+009+053+08]":
    o->SetProp(P_INT_SHORT,"Am Ende des nördlichen Zwingers");
    o->chaos_long(
       "Hier endet der Zwinger. Im Norden ist die äußere Mauer "
       "eingestürzt und hat den Gang mit einem gewaltigen Schuttberg "
       "verschüttet. Durch eine Lücke oben siehst du violette Blitze. Im "
       "Süden geht es zurück.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf dem Schuttberg sitzt eine Krähe mit drei Augen und beobachtet "
       "dich.",
       "Aus dem Schuttberg ragt eine knochige Hand, die dir zuwinkt.",
    }));

    o->AddDetail(({"zwinger","gang"}),
       "Der Zwinger endet hier am Schuttberg.");

    o->AddDetail(({"schuttberg","schutt"}),
       "Ein gewaltiger Berg aus Steinen und Mörtel, bis oben hin.");

    o->AddDetail(({"luecke","lücke"}),
       "Oben in der eingestürzten Mauer klafft eine Lücke.");

    o->AddDetail(({"blitze"}),
       "Violette Blitze im Dunst über der Burg.");

    o->AddDetail(({"kraehe","krähe","augen"}),
       "Eine schwarze Krähe mit drei Augen. Das mittlere zwinkert.");

    o->AddDetail(({"hand"}),
       "Knochig, bleich und erstaunlich freundlich.");

    o->AddDetail(({"berg"}),
       "Ein Berg aus Schutt.");

    o->AddDetail(({"moertel","mörtel"}),
       "Bröckelig und grau.");

    versperrt(o,file,"norden",
       "Der Schuttberg im Norden ist viel zu hoch und zu locker, um "
       "darüber zu klettern.");
    o->AddExit("sueden",     R("[+009+052+08]"));
    break;

    case "[+009+050+08]":
    o->SetProp(P_INT_SHORT,"Im südlichen Zwinger");
    o->chaos_long(
       "Du stehst im südlichen Teil des Zwingers zwischen der äußeren und "
       "der inneren Mauer. Der Boden ist uneben und von Gras überwuchert. "
       "Der Zwinger führt nach Süden weiter, im Norden geht es zurück zum "
       "inneren Tor.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Im Gras liegen Pfeile, deren Spitzen in alle Richtungen zeigen.",
       "Eine Pfütze im Gras spiegelt einen blauen Himmel.",
    }));

    o->AddDetail(({"zwinger"}),
       "Ein schmaler Gang zwischen den beiden Mauerringen.");

    o->AddDetail(({"tor"}),
       "Im Norden liegt das innere Tor.");

    o->AddDetail(({"pfeile","spitzen"}),
       "Alte Pfeile. Die Spitzen zeigen in alle Richtungen zugleich.");

    o->AddDetail(({"pfuetze","pfütze"}),
       "Sie spiegelt einen Himmel, den es hier nicht gibt.");

    o->AddDetail(({"gang"}),
       "Ein schmaler Gang zwischen den Mauern.");

    o->AddDetail(({"mauerringe","mauerring"}),
       "Der äußere und der innere Mauerring.");

    o->AddDetail(({"richtungen"}),
       "Alle auf einmal.");

    o->AddDetail(({"teil"}),
       "Der südliche Teil des Zwingers.");

    o->AddExit("norden",     R("[+009+051+08]"));
    o->AddExit("sueden",     R("[+009+049+08]"));
    break;

    case "[+009+049+08]":
    o->SetProp(P_INT_SHORT,"An der Abbruchkante im Zwinger");
    o->chaos_long(
       "Hier hört der Zwinger auf. Im Süden sind beide Mauern mitsamt dem "
       "Fels weggebrochen, eine Abbruchkante fällt senkrecht in die Tiefe. "
       "Kalter Wind pfeift herauf. Im Norden geht es zurück.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Kleine Steine fallen von der Kante, steigen dann aber wieder "
       "herauf.",
       "Tief unten glimmt ein violettes Licht.",
    }));

    o->AddDetail(({"abbruchkante","kante","tiefe","fels"}),
       "Die Kante fällt senkrecht in die Tiefe. Unten ist nichts als "
       "Dunst.");

    o->AddDetail(({"zwinger"}),
       "Hier endet der Zwinger an der Abbruchkante.");

    o->AddDetail(({"wind"}),
       "Ein kalter Wind pfeift aus der Tiefe herauf.");

    o->AddDetail(({"licht"}),
       "Ganz tief unten glimmt etwas Violettes.");

    o->AddSound(({"wind"}),
       "Er pfeift und heult.");

    o->AddDetail(({"violettes"}),
       "Ein fernes, violettes Licht.");

    versperrt(o,file,"sueden",
       "Im Süden geht es senkrecht in die Tiefe. Das überlebst du nicht.");
    o->AddExit("norden",     R("[+009+050+08]"));
    break;

    // ---- Hauptburg ------------------------------------------------

    case "[+010+051+08]":
    o->SetProp(P_INT_SHORT,"Im Burghof der Hauptburg");
    o->chaos_long(
       "Der Burghof der Hauptburg ist von hohen Gebäuden umgeben. Im "
       "Norden ragt der schiefe Bergfried in den Dunst, an seiner Spitze "
       "flackert violettes Licht. Im Osten liegt der Palas, im Süden die "
       "Kapelle ohne Dach. Im Westen geht es durch das innere Tor zurück "
       "zur Vorburg. Mitten im Hof steht ein alter Brunnen.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Über dem Brunnen schwebt eine Kugel aus Wasser und dreht sich "
       "langsam.",
       "Das Licht an der Spitze des Bergfrieds pulsiert heute schneller.",
       "Der Hof ist mit Raureif bedeckt, der in Spiralen wächst.",
    }));

    o->AddDetail(({"burghof","hof","hauptburg"}),
       "Der Burghof ist von hohen, verfallenen Gebäuden umgeben.");

    o->AddDetail(({"gebaeude","gebäude"}),
       "Bergfried, Palas und Kapelle umgeben den Hof.");

    o->AddDetail(({"bergfried","spitze"}),
       "Der Bergfried im Norden steht gefährlich schief. Ganz oben "
       "flackert violettes Licht.");

    o->AddDetail(({"licht"}),
       "Das violette Licht flackert an der Spitze des Bergfrieds.");

    o->AddDetail(({"palas"}),
       "Der Palas im Osten war einst das Wohnhaus der Burgherren.");

    o->AddDetail(({"kapelle","dach"}),
       "Die Kapelle im Süden hat kein Dach mehr.");

    o->AddDetail(({"tor","vorburg"}),
       "Im Westen führt das innere Tor zurück zur Vorburg.");

    o->AddDetail(({"brunnen"}),
       "Ein alter, gemauerter Brunnen. Er ist mit einem schweren Gitter "
       "verschlossen, tief unten glitzert Wasser.");

    o->AddDetail(({"gitter"}),
       "Ein schweres, rostiges Gitter.");

    o->AddDetail(({"wasser","kugel"}),
       "Das Wasser glitzert violett.");

    o->AddDetail(({"raureif","rauhreif","spiralen"}),
       "Er wächst in Spiralen und verschwindet, wenn du ihn anfasst.");

    o->AddDetail(({"burgherren"}),
       "Längst vergessen.");

    o->AddDetail(({"wohnhaus"}),
       "Der Palas im Osten.");

    o->AddExit("westen",     R("[+009+051+08]"));
    o->AddExit("osten",      R("[+011+051+08]"));
    o->AddExit("norden",     R("[+010+052+08]"));
    o->AddExit("sueden",     R("[+010+050+08]"));
    break;

    // ---- Bergfried ------------------------------------------------

    case "[+010+052+08]":
    o->SetProp(P_INT_SHORT,"Im Erdgeschoss des Bergfrieds");
    o->chaos_long(
       "Du stehst im Erdgeschoss des Bergfrieds. Die Mauern sind "
       "meterdick, das einzige Licht fällt von oben durch das "
       "Treppenhaus herein. Eine Wendeltreppe windet sich an der Wand "
       "nach oben. Im Süden geht es zurück in den Burghof.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Wendeltreppe dreht sich heute andersherum.",
       "Von oben schwebt eine einzelne violette Feder herab.",
    }));

    o->AddDetail(({"bergfried"}),
       "Der höchste Turm der Burg. Er steht schief, aber er steht.");

    o->AddDetail(({"treppenhaus","wendeltreppe","treppe"}),
       "Die Wendeltreppe windet sich an der Wand nach oben.");

    o->AddDetail(({"licht"}),
       "Violettes Licht fällt von oben herein.");

    o->AddDetail(({"feder"}),
       "Sie schwebt und schwebt und kommt nie unten an.");

    o->AddDetail(({"burghof"}),
       "Im Süden liegt der Burghof.");

    o->AddDetail(({"erdgeschoss"}),
       "Du stehst darin.");

    o->AddDetail(({"turm"}),
       "Der Bergfried ist der höchste Turm der Burg.");

    o->AddExit("sueden",     R("[+010+051+08]"));
    o->AddExit("oben",       R("[+010+052+09]"));
    break;

    case "[+010+052+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Im ersten Stock des Bergfrieds");
    o->chaos_long(
       "Der erste Stock des Bergfrieds war einst die Waffenkammer. Leere "
       "Gestelle stehen an den Wänden, auf dem Boden liegen zerbrochene "
       "Speere und verbeulte Schilde. Die Wendeltreppe führt weiter "
       "nach oben und hinunter ins Erdgeschoss.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Einer der Schilde zeigt ein Spiegelbild, das nicht deins ist.",
       "Die zerbrochenen Speere haben sich zu einem Stern gelegt.",
    }));

    o->AddDetail(({"waffenkammer"}),
       "Hier lagerten einst die Waffen der Burg.");

    o->AddDetail(({"gestelle","gestell"}),
       "Leere Gestelle aus schwarzem Holz.");

    o->AddDetail(({"speere","speer"}),
       "Zerbrochen und unbrauchbar.");

    o->AddDetail(({"schilde","schild"}),
       "Verbeult und rostig.");

    o->AddDetail(({"spiegelbild"}),
       "Es lächelt, obwohl du nicht lächelst.");

    o->AddDetail(({"stern"}),
       "Fünf zerbrochene Speere, zu einem Stern gelegt.");

    o->AddDetail(({"wendeltreppe","treppe"}),
       "Sie führt nach oben und nach unten.");

    o->AddDetail(({"holz"}),
       "Schwarz und hart.");

    o->AddDetail(({"bergfried"}),
       "Du bist im ersten Stock des Bergfrieds.");

    o->AddDetail(({"erdgeschoss"}),
       "Unten.");

    o->AddDetail(({"stock"}),
       "Der erste Stock.");

    o->AddDetail(({"waffen"}),
       "Längst fort.");

    o->AddExit("unten",      R("[+010+052+08]"));
    o->AddExit("oben",       R("[+010+052+10]"));
    break;

    case "[+010+052+10]":
    hoehe(o,20);
    o->SetProp(P_INT_SHORT,"Im zweiten Stock des Bergfrieds");
    o->chaos_long(
       "Der zweite Stock des Bergfrieds ist eine runde Stube. Durch "
       "schmale Schießscharten fällt fahles Licht. Ein Teil des Bodens ist "
       "durchgebrochen, durch das Loch siehst du hinunter in den ersten "
       "Stock. Die Wendeltreppe führt weiter nach oben zur Spitze und "
       "hinunter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Durch das Loch im Boden siehst du nicht den ersten Stock, sondern "
       "einen Sternenhimmel.",
       "Die Schießscharten zeigen heute in Richtungen, in denen keine "
       "Mauer ist.",
    }));

    o->AddDetail(({"stube"}),
       "Eine runde, kahle Stube.");

    o->AddDetail(({"schiessscharten","schießscharten","scharten"}),
       "Schmale Schlitze in der dicken Mauer.");

    o->AddDetail(({"loch","teil"}),
       "Ein Teil des Bodens ist durchgebrochen. Pass auf, wo du "
       "hintrittst.");

    o->AddDetail(({"licht"}),
       "Fahles Licht fällt durch die Schießscharten.");

    o->AddDetail(({"sternenhimmel"}),
       "Sterne, wo keine sein sollten.");

    o->AddDetail(({"wendeltreppe","treppe","spitze"}),
       "Die Wendeltreppe führt nach oben zur Spitze und nach unten.");

    o->AddDetail(({"bergfried"}),
       "Du bist im zweiten Stock des Bergfrieds.");

    o->AddDetail(({"schlitze"}),
       "Schmale Schießscharten.");

    o->AddDetail(({"stock"}),
       "Der zweite Stock.");

    o->AddExit("unten",      R("[+010+052+09]"));
    o->AddExit("oben",       R("[+010+052+11]"));
    break;

    case "[+010+052+11]":
    hoehe(o,30);
    o->SetProp(P_CHAOS_RISS,1);
    o->SetProp(P_LIGHT,2);
    o->SetProp(P_LIGHT_TYPE,LT_MAGIC);
    o->SetProp(P_INT_SHORT,"Auf der Spitze des Bergfrieds");
    o->chaos_long(
       "Die Spitze des Bergfrieds hat kein Dach mehr. Über der Plattform "
       "klafft ein Riss, aus dem violettes Licht und Chaosmagie sickern. "
       "Er pulsiert, als würde er atmen. Hier ist einst ein Ritual "
       "schiefgegangen. Du kannst in den Riss hineingehen, nach unten "
       "führt die Wendeltreppe zurück in den Bergfried.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Der Riss ist heute breiter als sonst, und das Flüstern lauter.",
       "Für einen Augenblick glaubst du, eine Klaue im Riss zu sehen.",
       "Funken sprühen aus dem Riss und tanzen über die Plattform.",
    }));

    o->AddDetail(({"riss"}),
       "Der Riss schwebt über der Plattform, gut mannshoch und von "
       "violettem Licht erfüllt. Wenn du hineinschaust, siehst du Dinge, "
       "die keinen Sinn ergeben. Man kann hineingehen, wenn man sich "
       "traut.");

    o->AddDetail(({"licht"}),
       "Das violette Licht pulsiert unablässig.");

    o->AddDetail(({"plattform"}),
       "Die Plattform ist rissig und mit verblassten Zeichen bedeckt.");

    o->AddDetail(({"zeichen","pentagramm","bannkreis"}),
       "Reste eines Pentagramms und eines Bannkreises, halb verwischt. "
       "Wer sie gezeichnet hat, hat dabei etwas falsch gemacht.");

    o->AddDetail(({"ritual"}),
       "Niemand weiß, wer das Ritual gewirkt hat. Seitdem ist der Riss "
       "offen. Hier ist die Chaosmagie so stark, dass Beschwörungen "
       "leichter gelingen.");

    o->AddDetail(({"beschwoerungen","beschwörungen"}),
       "Am Riss gelingen sie leichter.");

    o->AddDetail(({"dach"}),
       "Vom Dach ist nichts mehr übrig.");

    o->AddDetail(({"dinge","sinn"}),
       "Du schaust lieber nicht zu lange hinein.");

    o->AddDetail(({"klaue","funken"}),
       "Da war etwas. Oder auch nicht.");

    o->AddDetail(({"bergfried","spitze","wendeltreppe","treppe"}),
       "Du stehst ganz oben auf dem Bergfried. Die Wendeltreppe führt "
       "hinunter.");

    o->AddSound(({DEFAULT_SOUND,"riss","fluestern","flüstern"}),
       "Fern und vielstimmig, kaum zu verstehen.");

    o->AddExit("unten",      R("[+010+052+10]"));
    o->AddExit("hinein",     R("[+010+052+12]"));
    break;

    case "[+010+052+12]":
    hoehe(o,35);
    o->SetProp(P_CHAOS_RISS,1);
    o->SetProp(P_LIGHT,2);
    o->SetProp(P_LIGHT_TYPE,LT_MAGIC);
    o->SetProp(P_INT_SHORT,"Im Riss");
    o->chaos_long(
       "Du stehst im Riss, oder in etwas, das man so nennen könnte. Oben "
       "und unten haben ihre Bedeutung verloren, ringsum wabert violettes "
       "Licht, durchzogen von Bildern einer Burg, die noch unversehrt "
       "ist. Stimmen flüstern aus allen Richtungen. Wenn du hinausgehst, "
       "landest du wieder auf der Spitze des Bergfrieds.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "In den Bildern siehst du einen Magier in schwarzer Robe, der ein "
       "Pentagramm zeichnet und einen Fehler macht.",
       "Die Bilder zeigen die Burg im Sonnenschein, mit Fahnen auf den "
       "Türmen.",
       "Für einen Augenblick siehst du dich selbst, wie du von außen in "
       "den Riss hineinschaust.",
    }));

    o->AddDetail(({"riss","licht"}),
       "Violettes Licht, so weit du schauen kannst.");

    o->AddDetail(({"bilder","bild","burg"}),
       "Bilder der Burg Zwielichtstein, wie sie einmal war: unversehrt, "
       "mit Fahnen auf den Türmen und Leben im Hof.");

    o->AddDetail(({"fahnen","tuerme","türme","hof","leben"}),
       "Längst vergangen. Nur hier im Riss ist es noch zu sehen.");

    o->AddDetail(({"magier","robe","pentagramm","fehler"}),
       "Der Magier zeichnet das Pentagramm, setzt eine Linie falsch, und "
       "die Welt reißt auf. Immer und immer wieder.");

    o->AddDetail(({"stimmen","bedeutung","richtungen"}),
       "Die Stimmen flüstern, aber du verstehst kein Wort.");

    o->AddDetail(({"sonnenschein"}),
       "Ein Sonnenschein, den es im Schattental nicht mehr gibt.");

    o->AddDetail(({"spitze","bergfried"}),
       "Wenn du hinausgehst, bist du wieder auf der Spitze des "
       "Bergfrieds.");

    o->AddSound(({DEFAULT_SOUND,"stimmen"}),
       "Hunderte flüstern durcheinander.");

    o->AddDetail(({"linie"}),
       "Eine einzige falsche Linie.");

    o->AddDetail(({"welt"}),
       "Sie reißt auf. Immer wieder.");

    o->AddDetail(({"wort"}),
       "Kein einziges.");

    o->AddExit("hinaus",     R("[+010+052+11]"));
    break;

    // ---- Kapelle ---------------------------------------------------

    case "[+010+050+08]":
    o->SetProp(P_INT_SHORT,"In der Kapelle der Burg Zwielichtstein");
    o->chaos_long(
       "Die Kapelle hat kein Dach mehr, über dir hängt der graue Dunst. "
       "Die Bänke sind umgestürzt, der Altar im Süden ist gespalten. An "
       "der Wand ist ein Bild übermalt worden, man erkennt nur noch "
       "violette Schlieren. Im Osten führt eine Tür in die Sakristei, im "
       "Norden geht es zurück in den Burghof.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf dem gespaltenen Altar brennt eine Kerze mit schwarzer Flamme.",
       "Die Schlieren an der Wand haben sich zu einem Gesicht geformt.",
    }));

    o->AddDetail(({"kapelle"}),
       "Eine kleine Kapelle, längst entweiht.");

    o->AddDetail(({"dach","dunst"}),
       "Statt eines Daches hängt grauer Dunst über der Kapelle.");

    o->AddDetail(({"baenke","bänke"}),
       "Umgestürzte Holzbänke.");

    o->AddDetail(({"altar"}),
       "Ein steinerner Altar, mitten durch gespalten.");

    o->AddDetail(({"bild","schlieren"}),
       "Was einmal darauf zu sehen war, hat jemand mit violetter Farbe "
       "übermalt.");

    o->AddDetail(({"farbe"}),
       "Violette Farbe, die noch immer feucht aussieht.");

    o->AddDetail(({"kerze","flamme"}),
       "Eine Kerze mit schwarzer Flamme, die kein Licht macht.");

    o->AddDetail(({"gesicht"}),
       "Es grinst.");

    o->AddDetail(({"tuer","tür","sakristei"}),
       "Im Osten führt eine niedrige Tür in die Sakristei.");

    o->AddDetail(({"burghof"}),
       "Im Norden liegt der Burghof.");

    o->AddDetail(({"holzbaenke","holzbänke"}),
       "Umgestürzt und morsch.");

    o->AddDetail(({"wand"}),
       "An der Wand ist das übermalte Bild.");

    o->AddExit("norden",     R("[+010+051+08]"));
    o->AddExit("osten",      R("[+011+050+08]"));
    break;

    case "[+011+050+08]":
    o->SetProp(P_INT_SHORT,"In der Sakristei");
    o->chaos_long(
       "Die Sakristei ist ein kleiner, enger Raum. In einer Truhe liegen "
       "Fetzen alter Gewänder. Im Boden führt eine Treppe hinab zur Gruft, "
       "doch die Stufen sind nach wenigen Schritten verschüttet. Im "
       "Westen geht es zurück in die Kapelle.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus der verschütteten Gruft dringt ein leises Klopfen.",
       "Die Gewänder in der Truhe bewegen sich, als wäre noch jemand "
       "darin.",
    }));

    o->AddDetail(({"sakristei"}),
       "Ein kleiner, enger Raum neben der Kapelle.");

    o->AddDetail(({"truhe"}),
       "Eine alte Holztruhe mit gesprungenem Deckel.");

    o->AddDetail(({"deckel"}),
       "Gesprungen und schief.");

    o->AddDetail(({"fetzen","gewaender","gewänder"}),
       "Vermoderte Stoffreste, einst prächtig.");

    o->AddDetail(({"treppe","stufen","gruft","schritte"}),
       "Die Treppe zur Gruft ist nach wenigen Stufen verschüttet.");

    o->AddDetail(({"klopfen"}),
       "Lieber nicht nachsehen.");

    o->AddDetail(({"kapelle"}),
       "Im Westen liegt die Kapelle.");

    o->AddSound(({"klopfen","gruft"}),
       "Tock. Tock. Tock.");

    o->AddDetail(({"holztruhe"}),
       "Eine alte Truhe mit gesprungenem Deckel.");

    o->AddDetail(({"stoffreste"}),
       "Vermodert.");

    versperrt(o,file,"unten",
       "Die Treppe zur Gruft ist nach wenigen Stufen verschüttet.");
    o->AddExit("westen",     R("[+010+050+08]"));
    break;

    // ---- Palas -----------------------------------------------------

    case "[+011+051+08]":
    o->SetProp(P_INT_SHORT,"In der Vorhalle des Palas");
    o->chaos_long(
       "Die Vorhalle des Palas ist hoch und kühl. Über dir zieht sich eine "
       "Galerie an der Wand entlang, eine breite Treppe führt hinauf. Eine "
       "schmale Treppe führt hinunter in den Keller. Im Osten liegt der "
       "Rittersaal, im Norden die Küche, und im Westen geht es zurück in "
       "den Burghof.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf den Stufen der Treppe liegen Spielkarten, die alle den "
       "gleichen Buben zeigen.",
       "Ein Kronleuchter, den es nicht gibt, wirft Schatten an die Decke.",
    }));

    o->AddDetail(({"vorhalle","palas"}),
       "Die Vorhalle des alten Wohnhauses der Burgherren.");

    o->AddDetail(({"galerie"}),
       "Oben zieht sich eine Galerie an der Wand entlang.");

    o->AddDetail(({"treppe","treppen","stufen"}),
       "Eine breite Treppe führt hinauf zur Galerie, eine schmale "
       "hinunter in den Keller.");

    o->AddDetail(({"keller"}),
       "Unten liegt der Keller.");

    o->AddDetail(({"rittersaal"}),
       "Im Osten liegt der Rittersaal.");

    o->AddDetail(({"kueche","küche"}),
       "Im Norden liegt die Küche.");

    o->AddDetail(({"burghof"}),
       "Im Westen liegt der Burghof.");

    o->AddDetail(({"spielkarten","karten","buben","bube"}),
       "Lauter Kreuzbuben. Sie grinsen alle.");

    o->AddDetail(({"kronleuchter"}),
       "An der Decke ist nichts. Und doch sind da Schatten.");

    o->AddDetail(({"burgherren"}),
       "Längst vergessen.");

    o->AddDetail(({"kreuzbuben"}),
       "Sie grinsen alle.");

    o->AddDetail(({"wohnhaus"}),
       "Der Palas.");

    o->AddExit("westen",     R("[+010+051+08]"));
    o->AddExit("osten",      CHAOS_RITTERSAAL);
    o->AddExit("norden",     R("[+011+052+08]"));
    o->AddExit("oben",       R("[+012+051+09]"));
    o->AddExit("unten",      R("[+011+051+07]"));
    break;

    case "[+012+051+08]":
    o->SetProp(P_INT_SHORT,"Im Rittersaal der Burg Zwielichtstein");
    o->chaos_long(
       "Der Rittersaal ist groß und düster. Die Decke ist an einer Stelle "
       "eingestürzt, durch das Loch siehst du violette Blitze im Dunst. "
       "Eine lange Tafel steht umgestürzt zwischen den Trümmern. Im Osten "
       "liegt die Gildenhalle, im Westen geht es zurück in die Vorhalle. "
       "Von unten dringt Lärm herauf.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die umgestürzte Tafel ist heute gedeckt, mit Tellern voller "
       "violetter Asche.",
       "An der Wand hängt eine Rüstung, die dir mit dem Visier zunickt.",
    }));

    o->AddDetail(({"rittersaal","saal"}),
       "Ein großer, düsterer Saal.");

    o->AddDetail(({"loch"}),
       "Durch das Loch in der Decke siehst du violette Blitze im Dunst.");

    o->AddDetail(({"blitze","dunst"}),
       "Violette Blitze zucken lautlos durch den Dunst über der Burg.");

    o->AddDetail(({"tafel"}),
       "Eine lange, schwere Tafel aus schwarzem Holz, umgestürzt und "
       "zerkratzt.");

    o->AddDetail(({"holz"}),
       "Schwarzes, hartes Holz.");

    o->AddDetail(({"truemmer","trümmer"}),
       "Steine aus der eingestürzten Decke.");

    o->AddDetail(({"gildenhalle"}),
       "Im Osten liegt die Gildenhalle.");

    o->AddDetail(({"vorhalle"}),
       "Im Westen liegt die Vorhalle.");

    o->AddDetail(({"laerm","lärm"}),
       "Unter dem Saal liegt die Schänke. Man erreicht sie über den "
       "Keller.");

    o->AddDetail(({"schaenke","schänke","keller"}),
       "Die Schänke liegt im Keller unter dem Saal.");

    o->AddDetail(({"teller","asche"}),
       "Violette Asche auf alten Zinntellern.");

    o->AddDetail(({"ruestung","rüstung","visier"}),
       "Eine leere Rüstung. Meistens.");

    o->AddSound(({DEFAULT_SOUND,"laerm","lärm"}),
       "Laut und fröhlich, von unten.");

    o->AddDetail(({"zinnteller"}),
       "Alt und verbeult.");

    o->AddExit("westen",     R("[+011+051+08]"));
    o->AddExit("osten",      CHAOS_GILDENROOM);
    break;

    case "[+011+052+08]":
    o->SetProp(P_INT_SHORT,"In der Küche der Burg Zwielichtstein");
    o->chaos_long(
       "Die Küche ist groß und verrußt. In einem riesigen Herd hängt noch "
       "ein Kessel über der kalten Feuerstelle, auf dem Tisch liegen "
       "Messer und zerbrochene Schüsseln. Im Osten führt eine Tür in die "
       "Vorratskammer, im Süden geht es zurück in die Vorhalle.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Im Kessel blubbert es, obwohl kein Feuer brennt.",
       "Die Messer auf dem Tisch haben sich zu einem Kreis geordnet.",
    }));

    o->AddDetail(({"kueche","küche"}),
       "Eine große, verrußte Küche.");

    o->AddDetail(({"herd","feuerstelle"}),
       "Ein riesiger, gemauerter Herd mit kalter Feuerstelle.");

    o->AddDetail(({"kessel"}),
       "Ein schwerer, eiserner Kessel. Besser nicht hineinschauen.");

    o->AddDetail(({"tisch"}),
       "Ein langer Tisch, voller Kerben.");

    o->AddDetail(({"kerben"}),
       "Von unzähligen Messern.");

    o->AddDetail(({"messer","kreis"}),
       "Alte, schartige Messer.");

    o->AddDetail(({"schuesseln","schüsseln"}),
       "Zerbrochen.");

    o->AddDetail(({"tuer","tür","vorratskammer"}),
       "Im Osten führt eine Tür in die Vorratskammer.");

    o->AddDetail(({"vorhalle"}),
       "Im Süden liegt die Vorhalle.");

    o->AddSound(({"kessel"}),
       "Blubb.");

    o->AddExit("sueden",     R("[+011+051+08]"));
    o->AddExit("osten",      R("[+012+052+08]"));
    break;

    case "[+012+052+08]":
    o->SetProp(P_INT_SHORT,"In der Vorratskammer");
    o->chaos_long(
       "Die Vorratskammer ist ein schmaler Raum mit Regalen bis unter die "
       "Decke. Zerbrochene Krüge und leere Säcke liegen herum. Im Osten "
       "führte einst ein Gang weiter, doch er ist eingestürzt. Im Westen "
       "geht es zurück in die Küche.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "In einem der Säcke raschelt es, als wäre er voller Mäuse. Er ist "
       "leer.",
       "Ein Krug füllt sich langsam mit violettem Wein und leert sich "
       "wieder.",
    }));

    o->AddDetail(({"vorratskammer"}),
       "Ein schmaler Raum voller leerer Regale.");

    o->AddDetail(({"regale","regal"}),
       "Leer bis auf Staub und Spinnweben.");

    o->AddDetail(({"spinnweben"}),
       "Alte, verlassene Spinnweben.");

    o->AddDetail(({"kruege","krüge","krug","wein"}),
       "Zerbrochene Tonkrüge.");

    o->AddDetail(({"saecke","säcke","sack","maeuse","mäuse"}),
       "Leere, löchrige Säcke.");

    o->AddDetail(({"gang"}),
       "Der Gang im Osten ist eingestürzt.");

    o->AddDetail(({"kueche","küche"}),
       "Im Westen liegt die Küche.");

    o->AddSound(({"saecke","säcke","rascheln"}),
       "Rascheln, wo nichts ist.");

    o->AddDetail(({"tonkruege","tonkrüge"}),
       "Zerbrochen.");

    versperrt(o,file,"osten",
       "Der Gang nach Osten ist eingestürzt. Da kommst du nicht durch.");
    o->AddExit("westen",     R("[+011+052+08]"));
    break;

    // ---- Obergeschoss des Palas -----------------------------------

    case "[+012+051+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Auf der Galerie im Palas");
    o->chaos_long(
       "Die Galerie zieht sich hoch über der Vorhalle und dem Rittersaal "
       "an der Wand entlang. Das Geländer ist an vielen Stellen "
       "weggebrochen. Im Westen führt eine Tür in die Bibliothek, im "
       "Norden in ein Schlafgemach. Die breite Treppe führt hinunter in "
       "die Vorhalle.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Unten im Rittersaal sitzen schemenhafte Ritter an der Tafel und "
       "verblassen, als du hinschaust.",
       "Das Geländer ist heute vollständig. Morgen wohl nicht mehr.",
    }));

    o->AddDetail(({"galerie"}),
       "Ein schmaler Umgang hoch über dem Palas.");

    o->AddDetail(({"gelaender","geländer"}),
       "Morsch und an vielen Stellen weggebrochen.");

    o->AddDetail(({"vorhalle","rittersaal","tafel"}),
       "Tief unter dir liegen Vorhalle und Rittersaal.");

    o->AddDetail(({"tuer","tür","bibliothek"}),
       "Im Westen führt eine Tür in die Bibliothek.");

    o->AddDetail(({"schlafgemach"}),
       "Im Norden liegt ein Schlafgemach.");

    o->AddDetail(({"treppe"}),
       "Die breite Treppe führt hinunter in die Vorhalle.");

    o->AddDetail(({"ritter"}),
       "Da sind keine. Jetzt nicht mehr.");

    o->AddDetail(({"palas"}),
       "Du bist oben im Palas.");

    o->AddDetail(({"umgang"}),
       "Schmal, mit morschem Geländer.");

    o->AddExit("unten",      R("[+011+051+08]"));
    o->AddExit("westen",     R("[+011+051+09]"));
    o->AddExit("norden",     R("[+012+052+09]"));
    break;

    case "[+011+051+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"In der Bibliothek der Burg Zwielichtstein");
    o->chaos_long(
       "Die Bibliothek ist ein langer, staubiger Raum. An den Wänden "
       "stehen Regale voller alter Schriften, manche angesengt, manche "
       "seltsam flimmernd. Auf einem Lesepult liegt ein Verzeichnis. Im "
       "Osten geht es zurück auf die Galerie.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Ein Buch fliegt flatternd von einem Regal zum anderen.",
       "Die Buchstaben auf den Buchrücken tauschen leise die Plätze.",
    }));

    o->AddDetail(({"bibliothek"}),
       "Ein langer, staubiger Raum voller Regale.");

    o->AddDetail(({"regal","regale"}),
       "Die Regale biegen sich unter der Last der alten Schriften.");

    o->AddDetail(({"last"}),
       "Schwer, sehr schwer.");

    o->AddDetail(({"schriften","schrift","buecher","bücher","buch"}),
       "Alte Schriften der Gilde des Chaos. Welche es gibt, steht im "
       "Verzeichnis.");

    o->AddDetail(({"gilde"}),
       "Die Gilde des Chaos hat hier gesammelt, was sie weiß.");

    o->AddDetail(({"lesepult","pult"}),
       "Auf dem Lesepult liegt das Verzeichnis der Schriften.");

    o->AddDetail(({"verzeichnis","inhalt"}),
       "Das Verzeichnis kannst du lesen ('lies inhalt'). Die Schriften "
       "selbst liest du mit 'lies <kürzel>'.");

    o->AddDetail(({"buchstaben","buchruecken","buchrücken","plaetze",
                   "plätze"}),
       "Sie wechseln die Plätze, wenn du nicht hinsiehst.");

    o->AddDetail(({"galerie"}),
       "Im Osten liegt die Galerie.");

    o->AddSmell(({DEFAULT_SMELL,"papier"}),
       "Es riecht nach Staub, alt und muffig.");

    o->AddExit("osten",      R("[+012+051+09]"));
    break;

    case "[+012+052+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"In einem Schlafgemach");
    o->chaos_long(
       "Das Schlafgemach gehörte wohl einst der Herrin der Burg. Ein "
       "großes Bett mit zerrissenem Himmel steht an der Wand, daneben ein "
       "gesprungener Spiegel. Im Osten führte eine Tür auf einen Balkon, "
       "doch der ist abgestürzt. Im Süden geht es zurück auf die Galerie.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Im gesprungenen Spiegel steht eine Frau in einem grauen Kleid und "
       "kämmt sich die Haare.",
       "Das Bett ist frisch gemacht, die Decke zurückgeschlagen.",
    }));

    o->AddDetail(({"schlafgemach","herrin","gemach"}),
       "Ein großes, verfallenes Gemach.");

    o->AddDetail(({"bett","himmel"}),
       "Ein großes Himmelbett, der Stoff hängt in Fetzen.");

    o->AddDetail(({"stoff","fetzen"}),
       "Einst kostbar, jetzt zerfressen.");

    o->AddDetail(({"spiegel"}),
       "Ein großer, gesprungener Spiegel. Manchmal zeigt er mehr, als im "
       "Raum ist.");

    o->AddDetail(({"frau","kleid","haare"}),
       "Wenn du dich umdrehst, ist niemand da.");

    o->AddDetail(({"tuer","tür","balkon"}),
       "Die Tür im Osten führt ins Leere. Der Balkon ist abgestürzt.");

    o->AddDetail(({"galerie"}),
       "Im Süden liegt die Galerie.");

    o->AddDetail(({"himmelbett"}),
       "Der Stoff hängt in Fetzen.");

    o->AddDetail(({"leere","schritt"}),
       "Dahinter ist nichts als Luft.");

    versperrt(o,file,"osten",
       "Hinter der Tür im Osten ist nichts mehr. Der Balkon ist "
       "abgestürzt, ein Schritt weiter wäre dein letzter.");
    o->AddExit("sueden",     R("[+012+051+09]"));
    break;

    // ---- Keller ----------------------------------------------------

    case "[+011+051+07]":
    hoehe(o,-5);
    o->SetProp(P_LIGHT_TYPE,LT_TORCH);
    o->SetProp(P_INT_SHORT,"Im Kellergang unter dem Palas");
    o->chaos_long(
       "Der Kellergang ist niedrig, feucht und gewölbt. Fackeln in "
       "eisernen Haltern werfen flackerndes Licht. Im Osten dringt Lärm "
       "aus der Schänke, im Norden liegt die Brunnenkammer und im Süden "
       "der Kerker. Der Gang nach Westen ist verschüttet. Eine schmale "
       "Treppe führt hinauf in die Vorhalle.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Fackeln brennen heute mit grünen Flammen.",
       "Dein Schatten an der Wand ist dir ein paar Schritte voraus.",
    }));

    o->AddDetail(({"kellergang","gang","keller"}),
       "Ein niedriger, feuchter Gang unter dem Palas.");

    o->AddDetail(({"fackeln","fackel","halter","flammen"}),
       "Fackeln in rostigen, eisernen Haltern.");

    o->AddDetail(({"licht"}),
       "Flackerndes Fackellicht.");

    o->AddDetail(({"schaenke","schänke","laerm","lärm"}),
       "Im Osten liegt die Schänke.");

    o->AddDetail(({"brunnenkammer"}),
       "Im Norden liegt die Brunnenkammer.");

    o->AddDetail(({"kerker"}),
       "Im Süden liegt der Kerker.");

    o->AddDetail(({"treppe","vorhalle"}),
       "Die Treppe führt hinauf in die Vorhalle.");

    o->AddDetail(({"schritte"}),
       "Ein paar Schritte voraus. Immer.");

    o->AddSound(({DEFAULT_SOUND,"laerm","lärm"}),
       "Laut und fröhlich.");

    o->AddDetail(({"fackellicht"}),
       "Es flackert unruhig.");

    o->AddDetail(({"palas"}),
       "Der Keller liegt unter dem Palas.");

    versperrt(o,file,"westen",
       "Der Gang nach Westen ist verschüttet. Steine und Erde versperren "
       "ihn vollständig.");
    o->AddExit("oben",       R("[+011+051+08]"));
    o->AddExit("osten",      CHAOS_SCHAENKE);
    o->AddExit("norden",     R("[+011+052+07]"));
    o->AddExit("sueden",     R("[+011+050+07]"));
    break;

    case "[+011+052+07]":
    hoehe(o,-5);
    o->SetProp(P_INT_SHORT,"In der Brunnenkammer");
    o->chaos_long(
       "In der Brunnenkammer führt der Schacht des Burgbrunnens senkrecht "
       "in die Tiefe. Eine rostige Winde mit einem gerissenen Seil steht "
       "darüber. Aus dem Schacht steigt kalte, feuchte Luft herauf. Im "
       "Süden geht es zurück in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus dem Schacht steigt ein leises Lied herauf.",
       "Das gerissene Seil ist heute heil. Es führt nach oben, nicht nach "
       "unten.",
    }));

    o->AddDetail(({"brunnenkammer"}),
       "Eine feuchte, kalte Kammer.");

    o->AddDetail(({"schacht","brunnen","burgbrunnen","tiefe"}),
       "Der Schacht führt senkrecht in die Tiefe. Unten glitzert violett "
       "das Wasser.");

    o->AddDetail(({"wasser"}),
       "Tief unten glitzert es violett.");

    o->AddDetail(({"winde","seil"}),
       "Eine rostige Winde mit einem gerissenen Seil.");

    o->AddDetail(({"lied"}),
       "Leise und traurig.");

    o->AddDetail(({"kellergang"}),
       "Im Süden liegt der Kellergang.");

    o->AddSound(({"schacht","lied"}),
       "Leise und traurig.");

    o->AddDetail(({"kammer"}),
       "Eine feuchte, kalte Kammer.");

    versperrt(o,file,"unten",
       "Der Schacht ist viel zu tief, und das Seil ist gerissen.");
    o->AddExit("sueden",     R("[+011+051+07]"));
    break;

    case "[+011+050+07]":
    hoehe(o,-5);
    o->SetProp(P_LIGHT,0);
    o->SetProp(P_INT_SHORT,"Im Kerker der Burg Zwielichtstein");
    o->chaos_long(
       "Der Kerker ist feucht, kalt und düster. An den Wänden reihen "
       "sich Zellen mit rostigen Gittern, hinter denen Dämonen scharren, "
       "fauchen und mit glühenden Augen hervorstarren. Im Osten ist der "
       "Gang zu weiteren Zellen eingestürzt. Im Norden geht es zurück in "
       "den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Einer der Dämonen hat sich heute die Gitterstäbe zu einem Knoten "
       "gebogen. Er kommt trotzdem nicht heraus.",
       "Die Zellen sind heute alle leer. Das Scharren hört man trotzdem.",
    }));

    o->AddDetail(({"kerker"}),
       "Ein feuchter, kalter Kerker voller Zellen.");

    o->AddDetail(({"zelle","zellen","gitter","gitterstaebe",
                   "gitterstäbe","knoten"}),
       "Hinter den rostigen Gittern hocken gefangene Dämonen. Sie zerren "
       "an den Stäben, kommen aber nicht heraus.");

    o->AddDetail(({"daemon","dämon","daemonen","dämonen"}),
       "Die Dämonen in den Zellen fauchen dich an. Manche sind klein und "
       "flink, andere groß und wuchtig. Alle haben glühende Augen.");

    o->AddDetail(({"staebe","stäbe"}),
       "Die Stäbe sind rostig, halten aber.");

    o->AddDetail(({"augen"}),
       "Glühende Augen starren dich aus der Dunkelheit an.");

    o->AddDetail(({"dunkelheit"}),
       "Hier unten ist es fast völlig dunkel.");

    o->AddDetail(({"gang","kellergang"}),
       "Im Norden liegt der Kellergang, im Osten ist der Gang "
       "eingestürzt.");

    o->AddSound(({DEFAULT_SOUND,"scharren","fauchen"}),
       "Es scharrt, faucht und kratzt unablässig.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es stinkt nach Moder und nach Schwefel.");

    o->AddSmell(({"moder"}),
       "Feucht und modrig.");

    versperrt(o,file,"osten",
       "Der Gang zu den hinteren Zellen ist eingestürzt. Vielleicht ist "
       "das auch besser so.");
    o->AddExit("norden",     R("[+011+051+07]"));
    break;

    case "[+012+051+07]":
    hoehe(o,-5);
    o->SetProp(P_INT_SHORT,"In der Schänke der Burg Zwielichtstein");
    o->chaos_long(
       "Die Schänke ist ein niedriges Gewölbe unter dem Rittersaal. Ein "
       "Feuer prasselt in einem Kamin, über dem Tresen hängt eine "
       "Speisekarte. Durch einen feinen Riss in der Wand sickert violettes "
       "Licht und färbt die Getränke seltsam bunt. Im Westen geht es "
       "zurück in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Flammen im Kamin tanzen heute im Takt einer Musik, die "
       "niemand spielt.",
       "Auf dem Tresen steht ein Becher, der sich von selbst nachfüllt. "
       "Leider nur mit Wasser.",
    }));

    o->AddDetail(({"feuer","kamin"}),
       "Im Kamin prasselt ein Feuer, dessen Flammen manchmal violett "
       "aufflackern.");

    o->AddDetail(({"flammen"}),
       "Sie flackern gelb, rot und hin und wieder violett.");

    o->AddDetail(({"tresen","theke"}),
       "Ein alter, klebriger Tresen. Über ihm hängt die Speisekarte.");

    o->AddDetail(({"speisekarte","karte"}),
       "Die Speisekarte hängt über dem Tresen. Lies sie doch.");

    o->AddReadDetail(({"speisekarte","karte"}),"@@menue_text@@");

    o->AddDetail(({"riss","licht"}),
       "Durch einen feinen Riss in der Wand sickert violettes Licht.");

    o->AddDetail(({"getraenke","getränke","becher"}),
       "Im violetten Licht schimmern sie in allen möglichen Farben.");

    o->AddDetail(({"farben","musik","takt"}),
       "Bunt. Sehr bunt.");

    o->AddDetail(({"kellergang"}),
       "Im Westen liegt der Kellergang.");

    o->AddDetail(({"schaenke","schänke"}),
       "Eine gemütliche, verrauchte Schänke.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Rauch, verschüttetem Bier und ein wenig nach "
       "Schwefel.");

    o->AddSmell(({"rauch","bier"}),
       "Rauchig, schal und verschüttet.");

    o->AddSound(({DEFAULT_SOUND,"feuer"}),
       "Es prasselt und klirrt.");

    o->AddToMenu("Chaos-Becher",
         ({"becher","chaos-becher","chaos becher","chaos","chaosbecher"}),
         ([P_HP:28, P_SP:28, P_DRINK:2, P_ALCOHOL:10, P_BUY_VALUE:150]),
         5, "chaos_becher");

    o->AddToMenu("Riss-Schnaps",
         ({"schnaps","riss-schnaps","riss"}),
         ([P_HP:10, P_SP:60, P_DRINK:3, P_ALCOHOL:15, P_BUY_VALUE:150]),
         10,
         ({
           "Du kippst den violett schimmernden Schnaps hinunter. Er "
           "brennt im Hals und klärt den Kopf.",

           "&& kippt einen violett schimmernden Schnaps hinunter."
         }));

    o->AddToMenu("Schwefelsuppe",
         ({"suppe","schwefelsuppe"}),
         ([P_HP:60, P_SP:10, P_FOOD:8, P_BUY_VALUE:150]),
         10,
         ({
           "Du löffelst die gelbe Suppe. Sie stinkt grässlich, macht aber "
           "satt und wärmt von innen.",

           "&& löffelt eine stinkende, gelbe Suppe."
         }));

    o->AddToMenu("Kerkerbrot",
         ({"brot","kerkerbrot"}),
         ([P_HP:20, P_SP:0, P_FOOD:3, P_BUY_VALUE:30]),
         5,
         ({
           "Du kaust auf dem harten, grauen Brot herum. Es schmeckt nach "
           "nichts, aber es füllt den Magen.",

           "&& kaut auf einem harten, grauen Brot herum."
         }));

    o->AddToMenu("Fauliges Leitungswasser",
         ({"wasser","leitungswasser"}),
         ([P_HP:0, P_SP:0, P_DRINK:2, P_BUY_VALUE:5]),
         0,
         ({
           "Du trinkst das faulige Wasser. Igitt.",

           "&& trinkt fauliges Wasser und verzieht das Gesicht."
         }));

    o->AddDetail(({"rittersaal"}),
       "Der Rittersaal liegt über der Schänke.");

    o->AddExit("westen",     R("[+011+051+07]"));
    break;
  }
}
