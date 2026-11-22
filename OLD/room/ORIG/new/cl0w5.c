                         
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
  SetProp( P_INT_SHORT, "In einer Ruine inmitten der Eiswueste");
  SetProp( P_INT_LONG, BS(
     "Hier war frueher wohl eine kleine Kammer. Nichts besonderes, der Raum sah "
    +"bestimmt auch damals schon recht unscheinbar aus. Jetzt liegen hier ueberall "
    +"Truemmer herum. Im Osten liegen bzw. lagen mit Sicherheit die interessanteren "
    +"Raeume dieses Gemaeuers.",78,0,1) );

  AddDetail( ({"boden"}), BS(
     "Der Boden war mal kahl und leer, jetzt ist er von Truemmern und Schnee "
    +"bedeckt.",78) );
  AddDetail( ({"nichts"}), BS(
    "Du untersuchst das Nichts, und erkennst... ....NICHTS!",78) );
  AddDetail( ({"wand", "waende"}), BS(
    "Die Truemmer davon liegen ueberall auf dem Boden herum.",78) );
  AddDetail( ({"meinung"}), BS(
    "Deine Meinung interessiert niemand!",78) );
  AddDetail( ({"sicherheit"}), BS(
    "Oder bist Du anderer Meinung?",78) );
  AddDetail( ({"raum"}), BS(
    "Schau Dich einfach um!",78) );
  AddDetail( ({"kammer"}), BS(
    "Welchen Zweck sie wohl erfuellte?",78) );
  AddDetail( ({"zweck"}), BS(
    "Es gibt immer einen Zweck. Oder?",78) );
  AddDetail( ({"gebaeude", "gemaeuer", "raeume", "dingens"}), BS(
    "Gebaeude, Gemaeuer, Raeume... das Dingens in dem Du stehst ist gemeint!",78) );
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
     "Wenn kein Woelkchen am Himmel ist, kannst Du auch kein Woelkchen "
    +"untersuchen!",78) );
  AddDetail( ({"reste", "rest"}), BS(
    "Damit sind die Truemmer und Bruchstuecke gemeint.",78) );
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
  AddSmells( SENSE_DEFAULT, BS("So sehr Du schnueffelst, Du siehst hier nichts "
    +"Besonderes.",78));

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "osten", CHAOS_GILDEN_ROOM("cl0w4") );
}
