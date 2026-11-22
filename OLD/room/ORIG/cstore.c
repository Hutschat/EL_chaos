inherit "std/store";
#include "gilde.h"
#include <properties.h>
#include <rooms.h>

create()
{
  ::create();
  SetProp(P_INT_SHORT, "Speicher des Ladens");
  SetProp(P_INT_LONG, "Eigentlich hat hier keiner was zu suchen! Deshalb keine ausfuehrliche\nBeschreibung.\n");
  SetProp(P_LIGHT, 1);
  SetProp(P_INDOORS, 1);
AddItem( CHAOS_GILDEN_OBJ( "skerze"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "kreide"), REFRESH_REMOVE );

AddItem( CHAOS_GILDEN_OBJ( "drablut"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "skerze"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "drablut"), REFRESH_REMOVE );  
AddItem( CHAOS_GILDEN_OBJ( "gstaub"), REFRESH_REMOVE );  
AddItem( CHAOS_GILDEN_OBJ( "sstaub"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "sstaub"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "sand"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "klbutton"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "klbutton"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "klbutton"), REFRESH_REMOVE );
AddItem( CHAOS_GILDEN_OBJ( "klbutton"), REFRESH_REMOVE );
}
