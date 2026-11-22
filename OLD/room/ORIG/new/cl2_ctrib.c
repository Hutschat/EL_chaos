/* 11.09.98  Feuerwehr     Aenderung in zum_nichts         */   
                             
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <combat.h>
#include <new_skills.h>
#include <wizlevels.h>
#include "gilde.h"

create()
{
	::create();

SetProp(P_INT_SHORT, "Die Tribuene der Kampfarena");
SetProp( P_INT_LONG, 
"Dies ist die Tribuene und gleichzeitig der Zugang zur gefuerchteten\n"
+"Kampfarena. Nach Suedwesten kann man die Arena betreten, wenn man fuer\n"
+"einen Kampf zugelassen wird, aber man kann auch einfach einem Kampf\n"
+"zuschauen, wenn man denn Lust dazu hat (Syntax: 'beobachte an' bzw.\n"
+"'beobachte aus'. Dies gilt nur fuer die Kampfarena! Kaempfe in der\n"
+"Duellarena, also Erzmeisterkaempfe lassen sich so nicht beobachten!\n"
+"Die Tribuene ist sehr schlicht ausgestattet. Nichtmal einen\n"
+"Bauchladenverkaeufer gibt es hier!\n" );
SetProp(P_LIGHT, 1);
SetProp( P_INDOORS, 1 ); 
AddDetail( "zugang",
"Man kann von hier aus die Kampfarena betreten.\n");
AddDetail( "kampf",
"Was fuer ein Krampf.\n" );
AddDetail( "krampf",
"Es zuckt in Deinen Waden.\n");
AddDetail(({ "waden", "wade" }),
"Du bist im Besitz von jeden.\n");
AddDetail( "syntax",
"'beobachte an', 'beobachte aus'.\n");
AddDetail( "boden",
"Der Boden ist hier aus Stein.\n");
AddDetail(({ "stein", "gestein" }),
"Das Gestein ist huebsch anzuschauen.\n");
AddDetail(({ "wand", "waende" }),
"Die Waende sind huebsch anzuschauen.\n");
AddDetail( "decke", 
"Die Decke ist huebsch anzuschauen.\n");
AddDetail( "arena", 
"Meinst Du die Kampfarena oder die Duellarena?\n");
AddSpecialDetail(({ "duellarena" }), "duell_arena" );
AddSpecialDetail(({ "kampfarena" }), "kampf_arena" );
AddDetail( "lust",
"Hier hatte wohl jemand keine Lust auf Details.\n");
AddDetail(({ "details", "detail" }),
"Die Details sind huebsch anzusehen (c) Bambulko 1995\n");
AddDetail( "tribuene",
"Du bist auf der Tribuene.\n");
AddDetail(({ "bauchladenverkaeufer", "verkaeufer" }),
"Davon gibt's schon zwei im MorgenGrauen.\n");
AddDetail( "morgengrauen",
"Sowas kannst Du ueberall finden.\n");                                                          
AddSpecialExit( "suedwesten", "betritt_arena" );
AddSpecialExit( "norden", "einfach_hier_raus" ); 
AddCmd(({ "beobachte", "beobacht", "beo" }), "beobachte_kampf" );
}

                                                   
int betritt_arena()
  {
  object *inv;
  int i;
  if( this_player()->QueryProp( P_GUILD) == "chaos" &&
    CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 
      this_player()->QueryProp( P_GUILD_LEVEL ) + 1 ))
  {
    write( "Du hast die Pruefung fuer die naechste Stufe schon bestanden.\n");
    return 1;
  }
  if( !this_player()->QueryProp( CHAOS_PRUEFUNG ))
  {
    write( "Du darfst die Kampfarena nur betreten, wenn dies bei dem Versuch einer \n"
      +"Gildenstufenerhoehung verlangt wird.\n");
    return 1;
  }
  (CHAOS_GILDEN_ROOM("ckampf.c"))->idle_raus();
  inv = all_inventory( find_object( CHAOS_GILDEN_ROOM( "ckampf" )));
  for( i = sizeof(inv)-1; i>=0; i-- )
  {
    if( !living( inv[i])) continue;
    if( !query_once_interactive( inv[i])) continue;
    if(inv[i]) 
    {              
      write( "Es ist schon jemand in der Kampfarena.\n" );
      return 1;
    }
  }
  this_player()->move( CHAOS_GILDEN_ROOM( "ckampf" ), M_GO, "in die Kampfarena");
  return 1;
}          



int einfach_hier_raus()
{  
  this_player()->SetProp( "kampf_zuschauen", 0);
  this_player()->move( CHAOS_GILDEN_ROOM("cl2bu5"), M_GO, "nach Norden");
  return 1;
}               


string kampf_arena()
{  
  int i;
  object *inv;                  
  string s;
  s = "In der Kampfarena siehst Du:\n";
  (CHAOS_GILDEN_ROOM("ckampf"))->idle_raus();
  inv = all_inventory( find_object( CHAOS_GILDEN_ROOM( "ckampf" )));
  inv = filter_array( filter_array( inv, #'living ), #'objectp );
  if( !sizeof(inv)) s += "Leider niemanden.\n";
  for( i = sizeof(inv)-1; i>=0; i-- )
  { 
    if( inv[i]->QueryProp(P_INVIS)) continue;
    s += inv[i]->short();
  }
  return s;
}
                                    

int beobachte_kampf(string str)
{
  notify_fail( "Beobachte an oder aus?\n");
  if( !str) return 0;
  if( str == "an" )
  {
    this_player()->SetProp( "kampf_zuschauen", 1);
    write( "Du beobachtest nun die Kampfarena.\n");
    return 1;
  }          
  if( str == "aus" )
  {
    this_player()->SetProp( "kampf_zuschauen", 0);
    write( "Du beobachtest die Kampfarena jetzt nicht.\n");
    return 1;
  }
  return 0;
}
 
      
string duell_arena()
{
  string s;
  int i;
  mapping arena;
  arena = ([]);
  (CHAOS_ARENA_ROOM( "no"))->argl();
  (CHAOS_ARENA_ROOM( "nw"))->argl();  
  (CHAOS_ARENA_ROOM( "so"))->argl();
  (CHAOS_ARENA_ROOM( "sw"))->argl();
  arena[ "nw" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("nw"))),
    #'living );
  arena[ "no" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("no"))),
    #'living );  
  arena[ "sw" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("sw"))),
    #'living );
  arena[ "so" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("so"))),
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
