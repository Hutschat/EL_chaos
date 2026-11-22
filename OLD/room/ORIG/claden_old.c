/*
Letzte Aenderung: 09/12/98 von Tilly (komplett umgestrickt)
*/

inherit "std/room";

#include "gilde.h"
#include <bank.h>

#define BS break_string
#define AD AddDetail
#define AE AddExit
#define ASE AddSpecialExit
#define ARD AddReadDetail
#define ANZ(x)          x
#define PREIS(x)        x
#define TP              this_player()
#define TPN             this_player()->name()
#define TO              this_object()
#define A_ITEMS           "_achtarch_items_"

int MONEY=0;

void SetUpStorage(){
  SetProp(A_ITEMS,({  
    ({ANZ(4),CHAOS_GILDEN_OBJ("klbutton"),"'Kleriker sind Weicheier'-Button",
      ({"button","klerikerbutton"}),PREIS(30),MALE}),
    ({ANZ(2),CHAOS_GILDEN_OBJ("skerze"),"schwarze Kerze",
      ({"kerze","schwarze kerze"}),PREIS(690),FEMALE}),
    ({ANZ(15),CHAOS_GILDEN_OBJ("kreide"),"Stueck Kreide",
      ({"kreide","stueck kreide"}),PREIS(60),NEUTER}),
    ({ANZ(2),CHAOS_GILDEN_OBJ("drablut"),"Flasche mit Drachenblut",
      ({"flasche","blut","drachenblut"}),PREIS(4215),FEMALE}),
    ({ANZ(1),CHAOS_GILDEN_OBJ("gstaub"),"Beutel mit Goldstaub",
      ({"goldstaub"}),PREIS(9633),MALE}),
    ({ANZ(2),CHAOS_GILDEN_OBJ("sstaub"),"Beutel mit Silberstaub",
      ({"silberstaub"}),PREIS(2400),MALE}),
    ({ANZ(1),CHAOS_GILDEN_OBJ("sand"),"Beutel mit Sand",
      ({"sand","sandbeutel"}),PREIS(9999),MALE}),
    ({ANZ(1),"/obj/boerse","Geldboerse (leer)",
      ({"boerse","geldboerse"}),PREIS(240),FEMALE}),
    ({ANZ(1),"/obj/fackel","Fackel",
      ({"fackel"}),PREIS(25),FEMALE})                      
    }));
}

void create(){
  ::create();
  SetProp(P_LIGHT,0);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Im Laden der Chaosfestung");
  SetProp(P_INT_LONG,
   BS("Dies ist der beruehmte Laden 'Nuetzliche Zutaten fuer boese "
    "Zaubersprueche'. Seine Beruehmtheit erlangte der Laden dadurch, dass er "
    "trotz seiner aeusserst unguenstigen Lage in einer boesartigen Festung "
    "mitten in der Eiswueste unglaublich gute Umsaetze macht und so sein "
    "Besitzer, der Haendler Achtarch, vor einigen Jahren die Medaille der "
    "Ladenbesitzer-Vereinigung des MorgenGrauens fuer besonders herausragende "
    "Leistungen verliehen bekam. Dabei ist der Laden recht unscheinbar: "
    "Hinter einer kleinen Theke aus Holz steht normalerweise Achtarch vor "
    "spaerlich gefuellten Regalen. Knapp unter der Decke schwebt ein "
    "Chaosball, dessen Leuchten diesen Laden merkwuerdig verdunkelt.",78));
  AD(({"chaosball","ball"}),
    BS("Du betrachtest aufgeregt diesen Chaosball. Verdammt, hast "
    "du ein Schwein, ein echter Chaosball! Dummerweise besteht er aus "
    "Plastik. Heutzutage wird man aber auch ueberall beschissen...",78));
  AD(({"schlucker","muellschlucker"}),
   BS("Du siehst keinen Muellschlucker.",78));
  AD(({"plastik","kunststoff"}),
    BS("Billiger ging es wohl nicht.",78)); 
  AD(({"eiswueste"}),
   BS("Obwohl Du hier in der Festung bist kannst Du deutlich die feindliche "
    "Eiswueste spueren, die draussen auf ihre Opfer wartet.",78));
  AD(({"opfer"}),
   BS("Du koenntest das naechste Opfer sein.",78));
  AD(({"festung"}),
   BS("Du bist in der Festung des Chaos, falls Dir das noch nicht aufgefallen "
    "sollte.",78));
  AD(({"holz"}),
   BS("Gut, dass man nicht mehr bei 'unt holz' die bloede Beschreibung eines "
    "Bumerangs bekommt (sollte man denn gluecklicher Besitzer sein).",78));
  AD(({"theke"}),
   BS("Die Theke besteht aus Holz und ist so schlicht wie ihre "
    "Beschreibung.",78));
  AD(({"boden"}),
   BS("Der Boden ist noch da, keine Angst.",78));
  AD(({"wand","waende"}),
   BS("Die schlichten Waende verraten Achtarch als geizigen Haendler, der an "
    "allem spart. Ein Durchgang fuehrt nach Norden in ein Hinterzimmer, der "
    "andere Durchgang fuehrt zurueck in die grosse Halle.",78));
  AD(({"durchgang","durchgaenge"}),
   BS("Ein Durchgang fuehrt nach Norden in ein Hinterzimmer, der andere "
    "Durchgang fuehrt zurueck in die grosse Halle.",78));
  AD(({"halle"}),
   BS("Die Halle ist im Westen.",78));
  AD(({"schrift","hinterzimmer"}),
   "Erst jetzt bemerkst Du die Schrift ueber dem Durchgang:\n\n"
   "\t\tZur schaebigen Kneipe der Chaoten.\n");
  AD(({"decke"}),
   BS("Die schlichte Decke befindet sich ueber Dir, wie es fuer Decken "
    "ueblich ist. Jedenfalls bei Decken von Raeumen, auf Wolldecken kann man "
    "sich natuerlich auch stellen.",78));
  AD(({"wolldecke","wolldecken"}),
   BS("Du stehst auf einer Wolldecke. Aeh, doch nicht. Ist nur schlichter "
    "Boden.",78));
  AD(({"regale","regal"}),
   BS("Auf den Regalen befinden sich zahlreiche Gegenstaende, die man hier "
    "sicherlich kaufen kann.",78));
  AD(({"gegenstand","gegenstaende"}),
   BS("Schau sie Dir mit den ladenueblichen Befehlen an.",78));

  ARD("schrift","Zur schaebigen Kneipe der Chaoten.\n"); 

  ASE("norden","kneipe"); 
  AE("westen",CHAOS_GILDEN_ROOM("challe"));

  AddCmd(({"lies","lese","les","zeige","zeig"}),"liste");
  AddCmd(({"zeig","zeige","liste","preisliste"}),"liste");
  AddCmd(({"kaufe","kauf"}),"kaufen");
  AddCmd(({"verkaufe","verkauf","versetze","versetz"}),"verkaufe");
  AddCmd(({"klau","klaue","stehl","stehle"}),"diebe");

  RemoveItem("/obj/entsorg");
  AddItem(CHAOS_GILDEN_MON("achtarch"),REFRESH_REMOVE);

  SetUpStorage();

  seteuid(getuid(this_object()));
}

static string was(string str,int ge){
 string st;
  switch(ge){
    case 0: st = str; break;
    case 1: st = "einen "+str; break;
    case 2: st = "eine "+str; break;
    default: st = "ein "+str; break;
   }
 return st;
}

static string wen(string str,int ge){
 string st;
  switch (ge){
    case 0: st = "ein "+str; break;
    case 1: st = "einen "+str; break;
    case 2: st = "eine "+str; break;
    default: st = "einen "+str; break;
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
  output = sprintf("\n                            Preisliste:   \n\n",str)+
  
  "Nr.       Artikel					      Preis\n"+
  "--------------------------------------------------------------------------\n";
  item = QueryProp(A_ITEMS);
  for(i=1;i<=sizeof(item);i++){
      dum = zeile(i,item[i-1]); 
      output += dum;
  }
 return output;
}


void reset(){
  ::reset();
  if(MONEY>0){
    ZENTRALBANK->PayIn(MONEY);
    MONEY=0;
   }
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
 items = QueryProp(A_ITEMS);
 if(items[what][0]<1){
    tell_object(pl,"Tut mir leid, das ist leider ausverkauft.\n");
   return 1;
  }
 if(pl->QueryMoney()<items[what][4]){
    tell_object(pl,
     sprintf("Du brauchst dazu mindestens %d Muenzen!\n",items[what][4]));
   return 2; 
  }
  pl->AddMoney(-items[what][4]);
  ob = clone_object(items[what][1]);
  if(!ob) return 0;
  items[what][0] --;
  SetProp(A_ITEMS,items);
  tell_object(pl,"Du kaufst "+wen(items[what][2],items[what][5])+".\n");
  if(!IS_WIZARD(pl)) 
  MONEY=MONEY+(items[what][4]);
  if(ob->move(pl,M_GET)<=0){
    tell_object(pl,"Achtarch sagt: Du kannst das nicht mehr tragen, ich lege "
     +"es hier ab!\n");
    ob->move(this_object(),M_NOCHECK);
   }
  say(pl->name()+" kauft "+wen(items[what][2],items[what][5])+".\n",pl); 
 return 3;
}

static int kaufen(string str){
 int i,j;
 mixed things;
 notify_fail("Was moechtest Du kaufen?\n");
 if(!str) return 0;
 if(sscanf(str,"%d",i)){
    if(!present("\nchaos_gilden_achtarch")){
       if(!QueryProp("chaos_haendler_tot"))
          write("Der Haendler Achtarch ist zur Zeit nicht da.\n");
       else write("Der Haendler Achtarch wurde leider von "
          +capitalize(QueryProp("chaos_haendler_tot"))+" umgebracht.\n");
      return 1;
     }
    things = QueryProp(A_ITEMS);
    if((i<=0)||(i>sizeof(things))) return 0;
    j=do_buy(i-1,this_player());
    if(j) return 1;
   return 0;
  }
  if(sscanf(str,"%s",str)){
    things = QueryProp(A_ITEMS);
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


string int_long(mixed viewer, mixed viewpoint){
 return ::int_long(viewer, viewpoint)+"Kein Muellschlucker.\n";
}

kneipe(){
 string gilde;
 gilde=this_player()->QueryProp(P_GUILD);
 if(gilde=="chaos"||gilde=="bierschuettler"||gilde=="abenteurer"||
    gilde=="katzenkrieger"){
      if(deep_present("sarg",this_player())){
         write("Tsts, da hast Du wohl etwas dabei, was absoluter Mist ist.\n");
        return 1;
       }
      this_player()->move(CHAOS_GILDEN_ROOM("ckneipe"),M_GO);
     return 1;
    }
  this_player()->move(CHAOS_GILDEN_ROOM("ckneipe_fake"),M_GO);
 return 1;
}

static int verkaufe(string str){
 notify_fail("Was moechtest Du denn verkaufen?\n");
 if(!str) return 0;
 if(!present("\nchaos_gilden_achtarch")){
    if(!QueryProp("chaos_haendler_tot"))
       write("Der Haendler Achtarch ist zur Zeit nicht da.\n");
    else write("Der Haendler Achtarch wurde leider von "
       +capitalize(QueryProp("chaos_haendler_tot"))+" umgebracht.\n"); 
   return 1;
  }
  write(BS("Ich kaufe keine Gegenstaende. Was soll ich auch mit dem ganzen "
   "Dreck, den werde ich ja nie wieder los! Also geh in einen anderen Laden "
   "und versuche dort den Haendler zu besch*piep*.",78,"Achtarch sagt: "));
 return 1;
}

static int diebe(string str){
 notify_fail("Was willst Du stehlen?\n");
 if(!str) return 0;
  write("Man bestiehlt keine Chaoten, das ist ungesund!\n");
 return 1;
}

 