// ctrib.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen     ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet
                         
#include "def.h"

inherit CHAOS_GILDEN_ROOM("std/std_chaos");
                             
static string duellarena_det()
{
  string s;
  int i;
  mapping arena;
  arena = ([]);

  (CHAOS_ARENA_ROOM( "no"))->argl();
  (CHAOS_ARENA_ROOM( "nw"))->argl();  
  (CHAOS_ARENA_ROOM( "so"))->argl();
  (CHAOS_ARENA_ROOM( "sw"))->argl();
  arena["nw"]=filter_array(all_inventory(find_object(CHAOS_ARENA_ROOM("nw"))),
                                         #'living );
  arena["no"]=filter_array(all_inventory(find_object(CHAOS_ARENA_ROOM("no"))),
                                         #'living );  
  arena["sw"]=filter_array(all_inventory(find_object(CHAOS_ARENA_ROOM("sw"))),
                                         #'living );
  arena["so"]=filter_array(all_inventory(find_object(CHAOS_ARENA_ROOM("so"))),
                                        #'living );
  s = "               Die Duellarena der Meister des Chaos!\n"
  +"---------------------------------------------------------------------------\n";
  for( i = 0;i<8;i++)
  {
     if( sizeof(arena["nw"]) < i+1) 
       s += sprintf( "| %-35s| ", "");
     else 
     {
       if( !interactive( arena["nw"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["nw"][i]->name()), 
           capitalize(arena["nw"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["nw"][i]->QueryProp(P_HP) );
           
       else
         s += sprintf( "| %-13s (HP: %-3d | SP: %-3d)  | ", 
           capitalize(arena["nw"][i]->name()), arena["nw"][i]->QueryProp(P_HP),
           arena["nw"][i]->QueryProp( P_SP) );
     }
     if( sizeof(arena["no"]) < i+1) 
       s += sprintf( "%-35s|\n", "");
     else 
     {
       if( !interactive( arena["no"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["no"][i]->name()), 
           capitalize(arena["no"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["no"][i]->QueryProp(P_HP) );
       else    
         s += sprintf( "%-13s (HP: %-3d | SP: %-3d)  |\n", 
           capitalize(arena["no"][i]->name()), arena["no"][i]->QueryProp(P_HP),
           arena["no"][i]->QueryProp( P_SP) );
     }
  }
  s += "---------------------------------------------------------------------------\n";
  for( i = 0;i<8;i++)
  {
     if( sizeof(arena["sw"]) < i+1) 
       s += sprintf( "| %-35s| ", "");
     else
     {
       if( !interactive( arena["sw"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["sw"][i]->name()), 
           capitalize(arena["sw"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["sw"][i]->QueryProp(P_HP) );
       else     
         s += sprintf( "| %-13s (HP: %-3d | SP: %-3d)  | ", 
           capitalize(arena["sw"][i]->name()), arena["sw"][i]->QueryProp(P_HP),
           arena["sw"][i]->QueryProp( P_SP) );
     }
     if( sizeof(arena["so"]) < i+1) 
       s += sprintf( "%-35s|\n", "");
     else
     {
       if( !interactive( arena["so"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["so"][i]->name()), 
           capitalize(arena["so"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["so"][i]->QueryProp(P_HP) );
       else     
         s += sprintf( "%-13s (HP: %-3d | SP: %-3d)  |\n", 
           capitalize(arena["so"][i]->name()), arena["so"][i]->QueryProp(P_HP),
           arena["so"][i]->QueryProp( P_SP) );
     }
  }
  s += "---------------------------------------------------------------------------\n";
  return s;
} 

static string kampfarena_det()
{  
  object *inv;                  
  string s;

  s = "In der Kampfarena siehst Du:\n";

  (CHAOS_GILDEN_ROOM("ckampf"))->idle_raus();

  inv = all_inventory(find_object(CHAOS_GILDEN_ROOM("ckampf")));

  inv = filter_array(filter_array(inv, #'living ), #'objectp );

  if(!sizeof(inv)) 
    s += "Leider niemanden.\n";

  foreach(object tmp:inv)
  { 
    if(tmp->QueryProp(P_INVIS))
      continue;
    
    s += tmp->short();
  }
  return s;
}

protected void create()
{
  ::create();

  SetProp(P_INT_SHORT, "Die Tribuene der Kampfarena");
  SetProp(P_INT_LONG, 
  "Dies ist die Tribuene und gleichzeitig der Zugang zur gefuerchteten "
  "Kampfarena. Nach Suedwesten kann man die Arena betreten, wenn man fuer "
  "einen Kampf zugelassen wird, aber man kann auch einfach einem Kampf "
  "zuschauen, wenn man denn Lust dazu hat (Syntax: 'beobachte an' bzw. "
  "'beobachte aus'. Dies gilt nur fuer die Kampfarena! Kaempfe in der "
  "Duellarena, also Erzmeisterkaempfe lassen sich so nicht beobachten! "
  "Die Tribuene ist sehr schlicht ausgestattet. Nichtmal einen "
  "Bauchladenverkaeufer gibt es hier!");

  AddDetail("zugang",
  "Man kann von hier aus die Kampfarena betreten.");
 
  AddDetail("kampf",
  "Was fuer ein Krampf.");

  AddDetail("krampf",
  "Es zuckt in deinen Waden.");

  AddDetail(({"waden","wade"}),
  "Du bist im Besitz von jeden.");

  AddDetail("syntax",
  "'beobachte an', 'beobachte aus'.");

  AddDetail("boden",
  "Der Boden ist hier aus Stein.");

  AddDetail(({"stein","gestein"}),
  "Das Gestein ist huebsch anzuschauen.\n");

  AddDetail(({"wand","waende"}),
  "Die Waende sind huebsch anzuschauen.\n");

  AddDetail("decke", 
  "Die Decke ist huebsch anzuschauen.\n");

  AddDetail("arena",  
  "Meinst du die Kampfarena oder die Duellarena?\n");

  AddDetail(({"duellarena"}), 
  #'duellarena_det);
  
  AddDetail(({"kampfarena"}),
  #'kampfarena_det);

  AddDetail( "lust",
  "Hier hatte wohl jemand keine Lust auf Details.\n");

  AddDetail( "tribuene",
  "Du bist auf der Tribuene.");

  AddDetail(({"bauchladenverkaeufer","verkaeufer"}),
  "Davon gibt's schon zwei im Efferdland.");

  AddSpecialExit("suedwesten", "betritt_arena" );
  AddSpecialExit("nordosten",  "einfach_hier_raus" ); 
  AddSpecialExit("nordwesten", "zum_nichts" );
  
  AddCmd(({"beobachte", "beobacht", "beo" }), "beobachte_kampf" );
}

int betritt_arena()
{
  if(PL->QueryProp( P_GUILD) == "chaos" &&
     CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 
     PL->QueryProp(P_GUILD_LEVEL) + 1))
  {
    write( "Du hast die Pruefung fuer die naechste Stufe schon bestanden.\n");
    return 1;
  }
  if(!PL->QueryProp(CHAOS_PRUEFUNG))
  {
    write(break_string("Du darfst die Kampfarena nur betreten, wenn dies bei "
         "dem Versuch einer Gildenstufenerhoehung verlangt wird."));
    return 1;
  }
  (CHAOS_GILDEN_ROOM("ckampf"))->idle_raus();

  foreach(object tmp:all_inventory(find_object(CHAOS_GILDEN_ROOM("ckampf"))))
  {
    if(!living(tmp) || !interactive(tmp))
      continue;

    if(tmp) 
    {              
      write( "Es ist schon jemand in der Kampfarena.\n" );
      return 1;
    }
  }
  PL->move( CHAOS_GILDEN_ROOM( "ckampf" ), M_GO, "in die Kampfarena");
  return 1;
}          

int einfach_hier_raus()
{  
  PL->SetProp("kampf_zuschauen",0);
  PL->move( CHAOS_GILDEN_ROOM("challe"), M_GO, "nach Nordosten");
  return 1;
}               

static int beobachte_kampf(string str)
{
  notify_fail( "Beobachte an oder aus?\n");

  if(!str) 
    return 0;

  if(str == "an")
  {
    PL->SetProp("kampf_zuschauen",1);
    write( "Du beobachtest nun die Kampfarena.\n");
    return 1;
  }          
  if(str == "aus")
  {
    PL->SetProp( "kampf_zuschauen", 0);
    write("Du beobachtest die Kampfarena jetzt nicht.\n");
    return 1;
  }
  return 0;
}
 
int zum_nichts()
{
  if(PL->QueryProp(P_GUILD) != "chaos")
  {
    write("Du bist kein Mitglied der Chaos-Gilde!\n");
    return 1;
  }
  if(PL->QueryProp( P_GUILD_LEVEL) < 11)
  {
    write( "Du bist nicht maechtig genug!\n");
    return 1;
  }
  if(!CHAOS_GILDEN_MASTER->IstKampf())
  {
    write("Es ist kein Erzmeisterkampf angemeldet!\n");
    return 1;
  }
  if(member_array(getuid(PL),CHAOS_GILDEN_MASTER->query_duellier()) == -1)
  {
    write("Du bist fuer diesen Kampf nicht angemeldet.\n");
    return 1;
  }
  PL->move(CHAOS_GILDEN_ROOM("a_start"),M_GO,"ins Nichts",
                                             "verschwindet einfach",
                                             "faellt herein");
  return 1;
}
                                  
 
