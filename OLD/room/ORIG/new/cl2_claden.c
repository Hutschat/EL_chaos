
inherit "/std/laden";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include "gilde.h"



create()
{
	::create();

SetProp(P_INT_SHORT, "Im Laden");
SetProp( P_INT_LONG,
"Dies ist der beruehmte Laden 'Nuetzliche Zutaten fuer boese Zaubersprueche'.\n"
+"Seine Beruehmtheit erlangte der Laden dadurch, dass er trotz seiner\n"
+"aeusserst unguenstigen Lage in einer boesartigen Festung mitten in der\n"
+"Eiswueste unglaublich gute Umsaetze macht und so sein Besitzer, der\n"
+"Haendler Achtarch, vor einigen Jahren die Medaille der Ladenbesitzer-\n"
+"Vereinigung des MorgenGrauens fuer besonders herausragende Leistungen\n"
+"verliehen bekam. Dabei ist der Laden recht unscheinbar: Hinter einer\n"
+"kleinen Theke aus Holz steht normalerweise Achtarch vor spaerlich\n"
+"gefuellten Regalen.\n");
SetProp( P_INDOORS, 1 );
SetProp( P_LIGHT, 0);
AddDetail( "eiswueste",
"Obwohl Du hier in der Festung bist kannst Du deutlich die feindliche\n"
+"Eiswueste spueren, die draussen auf ihre Opfer wartet.\n");
AddDetail( "opfer",
"Du koenntest das naechste Opfer sein.\n");
AddDetail( "festung",
"Du bist in der Festung des Chaos, falls Dir das noch nicht aufgefallen\n"
+"sollte.\n");
AddDetail( "holz",
"Gut, dass man nicht mehr bei 'unt holz' die bloede Beschreibung eines\n"
+"Bumerangs bekommt (sollte man denn gluecklicher Besitzer sein).\n");
AddDetail( "theke",
"Die Theke besteht aus Holz und ist so schlicht wie ihre Beschreibung.\n");
AddDetail( "boden",
"Der Boden ist noch da, keine Angst.\n");
AddDetail(({ "wand", "waende" }),
"Die schlichten Waende verraten Achtarch als geizigen Haendler, der an\n"
+"allem spart. Ein Durchgang fuehrt nach Norden in ein Hinterzimmer,\n"
+"der andere Durchgang fuehrt zurueck in die grosse Halle.\n");
AddDetail(({ "durchgang", "durchgaenge" }),
"Ein Durchgang fuehrt nach Norden in ein Hinterzimmer, der andere Durchgang\n"
+"fuehrt zurueck in die grosse Halle.\n");
AddDetail( "halle",
"Die Halle ist im Westen.\n");
AddDetail(({ "schrift", "hinterzimmer" }),
"Erst jetzt bemerkst Du die Schrift ueber dem Durchgang:\n"
+"Zur schaebigen Kneipe der Chaoten.\n");
AddReadDetail( "schrift", "Zur schaebigen Kneipe der Chaoten.\n"); 
AddDetail( "decke",
"Die schlichte Decke befindet sich ueber Dir, wie es fuer Decken ueblich\n"
+"ist. Jedenfalls bei Decken von Raeumen, auf Wolldecken kann man sich\n"
+"natuerlich auch stellen.\n");
AddDetail(({ "wolldecke", "wolldecken" }),
"Du stehst auf einer Wolldecke. Aeh, doch nicht. Ist nur schlichter Boden.\n");
AddDetail(({ "regale", "regal" }),
"Auf den Regalen befinden sich zahlreiche Gegenstaende, die man hier\n"
+"sicherlich kaufen kann.\n");
AddDetail(({ "gegenstand", "gegenstaende" }),
"Schau sie Dir mit den ladenueblichen Befehlen an.\n");
//AddSpecialExit( "norden","kneipe");
AddExit( "westen", CHAOS_GILDEN_ROOM( "cl2bu7" ));
AddCmd(({ "verk", "verkaufe", "verkauf", "versetze", "versetz" }), "verkaufe" );
AddCmd(({ "kaufe", "kauf" }), "kaufe" );
AddItem( CHAOS_GILDEN_MON( "achtarch"), REFRESH_REMOVE);
SetStorageRoom( CHAOS_GILDEN_ROOM( "cstore" ));
}

kneipe(){
  string gilde;
  gilde=this_player()->QueryProp(P_GUILD);
  if(gilde=="chaos"||gilde=="bierschuettler"||gilde=="abenteurer"||
     gilde=="katzenkrieger"){
    if(deep_present("sarg",this_player())){
      write("Tsts, da hast Du wohl etwas dabei, was absoluter "+
      "Mist ist.\n");
      return 1;
    }
    this_player()->move(CHAOS_GILDEN_ROOM( "ckneipe" ),M_GO);
    return 1;
  }
  this_player()->move(CHAOS_GILDEN_ROOM( "ckneipe_fake" ),M_GO);
  return 1;
}
verkaufe(string str)
{
if( !present( "\nchaos_gilden_achtarch", this_object()))
	{
	if( !QueryProp( "chaos_haendler_tot" ))
		write( "Der Haendler Achtarch ist zur Zeit nicht da.\n");
	else write( "Der Haendler Achtarch wurde leider von "+
		capitalize(QueryProp( "chaos_haendler_tot"))+" umgebracht.\n"); 
	return 1;
	}
write( break_string( "Ich kaufe keine Gegenstaende. Was soll ich auch mit "+
	"dem ganzen Dreck, den werde ich ja nie wieder los! Also geh in einen "+
	"anderen Laden und versuche dort den Haendler zu besch*piep*.",
	78, "Achtarch sagt: "));
return 1;
}


kaufe(string str)
{
if( !present( "\nchaos_gilden_achtarch", this_object()))
	{
	if( !QueryProp( "chaos_haendler_tot" ))
		write( "Der Haendler Achtarch ist zur Zeit nicht da.\n");
	else write( "Der Haendler Achtarch wurde leider von "+
		capitalize(QueryProp( "chaos_haendler_tot"))+" umgebracht.\n"); 
	return 1;
	}
return ::buy(str);
}



