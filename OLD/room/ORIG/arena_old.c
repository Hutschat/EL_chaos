/*
Letzte Aenderung: 26/10/98 Tilly (KILL_MSG korrigiert)
*/
inherit "/std/room";

#include <properties.h>
#include <moving.h>
#include "gilde.h"

int check_feige(object spieler);

void create()
{
  ::create();
  AddCmd( "", "command_check",1 );
}


void weg_mit_dem_spieler(object player)
{
  if( !objectp(player)) return;
  player->move( CHAOS_GILDEN_ROOM( "vc/stop+"+getuid(player)), M_GO | M_NO_SHOW );
}
     
int command_check(string str)
{           
  string v;
  v= query_verb();
  if( v == "ende" || v == "quit" )
  {                                                          
    TRIB( "Wieso macht "+this_player()->name()+" eigentlich 'ende'? "+
      "Naja, jedenfalls war dies das Ende des Kampfes fuer "+
      this_player()->QueryPronoun(WEN) );
    weg_mit_dem_spieler( this_player());
    check_feige(this_player());
    CHAOS_GILDEN_MASTER->LoescheKaempfer( this_player());
    return 1;
  }
  if( (v == "schlaf" || v == "schlafe" ) && str == "ein" )
  {                                                   
    write( "Einschlafen ist wie Aufgeben!\n");     
    TRIB( capitalize(this_player()->name())+" zieht es vor einfach in der "+
      "Duellarena einzuschlafen. Tja, das wars dann wohl." );
    check_feige(this_player());
    CHAOS_GILDEN_MASTER->LoescheKaempfer( this_player());
    this_player()->StopHuntingMode();
    weg_mit_dem_spieler(this_player());
    return 1;
  }
  return 0;
}
                                                         

BecomesNetDead( object player)
{                                                                   
  TRIB( capitalize( player->name())+" ist leider netztot und damit aus "+
    "raus aus dem Kampf um den Erzmeistertitel." );
  player->StopHuntingMode();
  weg_mit_dem_spieler(player);
  CHAOS_GILDEN_MASTER->LoescheKaempfer(player);
}


NotifyPlayerDeath( object player, object killer, int le )
{
  TRIB( capitalize(player->name())+" ist leider von uns gegangen. :)" );
  CHAOS_GILDEN_MASTER->LoescheKaempfer(player);
}


void aufraeumen()
{
  map_objects(all_inventory(), "move", CHAOS_GILDEN_ROOM("ctrib"), M_GO | M_NO_SHOW);
}


int check_feige(object spieler)
{
  if (spieler->QueryProp(P_HP) > (spieler->QueryProp(P_MAX_HP)*3)/4)
    if (interactive(spieler))
    {
      tell_object(spieler,"Feuerwehr, Tilly und Bierchen erscheinen.\n"+
      "Bierchen sagt: Du, "+spieler->Name(WER)+", warst FEIGE!\n"+
      "Tilly sagt: Wir verurteilen Dich wegen Feigheit in einer Schlacht!\n"+
      "Feuerwehr sagt: Du wirst nun STERBEN.\n");
      call_out("let_him_die",4,spieler);
    }

}

int let_him_die(object ob)
{

  if (objectp(ob) && interactive(ob))
  {
     SetProp(P_KILL_NAME,"Die Chaosmagier");
     SetProp(P_KILL_MSG,({"sagen: Wir verurteilen Dich wegen Feigheit im Kampf.",
      MSG_EMOTE,PLURAL}));
     ob->die();
     return 1;
  }

}

void exit()
{
  ::exit();
  // Daemonen befrieden... keine gute Loesung aber ok.
  if (!query_once_interactive(this_player()))
    this_player()->StopHuntingMode();
}
