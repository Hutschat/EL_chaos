// 05.01 Feuerwehr repfile-abarbeitung.
// 26.06 Feuerwehr  s.o.

inherit "std/pub";
#include <properties.h>
#include <rooms.h>
#include <combat.h>
#include "gilde.h"
/*
"Ist es nun der Name der Kneipe oder eine Beschreibung der Raeumlichkeiten?\n"
+"Jedenfalls hat sie den Namen 'Die schaebige Kneipe der Chaoten' redlich\n"
+"verdient, denn es sieht wirklich so aus, als ob hier Chaoten gewuetet\n"
+"und die halbe Einrichtung bei einer Schlaegerei unter Besoffenen\n"
+"zerstoert haetten. Man kann jedenfalls die vielen zerbrochenen Stuehle\n"
+"und Tische, die dicke Scherbenschicht auf dem Boden und die zerstoerten\n"
+"Spiegel an der Wand nicht mit dem 'Zahn der Zeit' erklaeren.\n"
+"Der Dreck, der hier verkauft wird, laesst sich mit 'menue' ansehen.\n");
*/
 
create() {
  ::create();
  SetProp(P_LIGHT, 0);
  SetProp(P_INDOORS, 1);
  SetProp(P_INT_SHORT, "Die schaebige Kneipe der Chaoten" );
  SetProp(P_INT_LONG, break_string(
  "Dies ist wirklich 'Die schaebige Kneipe der Chaoten'. Sie sieht kaum "+
  "anders aus als ihre Ruine in der alten Gilde. Es sieht wirklich "+
  "so aus, als ob hier Chaoten gewuetet "+
  "und die halbe Einrichtung bei einer Schlaegerei unter Besoffenen "+
  "zerstoert haetten. Man kann jedenfalls die vielen zerbrochenen Stuehle "+
  "und Tische, die dicke Scherbenschicht auf dem Boden und die zerstoerten "+
  "Spiegel an der Wand nicht mit dem 'Zahn der Zeit' erklaeren.",78)+
  "Der Dreck, der hier verkauft wird, laesst sich mit 'menue' ansehen.\n");
  AddDetail( "raeumlichkeiten",
    "Was fuer ein nettes Wort fuer dieses Chaos.\n");
  AddDetail( ({"erscheinungsformen","chaos"}),
   "Das Chaos hat die unterschiedlichsten Erscheinungsformen. Eine kraeftige\n"
  +"Kneipenschlaegerei ist vielleicht die Alltaeglichste.\n");
  AddDetail(({ "schlaegerei", "kneipenschlaegerei","schlaegereien" }),
   "Leider findet zur Zeit keine Schlaegerei statt. Du wuerdest sicherlich\n"
  +"kraeftig mitmischen.\n" );
  AddDetail( "zahn",
  "Die Zeit hat zumindest einen Zahn. Das ist mehr als so manchem nach einer\n"
  +"weniger erfolgreichen Kneipenschlaegerei verblieben ist.\n");
  AddSpecialDetail( "zeit", "zeit" );
  AddDetail( "dreck",
  "Der Dreck liegt nicht nur auf dem Boden herum, nein, man kann ihn\n"
  +"sich auch bestellen.\n");
  AddDetail( "decke",
  "Sogar die Decke wurde durch die Schlaegereien in Mitleidenschaft gezogen.\n"
  +"Ein Stuhl, mit unmenschlicher Kraft geworfen, hat sich in die Decke\n"
  +"gebohrt und steckt so fest, dass man ihn nicht mehr herausziehen konnte.\n"
  +"Dies stoerte aber keinen hier. Nur einer war nicht so gluecklich,\n"
  +"naemlich derjenige, der auf dem Stuhl gesessen hat, als er geworfen\n"
  +"wurde und so zeugt nur noch das Skelett auf diesem Stuhl davon, was fuer\n"
  +"ein tragisches Ende diesem Gast widerfahren ist.\n");
  AddDetail(({"ende"}),
  "Wie tragisch.\n");
  AddDetail( "skelett",
  "Das Skelett haengt, zwischen Stuhl und Decke eingeklemmt, herunter und\n"
  +"grinst Dich an.\n");
  AddDetail( "gast",
  "Du bist auch ein Gast in dieser Kneipe! Also sei besser vorsichtig.\n");
  AddDetail( "boden",
  "Auf dem Boden liegt eine dicke Scherbenschicht, die bei jedem Schritt\n"
  +"unter den Fuessen knirscht und knackst. Eine Klappe im Boden fuehrt herab\n"
  +"in die Tiefen dieser Burg.\n");
  AddSpecialDetail(({"klappe"}),"det_klappe");
  AddSpecialDetail(({ "fuss", "fuesse" }), "fuesse" );
  AddDetail(({ "scherben", "scherbe", "scherbenschicht", "schicht" }),
  "Du betrachtest die bunten Scherben etwas eingehender und entdeckst\n"
  +"tatsaechlich noch eine unbeschaedigte, volle Flasche.\n");
  AddDetail( "flasche", 
  "Die Flasche enthaelt einen Zaubertrank, der leider nicht fuer Dich bestimmt\n"
  +"ist. Er bleibt ohne Wirkung.\n");
  AddDetail(({"zaubertrank","wirkung"}),
  "Verdammt. Der Zaubertrank hatte keine Wirkung.\n");
  AddDetail(({ "wand", "waende" }),
  "An den Waenden hingen einst schoene Spiegel, doch zahlreiche Schlaegereien\n"
  +"mit herumfliegenden Stuehlen und Tischen haben diesen recht viel\n"
  +"abverlangt. Im Osten ist der einzige Ausgang aus dieser vergammelten\n"
  +"Kneipe. An der Westwand befindet sich die noch halbwegs funktionstuechtige\n" 
  +"Theke, an der sogar noch ausgeschenkt wird.\n");
  AddDetail( "spiegel",
  "Die Spiegel sind leider alle kaputt.\n");
  AddDetail( "westwand",
  "An der Westwand steht die Theke.\n");
  AddDetail( "ausgang",
  "Durch einen Ausgang kann man einen Raum verlassen.\n");
  AddDetail( "theke", 
  "Die Theke macht nicht mehr den besten Eindruck, sie ist aber immer noch\n"
  +"funktionstuechtig und so wird auch heute noch ausgeschenkt. Ja, ganz\n"
  +"recht! Trotz dieses Chaos ist die Kneipe weiterhin geoeffnet. Hinter\n"
  +"der Theke steht der Wirt, mit dem man sich besser nicht anlegen sollte.\n");
  AddDetail( "wirt",
  "Der Wirt ist das gefaehrlichste Lebewesen im ganzen Universum! Mit einem\n"
  +"einzigen Schlag kann er ganze Koenigreiche verschwinden lassen, ein\n"
  +"Tritt von ihm hat schon den Mond vom Himmel geholt und sein Koerper ist\n"
  +"so unverwuestlich, dass er schon durch die Sonne geschwommen ist.\n" 
  +"Doch auf ihm lastest ein schrecklicher Fluch! Ein gemeiner Magier hat\n"
  +"ihn unangreifbar gemacht, was sein Leben recht langweilig werden laesst,\n" 
  +"denn es war immer ein schoener Spass, unvorsichtige Abenteurer in\n"
  +"tausend Stuecke zu zerreissen.\n");
  AddDetail(({"abenteurer"}),
  "Abenteurer sind hier garnicht gern gesehen.\n");
  AddDetail(({"burg"}),
  "Du befindest Dich hier in der schwarzen Burg. Aber das weisst Du schon.\n");
  AddDetail(({"chaoten","geschoepfe"}),
  "Chaoten sind die boesartigsten Geschoepfe, die es jemals gegeben hat.\n");
  AddDetail(({"eindruck"}),
  "Der Eindruck, den die Theke macht, ist recht erbaermlich.\n");
  AddDetail(({"einrichtung"}),
  "Die halbe Einrichtung wurde zertruemmert, und was uebrig ist sieht nicht so\n"+
  "aus, als wuerde es noch lange ueberleben.\n");
  AddDetail(({"fluch"}),
  "Hehe. Der ist verflucht boesartig.\n");
  AddDetail(({"gilde","chaosgilde"}),
  "Die Chaosgilde ist die boesartigste Gilde, die es gibt.\n");
  AddDetail(({"himmel"}),
  "Den kannst Du von hier aus garantiert nicht sehen.\n");
  AddDetail(({"kneipe","raum"}),
  "Dies ist die schaebige Kneipe der Chaoten.\n");
  AddDetail(({"koenigreiche","lebewesen","schlag","tritt","mond","koerper",
  "sonne","stuecke","leben","universum"}),
  "Ja, dieser Wirt ist schon verdammt boesartig und maechtig. Hehe.\n");
  AddDetail(({"kraft"}),
  "Wow. Diese Kraft war sicher beeindruckend.\n");
  AddDetail(({"magier"}),
  "Magier sind noch boesartiger als Chaoten.\n");
  AddDetail(({"mitleidenschaft"}),
  "Och, die arme Decke.\n");
  AddDetail(({"ruine"}),
  "Sie Ruine liegt weit suedlich von hier.\n");
  AddDetail(({"schritt"}),
  "Es knirscht und knarscht unter Deinen Fuessen.\n");
  AddDetail(({ "stuhl", "stuehle" }),
  "Die Stuehle sind leider alle zerbrochen und nicht mehr zum Hinsetzen\n"
  +"zu gebrauchen. Dies liegt wahrscheinlich daran, dass sie auch nicht zum\n"
  +"Fliegen geeignet waren, was aber die Chaoten, die damit herumgeworfen haben,\n"
  +"nicht weiter gestoert hat.\n");
  AddDetail(({ "tisch", "tische" }),
  "Die Tische sind leider alle zerstoert. Schade, Du wolltest so gerne auf den\n"
  +"Tischen tanzen und die Sau rauslassen.\n");
  AddDetail( "sau",
  "Die Sau wurde leider schon aus dem Kaefig gelassen.\n");
  AddDetail( "kaefig",
  "In einer Ecke des Raumes steht ein leerer Kaefig, in dem frueher eine\n"
  +"Sau gehalten wurde, die man zu besonders witzigen Festen herausgelassen\n"
  +"hat.\n");
  AddDetail( "ecke",
  "In einer Ecke steht ein leerer Kaefig.\n");
  AddDetail(({"feste"}),
  "Immer feste drauf, genau.\n");
  AddDetail(({"spass"}),
  "Na, den Spass muss man dem alten Wirt schon goennen.\n");
  
AddDrink( "fauliges Leitungswasser", ({ "wasser", "leitungswasser", 
  "fauliges wasser", "fauliges leitungswasser" }), 10, 0, 0, 0,
({ "In einem schmutzigen Glas erhaelst Du fauliges Leitungswasser. Du\n"
+"wunderst Dich ueber den Namen 'Leitungswasser', denn der Wirt hat das\n"
+"Wasser eindeutig aus einem Holzfass geschoepft.\n",
"&& trinkt ein Glas Wasser.\n" }));

AddDrink( "Altes Bier (Alt)", ({ "alt", "altes bier", "bier" }),
1000, 1, 30, 30,
({ "Igitt! Hier wird tatsaechlich altes, verschimmelts und verdorbenes Bier\n"
+"verkauft, dass von den ganzen Bakterien dunkel geworden ist! Nun hast\n"
+"Du es aber bestellt und trinkst es auch. Gerade als Du es mit einem\n"
+"schnellen und qualvollen Schluck hinuntergekippt hast bekommst Du das\n"
+"unbaendige Beduerfnis moeglichst schnell zu Fuss zu einer gemuetlichen\n"
+"Stadt mit einer riesigen Kirche an einem grossen Strom zu laufen, wo\n"
+"allgemein anerkannt das Beste Bier hergestellt wird, welches zufaelliger-\n"
+"weise genau wie die dort herrschende Sprache genannt wird.\n",
"&& trinkt ein altes Bier und schaemt sich.\n" }));

AddDrink( "Methylalkohol", ({ "alkohol", "methyl", "methylalkohol" }),
145, 10, 10, 3, "blind" );

AddToMenu("Ein ganzes Untier",({ "untier","ganzes untier" }),
  ([ P_BUY_VALUE : 1234,
     P_FOOD : 100,
     P_HP : 250,
     P_SP : 250]),10,
({ "Nun, wie der Name schon sagt bekommst Du ein ganzes Untier vorgesetzt\n"
+"(nur das Un fehlt :-)). Endlich kannst Du es mal essen, wo es Dich doch\n"
+"schon soviele male verspeisst hat. Leider schmeckt es genauso wie es\n"
+"gelebt hat.\n",
"&& isst tatsaechlich ein ganzes Untier! Leute gibts, die gibts nicht...\n"}) );

AddToMenu( "Die Glocken von Moron", ({ "glocken", "moron", "glocken von moron" }),
 ([ P_BUY_VALUE : 40,
    P_FOOD : 20,
    P_HP : 70,
    P_SP : 70 ]),10,
({ "Nun, aeh.. *gruebel* Diese Speise ist schwer zu beschreiben. Irgendwie\n"
"sehen diese Glocken merkwuerdig aus. Es ist so eine Art Gehaenge...\n"
+"Wie auch immer, Du isst diese beiden eifoermigen, fleischigen Dinger.\n",
"&& erhaelt die 'Glocken von Moron' wobei Du Dir ein Kichern nicht\n"
+"verkneifen kannst.\n" }));

AddFood( "Schleimliches Allerlei", ({ "schleim", "allerlei", 
	"schleimliches allerlei" }), 10, 12,
({ "Wie der Name schon sagt, erhaelst Du einen schleimigen Klumpen mit\n"
+"unidentifizierbaren Zutaten. Du willst gar nicht wissen, was da so alles\n"
+"drin ist und schlingst es schnell hinunter.\n",
"&& isst einen widerlichen Klumpen schleimigen Allerleis.\n" }));

AddExit( "sueden", CHAOS_GILDEN_ROOM( "claden") );
AddCmd(({"tritt","trete"}),"kick");
AddCmd(({"oeffne"}),"oeffne_was");
AddCmd(({"schliess","schliesse"}),"schliesse_was");
AddCmd(({"kletter","klettere"}),"climb_in");

}

int kick(string was) {
   if (was != "wirt")
     return 0;
     
   write("Du trittst den Wirt.\nDer Wirt schmeisst Dich raus.\n");
   say(this_player()->Name(WER)+" tritt den Wirt.\n"+
       "Der Wirt schmeisst "+this_player()->name(WEN)+" raus.\n",this_player());
   this_player()->move(C_112_ROOM("cl2bu5"),M_GO,"raus");       
   return 1;
}

blind(){
  write(BRS("Du trinkst den Alkohol und wirst blind, wie Du es sicherlich "
  "erwartet hast. Immerhin hat der Methylalkohol ganz ordentlich "
  "geschmeckt."));
  say(this_player()->name()+" erblindet.\n");
  this_player()->SetProp(P_BLIND,1);
  return 1;
}

string fuesse(){
  int i;
  object *arm;
  arm = this_player()->QueryProp(P_ARMOURS);
  for(i=0;i<sizeof(arm);i++){
    if( arm[i]->QueryProp(P_ARMOUR_TYPE) != AT_BOOT) continue;
    arm[i]->do_unwear(arm[i]->QueryProp(P_IDS)[1] );
  }
  return "Du koenntst Dir die Fuesse auch mal wieder waschen.\n";
}

string zeit(){
  return dtime(time())+"\n";
}

static mixed bestelle(string str){
  _notify_fail("Der Wirt bruellt Dich an: So einen Dreck gibs hier nicht!\n"
  "Der Wirt haut Dir eine aufs Maul!\n");
  if (str) return search_what(str,this_player(),this_player());
  return 0;
}

string det_klappe() {
  if (!call_other(C_SWIFT_ROOM("cl2_weinkeller"),"query_opened"))
    return break_string("Eine ganz normale Klappe im Boden. Sie ist "+
    "momentan geschlossen, doch das kann man ja aendern.\n",78);
  return break_string("Eine ganz normale Klappe im Boden. Sie ist "+
  "momentan geoeffnet, weshalb man durch sie nach unten klettern kann.",78);
}

int oeffne_was(string was) {
  if (was != "klappe") return notify_fail("Was moechtest Du oeffnen?\n"),0;
  return call_other(C_SWIFT_ROOM("cl2_weinkeller"),"open_klappe");
}

int schliesse_was(string was) {
  if (was != "klappe") return notify_fail("Was moechtest Du schliessen?\n"),0;
  return call_other(C_SWIFT_ROOM("cl2_weinkeller"),"close_klappe");
}

int climb_in(string was) {
  if (was != "durch klappe" && was != "klappe" && was != "nach unten")
    return notify_fail("Wodurch moechtest Du klettern?\n"),0;
  if (!call_other(C_SWIFT_ROOM("cl2_weinkeller"),"query_opened"))
    return write("Leider ist die Klappe gerade geschlossen.\n"),1;
   write("Du kletterst hinab in die Schwaerze.\n");
   this_player()->move(C_SWIFT_ROOM("cl2_weinkeller"),M_GO,
         "nach unten","klettert","kommt durch die Klappe geklettert");
   return 1;    
}                
  