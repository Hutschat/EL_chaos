
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
+"Bannkreise zeichnen. Im Westen fuehrt eine Haustuer nach draussen.\n");
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
AddSpecialDetail(({"tuer"}),"det_tuer");


AddItem( CHAOS_GILDEN_MON( "wuqour"), REFRESH_REMOVE,
         (["chaos_NeueGilde":1]));
AddItem( CHAOS_GILDEN_MON( "cl2_igor"),REFRESH_REMOVE,
         (["chaos_guard":"sueden",
           "chaos_guard_money":1000,
           "chaos_guard_chaos":1,
            "chaos_guard_msg":"Igor fluestert: Zu diesem Raum hast Du "+
                              "keinen Zutritt. Verpiss Dich.\n"]));

AddSpecialExit( "sueden", "ex_sueden");
AddCmd( "westen", "ex_westen");    
AddCmd(({"oeffne"}),"open");
AddCmd(({"schliess","schliesse"}),"close");

}


int ex_sueden() {
  if (this_player()->QueryProp("chaos_behandlung") &&
      present("wuqour",this_object()))
      return write("Du kannst Dich nicht bewegen. Wuqour behandelt Dich gerade.\n"),1;
  this_player()->move(CHAOS_GILDEN_ROOM("cl2_cbeh1"),M_GO,"nach Sueden");
  return 1;
}

string det_tuer()
{
    return break_string(
    "Die Tuer besteht aus dem gleichen, pechschwarzen und makell"+
    "osen Material, welches Du hier ueberall als Tuer findest. Die Tuer "+
    "ist uebrigens gerade "+(
     call_other(CHAOS_GILDEN_ROOM("cl2bu6"),"querydoor")==0?
     "geschlossen":"geoeffnet")+".",78);
}

string GetExits(object ob) {
  if (!call_other(CHAOS_GILDEN_ROOM("cl2bu6"),"querydoor")) 
    return "Es gibt einen sichtbaren Ausgang: sueden.\n";
  return "Es gibt zwei sichtbare Ausgaenge: westen und sueden.\n";
}

int ex_westen()
{
  if (this_player()->QueryProp("chaos_behandlung") &&
      present("wuqour",this_object()))
      return write("Du kannst Dich nicht bewegen. Wuqour behandelt Dich gerade.\n"),1;
  if (!call_other(CHAOS_GILDEN_ROOM("cl2bu6"),"querydoor"))
  {
     write("Du knallst gegen die geschlossene Tuer.\n");
     say(this_player()->Name(WER)+" rennt gegen die geschlossene Tuer.\n",this_player());
     return 1;
  }
  this_player()->move(CHAOS_GILDEN_ROOM("cl2bu6"),M_GO,"nach Westen");
  return 1;
} 

int open(string was)
{  
   notify_fail("Was moechtest Du denn oeffnen?\n");
   if (was != "tuer") return 0;
   
   if (!call_other(CHAOS_GILDEN_ROOM("cl2bu6"),"opendoor"))
   {
     write("Aber die Tuer ist schon geoeffnet...\n");
     return 1;
   }
   write("Du oeffnest eine Tuer.\n");
   say(this_player()->Name(WER)+" oeffnet eine Tuer.\n",this_player());
   return 1;
}  

int close(string was)
{  
   notify_fail("Was moechtest Du denn schliessen?\n");
   if (was != "tuer") return 0;

   if (!call_other(CHAOS_GILDEN_ROOM("cl2bu6"),"closedoor"))
   {
     write("Aber die Tuer ist schon gescholossen...\n");
     return 1;
   }
   write("Du schliesst eine Tuer.\n");
   say(this_player()->Name(WER)+" schliesst eine Tuer.\n",this_player());
   return 1;
}  
