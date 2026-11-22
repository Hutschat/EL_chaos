#include "gilde.h"

inherit "/std/room";

#define BS break_string
#define TP this_player()


void create()
{
  ::create();
  SetProp( P_INT_SHORT, "In einem Turm der chaotischen Burg");
  SetProp( P_INT_LONG, BS(
     "Also hier siehts ja heiter aus. Ueberall liegen Knochen herum, ja ganze "
    +"Knochenhaufen, von der Staubschicht, die bekanntlich den Boden bedeckt, ist fast "
    +"nix zu sehen. An den Ketten haengen Teile von Skeletten, offenbar ehemalige "
    +"Gefangene der Chaoten,  die hier ihren Lebensabend verbringen durften...",78) );

  AddDetail( "lebensabend", "Die Rente halt...\n");
  AddDetail( "rente", "Frag mal Tyrion wenn Du ihn siehst...\n");
  AddDetail( "tyrion", "Ich sagte WENN DU IHN SIEHST !!!\n");
  AddDetail( "sherlock holmes", "Bist Du nicht evtl. im falschen Mud?\n");
  AddDetail( ({"teile", "skelette"}), BS(
     "Naja die wenigsten der Skelette sind noch ganz. Es handelt sich nur noch um "
    +"einige zusammenhaengende Teile...",78) );
  AddDetail( ({"flecken", "blutflecken", "blut", "farben"}), BS(
     "Blutflecken sind ueberall zu finden, aber die sind alle schon laengst "
    +"vertrocknet, der Tod des letzten Gefangenen hier scheint schon etwas laenger "
    +"her zu sein.",78) );
  AddDetail( ({"knochenhaufen", "knochen", "gebeine"}), BS(
     "Auf dem gesamten Boden haeufen sich die Knochen verschiedener Lebewesen. "
    +"An einigen Gebeinen klebt noch vertrocknetes, altes Blut...",78) );
  AddDetail( "lebewesen", BS(
     "Lebewesen sind Wesen, die leben. Hmm was ist dann mit Daemonen, Zombies usw.? "
    +"Sind das nun Lebewesen oder nicht? Fragen ueber Fragen!",78) );
  AddDetail( "fragen", "Hast Du denn welche?\n");
  AddDetail( ({"wesen", "daemonen", "zombies"}), BS(
     "Lass mich doch mal philosophieren, untersuch nicht immer gleich alles!",78) );
  AddDetail( "tod", "Noch lebst Du!\n");
  AddDetail( ({"ringe", "schellen", "ketten", "handschellen", "fussschellen"}),
     "Gefertigt aus stabilem Eisen.\n");
  AddDetail( "eisen", "Das wurde offenbar magisch gehaertet, es ist unzerstoerbar.\n");
  AddDetail( "gefangene", "Hier gibts schon lange keine mehr. Oder?\n");
  AddDetail( "mitte", "Da ist ne Treppe.\n");
  AddDetail( ({"treppe"}), BS(
     "Die Treppe besteht aus groben Holzbohlen und fuehrt nach oben in den dunklen "
    +"Turm hinauf... oder hinunter Richtung Erdgeschoss.",78) );
  AddDetail( "erdgeschoss", "Dazu musst Du runtergehen!\n");
  AddDetail( ({"holzbohlen", "bohlen", "holz"}), BS(
     "Die Bohlen bestehen aus dunklem, schwerem Holz. Um was fuer eine Holzart es "
    +"sich dabei handelt kannst Du nicht sagen.",78) );
  AddDetail( ({"holzart", "ahnung"}), BS(
     "Du hast keine Ahnung was fuer ne Holzart das ist!",78) );
  AddDetail( "burg", "Das tust Du doch, da der Turm zur Burg gehoert!\n");
  AddDetail( "luft", "Abgestanden und muffig.\n");
  AddDetail( "wort", "Du untersuchst wohl jedes Wort?\n");
  AddDetail( ({"boden"}), BS(
     "Der Boden besteht wohl aus den grossen schwarzen Steinbloecken, wie der gesamte "
    +"Turm. Das kannst Du aber eigentlich nur vermuten, die herumliegenden Knochen "
    +"und der darunterliegende Staub verhindern da eine genaue Untersuchung.",78) );
  AddDetail( "untersuchung", BS(
     "Das untersuchen der Untersuchung, die Du gerade untersuchst, zeigt Dir nur, dass "
    +"Du besser etwas sinnvolleres untersuchen solltest, weil Du nichts untersuchen "
    +"kannst, was Du mittels dieser Untersuchung eigentlich untersuchen willst. "
    +"Das war doch jetzt klar verstaendlich, oder willst Du das auch nochmals "
    +"untersuchen?",78) );
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
    +"deshalb bestehen auch die Waende aus ebendiesen. An der gesamten Innenwand sind "
    +"stabile Ringe aus Eisen eingelassen, an denen Ketten mit Hand- und Fuss-Schellen "
    +"befinden.",78) );
  AddDetail( "innenwand", "Das ist die Wand die Du siehst, wenn Du IM Turm bist! :)\n");
  AddDetail( ({"staubschicht", "schicht"}), BS(
     "Eine Schicht aus schwarzgrauem Staub.",78) );
  AddDetail( ({"staub"}), BS(
     "Der Staub unter den Knochen liegt anscheinend auch schon etwas laenger, aber "
    +"wie gesagt, hier putzt ja keiner, also braucht man sich da nicht zu wundern. "
    +"Typisch Chaos, oder?",78) );
  AddDetail( "chaos", "Chaos rulez!!!\n");
  AddDetail( ({"spuren", "fussabdruecke"}), BS(
     "Bist Du Sherlock Holmes oder was? Wo ist hier die Rede von Fussabdruecken oder "
    +"Spuren???",78) );
  AddDetail( "rede", "Hier redet keiner. Oder?\n");
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
  AddDetail( "richtung", "Welche denn?\n");
  AddDetail( ({"stock", "stockwerk"}), BS(
     "Dies ist der 3. Stock dieses Turmes. Schau Dich einfach mal um!",78) );
  AddDetail( ({"zufall", "auffall"}), "Der Zufall ist das Gegenteil vom Auffall.\n");
  AddDetail( "gegenteil", "Grad andersrum halt.\n");
  AddDetail( "grad", "Du nervst!\n");
  AddDetail( "chaoten", "Tritt in die Gilde ein, so untersuchst Du am besten! :)\n");
  AddDetail( "raum", "Gib mal \"schau\" ein!\n");

  AddSounds( SENSE_DEFAULT, BS(
     "Die Knochenberge scheinen zu knistern und zu knacken, sehr leise zwar aber doch "
    +"hoerbar. Wenn Du genau lauschst, meinst Du ausserdem ein Stoehnen zu hoeren, "
    +"jedoch woher soll das kommen? Du kannst die Richtung nicht bestimmen...",78) );
  AddSounds( ({"stoehnen", "jammern", "geraeusche", "knacken"}), BS(
     "Irgendwer oder irgendwas muss die Geraeusche ja produzieren, oder? Vielleicht "
    +"hilft hier genaueres Umschauen weiter?",78) );

  AddSmells( SENSE_DEFAULT, BS(
     "Hier riechts muffig und abgestanden. Gelueftet wird hier wohl nur einmal pro "
    +"Jahrhundert. Nach frisch Verstorbenen riechts hier nicht, aber so sehen die "
    +"Ueberreste der ehemaligen Gefangenen hier auch nicht aus.",78) );
  AddSmells( ({"geruch"}), BS(
     "Staubig, muffig, abgestanden.",78) );
  AddSmells( ({"blut", "verwesung"}), BS(
     "Wenn Du ueberhaupt sowas riechst, so kommts wohl aus den unteren "
    +"Stockwerken!",78) );

  SetProp( P_LIGHT, 0);
  SetProp( P_INDOORS, 1);

  AddExit( "oben", CHAOS_GILDEN_ROOM("cl2tu3_5") );
  AddExit( "unten", CHAOS_GILDEN_ROOM("cl2tu3_3") );
}
