                         
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <new_skills.h>
#include <wizlevels.h>

#include "gilde.h"

#define BS break_string
#define TP this_player()
#define TO this_object()

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "In einer Ruine inmitten der Eiswueste");
  SetProp( P_INT_LONG, BS(
     "Hier herrscht das Chaos. Umgestuerzte Regale, zerissene Buecher, Schriftrollen "
    +"und andere Schriftstuecke bilden ein wahres Durcheinander mit den Truemmern und "
    +"dem Schnee. Bei der Anzahl der Regal-Fragmente kommen Dir die Buecherreste, die "
    +"Du erblickst aber recht gering vor. Offensichtlich wurden irgendwann viele der "
    +"Folianten gestohlen oder in Sicherheit gebracht.",78) );

  AddDetail( ({"buecher", "folianten", "exemplare", "buecherreste"}), BS(
     "Du findest nur total zerstoerte Exemplare. Nichts das Dir was nuetzen "
    +"koennte!",78) );
  AddDetail( ({"anzahl"}), BS(
    "Och das waren schon viele!",78) );
  AddDetail( ({"regal", "regale", "buecherregale"}), BS(
     "Das waren wohl alles mal Buecherregale. Ob es sich hier um eine Bibliothek "
    +"handelte?",78) );
  AddDetail( ({"bibliothek", "buecherei"}), BS(
     "Das war wohl in der Tat mal eine Bibliothek. Das haettest Du mitten in der "
    +"Eiswueste eigentlich nicht fuer moeglich gehalten.",78) );
  AddDetail( ({"sicherheit"}), BS(
    "So nennt man das heutzutage. Echt ehrlich! :)",78) );
  AddDetail( ({"schriften", "schriftstuecke", "schriftrollen", "rollen"}), BS(
    "Alles zerfetzt und vernichtet. :(",78) );
  AddDetail( ({"witzbold"}), BS(
    "Du bist gemeint!",78) );
  AddDetail( ({"augen"}), BS(
    "Witzbold!",78) );
  AddDetail( ({"chaos"}), BS(
    "Sperr die Augen auf!",78) );
  AddDetail( ({"ort", "raum", "umgebung"}), BS(
    "Schau Dich halt in Deiner Umgebung um. (Syntax: schau)",78) );
  AddDetail( ({"syntax", "befehl"}), BS(
    "Ist 'schau' ein _neuer_ Befehl fuer Dich?",78) );
  AddDetail( ({"gebaeude", "gemaeuer", "raeume", "dingens"}), BS(
    "Gebaeude, Gemaeuer, Raeume... das Dingens in dem Du stehst ist gemeint!",78) );
  AddDetail( ({"ueberall"}), BS(
    "Na wohin Du halt sehen kannst hier.",78) );
  AddDetail( ({"truemmer", "bruchstuecke", "teile"}), BS(
     "Ueberall liegen sie herum, halb vom Schnee verdeckt. Es waren wohl mal Teile der "
    +"Waende und der Decke.",78) );
  AddDetail( ({"decke"}), BS(
     "Die gibts hier nimmer. Du stehst unter freiem Himmel. Die ehemalige Decke liegt "
    +"in Bruchstuecken zu Deinen Fuessen.",78) );
  AddDetail( ({"himmel", "polarhimmel"}), BS(
     "Falls Du erwartet hast, etwas Besonderes zu sehen, wirst Du bitter enttaeuscht "
    +"sein. Du siehst hinauf in den klaren, frostigen Polarhimmel. Nicht mal ein "
    +"Woelkchen ist zu sehen.",78) );
  AddDetail( ({"woelkchen"}), BS(
     "Wie gesagt: Keins zu sehen.",78) );
  AddDetail( ({"reste", "rest"}), BS(
    "Damit sind die Truemmer und Bruchstuecke gemeint.",78) );
  AddDetail( ({"gestein", "material"}), BS(
    "Seltsames Material.",78) );
  AddDetail( ({"waende", "wand"}), BS(
     "Die Waende bestanden wohl einmal aus einem schwarzen Gestein. Ziemlicher "
    +"Kontrast mit dem weissen Schnee!",78) );
  AddDetail( ({"schwarz", "weiss"}), BS(
     "Das Schwarz ist so schwarz, wie das Weiss weiss ist!",78) );
  AddDetail( ({"kontrast"}), BS(
     "Schwarz und Weiss halt.",78) );
  AddDetail( ({"schutt"}), BS(
     "Du findest nix, was sich lohnen wuerde.",78) );
  AddDetail( ({"boden"}), BS(
     "Alles voll mit Truemmern. Der Schutt bedeckt den ganzen Raum.",78) );
  AddDetail( ({"ruinen", "ruine"}), BS(
    "Die Ruinen sind halb vom Schnee verdeckt, und Du stehst mitten drin. Schau Dich "
   +"einfach etwas um, wenns Dich interessiert!",78) );
  AddDetail( ({"eis", "schnee"}), BS(
    "Schnee und Eis bedecken die Truemmer.",78) );
  AddDetail( ({"eiswueste", "wueste", "labyrinth"}), BS(
     "Du befindest Dich noch in der Eiswueste, aber das eigentliche Labyrinth, fuer "
    +"das die Wueste beruechtigt ist, ist weiter suedlich!",78) );

  AddDetail( ({"polargebiet", "gebiet", "region", "polarregion", "polar"}), BS(
     "Momentan befindest Du Dich im Polargebiet, also in der Region Polar.",78) );

  AddSounds( SENSE_DEFAULT, BS("Der Wind heult und pfeift durch die Ruinen.",78));
  AddSmells( SENSE_DEFAULT, BS("Irgendwie riecht es hier alt. Die frische Polarluft "
    +"nuetzt hier nichts, die vielen alten Buecher die waren, und von denen Teile "
    +"auch noch zu finden sind, verbreiten einen eigentuemlichen Geruch, der in der "
    +"Nase kitzelt.",78));
  AddSmells( ({"luft", "polarluft"}), BS("Die riecht eigentlich gut, aber der Geruch "
    +"der von den alten Buecherresten ausgeht, ist uebel.",78) );
  AddSmells( ({"geruch", "buecher"}), BS("Es riecht hauptsaechlich nach vergammeltem "
    +"Pergament und Leder. Schweinsleder und... Du glaubst einen typischen "
    +"'Hobbitgeruch' zu wahrzunehmen.",78) );
  AddSmells( ({"leder", "schweinsleder"}), BS("Wie sowas halt riecht!",78) );
  AddSmells( ({"hobbitgeruch", "hobbit"}), BS("Bucheinbaende aus Hobbitleder???",78) );

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "suedosten", CHAOS_GILDEN_ROOM("cl0w7") );
}
