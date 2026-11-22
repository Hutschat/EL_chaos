                         
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
     "Wie siehts denn hier aus? Zwar liegen auch hier ueberall Truemmer herum, doch "
    +"scheint der Raum keine grosse Veraenderung durchgemacht zu haben, es hat hier "
    +"wohl schon frueher schlimm ausgesehen! Der Schnee verdeckt viel, aber hier "
    +"liegen soviele zerbrochene Tische und Stuehle herum, die kannst Du einfach nicht "
    +"uebersehen. Unter Deinen Fuessen knirscht es, als wuerdest Du auf einem grossen "
    +"Scherbenhaufen stehen. Vermutlich trifft das auch zu, eine dicke Scherbenschicht "
    +"scheint den Boden zu bedecken.",78) );

  AddDetail( ({"scherbenhaufen", "scherbenschicht", "haufen", "schicht"}), BS(
     "Du kannst die einzelnen Scherben untersuchen, wenn Du moechtest.",78) );
  AddDetail( ({"scherben"}), BS(
     "Du betrachtest die bunten Scherben etwas eingehender und entdeckst tatsaechlich "
    +"noch eine unbeschaedigte, volle Flasche.",78) );
  AddDetail( ({"flasche"}), BS(
     "Schade. Sie ist leer und hat auch schon Spruenge. Du wirst sie schnell wieder "
    +"fort.",78) );
  AddDetail( ({"spruenge"}), BS(
     "Ziemlich starke.",78) );
  AddDetail( ({"veraenderung"}), BS(
    "Also gross war die wohl nicht!",78) );
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
  AddDetail( ({"waende", "wand"}), BS(
     "Von den Waenden ist nicht mehr viel zu sehen, da sind auch nur Truemmer uebrig. "
    +"Schoene Spiegel hingen wohl mal dran, doch die liegen in Scherben auf dem "
    +"Boden. An der ehemaligen Westwand war frueher wohl mal ne Theke, Aber die ist "
    +"eigentlich nur noch zu erahnen.",78) );
  AddDetail( ({"boden"}), BS(
     "Da scheinst auf einer dicken Scherbenschicht zu stehen, die bei jedem Schritt "
    +"unter den Fuessen knirscht und knackst.",78) );
  AddDetail( ({"theke", "westwand"}), BS(
     "An der Westwand stand wohl mal eine Theke. Von der ist allerdings so gut wie "
    +"nichts mehr uebrig. Bestimmt stand da der Wirt dahinter.",78) );
  AddDetail( ({"tische", "stuehle"}), BS(
     "Alles zerstoert und zerbrochen. Nicht mehr zu gebrauchen.",78) );
  AddDetail( ({"jahre", "pech"}), BS(
     "Nun, sieben Jahre Pech pro Spiegel. Das weiss doch jeder!",78) );
  AddDetail( ({"spiegel"}), BS(
     "So wie die zerbrochen wurden, gibts bestimmt viele Jahre Pech.",78) );
  AddDetail( ({"schritt", "schritte"}), BS(
     "Sobald Du Dich bewegst.",78) );
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
  AddSmells( SENSE_DEFAULT, BS("Es riecht nach Eis, nach Blut und nach Alkohol. Hier "
    +"wurde wohl oefter mal was verschuettet.",78));
  AddSmells( ({"eis"}), "Normales Eis, keine besondere Geschmackssorte.\n");
  AddSmells( ({"blut"}), "Hier gabs offensichtlich oefters Streit.\n");
  AddSmells( ({"alkohol"}), "Wo's Alk gibt, sieht man oft froehliche Menschen :)\n");

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "sueden", CHAOS_GILDEN_ROOM("cl0w8") );
}
