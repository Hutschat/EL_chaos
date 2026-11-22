#include "gilde.h"

inherit "/std/room";

#define BS break_string
#define TP this_player()


void create()
{
  ::create();
  SetProp( P_INT_SHORT, "In einem Turm der chaotischen Burg");
  SetProp( P_INT_LONG, BS(
     "In diesem Stockwerk war bestimmt schon lange keiner mehr. Wer sich fuer Staub "
    +"interessiert dem wirds hier evtl. gefallen, denn eine maechtig dicke Staubschicht "
    +"bedeckt den gesamten Boden.",78) );

  AddDetail( "mitte", "Da ist ne Treppe.\n");
  AddDetail( ({"treppe"}), BS(
     "Die Treppe besteht aus groben Holzbohlen und fuehrt nach oben in den dunklen "
    +"Turm hinauf... und hinab ins Erdgeschoss.",78) );
  AddDetail( ({"holzbohlen", "bohlen", "holz"}), BS(
     "Die Bohlen bestehen aus dunklem, schwerem Holz. Um was fuer eine Holzart es "
    +"sich dabei handelt kannst Du nicht sagen.",78) );
  AddDetail( ({"holzart", "ahnung"}), BS(
     "Du hast keine Ahnung was fuer ne Holzart das ist!",78) );
  AddDetail( "erdgeschoss", "Dazu musst Du ein Stockwerk tiefer gehen!\n");
  AddDetail( "burg", "Das tust Du doch, da der Turm zur Burg gehoert!\n");
  AddDetail( "luft", "Abgestanden und muffig.\n");
  AddDetail( "wort", "Du untersuchst wohl jedes Wort?\n");
  AddDetail( ({"boden"}), BS(
     "Auch der Boden besteht aus den grossen schwarzen Steinbloecken, wie alles "
    +"hier. Eine dicke Staubschicht bedeckt den Boden, hier war offensichlich schon "
    +"seit laengerer Zeit keiner mehr.",78) );
  AddDetail( ({"decke"}), BS(
     "Hier wurde wirklich grosszuegig gebaut. Die Decke des Turmes - natuerlich auch "
    +"hier aus den grossen schwarzen Steinbloecken bestehend - befindet sich in "
    +"einigen Metern Hoehe ueber Dir.",78) );
  AddDetail( ({"zeit"}), BS(
     "Deine ist abgelaufen.\n",78) );
  AddDetail( ({"meter"}), BS(
     "Du weisst nicht was ein Meter ist?",78) );
  AddDetail( ({"Hoehe"}), BS(
     "Ziemlich hoch!",78) );
  AddDetail( ({"geruch", "gerueche"}), BS(
     "Gerueche kann man nicht untersuchen, aber riechen!",78) );
  AddDetail( ({"wand", "waende"}), BS(
     "Dieser Turm ist rund - wie die anderen auch - hier gibts also sozusagen "
    +"nur *eine* Wand (worauf man sich in dieser Burg nicht verlassen sollte!) "
    +"Der Turm wurde komplett mit den grossen schwarzen Steinbloecken errichtet, "
    +"deshalb bestehen auch die Waende aus ebendiesen.",78) );
  AddDetail( ({"staubschicht", "schicht"}), BS(
     "Eine dicke Schicht aus schwarzgrauem Staub.",78) );
  AddDetail( ({"staub"}), BS(
     "Der liegt anscheinend schon recht lang, geputzt wird hier sicher nicht oft. "
    +"Aber das ist ja kein Wunder, wer soll hier schon putzen? Schon mal nen Chaoten "
    +"gesehen der putzt? Womoeglich noch freiwillig? Laecherlich. Absurd!",78) );
  AddDetail( ({"spuren", "fussabdruecke"}), BS(
     "Keine zu sehen. Der Staub ist wirklich unberuehrt!",78) );
  AddDetail( ({"wunder"}), "Wunder gibt es immer wieder.\n");
  AddDetail( ({"stein", "steinbloecke", "bloecke"}), BS(
     "Die Steinbloecke, aus denen die Waende, Boden und Decke bestehen, sind gross, "
    +"schwarz und sehen aeusserst stabil aus.",78) );
  AddDetail( ({"gilde", "chaosgilde"}), BS(
     "Das tust Du gerade, denn auch dieser Turm gehoert zur Chaosgilde.",78) );
  AddDetail( ({"turm", "raeume"}), BS(
     "Also wenn Du den gesamten Turm untersuchen willst, nur zu. Aber die anderen "
    +"Raeume befinden sich in anderen Stockwerken, die solltest Du zum untersuchen "
    +"vorher auch aufsuchen, oder hast Du nen Roentgenblick und kannst durch Waende "
    +"sehen?",78) );
  AddDetail( ({"roentgenblick"}), BS(
     "Schade, Du hast wohl doch keinen.",78) );
  AddDetail( ({"stockwerke"}), BS(
     "Du kannst *dieses* Stockwerk untersuchen, indem Du Dich einfach gut umsiehst. "
    +"In die anderen Stockwerke musst Du Dich schon erst mal begeben, vorher laeuft "
    +"da sonst nix mit untersuchen, oder haste nen Roentgenblick und kannst durch "
    +"die Waende sehen?",78) );
  AddDetail( ({"stock", "stockwerk"}), BS(
     "Dies ist der 1. Stock dieses Turmes. Schau Dich einfach mal um!",78) );
  AddDetail( ({"zufall", "auffall"}), "Der Zufall ist das Gegenteil vom Auffall.\n");
  AddDetail( "gegenteil", "Grad andersrum halt.\n");
  AddDetail( "grad", "Du nervst!\n");
  AddDetail( "chaoten", "Tritt in die Gilde ein, so untersuchst Du am besten! :)\n");

  AddSounds( SENSE_DEFAULT, BS(
     "Ganz, ganz leise meinst Du ein Stoehnen und Jammern zu vernehmen. Aber sicher "
    +"bist Du Dir da nicht.",78) );
  AddSounds( ({"stoehnen", "jammern", "geraeusche"}), BS(
     "Irgendwer oder irgendwas muss die Geraeusche ja produzieren, oder? Vielleicht "
    +"schaust Du einfach mal nach?",78) );

  AddSmells( SENSE_DEFAULT, BS(
     "Hier riechts muffig und abgestanden. Gelueftet wird hier wohl nur einmal pro "
    +"Jahrhundert. Ein widerlich suesslicher Geruch liegt ausserdem noch in der "
    +"Luft!",78) );
  AddSmells( ({"geruch"}), BS(
     "Diesen Geruch kennst Du! Hier riechts ziemlich nach Blut und Verwesung.",78) );
  AddSmells( ({"blut", "verwesung"}), BS(
     "Da hier keine Ursache zu finden ist, scheint der Geruch von oben zu kommen.",78) );

  SetProp( P_LIGHT, 0);
  SetProp( P_INDOORS, 1);

  AddExit( "oben", CHAOS_GILDEN_ROOM("cl2tu3_3") );
  AddExit( "unten", CHAOS_GILDEN_ROOM("cl2tu3_1") );
}
