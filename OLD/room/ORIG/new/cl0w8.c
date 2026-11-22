                         
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

int komponenten;

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "In einer Ruine inmitten der Eiswueste");
  SetProp( P_INT_LONG, BS(
     "Kaputte Regale und eine zerfetze Theke aus Holz lassen die Vermutung aufkommen, "
    +"dass sich hier wohl frueher mal ein Laden befunden hat. Natuerlich liegen auch "
    +"hier ueberall Truemmer, denn Waende und Decke gibts auch hier keine mehr. "
    +"Welche Macht auch immer dieses Gebaeude zerstoert hat. Sie war gruendlich. "
    +"Ach ja, ueber all dem hat sich natuerlich schon eine Masse Schnee und Eis "
    +"angesammelt.",78) );

  AddDetail( ({"masse"}), BS(
     "Nicht grad wenig.",78) );
  AddDetail( ({"holz"}), BS(
     "Irgendein billiges, minderwertiges Holz.",78) );
  AddDetail( ({"schutt"}), BS(
     "Du kannst den Schutt ja mal durchwuehlen, ob Du noch was brauchbares findest, "
    +"aber pass auf, da verletzt man sich leicht. Das hat sich echt schnell!",78) );
  AddDetail( ({"macht"}), BS(
     "Welche Macht auch immer das war, sie war maechtig maechtig!!!",78) );
  AddDetail( ({"laden"}), BS(
     "Reine Vermutung, dass das ein Laden war!",78) );
  AddDetail( ({"vermutung"}), BS(
     "Es ist nur eine Vermutung!",78) );
  AddDetail( ({"theke"}), BS(
     "Die Theke besteht aus Holz und ist so schlicht wie ihre Beschreibung.",78) );
  AddDetail( ({"beschreibung"}), BS(
     "Eine zerfetzte Theke aus Holz.",78) );
  AddDetail( ({"regale", "regal"}), BS(
     "Auf den Regalen befanden sich mit Sicherheit zahlreiche Gegenstaende.",78) );
  AddDetail( ({"gegenstand", "gegenstaende"}), BS(
     "Es sind nirgends mehr Gegenstaende die auf dem Regal standen, zu sehen. "
    +"Entweder es gibt keine mehr, oder sie wurden verschuettet.",78) );
  AddDetail( ({"sicherheit"}), BS(
     "Was soll denn sonst dort gestanden haben?",78) );

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
     "Der Haendler dem dieser Laden frueher mal gehoerte wahr wohl geizig, jedenfalls "
    +"waren die Waende wohl ziemlich schlicht.",78) );
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
  AddSmells( SENSE_DEFAULT, "Hier riechts nach Eis und allerlei Krempel.\n");
  AddSmells( ({"eis"}), "Normales Eis, keine besondere Geschmackssorte.\n");
  AddSmells( ({"krempel"}), "Der Krempel riecht, wie Krempel halt riecht.\n");

  AddCmd(({"durchwuehle"}), "schutt");
  komponenten=2;

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "westen", CHAOS_GILDEN_ROOM("cl0w6") );
  AddExit( "norden", CHAOS_GILDEN_ROOM("cl0w9") );
}


int schutt(string str)
{
  int rnd;
  notify_fail( "Was willst Du durchwuehlen?\n" );
  if(!str) return 0;
  str=lower_case(str);
  if(str != "schutt" && str != "den schutt") return 0;
  if(komponenten)
  {
    rnd=random(200);
    switch(rnd)
    {
      case   0 .. 119 : tell_object(TP, BS("Du durchwuehlst den Schutt, kannst aber "
                          +"nichts finden.",78) );
                        tell_room( TO, BS(TP->Name(WER)+" durchwuehlt den "
                          +"Schutt.",78), ({TP}) );
                        break;
      case 120 .. 167 : tell_object(TP, BS("Beim durchwuehlen findest Du ein Stueck "
                          +"Kreide.",78) );
                        tell_room( TO, BS(TP->Name(WER)+" durchwuehlt den "
                          +"Schutt.",78), ({TP}) );
                        clone_object(CHAOS_GILDEN_OBJ("kreide"))->move(TP);
                        komponenten--;
                        break;
      case 168 .. 184 : tell_object(TP, BS("Beim durchwuehlen findest Du eine schwarze "
                          +"Kerze.",78) );
                        tell_room( TO, BS(TP->Name(WER)+" durchwuehlt den "
                          +"Schutt.",78), ({TP}) );
                        clone_object(CHAOS_GILDEN_OBJ("skerze"))->move(TP);
                        komponenten--;
                        break;
      case 185 .. 196 : tell_object(TP, BS("Beim durchwuehlen findest Du eine Flasche "
                          +"Drachenblut.",78) );
                        tell_room( TO, BS(TP->Name(WER)+" durchwuehlt den "
                          +"Schutt.",78), ({TP}) );
                        clone_object(CHAOS_GILDEN_OBJ("drablut"))->move(TP);
                        komponenten--;
                        break;
      default       : tell_object(TP, BS("Beim durchwuehlen findest Du einen Beutel "
                          +"mit Sand.",78) );
                        tell_room( TO, BS(TP->Name(WER)+" durchwuehlt den "
                          +"Schutt.",78), ({TP}) );
                        clone_object(CHAOS_GILDEN_OBJ("sand"))->move(TP);
                        komponenten--;
                        break;
    }
  }
  else
  {
    tell_object(TP, BS("Du durchwuehlst den Schutt, kannst aber nichts finden.",78) );
    tell_room( TO, BS(TP->Name(WER)+" durchwuehlt den Schutt.",78), ({TP}) );
  }
  return 1;
}

reset()
{
  ::reset();
  if( komponenten < 6 ) komponenten+=2;
}
