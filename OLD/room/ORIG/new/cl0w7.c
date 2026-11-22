                         
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
     "Das war wohl mal ein recht schlichter Raum, eine Theke ist das einzige "
    +"Moebelstueck. Das ist seltsamerweise noch gut erhalten, fast wie neu. "
    +"Der Zahn der Zeit und die rauhe Eiswueste haben auch hier schon ihr Werk "
    +"getan, bald wird das alles vom Schnee bedeckt sein. Auf dem Boden entdeckst Du "
    +"eine schaebige Top-Liste.",78) );

  AddDetail( ({"werk"}), BS(
     "Schnee und Eis bedecken die Truemmer schon zum groessten Teil.",78) );
  AddDetail( ({"sprichwort", "sprichwoerter"}), BS(
     "Wenn Du gut ueberlegst, fallen Dir bestimmt selbst welche ein.",78) );
  AddDetail( ({"zahn", "zeit"}), BS(
     "Komisches Sprichwort. Aber Sprichwoerter sind ja oft komisch.",78) );
  AddDetail( ({"liste", "top-liste", "topliste", "teil"}), BS(
     "So ein schaebiges, dreckiges Teil. Du kannst nichts mehr entziffern, also laesst "
    +"Du es liegen.",78) );
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
  AddDetail( ({"moebel", "moebelstueck"}), BS(
     "Einziges Moebelstueck ist eine Theke, die seltsamerweise noch voll intakt zu sein "
    +"scheint.",78) );
  AddDetail( ({"theke"}), BS(
      "Sie ist noch voll intakt. Naja hier wurden bestimmt lanweilige "
    +"Verwaltungsaufgaben erledigt, die Theke hat also schon schlimmeres erlebt als "
    +"die Zerstoerung hier. :)",78) );
  AddDetail( ({"zerstoerung"}), BS(
    "Meinst Du etwa, das sah hier schon immer so aus???",78) );
  AddDetail( ({"verwaltungsaufgaben"}), BS(
    "Das moechtest Du doch gar nicht wissen.",78) );
  AddDetail( ({"zettel", "fetzen", "papierfetzen", "papierzettel"}), BS(
    "Es sind nur noch Fetzen. Nichts brauchbares darunter.",78) );
  AddDetail( ({"reste", "rest"}), BS(
    "Damit sind die Truemmer und Bruchstuecke gemeint.",78) );
  AddDetail( ({"waende", "wand"}), BS(
     "An den Waenden hingen wohl mal irgendwelche Zettel, sonst nichts. Fetzen davon "
    +"liegen hier noch auf dem Boden herum, sie sind aber allesamt unleserlich.",78) );
  AddDetail( ({"boden", "steinboden"}), BS(
     "Der schlichte Steinboden ist wie im ganzen Gebaeude von Truemmern bedeckt. Du "
    +"erkennst einige alte Papierfetzen und eine schaebige, dreckige Top-Liste.",78) );
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

   AddReadDetail( ({ "liste", "top-liste", "top-liste" }),
     "Die ist nicht mehr lesbar, leider.\n" );

  AddSounds( SENSE_DEFAULT, BS("Der Wind heult und pfeift durch die Ruinen.",78));
  AddSmells( SENSE_DEFAULT, BS("Hier riecht es auffallend stark nach Papier und Tinte. "
    +"Das passt zu diesem ehemals nuechtern eingerichteten Raum!",78));
  AddSmells( ({"papier"}), "Das gab es hier frueher wohl in grossen Mengen.\n");
  AddSmells( ({"tinte"}), "Jo, es riecht wie Tinte.\n");

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "osten", CHAOS_GILDEN_ROOM("cl0w6") );
  AddExit( "nordwesten", CHAOS_GILDEN_ROOM("cl0w10") );
}
