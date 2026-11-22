                         
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <new_skills.h>
#include "gilde.h"
#include <wizlevels.h>
int zahl;
int healed;
void create()
{
	::create();
healed = 2;
SetProp(P_INT_SHORT, "In der Halle der Burg des Chaos");
SetProp( P_INT_LONG,
"Du stehst in einer riesigen gewoelbten Halle. Hoooch ueber Dir haengen\n"
+"mehrere Kronleuchter mit hunderten von schwarzen Kerzen, die in einem\n"
+"schwachen Lufthauch unruhig flackern. Im Sueden befindet sich ein\n"
+"Portal, das hinaus in die chaotische Burg fuehrt. In den kahlen\n"
+"Waenden befinden sich Durchgaenge, die in weitere Raeumlichkeiten dieses\n"
+"Gebaeudes zu fuehren scheinen.\n"
+"Eine Treppe fuehrt herauf auf eine grosse Galerie, welche ueber Dir die\n"
+"Waende umspannt.\n");
AddDetail(({ "raeumlichkeiten", "raeumlichkeit" }),
"Bewegung tut Deinem mueden Koerper gut, also geh ihn und schau nach.\n");
AddDetail( "koerper",
"Nerv nicht, sonst ist Dein Koerper bald eine Leiche.\n");
AddDetail( "leiche",
"Du hast es nicht anderes gewollt!!! In genau 60 Sekunden wirst Du sterben!!\n");
AddDetail( "luft",
"Du atmest noch, also gibts hier Luft.\n");
AddDetail( "gestein",
"Das Gestein ist hart wie Stein.\n");
AddDetail( "stein",
"Der Stein ist hart wie Fels.\n");
AddDetail( "fels",
"Der Fels ist hart wie Gestein.\n");
AddDetail( "boden",
"Du stehst auf einem steinernen Boden mit schwarzen und roten Fliesen,\n"
+"die immer ihre Farbe wechseln und so staendig andere Muster bilden.\n");
AddDetail(({ "fliesen", "fliese" }),
"Der Boden besteht aus roten und schwarzen Fliesen, die in regelmaessigen\n"
+"Abstaenden ihre Farbe wechseln und so seltsame Muster bilden.\n");
AddSpecialDetail( "muster", "muster" );
AddDetail( ({ "farben", "farbe" }),
"Die vorherrschende Farbe ist schwarz. Nur manche Fliesen sind rot.\n");
AddDetail(({ "durchgang", "durchgaenge" }),
"Es gibt hier vier Durchgaenge: Ueber dem Durchgang nach Westen liest Du\n"
+"'Der Gildenraum', ueber dem Druchgang nach Osten liest Du 'chaotische\n"
+"Bibliothek' und ueber dem im Sueden 'Burg des Chaos'.\n");
AddDetail( "gildenraum",
"Der Gildenraum befindet sich im Westen.\n");
AddDetail( "halle",
"Dies ist die Halle der Burg des Chaos.\n");
AddDetail( "decke",
"Die gewoelbte Decke laesst die riesige Halle noch groesser erscheinen.\n"
+"Die vielen Kronleuchter mit ihren schwarzen Kerzen verbreiten ein\n"
+"duesteres Licht. Eine grosse Galerie umspannt die Waende ueber Dir.\n");
AddDetail(({ "leuchter", "kronleuchter", "gestelle", "gestell" }),
"Die an der Decke haengenden Kronleuchter sind riesige Gestelle mit\n"
+"hunderten von duennen, meterlangen Armen an deren Enden sich je eine\n"
+"schwarze Kerze befindet. Sie machen den Eindruck von Spinnen, die\n"
+"ueber Deinem Kopf haengen und sich jederzeit herunter lassen koennten,\n"
+"um ihr unschuldiges Opfer zu packen. Durch das leichte Flackern der\n"
+"Kerzen scheinen sie sich wirklich zu bewegen und ihre Beine nach Dir\n"
+"auszustrecken.\n");
AddDetail( ({"chaotische burg","burg des chaos","burg"}),
"Die Burg schaust Du Dir am Besten von draussen an.\n");
AddDetail( "chaos",
"Chaos ist immer und ueberall!\n");
AddDetail(({ "spinnen", "spinne" }),
"Deine Phantasie geht mal wieder mit Dir durch.\n");
AddDetail(({ "arm", "arme" }),
"An den meterlangen Armen der Kronleuchter befindet sich je eine schwarze\n"
+"Kerze, die nur ein schwaches Licht verbreitet.\n");
AddDetail(({  "licht", "flackern" }),
"Von den hunderten schwarzen Kerzen geht ein duesteres, flackerndes Licht\n"
+"aus, das die grosse Halle noch unheimlicher wirken laesst. Es ist\n"
+"naemlich so duester, dass die Halle gar nicht erhellt wird.\n" );
AddDetail(({ "kerze", "kerzen" }),
"Obwohl hunderte von Kerzen an den Kronleuchtern brennen, verbreiten sie\n"
+"kein Licht. Ausserdem kannst Du keine einzige abgebrannte Kerze finden,\n"
+"als ob sie nie verloeschen wuerden.\n");
AddDetail(({ "wand", "waende" }),
"Die Waende sind voellig kahl, abgesehen von den vier Portraits, die in ihren,\n"
+"fauligen Rahmen vor sich hin schimmeln. Ausserdem bestehen sie zum grossen\n"
+"Teil aus Luft, auch Durchgang genannt. \n");
AddDetail(({"bilderrahmen","rahmen"}),
"Die schimmligen Rahmen fassen drei dreckige und eingestaubte Portraits.\n");
AddDetail(({"portrait","portraits","bild","bilder"}),
"Du kannst sie mit <bild 1-4> bewundern.\n");
AddDetail(({"bild 1","portrait 1"}),
"Dieses Bild ziert einen muerrisch dreinblickenden, alten Mann. Sein wallendes\n"
+"und ergrautes Haar faellt lang bis zum Boden. Aus glaenzenden Augen scheint\n"
+"Dich diese Gestalt abwartend zu mustern. Dir ist gar nicht wohl zumute bei\n"
+"dem Gedanken. Unter dem Portrait befindet sich noch eine winzige Inschrift:\n"
+"Gilden-Magier a.D. (Z)\n");
AddDetail(({"bild 2","portrait 2"}),
"Die kleine, untersetzte Gestalt auf diesem Portrait kommt Dir irgendwie sehr\n"
+"bekannt vor. Und als Du die Dose Bier in seiner rechten Hand bemerkst, weisst\n"
+"Du auch schon Bescheid. Dies ist wohl der besoffenste Magier, den das MG je\n"
+"gesehen hat. Mit leicht wirrem Blick schaut er Dich an und Du kannst Dir ein\n"
+"Schmunzeln nicht verkneifen. Unter dem Portrait befindet sich eine etwas\n"
+"groessere Inschrift: Gilden-Magier. (B)\n");
AddDetail(({"bild 3","portrait 3"}),
"Huch, was soll denn die Gestalt auf diesem Portrait darstellen? So sicher\n"
+"bist Du Dir da nicht. Sie sieht aus wie ein Mann, ist aber von ziemlich\n"
+"kleinem Wuchs. Maennlein oder Weiblein, das ist hier die Frage. Du gruebelst\n"
+"etwas und einigst Dich dann auf die Bezeichnung 'Tante'. Irgendwo hast Du\n"
+"dieses 'Etwas' auch schonmal gesehen, bloss wo? Ein Fluestern dringt an Dein\n"
+"Ohr und Du hoerst 'Das ist der boeseste und gemeinste Magier des MG!'. Unter\n"
+"dem Portrait befindet sich eine Inschrift: Gilden-Magier. (T)\n"); 
AddDetail(({"bild 4","portrait 4"}),
"Kaum wirfst Du einen Blick auf dieses Portrait, da setzen auch schon deine\n"+
"Fluchtreflexe ein. Du bist schon halb durchs Portal, bevor Du Dich wieder\n"+
"faengst. Was Du hier siehst, ist aber auch ebenso wahnsinnig wie entsetzlich.\n"+
"Du siehst ein schreckliches, schwarzes ... Wesen, welches in einen schreiend\n"+
"roten Mantel gehuellt vor Dir kauert. Auf seinem gehoernten Schaedel sitzt\n"+
"ein unfoermiger Helm, in welchem sich ein magisches blaues Leuchten um sich\n"+
"selbst dreht. Schnell wendest Du den Blick ab, doch nicht, bevor Du die\n"+
"Inschrift unter dem Bild entziffert hast: Gilden-Magier. (F)\n");
AddDetail(({"blick"}),"Du wirfst einen Blick quer durch den Raum.\n");
AddDetail(({"raum"}),"Du befindest Dich in einer grossen Halle.\n");
AddDetail(({"wesen"}),"MEIN Gott! Wer kann das sein??\n");
AddDetail(({"mantel"}),"Ist der ROT! Mannomann!\n");
AddDetail(({"schaedel"}),
"Welch unfoermiges Koerperteil! Kann dieses Wesen denken? Du weisst es nicht.\n");
AddDetail(({"helm"}),"Im Helm siehst Du ein sich drehendes, blaues Leuchten.\n");
AddDetail(({"hoerner"}),"Wow, das Biest hat Hoerner!\n");
AddSpecialDetail(({"leuchten","licht"}),"show_me_the_light");

AddDetail(({"galerie"}),"Geh hoch und schau sie Dir an!\n");
AddDetail(({"treppe"}),"Diese Treppe fuehrt hoch in die Galerie!\n");

SetProp(P_LIGHT, 0);
SetProp( P_INDOORS, 1 );

AddExit( "westen", CHAOS_GILDEN_ROOM("cl2_gilde") );
AddSpecialExit( "osten","osten");

AddExit("oben",CHAOS_GILDEN_ROOM("cl2_galerie1"));

NewDoor( "sueden", CHAOS_GILDEN_ROOM("cl2bu5"), 
({ "portal", "tuer" }),
({
D_NAME, "Portal",
D_SHORT, "Ein %ses Portal.",
D_GENDER, 0,
D_LONG, "Dieses grosse Portal fuehrt nach draussen in die chaotische Burg.\n"}));
AddItem(CHAOS_GILDEN_MON("cl2_dwaechter2"),REFRESH_DESTRUCT);
 

}


int osten()
{
if( this_player()->QueryProp( P_GUILD) != "chaos" )
	{
	write( "Diesen Raum darfst Du nur als Gilden-Mitglied betreten.\n");
	return 1;
	}
this_player()->move( CHAOS_GILDEN_ROOM( "cl2_cbibo"), M_GO, "nach Osten" );
return 1;
}

string muster()
{
string s;
if( zahl > 5) zahl = 0;
switch( zahl)
	{
	case 0:
		s = "\n"+
	   "                       ::||||||||||::\n"+
	   "                       ::::::::||::::\n"+
	   "                       ::::::||::::::\n"+
	   "                       ::::||::::::::\n"+
	   "                       ::||||||||||::\n";
	break;
	case 1:
		s = "\n"+
	   "                       ::||||||||||::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::||||||||||::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::||::::::||::\n";
	break;
	case 2:
		s = "\n"+
	   "                       ::||||||||::::\n"+
	   "                       ::||::::||::::\n"+
	   "                       ::||||||::::::\n"+
	   "                       ::||::::||::::\n"+
	   "                       ::||::::::||::\n";
	break;
	case 3:
		s = "\n"+
	   "                       ::||||||||::::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::||||||||::::\n";
	break;
	case 4:
		s = "\n"+
	   "                       ::::||||||::::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::||::::::||::\n"+
	   "                       ::::||||||::::\n";
   break;
   case 5:
		s = "\n"+
	   "                       ::||||||||||::\n"+
	   "                       ::::::::||::::\n"+
	   "                       ::::::||::::::\n"+
	   "                       ::::||::::::::\n"+
	   "                       ::||||||||||::\n";
   break;
   }
zahl ++;
return s;
}


string show_me_the_light() {
  if (healed>0) {
    healed--;
    this_player()->heal_self(250);
    return "Das chaotische Leuchten erfasst Dich, durchdringt Dich, heilt Dich.\n";
  }
  return "Wow ist das blau.\n";
}

reset() {
  ::reset();
  healed=2;
}
