                         
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
  SetProp( P_INT_SHORT, "Vor einer Ruine inmitten der Eiswueste");
  SetProp( P_INT_LONG, BS(
     "Du stehst vor den von Eis und Schnee bedeckten Truemmern einer ehemaligen "
    +"Festung. Kein Stein steht auf dem anderen, kein Raum blieb verschont. Hier "
    +"findest Du bestimmt keine Lebewesen. Es ist schon verwunderlich, dass jemand "
    +"so irrsinnig war, an einem so unwirtlichen Ort ein Gebaeude zu errichten. Das "
    +"waren bestimmt Spinner! Naja in absehbarer Zeit wird die Eiswueste sich diesen "
    +"Flecken wohl zurueckgeholt haben, dann siehts hier aus wie in der restlichen "
    +"Eiswueste, die sich suedlich von Dir erstreckt: weiss, kalt und "
    +"trostlos.",78,0,1) );

  AddDetail( ({"raum", "raeume"}), BS(
     "Die Festung hatte viele Raeume. Du kannst Dich ja mal in der Ruine umsehen!",78) );
  AddDetail( ({"zeit"}), BS(
     "Du hast genug davon. Sonst koenntest Du sie nicht untersuchen.",78) );
  AddDetail( ({"ueberall"}), BS(
     "Ueberall. Also dort! Und dort! Und dort drueben. Aber auch hier. Oder?",78) );
  AddDetail( ({"stein", "steine"}), BS(
     "Grobe Steine, die irgendwie unheimlich wirken.",78) );
  AddDetail( ({"schutt"}), BS(
     "Alles was da rumliegt eben.",78) );
  AddDetail( ({"lebewesen", "bewohner"}), BS(
     "Kein Bewohner der ehemaligen Festung zu sehen.",78) );
  AddDetail( ({"herz"}), BS(
     "Willst Dus rausreissen, um es zu untersuchen?",78) );
  AddDetail( ({"anblick"}), BS(
     "Er laesst Dein Herz hoeher schlagen.",78) );
  AddDetail( ({"labyrinth"}), BS(
     "Das Labyrinth der Eiswueste liegt im Sueden.",78) );
  AddDetail( ({"mut"}), BS(
     "Du hast doch Mut?",78) );
  AddDetail( ({"zeug"}), BS(
     "Zeug halt.",78) );
  AddDetail( ({"eis", "schnee"}), BS(
     "Kaltes, weisses Zeug. Stimmt was nicht damit?",78) );
  AddDetail( ({"inneres"}), BS(
     "Geh doch rein! Betrete die Ruine! Nur Mut!",78) );
  AddDetail( ({"wand", "waende"}), BS(
     "Was fuer Waende? Es stehen nur noch die Grundmauern der Festung!",78) );
  AddDetail( ({"decke", "himmel", "polarhimmel"}), BS(
     "Du starrst in den kalten, reinen Polarhimmel. Was fuer ein Anblick!",78) );
  AddDetail( ({"pfad", "schneepfad", "eispfad", "trampelpfad"}), BS(
     "Du stehst auf einem verschneiten Trampelpfad im ewigen Eis. Im Sueden ist die "
    +"Eiswueste, Noerdlich die Ruine, die Du besichtigen kannst.",78) );
  AddDetail( ({"menge"}), BS(
     "Echt viel.",78) );
  AddDetail( ({"truemmerhaufen", "zeugs"}), BS(
     "Das ganze eingestuerzte bzw. zerstoerte Zeugs der Festung, Waende und Decke "
    +"inklusive, bilden eine Menge Schutt und Truemmer. Das liegt alles hier "
    +"rum.",78) );
  AddDetail( ({"mauern", "grundmauern"}), BS(
     "Von den Mauern der Festung ist nicht viel uebriggeblieben, nur die Grundmauern "
    +"existieren noch. Der Rest liegt als Schutt und Truemmerhaufen auf dem Boden "
    +"herum.",78) );
  AddDetail( ({"portal", "tor"}), BS(
     "Ein maechtiges Portal liegt inmitten der Truemmer. Durch dieses Tor musste man "
    +"frueher anscheinend die Festung betreten. Jetzt ist es nur noch eine Ruine und "
    +"jeder kann durchlaufen, es stehen ja nur noch die Grundmauern.",78) );
  AddDetail( ({"schicht", "schneeschicht", "eisschicht"}), BS(
     "Eine dicke Schicht aus Eis und Schnee bedeckt die Truemmer der Ruine und schickt "
    +"sich an, diesen Ort fuer die Eiswueste zurueckzuerobern.",78) );
  AddDetail( ({"blick"}), BS(
     "Sehr scharfsinnig bist Du nicht, auch so ein zweiter Blick bringt Dich nicht "
    +"weiter.",78) );
  AddDetail( ({"wueste", "eiswueste", "schneewueste"}), BS(
     "Das Labyrinth der Eiswueste breitet sich suedlich von Dir aus. Der Weg ist "
    +"gefaehrlich... und kalt :)",78) );
  AddDetail( ({"bau"}), BS(
     "Die Festung muss hier lange Zeit gestanden haben, der Bau ist schon ewig "
    +"her.",78) );
  AddDetail( ({"stein"}), BS(
     "Die groben Steine die fuer den Bau dieser Festung verwendet wurden, strahlen "
    +"etwas unheimliches aus...",78) );
  AddDetail( ({"truemmer"}), BS(
     "Ueberall liegen die Truemmer der Ruine herum, kein Stein steht mehr auf dem "
    +"anderen, und irgendwohin muss der Schutt ja, oder? :) Also liegt er da halt auf "
    +"dem Boden rum. Eine dicke Schneeschicht verdeckt schon einiges.",78) );
  AddDetail( ({"sprichwort", "sprichwoerter"}), BS(
     "Sprichwoerter gibts viele. Denk nach, dann fallen Dir sicher selbst ein paar "
    +"ein!",78) );
  AddDetail( ({"daecher"}), BS(
     "Die duerften irgendwo unter den Truemmern liegen.",78) );
  AddDetail( ({"tuerme"}), BS(
     "Hohe spitze Tuerme mit noch spitzeren Daechern.",78) );
  AddDetail( ({"hechtsuppe"}), BS(
     "Nur ein Sprichwort.",78) );
  AddDetail( ({"flecken", "ort"}), BS(
     "Bald werden Eis und Schnee diesen Ort hier ueberdecken.",78) );
  AddDetail( ({"fenster"}), BS(
     "Da war bestimmt nicht mal Glas drin. Es muss gezogen haben wie Hechtsuppe.",78) );
  AddDetail( ({"glas", "fensterglas"}), BS(
     "Das Glas in Fenstern nennt man Fensterglas.",78) );
  AddDetail( ({"spinner", "bekloppte", "irrsinnige"}), BS(
     "Die Bekloppten die dieses Gemaeuer errichtet haben, gibts entweder nicht mehr "
    +"oder sie sind umgezogen. Was auch immer zutrifft: Das konnte ja wohl nur besser "
    +"werden, nicht!?",78) );
  AddDetail( ({"boden"}), BS(
     "Du stehst auf einem festgetrampelten Schnee- und Eispfad. Direkt vor Dir kannst "
    +"Du auch einen Blick auf den Boden innerhalb der Ruine werfen: Truemmer wohin Du "
    +"sehen kannst. Ein maechtiges Portal, das man hier frueher wohl durchschreiten "
    +"musste, liegt auf dem Boden.",78) );
  AddDetail( ({"festung", "gebaeude", "gemaeuer", "ruine"}), BS(
     "Wie die Festung mal ausgesehen haben mag, kannst Du anhang der Truemmer nur "
    +"vermuten. Es waren bestimmt schroffe Mauern und hohe Tuerme mit winzigen "
    +"Fenstern. Direkt vor Dir war wohl ein Portal, das ins Innere fuehrte. Jetzt "
    +"es mitsamt dem restlichen Schutt auf dem Boden.",78) );

  AddSounds( SENSE_DEFAULT, BS("Der Wind heult und pfeift durch die Ruinen.",78));
  AddSmells( SENSE_DEFAULT, BS("Es riecht nach.... ....Eis!",78));
  AddSmells( ({"eis"}), "Normales Eis, keine besondere Geschmackssorte.\n");

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "norden", CHAOS_GILDEN_ROOM("cl0w6") );
  AddExit( "sueden", CHAOS_GILDEN_ROOM("cl0w11") );
                     // /d/polar/alle/room/eiswueste/eiswueste[3,5]
}
