// achtarch.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen     ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet
// 27.11.2026 It@Efferdland            Schänke der Burg

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_chaot");

#define DEFAULT_QUEST_FAIL "Davon habe ich keine Ahnung."
#define SSQMASTER          "/d/polar/files.chaos/tilly/obj/spendenmaster"
#define SAMMLER            "Chaos-Gilde:Sammler"

static int counter1 = 0;

static string plan_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Dieser Plan ist nur etwas fuer wirklich hartgesottene Chaoten.\n";
  return "Es geht dabei um eine Spendenbuechse ... \n";
}

static string buechse_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Was fuer eine Buechse denn?";

  return("Also, pass gut auf. Ich habe mir folgendes gedacht: "
   "Es gibt doch bei dieser Luschen-Gilde namens Kaempfer dieses Sammeln "
   "von Spenden fuer ein Denkmal. Ich gebe Dir einfach eine solche "
   "Spendenbuechse und Du verkleidest Dich als Kaempfer und sammelst welche. "
   "Hast Du ausreichend Geld beisammen, bekommst Du einen Teil davon ab, "
   "den Rest behalte ich und sichere mein Ueberleben. Na, was haeltst Du "
   "davon? Wenn Du diese Aufgabe wirklich uebernehmen moechtest, dann "
   "frage mich einfach nach 'sammelaktion'.");
}

static string gilde_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Damit ist Deine gemeint, stell Dich doch nicht so bloed an.\n";

  return "Na, die Kaempfer sind gemeint. Hoer mir doch mal zu!\n";
}

static string sammel_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Ja. Geh und sammel etwas. Mir doch egal.\n";

  return(break_string("Genau! Du sammelst, als Kaempfer verkleidet, Spenden. "
   "Und die teilen wir uns dann :-)"));
}

static string spenden_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Yo, gib mir einfach Dein ganzes Geld.\n";

  return "Um die geht es. Beziehungsweise um eine Spendenbuechse.\n";
}

static string denkmal_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Irgendwo gibt es ein Denkmal, aber es nicht wichtig.\n";

  return(break_string("Du kennst doch die Kaempfer, fuer alles stellen die "
   "ein Denkmal auf."));
}

static string geld_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Geld ist nie verkehrt.\n";

  return(break_string("Wenn Du ausreichend Geld beisammen hast, gibst Du "
   "mir die Buechse wieder."));
}

static string teil_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Das geht Dich ueberhaupt nichts an.\n";

  return "Du wirst Deinen schon bekommen, ich bescheisse nur Nicht-Chaoten.\n";
}

static string rest_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Ich geb Dir gleich den Rest, pass bloss auf!\n";

  return "Den behalte ich, ist doch klar.\n";
}

static string leben_inf()
{
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Das geht Dich nichts an.\n";

  return "Du wuerdest mir damit wirklich helfen.\n";
}

static string sammelaktion_inf(){
  object ob;

  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Das ist eine Sache nur fuer Chaoten!\n";

  if(present("\nguild-chaos:buechse",PL))
    return "Du hast schon eine Spendenbuechse von mir bekommen.\n";

  if(!present("\nguild-chaos:buechse",PL))
  {
    ob = clone_object("/d/polar/files.chaos/tilly/obj/dose");

    ob->move(PL,M_NOCHECK);

    tell_object(PL,break_string("Hier, ich gebe Dir eine Spendenbuechse. "
                   "Damit Deine Tarnung als Kaempfer perfekt ist, musst Du "
                   "die Buechse UNBEDINGT schuetteln. Und jetzt geh und "
                   "sammele. Es ist zu unser beider Vorteil.",
                   0,Name(WER)+" sagt: "));
    
    if(call_other((SSQMASTER),"CheckSammler",getuid(PL))<=0)
      call_other((SSQMASTER),"SetzeSammler",getuid(PL),1);
   }
  return 0;
}

static string belohnung_inf()
{
  object ob;
  if(PL->QueryProp(P_GUILD)!="chaos")
    return "Du kriegst von mir nix.\n";

  if(present("\ntilly:chaut_obj",PL))
    return "Du hast schon eine Belohnung von mir erhalten.\n";

  if(!present("\nchaos_ruestung",PL))
    return "Du musst eine Chaoshaut besitzen um sie erhalten zu koennen.\n";

  else
  {
    ob = clone_object("/d/polar/files.chaos/tilly/obj/chautobj");
    ob->move(PL,M_NOCHECK);

    tell_room(environment(PL),Name(WER)+" heftet etwas an "
              +PL->name(WESSEN)+" Chaoshaut.\n",({PL}));

    write(Name(WER)+" heftet Dir etwas an Deine Chaoshaut.\n");
   }
  return "Da, hier hast Du sie :-)\n";
}

static int LetsGoDrink()
{
  ME->move(CHAOS_SCHAENKE,M_GO|M_NOCHECK);

  command_me("werfe rubel weg");

  tell_room(environment(ME),Name(WER)+" grinst breit.\n"+
            Name(WER)+" sagt: Trinkt einen auf mich mit!\n");
  
  ME->move(CHAOS_GILDEN_ROOM("claden"),M_GO|M_NOCHECK);
  
  return 1;
}

/*
Chaosrattenquest:
*/

static mixed chaot;

static int check_pl(object pl)
{
#ifndef JENANDRA_QUEST
  if(pl->QueryProp("jenandra:testquest")) return 1;
  return 0;
#else
  return 1;
#endif
}

static string ratte()
{
  object pl;
  string *prop;

  pl = PL;

  if(!check_pl(pl))
    return DEFAULT_QUEST_FAIL;

  prop = pl->QueryProp("jenandra:cratte");

  if(!pointerp(prop)||!sizeof(prop))
    return "Komm wieder, wenn Du weisst, was Du tust! Frag am besten erst "
           "mal Kruuolq!";
  if(member(prop,"hutschat")==-1)
    return "Du hast ja noch gar nicht alles beisammen, was Du brauchst. "
           "Belaestige mich nicht.";

  if(member(prop,"zugenaeht")==-1)
    return "Mach erst mal Deinen Kadaver so weit fertig, bevor Du mich hier "
           "nervst!";

  if(member(prop,CHAOS_ID_ACHTARCH)!=-1)
    return "Noch mal erzaehl ich Dir das nicht, haettest eben besser "
           "aufpassen sollen!";

  if(find_call_out("ritual")==-1)
  {
    ME->SetProp("jenandra:listener",geteuid(pl));

    call_out("ritual",5,pl);

    return "Na gut.";
  }
  else
    return "Ich hab zu tun!";
}

static string mydefault()
{
  object pl;
  string *prop;

  if(!check_pl(PL))
    return DEFAULT_QUEST_FAIL;
  
  prop = PL->QueryProp("jenandra:cratte");
  
  if(!pointerp(prop)||!sizeof(prop))
    return "Ich wuesste nicht, was Dich das angeht.\n";

  if(member(prop,CHAOS_ID_ACHTARCH)==-1)
    return "Du willst doch nicht etwa, dass ich ausgerechnet Dir was ueber "
           "das Ritual der Chaosratte erzaehle?";

  return "Du weisst alles, was Du wissen musst. Verpiss Dich.";
}

static void ritual (object pl)
{
  object zettel;

  string *txt=
  ({Name(WER)+" raeuspert sich.\n",
    
    break_string("Pass gut auf, ich werde Dir das nur ein einziges Mal "
    "erzaehlen. Also beschwer Dich hinterher nicht, wenn Du was nicht "
    "weisst.",0,Name(WER)+" warnt Dich: "),

    break_string("Du arglst vor Dich hin und blickst Dich hektisch um. "
    "Ah, da liegt ein kleiner Notizblock. Du kramst erfolgreich nach "
    "etwas zum Schreiben und schaust "+name(WEN)+" erwartungsvoll an."),

    Name(WER)+" sagt: Also, zuerst brauchst Du Blut.\n",

    "Du beginnst, eifrig mitzukritzeln.\n",

    Name(WER)+" sagt: Dein eigenes Blut, wohlgemerkt!\n",

    Name(WER)+" grinst fies.\n",
    break_string("Das heisst, Adern aufschneiden ist angesagt. In dem Blut "
    "musst Du den Kadaver dann waelzen.",0,Name(WER)+" sagt: "),

    break_string("Dann musst Du ihn verbuddeln. Aber nicht irgendwo, es "
    "muss in einem ganz bestimmten Grab sein.",0,Name(WER)+" sagt: "),
    Name(WER)+" faengt an zu denken. Kleine Rauchwoelkchen steigen auf.\n",
    Name(WER)+" denkt . o O (Aehm, welches war das gleich?)\n",

    break_string("Ach ja, das vom Zombiedrachen, glaub ich. Also da den "
    "Kadaver verbuddeln. Ein Pentagramm darf natuerlich auch nicht "
    "fehlen, ein gutes Pentagramm, mit Bannkreis und Bannzauber, wenn Du "
    "das kannst, und nicht nur mit Kreide!",0,Name(WER)+" sagt: "),
    Name(WER)+" hebt wichtigtuerisch den Zeigefinger.\n",

    break_string("Und dann kommt das Wichtigste - die chaotischen Worte "
    "der Verwandlung.",0,Name(WER)+" sagt: "),

    Name(WER)+" macht eine dramatische Pause und mustert Dich ernst.\n",
  
    Name(WER)+" sagt: Die Worte lauten ...\n",

    Name(WER)+" stockt.\n",
  
    Name(WER)+" denkt . o O (Ich werd alt.)\n",
    
    Name(WER)+" kratzt sich am Kopp.\n",
    
    Name(WER)+" sagt: Ah, natuerlich. Also, die Worte lauten:\n",

    Name(WER)+" deklamiert: Bumlegmdowe, xorchm yque uenkl Bumlekroeter!\n",

    Name(WER)+" stutzt.\n",

    Name(WER)+" sagt: Aehm, nein, vergiss das.\n",

    Name(WER)+" denkt sehr konzentriert nach. Grosse Rauchwoelkchen steigen "
    "auf.\n",

    Name(WER)+" sagt: Jetzt aber.\n",
    
    Name(WER)+" deklamiert: Strunz nurns Krozx, xorchm yque yque Klumslsm!\n",

    Name(WER)+" nickt zufrieden.\n",
    
    Name(WER)+" mustert Dich.\n",
    
    Name(WER)+" sagt: Achja - und achte auf deinen Charakter!\n",
    
    Name(WER)+" grummelt: So, jetzt verschwinde gefaelligst.\n",
    
    break_string("Hastig reisst Du Deinen Notizzettel vom Block ab und "
    "hoffst, alles richtig mitgekriegt zu haben.")});

  if(counter1 < sizeof(txt))
  {
    if(present(pl,environment(ME)))
    {
      tell_object(PL,txt[counter1]);
      
      tell_room(environment(ME),Name(WER)+" fluestert "+pl->name(WEM)+" etwas "
                "zu.\n",({pl}));
      counter1++;

      if(find_call_out("ritual")==-1)
        call_out("ritual",3,pl);
      
      return;
    }
    else
    {
      counter1=0;
      tell_room(environment(ME),break_string(
      "Haut einfach ab, waehrend ich mir den Mund fusselig rede, "
      "sowas...",0,Name(WER)+" grummelt: "));

      if(find_call_out("ritual")!=-1)
        while(remove_call_out("ritual")!=-1);
    }
  }
  if(counter1 >= sizeof(txt))
  {
    if(present(pl,environment(ME)))
    {
      mixed prop;
  
      prop = pl->QueryProp("jenandra:cratte");
  
      if(pointerp(prop) && sizeof(prop))
      {
        if(present(pl,environment(ME)) &&
          (ME->QueryProp("jenandra:listener")!=0) &&
          (ME->QueryProp("jenandra:listener")==getuid(pl)))
        {
          prop += ({CHAOS_ID_ACHTARCH});
        
          pl->SetProp("jenandra:cratte",prop);
          
//          zettel = clone_object(C_JENANDRA_CRATTE("notiz"));
          
          zettel->move(pl,M_NOCHECK);
          
          ME->SetProp("jenandra:listener",0);
        }
      }
    }
    counter1 = 0;

    if(find_call_out("ritual")!=-1)
      while(remove_call_out("ritual")!=-1);

    return;
  }	
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(20);
  enable_commands();
  SetProp(P_SHORT,capitalize(CHAOS_ID_ACHTARCH)+" der Haendler");
  SetProp(P_LONG,
  "Dies ist der Haendler "+capitalize(CHAOS_ID_ACHTARCH)+", dessen "
  "unglaublicher Geschaeftssinn weit ueber die Grenzen des Nordlands hinaus "
  "bekannt ist. Dies bestaetigt auch die Medaille, die er voller Stolz immer "
  "traegt.");
  
  SetProp(P_NAME,capitalize(CHAOS_ID_ACHTARCH));
  SetProp(P_GENDER,1);
  SetProp(P_ARTICLE,0);
  SetProp(P_MAX_HP,250);
  SetProp(P_HP,250);
  SetProp(P_XP,0);
  SetProp(P_ALIGN,300);
  SetProp(P_HANDS,({" mit blossen Haenden",150}));
  SetProp(P_BODY,90);
  SetProp(P_SIZE,198);
  SetProp(P_RACE,CL_HUMAN);
  AddId(({"mann","haendler",CHAOS_ID_ACHTARCH}));
  seteuid(getuid(ME));
  SetProp(P_DEFAULT_INFO,"zuckt ratlos mit den Schultern.\n");

  AddInfo(({"zardoz"}),
  "Zardoz ist der schoepfer der Chaosgilde.","sagt: ");
  
  AddInfo(({"mitglied","mitglieder"}),
  "Meinst Du, ich kenne alle Mitglieder der Gilde?","fragt: ");

  AddInfo(({"kruuolq"}),
  "Das ist der oberste Meister der Gilde des Chaos. Er kann Deine "
  "Zauberfaehigkeiten beurteilen und kennt auch alle Zaubersprueche der "
  "Gilde.","sagt: ");
  
  AddInfo(({"laden","handel","haendler"}),
  "Dies ist mein Laden, in dem ich vor allem Zubehoer und Zutaten fuer "
  "die Gildenmitglieder verkaufe. Sie brauchen diese um schoene Pentagramme "
  "und Bannkreise zu zeichnen.","sagt: ");
  
  AddInfo(({"pentagramm","pentagramme","kreis","kreise","bannkreise",
            "bannkreis"}),
  "Du kannst die Pentagramme und Bannkreise mit verschiedenen Materialien "
  "zeichnen. Je besser die Qualitaet des Zeichenmaterials, um so besser die "
  "magische Wirkung des Pentagramms. Wie die Pentagramme genau funktionieren "
  "ist mir nicht ganz klar, obwohl Wuqour es mir mal erklaert hat. Besser, "
  "Du fragst ihn.","sagt: ");
  
  AddInfo(({"wuqour","ritualmeister"}),
  "Wuqour ist der Ritualmeister der Gilde. Er verrichtet seine Arbeit im "
  "Ritual- und Beschwoerungsraum.","sagt: ");
  
  AddInfo(({"ritualraum","beschwoerungsraum"}),
  "Der Ritualraum befindet sich direkt suedlich von hier. Er ist aber "
  "nur fuer Gildenmitglieder zu betreten.","sagt: ");
  
  AddInfo("gilde",
  "Die Gilde befindet sich westlich der grossen Halle.","sagt: ");
  
  AddInfo("halle",
  "Die grosse Halle ist noerdlich des grossen Platzes.","sagt: ");
  
  AddInfo("platz",
  "Du bist sicher schon dran vorbeigekommen. Spikey steht da immer "
  "rum.","sagt: ");
  
  AddInfo("spikey",
  "Der steht steht immer auf dem grossen Platz rum.","sagt: ");
  
  AddInfo(({"kneipe","gaststaette"}),
  "Hi hi :-) Die schaebige Kneipe ist nicht gerade eine besonders "
  "gepflegte Gaststaette. Sie verkaufen dort nur Schund zu ueberhoehten "
  "Preisen.","sagt: ");
  
  AddInfo("zubehoer",
  "Beim Zubehoer zum Zeichnen von Pentagrammen und Bannkreisen unterscheidet "
  "man zwei Arten: Zeichenmaterial und Zubehoer. Ich verkaufe beides.",
  "sagt: ");
  
  AddInfo(({"zutaten","zutat"}),
  "Zutaten fuer Bannkreise sind magische Objekte, die man in das Pentagramm "
  "oder auf den Bannkreis stellt. Haeufig nimmt man fuer sowas schwarze "
  "Kerzen, die ich in meinem Sortiment habe. Aber es gibt auch einige andere "
  "Geheimmittel, die ich leider nicht vorraetig habe, da sie zu schwer zu "
  "bekommen sind.","sagt: ");
  
  AddInfo("geheimmittel",
  "Besonders gut eignen sollen sich die Augen eines Wasserunwesens, die man "
  "einfach in den Bannkreis setzt. Weitere Zutaten fallen mir jetzt nicht "
  "ein.","sagt: ");  
  
  AddInfo(({"kerzen","kerze" }),
  "Ich verkaufe hier schwarze Kerzen, die ewig brennen. Leider leuchten sie "
  "auch schwarz und erhellen somit keinen dunklen Raum.","sagt: ");
  
  AddInfo(({"zeichenmaterial","material"}),
  "Zum Zeichnen von Pentagrammen und Bannkreisen kann man die verschiedensten "
  "Sachen benutzen: Am gebraeuchlichsten ist immer noch die normale Kreide, "
  "die aber nur fuer einfache Daemonen ausreicht. Empfehlen kann ich meinen "
  "Goldstaub und das seltene Drachenblut. Beides hat natuerlich seinen "
  "Preis. Weiterhin gibt es einige Geheimmaterialien, die ich nicht vorraetig "
  "habe.","sagt: ");
  
  AddInfo(({"geheimmaterial","geheimmaterialien"}),
  "Nun, es gibt einige Sachen, die besonders gut, dafuer auch schwer zu "
  "bekommen sind. Zum Beispiel das Knochenmehl eines urzeitlichen Monsters, "
  "das wirklich ausgezeichnet ist.","sagt: ");
  
  AddInfo(({"mehl","knochenmehl","auge","wasserunwesen"}),
  "Ich weiss leider nicht, wo man sowas bekommen kann. Sonst haette ich es "
  "schon laengst in meinem Sortiment.","sagt: ");
  
  AddInfo("medaille",
  "Auf diese Medaille bin ich besonders stolz!","sagt: ");
  
  AddInfo(({"satan"}),
  "Das ist ein direkter Verwandter von mir :)","grinst: ");
  
  AddInfo(({"chaos"}),
  "Ich lieeeeebe das Chaos!","kichert: ");
  
  AddInfo(({CHAOS_ID_ACHTARCH}),
  "Das bin ich, du Trottel!","schreit: ");
  
  AddInfo(({"gildenladen"}),
  "Du stehst mitten drin. Ich biete hier momentan nur Komponenten zum "
  "Zeichnen von Pentagrammen und Bannkreisen an, aber Du kannst mir auch "
  "welche verkaufen. Ich weiss aber auch einiges ueber spezielle, magische "
  "Ruestungen fuer Daemonen...","sagt: ");
  
  AddInfo(({"hutschat", "verwalter"}),
  "Hutschat ist der Verwalter unserer Gilde.","sagt: ");
  
  AddInfo(({"daemonen","daemon"}),
  "Dafuer ist Wuqour unser Experte, frag ihn. Ich kann dir nur "
  "ueber magische Ruestungen fuer Daemonen was erzaehlen.","sagt: ");
  
  AddInfo(({"experte","experten"}),
  "Oh, wir haben hier viele Experten.","grinst: ");
  
  AddInfo(({"raeume"}),
  "Dazu gehste am besten mal zu Hutschat.","sagt: ");
  
  AddInfo(({"kaempfer","untoter","diener"}),
  "Ja, hier treibt sich irgendwo ein Untoter Kaempfer rum, der "
  "aufgrund eines Fluches in unsere Dienste gebannt wurde :)","sagt: ");
  
  AddInfo(({"fluch"}),
  "Da frag mal besser den Kaempfer.","sagt: ");
  
  AddInfo(({"galerie"}),
  "Ja, die 'Daemonische Galerie', die gibts hier auch irgendwo, "
  "aber Du musst schon selber gucken.","sagt: ");

  AddInfo(({"waffenlager","waffenarsenal"}),
  "Jo, ein Waffenlager haben wir auch. Dafuer haben wir sogar "
  "einen Diener, einen Kaempfer, hehe.","kichert: ");
  
  AddInfo(({"diener"}),
  "Da frag mal besser den Kaempfer.","sagt: ");
  
  AddInfo(({"burg"}),
  "Diese daemonische Burg ist der Hauptsitz unserer Chaosgilde",
  "sagt stolz: ");
  
  AddInfo(({"hauptsitz"}),
  "Der ist hier.","sagt: ");
  
  AddInfo(({"eisberg","hoehle"}),
  "Hmm, darueber weiss ich nicht soviel, musste mal bisschen rumfragen.",
  "sagt: ");
  
  AddInfo(({"kleriker","trves","zauberer","karatekas","katzenkrieger",
            "elementare","tanjian","bierschuettler","dunkelelfen",
            "druiden","feen"}),
  "Ich glaube Hutschat weiss ganz gut ueber die Bescheid.","sagt: ");
  
  AddInfo(({"chaoskomponenten","komponenten"}),
  "Hmm, also ich kenne momentan folgende Komponenten:\n"
  "Kreide, Streitkolbenstaub, Zardoz' Mittelfinger, schwarze Kerzen, "
  "Wasserunwesenaugen, farbiges Eis, Drachensabber, Daemonenschleim, "
  "Silberstaub, Goldstaub, diverse Chaosfarben, schwarze Bleistifte, "
  "Knochenmehl, schwarzer Sand, Kroetenhaut, Ghoulschleim, "
  "Luftwirbel, Waberblasenglut und Stufenpunktbruchstuecke, aber es "
  "soll noch mehr geben... Ausserdem kenn ich mich noch mit "
  "Daemonenausruestung ein wenig aus.","fluestert: ");
  
  AddInfo(({"kreide"}),
  "Pfft, also ueber Kreide was zu erzaehlen, tut mir leid, aber DAS "
  "ist unter meinem Niveau!","sagt: ");

  AddInfo(({"niveau"}),
  "Das ist sehr hoch!","sagt: ");
  
  AddInfo(({"streitkolbenstaub","staub","streitkolben"}),
  "Ja, der Staub eines magischen Streitkolbens. Meinen Informationen "
  "zugrunde, muesste ein kleiner boeser Zwerg diesen Streitkolben "
  "besitzen, jedoch kommt dort, wo er ist nicht jeder hin. Ausserdem "
  "darf man nicht gerade kaelteempfindlich sein!","sagt: ");
  
  AddInfo(({"zwerg"}),
  "Ich weiss auch nur das er boese ist.","bedauert: ");
  
  AddInfo(({"informationen","information"}),
  "Du solltest mich einfach mal ausfragen.","grinst: ");
  
  AddInfo(({"eis","farbiges eis"}),
  "Die Chaoskomponente 'Farbiges Eis' wurde zuletzt von einem "
  "gleich darauf an seinen schweren Wunden gestorbenen Abenteurer "
  "zu mir gebracht. Er stammelte noch irgend etwas von 'Eisdaemonen' "
  "und 'fuerchterliche Schneestuerme'","sagt: ");
  
  AddInfo(({"wunden"}),
  "Sie waren zu schwer fuer ihn.","kichert boese: ");
  
  AddInfo(({"eisdaemonen","schneestuerme"}),
  "Tut mir leid, mehr weiss ich auch nicht darueber.","sagt: ");
  
  AddInfo(({"abenteurer","waschlappen"}),
  "Irgendso ein Waschlappen halt.","sagt: ");
  
  AddInfo(({"drachensabber"}),
  "Hmm, Drachensabber kann man nur an einer einzigen Stelle im "
  "Efferdland bekommen, naemlich beim Nagadrachen.","sagt: ");
  
  AddInfo(({"stelle"}),
  "Ich sag doch, beim Nagadrachen.","sagt: ");

  AddInfo(({"nagadrachen"}),
  "Geruechten zufolge soll es in der Galerie einen Zugang zu ihm "
  "geben.","fluestert: ");

  AddInfo(({"geruechte","zugang"}),
  "Wer weiss...","sagt: ");
  
  AddInfo(({"daemonenschleim"}),
  "Das spucken die Schwarzwasserdaemonen aus, wenn man sie genug "
  "reizt.","kichert: ");
  
  AddInfo(({"schwarzwasserdaemonen","schwarzwasserdaemon"}),
   "Die leben am Schlundsee.","sagt: ");

  AddInfo(({"silberstaub"}),
  "Silberstaub ist ne recht billige Komponente, Du kannst sie hier "
  "bei mir direkt kaufen.","sagt: ");

  AddInfo(({"goldstaub"}),
  "Goldstaub ist ebenso wie Silberstaub fast schon eine "
  "Standard-Komponente.","sagt: ");
  
  AddInfo(({"standard-komponente"}),
  "Silber- und Goldstaub zb.","sagt: ");
  
  AddInfo(({"angebot"}),
  "Mach einfach mal 'zeige'.","sagt: ");
  
  AddInfo(({"sand","schwarzer sand","schwarzem sand"}),
  "Sieht seltsam aus, nicht wahr? Aber ist nicht halb so merkwuerdig "
  "wie es aussieht, da man es hier immer kaufen kann.","sagt: ");
  
  AddInfo(({"wasserunwesenaugen","augen"}),
  "Die Augen des Wasserunwesens sind eigentlich keine Komponente "
  "zum Zeichnen eines Pentagramms oder Bannkreises, sondern zum "
  "nachtraeglichen Verstaerken ebendieser.","sagt: ");

  AddInfo(({"wasserunwesen"}),
  "Ebenso wie die Dunkeldaemonen beim Daemonendrachen zu "
  "finden.","sagt: ");
  
  AddInfo(({"kroetenhaut"}),
  "Kroetenhaut ist die einzige Komponente die ich nicht kenne. Man "
  "hat mir nur vor langem einmal davon berichtet.","seufzt: ");
  
  AddInfo(({"chaosfarben","chaosfarbe","farben","farbe"}),
  "Die Chaosfarben... Es gibt viele unterschiedliche davon... "
  "Jedoch sind sie nicht alle gleichermassen gut geeignet fuer unsere "
  "daemonischen Pentagramme und Bannkreise. Die meisten hat man jedoch "
  "bei den Draks gesichtet, wie mir vom Geist eines kuerzlich "
  "dort verstorbenen Chaoskriegers berichtet wurde.","sagt: ");
  
  AddInfo(({"gebiet","drak","draks","drakgebiet"}),
  "Das Gebiet der Draks sollte man vorsichtig anschauen...","sagt: ");
  
  AddInfo(({"geist","chaoskrieger"}),
  "Er war zu unvorsichtig!","sagt: ");

  AddInfo(({"mittelfinger","finger","kerzen","schwarze kerzen"}),
  "Zardoz' Mittelfinger und die schwarzen Kerzen... Zuletzt wurden "
  "diese Komponenten in einem seltsamen Paralellweltkubus nahe "
  "des Grossen Sees  gesichtet...","sagt: ");
  
  AddInfo(({"paralellweltdimension"}),
  "Eine Paralellwelt eben.","sagt: ");

  AddInfo(({"weissfroesche"}),
   "Die solltest Du kennen!","sagt: ");
  
  AddInfo(({"tier"}),
  "Am besten du siehst selbst nach, sofern es dir moeglich "
  "ist.","sagt: ");
 
  AddInfo(({"bleistifte","schwarze bleistifte"}),
  "Die schwarzen Bleistifte findet man ebenso wie diverse Chaosfarben "
  "hauptsaechlich in Gebiet der Draks.","sagt: ");
  
  AddInfo(({"luftwirbel"}),
   "Chaotische Luftwirbel... Man fraegt sich, wie man so etwas "
   "ueberhaupt nehmen kann... Jedoch ist es durchaus moeglich, und "
   "derjenige der es schafft, darf sich gluecklich schaetzen, eine "
   "wirklich gute Chaoskomponente zu besitzen. Doch die Gefahren, "
   "die in der Eiszinne, dem Fundort dieser Luftwirbel auf einen warten, "
   "sind nicht zu unterschaetzen!","sagt: ");

  AddInfo(({"gefahren"}),
  "Glaub mir, die Gefahren der Eiszinne sind wirklich nicht zu "
  "unterschaetzen...","sagt: ");

  AddInfo(({"eiszinne"}),
   "Die Eiszinne, tja die musst Du schon selbst finden.","sagt: ");

  AddInfo(({"stufenpunktbruchstueck","bruchstueck","stufenpunkt"}),
   "Das Bruchstueck eines Stufenpunkts? Nun, das hoert sich wie Du "
   "sicher auch schon denkst, ziemlich merkwuerdig an :) Solch eine "
   "seltsame, jedoch SEHR maechtige Komponente findet man nur an einem "
   "Ort von aeusserst konzentrierter Magie, der angeblich eine Insel "
   "sein soll.","sagt: ");

  AddInfo(({"ort","magie","insel"}),
   "Eine Insel aus konzentrierter Magie soll es sein.","sagt: ");

  AddInfo(({"mehr"}),
  "Momentan kenne ich nicht mehr, als die aufgezaehlten Komponenten, "
  "jedoch ist es vielleicht ratsam in einigen Abstaenden noch einmal "
  "nachzufragen...","sagt: ");

  AddInfo(({"ghoulschleim"}),
  "Ghoulschleim, kommt wie man schon hoert, von Ghouls. Und eben diese "
  "Ghouls findet man nur in den duestersten Winkeln der Katakomben vom "
  "Gebirge. Dahin sollten sich jedoch wirklich nur die "
  "tapfersten Leute trauen, und ob es sich fuer diese minderwertige "
  "Komponente ueberhaupt lohnt, sollte man sich sowieso "
  "fragen!","sagt: ");
  
  AddInfo(({"ghouls"}),
   "Man findet sie hauptsaechlich in den Katakomben des Gebirges.","sagt: ");
  
  AddInfo(({"katakomben","gebirge"}),
   "Wenn du diese besuchen willst, so geh am besten mit mehreren "
   "Leuten dahin...","sagt: ");
  
  AddInfo(({"schleim"}),
  "Welchen Schleim meinst du ? Daemonen- oder Ghoulschleim?","fragt: ");
 
  AddInfo(({"leute"}),
  "Na Leute eben.","grinst: ");
  
  AddInfo(({"ausruestung","daemonenausruestung"}),
  "Nun, ich hatte schon einiges an daemonischer Ausruestung in meinen "
  "Haenden, wie zum Beispiel ein Paar daemonischer Handschuhe, "
  "einem Daemonenhelm nebst Stiefel, sowie einem "
  "Daemonenpanzer.","fluestert: ");
  
  AddInfo(({"handschuhe"}),
  "Die Handschuhe hatten den typischen Saeure-Ynagzet-Geruch an "
  "sich. Und sie sollten eine extrem gute Eigenschaft fuer Daemonen "
  "besitzen...","sagt: ");
  
  AddInfo(({"saeure-ynagzet","saeure-ynagzet-geruch","geruch"}),
  "Den Saeure-Ynagzet findet man in der Daemonen-Dimension.","sagt: ");
  
  AddInfo(({"daemonendimension"}),
  "Auch wieder was fuer mehrere Leute.","grinst: ");
  
  AddInfo(({"eigenschaft"}),
  "Das solltest Du selbst herausfinden.","grinst: ");
  
  AddInfo(({"daemonenhelm","daemonenstiefel","daemonenpanzer","panzer",
            "stiefel","helm"}),
  "Laut juengsten Auskuenften zufolge gibt es diese Daemonenausruestung "
  "in verschuetteten Gaengen einer uralten Steinbeisserhoehle zu finden."
  "Aber niemand weiss, ob das wirklich stimmt.","sagt: ");
  
  AddInfo(({"auskuenfte"}),
  "Wo ich die herhabe sage ich nicht!","sagt: ");
  
  AddInfo(({"gaenge","steinbeisserhoehle"}),
  "Finde sie!","sagt: ");
/*
Chaosrattenquest-Infos:
*/
  AddInfo(({"verwandlung","ritual","ratte","chaosratte","drecksratte",
            "beschwoeren","beschwoerung"}),#'ratte,"grollt: ");

  AddInfo(({"zombiedrache","drache","nadel","naehnadel","catgut","katze",
            "katzendarm","katzenleiche","einsiedler","ambusufzk","adern",
            "ader","insel","fels","felsen","felsbrocken",
            "kadaver"}),#'mydefault,"grummelt: ");

  AddInfo(({"uwe","uns-uwe"}),
  "Der und sein sogenannter Fanartikelshop! Eine Schande ist das! Und ein "
  "unertraeglicher Nachbar ist er noch dazu!","flucht: ");

  AddInfo(({"shop","fanartikelshop","fanartikel"}),
  "Nur Muell ist das, was Uns-Uwe da verkauft, sein Geld nicht wert.",
  "laestert: ");

  AddInfo(({"nachbar"}),
  "Dreckig und laut, der verscheucht mir die ganze Kundschaft.",
  "beschwert sich: ");
  
  AddInfo(({"kunde","kunden","kundschaft"}),
  "Genau, willst du etwas kaufen oder nicht? Wenn nicht, verschwinde!",
  "schnauzt: ");
  
  AddInfo(({"belohnung"}),#'belohnung_inf,"sagt: ");
/*
Spenden-Sammel-Quest-Infos:
*/
  AddInfo(({"hilfe","aufgabe"}),
  "Ach, seit Kruuolq und Wuqour die Komponenten so stark aufgewertet "
  "haben, laeuft mein Laden wirklich schlecht. Ich will mich wirklich "
  "nicht beklagen, aber du koenntest mir helfen. Ich habe auch schon "
  "einen Plan ausgearbeitet.","sagt: ");
  
  AddInfo(({"plan"}),#'plan_inf,"sagt: ");

  AddInfo(({"buechse","spendenbuechse"}),#'buechse_inf,"sagt: ",
  "antwortet @WEM.\n");

  AddInfo(({"luschengilde","luschen-gilde"}),#'gilde_inf,"sagt: ",
  "antwortet @WEM.\n");
  
  AddInfo(({"sammeln"}),#'sammel_inf,"sagt: ","antwortet @WEM.\n");
  AddInfo(({"spende","spenden"}),#'spenden_inf,"sagt: ",
   "antwortet @WEM.\n");
  AddInfo(({"denkmal"}),#'denkmal_inf,"sagt: ","antwortet @WEM.\n");
  AddInfo(({"geld"}),#'geld_inf,"sagt: ","antwortet @WEM.\n");
  AddInfo(({"teil"}),#'teil_inf,"sagt: ","antwortet @WEM.\n");
  AddInfo(({"rest"}),#'rest_inf,"sagt: ","antwortet @WEM.\n");
  AddInfo(({"ueberleben"}),#'leben_inf,"sagt: ","antwortet @WEM.\n");
  AddInfo(({"sammelaktion"}),#'sammelaktion_inf,"sagt: ",
   "antwortet @WEM.\n");

  AddItem(CHAOS_GILDEN_ARMOUR("medaille"),REFRESH_REMOVE|CLONE_WEAR);
}

                
varargs void die()
{
  if(!environment())
    return;
  
  if(!query_once_interactive(PL)) 
    return::die();
  
  environment()->SetProp("chaos_haendler_tot",getuid(PL));
  ::die();
}

give_notify(ob)
{
  object env,sh;
  string wen;
  int i;

  ::give_notify(ob);
  env = environment(ME);
  wen = ob->name();

  if(!env)
    return;
  
  if(ob->id("\nguild-chaos:buechse"))
  {
    if(PL->QueryProp(P_GUILD)!="chaos")
      return;
    
    i = ob->QueryProp(P_AMOUNT);
    
    if(i >= 50000)
    {
      if(sh=present("\nguild-chaos:buechse_obj",environment(PL)))
      {
        if(sh->QueryProp(SAMMLER)==getuid(PL))
          sh->remove();
      }
      if(call_other((SSQMASTER),"CheckAufgabe",getuid(PL)) < 1)
      {
        call_other((SSQMASTER),"SetzeAufgabe",getuid(PL),
           PL->name(),PL->QueryProp(P_GENDER));
        
        call_other((SSQMASTER),"SetzeSpender",getuid(PL),i);
        
        write(break_string("Wow, "+PL->name(WER)+"! Ich bin "
              "restlos begeistert, Du hast es tatsaechlich geschafft, alle "
              "zu taeuschen. Hier hast Du einen angemessenen Teil! "
              "Gratulation nochmal!!!",0,Name(WER)+" sagt: "));
      }
    }
    if(call_other((SSQMASTER),"CheckSpender",getuid(PL)) < i)
    {
      call_other((SSQMASTER),"SetzeSpender",getuid(PL),i);
    
      write(break_string("Respekt, Du hast Deine alte Bestmarke "
             "tataechlich noch uebertreffen koennen. Huih!",0,
             Name(WER)+" sagt: "));
     }
    ob->remove();
    write(Name(WER)+" steck Dir etwas zu.\n");
    
    PL->AddMoney( (i/2) );
    ME->AddMoney( (i/2) );
    
    LetsGoDrink();
    
    if(call_other((SSQMASTER),"CheckAufgabe",getuid(PL)) >= 1)
    {
      if(!present("\ntilly:chaut_obj",PL))
      {
        if(present_clone(CHAOS_CHAOSHAUT,PL))
        {
          sh = clone_object("/d/polar/files.chaos/tilly/obj/chautobj");

          sh->move(PL,M_NOCHECK);
          
          write(Name(WER)+" heftet Dir etwas an Deine Chaoshaut.\n");
          
          tell_room(environment(PL),Name(WER)+" heftet etwas an "
                    +PL->name(WESSEN)+" Chaoshaut.\n",({PL}));
         }
        else
          write(break_string("Du hast keine Chaoshaut und musst Dir die "
                "Belohnung ein anderes mal abholen.",0,Name(WER)+" sagt: "));
      }
    }
    return;
  }
  else
  {
    tell_room(environment(ME),Name(WER)+" laesst "+wen+" fallen "
     +"und grunzt laut.\n"); 
    ob->move(env,M_PUT);
    return;
  }
}
