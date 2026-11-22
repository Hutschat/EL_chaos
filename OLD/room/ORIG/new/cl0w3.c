                         
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
  SetProp( P_INT_SHORT, "In der Eiswueste");
  SetProp( P_INT_LONG, BS(
     "Weit im Norden siehst Du mitten im Weiss der Eiswueste einen schwarzen Fleck. "
    +"Was dort wohl ist? Weiter suedlich siehst Du einige Ruinen, halb verdeckt von "
    +"Schnee und Eis.",78,0,1) );

  AddDetail( ({"himmel", "polarhimmel"}), BS(
     "Ein schoener, klarer Polarhimmel!",78) );
  AddDetail( ({"ueberall"}), BS(
   "Z.B. da wo Du bist! :)",78) );
  AddDetail( ({"naeheres"}), BS(
   "Geh halt naeher ran!",78) );
  AddDetail( ({"ruinen"}), BS(
    "Die Ruinen sind halb vom Schnee verdeckt, Du musst weiter nach Sueden gehen, "
   +"evtl. kannst Du dann Naeheres erkennen...",78) );
  AddDetail( ({"weiss"}), BS(
    "Mit dem 'Weiss' sind Eis und Schnee gemeint...",78) );
  AddDetail( ({"eis", "schnee"}), BS(
    "Ueberall in der Eiswueste findest Du Eis und Schnee. Also auch hier :)",78) );
  AddDetail( ({"fleck"}), BS(
    "Du kannst nicht erkennen um was es sich handelt. Aber es ist schwarz!",78) );
  AddDetail( ({"farbe", "nachtschwarz", "schwarz"}), BS(
     "Die Farbe des Flecks ist Nachtschwarz.",78) );
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
     "Der Fleck ist ziemlich gross!",78) );

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
  AddExit( "norden", CHAOS_GILDEN_ROOM("cl0w2") );
  AddExit( "sueden", CHAOS_GILDEN_ROOM("cl0w4") );
}
