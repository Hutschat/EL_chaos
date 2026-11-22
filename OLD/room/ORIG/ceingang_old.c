/*
Letzte Aenderung: 05.01.99 von Tilly (det angepasst)
*/
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include "gilde.h"
int portal;

create()
{
	::create();

SetProp(P_INT_SHORT, "Vor der finsteren Festung des Chaos" );
SetProp( P_INT_LONG,
"Du stehst vor der finsteren Festung des Chaos. Wie ein duesterer Alptraum\n"
+"ragt sie aus dem endlosen Weiss der Eiswueste gruselig. Direkt vor Dir,\n"
+"wie der klaffende Schlund eines urzeitlichen Ungeheuers, befindet\n"
+"sich ein grosses Portal, das ins Innere des Gemaeuers fuehrt.\n");
SetProp(P_LIGHT, 1);
AddDetail( "weiss",
"Die Eiswueste ist so weiss, also ob der weisse Riese hier gewuetet haette.\n");
AddDetail( "riese",
"Der weisse Riese ist zur Zeit nicht da. Darueber solltest Du froh sein.\n");
AddDetail( "eiswueste",
"Die Eiswueste ist ueberall um Dich herum. Nur im Norden befindet sich\n"
+"der Eingang in die seltsame Festung des Chaos.\n");
AddDetail( "festung",
"Schroffe Mauern und hohe Tuerme mit winzigen Fenstern draengen sich\n"
+"dicht an dicht und ragen finster und bedrohlich ueber Dir auf. Ein\n"
+"grosses Portal scheint der einzige Eingang zu sein.\n");
AddDetail( "eingang",
"Der Eingang ist auch als ein grosses Portal zu bezeichnen.\n");
AddDetail( "alptraum", 
"Diese Festung ist wohl aus dem Alptraum eines verrueckten Magiers\n"
+"entsprungen.\n");
AddDetail(({ "maul", "schlund", "ungeheuer" }),
"Dies sind nur Vorstellungen die aus Deiner Phantasie entsprungen sind.\n");
AddDetail(({ "vorstellungen", "vorstellung" }),
"Was willst Du vor was stellen?\n");
AddDetail( "phantasie",
"Die Phantasie geht mit Dir durch.\n");
AddDetail(({ "mauer", "mauern", "gemaeuer" }),
"In dem endlosen Weiss der Eiswueste wirken diese duesteren Gemaeuer\n"
+"der Festung voellig irreal und unwirklich. Obwohl ein schwerer Schnee-\n"
+"sturm tobt, hat sich auf den Mauern kein Schnee angesammelt, als ob\n"
+"die Mauern von dem Schnee nicht erreicht wuerden. Ebenso auf dem armseligen\n"
+"Haus, welches nur notduerftig aus alten und vergammelten Brettern\n"
+"zusammengezimmert wurde.\n");
AddDetail(({"brett","bretter"}),
"Die Bretter sind schon sehr alt und sind zum grossen Teil bereits nahezu\n"
+"vergammelt. Wer koennte wohl dort hausen?\n");
AddDetail(({ "schneesturm", "sturm" }),
"Der Schneesturm wirbelt Schnee wild herum und nimmt Dir jede Sicht. Wenn\n"
+"Du nur fuenf Schritte nach hinten gehst, verschwindet die Festung wieder\n"
+"im Gestoeber.\n");
AddDetail( "sicht",
"Die Sicht ist hier sehr begrenzt.\n");
AddDetail( "gestoeber",
"Der Schnee stoebert nur so um Dich herum.\n");
AddDetail( "schnee",
"Du bist mitten in der Eiswueste! Hier gibt es Unmengen an Schnee.\n");
AddDetail( "eis",
"Ueberall ist Eis. Seltsamerweise ist nur die Festung davon ausgenommen.\n");
AddDetail( "boden",
"Der Boden besteht aus Eis und wird nur von einigen Fussspuren unterbrochen.\n");
AddDetail(({ "fussspuren", "fussspur", "spur", "spuren" }),
"Die meisten Fussspuren fuehren nach Sueden weiter in die Eiswueste hinein.\n"
+"Doch einige Spuren enden vor einem kleinen Huegel, der ziemlich unscheinbar\n"
+"im Schatten der Festung versteckt ist.\n" );
AddDetail(({ "himmel", "flaeche" }),
"Der Himmel ist eine grosse, schneeweisse Flaeche ueber Dir, die sich von\n"
+"Horizont zu Horizont kruemmt.\n");
AddDetail( "horizont",
"Ganz ganz fern, dort wo der Himmel die Welt beruehrt, dort ist der Horizont.\n"
+"Doch versuch nicht, ihn zu erreichen. Es ist vergebens.\n");
AddDetail( "welt",
"Die Welt ist eine Scheibe. Jedenfalls behaupten dies einige Goetter, die\n"
+"aber bekannter Massen ziemlich dumm und einfallslos sind.\n");
AddDetail(({  "scheibe", "scheiblette" }),
"Die Welt ist eher eine Scheiblette.\n");
AddDetail(({ "gott", "goetter" }),
"Die Goetter sind wirklich recht dumm und einfallslos. Viel schlimmer sind\n"
+"allerdings die Erzmagier.\n");
AddDetail( "erzmagier",
"Die Erzmagier sind machtgeil und klammern sich krampfhaft an ihren\n"
+"Sonderrechten, die sie anderen Magiern nicht zugestehen wollen.\n");
AddDetail( "magier",
"Einfache Magier sind dumm und stinken. Gut, dass die Regionsmagier auf\n"
+"sie aufpassen, sonst wuerden 90% der neuen Gebiete nur Mist enthalten.\n"
+"So sind es nur 89%.\n");
AddDetail( "regionsmagier",
"Die einzig wahren Magier.\n");
AddDetail( "mist",
"Der Mist stinkt schon bis zum Himmel.\n");
AddDetail(({ "sonderrechte", "sonderrecht" }),
"Die Sonderrechte der Erzmagier zeigen nur ihre Machtgeilheit. Sie sind\n"
+"nur dafuer da, andere Magier zu bespitzeln, zu unterdruecken und zu\n"
+"aergern.\n");
AddDetail( "machtgeilheit",
"Eine sehr verbreitete Krankheit unter den Erzmagiern.\n");
AddDetail(({ "macht", "krankheit" }),
"Von zuviel Macht bekommt man Pickel im Gesicht.\n");
AddDetail( "pickel",
"Erzmagier erkennt man an ihren Pickeln im Gesicht.\n");
AddDetail( "gesicht",
"Schau Dir in die Augen, Kleiner/Kleines.\n");
AddDetail( "augen",
"Du nimmst ein Auge aus der Augenhoehle und haelst es vor das andere Auge.\n");
AddDetail( "augenhoehle",
"Durch die Augenhoehle kannst Du jetzt Dein Gehirn sehen.\n");
AddDetail( "gehirn",
"Was macht denn das Stroh in Deinem Kopf?\n");
AddDetail( "kopf",
"Er ist noch immer da.\n");
AddDetail(( { "stroh", "intelligenz" }),
"Du hat auch nicht mehr Intelligenz als ein Wolpertinger.\n");
AddDetail( "wolpertinger",
"Nur ein toter Wolpertinger ist ein guter Wolpertinger.\n");
AddDetail(({ "tuerme", "turm" }),
"Die langen, etwas schiefen Tuerme ragen in den schneeweissen Himmel und\n"
+"scheinen sich etwas zu Dir zu neigen. Ihre schwach erleuchteten Fenster\n"
+"schauen wie Augen auf Dich hinab, das Portal erinnert an ein graessliches\n"
+"Maul und so glaubst Du, direkt in eine boesartige Fratze zu starren.\n");
AddDetail(({ "fratze", "form" }),
"Die Form der Festung erinnert Dich entfernt an eine boesartige Fratze,\n"
+"die Dich anstarrt.\n");
AddDetail( "fenster",
"Die kleinen, schwach beleuchteten Fenster in den Tuermen blicken\n"
+"hasserfuellt auf Dich hinab.\n");
AddSpecialDetail( "portal", "det_portal" );

AddExit( "sueden", "/d/polar/alle/room/eiswueste/eiswueste[3,5]" );
NewDoor( "norden", CHAOS_GILDEN_ROOM( "challe" ), 
({ "tuer", "portal" }),
({
D_NAME, "Portal",
D_SHORT, "Ein %ses Portal.",
D_GENDER, 0,
D_LONG, "Dieses grosse Portal fuehrt direkt in die Festung des Chaos, von der so\n"
+"manche gar schauerliche Geschichte berichtet wird. Willst Du wirklich dort\n"
+"hineingehen?\n"
}));

}
