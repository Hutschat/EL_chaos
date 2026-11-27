// gilde.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet
// 27.11.2026 It@Efferdland             wieder lauffähig, ohne Arena
// 27.11.2026 It@Efferdland             keine Kampfprüfung bis Stufe 11

#include "def.h"

inherit  "/std/gilde";
inherit  "/std/gilden_ob";

#define FROSCH_TEXT\
"Igitt! Ein Frosch! Hau bloss ab!\n"

protected void create()
{
  ::create();
  SetProp(P_LIGHT, 1);
  SetProp(P_INDOORS, 1);
  SetProp(P_INT_SHORT, "Die Gilde der Krieger des Chaos");
  SetProp(P_INT_LONG,
  "Dies ist der Verwaltungsraum der Gilde. Hier werden die Antraege auf "
  "Aufnahme in die Gilde bearbeitet oder das Lernen der Zaubersprueche "
  "ueberwacht. Der Raum ist recht schlicht gehalten. Die lange Theke "
  "gegenueber dem Eingang ist das einzige Moebelstueck. Auf dem Boden "
  "liegt eine schaebige Top-Liste.");

  AddDetail(({"antrag","antraege"}),
  "Frag einfach mal Hutschat aus, er bearbeitet diese Antraege.");

  AddDetail(({"raum","verwaltungsraum"}),
  "Dies ist der wichtigste Raum der Gilde.");

  AddDetail("gilde",
  "Diese Gilde ist wohl eine der besten Gilden im Efferdland!");

  AddDetail(({"moebelstueck","moebel"}),
  "Der Raum ist bis auf die lange Theke voellig leer.");

  AddDetail(({"wand","waende"}),
  "An den kahlen Waenden haengt eine Liste aller Mitglieder der Gilde. "
  "Ausserdem haengt dort ein Zettel.");

  AddDetail("liste",
  "Du kannst die Liste lesen.");

  AddDetail("zettel",
  "Auf dem Zettel stehen die neusten Aenderungen, die in der Gilde "
  "vorgenommen worden sind.");

  AddReadDetail( "zettel", "@@my_zettel@@" );
  AddReadDetail( "liste", "@@my_liste@@" );

  AddDetail(({"boden","steinboden"}),
  "Du stehst auf einem schlichten Steinboden und teilweise noch auf einer "
  "schaebigen und dreckigen Top-Liste.");

  AddDetail(({"topliste","top-liste"}),
  "Ueber diese Top-Liste sind schon viele Leute gelaufen. Sie scheint wenig "
  "Beachtung zu finden.");

  AddReadDetail(({"top-liste","topliste"}),
  "@@my_top_list@@" );

  AddDetail(({"gestein","stein"}),
  "Der Boden, die Decke und die Waende bestehen aus einem glatten, hellen "
  "Gestein.");

  AddDetail("decke",
  "Die schlichte Decke besteht aus einem hellen Gestein.");

  AddDetail("theke",
  "Hinter der langen Theke verrichtet normalerweise Hutschat seine "
  "Arbeit.");

//  SetProp(P_GUILD_DEFAULT_SPELLBOOK,"chaos/spellbook");

  SetProp(P_GUILD_ENTRY_RESTR,
  ([
     P_LEVEL: 5,
     P_QP:    120,
     SR_GOOD:-200,
     P_XP:    8000,
     SR_FUN: "LevelTestFun1",
     SR_EXCLUDE_RACE:({ "Hobbit" })
   ]));

  SetProp(P_GUILD_MALE_TITLES,
  ([ 1 : "der kleine Chaot",
     2 : "der Chaot",
     3 : "der Wahnwitzige",
     4 : "der Kaempfer des Chaos",
     5 : "der finstere Chaos-Kaempfer",
     6 : "der Krieger des Chaos",
     7 : "der finstere Chaos-Krieger",
     8 : "der Daemonen-Beschwoerer",
     9 : "der Dunkelmagier des Chaos",
    10 : "der Schwarzmagier des Chaos",
    11 : "der Meister des Chaos",
    12 : "der Erzmeister des Chaos",
    13 : "der einfache Krolkr'Bratruu-Anhaenger",
    14 : "der Krolkr'Bratruu-Anhaenger",
    15 : "",
    16 : "",
    17 : "",
     ]));
  SetProp(P_GUILD_FEMALE_TITLES,
  ([ 1 : "die kleine Chaotin",
     2 : "die Chaotin",
     3 : "die Wahnwitzige",
     4 : "die Kaempferin des Chaos",
     5 : "die finstere Chaos-Kaempferin",
     6 : "die Amazone des Chaos",
     7 : "die finstere Chaos-Amazone",
     8 : "die Daemonen-Beschwoererin",
     9 : "die Dunkelmagierin des Chaos",
    10 : "die Schwarzmagierin des Chaos",
    11 : "die Meisterin des Chaos",
    12 : "die Erzmeisterin des Chaos",
    13 : "die einfache Krolkr'Bratruu-Anhaengerin",
    14 : "die Krolkr'Bratruu-Anhaengerin",
    15 : "",
    16 : "",
    17 : "",

     ]));
   SetProp(P_GUILD_LEVEL_RESTR,
   ([ 1 :([
            P_LEVEL:  5,
            P_QP :    120,
            SR_GOOD: -150
         ]),
     2 : ([
            P_LEVEL:  6,
            SR_GOOD: -100,
            SR_FUN:   "LevelTestFun2"
         ]),
     3 : ([
            P_LEVEL:  8,
            SR_GOOD: -50,
            A_INT:    7,
            A_CON:    8,
            SR_FUN:   "LevelTestFun3"
         ]),
     4 : ([
            P_LEVEL:  10,
            SR_GOOD: -150,
            SR_FUN :  "LevelTestFun4"
         ]),
     5 : ([
            P_LEVEL:  12,
            SR_GOOD: -200,
            A_INT:    12,
            SR_FUN : "LevelTestFun5"
         ]),
     6 : ([ P_LEVEL:  14,
            SR_GOOD: -250,
            SR_FUN :  "LevelTestFun6"
         ]),
     7 : ([
            P_LEVEL:  16,
            SR_GOOD: -350,
            A_INT:    15,
            SR_FUN :  "LevelTestFun7"
         ]),
     8 : ([
            P_LEVEL:  18,
            SR_GOOD: -500,
            A_CON:    15,
            A_DEX:    13,
            A_STR:    14,
            SR_FUN :  "LevelTestFun8"
         ]),
     9 : ([
            P_LEVEL:  20,
            SR_GOOD: -600,
            SR_FUN :  "LevelTestFun9"
         ]),
    10 : ([
            P_LEVEL:  27,
            SR_GOOD: -750,
            A_CON:    19,
            A_STR:    17,
            A_DEX:    17,
            A_INT:    17,
            P_QP:     1650,
            SR_FUN :  "LevelTestFun10"
         ]),
    11 : ([
            P_LEVEL:  35,
            P_QP :    1900,
            SR_GOOD: -900,
            A_CON:    20,
            A_STR:    19,
            A_DEX:    19,
            A_INT:    20,
            SR_FUN : "LevelTestFun11" ]),
  ]));
  AddSpell("nachtsicht");
  AddSpell("dunkelheit");
  AddSpell("chaosruestung");
  AddSpell("kontrolle");
  AddSpell("bannzauber");
  AddSpell("schutz");
  AddSpell( "intarbir" );
  AddSpell( "chaosball" );
  AddSpell( "chaosschaden" );
  AddSpell( "verbanne" );
  AddSpell( "binde" );
  AddSpell( "kruftur" );
  AddSpell( "irkitis" );
  AddSpell( "finsternis" );
  AddSpell( "harkuhu" );
  AddSpell( "graiop" );
  AddSpell( "flaxtri" );
  AddSpell( "tutszt" );
  AddSpell( "yrintri" );
  AddSkill( SK_NIGHTVISION, ([ SI_SKILLFUNC:"Nightvision" ]) );
  AddCmd(({"tritt","trete"}),"bei_oder_aus_treten");
  AddCmd(({"lerne", "lern" }), "OwnLearnSpell" );
  AddCmd(({"gruess", "gruesse" }), "argl" );
  // Erzmeisterkampf in der Arena: Die Arena entfällt, Ersatz offen
  // AddCmd(({"melde", "meld" }), "melde_duell" );
  AddItem( CHAOS_GILDEN_MON( "kruuolq"), REFRESH_REMOVE );
  AddItem( CHAOS_GILDEN_MON( "hutschat"),  REFRESH_REMOVE);
  // Ausgänge kommen mit den neuen Räumen der Burg
}

string my_liste(){ return CHAOS_GILDENMASTER->Liste(); }

string my_top_list()
{
  CHAOS_GILDENMASTER->BerechneTopWert(PL);
  PL->more(CHAOS_GILDEN_OBJ("cliste"));
  return "";
}

string my_zettel()
{
  PL->more( CHAOS_GILDEN_TXT("g_news") );
  return "";
}

int argl()
{
  write( "Sind wir hier bei den Karatekas???\n");
  return 1;
}

varargs int austreten()
{
  object ob;

  if(!ob = present_clone(CHAOS_GILDEN_MON("hutschat"),ME))
  {
    write( "Hutschat ist nicht da. Ohne ihn laeuft hier gar nichts.\n");
    return 1;
  }
  write("Du musst wissen, was Du tust.\n");

  PL->SetProp(P_GUILD_LEVEL, 0);

  CHAOS_GILDENMASTER->LoescheMitglied( getuid(PL));

  ob->Zeitung((PL->QueryProp(P_GENDER)==2?"Bloede EX-Chaotin":
    "Dummer EX-Chaot")+" ist ausgetreten", "Ich muss euch leider mitteilen, "
    +"dass "+capitalize(getuid(PL))+" heute auf schaendlichste Art "+
    "und Weise aus der Gilde der Chaoten ausgetreten ist. Leider darf ich nicht "+
    "zum Playerkill aufrufen, aber ihr wisst, was zu tun ist!\n\nHutschat, "+
    "der Verwalter des Chaos.\n" );

  if(ob = present_clone(CHAOS_GILDEN_ARMOUR("chaosruestung"),PL))
    destruct(ob);

  if(ob = present_clone(CHAOS_GILDEN_ARMOUR("chaosring"), PL))
    ob->remove();
  return ::austreten();
}

static int beitreten()
{
  object ob;

  if(!ob = present_clone(CHAOS_GILDEN_MON("hutschat"), ME))
  {
    write( "Hutschat ist nicht da. Ohne ihn laeuft hier gar nichts.\n");
    return 1;
  }
  if(PL->QueryProp(P_GUILD) == "chaos" )
  {
    write("Du bist schon ein Mitglied dieser Gilde.\n");
    return 1;
  }
  if(::beitreten() < 0)
    return 1;

  ob->Zeitung("Neues Mitglied der Chaosgilde",
              "Dass "+capitalize(getuid(PL))+" als Autor genannt wird, ist "
              "nicht zufaellig, aber voellig unerheblich.\n\n"
              "Mitteilung von Hutschat, dem Verwalter des Chaos:\n"+
              capitalize(getuid(PL))+" wurde von mir heute in die Chaosgilde "
              "aufgenommen. Wuenschen wir "+
              PL->QueryPronoun(WEM)+" alles Boese! Moegen die Daemonen "
              "mit "+PL->QueryPronoun(WEM)+" sein.\n\nHutschat, der Verwalter "
              "des Chaos.");

  write("Hallo in der unglaublichen Gilde der Kaempfer des Chaos!\n");

  CHAOS_GILDENMASTER->NeuesMitglied(getuid(PL));

  PL->ModifySkill(SK_NIGHTVISION,QuerySkill(SK_NIGHTVISION), 0, "chaos");

  return 1;
}



static int advance(string str)
{
  mixed r1, r2;
  notify_fail(
  "Was moechtest Du erhoehen: Deine Spielerstufe oder Deine Gildenstufe?\n"+
  "Syntax: erhoehe <spielerstufe | gildenstufe>\n"+
  "oder:   erhoehe <spieler      | gilde>\n");

  if(!present_clone(CHAOS_GILDEN_MON("hutschat"), ME))
  {
    write( "Hutschat ist nicht da. Ohne ihn laeuft hier gar nichts.\n");
    return 1;
  }
  if(!str) return 0;

  if(str!="spielerstufe" && str!="spieler" && str!="gilde" &&
     str!="gildenstufe")
   return 0;

  if(str=="gilde" || str=="gildenstufe")
  {
    if(PL->QueryProp(P_GUILD_LEVEL) >= 11)
    {
      CHAOS_GILDENMASTER->LoescheFuerMeister(getuid(PL));
      write( "Du bist doch schon ein Meister des Chaos.\n");
      return 1;
    }
    r1 = gilden_ob::try_advance();

    if(r1)
    {
      adjust_title(PL);
      write("Wie hast Du das denn geschafft? Wen hast Du bestochen?\n");

      if(PL->QueryProp( P_GUILD_LEVEL) >= 11)
        CHAOS_GILDENMASTER->LoescheFuerMeister(getuid(PL));

      return r1;
    }
  }
  else
  {
    r2 = gilde::advance(str);
    return r2;
  }
  return r1;
}


void CreateChaot13( object pl)
{
  if(!pl) return ;
  pl->ModifySkill("chaosschaden",([ SI_SPELLCOST: 15 ]),0,"chaos");
}


/* Erhoehungsfunktion fuer die Chaos-Gilde in der Daemonendimension. */
string c_advance( object pl)
{
  string res, msg;
  int lvl;

  if(!pl)
    return "Oeh, wer sollte nochmal befoerdert werden? ";

  if(pl->QueryProp(P_GUILD) != "chaos" )
    return "Oeh, Du bist gar kein Chaot! ";

  if((lvl = pl->QueryProp(P_GUILD_LEVEL)) >= 17)
      return "Du hast doch schon den hoechsten Rang, was willst Du mehr? ";
/*
  if (res=check_restrictions(pl ,QueryProp(P_GUILD_LEVELS)[lvl+1]))
  {
    return "Du kannst aus folgendem Grund nicht befoerdert werden: "+res;
  }
*/
  pl->SetProp( P_GUILD_LEVEL, lvl + 1);

  adjust_title(pl);


  msg = capitalize(getuid(pl))+" wurde von mir auf Stufe "+(lvl+1)+" "+
       "befoerdert. ";

  switch( pl->QueryProp( P_GUILD_LEVEL))
  {
     case 13:
       CreateChaot13(pl);
       break;
     case 14:
       break;
  }
  return "Du hast Deine Faehigkeiten genug unter Beweis gestellt und bist "+
         "ab sofort befoerdert. Gratulation! ";
}


int OwnLearnSpell(string str)
{
  if(!present_clone(CHAOS_GILDEN_MON("kruuolq"),ME))
  {
    write("Der Meister Kruuolq ist nicht da. Nur er kann Dir die "
          "Zaubersprueche beibringen.\n");
    return 1;
  }
  notify_fail("Was moechtest Du hier lernen?\n");

  if(!str)
  {
    write(break_string("Du kannst Zaubersprueche lernen oder die "
          "Beschwoerung von Daemonen. Welche Sprueche es gibt, kannst du "
          "dir mit 'lerne <spruch|daemon>' anschauen."));
    return 1;
  }
  if(str == "spruch" || str == "zauberspruch")
  {
    write("Du kannst hier folgende Sprueche lernen:\n"+
    "   Nachtsicht     : Ab Gildenstufe 1.\n"+
    "   Dunkelheit     : Ab Gildenstufe 2.\n"+
    "   Chaosruestung  : Ab Gildenstufe 3.\n"+
    "   Kontrolle      : Ab Gildenstufe 3.\n"+
    "   Bannzauber     : Ab Gildenstufe 4.\n"+
    "   Schutz         : Ab Gildenstufe 4.\n"+
    "   Chaosball      : Ab Gildenstufe 5.\n"+
    "   Chaosschaden   : Ab Gildenstufe 6.\n"+
    "   Verbanne       : Ab Gildenstufe 7.\n"+
    "   Finsternis     : Ab Gildenstufe 8.\n"+
    "   Binde          : Ab Gildenstufe 9.\n\n"+
    "Du kannst ja mal Kruuolq nach den einzelnen Zauberspruechen befragen.\n");

    return 1;
  }
  if(str == "daemon" || str == "daemonen" || str == "beschwoerung")
  {
    write(" Du kannst folgende Daemonen beschwoeren:\n"+
    "   Intarbir       : Ab Gildenstufe 4.\n"+
    "   Kruftur        : Ab Gildenstufe 5.\n"+
    "   Irkitis        : Ab Gildenstufe 7.\n"+
    "   Harkuhu        : Ab Gildenstufe 8.\n"+
    "   Graiop         : Ab Gildenstufe 9.\n"+
    "   Flaxtri        : Ab Gildenstufe 10.\n"+
    "   Tutszt         : Ab Gildenstufe 11.\n"+
    "   Yrintri        : Nur fuer den Erzmeister.\n"+
    "Du kannst ja mal Kruuolq nach den einzelnen Daemonen befragen.\n");

    return 1;
  }
  return LearnSpell(str);
}

// Frösche dürfen nicht aufsteigen. Kampfprüfungen gibt es nur noch
// beim Erzmeisterkampf um Stufe 12.
static mixed frosch_test(object pl)
{
  if(pl->QueryProp(P_FROG))
    return FROSCH_TEXT;

  return 0;
}

string LevelTestFun1( object pl)
{
  if(pl->QueryProp(P_FROG))
    return FROSCH_TEXT;

  return 0;
}

string LevelTestFun2(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun3(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun4(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun5(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla)
    return bla;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun6(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if( bla) return bla;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun7(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun8(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun9(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  if(!IS_SEER(pl))
    return "Du musst ein Seher sein!\n";

  if(pl->QueryProp(P_FROG))
    return FROSCH_TEXT;

  if(!CHAOS_GILDENMASTER->QueryAufgabe(getuid(PL),"chaoshandschuhe"))
    return break_string("Du kannst erst deine Stufe erhoehen, wenn du "
          "Kruuolq ein Paar gute Chaoshandschuhe gebracht hast.");

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun10(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  if(pl->QueryProp(P_FROG))
    return FROSCH_TEXT;

  if(!CHAOS_GILDENMASTER->QueryAufgabe(getuid(PL),"metzel_master_quest"))
    return break_string("Du kannst erst deine Stufe erhoehen, wenn du "
           "die Metzel-Master-Quest gemacht hast. Frage dazu einfach mal "
           "Kruuolq.");

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun11(object pl)
{
  string|int test;
  mixed bla;

  bla = CHAOS_GILDENMASTER->ErhoehungsCheck(pl);

  if(bla) return bla;

  if(pl->QueryProp(P_FROG))
    return FROSCH_TEXT;

  test = frosch_test(pl);

  if(stringp(test))
    return test;

  return 0;
}

string LevelTestFun13(object pl)
{
  return 0;
}

string LevelTestFun14(object pl)
{
  return 0;
}

int Nightvision( object user, string skill, mapping info)
{
  int t;
  object env;

  t = user->QueryProp(CHAOS_GILDEN_NACHTSICHT);

  if(!t)
    return 0;

  if(t < time())
  {
    tell_object(user,
      "Die Magie deiner Augen laesst nach und verschwindet.\n");

    user->SetProp(CHAOS_GILDEN_NACHTBLIND,time() + 65 -
                                          user->QueryProp(P_GUILD_LEVEL) * 5);

    user->SetProp(CHAOS_GILDEN_NACHTSICHT,0);
    return 0;
  }
  if(!env = environment(user))
    return 0;

  if(env->_query_total_light() < 1 - (1+user->QueryProp(P_GUILD_LEVEL))/2)
  {
    tell_object(user, "Hier ist es fuer deine Nachtsicht zu dunkel.\n");
    return 0;
  }
  if(env->_query_total_light() > 0)
    return 0;

  return 1;
}

static int melde_duell(string str)
{
  int zeit;
  notify_fail( "Willst Du Dich fuer einen Erzmeisterkampf anmelden?\n");

  if(!str)
    return 0;

  if(member(({"kampf an","erzmeisterkampf ab","mich an",
              "dich an"}),str) == -1)
    return 0;

  if(PL->QueryProp(P_GUILD) != "chaos")
  {
    write( "Es koennen natuerlich nur Chaoten am Kampf teilnehmen!\n");
    return 1;
  }
  if(PL->QueryProp(P_GUILD_LEVEL) < 11)
  {
    write( "Du kannst Dich nicht fuer einen Kampf anmelden!\n");
    return 1;
  }
  if(IS_LEARNER( PL))
  {
    write( "Magier duerfen nicht daran teilnehmen!\n");
    return 1;
  }

  zeit = (CHAOS_GILDENMASTER->query_duellzeit());

  if(!sizeof(CHAOS_GILDENMASTER->query_duellier()))
  {
    if(zeit > time())
    {
      write("Das naechste Duell kann erst nach "+dtime(zeit)+
            " stattfinden!\n");
      return 1;
    }
    write(break_string("Du meldest einen neuen Erzmeisterkampf an! Das Duell "
          "beginnt in einer Stunde. Begib dich bis dahin ins Nichts!"));

    CHAOS_GILDENMASTER->set_duellzeit( time()+3600 );
    CHAOS_GILDENMASTER->AddKaempfer(PL);
    CHAOS_GILDENMASTER->tell_meister(break_string(capitalize(getuid(PL))+
           " hat einen Erzmeisterkampf angemeldet. Dieser Kampf beginnt in "
           "einer Stunde. Wer mitmachen will, meldet sich bitte in der "
           "Gilde an.",0, "Kruuolq an alle Meister: " ));

    call_out("count_down", 600, 0);

    return 1;
  }
  if(time() > zeit)
  {
    write("Deine Anmeldung kommt leider zu spaet.\n");
    return 1;
  }
  if(!CHAOS_GILDENMASTER->AddKaempfer(PL))
  {
    write("Du bist schon angemeldet.\n");
    return 1;
  }

  write("Du meldest dich fuer das Erzmeisterduell an!\n"+
    "Das Duell findet in "+time2string( "%m %M", zeit-time())+" statt.\n"
    "Begib Dich bitte bis dahin ins Nichts.\n");

  CHAOS_GILDENMASTER->tell_meister(break_string(PL->Name(WER)+
    " hat sich ebenfalls fuer den Erzmeisterkampf angemeldet!",0,
    "Kruuolq an alle Meister: "));

  return 1;
}


void count_down(int zahl)
{
  string zeit;

  if(zahl == 5)
  {
    CHAOS_GILDENMASTER->tell_meister( break_string( "Der Erzmeisterkampf "+
      "beginnt jetzt! Es werden keine Anmeldungen mehr entgegengenommen!",0,
      "Kruuolq an alle Meister: "));

    (CHAOS_GILDEN_ROOM( "a_start"))->start();

    return;
  }
  switch( zahl)
  {
    case 0: zeit = "50";break;
    case 1: zeit = "40";break;
    case 2: zeit = "30";break;
    case 3: zeit = "20";break;
    case 4: zeit = "10";break;
    default: zeit = "Fehler im RZG";break;
  }
  CHAOS_GILDENMASTER->tell_meister(break_string("Achtung! Der "
    "Erzmeisterkampf findet in "+zeit+" Minuten statt! Es sind noch "
    "Anmeldungen moeglich!",0,"Kruuolq an alle Meister: "));

  zahl ++;

  call_out("count_down",600,zahl);
}

int GuildRating(object pl)
{
  mapping ski;
  string *sk;
  int cnt, sum;
  closure qsa;

  if (!IsGuildMember(pl) || !interactive(pl))
    return 0;

  if(!(ski = QueryProp(P_GUILD_SKILLS)) ||
     !(qsa = symbol_function("QuerySkillAbility",pl)))
    return 0;

  sk  = m_indices(ski);
  cnt = sizeof(ski);

  foreach(string tmp:sk)
    sum += funcall(qsa,tmp);

  sum = sum/(cnt-1);

  if (sum < 0)
    sum = 0;
  else if (sum > MAX_ABILITY)
    sum = MAX_ABILITY;

  return pl->SetProp(P_GUILD_RATING, sum);
}
