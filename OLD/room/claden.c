// ctrib.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet
 
#include "def.h"

inherit CHAOS_GILDEN_ROOM("std/std_chaos");

#define A_ITEMS           "_achtarch_items_"

static int MONEY = 0;

static void SetUpStorage()
{
  SetProp(A_ITEMS,({  
    ({4,CHAOS_GILDEN_OBJ("klbutton"),"'Kleriker sind Weicheier'-Button",
      ({"button","klerikerbutton"}),30,MALE}),
    
    ({2,CHAOS_GILDEN_OBJ("komponenten/skerze"),"schwarze Kerze",
      ({"kerze","schwarze kerze"}),690,FEMALE}),
    
    ({15,CHAOS_GILDEN_OBJ("komponenten/kreide"),"Stueck Kreide",
      ({"kreide","stueck kreide"}),60,NEUTER}),
    
    ({2,CHAOS_GILDEN_OBJ("komponenten/sstaub"),"Beutel mit Silberstaub",
      ({"silberstaub"}),2400,MALE}),
    
    ({1,CHAOS_GILDEN_OBJ("komponenten/sand"),"Beutel mit Sand",
      ({"sand","sandbeutel"}),999,MALE}),
    
    ({1,"/obj/fackel","Fackel",({"fackel"}),25,FEMALE}),
    
    ({4,"/obj/seil","Seil",({"seil"}),425,NEUTER})
    }));
}

protected void create() {
  ::create();
  SetProp(P_LIGHT,0);
  SetProp(P_INT_SHORT,"Im Laden der Chaosfestung");
  SetProp(P_INT_LONG,
  "Dies ist der beruehmte Laden 'Nuetzliche Zutaten fuer boese "
  "Zaubersprueche'. Seine Beruehmtheit erlangte der Laden dadurch, dass er "
  "trotz seiner aeusserst unguenstigen Lage in einer boesartigen Festung "
  "mitten in der Eiswueste unglaublich gute Umsaetze macht und so sein "
  "Besitzer, der Haendler Achtarch, vor einigen Jahren die Medaille der "
  "Ladenbesitzer-Vereinigung des MorgenGrauens fuer besonders herausragende "
  "Leistungen verliehen bekam. Dabei ist der Laden recht unscheinbar: "
  "Hinter einer kleinen Theke aus Holz steht normalerweise Achtarch vor "
  "spaerlich gefuellten Regalen. Knapp unter der Decke schwebt ein "
  "Chaosball, dessen Leuchten diesen Laden merkwuerdig verdunkelt.");
  
  AddDetail(({"chaosball","ball"}),
  "Du betrachtest aufgeregt diesen Chaosball. Verdammt, hast du ein "
  "Schwein, ein echter Chaosball! Dummerweise besteht er aus Plastik. "
  "Heutzutage wird man aber auch ueberall beschissen...");
  
  AddDetail(({"schlucker","muellschlucker"}),
  "Du siehst keinen Muellschlucker.");

  AddDetail(({"plastik","kunststoff"}),
  "Billiger ging es wohl nicht.");

  AddDetail(({"eiswueste","wueste"}),
  "Obwohl du hier in der Festung bist kannst du deutlich die feindliche "
  "Eiswueste spueren, die draussen auf ihre Opfer wartet.");

  AddDetail(({"opfer"}),
  "Du koenntest das naechste Opfer sein.");
  
  AddDetail(({"festung"}),
  "Du bist in der Festung des Chaos, falls Dir das noch nicht aufgefallen "
  "sollte.");

  AddDetail(({"holz"}),
  "Gut, dass man nicht mehr bei 'unt holz' die bloede Beschreibung eines "
  "Bumerangs bekommt (sollte man denn gluecklicher Besitzer sein).");

  AddDetail(({"theke"}),
  "Die Theke besteht aus Holz und ist so schlicht wie ihre Beschreibung.");

  AddDetail(({"boden"}),
  "Der Boden ist noch da, keine Angst.");
  
  AddDetail(({"wand","waende"}),
  "Die schlichten Waende verraten Achtarch als geizigen Haendler, der an "
  "allem spart. Ein Durchgang fuehrt nach Norden in ein Hinterzimmer, der "
  "andere Durchgang fuehrt zurueck in die grosse Halle.");
  
  AddDetail(({"durchgang","durchgaenge"}),
  "Ein Durchgang fuehrt nach Norden in ein Hinterzimmer, der andere "
  "Durchgang fuehrt zurueck in die grosse Halle.");
  
  AddDetail(({"halle"}),
  "Die Halle ist im Westen.");
  
  AddDetail(({"schrift","hinterzimmer"}),
   "\nErst jetzt bemerkst Du die Schrift ueber dem Durchgang:\n\n"
   "\t\tZur schaebigen Kneipe der Chaoten.\n");

  AddDetail(({"decke"}),
  "Die schlichte Decke befindet sich ueber Dir, wie es fuer Decken "
  "ueblich ist. Jedenfalls bei Decken von Raeumen, auf Wolldecken kann man "
  "sich natuerlich auch stellen.");
  
  AddDetail(({"wolldecke","wolldecken"}),
  "Du stehst auf einer Wolldecke. Aeh, doch nicht. Ist nur schlichter "
  "Boden.");

  AddDetail(({"regale","regal"}),
  "Auf den Regalen befinden sich zahlreiche Gegenstaende, die man hier "
  "sicherlich kaufen kann.");

  AddDetail(({"gegenstand","gegenstaende"}),
 "Schau sie Dir mit den ladenueblichen Befehlen an.");

  AddReadDetail("schrift",
  "Zur schaebigen Kneipe der Chaoten."); 

  AddSpecialExit("norden",
  "kneipe"); 
  
  AddExit("westen",CHAOS_GILDEN_ROOM("challe"));

  AddCmd(({"lies","lese","les","zeige","zeig"}),"liste");
  AddCmd(({"zeig","zeige","liste","preisliste"}),"liste");
  AddCmd(({"kaufe","kauf"}),"kaufen");
  AddCmd(({"verkaufe","verkauf","versetze","versetz"}),"verkaufe");
  AddCmd(({"klau","klaue","stehl","stehle"}),"diebe");

  AddItem(CHAOS_GILDEN_MON("achtarch"),REFRESH_REMOVE);

  SetUpStorage();

  seteuid(getuid(ME));
}

static string was(string str,int ge)
{
  string st;
 
  switch(ge)
  {
    case 0:  st = "ein "  +str; break;
    case 1:  st = "einen "+str; break;
    case 2:  st = "eine " +str; break;
    default: st = "ein "  +str; break;
  }
  return st;
}

static string wen(string str,int ge)
{
  string st;
  switch (ge)
  {
    case 0:  st = "ein "   +str; break;
    case 1:  st = "einen " +str; break;
    case 2:  st = "eine "  +str; break;
    default: st = "einen " +str; break;
  }
  return st;
}

static string zeile(int i,mixed item)
{
  string out;
  int j;

  out = sprintf("%2d.       %s",i,capitalize(was(item[2],item[5])));

  for(j=0;j<(52-sizeof(was(item[2],item[5])));j++)
    out += " ";
  
  if (item[0] > 0)
    out += sprintf("%4d\n",item[4]);
 
  else
    out += "ausverkauft\n";
  
  return out;
}

static string list_things()
{
  string output,dum;
  mixed item;
  int i;
  string str;

  output = sprintf("\n                            Preisliste:   \n\n",str)+
  
  "Nr.       Artikel					      Preis\n"+
  "--------------------------------------------------------------------------\n";
  
  item = QueryProp(A_ITEMS);
  
  for(i=1;i<=sizeof(item);i++)
  {
    dum = zeile(i,item[i-1]); 
    output += dum;
  }
  return output;
}

static void PayIn()
{
  if(MONEY>0)
  {
    ZENTRALBANK->PayIn(MONEY);
    MONEY = 0;
  }
}

void reset()
{
  ::reset();
  PayIn();
  SetUpStorage();
}

varargs int remove(int bla)
{
  PayIn();
  return::remove(bla);
}

static int liste()
{
  notify_fail("Was willst Du lesen?\n");
  write(list_things());
  return 1;
}

static int do_buy(int what,object pl)
{
  object ob;
  mixed items;

  items = QueryProp(A_ITEMS);

  if(items[what][0]<1)
  {
    tell_object(pl,"Tut mir leid, das ist leider ausverkauft.\n");
    return 1;
  }
  if(pl->QueryMoney()<items[what][4])
  {
    tell_object(pl,
     sprintf("Du brauchst dazu mindestens %d Muenzen!\n",items[what][4]));
   return 2; 
  }
  pl->AddMoney(-items[what][4]);
  
  ob = clone_object(items[what][1]);
  
  if(!ob)
    return 0;
  
  items[what][0] --;
  
  SetProp(A_ITEMS,items);
  
  tell_object(pl,"Du kaufst "+wen(items[what][2],items[what][5])+".\n");
  
  if(!IS_WIZARD(pl)) 
    MONEY = MONEY+(items[what][4]);
  
  if(ob->move(pl,M_GET)<=0)
  {
    tell_object(pl,"Achtarch sagt: Du kannst das nicht mehr tragen, ich lege "
     +"es hier ab!\n");
    ob->move(ME,M_NOCHECK);
   }
  say(pl->Name(WER)+" kauft "+wen(items[what][2],items[what][5])+".\n",pl); 
  
  return 3;
}

static int kaufen(string str)
{
  int i,j;
  mixed things;

  notify_fail("Was moechtest Du kaufen?\n");

  if(!str) return 0;

  if(sscanf(str,"%d",i))
  {
    if(!present_clone(CHAOS_GILDEN_MON("achtarch")))
    {
      if(!QueryProp("chaos_haendler_tot"))
        write("Der Haendler Achtarch ist zur Zeit nicht da.\n");
      else write("Der Haendler Achtarch wurde leider von "
                 +capitalize(QueryProp("chaos_haendler_tot"))+" umgebracht.\n");
      return 1;
    }
    things = QueryProp(A_ITEMS);
    
    if((i<=0) || (i>sizeof(things)))
      return 0;
    
    j = do_buy(i-1,PL);

    if(j) return 1;
    
    return 0;
  }
  if(sscanf(str,"%s",str))
  {
    things = QueryProp(A_ITEMS);
  
    j = -1;
  
    for (i = 0;i<sizeof(things);i++)
    {
      if(member_array(str,things[i][3]) >= 0)
      {
        j = i;
        i = sizeof(things);
      }
    }
    
    if(j<0) return 0;
    
    i = do_buy(j,PL);
    
    if (i) return 1;
    
    return 0;      
  }
 return 0;
}

int kneipe()
{
  string gilde;
 
  gilde =PL->QueryProp(P_GUILD);
 
   if(gilde=="chaos"||gilde=="bierschuettler"||gilde=="abenteurer"||
      gilde=="katzenkrieger")
   {
     PL->move(CHAOS_GILDEN_ROOM("ckneipe"),M_GO);
     return 1;
   }
   PL->move(CHAOS_GILDEN_ROOM("ckneipe_fake"),M_GO);
   return 1;
}

static int verkaufe(string str)
{
  notify_fail("Was moechtest Du denn verkaufen?\n");
 
  if(!str)
    return 0;

  if(!present_clone(CHAOS_GILDEN_MON("achtarch")))
  {
    if(!QueryProp("chaos_haendler_tot"))
       write("Der Haendler Achtarch ist zur Zeit nicht da.\n");
 
    else write("Der Haendler Achtarch wurde leider von "
       +capitalize(QueryProp("chaos_haendler_tot"))+" umgebracht.\n"); 
 
   return 1;
  }
  write(break_string("Ich kaufe keine Gegenstaende. Was soll ich auch mit "
  "dem ganzen Plunder, den werde ich ja nie wieder los! Also geh in einen "
  "anderen Laden und versuche dort den Haendler zu besch*piep*.",0,
  "Achtarch sagt: "));
  
  return 1;
}

static int diebe(string str)
{
 notify_fail("Was willst Du stehlen?\n");

 if(!str)
   return 0;
  write("Man bestiehlt keine Chaoten, das ist ungesund!\n");
 
 return 1;
}
