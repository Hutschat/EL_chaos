// ceingang.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet

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
SetProp( P_INT_LONG,break_string(
  "Du stehst in einer riesigen gewoelbten Halle. Sie erinnert sehr an die "+
  "Halle der alten Chaosgilde, scheint jedoch noch groesser und hoeher zu "+
  "sein. Hoch ueber Dir umspannt eine Galerie die Waende, zu der eine schmale "+
  "Treppe hinauffuehrt. Von ihr herab haengen einige Kronleuchter, in denen "+
  "schwarze Kerzen unruhig flackern. Im Sueden fuehrt ein grosses Portal "+
  "hinaus aus der Halle, fort in die chaotische Burg. Nach Westen und Osten "+
  "fuehren Durchgaenge in weitere Raeumlichkeiten dieses Gebaeudes.",78));
AddDetail(({"raeumlichkeiten"}),break_string(
  "Wenn Du die weiteren Raeumlichkeiten dieser Burg kennenlernen willst, "+
  "so schau Dich nur gut um!",78));
AddDetail(({"halle"}),break_string(
  "Die Halle ist wirklich riesig und erschreckend "+
  "hoch. Eine Galerie zieht sich die Waende entlang ueber Dir. Dies ist "+
  "die Halle des Chaos in der Burg des Chaos. Erfurchtsvoll siehst Du Dich "+
  "um.",78));
AddDetail(({"chaosgilde"}),break_string(
  "Die Chaosgilde ist eine sehr alte, sehr maechtige und absolut boesartige "+
  "Gilde. Sie wird ueberall im Morgengrauen gefuerchtet und verachtet, denn "+
  "sie paktiert mit Daemonen und herrscht ueber die gewaltige, "+
  "zerstoererische Macht des Chaos.",78));
AddDetail(({"gilde"}),break_string(
  "Dies hier ist die Halle der Chaosgilde. Sie gehoert somit zur Gilde.",78));
AddDetail(({"morgengrauen"}),break_string(
  "Es befindet sich ueberall um Dich herum.",78));
AddDetail(({"daemonen","kreaturen"}),break_string(
  "Daemonen sind boesartige, blutruenstige, haessliche Kreaturen aus den "+
  "finsteren Dimensionen jenseits der Hoelle.",78));
AddDetail(({"dimensionen"}),break_string(
  "Es gibt viele Dimensionen, und einige sind wirklich verdammt uebel. Und "+
  "aus den uebelsten und fiesesten all dieser Dimensionen, da kommen die "+
  "Daemonen her.",78));
AddDetail(({"hoelle"}),break_string(
  "Viele Leute behaupten, von hier aus koennte man die Hoelle sehen. Das "+
  "ist natuerlich Unsinn. Die Hoelle ist von hier genausoweit entfernt "+
  "wie von jedem anderen Punkt im Morgengrauen. Nur der Weg ist leichter.",78));
AddDetail(({"unsinn"}),break_string(
  "Es gibt soviel Unsinn im Morgengrauen, da wird man ganz wuschig.",78));
AddDetail(({"punkt"}),break_string(
  ".",78));
AddDetail(({"leute"}),break_string(
  "Viele Leute behaupten viel.",78));
AddDetail(({"weg"}),break_string(
  "Der Weg zur Hoelle ist gepflastert mit guten Vorsaetzen, wie man so "+
  "schoen sagt.",78));
AddDetail(({"vorsaetze","gute vorsaetze"}),break_string(
  "Schoen das Du welche hast.",78));
AddDetail(({"macht"}),break_string(
  "Die Chaosgilde besitzt eine gewaltige, zerstoererische Macht.",78));
AddDetail(({"chaos"}),break_string(
  "Die Macht des Chaos ist unfassbar und gewaltig. Sie beherrscht das "+
  "Morgengrauen, erfuellt es mit ihrer Macht. Nichts kann sich mit ihm "+
  "vergleichen. Das Chaos ist der Anfang und das Ende, die einzige wahre "+
  "Macht auf dieser Welt. Alles andere ist Pfusch.",78));
AddDetail(({"welt"}),break_string(
  "It's a small world, after all.",78));
AddDetail(({"anfang","ende"}),break_string(
  "Das Chaos ist der Anfang und das Ende.",78));
AddDetail(({"pfusch"}),break_string(
  "Pfusch! Genau!",78));
AddDetail(({"galerie"}),break_string(
  "Die Galerie umspannt die gesamte Halle. Sie scheint nicht sonderlich "+
  "breit zu sein. An den Waenden ueber ihr scheinen Gemaelde zu haengen, "+
  "welche Du von hier aus jedoch nicht erkennen kannst. Eine schmale Treppe "+
  "fuehrt von hier aus hinauf auf die Galerie. Von der Galerie herab "+
  "haengen einige Kronleuchter, auf denen schwarze Kerzen unruhig flackern.",78));
AddDetail(({"gemaelde"}),break_string(
  "Die Gemaelde befinden sich oben auf der Galerie. Geh nur hoch und schau "+
  "sie Dir an. Hier unten wurden lediglich einige Portraits aufgehaengt, "+
  "welche natuerlich ebenfalls schoen anzusehen sind.",78));
AddDetail(({"treppe"}),break_string(
  "Die Treppe ist schmal und schief und krumm. "+
  "Sie besteht aus einem merkwuerdigem, schwarzen, krummen Holz, welches "+
  "von den merkwuerdigen verkrueppelten Baeumen ausserhalb der Burg zu "+
  "stammen scheint.",78));
AddDetail(({"holz","baeume"}),break_string(
  "Das Holz dieser Treppe scheint von den Baeumen ausserhalb der Burg "+
  "zu stammen. Du fragst Dich wirklich, warum man derart krummes Holz "+
  "benutzt, um eine Treppe zu bauen.",78));
AddDetail(({"leuchter","kronleuchter"}),break_string(
  "Die an der Galerie haengenden Kronleuchter sind riesige Gestelle mit "+
  "hunderten von duennen, meterlangen Armen an deren Enden sich je eine "+
  "schwarze Kerze befindet. Sie machen den Eindruck von Spinnen, die ueber "+
  "Deinem Kopf haengen und sich jederzeit herunter lassen koennten, um ihr "+
  "unschuldiges Opfer zu packen. Durch das leichte Flackern der Kerzen "+
  "scheinen sie sich wirklich zu bewegen und ihre Beine nach Dir "+
  "auszustrecken.",78));
AddDetail(({"eindruck"}),break_string(
  "Die Kronleuchter, so wie sie von den Kerzen auf ihnen beleuchtet werden, "+
  "erwecken den Eindruck, gewaltige, schwarze Spinnen zu sein, welche "+
  "nur darauf warten, sich auf Dich zu stuerzen.",78));
AddDetail(({"gestelle"}),break_string(
  "Die Gestelle sind gross und scheinen aeusserst schwer zu sein. Du "+
  "hoffst, dass sie die Galerie nicht eines Tages runterreissen. Sie "+
  "bestehen aus schwarzem Metall und sehen mit ihren vielen schwarzen "+
  "Armen wirklich aus wie gewaltige Spinnen, welche dort oben auf Dich "+
  "lauern.",78));
AddDetail(({"metall"}),break_string(
  "Das Metall ist schwarz, doch es koennte auch angestrichen worden sein. "+
  "Wie auch immer, es sieht verdammt schwer aus. Hoffentlich faellt es "+
  "nicht gleich auf Dich drauf.",78));
AddDetail(({"arme"}),break_string(
  "Jeder der Kronleuchter hat mehr viele Dutzend Arme aus einem schwarzen "+
  "Metall. Auf ihnen sitzen die schwarzen Kerzen, welche, unruhig flackernd, "+
  "so gut wie garkein Licht verbreiten.",78));
AddDetail(({"dutzend"}),break_string(
  "Du weisst, was ein Dutzend ist.",78));
AddDetail(({"kerzen"}),break_string(
  "Die Kerzen sind schwarz und flackern, obwohl sich "+
  "hier kein Lueftchen zu regen scheint. Sie verbreiten so gut wie kein "+
  "Licht, scheinen dafuer jedoch auch nicht herunterzubrennen. In ihrem "+
  "schwachen, flackernden Schein scheinen sich die Kronleuchter wie "+
  "lebendige, schwarze Spinnen zu bewegen...",78));
AddDetail(({"lueftchen"}),break_string(
  "Hier regt sich kein Lueftchen.",78));
AddDetail(({"licht","finsternis","dunkelheit"}),break_string(
  "Die Kerzen auf den Kronleuchtern hier verbreiten eigentlich kein "+
  "wirkliches Licht. Sie scheinen die herrschende Finsternis lediglich "+
  "etwas zu mildern.",78));
AddDetail(({"schein"}),break_string(
  "Der Schein der Kerzen ist schwach und flackernd.",78));
AddDetail(({"spinnen","spinne"}),break_string(
  "Die Kronleuchter sehen wirklich aus wie gewaltige Spinnen, welche "+
  "sich langsam auf Dich zubewegen. Du erschauerst unwillkuerlich.",78));
AddDetail(({"kopf"}),break_string(
  "Gib auf ihn Acht!",78));
AddDetail(({"opfer"}),break_string(
  "Es gibt zwei Regeln: 1) Es gibt immer ein Opfer. 2) Pass auf dass Du "+
  "es nicht bist.",78));
AddDetail(({"regeln"}),break_string(
  "1) Es gibt immer ein Opfer. 2) Pass auf dass Du es nicht bist.",78));
AddDetail(({"beine","bein"}),break_string(
  "Der Kronleuchter hat viele hundert Arme, und jeder dieser Arme wirkt "+
  "wie das Bein einer Spinne.",78));
AddDetail( "boden",
  "Du stehst auf einem steinernen Boden mit schwarzen und roten Fliesen,\n"
  +"die immer ihre Farbe wechseln und so staendig andere Muster bilden.\n");
AddDetail(({ "fliesen", "fliese" }), break_string(
  "Der Boden besteht aus roten und schwarzen Fliesen, die in regelmaessigen "+
  "Abstaenden ihre Farbe wechseln und so seltsame Muster bilden. Auch diese "+
  "Fliesen scheinen aus der alten Gilde hierhertransportiert worden zu "+
  "sein. Derartiges hast Du nirgendwo sonst in dieser Burg gesehen.",78));
AddDetail(({"abstaende"}),break_string(
  "Die Abstaende sind regelmaessig.",78));
AddSpecialDetail( "muster", "muster" );
AddDetail( ({ "farben", "farbe" }),
  "Die vorherrschende Farbe ist schwarz. Nur manche Fliesen sind rot.\n");
AddDetail(({ "durchgang", "durchgaenge" }), break_string(
  "Der westliche Durchgang fuehrt in die Chaosgilde selbst hinein. Nach "+
  "Osten geht es in die Bibliothek der Chaosgilde.",78));
AddDetail(({"bibliothek"}),break_string(
  "Die Chaosgilde besitzt eine grosse Bibliothek, auch wenn die Chaoten sie "+
  "bis jetzt nur sehr ungern nutzen. Sie befindet sich oestlich dieser "+
  "Halle.",78));
AddDetail(({"chaoten"}),break_string(
  "Dies hier ist die Chaosgilde, die Gilde der Chaoten.",78));
AddDetail(({  "flackern" }),
  "Von den hunderten schwarzen Kerzen geht ein duesteres, flackerndes Licht\n"
  +"aus, das die grosse Halle noch unheimlicher wirken laesst. Es ist\n"
  +"naemlich so duester, dass die Halle gar nicht erhellt wird.\n" );
AddDetail(({ "kerze", "kerzen" }),
   "Obwohl hunderte von Kerzen an den Kronleuchtern brennen, verbreiten sie\n"
   +"kein Licht. Ausserdem kannst Du keine einzige abgebrannte Kerze finden,\n"
  +"als ob sie nie verloeschen wuerden.\n");
AddDetail(({ "wand", "waende" }), break_string(
  "Die Waende sind auf den ersten Blick recht unansehnlich. Sie sind voellig "+
  "kahl, abgesehen von den vier Portraits, die in ihren fauligen Rahmen vor "+
  "sich hin schimmeln, und den Durchgaengen, welche aus dieser Halle fuehren. "+
  "Auf den zweiten Blick jedoch ist jedoch gerade diese Kahlheit etwas beson"+
  "deres. Denn die Waende bestehen nicht mehr aus den gewaltigen, tiefschwar"+
  "zen Felsbloecken wie alles andere hier in der Burg, sondern aus gewoehn"+
  "lichen, schwarzen Backsteinen. Diese scheinen aus den alten Gildenraeumen "+
  "entfernt worden zu sein und hierher gebracht worden zu sein, um die Halle "+
  "so wieder aufzubauen, wie sie vorher aussah (nur groesser). Was fuer ein "+
  "Aufwand!",78));
AddDetail(({"backsteine"}),break_string(
  "Normale, profane, schwarze Backsteine formen die Waende dieser Halle. "+
  "Das ist so erfrischend normal und gewoehnlich...",78));
AddDetail(({"aufwand"}),break_string(
  "Diese Burg zu bauen war sicher ein ungeheurer Aufwand. Du kannst Dir "+
  "nicht erklaeren, wie sie so schnell fertig werden konnte.",78));
AddDetail(({"blick"}),break_string(
  "Du blickst Dich aufmerksam um.",78));
AddDetail(({"kahlheit"}),break_string(
  "Dieser Raum ist, bis auf seine vier Portraits an den Waenden, sehr kahl.",78));
AddDetail(({"felsbloecke"}),break_string(
  "Die ultraschwarzen Felsbloecke, aus denen die gesamte restliche Gilde zu "+
  "bestehen scheint, sucht man hier vergebens. Diese Halle ist eine will"+
  "kommene Abwechslung vom tiefschwarzen Alltag dieser Burg.",78));
AddDetail(({"abwechslung"}),break_string(
  "Ein bisschen Abwechslung ist immer gut.",78));
AddDetail(({"alltag"}),break_string(
  "Der Alltag dieser Burg ist tiefschwarz, bedrohlich, toedlich und oede.",78));
AddDetail(({"burg","heim"}),break_string(
  "Dies ist die schwarze Burg, Heim der Chaosgilde.",78));
AddDetail(({"bilderrahmen","rahmen"}),
  "Die schimmligen Rahmen fassen vier dreckige und eingestaubte Portraits.\n"+
  "Du kannst sie einzeln untersuchen...\n");
AddDetail(({"rahmen 1","rahmen 2","rahmen 4"}),break_string(
  "Der Rahmen ist dreckig, speckig und alt. Du findest ihn nichts anderes "+
  "als eklig.",78));
AddDetail(({"rahmen 3"}),break_string(
  "Dieser Rahmen ist anders. Er ist stabil und aus gutem Holz geschnitzt. "+
  "Es sieht fast so aus, als wuerde er oft bewegt, quasi gezogen...",78));
AddDetail(({"portrait","portraits","bild","bilder"}),
  "Du kannst sie mit <bild 1-4> bewundern.\n");
AddDetail(({"bild 1","portrait 1"}),
  "Dieses Bild ziert einen muerrisch dreinblickenden, alten Mann. Sein wallendes\n"
  +"und ergrautes Haar faellt lang bis zum Boden. Aus glaenzenden Augen scheint\n"
  +"Dich diese Gestalt abwartend zu mustern. Dir ist gar nicht wohl zumute bei\n"
  +"dem Gedanken. Unter dem Portrait befindet sich noch eine winzige Inschrift:\n"
  +"Gilden-Magier a.D. (Z)\n");
AddDetail(({"gedanken"}),break_string(
  "Sie sind frei.",78));
AddDetail(({"augen"}),break_string(
  "Die Augen des alten Mannes glaenzen.",78));
AddDetail(({"bild 2","portrait 2"}),
  "Die kleine, untersetzte Gestalt auf diesem Portrait kommt Dir irgendwie sehr\n"
  +"bekannt vor. Und als Du die Dose Bier in seiner rechten Hand bemerkst, weisst\n"
  +"Du auch schon Bescheid. Dies ist wohl der besoffenste Magier, den das MG je\n"
  +"gesehen hat. Mit leicht wirrem Blick schaut er Dich an und Du kannst Dir ein\n"
  +"Schmunzeln nicht verkneifen. Unter dem Portrait befindet sich eine etwas\n"
  +"groessere Inschrift: Gilden-Magier. (B)\n");
AddDetail(({"bier","dose","bierdose","dose bier"}),break_string(
  "Diese Bierdose scheint niemals aus seiner Hand zu verschwinden.",78));
AddDetail(({"hand"}),break_string(
  "Die Hand haelt die Bierdose fest umklammert.",78));
AddDetail(({"schmunzeln"}),break_string(
  "Du laechelst.",78));
AddDetail(({"bild 3","portrait 3"}),
  "Huch, was soll denn die Gestalt auf diesem Portrait darstellen? So sicher\n"
  +"bist Du Dir da nicht. Sie sieht aus wie ein Mann, ist aber von ziemlich\n"
  +"kleinem Wuchs. Maennlein oder Weiblein, das ist hier die Frage. Du gruebelst\n"
  +"etwas und einigst Dich dann auf die Bezeichnung 'Tante'. Irgendwo hast Du\n"
  +"dieses 'Etwas' auch schonmal gesehen, bloss wo? Ein Fluestern dringt an Dein\n"
  +"Ohr und Du hoerst 'Das ist der boeseste und gemeinste Magier des MG!'. Unter\n"
  +"dem Portrait befindet sich eine Inschrift: Gilden-Magier. (T)\n"
  +"Irgend etwas ist an diesem Portrait ist merkwuerdig. Es ist weniger das Bild,\n"
  +"es ist mehr ... das drummherum?\n"); 
AddDetail(({"fluestern"}),break_string(
  "Es ist kaum zu verstehen.",78));
AddDetail(({"frage"}),break_string(
  "Mit 'Tante' bist Du dieser Frage geschickt ausgewichen.",78));
AddDetail(({"tante"}),break_string(
  "Vor Dir steht die Chaos-Tante Tilly.",78));
AddDetail(({"wuchs"}),break_string(
  "Die Tante auf diesem Portrait ist von kleinem Wuchs.",78));
AddDetail(({"maennlein","weiblein"}),break_string(
  "Du kannst Dich bei diesem Portrait einfach nicht zwischen Maennlein "+
  "oder Weiblein entscheiden!",78));
AddDetail(({"magier"}),break_string(
  "Auf jedem der Portraits sind Magier abgebildet.",78));
AddDetail(({"bezeichnung"}),break_string(
  "Sie lautet: 'Tante'.",78));
AddDetail(({"bild 4","portrait 4"}),
  "Kaum wirfst Du einen Blick auf dieses Portrait, da setzen auch schon deine\n"+
  "Fluchtreflexe ein. Du bist schon halb durchs Portal, bevor Du Dich wieder\n"+
  "faengst. Was Du hier siehst, ist aber auch ebenso wahnsinnig wie entsetzlich.\n"+
  "Du siehst ein schreckliches, schwarzes ... Wesen, welches in einen schreiend\n"+
  "roten Mantel gehuellt vor Dir kauert. Auf seinem gehoernten Schaedel sitzt\n"+
  "ein unfoermiger Helm, in welchem sich ein magisches blaues Leuchten um sich\n"+
  "selbst dreht. Schnell wendest Du den Blick ab, doch nicht, bevor Du die\n"+
  "Inschrift unter dem Bild entziffert hast: Gilden-Magier. (F)\n");
AddDetail(({"blick"}),
  "Du wirfst einen Blick quer durch den Raum.\n");
AddDetail(({"raum"}),
  "Du befindest Dich in einer grossen Halle.\n");
AddDetail(({"wesen"}),
  "MEIN Gott! Wer kann das sein??\n");
AddDetail(({"gott"}),break_string(
  "Den suchst Du HIER vergebens.",78));
AddDetail(({"mantel"}),
  "Ist der ROT! Mannomann!\n");
AddDetail(({"schaedel"}),
  "Welch unfoermiges Koerperteil! Kann dieses Wesen denken? Du weisst es nicht.\n");
AddDetail(({"koerperteil"}),break_string(
  "Du meinst damit den Schaedel.",78));
AddDetail(({"helm"}),
  "Im Helm siehst Du ein sich drehendes, blaues Leuchten.\n");
AddDetail(({"hoerner","biest"}),
  "Wow, das Biest hat Hoerner!\n");
AddSpecialDetail(({"leuchten","licht"}),
  "show_me_the_light");
AddDetail(({"reflexe","fluchtreflexe"}),break_string(
  "Du hast wirklich Muehe, sie zu kontrollieren.",78));
AddDetail(({"muehe"}),break_string(
  "*seufz* Es ist nicht leicht.",78));
AddDetail(({"gestalt","gestalten"}),break_string(
  "Das sind wirklich merkwuerdige Gestalten dort auf den Portraits.",78));
AddDetail(({"gilden"}),break_string(
  "Es gibt sicherlich viele Gilden hier im Morgengrauen, doch diese, "+
  "die Chaosgilde, ist die boesartigste von allen.",78));
AddDetail(({"gildenraeume"}),break_string(
  "Von denen gibt es hier jede Menge.",78));
AddDetail(({"menge"}),break_string(
  "Es gibt hier wirklich einige Gildenraeume.",78));
AddDetail(({"mann"}),break_string(
  "Auf jedem der Portraits ist ein Mann dargestellt. Glaubst Du...",78));
AddDetail(({"haar"}),break_string(
  "Wow. Der Mann hat wirklich langes, wallendes Haar.",78));
AddDetail(({"inschrift","inschriften"}),break_string(
  "Unter jedem Portrait steht eine kleine Inschrift.",78));
AddDetail(({"mg"}),break_string(
  "Damit ist das Morgengrauen gemeint.",78));


SetProp(P_LIGHT, 0);
SetProp( P_INDOORS, 1 );

AddExit( "westen", "/gilden/chaos" );
AddExit("oben",C_SWIFT_ROOM("cl2_galerie1"));

AddSpecialExit( "osten","osten");

AddCmd(({"zieh","ziehe"}),"pull_it");


// AddExit("norden",C_112_ROOM("cl2bu12"));


NewDoor( "sueden", C_112_ROOM("cl2bu5"), 
({ "portal", "tuer","tor" }),
({
D_NAME, "Portal",
D_SHORT, "Ein %ses Portal.",
D_GENDER, 0,
D_LONG, "Dieses grosse Portal fuehrt nach draussen in die chaotische Burg.\n"}));


AddItem(C_112_MON("cl2_dwaechter2"),REFRESH_DESTRUCT);
AddItem(C_112_MON("cl3_stonedaem"),REFRESH_DESTRUCT,
    ([P_DEFAULT_INFO:"sagt: Nur Chaoten duerfen hier nach Osten.\n",
      P_SHORT:"Ein steinerner Waechter bewacht den oestlichen Durchgang"])); 

}

int pull_it(string was) {
  if (was == "rahmen")
    return notify_fail("Welchen Rahmen willst Du denn ziehen?\n"),0;
  if (was != "rahmen 3" && was != "an rahmen 3")
    return 0;
  write(break_string("Du ziehst am Bilderrahmen und entdeckst einen geheimen "+
    "Durchgang, den Du ohne zu zoegern durchquerst.",78));
  this_player()->move(C_112_ROOM("cl2bu12"),M_GO,"hinter einem Gemaelde",
    "verschwindet","kommt herein");
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
  if (healed>=0) {
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



int osten() {
  if (this_player()->QueryProp(P_GUILD) == "chaos") {
    this_player()->move(CHAOS_GILDEN_ROOM("cbibo"),M_GO,"nach osten");
    return 1;
  }
  if (!present("\nstone_daemon",this_object()))
    reset();
  write("Der steinerne Waechter haelt Dich auf.\n");
  say("Der steinerne Waechter haelt "+this_player()->name(WEN)+" auf.\n",this_player());
  tell_room(this_object(),
  "Der steinerne Waechter sagt: Nur Chaoten duerfen hier durch.\n");
  return 1;
}
