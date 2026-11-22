                         
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <new_skills.h>
#include <wizlevels.h>

#include "gilde.h"

#define BS break_string
#define TP this_player()

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "Im schwarzen Eisberg");
  SetProp( P_INT_LONG, BS(
     "Hier ist eine kleine Nische im Eis. Die Umgebung sieht noch duesterer aus, als "
    +"es schon am Eingang der Eishoehle der Fall war. Eissplitter auf dem Boden und "
    +"Kerben in den Waenden deuten auf heftige Kaempfe hin, die hier einmal getobt "
    +"haben moegen. Blutflecke und herumliegende Knochenteile bestaetigen Deine "
    +"Vermutung, dass dies die Heimstatt eines gefaehrlichen Wesens sein "
    +"koennte...",78,0,1) );

  AddDetail( ({"leiche", "leichen"}), "Du kannst keine sehen!\n");
  AddDetail( ({"eingang", "ausgang"}), "Den Eingang bzw. Ausgang der Hoehle kannst "
    +"Du von hier aus nicht sehen!\n");
  AddDetail( ({"eishoehle", "hoehle", "ort", "umgebung"}),
     "Tust Du das nicht schon die ganze Zeit?\n");
  AddDetail( ({"farbe", "nachtschwarz"}), "Die Farbe des Eises ist Nachtschwarz!\n");
  AddDetail( ({"feind", "feinde"}), "Keine Feinde in der Naehe! Oder? :)\n");
  AddDetail( "kaelte", "Die Kaelte ist kalt. Meistens jedenfalls :)\n");
  AddDetail( "macht", "Beschaff Dir Wissen!\n");
  AddDetail( "wissen", "Na Du weisst doch: Wissen ist Macht. (aber nichts wissen macht "
    +"auch nix)\n");
  AddDetail( "naehe", "Klar, ausserdem ists nachts kaelter als draussen.\n");
  AddDetail( "labyrinth", "Die Eiswueste ist eine Art Labyrinth.\n");
  AddDetail( "schiss", "Pass auf dass das nicht in die Hose geht!\n");
  AddDetail( "hose", "Laeufst Du denn OHNE Hose rum???\n");
  AddDetail( "zentrum", "Das Zentrum ist in der Mitte.\n");
  AddDetail( "mitte", "Die Mitte ist im Zentrum.\n");
  AddDetail( "zeit", "Nimm Dir viel davon zum Untersuchen!\n");
  AddDetail( ({"wesen", "kreaturen"}), "Wesen bzw. Kreaturen sind wir doch alle, "
    +"oder?\n");
  AddDetail( "seiten", "Die Seiten umgeben das Zentrum.\n");
  AddDetail( ({"entfernung", "abstand"}), "Den Abstand zur Decke kannst Du nicht "
    +"klar bestimmen.\n");
  AddDetail( ({"eiswueste", "wueste"}), "Dazu musst Du die Hoehle verlassen!\n");
  AddDetail( "lebenssaft", "Anderes Wort fuer Blut.\n");
  AddDetail( ({"fall", "gruppen", "pass", "willen", "art"}), BS(
     "Dieses Detail konnte hier nicht ueberleben und ist bereits vor laengerer Zeit "
    +"verschieden.",78) );
  AddDetail( ({"detail", "details"}), "Welches Detail meinst Du denn?\n");
  AddDetail( "nische", "Schau Dich doch mal um!\n");
  AddDetail( "wort", "Besteht meist aus mehreren Buchstaben.\n");
  AddDetail( "woerter", "Bestehen meist aus mehreren Buchstaben.\n");
  AddDetail( "buchstaben", "In Gruppen bilden sie Woerter :)\n");
  AddDetail( ({"eissplitter", "splitter"}), BS(
     "Winzige Splitter aus Eis, evtl. kommen ja daher die Kerben in den Waenden!?",78) );
  AddDetail( "kerben", "Hier muessen ja mal heftige Kaempfe getobt haben!\n");
  AddDetail( "heimstatt", "So genau willst Du das gar nicht wissen.\n");
  AddDetail( "vermutung", "Es koennte ja so sein, oder?\n");
  AddDetail( "gemetzel", "Sowas in der Art hats hier wohl schon oefters gegeben.\n");
  AddDetail( "gedanke",
     "Ich denke, also bin ich. Auf orkisch: Ich fresse, also bin ich.\n");
  AddDetail( "ueberall", "Na ueberall halt...\n");

  AddSpecialDetail( ({"luft", "duft", "geruch", "gestank"}), "luft");
  AddSpecialDetail( ({"boden", "fussboden", "hoehlenboden"}), "boden");
  AddSpecialDetail( ({"decke", "hoehlendecke"}) ,"decke");
  AddSpecialDetail( ({"dunkelheit", "dunkel", "finsternis"}), "dunkelheit");
  AddSpecialDetail( "chaos", "chaos");
  AddSpecialDetail( "licht", "licht");
  AddSpecialDetail( ({"wand", "waende"}), "waende");
  AddSpecialDetail( ({"berg", "eisberg"}), "berg");
  AddSpecialDetail( ({"eis"}), "eis");
  AddSpecialDetail( "geschmack", "geschmack");
  AddSpecialDetail( ({"schwefel", "moder", "modergeruch"}), "gerueche");
  AddSpecialDetail( ({"gefuehle", "gefuehl"}), "gefuehl");
  AddSpecialDetail( "schutz", "schutz");
  AddSpecialDetail( ({"blutflecke", "blutspritzer", "blutfleck", "blut", "spritzer",
    "flecke"}), "blutflecke");
  AddSpecialDetail( ({"kampf", "kaempfe"}), "kampf");
  AddSpecialDetail( ({"knochen", "knochenteile", "teile", "gebeine"}), "knochenteile");
  AddSpecialDetail( "befriedigung", "befriedigung");
  AddSpecialDetail( "wohnraum", "wohnraum");
  AddSpecialDetail( "kaempfer", "kaempfer");

  AddSounds( SENSE_DEFAULT, BS("Hier ist es totenstill!",78));
  AddSmells( SENSE_DEFAULT, BS("Hier riechts nach Schwefel und Moder.",78));
  AddSmells( ({"schwefel", "moder"}), "Ja danach riechts tatsaechlich!\n");

  SetProp( P_LIGHT, 0);
  SetProp( P_INDOORS, 1 );
  AddExit( "suedwesten", CHAOS_GILDEN_ROOM("cl1w1") );
}


string luft()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Hier riechts richtig gut. Leichter Schwefel- und Modergeruch, durchsetzt vom "
    +"bekannten Duft vor sich hinfaulender Leichen...",78);
  else
    return BS(
     "Baeh! Hier stinkts ekelhaft nach Schwefel und Moder. Ausserdem glaubst Du "
    +"den widerlichen Gestank von verfaulenden Leichen zu erkennen!",78);
}
string boden()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Alles hier besteht aus dem herrlich schwarzen Eis, auch der Boden! Kleine "
    +"Eissplitter liegen ueberall verstreut herum.",78);
  else
    return BS(
     "Der Boden dieser Eishoehle ist widerlich schwarz und kalt. Kleine "
    +"Eissplitter liegen ueberall verstreut herum.",78);
}
string decke()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das schwarze, dunkle Eis gibt Dir ein Gefuehl des Schutzes.",78);
  else
    return BS(
     "Bei dem schwarzen, unheimlichen Eis ist es nicht leicht, die Entfernung zur "
    +"Decke zu bestimmen. Sie koennte direkt ueber Dir liegen, evtl. aber auch in "
    +"mehreren Meter Hoehe. Vielleicht senkt sie sich ja gerade, um Dich zu "
    +"erdruecken?",78);
}
string dunkelheit()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Ja, hier fuehlst Du Dich wohl! Ein Ort ganz nach Deinem Geschmack: Duester, "
    +"kalt und unheimlich (zumindest fuer Nicht-Chaoten).",78);
  else
    return BS(
     "Hier wirkt alles duester und bedrohlich. Kein 'normales' Wesen koennte sich "
    +"an einem derart schrecklichen Ort wohlfuehlen. Du willst doch sicherlich "
    +"zu den 'normalen' Wesen gehoeren? Dann verlass die Hoehle lieber schnell "
    +"wieder! :)",78);
}
string chaos()
{
  if(TP->QueryProp(P_RACE) == "Hobbit")   // Hobbit??? *lach*
    return BS(
     "*Bibber* Ueberhaupt bei dem Gedanken an das Chaos wird Dir so uebel, dass "
    +"Du Dich gleich mal uebergibst. Wahrscheinlich hast Du mal wieder zuviel "
    +"gefr... aeh gegessen. Auf jeden Fall: Das Chaos ist nix fuer Hobbits, weil "
    +"... Chaos ist so .........chaotisch!",78);
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Ja, dieser Ort strahlt die Macht des Chaos aus, das kannst Du deutlich fuehlen. "
    +"Das Zentrum der Macht kann nicht sehr weit entfernt sein.",78);
  else
    return BS(
     "Ein seltsames Gefuehl, dunkel und unheilvoll, schleicht zu Deinem Herzen. "
    +"Schnell konzentrierst Du Dich auf etwas anderes.",78);
}
string licht()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Licht ist der Feind der Dunkelheit, welche Du zu Deinen Verbuendeten zaehlst!",78);
  else
    return BS(
     "Das schwarze Eis der Hoehle strahlt eine gewisse Dunkelheit und Finsternis aus, "
    +"das jeglichem Licht regelrecht entgegenzuwirken scheint.",78);
}
string waende()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das schwarze, hier allesbeherrschende Eis umgibt Dich von allen Seiten. Kleine "
    +"Kerben und Blutspritzer zeugen von heftigen Kaempfen, die hier wohl mal "
    +"stattfanden. Genau so stellst Du Dir Deinen idealen Wohnraum vor...",78);
  else
    return BS(
     "Das schwarze, hier allesbeherrschende Eis umgibt Dich von allen Seiten. "
    +"Kerben und Blutspritzer zeugen von gewaltigen Kaempfen, die hier einmal getobt "
    +"haben. Bei dem Anblick musst Du unwillkuerlich wuergen...",78);
}
string berg()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Du befindest Dich im Inneren des schwarzen Eisbergs. Ueberall bist Du von dem "
    +"herrlich schwarzen Eis umgeben.",78);
  else
    return BS(
     "Du befindest Dich in einem unheimlichen, schwarzen Eisberg. Schwarzes Eis? "
    +"Ja, hier scheints sowas zu geben, auch wenn Du Dir die Sache nicht erklaeren "
    +"kannst. Irgendwie unheimlich...",78);
}
string eis()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das Eis ist von nachtschwarzer Farbe und eiskalt. Einfach herrlich!",78);
  else
    return BS(
     "Normales Eis ist dies hier nicht, sonst waers wohl nicht schwarz. Na wenigstens "
    +"ist es kalt, aber das troestet Dich nicht ueber die unheimliche Atmosphaere, die "
    +"dieser Ort verbreitet, hinweg!",78);
}
string geschmack()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Dieser Ort entspricht ganz Deinem Geschmack, hier fuehlst Du Dich wohl.",78);
  else
    return BS(
     "Also der Schoepfer dieses Raumes hat bestimmt keinen, da bist Du Dir sicher. "
    +"Welches kranke Wesen mag sich an solch einem Ort wohlfuehlen?",78);
}
string gerueche()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Ein herrlicher Geruch.",78);
  else
    return BS(
     "Pfui stinkt das! Dir wird ganz uebel bei so nem Gestank!",78);
}
string gefuehl()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Gefuehle hast Du als Kaempfer des Chaos ja normalerweise nicht, aber wohlfuehlen "
    +"tust Du Dich hier!",78);
  else
    return BS(
     "Du hast wohl Schiss!?",78);
}
string schutz()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das kalte, schwarze Eis vermittelt Dir ein Gefuehl des Schutzes.",78);
  else
    return BS(
     "Den haettest Du wohl gerne hier, was?",78);
}
string blutflecke()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Mit innerlicher Befriedigung stellst Du Dir den verzweifelten Kampf der Wesen "
    +"vor, denen dieser Lebenssaft einmal gehoerte...",78);
  else
    return BS(
     "Baeh. Vertrocknetes, schmieriges Blut klebt an den Waenden.",78);
}
string kampf()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Als Kaempfer des Chaos sollst du den Kampf 'SUCHEN', nicht(!) 'untersuchen' "
    +"!!!",78);
  else
    return BS(
     "Die Kerben, das Blut und die Knochenteile lassen auf zurueckliegende Kaempfe "
    +"schliessen.",78);
}
string knochenteile()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Hmmm lecker :)",78);
  else
    return BS(
     "Die armen Wesen, denen die Gebeine mal gehoerten...",78);
}
string befriedigung()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Der Gedanke an das Gemetzel hier befriedigt Dich ungemein.",78);
  else
    return BS(
     "Na! Das ist nicht der richtige Ort dazu, oder!?",78);
}
string wohnraum()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Jo, das waer einer fuer Dich.",78);
  else
    return BS(
     "Sowas siehst Du hier beim besten Willen nicht!",78);
}
string kaempfer()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Du bist ein Kaempfer des Chaos.",78);
  else
    return BS(
     "Sowas siehst Du da nicht!",78);
}
