/* Die Zaubersprueche:

Nachtsicht:
  Man kann im Dunklen sehen. Da die Krieger des Chaos sich gerne
  in dunklen Festungen verborgen halten, koennen sie diesen Spruch
  schon recht frueh.
  SP:10, Level: 1, Dauer: 40 * guild_level
Dunkelheit:
  Macht einen Raum fuer guild_level * 40 Sekunden dunkel. Dies geht nur,
  wenn der Raum nicht schon zu dunkel ist.
  SP: 10, Level: 2, Dauer: 15 * guild_level,
  Max. Dunkelheit: -guild_level/2
Chaosruestung:
  Erschafft eine Ruestung. Diese Ruestung muss kontrolliert werden.
  Die Ruestung hat AT_MISC und normalerweise keinen Ruestungsschutz,
  nur wenn sie besonders gut gelingt. Man braucht die Chaosruestung
  fuer fast alle hoeheren Sprueche der Chaosgilde. Sie muss jeden
  Reset mit dem Kontrolle-Spruch kontrolliert werden. Man kann ihren
  Ruestungschutz kurzzeitig mit dem Schutz-Spruch erhoehen.
  SP: 100, Level: 3
Kontrolle:
  Kontrolliert die Chaosruestung, die sonst den Caster (vielleicht)
  umbringt. Ohne gelungene Kontrolle verliert man Lebenspunkte,
  laeuft wirr umher, wird vielleicht blind, etc. Nach einiger Zeit
  kommt der Chaosdaemon zum Vorschein und greift den Caster an.
  (Laut Statistik von Rochus ist die Chaosruestung mein gefaehrlichstes
  Monster :-))
  SP: 20, Level: 3
Bannzauber:
  Verstaerkt den Schutz eines Bannkreises. Die Werte fuer das Pentagramm
  und den Bannkreis gehen in die Wahrscheinlichkeitsrechnung fuer das
  Beschwoeren von Daemonen mit ein. Der Spruch erhoeht also die
  Wahrscheinlichkeit, dass bei einer Beschwoerung der richtige Daemon
  kommt, und dass dieser nicht aggressiv ist.
  SP: 10, Level: 4, Bannkreisfaktor: 2 * guild_level + 8 * suc
Schutz:
  Verstaerkt den Ruestungsschutz der Chaosruestung fuer kurze Zeit.
  Es gibt zwei Arten dieses Spruches: schutz stark, schutz schwach.
  Der eine Spruch erhoeht die AC der Chaosruestung fuer sehr kurze
  stark, der andere fuer laengere Zeit nur etwas. Zeit und AC sind
  vom guild_level und vom suc abhaengig.
  SP: 20, Level: 4
Chaosball:
  Angriffzauber, der einen zufaelligen Schaden macht. Gelingt der
  Spruch ueberhaupt nicht, dann geht er nach hinten los :-)
  SP: 15, Level: 5, Schaden: 100 + level/27 * random(400);
  Restriktionen: Hands: 2, man muss eine Chaosruestung tragen.
Chaosschaden:
  Legt den Schaden der naechsten 1+level/2 Chaosbaelle fest. Der
  eingestelle Schaden kommt bei einer SI_SKILLABILITY von 10000
  mit 95%iger Wahrscheinlichkeit.
  SP: 20, Level: 6
Chaoskontrolle:
  Aehnlich wie Chaosschaden. Allerdings ist dies eine Kombination eines
  mechanischem- plus einem der uebrigen Schaeden.
  SP: 30, Level: 11
Verbanne:
  Mit dem Spruch kann man selbstbeschworene Daemonen in die
  Daemonendimensionen zurueckschicken, wenn der Daemon sich dem
  nicht widersetzt. Gegen andere Daemonen macht der Spruch einen
  hohen Schaden, allerdings NUR gegen Daemonen.
  SP: 30, Level: 7
Finsternis:
  Betaeubt den Gegner (oder sich selber :-)) Man kann diesen
  Spruch nur alle 15 Minuten sprechen.
  SP: 100, Level: 8, Dauer: A_INT + random( suc/1000)
  Restriktionen: Hands: 2, man muss eine Chaosruestung tragen.
Binde:
  Mit diesem Spruch kann man das magische Band zu einem beschworenen
  Daemonen erneuern. Er folgt einem dann laenger.
  SP: 50, Level: 9
Intarbir:
  Ein Daemon, der ein Monster einschaetzt.
  SP: 5, Level: 4
Bhuturih:
  Ein Daemon, der Spieler findet.
  SP: 15, Level: 6
Kruftur:
  Daemon, der Gegenstaende identifiziert.
  SP: 10, Level: 6
Tyoorthok:
  Ein Daemon, der etwas ueber die eigene Konstitution erzaehlt.
  SP: 18, Level: 7
Irkitis:
  Ein Daemon, der fuer A_INT + suc/1000 Runden mit WC 150 mitkaempft.
  Er greift nur an, wird selbst nicht angegriffen, faengt also keine
  Schlaege des Gegners ab.
  SP:50, Level: 7
Harkuhu:
  Der Daemon kaempft mit WC 0 und faengt 25% aller Attacken
  ab, der Rest wird auf die Enemies des Gegners umgelenkt. Er folgt
  60 * suc/1000 Sekunden lang dem Caster.
  SP:50, Level: 8
Graiop:
  Der Daemon kaempft A_INT +  3 * suc/1000 Kampfrunden mit
  (WC 150). Er faengt 33% aller Attacken ab.
  SP:90, Level: 9
Flaxtri:
  Folgt 3 * suc/10 Sekunden und kaempft solange, bis er stirbt mit
  WC 170 und faengt 50% aller Attacken ab.
  SP:120, Level: 10
Tutszt:
  Der beste Daemon. Er folgt 5 * suc/10 Sekunden und kaempft mit WC 200 und
  faengt 66% aller Attacken ab.
  SP:140, level: 11

Fuer alle Daemonen gilt: Sie folgen nur solange sie leben :-), Es kann
passieren, dass sie ploetzlich den Caster angreifen, dass sie dem Caster
ueberhaupt nicht folgen, dass sie vorzeitig verschwinden, oder dass schon
bei der Beschwoerung ein anderer (dem Caster gegenueber aggressiver)
Daemon erscheint. Dann koennen sie sich waehrend des Kampfes ploetzlich
mit dem Gegner verbuenden und gemeinsam alle Enemies angreifen...

suc : SpellSuccess
*/

#pragma no_clone
#pragma no_inherit

#include "def.h"

inherit CHAOS_GILDEN_OBJ("std/funcs");

mapping daemon;
string *ChaosDamage(object caster, int suc);

inherit "/std/spellbook";

protected void create() {
  ::create();
  SetProp(P_GLOBAL_SKILLPROPS,
      ([
       SI_SPELLFATIGUE:2,
       SI_SKILLLEARN:2,
       OFFSET(SI_SKILLLEARN):2
      ]));
  AddSpell( "chaosball",15,
      ([
       SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:5]),
       SI_SKILLRESTR_USE:([
       P_GUILD_LEVEL : 5,
       SR_FUN:"Funcs_CheckRuestung"]), SI_DIFFICULTY:20
      ]));
  AddSpell( "verbanne", 30,
      ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:7]),
      SI_SKILLRESTR_USE:([
      SR_FUN:"Funcs_CheckRuestung",P_GUILD_LEVEL : 7]),
      SI_DIFFICULTY:50,
      SI_NOMAGIC:100,
      SI_SKILLDAMAGE_TYPE:DT_SOUND
      ]));
  AddSpell( "schutz", 25,
      ([ SI_SKILLRESTR_LEARN:([ P_GUILD_LEVEL:4]),
      SI_SKILLRESTR_USE:([SR_FREE_HANDS:1,
      SR_GOOD:0,
      SR_FUN:"Funcs_CheckRuestung", P_GUILD_LEVEL : 4]),
      SI_DIFFICULTY:40
      ]));
  AddSpell( "dunkelheit",10,
      ([
       SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:2]),
       SI_DIFFICULTY:-10,
       SI_SKILLLEARN:4,
       OFFSET(SI_SKILLLEARN):6
      ]));
  AddSpell( "nachtsicht",10,
      ([
       SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:1]),
       SI_DIFFICULTY:-20,
       SI_SKILLLEARN:4,
       OFFSET(SI_SKILLLEARN):6,
       SI_NOMAGIC:100,
      ]));
  AddSpell( "chaosruestung",95,
      ([
       SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:3]),
       SI_SKILLRESTR_USE:([SR_GOOD:-100,
       SR_FREE_HANDS:2,
       P_GUILD_LEVEL : 3]),
       SI_DIFFICULTY:70,
       SI_SPELLFATIGUE:50,
       OFFSET(SI_SKILLLEARN):10
      ]));
  AddSpell( "kontrolle", 20,
      ([
       SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:3]),
       SI_SKILLRESTR_USE:([SR_FUN:"Funcs_CheckRuestung",
       P_GUILD_LEVEL:3]),
       SI_DIFFICULTY:50,
       SI_SPELLFATIGUE:20,
       OFFSET(SI_SKILLLEARN):5,
       SI_NOMAGIC:100,
      ]));
  AddSpell( "finsternis",100,
      ([
       SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:8]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"Funcs_CheckRuestung",
       SR_GOOD:-300,
       P_GUILD_LEVEL : 8]), SI_DIFFICULTY:120,
       SI_SKILLLEARN:4,
      ]));
  AddSpell( "chaosschaden",20,
      ([
       SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:6]),
       SI_SKILLRESTR_USE:([P_GUILD_LEVEL : 6]),
       SI_DIFFICULTY:20
      ]));
  AddSpell( "chaoskontrolle",20,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:11]),
        SI_SKILLRESTR_USE:([P_GUILD_LEVEL : 11]),
        SI_DIFFICULTY:-10,
       ]));
  AddSpell( "bannzauber",10,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:4]),
        SI_SKILLRESTR_USE:([P_GUILD_LEVEL : 4]),
        SI_DIFFICULTY:-10,
        SI_SPELLFATIGUE:4
       ]));
  AddSpell( "binde", 40,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:9]),
        SI_DIFFICULTY:90,
        SI_SKILLRESTR_USE:([SR_FUN:"Funcs_CheckRuestung",P_GUILD_LEVEL:9]),
        SI_NOMAGIC:100,
        SI_SPELLFATIGUE:10
       ]));
/*    AddSpell( "chaosmaske", 40,
       ([ SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:11]),
       SI_SKILLRESTR_USE:([
       SR_GOOD:-200,P_GUILD_LEVEL:11 ]),
       SI_DIFFICULTY:30,
       SI_SPELLFATIGUE:20
       ]));
*/
  AddSpell(CHAOS_ID_INTARBIR,5,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:4,SR_GOOD:200]),
        SI_SKILLRESTR_USE:([
        SR_FUN:"TestEnvironment",P_GUILD_LEVEL:4 ]),
        SI_DIFFICULTY:-50,
        SI_SPELLFATIGUE:3,
        OFFSET(SI_SKILLLEARN):8
       ]));
  AddSpell(CHAOS_ID_KRUFTUR,10,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:5,SR_GOOD:100]),
        SI_SKILLRESTR_USE:([
        SR_FUN:"TestEnvironment",P_GUILD_LEVEL:5 ]),
        SI_DIFFICULTY:-20,
        SI_SPELLFATIGUE:3,
        OFFSET(SI_SKILLLEARN):6
       ]));
  AddSpell( "bhuturih",15,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:6,SR_GOOD:150]),
        SI_SKILLRESTR_USE:([
        SR_FUN:"TestEnvironment",P_GUILD_LEVEL:6 ]),
        SI_DIFFICULTY:-30,
        SI_SPELLFATIGUE:3,
        OFFSET(SI_SKILLLEARN):7
       ]));
  AddSpell( "tyoorthok",20,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:7,SR_GOOD:100]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:1,P_GUILD_LEVEL:7,
        SR_GOOD:200, SR_FUN:"TestEnvironment" ]),
        SI_DIFFICULTY:20,
        SI_SPELLFATIGUE:10,
        OFFSET(SI_SKILLLEARN):10
       ]));
  AddSpell(CHAOS_ID_IRKITIS,50,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:7,SR_GOOD:300]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,P_GUILD_LEVEL:7,
        SR_GOOD:-100, SR_FUN:"DaemonenTest" ]),
        SI_DIFFICULTY:20,
        SI_SPELLFATIGUE:6
       ]));
  AddSpell(CHAOS_ID_HARKUHU,50,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:8,SR_GOOD:400]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,P_GUILD_LEVEL:8,
        SR_GOOD:-200, SR_FUN:"DaemonenTest"]),
        SI_DIFFICULTY:30,
        SI_SPELLFATIGUE:10
       ]));
  AddSpell(CHAOS_ID_GRAIOP,90,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:9,SR_GOOD:200]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,P_GUILD_LEVEL:9,
        SR_GOOD:-250, SR_FUN:"DaemonenTest" ]),
        SI_DIFFICULTY:50,
        SI_SPELLFATIGUE:15
       ]));
  AddSpell(CHAOS_ID_FLAXTRI,120,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:10,SR_GOOD:-100]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,P_GUILD_LEVEL:10,
        SR_GOOD:-300, SR_FUN:"DaemonenTest" ]),
        SI_DIFFICULTY:80,
        SI_SPELLFATIGUE:20
       ]));
  AddSpell(CHAOS_ID_BALAL,200,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:10,SR_GOOD:-400]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,P_GUILD_LEVEL:10,
                            SR_GOOD:-300, 
                            SR_FUN:"DaemonenTest" ]),
        SI_DIFFICULTY:85,
        SI_SPELLFATIGUE:25
       ]));
  AddSpell(CHAOS_ID_TUTSZT,140,
       ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:11,SR_GOOD:-500 ]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,P_GUILD_LEVEL:11,
        SR_GOOD:-300, SR_FUN:"DaemonenTest" ]),
        SI_DIFFICULTY:100,
        SI_SPELLFATIGUE:30
       ]));
  AddSpell(CHAOS_ID_YRINTRI, 180,
      ([
        SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:12,SR_GOOD:-700 ]),
        SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
        SR_GOOD:-300, SR_FUN:"DaemonenTest",
        P_GUILD_LEVEL:12 ]),
        SI_DIFFICULTY:150,
        SI_SPELLFATIGUE:60
       ]));

/* Dieses mapping enthaelt die Eigenschaften der Daemonen. Es sind die
   Wahrscheinlichkeiten mit denen der Daemon eine bestimmte Handlung
   ausfuehrt. */
  daemon = ([
      CHAOS_ID_INTARBIR:([DAEM_AGGRESSIVE:1, DAEM_DISAPPEAR:3,
                  DAEM_FALSE:7, WRONG_DAEM:1]),
      "bhuturih":([DAEM_AGGRESSIVE:1, DAEM_DISAPPEAR:2,
                  DAEM_FALSE:8, WRONG_DAEM:1]),
      CHAOS_ID_KRUFTUR:([DAEM_AGGRESSIVE:1, DAEM_DISAPPEAR:2,
                  DAEM_FALSE:10, WRONG_DAEM:2]),
      "tyoorthok":([DAEM_AGGRESSIVE:1, DAEM_DISAPPEAR:4,
                  DAEM_FALSE:12, WRONG_DAEM:2]),
      CHAOS_ID_IRKITIS:([DAEM_AGGRESSIVE:5, DAEM_DISAPPEAR:15,
                  DAEM_FALSE:10, WRONG_DAEM:20 ]),
      CHAOS_ID_HARKUHU:([DAEM_AGGRESSIVE:15, DAEM_DISAPPEAR:10,
                  DAEM_FALSE:15, WRONG_DAEM:30 ]),
      CHAOS_ID_GRAIOP: ([DAEM_AGGRESSIVE:20, DAEM_DISAPPEAR:15,
                  DAEM_FALSE:20, WRONG_DAEM:25 ]),
      CHAOS_ID_FLAXTRI:([DAEM_AGGRESSIVE:30, DAEM_DISAPPEAR:20,
                  DAEM_FALSE:25, WRONG_DAEM:35 ]),
      CHAOS_ID_BALAL:  ([DAEM_AGGRESSIVE:5, DAEM_DISAPPEAR:25,
                  DAEM_FALSE:30, WRONG_DAEM:40 ]),
      CHAOS_ID_TUTSZT:([DAEM_AGGRESSIVE:35, DAEM_DISAPPEAR:25,
                  DAEM_FALSE:30, WRONG_DAEM:45 ]),
      CHAOS_ID_YRINTRI:([DAEM_AGGRESSIVE:45, DAEM_DISAPPEAR:35,
                  DAEM_FALSE:35, WRONG_DAEM:55 ])
            ]);
}

static int daem_already_present(object caster,string daem) {
  if(present(daem+"_"+getuid(caster),environment(caster))) {
    tell_object(caster,break_string("Du beschwoerst magische Kraefte, doch da "
                       +capitalize(daem)+" schon da ist, passiert ueberhaupt "
                       "nichts."));
    return 1;
  }
  return 0;
}

static object SetDaemType(object caster,int result,string daem_name) {
  object daem = clone_object(CHAOS_GILDEN_MON(daem_name));

  daem->setDaemBeschwoerer(caster);
  daem->AddId(daem_name+"_"+getuid(caster));

  if(result==DD) {
    daem->SetProp(DAEM_DISAPPEAR,1);
  }
  if(result==DA) {
    daem->SetProp(DAEM_AGGRESSIVE,1);
  }
  if(result==DF) {
    daem->SetProp(DAEM_FALSE,1);
  }
  daem->SetProp(DAEM_FAKTOR_MAPPING,daemon[daem_name]);
  
  return daem;
}

static void Misserfolg( object caster, string spell, mapping sinfo) {
  int old_abil;

  tell_object(caster,"Der Zauberspruch ist missglueckt.\n");

  old_abil = sinfo[SI_SKILLABILITY];

  Learn(caster,spell,sinfo);

  if(old_abil < caster->QuerySkillAbility(spell)) {
    tell_object(caster,"Du lernst aus Deinen Fehlern.\n");
  }
  else {
    tell_object(caster,"Du lernst nicht aus Deinen Fehlern.\n");
  }
}

// Testest die Umgebung, ob sie fuer das Beschwoeren von Daemonen
// geeignet ist

varargs string TestEnvironment(object caster, mapping sinfo) {
  if(caster->QueryProp(P_FROG)) {
    return ("Du willst doch wohl nicht als Frosch einen Daemonen "
            "beschwoeren?\n");
  }
  if(GUILD_HELPER->
      GH_get_npc_forbidden_rooms(object_name(environment(caster)))) {
    return "Die Umgebung ist fuer das Beschwoeren von Daemonen ungeeignet.\n";
  }
  return 0;
}

int|string DaemonenTest(object caster, mapping sinfo)
{
  mixed ret;

  // Hat der Spieler eine Chaosruestung?
  ret = Funcs_CheckRuestung(caster);
  
  if(!stringp(ret)) {
    // Kann er im Raum Daemonen beschwoeren?
    ret = TestEnvironment(caster);
  }
  if(stringp(ret)) {
    return ret;
  }
  return 0;
}

int dunkelheit(object caster, mapping sinfo)
{
  int zeit, suc;

  suc = SpellSuccess(caster,sinfo);

  if(GUILD_HELPER->
       GH_get_npc_forbidden_rooms(object_name(environment(caster)))) {
    tell_object(caster,"Dieser Ort laesst sich nicht verdunkeln.\n");
    return 0;
  }
  if(environment(caster)->QueryProp(P_INT_LIGHT) <=
      -(caster->QueryProp(P_GUILD_LEVEL))) {
    tell_object(caster,"Es ist hier zu dunkel!\n");
    return 0;
  }
  if(-2000<=suc && suc<=0) {
    return MISSERFOLG;
  }
  tell_object(caster,"Du beschwoerst dunkle Maechte.\n");

  say(sprintf("%s beschwoert dunkle Maechte.\n",caster->Name(WER,1)));

  zeit  = caster->QueryProp(P_GUILD_LEVEL)*15;
  
  object tmp = present_clone(CHAOS_GILDEN_OBJ("dunkel"),environment(caster));
  
  if(!tmp) {
    tmp = clone_object(CHAOS_GILDEN_OBJ("dunkel"));
  }
  tmp -> set_my_time(zeit);
  
  tmp -> move(environment(caster), M_NOCHECK);

  if(suc<-2000) {
    tell_object(caster,"Mist, der Spruch ging daneben! Es wird ploetzlich "
                       "heller!\n");

    tmp->my_light(2);
    
    return MISSERFOLG;
  }
  tmp->my_light(-1);
  
  printf("Du verdunkelst Deine Umgebung.\n");
  return ERFOLG;
}

// Chaoten besitzen keinen Licht-Zauber, dafuer aber eine Nachtsicht

int nachtsicht(object caster, mapping sinfo) {
  int zeit, suc;

  suc = SpellSuccess(caster, sinfo);

  if(caster->QueryProp(CHAOS_GILDEN_NACHTSICHT)>time()) {
    tell_object(caster,"Du hast doch schon die Nachtsicht aktiviert!\n");
    return 0;
  }
  if(suc<=-2500) {
    tell_object(caster,"Mist! Deine Augen werden nachtblind!\n");
    caster->SetProp(CHAOS_GILDEN_NACHTBLIND, time() + 60);
    return MISSERFOLG;
  }
  if(time()<caster->QueryProp(CHAOS_GILDEN_NACHTBLIND)) {
    tell_object(caster,"Deine Augen sind zur Zeit nachtblind!\n");
    return  0;
  }
  if(suc <= 0) {
    return MISSERFOLG;
  }
  tell_object(caster,"Du veraenderst magisch Deine Augen.\n");

  say(caster->Name(WESSEN,1)+" Augen leuchten kurz dunkelrot auf.\n",caster);

  zeit = time()+caster->QueryProp(P_GUILD_LEVEL)*40;

  caster->SetProp(CHAOS_GILDEN_NACHTSICHT,zeit);

  return ERFOLG;
}

int schutz(object caster, mapping sinfo) {
  object victim, haut;
  int ac, level, suc, zeit;
  string str;
  mixed tmp;

  str  = sinfo[SI_SKILLARG];
  suc  = SpellSuccess(caster,sinfo);
  
  haut = present_clone(CHAOS_GILDEN_ARMOUR("chaosruestung"),caster);

  tmp = Funcs_CheckRuestung(caster);
  
  if(stringp(tmp)) {
    tell_object(caster,tmp);
    return 0;
  }
  if(!haut->id("neue_ruestung")) {
    tell_object(caster,"Besorg Dir erstmal eine neue Chaosruestung!\n");
    return 0;
  }
  if(haut->QueryProp(RUEST_SCHUTZ)) {
    tell_object(caster,"Die Chaosruestung ist schon magisch veraendert!\n");
    return 0;
  }
  if(str && str != "schwach" && str != "stark") {
    tell_object(caster,"Diese Art von Schutz kannst Du nicht waehlen.\n");
    return 0;
  }
  if(-2000<suc && suc<=0) {
    return MISSERFOLG;
  }
  level = caster->QueryProp(P_GUILD_LEVEL);

  tell_object(caster,break_string("Du fuchtelst wie wild mit einer Hand "
                     "herum (keiner weiss, warum man das bei diesem Spruch "
                     "so machen muss)."));

  say(break_string(caster->Name(WER,1)+" fuchtelt wie bescheuert mit einer "
      "Hand herum. Hat "+caster->QueryPronoun()+" einen Schaden?"));

  if(suc<=-2000) {
    ac = suc/100+level;

    if(ac>-1) {
      ac=-1;
    }
    if(ac<-20) {
      ac=-20;
    }
    printf("Mist, Du verschlechterst die Chaosruestung!\n");

    haut->verbessere_ruestung(ac,random(20));

    return MISSERFOLG;
  }
  if(!str||str=="schwach") {
    ac   = 10+suc/200+random(level*3);
    zeit = 6+3*level+suc/400+random(level*6);
  }
  if(str=="stark") {
    ac   = 20+suc/100+3*level+random(level*7);
    zeit = 1+random(10)+suc/1000+random(level);
  }
  printf("Du verstaerkst den Schutz der Chaoshaut.\n");
  haut->verbessere_ruestung(ac,zeit);
  return ERFOLG;
}

void BeschaedigeWaffe(object waffe) {
  printf(break_string("Du hast wohl die falsche Magie "
                      "durch "+waffe->name(WEN,1)+" fliessen lassen! "+
                      capitalize(waffe->QueryPronoun())+" wird etwas "
                      "beschaedigt!"));

  waffe->Damage(5+random(20));
}


int CheckDamTypes(mixed dt, string dam_type, object waffe) {
  int wc;

  wc = waffe->QueryProp(P_WC)/2;

  if(!pointerp(dt)) {
    dt = ({dt});
  }
  
  if(member(dt,dam_type)!=-1) {
    return random(wc);
  }
  
  mapping check = 
  ([
    DT_FIRE:     ({DT_COLD,DT_WATER}),
    DT_COLD:     ({DT_FIRE}),
    DT_WATER:    ({DT_FIRE,DT_AIR}),
    DT_AIR:      ({DT_SOUND}),
    DT_SOUND:    ({DT_MAGIC}),
    DT_LIGHTNING:({DT_COLD}),
    DT_POISON:   ({DT_ACID,DT_LIGHTNING}),
    DT_ACID:     ({DT_WATER,DT_LIGHTNING}),
    DT_DARKNESS: ({DT_LIGHT,DT_MAGIC}), 
    DT_MAGIC:    ({DT_POISON}),
  ]);
  
  if(check[dam_type]) {
    if(dt - check[dam_type] != dt) {
      if(!random(50)) {
        BeschaedigeWaffe(waffe);
      }
      return - random(wc);
    }
  }
  return 0;
}

string *ChaosDamage(object caster, int suc) {
  string *types,*dam_type;
  int anzahl;
  string *chaos_dam_type;

  // Keinen heiligen Schaden fuer Chaoten
  types = ALL_DAMAGE_TYPES - ({DT_LIGHT});
  
  chaos_dam_type = caster->QueryProp(CHAOS_DAM_TYPE);
  dam_type       = ({""});

  if(!chaos_dam_type ||
     caster->QueryProp(CHAOS_DAM_CHAOS) ||
     random(10100)>=caster->QuerySkillAbility("chaosschaden")) {
    dam_type[0]=types[random(sizeof(types))];
  }
  else {
    anzahl   = caster->QueryProp(CHAOS_DAM_ANZ);
    dam_type = chaos_dam_type;
    anzahl--;

    if(anzahl==0) {
      caster->SetProp(CHAOS_DAM_TYPE,0);
      caster->SetProp(CHAOS_DAM_ANZ,0);
    }
    else {
      caster->SetProp(CHAOS_DAM_TYPE,dam_type);
      caster->SetProp(CHAOS_DAM_ANZ,anzahl);
    }
  }
  return dam_type;
}

int check_align(object caster,object enemy,int dam) {
  int diff;

  diff = enemy->QueryProp(P_ALIGN) - caster->QueryProp(P_ALIGN) - 1000;

  if(diff < 0) {
    return 0;
  }
  if(diff > 1000) {
    diff = 1000;
  }
  return (dam*diff)/3333;
}

int chaosball(object caster, mapping sinfo) {
  object victim, waffe;
  int dam, level, suc, anzahl,g_rate, wc;
  string vn, vnw, cn, dam_txt,check_old,dam1,dam2;
  string *chaos_dam_type;
  mixed dt;
  mixed *dam_type;

  if (caster->QueryProp(CHAOSBALL_BLOCKADE) &&
      time() - caster->QueryProp(P_LAST_MOVE) < 3)
  {
     tell_object(caster,"Du denkst Dir: Halt, nein. Es ist zu frueh.\n");
     return 0;
  }
  victim = FindEnemyVictim(sinfo[SI_SKILLARG],caster,
          "Nach wem willst Du einen Chaosball werfen?\n");

  if(!victim)
    return 0;

  suc      = SpellSuccess(caster,sinfo);
  cn       = caster->name();
  vnw      = victim->name(WEN,2);
  dam_type = ChaosDamage(caster,suc);

  if(sizeof(dam_type)==2)
  {
    check_old = to_string(dam_type[1]);

    if(to_int(check_old)==dam_type[1])
    {
      tell_object(caster,"Du benutzt einen alten Chaosschaden. Bitte diesen "
                         "neu setzten!\n");
      return 0;
    }
    dam_txt = Funcs_DamText(dam_type,0);
  }
  else {
    dam_txt = Funcs_DamText(dam_type[0],0);
  }
  level = caster->QueryProp(P_LEVEL);

  if(level>27) {
    level = 27;
  }
  dam = 100+random(400*level)/27;

  if(sizeof(dam_type)==2) {
    if(caster->QueryProp(P_SP)<sinfo[SI_SPELLCOST]+5) {
      tell_object(caster,"Du hast zu wenig Zauberpunkte fuer diesen "
                         "Spruch..\n");
      return 0;
    }
    caster->restore_spell_points(-5);
  }
  if(suc<-2500) {
    printf("Hilfe! Der Spruch ging nach hinten los!\n"
          +"Du feuerst "+dam_txt+" auf Dich ab.\n");

    say(sprintf("%s feuert "+dam_txt+" auf sich ab.\n",capitalize(cn)));

    SetProp(P_NAME,"Unberechenbares Chaos");

    caster->do_damage(dam/14,caster);

    return MISSERFOLG;
  }
  if(suc<=0)
    return MISSERFOLG;

  say(sprintf("%s feuert "+dam_txt+" auf %s ab.\n",
     capitalize(cn), vnw),victim);

  printf("Du feuerst "+dam_txt+" auf %s ab.\n",vnw);

  tell_object(victim,sprintf("%s feuert "+dam_txt+" auf Dich ab.\n",
              capitalize(cn)));

  if(objectp(waffe=caster->QueryProp(P_WEAPON)))
  {
    dt = waffe->QueryProp(P_DAM_TYPE);

    if(stringp(dt))
      dt=({dt});

    if(sizeof(dam_type)==2)
    {
      if(member(dt,dam_type[1]!=-1) && member(dt,dam_type[0])!=-1)
      {
        wc = waffe->QueryProp(P_WC);
        if(!member(PHYSICAL_DAMAGE_TYPES,dam_type[0]))
          dam+=CheckDamTypes(dt,dam_type[0],waffe);

        if(wc>150)
          wc=150;

        wc = wc/2;

        dam += random(wc)+wc;
      }
      dam += 50 + random(level*2);
    }
    else if(!member(PHYSICAL_DAMAGE_TYPES,dam_type[0]))
      dam += CheckDamTypes(dt,dam_type[0],waffe);
  }
  dam += check_align(caster,victim,dam);

  if(suc < victim->SpellDefend(caster,
                              ([ SP_NAME:"chaosball",
                                 SI_MAGIC_TYPE:({MT_ANGRIFF})
                              ])))
  {
    tell_object(victim,caster->Name(WESSEN,1)+" Chaosball zerplatzt wie "
                "eine Seifenblase.\n");

    tell_object(caster,break_string("Dein Chaosball zerplatzt wie eine "
                "Seifenblase! Aus der Ferne hoerst Du noch kurz das fiese "
                "Lachen eines Daemons. Dann wird es kurz totenstill."));
    return 1;
  }
  sinfo += ([ SI_SKILLDAMAGE_TYPE:({ dam_type }) ]);

  TryAttackSpell(victim,dam, dam_type,
                ([ SP_SHOW_DAMAGE:1,
                   SI_SKILLDAMAGE_TYPE:dam_type
                ]),caster,sinfo);

  return ERFOLG;
}

int verbanne(object caster, mapping sinfo)
{
  string str;
  int resi, suc, dam;
  object victim;

  suc = SpellSuccess(caster,sinfo);
  str = sinfo[SI_SKILLARG];

  if(str=="haut"||str=="chaoshaut"||str=="chaosruestung")
  {
    notify_fail("Wen willst Du verbannen?\n");

    if(!victim=present_clone(CHAOS_GILDEN_ARMOUR("chaosruestung"),caster))
      return 0;

    if(suc<=0)
      return MISSERFOLG;

    printf("Du richtest Deine ganze Macht gegen den Daemon in Deiner "
          +"Haut!\n");

    say(caster->Name(WER,1)+" wirft wuetende Worte gegen sich "
        +"selber!\n",({caster}));

    if(suc>2000)
    {
      victim->remove_it();
      return ERFOLG;
    }
    else if(suc>5){

      printf("Aua! Der Daemon rebelliert kurz aber kraeftig!\n");
      caster->reduce_hit_point(10+random(10));
      victim->remove_it();
      return ERFOLG;
    }
    else
    {
      printf("Die Verbannung hat nicht so ganz geklappt, Du hast den "
            +"Chaosdaemonen\nnur veraergert!\n");
      victim->SetProp(DAEM_FALSE,1);
      victim->chaos_chaos_chaos(26);
      return ERFOLG;
    }
  }
  victim = FindLivingVictim(sinfo[SI_SKILLARG],caster,
                          "Wen willst Du verbannen?\n");
  // 2x FindVictim, da das 1. ihn nicht zum Feind macht.
  // Ich machs nicht per Hand, da das Std-Spellbook evtl.
  // erweitert wird.

  if(!victim)
    return 0;

  if(!victim->is_class_member(CL_DEMON) &&
     !victim->is_class_member(CL_SHADOW_CREAT) &&
     !victim->QueryProp(CHAOS_DAEM_BESCHWOERER))
  {
    printf("%s kannst Du nicht verbannen!\n",victim->Name(WEN,1));
    return 0;
  }
  victim = FindEnemyVictim(sinfo[SI_SKILLARG],caster,
                           "Dieses Opfer ist unangreifbar.\n");
  if (!victim)
    return 0;

  if(suc<=0)
    return MISSERFOLG;

  if(suc < victim->SpellDefend(caster,
                               ([ SP_NAME:"verbanne",
                                  SI_MAGIC_TYPE:({MT_BEHERRSCHUNG})])))
  {
    tell_object(victim,caster->Name(WER,1)+" sagt: He, Du, geh ma weg hier!\n"+
                       "Du sagst: Och noeeeeh.\n");

    tell_object(caster,"Du erhebst die Haende ueber den Kopf.\n"+
                       "Du sagst: He, Du, geh ma weg hier!\n"+

    victim->Name(WER,1)+" sagt: Och noeeeeh.\n");

    return 1;
  }
  printf("Du hebst die Arme empor und wirfst uebelste Worte gegen %s.\n",
         victim->name(WEN) );

  say(caster->Name(WER,1)+" hebt die Arme empor und wirft uebelste "
     +"Worte gegen "+victim->name(WEN)+".\n");

  if(victim->id("chaos_aggressive_daemonen"))
  {
    resi = victim->QueryProp(P_HANDS)[1];

    if(victim->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(caster))
      resi = random(resi*45);

    else
      resi = random(resi*60);

    if(suc>resi)
    {
      printf(break_string("Der Spruch war ein voller Erfolg! %s "+
             "verschwindet aus dieser Dimension."),
             victim->Name(WER,1));

      victim->die();

      return ERFOLG;
    }
    else
      dam = 250 + random(700);
  }
  else if(victim->id(CHAOS_ID_GILDENDAEMON))
  {
    resi = victim->QueryProp(DAEM_FAKTOR_MAPPING)[DAEM_AGGRESSIVE];

    if(victim->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(caster))
      resi = random(resi*285);

    else
      resi = random(resi*305);

    if(suc>resi)
    {
      printf(break_string("Der Spruch war ein voller Erfolg! %s "+
             "verschwindet aus dieser Dimension."),victim->Name(WER,1));

      victim->die();
      return ERFOLG;
    }
    else
      dam = 250+random(600);
  }
  else
    dam = 400+random(500); // Gegen Nicht-Gilden-Daemonen

  TryAttackSpell(victim,dam,({DT_SOUND,DT_TERROR}),([ 
                                                     SP_NAME:"verbanne",
                                                     SP_SHOW_DAMAGE:1
                                                   ]),caster,sinfo);
  return ERFOLG;
}

int finsternis(object caster, mapping sinfo)
{
  object victim;
  int zeit, suc, old_dattack;
  string cn, vnw;
  object *flw;

  if (caster->QueryProp(CHAOS_FINSTERNIS)>time())
  {
    tell_object(caster,"Du kannst noch keine neue Finsternis zaubern.\n");
    return 0;
  }
  victim = FindEnemyVictim(sinfo[SI_SKILLARG],caster,
                           "Wen willst Du mit einer Finsternis belegen?\n");

  if(!victim)
    return 0;

  old_dattack = victim->QueryProp(P_DISABLE_ATTACK);

  if (old_dattack>0)
  {
    printf("Aber %s ist doch schon verfinstert!\n",victim->name(WER));
    return 0;
  }
  suc = SpellSuccess(caster,sinfo);

  if(suc<-2000)
  {
    printf("Oh weia! Jetzt hast Du den Zauber gegen Dich angewendet!\n");
    caster->SetProp(P_DISABLE_ATTACK,20);
  }
  if(suc<=0)
    return MISSERFOLG;

  caster->SetProp(CHAOS_FINSTERNIS,time()+120);

  if(suc < victim->SpellDefend(caster,
                               ([ SP_NAME:"finsternis",
                                  SI_MAGIC_TYPE:({MT_BEHERRSCHUNG})
                               ])))
  {
    tell_object(victim,break_string(caster->name(WESSEN,1)+" Wolke der "
                       "Finsternis dreht kurz vor Dir ab und verpufft."));

    tell_object(caster,break_string("Du willst "+victim->name(WEN,1)+
                       " in eine Wolke der Finsternis huellen, doch die Wolke "
                       "verzieht sich sofort."));
    return 1;
  }

  cn  = caster->name();
  vnw = victim->name(WEN,2);

  say(sprintf("%s huellt %s in einer Wolke aus Finsternis ein.\n",cn, vnw),
              victim);

  printf("Du huellst "+vnw+" in eine Wolke aus Finsternis ein.\n",vnw);

  tell_object(victim,
              sprintf("%s huellt Dich in eine Wolke aus Finsternis ein.\n",cn));

  zeit = 4+caster->QueryAttribute(A_INT)/2+random(suc/800);
  zeit = sinfo[SI_SKILLABILITY]*zeit/MAX_ABILITY;

  if (zeit>20)
    zeit = 20;

  zeit = zeit * caster->QuerySkillAttribute(SA_DURATION)/100;

  victim->SetProp(P_DISABLE_ATTACK,zeit+old_dattack);

  if (pointerp(caster->QueryProp(P_PURSUERS)) &&
      pointerp(caster->QueryProp(P_DEFENDERS)))
  {
    flw = (caster->QueryProp(P_PURSUERS)[1] &
           caster->QueryProp(P_DEFENDERS)) -({0});

    map_objects(flw,"Kill",victim);
  }
  return ERFOLG;
}

// Jetzt fuer Chaosschaden UND Chaoskontrolle
// gruppe: 0 mech-schaden und element-schaden
//         1 element-schaden
//         2 mech-schaden
// (Nur fuer Einzelschaeden)

static mixed check_chaosdamage(string *dam_type, int gruppe)
{
  mapping schaden_element = ([
    "feuer":DT_FIRE,
    "eis":DT_COLD,
    "sturm":DT_AIR,
    "magie":DT_MAGIC,
    "wasser":DT_WATER,
    "blitz":DT_LIGHTNING,
    "saeure":DT_ACID,
    "gift":DT_POISON,
    "krach":DT_SOUND,
    "boese":DT_DARKNESS,
    "terror":DT_TERROR,
    ]);

  mapping schaden_mech = ([
    "pfeil":DT_PIERCE,
    "messer":DT_SLASH,
    "felsen":DT_BLUDGEON,
    "peitsche":DT_WHIP,
    "quetschen":DT_SQUEEZE,
    "explosion":DT_EXPLOSION,
    "widerhaken":DT_RIP
    ]);

 // Einzelschaeden

  if(sizeof(dam_type)==1) {
    switch(gruppe) {
      case 0:
        if(member(schaden_element,dam_type[0]))
          return ({schaden_element[dam_type[0]]});

        if(member(schaden_mech,dam_type[0]))
          return ({schaden_mech[dam_type[0]]});

        break;

      case 1:
        if(member(schaden_element,dam_type[0]))
          return ({schaden_element[dam_type[0]]});

        break;

      default:
        if(member(schaden_mech,dam_type[0]))
          return ({schaden_mech[dam_type[0]]});

        break;
    }
  }
  if(sizeof(dam_type)==2) {
    if((member(schaden_element,dam_type[0])&&
        member(schaden_element,dam_type[1]))||
       (member(schaden_mech,dam_type[0])&&
        member(schaden_mech,dam_type[1]))) {
      return ({});
    }
    if((member(schaden_element,dam_type[0])==0&&
        member(schaden_mech,dam_type[0])==0)||
       (member(schaden_element,dam_type[1])==0&&
        member(schaden_mech,dam_type[1])==0)) {
      return ({});
    }
    if(member(schaden_element,dam_type[0])) {
      return ({
               schaden_element[dam_type[0]],
               schaden_mech[dam_type[1]]
             });
    }
    else {
      return ({
               schaden_element[dam_type[1]],
               schaden_mech[dam_type[0]]
             });
    }
  }
  return ({});
}

int chaosschaden(object caster, mapping sinfo)
{
  string *dam_type, str, txt1, txt2, *exp;
  int anzahl, sp, suc;
  mixed chaos_dam_type;

  dam_type = ({});
  str      = sinfo[SI_SKILLARG];

  chaos_dam_type = caster->QueryProp(CHAOS_DAM_TYPE);
  anzahl         = caster->QueryProp(CHAOS_DAM_ANZ);
  suc            = SpellSuccess(caster,sinfo);

  if(!str && pointerp(chaos_dam_type)) {
    if(sizeof(chaos_dam_type)==2) {
      tell_object(caster,"Verwende zum Anzeigen bitte 'chaoskontrolle'!\n");
      return 0;
    }
    txt1 = Funcs_DamText(chaos_dam_type[0],0);
    exp  = explode(txt1," ");

    if(exp[0]=="einen") {
      txt1 = "ein "+implode( exp[1..<0], " ");
    }
    txt2 = Funcs_DamText(chaos_dam_type[0],1);

    tell_object(caster,(anzahl==1?"Der naechste Chaosball ist: "+txt1:
           "Die naechsten "+anzahl+" Chaosbaelle sind: "+txt2)+".\n");

    if(caster->QueryProp(CHAOS_DAM_CHAOS)) {
      tell_object(caster,"Du hast den Chaosschaden momentan deaktiviert.\n");
    }
    return 0;
  }
  if(!str) {
    printf("Du hast keinen Chaosschaden eingestellt!\n");
    return 0;
  }
  if(str == "chaos") {
    caster->restore_spell_points(19);

    if (caster->QueryProp(CHAOS_DAM_CHAOS)) {
      caster->SetProp(CHAOS_DAM_CHAOS,0);
      printf("Du verwendest wieder Deinen Chaosschaden.\n");
      return 1;
    }
    else {
      caster->SetProp(CHAOS_DAM_CHAOS,1);
      printf("Du verwendest keinen Chaosschaden mehr.\n");
      return 1;
    }
  }

  dam_type = ({str});
  dam_type = check_chaosdamage(dam_type,0);

  if(!sizeof(dam_type)) {
    printf("Diesen Schadenstyp kannst Du nicht waehlen.\n");
    return 0;
  }
  if(str=="boese" && caster->QueryProp(P_ALIGN)>-200) {
    printf("Du bist nicht boese genug, um satanische Flueche zu sprechen!\n");
    return 0;
  }
  if(suc<=0) {
    return MISSERFOLG;
  }
  if(pointerp(chaos_dam_type)) {
    anzahl += 1+random(caster->QueryProp(P_GUILD_LEVEL));
  }
  else {
    anzahl = 1+random(caster->QueryProp(P_GUILD_LEVEL));
  }
  if(pointerp(chaos_dam_type)) {
    if(sizeof(chaos_dam_type)==2) {
      tell_object(caster,"Du stellst den Chaosball von Chaoskontrolle auf "+
                         "Chaosschaden um.\n");
    }
    else if(chaos_dam_type[0]!=dam_type[0]) {
      tell_object(caster,"Du aenderst den Schadenstyp.\n");
    }
  }
  txt1 = Funcs_DamText(dam_type[0],0);
  exp  = explode(txt1," ");

  if(exp[0]=="einen") {
    txt1="ein "+implode(exp[1..<0]," ");
  }
  txt2 = Funcs_DamText(dam_type[0],1);

  caster->SetProp(CHAOS_DAM_TYPE,({dam_type[0]}));
  caster->SetProp(CHAOS_DAM_ANZ,anzahl);

  printf((anzahl==1?"Der naechste Chaosball ist: "+txt1:
         "Die naechsten "+anzahl+" Chaosbaelle sind: "+txt2 )+".\n");

  say(caster->Name(WER.1)+" murmelt seltsame Worte. "+
      (caster->QueryProp(P_GENDER)==1?"Seine":"Ihre")+
      " Augen leuchten kurz rot auf.\n");

  return ERFOLG;
}

int chaoskontrolle(object caster, mapping sinfo) {
  string str,txt1,txt2,*exp,s1,s2;
  int anzahl, sp, suc;
  mixed chaos_dam_type,dam_type;

  str = sinfo[SI_SKILLARG];

  chaos_dam_type = caster->QueryProp(CHAOS_DAM_TYPE);
  anzahl         = caster->QueryProp(CHAOS_DAM_ANZ);

  suc = SpellSuccess(caster,sinfo);

  if(!str&&pointerp(chaos_dam_type) && sizeof(chaos_dam_type)==2) {
    txt1= Funcs_DamText(chaos_dam_type,0);
    
    exp   =  explode(txt1," ");

    if(exp[0]=="einen") {
      txt1 ="ein "+implode(exp[1..<0]," ");
    }
    txt2 = Funcs_DamText(chaos_dam_type,1);
    tell_object(caster,(caster->QueryProp(CHAOS_DAM_ANZ)==1?
                            "Der naechste Chaosball ist: "+txt1:
                            "Die naechsten "+caster->QueryProp(CHAOS_DAM_ANZ)+
             " Chaosbaelle sind: "+txt2)+".\n");

    if (caster->QueryProp(CHAOS_DAM_CHAOS)) {
      tell_object(caster,"Die Chaoskontrolle hast Du deaktiviert.\n");
    }
    return 0;
  }
  if(!str) {
    printf("Du hast keine Chaoskontrolle eingestellt!\n");
    return 0;
  }
  if (str == "chaos") {
    caster->restore_spell_points(19);

    if (caster->QueryProp(CHAOS_DAM_CHAOS)) {
      caster->SetProp(CHAOS_DAM_CHAOS,0);
      printf("Du verwendest wieder Deinen Chaosschaden.\n");
      return 1;
    }
    else {
      caster->SetProp(CHAOS_DAM_CHAOS,1);
      printf("Du verwendest keinen Chaosschaden mehr.\n");
      return 1;
    }
  }
  if(sscanf(str,"%s und %s",s1,s2)!=2) {
    printf("Wie nun? Chaoskontrolle <schaden1> und <schaden2>\n");
    return 0;
  }
  dam_type = ({s1,s2});
  dam_type = check_chaosdamage(dam_type,0);

  if(!sizeof(dam_type)) {
    printf("Diese Kombination geht leider nicht.\n");
    return 0;
  }
  if((s1=="boese"||s2=="boese") && caster->QueryProp(P_ALIGN)>-300) {
    printf("Du bist nicht boese genug, um dies zu kontrollieren!\n");
    return 0;
  }
  if(suc<= 0) {
    return MISSERFOLG;
  }
  if(pointerp(chaos_dam_type)) {
    anzahl = caster->QueryProp(CHAOS_DAM_ANZ)+1+
                     random(caster->QueryProp(P_GUILD_LEVEL));
  }
  else {
    anzahl = 1+random(caster->QueryProp(P_GUILD_LEVEL));
  }
  if(pointerp(chaos_dam_type)) {
    if(sizeof(chaos_dam_type)==2) {
      if(chaos_dam_type[0]!=dam_type[0]||chaos_dam_type[1]!=dam_type[1]) {
         tell_object(caster,"Du aenderst den Schadenstyp.\n");
      }
    }
    else if(sizeof(chaos_dam_type)==1) {
       tell_object(caster,"Du stellst den Chaosball von Chaosschaden auf "+
                          "Chaoskontrolle um.\n");
    }
  }
  txt1 = Funcs_DamText(dam_type,0);
  exp  = explode(txt1, " ");

  if(exp[0]=="einen") {
    txt1 = "ein "+implode(exp[1..<0]," ");
  }
  txt2 = Funcs_DamText(dam_type,1);
   
  caster->SetProp(CHAOS_DAM_TYPE,dam_type);
  caster->SetProp(CHAOS_DAM_ANZ,anzahl);

  printf((anzahl==1?"Der naechste Chaosball ist: "+txt1:
          "Die naechsten "+anzahl+" Chaosbaelle sind: "+txt2 )+".\n");

  say(caster->Name(WER,1)+" murmelt geheimnisvolle Worte der Macht. "
       +(caster->QueryProp(P_GENDER)==1?"Seine":"Ihre")+
       " Augen blitzen blutig-rot auf.\n");
  
  return ERFOLG;
}


int chaosruestung( object caster, mapping sinfo) {
  object ruest;
  int level, suc, alig;

  if(present_clone(CHAOS_GILDEN_ARMOUR("chaosruestung"),caster)) {
    printf("Du kannst immer nur eine Chaosruestung besitzen.\n");
    return 0;
  }
  level = caster->QueryProp(P_GUILD_LEVEL);
  suc   = SpellSuccess(caster,sinfo);

  if(suc<-2000) {
    call_out("falscher_daemon",0,caster,-(suc/1000)*level/3);
    return MISSERFOLG;
  }
  if(suc<=0) {
    return MISSERFOLG;
  }
  ruest = clone_object(CHAOS_GILDEN_ARMOUR("chaosruestung"));

  alig = caster->QueryProp(P_ALIGN);

  if(alig>-2000) {
    caster->SetProp(P_ALIGN,caster->QueryProp(P_ALIGN)-30*level);
  }
  printf("Du beschwoerst einen unheimlichen Daemon, der direkt in "
         "Deine Haut eindringt.\n");

  say(break_string(caster->Name(WER)+" macht seltsame Bewegungen, spricht "
     "magische Worte einer seltsamen Sprache und beschwoert so einen "
     "unheimlichen Daemon, der sofort in "
     +(caster->QueryProp(P_GENDER)==1?"seine":"ihre")+" Haut eindringt und "
     "diese mutieren laesst! Es sieht einfach gruselig aus!"));

  ruest->move(caster,M_NOCHECK);
  ruest->SetProp(CHAOS_DAEM_BESCHWOERER,getuid(caster));
  ruest->SetProp(RUEST_CASTER_LEVEL,level);
  ruest->do_wear("_chaos_ruestung_",1);
  ruest->SetProp(P_CURSED,1);
  ruest->SetProp(DAEM_FALSE,1);
  ruest->starte_anziehen(suc);
  return ERFOLG;
}

int kontrolle(object caster, mapping sinfo) {
  int suc;
  object ob;

  ob = present_clone(CHAOS_GILDEN_ARMOUR("chaosruestung"),caster);

  if(!ob) {
    tell_object(caster,"Ohne Chaosruestung macht dieser Spruch keinen Sinn!\n");
    return 0;
  }
  if(!ob->QueryProp(DAEM_FALSE)) {
    tell_object(caster,"Der Daemon der Chaosruestung ist doch noch "
                       "friedlich.\n");
    return 0;
  }

  suc = SpellSuccess(caster,sinfo);

  tell_object(caster,break_string("Du fuchtelst wild mit den Haenden herum "
              "und murmelst finstere Worte der Macht."));
              
  if(suc<-2000) {
    tell_object(caster,"Mist, der Spruch ging voellig daneben.\n");
    caster->reduce_hit_points( random(-suc/100));
    return MISSERFOLG;
  }
  if(suc<=0) {
    return MISSERFOLG;
  }
  ob->SetProp(DAEM_FALSE,0);

  tell_object(caster,"Du erlangst die Kontrolle ueber die Chaosruestung "
                     "zurueck.\n");

  say(break_string(caster->Name(WER)+" fuchtelt mit den Haenden herum und "
      "murmelt finstere Worte der Macht. Ploetzlich scheinen "
      +(caster->QueryProp(P_GENDER)==1?"seine":"ihre")+
      " seltsamen Anfaelle weg zu sein."));

  return ERFOLG;
}

int bannzauber(object caster, mapping sinfo)
{
  int suc;
  object ob;

  if(!ob=Funcs_GetPentagramm(caster)) {
    printf( "Du brauchst ein eigenes Pentagramm fuer diesen Spruch.\n");
    return 0;
  }
  if(!ob->QueryProp(CHAOS_BANNKREIS)) {
    printf("Du musst den Bannzauber auf einen Bannkreis sprechen.\n");
    return 0;
  }
  if(ob->QueryProp(CHAOS_BANNKREIS)==2) {
    printf("Auf dem Bannkreis liegt schon ein Bannzauber.\n");
    return 0;
  }

  suc = SpellSuccess(caster,sinfo);

  if(suc<-3500) {
    printf("Argl! Der Spruch ging voellig daneben und zerstoert das "
           "Pentagramm!\n");

    say(break_string(caster->Name(WER)+" tanzt um das Pentagramm herum, "
        "spricht magische Worte und beschwoert finstere Kraefte. Dann "
        "schiesst ploetzlich ein heller Strahl hinab und zerstoert "
        "das Pentagramm und den Bannkreis."));

    ob->reset();

    return MISSERFOLG;
  }
  if(suc<-2500) {
    printf("Mist, der Spruch ging daneben. Der Spruch verschlechtert den "
           "Bannkreis.\n");

    say(break_string(caster->Name(WER)+" tanzt um das Pentagramm herum, "
        "spricht magische Worte und beschwoert finstere Kraefte. Dann "
        "schiesst ploetzlich ein heller Strahl hinab und laesst den "
        "Bannkreis aufleuchten."));

    ob->SetProp(CHAOS_BANNKREIS,2);
    ob->SetProp(CHAOS_BANNKREIS_FAKTOR,
    ob->QueryProp(CHAOS_BANNKREIS_FAKTOR)-10-random(50));

    return MISSERFOLG;
  }
  if(suc<=0) {
    return MISSERFOLG;
  }
  ob->SetProp(CHAOS_BANNKREIS,2);

  if (ob->QueryProp(CHAOS_NEUES_PENTA)) {
    ob->SetProp(CHAOS_BANNKREIS_RANDOM,ob->QueryProp(CHAOS_BANNKREIS_RANDOM)+

    caster->QueryProp(P_GUILD_LEVEL)*2+8*suc/1000);

    ob->SetProp(CHAOS_BANNZAUBER_FAKTOR,suc);
  }
  else {
    ob->SetProp(CHAOS_BANNKREIS_FAKTOR,ob->QueryProp(CHAOS_BANNKREIS_FAKTOR)+
        caster->QueryProp(P_GUILD_LEVEL)*2+8*suc/1000);
  }
  printf("Du sprichst einen Bannzauber auf den Bannkreis.\n");

  if(suc>=5000) {
    printf("Der Spruch war so gut, dass auch das Pentagramm verbessert "
           "wird.\n");

    if (ob->QueryProp(CHAOS_NEUES_PENTA)) {
      ob->SetProp(CHAOS_PENTAGRAMM_RANDOM,
                   ob->QueryProp(CHAOS_PENTAGRAMM_RANDOM)+
                   caster->QueryProp(P_GUILD_LEVEL)+5*suc/1000);
    }
    else {
      ob->SetProp(CHAOS_PENTAGRAMM_FAKTOR,
                   ob->QueryProp(CHAOS_PENTAGRAMM_FAKTOR)+
                   caster->QueryProp(P_GUILD_LEVEL)+5*suc/1000);
    }
  }
  say(break_string(caster->Name(WER)+" tanzt um das Pentagramm herum, "
      "spricht magische Worte und beschwoert finstere Kraefte. Dann "
      "schiesst ploetzlich ein blutroter Strahl hinab und laesst den "
      "Bannkreis schaurig aufleuchten."));

  return ERFOLG;
}

object FindeEigenenDaemonen(string daemon, object caster) {
  object tmp;
  
  if(!daemon)
    return 0;

  foreach(tmp:filter(filter(all_inventory(environment(caster)),
                      #'living), #'objectp)) {
    if(tmp->is_class_member(CL_DEMON) && tmp->id(daemon)) {
      if(tmp->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(caster)) {
        return tmp;
      }
    }
  }
  return 0;
}

int binde( object caster, mapping sinfo) {
  object daem;
  string str;
  mixed pers;
  int suc, count, zeit;

  suc = SpellSuccess(caster,sinfo);

  daem = FindeEigenenDaemonen(sinfo[SI_SKILLARG],caster);

  if(!daem) {
    if (sinfo[SI_SKILLARG] &&
        present(sinfo[SI_SKILLARG],environment(caster))) {
      printf("Das Ding wurde nicht von Dir beschworen.\n");
    }
    else {
      printf("So einnen Daemonen findest Du hier nicht!\n");
    }
    return 0;
  }
  if(!daem->id(CHAOS_ID_GILDENDAEMON)) {
    printf("Du kannst nur Gilden-Daemonen an Dich binden!\n");
    return 0;
  }
  if(daem->QueryProp(CHAOS_DAEM_BESCHWOERER)!=getuid(caster)) {
    printf("Du kannst nur Deine eigenen Daemonen an Dich binden!\n");
    return 0;
  }
  if(suc<=0) {
    switch(random(100)) {
      case 1..3:
        printf(break_string("Der Spruch hat ueberhaupt nicht funktioniert! "
               "Seltsam, warum schaut Dich der Daemon auf einmal so komisch "
               "an? Warum grinst er bloss?"));
        daem->SetProp(DAEM_FALSE,1);
        break;

      case 4..8:
        daem->SetProp(DAEM_DISAPPEAR,1);
        break;

      case 9..10:
        daem->SetProp(DAEM_AGGRESSIVE,1);
        break;

      case 11..20:
        daem->SetProp(CHAOS_DAEM_NO_DISAPPEAR,0);
        break;

      default: break;
    }
    return MISSERFOLG;
  }
  printf(break_string("\nDu stierst "+daem->name(WEN,1)+" finster an und "
         "sprichst Worte der Macht.\n"
        +daem->Name(WER,1)+" wird dadurch eingeschuechtert und bleibt "
        "laenger unter\nDeiner Kontrolle."));

  say(caster->Name(WER,1)+" stiert "+daem->name(WEN,1)+" finster und "
      "boese an.\n");

  if(count = daem->QueryProp(DAEM_COUNT_DOWN)) {
    count += random(caster->QueryAttribute(A_INT))+suc/200;
    str    = daem->Name(WER,1)+" wird vorraussichtlich jetzt ";

    switch(count) {
      case 0..20:
        str += "ganz kurz";
        break;
      case 21..30:
        str += "etwas";
        break;
      case 31..50:
        str += "einige Zeit";
        break;
      case 51..70:
        str += "laengere Zeit";
        break;
      case 71..100:
        str += "eine sehr lange Zeit";
        break;
      default:
        str += "eine ueberaus lange Zeit";
        break;
    }
    str += " mit Dir zusammen kaempfen.";

    printf(break_string(str));

    daem->SetProp(DAEM_COUNT_DOWN,count);
  }
  if(zeit = daem->QueryProp(CHAOS_DAEM_FOLLOW_TIME)) {
    zeit += random(600)+suc/3;
    str   = daem->Name(WER,1)+" wird Dir vorraussichtlich ";

    switch(zeit - time()) {
      case 0..60:
        str += "ganz kurz";
        break;
      case 61..180:
        str += "etwas";
        break;
      case 181..300:
        str += "einige Zeit";
        break;
      case 301..600:
        str += "laengere Zeit";
        break;
      case 601..1200:
        str += "eine sehr lange Zeit";
        break;
      default:
        str += "eine ueberaus lange Zeit";
        break;
    }
    str += " folgen.";

    printf(break_string(str));

    daem->SetProp(CHAOS_DAEM_FOLLOW_TIME, zeit);

    if(!pointerp(pers=caster->QueryProp(P_PURSUERS)) ||
       member(pers[1],daem)==-1) {
      caster->AddPursuer(daem);
    }
  }
  if(suc>3000) {
    caster->AddPursuer(daem);
  }
  return ERFOLG;
}
/*
int chaosmaske( object caster, mapping sinfo){
  object maske;
  int suc;
  suc=SpellSuccess(caster,sinfo);
  maske = (filter_objects(this_player()->QueryProp(P_ARMOURS)||({}),
                          "id",AT_HELMET)+({0}))[0];
  if(present("\nChaosMaske",caster)) {
    printf("Du bist doch schon verwandelt. Verschwende deine Macht nicht so!\n");
    return 0;
  }
  if(!maske) {
    printf("Also, eine Chaosmaske solltest Du dafuer schon tragen.\n");
    return 0;
  }
  if (environment(caster)->_query_total_light()>0 && !IS_LEARNER(caster)) {
    printf("Es ist viel zu hell hier.\n");
    return 0;
  }
  if (sizeof(caster->QueryProp(P_TMP_ATTACK_HOOK))==3)
     if (caster->QueryProp(P_TMP_ATTACK_HOOK)[0]<=time()) {
       printf("Irgend etwas .... irgend etwas stimmt mit deinen Haenden nicht!\n");
       return 1;
  }
  if (!maske->is_chaosmaske()) {
    printf("Du versuchst die Magie "+maske->Name(WESSEN)+" zu aktivieren. Vergeblich.\n");
    return ERFOLG;
  }
  if(suc<=-4000) {   //gaaaanz schlecht...
    maske=clone_object(
    ({CHAOS_GILDEN_OBJ("masken/hase_maske"),
      CHAOS_GILDEN_OBJ("masken/baer_maske")
    })[random(2)]);
    maske->move(this_player(),M_NOCHECK);
    maske->DoWear(1);
    if (member_array(maske,caster->QueryProp(P_ARMOURS))>-1)
      maske->activate(-suc);
    Learn(caster,"chaosmaske",sinfo);
    return 0;
  }
  if (suc<=0)
    return MISSERFOLG;
  maske->activate(suc);
  return ERFOLG;
}
*/

int intarbir(object caster, mapping sinfo) {
  object daem, p;
  int result, suc;
  int pentaf, kreisf;

  if(daem_already_present(caster,CHAOS_ID_INTARBIR)) {
    return ERFOLG;
  }

  suc = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }
  p      = Funcs_GetPentagramm(caster);
  pentaf = Funcs_GetPentagrammfaktor(p);
  kreisf = Funcs_GetKreisfaktor(p);
  result = Funcs_TestPentagramm(daemon[CHAOS_ID_INTARBIR], caster, pentaf, kreisf, suc);

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_INTARBIR][WRONG_DAEM] );

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  daem = SetDaemType(caster,result,CHAOS_ID_INTARBIR);

  printf("Du beschwoerst finstere Kraefte und oeffnest so ein Tor in "
         "andere Welten.\n");

  say(break_string(caster->Name(WER,1)+" murmelt leise Worte einer "
      "gutturalen Sprache und laesst eine rote, magische Wolke entstehen, "
      "aus der eine finstere Gestalt hervorkommt."));

  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+ 30 + suc/1000 * 30);
  daem->move(environment(caster),M_GO);

  if(result!=DF||random(100)>daemon[CHAOS_ID_INTARBIR][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
      daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  return ERFOLG;
}

int bhuturih(object caster, mapping sinfo) {
  object daem, p;
  int result, suc;

  if(present("bhuturih_"+getuid(caster),environment(caster))) {
    printf("Was willst Du mit zwei Daemonen?\n");
    return 0;
  }
  suc = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }
  p = Funcs_GetPentagramm(caster);

  result = Funcs_TestPentagramm(daemon["bhuturih"],
                        caster,
                        Funcs_GetPentagrammfaktor(p),
                        Funcs_GetKreisfaktor(p),
                        suc);

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon["bhuturih"][WRONG_DAEM] );

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }

  daem = SetDaemType(caster,result,"bhuturih");

  printf("Du beschwoerst finstere Kraefte und oeffnest so ein Tor in "
         "andere Welten.\n");

  say(break_string(caster->Name(WER,1)+" murmelt leise Worte einer "
      "gutturalen Sprache und laesst eine rote, magische Wolke entstehen, "
      "aus der eine hintergruendig-grinsende Gestalt entschwebt."));

  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+ 30 + suc/1000 * 30);
  daem->move(environment(caster),M_GO);

  if(result!=DF || random(100)>daemon["bhuturih"][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
      daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  return ERFOLG;
}

int tyoorthok(object caster, mapping sinfo)
{
  object daem, p;
  int result, suc;

  if(present("tyoorthok_"+getuid(caster),environment(caster))) {
    printf("Was willst Du mit zwei Daemonen?\n");
    return 0;
  }
  suc = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }
  p      = Funcs_GetPentagramm(caster);
  result = Funcs_TestPentagramm(daemon["tyoorthok"],
                        caster,
                        Funcs_GetPentagrammfaktor(p),
                        Funcs_GetKreisfaktor(p),
                        suc);

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon["tyoorthok"][WRONG_DAEM] );

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }

  daem = SetDaemType(caster,result,"tyoorthok");
  
  printf("Du beschwoerst finstere Kraefte und oeffnest so ein Tor in "
         "andere Welten.\n");

  say(break_string(caster->Name(WER,1)+" murmelt Worte einer "
      "unbekannten Sprache und laesst eine aschgraue Saeule entstehen, "
      "aus der sich eine alte und gebeugte Gestalt entwindet."));

  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+ 30 + suc/1000 * 30);
  daem->move(environment(caster),M_GO);

  if(result!=DF||random(100)>daemon["tyoorthok"][DAEM_FALSE]) {
    caster->AddPursuer(daem);
  }
  return ERFOLG;
}

int kruftur(object caster, mapping sinfo) {
  object daem, p;
  int result, suc;

  if(daem_already_present(caster,CHAOS_ID_KRUFTUR)) {
    return ERFOLG;
  }

  suc = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }

  p      = Funcs_GetPentagramm(caster);
  result = Funcs_TestPentagramm(daemon[CHAOS_ID_KRUFTUR],
                        caster,
                        Funcs_GetPentagrammfaktor(p),
                        Funcs_GetKreisfaktor(p),
                        suc);

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_KRUFTUR][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }

  daem = SetDaemType(caster,result,CHAOS_ID_KRUFTUR);

  printf("Du beschwoerst finstere Kraefte und oeffnest so ein Tor in "
         "andere Welten.\n");

  say(break_string(caster->Name(WER,1)+" grummelt irgendetwas "
      "Unverstaendliches und macht dabei magische Zeichen. Ploetzlich bildet "
      "sich ein Riss in der Realitaet."));

  daem->move(environment(caster),M_GO);
  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME, time()+ 30 + suc/1000 * 30);

  if(result!=DF||random(100)>daemon[CHAOS_ID_KRUFTUR][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
      daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  return ERFOLG;
}

int irkitis(object caster, mapping sinfo) {
  object daem, p;
  int result, suc;

  if(daem_already_present(caster,CHAOS_ID_IRKITIS)) {
    return ERFOLG;
  }

  suc    = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }
  p      = Funcs_GetPentagramm(caster);
  result = Funcs_TestPentagramm(daemon[CHAOS_ID_IRKITIS],
                        caster,
                        Funcs_GetPentagrammfaktor(p),
                        Funcs_GetKreisfaktor(p),
                        suc);

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_IRKITIS][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  daem = SetDaemType(caster,result,CHAOS_ID_IRKITIS);

  daem->SetProp(DAEM_DEFEND_FAKTOR,100);
  
  daem->SetProp(DAEM_COUNT_DOWN,caster->QueryAttribute(A_INT)+suc/1000);

  printf("Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in "
         "andere Welten.\n");

  say(caster->Name(WER,1)+" beschwoert unheimliche Kraefte und "
      "oeffnet ein Tor in andere Welten.\n");

  daem->move(environment(caster),M_TPORT);

  if(result!=DF || random(100)>daemon[CHAOS_ID_IRKITIS][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
      daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  if(result!=DF||random(100)>daemon[CHAOS_ID_IRKITIS][DAEM_FALSE]) {
    caster->AddDefender(daem);
  }
  if(p && !CHAOS_MAGIER(caster)) {
    p->starte_entfernen(10);
  }
  return ERFOLG;
}

int harkuhu(object caster, mapping sinfo)
{
  object daem, p;
  int result, suc;
  int pentagrammfaktor,kreisfaktor;
  
  if(daem_already_present(caster,CHAOS_ID_HARKUHU)) {
    return ERFOLG;
  }

  suc    = SpellSuccess(caster, sinfo);


  if(suc<=0) {
    return MISSERFOLG;
  }
  p                = Funcs_GetPentagramm(caster);
  pentagrammfaktor = Funcs_GetPentagrammfaktor(p);
  kreisfaktor      = Funcs_GetKreisfaktor(p);
  
  result = Funcs_TestPentagramm(daemon[CHAOS_ID_HARKUHU],
                        caster,
                        Funcs_GetPentagrammfaktor(p),
                        Funcs_GetKreisfaktor(p),
                        suc);

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_HARKUHU][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  daem = SetDaemType(caster,result,CHAOS_ID_HARKUHU);
  daem->SetProp(DAEM_DEFEND_FAKTOR,50);
  
  printf("Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in "
         "andere Welten.\n");

  say(break_string(caster->Name(WER,1)+" beschwoert unheimliche Kraefte und "
      "oeffnet ein Tor in andere Welten."));

  daem->move(environment(caster),M_TPORT);
  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+240+suc/1000*58);

  if(result!=DF || random(100)>daemon[CHAOS_ID_HARKUHU][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
       daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  if(result!=DF || random(100)>daemon[CHAOS_ID_HARKUHU][DAEM_FALSE]) {
    caster->AddDefender(daem);
  }
  if(p && !CHAOS_MAGIER(caster)) {
    p->starte_entfernen(6);
  }
  if ((kreisfaktor + pentagrammfaktor > 50) && 
     (suc +20*kreisfaktor+20*pentagrammfaktor > 7300) && !result) {
    tell_object(caster,break_string("Du hast Harkuhu ungewoehnlich gut "
                       "beschworen. In seinen leuchtenden Augen erkennst Du "
                       "ungewohnte Schaerfe."));

    daem->SetProp(DAEM_CAN_SPEAK,1);
  }
  daem->setPower(p,caster,sinfo[SI_SKILLABILITY]);
  return ERFOLG;
}

int graiop( object caster, mapping sinfo) {
  object daem, p;
  int result, suc;
  int pentagrammfaktor,kreisfaktor;
  
  if(daem_already_present(caster,CHAOS_ID_GRAIOP)) {
    return ERFOLG;
  }

  suc    = SpellSuccess(caster,sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }

  p      = Funcs_GetPentagramm(caster);
  pentagrammfaktor = Funcs_GetPentagrammfaktor(p);
  kreisfaktor      = Funcs_GetKreisfaktor(p);
    
  result = Funcs_TestPentagramm(daemon[CHAOS_ID_GRAIOP],
                        caster,
                        Funcs_GetPentagrammfaktor(p),
                        Funcs_GetKreisfaktor(p),
                        suc);

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_GRAIOP][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  daem = SetDaemType(caster,result,CHAOS_ID_GRAIOP);
  daem->SetProp(DAEM_DEFEND_FAKTOR,60);

  printf("Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in "
         "andere Welten.\n");

  say(break_string(caster->Name(WER,1)+" spricht magische Worte, die, "
      "zusammen mit abartigen Gesten, einen wilden, gefaehrlichen Daemonen "
      "aus den Tiefen der niederen Dimensionen rufen."));

  daem->move(environment(caster),M_TPORT);
  daem->SetProp(DAEM_COUNT_DOWN,caster->QueryAttribute(A_INT)+4*suc/1000);

  if(result!=DF||random(100)>daemon[CHAOS_ID_GRAIOP][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
       daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  if(result!=DF || random(100)>daemon[CHAOS_ID_GRAIOP][DAEM_FALSE]) {
    caster->AddDefender(daem);
  }
  if(p && !CHAOS_MAGIER(caster)) {
    p->starte_entfernen(8);
  }
  if ((kreisfaktor + pentagrammfaktor > 50) && 
      (suc +20*kreisfaktor+20*pentagrammfaktor > 7300) && !result) {
    tell_object(caster,"Du hast Graiop ungewoehnlich gut beschworen. In "
          "seinen feurigen Augen erkennst Du ungewohnte Tiefen.");

    daem->SetProp(DAEM_CAN_SPEAK,1);
  }
  daem->setPower(p,caster,sinfo[SI_SKILLABILITY]);
  return ERFOLG;
}

int flaxtri(object caster, mapping sinfo) {
  object daem, p;
  int result, suc;
  int pentagrammfaktor,kreisfaktor;

  if(daem_already_present(caster,CHAOS_ID_FLAXTRI)) {
    return ERFOLG;
  }

  suc    = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }
  p                = Funcs_GetPentagramm(caster);
  pentagrammfaktor = Funcs_GetPentagrammfaktor(p);
  kreisfaktor      = Funcs_GetKreisfaktor(p);

  result = Funcs_TestPentagramm(daemon[CHAOS_ID_FLAXTRI],
                        caster,
                        pentagrammfaktor,
                        kreisfaktor,
                        suc );

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_FLAXTRI][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  daem = SetDaemType(caster,result,CHAOS_ID_FLAXTRI);
  daem->SetProp(DAEM_DEFEND_FAKTOR,50);

  printf(break_string("Du beschwoerst unheimliche Kraefte und oeffnest so ein "
         "Tor in andere Welten."));

  say(break_string(caster->Name(WER)+" murmelt ein unheimliches "
      "Wort und beginnt sofort mit einem abartigen Tanz, dessen wilde Gesten "
      "geradezu obszoen sind."));

  daem->move(environment(caster),M_TPORT);

  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+300+300*suc/1000);
  daem->SetProp(CHAOS_DAEM_NO_DISAPPEAR,1);

  if(result!=DF||random(100)>daemon[CHAOS_ID_FLAXTRI][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
       daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  if(result!=DF||random(100)>daemon[CHAOS_ID_FLAXTRI][DAEM_FALSE]) {
    caster->AddDefender(daem);
  }
  if(p && !CHAOS_MAGIER(caster)) {
    p->starte_entfernen(10);
  }
  if ((kreisfaktor + pentagrammfaktor > 50) && 
      (suc +20*kreisfaktor+20*pentagrammfaktor > 7300) && !result) {
    tell_object(caster,break_string("Du hast Flaxtri ungewoehnlich gut "
                       "beschworen. In seinen boesartigen Augen bemerkst Du "
                       "erstaunliche Tiefen."));

    daem->SetProp(DAEM_CAN_SPEAK,1);
  }
  daem->setPower(p,caster,sinfo[SI_SKILLABILITY]);
  return ERFOLG;
}

int balal(object caster, mapping sinfo) {
  object daem, p;
  int result, suc;
  int pentagrammfaktor,kreisfaktor;
  
  if(daem_already_present(caster,CHAOS_ID_BALAL)) {
    return ERFOLG;
  }
  suc    = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }

  p      = Funcs_GetPentagramm(caster);
  pentagrammfaktor = Funcs_GetPentagrammfaktor(p);
  kreisfaktor      = Funcs_GetKreisfaktor(p);

  result = Funcs_TestPentagramm(daemon[CHAOS_ID_BALAL],
                        caster,
                        pentagrammfaktor,
                        kreisfaktor,
                        suc );

  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_BALAL][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }

  daem = SetDaemType(caster,result,CHAOS_ID_BALAL);
  daem->SetProp(DAEM_DEFEND_FAKTOR,50);
  
  printf(break_string("Du beschwoerst unheimliche Kraefte und oeffnest so ein "
         "Tor in andere Welten."));

  say(break_string(caster->Name(WER)+" murmelt ein unheimliches "
      "Wort und beginnt sofort mit einem abartigen Tanz, dessen wilde Gesten "
      "geradezu obszoen sind."));

  daem->move(environment(caster),M_TPORT);

  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,0);
  daem->SetProp(CHAOS_DAEM_NO_DISAPPEAR,1);

  if(result != DF || random(100)>daemon[CHAOS_ID_BALAL][DAEM_FALSE]) {
    caster->AddDefender(daem);
  }
  if(p && !CHAOS_MAGIER(caster)) {
    p->starte_entfernen(10);
  }
  daem->setPower(p,caster,sinfo[SI_SKILLABILITY]);
  return ERFOLG;
}

int tutszt(object caster, mapping sinfo) {
  object daem, p;
  int result, suc;
  int pentagrammfaktor,kreisfaktor;
  
  if(daem_already_present(caster,CHAOS_ID_TUTSZT)) {
    return ERFOLG;
  }
  suc    = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }

  p                = Funcs_GetPentagramm(caster);
  pentagrammfaktor = Funcs_GetPentagrammfaktor(p);
  kreisfaktor      = Funcs_GetKreisfaktor(p);

  result = Funcs_TestPentagramm(daemon[CHAOS_ID_TUTSZT],
                        caster,
                        pentagrammfaktor,
                        kreisfaktor,
                        suc);

  /* Test fuer Mist-Chaoten, welche Tutszt zum Ueben schlecht beschwoeren. */
  if (!result && !objectp(p)) {
    result = DA;
  }
  else if (!result && (p->QueryProp(CHAOS_PENTAGRAMM_FAKTOR) < 21 ||
                       p->QueryProp(CHAOS_BANNKREIS_FAKTOR) < 11)) {
    result = DA;
  }
  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_YRINTRI][WRONG_DAEM]);
    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_TUTSZT][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  daem = SetDaemType(caster,result,CHAOS_ID_TUTSZT);

  daem->SetProp(DAEM_DEFEND_FAKTOR,30);

  if(CHAOS_GILDENMASTER->ist_erz( caster)) {
    daem->Setprop(DAEM_DEFEND_FAKTOR,20);
  }
  printf(break_string("Du beschwoerst unheimliche Kraefte und oeffnest so ein "
         "Tor in andere Welten."));

  say(break_string(caster->Name(WER)+" fuchtelt wie wild mit den Armen herum, "
      "stoesst boesartige Worte einer magischen Sprache hervor und vollfuehrt "
      "mit "+(caster->QueryProp(P_GENDER)==1?"seinen":"ihren")+" Fuessen einen "
      "seltsamen Tanz."));

  daem->move(environment(caster),M_TPORT);
  daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+1000+500*suc/1000);
  daem->SetProp(CHAOS_DAEM_NO_DISAPPEAR,1);

  if(result!=DF||random(100)>daemon[CHAOS_ID_TUTSZT][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if (sinfo[SI_SKILLARG] == "leise") {
      daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  if(result!=DF||random(100)>daemon[CHAOS_ID_TUTSZT][DAEM_FALSE]) {
    caster->AddDefender(daem);
  }
  if(p && !CHAOS_MAGIER(caster)) {
    p->starte_entfernen(10);
  }
  if ((kreisfaktor + pentagrammfaktor > 50) && 
      (suc +20*kreisfaktor+20*pentagrammfaktor > 7300) && !result) {
    tell_object(caster,break_string("Du hast Tutszt ungewoehnlich gut "
                       "beschworen. In seinen dunklen Augen erkennst Du eine "
                       "ungewohnte Schaerfe."));
                       
    daem->SetProp(DAEM_CAN_SPEAK,1);
  }
  if (result != DA) {
    daem->setPower(p,caster,sinfo[SI_SKILLABILITY]);
  }
  return ERFOLG;
}

int yrintri(object caster, mapping sinfo) {
  object mon, obj;
  int result, suc;
  int pentagrammfaktor, kreisfaktor;

  if(!CHAOS_GILDENMASTER->ist_erz(caster) && !CHAOS_MAGIER(caster)) {
    if(caster->QueryProp(P_GUILD_LEVEL)==12) {
      caster->SetProp(P_GUILD_LEVEL,11);
    }
    tell_object(caster,"Du bist nicht der Erzmeister des Chaos!\n");
    return 0;
  }
  if(daem_already_present(caster,CHAOS_ID_YRINTRI)) {
    return ERFOLG;
  }
  suc    = SpellSuccess(caster, sinfo);

  if(suc<=0) {
    return MISSERFOLG;
  }
  
  obj    = Funcs_GetPentagramm(caster);

  kreisfaktor      = Funcs_GetKreisfaktor(obj);
  pentagrammfaktor = Funcs_GetPentagrammfaktor(obj);
  
  result = Funcs_TestPentagramm(daemon[CHAOS_ID_YRINTRI],
                        caster,
                        pentagrammfaktor,
                        kreisfaktor,
                        suc );

  /* Test fuer Mist-Chaoten, welche Yrintri zum Ueben schlecht beschwoeren. */
  if (!result && !objectp(obj)) {
    result = DA;
  }
  else if (!result && (obj->QueryProp(CHAOS_PENTAGRAMM_FAKTOR) < 22 ||
                       obj->QueryProp(CHAOS_BANNKREIS_FAKTOR) < 12)) {
    result = DA;
  }
  if(result==WD) {
    call_out("falscher_daemon",0,caster,daemon[CHAOS_ID_YRINTRI][WRONG_DAEM]);

    if(obj && !CHAOS_MAGIER(caster)) {
      obj->starte_entfernen(10);
    }
    return ERFOLG;
  }
  mon = SetDaemType(caster,result,CHAOS_ID_YRINTRI);
  mon->SetProp(DAEM_DEFEND_FAKTOR,15);

  tell_object(caster,break_string("Du beschwoerst unheimliche Kraefte und "
                     "oeffnest so ein Tor in andere Welten."));

  say(break_string(caster->Name(WER,1)+" fuchtelt wie wild mit den Armen "
      "herum, stoesst boesartige Worte einer magischen Sprache hervor und "
      "vollfuehrt mit "+(caster->QueryProp(P_GENDER)==1?"seinen":"ihren")+
      " Fuessen einen seltsamen Tanz."));

  mon->move(environment(caster),M_TPORT);
  mon->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+2000+500*suc/1000);
  mon->SetProp(CHAOS_DAEM_NO_DISAPPEAR,1);

  if(result!=DF||random(100) > daemon[CHAOS_ID_YRINTRI][DAEM_FALSE]) {
    caster->AddPursuer(mon);

    if (sinfo[SI_SKILLARG] == "leise") {
      mon->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  if(result!=DF || random(100) > daemon[CHAOS_ID_YRINTRI][DAEM_FALSE]) {
    caster->AddDefender(mon);
  }
  if(obj && !CHAOS_MAGIER(caster)) {
    obj->starte_entfernen(10);
  }
  if ((kreisfaktor + pentagrammfaktor > 50) && 
      (suc +20*kreisfaktor+20*pentagrammfaktor > 7300) && !result) {
    tell_object(caster,break_string("Du hast Yrintri ungewoehnlich gut "
                       "beschworen. In seinen boesen Augen erkennst Du eine "
                       "ungewohnte Schaerfe."));

    mon->SetProp(DAEM_CAN_SPEAK,1);
  }
  if (result != DA) { /* Aggressive Daemonen kriegen FULL POWER! */
    mon->setPower(obj,caster,sinfo[SI_SKILLABILITY]);
  }
  return ERFOLG;
}


void falscher_daemon(object caster, int wd) {
  object daem;

  if(!caster) {
    return;
  }
  tell_object(caster,break_string("Oh oh! Da lief was schief. Du hast einen "
              "entscheidenden Fehler gemacht und so einen anderen Daemon als "
              "erwartet beschworen!"));

  say(break_string("Oh oh! "+caster->Name(WER,1)+" muss irgendetwas falsch "
      "gemacht haben! "+(caster->QueryProp(P_GENDER)==1?"Er":"Sie")+
      " wird ploetzlich ganz weiss im Gesicht und flucht lautstark."),caster);

  switch(random(wd)) {
    case 0..3:
      daem = clone_object(CHAOS_GILDEN_MON("uebmatu"));

      tell_room(environment(caster),"Ein laecherlicher Daemon, Uebmatu "
                "genannt, faellt herein.\n");
      break;
    case 4..7:
      daem = clone_object(CHAOS_GILDEN_MON("anthukt"));

      tell_room(environment(caster),"Ein spinnenaehnlicher Daemon mit "
                "Ziegenkopf krabbelt herein.\n");
      break;
    case 8..12:
      daem = clone_object(CHAOS_GILDEN_MON("chochos"));

      tell_room(environment(caster),"Ein schwarzer Daemon schleicht in diese "
                "Dimension!\n");
      break;
    case 13..18:
      daem = clone_object(CHAOS_GILDEN_MON("daedhel"));

      tell_room(environment(caster),"Daedhel stuermt wild herein! Flieht, "
           "Sterbliche!\n");
      break;
    case 19..33:
      daem = clone_object(CHAOS_GILDEN_MON("hothrog"));

      tell_room(environment(caster),break_string("Ein boesartiger Daemon, er "
                "ist unter dem Namen Hothrog bekannt,beschworen von "
                +caster->name(WEN)+", stuermt herein!"));
      break;
    case 34..60:
      daem = clone_object(CHAOS_GILDEN_MON("rythoth"));

      tell_room(environment(caster),break_string("Ein uebler Hetzerdaemon, "
                "bekannt unter der Bezeichnung Rythoth, hetzt herein, auf "
                "der Suche nach blutigen Opfern!"));
      break;
    default:
      tell_object( caster, "Es passiert nichts.\n");
  }
  if(daem) {
    daem->SetProp(DAEM_AGGRESSIVE,getuid(caster));
    daem->setDaemBeschwoerer(caster);
    daem->move(environment(caster),M_GO|M_SILENT);
  }
}
