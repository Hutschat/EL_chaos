                         
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <new_skills.h>
#include <wizlevels.h>

#include "gilde.h"

#define BS break_string
#define TP this_player()

int healed;

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "In einer Ruine inmitten der Eiswueste");
  SetProp( P_INT_LONG, BS(
     "Du stehst mitten in den halb vom Schnee bedeckten Truemmern. Was hier wohl "
    +"mal war? An den Waenden und der Decke befanden sich wohl magische Symbole, "
    +"finstere Runen und starke Bannsprueche, mit Blut geschrieben. Das kannst Du "
    +"sogar noch an den Bruchstuecken erkennen, die ueberall umherliegen. Nur der "
    +"Boden ist, abgesehen von den Truemmern natuerlich, voellig leer und glatt. "
    +"In einigen Jahren wird die Eiswueste wohl auch die Reste ueberdecken, "
    +"dann gibt es keine Hinweise mehr auf diesen Ort.",78,0,1) );

  AddDetail( ({"pfad", "trampelpfad"}), BS(
     "Er kommt wohl aus der suedlichen Eiswueste und fuehrt weiter nach Norden.",78) );
  AddDetail( ({"durchgang", "durchgaenge"}), BS(
     "Westlich und suedlich gings frueher wohl in andere Raeume. Nach Norden gings "
    +"frueher bestimmt nicht raus, dort wurden die Truemmer offensichtlich beiseite "
    +"geraeumt, eine Art Trampelpfad laesst erkennen dass hier wohl oefters jemand "
    +"vorbeikommt.",78) );
  AddDetail( ({"hinweise"}), BS(
     "Noch siehst Du die Truemmer, aber bald werden sie wohl unter ewigem Eis "
    +"ruhen...",78) );
  AddDetail( ({"ort", "raum", "umgebung"}), BS(
    "Schau Dich halt in Deiner Umgebung um. (Syntax: schau)",78) );
  AddDetail( ({"syntax", "befehl"}), BS(
    "Ist 'schau' ein _neuer_ Befehl fuer Dich?",78) );
  AddDetail( ({"grund"}), BS(
    "Keiner erkennbar!",78) );
  AddDetail( ({"jahre", "weile"}), BS(
    "Es wird wohl schon noch ne Weile dauern...",78) );
  AddDetail( ({"krieger"}), BS(
    "Wenn die mal hier waren, jetzt sind sie's nimmer.",78) );
  AddDetail( ({"gebaeude", "gemaeuer", "raeume", "dingens"}), BS(
    "Gebaeude, Gemaeuer, Raeume... das Dingens in dem Du stehst ist gemeint!",78) );
  AddDetail( ({"niederlassung", "filialen"}), BS(
    "Niederlassung? Haben die Chaoten denn sogar Filialen? Du wunderst Dich sehr.",78) );
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
  AddSpecialDetail( ({"kein woelkchen"}), "kein_woelkchen");
  AddDetail( ({"reste", "rest"}), BS(
    "Damit sind die Truemmer und Bruchstuecke gemeint.",78) );
  AddDetail( ({"runen", "bannsprueche", "symbole", "zeichen", "pentagramme"}), BS(
     "Zeichen, die die Chaoten gern benutzen. Ob es sich bei diesem Gebaeude um eine "
    +"Niederlassung der Chaoten gehandelt hat? Aber wieso wurde es zerstoert? Naja die "
    +"Krieger des Chaos brauchen bestimmt keinen Grund...",78) );
  AddDetail( ({"waende", "wand"}), BS(
     "Die Waende waren wohl mal, bis auf die beiden Durchgaenge, ueber und ueber mit "
    +"Symbolen, Bannspruechen und Runen bemalt. Davon ist nicht viel uebriggeblieben, "
    +"und der Schnee beginnt die kuemmerlichen Reste zu bedecken.",78) );
  AddDetail( ({"boden"}), BS(
     "Der Boden eignete sich wohl einmal besonders gut zum Zeichnen von "
    +"Pentagrammen.",78) );
  AddDetail( ({"blut"}), BS(
    "Blut ist eine hervorragende Farbe zum Malen von Bannspruechen.",78) );
  AddDetail( ({"farbe"}), BS(
     "Blut ist nicht nur in der Regel rot. Eigentlich immer. Zumindest menschliches "
    +"Blut. :)",78) );
  AddDetail( ({"regel"}), BS(
     "Keine Ausnahme ohne sie!",78) );
  AddDetail( ({"ausnahme"}), BS(
     "Mach was sinnvolleres. Zaehl die Schneeflocken oder so :)",78) );
  AddDetail( ({"schneeflocken"}), BS(
     "Im Moment schneit es nicht. Also gibts keine. Und der Schnee aufm Boden ist "
    +"Pulverschnee.",78) );
  AddDetail( ({"erfolg"}), BS(
     "Den Erfolg kann man nicht untersuchen, man hat ihn oder man hat ihn nicht!",78) );
  AddDetail( ({"moment"}), BS(
     "Du versuchst es... aber immer kurz vor dem Erfolg... ist der Moment weg! ",78) );
  AddDetail( ({"pulverschnee"}), BS(
     "Er ist weiss.",78) );
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
  AddSmells( SENSE_DEFAULT, BS("Der Geruch von Blut und Schnee ist schon eine seltsame "
    +"Mischung, aber genau so riecht es hier!",78));
  AddSmells( ({"blut"}), "Das ist schon alt und vertrocknet, aber riechen tut mans "
    +"noch...\n");
  AddSmells( ({"schnee"}), "Der riecht frisch. Kein Wunder. Er ist ja wohl auch frisch "
    +"gefallen!?\n");

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Die Trostlosigkeit dieses einst so gewaltigen Ortes bedrueckt Dich.\n",
    BS("Du hast das Gefuehl, dass hier einst etwas wirklich Boeses existierte "
      +"... wo ist es hin?",78)
  }), 150 );

  AddCmd(({"zaehl", "zaehle"}), "heilung");
  healed=7;

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "norden", CHAOS_GILDEN_ROOM("cl0w3") );
  AddExit( "sueden", CHAOS_GILDEN_ROOM("cl0w6") );
  AddExit( "westen", CHAOS_GILDEN_ROOM("cl0w5") );
}

string kein_woelkchen()
{
  if(TP->QueryProp(P_SP) > 29)
    TP->SetProp(P_SP, TP->QueryProp(P_SP)-30 );
  return "Du rufst: Ich bin ein Oberbluemchenpfluecker!\n";
}

int heilung(string str)
{
  notify_fail( "Zaehl nur, das bildet...\n" );
  if(!str) return 0;
  str=lower_case(str);
  if(str != "schneeflocken") return 0;
  if(healed)
  {
    tell_object(TP, BS("Du zaehlst Die Schneeflocken. Wie Du so zaehlst, findest "
      +"Du eine, die blaeulich funkelt. Schnell steckst Du sie in den Mund (so was "
      +"Leichtsinniges) und schluckst sie runter. Kaelte durchdringt Deinen Koerper. "
      +"Seltsamerweise fuehlst Du Dich auf einmal besser.",78) );
    TP->heal_self( 60+random(60) );    // also 7 * 60-120
    healed--;
  }
  else
  {
    tell_object(TP, BS("Du zaehlst Die Schneeflocken. Du zaehlst, und zaehlst, und "
      +"zaehlst. Irgendwann kommst Du zum Schluss, dass Dein Geist hier einfach "
      +"ueberfordert (oder unterfordert?) ist.",78) );
  }
  return 1;
}

reset()
{
  ::reset();
  if(healed < 7) healed++;
}
