
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include "gilde.h"

create()
{
	::create();

SetProp(P_INT_SHORT, "Der Beschwoerungsraum");
SetProp( P_INT_LONG,
"Dies ist unverkennbar der Beschwoerungsraum der Gilde. Ueberall, an den\n"
+"Waenden und der Decke befinden sich magische Symbole, finstere Runen und\n"
+"starke Bannsprueche zumeist mit Blut geschrieben. Nur der Boden ist\n" 
+"voellig leer und glatt, da hier die Mitglieder ihre Pentagramme und\n"
+"Bannkreise zeichnen.\n");
SetProp(P_LIGHT, 0);
SetProp( P_INDOORS, 1 );
AddDetail( "boden", 
"Der Boden eignet sich besonders gut zum Zeichnen von Pentagrammen.\n");
AddDetail( "decke",
"An der Decke, die ueber und ueber mit Symbolen und Bannspruechen\n"
+"vollgemalt ist, haengt ein einzelner Kronleuchter und verbreitet mit\n"
+"seinen schwarzen Kerzen ein duesteres Licht.\n");
AddDetail(({ "wand", "waende" }),
"Die Waende sind, bis auf die beiden Durchgaenge, ueber und ueber mit\n"
+"Symbolen, Bannspruechen und Runen bemalt\n");
AddDetail(({ "durchgang", "durchgaenge" }),
"Es gibt zwei Durchgaenge. Einer fuehrt nach Sueden in die Eingangshalle,\n"
+"der Zweite befindet sich in der westlichen Wand.\n");
AddDetail(({ "halle", "eingangshalle" }),
"Die Eingangshalle befindet sich suedlich von hier.\n");
AddDetail( "blut",
"Blut ist eine hervorragende Farbe zum Malen von Bannspruechen.\n");
AddDetail( "licht",
"Das Licht ist so duester, das es ueberhaupt keine Helligkeit verbreitet.\n");
AddDetail( "kerzen",
"Auf dem Kronleuchter brennen schwarze Kerzen.\n");
AddDetail(({ "leuchter", "kronleuchter" }),
"Ein einzelner Kronleuchter haengt an der Decke.\n");
AddDetail(({ "symbole", "symbol", "bannsprueche", "bannspruch", "runen",
	"rune" }),
"Die unzaehligen magischen Symbole, Bannsprueche und Runen haben nur den\n"
+"Sinn die Beschwoerung von Daemonen sicherer zu machen. Doch auch diese\n"
+"geben keinen zuverlaessigen Schutz ab. Wer die Beschwoerung von Daemonen\n"
+"nicht perfekt beherrscht, lebt immer gefaehrlich.\n");
AddDetail( "sinn",
"Hat das Leben ueberhaupt einen Sinn?\n");
AddDetail( "leben",
"Untersuch doch mal den Tod :-))))\n");
AddDetail( "tod",
"Error in  57: call_other this_player()->die();\n");
AddDetail( "beschwoerung",
"Dieser Raum eigent sich besonder fuer Beschwoerungen.\n");
AddDetail( "schutz",
"Zum Schutz der Beschwoerer befinden sich ueberall magische Symbole, Runen\n"
+"und Bannsprueche.\n");

AddItem( CHAOS_GILDEN_MON( "wuqour"), REFRESH_REMOVE);
AddExit( "sueden", CHAOS_GILDEN_ROOM( "challe" ));
AddExit( "westen", CHAOS_GILDEN_ROOM( "ctele" ));    
}


