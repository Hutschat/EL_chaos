// hutschat.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#pragma no_inherit
#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"
#define DEFAULT_QUEST_FAIL "Frag Kruuolq."

inherit "/std/npc";

int last_call;

// Chaosrattenquest

static int check_pl(object pl){
#ifndef JENANDRA_QUEST
  if(pl->QueryProp("jenandra:testquest")) return 1;
  return 0;
#else
  return 1;
#endif
}

static string nadel()
{
  object pl,nadel;
  string *prop;

  pl=PL;

  if(!check_pl(pl))
    return DEFAULT_QUEST_FAIL;

  prop = pl->QueryProp("jenandra:cratte");

  if(!pointerp(prop)||!sizeof(prop))
	return "Frag Kruuolq.";

  if(member(prop,"einsiedler")==-1)
	return "Find erst mal raus, was Du machen musst. Dann kannst Du "+
	"von mir aus wiederkommen.";

/*  if(present("\n"+C_JENANDRA_CRATTE("nadel"),pl)||
    present("WOLPIEQUESTID",pl)){
    if(member(prop,"hutschat")==-1){
      prop+=({"hutschat"});
      pl->SetProp("jenandra:cratte",prop);
    }
	return "Du hast doch schon eine Nadel! Lass mich in Ruhe!";
  }
  tell_object(pl,break_string("Hutschat mustert Dich scharf und "
  "oeffnet dann ein Geheimfach an seinem Schreibtisch, um ein Naehkaestchen "
  "herauszuholen. Als er es oeffnet, siehst Du, dass es sehr gut sortiert "
  "ist. Du kannst Dir ein Grinsen kaum verkneifen.",78)+
  break_string("Er sucht eine Nadel aus und gibt sie Dir. Dann stellt er "
  "das Naehkaestchen zurueck und verschliesst das Geheimfach sorgfaeltig "
  "wieder.",78));
  tell_room(environment(ME),break_string("Hutschat "
  "tuschelt heimlich mit "+pl->name(WEM)+" und scheint "
  +(pl->QueryProp(P_GENDER)==2?"ihr":"ihm")+" etwas zu geben.",78),({pl}));
  nadel=clone_object(C_JENANDRA_CRATTE("nadel"));
  nadel->move(pl,M_NOCHECK|M_SILENT);
  prop+=({"hutschat"});
  pl->SetProp("jenandra:cratte",prop);
*/
  return "Wehe, Du erzaehlst das rum!";
}

static string katze()
{
  string *prop;

  if(!check_pl(PL))
    return DEFAULT_QUEST_FAIL;

  prop = PL->QueryProp("jenandra:cratte");

  if(!pointerp(prop)||!sizeof(prop))
    return "Wuesste nicht, von welchem Interesse das fuer Dich sein koennte.";

  return "Ich habe gehoert, Pubert soll Catgut aus toten Katzen machen "
         "koennen - frag mich nicht, warum ausgerechnet der.";
}

// Ende Chaosrattenquest

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(30,300);
  last_call = 0;
  SetProp(P_SHORT, "Hutschat der Verwalter des Chaos");
  SetProp(P_LONG, 
  "Hutschat ist der Verwalter. Er ist der einzige, der durch dieses ganze\ "
  "Chaos blickt und ist deshalb von hoechster Wichtigkeit fuer das "
  "Fortbestehen der Gilde, denn ohne ihn kann niemand in die Gilde "
  "aufgenommen werden, austreten oder seine Stufe erhoehen.");
  SetProp(P_NAME, "Hutschat");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE, 0);
  SetProp(P_ALIGN, 400);
  SetProp(P_SIZE, 145);
  SetProp(P_HANDS, ({" mit blossen Haenden", 30,DT_BLUDGEON }));
  SetProp(P_BODY, 50);
  SetProp(P_RACE,CL_DWARF);
  SetProp(P_DEFAULT_INFO, "sagt: Frag Kruuolq.\n");
  AddId(({"verwalter","hutschat"}));

  AddInfo("hutschat", 
  "Das bin doch ich!! :-)", "grinst: ");  

  AddInfo("zardoz",
  "Zardoz hat diese Gilde gebaut und laesst mich hier mit unmoeglichen "
  "Arbeitszeiten herumstehen.", "sagt: ");

  AddInfo(({"arbeitszeiten", "arbeitszeit" }),
  "Nun, Du kannst mich ja mal nach meiner Freizeit fragen...", "grummelt: ");

  AddInfo( "freizeit",
  "Sowas siehst Du hier nicht.", "weint: ");

  AddInfo(({"wuqour", "ritualmeister" }),
  "Wuqour ist unser Ritualmeister.", "sagt: ");

  AddInfo( "festung",
  "Du bist in der Festung des Chaos. Diese ist die Heimat der Gilde der "
  "Krieger des Chaos.", "sagt: ");

  AddInfo(({"chaot", "chaoten" }),
  "Die Mitglieder dieser Gilde sind die reinsten Chaoten.","grinst: ");

  AddInfo(({"organisation", "verwaltung" }),
  "Ich verwalte die Gilde hier. Ohne mich laeuft hier gar nichts. Deshalb "
  "bekomme ich auch ein recht hohes Gehalt.", "grinst: ");

  AddInfo(({"zauberei", "zaubersprueche", "zauberspruch", "spruch", "sprueche", "lernen",
	   "beschwoeren", "beschwoerung", "ritual", "rituale", "daemonen", 
	   "daemon","intarbir", "kruftur", "ombatis", "irkitis", "harkuhu", 
	   "kampf","tutszt", "graiop", "flaxtri", "zauber", "zauberspruechen",
	   "spruechen","nachtsicht", "dunkelheit", "bannzauber", "pentagramm", 
	   "pentagramme","bannkreis", "bannkreise", "finsternis", "chaosball",
	   "chaosschaden","arena", "kampfarena", "magie", "chaosruestung",
	   "kaempfen","kampfarena", "magie", "ziumtu","yruruu","chaosruestung", "erfordernis", 
	   "erfordernissen","bhuturih" }),
  "Da fragst Du besser mal Kruuolq. Er ist immerhin der oberste Meister "
  "der Gilde!", "sagt: ");

  AddInfo(({"hobbits", "hobbit" }),
  "Wir nehmen keine Hobbits in unsere Gilde auf!","sagt: ");

  AddInfo("vorzeigehobbit",
  "Jasper ist unser Vorzeigehobbit. :))", "sagt: ");

  AddInfo(({"meister", "kruuolq" }),
  "Das ist der oberste Meister der Gilde des Chaos.", "sagt: ");

  AddInfo(({"austritt", "austreten", "ruecktritt" }),
  "Du kannst mit 'tritt aus gilde aus' wieder diese Gilde verlassen. "
  "Allerdings verlierst Du dann Deine Zauberfaehigkeiten dieser Gilde und "
  "bist beim Wiedereintritt nur ein kleiner Chaot. Aber warum solltest Du "
  "auch austreten wollen?", "sagt: ");

  AddInfo("gehalt",
  "Mein Gehalt geht Dich gar nichts an!", "bruellt: ");

  AddInfo(({"chaos" }),
  "Die Organisation der Gilde ist das reinste Chaos. Nur ich blicke da durch.",
  "sagt: ");

  AddInfo(({"kleiner chaot", "chaot", "wahnwitziger" }),
  "Das sind unsere Stufenbezeichnungen.", "sagt: ");

  AddInfo(({"anforderungen", "anforderung", "erhoehung", "erhoehen", 
            "eintreten", "beitreten", "beitritt", "erhoehe", "aufnahmebedinung",  
            "aufnahmebedingungen", "aufnahme", "antrag", "gildenerhoehen",  
            "gildenerhoehung", "aufsteigen", "aufstieg", "eintritt" }),
  "@@anforderung@@", "sagt: ");

  AddInfo(({"bedingung", "bedingungen", "vorraussetzung" }),
  "Du musst z.B. boese genug sein um aufgenommen zu werden. Ausserdem nehmen "
  "wir grundsaetzlich keine schleimigen Froesche auf.", "sagt: ");

  AddInfo(({"beurteilung", "faehigkeit", "faehigkeiten", "zauberfaehigkeiten"}),
  "Dazu kann Dir Kruuolq mehr sagen.", "sagt: ");

  AddInfo(({"pruefung", "pruefungen", "aufgabe", "aufgaben", "kampfpruefung", 
            "kampfpruefungen", "quest" }),
  "Nun, Du musst verschiedene Aufgaben erfuellen, wenn Du Deine Stufe "
  "erhoehen willst. Zu den Aufgaben kann Dir Kruuolq mehr sagen. Er weiss "
  "auch, wie gut Du einen Zauberspruch beherrschst und ob es fuer die "
  "naechste Stufe ausreicht.", "sagt: ");

  AddInfo( "gilde",
  "Nun, wenn Du in die Gilde eintreten willst, dann kann ich Dir die "
  "Anforderungen dafuer nennen. Kannst Du diese Anforderungen erfuellen, "
  "dann kannst Du der Gilde mit 'tritt gilde bei' beitreten.",
  "sagt: ");

  AddInfo(({ "stufe", "stufen", "level" }),
  "Du kannst hier sowohl Deine Stufe als auch Deine Gildenstufe erhoehen. "
  "Dies machst Du mit erhoehe <spielerstufe | gildenstufe>. Du musst "
  "fuer die Gildenstufen natuerlich die Anforderungen erfuellen.",
  "sagt: " );

  AddInfo(({"gildenstufe", "gildenstufen", "gildentitel", "gildenlevel", 
            "stufenbezeichnungen", "stufenbezeichnung", "titel" }),
  "@@stufen@@" );

  AddInfo( "magier",
  "Magier sind doof und stinken!", "sagt: ");

 AddInfo(({"bild", "frau", "mutter"}),
 "Das war meine Mutter. Go^^, aeh, Satan sei ihrer Seele gnae^^^^, "
 "aehm, boese gestimmt.","stottert: ");
 
 AddInfo(({"satan"}),
 "Naja, ein Kumpel von uns.","grinst: ");
 
 AddInfo(({"ordner"}),
 "Och, in den Ordnern bewahre ich meine Unterlagen auf..","sagt: ");
 
 AddInfo(({"unterlagen"}),
 "Die sind in den Ordnern.","sagt: ");
 
 AddInfo(({"schublade", "schubladen"}),
 "Vergiss es, da sind meine groessten Schaetze drin!","zischt: ");
 
 AddInfo(({"schaetze"}),
 "Naja, ehrlich gesagt, ist da gar nichts drin, weil ich auch "
 "nichts habe.","kichert: ");
 
 AddInfo(({"wand", "waende", "decke", "boden", "weiss", "farbe"}),
 "Das Weiss? Gefaellt es dir nicht? Ich habe hier absichtlich alles "
 "weiss streichen lassen, damit jeder, der reinkommt erkennt, dass hier "
 "die einzige Person sitzt, die ueber dieses ganze Chaos noch den "
 "Ueberblick hat.","sagt: ");
 
 AddInfo(({"person"}),
 "Na ich, oder sitzt hier sonst noch jemand?","sagt: ");
 
 AddInfo(({"chaos"}),
 "Jaja, das Chaos, ich versuche dieses Chaos fuer die notwendigsten "
 "Sachen ein wenig zu ordnen.","seufzt: ");
 
 AddInfo(({"sachen"}),
 "Naja, Personalplanung, Rentenversicherungen und so weiter.","sagt: ");
 
 AddInfo(({"personalplanung", "formulare"}),
 "Das verstehst Du sowieso nicht!","sagt: ");
 
 AddInfo(({"rentenversicherungen"}),
 "Fuer die altgewordenen Leute unter uns.","sagt: ");
 
 AddInfo(({"pflanze"}),
 "Aehm, nun ja... Also bei der RIESENMENGE an Arbeit kommt man hier "
 "zu nichts, nichtmal zum Blumengiessen.","luegt: ");
 
 AddInfo(({"achtarch"}),
 "Das ist der Besitzer unseres kleinen Gildenladens. Er kennt "
 "sich ziemlich gut mit Chaoskomponenten und so Zeugs aus.","sagt: ");
 
 AddInfo(({"gildenladen"}),
 "Na denn wirste ja wohl finden","fragt: ");
 
 AddInfo(({"chaoskomponenten"}),
 "Da frag mal besser Achtarch.","sagt: ");
 
 AddInfo(({"raeume"}),
 "Dazu gibts hier nen Ordner.","sagt: ");
 
 AddInfo(({"kneipe"}),
 "Du willst wohl fuer alles den Weg erklaert haben, was? Vergiss es!",
 "sagt: ");
 
 AddInfo(({"galerie"}),
 "Ja, die 'Daemonische Galerie', die gibts hier auch irgendwo, aber Du musst "
 "schon selber gucken.","sagt: ");
 
 AddInfo(({"burg"}),
 "Tja, da staunst du was? Diese daemonische Burg ist der Hauptsitz der "
 "Chaosgilde, von hier aus werden all die boesen Taten begangen, wofuer wir "
 "so beruehmt sind...","sagt stolz: ");
 
 AddInfo(({"hauptsitz"}),
 "Wir haben natuerlich noch Aussenposten ueberall auf der Welt!","sagt: ");
 
 AddInfo(({"welt"}),
 "Also ich weiss zwar viel, aber das wuerde dann doch zu weit fuehren.",
 "stoehnt: ");
 
 AddInfo(({"aussenposten"}),
 "Hmm, die Mitglieder der Gilde selbst sind unsere Aussenposten.","grinst: ");
 
 AddInfo(({"mitglied", "mitglieder"}),
 "Davon haben wir viele!","sagt: ");
 
 AddInfo(({"taten"}),
 "Ieeeks, das sind so fuerchterliche Dinge, die darf man normalerweise "
 "nichtmal denken!","sagt zitternd: ");
 
 AddInfo(({"dinge"}),
 "Naja, DINGE eben!","zittert: ");
 
 AddInfo(({"eisberg", "hoehle", "eis"}),
 "Ueber den schwarzen Eisberg und die vor der Burg liegende Hoehle weiss ich "
 "leider nur wenig. Meine Aufgabe ist eben die Verwaltung.","sagt: ");
 
 AddInfo(({"aufgabe"}),
 "Die Verwaltung dieses Chaos' hier ist meine Aufgabe.","sagt: ");
 
 AddInfo(({"kleriker"}),
 "Ieeehh, dieses PACK!!! Frag besser nie Kruuolq danach, der regt sich immer "
 "leicht darueber auf!","schreit: ");
 
 AddInfo(({"trves"}),
 "Widerliche Angeber, die keinen Funken Ahnung von der Macht der Chaosmagie "
 "haben!","sagt: ");
 
 AddInfo(({"angeber"}),
 "Du kannst nur die Trves meinen.","grinst: ");
 
 AddInfo(({"funken", "ahnung"}),
 "Aber auch nicht einen.","sagt: ");
 
 AddInfo(({"chaosmagie", "macht"}),
 "SEHR maechtig!","fluestert: ");
 
 AddInfo(({"zauberer"}),
 "Du meinst diese Feiglinge, die sich immer im gefaehrlichsten Moment "
 "wegteleportieren? Doch das kann hier bei uns sehr schnell boese ausgehen.",
 "kichert: ");
 
 AddInfo(({"feiglinge"}),
 "Sag nichts... Du sprichst... von den... ZAUBERERN, oder?","grinst: ");
 
 AddInfo(({"karatekas", "karate", "katzenkrieger", "tanjian",
           "elementare", "bierschuettler"}),
 "Naja, ueber die kann man nicht viel sagen.","sagt: ");

// Chaosrattenquest
 
 AddInfo(({"nadel","naehzeug"}),#'nadel,"grollt: ");
 AddInfo(({"catgut","katzendarm","katze","katzenleiche"}),#'katze,"sagt: ");
 AddInfo(({"uwe","uns-uwe"}),"Waere es nach mir gegangen, man haette den "
   "gar nicht hier reingelassen.","grollt: ");
          
// Ende Chaosrattenquest
}


string anforderung()
{
  string s, level;
  if(PL->QueryProp( P_GUILD) != "chaos" )
   return "Um in die Gilde aufgenommen zu werden musst Du mindestens "
          "Stufe 5 in der Abenteurergilde besitzen und 120 Abenteuerpunkte "
          "haben. Es gibt noch weitere Bedingungen auf die Du hingewiesen "
          "wirst, wenn Du versuchst der Gilde beizutreten. Uebrigens "
          "nehmen wir keine Hobbits auf, da diese von den Daemonen "
          "einfach ausgelacht werden. Kein Daemon wuerde sich jemals "
          "etwas von einem Hobbit befehlen lassen. Nur ein einziger "
          "Hobbit hat es jemals geschafft in unsere Gilde einzutreten."; 

  level = PL->QueryProp( P_GUILD_LEVEL);

  s = "Um Deine Stufe zu erhoehen musst Du zuerst alle Sprueche bis zu einem "
      "gewissen Grade beherrschen. Wie gut Du die Sprueche koennen musst, " 
      "verraet Dir Kruuolq, wenn Du ihn nach 'Erhoehung fragst. Danach "
      "musst Du eine Pruefung in der Kampfarena bestehen. ";

  switch(level)
  {
    case 8:
      s += "Als besondere Aufgabe musst Du Kruuolq ein Paar "
           "weisse Handschuhe bringen. Frag ihn mal danach.";
      break;

    case 9:
      s += "Als besondere Aufgabe musst Du die Metzel-Master-Quest machen. "
            "Naeheres darueber verraet Dir Kruuolq.";
      break;
  }
  return s;
}
		

void Attack(object enemy)
{
  object k;
  
  if(k = present_clone(CHAOS_GILDEN_MON("kruuolq"), environment(ME)))

  if(!k->InFight())
  {
    tell_room(environment(ME),"Hutschat ruft: Kruuolq hilf mir! Ich werde "
              "angegriffen!\n");
    
    k->Kill(enemy);
  }
  return ::Attack(enemy);
}


string stufen()
{
  string blub;
  int stufe;

  blub  = "";
  stufe = PL->QueryProp( P_GUILD_LEVEL);

  if(PL->QueryProp(P_GUILD) == "chaos")
    blub = "\nDu hast die Gildenstufe "+stufe+".\n";

  return "sagt: Es gibt 11 Gildenstufen:\n"+
  " 1. Kleiner Chaot                 #  kleine Chaotin\n"+
  " 2. Chaot                         #  Chaotin\n"+
  " 3. Wahnwitziger                  #  Wahnwitzige\n"+
  " 4. Kaempfer des Chaos            #  Kaempferin des Chaos\n"+
  " 5. finsterer Chaos-Kaempfer      #  finstere Chaos-Kaempferin\n"+
  " 6. Krieger des Chaos             #  Amazone des Chaos\n"+
  " 7. finsterer Chaos-Krieger       #  finstere Chaos-Amazone\n"+
  " 8. Daemonen-Beschwoerer          #  Daemonen-Beschwoererin\n"+
  " 9. Dunkelmagier des Chaos        #  Dunkelmagierin des Chaos\n"+
  "10. Schwarzmagier des Chaos       #  Schwarzmagierin des Chaos\n"+
  "11. Verbreiter des CHAOS          #  Verbreiterin des CHAOS\n"+blub;
}

void make_notes(object wer)
{
  if (find_call_out("make_notes_and_disappear") == -1)
    call_out("make_notes_and_disappear",2,wer);
}

void make_notes_and_disappear(object wer)
{
   if (objectp(wer) && environment(wer) == environment())
   {
     tell_object(wer,"Hutschat schaut Dich zerstreut an und macht muerrisch "
                     "Notizen.\n");
     tell_room(environment(),"Hutschat schaut "+wer->name(WEN)+
               " zerstreut an und macht muerrisch Notizen.\n",({wer}));
   }
//   move(C_SWIFT_ROOM("cl2_hutschatraum"),M_GO,"nach Suedwesten");
}
