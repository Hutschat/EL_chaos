// ctele.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_ROOM("std/std_chaos");
      
static string my_long()
{
  if(PL->QueryProp(P_GUILD) != "chaos" || PL->QueryProp(P_GUILD_LEVEL) < 9)
    return break_string("Diese kleine Kammer ist voellig leer und sieht "
           "recht unscheinbar aus. Du kannst dir die Bedeutung dieses "
           "Raumes ueberhaupt nicht vorstellen. Trotzdem wird diese Kammer "
           "haeufig benutzt, obwohl hier wirklich nichts auffaelliges zu "
           "finden ist. Der einzige Ausgang befindet sich in der Ostwand "
           "und fuehrt zurueck in den Ritualraum.");

  return break_string("Diese kleine Kammer ist voellig leer und sieht recht "
         "unscheinbar aus. Genau in der Mitte dieser Kammer befindet sich "
         "ein fuer Unkundige unsichtbarer Riss in der Realitaet. Aber du "
         "kannst ihn sehen und kennst auch seine Bedeutung. Man kann hier "
         "ohne Zeitverlust durch das Efferdland reisen. Dies soll via "
         "Teleportation moeglich sein. Der einzige Ausgang befindet sich in "
         "der Ostwand und fuehrt zurueck in den Ritualraum.");
}

protected void create()
{
  ::create();

  SetProp(P_INT_SHORT, "Eine kleine Kammer");
  Set(P_INT_LONG,#'my_long,F_QUERY_METHOD);
  SetProp(P_LIGHT, 0);
  
  AddDetail(({"kammer","raum" }),
  "Diese kleine Kammer ist voellig unscheinbar.");
  
  AddDetail(({"fussboden","boden"}),
  "Der Boden ist kahl und leer.");
  
  AddDetail(({"wand","waende"}),
  "Die Waende sind voellig leer und kahl.");
  
  AddDetail( "decke",
  "Die Decke sieht aus wie die Waende. Ihr einziger Unterschied besteht "
  "darin, einen anderen Winkel im Bezug zur Schwerkraft zu besitzen.");
  
  AddDetail("winkel",
  "Der Winkel zwischen Decke und Wand betraegt im allgemeinen 90%.");

  AddDetail("bezug",
  "Nichts zum ziehen gefunden.");

  AddDetail("schwerkraft",
  "Du kannst die Schwerkraft deutlich spueren.");

  AddDetail("riss",
  "Ein Riss in der Realitaet befindet sich in der Mitte des Raumes.");

  AddDetail("durchgang",
  "Ein Durchgang fuehrt nach Osten.");

  AddDetail("ritualraum",
  "Der Ritualraum befindet sich im Osten.");

  AddDetail("ausgang",
  "Im Osten befindet sich ein Durchgang, der in den Ritualraum fuehrt.");

  AddDetail("ostwand",
  "Die Ostwand unterscheidet sich von den anderen Waenden nur durch den "
  "Durchgang.");

  AddCmd(({"teleport","teleportiere"}),"tele");
  
  AddExit("osten", CHAOS_GILDEN_ROOM("critual"));
}

static int tele(string str)
{
  string ort;

  if(PL->QueryProp(P_GUILD) != "chaos")
  {
    notify_fail( "Du gehoerst der Gilde nicht an.\n");
    return 0;
  }
  if(PL->QueryProp(P_GUILD_LEVEL) < 9)
  {
    notify_fail( "Du bist nicht maechtig genug.\n");
    return 0;
  }
  if(!str)
  {
    notify_fail( "Du musst schon wissen, wohin Du teleportieren willst.\n");
    return 0;
  }
  notify_fail("Wohin willst Du teleportieren?\n");

  if(!sscanf(str,"zur %s",ort)  && !sscanf(str,"zum %s",ort) &&
     !sscanf(str,"nach %s",ort) && !sscanf(str,"zu %s",ort)) 
  {
    return 0;
  }
  write("Du betrittst das Pentagramm.\n");
  switch(ort)
  {
    case "gruft":
       PL->move("/d/polar/terrorist/room/gruft3",M_TPORT);
       break;
    case "gilde":
    case "abenteurergilde":
    case "abenteuergilde":
      PL->move( "/gilden/abenteurer", M_TPORT);
      break;
    case "moulokin":
    case "moloukin":
    case "hunnar":
    	PL->move( "/d/polar/alle/room/Moulokin/mk_seeloewe3", M_TPORT );
    	break;
    case "drachenhort":
    case "bank":
    case "drachenzinnen":
    case "seherbank":
    	PL->move("/d/ebene/room/dra_str1",M_TPORT);
    	break;
    case "katakomben":
    	PL->move("/d/vland/morgoth/room/kata/kata12",
    	  M_TPORT|M_SILENT );
    	break;
    case "portvain":
    case "port vain":
    case "port":
    case "vain":
      PL->move( "/d/ebene/room/PortVain/laden", M_TPORT);
      break;
    case "weihnachtsmann":
    case "nordpol":
      PL->move( "/d/polar/alle/room/nordpol", M_TPORT);
      break;
    case "zwerge":
    case "zwergen":
    case "zwergenstadt":
    case "zwergenschmied":
    case "zwergenkneipe":
    case "schmied":
    case "zwergenladen":
      PL->move( "/d/gebirge/room/zladen", M_TPORT);
      break;
    case "burg":
    case "daemonenburg":
    case "daemonen":
    case "beschwoerungsraum":
      if( deep_present( "boings hoellenfeuer", this_player()))
        return write( "Boings Hoellenfeuer verhindert den Teleport!\n"),1;
      this_player()->move( "/d/ebene/zardoz/burg/workroom", M_TPORT);
      break;
    case "parallelwelt":
    case "seherwelt":
    case "parawelt":
      write( "Irgendwas scheint passiert zu sein...\n");
      this_player()->SetProp( P_PARA, 1);
      break;        
    case "welt":
    case "normale welt":
    case "normalen welt":
    	write( "Nichts passiert... oder doch?\n");
    	this_player()->SetProp( P_PARA, 0);
    	break;
    case "tod":
    case "tot":
    case "zu meinem tod":
    case "gevatter tod":    
      write( "Du kannst von Glueck sagen, dass Zardoz nicht fies ist!\n");
      this_player()->reduce_hit_point(250);
      break;            
    case "hochebene":
    case "gebirge":
      this_player()->move( "/d/gebirge/room/he1x1", M_TPORT);
      break;
    case "ssp":
    case "musikschloss":
    case "schreckensspitze":
    case "schreckenspitze":
      this_player()->move( "/d/gebirge/boing/sm/l1/m5x1", M_TPORT );
      break;
    case "seherladen":
    case "svolvaer":
    	this_player()->move( "/players/loco/latte/svolvaer/seherladen", M_TPORT);
    	break;
    case "wueste":
    case "arena":
    case "duellarena":
    	this_player()->move( "/d/wueste/room/arena/vorplatz", M_TPORT);
    	break;
    case "hoelle":
    	this_player()->move( "/d/unterwelt/raeume/hoelle2", M_TPORT );
    	break;
    case "elfen":
    case "elf":
    case "elfenladen":
    case "elfendorf":
    case "elfenhain":
    	this_player()->move( "/d/wald/quasimodo/room/strasse2", M_TPORT );
    	break;
    case "architekt":
    case "archi":
    case "architekten":
    case "f&e":
    case "forschung und entwicklung":
    	this_player()->move( "/players/rochus/quest_3player/room/eingang", M_TPORT);
    	break;
    case "dschungel":
    case "urwald":
    	this_player()->move( "/d/dschungel/gum/rooms/bruecke", M_TPORT);
    	break;
    case "zardoz":
    case "zardoz workroom":
    	this_player()->move( "/players/zardoz/workroom", M_TPORT );
    	break;
    case "aurora":
    case "tarko reub":
    case "troedler":
    case "troedelhaendler":
	this_player()->move( "/d/inseln/wargon/aurora/room/wald2", M_TPORT);
    	break;
    case "moron":
    	this_player()->move( "/d/ebene/calum/Moron/room/weg3", M_TPORT );
    	break;
    case "steinbeisser":
    case "steinbeisserhoehle":
    case "hoehle":
    case "beisserhoehle":
    	this_player()->move( "/d/gebirge/boing/beisser/room/beisshoehle5", M_TPORT );
    	break;
    case "wald":
    case "glockenwald":
    	this_player()->move( "/d/wald/troy/room/gwald3x2", M_TPORT );
    	break;
    default:
      write( "Es passiert nichts. Dieser Zielort ist noch nicht bekannt.\n" );
      break;
    }
  return 1;
}

