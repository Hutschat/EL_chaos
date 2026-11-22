// Sting/Waffenlager-Raum (Chaosgilde)
// -----------------------------------

#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";

int klappe;
int healed;  // schon einmal pro reset geheilt?

create() {
  ::create();
  healed = 3;
  SetProp( P_INT_SHORT, "Das beruehmte Waffenarsenal der Chaosgilde" );
  SetProp( P_INT_LONG, BS("Du hast das Waffenlager der Chaosgilde "+
  	   "betreten. Es war vor langer, langer Zeit einmal bis ueber "+
  	   "alle Grenzen des Landes hinaus bekannt, doch hinzwischen "+
  	   "haben es seltsamerweise die meisten Leute vergessen... "+
  	   "Der ganze Raum ist regelrecht vollgestopft mit allerlei "+
  	   "Waffen und auch einigen Ruestungen. Allerdings "+
  	   "liegt alles einfach nur chaotisch auf dem Boden rum. "+
  	   "Ausserdem siehst du in der Ecke einen Untoten stehen, "+
  	   "der in typischer Kaempfertracht gekleidet ist.",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "ecke" }), BS(
	  "In der einen steht der Untote, die anderen sind mit Waffen "
  	+ "uebersaeht.",78));
  AddDetail( ({ "kaempfertracht" }), BS(
	  "Zumindest sieht es so aus, ganz sicher bist du dir "
  	+ "nicht.",78));
  AddDetail( ({ "decke" }), BS(
  	"Hmm, die ist ueber dir, und da haengt auch eine riesige "
	  + "Axt an einem Faden.",78));
  AddDetail( ({ "faden" }), BS(
  	"Sehr duenn... Mach hier lieber nichts falsches!",78));
  AddDetail( ({ "material" }), BS(
  	"Unbekannt.",78));
  AddDetail( ({ "axt" }), BS(
  	"Welche Axt meinst du denn ? Eine von denen auf dem Boden, "
  	+ "oder die an der Decke?",78));
  AddDetail( ({ "axt an der decke" }), BS(
  	"Das ist die unberuehmte Axt des Damokles!",78));
  AddDetail( ({ "damokles" }), BS(
  	"Ach nee, das war ja ein Schwert, naja hier ist eben "
  	+ "NICHTS normal... Damokles ist uebrigens auch ein "
  	+ "Mitglied der Chaosgilde.",78));
  AddDetail( ({ "Schwert" }), BS(
	  "Praezisiere das!",78));
  AddDetail( ({ "nichts" }), BS(
  	"Hier ist nicht nichts.",78));
  AddDetail( ({ "mitglied" }), BS(
  	"Wenn du in diesen Raum gekommen bist, solltest du "
  	+ " eigentlich ein Mitglied dieser Gilde sein...",78));
  AddDetail( ({ "gilde", "chaosgilde" }), BS(
	  "Du befindest dich in ihr, und gehoerst ihr auch an "
	  + "Sei stolz darauf, und ziehe aus, um boese und gemeine "
	  + "Taten zu vollbringen!",78));
  AddDetail( ({ "taten" }), BS(
  	"Naja, was typisches halt... (Jungfrauen schaenden, "
  	+ "Heilige toeten...",78));
  AddDetail( ({ "jungfrauen", "heilige" }), BS(
	  "Die wirst du hier nicht finden!",78));
  AddDetail( ({ "wand" }), BS(
	  "Hier gibts Waende, ja, aber an denen ist nix besonderes, "
	  + "sie bestehen einfach aus normalem dunklen Gestein.",78));
  AddDetail( ({ "gestein" }), BS(
	  "Ein dunkles, mit Kratzen und Rillen uebersaehtes "
	  + "Gestein.",78));
  AddDetail( ({ "kratzer" }), BS(
	  "Die vielen Kratzer kommen wohl von irgendwelchen, "
  	+ "amoklaufenden Chaoten, die hier Waffen getestet "
  	+ "haben...",78));
  AddDetail( ({ "chaoten" }), BS(
  	"Tja, du bist hier NICHT alleine...",78));
  AddDetail( ({ "rillen" }), BS(
	  "Du streichst ueber die Rillen, ploetzlich entdeckst du "
	  + "einen winzigen Hebel, der dir bisher nicht aufgefallen "
  	+ "war.",78));
  AddDetail( ({ "hebel" }), BS(
  	"Der Hebel fuehlt sich seltsam kalt an, vielleicht solltest "
  	+ "du besser Abstand halten...",78 ));
  AddDetail( ({ "abstand" }), BS(
  	"So ein bis zwei Meter sollten reichen, das du ihn nicht "
  	+ "aus Versehen beruehrst.",78));
  AddDetail( ({ "meter" }), BS(
  	"Du weisst nicht was ein Meter ist??? Du IDIOT!",78));
  AddDetail( ({ "idiot" }), BS(
	  "Du untersucht wohl jeden Mist was?",78));
  AddDetail( ({ "versehen" }), BS(
	  "Glaub mir, so ein Versehen ist _schnell_ passiert...",78));
  AddDetail( ({ "mist" }), BS(
  	"Wirklich JEDEN?",78));
  AddDetail( ({ "jeden mist" }), BS(
  	"Tatsaechlich, du spinnst echt.",78));
  AddDetail( ({ "boden" }), BS(
  	"Wow, hier liegt echt jede Menge Zeugs rum, allerlei Waffen "
  	+ "und auch einige Ruestungen.",78));
  AddDetail( ({ "zeugs" }), BS(
  	"Naja, Waffen und Ruestungen halt.",78));
  AddDetail( ({ "menge" }), BS(
  	"Eine wirklich GROSSE Menge!",78));
  AddDetail( ({ "ruestungen" }), BS(
  	"Du siehst tiefschwarze, Bosheit ausstrahlende Panzer, "
  	+ "eklige, mit Schleim ueberzogene Handschuhe, und sogar "
  	+ "einen der legendaeren Umhaenge des Todes.",78));
  AddDetail( ({ "panzer" }), BS(
  	"Tiefschwarz sind sie, und du kannst die Bosheit, die "
  	+ "daraus hervorstrahlt, foermlich spueren. Ein leichtes "
  	+ "Kribbeln laeuft dir ueber den Ruecken. Genau sowas "
  	+ "koenntest du gebrauchen.",78));
  AddDetail( ({ "bosheit" }), BS(
	  "Ja, das gefaellt dir, was?",78));
  AddDetail( ({ "kribbeln" }), BS(
  	"Ein unheimliches Kribbeln halt.",78));
  AddDetail( ({ "ruecken" }), BS(
	  "Den kannst du in den dir moeglichen Haltungen nur schlecht "
  	+ "sehen.",78));
  AddDetail( ({ "haltungen" }), BS(
  	"Naja, was du halt so kannst: stehen, sitzen, liegen und " 
  	+ "einige andere daemonische Haltungen, die wir hier nicht "
  	+ "naeher beschreiben wollen...",78));
  AddDetail( ({ "daemonische haltungen" }), BS(
	  "Darauf gehen wir lieber nicht ein...",78));
  AddDetail( ({ "handschuhe" }), BS(
  	"Ekliger, gruener Schleim tropft von ihnen herab, "
  	+ "und doch sehen sie eigentlich sehr stabil aus. Es "
  	+ "sind wohl einige der fast vergessenen "
  	+ "Adamanthandschuhe",78));
  AddDetail( ({ "schleim" }), BS(
	  "Man ist der schoen eklig, sieht richtig lecker aus.",78));
  AddDetail( ({ "umhaenge" }), BS(
  	"Diese Umhaenge gibt es sogar in der jetzigen Zeit noch, "
  	+ "jedoch haben sie den Grossteil ihrer Macht eingebuesst. "
  	+ "Frueher konnte man damit auf Erden wandeln, ohne Gefahr "
  	+ "zu laufen, das Irgendetwas einen toeten kann!",78));	
  AddDetail( ({ "erden", "welt" }), BS(
  	"Nennt sich auch Morgengrauen.",78));
  AddDetail( ({ "zeit" }), BS(
	  "Frueher war sowieso alles besser :)",78));
  AddDetail( ({ "grossteil" }), BS(
	  "Circa 99,999999%.",78));
  AddDetail( ({ "macht" }), BS(
  	"Die Macht war zu gross, das ein Wurm wie du sie dir auch "
  	+ "nur andeutungsweise vorstellen kannst!",78));
  AddDetail( ({ "wurm" }),QueryProp(P_LONG));
  AddDetail( ({ "gefahr" }), BS(
  	"Es gibt viele Gefahren in unserer Welt.",78));
  AddDetail( ({ "irgendetwas" }), BS(
  	"Irgendetwas beobachtet dich... Pass lieber auf was du "
  	+ "machst!",78));
  AddDetail( ({ "toete irgendetwas" }), BS(
	  "*kicher daemonisch* War doch nur ein Scherz!",78));
  AddDetail( ({ "scherz", "witz", "spaesschen" }), BS(
	  "Ein Witz, Scherz, Spaesschen, du verstehst ?",78));
  AddDetail( ({ "waffen" }), BS(
  	"Du siehst einen Vollstrecker, eine Axtmeisteraxt, diverse "
  	+ "Grummeldolche, diverse Keulen und noch exotischere "
  	+ " Sachen. An manchen von ihnen klebt noch Blut.",78));
  AddDetail( ({ "Vollstrecker" }), BS(
  	"Das auf der ganzen Welt beruehmte Schwert des grauenvollen "
  	+ "Weghiers, das lebt, und nur von dem einen Willen "
  	+ "beherrscht wird, naemlich zu TOETEN.",78));
  AddDetail( ({ "weghier" }), BS(
  	"Jof sei Dank, ist der nicht hier.",78));
  AddDetail( ({ "jof", "boing", "rumata" }), BS(
  	"Einer der Goetter.",78));
  AddDetail( ({ "dank" }), BS(
  	"Ich spuck auf deinen Dank!",78));
  AddDetail( ({ "goetter" }), BS(
  	"Jof, Boing und Rumata.",78));
  AddDetail( ({ "willen" }), BS(
	  "TOETEN TOETEN TOETEN TOETEN TOETEN TOETEN TOETEN",78));
	
  AddSpecialDetail("axtmeisteraxt","det_axt");
  AddDetail( ({ "dolche", "grummeldolche" }), BS(
  	"Grummeldolche sind eine elegante Waffe, und vor allem "
  	+ "gibt es sie mit vielen Schadensarten, fuer Chaoskrieger "
  	+ "also sehr geeignet.",78));
  AddDetail( ({ "schadensarten" }), BS(
	  "Soviel wird hier nicht verraten.",78));
  AddDetail( ({ "chaoskrieger" }), BS(
  	"Dazu zaehlst auch du schon!",78));
  AddDetail( ({ "keulen" }), BS(
	  "Das uebliche: Feuerkeulen, Eiskeulen, riesige Keulen und "
  	+ "noch ein paar andere, die du nicht erkennen kannst.",78));
  AddDetail( ({ "andere" }), BS(
  	"Die kannst du wirklich nicht erkennen.",78));
  AddDetail( ({ "feuerkeulen", "eiskeulen" }), BS(
  	"Geh mal in die Schreckensspitze, da gibts sowas!",78));
  AddDetail( ({ "schreckensspitze" }), BS(
  	"Auch SSP genannt.",78));
  AddDetail( ({ "ssp" }), BS(
  	"Heisst soviel wie Schreckensspitze.",78));
  AddDetail( ({ "riesige keulen" }), BS(
  	"Einige Dunkeldaemonen benutzen die.",78));
  AddDetail( ({ "dunkeldaemonen" }), BS(
  	"Schwer zu beherrschende Daemonenart" ,78));
  AddDetail( ({ "daemonenart" }), BS(
  	"In der Galerie haengen die Gemaelde von einigen.",78));
  AddDetail( ({ "sachen" }), BS(
  	"Eine brennende Peitsche siehst du, und ein kurzes, "
  	+ "schwarzes Messer faellt dir auch noch auf.",78));
  AddDetail( ({ "peitsche" }), BS(
  	"Das koennte eine der legendaeren Peitschen des Balrog "
  	+ "sein",78));
  AddDetail( ({ "balrog" }), BS(
  	"Ein fuerchterliches Monster, bewaffnet mit einer "
  	+ "brennenden Peitsche und der ""Flamme von Uduun""",78));
  AddDetail( ({ "monster" }), BS(
  	"Davon gibts soviele, das wuerde eine Ewigkeit dauern.",78));
  AddDetail( ({ "ewigkeit" }), BS(
  	"Die waehrt ewig...",78));
  AddDetail( ({ "flamme", "uduun" }), BS(
  	"Die Flamme von Uduun, ein maechtiges einhaendiges und "
  	+ "trotzdem zweischneidiges Schwert mit einer Klinge aus "
  	+ "purem Feuer, das zu fuehren nur dunkle und boese "
  	+ "Gestalten in der Lage sind.",78));
  AddDetail( ({ "klinge" }), BS(
  	"Aus purem Feuer ist sie",78));
  AddDetail( ({ "feuer" }), BS(
  	"Das brennende Element.",78));
  AddDetail( ({ "element" }), BS(
  	"Feuer, Wasser, Erde und Luft.",78));
  AddDetail( ({ "wasser", "erde", "luft" }), BS(
  	"Das sind Elemente.",78));
  AddDetail( ({ "gestalten" }), BS(
  	"Als finsterer Krieger der dunklen Maechte des Chaos, "
  	+ "gehoerst auch DU zu diesen Gestalten!",78));
  AddDetail( ({ "maechte" }), BS(
  	"Dunkel sind sie...",78));
  AddDetail( ({ "chaos" }), BS(
  	"Das laesst sich schwer beschreiben :)",78));
  AddDetail( ({ "messer" }), BS(
  	"Dieses schwarze Messer ist dir wohl auch nur aufgrund "
  	+ "seiner angsteinfloessenden Aura aufgefallen.",78));
  AddDetail( ({ "aura" }), BS(
  	"Du vermutest, das du eines der vermissten Messer der "
  	+ "Angst vor dir siehst.",78));
  AddDetail( ({ "angst" }), BS(
  	"Die ueberkommt dich, bei dem Anblick dieser Waffe.",78));
  AddDetail(({"burg"}),BS("Da stehst Du drinn!",78));
  


  AddSounds( SENSE_DEFAULT,
	  	BS("Du glaubst, staendig ein Klirren, wie das "
  		+ "Aufeinandertreffen von Waffen zu hoeren.",78));
  AddSounds( ({ "klirren" }), "Das bildest Du dir wohl nur ein.");
	


  AddSmells( SENSE_DEFAULT, BS(
	  	"Wenn man hier ueberhaupt etwas riechen kann, "
  		+ "dann vielleicht das eingetrocknete Blut, "
  		+ "das teilweise noch an den Waffen klebt.",78));
  AddSmells( ({ "blut" }), BS(
  		"Riecht nicht besonders frisch.",78));

  AddSpecialDetail( ({ "klappe" }),"det_klappe");
  AddSpecialDetail( ({ "phiole" }),"det_phiole");
  AddSpecialDetail( ({ "fluessigkeit", "blut" }),"det_blut");


  AddCmd( ({ "zerschneide", "schneide" }), "damokles" );
  AddCmd( ({ "halte" }), "abstand" );
  AddCmd( ({ "ziehe" }), "hebel" );  
  AddCmd( ({ "druecke" }), "hebel2" );  
  AddCmd( ({ "rohrhoere" }), "rohrhoere" );

  AddCmd( ({ "trink", "trinke" }), "phiole" );  

  AddItem(CHAOS_GILDEN_MON("cl2_wlagernpc"),REFRESH_DESTRUCT);  
  
  NewDoor("sueden",CHAOS_GILDEN_ROOM("cl2bu4"),({"tuer"}),
  ({D_NAME,"Tuer",
    D_SHORT,"Im Sueden fuehrt die %se Tuer in die Burg zurueck",
    D_LONG,"Die Tuer sieht nicht naeher interessant aus.\n",
    D_FLAGS, DOOR_CLOSED | DOOR_RESET_CL
  }));
}

damokles( str )
{
  notify_fail( "Was willst du denn zerschneiden?\n" );
  if(!str) return 0;
  
  if(member(({"faden"}),str)!=-1)
  {
      write(BS("Du versuchst den Faden der Damokles-Axt durchzuschneiden, "+
             "jedoch schaffst du es nicht, er besteht wohl aus einem "+
             "unbekannten, widerstandsfaehigem Material.",78) );
      return 1; 
   }
   return 0; 
}  


abstand( str )
{
  notify_fail( "Du willst wohl Abstand halten?\n" );
  if(!str) return 0;
  if( str == "abstand" )
  {
     write( "Du gehst ein paar Schritte zurueck und haelst Abstand.\n" );
     return 1; 
  }
  return 0; 
}

rohrhoere( str )
{
  if (!str) {
    write("Eine Stimme fluestert: Dieser Raum wurde von Sting "
         +"geschrieben.\n" );
    return 1;
  }
  return 0; 
}


hebel( str )
{
  notify_fail( "Was willst Du denn ziehen?\n" );
  if(!str) return 0;
  if( str == "hebel" )
  {
    write( "Du ziehst an dem Hebel, doch nichts passiert.\n" );
    return 1; 
  }
  return 0; 
}


hebel2( str )
{
  notify_fail( "Was willst Du denn druecken?\n" );
  if(!str) return 0;
  if( str == "hebel" )
  {
    if (klappe)
    {
       write("Nichts passiert.\n");
       return 1;
    }  
    write( BS("Du drueckst den Hebel, ploetzlich oeffnet sich "
         + "an der oestlichen Wand eine bisher unsichtbare "
         + "Klappe.",78) );
    klappe = 1;
    call_out("zu",10);
    return 1;
  }
  return 0;
}

int zu()
{
  tell_room(this_object(),"Etwas schliesst sich.\n");
  klappe = 0;
  return 1;
}


string det_klappe()
{
  if ( klappe )  
    return BS("In der Klappe steht eine kleine Phiole mit einer roten "
              + "Fluessigkeit.",78);
  return 0;
}

string det_phiole()
{
  if (klappe)   
      return BS("Du koenntest probieren, sie zu trinken...",78);
  return 0;
}

string det_blut()
{
  if (klappe) 
      return BS("Das sieht aus wie Blut!.",78);
  return BS("Sieht nicht besonders frisch aus.",78);
}



phiole( str )
{

  notify_fail( "Was willst Du denn trinken?\n" );
  if(!str) return 0;
  
  if( str == "phiole" || str == "blut" )
  {
    if (klappe)
    {
      if (healed > 0)
      {
        write( BS("Also wenn das wirklich Blut, war, dann hat es jedenfalls "
             + "ausgezeichnet geschmeckt...",78) );
        this_player()->heal_self(20+random(20));
        healed--;
      }
      else
      {
        write("Baeeeh, das schmeckte ja ekelhaft!\n");
      }
      return 1; 
    }
    return 0; 
  }
  return 0;
}


reset()
{
  ::reset();
  healed=3;
}  

string det_axt()
{
   say(BS(this_player()->Name(WER)+" kuckt sich eine nichtvorhandene "+
       "Axtmeisteraxt an. Du denkst . o O ( Der spinnt!).",78),this_player());
   return BS("Ups, die gibts ja (noch) gar nicht. *daemonisch grins*",78);
}



