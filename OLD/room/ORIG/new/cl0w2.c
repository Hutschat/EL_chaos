                         
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
  SetProp( P_INT_SHORT, "In der Naehe eines schwarzen Eisberges");
  SetProp( P_INT_LONG, BS(
     "Im Norden ragt ein riesiger Eisberg in die Hoehe. Das ist an und fuer sich ja "
    +"nichts ungewoehnliches, aber dieser Eisberg ist ... schwarz!!!\n"
    +"Ansonsten befindest Du Dich noch immer in der Eiswueste, alles um Dich herum "
    +"ist weiss. Bis auf diesen Eisberg halt. Weit im Sueden kannst Du irgendwas "
    +"im Schnee erkennen.",78,0,1) );

  AddDetail( ({"schnee", "eis"}), BS(
     "Schnee und Eis umgeben Dich, wohin Du blicken kannst. Aber der Eisberg im "
    +"Norden unterscheidet sich doch von sehr von der restlichen Eiswueste!",78) );
  AddDetail( ({"himmel", "polarhimmel"}), BS(
     "Ein schoener, klarer Polarhimmel!",78) );
  AddDetail( ({"eisberg"}), BS(
     "Ein normaler Eisberg, Du ihn ueberall hier finden kannst. Nur dass er "
    +"nicht weiss, sondern schwarz ist!",78) );
  AddDetail( ({"irgendwas"}), BS(
     "Du bist noch zu weit weg. Geh naeher ran!",78) );
  AddDetail( ({"farbe", "nachtschwarz", "schwarz"}), BS(
     "Die Farbe des Eisberges ist Nachtschwarz.",78) );
  AddDetail( ({"eiswueste", "wueste", "labyrinth"}), BS(
     "Du befindest Dich noch in der Eiswueste, aber das eigentliche Labyrinth, fuer "
    +"das die Wueste beruechtigt ist, ist weiter suedlich!",78) );
  AddDetail( ({"boden", "pfad", "weg", "trampelpfad"}), BS(
     "Obwohl es hier des oefteren schneit, ist der Trampelpfad auf dem Du stehst, "
    +"deutlich zu erkennen. Offensichtlich kommen hier des oefteren 'Leute' "
    +"vorbei...",78) );
  AddDetail( ({"polargebiet", "gebiet", "region", "polarregion"}), BS(
     "Momentan befindest Du Dich im Polargebiet, also in der Region Polar.",78) );
  AddDetail( ({"wildnis"}), BS(
     "Machst Du das nicht schon die ganze Zeit? Oder was tust Du hier, so fernab "
    +"jeder Zivilisation?",78) );
  AddDetail( ({"zeit"}), BS(
     "Davon hatte der Magier, der diesen Raum beschrieb, wohl nicht "
    +"uebermaessig!",78) );
  AddDetail( ({"magier"}), BS(
     "Swift.",78) );
  AddDetail( ({"zivilisation"}), BS(
     "Die ist weit weg von hier. Und das ist gut so.",78) );
  AddDetail( ({"leute"}), BS(
     "Na Leute halt!",78) );
  AddDetail( ({"hoehe", "groesse"}), BS(
     "Der Eisberg hat ne ziemliche Groesse und ist deswegen auch recht hoch!",78) );
  AddDetail( ({"abnormitaet", "normalitaet", "gegenteil"}), BS(
     "Abnormitaet nennt man das Gegenteil der Normalitaet, und normal ist ein "
    +"schwarzer Eisberg ja wohl nicht, oder?",78) );


  AddSounds( SENSE_DEFAULT, BS("Du hoerst nur den Wind, das himmlische Kind...",78));
  AddSmells( SENSE_DEFAULT, BS("Es riecht nach... Eis.",78));
  AddSmells( ({"eis"}), "Normales Eis, keine besondere Geschmackssorte.\n");

  AddRoomMessage(({
    "Der eisige Wind blaest Dir ins Gesicht.\n",
    "Du zitterst vor Kaelte.\n",
    "Die Einsamkeit der Eiswueste ist wirklich bedrueckend.",
    "Eine ploetzliche Windboe wirbelt etwas Schnee auf..."
  }), 150 );

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 0 );
  AddExit( "norden", CHAOS_GILDEN_ROOM("cl0w1") );
  AddExit( "sueden", CHAOS_GILDEN_ROOM("cl0w3") );
}
