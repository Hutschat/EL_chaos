// a_start.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet
 
#include "def.h"

inherit CHAOS_GILDEN_ROOM("std/std_chaos");

static string zeit()
{
  int z;

  z = CHAOS_GILDEN_MASTER->query_duellzeit()-time();

  if(z < 0)
    return "Es ist kein Kampf angemeldet";

  return "Der naechste Kampf beginnt in "+time2string("%m %M", z);
}  

static string anmeldung()
{
  mixed duellier;
  
  duellier = CHAOS_GILDEN_MASTER->query_duellier();
  
  if(!sizeof(duellier))
    return "";
  
  return "Es nehmen teil: "+array2string(duellier,1)+".";
}

protected void create()
{
  ::create();
  SetProp(P_INT_SHORT, "Das absolute Nichts");
  SetProp(P_LIGHT, 1);
  SetProp(P_INT_LONG,                       
  "\nDu schwebst im absoluten Nichts, nur umgeben von Luft, die dich am "
  "Leben erhaelt. Ein schwaches Licht kommt aus allen Richtungen. "
  "Voller Spannung erwartest du den Beginn des Erzmeisterskampfes. "
  "@@zeit@@.\n@@anmeldung@@");
  
  AddDetail("licht",
  "Das Licht kommt von ueberall her und leuchtet schwach.\n");
  
  AddDetail("spannung",
  "Eine unbeschreibliche Spannung liegt in der Luft.\n");
  
  AddDetail("luft",
  "Die gibts hier zum Glueck.\n");
  
  AddDetail("glueck",
  "Hm, du und Glueck? Nagut, ausnahmsweise...");
  
  AddDetail(({"richtung","richtungen"}),
  "Die Richtungen sind hier schlecht einzuschaetzen.");
  
  AddDetail("leben",
  "Du knuddelst deinen Urdrachen zum letzten Mal.");
  
  AddDetail(({"arena","duellarena"}),
  "Die kannst du von hier aus nicht sehen.");
  
  AddDetail("nichts", "Du siehst Nichts.");
  
  AddDetail(({"boden","decke","wand","waende"}),
  "Gibt's hier nicht.");
  
  AddExit("zurueck",CHAOS_GILDEN_ROOM( "ctrib" ));
  
  AddCmd("beschleunige","speed_up");
}

int speed_up(string was)
{
   notify_fail("Was moechtest Du beschleunigen?\n");

   if (was != "countdown")
     return 0;
     
   if(member_array(getuid(PL),CHAOS_GILDEN_MAGIER) == -1)
   {
      write("Sowas duerfen nur die Chaos-Gildenmagier.\n");
      return 1;
   }
   if(!CHAOS_GILDEN_MASTER->IstKampf())
   {
      write("Es ist momentan kein Erzmeisterkampf angemeldet.\n");
      return 1;
   }
   write("Du beschleunigst den Timer.\n");
   
   "/gilden/chaos"->beschleunige_countdown();
   
   return 1;
}

int test_auf_equip(object pl)
{
  mixed ausr;
  int i;

  if( !interactive(pl))
    return 0; 

  ausr = deep_inventory(pl);

  foreach(object tmp:deep_inventory(pl))
  {
    if(tmp->QueryProp(P_AUTOLOADOBJ))
      continue;
    if(tmp->QueryProp(P_NEVERDROP))
      continue;
    if(tmp->QueryProp(P_WEAPON_TYPE) != WT_AMMU)
      continue;
    if(tmp->QueryProp(P_ARMOUR_TYPE))
      continue;
    return 1;
  }
  return 0;
}

void init()
{
  ::init();
  if(test_auf_equip(PL))
  {
    PL->move(CHAOS_GILDEN_ROOM("ctrib"), M_GO);
    call_out("erklaerung",0);
  }
}

static void erklaerung()
{
  write( "ACHTUNG! ACHTUNG! ACHTUNG! ACHTUNG!\n\n"
  "Neuerdings darf man nur noch normale Waffen und Ausruestungen mit in\n"
  "die Arena nehmen. Ausserdem natuerlich Gegenstaende, die Du nicht\n"
  "ablegen kannst. Nur dann ist es Dir erlaubt, am Erzmeisterkampf\n"
  "teilzunehmen.\n");
}
  
void start()
{
  string *duellier;     // Die Duellierer
  object pl,*ob;        // Hilfsvariablen
  int i,j;              // Schleifenzaehler
  string *rooms;        // Die Raeume der EM-Arena
  
  rooms = ({"no","nw","so","sw"});

  duellier = CHAOS_GILDEN_MASTER->query_duellier();

  foreach(string tmp:duellier)
  {
    if(!pl = find_player(tmp))
    {
      CHAOS_GILDEN_MASTER->loesche_duellier(tmp);
      continue;
    }
    if(!present(pl,ME))
      CHAOS_GILDEN_MASTER->loesche_duellier(tmp);
  }
  
  if(sizeof(CHAOS_GILDEN_MASTER->query_duellier()) < 3)
  {
    CHAOS_GILDEN_MASTER->set_duellzeit( (time()+60*60*5));
    CHAOS_GILDEN_MASTER->loesche_alle();

    tell_room(ME,"Der Kampf findet aufgrund zuwenig Teilnehmer nicht "
                 "statt.\n");
    map_objects(all_inventory(),"move",CHAOS_GILDEN_ROOM("ctrib"),M_GO);
    return;
  }                
  TRIB( "Der Kampf um den Erzmeistertitel startet jetzt!" );

  tell_room(ME, "Auf gehts!\nEine Kraft wirbelt dich umher!\n");
  
  ob = filter_array(all_inventory(ME),#'interactive);
  
  for(i = sizeof(ob)-1;i>=0;i--)
  {
    for (j=i-1;j>=0;j--)
      ob[j]->InsertEnemy(ob[i]);
    
    ob[i]->move(CHAOS_ARENA_ROOM(rooms[i%4]),M_GO,"in den Kampf",
                                                  "zieht",
                                                  "erscheint");
  }
}    
  
