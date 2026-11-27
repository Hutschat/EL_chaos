// wuqour.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            UTF-8, init() für neuen Driver

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"
#include "wuqour.h"

inherit "std/npc";
inherit CHAOS_GILDEN_OBJ("std/funcs");

void sequence(object wer,int flag,int index);

/* 1 Kreis, 1 Heilung pro Spieler und Reset */
string *kreis, *heilung;


int evil;  // Wuqour wurde mit heiligem Schaden angegriffen. Wuqour ist BOESE!
int anz;   // anzahl schlaege pro runde.
int blutmagie;

/* Boeser machen, Entblinden, entgiften, enttauben nur alle 10 Min. */
static int last_boese,last_blind,last_gift,last_taub;

// Prototypen für Closures
string feste_drauf();
int boeser_machen(object ob);
void lernen(int wen, int index);
void spreche_kreiszauber(object p);

static int beschaeftigt()
{
  if(PL && PL->QueryProp(P_GUILD) != "chaos")
    return 1;

  return (find_call_out(#'sequence)>-1 ||
          find_call_out(#'boeser_machen)>-1 ||
          find_call_out(#'lernen)>-1);
}

static string boese_inf()
{
  if(beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";
 
  if(time() < last_boese + 900)
    return "Ach, toete ne Ameise oder 'n Huhn, ich will jetzt nich.";

  if(PL->QueryProp(P_ALIGN) < - 490)
    return "Du bist schon boese genug! :-)";

  last_boese = time();
  call_out(#'boeser_machen,0,PL);
  return "OK, dann beiss mal kraeftig die Zaehne zusammen.";
}

static string frosch_inf()
{
  if(beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";
 
  if(!PL->QueryProp( P_FROG))
    return "Wenn Du mal ein Frosch sein solltest, dann kann ich Dich "
           "entfroschen. Du musst mich nur nochmal fragen.";

  PL->SetProp(P_FROG, 0);
  
  return "Du armer Wicht warst ja ein Frosch! Ich habe Dich aber schon "
         "entfroscht. :-)";
}

static string entgiften_inf()
{
  if(beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";

  if(time() < last_gift + 900)
    return "Da hab ich jetzt keine Zeit fuer. Stell Dich da in die Ecke und "
           "stirb vor Dich hin, ja?";

  if(!PL->QueryProp(P_POISON))
    return "Wenn Du mal vergiftet sein solltest, dann kann ich Dich heilen. "
           "Du musst mich nur nochmal fragen.";

  if(PL->QueryProp( P_POISON) > 5)
    return "Tut mir leid, aber Du bist so stark vergiftet, dass ich Dir "
           "nicht helfen kann.";

  last_gift = time();

  PL->SetProp(P_POISON,0);

  return "Du armer Wicht warst ja vergiftet! Ich habe Dich aber geheilt :-)";
}

static string taub_inf()
{
  if (beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";
 
  if (time() < last_taub + 900)
    return "Ich hab eben erst jemanden enttaubt. ALSO LASS MICH IN RUHE!";

  if(!PL->QueryProp(P_DEAF))
    return "Wenn Du mal taub sein solltest, dann kann ich Dich heilen. "+
           "Du musst mich nur nochmal fragen.";

  last_taub = time();

  PL->SetProp(P_DEAF,0);
  return "Taube Chaoten? Sowas gibs bei mir nicht. So, Du bist geheilt. ";
}

static string heilung_inf()
{
  object ob;

  if (beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";

  if(member(heilung,getuid(PL)) != -1)
    return "Ich habe Dich doch erst vor kurzer Zeit geheilt! So oft kann "
           "ich Dir nicht helfen. Aber es gibt ja noch die, wenn auch etwas "
           "schaebige, Kneipe.";
  
  heilung += ({getuid(PL)});


  if(PL->QueryProp(P_HP) < 10+random(15))
  {
    PL->SetProp(P_HP,0);
    
    SetProp(P_KILL_NAME,"Wuqours Heilung");
//    SetProp(P_KILL_MSG,({"war doch etwas ruppig...",MSG_EMOTE,SINGULAR}));
    
    PL->SetProp(P_GHOST,1);
  
    ob = clone_object(PL->QueryProp(P_CORPSE) || CHAOS_CORPSE);
  
    if(objectp(ob))
    {
      ob->move(environment(PL),M_NOCHECK);
      ob->Identify(PL);
    }
    ob = clone_object(CHAOS_DEATHMARK);

    if(!objectp(ob))
      return "Oooooh, hier lief etwas schief.";
    
    ob->move(PL,M_NOCHECK);
    
    SetProp(P_KILL_NAME,0);
    SetProp(P_KILL_MSG,0);
    
    return "Ach Du Scheisse.";
  }
  tell_object(PL,"AAAH! Wuqour geht nicht allzu zimperlich mit Dir um.\n");
  PL->heal_self( 40 + random(200));

  return "'Krumbaslk Geommwoarlasba!' Sei geheilt, hinterhaeltiger Krieger "
         "der dunklen Maechte des Chaos!";
}

static string daemonenvertreibung_inf()
{
  object h;
  
  if(beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";

  if(!h = present("\nchaos_ruestung",PL)) 
	return "Du traegst doch gar keine Chaosruestung!";

  if(h->QueryProp(DAEM_FALSE))
    return "Der Daemon in Deiner Haut ist schon geweckt worden.";

  h->reset();
  return "So "+PL->name(WER)+", ich habe den Chaosdaemon in Deiner "
         "Haut geweckt.";
}

static string kreiszauber_inf()
{
  object p;

  if(beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";

  if(member(kreis, getuid(PL)) != -1)
    return "Komm spaeter wieder! So haeufig kann ich Dir nicht helfen.";

  if(!p = present("\nchaos_gilden_pentagramm_"+getuid(PL),
                  environment(ME)))
    return "Zeichne erstmal ein Pentagramm. Vorher kann ich keinen "
           "Zauber sprechen.";

  if(p->QueryProp("ritus_meister_zauber"))
    return "Ich habe auf dieses Pentagramm doch schon einen Spruch "
           "gesprochen. Ein zweiter Spruch waere voellig sinnlos.";

  if(!p->QueryProp(CHAOS_BANNKREIS))
    return "Zeichne erstmal einen Bannkreis um das Pentagramm.";

  if(find_call_out(#'spreche_kreiszauber) == -1)
    call_out( #'spreche_kreiszauber, 4, p );

  kreis += ({getuid(PL)});
  
  return "OK, ich werde einen Kreiszauber sprechen.";
}

static string beurteilung_inf()
{
  object p;
  string s;
  
  if(beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";

  if(!p = present("\nchaos_gilden_pentagramm_"+getuid(PL),environment(ME)))
    return "Zeichne erstmal ein Pentagramm. Wie soll ich Dein Pentagramm "
           "denn sonst beurteilen?";

  switch(p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR))
  {
    case 0..5:
    s = "Aeh? Das soll doch wohl nicht Dein Ernst sein! Das Pentagramm ist "
        "ja wirklich uebel. Man koennte es fast als Hexagramm bezeichnen. ";
    break;

    case 6..15:
    s = "Nun, um es mal vorsichtig auszudruecken: Das Pentagramm ist nicht "
        "so der grosse Bringer. ";
    break;

    case 16..30:
    s = "Naja, das Pentagramm ist nicht so schlecht. Man kann jedenfalls "
        "erkennen, dass es ein Pentagramm sein soll. ";
    break; 

    case 31..45:
    s = "Ja, das Pentagramm sieht ganz brauchbar aus. Ganz ordentlich "
        "gemacht. ";
    break; 

    case 46..60:
    s = "Das Pentagramm ist gut geworden. ";
    break;

    case 61..90:
    s = "Wow! So ein schoenes Pentagramm haette ich Dir gar nicht "
        "zugetraut! Es ist Dir wirklich gut gelungen. ";
    break; 

    case 91..130:
    s = "Unglaublich! Wie hast Du denn so ein tolles Pentagramm fertig "
        "gebracht? Ich bin ganz ueberwaeltigt! ";
    break; 

    case 131..160:
    s = "Fantastisch! Ich ziehe meinen Hut! Ich haette es nicht besser machen "
         "koennen! ";
    break; 

    case 161..20000:
    s = "Waaaaaaaaaaahnsinn! Ich glaube es einfach nicht!!!! Dieses "
        "Pentagramm ist das absolut beste, was ich jemals gesehen habe! ";
    break; 

    default:
    s = "Das gibts doch gar nicht! Wie kann man nur so ein schlechtes "
        "Pentagramm zeichnen und mich dann auch noch um eine Beurteilung "
        "bitten? ";
    break; 
  }
  if(!p->QueryProp(CHAOS_BANNKREIS))
    s += "Du hast noch keinen Bannkreis um das Pentagramm gezeichnet.";

  else 
  {
    switch(p->QueryProp( CHAOS_BANNKREIS_FAKTOR))
    {
      case 0..5:
      s+= "Bist Du sicher das dies ein KREIS sein soll? Es sieht eher wie "
          "ein Sechseck aus! Die Daemonen werden hoechstens darueber lachen!";
      break;

      case 6..10:
      s += "Nun zum Bannkreis: Also, der Bannkreis gefaellt mir ueberhaupt "
           "nicht! Versuche es lieber nochmal.";
      break;

      case 11..25:
      s += "Der Bannkreis ist Dir nicht besonders gut gelungen. Ich wuerde "
           "sogar sagen, dass er richtig schlecht ist.";
      break;

      case 26..40:
      s += "Naja, der Bannkreis ist zwar nicht toll, aber er sollte fuer "
           "einfache Beschwoerungen ausreichen.";
      break;

      case 41..55:
      s += "Ja, der Bannkreis ist schon ganz brauchbar.";
      break;

      case 56..80:
      s += "Der Bannkreis ist nicht schlecht und nicht gut.";
      break;

      case 81..100:
      s += "Nicht schlecht! Der Bannkreis kann wirklich als gelungen "
           "bezeichnet werden.";
      break;

      case 101..120:
      s += "Hey! Der Bannkreis ist Dir aber wirklich gut geraten! "
           "Gratulation.";
      break;

      case 121..150:
      s += "Von dem Bannkreis bin ich ganz ueberwaeltigt! Super gemacht!";
      break;

      case 151..180:
      s += "Der Bannkreis ist schlicht weg phantastisch!";
      break;

      case 181..220:
      s += "Huih! Der Bannkreis ist wirklich unglaublich! Damit kannst Du "
           "sicherlich die uebelsten Daemonen locker in ihre Schranken "
           "weisen!";
      break;

      case 221..20000:
      s += "Mir bleibt die Spucke weg! Das ist der absolut beste Bannkreis, "
           "der hier je gezeichnet wurde!!!!";
      break;

      default:
      s += "So einen stuemperhaften und schaebigen Bannkreis hab ich in "
           "meinem ganzen Leben noch nicht gesehen!";
    }
  }
  if(p->QueryProp(CHAOS_BANNKREIS) == 1)
    s += " Du hast noch keinen Bannzauber auf den Bannkreis gelegt.";

  return s;
}

static string blind_inf()
{
  if (beschaeftigt())
    return "Leider bin ich gerade beschaeftigt. Moment.";

  if (time()< last_blind + 900)
    return "Noeeeeh, ich hab eben schon jemanden entblindet, warte noch was.";

  if(!PL->QueryProp(P_BLIND))
    return "Wenn Du mal blind sein solltest, dann kann ich Dich heilen. "
           "Du musst mich nur nochmal fragen.";
  
  last_blind = time();
  PL->SetProp(P_BLIND, 0);
  return "Du armer Wicht warst ja blind! Ich habe Dich aber geheilt :-)";
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(20,1600);
  evil = 0;
  blutmagie = 0;
  Set(P_PLAYER_LIGHT, 3, F_QUERY_METHOD); 
  SetProp(P_SHORT, "Wuqour der Meister der Rituale");
  SetProp(P_LONG, 
  "Wuqour ist der Meister der Rituale und Beschwoerungen innerhalb der Gilde "
  "der Krieger des Chaos. Er hilft anderen Mitgliedern bei schwierigen "
  "Beschwoerungen und kann auch ein vorzeitiges Ablegen der Chaosruestung "
  "bewirken.");
  SetProp(P_NAME, "Wuqour");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE, 0);
  SetProp(P_XP, 1380000);
  SetProp(P_ALIGN, -900);
  SetProp(P_SIZE, 210);
  SetProp(P_WEIGHT,120000);
  SetProp(P_HANDS, ({" mit der Macht des Chaos", 230,DT_DARKNESS }));
  SetProp(P_BODY, 230);
  AddClass(({
    CL_WALKING,
    CL_HAIR,
    CL_SKIN,
    CL_BREATH_AIR,
    CL_ELF,
  }));
  
  SetProp(P_RACE, "Elf");
  SetProp( P_SIZE, 214);
  SetProp( P_DEFAULT_INFO, "runzelt nur mit der Stirn.\n");
  SetAttackChats( 35, ({ #'feste_drauf }));
  set_living_name( "wuqour" );
  AddId(({"meister","ritualmeister","wuqour","mann","elf"}));
  
  AddInfo(({"ritus","ritual","beschwoerung","beschwoeren","rituale", 
            "beschwoerungen","ritualen"}),
  "Daemonen beschwoeren ist nicht ganz einfach. Das Wichtigste ist der "
  "Zauberspruch, ohne den gar nichts laeuft. Zusaetzlich sind Pentagramme "
  "und Bannkreise empfehlenswert, die die Daemonen in ihre Schranken weisen. "
  "Ich kann Dir bei Ritualen und Beschwoerungen helfen. So kann ich Dein "
  "Pentagramm und den Bannkreis verbessern, wenn Du mich nach meinem "
  "Kreiszauber fragst. Wenn Du diese Hilfe nicht in Anspruch nehmen willst, " 
  "So kann ich Dir zumindest sagen, ob Dein Pentagramm und der Bannkreis "
  "gut gelungen sind. Frage mich einfach nach meiner Beurteilung.", 
  "sagt: ");

  AddInfo(({"frau","putzfrau"}),
  "Hm, mit der war irgendwas. Aber was .... ","gruebelt: ");

  AddInfo(({"blind","erblindung","blindheit","erblinden"}), 
  #'blind_inf, "sagt: ");

  AddInfo(({"bewertung","beurteilung","deine beurteilung",
            "deiner beurteilung","beurteilen","begutachtung",
            "einschaetzung" }),
  #'beurteilung_inf, "sagt: ");

  AddInfo(({"meine beurteilung","meiner beurteilung" }),
  "Argl! Bist Du bloede!", "sagt: ");

  AddInfo(({"zauber","zauberspruch","zaubersprueche","chaosball",
            "chaosschaden","finsternis","nachtsicht","dunkelheit","zaubern", 
            "zauberspruechen","sprueche","spruch","zauberei"}),
  "Zaubersprueche kannst Du bei Kruuolq lernen.","sagt: ");

  AddInfo("kruuolq", 
  "Das ist unser oberster Meister. Von ihm kannst Du zahlreiche "
  "Zaubersprueche lernen.", "sagt: ");

  AddInfo("hutschat",
  "Hutschat regelt die Verwaltung in der Gilde.", "sagt: ");

  AddInfo(({"faehigkeiten","zauberfaehigkeiten","zauber-faehigkeiten" }),
  "Da fragst Du besser Kruuolq. Ich kann nur Deine Pentagramme beurteilen.",
  "sagt: ");

  AddInfo(({ "nachtblind", "nachtblindheit" }),
  "Wenn die Wirkung der Nachtsicht nachlaesst, wird man fuer kurze Zeit "
  "nachtblind. Je hoeher Deine Gildenstufe ist, umso kuerzer ist diese Zeit.",
  "sagt: ");

  AddInfo(({"chaosgilde","gilde"}),
  "Dies ist die Chaosgilde. Hier in der schwarzen Burg mitten in einer "
  "gewaltigen Hoehle in einem schwarzen Eisberg. Das ist doch aeusserst "
  "beeindruckend.", "sagt: ");

  AddInfo(({"name","namen","daemon","daemonen" }),
  "Folgende Daemonen koennen wir beschwoeren und meistern: Intarbir, "
  "Kruftur, Ombatis, Bhuturih, Irkitis, Tyoorthok, Harkuhu, Graiop, "
  "Flaxtri und Tutszt. Alle Daemonen folgen Dir. Du kannst ihnen befehlen "
  "stehen zu bleiben, oder wieder zu folgen. Dies geht mit: befehle <name> "
  "folge mir, bzw. halt.","sagt: ");

  AddInfo(({"pentagramm","pentagramme" }),
  "Das Pentagramm oeffnet das Tor zu den Daemonendimensionen. Es sorgt vor "
  "allem dafuer, dass auch wirklich der Daemon kommt, den Du beschwoeren "
  "willst, denn es kann immer mal wieder vorkommen, dass sich ein anderer "
  "Daemon durch den Riss in der Realitaet schleicht und dann unkontrolliert "
  "wuetet und vor allem dem Beschwoerer gegenueber aggressiv ist. Zum "
  "Zeichnen eines Pentagrammes brauchst Du verschiedene Zutaten.","sagt: ");

  AddInfo(({"zutat","zutaten"}),
  "Man kann ein Pentagramm und einen Bannkreis aus einfacher Kreide "
  "zeichnen, dann sind sie natuerlich nicht besonders gut, aber fuer "
  "einfache Daemonen reicht es aus. Sehr gute Zutaten sind z.B. Goldstaub "
  "oder Drachenblut. Zusaetzlich kann man auch noch schwarze Kerzen oder "
  "andere geeignete Dinge in das Pentagramm stellen. Viele Zutaten kannst "
  "Du bei unserem Haendler kaufen, andere sind nur sehr schwer im "
  "Efferdland zu finden.", "sagt: ");
  
  AddInfo("kreiszauber",
  #'kreiszauber_inf,"sagt: " );

  AddInfo("zeichnen",
  "Du kannst mit 'zeichne pentagramm mit <objekt>' bzw. 'zeichne bannkreis "
  "mit <objekt>' zeichnen. Dies geht z.B. mit Kreide oder Drachenblut. Du "
  "kannst die Pentagramme oder Bannkreise auch wieder wegwischen.", "sagt: ");

  AddInfo(({"wischen","wegwischen"}),
  "Du kannst mit 'wische bannkreis weg' nur den Bannkreis loeschen oder aber "
  "mit 'wische pentagramm weg' beides zerstoeren.", "sagt: ");

  AddInfo(({"kreide","goldstaub","drachenblut","knochenmehl","sand",
            "silberstaub","gold","silber","staub","mehl","blut"}),
  "Damit kannst Du ein Pentagramm oder einen Bannkreis zeichnen. Du musst "
  "aber dabei beachten, dass manches fuer Pentagramme besser geeignet ist "
  "und anderes besser fuer Bannkreise. Dies kann Dir aber Kruftur sagen.",
  "sagt: ");

  AddInfo(({"auge","augen","kroetenhaut","kerzen","kerze"}),
  "Diese Zutaten kannst Du in ein Pentagramm setzen und es damit verbessern.",
  "sagt: ");

  AddInfo("efferdland",
  "Orientierungsschwierigkeiten?", "fragt: ");

  AddInfo(({"haendler","achtarch"}),
  "Achtarch heisst unser Haendler. Er verkauft Zutaten zur Beschwoerung von "
  "Daemonen.", "sagt: ");

  AddInfo("intarbir",
  "Der Daemon Intarbir hat ein besonderes Gespuer fuer die Kraft und "
  "Kampffaehigkeit von Monstern. Er kann Dir nuetzliche Informationen ueber "
  "einen Gegner geben. Syntax: 'befehle intarbir schaetze <monster> ein'.", 
  "sagt: ");

  AddInfo("kruftur",
  "Kruftur ist der Denkdaemon. Er kann bei Gegenstaenden, Waffen oder "
  "Ruestungen magische Faehigkeiten erkennen. Du musst ihm nur den "
  "Gegenstand geben. Er kann natuerlich auch Monster identifizieren. Der "
  "Syntax dazu ist: 'befehle kruftur identifiziere <name>'. ","sagt: ");

  AddInfo("ombatis",
  "Der fette Daemon Ombatis ist eine ganz schlimme Nervensaege :-) Wir "
  "benutzen ihn um unsere Feinde um Sinn und Verstand zu bringen. Du kannst "
  "ihn einem anderen Spieler hinterher schicken, er wird ihn dann "
  "anbruellen, belabern und belaestigen. Syntax: 'befehle ombatis "
  "folge <name>'.","grinst: ");

  AddInfo( "bhuturih",
  "Bhuturih ist ein kleines Luder. Sie kann, falls sie denn Lust dazu "
  "haben sollte, andere Spieler fuer Dich finden. Syntax: 'befehle bhuturih "
  "finde <name>'", "sagt: ");

  AddInfo("tyoorthok",
  "Das ist ein alter und sehr weiser Daemon, der Dir einiges ueber "
  "Deine koerperliche Verfassung und Aufnahmefaehigkeit sagen kann. "
  "Zudem kann er gegen ein kleines Entgeld fiese und nervige Krankheiten "
  "heilen. "
  "Syntax: 'befehle tyoorthok untersuche <name>'", "sagt: ");

  AddInfo("irkitis",
  "Ha, der wilde Halbdunkeldaemon mit dem Namen Irkitis ist ein flinker und "
  "hinterhaeltiger Kaempfer. Er ist so schnell, dass ihn nie ein Gegner "
  "trifft.", "sagt: ");

  AddInfo("harkuhu",
  "Der etwas seltsam aussehende Lichtdaemon ist zwar kein guter Kaempfer, "
  "aber er kann einiges Einstecken ehe er wieder verschwindet.","sagt: ");

  AddInfo("graiop",
  "Graiop, so heisst ein recht starker Feuerdaemon. Er ist ein ganz "
  "brauchbarer Kaempfer, der natuerlich aufgrund seiner Art im Dunkeln "
  "leuchtet.","sagt: ");

  AddInfo("flaxtri",
  "Flaxtri ist ein aeusserst gefaehrlicher Saeuredaemon, dessen aetzende "
  "Schleimhaut schwere Verletzungen bei Beruehrung hervorruft. Er ist ein "
  "ganz besonders wilder Kampfdaemon.","sagt: ");

  AddInfo( "tutszt",
  "Du fragst mich nach dem staerksten Daemon? Ha! Tutszt ist ein Blutdaemon "
  "was schon genug sagen sollte. Er ist wirklich sehr wild und gefaehrlich. "
  "Seine Blutgier ist ueberall gefuerchtet, deshalb duerfen ihn auch nur die "
  "allerbesten Krieger des Chaos beschwoeren.","sagt: ");

  AddInfo(({"bannkreis","bannkreise","kreise","kreis"}),
  "Der Bannkreis wird um das Pentagramm gezeichnet. Er soll verhindern, dass "
  "der Daemon seinen Beschwoerer anfaellt, vorzeitig wieder verschwindet "
  "oder nicht den Befehlen gehorcht. Wie gut ein Bannkreis ist, haengt "
  "von den Zutaten ab und von dem Bannzauber, den Du darauf sprechen "
  "kannst. Ich kann fuer Dich einen Bannkreis beurteilen, wenn Du ihn hier "
  "zeichnest.", "sagt: "); 

  AddInfo(({"befehle","befehlen"}),
  "Man kann seine Daemonen verschiedene Sachen befehlen. Dies geht immer mit "
  "'befehle <daemonenname> <befehl>. Als Befehle stehen folgende Kommandos "
  "zur Verfuegung: folge, stop, folge leise, toete <name>. Bei 'toete' "
  "greift der Kampfdaemon den Gegner an, man selber aber auch!", "sagt: ");

  AddInfo("bannzauber",
  "Der Bannzauber ist ein Spruch, den Du im Gilden-Raum lernen kannst. Er "
  "verbessert den Schutz des Bannkreises, wenn er gut gelingt. Sollte er "
  "voellig misslingen, dann wischt man am besten den Bannkreis weg und "
  "zeichnet einen neuen.", "sagt: ");

  AddInfo(({"chaosruestung","ruestung","hautdaemon"}),
  "Wenn Du den Chaosdaemon aus Deiner Haut vertreiben willst, dann kann ich "
  "Dir helfen. Du musst mich nur nach der Daemonenvertreibung fragen. Da "
  "diese Vertreibung fuer Dich gefaehrlich werden kann, Du darfst ja nicht "
  "den Kontrolle-Zauber anwenden, solltest Du vorher koerperlich fit sein. "
  "Wenn Du eine Heilung benoetigst, so kannst Du mich nach dieser "
  "befragen, allerdings werde ich Dich nur einmal heilen, da ich mir meine "
  "Magie auch noch fuer andere Mitglieder aufheben muss.", "sagt: ");

  AddInfo(({"daemonenvertreibung","vertreibung","daemonenverbannung",
            "verbannung","austreibung","vertreiben","entlassen","verdammen",  
           "befreien","erloesen","erweckung","daemonenaustreibung"}), 
  #'daemonenvertreibung_inf,"sagt: ");

  AddInfo(({"kontrolle","kontrolle-zauber","kontrolle zauber"}),
  "Der Kontrolle-Zauber bindet den Chaosdaemonen in Deine Haut. Wenn Du "
  "den Daemon los werden willst, so darfst Du diesen Spruch nicht benutzen. "
  "Ich kann natuerlich die Vertreibung auch starten, damit Du den Kontrolle-"
  "Zauber ueben kannst.","sagt: ");

  AddInfo(({"haut","chaoshaut"}),
  "Deine Haut kann mit der Chaosruestung verstaerkt werden. Du bannst dabei "
  "einen Chaosdaemonen in Deine Haut, die dadurch viel widerstandsfaehiger "
  "wird.","sagt: ");

  AddInfo(({"chaosdaemonen","chaosdaemon","zurkur"}),
  "Den Chaosdaemonen, den wir fuer die Chaosruestung benutzen, nennen wir "
  "Zurkur.", "sagt: ");

  AddInfo(({"uebmatu","hothrog","daedhel","chochos","rythoth"}),
  "Das ist ein Daemon, der manchmal kommt um Unruhe zu stiften.", "sagt: ");

  AddInfo(({"igor","handlanger"}),
  "Igor ist mein Handlanger. Man sollte sich nicht mit ihm anlegen, denn er "
  "ist verschlagen, gemein und maechtig. Ein boeser Junge, ich bin sehr "
  "stolz auf ihn.","sagt: ");

  AddInfo(({"burg"}),
  "Dies hier ist natuerlich nicht in dem Sinne eine Burg. Es mag wie eine "
  "Burg aussehen und sich wie eine Burg anfuehlen, aber Prinzipiell ist es "
  "eher eine Manifestation als eine Burg. Was der Sache jedoch in keiner "
  "Weise abtraeglich ist, wie ich betonen moechte.","sagt: ");

  AddInfo(({"manifestation"}),
  "Eine Manifestation ist eine sehr komplexe Sache. Prinzipiell ist die "
  "grosse Schwierigkeit dabei dafuer zu sorgen, dass sie nicht irgendwann "
  "mit einem <Puffffff> verschwindet.","sagt: ");

  AddInfo(({"eisberg","berg"}),
  "Im Gegensatz zu dieser Burg ist der Eisberg keine Manifestation, sondern "
  "ein richtiger Eisberg, jedenfalls in einer etwas weiter gefassten "
  "Definition.","sagt: ");

  AddInfo(({"definition"}),
  "Wie definiert man schon einen Eisberg? Er ist gross, er ist gefroren, er "
  "tropft, er ist kalt. Haben wir alles da.","sagt: ");

  AddInfo(({"eis","schwarzes eis"}),
  "Ich finde schwarzes Eis aeusserst huebsch. Mehr werde ich nicht darueber "
  "sagen.","sagt: ");

  AddInfo(({"hoehle"}),
  "Diese gewaltige Hoehle mit all ihrer Saeure und ihren merkwuerdigen, "
  "schwarzen Baeumen ist ein einziges, gewaltiges, kreatives Werk. Und es "
  "ist wunderschoen.","sagt: ");

  AddInfo(({"saeure"}),
  "Wir haben hier jede Menge Saeure. Nimm Dich vor ihr in Acht...","sagt: ");

  AddInfo(({"baeume"}),
  "Sie wachsen draussen...","sagt: ");

  AddInfo(({"kopf","totenkopf","schaedel","totenschaedel"}),
  "Er gab sein Leben freiwillig. Wuqour, sagte er, bitte stoss mich in diese "
  "Saeure hinein. Nun, jedenfalls prinzipiell sagte er das. Auf seine ganz "
  "eigene Art.","sagt: ");

  AddInfo(({"heilen","heilung"}),
  #'heilung_inf, "sagt: ");
  
  AddInfo(({"taub","taubheit","enttauben"}),
  #'taub_inf,"sagt: ");
  
  AddInfo(({"gift","vergiftung","vergifte","entgifte","entgift","entgiften",
            "entgiftung"}),
  #'entgiften_inf, "sagt: ");
  
  AddInfo(({"froesche","frosch","froschsein","entfroschung","entfrosche",
            "entfroschen" }),
  #'frosch_inf, "sagt: ");
  
  AddInfo(({"boese","boes","gemein","satanisch","gesinnung"}),
  #'boese_inf, "sagt: ");
	
  kreis   = ({});
  heilung = ({});

  AddCmd(({"lern","lerne"}),"learnSomeDaemon");
  AddCmd(({"frag","frage"}),"ask_him");

}

/* Wuqour antwortet Nicht-Chaoten nicht mehr. */
static int ask_him(string was)
{
  if (was[0..10] != "wuqour nach")
    return 0;
  
  if(PL->QueryProp(P_GUILD) == "chaos")
    return 0;

  say(PL->Name(WER)+" fragt "+name(WEN)+" nach "+capitalize(was[12..])+
      ".\n",PL);
  
  tell_room(environment(),Name(WER)+" scheint zu beschaeftigt zu sein, um zu "
            "antworten.\n");
  
  return 1;
}

/* Wuqour arbeitet mit call_outs. Damit nicht mehrere gleichzeitig laufen
   und sich behindern (wirres Umherlaufen) wird mit dieser Funktion getestet.
   Dadurch werden auch Nicht-Chaoten rausgefiltert.
*/


/* --------------------------------------------------------------------- */
/*      DER LERN-TEIL VON WUQOUR                                         */

/* Die Lern-Prozedur fuer Daemonen. Wird ueber AddCmd("lerne") aufgerufen
   Jeder Daemon erhaelt eine eigene Sequenz.
*/
int learnSomeDaemon(string wen)
{
  int i;

  if(PL->QueryProp(P_GUILD) != "chaos")
    return notify_fail(Name(WER)+" sagt: Dir bring ich nix bei!\n"),0;

  if(!wen)
    return notify_fail(break_string("Geh zu Kruuolq und komm wieder, "
                       "wenn Du weisst, was Du lernen moechtest.",0,
                       Name(WER)+" sagt: ")),0;

  if ((i = member(DEAMONS,wen)) == -1)
     return notify_fail(Name(WER)+" sagt:Das bringe ich Dir nicht bei!\n"),0;

  if (!(CHAOS_GILDENROOM)->MayLearnSpell(wen))
     return (CHAOS_GILDENROOM)->LearnSpell(wen);
  
  if (beschaeftigt())
    return write(Name(WER)+" sagt: Jetzt nicht. Geh weg.\n"),1;
    
  say(PL->Name(WER)+" bittet Wuqour um Weisheit.\n",PL);
 
  if(PL->QuerySkill(wen))
    tell_room(environment(),
    break_string("Du kannst den Spruch schon, doch ich erklaere ihn Dir ein "
    "weiteres mal.",0,Name(WER)+" sagt: "));
 
  tell_room(environment(),Name(WER)+" sagt: So lass uns beginnen.\n");
 
  call_out(#'lernen,4,i,0);

  return 1;
}

void lernen_sag(string was)
{
  if (was[0] == '#')
    tell_room(environment(),was[1..]);
  else
    write(was);
}

void lernen_getdaemon(string wen)
{
  object daem;

  daem = clone_object(CHAOS_GILDEN_MON(wen));

  daem->setDaemBeschwoerer(ME);
  daem->AddId(wen+"_"+getuid());
  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+ 99999);
  daem->SetProp(DAEM_FAKTOR_MAPPING,([DAEM_AGGRESSIVE:1, 
                                      DAEM_DISAPPEAR:1,
                                      DAEM_FALSE:1, 
                                      WRONG_DAEM:1])); 
  daem->move(environment(),M_GO);
  daem->SetProp("daemon_wants_kill",1);

  AddPursuer(daem);
}

void lernen(int wen, int index) 
{
  string str;
  int wait,i;
  object daem;
  object *obs;
  mixed temp;
  
  if(!objectp(PL))
    return;

  if(environment() != environment(PL))
    return;

  if (index < 9)
  {
    switch(index)
    {
      case 0: 
      str = "#"+Name(WER)+" sagt: Nun, "+
            ((PL->QueryProp(P_GENDER)==2)?"Chaotin":"Chaot")+
            "! Bereite Dich vor!";
      wait = 6;
      break;

      case 1:
      str = "#"+Name(WER)+" strafft seine Gestalt und wird umhuellt von "
            "einer Woge puren Chaos'.";
      wait = 6;
      break;
      
      case 2: 
      str = "#"+Name(WER)+" sagt: "+PL->name(WER)+", "+"oeffne Deine Augen "
            "und Ohren fuer das Chaos.";
      wait = 6;
      break;
      
      case 3: 
      str = "Die chaotische Woge erhebt sich von Wuqour und ergiesst sich auf "
            "Dich, umhuellt Dich, verschluckt Dich, erfuellt Dich.";
      wait = 6;
      break;  
      
      case 4:
      str = "Du siehst die Welt aus einer neuen Perspektive. Du fuehlst das "
            "Chaos, wie es Dich wild hin und herwirbelt wie ein Blatt im "
            "Wind. Du befindest Dich im Fluss mit dem Chaos, mehr als je "
            "zuvor.";
      wait = 15;
      break;
      
      case 6: 
      str = "#"+break_string("Nun bist Du bereit. Lass mich Dir erzaehlen "
            "von "+capitalize(DEAMONS[wen])+" und dem Rufen.",0,
            Name(WER)+" sagt: ");;
      wait = 10;
      break;
      
      case 7: 
      str = "#"+break_string(DEAMON_TEXTS[wen],0,Name(WER)+" sagt: ");
      wait = 26;
      break;
      
      case 8: str = Name(WER)+" ruft in das Chaos hinein. Er ruft nach ... "
              "nach "+capitalize(DEAMONS[wen])+"!!!";
      wait = 12;
      break;
    }
    if (index != 7)
      lernen_sag(break_string(str));

    else 
      lernen_sag(str);

    call_out(#'lernen,wait,wen,index+1);
    return;
  }
  /* --------------------- BHUTURIH --------------------------------------- */
  if (wen == 3)
  {
    switch(index-9)
    {
      case 0: 
      lernen_getdaemon("bhuturih");
      break;
      
      case  6:
      daem = users()[random(sizeof(users()))];
      lernen_sag("#"+Name(WER)+" sagt: Bhuturih, finde "+
                 capitalize(getuid(daem))+"\n");
               
      write("Bhuturih konzentriert sich und haelt Dir einen milchigen "
            "Spiegel\nvor die Nase. Du siehst:\n\n"+
            environment(daem)->int_long(PL,0));
      break;
      
      case  7: 
      lernen_sag(sprintf(BHUTURIH_ARRAY[7],PL->Name(WER)));
      break;
      
      case  8: 
      daem = present("bhuturih_"+getuid());
      if(daem)
        daem->remove();
      
      default:
      lernen_sag(BHUTURIH_ARRAY[index-9]);
      break;
    }
    if ((index-8) < sizeof(BHUTURIH_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- FLAXTRI --------------------------------- */
  if (wen == 8)
  {
    switch(index-9)
    {
       case 0:
       clone_object(CHAOS_GILDEN_OBJ("saeurefleck"))->move(environment());
       lernen_sag(FLAXTRI_ARRAY[index-9]);
       break;
       
       case 3:
       if (present("igor"))
         lernen_sag("#Igor wischt den Fleck weg.\n");
       else
         lernen_sag("#Igor erscheint aus pulsierender Dunkelheit.\n"+
         "Igor betrachtet kopfschuettelnd den Fleck und schnippt mit den Fingern.\n"+
         "Der Fleck verschwindet und Igor mit ihm.\n"); 
         daem = present("\nsaeurefleck"); 
         if(daem)
           daem->remove();
         break;
       
       case 7: 
         lernen_getdaemon("flaxtri");
         break;
      
       case 13:
         daem = present("flaxtri_"+getuid());
         if(daem)
           daem->remove();
         lernen_sag(FLAXTRI_ARRAY[index-9]);
         clone_object(CHAOS_GILDEN_MON("saeurefleck"))->move(environment());
         break;
       
       case 14:
         tell_room(environment(),Name(WER)+" schuettet etwas ueber "+
                   PL->Name(WEM)+" aus.\n",({PL}));
         daem = present("\nsaeurefleck");
         if(daem)
           daem->remove();
       
       default:
         lernen_sag(FLAXTRI_ARRAY[index-9]);
         break;
    }
    if ((index-8) < sizeof(FLAXTRI_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- GRAIOP --------------------------------- */
  if (wen == 7)
  {
    switch(index-9) 
    {
       case 11:
       lernen_getdaemon("graiop");
       break;
       
       case 13:
       lernen_sag(GRAIOP_ARRAY[index-9]);
       call_out(#'lernen,20,wen,index+1);
       return;
       
       case 16:
       daem = clone_object(POOL_NPC_ANIMAL "eishase");
       daem->move(environment(), M_GO );
       break;
       
       case 17:
       daem = present("graiop_"+getuid());
       lernen_sag(GRAIOP_ARRAY[index-9]);
       if (daem)
         daem->InsertEnemy(present("\npool_eishase"));
       break;
       
       case 20:
       daem = present("graiop_"+getuid());
       if(daem)
         daem->remove();
       lernen_sag(GRAIOP_ARRAY[index-9]);
       break;
      
       default:
       lernen_sag(GRAIOP_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(GRAIOP_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- HARKUHU --------------------------------- */
  if (wen == 6)
  {
    switch(index-9) 
    {
       case 0:
       map_objects(all_inventory(environment()) & users(),"SetProp",
                                                            P_BLIND,1);
       lernen_sag(HARKUHU_ARRAY[index-9]);
       break;
       
       case 2:
       map_objects(all_inventory(environment()) & users(),"SetProp",
                                                            P_BLIND,0);
       lernen_sag(HARKUHU_ARRAY[index-9]);
       break;      
       
       case 5:
       lernen_getdaemon("harkuhu");
       break;
       
       case 8:
       daem = present("harkuhu_"+getuid());
       if(daem)
         daem->remove();
       lernen_sag(HARKUHU_ARRAY[index-9]);
       break;
       
       case 10:
       lernen_sag(sprintf(HARKUHU_ARRAY[10],PL->Name(WER)));
       break;
       
       default:
       lernen_sag(HARKUHU_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(HARKUHU_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- INTARBIR --------------------------------- */
  if (wen == 0)
  {
    switch(index-9)
    {
       case 0:
       lernen_getdaemon("intarbir");
       lernen_sag(INTARBIR_ARRAY[index-9]);
       break;
       
       case 1:
       lernen_sag(sprintf(INTARBIR_ARRAY[1],PL->Name(WER)));
       break;
       
       case 2: 
       daem = present("intarbir_"+getuid());
       if (daem)
         daem->schaetze_monster(PL,ME);
       break;
       
       case 4:
       daem = present("intarbir_"+getuid());
       if(daem)
         daem->remove();
       lernen_sag(INTARBIR_ARRAY[index-9]);
       call_out(#'lernen,0,wen,index+1);
       return;
       
       default:
       lernen_sag(INTARBIR_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(INTARBIR_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- IRKITIS --------------------------------- */
  if (wen == 4) 
  {
    switch(index-9) 
    {
       case 0: 
       clone_object(CHAOS_GILDEN_MON("wirbelwind"))->move(environment(), M_GO );
       break;
       
       case 2:
       if((daem=present_clone(CHAOS_GILDEN_MON("wirbelwind"))))
         daem->remove();
       lernen_sag(IRKITIS_ARRAY[index-9]);
       break;
       
       case 5:
       lernen_getdaemon("irkitis");
       break;
       
       case 7:
       lernen_sag(sprintf(IRKITIS_ARRAY[index-9],PL->Name(WER)));
       break;
       
       case 8:
       clone_object(POOL_NPC_ANIMAL "huhn")->move(environment(), M_GO );
       break;
       
       case 9: 
       lernen_sag(IRKITIS_ARRAY[index-9]);
       daem = present("irkitis_"+getuid());
       if (daem) 
       {
         temp = present("\npool_huhn",environment());
         
         if(objectp(temp))
           daem->InsertEnemy(temp);
       }
       break;
       
       case 11:
       daem = present("irkitis_"+getuid());
       if(daem)
         daem->remove();
       
       default:
       lernen_sag(IRKITIS_ARRAY[index-9]);
         break;
    }
    if ((index-8) < sizeof(IRKITIS_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- KRUFTUR --------------------------------- */
  if(wen == 1)
  {
    switch(index-9) 
    {
       case 0:
       lernen_getdaemon("kruftur");
       
       case 2:
       lernen_sag(sprintf(KRUFTUR_ARRAY[index-9],PL->Name(WER)));
       break;
       
       case 1:
       obs = all_inventory(PL);
       if (!sizeof(obs))
         break;
       daem = present("kruftur_"+getuid());
       if(!daem)
         break;
       foreach(object tmp:obs)
         if(tmp->QueryProp(P_INFO) || !i) 
         {
           tell_room(environment(PL),break_string("Ich habe folgende "
                     "Information ueber "+tmp->name(WEN)+" erhalten: "+
                     daem->query_information(tmp),0, "Kruftur sagt: "));
           break;
         }
       break;                
       
       case 4:
       lernen_sag(KRUFTUR_ARRAY[index-9]);
       daem = present("kruftur_"+getuid());
       if(daem)
         daem->remove();
       break;
       
       default:
       lernen_sag(KRUFTUR_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(KRUFTUR_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- OMBATIS --------------------------------- */
  if (wen == 2)
  {
    switch(index-9)
    {
       case 1:
       lernen_sag(OMBATIS_ARRAY[index-9]);
       lernen_getdaemon("ombatis");
       break;
    
       case 11:
       lernen_sag(OMBATIS_ARRAY[index-9]);
       daem = present("ombatis_"+getuid());
       if(daem)
         daem->remove();break;
      
       default: 
       lernen_sag(OMBATIS_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(OMBATIS_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- TUTSZT --------------------------------- */
  if (wen == 9) 
  {
    switch(index-9)
    {
       case 7:
       lernen_sag(TUTSZT_ARRAY[index-9]);
       lernen_getdaemon("tutszt");
       break;
       
       case 13:
       lernen_sag(TUTSZT_ARRAY[index-9]);
       daem = present("tutszt_"+getuid());
       if(daem)
         daem->die();break;
       
       case 15:
       lernen_sag(TUTSZT_ARRAY[index-9]);
       PL->command_me("trinke blut");
       break;
       
       default:
       lernen_sag(TUTSZT_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(TUTSZT_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- TYOORTHOK ----------------------------- */
  if (wen == 5)
  {
    switch(index-9) 
    {
       case 0:
       lernen_sag(TYOORTHOK_ARRAY[index-9]);
       lernen_getdaemon("tyoorthok");
       break;
       
       case 3:
       lernen_sag(sprintf(TYOORTHOK_ARRAY[index-9],PL->Name(WER)));
       break;
       
       case 4:
       daem = present("tyoorthok_"+getuid());
       if(!daem)
         break;
       lernen_sag("Tyoorthok rueckt seine Brille zurecht und spricht "
                  "geheime Worte ueber Deinem\nHaupte. Danach gruebelt er "
                  "einen Augenblick und murmelt:\n"+
                  daem->total_soak(PL,0)+daem->total_drink(PL,0)+
                  daem->total_alc(PL,0)+daem->total_pois(PL,0)+
                  daem->total_deaf(PL));
       break;

       case 7:
       lernen_sag(TYOORTHOK_ARRAY[index-9]);
       daem = present("tyoorthok_"+getuid());
       if(daem)
         daem->remove();
       break;
      
       default:
       lernen_sag(TYOORTHOK_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(TYOORTHOK_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  /*-------------------------- YRINTRI --------------------------------- */
  if (wen == 10)
  {
    switch(index-9)
    {
       case 7:
       lernen_sag(YRINTRI_ARRAY[index-9]);
       lernen_getdaemon("yrintri");
       break;
       
       case 12:
       clone_object(CHAOS_GILDEN_MON("heiliger"))->
                             move(environment(), M_GO );
       lernen_sag(YRINTRI_ARRAY[index-9]);
       break;
       
       case 17:
       daem = present("yrintri_"+getuid());
       if(!daem)
         break;
       daem->SetProp(P_HANDS,({ " mit unheiligen Klauen",260,DT_DARKNESS}));
       lernen_sag(YRINTRI_ARRAY[index-9]);
       lernen_sag("#Yrintri verwandelt seine Klauen.\n");
       break;
       
       case 18:
       daem = present("yrintri_"+getuid());
       if(!daem)
         break;
       lernen_sag(YRINTRI_ARRAY[index-9]);
       daem->Kill(present_clone(CHAOS_GILDEN_MON("heiliger"),
                                environment()));
       break;
       
       case 22:
       daem = present("yrintri_"+getuid());
       if(!daem)
         break;
       daem->Kill(ME);
       break;
       
       case 23:
       lernen_sag(YRINTRI_ARRAY[index-9]);
       daem = present("yrintri_"+getuid());
       if(!daem)
         break;
       daem->die();
       break;
      
       default: 
       lernen_sag(YRINTRI_ARRAY[index-9]);
       break;
    }
    if ((index-8) < sizeof(YRINTRI_ARRAY))
      call_out(#'lernen,10,wen,index+1);
    else
      return (CHAOS_GILDENROOM)->LearnSpell(DEAMONS[wen]);
  }
  
  return;
}          

/* ----------- DER KAMPF - TEIL VON WUQOUR ------------------------------ */           

public varargs void init(object origin)
{
  ::init(origin);
  if(PL->id( "zurkur"))
  {
    tell_room(environment(),Name(WER)+" stuerzt sich auf den widerlichen "
              "Chaosdaemon.\n");
    Kill(PL);
  }
  if(PL->id("chaos_aggressive_daemonen") && !
     PL->QueryProp(CHAOS_NPC_BESCHWOERER))
    Kill(PL);
 
  if(PL->id("\nigor"))
    AddDefender(PL);
}

string feste_drauf()
{
  object daem;

  object en = QueryEnemy();

  switch( random(15))
  {
    case 0:
    if(!interactive(en))
      break;
    tell_room(environment(ME),Name(WER)+" beschwoert einen Daemonen "
              "herbei!\n");

    daem = clone_object(CHAOS_GILDEN_MON("rythoth"));

    daem->SetProp(CHAOS_DAEM_BESCHWOERER, getuid(en));
    daem->SetProp(CHAOS_NPC_BESCHWOERER,1);
    daem->SetProp(DAEM_AGGRESSIVE, getuid(en));
    daem->move(environment(en),M_TPORT);
    break;

    case 1:
    say(Name(WER,1)+" schnippt mit den Fingern und sagt: Nun bist Du "
        "blind und taub und Frosch und vergiftet, "+en->Name(WER)+". Hab "
        "Spass.\n");
    en->SetProp(P_FROG,1);
    en->SetProp(P_BLIND,1);
    en->SetProp(P_DEAF,1);
    if(en->QueryProp(P_POISON)<3)
      en->SetProp(P_POISON,3);
    break;

    case 2:
    tell_object(en,Name(WER)+" bringt das Gift in Dir zum Kochen.\n");
    
    say(Name(WER)+" bringt "+en->name(WESSEN)+" Blut zum Kochen.\n");
    en->AddPoison(2);
    break;
    
    case 3:
/*
    command_me("oeffne tuer");
    tell_object(en,Name(WER)+" befoerdert Dich mit einem Fusstritt zur Tuer "
                "raus.\n");

    say(Name(WER)+" tritt "+en->name(WEN)+" zur Tuer raus.\n",({en}));

    en->move(C_112_ROOM("cl2bu6"),M_GO,"nach Westen","fliegt","kommt hereingeflogen");
    en->reduce_hit_point(30+random(30));
*/    
    break;

    case 4:
    tell_object(en,Name(WER)+" stiehlt Dir Dein Leben.\n");
    say(Name(WER)+" beruehrt "+en->name(WEN)+".\n",({en}));
    en->reduce_hit_points(60);
    heal_self(60);
    break;

    case 5:
    tell_object(en,Name(WER)+" umhuellt Dich mit einer Wolke aus "
                "Finsternis.\n"); 

    say(Name(WER)+" umhuellt "+en->name()+" mit einer Wolke aus "
        "Finsternis.\n");

    en->SetProp(P_DISABLE_ATTACK,en->QueryProp(P_DISABLE_ATTACK) +
        20 + random(10));
    break;
  }
  return "";
}

protected void heart_beat()
{
  if (InFight())
  {
    if (anz>10)
       anz=10;
    if (anz<1)
      anz = 1;
    ME->ModifySkillAttribute(SA_SPEED,100*(anz+ (evil?anz:0)),2);
  }
  ::heart_beat();
  heal_self(random(6));
  anz = 0;
}

// Wuqour greift mit Chaosbaellen an, und zwar jede Kampfrunde.
// Um nicht immer aufs Spellbook zuzugreifen, hab ich das ganze
// hier ... simuliert. Schliesslich greift Wuqour evtl. recht 
// haeufig in einer Runde an.
void Attack(object enemy)
{
  string d1,d2;
  string dam_txt;

  if (blutmagie>0)
  {
    // siehe Raum C_112_ROOM("cl3_cerz3")
    tell_object(enemy,Name(WER)+" bruellt und schleudert die Blutmagie auf "
                      "Dich.\n");

    enemy->Defend(blutmagie+random(blutmagie),"blut",([SP_SHOW_DAMAGE:1]),
                  ME);
    heal_self(blutmagie);

    blutmagie = 0;

    if(!enemy || enemy->QueryProp(P_GHOST))
      return;
  }
  
  d1 = (MAGICAL_DAMAGE_TYPES-
       ({DT_LIGHT}))[random(sizeof(MAGICAL_DAMAGE_TYPES)-1)];
  
  d2 = PHYSICAL_DAMAGE_TYPES[random(sizeof(PHYSICAL_DAMAGE_TYPES))];
  
  dam_txt = Funcs_DamText(({d1,d2}),0);
    
  tell_object(enemy,Name(WER)+" feuert "+dam_txt+" auf Dich ab.\n");

  say(Name(WER)+" feuert "+dam_txt+" auf "+enemy->name(WEN)+" ab.\n",enemy);
  // Das ist die normale Formel fuer unsern Chaosball :-) (najaaa, fast)
  enemy->Defend((int)((100+random(400)+random(150)+75+50+random(50))*1.2),
                ({d1,d2}),([SP_SHOW_DAMAGE:1, SI_SKILLDAMAGE_TYPE:({d1,d2})]),
                ME);
  SetProp(P_KILL_MSG,0);
}


void enhance(int stufe,int rating,object ob)
{
  if(stufe>50)
    stufe = 50;
  
  if(rating>7500)
    rating = 7500;
  
  blutmagie = ((1000*stufe*rating)/(7500*50));
  
  say("Eine blutrote Wolke steigt aus dem Boden empor und erfuellt "
      "Wuqour.\n"+"Du bekommst grosse Angst.\n");
  
  SetProp(P_KILL_MSG,"Ich danke Dir, "+capitalize(getuid(ob))+". Dein Blut "+
                     "hatte die Macht, diesen Gegner zu besiegen.");
  return;
}


void InformDefend(object enemy)
{
  if(!present(enemy,environment(ME)))
    return;
  
  if(!objectp(enemy))
    return;
  
  if(!living(enemy))
    return;
  Kill(enemy);
}

varargs int Defend( int dam, mixed dt, mixed sp, object enemy)
{
  if (!dt)
    return 0;

  if(!pointerp(dt))
    dt = ({dt});

  anz++;
  
  if (sizeof(dt & ({DT_DARKNESS})))
  {
    say(Name(WER)+" laechelt.\n"+Name(WER)+" absorbiert und returniert.\n");
    heal_self(dam);
    enemy->Defend(dam,dt,sp,ME);
    return 0;
  }
  
  if (sizeof(dt & ({DT_LIGHT})))
  {
    if (!evil) 
    {
      evil = 1;
      say(Name(WER)+" bruellt zornig auf, als der heilige Schaden ihn "
          "trifft.\n"+
          "Rotes Feuer lodert in seinen Augen. Das war ein Fehler.\n");
    } 
    else 
      evil++;
    
    if (evil < 5) 
      return::Defend(dam,dt,sp,enemy);
    
    else if (evil == 5)
    {
      say("Wuqour scheint langsam immun gegen derlei Attacken zu werden.\n");
      dam = dam/2;
    }
    else 
      dam=dam/2;
  }
  return::Defend(dam,dt,sp,enemy);
  
}


void spreche_kreiszauber(object p)
{
  if( !p || !objectp(p)) 
  {
    tell_room(environment(ME),Name(WER)+" sagt: Huch, wo ist denn das "
              "Pentagramm ploetzlich hin?\n");
    return;
  }

  tell_room(environment(ME),break_string(Name(WER)+" kniet sich vor das "
            "Pentagramm und macht seltsame Zeichen mit seinen Haenden und "
            "Fingern in der Luft. Dabei murmelt er seltsame Worte und "
            "ploetzlich fliesst eine hell leuchtende Magie von seinen "
            "Fingerspitzen in das Pentagramm hinein, das kurz aufflackert."));

  p->SetProp("ritus_meister_zauber",1);

  p->SetProp( CHAOS_PENTAGRAMM_RANDOM, 
	p->QueryProp( CHAOS_PENTAGRAMM_RANDOM) + 30 + random(40));
  
  p->SetProp( CHAOS_BANNKREIS_RANDOM, 
	p->QueryProp( CHAOS_BANNKREIS_RANDOM) + 30 + random(40));
}

int boeser_machen(object ob)
{
  object ob2;
  int al;

  if (!objectp(ob))
    return 1;

  if (environment(ob) != environment())
    return 1;
  al = ob->QueryProp(P_ALIGN);
  
  if (al < -490) 
  {
    tell_room(environment(),Name(WER)+" sagt: So, das fuehlt sich besser "
              "an, was?\n");
    return 1;
  }
  al -= 40 + random(20);

  if(al < -499)
    al = - 499;

  tell_object(ob,
  ({
  Name(WER)+" pruegelt alle Guete aus Dir heraus. Kraeftig.\n",
  Name(WER)+" sticht Dich mit gluehenden Nadeln, um das BOESE in Dir zu "
            "wecken.\n",
  Name(WER)+" quetscht das Gute aus Dir heraus. Einige Rippen brechen.\n",
  Name(WER)+" schlaegt Dich windelweich. Du wirst sauer. Du wirst BOESE!\n",
  Name(WER)+" schlaegt mit einer Axt nach Dir, um Dir etwas Blut "
            "abzunehmen.\n",
  Name(WER)+" wirft Dich zu Boden und springt auf Dir herum.\n",
  Name(WER)+" weckt den Wahn in Dir. Du zerkratzt Dir dein Gesicht.\n",
  Name(WER)+" zieht Dich von links auf rechts und sagt: Jooh, sieht besser "
            "aus.\n",
  Name(WER)+" zieht Dir einen Plueschhasen aus der Tasche, pruegelt Dich "
            "und ruft:\n"+"Was ist das? WAS IST DAS? HAEEEEEEEEH? (Du weinst "
            "vor Scham)\n",
  Name(WER)+" rammt Dir einen Dolch in die Gedaerme, deutet auf das Blut "
            "und sagt:\n"+"Und jetzt schreibst Du hundert mal: 'ICH BIN "
            "WIRKLICH EXTREM BOESE!'\n",
  Name(WER)+" durchsucht Dich brutalst nach Gummibaerchen und aehnlichem.\n",
  Name(WER)+" versetzt Dir einen ueblen Kopfstoss und ruft: HAST DU "
            "GELAECHELT???\n",
  Name(WER)+" pruegelt: Du bist ein uebles Monster, also verhalte Dich wie "
            "eins!\n",
  Name(WER)+" rammt seine Faust in dein Auge und ruft: Wir sind Geschoepfe "
            "der Nacht!\n"
  })[random(14)]);
  
  say(Name(WER)+" maltraetiert "+ob->name(WEN)+" gar fuerchterlich.\n",ob);
  
  ob->SetProp(P_ALIGN,al);
  ob->reduce_hit_points(5+random(10));
  
  if(PL->QueryProp(P_HP)<2)
  {
   tell_room(environment(),Name(WER)+" schlaegt zu kraeftig zu.\n");

   ME->SetProp(P_HP,0);
   SetProp(P_KILL_NAME,"Boshaftigkeit");
   
   //SetProp(P_KILL_MSG,({"ist schon fies...",MSG_EMOTE,SINGULAR}));
   
   PL->SetProp(P_GHOST,1);
   
   ob2 = clone_object(ob->QueryProp(P_CORPSE) || CHAOS_CORPSE);
   if (objectp(ob2))
   {
     ob2->move(environment(ob),M_NOCHECK);
     ob2->Identify(ob);
   }
   ob2 = clone_object(CHAOS_DEATHMARK);
   
   if (!objectp(ob2)) 
     return 1;
   
   ob2->move(ob,M_NOCHECK);
   SetProp(P_KILL_NAME,0);
   SetProp(P_KILL_MSG,0);
  }
  call_out(#'boeser_machen,random(4),ob);
  
  return 1;
}

/* wird von sequenz aus aufgerufen. Gibt die gewuenschte Zeile aus dem 
   Sequenz-Array fuer die Heilungsart zurueck.
*/ 
mixed get_line(int flag, int index)
{
   switch (flag) 
   {
     case W_HEAL:   return HEAL_ARRAY[index];
     case W_DEAF:   return DEAF_ARRAY[index];
     case W_POISON: return POISON_ARRAY[index];
     case W_FROG:   return FROG_ARRAY[index];
     case W_DEMON:  return DEMON_ARRAY[index];
     case W_BLIND:  return BLIND_ARRAY[index];
   }
   return "";
}
/* wird von sequenz aus aufgerufen. Gibt die Groesse des Sequenz-Arrays 
   fuer die Heilungsart zurueck. */

int get_size(int flag)
{
   switch (flag) {  
     case W_HEAL:   return sizeof(HEAL_ARRAY);
     case W_DEAF:   return sizeof(DEAF_ARRAY);
     case W_POISON: return sizeof(POISON_ARRAY);
     case W_FROG:   return sizeof(FROG_ARRAY);
     case W_DEMON:  return sizeof(DEMON_ARRAY);
     case W_BLIND:  return sizeof(BLIND_ARRAY);
   }
   return 0;
}

/* Hier wird die eigentliche Heilung fuer die verschiedenen Heiltypen
   durchgefuehrt. */
int make_it(object wer,int flag)
{
   object ob;
   switch (flag)
   {
     case W_HEAL:   wer->heal_self( 40 + random(200));break;
     case W_DEAF:   wer->SetProp(P_DEAF,0);break;
     case W_POISON: wer->SetProp(P_POISON,0);break;
     case W_FROG:   wer->SetProp(P_FROG,0);break;
     case W_BLIND:  wer->SetProp(P_BLIND,0);break;
     case W_DEMON: 
       ob = present("\nchaos_ruestung",wer);
       if (!objectp(ob)) 
         return 1;
       if( !ob->QueryProp( DAEM_FALSE))
       {
         ob->SetProp("chaos_count_up",0);
         ob->SetProp(DAEM_FALSE,1);
         ob->chaos_chaos_chaos(0);
       }
       break;
   }
   return 0;
}


/* Diese Funktion wird nur fuer Wuqours' Heilung benoetigt. */
int hurt_him(object wer)
{
  object ob;

  wer->reduce_hit_points(10);

  if(wer->QueryProp(P_HP)>2)
    return 1;

  SetProp(P_KILL_NAME,"Wuqours Behandlung");
  //SetProp(P_KILL_MSG,({"war doch etwas ruppig...",MSG_EMOTE,SINGULAR})); 
  
  PL->SetProp(P_GHOST,1);
  
  ob = clone_object(PL->QueryProp(P_CORPSE) || CHAOS_CORPSE);
  
  if (objectp(ob))
  {
    ob->move(environment(PL),M_NOCHECK);
    ob->Identify(PL);
  }
  ob = clone_object(CHAOS_DEATHMARK);
  if (!objectp(ob))
    return 1; 
  ob->move(PL,M_NOCHECK);
  return 1;
}

int move_him(object wer) 
{
/*
  move(C_112_ROOM("cl2_cbeh1"),M_GO,"nach Sueden");
  wer->move(C_112_ROOM("cl2_cbeh1"),M_GO|M_NO_SHOW,"nach Sueden");
  tell_object(wer,environment(wer)->int_short(wer,wer));
*/
  return 1;
}   

/* Die Sequenz (fuer wen, welche Heilung (Blind/taub), Index) */
void sequence(object wer,int flag,int index) 
{
  int hurt,i;
  int room;
  int do_it;
  string zeile;
 
  hurt  = 0;
  room  = 0;
  do_it = 0;
  if(!objectp(wer))
    return;
  
  if(!index)
    wer->SetProp("chaos_behandlung",1);
  
  if (environment(wer) != environment())
  {
    wer->SetProp("chaos_behandlung",0);
    return;
  }
  zeile = get_line(flag,index);
  switch(zeile[0])
  {
    case '#': hurt = 1; zeile = zeile[1..]; break;
    case '$': room = 1; zeile = zeile[1..]; break;
    case '*':do_it = 1; zeile = zeile[1..]; break;
      // Speziell fuer die Frosch-Sequenz.
    case '%': 
      zeile = zeile[1..];
      if (index==6) PL->SetProp("chaos_frog",1);
      else          PL->SetProp("chaos_frog",0);
      break;
   }
   if ((i=strstr(zeile,"§",0))>-1)
   {
     if (wer->Query(P_GENDER)==1)
       zeile = zeile[0..i-1];
     else
       zeile = zeile[i+1..];
   }
   tell_object(wer,zeile);
   
   if (hurt)
     hurt_him(wer);
   if (room)
     move_him(wer);
   if (do_it)
     make_it(wer,flag);

   if (index < get_size(flag)-1)
   {
     call_out(#'sequence,get_line(flag,index+1),wer,flag,index+2);
     return;
   }
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//   if(object_name(environment()) == C_112_ROOM("cl2_cbeh1")) 
   {
     PL->move(CHAOS_GILDEN_ROOM("critual"),M_GO,"nach Norden");

     move(CHAOS_GILDEN_ROOM("critual"),M_GO,"nach Norden");
   }
   wer->SetProp("chaos_behandlung",0);
}
                              