
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <new_skills.h>
#include "gilde.h"

void create()
{
	::create();

SetProp(P_INT_SHORT, "Ein grosses Zimmer");
SetProp( P_INT_LONG,
"Zweiter Raum fuer die Meister und den Erzmeister.\n");
SetProp(P_LIGHT, 1);
SetProp( P_INDOORS, 1 );                 
AddExit( "osten", CHAOS_GILDEN_ROOM( "cerz1" ));
}                        
