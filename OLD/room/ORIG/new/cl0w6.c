                         
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
  SetProp( P_INT_LONG, 
     "Du befindest Dich in einer grossen Halle. Bzw. in den Resten davon.\n"
    +"Schnee bedeckt eine Unmenge von Truemmern. Aus dem Schutt ragen verbogene Kron-\n"
    +"leuchter hervor, Bruchstuecke schwarzer Kerzen liegen ueberall. Ein grosses\n"
    +"Portal fuehrte frueher einmal nach Sueden in die toedliche Eiswueste, aber\n"
    +"auch das liegt zu Deinen Fuessen, wie der ganze andere Krempel.\n");

  AddDetail( ({"kronleuchter", "leuchter"}), BS(
     "Die Kronleuchter hingen bestimmt an der Decke. Es handelt sich um die Ueberreste "
    +"von riesigen Gestellen mit hunderten von duennen, meterlangen Armen, an deren "
    +"Enden sich je eine schwarze Kerze befand. Sie machen auch jetzt noch den "
    +"Eindruck von Spinnen. Du versuchst Dir vorzustellen, wie das damals ausgesehen "
    +"haben mag. Bestimmt Grauenvoll!!!",78) );
  AddDetail( ({"spinnen", "spinne"}), BS(
     "Du siehst keine. Jofseidank!",78) );
  AddDetail( ({"arme"}), BS(
     "Hunderte von duennen, meterlangen Armen erinnern an Spinnen.",78) );
  AddDetail( ({"gestelle"}), BS(
     "Die Gestelle der Kronleuchter sind total verbogen und damit unbrauchbar.",78) );
  AddDetail( ({"eindruck"}), BS(
     "Keine Angst! :)",78) );
  AddDetail( ({"angst"}), BS(
     "Hast Du denn welche?",78) );
  AddDetail( ({"unmenge"}), BS(
     "Soviele Truemmer wie hier rumliegen, es muss hier ein 1. Stockwerk gegeben "
    +"haben, von dem allerdings nichts mehr uebrig blieb.",78) );
  AddDetail( ({"stockwerk", "teile", "stock"}), BS(
     "Bestimmt sind das deshalb hier soviele Truemmer, weil Teile des oberen Stocks "
    +"hier herumliegen...",78) );
  AddDetail( ({"schutt"}), BS(
     "Hier und da ragen einige verbogene Kronleuchter aus dem Schutt, der restliche "
    +"Krempel lohnt keine Untersuchung.",78) );
  AddDetail( ({"untersuchung"}), BS(
     "Die fuehrst Du doch gerade durch, oder?",78) );
  AddDetail( ({"portal", "tuer", "tor"}), BS(
     "Dieses grosse Portal fuehrte direkt in die toedliche Eiswueste. Jetzt liegt es "
    +"auf dem Boden und wird wohl bald unter ewigem Eis verschwunden sein...",78) );
  AddDetail( ({"ueberreste"}), BS(
     "Es sind wirklich nur noch Ueberreste. Da gibts nix zu finden!",78) );
  AddDetail( ({"fliesen"}), BS(
     "Schwarze und rote Fliesen bedeckten frueher den Boden.",78) );
  AddDetail( ({"kerzen"}), BS(
     "Es handelte sich um schwarze, unheimliche Kerzen.",78) );
  AddDetail( ({"zeugs"}), BS(
     "Du findest nichts brauchbares.",78) );
  AddDetail( ({"krempel"}), BS(
     "Oder wie wuerdest Du das Zeugs nennen, das hier ueberall rumliegt?",78) );
  AddDetail( ({"farbe"}), BS(
     "Die vorherrschende Farbe war schwarz. Nur manche Fliesen waren rot.",78) );
  AddDetail( ({"boden"}), BS(
     "Truemmer und Schnee bedecken den Boden, aber Du kannst trotzdem die Ueberreste "
    +"schwarzer und roter Fliesen erkennen, die auch jetzt noch immer ihre Farbe "
    +"wechseln und so staendig neue Muster bilden.",78) );
  AddDetail( ({"muster"}), BS(
     "Die Muster sind leider nicht mehr zu erkennen.",78) );
  AddDetail( ({"nichts"}), BS(
    "Du untersuchst das Nichts, und erkennst... ....NICHTS!",78) );
  AddDetail( ({"wand", "waende"}), BS(
    "Die Truemmer davon liegen ueberall auf dem Boden herum.",78) );
  AddDetail( ({"raum"}), BS(
    "Schau Dich einfach um!",78) );
  AddDetail( ({"halle"}), BS(
    "Sie war wohl ziemlich gross. Welchen Zweck sie wohl erfuellte?",78) );
  AddDetail( ({"zweck"}), BS(
    "Es gibt immer einen Zweck. Oder?",78) );
  AddDetail( ({"gebaeude", "gemaeuer", "raeume", "dingens"}), BS(
    "Gebaeude, Gemaeuer, Raeume... das Dingens in dem Du stehst ist gemeint!",78) );
  AddDetail( ({"ueberall"}), BS(
    "Wo Du hinsiehst halt.",78) );
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
  AddSmells( SENSE_DEFAULT, BS("Der Geruch, der in der Luft liegt, ist nicht naeher "
    +"definierbar. Du bist Dir sicher, so etwas aehnliches noch nie gerochen zu "
    +"haben.",78));

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "norden", CHAOS_GILDEN_ROOM("cl0w4") );      // zu ex-wuqour
  AddExit( "westen", CHAOS_GILDEN_ROOM("cl0w7") );      // zu ex-kruuolq/hutschat
  AddExit( "osten", CHAOS_GILDEN_ROOM("cl0w8") );       // zu ext-achtarch
  AddExit( "sueden", CHAOS_GILDEN_ROOM("cl0w11") );     // "cl0w11" entspricht "ceingang"
}
