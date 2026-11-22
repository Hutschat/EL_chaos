inherit "std/pub";
#include <properties.h>
#include <rooms.h>
#include <combat.h>
#include "gilde.h"
 
create() {
  ::create();
  SetProp(P_LIGHT, 0);
  SetProp(P_INDOORS, 1);
  SetProp(P_INT_SHORT, "Die schaebige Kneipe der Chaoten" );
  SetProp(P_INT_LONG, 
"Ist es nun der Name der Kneipe oder eine Beschreibung der Raeumlichkeiten?\n"
+"Jedenfalls hat sie den Namen 'Die schaebige Kneipe der Chaoten' redlich\n"
+"verdient, denn es sieht wirklich so aus, als ob hier Chaoten gewuetet\n"
+"und die halbe Einrichtung bei einer Schlaegerei unter Besoffenen\n"
+"zerstoert haetten. Man kann jedenfalls die vielen zerbrochenen Stuehle\n"
+"und Tische, die dicke Scherbenschicht auf dem Boden und die zerstoerten\n"
+"Spiegel an der Wand nicht mit dem 'Zahn der Zeit' erklaeren.\n"
+"Der Dreck, der hier verkauft wird, laesst sich mit 'menue' ansehen.\n");
AddDetail( "raeumlichkeiten",
"Was fuer ein nettes Wort fuer dieses Chaos.\n");
AddDetail( "chaos",
"Das Chaos hat die unterschiedlichsten Erscheinungsformen. Eine kraeftige\n"
+"Kneipenschlaegerei ist vielleicht die Alltaeglichste.\n");
AddDetail(({ "schlaegerei", "kneipenschlaegerei" }),
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
AddDetail( "skelett",
"Das Skelett haengt, zwischen Stuhl und Decke eingeklemmt, herunter und\n"
+"grinst Dich an.\n");
AddDetail( "gast",
"Du bist auch ein Gast in dieser Kneipe! Also sei besser vorsichtig.\n");
AddDetail( "boden",
"Auf dem Boden liegt eine dicke Scherbenschicht, die bei jedem Schritt\n"
+"unter den Fuessen knirscht und knackst.\n");
AddSpecialDetail(({ "fuss", "fuesse" }), "fuesse" );
AddDetail(({ "scherben", "scherbe", "scherbenschicht", "schicht" }),
"Du betrachtest die bunten Scherben etwas eingehender und entdeckst\n"
+"tatsaechlich noch eine unbeschaedigte, volle Flasche.\n");
AddDetail( "flasche", 
"Die Flasche enthaelt einen Zaubertrank, der leider nicht fuer Dich bestimmt\n"
+"ist. Er bleibt ohne Wirkung.\n");
AddDetail(({ "wand", "waende" }),
"An den Waenden hingen einst schoene Spiegel, doch zahlreiche Schlaegereien\n"
+"mit herumfliegenden Stuehlen und Tischen haben diesen recht viel\n"
+"abverlangt. Im Sueden ist der einzige Ausgang aus dieser vergammelten\n"
+"Kneipe. An der Westwand befindet sich die noch halbwegs funktionstuechtige\n" 
+"Theke, an der sogar noch ausgeschenkt wird.\n");
AddDetail( "spiegel",
"Die Spiegel sind leider alle kaputt.\n");
AddDetail( "westwand",
"An der Westwand steht die Theke und ein Regal.\n");
AddDetail( "regal",
"Auf dem hohen Regal stapeln mehrere grosse  Faesser mit unterschiedlichsten\n"
+"Inhalt. Bei dem reichhaltigen Vorrat wundert es doch sehr, dass man hier\n"
+"nur so wenig bestellen kann.\n");
AddDetail(({ "faesser", "fass" }),
"In den Faessern werden die unterschiedlichsten Getraenke gelagert. Auf\n"
+"einem Holzfass steht was wirklich seltsames geschrieben.\n");
AddDetail( "holzfass",
"Auf dem Holzfass steht geschrieben: 'Leitungswasser, echt faulig!' Dieses\n"
+"Wasser kommt tatsaechlich aus dem schimmeligen und verschmutzten Fluss\n"
+"Leitung. Das sowas ueberhaupt verkauft werden darf, ist schon ein Wunder,\n" 
+"wo man dieses Wasser in Port Vain nicht mal fuer die Klohspuelung verwenden\n"
+"darf.\n");
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

AddDrink( "fauliges Leitungswasser", ({ "wasser", "leitungswasser", 
  "fauliges wasser", "fauliges leitungswasser" }), 10, 0, 0, 0,
({ "In einem schmutzigen Glas erhaelst Du fauliges Leitungswasser. Du\n"
+"wunderst Dich ueber den Namen 'Leitungswasser', denn der Wirt hat das\n"
+"Wasser eindeutig aus einem Holzfass geschoepft.\n",
"&& trinkt ein Glas Wasser.\n" }));

AddToMenu("Chaos-Becher", ({"becher", "chaos-becher", "chaos becher", 
	"chaos" }), 
  ([ P_BUY_VALUE : 100,
     P_HP : 28,
     P_SP : 28,
     P_ALCOHOL : 8,
     P_DRINK : 1]),5, "tot" );

AddDrink( "Fausttaler Drogenfrei", ({ "fausttaler", "drogenfrei", 
	"fausttaler drogenfrei" }),
  70, 50, 0, 7,
({ "Du kannst kaum glauben, aber dieses harmlose Gesoeff wird tatsaechlich\n"
+"in so einer harten Kneipe ausgeschenkt. Sein Ruf ist wirklich nicht\n"
+"untertrieben: Hier kannst Du lange auf eine richtige Droehnung warten.\n",
"&& schaut sich schamvoll um und trinkt dann heimlich einen Fausttaler\n"
+"Drogenfrei.\n" }));

AddDrink( "Pilz (licht)", ({ "pilz", "pilz (licht)" }), 300,200,21,10,
({ "Du bist zwar kein Experte in Mykologie aber es ist doch ganz deutlich,\n"
+"dass dieser Pilz kein Pilz ist, sondern ein bieraehnliches Getraenk.\n"
+"Da Du dem Wirt keine Legastenie unterstellen willst, trinkst Du diesen\n"
+"oder dieses 'Pilz' ohne zu meckern aus. Was aber die zusaetzliche Angabe\n"
+"'licht' zu bedeuten hat, ist Dir nun voellig unklar, denn das Getraenk\n"
+"hat ueberhaupt gar nicht geleuchtet.\n",
"&& bestellt sich einen Pilz der weder eine Pflanze ist noch leuchtet.\n"}));

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

 AddToMenu("Zauberersaft (heiss)",
 ({"saft","zauberersaft"}),
 ([
  P_HP:0,
  P_SP:61,
  P_BUY_VALUE:300,
  P_ALCOHOL : 2,
  P_FOOD : 1,
  P_DRINK:2 ]),
 4,
 ({"\
 Du bekommst eine Tasse mit heissem Zauberersaft, er schmeckt beschissen.\n","\
 && trinkt eine Tasse mit heissem Zauberersaft und muss fast kotzen.\n"}),
 0,10,({
 "Der Wirt sagt: Zauberersaft? Moment! Ich presse mal einen frisch aus...\n",
 "Der Wirt sagt: Zauberersaft? Moment! Ich presse mal einen frisch aus...\n"}));

 AddToMenu("Kaempferblut auf Eis",
 ({"blut","kaempferblut","eisblut"}),
 ([
  P_HP:61,
  P_SP:0,
  P_BUY_VALUE:300,
  P_ALCOHOL : 2,
  P_DRINK : 2,
  P_FOOD:1 ]),
 4,
 ({BRS("Der Wirt schmeisst noch einen schwarzen Eiswuerfel in den Humpen und "
 "reicht ihn Dir."),
 "&& bekommt einen Humpen Kaempferblut auf Eis.\n"}),
 0,10,({
 "Der Wirt kichert: Moment! Kaempfer sind immer so zickig beim Blutspenden.\n",
 "Der Wirt kichert: Moment! Kaempfer sind immer so zickig beim Blutspenden.\n"}));

 AddToMenu("Keys Special (geruehrt)",
 ({"key","keys","keys special","special"}),
 ([
  P_HP:0,
  P_SP:68,
  P_BUY_VALUE:350,
  P_ALCOHOL :0,
  P_FOOD : 0,
  P_DRINK:5 ]),
 8,
 ({BRS("Du bekommst Dein Gesoeff und trinkst es aus. Dieser Special war "
 "nicht nur gut, er war sogar besonders ekelig."),
 "&& trinkt mit Ekel im Gesicht einen Special.\n"}),
 0,15,({
 "Der Wirt bruellt: Verdammt! Schon wieder diese Ploerre! DAS DAUERT!\n",
 "Der Wirt bruellt: Verdammt &&! Schon wieder diese Ploerre! DAS DAUERT!!"}));


 AddToMenu("Feuer aus der Feuerebene",
 ({"feuer"}),
 ([
  P_HP:68,
  P_SP:0,
  P_BUY_VALUE:350,
  P_ALCOHOL :0,
  P_FOOD : 0,
  P_DRINK:5 ]),
 8,
 ({BRS("Du bekommst ein Glas reinen Feuers und fuehlst Dich danach hart "
 "wie Kruppstahl."),
 "&& trinkt ein Glas reinen Feuers und verbrennt sich nichtmal die Fresse...\n"}),
 0,15,({
 "Der Wirt nickt, zuendet ein Glas mit purem Methylalkohol an\n"
 "und sagt: Gleich!",
 "Der Wirt nickt && zu, zuendet ein Glas mit purem Methylalkohol an\nund "
 "sagt: Gleich!"}));

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
}

tot(object spend, object drinker){
  SetProp(P_KILL_NAME,"Ein Becher voller Chaos" );
  SetProp(P_KILL_MSG,"Prost!");
  if(drinker->QueryProp(P_GUILD)=="chaos"){
    write(BRS("Der Becher voll Chaos ist genau das richtige fuer einen "
    "hartgesottenen Krieger des Chaos. Er schmeckt Dir nicht nur sehr "
    "gut, er ist es sogar."));
    say(this_player()->name()+" trinkt hastig einen Becher Chaos und fuehlt "
    "sich gut.\n");
    return 1;
  }
  write(BRS("Als Nicht-Mitglied der Gilde des Chaos haettest Du ihr "
  "staerkstes Gebraeu besser nicht bestellt. Dir dreht sich der Magen um "
  "und mit einem Schlag wird Dir furchtbar uebel."));
  say(drinker->name()+" trinkt einen Becher mit Chaos und schaut sehr "
  "seltsam drein.\n");
  drinker->do_damage(40+random(50),this_object());
  drinker->restore_spell_points(-80);
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
        