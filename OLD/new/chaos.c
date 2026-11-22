// Letzte Aenderung:    Datum   : 25.4.98   
//                      Uhrzeit : 4.32 
//                      Magier  : Bierchen           


inherit  "/std/gilde";
inherit "/std/gilden_ob";
#include <properties.h>
#include <rooms.h>
#include <wizlevels.h>
#include <language.h>
#include <defines.h>
#include <moving.h>
#include <new_skills.h>
#include "/gilden/files.chaos/gilde.h"
#include "/p/daemon/ch.h"


void create() {
  ::create();
SetProp( P_LIGHT, 1);
SetProp( P_INDOORS, 1);
SetProp( P_INT_SHORT, "Die Gilde der Krieger des Chaos");
SetProp( P_INT_LONG, 
"Dies ist der Verwaltungsraum der Gilde. Hier werden die Antraege auf\n"
+"Aufnahme in die Gilde bearbeitet oder das Lernen der Zaubersprueche\n"
+"ueberwacht. Der Raum ist recht schlicht gehalten. Die lange Theke \n"
+"gegenueber dem Eingang ist das einzige Moebelstueck. Auf dem Boden\n"
+"liegt eine schaebige Top-Liste.\n" );
AddDetail(({ "antrag", "antraege" }),
"Frag einfach mal Hutschat aus, er bearbeitet diese Antraege.\n");
AddDetail(({ "raum", "verwaltungsraum" }),
"Dies ist der wichtigste Raum der Gilde.\n");
AddDetail( "gilde",
"Diese Gilde ist wohl eine der besten Gilden des MorgenGrauen!\n");
AddDetail(({ "moebelstueck", "moebel" }),
"Der Raum ist bis auf die lange Theke voellig leer.\n");
AddDetail(({ "wand", "waende" }),
"An den kahlen Waenden haengt eine Liste aller Mitglieder der Gilde.\n"
+"Ausserdem haengt dort ein Zettel.\n");
AddDetail( "liste",
"Du kannst die Liste lesen.\n");
AddDetail( "zettel",
"Auf dem Zettel stehen die neusten Aenderungen, die in der Gilde\n"
+"vorgenommen worden sind.\n");
AddReadDetail( "zettel", "@@my_zettel@@" );
AddReadDetail( "liste", "@@my_liste@@" );
AddDetail(({ "boden", "steinboden" }),
"Du stehst auf einem schlichten Steinboden und teilweise noch auf einer\n"
+"schaebigen und dreckigen Top-Liste.\n" );
AddDetail(({ "topliste", "top-liste" }),
"Ueber diese Top-Liste sind schon viele Leute gelaufen. Sie scheint wenig\n"
+"Beachtung zu finden.\n");
AddReadDetail(({ "top-liste", "topliste" }),
"@@my_top_list@@" );
AddDetail(({ "gestein", "stein" }),
"Der Boden, die Decke und die Waende bestehen aus einem glatten, hellen\n"
+"Gestein.\n");
AddDetail( "decke",
"Die schlichte Decke besteht aus einem hellen Gestein.\n");
AddDetail( "theke",
"Hinter der langen Theke verrichtet normalerweise Hutschat seine Arbeit.\n");
 // SetProp(P_GUILD_DEFAULT_SPELLBOOK,"chaos_sp");
  SetProp(P_GUILD_DEFAULT_SPELLBOOK,"chaos_sp");
  
  SetProp(P_GUILD_RESTRICTIONS,
   ([ P_LEVEL: 5, P_QP: 120, SR_GOOD:-200, P_XP:8000, 
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
    11 : "der Idiot des Chaos",
    12 : "der Erzmeister des Chaos"
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
    11 : "die Idiotin des Chaos",
    12 : "die Erzmeisterin des Chaos"
     ]));
   SetProp(P_GUILD_LEVELS,
  ([ 1 : ([ P_LEVEL: 5, P_QP : 120, SR_GOOD:-150  ]),
     2 : ([ P_LEVEL: 6, SR_GOOD:100, 
    SR_FUN: "LevelTestFun2" ]),
     3 : ([ P_LEVEL: 8, SR_GOOD:-50, 
    A_INT:7, A_CON:8, 
    SR_FUN: "LevelTestFun3" ]),
     4 : ([ P_LEVEL: 10, SR_GOOD:-150, 
    SR_FUN : "LevelTestFun4" ]),
     5 : ([ P_LEVEL: 12, SR_GOOD:-200,
    A_INT:12,
    SR_FUN : "LevelTestFun5" ]),
     6 : ([ P_LEVEL: 14, SR_GOOD:-250, 
    SR_FUN : "LevelTestFun6" ]),
     7 : ([ P_LEVEL: 16, SR_GOOD:-350, 
    A_INT:15,
    SR_FUN : "LevelTestFun7" ]),
     8 : ([ P_LEVEL: 18, SR_GOOD:-500, 
     A_CON:15, A_DEX:13, A_STR:14,   
    SR_FUN : "LevelTestFun8" ]),
     9 : ([ P_LEVEL: 20, SR_GOOD:-600, 
    SR_FUN : "LevelTestFun9" ]),
    10 : ([ P_LEVEL: 27, SR_GOOD:-750, 
    A_CON:19, A_STR:17, A_DEX:17, A_INT:17, P_QP: 1650,
    SR_FUN : "LevelTestFun10" ]),
    11 : ([ P_LEVEL: 35, P_QP : 1900, SR_GOOD:-900, 
    A_CON:20, A_STR:19, A_DEX:19, A_INT:20,
    SR_FUN : "LevelTestFun11" ])
     ]) ); 
  AddSpell( "nachtsicht" );
  AddSpell( "dunkelheit" );          
  AddSpell( "chaosruestung");
  AddSpell( "kontrolle" );
  AddSpell( "bannzauber" );
  AddSpell( "schutz" );
  AddSpell( "intarbir" );
  AddSpell( "chaosball" );
  AddSpell( "chaosschaden" );
  AddSpell( "verbanne" ); 
  AddSpell( "binde" );
  AddSpell( "daemonenheilung" );
  AddSpell( "kruftur" );
  AddSpell( "ombatis" );
  AddSpell( "irkitis" );
  AddSpell( "finsternis" );          
  AddSpell( "harkuhu" );
  AddSpell( "graiop" );
  AddSpell( "flaxtri" );
  AddSpell( "tutszt" );
  AddSpell( "yrintri" );
  AddSkill( SK_NIGHTVISION, ([ SI_SKILLFUNC:"Nightvision" ]) );
  AddCmd(({"tritt","trete"}),"bei_oder_aus_treten");
  AddCmd(({ "lerne", "lern" }), "OwnLearnSpell" );
  AddCmd(({ "gruess", "gruesse" }), "argl" );
  AddCmd(({ "melde", "meld" }), "melde_duell" );
  AddItem( CHAOS_GILDEN_MON( "kruuolq"), REFRESH_REMOVE );
  AddItem( CHAOS_GILDEN_MON( "hutschat"),  REFRESH_REMOVE);
  AddExit( "osten", CHAOS_GILDEN_ROOM( "challe" ));
  AddSpecialExit("nordwesten","nordwesten");
  SetProp(P_NAME,"Kruuolq");
  SetProp(P_ARTICLE,0);
  catch(CHMASTER->join("Chaos", this_object()));
}
int nordwesten(){
  if(this_player()->QueryProp(P_GUILD)!="chaos"){
    write("Dieser Raum ist nur fuer Gildenmitglieder!\n");
    return 1;
  }
  this_player()->move(CHAOS_GILDEN_ROOM( "cbibo" ),M_GO|M_NOCHECK);
  return 1;
}
string my_liste(){ return CHAOS_GILDEN_MASTER->Liste(); }

string my_top_list()
{
CHAOS_GILDEN_MASTER->BerechneTopWert(this_player());
this_player()->more( CHAOS_GILDEN_OBJ( "cliste" ));
return "";
}



string my_zettel()
{
this_player()->more( "/players/zardoz/texte/g_news" );
return "";
}

int argl()
{
write( "Sind wir hier bei den Karatekas???\n");
return 1;
}


int austreten()
{
  object haut, hut;
  if( !hut = present( "hutschat", this_object()))
  {
  write( "Hutschat ist nicht da. Ohne ihn laeuft hier gar nichts.\n");
  return 1;
  }
  write( "Du musst wissen, was Du tust.\n");
  this_player()->SetProp( P_GUILD_LEVEL, 0);
  CHAOS_GILDEN_MASTER->LoescheMitglied( getuid(this_player()));
  hut->Zeitung( (this_player()->QueryProp(P_GENDER)==2?"Bloede EX-Chaotin":
    "Dummer EX-Chaot")+" ist ausgetreten", "Ich muss euch leider mitteilen, "
    +"dass "+capitalize(getuid(this_player()))+" heute auf schaendlichste Art "+
    "und Weise aus der Gilde der Chaoten ausgetreten ist. Leider darf ich nicht "+
    "zum Playerkill aufrufen, aber ihr wisst, was zu tun ist!\n\nHutschat, "+
    "der Verwalter des Chaos.\n" );
 // log_file( "zardoz/gilde", capitalize(getuid(this_player()))+" ist am "+
 //   dtime(time())+" ausgetreten.\n");
   LOG("-austritt",this_player()->query_real_name()+
   " ist ausgetreten. Sofort Zappen!.");
         
  if( haut = present( "\nchaos_ruestung", this_player()))
    destruct(haut);
  if( haut = present( "chaos-ring", this_player()))
    haut->remove();
  return ::austreten();
}


int beitreten()
{
  object hut;
  if( !hut = present( "hutschat", this_object()))
  {
  write( "Hutschat ist nicht da. Ohne ihn laeuft hier gar nichts.\n");
  return 1;
  }
  if( this_player()->QueryProp( P_GUILD) == "chaos" )
  {
  write( "Du bist schon ein Mitglied dieser Gilde.\n");
  return 1;
  }
  if(::beitreten() < 0) return 1;
  hut->Zeitung( "Neues Mitglied der Chaosgilde", 
  "Dass "+capitalize(getuid(this_player()))+" als Autor genannt wird, ist "
  "nicht zufaellig, aber voellig unerheblich.\n\nMitteilung von Hutschat, "
  "dem Verwalter des Chaos:\n"+capitalize(getuid(this_player()))+" wurde von "
  "mir heute in die Chaosgilde aufgenommen. Wuenschen wir "+
  this_player()->QueryPronoun(WEM)+" alles Boese! Moegen die Daemonen "+
  "mit "+this_player()->QueryPronoun(WEM)+" sein.\n\nHutschat, der Verwalter "
  +"des Chaos.");
 // log_file( "zardoz/gilde", capitalize(getuid(this_player()))+" ist am "+
 //   dtime(time())+" in die Gilde eingetreten.\n");
  LOG("-eintritt",this_player()->query_real_name()+
  " ist eingetreten. Eine gute Wahl!");
        
  write( "Hallo in der unglaublichen Gilde der Kaempfer des Chaos!\n");
  CHAOS_GILDEN_MASTER->NeuesMitglied( getuid( this_player()));
this_player()->ModifySkill( SK_NIGHTVISION, QuerySkill( SK_NIGHTVISION), 0, "chaos" );
return 1;
}



advance(string str)
{
  mixed r1, r2;
  notify_fail(
  "Was moechtest Du erhoehen: Deine Spielerstufe oder Deine Gildenstufe?\n"+
  "Syntax: erhoehe <spielerstufe | gildenstufe>\n"+
  "oder:   erhoehe <spieler      | gilde>\n");
  if( !present( "hutschat", this_object()))
  {
  write( "Hutschat ist nicht da. Ohne ihn laeuft hier gar nichts.\n");
  return 1;
  }
  if(!str)return 0;
  if(str!="spielerstufe"&&str!="spieler"&&str!="gilde"&&str!="gildenstufe")
   return 0;
  if(str=="gilde"||str=="gildenstufe")
  {
  if( this_player()->QueryProp( P_GUILD_LEVEL) >= 11 )
    {
    CHAOS_GILDEN_MASTER->LoescheFuerMeister(getuid(this_player()));
    write( "Du bist doch schon ein Meister des Chaos.\n");
    return 1;
    }
  r1=gilden_ob::try_advance();
  if(r1)
    {
    adjust_title(this_player());
    write("Wie hast Du das denn geschafft? Wen hast Du bestochen?\n");
    //log_file( "zardoz/gilde", capitalize(getuid(this_player()))+
    //" hat die Stufe auf "+this_player()->QueryProp(P_GUILD_LEVEL)+" am "+
    //      dtime(time())+" erhoeht.\n");
    LOG("-erhoehung",this_player()->query_real_name()+
    " hat auf "+this_player()->QueryProp(P_GUILD_LEVEL)+" erhoeht.");
            
    if( this_player()->QueryProp( P_GUILD_LEVEL) >= 11)
      CHAOS_GILDEN_MASTER->LoescheFuerMeister(getuid(this_player()));
    return r1;
    }
  }
  
  else 
  {
  r2= gilde::advance();
  return r2;
  }
  return r1;
}


OwnLearnSpell(string str)
{
  if( !present( "kruuolq", this_object()))
  {
  write( "Der Meister Kruuolq ist nicht da. Nur er kann Dir die Zaubersprueche\n"
  +"beibringen.\n");
  return 1;
  }
  notify_fail("Was moechtest Du hier lernen?\n");
  if(!str)
  {
    write( "Du kannst Zaubersprueche lernen oder die Beschwoerung von Daemonen.\n"
      +"Welche Sprueche es gibt, kannst Du Dir mit 'lerne <spruch|daemon>' anschauen.\n");
    return 1; 
  }
  if( str == "spruch" || str == "zauberspruch" )
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
  if( str == "daemon" || str == "daemonen" || str == "beschwoerung" )
  {    
  write(" Du kannst folgende Daemonen beschwoeren:\n"+
  "   Intarbir       : Ab Gildenstufe 4.\n"+
  "   Kruftur        : Ab Gildenstufe 5.\n"+
  "   Ombatis        : Ab Gildenstufe 6.\n"+
  "   Irkitis        : Ab Gildenstufe 7.\n"+
  "   Harkuhu        : Ab Gildenstufe 8.\n"+
  "   Graiop         : Ab Gildenstufe 9.\n"+
  "   Flaxtri        : Ab Gildenstufe 10.\n"+
  "   Tutszt         : Ab Gildenstufe 11.\n"+
  "   Yrintri        : Nur fuer den Erzmeister.\n"+
  "Du kannst ja mal Kruuolq nach den einzelnen Daemonen befragen.\n");
  return 1;
  }
  if( str == "daemonenheilung" )
  {
    write( "Guter Versuch! Aber den Spruch gibt es noch nicht!\n");
    return 1;
  }
  return LearnSpell(str);
}

string LevelTestFun1( object pl)
{
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
if( !pl->QueryProp( CHAOS_KAMPF_BESTANDEN ))
  {
  pl->SetProp( CHAOS_PRUEFUNG, 1); 
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
  }
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun2(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 2))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun3(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 3))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun4(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 4))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun5(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 5))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun6(object pl)
{
mixed bla;
int zeit;     
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 6))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun7(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 7))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun8(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 8))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun9(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( !IS_SEER( pl)) return "Du musst ein Seher sein!\n";
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
if( !CHAOS_GILDEN_MASTER->QueryAufgabe( getuid(this_player()), "chaoshandschuhe"))
  return "Du kannst erst deine Stufe erhoehen, wenn du Kruuolq ein Paar gute\n"
  +"Chaoshandschuhe gebracht hast.\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 9))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun10(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
if( !CHAOS_GILDEN_MASTER->QueryAufgabe( getuid(this_player()), "metzel_master_quest"))
  return "Du kannst erst deine Stufe erhoehen, wenn Du die Metzel-Master-Quest gemacht\n"
  +"hast. Frage dazu einfach mal Kruuolq.\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 10))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
pl->SetProp( CHAOS_PRUEFUNG, 0);
return 0;
}

string LevelTestFun11(object pl)
{
mixed bla;
bla = CHAOS_GILDEN_MASTER->ErhoehungsCheck(pl);
if( bla) return bla;
if( pl->QueryProp( P_FROG)) return "Igitt! Ein Frosch! Hau bloss ab!\n";
pl->SetProp( CHAOS_PRUEFUNG, 1); 
if( !CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 11))
  return "Du musst erst noch einen Kampf in der Kampfarena gewinnen.\n";
return 0;
}

int Nightvision( object user, string skill, mapping info)
{
  int t;
  object env;
  t = user->QueryProp( CHAOS_GILDEN_NACHTSICHT );
  if( !t ) return 0;
  if( t < time())
  {
    tell_object(user, "Die Magie Deiner Augen laesst nach und verschwindet.\n");
    user->SetProp( CHAOS_GILDEN_NACHTBLIND, time() + 65 - 
        user->QueryProp( P_GUILD_LEVEL) * 5 );
    user->SetProp( CHAOS_GILDEN_NACHTSICHT, 0);
    return 0;
  }
  if( !env = environment(user)) return 0;
  if( env->_query_total_light() < 1 - (1+user->QueryProp( P_GUILD_LEVEL))/2)
  {
    tell_object( user, "Hier ist es fuer Deine Nachtsicht zu dunkel.\n");
    return 0;
  }
  if( env->_query_total_light() > 0) return 0;
  return 1;
}


int melde_duell(string str)
{
  int zeit;
  notify_fail( "Willst Du Dich fuer einen Erzmeisterkampf anmelden?\n");
  if( !str) return 0;
  if( str != "kampf an" && str != "erzmeisterkampf an" && str != "mich an"
    && str != "dich an" ) return 0;
  if( this_player()->QueryProp( P_GUILD) != "chaos" )
  {
    write( "Es koennen natuerlich nur Chaoten am Kampf teilnehmen!\n");
    return 1;
  }
  if( this_player()->QueryProp( P_GUILD_LEVEL) < 11) 
  {
    write( "Du kannst Dich nicht fuer einen Kampf anmelden!\n");
    return 1;
  }
  if( IS_LEARNER( this_player()))
  {
    write( "Magier duerfen nicht daran teilnehmen!\n");
    return 1;
  }
  
  zeit = CHAOS_GILDEN_MASTER->query_duellzeit();
  if( !sizeof(CHAOS_GILDEN_MASTER->query_duellier()))
  {
    if( zeit > time())
    {
      write( "Das naechste Duell kann erst nach "+dtime(zeit)+" stattfinden!\n");
      return 1;
    }
    write( "Du meldest einen neuen Erzmeisterkampf an! Das Duell beginnt in\n"
      +"einer Stunde. Begib Dich bis dahin ins Nichts!\n" );
    CHAOS_GILDEN_MASTER->set_duellzeit( time()+3600 );
    CHAOS_GILDEN_MASTER->AddKaempfer(this_player());
    CHAOS_GILDEN_MASTER->tell_meister( break_string( 
      capitalize(getuid(this_player()))+ " hat einen Erzmeisterkampf angemeldet. "+
      "Dieser Kampf beginnt in einer Stunde. Wer mitmachen will, meldet sich "+
      "bitte in der Gilde an.", 78, "Kruuolq an alle Meister: " ));
    call_out( "count_down", 600, 0 );
    return 1;
  }
  if( time() > zeit ) 
  {
    write( "Deine Anmeldung kommt leider zu spaet.\n");
    return 1;
  }
  if( !CHAOS_GILDEN_MASTER->AddKaempfer(this_player()))
  {
    write( "Du bist schon angemeldet.\n");
    return 1;
  }
  write( "Du meldest Dich fuer das Erzmeisterduell an!\n"+
    "Das Duell findet in "+time2string( "%m %M", zeit-time())+" statt.\n"
    +"Begib Dich bitte bis dahin ins Nichts.\n");
  CHAOS_GILDEN_MASTER->tell_meister( break_string( capitalize(this_player()->name())+
    " hat sich ebenfalls fuer den Erzmeisterkampf angemeldet!", 78, 
    "Kruuolq an alle Meister: "));
  return 1;
}


void count_down(int zahl)
{
  string zeit;
  if( zahl == 5 )
  {
   CHAOS_GILDEN_MASTER->tell_meister( break_string( "Der Erzmeisterkampf "+
      "beginnt jetzt! Es werden keine Anmeldungen mehr entgegengenommen!",78,
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
  CHAOS_GILDEN_MASTER->tell_meister( break_string( "Achtung! Der Erzmeister"+
    "kampf findet in "+zeit+" Minuten statt! Es sind noch Anmeldungen moeglich!",
    78, "Kruuolq an alle Meister: " )); 
  zahl ++;
  call_out( "count_down", 600, zahl);    
}
   
   
int GuildRating(object pl)
{
  mapping ski;
  string *sk;
  int i, cnt, sum;
  closure qsa;
  
  if (!IsGuildMember(pl)||!query_once_interactive(pl))
    return 0;

  if (!(ski = QueryProp(P_GUILD_SKILLS)) ||
      !(qsa = symbol_function("QuerySkillAbility",pl)))
    return 0;

  sk = m_indices(ski);
  cnt = sizeof(ski);
  
  for (i=cnt-1, sum=0; i>=0; i--)
    sum += funcall(qsa, sk[i]);

  sum = sum/(cnt-1);
  if (sum < 0)
    sum = 0;
  else if (sum > MAX_ABILITY)
    sum = MAX_ABILITY;
  
  return pl->SetProp(P_GUILD_RATING, sum);
}


