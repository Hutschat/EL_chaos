// dmaker.c - Die Räume der Burg Zwielichtstein
//
// Plan der Burg in sys/chaosburg.h. Langtexte über chaos_long(), damit
// bei jedem Reset eine wechselnde Zeile dazukommen kann (room/std/
// dets.c).
//
// Die Burg ist eine alte Ruine, in der sich die Chaoten eingenistet
// haben: Was eingestürzt ist, bleibt eingestürzt, und wo sie wohnen,
// ist es dreckig, unordentlich und kaputt.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu
// 27.11.2026 It@Efferdland            ausgebaut
// 27.11.2026 It@Efferdland            neuer Grundriss
// 27.11.2026 It@Efferdland            Bewohner, Achtarchs Laden

#pragma strong_types
#pragma no_clone
#pragma no_inherit
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"
#include <laden.h>
#include <kneipe.h>

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

// ---- Gemeinsames für mehrere Räume ---------------------------------

// Der Burgplatz
static void platz(object o) {
  o->AddDetail(({"burgplatz","platz"}),
     "Der Burgplatz liegt zwischen dem Torhaus im Westen und dem "
     "Hauptgebäude im Osten. Rundherum stehen Gesindehaus, Ställe, "
     "Schmiede, Achtarchs Laden und Kapelle, manche davon nur noch als "
     "Ruine. "
     "Im Nordosten ragt der Turm auf.");

  o->AddDetail(({"feuerstelle","feuerstellen","asche"}),
     "Überall auf dem Platz sind Feuerstellen, mit Steinen eingefasst "
     "und voller Asche. In einer liegt ein halb verkohltes Stuhlbein.");

  o->AddDetail(({"stuhlbein"}),
     "Hier wird geheizt, was gerade herumliegt.");

  o->AddDetail(({"geruempel","gerümpel","moebel","möbel"}),
     "Zerbrochene Möbel, Scherben und Lumpen liegen überall herum.");

  o->AddDetail(({"scherben","lumpen"}),
     "Nichts davon ist noch zu gebrauchen.");

  o->AddDetail(({"gebaeude","gebäude","ruinen"}),
     "Um den Platz stehen die Nebengebäude der Burg, manche bewohnt, "
     "manche nur noch Ruinen.");

  o->AddDetail(({"hauptgebaeude","hauptgebäude"}),
     "Das Hauptgebäude im Osten ist der besterhaltene Teil der Burg. "
     "Fast alle Fenster sind zerbrochen.");

  o->AddDetail(({"fenster"}),
     "Zerbrochen, mit Brettern vernagelt oder mit Lumpen zugestopft.");

  o->AddDetail(({"brettern","bretter"}),
     "Schief angenagelt. Hält trotzdem.");

  o->AddDetail(({"turm"}),
     "Der Turm steht frei im Nordosten des Platzes. An seiner Spitze "
     "flackert violettes Licht.");

  o->AddDetail(({"torhaus"}),
     "Im Westen liegt das Torhaus.");

  o->AddDetail(({"brunnen"}),
     "Mitten auf dem Platz steht der alte Brunnen.");

  o->AddDetail(({"nebengebaeude","nebengebäude"}),
     "Gesindehaus, Ställe, Schmiede, Laden und Kapelle.");

  o->AddDetail(({"gesindehaus"}),
     "Das Gesindehaus im Nordwesten ist jetzt die Schänke.");

  o->AddDetail(({"staelle","ställe"}),
     "Die Ställe im Norden sind eine Ruine.");

  o->AddDetail(({"schmiede"}),
     "Die Schmiede im Südwesten ist noch in Betrieb.");

  o->AddDetail(({"werkstatt","laden","achtarch"}),
     "In der Ruine der alten Werkstatt im Süden hat Achtarch seinen Laden "
     "eingerichtet.");

  o->AddDetail(({"kapelle"}),
     "Die alte Kapelle im Südosten ist eine Ruine ohne Dach.");

  o->AddDetail(({"spitze","licht"}),
     "An der Spitze des Turms flackert violettes Licht.");

  o->AddDetail(({"teil"}),
     "Manches steht noch, manches nicht.");

  o->AddDetail(({"dach","grundmauern"}),
     "Viele Gebäude haben kein Dach mehr, von manchen stehen nur noch "
     "die Grundmauern.");

  o->AddDetail(({"schaenke","schänke"}),
     "Die Schänke liegt im Gesindehaus im Nordwesten.");

  o->AddDetail(({"betrieb"}),
     "Wenn auch nicht so, wie früher.");

  o->AddDetail(({"feuer"}),
     "In manchen Feuerstellen glimmt es noch.");
}

// Der Mittelgang im Erdgeschoss
static void mittelgang(object o) {
  o->AddDetail(({"mittelgang","gang"}),
     "Der Mittelgang führt von der Eingangshalle im Westen zum "
     "Rittersaal im Osten. Zu beiden Seiten gehen Türen ab.");

  o->AddDetail(({"seiten","teil","westende","ostende"}),
     "Der Gang ist lang. Zu beiden Seiten gehen Türen ab.");

  o->AddDetail(({"tueren","türen"}),
     "Manche hängen nur noch in einer Angel, eine fehlt ganz.");

  o->AddDetail(({"angel"}),
     "Rostig und verbogen.");

  o->AddDetail(({"wandteppiche","wandteppich","teppiche"}),
     "Alte Wandteppiche, angekokelt und voller Löcher. Was einmal darauf "
     "zu sehen war, kann niemand mehr sagen.");

  o->AddDetail(({"loecher","löcher"}),
     "Brandlöcher, Mottenlöcher und ein paar, die aussehen, als hätte "
     "jemand hineingebissen.");

  o->AddDetail(({"brandloecher","brandlöcher","mottenloecher",
                 "mottenlöcher"}),
     "Viele.");

  o->AddDetail(({"eingangshalle"}),
     "Die Eingangshalle liegt am Westende des Gangs.");

  o->AddDetail(({"rittersaal"}),
     "Der Rittersaal liegt am Ostende des Gangs.");
}

// Der obere Gang
static void obergang(object o) {
  hoehe(o,10);
  o->AddDetail(({"gang"}),
     "Der obere Gang verläuft über dem Mittelgang, vom Söller im Westen "
     "zur Galerie im Osten.");

  o->AddDetail(({"mittelgang"}),
     "Der Mittelgang liegt unter dir.");

  o->AddDetail(({"teil","mitte","westende","ostende"}),
     "Der Gang ist lang und knarrt überall.");

  o->AddDetail(({"dielen","diele"}),
     "Der Gang hat einen Boden aus Holzdielen. Sie knarren, und ein paar "
     "fehlen.");

  o->AddDetail(({"holzdielen","holz"}),
     "Knarrend und morsch.");

  o->AddDetail(({"soeller","söller"}),
     "Der Söller liegt am Westende des Gangs.");

  o->AddDetail(({"galerie"}),
     "Die Galerie liegt am Ostende des Gangs.");

  o->AddDetail(({"tueren","türen","tuer","tür"}),
     "Schiefe Türen, eine ist nur mit einem Vorhang verhängt.");

  o->AddDetail(({"vorhang"}),
     "Ein angekokelter, alter Vorhang.");

  o->AddSound(({"dielen"}),
     "Knarz.");
}

// Der Kellergang
static void kellergang(object o) {
  hoehe(o,-5);
  o->SetProp(P_LIGHT_TYPE,LT_TORCH);
  o->AddDetail(({"kellergang","gang","keller"}),
     "Ein niedriger, feuchter Gang unter dem Hauptgebäude. Er führt vom "
     "Weinkeller im Osten zur Gruft im Westen.");

  o->AddDetail(({"hauptgebaeude","hauptgebäude","teil","mitte"}),
     "Über dir liegt das Hauptgebäude.");

  o->AddDetail(({"fackeln","fackel","halter"}),
     "Fackeln in rostigen Haltern. Irgendwer erneuert sie, aber nicht "
     "oft genug.");

  o->AddDetail(({"licht"}),
     "Flackerndes, rußiges Fackellicht.");

  o->AddDetail(({"fackellicht"}),
     "Es flackert unruhig.");

  o->AddDetail(({"weinkeller"}),
     "Im Osten liegt der Weinkeller.");

  o->AddDetail(({"gruft"}),
     "Im Westen liegt die Gruft.");

  o->AddDetail(({"pfuetzen","pfützen","wasser"}),
     "Auf dem Boden stehen Pfützen. Manche schillern violett.");

  o->AddSmell(({DEFAULT_SMELL}),
     "Es riecht nach Moder, Rauch und ein wenig nach Schwefel.");

  o->AddSmell(({"moder","rauch"}),
     "Feucht und rußig.");
}

public varargs void create_room(string file, object o) {
  if(!::create_room(file,o,CHAOS_VC_BURG)) {
    return;
  }
  switch(file) {

    // ==== Torhaus und Wehrgang =======================================

    case "[+007+051+08]":
    o->SetProp(P_INT_SHORT,"Im Torhaus der Burg Zwielichtstein");
    o->chaos_long(
       "Du stehst im Torhaus der Burg Zwielichtstein, einem dunklen, "
       "gewölbten Durchgang. Über dir hängt das Fallgitter verbogen und "
       "rostig in seiner Führung. Jemand hat mit violetter Farbe "
       "»Willkommen!« an die Wand geschmiert, darunter kleiner: »Auf "
       "eigene Gefahr«. Im Westen geht es hinaus ins Schattental, im "
       "Osten auf den Burgplatz. Eine enge Treppe führt hinauf auf den "
       "Wehrgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Das Fallgitter senkt sich lautlos eine Handbreit und hebt sich "
       "dann wieder.",
       "Unter dem Willkommen hat jemand eine grinsende Fratze gemalt.",
    }));

    o->AddDetail(({"torhaus","durchgang"}),
       "Ein dunkler, gewölbter Durchgang durch die dicke Mauer.");

    o->AddDetail(({"fallgitter","gitter","fuehrung","führung"}),
       "Das Fallgitter hängt verbogen und rostig in seiner Führung. "
       "Hoffentlich hält es noch eine Weile.");

    o->AddDetail(({"rost","weile","eisen"}),
       "Rotbrauner Rost frisst sich durch das alte Eisen.");

    o->AddDetail(({"farbe","willkommen","gefahr","fratze"}),
       "Violette Farbe, dick aufgetragen und an mehreren Stellen "
       "heruntergelaufen. »Willkommen! Auf eigene Gefahr.«");

    o->AddDetail(({"schattental"}),
       "Im Westen führt der Weg hinunter ins Schattental.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Osten liegt der Burgplatz.");

    o->AddDetail(({"treppe","wehrgang"}),
       "Eine enge, ausgetretene Treppe führt hinauf auf den Wehrgang.");

    o->AddSound(({"fallgitter","gitter"}),
       "Das Fallgitter quietscht leise.");

    o->AddDetail(({"weg"}),
       "Der Weg führt hinunter ins Schattental.");

    o->AddExit("westen",     CHAOS_BURGPFAD);
    o->AddExit("osten",      R("[+008+051+08]"));
    o->AddExit("oben",       R("[+007+051+09]"));
    break;

    case "[+007+051+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Auf dem Wehrgang über dem Torhaus");
    o->chaos_long(
       "Der Wehrgang zieht sich über dem Torhaus an der Westmauer "
       "entlang. Die Zinnen sind größtenteils abgebrochen. Tief unten im "
       "Westen liegt das Schattental, im Osten der Burgplatz mit seinen "
       "Feuerstellen. Nach Norden und Süden ist der Wehrgang eingestürzt. "
       "Auf den Steinen liegen leere Flaschen, hier sitzt wohl öfter "
       "jemand und schaut ins Tal.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Ein Rabe sitzt auf einer Zinne und krächzt rückwärts.",
       "Unten im Tal scheinen die Wände der Menagerie sich langsam zu "
       "verschieben.",
    }));

    o->AddDetail(({"wehrgang"}),
       "Schmal und zugig.");

    o->AddDetail(({"zinnen","zinne"}),
       "Die meisten Zinnen sind abgebrochen. Lehn dich besser nicht zu "
       "weit hinaus.");

    o->AddDetail(({"westmauer"}),
       "Die Westmauer ist rissig, hält aber noch.");

    o->AddDetail(({"schattental","tal","menagerie","waende","wände"}),
       "Tief unten im Westen liegt das Schattental mit dem Labyrinth der "
       "Menagerie.");

    o->AddDetail(({"labyrinth"}),
       "Schwarze Wände, von hier oben gut zu sehen.");

    o->AddDetail(({"burgplatz","platz","feuerstellen"}),
       "Im Osten liegt der Burgplatz. Aus den Feuerstellen steigt Rauch "
       "auf.");

    o->AddDetail(({"rauch"}),
       "Dünner, grauer Rauch.");

    o->AddDetail(({"flaschen","flasche"}),
       "Leere Flaschen. An einer klebt noch ein Rest Riss-Schnaps.");

    o->AddDetail(({"rest","riss-schnaps","schnaps"}),
       "Violett und klebrig.");

    o->AddDetail(({"rabe"}),
       "Ein zerzauster, schwarzer Rabe.");

    o->AddDetail(({"torhaus","treppe"}),
       "Eine enge Treppe führt hinunter ins Torhaus.");

    versperrt(o,file,"norden",
       "Nach Norden ist der Wehrgang eingestürzt. Dort klafft eine Lücke, "
       "tief unten liegen Trümmer.");
    versperrt(o,file,"sueden",
       "Nach Süden endet der Wehrgang an einem Haufen herabgestürzter "
       "Steine. Jemand hat ein Schild davor gestellt: »Hier nicht!«");
    o->AddExit("unten",      R("[+007+051+08]"));
    break;

    // ==== Burgplatz ==================================================

    case "[+008+052+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"In der Nordwestecke des Burgplatzes");
    o->chaos_long(
       "Du stehst in der Nordwestecke des Burgplatzes. Im Norden steht das "
       "Gesindehaus, das einzige Nebengebäude mit einem halbwegs dichten "
       "Dach. Aus der offenen Tür dringen Lärm und der Geruch von "
       "verschüttetem Bier. Zwischen dem Gesindehaus und der Mauer ist "
       "eine Leine gespannt, an der Roben trocknen.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Eine der Roben an der Leine winkt dir mit einem Ärmel zu.",
       "Vor der Tür des Gesindehauses schläft ein Chaot im Dreck.",
    }));

    o->AddDetail(({"gesindehaus","dach","tuer","tür"}),
       "Das Gesindehaus im Norden ist jetzt die Schänke der Burg. Über "
       "der Tür hängt ein schiefes Schild.");

    o->AddDetail(({"schild"}),
       "»Zum schiefen Pentagramm«. Das Pentagramm darauf ist tatsächlich "
       "schief.");

    o->AddDetail(({"leine","roben","robe","aermel","ärmel"}),
       "An der Leine hängen schwarze und violette Roben. Die meisten "
       "haben Brandlöcher.");

    o->AddDetail(({"brandloecher","brandlöcher"}),
       "In jeder Robe mindestens eins.");

    o->AddDetail(({"laerm","lärm","bier"}),
       "Der Lärm kommt aus der Schänke.");

    o->AddDetail(({"dreck"}),
       "Hier liegt eine Menge davon.");

    o->AddSound(({DEFAULT_SOUND,"laerm","lärm"}),
       "Aus dem Gesindehaus dringen Gelächter und Becherklirren.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Rauch und verschüttetem Bier.");

    o->AddDetail(({"nordwestecke","ecke"}),
       "Hier stehst du.");

    o->AddDetail(({"geruch"}),
       "Bier und Rauch.");

    o->AddDetail(({"rauch"}),
       "Er zieht aus der Tür.");

    o->AddDetail(({"menge"}),
       "Eine große.");

    o->AddSmell(({"bier","rauch"}),
       "Schal und rauchig.");

    o->AddSound(({"becherklirren","gelaechter","gelächter","gesindehaus"}),
       "Laut und fröhlich.");

    o->AddExit("norden",     CHAOS_SCHAENKE);
    o->AddExit("osten",      R("[+009+052+08]"));
    o->AddExit("sueden",     R("[+008+051+08]"));
    break;

    case "[+009+052+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"Im Norden des Burgplatzes");
    o->chaos_long(
       "Du stehst im Norden des Burgplatzes. Vor dir liegen die Ruinen der "
       "Ställe, deren Dach längst eingestürzt ist. Neben dem Eingang "
       "türmt sich ein Haufen zerbrochener Möbel, wohl das Brennholz für "
       "die Feuerstellen. Im Westen liegt das Gesindehaus, im Osten steht "
       "der Turm.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf dem Möbelhaufen sitzt ein Stuhl, der noch ganz ist. Er sieht "
       "beleidigt aus.",
       "Aus den Ställen ist ein Schnauben zu hören, das nach nichts klingt, "
       "was du kennst.",
    }));

    o->AddDetail(({"staelle","ställe","eingang"}),
       "Die Ställe im Norden sind eine Ruine ohne Dach.");

    o->AddDetail(({"haufen","moebelhaufen","möbelhaufen","brennholz"}),
       "Stuhlbeine, Tischplatten, eine halbe Truhe. Alles, was brennt.");

    o->AddDetail(({"stuhlbeine","tischplatten","truhe","stuhl"}),
       "Zerbrochen und bereit für das nächste Feuer.");

    o->AddDetail(({"gesindehaus"}),
       "Im Westen liegt das Gesindehaus mit der Schänke.");

    o->AddSound(({"schnauben"}),
       "Tief und kehlig.");

    o->AddExit("norden",     R("[+009+053+08]"));
    o->AddExit("westen",     R("[+008+052+08]"));
    o->AddExit("osten",      R("[+010+052+08]"));
    o->AddExit("sueden",     R("[+009+051+08]"));
    break;

    case "[+010+052+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"In der Nordostecke des Burgplatzes");
    o->chaos_long(
       "Du stehst in der Nordostecke des Burgplatzes, am Fuß des Turms. "
       "Er steht frei, ein Stück vom Hauptgebäude entfernt, und neigt sich "
       "bedenklich. An seiner Spitze flackert violettes Licht. Die Tür im "
       "Norden ist mit Kreidezeichen bedeckt. Im Osten ragt das "
       "Hauptgebäude auf.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Das Licht an der Turmspitze pulsiert heute schneller.",
       "Ein Funkenregen geht vom Turm nieder und verlischt, bevor er den "
       "Boden erreicht.",
    }));

    o->AddDetail(({"turm","fuss","fuß"}),
       "Der Turm neigt sich bedenklich. An seiner Spitze flackert "
       "violettes Licht.");

    o->AddDetail(({"spitze","turmspitze","licht"}),
       "Violettes Licht flackert dort oben.");

    o->AddDetail(({"tuer","tür","kreidezeichen","zeichen"}),
       "Pentagramme, Pfeile und eine Warnung: »Nur für Mutige. Und "
       "Dumme.«");

    o->AddDetail(({"pentagramme","pfeile","warnung"}),
       "Alles mit Kreide, alles etwas krakelig.");

    o->AddDetail(({"funkenregen","funken"}),
       "Violette Funken, harmlos. Meistens.");

    o->AddDetail(({"nordostecke","ecke"}),
       "Hier stehst du.");

    o->AddDetail(({"mutige","dumme","stueck","stück"}),
       "Wer die Warnung liest, darf sich aussuchen, was er ist.");

    o->AddExit("norden",     R("[+010+053+08]"));
    o->AddExit("westen",     R("[+009+052+08]"));
    o->AddExit("sueden",     R("[+010+051+08]"));
    break;

    case "[+008+051+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"Im Westen des Burgplatzes");
    o->chaos_long(
       "Du stehst auf dem Burgplatz, gleich hinter dem Torhaus im Westen. "
       "Vor dir öffnet sich der Platz, ein holpriges Rechteck voller "
       "Feuerstellen, Gerümpel und zertrampeltem Gras. Rundherum stehen "
       "Nebengebäude, viele davon nur noch Ruinen. Am Ostende ragt das "
       "Hauptgebäude auf, im Nordosten der schiefe Turm.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Zwei Chaoten streiten sich lautstark darüber, wessen Dämon den "
       "Brunnen angesengt hat.",
       "Ein Haufen Lumpen bewegt sich. Es ist nur ein schlafender Chaot.",
    }));

    o->AddDetail(({"rechteck"}),
       "Der Burgplatz ist grob rechteckig und ziemlich verwahrlost.");

    o->AddDetail(({"nebengebaeude","nebengebäude"}),
       "Gesindehaus, Ställe, Schmiede, Laden und Kapelle.");

    o->AddDetail(({"chaoten","chaot"}),
       "Gerade ist keiner zu sehen. Gehört hört man sie trotzdem.");

    o->AddDetail(({"ostende"}),
       "Dort steht das Hauptgebäude.");

    o->AddExit("westen",     CHAOS_BURGTOR);
    o->AddExit("norden",     R("[+008+052+08]"));
    o->AddExit("osten",      R("[+009+051+08]"));
    o->AddExit("sueden",     R("[+008+050+08]"));
    break;

    case "[+009+051+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"Am Brunnen auf dem Burgplatz");
    o->chaos_long(
       "Mitten auf dem Burgplatz steht der alte Brunnen. Seine Einfassung "
       "ist angesengt, und auf dem Rand liegen Becher, Knochen und ein "
       "Buch, das jemand dort vergessen hat. Um dich herum liegt der "
       "Platz mit seinen Feuerstellen, im Osten das Hauptgebäude.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Über dem Brunnen schwebt eine Kugel aus Wasser und dreht sich "
       "langsam.",
       "Aus dem Brunnen steigt ein Blubbern, als würde unten jemand "
       "kochen.",
       "Jemand hat einen Eimer violetter Farbe in den Brunnen gekippt.",
    }));

    o->AddDetail(({"brunnen","einfassung","rand"}),
       "Ein alter, gemauerter Brunnen. Die Einfassung ist angesengt, als "
       "hätte etwas sehr Heißes daran gesessen. Tief unten glitzert "
       "Wasser.");

    o->AddDetail(({"wasser","kugel"}),
       "Das Wasser glitzert violett. Trinken würde es nur ein Chaot.");

    o->AddDetail(({"becher","knochen"}),
       "Leere Becher und abgenagte Knochen.");

    o->AddDetail(({"buch"}),
       "Ein zerlesenes Buch mit dem Titel »Beschwören für Anfänger«. Die "
       "Hälfte der Seiten ist herausgerissen, die andere angekokelt.");

    o->AddDetail(({"seiten","titel","haelfte","hälfte"}),
       "Viel ist davon nicht mehr zu lesen.");

    o->AddDetail(({"eimer","farbe"}),
       "Der Eimer liegt noch daneben.");

    o->AddSound(({"brunnen","blubbern"}),
       "Blubb.");

    o->AddDetail(({"anfaenger","anfänger","beschwoeren","beschwören","hoffnung"}),
       "Der Titel macht wenig Hoffnung.");

    o->AddDetail(({"heisses","heißes"}),
       "Irgendein heißer Dämon vielleicht.");

    o->AddDetail(({"chaoslehrling","lehrling","lehrlinge"}),
       "Lehrlinge laufen hier ständig herum.");

    o->AddItem(CHAOS_GILDEN_MON("lehrling"),REFRESH_DESTRUCT);

    o->AddExit("norden",     R("[+009+052+08]"));
    o->AddExit("westen",     R("[+008+051+08]"));
    o->AddExit("osten",      R("[+010+051+08]"));
    o->AddExit("sueden",     R("[+009+050+08]"));
    break;

    case "[+010+051+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"Vor dem Hauptgebäude");
    o->chaos_long(
       "Du stehst am Ostrand des Burgplatzes vor dem Hauptgebäude der "
       "Burg. Eine breite Steintreppe führt zum Portal hinauf, dessen "
       "Flügel schief in den Angeln hängen. Über dem Portal ist ein altes "
       "Wappen zu sehen, das jemand mit einem grinsenden Gesicht "
       "übermalt hat.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf der Treppe sitzen drei leere Becher in einer Reihe, als "
       "würden sie auf jemanden warten.",
       "Das Gesicht über dem Portal zwinkert dir zu.",
    }));

    o->AddDetail(({"steintreppe","treppe"}),
       "Eine breite Steintreppe mit ausgetretenen Stufen.");

    o->AddDetail(({"stufen"}),
       "Ausgetreten und voller Brandflecken.");

    o->AddDetail(({"portal","fluegel","flügel","angeln"}),
       "Das Portal steht offen. Schließen lässt es sich schon lange nicht "
       "mehr.");

    o->AddDetail(({"wappen","gesicht"}),
       "Unter dem grinsenden Gesicht ist noch ein Stück des alten Wappens "
       "zu sehen: ein Stern, durch den ein Sprung geht.");

    o->AddDetail(({"stern","sprung"}),
       "Gesprungen und verblasst.");

    o->AddDetail(({"becher"}),
       "Leer, natürlich.");

    o->AddDetail(({"ostrand","stueck","stück"}),
       "Hier beginnt das Hauptgebäude.");

    o->AddExit("osten",      R("[+011+051+08]"));
    o->AddExit("norden",     R("[+010+052+08]"));
    o->AddExit("westen",     R("[+009+051+08]"));
    o->AddExit("sueden",     R("[+010+050+08]"));
    break;

    case "[+008+050+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"In der Südwestecke des Burgplatzes");
    o->chaos_long(
       "Du stehst in der Südwestecke des Burgplatzes. Im Süden steht die "
       "Schmiede, aus deren Esse violetter Rauch aufsteigt. Davor liegt "
       "ein Haufen verbogener Metallteile, an denen sich jemand versucht "
       "hat.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Eines der Metallteile zuckt, als wollte es noch etwas werden.",
       "Aus der Schmiede ist ein lauter Schlag und ein noch lauterer Fluch "
       "zu hören.",
    }));

    o->AddDetail(({"schmiede","esse"}),
       "Die Schmiede im Süden ist noch in Gebrauch, wenn auch nicht für "
       "das, wofür sie gebaut wurde.");

    o->AddDetail(({"rauch"}),
       "Violetter Rauch. Kein gutes Zeichen.");

    o->AddDetail(({"metallteile","haufen"}),
       "Verbogene Klingen, ein Helm mit drei Löchern für die Augen, ein "
       "Hufeisen mit Zacken.");

    o->AddDetail(({"klingen","helm","hufeisen","zacken","augen"}),
       "Kein Teil davon sieht so aus, wie es sollte.");

    o->AddDetail(({"zeichen"}),
       "Ein gutes ist es nicht.");

    o->AddDetail(({"gebrauch"}),
       "Noch.");

    o->AddDetail(({"loechern","löchern"}),
       "Für die Augen. Drei.");

    o->AddDetail(({"suedwestecke","südwestecke","ecke"}),
       "Hier stehst du.");

    o->AddExit("sueden",     R("[+008+049+08]"));
    o->AddExit("norden",     R("[+008+051+08]"));
    o->AddExit("osten",      R("[+009+050+08]"));
    break;

    case "[+009+050+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"Im Süden des Burgplatzes");
    o->chaos_long(
       "Du stehst im Süden des Burgplatzes. Im Süden liegt die Ruine der "
       "alten Werkstatt, die jemand mit Brettern und Planen zu einem Laden "
       "umgebaut hat. Über dem Eingang hängt ein Schild. Hier hängt Wäsche "
       "zwischen zwei Pfählen, und ein umgedrehter Kessel dient als Tisch "
       "für ein angefangenes Würfelspiel.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Würfel auf dem Kessel zeigen alle eine Sieben.",
       "Die Wäsche flattert, obwohl kein Wind geht.",
    }));

    o->AddDetail(({"werkstatt","ruine","laden","brettern","bretter",
                   "planen","eingang"}),
       "Die alte Werkstatt im Süden ist eine Ruine, aber Achtarch hat sie "
       "mit Brettern und Planen zu seinem Laden gemacht.");

    o->AddDetail(({"schild"}),
       "»Achtarchs Laden. Nützliches für böse Zaubersprüche. Und Fackeln.«");

    o->AddReadDetail(({"schild"}),
       "»Achtarchs Laden. Nützliches für böse Zaubersprüche. Und "
       "Fackeln.«\n");

    o->AddDetail(({"waesche","wäsche","pfaehle","pfähle","pfahl"}),
       "Socken, Hemden und eine Robe mit einem großen Loch auf dem "
       "Rücken.");

    o->AddDetail(({"socken","hemden","robe","loch","ruecken","rücken"}),
       "Alles leicht angesengt.");

    o->AddDetail(({"kessel","tisch"}),
       "Ein umgedrehter Kessel, als Tisch benutzt.");

    o->AddDetail(({"wuerfelspiel","würfelspiel","wuerfel","würfel",
                   "sieben"}),
       "Drei Würfel liegen auf dem Kessel. Wer gerade dran war, ist nicht "
       "zu erkennen.");

    o->AddDetail(({"fackeln","zaubersprueche","zaubersprüche"}),
       "Das steht auf dem Schild.");

    o->AddExit("sueden",     R("[+009+049+08]"));
    o->AddExit("norden",     R("[+009+051+08]"));
    o->AddExit("westen",     R("[+008+050+08]"));
    o->AddExit("osten",      R("[+010+050+08]"));
    break;

    case "[+010+050+08]":
    platz(o);
    o->SetProp(P_INT_SHORT,"In der Südostecke des Burgplatzes");
    o->chaos_long(
       "Du stehst in der Südostecke des Burgplatzes. Im Süden liegt die "
       "alte Kapelle, nur noch eine Ruine ohne Dach. Vor ihrem Eingang "
       "steht ein Pfahl mit einem Schild. Im Osten ragt die Mauer des "
       "Hauptgebäudes auf, über und über mit Ruß geschwärzt.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Am Schild hat jemand ein zweites befestigt: »Doch, geht.«",
       "Vor der Kapelle liegt ein toter Rabe, der dir hinterherschaut.",
    }));

    o->AddDetail(({"kapelle","eingang"}),
       "Die alte Kapelle im Süden ist eine Ruine.");

    o->AddDetail(({"pfahl","schild"}),
       "Auf dem Schild steht: »Alte Kapelle. Beschwören verboten.« Das "
       "»verboten« ist durchgestrichen.");

    o->AddDetail(({"mauer","russ","ruß"}),
       "Die Mauer des Hauptgebäudes ist rußgeschwärzt. Hier hat es wohl "
       "mehr als einmal gebrannt.");

    o->AddDetail(({"rabe"}),
       "Er ist eindeutig tot. Und er schaut eindeutig.");

    o->AddDetail(({"suedostecke","südostecke","ecke"}),
       "Hier stehst du.");

    o->AddExit("sueden",     R("[+010+049+08]"));
    o->AddExit("norden",     R("[+010+051+08]"));
    o->AddExit("westen",     R("[+009+050+08]"));
    break;

    // ==== Nebengebäude ===============================================

    case "[+008+053+08]":
    o->SetProp(P_INT_SHORT,"In der Schänke »Zum schiefen Pentagramm«");
    o->chaos_long(
       "Die Schänke im alten Gesindehaus ist laut, verraucht und klebrig. "
       "Hinter dem Tresen, in den jemand Brandlöcher gebrannt hat, hängt "
       "eine Speisekarte. In einem offenen Kamin prasselt ein Feuer, das "
       "manchmal violett aufflackert. Bänke, Stühle und Tische sind "
       "zusammengewürfelt, kein Teil passt zum anderen. Im Süden geht es "
       "hinaus auf den Burgplatz.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Flammen im Kamin tanzen heute im Takt einer Musik, die "
       "niemand spielt.",
       "Unter einem Tisch schläft ein kleiner Dämon, den Kopf in einem "
       "Bierkrug.",
       "An der Wand hängt ein neuer Zettel: »Anschreiben nur für "
       "Erzmeister!«",
    }));

    o->AddDetail(({"schaenke","schänke","gesindehaus"}),
       "Das alte Gesindehaus. Heute ist es die Schänke der Chaoten.");

    o->AddDetail(({"tresen","theke","brandloecher","brandlöcher"}),
       "Ein klebriger Tresen voller Brandlöcher. Über ihm hängt die "
       "Speisekarte.");

    o->AddDetail(({"speisekarte","karte"}),
       "Die Speisekarte hängt über dem Tresen. Lies sie doch.");

    o->AddReadDetail(({"speisekarte","karte"}),
                     symbol_function("menue_text",o));

    o->AddDetail(({"kamin","feuer","flammen"}),
       "Im Kamin prasselt ein Feuer, dessen Flammen manchmal violett "
       "aufflackern.");

    o->AddDetail(({"baenke","bänke","stuehle","stühle","tische","tisch"}),
       "Zusammengesucht aus allen Teilen der Burg. Kein Stuhl gleicht dem "
       "anderen.");

    o->AddDetail(({"teil"}),
       "Kein Teil passt zum anderen.");

    o->AddDetail(({"daemon","dämon","kopf","bierkrug"}),
       "Er schnarcht in den Krug.");

    o->AddDetail(({"musik","takt"}),
       "Woher sie kommt, weiß keiner.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Süden liegt der Burgplatz.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Rauch, verschüttetem Bier und ein wenig nach "
       "Schwefel.");

    o->AddSmell(({"rauch","bier"}),
       "Rauchig, schal und verschüttet.");

    o->AddSound(({DEFAULT_SOUND,"feuer"}),
       "Es prasselt, klirrt und lacht.");

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

    o->AddDetail(({"krug"}),
       "Er schnarcht hinein.");

    o->AddDetail(({"licht"}),
       "Flackernd, vom Kamin.");

    o->AddDetail(({"stuhl"}),
       "Kein Stuhl gleicht dem anderen.");

    o->SetProp(P_PUB_KEEPER,CHAOS_ID_WIRT);
    o->AddDetail(({"wirt","krummbart"}),
       "Krummbart, der Wirt, steht meistens hinter dem Tresen.");

    o->AddItem(CHAOS_GILDEN_MON("wirt"),REFRESH_DESTRUCT);

    o->AddExit("sueden",     R("[+008+052+08]"));
    break;

    case "[+009+053+08]":
    o->SetProp(P_INT_SHORT,"In der Ruine der Ställe");
    o->chaos_long(
       "Von den Ställen sind nur die Mauern übrig, das Dach ist "
       "eingestürzt und liegt in verkohlten Balken auf dem Boden. In den "
       "alten Boxen stehen keine Pferde mehr. Stattdessen sind ein paar "
       "Boxen mit Ketten und Brettern zu Verschlägen umgebaut, in denen "
       "angenagte Knochen liegen. Im Süden geht es zurück auf den "
       "Burgplatz.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus einem der Verschläge glühen zwei Augen.",
       "Die Ketten an einem Verschlag sind zerrissen. Was immer darin war, "
       "ist jetzt woanders.",
    }));

    o->AddDetail(({"staelle","ställe","ruine","mauern"}),
       "Die Mauern stehen noch, sonst nicht viel.");

    o->AddDetail(({"dach","balken"}),
       "Verkohlte Balken liegen kreuz und quer.");

    o->AddDetail(({"boxen","box","pferde"}),
       "Pferde gibt es hier schon lange keine mehr.");

    o->AddDetail(({"verschlaege","verschläge","verschlag","ketten",
                   "bretter","brettern"}),
       "Hier halten die Chaoten wohl ihre Dämonen, wenn sie gerade keine "
       "Verwendung für sie haben. Die Bretter sind zerkratzt und "
       "angesengt.");

    o->AddDetail(({"knochen"}),
       "Angenagt. Von wem, willst du gar nicht wissen.");

    o->AddDetail(({"augen"}),
       "Rot und glühend. Dann sind sie weg.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Süden liegt der Burgplatz.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es stinkt nach Mist, Schwefel und verbranntem Holz.");

    o->AddSmell(({"mist","holz"}),
       "Kein Pferdemist. Irgendetwas anderes.");

    o->AddDetail(({"verwendung"}),
       "Dämonen, die gerade niemand braucht.");

    o->AddSmell(({"pferdemist"}),
       "Nein, kein Pferdemist.");

    o->AddExit("sueden",     R("[+009+052+08]"));
    break;

    case "[+008+049+08]":
    o->SetProp(P_LIGHT_TYPE,LT_FIRE);
    o->SetProp(P_INT_SHORT,"In der Schmiede der Burg Zwielichtstein");
    o->chaos_long(
       "Die Schmiede ist ein niedriger, verrußter Raum. In der Esse brennt "
       "ein violettes Feuer, das kaum Wärme gibt, aber Eisen trotzdem "
       "zum Glühen bringt. Auf dem Amboss liegt ein halbfertiges Ding, "
       "das entweder ein Schwert oder ein Kochlöffel werden soll. Überall "
       "liegen Werkzeuge herum. Im Norden geht es zurück auf den "
       "Burgplatz.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Ab und zu erklingt ein Hammerschlag auf dem Amboss, aber niemand "
       "ist da.",
       "Das Ding auf dem Amboss hat seit gestern einen Griff mehr.",
    }));

    o->AddDetail(({"schmiede"}),
       "Ein niedriger, verrußter Raum.");

    o->AddDetail(({"esse","feuer"}),
       "Ein violettes Feuer, das ohne Kohle brennt.");

    o->AddDetail(({"waerme","wärme","kohle"}),
       "Kaum zu spüren.");

    o->AddDetail(({"amboss"}),
       "Ein schwerer, eiserner Amboss mit tiefen Kerben.");

    o->AddDetail(({"kerben"}),
       "Spuren unzähliger Hammerschläge.");

    o->AddDetail(({"ding","schwert","kochloeffel","kochlöffel","griff"}),
       "Lang, verbogen, mit zwei Griffen und einer Mulde. Was es werden "
       "soll, weiß vermutlich nicht einmal der Schmied.");

    o->AddDetail(({"mulde","griffe"}),
       "Was das soll, weiß nur Klonk.");

    o->AddDetail(({"werkzeuge","werkzeug","zangen","haemmer","hämmer"}),
       "Zangen und Hämmer, achtlos hingeworfen.");

    o->AddDetail(({"eisen"}),
       "Es glüht violett.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Norden liegt der Burgplatz.");

    o->AddSound(({"hammerschlag","amboss"}),
       "Klong.");

    o->AddDetail(({"gluehen","glühen"}),
       "Violett.");

    o->AddDetail(({"hammerschlaege","hammerschläge"}),
       "Du hörst sie, aber niemand schlägt.");

    o->AddDetail(({"schmied","klonk"}),
       "Klonk, der Schmied, ist meistens hier.");

    o->AddItem(CHAOS_GILDEN_MON("schmied"),REFRESH_DESTRUCT);

    o->AddExit("norden",     R("[+008+050+08]"));
    break;

    case "[+009+049+08]":
    o->SetProp(P_INT_SHORT,"In Achtarchs Laden");
    o->chaos_long(
       "Achtarch hat die Ruine der alten Werkstatt zu seinem Laden "
       "gemacht. Über den Grundmauern spannen sich Planen und Bretter als "
       "Dach, durch die Lücken tropft es. Hinter einem Tresen aus einer "
       "alten Hobelbank stehen Regale mit Kreide, Kerzen, Fackeln und "
       "allerlei Kram. Über dem Tresen hängt eine Medaille, die Achtarch "
       "jedem zeigt, ob er will oder nicht. Im Norden geht es zurück auf "
       "den Burgplatz.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Durch eine Lücke im Dach tropft es genau auf den Tresen. Achtarch "
       "hat einen Eimer daruntergestellt.",
       "Ein Stück Kreide wandert von selbst über das Regal.",
    }));

    o->SetProp(P_SHOP_STORE_ITEMS,({
       ({POOL_KOMPOS "CHAOS_kreide",          8}),
       ({POOL_KOMPOS "CHAOS_kreide_schwarz",  4}),
       ({POOL_KOMPOS "CHAOS_kohle",           4}),
       ({POOL_KOMPOS "CHAOS_kerze_schwarz",   4}),
       ({POOL_KOMPOS "CHAOS_silberstaub",     2}),
       ({"/obj/fackel",                       6}),
       ({"/obj/seil",                         3}),
       ({"/obj/schaufel",                     2}),
       ({POOL_CONTAINER "beutel",             3}),
       ({POOL_MISC "eimer",                   2}),
       ({POOL_FOOD "apfel",                   6}),
       ({POOL_FOOD "steak",                   4}),
    }));
    o->SetProp(P_SHOP_KEEPER,CHAOS_ID_ACHTARCH);

    o->AddDetail(({"laden","werkstatt","ruine","grundmauern"}),
       "Die alte Werkstatt, notdürftig wieder überdacht.");

    o->AddDetail(({"planen","bretter","dach","luecken","lücken"}),
       "Planen und Bretter, schief festgenagelt. Durch die Lücken tropft "
       "es.");

    o->AddDetail(({"tresen","hobelbank"}),
       "Die alte Hobelbank dient als Tresen. Zwei Beine sind durch "
       "Kisten ersetzt.");

    o->AddDetail(({"kisten","beine"}),
       "Hält. Gerade so.");

    o->AddDetail(({"regale","regal","kreide","kerzen","fackeln","kram"}),
       "In den Regalen liegt, was Achtarch verkauft. Was genau, zeigt dir "
       "die Liste ('liste').");

    o->AddDetail(({"medaille"}),
       "Eine Medaille der Ladenbesitzer-Vereinigung für herausragende "
       "Leistungen. Achtarch putzt sie jeden Tag.");

    o->AddDetail(({"eimer"}),
       "Er ist halb voll.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Norden liegt der Burgplatz.");

    o->AddDetail(({"boden"}),
       "Gestampfte Erde, voller Sägespäne.");

    o->AddDetail(({"saegespaene","sägespäne","erde"}),
       "Reste aus der Zeit, als hier noch eine Werkstatt war.");

    o->AddDetail(({"wand","waende","wände","mauern"}),
       "Alte Grundmauern, mit Brettern ausgebessert.");

    o->AddSound(({DEFAULT_SOUND,"tropfen"}),
       "Tropf. Tropf.");

    o->AddDetail(({"achtarch","haendler","händler"}),
       "Achtarch steht meistens hinter seinem Tresen.");

    o->AddDetail(({"liste"}),
       "Mit 'liste' siehst du, was Achtarch verkauft.");

    o->AddDetail(({"vereinigung","ladenbesitzer","ladenbesitzer-vereinigung","leistungen","tag"}),
       "Er ist sehr stolz darauf.");

    o->AddDetail(({"decke"}),
       "Statt einer Decke gibt es Planen und Bretter.");

    o->AddDetail(({"fussboden","fußboden"}),
       "Gestampfte Erde.");

    o->AddDetail(({"muelleimer","mülleimer","zeit"}),
       "Was Achtarch nicht ankauft, wirft er weg.");

    o->AddItem(CHAOS_GILDEN_MON("achtarch"),REFRESH_DESTRUCT);

    o->AddExit("norden",     R("[+009+050+08]"));
    break;

    case "[+010+049+08]":
    o->SetProp(P_INT_SHORT,"In der Ruine der alten Kapelle");
    o->chaos_long(
       "Die alte Kapelle hat kein Dach mehr, über dir hängt der graue "
       "Dunst. Der Altar ist gespalten, die Bänke sind längst verheizt. "
       "Auf dem Boden prangt ein riesiges Pentagramm, mit Asche und Blut "
       "gezogen und von Brandflecken umgeben. Hier üben die Chaoten wohl "
       "das Beschwören, wenn es drinnen zu eng wird. Im Norden geht es "
       "zurück auf den Burgplatz.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf dem gespaltenen Altar brennt eine Kerze mit schwarzer Flamme.",
       "In der Mitte des Pentagramms liegt ein angekauter Schuh.",
    }));

    o->AddDetail(({"kapelle","ruine"}),
       "Eine alte Kapelle, entweiht und ohne Dach.");

    o->AddDetail(({"dunst"}),
       "Statt eines Daches hängt grauer Dunst über der Kapelle.");

    o->AddDetail(({"altar"}),
       "Ein steinerner Altar, mitten durch gespalten.");

    o->AddDetail(({"baenke","bänke"}),
       "Keine mehr da. Verheizt.");

    o->AddDetail(({"pentagramm","asche","blut","mitte"}),
       "Ein riesiges Pentagramm. Eine der Linien ist verwischt, und "
       "daneben ist der Boden besonders schwarz.");

    o->AddDetail(({"linien","linie"}),
       "Eine ist verwischt. Das war wohl der Fehler.");

    o->AddDetail(({"kerze","flamme"}),
       "Eine Kerze mit schwarzer Flamme, die kein Licht macht.");

    o->AddDetail(({"schuh"}),
       "Ein linker Schuh, angekaut. Der Besitzer vermisst ihn vermutlich.");

    o->AddDetail(({"besitzer"}),
       "Nicht hier.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Norden liegt der Burgplatz.");

    o->AddDetail(({"beschwoeren","beschwören"}),
       "Hier wird es geübt.");

    o->AddDetail(({"daches","dach"}),
       "Es gibt keins mehr.");

    o->AddDetail(({"fehler"}),
       "Daneben ist der Boden besonders schwarz.");

    o->AddExit("norden",     R("[+010+050+08]"));
    break;

    // ==== Turm =======================================================

    case "[+010+053+08]":
    o->SetProp(P_INT_SHORT,"Im Erdgeschoss des Turms");
    o->chaos_long(
       "Du stehst im Erdgeschoss des Turms. Die Mauern sind meterdick, "
       "trotzdem steht der Turm schief, und man spürt es beim Gehen. Eine "
       "Wendeltreppe windet sich an der Wand nach oben. Auf dem Boden "
       "liegen Kisten, aus denen Kerzenstummel, Kreide und getrocknete "
       "Kräuter quellen. Im Süden geht es zurück auf den Burgplatz.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Wendeltreppe dreht sich heute andersherum.",
       "Von oben schwebt eine einzelne violette Feder herab.",
    }));

    o->AddDetail(({"turm"}),
       "Der Turm steht frei auf dem Burgplatz. Er ist schief, aber er "
       "steht.");

    o->AddDetail(({"wendeltreppe","treppe"}),
       "Die Wendeltreppe windet sich an der Wand nach oben.");

    o->AddDetail(({"kisten","kiste"}),
       "Offene Kisten voller Beschwörungskram.");

    o->AddDetail(({"kerzenstummel","kreide","kraeuter","kräuter",
                   "beschwoerungskram","beschwörungskram"}),
       "Alles, was man für ein Ritual braucht, und noch einiges mehr.");

    o->AddDetail(({"feder"}),
       "Sie schwebt und schwebt und kommt nie unten an.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Süden liegt der Burgplatz.");

    o->AddDetail(({"erdgeschoss"}),
       "Du stehst darin.");

    o->AddDetail(({"gehen"}),
       "Man geht ein wenig schief.");

    o->AddDetail(({"ritual"}),
       "Für ein Ritual ist hier alles da.");

    o->AddExit("sueden",     R("[+010+052+08]"));
    o->AddExit("oben",       R("[+010+053+09]"));
    break;

    case "[+010+053+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Im ersten Stock des Turms");
    o->chaos_long(
       "Der erste Stock des Turms ist zu einer Hexenküche geworden. Auf "
       "einem langen Tisch stehen Kolben, Tiegel und Schalen, manche "
       "zerbrochen, manche mit Dingen gefüllt, die sich bewegen. Die Wände "
       "sind mit Ruß und Spritzern bedeckt. Die Wendeltreppe führt nach "
       "oben und nach unten.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "In einem der Kolben blubbert eine grüne Flüssigkeit und summt "
       "dabei.",
       "Auf dem Tisch liegt eine Notiz: »Nicht umrühren!!!« Daneben ein "
       "Löffel.",
    }));

    o->AddDetail(({"hexenkueche","hexenküche"}),
       "Hier wird gebraut, gekocht und gelegentlich gesprengt.");

    o->AddDetail(({"tisch"}),
       "Ein langer, fleckiger Tisch voller Brandflecken.");

    o->AddDetail(({"kolben","tiegel","schalen","dinge"}),
       "Glas und Ton, voller Reste. Manche Reste bewegen sich.");

    o->AddDetail(({"reste","fluessigkeit","flüssigkeit"}),
       "Lieber nicht anfassen.");

    o->AddDetail(({"russ","ruß","spritzer","spritzern"}),
       "Ruß und bunte Spritzer an allen Wänden, bis an die Decke.");

    o->AddDetail(({"notiz","loeffel","löffel"}),
       "»Nicht umrühren!!!« Der Löffel ist benutzt.");

    o->AddDetail(({"wendeltreppe","treppe"}),
       "Sie führt nach oben und nach unten.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Schwefel, Kräutern und angebranntem Etwas.");

    o->AddSmell(({"etwas","kraeuter","kräuter"}),
       "Undefinierbar.");

    o->AddDetail(({"stock","turms"}),
       "Der erste Stock des Turms.");

    o->AddDetail(({"ton"}),
       "Zerbrochene Schalen aus Ton.");

    o->AddExit("unten",      R("[+010+053+08]"));
    o->AddExit("oben",       R("[+010+053+10]"));
    break;

    case "[+010+053+10]":
    hoehe(o,20);
    o->SetProp(P_INT_SHORT,"Im zweiten Stock des Turms");
    o->chaos_long(
       "Der zweite Stock des Turms ist eine runde Stube. Durch schmale "
       "Schießscharten fällt fahles Licht. Ein Teil des Bodens ist "
       "durchgebrochen, jemand hat ein Brett darübergelegt und "
       "»Vorsicht« darauf gekritzelt. An den Wänden hängen Sternkarten, "
       "auf denen Sterne eingezeichnet sind, die es nicht gibt. Die "
       "Wendeltreppe führt hinauf zur Spitze und hinunter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Durch das Loch im Boden siehst du nicht den ersten Stock, sondern "
       "einen Sternenhimmel.",
       "Auf einer Sternkarte ist heute ein neuer Stern dazugekommen.",
    }));

    o->AddDetail(({"stube"}),
       "Eine runde, kahle Stube.");

    o->AddDetail(({"schiessscharten","schießscharten","scharten"}),
       "Schmale Schlitze in der dicken Mauer.");

    o->AddDetail(({"schlitze"}),
       "Schmal. Zu schmal für einen Dämon. Hoffentlich.");

    o->AddDetail(({"teil","loch","brett","vorsicht"}),
       "Ein Brett über einem Loch im Boden. »Vorsicht« steht darauf.");

    o->AddDetail(({"sternkarten","sternkarte","sterne","stern"}),
       "Sorgfältig gezeichnete Karten von Sternen, die es nicht gibt. "
       "Noch nicht.");

    o->AddDetail(({"sternenhimmel"}),
       "Sterne, wo keine sein sollten.");

    o->AddDetail(({"licht"}),
       "Fahles Licht fällt durch die Schießscharten.");

    o->AddDetail(({"wendeltreppe","treppe","spitze"}),
       "Die Wendeltreppe führt nach oben zur Spitze und nach unten.");

    o->AddDetail(({"karten"}),
       "Sternkarten.");

    o->AddDetail(({"stock","turms"}),
       "Der zweite Stock des Turms.");

    o->AddExit("unten",      R("[+010+053+09]"));
    o->AddExit("oben",       R("[+010+053+11]"));
    break;

    case "[+010+053+11]":
    hoehe(o,30);
    o->SetProp(P_CHAOS_RISS,1);
    o->SetProp(P_LIGHT,2);
    o->SetProp(P_LIGHT_TYPE,LT_MAGIC);
    o->SetProp(P_INT_SHORT,"Auf der Spitze des Turms");
    o->chaos_long(
       "Die Spitze des Turms hat kein Dach mehr. Über der Plattform "
       "klafft ein Riss, aus dem violettes Licht und Chaosmagie sickern. "
       "Er pulsiert, als würde er atmen. Hier ist einst ein Ritual "
       "schiefgegangen, und die Chaoten kommen gern her, weil Beschwörungen "
       "am Riss leichter gelingen. Die Plattform ist voller Kreidezeichen "
       "und Brandflecken. Du kannst in den Riss hineingehen, nach unten "
       "führt die Wendeltreppe.");

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

    o->AddDetail(({"plattform","kreidezeichen","zeichen"}),
       "Pentagramme über Pentagrammen, Bannkreise über Bannkreisen. "
       "Manche frisch, manche uralt.");

    o->AddDetail(({"pentagramme","bannkreise","bannkreis"}),
       "Die ältesten sind kaum noch zu erkennen. Wer sie gezeichnet hat, "
       "hat dabei etwas falsch gemacht.");

    o->AddDetail(({"ritual"}),
       "Niemand weiß, wer das Ritual gewirkt hat. Seitdem ist der Riss "
       "offen.");

    o->AddDetail(({"beschwoerungen","beschwörungen"}),
       "Am Riss gelingen sie leichter.");

    o->AddDetail(({"dach"}),
       "Vom Dach ist nichts mehr übrig.");

    o->AddDetail(({"dinge","sinn"}),
       "Du schaust lieber nicht zu lange hinein.");

    o->AddDetail(({"klaue","funken"}),
       "Da war etwas. Oder auch nicht.");

    o->AddDetail(({"turm","spitze","wendeltreppe","treppe"}),
       "Du stehst ganz oben auf dem Turm. Die Wendeltreppe führt "
       "hinunter.");

    o->AddSound(({DEFAULT_SOUND,"riss","fluestern","flüstern"}),
       "Fern und vielstimmig, kaum zu verstehen.");

    o->AddExit("unten",      R("[+010+053+10]"));
    o->AddExit("hinein",     R("[+010+053+12]"));
    break;

    case "[+010+053+12]":
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
       "landest du wieder auf der Spitze des Turms.");

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
       "sauber, mit Fahnen auf den Türmen. Kaum wiederzuerkennen.");

    o->AddDetail(({"fahnen","tuerme","türme"}),
       "Längst vergangen. Nur hier im Riss ist es noch zu sehen.");

    o->AddDetail(({"magier","robe","pentagramm","fehler","linie","welt"}),
       "Der Magier zeichnet das Pentagramm, setzt eine Linie falsch, und "
       "die Welt reißt auf. Immer und immer wieder.");

    o->AddDetail(({"stimmen","bedeutung","richtungen","wort"}),
       "Die Stimmen flüstern, aber du verstehst kein Wort.");

    o->AddDetail(({"sonnenschein"}),
       "Ein Sonnenschein, den es im Schattental nicht mehr gibt.");

    o->AddDetail(({"spitze","turm"}),
       "Wenn du hinausgehst, bist du wieder auf der Spitze des Turms.");

    o->AddSound(({DEFAULT_SOUND,"stimmen"}),
       "Hunderte flüstern durcheinander.");

    o->AddExit("hinaus",     R("[+010+053+11]"));
    break;

    // ==== Hauptgebäude, Erdgeschoss ==================================

    case "[+011+051+08]":
    o->SetProp(P_INT_SHORT,"In der Eingangshalle des Hauptgebäudes");
    o->chaos_long(
       "Die Eingangshalle ist hoch und zugig. An den Wänden hängen "
       "angekokelte Wandteppiche, an einem Hirschgeweih neben der Tür "
       "hängen Roben, Hüte und ein Kettenhemd voller Löcher. Auf dem "
       "Boden liegt ein Fußabtreter mit der Aufschrift »Schuhe abtreten«, "
       "der selbst voller Schlamm ist. Im Westen geht es hinaus auf den "
       "Burgplatz, im Osten beginnt der Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Das Hirschgeweih hat heute ein Ende mehr als gestern.",
       "Einer der Hüte am Geweih dreht sich langsam um sich selbst.",
    }));

    o->AddDetail(({"eingangshalle","halle"}),
       "Hoch, zugig und unordentlich.");

    o->AddDetail(({"wandteppiche","wandteppich","teppiche"}),
       "Angekokelt und voller Löcher.");

    o->AddDetail(({"loecher","löcher"}),
       "Überall Löcher.");

    o->AddDetail(({"hirschgeweih","geweih","ende"}),
       "Ein altes Hirschgeweih, als Garderobe benutzt.");

    o->AddDetail(({"roben","huete","hüte","kettenhemd"}),
       "Alles achtlos aufgehängt. Das Kettenhemd hat mehr Löcher als "
       "Ringe.");

    o->AddDetail(({"ringe","garderobe"}),
       "Viel hält sie nicht mehr.");

    o->AddDetail(({"tuer","tür","portal"}),
       "Das Portal im Westen steht offen.");

    o->AddDetail(({"fussabtreter","fußabtreter","aufschrift","schlamm",
                   "schuhe"}),
       "»Schuhe abtreten«. Der Fußabtreter selbst bräuchte das am "
       "nötigsten.");

    o->AddDetail(({"burgplatz","platz"}),
       "Im Westen liegt der Burgplatz.");

    o->AddDetail(({"mittelgang","gang"}),
       "Im Osten beginnt der Mittelgang.");

    o->AddDetail(({"chaoslehrling","lehrling","lehrlinge"}),
       "Lehrlinge laufen hier ständig herum.");

    o->AddItem(CHAOS_GILDEN_MON("lehrling"),REFRESH_DESTRUCT);

    o->AddExit("westen",     R("[+010+051+08]"));
    o->AddExit("osten",      R("[+012+051+08]"));
    break;

    case "[+012+051+08]":
    mittelgang(o);
    o->SetProp(P_INT_SHORT,"Im Mittelgang, westlicher Teil");
    o->chaos_long(
       "Du stehst im westlichen Teil des Mittelgangs. Von hier geht es im "
       "Norden in die Küche, aus der es nach Angebranntem riecht, und im "
       "Süden in die Vorratskammer. An den Wänden hängen angekokelte "
       "Wandteppiche. Im Westen liegt die Eingangshalle, im Osten führt "
       "der Gang weiter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus der Küche rollt ein Kohlkopf und bleibt vor deinen Füßen "
       "liegen.",
       "Auf dem Boden ist eine Spur aus Mehl, die in die Vorratskammer "
       "führt. Die Abdrücke darin haben drei Zehen.",
    }));

    o->AddDetail(({"kueche","küche"}),
       "Im Norden liegt die Küche.");

    o->AddDetail(({"vorratskammer"}),
       "Im Süden liegt die Vorratskammer.");

    o->AddDetail(({"kohlkopf","fuessen","füßen"}),
       "Ein Kohlkopf. Ein angebissener.");

    o->AddDetail(({"spur","mehl","abdruecke","abdrücke","zehen"}),
       "Kleine Abdrücke mit drei Zehen.");

    o->AddSmell(({DEFAULT_SMELL,"angebranntem"}),
       "Aus der Küche riecht es nach Angebranntem.");

    o->AddDetail(({"angebranntem","angebranntes"}),
       "Aus der Küche.");

    o->AddSmell(({"kueche","küche","angebranntem"}),
       "Angebrannt.");

    o->AddExit("westen",     R("[+011+051+08]"));
    o->AddExit("osten",      R("[+013+051+08]"));
    o->AddExit("norden",     R("[+012+052+08]"));
    o->AddExit("sueden",     R("[+012+050+08]"));
    break;

    case "[+013+051+08]":
    mittelgang(o);
    o->SetProp(P_INT_SHORT,"Im Mittelgang, mittlerer Teil");
    o->chaos_long(
       "Du stehst in der Mitte des Mittelgangs. Im Norden liegt die "
       "Bibliothek, deren Tür mit einer Kette gesichert ist, die aber "
       "trotzdem offen steht. Im Süden liegt die Schreibstube, aus der "
       "ein Stapel Papier bis in den Gang quillt. Der Gang führt nach "
       "Westen und Osten weiter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Ein Buch flattert aus der Bibliothek, dreht eine Runde und fliegt "
       "zurück.",
       "Aus der Schreibstube ist ein genervtes Seufzen zu hören.",
    }));

    o->AddDetail(({"bibliothek","tuer","tür","kette"}),
       "Im Norden liegt die Bibliothek. Die Kette an der Tür ist zwar "
       "da, verschließt aber nichts.");

    o->AddDetail(({"schreibstube"}),
       "Im Süden liegt die Schreibstube.");

    o->AddDetail(({"stapel","papier"}),
       "Anträge, Listen und Beschwerden.");

    o->AddDetail(({"antraege","anträge","listen","beschwerden"}),
       "Lauter Papierkram der Gilde.");

    o->AddDetail(({"buch","runde"}),
       "Es fliegt wie eine verwirrte Fledermaus.");

    o->AddDetail(({"fledermaus"}),
       "Eine verwirrte.");

    o->AddDetail(({"gilde","papierkram"}),
       "Der Papierkram der Gilde.");

    o->AddDetail(({"mitte"}),
       "Du stehst in der Mitte des Gangs.");

    o->AddExit("westen",     R("[+012+051+08]"));
    o->AddExit("osten",      R("[+014+051+08]"));
    o->AddExit("norden",     R("[+013+052+08]"));
    o->AddExit("sueden",     R("[+013+050+08]"));
    break;

    case "[+014+051+08]":
    mittelgang(o);
    o->SetProp(P_INT_SHORT,"Im Mittelgang, östlicher Teil");
    o->chaos_long(
       "Du stehst im östlichen Teil des Mittelgangs. Im Norden führt eine "
       "breite Treppe nach oben, im Süden liegt die Wachstube. Im Osten "
       "öffnet sich der Gang zum Rittersaal, aus dem Stimmen und "
       "gelegentlich ein Knall dringen.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf der Treppe sitzt ein Chaot und zählt seine Finger. Er kommt "
       "auf elf.",
       "Aus dem Rittersaal schwebt eine Rauchwolke in Form eines "
       "Totenkopfs.",
    }));

    o->AddDetail(({"treppe"}),
       "Im Norden führt eine breite Treppe nach oben.");

    o->AddDetail(({"wachstube"}),
       "Im Süden liegt die Wachstube.");

    o->AddDetail(({"stimmen","knall"}),
       "Aus dem Rittersaal. Dort ist meistens etwas los.");

    o->AddDetail(({"chaot","finger"}),
       "Er zählt nochmal. Zwölf.");

    o->AddDetail(({"rauchwolke","totenkopf"}),
       "Sie verweht, bevor du genauer hinsehen kannst.");

    o->AddSound(({DEFAULT_SOUND,"stimmen","knall"}),
       "Stimmen aus dem Osten, ab und zu ein Knall.");

    o->AddSound(({"osten","knall"}),
       "Stimmen und ab und zu ein Knall.");

    o->AddExit("westen",     R("[+013+051+08]"));
    o->AddExit("osten",      CHAOS_RITTERSAAL);
    o->AddExit("norden",     R("[+014+052+08]"));
    o->AddExit("sueden",     R("[+014+050+08]"));
    break;

    case "[+012+052+08]":
    o->SetProp(P_INT_SHORT,"In der Küche der Burg Zwielichtstein");
    o->chaos_long(
       "Die Küche ist groß, verrußt und ein einziges Durcheinander. "
       "Schmutziges Geschirr stapelt sich zu schiefen Türmen, in einem "
       "riesigen Herd blubbert ein Kessel mit etwas Undefinierbarem, und "
       "auf dem Tisch liegen Messer, Zwiebeln und ein Kochbuch mit dem "
       "Titel »Kochen mit Schwefel«. Im Süden geht es zurück in den "
       "Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Einer der Geschirrtürme schwankt bedenklich, fällt aber nicht.",
       "Aus dem Kessel greift ein Tentakel nach einer Zwiebel.",
    }));

    o->AddDetail(({"kueche","küche","durcheinander"}),
       "Eine große, verrußte und völlig unordentliche Küche.");

    o->AddDetail(({"geschirr","tuerme","türme","geschirrtuerme",
                   "geschirrtürme"}),
       "Teller, Schüsseln und Becher, schmutzig und hoch gestapelt.");

    o->AddDetail(({"teller","schuesseln","schüsseln","becher"}),
       "Ungespült. Seit Wochen.");

    o->AddDetail(({"herd","kessel"}),
       "Ein riesiger, gemauerter Herd. Im Kessel blubbert etwas. Besser "
       "nicht hineinschauen.");

    o->AddDetail(({"undefinierbarem","tentakel"}),
       "Was immer das ist, es lebt noch.");

    o->AddDetail(({"tisch","messer","zwiebeln","zwiebel"}),
       "Ein langer, zerkratzter Tisch voller Küchenkram.");

    o->AddDetail(({"kochbuch","titel"}),
       "»Kochen mit Schwefel«. Erklärt einiges.");

    o->AddDetail(({"kuechenkram","küchenkram"}),
       "Alles durcheinander.");

    o->AddDetail(({"mittelgang","gang"}),
       "Im Süden liegt der Mittelgang.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Angebranntem, Zwiebeln und Schwefel.");

    o->AddSmell(({"angebranntem"}),
       "Stark.");

    o->AddSound(({"kessel"}),
       "Blubb.");

    o->AddDetail(({"kochen","wochen"}),
       "Seit Wochen.");

    o->AddSmell(({"zwiebeln","zwiebel"}),
       "Scharf.");

    o->AddDetail(({"koch","schmorbold"}),
       "Schmorbold, der Koch, steht meistens am Kessel.");

    o->AddItem(CHAOS_GILDEN_MON("koch"),REFRESH_DESTRUCT);

    o->AddExit("sueden",     R("[+012+051+08]"));
    break;

    case "[+012+050+08]":
    o->SetProp(P_INT_SHORT,"In der Vorratskammer");
    o->chaos_long(
       "Die Vorratskammer ist ein schmaler Raum mit Regalen bis unter die "
       "Decke. Die meisten Regale sind leer gefressen, aufgerissene "
       "Säcke liegen herum, und auf dem Boden verteilt sich Mehl. Ganz "
       "oben steht ein Topf mit der Aufschrift »NICHT ESSEN. Gez. "
       "Hutschat.« Im Norden geht es zurück in den Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "In einem der Säcke raschelt es, als wäre er voller Mäuse. Er ist "
       "leer.",
       "Der Topf ganz oben ist heute leer. Jemand hat doch gegessen.",
    }));

    o->AddDetail(({"vorratskammer"}),
       "Ein schmaler, geplünderter Raum.");

    o->AddDetail(({"regale","regal"}),
       "Leer gefressen.");

    o->AddDetail(({"saecke","säcke","sack","maeuse","mäuse","mehl"}),
       "Aufgerissene Säcke. Das Mehl ist überall.");

    o->AddDetail(({"topf","aufschrift"}),
       "»NICHT ESSEN. Gez. Hutschat.« Der Deckel ist verbeult.");

    o->AddDetail(({"deckel"}),
       "Verbeult, als hätte jemand mit Gewalt versucht, ihn zu öffnen.");

    o->AddDetail(({"gewalt"}),
       "Hat nicht geklappt. Oder doch.");

    o->AddDetail(({"mittelgang","gang"}),
       "Im Norden liegt der Mittelgang.");

    o->AddSound(({"saecke","säcke","rascheln"}),
       "Rascheln, wo nichts ist.");

    o->AddDetail(({"essen"}),
       "Lieber nicht.");

    o->AddExit("norden",     R("[+012+051+08]"));
    break;

    case "[+013+052+08]":
    o->SetProp(P_INT_SHORT,"In der Bibliothek der Burg Zwielichtstein");
    o->chaos_long(
       "Die Bibliothek ist ein langer, staubiger Raum. An den Wänden "
       "stehen Regale voller alter Schriften, manche angesengt, manche "
       "seltsam flimmernd. Einige Bücher sind mit Messern an die Regale "
       "genagelt, damit sie nicht wegfliegen. Auf einem Lesepult liegt "
       "ein Verzeichnis. Im Süden geht es zurück in den Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Ein Buch zerrt an dem Messer, das es festhält.",
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

    o->AddDetail(({"messer","messern"}),
       "Küchenmesser, Dolche, eine Gabel. Hauptsache, es hält.");

    o->AddDetail(({"kuechenmesser","küchenmesser","dolche","gabel"}),
       "Durch die Buchdeckel gerammt.");

    o->AddDetail(({"buchdeckel"}),
       "Durchbohrt.");

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

    o->AddDetail(({"mittelgang","gang"}),
       "Im Süden liegt der Mittelgang.");

    o->AddSmell(({DEFAULT_SMELL,"papier"}),
       "Es riecht nach Staub, alt und muffig.");

    o->AddExit("sueden",     R("[+013+051+08]"));
    break;

    case "[+013+050+08]":
    o->SetProp(P_INT_SHORT,"In der Schreibstube");
    o->chaos_long(
       "In der Schreibstube wird der Papierkram der Gilde erledigt, "
       "jedenfalls theoretisch. Auf einem Schreibpult türmen sich "
       "Anträge, Listen und Beschwerden, ein Tintenfass ist umgekippt und "
       "hat einen schwarzen See auf dem Boden hinterlassen. An der Wand "
       "hängt eine Liste mit der Überschrift »Wer hat welchen Dämon "
       "verloren«. Sie ist sehr lang. Im Norden geht es zurück in den "
       "Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Eine Feder kritzelt von selbst etwas auf ein Blatt und streicht "
       "es wieder durch.",
       "Unter dem Stapel Anträge ragt ein Schwanz hervor.",
    }));

    o->AddDetail(({"schreibstube"}),
       "Ein kleiner Raum voller Papier.");

    o->AddDetail(({"papierkram","antraege","anträge","listen",
                   "beschwerden","stapel"}),
       "Ungeordnet und hoch gestapelt.");

    o->AddDetail(({"schreibpult","pult"}),
       "Ein Schreibpult, unter dem Papier kaum zu sehen.");

    o->AddDetail(({"papier"}),
       "Überall.");

    o->AddDetail(({"tintenfass","see"}),
       "Die Tinte ist längst eingetrocknet.");

    o->AddDetail(({"tinte"}),
       "Schwarz und eingetrocknet.");

    o->AddDetail(({"liste","ueberschrift","überschrift"}),
       "»Wer hat welchen Dämon verloren«. Die Liste reicht bis auf den "
       "Boden.");

    o->AddDetail(({"feder","blatt"}),
       "Sie schreibt und streicht durch.");

    o->AddDetail(({"schwanz"}),
       "Ein schuppiger Schwanz. Er zuckt.");

    o->AddDetail(({"mittelgang","gang"}),
       "Im Norden liegt der Mittelgang.");

    o->AddDetail(({"gilde"}),
       "Die Gilde des Chaos. Viel Papier.");

    o->AddDetail(({"wer"}),
       "Lies die Liste.");

    o->AddDetail(({"schreiber","kritzel"}),
       "Kritzel, der Schreiber, sitzt meistens am Pult.");

    o->AddItem(CHAOS_GILDEN_MON("schreiber"),REFRESH_DESTRUCT);

    o->AddExit("norden",     R("[+013+051+08]"));
    break;

    case "[+014+052+08]":
    o->SetProp(P_INT_SHORT,"Im Treppenhaus");
    o->chaos_long(
       "Im Treppenhaus führt eine breite Treppe nach oben. Das Geländer "
       "fehlt zur Hälfte, die andere Hälfte ist angesengt. Auf den Stufen "
       "liegen Kleidungsstücke, als hätte sich jemand beim Hinaufgehen "
       "ausgezogen. Im Süden geht es zurück in den Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Ein Stiefel hüpft die Treppe hinauf, ganz allein.",
       "Auf einer Stufe sitzt eine Katze mit sechs Beinen.",
    }));

    o->AddDetail(({"treppenhaus","treppe","stufen","stufe"}),
       "Eine breite, abgetretene Treppe.");

    o->AddDetail(({"gelaender","geländer","haelfte","hälfte"}),
       "Die eine Hälfte fehlt, die andere ist angesengt.");

    o->AddDetail(({"kleidungsstuecke","kleidungsstücke","stiefel"}),
       "Ein Stiefel, ein Gürtel, ein Hut.");

    o->AddDetail(({"guertel","gürtel","hut"}),
       "Der Besitzer ist wohl oben.");

    o->AddDetail(({"katze","beine"}),
       "Sie schaut dich an, mit allen drei Augen.");

    o->AddDetail(({"augen"}),
       "Drei.");

    o->AddDetail(({"mittelgang","gang"}),
       "Im Süden liegt der Mittelgang.");

    o->AddDetail(({"besitzer"}),
       "Oben vermutlich.");

    o->AddDetail(({"hinaufgehen"}),
       "Unterwegs ausgezogen.");

    o->AddExit("sueden",     R("[+014+051+08]"));
    o->AddExit("oben",       R("[+014+052+09]"));
    break;

    case "[+014+050+08]":
    o->SetProp(P_INT_SHORT,"In der Wachstube");
    o->chaos_long(
       "Die Wachstube ist eng und verrußt. Eine Wache gibt es hier "
       "nicht, nur einen Strohsack, auf dem offenbar jemand regelmäßig "
       "schläft, und eine Glocke mit einem Zettel: »Bei Gefahr läuten. "
       "Bei großer Gefahr weglaufen.« An der Wand lehnen ein paar "
       "rostige Hellebarden. Im Norden geht es zurück in den Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf dem Strohsack liegt ein Chaot und schnarcht.",
       "Die Glocke läutet einmal von selbst. Niemand reagiert.",
    }));

    o->AddDetail(({"wachstube"}),
       "Klein, eng und verrußt.");

    o->AddDetail(({"wache"}),
       "Keine Wache weit und breit.");

    o->AddDetail(({"strohsack"}),
       "Platt gelegen und voller Krümel.");

    o->AddDetail(({"kruemel","krümel"}),
       "Reste vom Kerkerbrot.");

    o->AddDetail(({"glocke","zettel","gefahr"}),
       "»Bei Gefahr läuten. Bei großer Gefahr weglaufen.«");

    o->AddDetail(({"hellebarden","hellebarde"}),
       "Rostig und stumpf.");

    o->AddDetail(({"chaot"}),
       "Er schnarcht.");

    o->AddDetail(({"mittelgang","gang"}),
       "Im Norden liegt der Mittelgang.");

    o->AddSound(({"glocke"}),
       "Bong.");

    o->AddDetail(({"kerkerbrot"}),
       "Hart wie Stein.");

    o->AddExit("norden",     R("[+014+051+08]"));
    break;

    case "[+015+051+08]":
    o->SetProp(P_INT_SHORT,"Im Rittersaal der Burg Zwielichtstein");
    o->chaos_long(
       "Der Rittersaal ist groß und düster. Die lange Tafel in der Mitte "
       "ist voller Brandflecken, Becher und Kreidezeichnungen. Hier "
       "versammeln sich die Chaoten, und man sieht es: Stühle liegen "
       "umgekippt, an der Decke klebt etwas Grünes. Hoch oben zieht sich "
       "eine Galerie an der Wand entlang. Im Norden liegt die "
       "Chaoskapelle, im Süden führt eine Treppe in den Keller. Im Osten "
       "liegt die Gildenhalle, im Westen der Mittelgang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Tafel ist heute gedeckt, mit Tellern voller violetter Asche.",
       "An der Wand hängt eine Rüstung, die dir mit dem Visier zunickt.",
       "Das Grüne an der Decke ist ein Stück weitergewandert.",
    }));

    o->AddDetail(({"rittersaal","saal"}),
       "Ein großer, düsterer Saal.");

    o->AddDetail(({"tafel","kreidezeichnungen"}),
       "Eine lange, schwere Tafel aus schwarzem Holz, übersät mit "
       "Brandflecken und Kreidezeichnungen.");

    o->AddDetail(({"becher"}),
       "Leer und klebrig.");

    o->AddDetail(({"holz"}),
       "Schwarzes, hartes Holz.");

    o->AddDetail(({"stuehle","stühle"}),
       "Umgekippt. Einer hängt an der Wand.");

    o->AddDetail(({"gruenes","grünes"}),
       "Es klebt an der Decke und wandert langsam.");

    o->AddDetail(({"galerie"}),
       "Hoch oben zieht sich eine Galerie an der Wand entlang. Man "
       "erreicht sie über die Treppe im Mittelgang.");

    o->AddDetail(({"chaoskapelle","kapelle"}),
       "Im Norden liegt die Chaoskapelle.");

    o->AddDetail(({"treppe","keller"}),
       "Im Süden führt eine Treppe in den Keller.");

    o->AddDetail(({"gildenhalle"}),
       "Im Osten liegt die Gildenhalle.");

    o->AddDetail(({"mittelgang","gang"}),
       "Im Westen liegt der Mittelgang.");

    o->AddDetail(({"teller","asche"}),
       "Violette Asche auf alten Zinntellern.");

    o->AddDetail(({"zinntellern","zinnteller"}),
       "Verbeult.");

    o->AddDetail(({"ruestung","rüstung","visier"}),
       "Eine leere Rüstung. Meistens.");

    o->AddDetail(({"mitte"}),
       "In der Mitte steht die Tafel.");

    o->AddDetail(({"chaoslehrling","lehrling","lehrlinge"}),
       "Lehrlinge laufen hier ständig herum.");

    o->AddItem(CHAOS_GILDEN_MON("lehrling"),REFRESH_DESTRUCT);

    o->AddExit("westen",     R("[+014+051+08]"));
    o->AddExit("osten",      CHAOS_GILDENROOM);
    o->AddExit("norden",     R("[+015+052+08]"));
    o->AddExit("sueden",     R("[+015+050+08]"));
    break;

    case "[+015+052+08]":
    o->SetProp(P_LIGHT_TYPE,LT_MAGIC);
    o->SetProp(P_INT_SHORT,"In der Chaoskapelle");
    o->chaos_long(
       "Die Chaoskapelle ist ein kleiner, dunkler Raum. Statt eines "
       "Altars steht hier ein Haufen aus Gerümpel, Knochen und Kerzen, "
       "auf dessen Spitze ein gesprungener Spiegel thront. Auf dem Boden "
       "ist ein Pentagramm eingebrannt, das schwach violett glimmt. An "
       "den Wänden hängen Zettel mit Bitten, Flüchen und Wünschen. Im "
       "Süden geht es zurück in den Rittersaal.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Im gesprungenen Spiegel siehst du dein Gesicht, aber falsch "
       "zusammengesetzt.",
       "Die Kerzen brennen heute rückwärts. Sie werden länger.",
       "Das Pentagramm glimmt heftiger, als hätte gerade jemand gebetet.",
    }));

    o->AddDetail(({"chaoskapelle","kapelle"}),
       "Hier huldigen die Chaoten dem Chaos, auf ihre Art.");

    o->AddDetail(({"altar","haufen"}),
       "Ein Haufen aus Gerümpel, Knochen und Kerzen. Er ist gleichzeitig "
       "Altar, Ablage und Müllhaufen.");

    o->AddDetail(({"geruempel","gerümpel","knochen","ablage",
                   "muellhaufen","müllhaufen"}),
       "Zerbrochene Becher, abgenagte Knochen, ein einzelner Stiefel.");

    o->AddDetail(({"stiefel","becher"}),
       "Irgendwer opfert hier wirklich alles.");

    o->AddDetail(({"kerzen"}),
       "Schwarze, rote und violette Kerzen, alle tropfen.");

    o->AddDetail(({"spiegel","spitze","gesicht"}),
       "Ein gesprungener Spiegel. Was er zeigt, ist nie ganz richtig.");

    o->AddDetail(({"pentagramm"}),
       "Ins Holz eingebrannt. Es glimmt schwach violett.");

    o->AddDetail(({"holz"}),
       "Verkohlt.");

    o->AddDetail(({"zettel","bitten","fluechen","flüchen","wuenschen",
                   "wünschen"}),
       "»Lass mich den Feuerdämon diesmal behalten.« »Möge Kruuolq "
       "über seinen eigenen Bart stolpern.« »Mehr Riss-Schnaps.«");

    o->AddDetail(({"bart","feuerdaemon","feuerdämon"}),
       "Lauter fromme Wünsche.");

    o->AddDetail(({"rittersaal"}),
       "Im Süden liegt der Rittersaal.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Wachs, Schwefel und altem Staub.");

    o->AddSmell(({"wachs"}),
       "Schwer und süßlich.");

    o->AddDetail(({"art"}),
       "Auf ihre ganz eigene Art.");

    o->AddDetail(({"kruuolq","meister"}),
       "Der oberste Meister des Chaos. Er hat einen Bart.");

    o->AddDetail(({"schnaps","wuensche","wünsche"}),
       "Fromme Wünsche.");

    o->AddExit("sueden",     CHAOS_RITTERSAAL);
    break;

    case "[+015+050+08]":
    o->SetProp(P_INT_SHORT,"Am Kopf der Kellertreppe");
    o->chaos_long(
       "Hier führt eine steile, ausgetretene Treppe in den Keller hinunter. "
       "Aus der Tiefe steigt kalte, modrige Luft herauf. Jemand hat ein "
       "Seil als Geländer gespannt, das schon reichlich dünn aussieht. Im "
       "Norden geht es zurück in den Rittersaal.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Von unten hörst du ein Kettenrasseln.",
       "Die Treppe hat heute eine Stufe mehr als gestern.",
    }));

    o->AddDetail(({"treppe","kellertreppe","stufe","stufen"}),
       "Steil und ausgetreten. Pass auf, wo du hintrittst.");

    o->AddDetail(({"keller","tiefe"}),
       "Unten liegt der Keller.");

    o->AddDetail(({"seil","gelaender","geländer"}),
       "Ein ausgefranstes Seil. Lieber nicht zu fest daran ziehen.");

    o->AddDetail(({"kettenrasseln"}),
       "Aus dem Keller.");

    o->AddDetail(({"rittersaal"}),
       "Im Norden liegt der Rittersaal.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Kalt und modrig.");

    o->AddExit("norden",     CHAOS_RITTERSAAL);
    o->AddExit("unten",      R("[+015+050+07]"));
    break;

    // ==== Hauptgebäude, Obergeschoss =================================

    case "[+011+051+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Auf dem Söller");
    o->chaos_long(
       "Der Söller ist ein offener Erker über der Eingangshalle. Von hier "
       "überblickst du den ganzen Burgplatz mit seinen Feuerstellen, die "
       "Ruinen ringsum und den schiefen Turm. Auf der Brüstung stehen "
       "leere Becher, und in einer Ecke liegt ein Haufen Steine, wohl zum "
       "Werfen. Im Osten führt der obere Gang ins Haus.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Unten auf dem Platz streiten sich zwei Chaoten. Einer zeigt nach "
       "oben, als hätte er dich gesehen.",
       "Ein Stein aus dem Haufen fehlt. Unten auf dem Platz flucht "
       "jemand.",
    }));

    o->AddDetail(({"soeller","söller","erker"}),
       "Ein offener Erker mit niedriger Brüstung.");

    o->AddDetail(({"bruestung","brüstung","becher"}),
       "Auf der Brüstung stehen leere Becher in einer Reihe.");

    o->AddDetail(({"burgplatz","platz","feuerstellen","ruinen"}),
       "Unter dir liegt der Burgplatz, umgeben von Ruinen.");

    o->AddDetail(({"turm"}),
       "Der schiefe Turm im Nordosten. An seiner Spitze flackert "
       "violettes Licht.");

    o->AddDetail(({"licht"}),
       "Violett und flackernd.");

    o->AddDetail(({"eingangshalle"}),
       "Die Eingangshalle liegt unter dir.");

    o->AddDetail(({"steine","haufen","ecke"}),
       "Ein Haufen faustgroßer Steine. Wofür, ist klar.");

    o->AddDetail(({"chaoten"}),
       "Sie streiten über irgendetwas.");

    o->AddDetail(({"gang","haus"}),
       "Im Osten beginnt der obere Gang.");

    o->AddDetail(({"reihe"}),
       "Sauber aufgereiht.");

    o->AddDetail(({"spitze"}),
       "An der Spitze des Turms flackert Licht.");

    o->AddDetail(({"werfen"}),
       "Am liebsten auf den Platz hinunter.");

    o->AddExit("osten",      R("[+012+051+09]"));
    break;

    case "[+012+051+09]":
    obergang(o);
    o->SetProp(P_INT_SHORT,"Im oberen Gang, westlicher Teil");
    o->chaos_long(
       "Du stehst im westlichen Teil des oberen Gangs. Die Dielen "
       "knarren bei jedem Schritt. Im Norden liegt ein Gästezimmer, im "
       "Süden ist die Wand eingestürzt und gibt den Blick auf einen "
       "Schutthaufen frei. Im Westen liegt der Söller, im Osten führt der "
       "Gang weiter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Eine Diele knarrt, obwohl niemand darauf tritt.",
       "Auf dem Schutthaufen im Süden sitzt ein Dämon und schmollt.",
    }));

    o->AddDetail(({"gaestezimmer","gästezimmer"}),
       "Im Norden liegt ein Gästezimmer.");

    o->AddDetail(({"wand","schutthaufen","schutt","blick"}),
       "Im Süden ist die Wand eingestürzt. Dahinter liegt nur Schutt.");

    o->AddDetail(({"schritt"}),
       "Knarz.");

    o->AddDetail(({"daemon","dämon"}),
       "Ein kleiner, grauer Dämon, der beleidigt aussieht.");

    versperrt(o,file,"sueden",
       "Im Süden ist die Wand eingestürzt. Dahinter ist nur ein großer "
       "Schutthaufen.");
    o->AddExit("westen",     R("[+011+051+09]"));
    o->AddExit("osten",      R("[+013+051+09]"));
    o->AddExit("norden",     R("[+012+052+09]"));
    break;

    case "[+013+051+09]":
    obergang(o);
    o->SetProp(P_INT_SHORT,"Im oberen Gang, mittlerer Teil");
    o->chaos_long(
       "Du stehst in der Mitte des oberen Gangs. Im Norden liegt das "
       "Gemach des obersten Meisters, die Tür ist mit Runen und einem "
       "Zettel »Nicht stören!« beklebt. Im Süden liegt das alte Gemach der "
       "Herrin. Der Gang führt nach Westen und Osten weiter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus dem Gemach des Meisters dringt lautes Schnarchen.",
       "Unter der Tür des Meisters quillt violetter Rauch hervor.",
    }));

    o->AddDetail(({"gemach","meister","runen","zettel"}),
       "Im Norden das Gemach des obersten Meisters. Auf dem Zettel steht "
       "»Nicht stören!«, darunter in anderer Schrift: »Doch, bitte.«");

    o->AddDetail(({"schrift"}),
       "Krakelig.");

    o->AddDetail(({"herrin"}),
       "Im Süden liegt das Gemach der Herrin.");

    o->AddDetail(({"rauch"}),
       "Violett. Riecht nach Schwefel.");

    o->AddSound(({"schnarchen"}),
       "Laut und regelmäßig.");

    o->AddExit("westen",     R("[+012+051+09]"));
    o->AddExit("osten",      R("[+014+051+09]"));
    o->AddExit("norden",     R("[+013+052+09]"));
    o->AddExit("sueden",     R("[+013+050+09]"));
    break;

    case "[+014+051+09]":
    obergang(o);
    o->SetProp(P_INT_SHORT,"Im oberen Gang, östlicher Teil");
    o->chaos_long(
       "Du stehst im östlichen Teil des oberen Gangs. Im Norden führt die "
       "Treppe hinunter, im Süden liegt die Kammer der Zofe. Im Osten "
       "öffnet sich der Gang zur Galerie über dem Rittersaal.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus der Kammer der Zofe weht ein Duft nach frischer Wäsche. "
       "Ungewöhnlich.",
       "Auf dem Boden liegt ein Hut, der vorhin noch auf der Treppe lag.",
    }));

    o->AddDetail(({"treppe"}),
       "Im Norden führt die Treppe hinunter.");

    o->AddDetail(({"kammer","zofe"}),
       "Im Süden liegt die Kammer der Zofe.");

    o->AddDetail(({"rittersaal"}),
       "Unter der Galerie liegt der Rittersaal.");

    o->AddDetail(({"hut"}),
       "Ein spitzer, schwarzer Hut.");

    o->AddDetail(({"duft","waesche","wäsche"}),
       "Frisch. Hier. Erstaunlich.");

    o->AddExit("westen",     R("[+013+051+09]"));
    o->AddExit("osten",      R("[+015+051+09]"));
    o->AddExit("norden",     R("[+014+052+09]"));
    o->AddExit("sueden",     R("[+014+050+09]"));
    break;

    case "[+014+052+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Am oberen Ende der Treppe");
    o->chaos_long(
       "Du stehst am oberen Ende der breiten Treppe. An der Wand hängt "
       "ein großes Bild, auf dem einmal ein Burgherr zu sehen war. Jemand "
       "hat ihm einen Schnurrbart, Hörner und einen dritten Arm gemalt. "
       "Die Treppe führt hinunter, im Süden liegt der obere Gang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Der Burgherr auf dem Bild hat heute auch noch einen Schwanz.",
       "Der Burgherr auf dem Bild schaut heute in eine andere Richtung.",
    }));

    o->AddDetail(({"treppe"}),
       "Die breite Treppe führt hinunter.");

    o->AddDetail(({"bild","burgherr"}),
       "Ein alter Burgherr in Rüstung, verschönert mit Schnurrbart, "
       "Hörnern und einem dritten Arm.");

    o->AddDetail(({"schnurrbart","hoerner","hörner","arm","schwanz",
                   "ruestung","rüstung"}),
       "Mit violetter Farbe, ziemlich frech.");

    o->AddDetail(({"farbe"}),
       "Violett.");

    o->AddDetail(({"richtung"}),
       "Jedenfalls nicht mehr zu dir.");

    o->AddDetail(({"gang"}),
       "Im Süden liegt der obere Gang.");

    o->AddDetail(({"ende"}),
       "Das obere Ende der Treppe.");

    o->AddExit("unten",      R("[+014+052+08]"));
    o->AddExit("sueden",     R("[+014+051+09]"));
    break;

    case "[+012+052+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Im Gästezimmer");
    o->chaos_long(
       "Das Gästezimmer ist längst eine Abstellkammer. Zwischen einem "
       "kaputten Bett und einem Schrank ohne Türen stapeln sich Kisten, "
       "zerbrochene Stühle, Kessel und ausgestopfte Tiere. Ein "
       "Gast würde hier keinen Platz finden. Im Süden geht es zurück in "
       "den Gang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Eines der ausgestopften Tiere hat dir gerade zugezwinkert.",
       "Im Schrank liegt ein Zettel: »Gäste bitte in der Schänke "
       "abgeben.«",
    }));

    o->AddDetail(({"gaestezimmer","gästezimmer","abstellkammer"}),
       "Vollgestellt bis unter die Decke.");

    o->AddDetail(({"bett"}),
       "Ein Bett mit gebrochenem Rahmen.");

    o->AddDetail(({"rahmen"}),
       "Gebrochen.");

    o->AddDetail(({"schrank"}),
       "Ein Schrank ohne Türen. Leer bis auf Staub.");

    o->AddDetail(({"kisten","stuehle","stühle","kessel"}),
       "Gerümpel, aufeinandergestapelt.");

    o->AddDetail(({"tiere","tier"}),
       "Ein Fuchs, eine Eule und etwas mit zu vielen Zähnen.");

    o->AddDetail(({"fuchs","eule","zaehne","zähne"}),
       "Ausgestopft. Hoffentlich.");

    o->AddDetail(({"gast","platz"}),
       "Nicht hier.");

    o->AddDetail(({"zettel"}),
       "»Gäste bitte in der Schänke abgeben.«");

    o->AddDetail(({"gang"}),
       "Im Süden liegt der obere Gang.");

    o->AddDetail(({"schaenke","schänke"}),
       "Unten am Platz.");

    o->AddDetail(({"tueren","türen"}),
       "Fehlen.");

    o->AddExit("sueden",     R("[+012+051+09]"));
    break;

    case "[+013+052+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Im Gemach des obersten Meisters");
    o->chaos_long(
       "Das Gemach des obersten Meisters war einst das Schlafzimmer des "
       "Burgherrn. Jetzt schläft hier jemand zwischen Bücherstapeln, "
       "Beschwörungskram und schmutzigen Roben. Das große Himmelbett hat "
       "keinen Himmel mehr, dafür ein Pentagramm auf der Matratze. Auf "
       "dem Nachttisch steht ein Totenschädel mit einer Kerze darin. Im "
       "Süden geht es zurück in den Gang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Auf dem Kopfkissen liegt ein kleiner Dämon und schläft.",
       "Die Kerze im Schädel brennt mit grüner Flamme.",
    }));

    o->AddDetail(({"gemach","schlafzimmer","meister"}),
       "Ein großes Gemach, unaufgeräumt und vollgestellt.");

    o->AddDetail(({"buecherstapeln","bücherstapeln","buecherstapel",
                   "bücherstapel","buecher","bücher"}),
       "Hohe Stapel, viele Bücher aufgeschlagen, eins als Kopfkissen.");

    o->AddDetail(({"beschwoerungskram","beschwörungskram"}),
       "Kreide, Kerzen, getrocknete Fledermäuse.");

    o->AddDetail(({"kreide","kerzen","fledermaeuse","fledermäuse"}),
       "Das Übliche.");

    o->AddDetail(({"roben"}),
       "Schmutzig und angesengt.");

    o->AddDetail(({"himmelbett","bett","matratze","pentagramm"}),
       "Ein großes Bett ohne Himmel. Auf die Matratze ist ein Pentagramm "
       "gezeichnet. Wer darin schläft, träumt vermutlich seltsam.");

    o->AddDetail(({"himmel"}),
       "Fehlt.");

    o->AddDetail(({"nachttisch","totenschaedel","totenschädel","schaedel",
                   "schädel","kerze","flamme"}),
       "Ein Totenschädel als Kerzenhalter.");

    o->AddDetail(({"kopfkissen","daemon","dämon"}),
       "Ein Buch als Kopfkissen.");

    o->AddDetail(({"kerzenhalter"}),
       "Er grinst.");

    o->AddDetail(({"gang"}),
       "Im Süden liegt der obere Gang.");

    o->AddDetail(({"buch","stapel"}),
       "Bücher in hohen Stapeln.");

    o->AddDetail(({"burgherrn"}),
       "Lange tot.");

    o->AddDetail(({"uebliche","übliche"}),
       "Kreide, Kerzen, Fledermäuse.");

    o->AddExit("sueden",     R("[+013+051+09]"));
    break;

    case "[+013+050+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Im Gemach der Herrin");
    o->chaos_long(
       "Das Gemach gehörte einst der Herrin der Burg. Ein großer, "
       "gesprungener Spiegel steht noch an der Wand, das Bett ist "
       "verschwunden, und auf dem Boden liegen Daunen aus einem "
       "aufgeschlitzten Kissen. Im Süden führte eine Tür auf einen "
       "Balkon, doch der ist abgestürzt. Jemand hat ein Brett quer vor "
       "die Tür genagelt. Im Norden geht es zurück in den Gang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Im gesprungenen Spiegel steht eine Frau in einem grauen Kleid und "
       "kämmt sich die Haare.",
       "Die Daunen auf dem Boden wirbeln auf, ohne Wind.",
    }));

    o->AddDetail(({"gemach","herrin"}),
       "Ein großes, leeres Gemach.");

    o->AddDetail(({"spiegel"}),
       "Ein großer, gesprungener Spiegel. Manchmal zeigt er mehr, als im "
       "Raum ist.");

    o->AddDetail(({"frau","kleid","haare"}),
       "Wenn du dich umdrehst, ist niemand da.");

    o->AddDetail(({"bett"}),
       "Verschwunden. Vermutlich verheizt.");

    o->AddDetail(({"daunen","kissen"}),
       "Weiße Daunen aus einem aufgeschlitzten Kissen.");

    o->AddDetail(({"tuer","tür","balkon","brett"}),
       "Ein Brett ist quer vor die Tür genagelt. Dahinter ist nichts als "
       "Luft.");

    o->AddDetail(({"leere","schritt"}),
       "Dahinter ist nichts als Luft.");

    o->AddDetail(({"gang"}),
       "Im Norden liegt der obere Gang.");

    versperrt(o,file,"sueden",
       "Hinter der vernagelten Tür ist nichts mehr. Der Balkon ist "
       "abgestürzt, ein Schritt weiter wäre dein letzter.");
    o->AddExit("norden",     R("[+013+051+09]"));
    break;

    case "[+014+050+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"In der Kammer der Zofe");
    o->chaos_long(
       "Die kleine Kammer der Zofe ist jetzt die Wäschekammer der Burg, "
       "jedenfalls ist das der Plan. Ein Waschzuber steht in der Mitte, "
       "daneben ein Berg Roben, der darauf wartet, gewaschen zu werden. "
       "Über eine Leine quer durch den Raum hängen Socken. Im Norden geht "
       "es zurück in den Gang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Im Waschzuber schwimmt ein Fisch, der nicht hierher gehört.",
       "Der Berg Roben ist heute höher. Er wächst.",
    }));

    o->AddDetail(({"kammer","zofe","waeschekammer","wäschekammer","plan"}),
       "Eine kleine Kammer voller Wäsche.");

    o->AddDetail(({"waschzuber","zuber","mitte"}),
       "Ein Holzzuber voller grauem Wasser.");

    o->AddDetail(({"holzzuber","wasser"}),
       "Grau und kalt.");

    o->AddDetail(({"berg","roben"}),
       "Ein Berg schmutziger Roben.");

    o->AddDetail(({"leine","socken"}),
       "Socken, keine zwei gleich.");

    o->AddDetail(({"fisch"}),
       "Er schaut beleidigt.");

    o->AddDetail(({"gang"}),
       "Im Norden liegt der obere Gang.");

    o->AddDetail(({"waesche","wäsche"}),
       "Socken, Roben, alles schmutzig.");

    o->AddExit("norden",     R("[+014+051+09]"));
    break;

    case "[+015+051+09]":
    hoehe(o,10);
    o->SetProp(P_INT_SHORT,"Auf der Galerie über dem Rittersaal");
    o->chaos_long(
       "Die Galerie zieht sich hoch über dem Rittersaal an der Wand "
       "entlang. Das Geländer ist an vielen Stellen weggebrochen, und auf "
       "dem Boden liegen Nussschalen und Apfelreste. Von hier oben kann man "
       "gut sehen, was unten an der Tafel passiert, und gut darauf "
       "zielen. Im Westen geht es zurück in den oberen Gang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Unten im Rittersaal sitzen schemenhafte Ritter an der Tafel und "
       "verblassen, als du hinschaust.",
       "Unten an der Tafel reibt sich ein Chaot den Kopf und schaut "
       "misstrauisch nach oben.",
    }));

    o->AddDetail(({"galerie"}),
       "Ein schmaler Umgang hoch über dem Rittersaal.");

    o->AddDetail(({"gelaender","geländer","stellen"}),
       "Morsch und an vielen Stellen weggebrochen.");

    o->AddDetail(({"rittersaal","tafel"}),
       "Tief unter dir liegt der Rittersaal.");

    o->AddDetail(({"nussschalen","apfelreste"}),
       "Wurfgeschosse.");

    o->AddDetail(({"wurfgeschosse"}),
       "Wer hier sitzt, wirft.");

    o->AddDetail(({"ritter","chaot","kopf"}),
       "Da unten.");

    o->AddDetail(({"gang"}),
       "Im Westen liegt der obere Gang.");

    o->AddDetail(({"umgang"}),
       "Schmal und morsch.");

    o->AddExit("westen",     R("[+014+051+09]"));
    break;

    // ==== Keller =====================================================

    case "[+015+050+07]":
    hoehe(o,-5);
    o->SetProp(P_LIGHT_TYPE,LT_TORCH);
    o->SetProp(P_INT_SHORT,"Am Fuß der Kellertreppe");
    o->chaos_long(
       "Du stehst am Fuß der Kellertreppe in einem niedrigen Gewölbe. "
       "Eine Fackel brennt in einem rostigen Halter. An der Wand hat "
       "jemand mit Ruß einen Pfeil nach Norden gemalt, daneben das Wort "
       "»Wein«. Die Treppe führt hinauf in den Rittersaal.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Der Pfeil an der Wand zeigt heute nach oben.",
       "Unter dem Wort »Wein« steht jetzt: »alle«.",
    }));

    o->AddDetail(({"gewoelbe","gewölbe"}),
       "Niedrig und feucht.");

    o->AddDetail(({"fackel","halter"}),
       "Eine rußende Fackel in einem rostigen Halter.");

    o->AddDetail(({"pfeil","wort","wein","russ","ruß"}),
       "Ein Pfeil nach Norden und das Wort »Wein«.");

    o->AddDetail(({"treppe","kellertreppe","rittersaal"}),
       "Die Treppe führt hinauf in den Rittersaal.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Moder und ein wenig nach Wein.");

    o->AddSmell(({"moder","wein"}),
       "Modrig und säuerlich.");

    o->AddExit("oben",       R("[+015+050+08]"));
    o->AddExit("norden",     R("[+015+051+07]"));
    break;

    case "[+015+051+07]":
    hoehe(o,-5);
    o->SetProp(P_LIGHT_TYPE,LT_TORCH);
    o->SetProp(P_INT_SHORT,"Im Weinkeller");
    o->chaos_long(
       "Der Weinkeller ist ein langes Gewölbe unter dem Rittersaal. An "
       "den Wänden liegen Fässer, die meisten leer, einige angebohrt, "
       "eines zertrümmert. Leere Flaschen stehen in Reihen auf dem Boden, "
       "als hätte jemand mit ihnen Kegeln geübt. Im Süden geht es zur "
       "Treppe, im Westen in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus einem der Fässer tropft violetter Wein. Er tropft nach oben.",
       "Hinter einem Fass schnarcht jemand.",
    }));

    o->AddDetail(({"weinkeller","gewoelbe","gewölbe"}),
       "Ein langes, feuchtes Gewölbe.");

    o->AddDetail(({"faesser","fässer","fass"}),
       "Große Eichenfässer. Die meisten klingen hohl.");

    o->AddDetail(({"eichenfaesser","eichenfässer"}),
       "Alt und leer.");

    o->AddDetail(({"wein"}),
       "Viel ist nicht mehr übrig.");

    o->AddDetail(({"flaschen","reihen","kegeln"}),
       "Leere Flaschen, ordentlich in Reihen aufgestellt. Das einzig "
       "Ordentliche in der ganzen Burg.");

    o->AddDetail(({"treppe"}),
       "Im Süden liegt die Treppe.");

    o->AddDetail(({"kellergang","gang"}),
       "Im Westen liegt der Kellergang.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach saurem Wein und Moder.");

    o->AddSound(({"schnarchen"}),
       "Gleichmäßig. Wer immer das ist, schläft gut.");

    o->AddDetail(({"ordentliche"}),
       "Wirklich.");

    o->AddDetail(({"rittersaal"}),
       "Über dir.");

    o->AddSmell(({"moder","wein"}),
       "Säuerlich und modrig.");

    o->AddExit("sueden",     R("[+015+050+07]"));
    o->AddExit("westen",     R("[+014+051+07]"));
    break;

    case "[+014+051+07]":
    kellergang(o);
    o->SetProp(P_INT_SHORT,"Im Kellergang, östlicher Teil");
    o->chaos_long(
       "Du stehst im östlichen Teil des Kellergangs. Fackeln werfen "
       "flackerndes Licht, auf dem Boden stehen Pfützen. Im Norden liegt "
       "die Waffenkammer, im Süden die Rüstungskammer. Im Osten geht es "
       "zum Weinkeller, im Westen führt der Gang weiter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus der Waffenkammer klirrt es, als würde jemand üben.",
       "Eine leere Rüstung steht im Gang und hält dir die Hand hin.",
    }));

    o->AddDetail(({"waffenkammer"}),
       "Im Norden liegt die Waffenkammer.");

    o->AddDetail(({"ruestungskammer","rüstungskammer"}),
       "Im Süden liegt die Rüstungskammer.");

    o->AddDetail(({"ruestung","rüstung","hand"}),
       "Leer. Und höflich.");

    o->AddExit("osten",      R("[+015+051+07]"));
    o->AddExit("westen",     R("[+013+051+07]"));
    o->AddExit("norden",     R("[+014+052+07]"));
    o->AddExit("sueden",     R("[+014+050+07]"));
    break;

    case "[+013+051+07]":
    kellergang(o);
    o->SetProp(P_INT_SHORT,"Im Kellergang, mittlerer Teil");
    o->chaos_long(
       "Du stehst in der Mitte des Kellergangs. Hier wird es kälter. Im "
       "Norden liegt der alte Folterraum, im Süden führt eine schwere "
       "Gittertür ins Verlies, aus dem es scharrt und faucht. Der Gang "
       "führt nach Osten und Westen weiter.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Durch die Gittertür starren dich zwei glühende Augen an.",
       "Aus dem Folterraum ist ein Quietschen zu hören, wie von einer "
       "Kurbel.",
    }));

    o->AddDetail(({"folterraum"}),
       "Im Norden liegt der alte Folterraum.");

    o->AddDetail(({"gittertuer","gittertür","verlies"}),
       "Eine schwere Gittertür führt nach Süden ins Verlies.");

    o->AddDetail(({"augen"}),
       "Glühend rot.");

    o->AddDetail(({"kurbel"}),
       "Irgendwo im Folterraum.");

    o->AddSound(({DEFAULT_SOUND,"scharren","fauchen"}),
       "Aus dem Verlies scharrt und faucht es.");

    o->AddSound(({"verlies","fauchen"}),
       "Scharren und Fauchen.");

    o->AddExit("osten",      R("[+014+051+07]"));
    o->AddExit("westen",     R("[+012+051+07]"));
    o->AddExit("norden",     R("[+013+052+07]"));
    o->AddExit("sueden",     R("[+013+050+07]"));
    break;

    case "[+012+051+07]":
    kellergang(o);
    o->SetProp(P_INT_SHORT,"Im Kellergang, westlicher Teil");
    o->chaos_long(
       "Du stehst im westlichen Teil des Kellergangs. Im Norden ist die "
       "Decke eingestürzt, ein Berg aus Steinen und Erde versperrt den "
       "Durchgang. Im Süden liegt der Wachraum. Im Westen öffnet sich der "
       "Gang zur Gruft, im Osten geht es zurück.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus dem Schutt im Norden ragt ein Arm. Er winkt.",
       "Auf dem Schutt im Norden hat jemand eine Kerze aufgestellt.",
    }));

    o->AddDetail(({"decke","berg","steine","erde","schutt","durchgang"}),
       "Die Decke ist eingestürzt, der Durchgang im Norden ist voller "
       "Steine und Erde.");

    o->AddDetail(({"wachraum"}),
       "Im Süden liegt der Wachraum.");

    o->AddDetail(({"arm"}),
       "Knochig. Und freundlich.");

    o->AddDetail(({"kerze"}),
       "Eine einzelne, flackernde Kerze. Für wen auch immer.");

    versperrt(o,file,"norden",
       "Im Norden ist die Decke eingestürzt. Steine und Erde versperren "
       "den Durchgang vollständig.");
    o->AddExit("osten",      R("[+013+051+07]"));
    o->AddExit("westen",     R("[+011+051+07]"));
    o->AddExit("sueden",     R("[+012+050+07]"));
    break;

    case "[+014+052+07]":
    hoehe(o,-5);
    o->SetProp(P_INT_SHORT,"In der Waffenkammer");
    o->chaos_long(
       "Die Waffenkammer ist ein langer Raum mit Gestellen an den Wänden. "
       "Die meisten Gestelle sind leer, in den übrigen stecken verbogene "
       "Schwerter, Speere ohne Spitze und eine Keule, die jemand violett "
       "angemalt hat. An einer Wand ist eine Zielscheibe aufgemalt, voller "
       "Brandflecken. Im Süden geht es zurück in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Eines der Schwerter klappert in seinem Gestell, als wollte es "
       "heraus.",
       "In der Mitte der Zielscheibe steckt ein frischer Pfeil.",
    }));

    o->AddDetail(({"waffenkammer"}),
       "Ein langer Raum mit Waffengestellen.");

    o->AddDetail(({"gestelle","gestell","waffengestellen"}),
       "Holzgestelle, größtenteils leer.");

    o->AddDetail(({"schwerter","schwert","speere","spitze","keule"}),
       "Kaum etwas davon ist noch zu gebrauchen. Die Keule ist "
       "violett.");

    o->AddDetail(({"zielscheibe","mitte","pfeil"}),
       "Eine aufgemalte Zielscheibe. Getroffen wurde sie mit Feuer, nicht "
       "mit Pfeilen.");

    o->AddDetail(({"feuer","pfeilen"}),
       "Wie man an den Brandflecken sieht.");

    o->AddDetail(({"kellergang","gang"}),
       "Im Süden liegt der Kellergang.");

    o->AddExit("sueden",     R("[+014+051+07]"));
    break;

    case "[+014+050+07]":
    hoehe(o,-5);
    o->SetProp(P_INT_SHORT,"In der Rüstungskammer");
    o->chaos_long(
       "In der Rüstungskammer stehen alte Rüstungen in einer Reihe, rostig "
       "und verbeult. Die Chaoten haben sie mit violetter Farbe "
       "angemalt, ihnen Hüte aufgesetzt und einer einen Besen in die Hand "
       "gedrückt. Auf einem Tisch liegen Helme, Handschuhe und ein "
       "Kettenhemd, das jemand als Netz benutzt hat. Im Norden geht es "
       "zurück in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Rüstung mit dem Besen fegt. Langsam.",
       "Eine der Rüstungen hat heute ihren Hut getauscht.",
    }));

    o->AddDetail(({"ruestungskammer","rüstungskammer"}),
       "Ein Raum voller alter Rüstungen.");

    o->AddDetail(({"ruestungen","rüstungen","ruestung","rüstung","reihe"}),
       "Rostig, verbeult und violett angemalt.");

    o->AddDetail(({"farbe"}),
       "Violett.");

    o->AddDetail(({"huete","hüte","hut","besen","hand"}),
       "Die Chaoten fanden das lustig.");

    o->AddDetail(({"tisch","helme","handschuhe"}),
       "Alles verbeult und rostig.");

    o->AddDetail(({"kettenhemd","netz"}),
       "Voller Fischgräten.");

    o->AddDetail(({"fischgraeten","fischgräten"}),
       "Irgendwo muss es hier Fische geben.");

    o->AddDetail(({"kellergang","gang"}),
       "Im Norden liegt der Kellergang.");

    o->AddDetail(({"fische"}),
       "Keine zu sehen.");

    o->AddExit("norden",     R("[+014+051+07]"));
    break;

    case "[+013+052+07]":
    hoehe(o,-5);
    o->SetProp(P_INT_SHORT,"Im alten Folterraum");
    o->chaos_long(
       "Der alte Folterraum ist ein düsteres Gewölbe. Eine Streckbank "
       "steht in der Mitte, an den Wänden hängen Ketten und Zangen. Die "
       "Chaoten benutzen den Raum offenbar als Übungsraum für "
       "widerspenstige Dämonen: Die Streckbank ist zerkratzt und "
       "angesengt, und an der Wand hängt eine Tafel mit Strichen. Im "
       "Süden geht es zurück in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Kurbel der Streckbank dreht sich langsam von selbst.",
       "An der Tafel ist ein Strich dazugekommen.",
    }));

    o->AddDetail(({"folterraum","gewoelbe","gewölbe"}),
       "Düster und kalt.");

    o->AddDetail(({"streckbank","kurbel","mitte"}),
       "Eine alte Streckbank, zerkratzt und angesengt.");

    o->AddDetail(({"ketten","zangen"}),
       "Rostig und verbogen.");

    o->AddDetail(({"uebungsraum","übungsraum","daemonen","dämonen"}),
       "Was hier geübt wird, willst du lieber nicht wissen.");

    o->AddDetail(({"tafel","striche","strich"}),
       "Zwei Spalten: »Chaoten« und »Dämonen«. Die Dämonen führen.");

    o->AddDetail(({"spalten"}),
       "Die Dämonen führen deutlich.");

    o->AddDetail(({"kellergang","gang"}),
       "Im Süden liegt der Kellergang.");

    o->AddExit("sueden",     R("[+013+051+07]"));
    break;

    case "[+013+050+07]":
    hoehe(o,-5);
    o->SetProp(P_LIGHT,0);
    o->SetProp(P_INT_SHORT,"Im Verlies der Burg Zwielichtstein");
    o->chaos_long(
       "Das Verlies ist feucht, kalt und finster. An den Wänden reihen "
       "sich Zellen mit rostigen Gittern, hinter denen Dämonen scharren, "
       "fauchen und mit glühenden Augen hervorstarren. Hier sperren die "
       "Chaoten ein, was ihnen entwischt ist und wieder eingefangen "
       "wurde. Im Norden geht es zurück in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Einer der Dämonen hat die Gitterstäbe zu einem Knoten gebogen. Er "
       "kommt trotzdem nicht heraus.",
       "An einer Zelle hängt ein Schild: »Füttern verboten. Wirklich.«",
    }));

    o->AddDetail(({"verlies"}),
       "Feucht, kalt und finster.");

    o->AddDetail(({"zelle","zellen","gitter","gitterstaebe",
                   "gitterstäbe","knoten"}),
       "Hinter den rostigen Gittern hocken gefangene Dämonen.");

    o->AddDetail(({"daemon","dämon","daemonen","dämonen"}),
       "Die Dämonen in den Zellen fauchen dich an. Manche sind klein und "
       "flink, andere groß und wuchtig. Alle haben glühende Augen.");

    o->AddDetail(({"augen"}),
       "Glühende Augen starren dich aus der Dunkelheit an.");

    o->AddDetail(({"dunkelheit"}),
       "Hier unten ist es völlig dunkel.");

    o->AddDetail(({"schild"}),
       "»Füttern verboten. Wirklich.«");

    o->AddDetail(({"kellergang","gang"}),
       "Im Norden liegt der Kellergang.");

    o->AddSound(({DEFAULT_SOUND,"scharren","fauchen"}),
       "Es scharrt, faucht und kratzt unablässig.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es stinkt nach Moder und nach Schwefel.");

    o->AddSmell(({"moder"}),
       "Feucht und modrig.");

    o->AddItem(CHAOS_GILDEN_MON("kerkerdaemon"),REFRESH_DESTRUCT);
    o->AddItem(CHAOS_GILDEN_MON("kerkerdaemon"),REFRESH_DESTRUCT);

    o->AddExit("norden",     R("[+013+051+07]"));
    break;

    case "[+012+050+07]":
    hoehe(o,-5);
    o->SetProp(P_LIGHT_TYPE,LT_TORCH);
    o->SetProp(P_INT_SHORT,"Im Wachraum");
    o->chaos_long(
       "Der Wachraum ist ein kleines Gewölbe mit einem Tisch und zwei "
       "Hockern. Auf dem Tisch liegen Würfel, Karten und ein halbes "
       "Kerkerbrot. An der Wand hängt ein Schlüsselbund, an dem kein "
       "einziger Schlüssel zu irgendeiner Tür passt, wie ein Zettel "
       "daneben verrät. Im Norden geht es zurück in den Kellergang.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Die Würfel auf dem Tisch zeigen alle eine Sieben.",
       "Einer der Hocker ist heute einen Kopf kleiner.",
    }));

    o->AddDetail(({"wachraum","gewoelbe","gewölbe"}),
       "Ein kleines, feuchtes Gewölbe.");

    o->AddDetail(({"tisch","hocker","hockern","kopf"}),
       "Ein wackliger Tisch und zwei Hocker.");

    o->AddDetail(({"wuerfel","würfel","sieben","karten"}),
       "Ein angefangenes Spiel.");

    o->AddDetail(({"spiel"}),
       "Wer gewinnt, ist nicht zu erkennen.");

    o->AddDetail(({"kerkerbrot","brot"}),
       "Halb gegessen und steinhart.");

    o->AddDetail(({"schluesselbund","schlüsselbund","schluessel",
                   "schlüssel"}),
       "Ein dicker Bund rostiger Schlüssel.");

    o->AddDetail(({"zettel","tuer","tür"}),
       "»Passt nirgends. Nicht wegwerfen, man weiß nie.«");

    o->AddDetail(({"kellergang","gang"}),
       "Im Norden liegt der Kellergang.");

    o->AddDetail(({"bund"}),
       "Ein dicker Bund rostiger Schlüssel.");

    o->AddDetail(({"wache","gaehnulf","gähnulf"}),
       "Gähnulf soll hier Wache halten. Meistens schläft er.");

    o->AddItem(CHAOS_GILDEN_MON("wache"),REFRESH_DESTRUCT);

    o->AddExit("norden",     R("[+012+051+07]"));
    break;

    case "[+011+051+07]":
    hoehe(o,-5);
    o->SetProp(P_INT_SHORT,"In der Gruft der Burg Zwielichtstein");
    o->chaos_long(
       "Die Gruft ist ein niedriges Gewölbe mit Nischen in den Wänden, in "
       "denen einst die Toten der Burg lagen. Die meisten Nischen sind "
       "leer geräumt, die Knochen liegen sortiert in Körben auf dem Boden: "
       "»Schädel«, »Lange Knochen«, »Kleinzeug«. Offenbar bedienen sich die "
       "Chaoten hier für ihre Rituale. Im Norden liegt die Grabkammer, "
       "im Osten der Kellergang. Nach Westen und Süden ist die Gruft "
       "eingestürzt.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Im Korb mit den Schädeln klappert es leise.",
       "In einer der Nischen liegt doch noch jemand. Er hat die Arme "
       "verschränkt und sieht verärgert aus.",
    }));

    o->AddDetail(({"gruft","gewoelbe","gewölbe"}),
       "Niedrig, kalt und still. Fast.");

    o->AddDetail(({"nischen","nische","toten"}),
       "Lange, schmale Nischen in den Wänden. Fast alle leer.");

    o->AddDetail(({"knochen","koerbe","körbe","korb","schaedel",
                   "schädel","kleinzeug"}),
       "Ordentlich sortiert: Schädel, lange Knochen, Kleinzeug.");

    o->AddDetail(({"rituale"}),
       "Für ein gutes Ritual braucht man eben Knochen.");

    o->AddDetail(({"arme","jemand"}),
       "Ein Skelett, das sich weigert, sortiert zu werden.");

    o->AddDetail(({"skelett"}),
       "Es hat die Arme verschränkt.");

    o->AddDetail(({"grabkammer"}),
       "Im Norden liegt die Grabkammer.");

    o->AddDetail(({"kellergang","gang"}),
       "Im Osten liegt der Kellergang.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Staub, Erde und sehr altem Tod.");

    o->AddSmell(({"erde","tod"}),
       "Alt und trocken.");

    o->AddSound(({"schaedel","schädel","klappern"}),
       "Klapper.");

    o->AddDetail(({"lange"}),
       "Säuberlich gestapelt.");

    o->AddDetail(({"ritual"}),
       "Für ein gutes Ritual braucht man eben Knochen.");

    o->AddDetail(({"totengraeber","totengräber","modrich"}),
       "Modrich sortiert hier die Knochen.");

    o->AddItem(CHAOS_GILDEN_MON("totengraeber"),REFRESH_DESTRUCT);

    versperrt(o,file,"westen",
       "Im Westen ist die Gruft eingestürzt. Zwischen den Steinen ragen "
       "Knochen hervor, die noch keiner sortiert hat.");
    versperrt(o,file,"sueden",
       "Im Süden ist die Decke heruntergekommen. Da ist kein Durchkommen.");
    o->AddExit("osten",      R("[+012+051+07]"));
    o->AddExit("norden",     R("[+011+052+07]"));
    break;

    case "[+011+052+07]":
    hoehe(o,-5);
    o->SetProp(P_LIGHT_TYPE,LT_MAGIC);
    o->SetProp(P_INT_SHORT,"In der Grabkammer");
    o->chaos_long(
       "In der Grabkammer steht ein steinerner Sarkophag, dessen Deckel "
       "jemand mit einer Brechstange verschoben hat. Die Brechstange "
       "steckt noch im Spalt. Der Sarkophag ist leer. In den Deckel ist "
       "eine Inschrift gemeißelt, und an der Wand ist ein verblasstes Bild "
       "eines Mannes in Rüstung zu erkennen. Im Süden geht es zurück in "
       "die Gruft.");

    o->SetProp(P_CHAOS_VARIANTEN,({
       "Aus dem leeren Sarkophag ist ein leises Seufzen zu hören.",
       "Der Deckel des Sarkophags ist heute ein Stück weiter zugeschoben. "
       "Von innen?",
    }));

    o->AddDetail(({"grabkammer","kammer"}),
       "Eine kleine, kalte Kammer.");

    o->AddDetail(({"sarkophag","deckel","spalt"}),
       "Ein schwerer, steinerner Sarkophag. Der Deckel ist zur Seite "
       "geschoben, drinnen ist nichts.");

    o->AddDetail(({"brechstange"}),
       "Rostig. Sie steckt fest.");

    o->AddDetail(({"inschrift"}),
       "Die Inschrift ist kaum noch zu lesen.");

    o->AddReadDetail(({"inschrift"}),
       "»Hier ruht der letzte Herr von Zwielichtstein, der den Stern "
       "brach. Er möge ruhen.« Darunter, frisch mit Kreide: »Tut er "
       "aber nicht.«");

    o->AddDetail(({"bild","mann","mannes","ruestung","rüstung"}),
       "Ein Mann in Rüstung, ein gesprungener Stern auf dem Schild.");

    o->AddDetail(({"stern","schild"}),
       "Derselbe gesprungene Stern wie über dem Portal.");

    o->AddDetail(({"portal"}),
       "Oben, über dem Eingang des Hauptgebäudes.");

    o->AddDetail(({"gruft"}),
       "Im Süden liegt die Gruft.");

    o->AddSound(({"seufzen"}),
       "Tief und müde.");

    o->AddDetail(({"eingang","hauptgebaeudes","hauptgebäudes"}),
       "Weit oben.");

    o->AddDetail(({"seite"}),
       "Der Deckel ist zur Seite geschoben.");

    o->AddExit("sueden",     R("[+011+051+07]"));
    break;
  }
}
