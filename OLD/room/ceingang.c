// ceingang.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_ROOM("std/std_chaos");

static int portal;

protected void create()
{
  ::create();
  SetProp(P_INDOORS,0);
  SetProp(P_ENVIRONMENT,([ENV_TEMPERATURE:25]));
  SetProp(P_TERRAIN,T_ICE);
  SetProp(P_INT_SHORT, "Vor der finsteren Festung des Chaos" );
  SetProp(P_INT_LONG,
  "Du stehst vor der finsteren Festung des Chaos. Wie ein duesterer Alptraum "
  "ragt sie aus dem endlosen Weiss der Eiswueste gruselig. Direkt vor dir, "
  "wie der klaffende Schlund eines urzeitlichen Ungeheuers, befindet "
  "sich ein grosses Portal, das ins Innere des Gemaeuers fuehrt. ");

  AddDetail("weiss",
  "Die Eiswueste ist so weiss, also ob der weisse Riese hier gewuetet "
  "haette.");

  AddDetail("riese",
  "Der weisse Riese ist zur Zeit nicht da. Darueber solltest du froh sein.");

  AddDetail(({"wueste","eiswueste"}),
  "Die Eiswueste ist ueberall um dich herum. Nur im Norden befindet sich "
  "der Eingang in die seltsame Festung des Chaos.");

  AddDetail(({"festung","chaosfestung"}),
  "Schroffe Mauern und hohe Tuerme mit winzigen Fenstern draengen sich "
  "dicht an dicht und ragen finster und bedrohlich ueber dir auf. Ein "
  "grosses Portal scheint der einzige Eingang zu sein.");
  
  AddDetail("eingang",
  "Der Eingang ist auch als ein grosses Portal zu bezeichnen.");

  AddDetail("alptraum", 
  "Diese Festung ist wohl aus dem Alptraum eines verrueckten Magiers "
  "entsprungen.");

  AddDetail(({"maul","schlund","ungeheuer"}),
  "Dies sind nur Vorstellungen, die aus deiner Phantasie entsprungen sind.");

  AddDetail(({"vorstellungen","vorstellung"}),
  "Was willst du vor was stellen?");

  AddDetail("phantasie",
  "Die Phantasie geht mit dir durch.");

  AddDetail(({"mauer","mauern","gemaeuer"}),
  "In dem endlosen Weiss der Eiswueste wirken diese duesteren Gemaeuer "
  "der Festung voellig irreal und unwirklich. Obwohl ein schwerer "
  "Schneesturm tobt, hat sich auf den Mauern kein Schnee angesammelt, als "
  "ob sie vom Schnee nicht erreicht wuerden. Ebenso auf dem armseligen "
  "Haus, welches nur notduerftig aus alten und vergammelten Brettern "
  "zusammengezimmert wurde.");

  AddDetail(({"brett","bretter"}),
  "Die Bretter sind schon sehr alt und sind zum grossen Teil bereits nahezu "
  "vergammelt. Wer koennte wohl dort hausen?");

  AddDetail(({"schneesturm","sturm"}),
  "Der Schneesturm wirbelt Schnee wild herum und nimmt Dir jede Sicht. Wenn "
  "Du nur fuenf Schritte nach hinten gehst, verschwindet die Festung wieder "
  "im Gestoeber.");

  AddDetail(({"sicht","aussicht"}),
  "Die Sicht ist hier sehr begrenzt.");

  AddDetail(({"gestoeber","schneegestoeber"}),
  "Der Schnee stoebert nur so um dich herum.");

  AddDetail("schnee",
  "Du bist mitten in der Eiswueste! Hier gibt es Unmengen an Schnee.");

  AddDetail("eis",
  "Ueberall ist Eis. Seltsamerweise ist nur die Festung davon ausgenommen.");

  AddDetail(({"boden","fussboden"}),
  "Der Boden besteht aus Eis und wird nur von einigen Fussspuren "
  "unterbrochen.");

  AddDetail(({"fussspuren","fussspur","spur","spuren"}),
  "Die meisten Fussspuren fuehren nach Sueden weiter in die Eiswueste "
  "hinein. Doch einige Spuren enden vor einem kleinen Huegel, der ziemlich "
  "unscheinbar im Schatten der Festung versteckt ist.");

  AddDetail(({"wolke","wolke"}),
  "Vor lauter Schneegestoeber siehst du keine Wolken.");
  
  AddDetail(({"sonne"}),
  "Irgendwo muss die Sonne sein, schliesslich ist es hier nicht dunkel. "
  "Aber sie vesteckt sich hinter dem Schnee, der da bestaendig vom "
  "Himmel faellt.");
  
  AddDetail(({"himmel","flaeche"}),
  "Der Himmel ist eine grosse, schneeweisse Flaeche ueber dir, die "
  "sich von Horizont zu Horizont kruemmt.");

  AddDetail("horizont",
  "Ganz ganz fern, dort wo der Himmel die Welt beruehrt, dort ist der "
  "Horizont. Doch versuche nicht, ihn zu erreichen. Es ist vergebens.");

  AddDetail("welt",
  "Die Welt ist eine Scheibe. Jedenfalls behaupten dies einige Goetter, die "
  "aber bekannter Massen ziemlich dumm und einfallslos sind.");

  AddDetail(({"scheibe","scheiblette"}),
  "Die Welt ist eher eine Scheiblette.\n");

  AddDetail(({"gott","goetter"}),
  "Die Goetter sind wirklich recht dumm und einfallslos.");

  AddDetail(({"tuerme","turm"}),
  "Die langen, etwas schiefen Tuerme ragen in den schneeweissen Himmel und "
  "scheinen sich etwas zu dir zu neigen. Ihre schwach erleuchteten Fenster "
  "schauen wie Augen auf dich hinab, das Portal erinnert an ein graessliches "
  "Maul und so glaubst du, direkt in eine boesartige Fratze zu starren.");

  AddDetail(({"fratze","form"}),
  "Die Form der Festung erinnert dich entfernt an eine boesartige Fratze, "
  "die dich anstarrt.");

  AddDetail("fenster",
  "Die kleinen, schwach beleuchteten Fenster in den Tuermen blicken "
  "hasserfuellt auf dich hinab.");

//AddExit( "sueden", "/d/polar/alle/room/eiswueste/eiswueste[3,5]" );
  NewDoor( "norden", CHAOS_GILDEN_ROOM( "challe" ), 
  ({ "tuer", "portal" }),
  ({
    D_NAME, "Portal",
    D_SHORT, "Ein %ses Portal.",
    D_GENDER, NEUTER,
    D_LONG, break_string("Dieses grosse Portal fuehrt direkt in die Festung "
            "des Chaos, von der so manche gar schauerliche Geschichte "
            "berichtet wird. Willst Du wirklich dort hineingehen?")
  }));
}
