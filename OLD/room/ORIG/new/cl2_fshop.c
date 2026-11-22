inherit "std/room";

#include "gilde.h"
#include "cl2_fshop.h"


static string was(string str,int ge){
  string st;
  switch(ge){
    case 0: 
      st = str; 
      break;
    case 1: 
      st = "einen "+str; 
      break;
    case 2: 
      st = "eine "+str; 
      break;
    default: 
      st = "ein "+str; 
      break;
  }
  return st;
}
static string wen(string str,int ge){
  string st;
  switch (ge){
    case 0: 
      st = "ein "+str; 
      break;
    case 1: 
      st = "einen "+str; 
      break;
    case 2: 
      st = "eine "+str; 
      break;
    default: 
      st = "einen "+str; 
      break;
  }
  return st;
}
static string zeile(int i,mixed item){
  string out;
  int j;
  out = sprintf("%2d.       %s",i,capitalize(was(item[2],item[5])));
  for(j=0;j<(52-sizeof(was(item[2],item[5])));j++) out += " ";
  
  if (item[0] > 0) out += sprintf("%4d\n",item[4]);
  else out += "ausverkauft\n";
  
  return out;
}
static string list_things(){
  string output,dum;
  mixed item;
  int i;
  string str;
  output = sprintf("                       Preisliste: %s\n",str)+
  
  "Nr.       Artikel					      Preis\n"+
  "--------------------------------------------------------------------------\n";
  item = QueryProp(P_FSHOP_ITEMS);
  for(i=1;i<=sizeof(item);i++){
      dum = zeile(i,item[i-1]); 
      output += dum;
  }
  return output;
}

void SetUpStorage(){
  SetProp(P_FSHOP_ITEMS,({  
    ({
      ANZ(5),
      FSHOP_OBJ("klbutton"),
      "'Kleriker sind Weicheier'-Botton",
      ({"button","klerikerbutton"}),
      PREIS(300),
      MALE
    }),
    ({ANZ(5),FSHOP_OBJ("sskunk"),"Gramm Super-Skunk",
    ({"superskunk","super-skunk","ssknunk"}),PREIS(300),MALE}),  
    }));
}
void reset(){
  ::reset();
  SetUpStorage();
}
static int liste(){
  notify_fail("Was willst Du lesen?\n");
   write(list_things());
  return 1;
}

static int do_buy(int what,object pl){
  object ob;
  mixed items;
  items = QueryProp(P_FSHOP_ITEMS);
  if (items[what][0]<1){
    tell_object(pl,
      "Tut mir leid, das ist leider ausverkauft.\n");
    return 1; /* 1 = ausverkauft */
  }
  if (pl->QueryMoney()<items[what][4]){
    tell_object(pl,
       sprintf("Du brauchst dazu mindestens %d Muenzen!\n",items[what][4]));
    return 2; /* 2 = zuwenig Geld */
  }
  pl->AddMoney(-items[what][4]);
  ob = clone_object(items[what][1]);
  if(!ob) return 0;
  items[what][0] --;
  SetProp(P_FSHOP_ITEMS,items);
  tell_object(pl,"Du kaufst "+wen(items[what][2],items[what][6])+".\n");
  if(!IS_LEARNER(pl))
    ZENTRALBANK->PayIn(items[what][4]);
  if (ob->move(pl,M_GET)<= 0){
    tell_object(pl,"Du kannst das nicht mehr tragen, ich lege es hier ab!\n");
    ob->move(this_object(),M_NOCHECK);
  }
  say(pl->name()+" kauft "+wen(items[what][2],items[what][6])+".\n",pl); 
  return 3;  /* 3 = OK */
}

static int kaufen(string str){
  int i,j;
  mixed things;
  notify_fail("Was moechtest Du kaufen?\n");
  if(!str) return 0;
  if(sscanf(str,"%d",i)){
  /*
    if(!present("\npiet")){
      write("Da Piet nicht anwesend ist, kannst Du leider nichts kaufen.\n");
      return 1;
    }*/
    things = QueryProp(P_FSHOP_ITEMS);
    if((i<=0)||(i>sizeof(things))) return 0;
    j=do_buy(i-1,this_player());
    if(j) return 1;
    return 0;
  }
  if (sscanf(str,"%s",str)){
    things = QueryProp(P_FSHOP_ITEMS);
    j = -1;
    for (i = 0;i<sizeof(things);i++){
      if(member_array(str,things[i][3]) >= 0){
        j = i;
        i = sizeof(things);
      }
    }
    if(j<0) return 0;
    i=do_buy(j,this_player());
    if (i) return 1;
    return 0;      
  }
  return 0;
}
static int diebe(string str){
  notify_fail("Was willst Du stehlen?\n");
  if(!str) return 0;
  write("Man bestiehlt keine Chaoten, das ist ungesund!\n");
  return 1;
}
void create(){
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,
    "Der Fanshop in der Chaosburg");
  SetProp(P_INT_LONG,
   BS("Verdammt, was ist dass den fuer ein dreckiger Laden? "
   "Die Waende sind ueber und ueber behangen mit irgendwelchen "
   "Merwuerdigkeiten, die zudem vollkommen eingestaubt sind und "
   "auf dem Boden dieser Einrichtung kriechen "
   "ungestoert tausende, Schleimspuren hinter sich ziehende, "
   "Insekten herum. Du musst regelrecht aufpassen, keine "
   "davon mit deinen Fuessen zu zermatschen. Knapp unter der Decke schwebt "
   "ein Chaosball, dessen Leuchten diesen Laden in ein merkwuerdiges "
   "Licht taucht "
   "und vor der rechten Wand faellt dir eine Tresen auf, "
   "hinter dem sich normalerweise der Besitzer dieser Bruchbude "
   "aufhaelt. Eine Preisliste der Waren, die hier angeboten werden, "
   "baumelt an der linken Wand.",78));
  
  AD(({"chaosball","leuchtenden chaosball"}),
    BS("Du betrachtest aufgeregt diesen Chaosball. Verdammt, hast "
    "du ein Schwein, ein echter Chaosball! Dummerweise besteht er aus "
    "Plastik. Heutzutage wird man aber auch ueberall beschissen...",78));
  AD(({"plastik","kunststoff"}),
    BS("Billiger ging es wohl nicht 
  AddReadDetail(({"liste","preisliste"}),
   "Als Du naeher hinschaust, siehst Du, dass die Liste viergeteilt ist.\n"
  +"Du kannst Dir die einzelnen Preislisten mit den folgenden Befehlen an-\n"
  +"schauen:\n"
  +" (preis)liste dope            Zeigt die Preise der 'Kraeuter' die Du hier \n"
  +"                              kaufen kannst.\n"
  +" (preis)liste geraete         Zeigt die Rauchgeraete und was sie kosten.\n"
  +" (preis)liste verschiedenes   Zeigt alle uebrigen Sachen, die Du hier \n"
  +"                              kaufen kannst.\n"
  +" Um eine Ware zu kaufen tipppe: kauf(e) <name>\n" 
  +"                          oder: kauf(e) <nummer> .\n"
  +" Alle Artikel sind vom Umtausch ausgeschlossen!\n\n"
  );
  AddSpecialExit("westen",CHAOS_GILDEN_ROOM("cl2bu7")); 
  AddCmd(({"lies","lese","les","zeige","zeig"}),"liste");
  AddCmd(({"liste","preisliste"}),"liste");
  AddCmd(({"kaufe","kauf"}),"kaufen");
  AddCmd(({"klau","klaue","stehl","stehle"}),"diebe");
  SetUpStorage();
  seteuid(getuid(this_object()));
  AddExit("sueden",CHAOS_GILDEN_ROOM(""));
}
