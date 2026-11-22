#include "gilde.h"

inherit "/std/room";

#define BS break_string
#define TP this_player()


void create()
{
  ::create();
  SetProp( P_INT_SHORT, "In einem Turm der chaotischen Burg");
  SetProp( P_INT_LONG, BS(
     "Abgestandene, muffige Luft schlaegt Dir entgegen. Hier im Erdgeschoss dieses "
    +"Turmes ist nichts Besonderes zu sehen, der Turm ist wie die anderen aus den "
    +"selben grossen schwarzen Steinbloecken erbaut worden. In der Mitte des Turms "
    +"fuehrt eine Treppe aus uralten Holzbohlen in die oberen Stockwerke.",78) );

  AddDetail( "mitte", "Da ist ne Treppe.\n");
  AddDetail( ({"treppe"}), BS(
     "Die Treppe besteht aus groben Holzbohlen und fuehrt nach oben in den dunklen "
    +"Turm hinauf...",78) );
  AddDetail( ({"holzbohlen", "bohlen", "holz"}), BS(
     "Die Bohlen bestehen aus dunklem, schwerem Holz. Um was fuer eine Holzart es "
    +"sich dabei handelt kannst Du nicht sagen.",78) );
  AddDetail( ({"holzart", "ahnung"}), BS(
     "Du hast keine Ahnung was fuer ne Holzart das ist!",78) );
  AddDetail( "burg", "Das tust Du doch, da der Turm zur Burg gehoert!\n");
  AddDetail( "luft", "Abgestanden und muffig.\n");
  AddDetail( "wort", "Du untersuchst wohl jedes Wort?\n");
  AddDetail( ({"boden"}), BS(
     "Auch der Boden besteht aus den grossen schwarzen Steinbloecken, wie alles "
    +"hier. Staub bedeckt den Boden, das heisst aber nicht dass hier keiner "
    +"reinkommt. Mehrere (aeltere?) Spuren im Staub deuten darauf hin, dass hier "
    +"ab und an \"Leute\" vorbeikommen!",78) );
  AddDetail( ({"decke"}), BS(
     "Hier wurde wirklich grosszuegig gebaut. Die Decke des Turmes - natuerlich auch "
    +"hier aus den grossen schwarzen Steinbloecken bestehend - befindet sich in "
    +"einigen Metern Hoehe ueber Dir.",78) );
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
    +"deshalb bestehen auch die Waende daraus.",78) );
  AddDetail( ({"staub"}), BS(
     "Der liegt anscheinend schon recht lang, geputzt wird hier sicher nicht oft. "
    +"Aber das ist ja kein Wunder, wer soll hier schon putzen? Schon mal nen Chaoten "
    +"gesehen der putzt? Womoeglich noch freiwillig? Laecherlich. Absurd!",78) );
  AddDetail( ({"spuren", "fussabdruecke"}), BS(
     "Im Staub sind mehr oder minder alte Spuren zu erkennen. Nicht alle sind "
    +"humanoiden Ursprungs, einige davon sehen eigentlich gar nicht wie Fussabdruecke "
    +"aus, da scheinen sich Schlangen oder Spinnen herumgetrieben zu haben. Na kein "
    +"Wunder, wenn man bedenkt wies hier aussieht!!!",78) );
  AddDetail( ({"ursprung", "rasse"}), "Viele Rassen sind humanoiden Ursprungs!\n");
  AddDetail( ({"wunder"}), "Wunder gibt es immer wieder.\n");
  AddDetail( ({"schlangen", "spinnen"}), "Im Moment siehst Du keine. Glueck gehabt!\n");
  AddDetail( ({"moment"}), "Der ist schon vorbei.\n");
  AddDetail( ({"glueck"}), "Anderes Wort fuer \"positiver Zufall\".\n");
  AddDetail( ({"leute"}), BS(
     "Naja aeh... irgendwer wars halt. Und das Wort Leute ist halt recht allgemein, "
    +"das schliesst dann nicht nur Menschen sondern auch Elfen, Zwerge, Hobbits, "
    +"Felinen, Trolle, Goblins, Daemonen, Orks und alles andere Gesocks mit ein!",78) );
  AddDetail( ({"menschen", "elfen", "zwerge", "hobbits", "felinen", "trolle", "goblins",
    "daemonen", "orks"}), BS(
     "Denen bist Du bestimmt schon begegnet. Leute wie Du und ich halt :) ",78) );
  AddDetail( "gesocks", "Sowas wie Du!?\n");
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
  AddDetail( ({"erdgeschoss", "stock", "stockwerk"}), BS(
     "Dies ist der unterste Stock dieses Turmes. Schau Dich einfach mal um!",78) );
  AddDetail( ({"zufall", "auffall"}), "Der Zufall ist das Gegenteil vom Auffall.\n");
  AddDetail( "gegenteil", "Grad andersrum halt.\n");
  AddDetail( "grad", "Du nervst!\n");
  AddDetail( "chaoten", "Tritt in die Gilde ein, so untersuchst Du am besten! :)\n");

  AddSounds( SENSE_DEFAULT, BS(
     "Also irgendwas hoerst Du. Es scheint von oben zu kommen, aber einordnen kannst "
    +"Du die Geraeusche nicht.",78) );
  AddSounds( ({"geraeusche"}), BS(
     "Du kannst noch nicht sagen, was fuer Geraeusche das sind oder wer oder was "
    +"dafuer verantwortlich ist!",78) );

  AddSmells( SENSE_DEFAULT, BS(
     "Hier riechts muffig und abgestanden. Gelueftet wird hier wohl nur einmal pro "
    +"Jahrhundert. Du bemerkst ausserdem einen leicht suesslichen Geruch.",78) );
  AddSmells( ({"geruch"}), BS(
     "Diesen Geruch kennst Du! Hier riechts nach Blut und Verwesung.",78) );
  AddSmells( ({"blut", "verwesung"}), BS(
     "Da hier keine Ursache zu finden ist, scheint der Geruch von oben zu kommen.",78) );

  SetProp( P_LIGHT, 0);
  SetProp( P_INDOORS, 1);

  AddExit( "oben", CHAOS_GILDEN_ROOM("cl2tu3_2") );
  NewDoor("sueden",CHAOS_GILDEN_ROOM("cl2bu9"),({"tuer"}),
  ({D_NAME,"Tuer",
    D_GENDER,2,
    D_SHORT,"Eine %se Tuer fuehrt aus den Turm.",
    D_LONG,BS("Diese wunderbar schlichte, absolut schwarze Tuer fuehrt "+
    "nach draussen."),
    D_FLAGS, DOOR_CLOSED | DOOR_RESET_CL
  }));

}
