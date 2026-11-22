#include "gilde.h"

inherit "/std/room";

#define BS break_string
#define TP this_player()


void create()
{
  ::create();
  SetProp( P_INT_SHORT, "In einem Turm der chaotischen Burg");
  SetProp( P_INT_LONG, BS(
     "Eigentlich waers hier relativ langweilig, ein Raum wie der darunter... aber die "
    +"Staubschicht ist hier nicht ganz so dick, und an der Wand sind mehrere Ketten "
    +"mit Hand- und Fuss-Schellen angebracht. Knochen und vertrocknetes Blut zeugen von "
    +"verblichenen Opfern bzw. Gefangenen. Wer hier angekettet ist, hat bestimmt nix "
    +"mehr zu lachen...",78) );

  AddDetail( ({"flecken", "blutflecken", "blut", "farben"}), BS(
     "An einigen Stellen im Staub, in verdaechtiger Naehe der herumliegenden Knochen, "
    +"kannst Du breite, dicke Blutflecken erkennen, die sich mit dem Staub vermengt "
    +"haben. Es gibt frische Flecken und uralte, vertrocknete.",78) );
  AddDetail( ({"knochenhaufen", "knochen", "gebeine"}), BS(
     "In der Naehe der Ketten befinden sich mehrere Knochenhaufen und Blutflecken, "
    +"es sieht nicht so aus als ob die Wesen hier einen angenehmen Tod "
    +"hatten",78) );
  AddDetail( "opfer", BS(
     "Die Gefangenen, die hier mehr oder minder schuldig angekettet waren.",78) );
  AddDetail( "tod", "Noch lebst Du!\n");
  AddDetail( ({"ringe", "schellen", "ketten", "handschellen", "fussschellen"}),
     "Gefertigt aus stabilem Eisen.\n");
  AddDetail( "eisen", "Das wurde offenbar magisch gehaertet, es ist unzerstoerbar.\n");
  AddDetail( "gefangene", "Wenn Du keine siehst werden keine da sein. Oder?\n");
  AddDetail( ({"naehe", "stellen"}), "Unterhalb der Ketten aufm Boden.\n");
  AddDetail( "richtung", "Es geht nach oben und nach unten.\n");
  AddDetail( "erdgeschoss", "Das Erdgeschoss liegt einiges tiefer.\n");
  AddDetail( "mitte", "Da ist ne Treppe.\n");
  AddDetail( ({"treppe"}), BS(
     "Die Treppe besteht aus groben Holzbohlen und fuehrt nach oben in den dunklen "
    +"Turm hinauf... oder hinunter Richtung Erdgeschoss.",78) );
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
    +"hier. Eine Staubschicht bedeckt den Boden, aber ziemlich viele Spuren deuten "
    +"darauf hin dass hier immer wieder mal jemand vorbeikommt.",78) );
  AddDetail( ({"decke"}), BS(
     "Hier wurde wirklich grosszuegig gebaut. Die Decke des Turmes - natuerlich auch "
    +"hier aus den grossen schwarzen Steinbloecken bestehend - befindet sich in "
    +"einigen Metern Hoehe ueber Dir.",78) );
  AddDetail( ({"jemand"}), BS(
     "So einer wie Du z.B. !",78) );
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
    +"deshalb bestehen auch die Waende aus ebendiesen. An der gesamten Innenwand sind "
    +"stabile Ringe aus Eisen eingelassen, an denen Ketten mit Hand- und Fuss-Schellen "
    +"befinden.",78) );
  AddDetail( ({"innenwand"}), BS(
     "Das ist der Teil der Wand, den Du siehst. :)",78) );
  AddDetail( ({"teil"}), BS(
     "Du siehst stabile Ringe aus Eisen sowie Kettem mit Hand- und Fuss-Schellen.",78) );
  AddDetail( ({"staubschicht", "schicht"}), BS(
     "Eine Schicht aus schwarzgrauem Staub.",78) );
  AddDetail( ({"staub"}), BS(
     "Der liegt anscheinend schon recht lang, geputzt wird hier sicher nicht oft. "
    +"Aber das ist ja kein Wunder, wer soll hier schon putzen? Schon mal nen Chaoten "
    +"gesehen der putzt? Womoeglich noch freiwillig? Laecherlich. Absurd!",78) );
  AddDetail( ({"spuren", "fussabdruecke"}), BS(
     "Tja, Spuren werden das schon sein, aber so durcheinander dass Du da wirklich "
    +"nichts genaueres erkennen kannst.",78) );
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
     "Dies ist der 2. Stock dieses Turmes. Schau Dich einfach mal um!",78) );
  AddDetail( ({"zufall", "auffall"}), "Der Zufall ist das Gegenteil vom Auffall.\n");
  AddDetail( "gegenteil", "Grad andersrum halt.\n");
  AddDetail( "grad", "Du nervst!\n");
  AddDetail( "chaoten", "Tritt in die Gilde ein, so untersuchst Du am besten! :)\n");
  AddDetail( "raum", "Gib mal \"schau\" ein!\n");

  AddSounds( SENSE_DEFAULT, BS(
     "Aus den oberen Stockwerken kannst Du jetzt deutlich ein Stoehnen hoeren, "
    +"ausserdem schabende und knackende Geraeusche!?",78) );
  AddSounds( ({"stoehnen", "jammern", "geraeusche"}), BS(
     "Irgendwer oder irgendwas muss die Geraeusche ja produzieren, oder? Vielleicht "
    +"schaust Du einfach mal nach?",78) );

  AddSmells( SENSE_DEFAULT, BS(
     "Hier riechts muffig und abgestanden. Gelueftet wird hier wohl nur einmal pro "
    +"Jahrhundert. Der ekelhaft suessliche Geruch frisch Verstorbener liegt hier "
    +"in der Luft!",78) );
  AddSmells( ({"geruch"}), BS(
     "Diesen Geruch kennst Du! Hier riechts ziemlich nach Blut und Verwesung.",78) );
  AddSmells( ({"blut", "verwesung"}), BS(
     "Schau Dich um, dann wirst Du den Grund schon finden!",78) );

  SetProp( P_LIGHT, 0);
  SetProp( P_INDOORS, 1);

  AddExit( "oben", CHAOS_GILDEN_ROOM("cl2tu3_4") );
  AddExit( "unten", CHAOS_GILDEN_ROOM("cl2tu3_2") );
}
