                         
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
  SetProp( P_INT_SHORT, "Im schwarzen Eisberg");
  SetProp( P_INT_LONG, BS(
     "Hier ist es noch etwas dunkler als beim Eingang der Hoehle. "
    +"Das schwarze Eis, das Dich von allen Seiten umgibt, verbreitet Dunkelheit und "
    +"Kaelte.",78,0,1) );

  AddSounds( SENSE_DEFAULT, BS("Hier ist es totenstill!",78));
  AddSmells( SENSE_DEFAULT, BS("Hier riechts nach Schwefel und Moder.",78));
  AddSmells( ({"schwefel", "moder"}), "Ja danach riechts tatsaechlich!\n");

  SetProp( P_LIGHT, -1);
  SetProp( P_INDOORS, 1 );

  AddCmd( "licht", "licht_spruch");
  AddCmd( "zuende", "zuende_fackel");
}


int kugeltest(object ob)
{
  return ob->id("leuchtende kugel");
}
int fackeltest(object ob)
{
  if(ob->id("fackel")) return ob->_query_lighted();
  return 0;
}

void leuchtquellen_weg(object pl)
{
  int i;
  string *leuchtkugeln,*fackeln;

//------- Lichtkugeln werden schwarz und verlieren Leuchtkraft
  leuchtkugeln=filter_array(deep_inventory(pl), #'kugeltest);
  for(i=0;i<sizeof(leuchtkugeln);i++)
  {
    leuchtkugeln[i]->SetProp(P_LIGHT, 0);   // Licht aus! :)
    leuchtkugeln[i]->SetProp(P_SHORT, "Eine schwarze Kugel");
    leuchtkugeln[i]->SetProp(P_LONG,
      "Eine ziemlich normale schwarze Kugel, die frueher mal magisch leuchtete.\n");
    leuchtkugeln[i]->RemoveId("leuchtende kugel");
  }
  if(sizeof(leuchtkugeln) > 1)    // Mehrere Leuchtkugeln im INV ? :)
    tell_object(pl, BS("Deine Lichtkugeln verlieren ihre Leuchtkraft und verfaerben "
      +"sich schwarz!",78) );
  if(sizeof(leuchtkugeln) == 1)   // Nur 1 Leuchtkugel im INV
    tell_object(pl, BS("Deine Lichtkugel verliert ihre Leuchtkraft und verfaerbt "
      +"sich schwarz!",78) );
//------- Fackeln werden von Luftzug geloescht
  fackeln=filter_array(deep_inventory(pl), #'fackeltest);
  for(i=0;i<sizeof(fackeln);i++)
  {
    fackeln[i]->unlight();
  }
  if(sizeof(fackeln) > 1)    // Mehrere Leuchtkugeln im INV ? :)
    tell_object(pl, BS("Ein ploetzlicher Luftzug loescht alle Deine Fackeln.",78) );
  if(sizeof(fackeln) == 1)   // Nur 1 Leuchtkugel im INV
    tell_object(pl, BS("Ein ploetzlicher Luftzug loescht Deine Fackel.",78) );
}

void init()
{
  object mag;
  leuchtquellen_weg(TP);
  ::init();
}

int licht_spruch()
{
  while(remove_call_out("leuchtquellen_weg") != -1); // alle call_outs weg!
  call_out("leuchtquellen_weg",0, TP);
  return 0;
}

int zuende_fackel(string str)
{
  string dummy;
  if( !str ) return 0;
  if( sscanf( str, "fackel %s", dummy))
  {
    while(remove_call_out("leuchtquellen_weg") != -1); // alle call_outs weg!
    call_out("leuchtquellen_weg",0, TP);
  }
  return 0;
}
