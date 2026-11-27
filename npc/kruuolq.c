// kruuolq.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 11.03.2019 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            UTF-8, Fehler für neuen Driver behoben

#pragma no_inherit
#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check
 
#include "def.h"

#include "kruuolq.h"

inherit "std/npc";
inherit "std/util/pager";
inherit "std/player/moneyhandler";

#define P_DUELLANT "_lets_go_have_fun_"  // ganz wichtig fuers Attack() !!
#define DEFAULT_QUEST_FAIL "Davon weiss ich nichts."


static int beurteilung(object pl);
string erhoehen();

int blutmagie; // feuerwehr 11.04.99. siehe raum cl3_cerz3

// Chaosrattenquest

// Prototypen für Closures
static string erzikampf_info();
static string gib_ring();
static string gib_seherring();
string metzel_quest_done();
string sag_beurteilung();
static string special_yrintri();
static string unser_aller_erzmeister();
static int boese(object pl);
static int gildenmags(object pl);
void lernen(int spell, int index);
void my_mistake();
static int raum_test();

static int check_pl(object pl){
#ifndef JENANDRA_QUEST
  if(pl->QueryProp("jenandra:testquest")) return 1;
  return 0;
#else
  return 1;
#endif
}
/*
static string ratte(){
  object pl,medal;
  string *prop;
  pl=PL;
  if(!check_pl(pl)) return DEFAULT_QUEST_FAIL;
  prop=pl->QueryProp("jenandra:cratte");
  if(pointerp(prop)&&sizeof(prop)){
    return "Du hast mich doch schon mal danach gefragt! Verschwende nicht "+
	       "meine Zeit! Winkrieg weiss da was drueber!";
  }
  if((C_JENANDRA_CRATTE("qmaster"))->QueryMember(pl)){
    return "Willst Du mich veralbern? Du hast doch schon mal eine "
		   "Chaosratte gemacht!";
  }
  if(to_int(pl->query_real_name())){
	return "Vergiss es. Du erfaehrst von mir nichts ueber die Chaosratte.";
  }
  if(pl->QueryProp(P_ALIGN)>-300){
	return "Mit Deinem ekelhaft guten Charakter hast Du ueberhaupt keine "
		   "Chance, Dir eine Chaosratte zu bauen - tu dagegen erst mal "
		   "was!";
  }
  if(pl->QueryProp(P_GUILD)=="chaos"){
	if(pl->QueryProp(P_GUILD_LEVEL)<4){
	  tell_room(environment(),"Kruuolq laechelt mitleidig.\n");
	  return "Komm wieder, wenn Du gross genug bist, um einen Bannzauber "+
			 "hinzukriegen.";
	}
  }
  if(!pointerp(prop)||!sizeof(prop)){
    pl->SetProp("jenandra:cratte",({"kruuolq"}));
    if(!present(("\n"+C_JENANDRA_CRATTE("medal")),pl)){
      medal=clone_object(C_JENANDRA_CRATTE("medal"));
      medal->move(pl,M_NOCHECK|M_GIVE);
    }
    return "Du willst Dir eine Chaosratte bauen? Dann geh doch mal zu "+
	       "Winkrieg, ich glaube, der kann Dir da weiterhelfen.";
  }
}

static string medal(){
  if(present(("\n"+C_JENANDRA_CRATTE("medal")),PL)){
	return "Soll ich Dich am Haendchen nehmen und zu Mutti bringen? Mach "+
		   "Die Augen auf und schau Dir die Medaille an!";
  }
  return "Keine Ahnung, wovon Du redest!";
}
*/
// Ende Chaosrattenquest

void tell_player(string s, object pl);

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  blutmagie = 0;
  create_default_npc(20,1000);
  SetProp(P_GUILD,"chaos");
  SetProp(P_DUELLANT,0);       // wichtig fuers Attack() !!!
  SetProp(P_GUILD_LEVEL,11);
  SetProp(P_SHORT, capitalize(CHAOS_ID_KRUUOLQ)+" der oberste Meister des Chaos");
  SetProp(P_LONG, 
  capitalize(CHAOS_ID_KRUUOLQ)+" ist der oberste Meister der Chaos-Gilde. Er "
  "ist schon recht alt, was bei der Gefaehrlichkeit der Chaos-Magie schon recht "
  "ungewoehnlich ist. Jetzt praktiziert er diese Magie nur noch selten. "
  "Dafuer lehrt er seine ungewoehnlichen Faehigkeiten anderen Kriegern "
  "des Chaos und kann so vielfaeltige Informationen zu den Zauberspruechen "
  "und Daemonen erzaehlen.");
  SetProp(P_NAME,capitalize(CHAOS_ID_KRUUOLQ));
  SetProp(P_DRINK,0);
  SetProp(P_MAX_DRINK,100);
  SetProp(P_ALCOHOL,0);
  SetProp(P_MAX_ALCOHOL,150);
  SetProp(P_FOOD,0);
  SetProp(P_MAX_FOOD,100);
  SetProp(P_GENDER,1);
  SetProp(P_ARTICLE,0);
  SetProp(P_XP,1250000);
  SetProp(P_ALIGN,-100);
  SetProp(P_SIZE,210);
  SetProp(P_RESISTANCE,
  ([
    DT_DARKNESS:-1.0,
    DT_LIGHT:    0.5
  ]));
  SetProp(P_KILL_MSG,"Es war ein fairer Kampf, da gibts nichts! >:)");
  SetProp(P_HANDS,
   ({" mit der Macht des Chaos", 250,({DT_BLUDGEON,DT_DARKNESS})}));
  SetProp(P_BODY,310);
  SetProp(P_RACE,"Mensch");
  SetProp(P_DEFAULT_INFO,"sagt: Frag mal Hutschat.\n");
  AddId(({"\ncg_kruuolq","meister",CHAOS_ID_KRUUOLQ}));
  set_living_name(CHAOS_ID_KRUUOLQ);
  
 AddInfo(CHAOS_ID_KRUUOLQ,
 "Das bin ich!", "sagt: ");

 AddInfo(({ "gilde" }),
 "In der Gilde des Chaos wird nur jemand aufgenommen, der unsere Ziele "
 "verfolgt. Eine gewisse Grundeinstellung ist dafuer schon noetig. Nur "
 "dann kann man ueberhaupt die maechtige aber auch sehr gefaehrliche Magie "
 "erlernen. Du kannst der Gilde mit 'trete gilde bei' beitreten.",
 "sagt: " );
 
 AddInfo("magier",
 "Magier sind doof und stinken!", "sagt: ");

 AddInfo(({"ritualmeister","wuqour"}),
  "Wuqour ist unser Ritualmeister. Er steht fuer gewoehnlich im "
  "Beschwoerungs- und Ritualraum herum und kann Dir bei der Beschwoerung "
  "von Daemonen sicherlich helfen.", "sagt: ");

 AddInfo(({"beschwoerungsraum","ritualraum"}),
 "Der Ritualraum befindet sich auch in dieser Festung. Nur Gilden-Mitglieder "
 "haben dort Zutritt.", "sagt: ");

 AddInfo(({"nachtblind","nachtblindheit"}),
 "Wenn die Nachtsicht nachlaesst, dann kann man fuer einige Zeit keinen "
 "neuen Nachtsichtzauber sprechen. Man ist solange nachtblind. Je hoeher "
 "deine Stufe in der Gilde ist, umso kuerzer ist diese Zeit.", "sagt: ");

 AddInfo(({"ziele","ziel"}),
 "Unsere Ziele sind sehr geheim. Ich kann Dir nur soviel sagen: Es "
 "geht um die Weltherrschaft.", "sagt: ");

 AddInfo( "grundeinstellung",
 "Du musst schon boese sein, um in unserer Gilde aufgenommen zu werden.",
 "sagt: ");

 AddInfo(({"boese","bosheit"}),
 "Boese ist der, der Boeses tut.","sagt weise: ");
 
 AddInfo(({"chaot","chaoten"}),
 "grinst daemonisch.\n");    
 
 AddInfo("zardoz",
 "Zardoz ist der bloede Magier, der diese Gilde erschaffen hat. Wenn Du Dich "
 "also beschweren willst, so wende Dich an ihn. Aber wahrscheinlich ignoriert "
 "er Dich, so wie ich ihn kenne.","sagt: ");
 
 AddInfo(CHAOS_ID_HUTSCHAT,
 capitalize(CHAOS_ID_HUTSCHAT)+" ist ein ganz wichtiges Mitglied unserer Gilde, "
 "denn er ist der einzige der sich mit der Verwaltung auskennt. Ohne ihn laeuft "
 "hier ueberhaupt nichts.", "sagt: ");
 
 AddInfo(({"verwalten","verwaltung"}),
 "Fuer die Verwaltung ist Hutschat zustaendig.", "sagt: " );
 
 AddInfo(({"magie"}),
 "Im Prinzip haben wir uns auf nur zwei Zweige der Magie beschraenkt. Zum "
 "einen beherrschen wir das zerstoererische Element Chaos und zum anderen "
 "koennen wir maechtige Daemonen aus ihren Dimensionen herbeirufen.",
 "sagt: " );

 AddInfo(({"chaos"}),
 "Chaos ist ein maechtiges, ungeformtes Element. Es besitzt die "
 "unterschiedlichsten Erscheinungsformen, die wir zu manipulieren wissen.",
 "fluestert: ");

 AddInfo(({"formen","erscheinungsformen"}),
  "Chaos kann z.B. als Feuer, Wasser, Blitze oder Kaelte auftreten.",
  "sagt: " );

 AddInfo(({"element","elemente"}),
 "Es gibt die unterschiedlichsten Elemente, von denen Dir sicherlich einige "
 "bekannt vorkommen: Feuer, Wasser, Eis, Luft... Chaos setzt sich aus "
 "allen diesen Elementen zusammen. Es besitzt dadurch zwar mehr Macht, doch "
 "es laesst sich auch schwerer beherrschen.",
 "sagt: ");

 AddInfo(({"daemon","daemonen"}),
 "Es gibt die unterschiedlichsten Daemonen. In der Gilde kann man die "
 "Beherrschung einiger Daemonen erlernen. Man wird nie alle Daemonen "
 "beherrschen koennen, denn erstens muss man ihren Namen kennen, und "
 "zweitens sind viele Daemonen viel zu maechtig, um sich von einfachen "
 "Sterblichen beschwoeren zu lassen.","grinst: ");
 
 AddInfo(({"name","namen"}),
 "Die Namen der Zaubersprueche zur Beschwoerung von Daemonen sind gleich "
 "den Namen der Daemonen, die beschwoert werden sollen. Die Daemonen heissen: "
 "Intarbir, Kruftur, Ombatis, Bhuturih, Irkitis, Tyoorthok, Harkuhu, Graiop, "
 "Flaxtri und Tutszt.","sagt: " );
 
 AddInfo(({"lernen","lerne"}), 
 "Mit 'lerne' erhaelst Du eine Liste aller Zaubersprueche dieser Gilde. "
 "Du kannst mich dann zu jedem dieser Zaubersprueche befragen, ich kenne "
 "sie alle.", "sagt: ");

 AddInfo(({"zauberspruch", "zaubersprueche", "spruch", "sprueche", "spells",  
           "zauberspruechen", "zauber", "zauberei", "spruechen", "zaubern"}),
 "Du kannst mit 'lerne <name>' die Zaubersprueche lernen, wenn Du die "
 "entsprechende Gildenstufe erreicht hast. Zu den Gildenstufen kann Dir "
 +capitalize(CHAOS_ID_HUTSCHAT)+" mehr sagen, aber ich kann Deine "
 "Zauber-Faehigkeiten beurteilen. Wenn Du Daemonen beschwoeren willst, dann "
 "frag am besten "+capitalize(CHAOS_ID_WUQOUR)+" im Beschwoerungsraum. Er ist "
 "unser Ritual-Meister.", "sagt: ");

 AddInfo(({"faehigkeiten", "faehigkeit", "zauberfaehigkeit", "koennen",
           "zauberfaehigkeiten", "beurteilung", "beurteilen", "status",
           "beherrschung" }),#'sag_beurteilung);
 
 AddInfo(({"anforderungen", "anforderung", "eintritt", "aufnahme", "antrag",
           "eintreten", "beitreten", "beitritt", "stufe", "stufen", "level",
           "gildenstufe", "gildenstufen", "bedingungen", "bedingung",
           "gildentitel", "gildenlevel", "aufnahmebedingungen",
           "aufnahmebedingung", "titel","gilden-titel", "anmeldung"}),
  "Hmmm... Frag mal Hutschat, der ist dafuer zustaendig.", "sagt: ");

 AddInfo(({"erhoehung", "erhoehen", "erhoehe", "stufenerhoehung", 
           "gildenerhoehung", "gildenstufenerhoehung", "aufsteigen", "aufstieg", 
           "eignung", "erfordernis", "erfordernissen" }), 
   #'erhoehen, "sagt: ");

 AddInfo(({"aufgabe","aufgaben"}),
 "Um eine Stufe zu erhoehen muss jedes Mitglied eine Pruefung (und in "
 "manchen Stufen auch eine besondere Aufgabe) loesen und bestehen. Dies "
 "wird dir in den Anforderungen zur Erhoehung erklaert.", "sagt: ");
 
 AddInfo(({"pruefung", "pruefungen", "kampfpruefung", "kampfpruefungen" }),   
 "Sobald Du deine Zaubersprueche gut genug kannst, darfst Du die Pruefung "
 "in der gildeneigenen Kampfarena beginnen. Dort musst Du gegen unseren "
 "Pruefungs-Meister kaempfen und gewinnen. Es ist zwar kein Kampf auf Leben "
 "und Tod, aber wenn Du fliehen solltest, dann musst Du den Kampf nochmal von "
 "vorne beginnen. Wenn Du noch kein Mitglied der Gilde bist, so musst Du einen "
 "Kampf als Aufnahmepruefung in der gildeneigenen Kampfarena gewinnen.",
 "sagt: ");
 
 AddInfo(({"kampf","kaempfen"}),
  "Der Kampf in der Kampfarena der Chaosgilde kann gefaehrlich fuer Dich "
  "werden. Du sollest ihn nur gut vorbereitet beginnen, denn es ist zwar kein "
  "Kampf auf Leben und Tod, aber wenn Du fliehen solltest, dann beginnt der "
  "Kampf wieder von vorne. Dein Gegner kann natuerlich Deine Staerke "
  "abschaetzen und sich darauf einstellen.", "sagt: ");
 
 AddInfo(({"pruefer","gegner"}),
 "Dein Gegner richtet sich nach Deiner Staerke. Du kannst den Kampf also "
 "auch gewinnen, wenn Du nicht so gute Werte hast. Allerdings solltest Du "
 "nicht ohne halbwegs gute Ausruestung diesen Kampf wagen.", "sagt: ");

 AddInfo("yruruu",
 "Dies ist er Pruefer, gegen den Du gewinnen musst, wenn Du in unsere Gilde "
 "aufgenommen werden willst. ", "sagt: ");

 AddInfo("tyoorthok",
 "Das ist ein alter und sehr weiser Daemon, der Dir einiges ueber Deine "
 "koerperliche Verfassung und Aufnahmefaehigkeit sagen kann. Zudem kann "
 "er fiese und nervige Krankheiten heilen. Er hilft Dir sicher gern, auch "
 "wenn derartige Nettigkeiten unter Chaoten verpoent sind. ", "sagt: ");

 AddInfo("krankheiten",
 "Man munkelt, es waeren die Krankheiten, die einmal (vor langer langer "
 "Zeit) unsere Chaoshaut abgewehrt hat. ", "sagt: ");

 AddInfo("ziumtu", 
 "Gegen Ziumtu musst Du in der Kampfarena gewinnen, wenn Du in der Gilde "
 "aufsteigen willst. Der Kampf wird natuerlich von Stufe zu Stufe "
 "schwieriger!", "sagt: ");

 AddInfo(({"pentagramm", "pentagramme", "bannkreis", "bannkreise", "gift",
           "frosch", "froesche", "heilung", "heilen", "blind", "blindheit", 
           "ritual", "rituale", "beschwoerungen", "beschwoerung", "zeichnen", 
           "beschwoeren", "kreise" }),
 "Frag dazu mal Wuqour. Er kann Dir weiterhelfen.", "sagt: ");
 
 AddInfo( "aufnahmepruefung",
 "Du musst einen Kampf in der gildeneigenen Kampfarena gewinnen. Dann wirst "
 "Du in der Gilde aufgenommen.", "sagt ");
 
 AddInfo(({"kampfarena","arena"}),
 "Die Kampfarena befindet sich auch hier in der Festung. Wenn Du dort "
 "dem Schiedsrichter zunickst, startet sofort der Kampf, der darueber "
 "entscheiden wird, ob Du deine Stufe erhoehen kannst.", "sagt: ");

 AddInfo("nachtsicht",
 "Dieser Zauberspruch ermoeglicht es, im Dunkeln zu sehen.", "sagt: ");

 AddInfo("dunkelheit",
 "Mit diesem schoenen Zauberspruch kannst Du einen Raum fuer einige Zeit "
 "verdunkeln.", "sagt: ");

 AddInfo(({ "ruestung", "chaosruestung" }),
 "Dies ist vielleicht der wichtigste Zauberspruch unserer Gilde. Erst dieser "
 "Spruch macht Dich zu einem richtigen Krieger des Chaos. Man beschwoert "
 "einen Chaosdaemonen, der aber nicht erscheint, sondern sofort in Deine "
 "Haut eindringt und diese mutieren laesst. Sie wird so viel "
 "widerstandsfaehiger und wirkt wie eine Ruestung. Der Daemon ist leider "
 "nicht sehr gluecklich darueber, und so versucht er zu entkommen. Aber wir "
 "haben fuer solche Faelle den Kontrolle-Zauberspruch entwickelt, der "
 "den Daemonen bannt. Ohne diese mutierte Haut funktionieren auch die "
 "meisten unserer Zaubersprueche nicht.", "sagt: ");

 AddInfo(({ "mutierte haut", "haut", "chaoshaut" }),
 "Wir sind auf unsere mutierte Haut sehr stolz und tragen deshalb darueber "+
 "keine andere Ruestung. Obwohl sie manchmal auch unangenehm werden kann "+
 "ist sie dennoch sehr nuetzlich. Die mutierte Haut wird uebrigens immer "+
 "besser, je hoeher Deine Gilden-Stufe ist.", "sagt: ");
 
 AddInfo( "kontrolle",
 "Dieser Zauberspruch ist sehr sehr wichtig. Deshalb verlangen wir auch, "
 "dass jedes Mitglied unserer Gilde diesen gut beherrscht. Nur dieser "
 "Zauberspruch ist in der Lage, den Chaosdaemonen der Chaosruestung zu "
 "bannen und ruhig zu stellen. Gelingt dieser Spruch nicht, so kann die "
 "Chaosruestung unter Umstaenden toedlich werden.", "sagt: ");
 
 AddInfo(({"binde"}),
 "Mit diesem Zauberspruch kannst Du Deine Verbindung mit einem Daemonen "
 "erneuern. Er wird Dir, wenn der Spruch gelingt, eine laengere Zeit folgen.",
 "sagt: " );

 AddInfo("schutz",
 "Mit diesem Spruch kannst Du die Chaosruestung kurzzeitig magisch "
 "verbessern. Dabei kannst zu zwischen zwei Arten waehlen: Einfach nur "
 "'schutz' oder 'schutz schwach' erhoeht den Schutz nicht sehr stark, "
 "haelt dafuer aber laenger an, oder 'schutz stark' erhoeht den magischen "
 "Schutz stark, schuetzt aber nur eine sehr kurze Zeit.", "sagt: ");
 
 AddInfo("chaosball", 
 "Der Chaosball ist ein maechtiger Angriffszauber. Man bewirft seinen "
 "Gegner mit Chaos in seinen unterschiedlichsten Erscheinungsformen. So "
 "kann es sich als flammende Feuerkugel, als frostige Wolke oder als "
 "ein magischer Strahl manifestieren. Mit dem Zauberspruch Chaosschaden "
 "kannst Du dir die Schadensart des Chaosballs aussuchen.",
 "schwaermt: ");
 
 AddInfo(({"chaosschaden","chaosschaeden"}),
 "Mit diesem Spruch kannst Du die Art des Schadens des Chaosballs bestimmen. "
 "Dir stehen sehr viele verschiedene Schadenstypen zur Verfuegung, die "
 "je nach Gegner mehr oder weniger gut sind: Feuer, Eis, Sturm, Magie, " 
 "Krach, Wasser, Blitz, Pfeil, Messer, Felsen, Boese, Saeure, "
 "Terror, Peitsche, Quetschen, Explosion, Widerhaken und Gift.", "sagt: ");
 
 AddInfo("chaoskontrolle",
 "Mit diesem Spruch kannst Du die Art des Schadens des Chaosballs "
 "kontrollieren. Oder zumindest kannst Du dies versuchen. Aber dies "
 "geschieht nicht, wie bei diesem dummen Chaosschaden. "
 "Du kannst alle mechanische Schaeden und den Rest kombinieren, "
 "wenn es denn einen Rest geben sollte.","sagt: ");
 
 AddInfo(({"feuer", "eis", "sturm", "magie", "wasser", "blitz",
            "saeure", "gift" ,"terror","peitsche"}),
 "Na, was ist das wohl?", "fragt: ");

 AddInfo("bannzauber",
 "Mit diesem Zauberspruch kannst Du einen Bannkreis verstaerken und dich "
 "so bei der Beschwoerung besser vor den Daemonen schuetzen. Ausserdem "
 "erhoeht es die Wahrscheinlichkeit, dass der Daemon dir gehorcht und nicht "
 "voellig eigensinnig handelt. Bei den niederen Daemonen ist er noch nicht "
 "unbedingt noetig, aber bei den richtig fiesen Daemonen kommst Du ohne ihn "
 "gar nicht aus.", "sagt: ");
 
 AddInfo("verbanne",
 "Diese magischen Worte koennen Daemonen in ihre Daemonendimensionen "
 "verbannen. Sollten sie nicht sofort verschwinden, so wird ihnen dennoch "
 "ein grosser Schaden zugefuegt. Der Spruch ist aber NUR gegen Daemonen "
 "anwendbar! Er funktioniert aber auch gegen den Daemon in Deiner Haut. Du "
 "kannst damit die Chaosruestung los werden.","sagt: " );

 AddInfo( "finsternis",  
 "Die Wolke der Finsternis ist ein maechtiger Zauberspruch. Man kann damit "
 "seinen Gegner fuer kurze Zeit kampfunfaehig machen und so auf ihn "
 "einschlagen, ohne dass er sich wehren kann.", "sagt: ");

 AddInfo("intarbir",
 "Der Daemon Intarbir hat ein besonderes Gespuer fuer die Kraft und "
 "Kampffaehigkeit von Monstern. Er kann Dir nuetzliche Informationen ueber "
 "einen Gegner geben. Syntax: 'befehle intarbir schaetze <monster> ein'.", 
 "sagt: "); 
 
 AddInfo("kruftur",
 "Kruftur ist der Denkdaemon. Er kann bei Gegenstaenden oder Monstern "
 "magische Faehigkeiten erkennen. Du musst ihm nur den Gegenstand geben "
 "oder diesen ihm nennen. Er kann natuerlich auch Monster identifizieren. "
 "Der Syntax dazu ist: 'befehle kruftur identifiziere <name>'. ","sagt: ");
 
 AddInfo("ombatis",
 "Ombatis hat es vorgezogen, auf nimmerwiedersehen in die Daemonendimension "
 "zu verschwinden. Deshalb koennen wir ihn auch nicht mehr beschwoeren.",
 "sagt: ");
 
 AddInfo("irkitis",
 "Ha, der wilde Halbdunkeldaemon mit dem Namen Irkitis ist ein flinker und "
 "hinterhaeltiger Kaempfer. Er ist so schnell, dass ihn nie ein Gegner "
 "trifft.", "sagt: ");
 
 AddInfo("harkuhu",
 "Der etwas seltsam aussehende Lichtdaemon ist zwar kein guter Kaempfer, "
 "aber er kann einiges Einstecken, ehe er wieder verschwindet.","sagt: ");

 AddInfo("bhuturih",
 "Bhuturih, eine nette Daemonin, manchmal. Sie kann Spieler fuer "
 "Dich finden und gelegentlich mehr als das. Aber traue ihr "
 "nicht! Sie ist ein Luder!","sagt: ");

 AddInfo("graiop",
 "Graiop, so heisst ein recht starker Feuerdaemon. Er ist ein ganz "
 "brauchbarer Kaempfer, der natuerlich aufgrund seiner Art im Dunkeln "
 "leuchtet.","sagt: ");
 
 AddInfo("flaxtri",
 "Flaxtri ist ein aeusserst gefaehrlicher Saeuredaemon, dessen aetzende "
 "Schleimhaut schwere Verletzungen bei Beruehrung hervorruft. Er ist ein "
 "ganz besonders wilder Kampfdaemon.","sagt: ");

 AddInfo("tutszt",
 "Du fragst mich nach dem staerksten Daemon? Ha! Tutszt ist ein Blutdaemon, "
 "was schon genug sagen sollte. Er ist wirklich sehr wild und gefaehrlich. "
 "Seine Blutgier ist ueberall gefuerchtet, deshalb duerfen ihn auch nur die "
 "allerbesten Krieger des Chaos beschwoeren.","sagt: ");

 AddInfo(({"handschuhe","handschuhen"}),
 "Nun, diese Aufgabe ist nicht sehr einfach. Du sollst mir die weissen "+
 "Handschuhe des schwarzen Sheriffs bringen.", "sagt: ");

 AddInfo(({"master-quest", "metzel", "metzel-master-quest", 
	   "metzelmasterquest", "metzel-quest", "metzel quest", 
	   "metzel master quest" }),
 "Um die zehnte Gildenstufe zu erlangen, und damit Schwarzmagier des Chaos "
 "zu werden, musst Du die Metzel-Master-Quest machen. Deine Aufgabe besteht "
 "darin, die gefaehrlichsten Monster des MorgenGrauens zu toeten und als "
 "Beweis einen Teil von ihnen zu bringen. Du brauchst nicht alle Teile "
 "auf einmal zu bringen, Du kannst die Quest schrittweise machen. Sobald "
 "Du also einen Beweis hast, kannst Du ihn mir geben und die anderen Beweise "
 "spaeter abliefern.", "sagt: ");
 
 AddInfo(({"teil","teile","beweis","beweise"}),
 function string() { return
 "Also, bringe mir folgende Teile als Beweis, dass Du das Monster getoetet "
 "hast: Eine Schuppe des Schlammdrachen, das Un vom Untier, den Skalp der "
 "Leronis, das Deodorant von Lofwyr, die Orange vom orangenen Drachen, "
 "Wasser vom Wassertroll-Schamanen, ein Auge von Kruuolq und Etwas vom "
 "Etwas. Um zu erfahren, welche Teile Du mir schon brachtest, frage mich "
 "nach erledigte teile. "+gib_ring(); },"sagt: ");
 
 AddInfo(({"erledigte beweise","erledigte teile"}),
 #'metzel_quest_done,"sagt: ");
 
 AddInfo(({"ring","chaos-ring","chaosring"}),
 #'gib_ring, "sagt: ");
 
 AddInfo("ebene",
 "Du weisst nicht wo die Ebene ist???", "fragt: ");

 AddInfo(({ "drache", "drachen" }),
 "Welchen Drachen meinst Du?", "fragt: ");

 AddInfo( "parallelwelt",
 "Wie man dahin kommt weiss ich leider nicht.", "sagt: ");
 
 AddInfo(({"seher-ring","seherring"}),#'gib_seherring,"sagt: ");

 AddInfo(({ "erzmeister", "erzmeisterin" }),
  #'unser_aller_erzmeister, "sagt: ");
 AddInfo( "yrintri", #'special_yrintri, "sagt: ");
 AddInfo(({"erzmeisterkampf","meisterkampf"}),#'erzikampf_info,"sagt: ");
 
 // Chaosrattenquest
 
 //AddInfo(({"ratte","chaosratte","drecksratte"}),#'ratte,"sagt: ");
 AddInfo(({"uwe","uns-uwe"}),"Uns-Uwe ist selbst fuer einen Chaoten "
           "ungewoehnlich hinterhaeltig. Er wird Dich reinlegen, wo immer er "
           "kann!","sagt: ");
 //AddInfo(({"medaille"}),#'medal,"schnauzt: ");
 
 // Ende Chaosrattenquest                  
   
 enable_commands();
// call_out(#'raum_test,0);
 AddCmd(({"lern","lerne"}),"learnSomeSpell");
 
}           

static int raum_test()
{
  object tmp;

  if((file_name(environment(ME))!="/gilden/chaos" &&
      file_name(environment(ME))!=CHAOS_GILDEN_ROOM("cl2_gilde")))
  {
    foreach(tmp:all_inventory(ME))
      destruct(tmp);

    remove(ME);
  }
  return 1;
}

static string erzikampf_info()
{
 string s;
 int ezeit;

 s = "Jeder Chaot (oder Chaotin) mit mindestens Gildenlevel 11 kann hier "
     "durch den Befehl 'melde Erzmeisterkampf an' einen Kampf anmelden. Der "
     "naechste ";

 ezeit = (CHAOS_GILDENMASTER->query_duellzeit());

 if(ezeit > time())
   s += "kann erst nach "+dtime(ezeit)+" stattfinden!";
 
 else
   s += "koennte sofort angemeldet werden.";
 
 return s;
}
 
static string special_yrintri()
{
  if(CHAOS_GILDENMASTER->ist_erz(PL))
  {
    return "Yrintri ist der absolut maechtigste Daemon. Er ist in der Lage "
    "seine Gestalt zu aendern und kann so mal mit Feuer, mal mit Eis "
    "angreifen. Syntax: befehle yrintri verwandel dich in <art>. Natuerlich "
    "kann so ein gefaehrlicher Daemon nur vom Erzmeister persoenlich "
    "beherrscht werden. Aber das bist Du ja schliesslich.";
  }
  return "Halts Maul! Das geht Dich gar nix an!!!";
}

public varargs void init(object origin)
{
  string mags;
  ::init(origin);
  
  mags = getuid(PL);
  
  if(interactive(PL) && CHAOS_GILDENMASTER->ist_erz(PL))
    call_out(function void(object pl) {
      if(present(pl,environment(ME)))
      {
        tell_room(environment(),Name(WER)+" verneigt sich vor "+
                  (pl->QueryProp(P_GENDER)==1?"dem Erzmeister ":
                  "der Erzmeisterin ")+capitalize(getuid(pl))+".\n",({pl}));

        tell_object(pl,Name(WER)+" verneigt sich vor Dir mit dem Dir "
                       "gebuehrenden Respekt.\n");
      }
    },0,PL);

  if(mags=="it")
  {
    switch(random(10))
    {
      case 0..2:
        call_out(#'gildenmags,0,PL);
        break;
      default:
        break;
    }
  }
  if(interactive(PL) && PL->QueryProp(P_GUILD)=="klerus")
     call_out(#'boese,3,PL);
}

static int gildenmags(object pl)
{
  if(present(pl,environment(ME)))
  {
    switch (random(15))
    {
      case 0:
        tell_object(pl,(Name(WER)+" faellt auf die Knie und kuesst Deine "
                       "Fuesse!\n"));
        
        tell_room(environment(ME),Name(WER)+" faellt auf die Knie und "
                  "kuesst "+pl->name(WESSEN)+" Fuesse! Igitt!\n",({pl}));
        break;

      case 1..5:
        tell_object(pl,(Name(WER)+" zeigt Dir den Stinkefinger!\n"));
        
        tell_room(environment(ME),Name(WER)+" zeigt "+pl->name(WEM)+" den "
                  "Stinkefinger!\n",({pl}));
        break;

      case 6..10:
        tell_object(pl,(Name(WER)+" haut Dir eine aufs Maul!\n"));
        
        tell_room(environment(ME),Name(WER)+" haut "+pl->name(WEM)+" eine "
                  "aufs Maul!\n",({pl}));
        break;

      default:
        tell_room(environment(ME),Name(WER)+" sagt: Verdammt! Arbeite mal! "
                  "Idlen ist hier verboten "+pl->name(WER)+"!\n");
        break;
    } 
  }
  return 1;
}

/*
Kleriker mit einem Align von ueber -200 werden um 100 boeser gemacht,
also maximal -299:
*/

static int boese(object pl)
{
  int i,val;

  val = 100;

  if(present(pl,environment(ME)))
  {
    i = pl->QueryProp(P_ALIGN);

    if(i>-200)
    {
      pl->SetProp(P_ALIGN,i-val);
    
      tell_object(pl,break_string(Name(WER)+"starrt tief in Deine Augen. Ein "
                    "wohliges Gefuehl boeser Macht ueberflutet Deinen "
                    "Koerper."));

      tell_room(environment(ME),break_string(Name(WER)+" starrt "+
                pl->name(WEN)+" tief in die Augen."),({pl}));
    }
  }
  return 1;
}

static string unser_aller_erzmeister()
{
  string erzi;

  erzi = CHAOS_GILDENMASTER->query_erzmeister();

  return "Der Erzmeister ist der hoechste Rang in dieser Gilde. Es kann "
         "immer nur einen geben, er ist unser aller Oberhaupt. Zur Zeit ist "
         "dies "+(stringp(erzi)?capitalize(erzi):"leider niemand")+".";
}

varargs mixed StopHuntingMode(int silent)
{
  mapping save_enemy;
  object enemy;

  enemy = PL;

  if(present(enemy,environment(ME)))
  {
    if(query_once_interactive(enemy))
    {
      tell_room(environment(ME),ME->Name(WER)+" haut "+enemy->name(WEM)+
               " kraeftig aufs Maul!\n",({enemy}));
      
      tell_object(enemy,ME->Name(WER)+" haut dir kraeftig aufs Maul!\n");

      enemy->do_damage(30+random(20),ME);

      InsertEnemy(enemy);
    }
  }
  save_enemy = enemies;
  return save_enemy;
}

static string gib_ring()
{
  object ob;

  if(PL->QueryProp(P_GUILD_LEVEL)<9)
    return "Du hast noch nicht die Gilden-Stufe 9, also werde ich Dir "
           "jetzt noch keinen Chaos-Ring geben.";

  if(PL->QueryProp(P_GUILD_LEVEL)>10)
    return "Ne ne, Du hast die Quest schon gemacht.";

  if(present_clone(CHAOS_GILDEN_OBJ("cring"), PL))
  { 
    call_out(#'my_mistake,0,PL);
    return "Denk daran, dass Du den Chaos-Ring waehrend der Quest "+
           "tragen musst!";
   } 
  if(CHAOS_GILDENMASTER->QueryAufgabe(getuid(PL),"metzel_master_quest"))
    return "Aber Du hast diese Quest ja eh schon gemacht!";

  ob = clone_object(CHAOS_GILDEN_OBJ("cring"));
  ob->move(PL,M_NOCHECK);

  ob->do_wear("ring",1);

  call_out(#'my_mistake,0,PL);

  return "Ich gebe Dir einen Chaos-Ring, den Du waehrend der Quest tragen "
         "musst!!";
}

static string gib_seherring()
{
  object ob;

  if (PL->QueryProp(P_GUILD_LEVEL) < 11)
    return "Diese Quest ist nur fuer Chaoten der Stufe 11 gedacht.";

  if ((ob=present(CHAOS_ID_SEHER_RING_METZELQUEST,PL)))
  {
    if (ob->killed_all())
      return "Aaaah, Du hast das heilige Pack getoetet. Ich bin sehr "
             "stolz. Nun ueberreiche mir den Ring, auf dass ich Dich belohnen "
             "und preisen kann.";

    return "Du hast den Ring schon. Geh und toete die Monster, die Du "
           "noch toeten musst!";
  }
/*
  if( (C_112_OBJ("c_smmq_master"))->sget_zeit(getuid(PL))>0)
    return "Du hast die Quest schon bestanden. Ich bin stolz auf Dich.";
  ob=clone_object(C_112_OBJ("c_seher_ring"));
  if (ob->move(PL,M_GET) != 1)
    return "Leider kannst Du den Ring nicht mehr tragen!";
  ob->do_wear("chaos-ring",1);
*/
  return "Ich gebe Dir einen wahren Chaos-Ring, den Du waehrend der Quest "
         "tragen musst!!";
}

void my_mistake()
{
  tell_object(PL,
  
  Name(WER)+" raeuspert sich.\n"+
  Name(WER)+" sagt: Aehm, das mit meinem Auge vergiss mal lieber, bring mir\n"+
  Name(WER)+" sagt: stattdessen lieber die Warze von Liliths Nase.\n");
  return;
}
  
void catch_tell(string str)
{
  int zeit,ct,llp;
  string spieler,was,s,bla,blub;
  object pl;

  npc::catch_tell(str);

  str = lower_case(str);

  if(!sscanf(str,"%s teilt dir mit: %s", spieler, was))
    return;
  
  if(!pl=find_player(spieler)) return;

/*
Wenn Kruuolq kaempft gibt es keine Informationen und aehnliches:
*/

  if(InFight())
  {
    tell_object(pl,break_string("Ich bin gerade mit "+QueryEnemy()->name()+
                   " beschaeftigt, frag mich spaeter nochmal.",0,
                   Name(WER)+" teilt Dir mit: "));
    return;
   }                 

  was = was[0..<2];

  if(was=="beurteilung"||was=="faehigkeit"||was=="faehigkeiten"|| 
     was=="zauberfaehigkeit"||was=="zauberfaehigkeiten"||
     was=="koennen"||was=="status")
  {

    tell_object(pl,Name(WER)+" teilt Dir mit:\n");
    call_out(#'beurteilung,0,pl);
  }
  if(was=="erhoehen"||was=="erhoehung"||was=="aufsteigen"|| 
     was=="stufenerhoehung"||was=="anforderung")
  {
    s=break_string(erhoehen(),0,Name(WER)+" teilt Dir mit: ");
    call_out(#'tell_player,0,s,pl);
  }
  if(sscanf(was,"%smeld%s",bla,blub)==2)
  {
    if(PL->QueryProp(P_GUILD)!="chaos")
    {
      s=Name(WER)+" teilt Dir mit: Du bist kein Chaot!\n";
      call_out(#'tell_player,0,s,pl);
      return;
    }
    if(PL->QueryProp(P_GUILD_LEVEL)<11)
    {
      s=Name(WER)+" teilt Dir mit: Du bist kein Meister des Chaos!\n";
      call_out(#'tell_player,0,s,pl);
      return;
    }
    if(CHAOS_GILDENMASTER->IstKampf())
    {
      s=Name(WER)+" teilt Dir mit: Es laeuft schon ein Kampf!\n";
      call_out(#'tell_player,0,s,pl);
      return;
    }
    if(member(CHAOS_GILDENMASTER->query_duellier(),getuid(PL))!=-1)
    {
      s=Name(WER)+" teilt Dir mit: Du bist doch schon angemeldet!\n";
      call_out(#'tell_player,0,s,pl);
      return;
    }
    if((zeit=CHAOS_GILDENMASTER->query_duellzeit()) > time())
    {
      s=break_string("Der naechste Kampf kann fruehstens am "+
        dtime(zeit)+" stattfinden. Erst danach kannst Du dich erneut "+
        "anmelden!",0,Name(WER)+" teilt Dir mit: ");
        call_out(#'tell_player,0,s,pl);
    }
    CHAOS_GILDENMASTER->AddKaempfer(PL);
  }
/*
Der rituelle Selbstmord fuer sterbewillige Chaoten, kein Fake (sind ja nicht
bei Klerus oder Zaubis >:)
*/
  if(  (sscanf(was,"%slerike%s",bla,blub)==2) 
     ||(sscanf(was,"%sdusche%s",bla,blub)==2)
     ||(sscanf(was,"%setbrude%s",bla,blub)==2)
     ||(sscanf(was,"%seiche%s",bla,blub)==2))
  {
    if(PL->QueryProp(P_GUILD)!="chaos")
    {
      s=Name(WER)+" teilt Dir mit: Halts Maul!\n";
      call_out(#'tell_player,0,s,pl);
      return;
    }
    if(present(PL,environment(ME)))
    {
      tell_object(PL,Name(WER)+" fluestert: Sprich Dich ruhig aus.\n");
      return;
    }   
    llp = PL->QueryProp(P_HP);
    ct  = PL->QueryProp("last_combat_time"); 
    
    if( (time()-ct) <= 45 && llp <= 45 )
    {
      s = Name(WER)+" teilt Dir mit: DAS HAST DU NUN DAVON!!!\n";
      call_out(#'tell_player,0,s,pl);
      SetProp(P_KILL_NAME,Name(WESSEN)+" langer Arm der Ungerechtigkeit");
 //   SetProp(P_KILL_MSG,({"findet Dich ueberall!",MSG_EMOTE,SINGULAR}));
 //     SetProp(P_ENEMY_DEATH_SEQUENCE,"/gilden/files.chaos/texte/ehrentod.seq");
      PL->die();
      SetProp(P_KILL_NAME,Name(WER));
//    SetProp(P_KILL_MSG,"Es war ein fairer Kampf, da gibts nichts! >:)");
      SetProp(P_ENEMY_DEATH_SEQUENCE,0);
      return;
    }
    else
    {
      s = Name(WER)+" deutet aus der Ferne mit einem Finger auf Dich und "
          "sagt: LEIDE!\n";  

      call_out(#'tell_player,0,s,pl);

      PL->reduce_hit_points(10+random(10));
    } 
  }
  return;
}

void give_notify(object ob)
{
  ::give_notify(ob);
  if(ob->id(CHAOS_ID_HANDSCHUHE))
  {
    if(CHAOS_GILDENMASTER->QueryAufgabe(getuid(PL),"chaoshandschuhe"))
    {
      write("Du hast diese Aufgabe doch schon bestanden.\n"+
            Name(WER)+" laesst die Handschuhe fallen.\n");
    
      ob->move(environment(ME));
      return;
    }
    write("Vielen Dank! Damit hast Du diese Aufgabe bestanden!\n"+
          Name(WER)+" laesst die Handschuhe einfach verschwinden.\n");

    ob->remove();

    CHAOS_GILDENMASTER->SetzeAufgabe(getuid(PL),"chaoshandschuhe");
 
    return;
  }
  if(ob->id(CHAOS_ID_METZELOBJECT))
  {
    if(CHAOS_GILDENMASTER->QueryAufgabe(getuid(PL),"metzel_master_quest"))
    {
      write("Du hast die Quest doch schon gemacht!\n");
      ob->remove();
      return;
    }
    if(!PL->QueryProp("chaos_metzel_objekte")) 
    {
      PL->SetProp("chaos_metzel_objekte", 
           ({ ob->QueryProp(P_IDS)[sizeof(ob->QueryProp(P_IDS))-1] }));

      PL->Set("chaos_metzel_objekte", SAVE, F_MODE_AS );
    }
    else 
      PL->SetProp( "chaos_metzel_objekte", 
           PL->QueryProp( "chaos_metzel_objekte") +  
           ({ ob->QueryProp(P_IDS)[sizeof(ob->QueryProp(P_IDS))-1] }));
    
    tell_object( PL, Name(WER)+" sagt: Vielen Dank.\n");
    ob->remove();
/*
	if( !metzel_quest_check(PL)) 
		tell_object( PL, 
			"Kruuolq sagt: Dann bringe mir noch die restlichen Sachen.\n");
*/
  }
}

/*
Zum senden, nicht von ausserhalb:
*/

int sach_was(string txt)
{
  if(extern_call()) return 0;
  //catch(CHMASTER->send("Chaos", ME,txt, MSG_SAY));
 return 1;
}

string metzel_quest_done() 
{
  mixed ids;
  string str;

  if (!objectp(PL)) return "";

  ids = PL->QueryProp( "chaos_metzel_objekte" );

  if (!pointerp(ids))
    return "Du brachtest mir bis jetzt noch keine Teile.";

  str = "Du brachtest mir bis jetzt folgende Teile: ";
          
  if( member( ids, "untier_un")!=-1)
    str+="das Un vom Untier, ";

  if( member( ids, "odrache_orange" )!=-1) 
    str+="die Orange vom orangenen Drachen, ";

  if( member( ids, "lofwyr_deo") !=-1) 
    str+="das Deodorant von Lofwyr, ";

  if( member( ids, "etwas_etwas" )!=-1)
    str+="Etwas vom Etwas, ";

  if( member( ids, "schlammdrachen_schuppe")!=-1)
    str+="eine Schuppe des Schlammdrachen, ";

  if( member( ids, "leronis_skalp" ) !=-1)
    str+="den Skalp der Leronis, ";

  if( member( ids, "liliths_nasen_warze") !=-1) 
    str+="die Warze von Liliths Nase, ";

  if( member( ids, "schamane_wasser") !=-1 ) 
    str+="Wasser vom Wassertroll-Schamanen, ";

  str = str[0..sizeof(str)-3]+". ";

  switch(sizeof(ids)) 
  {
    case 0..3 : str+="Da hast Du ja noch einiges vor Dir :-).";break;
    case 4..5 : str+="Na, die Haelfte hast Du ja schonmal!";break;
    case 6..9 : str+="Go Go Go! Fast ist es geschafft!";break;
  }
  return str;
}

int metzel_quest_check(object pl)
{
  mixed ids;
  int stufe;

  ids = pl->QueryProp( "chaos_metzel_objekte" );

  if(member(ids,"untier_un")       !=-1 && 
     member(ids,"odrache_orange")  !=-1 &&
     member(ids,"lofwyr_deo")      !=-1 && 
     member(ids,"etwas_etwas")     !=-1 && 
     member(ids,"schlammdrachen_schuppe")!=-1 && 
     member(ids,"leronis_skalp" )  !=-1 && 
     member(ids,"liliths_nasen_warze") !=-1 && 
     member(ids,"schamane_wasser") !=-1)  
  {
    if(pl->QueryProp(P_GUILD) != "chaos" )
    {
      tell_object(pl,"Du bist kein Mitglied der Chaos-Gilde!\n");
      pl->SetProp( "chaos_metzel_objekte", 0);
      return 0;
    }
    tell_object(pl,break_string("Gratulation! Du hast Deine Aufgabe gut "
               "gemacht! So, damit kannst Du nun Deine Stufe erhoehen, wenn "
               "die anderen Anforderungen erfuellt sind.",0,
               Name(WER)+" sagt: "));
/*
Damits auch alle mitkriegen:
*/		
    //    catch(CHMASTER->join("Chaos", ME));		
    sach_was(capitalize(getuid(PL))+" hat soeben die Metzel - Master - "
             "Quest bestanden!");
      //  catch(CHMASTER->leave("Chaos", ME));     

    object ob;

    if(ob = present_clone(CHAOS_GILDEN_ARMOUR("chaosring"), pl))
    {
      tell_object(pl,Name(WER)+" sagt: Den Ring brauchst Du nicht mehr.\n"+
                     Name(WER)+" nimmt Dir den Chaos-Ring ab.\n");
          
      ob->remove();
    } 
    CHAOS_GILDENMASTER->SetzeAufgabe( getuid(pl), "metzel_master_quest" );
    pl->SetProp( "chaos_metzel_objekte", 0);
    return 1;
  } 
  return 0;
}

/*
So, nun wirds spannend:
*/

void Attack(object enemy)
{
  if(!enemy || !living(enemy))
    return;      // erstmal befrieden und dann ab 
  
  if(!ME->QueryProp(P_DUELLANT))          // in die private Duell-Arena von    
  {
    ME->SetProp(P_DUELLANT,1);            // Kruuolq:
    enemy->StopHuntFor(ME);
    
    ME->StopHuntFor(enemy);
    
    tell_room(environment(ME),Name(WER)+" verschwindet in seinen geheimen "
              "Uebungsraum.\n"+enemy->name()+" trottet "+name(WEM)+
              " hinterher.\n",({enemy}));
    

    ME->move(CHAOS_GILDEN_ROOM("duell"),M_GO|M_SILENT);

    tell_object(enemy,break_string("Du willst kaempfen? OK! Dann komm mal "
     "mit, braucht ja nicht jeder hier Zeuge Deiner Niederlage zu "
     "werden.\n",0,Name(WER)+" teilt Dir mit: "));
    
    enemy->move(CHAOS_GILDEN_ROOM("duell"),M_GO|M_SILENT|M_NO_SHOW);
  }
  if(ME->QueryProp(P_DISABLE_ATTACK))
    ME->SetProp(P_DISABLE_ATTACK,0);
  
  if(ME->QueryProp(P_TMP_ATTACK_HOOK))
    ME->SetProp(P_TMP_ATTACK_HOOK,0);
  
  if(living(enemy))
  {
    if (blutmagie>0)  // siehe Raum C_112_ROOM("cl3_cerz3")
    {
      tell_object(enemy,Name(WER)+" bruellt und schleudert die Blutmagie "
                        "auf Dich.\n");
      
      enemy->Defend(blutmagie+random(blutmagie),"blut",
                    ([SP_SHOW_DAMAGE:1]),ME);
      
      heal_self(blutmagie);
      blutmagie = 0;
      if (!enemy || enemy->QueryProp(P_GHOST)) return;
    }
    switch(random(60))
    {
      case 0..8:
      tell_object(enemy,Name(WER)+" feuert eine frostige Eiswolke auf Dich "
                        "ab.\n");
      enemy->Defend(400+random(100),DT_COLD,1,ME);
      break;
      
      case 9..13:
      tell_object(enemy,Name(WER)+" feuert einen satanischen Fluch auf "+
                       "Dich ab.\n");
      enemy->Defend(400+random(100),DT_DARKNESS,1,ME);
      break;
      
      case 14..18:
      tell_object(enemy,Name(WER)+" feuert eine hinterhaeltige "
                        "Terrorattacke auf Dich ab.\n");
      enemy->Defend(400+random(200),DT_TERROR,1,ME);
      break;

      case 19..23:
        tell_object(enemy,Name(WER)+" feuert einen explosiven Magierschaedel "
                          "auf Dich ab.\n");
      enemy->Defend(500+random(100),DT_EXPLOSION,1,ME);
      break;
      
      case 24..30:
      tell_object(enemy,Name(WER)+" feuert einen giftigen Pfeil auf Dich "
                        "ab.\n");
      enemy->Defend(450+random(100),DT_PIERCE,1,ME);
      break;
      
      case 31..37:
      tell_object(enemy,Name(WER)+" feuert schreiende Widerhaken "
                        "auf Dich ab.\n");
      enemy->Defend(450+random(100),DT_SOUND,1,ME);
      break;
      
      case 38..45:
      tell_object(enemy,Name(WER)+" feuert stuermische Felsen auf "
                        "Dich ab.\n");
      enemy->Defend(450+random(100),DT_BLUDGEON,1,ME);
      break;         
      
      case 46..50:
      tell_object(enemy,Name(WER)+" umhuellt Dich mit einer Wolke aus "+
                        "Finsternis.\n"); 
      enemy->SetProp(P_DISABLE_ATTACK, enemy->QueryProp(P_DISABLE_ATTACK) +
                                        2 + random(5));
      break;
      
      default:
        break;
    }
  }
  if(!enemy || enemy->QueryProp(P_GHOST))
    return;
 
  ::Attack(enemy);  
   SetProp(P_KILL_MSG,"Es war ein fairer Kampf, da gibts nichts! >:)");
}

void enhance(int stufe,int rating,object ob)
{
   if(stufe>50)
     stufe = 50;

   if(rating>7500)
     rating = 7500;

   blutmagie = ((1000*stufe*rating)/(7500*50));
   
   say("Eine blutrote Wolke steigt aus dem Boden empor und erfuellt "
       +name(WEN)+".\nDu bekommst grosse Angst.\n");

   SetProp(P_KILL_MSG,"Ich danke Dir, "+capitalize(getuid(ob))+". Dein Blut "
                      "hatte die Macht, diesen Gegner zu besiegen.");
   return;
}

/*
Spieler tot? Alles klar, aufraeumen und zurueck in die Gilde:
*/

void NotifyPlayerDeath(object player)
{
 string pos;

 pos = file_name(environment(ME));

 if(pos[0..sizeof(CHAOS_GILDEN_ROOM("duell"))-1]==CHAOS_GILDEN_ROOM("duell"))
 {
    player->StopHuntFor(ME);
 
    tell_object(player,break_string("Wenn Du Deine Sachen wieder haben "
                       "moechtest, frag doch mal unseren Erzmeister.",
                       0,Name(WER)+" teilt Dir mit: "));
 
    ME->StopHuntFor(player);
    ME->SetProp(P_DUELLANT,0);

    command_me("iss leiche");

    ME->heal_self();

    (CHAOS_GILDEN_ROOM("duell"))->aufraeumen(0);

    ME->move(CHAOS_GILDENROOM,M_GO);
  }
}
       
string erhoehen()
{
  int level;
  string bla;

  if(PL->QueryProp( P_GUILD) != "chaos" )
    return "Du gehoerst nicht dieser Gilde an!";

  level = PL->QueryProp(P_GUILD_LEVEL);

  if(level > 10) 
    return "Du bist doch schon ein Meister des Chaos.";

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(PL);

  if(!bla)
    bla = "Du beherrscht die Zaubersprueche ausreichend gut. ";

  if( !CHAOS_GILDENMASTER->QueryPruefung(getuid(PL), level+1))
    bla += "Du musst noch einen Kampf in der gildeneigenen Kampfarena "
           "gewinnen. ";

  else bla += "Du hast den Kampf auch schon bestanden. ";

  switch(level)
  {
    case 1:
    if(PL->QueryProp(P_LEVEL) < 6)
      bla += "Du brauchst mindestens Spielerlevel 6. ";
    break;

    case 2:
    if(PL->QueryProp(P_LEVEL) < 8)
      bla += "Du brauchst mindestens Spielerlevel 8. ";
    if(PL->QueryAttribute(A_INT) < 7)
      bla += "Deine Intelligenz muss groesser 6 sein. ";
    if(PL->QueryAttribute(A_CON) < 8)
      bla += "Deine Aussdauer muss mindestens einen Wert von 8 haben. ";
    break;	

    case 3:
    if(PL->QueryProp(P_LEVEL) < 10)
      bla += "Du brauchst mindestens Spielerlevel 10. ";
    break;	

    case 4:
    if(PL->QueryProp(P_LEVEL) < 12)
      bla += "Du brauchst mindestens Spielerlevel 12. ";
    if(PL->QueryAttribute(A_INT) < 12)
      bla += "Deine Intelligenz muss mindestens einen Wert von 12 haben. ";
    break;	

    case 5:
    if(PL->QueryProp(P_LEVEL) < 14)
      bla += "Du brauchst mindestens Spielerlevel 14. ";
    break;	

    case 6:
    if(PL->QueryProp(P_LEVEL) < 16)
      bla += "Du brauchst mindestens Spielerlevel 16. ";
    if(PL->QueryAttribute(A_INT) < 15)
      bla += "Deine Intelligenz muss mindestens einen Wert von 15 haben. ";
    break;	

    case 7:
    if(PL->QueryProp(P_LEVEL) < 18)
      bla += "Du brauchst mindestens Spielerlevel 18. ";
    if(PL->QueryAttribute(A_CON) < 15)
      bla += "Deine Aussdauer muss mindestens einen Wert von 15 haben. ";
    if(PL->QueryAttribute(A_DEX) < 13)
      bla += "Deine Geschicklichkeit muss mindestens einen Wert von 13 "
             "haben. ";
    if(PL->QueryAttribute(A_STR) < 14)
      bla += "Deine Staerke muss mindestens einen Wert von 14 haben. ";
    break;	

    case 8:
    if (!IS_SEER(PL))
      bla+="Du musst natuerlich Seher"+((PL->QueryProp(P_GENDER)==2)?"in":"")+
           " werden. ";
    break;	

    case 9:
    if(PL->QueryProp(P_LEVEL) < 27)
      bla += "Du brauchst mindestens Spielerlevel 27. ";
    if(PL->QueryProp( P_QP)<1650)
      bla += "Du hast noch keine 1650 Abenteuerpunkte! ";
    if(PL->QueryAttribute(A_STR) < 17)
      bla += "Deine Staerke muss mindestens einen Wert von 17 haben. ";
    if(PL->QueryAttribute(A_DEX) < 17)
      bla += "Deine Geschicklichkeit muss mindestens einen Wert von 17 "
             "haben. ";
    if(PL->QueryAttribute(A_CON) < 19)
      bla += "Deine Ausdauer muss mindestens einen Wert von 19 haben. ";
    if(PL->QueryAttribute(A_INT) < 17)
      bla += "Deine Intelligenz muss mindestens einen Wert von 17 haben. ";
    break;

    case 10:
    if(PL->QueryProp(P_LEVEL) < 35)
      bla += "Du brauchst mindestens Spielerlevel 35. ";
    if(PL->QueryAttribute(A_INT) < 20)
      bla += "Deine Intelligenz muss mindestens einen Wert von 20 haben. ";
    if(PL->QueryAttribute(A_CON) < 19)
      bla += "Deine Ausdauer muss mindestens einen Wert von 19 haben. ";
    if(PL->QueryAttribute(A_DEX) < 19)
      bla += "Deine Geschicklichkeit muss mindestens einen Wert von 19 "
             "haben. ";
    if(PL->QueryAttribute(A_STR) < 19)
      bla += "Deine Staerke muss mindestens einen Wert von 19 haben. ";
    if(PL->QueryProp( P_QP) < 1900)
      bla += "Du hast noch keine 1900 Abenteuerpunkte! ";
    break;
  }
  return bla;
}

string sag_beurteilung()
{
  call_out(#'beurteilung,0,PL);
  return "grinst breit.\n";
}

static int beurteilung(object pl)
{
  int w;
  string s;

  if(pl->QueryProp(P_GUILD)!="chaos")
  {
    tell_object(pl,"Du gehoerst dieser Gilde gar nicht an.\n");
    return 1;
  }
  s="Hier kommt die Liste Deiner Faehigkeiten:\n";
  s+="Du kannst folgende Zaubersprueche:\n";
  if(w=pl->QuerySkillAbility("nachtsicht"))    
    s+="Nachtsicht                  : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("dunkelheit"))
    s+="Dunkelheits-Zauber          : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("chaosruestung"))
    s+="Chaosruestung               : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("kontrolle"))
    s+="Kontrolle-Spruch            : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("bannzauber"))
    s+="Bannzauber                  : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("schutz"))
    s+="Schutz                      : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("chaosball"))
    s+="Chaosball                   : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("chaosschaden"))
    s+="Chaosschaden-Zauber         : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("verbanne"))
    s+="Verbanne-Zauber             : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("binde"))
    s+="Der Binde-Zauber            : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("chaoskontrolle"))
    s+="Chaoskontrolle              : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("finsternis"))
    s+="Wolke der Finsternis        : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("intarbir"))    
    s+="Beschwoerung von Intarbir   : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("kruftur"))    
    s+="Beschwoerung von Kruftur    : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("ombatis"))    
    s+="Beschwoerung von Ombatis    : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("bhuturih"))    
    s+="Beschwoerung von Bhuturih   : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("irkitis"))
    s+="Beschwoerung von Irkitis    : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("tyoorthok"))
    s+="Beschwoerung von Tyoorthok  : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("harkuhu"))    
    s+="Beschwoerung von Harkuhu    : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("graiop"))    
    s+="Beschwoerung von Graiop     : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("flaxtri"))    
    s+="Beschwoerung von Flaxtri    : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("tutszt"))    
    s+="Beschwoerung von Tutszt     : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  if(w=pl->QuerySkillAbility("yrintri"))    
    s+="Beschwoerung von Yrintri    : ("+CHAOS_GILDENMASTER->CheckWert(w)+")\n";
  s=break_string(s,0, 0, 1);
  pl->More(s);
  return 1;
  //return s;
}

void tell_player(string s,object pl)
{
  if(pl) tell_object(pl,s);
}

void WriteArtikel( string header, string txt)
{
  "/secure/news"->WriteNote( ({ "gilden.chaos",Name(WER), 0,0,header, txt }),1);
}
  
static int _set_disable_attack(int val)
{
 return 0;
}
    


/* --------------------- Der Lern-Teil von Kruuolq ------------------- */

int beschaeftigt() 
{
  return (InFight() || find_call_out(#'lernen)>-1);
}

int learnSomeSpell(string wen)
{
  int i;
  if (PL->QueryProp(P_GUILD) != "chaos")
    return 0;

  if ((i = member(SPELLS,wen)) == -1)
     return 0;
   if (!(CHAOS_GILDENROOM)->MayLearnSpell(wen))
    return (CHAOS_GILDENROOM)->LearnSpell(wen);

  if (beschaeftigt())
    return write(Name(WER)+" sagt: Jetzt nicht.\n"),1;
  
  
  say(PL->Name(WER)+" bittet "+name(WEN)+" um Weisheit.\n",PL);

  if(PL->QuerySkill(wen))
    tell_room(environment(),break_string("Du kannst den Spruch schon, doch "
              "ich erklaere ihn Dir ein weiteres mal. So lass uns beginnen.",
              0,Name(WER)+" sagt: "));

  call_out(#'lernen,4,i,0);
  return 1;
}

void lernen_sag(string was)
{
  int i;

  if (was[0] == '#')
    tell_room(environment(),was[1..]);

  else if((i=strstr(was,"§"))>-1)
  {
    write(was[0..i-1]);
    tell_room(environment(),was[i+1..],({PL}));
  }
  else
    write(was);
}

string lernen_string(int sp, int index)
{
  switch(sp)
  {
    case 0:  return NACHTSICHT_ARRAY[index];
    case 1:  return DUNKELHEIT_ARRAY[index];
    case 2:  return CHAOSRUESTUNG_ARRAY[index];
    case 3:  return KONTROLLE_ARRAY[index];
    case 4:  return BANNZAUBER_ARRAY[index];
    case 5:  return SCHUTZ_ARRAY[index];
    case 6:  return CHAOSBALL_ARRAY[index];
    case 7:  return CHAOSSCHADEN_ARRAY[index];
    case 8:  return VERBANNE_ARRAY[index];  
    case 9:  return BINDE_ARRAY[index];
    case 10: return CHAOSKONTROLLE_ARRAY[index];
    case 11: return FINSTERNIS_ARRAY[index];
  }
  return "";
}

int lernen_max(int sp)
{
  switch(sp) {
    case 0: return sizeof(NACHTSICHT_ARRAY) - 1;
    case 1: return sizeof(DUNKELHEIT_ARRAY) - 1;
    case 2: return sizeof(CHAOSRUESTUNG_ARRAY) - 1;
    case 3: return sizeof(KONTROLLE_ARRAY) - 1;
    case 4: return sizeof(BANNZAUBER_ARRAY) - 1;
    case 5: return sizeof(SCHUTZ_ARRAY) - 1;
    case 6: return sizeof(CHAOSBALL_ARRAY) - 1;
    case 7: return sizeof(CHAOSSCHADEN_ARRAY) - 1;
    case 8: return sizeof(VERBANNE_ARRAY) - 1;
    case 9: return sizeof(BINDE_ARRAY) - 1;
    case 10: return sizeof(CHAOSKONTROLLE_ARRAY) - 1;
    case 11: return sizeof(FINSTERNIS_ARRAY) - 1;
  }
  return -1;
}


void lernen_getdaemon(string wen)
{
  object daem;

  daem = clone_object(CHAOS_GILDEN_MON(wen));

  daem->setDaemBeschwoerer(ME);
  daem->AddId(wen+"_"+CHAOS_ID_KRUUOLQ);
  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+ 99999);
  daem->SetProp(DAEM_FAKTOR_MAPPING,([DAEM_AGGRESSIVE:1,
                                      DAEM_DISAPPEAR:1,
                                      DAEM_FALSE:1,
                                      WRONG_DAEM:1])); 
  daem->move(environment(),M_GO);
  daem->SetProp(P_NO_ATTACK,"Keine gute Idee jetzt.\n");
}


void lernen(int spell, int index)
{
  string str;
  int wait,i;
  object daem;
  object *obs;
  
  if(!objectp(PL)) return;
  if(environment() != environment(PL)) return;
  
  str = lernen_string(spell,index);
  wait = sizeof(explode(str,"\n"))*4;
  // wait = 0;
  /* ------- CHAOSRUESTUNG ------ */
  if (spell == 2)
  
    switch(index)
    {
      case  4:
      str = sprintf(str,capitalize(getuid(PL)));
      break;
    
      case 14:
      environment()->SetProp(P_LIGHT,-1000);
      break;
      
      case 15:
      environment()->SetProp(P_LIGHT,1);
      clone_object(CHAOS_GILDEN_MON(CHAOS_ID_ZUKUR))->
             move(environment(),M_GO|M_SILENT);
      break;
      
      case 17:
      str = sprintf(str,capitalize(getuid(PL)));
      present("\nzurkur",environment())->remove();
      break;
      
      case 20: 
      str = break_string("Durch \"verbanne chaoshaut\" kannst Du den "
            "Daemon wieder aus Deiner Haut verbannen.",0,
            Name(WER)+" sagt: ");
      break;
    }
  /* ------- BANNZAUBER ------- */
  if (spell == 4) switch(index)
  {
    case 3: clone_object(CHAOS_GILDEN_OBJ("penta"))->move(environment(),M_PUT|M_NOCHECK);
            break;
    case 5: present(CHAOS_ID_KRUUOLQ_PENTA,environment())->set_new_title();
            break;
    case 6: present(CHAOS_ID_KRUUOLQ_PENTA,environment())->remove();
            break;
  }
  /* ------- SCHUTZ ---------- */
  if (spell == 5 && index == 6)
  {
    if (!present_clone(CHAOS_CHAOSHAUT,PL))
      write("Eine temporaere Chaosruestung blitzt um Dich herum auf.\n");
    str = sprintf(str,capitalize(getuid(PL)));
  }
  /* ---------- CHAOSBALL -------- */
  if (spell == 6) switch(index) {
    case  6: 
//!!!!!!!!!!!!!    clone_object(C_112_MON("cl2_vdaemon"))->move(environment(),M_GO|M_SILENT);
             break;
    case  7: present("\nkruuolq_vdaemon",environment())->remove();break;
    case 11: str = sprintf(str,capitalize(getuid(PL)));wait =0;break;    
  }
  /* --------- CHAOSSCHADEN ----------- */
  if (spell == 7 && index == 10)
     str = sprintf(str,capitalize(getuid(PL)));
  /* --------- VERBANNE --------------- */
  if (spell == 8) switch(index)
  {
     case 5:
       lernen_getdaemon(CHAOS_ID_TUTSZT);str="";
       break;
     
     case 6: 
       lernen_sag(str);
       present(CHAOS_ID_TUTSZT+"_kruuolq",environment())->die();
       call_out(#'lernen,wait+4,spell,index+1);return;
     
     case 8: 
     case 9:
       str = sprintf(str,capitalize(getuid(PL)));
       break;
     
  }
  /* ---- CHAOSKONTROLLE ------- */
  if (spell == 10 && index == 3)
     str = sprintf(str,capitalize(getuid(PL)));
  /* ------- FINSTERNIS ------ */
  if (spell == 11) switch(index) {
    case  6: environment()->SetProp(P_LIGHT,-1000);break;
    case  7: environment()->SetProp(P_LIGHT,1);
//!!!!!!!!!!!!!!!!             clone_object(C_112_MON("cl2_ddaemon"))->move(environment(),M_GO|M_SILENT);
             break;
    case  8: str = sprintf(str,capitalize(getuid(PL)));
             break;
    case 10: daem = present("\nkruuolq_ddaemon",environment());
             daem->SetProp(P_NO_ATTACK,0);
             PL->Kill(daem);
             wait = 30;
             break;
    case 11: if ((daem = present("\nkruuolq_ddaemon",environment()))) {
               tell_room(environment(),Name(WER)+" zerfetzt den Teufelsdaemon.\n");
               daem->remove();
             }
             break;
    case 12: str = sprintf(str,capitalize(getuid(PL)));
             break;
  }
       
  // tell_room(environment(),index+":\n");
  lernen_sag(str);
  if (index < lernen_max(spell))
     call_out(#'lernen,wait,spell,index+1);
  else 
     (CHAOS_GILDENROOM)->LearnSpell(SPELLS[spell]);
  return;
}
