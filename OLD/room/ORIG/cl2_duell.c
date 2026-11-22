/*
Kruuolqs ganz privater Duellier-Raum

Letzte Aenderung: 12.10.99 von Tilly (bugfix)
*/

inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <combat.h>
#include <new_skills.h>
#include <wizlevels.h>

#include "gilde.h"

#define BS break_string
#define P_DUELLANT "_lets_go_have_fun_"

static int x = 0;

string _query_int_long(){
 string s;
 s="Du hast es nicht anders gewollt, Du warst so leichtsinnig und "
   "unueberlegt. Und nun stehst Du hier und schaust Dich bibbernden "
   "Herzens um. Dies scheint Kruuolqs ganz privater Uebungsraum zu sein, "
   "in dem er neue Techniken entwickelt und testet um das Gute in dieser "
   "Welt zu bekaempfen und zu besiegen. An den Waenden befinden sich "
   "meterhohe Regale, in denen er verschiedene Trophaeen aus seinen "
   "zahlreichen Kaempfen aufbewahrt. Auch siehst Du einige kleinere "
   "Tische, auf denen in Glaskolben diverse Fluessigkeiten vor sich hin "
   "brodeln. Offensichtlich experimentiert Kruuolq ein bisschen rum, Du "
   "wuenscht Dir nur, dass er seine neuesten Ergebnisse nicht gerade an "
   "Dir ausprobiert. Der Raum wird durch ein riesiges Heptagramm "
   "beleuchtet, welches ueber Dir in der Luft schwebt und auf mysterioese "
   "Art und Weise leuchtet. Der Boden ist mit einem seltsamen Sand bedeckt, "
   "der Deine Schritte unhoerbar werden laesst und ein beunruhigendes "
   "Eigenleben zu besitzen scheint. Dein Puls rast und Angstschweiss rinnt "
   "Dir den ganzen Koerper hinunter.";
 if(this_player()->InFight()){
   s+=" Wieso nur ich? Warum kann ich auch nicht meine vorlaute Klappe "
      "halten und rutsche andauernd in solche ausweglosen Situationen wie "
      "diese? Fragen ueber Fragen, und keine Antwort in Sicht, naja, das "
      "hast Du Dir selber zu zuschreiben.";
  }
 return BS(s,78);
}
 
void create(){
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(NO_TPORT,1);
  SetProp(P_INT_SHORT,"In Kruuolqs privatem Uebungsraum");
  AddDetail(({"angstschweiss","schweiss","angst","antwort","antworten","art",
   "boden","fussboden","decke","eigenleben","leben","ergebniss","ergebnisse",
   "fluessigkeit","fluessigkeiten","frage","fragen","glas","glaskolben",
   "kolben","gute","heptagramm","herzen","herz","kaempfe","kampf","klappe", 
   "koerper","luft","puls","raum","regal","regale","sand","schritt","schritte",
   "sicht","situation","situationen","technik","techniken","tisch","tische",
   "trophaee","trophaeen","uebungsraum","waende","wand","weise","welt",
   "experimente","experimente"}),
   "Du bist hier um zu kaempfen, BLUEMCHENPFLUECKER!!!\n");
  AddSpecialExit("portal","shit");  
  AddSpecialExit("westen","westen");
  AddCmd(({"sag","sage"}),"hehe");
}

int westen(string dir){
  if(!CHAOS_GILDEN_MASTER->ist_erz(this_player())||!IS_WIZARD(this_player())){
    notify_fail("Du kannst diesen Raum durch diesen Ausgang nicht "
     +"verlassen.\n");
    return 0;
   }
  return this_player()->move("/d/polar/files.chaos/swift/room/cl2tu1_3",
   M_GO,0,"nach Westen","kommt herein");
}
      
void init(){
 ::init();
 if(!x){
   if(find_call_out("kruuolqs_msg")==-1)
     call_out("kruuolqs_msg",0,this_player());
  } 
}

kruuolqs_msg(){
 object pl,mon;
 pl=this_player();
 if(mon=present("\ncg_kruuolq")&&mon!=pl){
  tell_object(pl,
  "Kruuolq sagt: Okay! Du wolltest es nicht anders. Solltest Du feige\n" 
  "Kruuolq sagt: kneifen wollen, musst Du Dich mir ergeben, und das sagst\n"
  "Kruuolq sagt: Du mir am besten moeglichst schnell. Hier kommt nur einer\n"
  "Kruuolq sagt: von uns lebend raus.\n"
  "Kruuolq lacht Dich daemonisch aus.\n");
  pl->Kill();
  x = 1;
 }
} 

static int shit(){
 if(this_player()->InFight()){
    write("Du bist doch gerade beschaeftigt!\n");
   return 1;
  }
 if(CHAOS_GILDEN_MASTER->ist_erz(this_player())){
   write(BS("Du nimmst lieber den Ausgang im Westen. Das Portal schaut nicht "
    "gerade vertrauenserweckend aus.",78));
   this_player()->move("/d/polar/files.chaos/swift/room/cl2tu1_3",M_GO,0,
    "nach Westen","kommt herein");
   return 1;
  }    
 if(present("\ncg_kruuolq")){
    write("Abgehauen wird hier nicht. Entweder Du ergibst Dich oder "
     +"bleibst ewig hier.\n");
   return 1;
  }
 else{
   write("Irgendetwas ist grad passiert - oder vielleicht doch nicht?\n");
   this_player()->move("/d/polar/alle/room/eiswueste/eiswueste[3,5]",
    M_GO|M_NO_SHOW);
   x = 0; 
   return 1;
  }
 return 0;  
}

static int hehe(string was){
 int y;
 object *inv,ob,truhe,m;
 m=find_player("tilly");
 inv=all_inventory(this_player());
 notify_fail("Was willst Du sagen?\n");
 if(!was) return 0;
 if(!this_player()->InFight()) return 0;
 if(was=="ich ergeb mich"||was=="ich ergebe mich"){
    if(CHAOS_GILDEN_MASTER->ist_erz(this_player()) && !present("\ncg_kruuolq")){
      write("Nimm doch den Ausgang im Westen statt hier rumzuplaerren.\n");
      return 1;
     }     
    else{
       write(BS("Du ergibst Dich Kruuolq und als Zeichen Deiner grossen Demut "
        "ueberreichst Du ihm Deine Ausruestung als Trophaee. Vor lauter "
        "Dankbarkeit tritt er Dir schmerzhaft in Deinen Hintern und "
        "katapultiert Dich somit aus dem Raum.",78));
    if(inv && sizeof(inv)){
       for(y=sizeof(inv)-1;y>=0;y--){
           if(!inv[y]->QueryProp(P_NODROP)
              ||!inv[y]->QueryProp(P_NEVERDROP)
              ||!inv[y]->QueryProp(P_AUTOLOADOBJ)
              ||!inv[y]->QueryProp(P_CURSED)){
              inv[y]->move(CHAOS_GILDEN_ROOM("cl2_schatz"),M_PUT);
            }                     
          }
        }  
       write("Kruuolq teilt Dir mit: Wenn Du Deine Sachen eventuell wieder\n"
        "Kruuolq teilt Dir mit: haben moechtest, solltest Du vielleicht\n"
        "Kruuolq teilt Dir mit: mal unseren Erzmeister fragen.\n");    
       tell_room(CHAOS_GILDEN_ROOM("cl2_schatz"),
        "Kruuolq kommt herein und schmeisst einige Sachen auf den Boden, "
        +"die er einem vorlautem Nichtsnutz abgenommen hat.\n"
        "Kruuolq verschwindet wieder.\n");
       this_player()->reduce_hit_point(100+random(50));
       this_player()->move("/d/polar/alle/room/eiswueste/eiswueste[3,5]",
        M_GO|M_NO_SHOW);
       if(ob=present("\ncg_kruuolq")){
          ob->move("/gilden/chaos",M_GO);
          ob->SetProp(P_DUELLANT,0);
         } 
       x = 0; 
      return 1;
    }
  }    
  write("Nein nein nein! Du sollst Dich ergeben!\n");
 return 0;
}
                                
void BecomesNetDead(object me){                                                                   
 int y;
 object *inv,ob,truhe;
 inv=all_inventory(me);
 if(inv && sizeof(inv)){
   for(y=sizeof(inv)-1;y>=0;y--){
     if(!inv[y]->QueryProp(P_NODROP)
        ||!inv[y]->QueryProp(P_NEVERDROP)
        ||!inv[y]->QueryProp(P_AUTOLOADOBJ)
        ||!inv[y]->QueryProp(P_CURSED)){
        inv[y]->move(CHAOS_GILDEN_ROOM("cl2_schatz"),M_PUT);
       }                     
     }
  }   
 me->move("/d/polar/alle/room/eiswueste/eiswueste[3,5]",M_GO);
 tell_room(CHAOS_GILDEN_ROOM("cl2_schatz"),
  "Kruuolq kommt herein und schmeisst einige Sachen auf den Boden, die "
  +"er einem vorlautem Nichtsnutz abgenommen hat.\n"
  "Kruuolq verschwindet wieder.\n");
 if(ob=present("\ncg_kruuolq")){
    ob->SetProp(P_DUELLANT,0);
    ob->move("/gilden/chaos",M_GO|M_NOCHECK); 
  } 
  x = 0;
  if(find_call_out("aufraeumen")==-1)
    call_out("aufraeumen",0);
 return;
}                     

aufraeumen(){
 int y;
 object *inv,truhe;
 inv=all_inventory(this_object());
 if(inv && sizeof(inv))
  for(y=sizeof(inv)-1;y>=0;y--)
   inv[y]->move(CHAOS_GILDEN_ROOM("cl2_schatz"),M_PUT);
 tell_room(CHAOS_GILDEN_ROOM("cl2_schatz"),
  "Kruuolq kommt herein und schmeisst einige Sachen auf den Boden, die "
  +"er einem vorlautem Nichtsnutz abgenommen hat.\n"
  "Kruuolq verschwindet wieder.\n");
  x = 0; 
 return 1;
}
 
/*
Sollte nicht vorkommen, aber sicher ist sicher:
*/

void BecomesNetAlive(object me){ 
  me->reduce_hit_point(100+random(50));
  me->move("/d/polar/alle/room/eiswueste/eiswueste[3,5]",M_GO|M_NO_SHOW);
  x = 0;
 return;  
}

