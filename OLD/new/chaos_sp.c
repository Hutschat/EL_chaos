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
  SP: 20, Level: 5, Schaden: 100 + level/27 * random(400);
  Restriktionen: Hands: 2, man muss eine Chaosruestung tragen.
Chaosschaden:
  Legt den Schaden der naechsten 1+level/2 Chaosbaelle fest. Der
  eingestelle Schaden kommt bei einer SI_SKILLABILITY von 10000
  mit 95%iger Wahrscheinlichkeit.
  SP: 20, Level: 6
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
Kruftur:
  Daemon, der Gegenstaende identifiziert.
  SP: 10, Level: 6
Ombatis:
  Ein nervender Daemon wird beschworen, mit dem man andere Spieler 
  ein klein wenig aergern kann. Er folgt dem Spieler und labert ihn
  dumm an. Aehnlich dem Eusebius (c) Puma :-)
  SP: 80, Level: 7
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

#include <properties.h>
#include <language.h>
#include <attributes.h>
#include <combat.h>
#include <wizlevels.h>
#include <moving.h>
#include <new_skills.h>
#include "/gilden/files.chaos/gilde.h"

mapping daemon;
string ChaosDamageText( string dam_type, int plu);
string ChaosDamage(object caster, int suc);
int check_result( string daem, object caster, int pentaf, int kreisf, int abil);

inherit "/std/spellbook";

create() {
  ::create();
  SetProp(P_GLOBAL_SKILLPROPS,
      ([SI_SPELLFATIGUE:2,    
    SI_SKILLLEARN:2,      
      OFFSET(SI_SKILLLEARN):2 
      ]));
  AddSpell( "chaosball",20,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:5]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"CheckRuestung"]), SI_DIFFICULTY:20 
      ]));
  AddSpell( "verbanne", 30,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:7]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"CheckRuestung"]),
       SI_DIFFICULTY:50,
       SI_SKILLDAMAGE_TYPE:DT_SOUND
       ])); 
  AddSpell( "schutz", 25, 
    ([ SI_SKILLRESTR_LEARN:([ P_GUILD_LEVEL:4]),
      SI_SKILLRESTR_USE:([SR_FREE_HANDS:1,
      SR_FUN:"CheckRuestung"]),
      SI_DIFFICULTY:40
      ])); 
  AddSpell( "dunkelheit",10, 
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:2]),
       SI_DIFFICULTY:-10,
       SI_SKILLLEARN:4,      
        OFFSET(SI_SKILLLEARN):6 
       ]));  
  AddSpell( "nachtsicht",10, 
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:1]),
       SI_DIFFICULTY:-20,    
      SI_SKILLLEARN:4,      
      OFFSET(SI_SKILLLEARN):6,
      SI_NOMAGIC:100,
       ]));  
  AddSpell( "chaosruestung",95,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:3]),
       SI_SKILLRESTR_USE:([SR_GOOD:500, 
       SR_FREE_HANDS:2]),
       SI_DIFFICULTY:70,
       SI_SPELLFATIGUE:50,
      OFFSET(SI_SKILLLEARN):10     
       ]));  
  AddSpell( "kontrolle", 20,
      ([ SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:3]),
       SI_SKILLRESTR_USE:([SR_FUN:"CheckRuestung"]),
       SI_DIFFICULTY:50,
       SI_SPELLFATIGUE:20,
       OFFSET(SI_SKILLLEARN):5,
       SI_NOMAGIC:100,
      ]));
  AddSpell( "finsternis",100,             
     ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:8]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"CheckFinsternis"]), SI_DIFFICULTY:120,  
       SI_SKILLLEARN:4,      
       ]));
  AddSpell( "chaosschaden",20,         
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:6]),
       SI_DIFFICULTY:20 
       ]));
  AddSpell( "bannzauber",10,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:4]),
       SI_DIFFICULTY:-10, 
       SI_SPELLFATIGUE:4     
       ]));
  AddSpell( "binde", 40,
       ([ SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:9]),
       SI_DIFFICULTY:90,
       SI_SKILLRESTR_USE:([SR_FUN:"CheckRuestung"]),
       SI_SPELLFATIGUE:10
       ]));
  AddSpell( "intarbir",5,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:4,
       SR_GOOD:200]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"CheckKleinerDaemon" ]),
       SI_DIFFICULTY:-50,
       SI_SPELLFATIGUE:3,
       OFFSET(SI_SKILLLEARN):8      
       ]));
  AddSpell( "kruftur",10,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:5,
       SR_GOOD:100]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"CheckKleinerDaemon" ]),
       SI_DIFFICULTY:-20,
       SI_SPELLFATIGUE:3,
       OFFSET(SI_SKILLLEARN):6
       ]));
  AddSpell( "ombatis",80,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:6,
       SR_GOOD:-100]),
       SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
       SR_GOOD:500, SR_FUN:"CheckKleinerDaemon" ]),
       SI_DIFFICULTY:10,
       SI_SPELLFATIGUE:10,
       OFFSET(SI_SKILLLEARN):6 
       ]));
  AddSpell( "irkitis",50,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:7,
       SR_GOOD:300]),
       SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
       SR_GOOD:600, SR_FUN:"DaemonenTest" ]),
       SI_DIFFICULTY:20,
       SI_SPELLFATIGUE:6     
       ]));
  AddSpell( "harkuhu",50,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:8,
       SR_GOOD:400]),
       SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
       SR_GOOD:500, SR_FUN:"DaemonenTest"]),
       SI_DIFFICULTY:30,
       SI_SPELLFATIGUE:10     
       ]));
  AddSpell( "graiop",90,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:9,
       SR_GOOD:200]),                      
       SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
       SR_GOOD:400, SR_FUN:"DaemonenTest" ]),
       SI_DIFFICULTY:50,
       SI_SPELLFATIGUE:15     
       ]));
  AddSpell( "flaxtri",120,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:10,  
       SR_GOOD:-100]),                      
       SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
       SR_GOOD:300, SR_FUN:"DaemonenTest" ]),
       SI_DIFFICULTY:80,
       SI_SPELLFATIGUE:20     
       ]));
  AddSpell( "tutszt",140,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:11,
      SR_GOOD:-500 ]),                      
       SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
       SR_GOOD:100, SR_FUN:"DaemonenTest" ]),
       SI_DIFFICULTY:100,
       SI_SPELLFATIGUE:30     
       ]));    
  AddSpell( "yrintri", 180,
      ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:12,
      SR_GOOD:-700 ]),                      
       SI_SKILLRESTR_USE:([SR_FREE_HANDS:2,
       SR_GOOD:0, SR_FUN:"DaemonenTest", 
       P_GUILD_LEVEL:12 ]),
       SI_DIFFICULTY:150,
       SI_SPELLFATIGUE:60     
       ]));    

/* Dieses mapping enthaelt die Eigenschaften der Daemonen. Es sind die
   Wahrscheinlichkeiten mit denen der Daemon eine bestimmte Handlung 
   ausfuehrt. */
  daemon = ([   
      "intarbir":([DAEM_AGGRESSIVE:1, DAEM_DISAPPEAR:3,
                  DAEM_FALSE:7, WRONG_DAEM:1]),
      "kruftur":([DAEM_AGGRESSIVE:1, DAEM_DISAPPEAR:2,
                  DAEM_FALSE:10, WRONG_DAEM:2]),
      "ombatis":([DAEM_AGGRESSIVE:10, DAEM_DISAPPEAR:10,
                  DAEM_FALSE:25, WRONG_DAEM:15 ]),
      "irkitis":([DAEM_AGGRESSIVE:5, DAEM_DISAPPEAR:15,
                  DAEM_FALSE:10, WRONG_DAEM:20 ]),
      "harkuhu":([DAEM_AGGRESSIVE:15, DAEM_DISAPPEAR:10,
                  DAEM_FALSE:15, WRONG_DAEM:30 ]),
      "graiop":([DAEM_AGGRESSIVE:20, DAEM_DISAPPEAR:15,
                  DAEM_FALSE:20, WRONG_DAEM:25 ]),
      "flaxtri":([DAEM_AGGRESSIVE:30, DAEM_DISAPPEAR:20,
                  DAEM_FALSE:25, WRONG_DAEM:35 ]),
      "tutszt":([DAEM_AGGRESSIVE:35, DAEM_DISAPPEAR:25,
                  DAEM_FALSE:30, WRONG_DAEM:45 ]),
      "yrintri":([DAEM_AGGRESSIVE:45, DAEM_DISAPPEAR:35,
                  DAEM_FALSE:35, WRONG_DAEM:55 ])
            ]);
}  


void Misserfolg( object caster, string spell, mapping sinfo)
{
  int old_abil;
  write( "Der Zauberspruch ist missglueckt.\n");
  old_abil = sinfo[SI_SKILLABILITY];
  Learn(caster, spell, sinfo);
  if( old_abil < caster->QuerySkillAbility( spell))
    write( "Du lernst aus Deinen Fehlern.\n");
  else write( "Du lernst nicht aus Deinen Fehlern.\n");
}


string CheckRuestung(object caster, mapping sinfo)
{
object rue;
if( !rue = present( "\nchaos_ruestung", caster))
    return "Du musst fuer diesen Spruch eine Chaos-Ruestung tragen.\n";
return 0;
}

string CheckFinsternis(object caster, mapping sinfo)
{
object rue;
int fin;
if( !rue = present( "\nchaos_ruestung", caster))
  return "Du musst fuer diesen Spruch eine Chaos-Ruestung tragen.\n";
fin = caster->QueryProp( CHAOS_FINSTERNIS);
  if( fin && time() < fin )
  return "Du kannst diesen Spruch nicht so haeufig hintereinander anwenden.\n";
return 0;
}

/* Es gibt Raeume, die sind fuer das Beschwoeren von Daemonen ungeeignet
   (z.B. Abenteurergilde etc.) Das array ist in /gilden/files.chaos/gilde.h
   definiert */
string CheckKleinerDaemon( object caster, mapping sinfo)
{
  if( member( VERBOTENE_RAEUME, file_name( environment(caster))) != -1)
    return "Die Umgebung ist fuer das Beschwoeren von Daemonen ungeeignet.\n";
  if( caster->QueryProp( P_FROG))
    return "Du willst doch wohl nicht als Frosch einen Daemonen beschwoeren?\n";  
  return 0;
}


string DaemonenTest(object caster, mapping sinfo)
{
  int i, si;
  string *v, f;
  object rue;
  f = file_name( environment(caster));
  v = VERBOTENE_RAEUME;
  if( !rue = present( "\nchaos_ruestung", caster))
    return "Du musst fuer diesen Spruch eine Chaos-Ruestung tragen.\n";
  if( member( v, f) != -1)
    return "Die Umgebung ist fuer das Beschwoeren von Daemonen ungeeignet.\n";
  si = sizeof(v);
  for( i=0;i<si;i++)
  {
    if(v[i] == f[0..sizeof(v[i])-1] ) return "Die Umgebung ist fuer das Beschwoeren von Daemonen ungeeignet.\n";
  }
  if( caster->QueryProp( P_FROG))
    return "Du willst doch wohl nicht als Frosch einen Daemonen beschwoeren?\n";
  return 0;
}
                                

int dunkelheit(object caster, mapping sinfo) 
{
  int zeit, light, suc;
  suc = SpellSuccess( caster, sinfo);
  if( member( VERBOTENE_RAEUME, file_name(environment(caster)))!=-1)
  {
    printf( "Der Raum laesst sich nicht verdunkeln.\n");
    return 0;
  }
  if( environment(caster)->_query_total_light() <= 
      0 - caster->QueryProp( P_GUILD_LEVEL)/2)
  {
    printf( "Es ist hier zu dunkel!\n");
    return 0;
  }
  if ( -2000 <= suc && suc <= 0) return MISSERFOLG;
  printf("Du beschwoerst dunkle Maechte.\n");
  say(sprintf("%s beschwoert dunkle Maechte.\n", capitalize(caster->name())));
  zeit = caster->QueryProp( P_GUILD_LEVEL) * 15;
  light = environment(caster)->QueryProp( P_LIGHT) -1;
  if( suc < - 2000)
  {
    printf( "Mist, der Spruch ging daneben! Es wird ploetzlich heller!\n");
    light = light + 2;
    "/obj/tmp_prop_master"->SetTmpProp( environment(caster),P_LIGHT,
      light, zeit);
    return MISSERFOLG;
  }
  "/obj/tmp_prop_master"->SetTmpProp( environment(caster),P_LIGHT,
      light, zeit);
  printf("Du verdunkelst Deine Umgebung.\n");
  return ERFOLG;
}

/* Die Chaosgilde benutzt die Maechte der Finsternis. Deshalb koennen ihre
   Mitglieder auch viel leichter die Nachtsicht benutzen, als in anderen
   Gilden. */
int nachtsicht(object caster, mapping sinfo) 
{
   int zeit, suc;
   suc = SpellSuccess( caster, sinfo);
   if( caster->QueryProp( CHAOS_GILDEN_NACHTSICHT) > time())
  {
  printf( "Du hast doch schon die Nachtsicht aktiviert!\n");
  return 0;
  }
   if( suc <= - 2500)
  {
  printf( "Mist! Deine Augen werden nachtblind!\n");
  caster->SetProp( CHAOS_GILDEN_NACHTBLIND, time() + 60);
  return MISSERFOLG;
  }
   if ( suc <=0)
    return MISSERFOLG;
   if( time() < caster->QueryProp( CHAOS_GILDEN_NACHTBLIND))
  {
  printf( "Deine Augen sind zur Zeit nachtblind!\n");
  return  0;
  }
   printf( "Du veraenderst magisch Deine Augen.\n");
   say( capitalize( caster->name(WESSEN))+" Augen leuchten kurz dunkelrot auf.\n", caster);
   zeit = time() + caster->QueryProp( P_GUILD_LEVEL) * 40;
   caster->SetProp( CHAOS_GILDEN_NACHTSICHT, zeit );
  return ERFOLG;
}
 


int schutz( object caster, mapping sinfo)
{
  object victim, haut;
  int ac, level, suc, zeit;
  string str;
  str = sinfo[SI_SKILLARG];
  suc = SpellSuccess(caster, sinfo);
  haut = present( "\nchaos_ruestung", caster );
  if( !haut )
  {
    printf( "Du hast keine Chaosruestung!\n" );
    return 0;
  }
  if( !haut->id( "neue_ruestung"))
  {
    printf( "Besorg Dir erstmal eine neue Chaosruestung!\n");
    return 0;
  } 
  if( haut->QueryProp( RUEST_SCHUTZ ))
  {
    printf( "Die Chaosruestung ist schon magisch veraendert!\n");
    return 0;
  }
  if( str && str != "schwach" && str != "stark" )
  {
    printf( "Diese Art von Schutz kannst Du nicht waehlen.\n" );
    return 0;
  }
  if( -2000 < suc && suc <= 0 ) return MISSERFOLG;
  level = caster->QueryProp( P_GUILD_LEVEL );
  printf( "Du fuchtelst wie wild mit einer Hand herum (keiner weiss, warum\n"
  +"man das bei diesem Spruch so machen muss).\n");
  say( break_string( capitalize(caster->name())+
  " fuchtelt wie bescheuert mit einer Hand herum. Hat "+
    caster->QueryPronoun()+" einen Schaden?\n", 78) );
  if( suc <= - 2000)
  {
    ac = suc/100 + level;
    if( ac > 0) ac = 0;
    if( ac < -20) ac = -20;
    printf( "Mist, Du verschlechterst die Chaosruestung!\n");
    haut->verbessere_ruestung( ac, random(20) );
    return MISSERFOLG;
  }
  if( !str || str == "schwach" )
  {
    ac = 10 + suc/200 + random( level * 5);
    zeit = 4 + 2 * level + suc/600 + random( level * 5);
  }
  if( str == "stark" )
  {
    ac = 20 + suc/100 + 3 * level + random( level * 7); 
    zeit = 1 + random(10)+ suc/1000 + random( level );
  }
  printf( "Du verstaerkst den Schutz der Chaoshaut.\n");
  haut->verbessere_ruestung( ac, zeit );
  return ERFOLG;          
}


BeschaedigeWaffe(object waffe)
{
  printf( break_string( "Du hast wohl die falsche Magie durch "+
    waffe->name(WEN,1)+" fliessen lassen! "+
    capitalize(waffe->QueryPronoun())+" wird etwas beschaedigt!", 78));
  waffe->Damage(5 + random(20));
}  


int CheckDamTypes( mixed dt, string dam_type, object waffe)
{
  int wc;    
  /*
  Morgoth hat es abgeschwaecht, also ists wieder benutzbar.
  if( !random(5) && 
      explode(file_name(waffe), "#")[0] == "/d/vland/morgoth/obj/eschwert" )
  {
    printf( "Der Chaosball zerschiesst %s zu Staub!!!\n", waffe->name(WEN,1));
    waffe->remove(1);
    return -500;
  } 
  */
  wc = waffe->QueryProp(P_WC)/2;

  if( member( dt, dam_type) != -1) return random(wc);
  switch( dam_type)
  {
    case DT_FIRE:
      if( member( dt, DT_COLD) != -1 || member( dt, DT_WATER) != -1 )
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_COLD:
      if( member( dt, DT_FIRE) != -1 )
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_WATER:
      if( member( dt, DT_FIRE) != -1 || member( dt, DT_AIR) != -1 )
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_AIR:
       if( member( dt, DT_SOUND) != -1 )
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_SOUND:
      if( member( dt, DT_MAGIC) != -1 )
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_LIGHTNING:
       if( member( dt, DT_COLD) != -1 )
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_POISON:
       if( member( dt, DT_ACID) != -1 || member(dt, DT_LIGHTNING) != -1)
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_ACID:
       if( member( dt, DT_WATER) != -1 || member(dt, DT_LIGHTNING) != -1)
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_UNHOLY:  
      if( member( dt, DT_HOLY) != -1 || member( dt, DT_MAGIC) != -1)
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_MAGIC:
      if( member( dt, DT_POISON) != -1 )
      {
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
  }
  return 0;
}
  
    
int chaosball(object caster, mapping sinfo) 
{
  object victim, waffe;
  int dam, level, suc;
  string vn, vnw, cn, dam_type, dam_txt;
  mixed dt;


  victim=FindEnemyVictim(sinfo[SI_SKILLARG],caster,
       "Nach wem willst Du einen Chaosball werfen?\n");
  if (!victim)
  return 0;
  suc = SpellSuccess(caster, sinfo);


  cn = caster->name();
  vnw = victim->name(WEN, 2);
   dam_type = ChaosDamage(caster, suc);       
   dam_txt = ChaosDamageText(dam_type, 0);
   level = caster->QueryProp(P_LEVEL);
   if( level > 27 ) level = 27;
   dam = 100 + random(400 * level)/27;
  if( suc < -2500)
  {
  printf( "Hilfe! Der Spruch ging nach hinten los!\n"
    +"Du feuerst "+dam_txt+" auf Dich ab.\n");
  say( sprintf( "%s feuert "+dam_txt+" auf sich ab.\n", capitalize(cn)));
  SetProp( P_NAME, "Unberechenbares Chaos" );
  caster->do_damage( dam/14, caster);
  return MISSERFOLG;
  }
  if( suc <= 0) return MISSERFOLG;
  
  say(sprintf("%s feuert "+dam_txt+" auf %s ab.\n",cn, vnw),
    victim);
  printf("Du feuerst "+dam_txt+" auf %s ab.\n", vnw);
  tell_object(victim,sprintf("%s feuert "+dam_txt+
  " auf Dich ab.\n", cn));
  
  if( objectp(waffe = caster->QueryProp(P_WEAPON)))
  {
     dt = waffe->QueryProp( P_DAM_TYPE);
     if( stringp(dt)) dt = ({ dt });
     if( !member( PHYSICAL_DAMAGE_TYPES, dam_type))
                 dam += CheckDamTypes( dt, dam_type, waffe );
  }
  sinfo += ([ SI_SKILLDAMAGE_TYPE:({ dam_type }) ]);
  TryAttackSpell(victim,dam, dam_type,([ SP_SHOW_DAMAGE:1,
  SI_SKILLDAMAGE_TYPE:dam_type ]),caster,sinfo);
  return ERFOLG;
}


string ChaosDamage(object caster, int suc)
{
string *types, dam_type;
int anzahl;
mixed chaos_dam_type;
types = ({ DT_BLUDGEON, DT_SLASH, DT_PIERCE, DT_FIRE, DT_COLD, DT_ACID,
       DT_LIGHTNING, DT_WATER, DT_AIR, DT_MAGIC, DT_POISON,
       DT_SOUND, DT_UNHOLY });
if( !caster->QueryProp( CHAOS_DAM_TYPE) || 
 random(10100) >= caster->QuerySkillAbility( "chaosschaden") ) 
    dam_type = types[random(sizeof(types))];
else 
   {
    chaos_dam_type = caster->QueryProp( CHAOS_DAM_TYPE);
    anzahl = chaos_dam_type[1] - 1;
    dam_type = chaos_dam_type[0];     
    if( chaos_dam_type[1] < 2) caster->SetProp(CHAOS_DAM_TYPE, 0);
    else 
     caster->SetProp( CHAOS_DAM_TYPE, ({ dam_type, anzahl })); 
   }
return dam_type;
}


string ChaosDamageText( string dam_type, int plu)
{
  if(!dam_type) return "";
  switch( dam_type)
  {
    case DT_FIRE:
      if(plu) return "lodernde Flammenkugeln";
      return "eine lodernde Flammenkugel";
    case DT_AIR: 
      if(plu) return "todbringende Stuerme";
      return "einen todbringenden Sturm";
    case DT_MAGIC: 
      if(plu) return "magische Strahlen";
      return "einen magischen Strahl";
    case DT_WATER: 
      if(plu) return "ueble Wasserstrahlen";
      return "einen ueblen Wasserstrahl"; 
    case DT_COLD: 
      if(plu) return "frostige Eiswolken";
      return "eine frostige Eiswolke";
    case DT_ACID: 
      if(plu) return "aetzende Saeureregen";
      return "einen aetzenden Saeureregen";
    case DT_LIGHTNING: 
      if(plu) return "fuerchterliche Blitze";
      return "einen fuerchterlichen Blitz";
    case DT_BLUDGEON: 
      if(plu) return "harte Felsbrocken";
      return "einen harten Felsbrocken";
    case DT_PIERCE: 
      if(plu) return "eherne Pfeile";
      return "einen ehernen Pfeil";
    case DT_SLASH: 
      if(plu) return "rotierende Messer";
      return "ein rotierendes Messer";
    case DT_POISON:
      if(plu) return "konzentrierte Gifte";
      return "konzentriertes Gift";
    case DT_SOUND:
      if(plu) return "schrille Kampfschreie";
      return "einen schrillen Kampfschrei"; 
    case DT_UNHOLY:
      if(plu) return "satanische Flueche";
      return "einen satanischen Fluch";
    case DT_TERROR:
      if(plu) return "hinterhaeltige Terrorattacken";
      return "eine hinterhaeltige Terrorattacke";
    case DT_WHIP:
      if(plu) return "wirbelnde Peitschenhiebe";
      return "einen wirbelnden Peitschenhieb";
    default: 
      if(plu) return "unbekannte Angriffe";
      return "einen Chaosball";
  }
}


int verbanne( object caster, mapping sinfo)
{
  string bla, blub, str;
  int resi, suc, dam;
  object victim;
  suc = SpellSuccess(caster, sinfo);
  str = sinfo[SI_SKILLARG];
  if( str == "haut" || str == "chaoshaut" || str == "chaosruestung" )
  {   
      notify_fail( "Wen willst Du verbannen?\n");
      if( !victim = present( "\nchaos_ruestung", caster )) return 0;
      if( suc <= 0) return MISSERFOLG;
      printf( "Du richtest Deine ganze Macht gegen den Daemon in Deiner Haut!\n");
      say( capitalize(caster->name())+" wirft wuetende Worte gegen sich selber!\n",
        ({ caster }));
      if( suc > 2000 )
      {
        victim->remove_it();
        return ERFOLG;
      }
      else if( suc > 5)
      {
        printf( "Aua! Der Daemon rebelliert kurz aber kraeftig!\n");
        caster->reduce_hit_point( 10 + random(10));
        victim->remove_it();
        return ERFOLG;
      }
      else 
      {
        printf( "Die Verbannung hat nicht so ganz geklappt, Du hast den Chaosdaemonen\n"
          +"nur veraergert!\n");
        victim->SetProp( DAEM_FALSE, 1 );
        victim->chaos_chaos_chaos(26); 
        return ERFOLG;
      }
  }
  victim=FindEnemyVictim(sinfo[SI_SKILLARG],caster,
     "Wen willst Du verbannen?\n");
  if( !victim ) return 0;
  if( !victim->id( "daemon") && !sscanf( victim->name(), "%sdaemon%s",
    bla, blub) && !victim->QueryProp(CHAOS_DAEM_BESCHWOERER) &&
    lower_case(victim->QueryProp( P_RACE)) != "daemon" &&
    !sscanf( to_string( victim->QueryProp( P_SHORT)), "%sdaemon%s",
    bla, blub) )
  {
    printf( "%s kannst Du nicht verbannen!\n", capitalize(victim->name()));
    return 0;
  }
  if( suc <= 0) return MISSERFOLG;
  printf( "Du hebst die Arme empor und wirfst uebelste Worte gegen %s.\n",
       victim->name(WEN) );
  say( capitalize(caster->name())+" hebt die Arme empor und wirft uebelste Worte gegen "+
  victim->name(WEN)+".\n" );
  if( victim->id( "chaos_aggressive_daemonen" ))
    {
      resi = victim->QueryProp(P_HANDS)[1];
      if( victim->QueryProp( CHAOS_DAEM_BESCHWOERER) == getuid(caster))
  resi = random(resi * 50);
      else resi = random( resi * 70);
      if( suc > resi )
      {
      printf( break_string( "Der Spruch war ein voller Erfolg! %s "+
  "verschwindet aus dieser Dimension.", 78), 
  capitalize( victim->name()) );
      victim->die();
      return ERFOLG;
      }
      else dam = 250 + random(700);
    }
   else if( victim->id( "\nchaos_gilden_daemon" ))
    {
      resi = victim->QueryProp( DAEM_FAKTOR_MAPPING)[DAEM_AGGRESSIVE];
      if( victim->QueryProp( CHAOS_DAEM_BESCHWOERER) == getuid(caster))
      resi = random( resi * 285 );
      else resi = random( resi * 305 );
      if(suc > resi)
      {  
  printf( break_string( "Der Spruch war ein voller Erfolg! %s "+
    "verschwindet aus dieser Dimension.", 78), 
    capitalize( victim->name()) );
  victim->die();
  return ERFOLG;
      }
      else dam = 250 + random(600);
    }
    else dam = 200 + random(700); // Gegen Nicht-Gilden-Daemonen
  TryAttackSpell(victim,dam, DT_SOUND,([ SP_NAME:"verbanne", SP_SHOW_DAMAGE:1]),
    caster,sinfo);
  return ERFOLG;
}


int finsternis(object caster, mapping sinfo)
{
  object victim;
  int zeit, suc;
  string cn, vnw;

  victim=FindEnemyVictim(sinfo[SI_SKILLARG],caster,
     "Wen willst Du mit einer Finsternis belegen?\n");
  if (!victim)
  return 0;
  suc = SpellSuccess(caster, sinfo);
  if( suc < - 2000 )
  {
  printf( "Oh weia! Jetzt hast Du den Zauber gegen Dich angewendet!\n");
  caster->SetProp( P_DISABLE_ATTACK, 20);
  }
  if ( suc <= 0) return MISSERFOLG;
  cn = caster->name();
  vnw = victim->name(WEN, 2);
  say(sprintf("%s huellt %s in einer Wolke aus Finsternis ein.\n",cn, vnw),
    victim);
  printf("Du huellst "+vnw+" in eine Wolke aus Finsternis ein.\n", vnw);
  tell_object(victim,
  sprintf("%s huellt Dich in eine Wolke aus Finsternis ein.\n", cn));
  zeit = 4 + caster->QueryAttribute(A_INT) + random(suc/500);
  zeit = sinfo[SI_SKILLABILITY] * zeit/MAX_ABILITY;
  victim->SetProp(P_DISABLE_ATTACK, victim->QueryProp(P_DISABLE_ATTACK)+zeit);
  caster->SetProp( CHAOS_FINSTERNIS, time() + 1300 - suc/10 );
  return ERFOLG;
}


int chaosschaden(object caster, mapping sinfo)
{
  string dam_type, str, txt1, txt2, *exp;
  int anzahl, sp, suc;
  mixed chaos_dam_type;
  mapping schaden;
  schaden = ([ 
    "feuer":DT_FIRE, 
    "eis":DT_COLD, 
    "sturm":DT_AIR,
    "magie":DT_MAGIC,
    "wasser":DT_WATER, 
    "blitz":DT_LIGHTNING, 
    "pfeil":DT_PIERCE, 
    "messer":DT_SLASH, 
    "felsen":DT_BLUDGEON, 
    "saeure":DT_ACID, 
    "gift":DT_POISON, 
    "krach":DT_SOUND, 
    "boese":DT_UNHOLY,
    "terror":DT_TERROR,
    "peitsche":DT_WHIP 
    ]);
  str = sinfo[SI_SKILLARG];
  chaos_dam_type = caster->QueryProp( CHAOS_DAM_TYPE);   
  suc = SpellSuccess(caster, sinfo);
  if( !str && pointerp(chaos_dam_type))
  {
    txt1 = ChaosDamageText(chaos_dam_type[0], 0);
    exp = explode(  txt1, " ");
    if( exp[0] == "einen")
      txt1 = "ein "+implode( exp[1..<0], " ");
    txt2 = ChaosDamageText(chaos_dam_type[0], 1);
    write( (chaos_dam_type[1]==1?"Der naechste Chaosball ist: "+txt1:       
      "Die naechsten "+chaos_dam_type[1]+" Chaosbaelle sind: "+txt2)+".\n"); 
    return 0;
  }
  if( !str)
  {
    printf( "Du hast keinen Chaosschaden eingestellt!\n");
    return 0;
  }
  if( member( schaden, str) == 0)
  {
    printf( "Diesen Schadenstyp kannst Du nicht waehlen.\n");
    return 0;
  }
  if( str == "boese" && this_player()->QueryProp( P_ALIGN) > -200)
  {
    printf( "Du bist nicht boese genug um satanische Flueche zu sprechen!\n");
    return 0;
  }
  if (suc <= 0 )
    return MISSERFOLG;
    
  dam_type = schaden[str];
  if( pointerp(chaos_dam_type)) anzahl = chaos_dam_type[1] + 
    1 + random(caster->QueryProp(P_GUILD_LEVEL)); 
  else anzahl = 1 + random(caster->QueryProp(P_GUILD_LEVEL));
  if( pointerp(chaos_dam_type) && chaos_dam_type[0] != dam_type )
     write( "Du aenderst den Schadenstyp. ");
  txt1 = ChaosDamageText(dam_type, 0);
  exp = explode(  txt1, " ");
  if( exp[0] == "einen")
    txt1 = "ein "+implode( exp[1..<0], " ");
  txt2 = ChaosDamageText(dam_type, 1);
  caster->SetProp( CHAOS_DAM_TYPE, ({ dam_type, anzahl }));
  printf( ( anzahl==1?"Der naechste Chaosball ist: "+txt1:
    "Die naechsten "+anzahl+" Chaosbaelle sind: "+txt2 )+".\n");
  say( capitalize( caster->name())+
    " murmelt seltsame Worte. "+(caster->QueryProp( P_GENDER)==1?"Seine": 
    "Ihre")+" Augen leuchten kurz rot auf.\n");
  return ERFOLG;
}


int chaosruestung( object caster, mapping sinfo)
{
object ruest;
int level, suc, alig;
if( present( "\nchaos_ruestung", caster))
  {
  printf( "Du kannst immer nur eine Chaosruestung besitzen.\n");
  return 0; 
  }
level = caster->QueryProp( P_GUILD_LEVEL);
suc = SpellSuccess( caster, sinfo);
if( suc < -2000) 
  {
  call_out( "falscher_daemon", 0, caster, - (suc/1000) * level/3);
  return MISSERFOLG;
  }
if( suc<=0)
  return MISSERFOLG;
ruest = clone_object( CHAOS_GILDEN_OBJ( "cruest" ));
alig = caster->QueryProp( P_ALIGN);
if( alig > -2000)
  caster->SetProp( P_ALIGN, caster->QueryProp( P_ALIGN) - 30 * level);
printf( "Du beschwoerst einen unheimlichen Daemon, der direkt in Deine Haut eindringt.\n");
say( break_string( capitalize(caster->name())+" macht seltsame Bewegungen, "+ 
  "spricht magische Worte einer seltsamen Sprache und beschwoert so "+
  "einen unheimlichen Daemon, der sofort in "+ 
  (caster->QueryProp(P_GENDER)==1?"seine":"ihre")+" Haut "+
  "eindringt und diese mutieren laesst. Es sieht einfach gruselig aus. ", 78) );
ruest->move( caster, M_NOCHECK);
ruest->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
ruest->SetProp( RUEST_CASTER_LEVEL, level);
//ruest->SetProp( P_AC, 29 + level); // raus, da jetzt AT_MISC
ruest->do_wear( "_chaos_ruestung_", 1);
ruest->SetProp( P_CURSED, 1);
ruest->SetProp( DAEM_FALSE, 1);
ruest->starte_anziehen(suc);
return ERFOLG;
}


int kontrolle( object caster, mapping sinfo)
{
int suc;
object ob;

ob = present( "\nchaos_ruestung", caster);
if( !ob->QueryProp( DAEM_FALSE ))
  {
  printf( "Der Daemon der Chaos-Ruestung ist doch noch friedlich.\n");
  return 0;
  }
suc = SpellSuccess(caster, sinfo);
if( suc < -2000 )
  {
  printf( "Mist, der Spruch ging voellig daneben.\n");
  caster->reduce_hit_point( random(-suc/100));
  return MISSERFOLG;
  }

if ( suc <=0)
     return MISSERFOLG;

ob->SetProp( DAEM_FALSE, 0);
printf( "Du erlangst die Kontrolle ueber die Chaos-Ruestung zurueck.\n");
say( break_string( capitalize(caster->name())+" fuchtelt mit den Haenden "+
  "herum, und spricht seltsame Worte. Ploetzlich scheinen "+
  (caster->QueryProp(P_GENDER)==1?"seine":"ihre")+
  " seltsamen Anfaelle weg zu sein. " , 78));
return ERFOLG;
}




int bannzauber( object caster, mapping sinfo)
{
int suc;
object ob;
if(!ob = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment(caster)))
  {
  printf( "Du brauchst ein eigenes Pentagramm fuer diesen Spruch.\n");
  return 0;
  }
if( !ob->QueryProp( CHAOS_BANNKREIS ))
  {
  printf( "Du musst den Bannzauber auf einen Bannkreis sprechen.\n");
  return 0;
  }
if( ob->QueryProp( CHAOS_BANNKREIS ) == 2)
  {
  printf( "Auf dem Bannkreis liegt schon ein Bannzauber.\n");
  return 0;
  }
suc = SpellSuccess(caster, sinfo);
if( suc < -3500 )
  {
  printf( "Argl! Der Spruch ging voellig daneben und zerstoert das Pentagramm!\n");
  say( break_string( capitalize(caster->name())+" tanzt um das Pentagramm "+
    "herum, spricht magische Worte und beschwoert finstere Kraefte. "+
    "Dann schiesst ploetzlich ein heller Strahl hinab und zerstoert "+
    "das Pentagramm und den Bannkreis.", 78));
  ob->reset();
  return MISSERFOLG;
  }
if( suc < -2500 )
  {
  printf( "Mist, der Spruch ging daneben. Der Spruch verschlechtert den Bannkreis.\n");
  say( break_string( capitalize(caster->name())+" tanzt um das "+
    "Pentagramm herum, spricht magische Worte und beschwoert "+
    "finstere Kraefte. Dann schiesst ploetzlich ein heller Strahl "+
    "hinab und laesst den Bannkreis aufleuchten.", 78 ));
  ob->SetProp( CHAOS_BANNKREIS, 2);
  ob->SetProp( CHAOS_BANNKREIS_FAKTOR, 
    ob->QueryProp( CHAOS_BANNKREIS_FAKTOR) - 10 - random(50)); 
  return MISSERFOLG;
  }

if ( suc <=0) return MISSERFOLG;

ob->SetProp( CHAOS_BANNKREIS, 2);
ob->SetProp( CHAOS_BANNKREIS_FAKTOR, ob->QueryProp( CHAOS_BANNKREIS_FAKTOR)+
  caster->QueryProp( P_GUILD_LEVEL) * 2 + 8 * suc/1000);
printf( "Du sprichst einen Bannzauber auf den Bannkreis.\n");
if( suc >= 5000)
  {
  printf( "Der Spruch war so gut, dass auch das Pentagramm verbessert wird.\n");
  ob->SetProp( CHAOS_PENTAGRAMM_FAKTOR, 
    ob->QueryProp( CHAOS_PENTAGRAMM_FAKTOR)+
    caster->QueryProp( P_GUILD_LEVEL) + 5 * suc/1000 );
  }
say( break_string(capitalize(caster->name())+" tanzt um das Pentagramm "+
  "herum, spricht magische Worte und beschwoert finstere Kraefte. Dann "+
  "schiesst ploetzlich ein blutroter Strahl hinab und laesst den "+
  "Bannkreis schaurig aufleuchten.", 78));
return ERFOLG;
}


object FindeEigenenDaemonen(string daemon, object caster)
{
  object *inv;
  int i;
  if( !daemon ) return 0;
  inv = filter_array( filter_array( all_inventory(environment(caster)),
    #'living), #'objectp );
  inv = filter_objects( inv, "id", daemon);
  for( i = sizeof(inv)-1;i>=0;i--)
  {
    if( inv[i]->QueryProp( CHAOS_DAEM_BESCHWOERER) == getuid(caster))
      return inv[i];
  }
  return 0;
}


int binde( object caster, mapping sinfo)
{
  object daem;                                                         
  string str;
  mixed pers;
  int suc, count, zeit;
  suc = SpellSuccess(caster, sinfo);
  daem = FindeEigenenDaemonen( sinfo[SI_SKILLARG], caster );
  if (!daem) 
  {
    printf( "So nen Daemonen findest Du hier nicht!\n"); 
    return 0;
  }
  if(  !daem->id( "\nchaos_gilden_daemon" ))
  {
    printf( "Du kannst nur Gilden-Daemonen an Dich binden!\n");
    return 0;
  }
  if( daem->QueryProp( CHAOS_DAEM_BESCHWOERER) != getuid(this_player()))
  {
    printf( "Du kannst nur Deine eigenen Daemonen an Dich binden!\n");
    return 0;
  }
  if ( suc <= 0)
  {
    switch( random(100))
    {
      case 1..3:
      printf( "Der Spruch hat ueberhaupt nicht funktioniert! Seltsam, warum\n"
        +"schaut Dich der Daemon auf einmal so komisch an? Warum grinst er bloss?\n");
        daem->SetProp( DAEM_FALSE, 1);
        break;
      case 4..8:
        daem->SetProp( DAEM_DISAPPEAR, 1);
        break;
      case 9..10:
        daem->SetProp( DAEM_AGGRESSIVE, 1);
        break;
      case 11..20:
          daem->SetProp( CHAOS_DAEM_NO_DISAPPEAR, 0);
          break;
       default: break;
     }
    return MISSERFOLG;
  }
  printf( "Du stierst "+daem->name(WEN)+" finster an und sprichst Worte der Macht.\n"
    +capitalize(daem->name())+" wird dadurch eingeschuechtert und bleibt laenger unter\n"
    +"Deiner Kontrolle.\n");
  say( capitalize(caster->name())+" stiert "+daem->name(WEN)+" finster und boese an.\n");
  if( count = daem->QueryProp( DAEM_COUNT_DOWN))
  {                                     
    count += random(caster->QueryAttribute( A_INT)) + suc/200;
    str = capitalize(daem->name())+" wird vorraussichtlich jetzt ";
    switch( count)
    {
      case 0..20: str += "ganz kurz";break;
      case 21..30: str += "etwas"; break;
      case 31..50: str += "einige Zeit"; break;
      case 51..70: str += "laengere Zeit";break;
      case 71..100: str += "eine sehr lange Zeit";break;
      default: str += "eine ueberaus lange Zeit";break;
    }
    str += " mit Dir zusammen kaempfen.";
    printf( break_string( str, 78));                                      
    daem->SetProp( DAEM_COUNT_DOWN, count );
  }
  if( zeit = daem->QueryProp( CHAOS_DAEM_FOLLOW_TIME))
  {
    zeit += random(600) + suc/3;                                            
    str = capitalize(daem->name())+" wird Dir vorraussichtlich ";
    switch( zeit - time())
    {
      case 0..60: str += "ganz kurz";break;
      case 61..180: str += "etwas"; break;
      case 181..300: str += "einige Zeit"; break;
      case 301..600: str += "laengere Zeit";break;
      case 601..1200: str += "eine sehr lange Zeit";break;
      default: str += "eine ueberaus lange Zeit";break;
    }
    str += " folgen.";
    printf( break_string( str, 78));                                        
    daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, zeit );
    if( !pointerp(pers = caster->QueryProp(P_PURSUERS)) 
      || member( pers[1], daem) == -1)
      caster->AddPursuer( daem);
  }
  if( suc > 3000 ) caster->AddPursuer( daem);
  return ERFOLG;
}


int intarbir( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
if( present( "intarbir_"+getuid(caster), environment( caster)))
  {
  printf( "Was willst Du mit zwei Daemonen?\n");
  return 0; 
  }
suc = SpellSuccess( caster, sinfo);
if( suc<=0)
     return MISSERFOLG;
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
result = check_result( daemon["intarbir"], caster, pentaf, kreisf, suc);
if( result == WD) 
  {
  call_out( "falscher_daemon", 0, caster, 
    daemon["intarbir"][WRONG_DAEM] );
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
  }
daem = clone_object( CHAOS_GILDEN_MON( "intarbir" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->AddId( "intarbir_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["intarbir"] );
printf( "Du beschwoerst finstere Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( break_string( capitalize(caster->name())+" murmelt leise Worte einer "+
  "gutturalen Sprache und laesst eine rote, magische Wolke entstehen, "+
  "aus der eine finstere Gestalt hervorkommt.", 78));
daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, time()+ 30 + suc/1000 * 30 );
daem->move( environment( caster ), M_GO);
if( result != DF || random( 100) > daemon["intarbir"][DAEM_FALSE] )
  caster->AddPursuer( daem);
return ERFOLG;
}

int kruftur( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
if( present( "kruftur_"+getuid(caster), environment( caster)))
  {
  printf( "Was willst Du mit zwei Daemonen?\n");
  return 0; 
  }
suc = SpellSuccess( caster, sinfo);
if( suc <= 0 )
     return MISSERFOLG;
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
result = check_result( daemon["kruftur"], caster, pentaf, kreisf, suc);
if( result == WD) 
  {
  call_out( "falscher_daemon", 0, caster, 
    daemon["kruftur"][WRONG_DAEM] );
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
  }
daem = clone_object( CHAOS_GILDEN_MON( "kruftur" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->AddId( "kruftur_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["kruftur"] );
printf( "Du beschwoerst finstere Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( break_string( capitalize(caster->name())+" grummelt irgendetwas "+ 
  "Unverstaendliches und macht dabei magische Zeichen. Ploetzlich bildet "+
  "sich ein Riss in der Realitaet.", 78));
daem->move( environment( caster ), M_GO );
daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, time()+ 30 + suc/1000 * 30 );
if( result != DF || random( 100) > daemon["kruftur"][DAEM_FALSE] )
  caster->AddPursuer( daem);
return ERFOLG;
}




int ombatis( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
suc = SpellSuccess( caster, sinfo);
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
if( present( "ombatis_"+getuid(caster), environment(caster)))
  {
  write( "Ombatis ist doch schon da!\n");
  return 0;
  }
if( suc <= 0) return MISSERFOLG;
result = check_result( daemon["ombatis"], caster, pentaf, kreisf, suc );
if( result == WD) 
  {
  call_out( "falscher_daemon", 0, caster, 
    daemon["ombatis"][WRONG_DAEM] );
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
  }
daem = clone_object( CHAOS_GILDEN_MON( "ombatis" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->AddId( "ombatis_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["ombatis"] );     
printf( "Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( break_string( capitalize(caster->name())+" kichert wild und spricht "+
  "seltsame Worte mit einer Stimme, die gar nicht zu "+
    (caster->QueryProp( P_GENDER)==1?"ihm":"ihr")+" passt. Sofort "+
  "bildet sich ein dunkles Portal mitten in der Luft.", 78));
daem->move( environment( caster ), M_TPORT );
daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, time()+caster->QueryProp(P_LEVEL) * 30);
return ERFOLG;
}

int irkitis( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
suc = SpellSuccess( caster, sinfo);
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
if( present( "irkitis_"+getuid(caster), environment(caster)))
  {
  write( "Du beschwoerst magische Kraefte, doch da Irkitis schon da ist, passiert\n"
  +"ueberhaupt nichts.\n");
  return ERFOLG;
  }
if( suc <= 0) return MISSERFOLG;
result = check_result( daemon["irkitis"], caster, pentaf, kreisf, suc );
if( result == WD) 
  {
  call_out( "falscher_daemon", 0, caster, 
    daemon["irkitis"][WRONG_DAEM] );
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
  }
daem = clone_object( CHAOS_GILDEN_MON( "irkitis" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->SetProp( DAEM_DEFEND_FAKTOR, 100);
daem->AddId( "irkitis_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["irkitis"] );     
daem->SetProp( DAEM_COUNT_DOWN, caster->QueryAttribute(A_INT) + suc/1000 );  
printf( "Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( capitalize(caster->name())+" beschwoert unheimliche Kraefte und oeffnet ein Tor in andere Welten.\n");
daem->move( environment( caster ), M_TPORT );
if( result != DF || random( 100) > daemon["irkitis"][DAEM_FALSE] )
  caster->AddPursuer( daem);
if( result != DF || random( 100) > daemon["irkitis"][DAEM_FALSE] ) 
  caster->AddDefender(daem);
if(p) p->starte_entfernen(10);     
return ERFOLG;
}



int harkuhu( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
suc = SpellSuccess( caster, sinfo);
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
if( present( "harkuhu_"+getuid(caster), environment(caster)))
  {
  write( "Du beschwoerst magische Kraefte, doch da Harkuhu schon da ist, passiert\n"
  +"ueberhaupt nichts.\n");
  return ERFOLG;
  }
if( suc <= 0) return MISSERFOLG;
result = check_result( daemon["harkuhu"], caster, pentaf, kreisf, suc );
if( result == WD) 
  {
  call_out( "falscher_daemon", 0, caster, 
    daemon["harkuhu"][WRONG_DAEM] );
  return ERFOLG;
  if(p) p->starte_entfernen(10);     
  }
daem = clone_object( CHAOS_GILDEN_MON( "harkuhu" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->SetProp( DAEM_DEFEND_FAKTOR, 50);
daem->AddId( "harkuhu_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["harkuhu"] );     
printf( "Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( capitalize(caster->name())+" beschwoert unheimliche Kraefte und oeffnet ein Tor in andere Welten.\n");
daem->move( environment( caster ), M_TPORT );
daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, time()+ 240 + suc/1000 * 58 );
if( result != DF || random( 100) > daemon["harkuhu"][DAEM_FALSE] )
  caster->AddPursuer( daem);
if( result != DF || random( 100) > daemon["harkuhu"][DAEM_FALSE] ) 
  caster->AddDefender(daem);
if(p) p->starte_entfernen(6);     
return ERFOLG;
}

int graiop( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
suc = SpellSuccess( caster, sinfo);
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
if( present( "graiop_"+getuid(caster), environment(caster)))
  {
  write( "Du beschwoerst magische Kraefte, doch da Graiop schon da ist, passiert\n"
  +"ueberhaupt nichts.\n");
  return ERFOLG;
  }
if( suc <= 0) return MISSERFOLG;
result = check_result( daemon["graiop"], caster, pentaf, kreisf, suc );
if( result == WD) 
  {
  call_out( "falscher_daemon", 0, caster, 
    daemon["graiop"][WRONG_DAEM] );
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
  }
daem = clone_object( CHAOS_GILDEN_MON( "graiop" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->SetProp( DAEM_DEFEND_FAKTOR, 60);
daem->AddId( "graiop_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["graiop"] );     
printf( "Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( break_string( capitalize(caster->name())+" spricht magische Worte, "+
  "die, zusammen mit abartigen Gesten, einen wilden, gefaehrlichen "+
  "Daemonen aus den Tiefen der niederen Dimensionen rufen.", 78));
daem->move( environment( caster ), M_TPORT );
daem->SetProp( DAEM_COUNT_DOWN, caster->QueryAttribute(A_INT) + 4 * suc/1000);
if( result != DF || random( 100) > daemon["graiop"][DAEM_FALSE] )
  caster->AddPursuer( daem);
if( result != DF || random( 100) > daemon["graiop"][DAEM_FALSE] ) 
  caster->AddDefender(daem);
if(p) p->starte_entfernen(8);     
return ERFOLG;
}

int flaxtri( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
suc = SpellSuccess( caster, sinfo);
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
if( present( "flaxtri_"+getuid(caster), environment(caster)))
  {
  write( "Du beschwoerst magische Kraefte, doch da Flaxtri schon da ist, passiert\n"
  +"ueberhaupt nichts.\n");
  return ERFOLG;
  }
if( suc <= 0) return MISSERFOLG;
result = check_result( daemon["flaxtri"], caster, pentaf, kreisf, suc );
if( result == WD) 
  {                                    
  call_out( "falscher_daemon", 0, caster, 
    daemon["flaxtri"][WRONG_DAEM] );
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
  }
daem = clone_object( CHAOS_GILDEN_MON( "flaxtri" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->SetProp( DAEM_DEFEND_FAKTOR, 50);
daem->AddId( "flaxtri_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["flaxtri"] );     
printf( "Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( break_string( capitalize(caster->name())+" murmelt ein unheimliches "+
  "Wort und beginnt sofort mit einem abartigen Tanz, dessen wilde Gesten "+
  "geradezu obszoen sind.", 78));
daem->move( environment( caster ), M_TPORT );
daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, time() + 300 + 300 * suc/1000  );
daem->SetProp( CHAOS_DAEM_NO_DISAPPEAR, 1);
if( result != DF || random( 100) > daemon["flaxtri"][DAEM_FALSE] )
  caster->AddPursuer( daem);
if( result != DF || random( 100) > daemon["flaxtri"][DAEM_FALSE] ) 
  caster->AddDefender(daem);
if(p) p->starte_entfernen(10);     
return ERFOLG;
}

int tutszt( object caster, mapping sinfo)
{
object daem, p;
int result, suc;
int pentaf, kreisf;
suc = SpellSuccess( caster, sinfo);
if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
  environment( caster)))
  {
  pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
  if( p->QueryProp( CHAOS_BANNKREIS)) 
    kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
if( present( "tutszt_"+getuid(caster), environment(caster)))
  {
  write( "Du beschwoerst magische Kraefte, doch da Tutszt schon da ist, passiert\n"
  +"ueberhaupt nichts.\n");
  return ERFOLG;
  }
if( suc <= 0) return MISSERFOLG;
result = check_result( daemon["tutszt"], caster, pentaf, kreisf, suc );
if( result == WD) 
  {
  call_out( "falscher_daemon", 0, caster, 
    daemon["tutszt"][WRONG_DAEM] );
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
  }
daem = clone_object( CHAOS_GILDEN_MON( "tutszt" ));
daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
daem->SetProp( DAEM_DEFEND_FAKTOR, 30 );
if( CHAOS_GILDEN_MASTER->ist_erz( caster))
  daem->Setprop( DAEM_DEFEND_FAKTOR, 20 );
daem->AddId( "tutszt_"+getuid(caster));
if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
if( result == DF) daem->SetProp( DAEM_FALSE, 1);
daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["tutszt"] );     
printf( "Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in andere Welten.\n");
say( break_string( capitalize(caster->name())+" fuchtelt wie wild mit den "+
  "Armen herum, stoesst boesartige Worte einer magischen Sprache hervor "+
  "und vollfuehrt mit "+
  (caster->QueryProp( P_GENDER)==1?"seinen":"ihren")+" Fuessen einen "+
  "seltsamen Tanz.", 78));
daem->move( environment( caster ), M_TPORT );
daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, time() + 1000 + 500 * suc/1000);
daem->SetProp( CHAOS_DAEM_NO_DISAPPEAR, 1);
if( result != DF || random( 100) > daemon["tutszt"][DAEM_FALSE] )
  caster->AddPursuer( daem);
if( result != DF || random( 100) > daemon["tutszt"][DAEM_FALSE] ) 
  caster->AddDefender(daem);
if(p) p->starte_entfernen(10);     
return ERFOLG;
}                 


int yrintri( object caster, mapping sinfo)
{
  object daem, p;
  int result, suc;
  int pentaf, kreisf;
  suc = SpellSuccess( caster, sinfo);
  if( !CHAOS_GILDEN_MASTER->ist_erz(caster))
  {
    if( caster->QueryProp( P_GUILD_LEVEL) == 12)
        caster->SetProp( P_GUILD_LEVEL, 11);
    tell_object( caster, "Du bist nicht der Erzmeister des Chaos!\n");
    return 0;
  }    
  if( p = present( "\nchaos_gilden_pentagramm_"+getuid(caster), 
    environment( caster)))
  {
    pentaf = p->QueryProp( CHAOS_PENTAGRAMM_FAKTOR);
    if( p->QueryProp( CHAOS_BANNKREIS)) 
      kreisf = p->QueryProp( CHAOS_BANNKREIS_FAKTOR);
  }
  if( present( "yrintri_"+getuid(caster), environment(caster)))
  {
    write( "Du beschwoerst magische Kraefte, doch da Yrintri schon da ist, passiert\n"
      +"ueberhaupt nichts.\n");
    return ERFOLG;
  }
  if( suc <= 0) return MISSERFOLG;
  result = check_result( daemon["yrintri"], caster, pentaf, kreisf, suc );
  if( result == WD) 
  {
    call_out( "falscher_daemon", 0, caster, 
    daemon["yrintri"][WRONG_DAEM] );
    if(p) p->starte_entfernen(10);     
    return ERFOLG;
  }
  daem = clone_object( CHAOS_GILDEN_MON( "yrintri" ));
  daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster) );
  daem->SetProp( DAEM_DEFEND_FAKTOR, 15 );
  daem->AddId( "yrintri_"+getuid(caster));
  if( result == DD) daem->SetProp( DAEM_DISAPPEAR, 1);
  if( result == DA) daem->SetProp( DAEM_AGGRESSIVE, 1);
  if( result == DF) daem->SetProp( DAEM_FALSE, 1);
  daem->SetProp( DAEM_FAKTOR_MAPPING, daemon["yrintri"] );     
  printf( "Du beschwoerst unheimliche Kraefte und oeffnest so ein Tor in andere Welten.\n");
  say( break_string( capitalize(caster->name())+" fuchtelt wie wild mit den "+
    "Armen herum, stoesst boesartige Worte einer magischen Sprache hervor "+
    "und vollfuehrt mit "+
    (caster->QueryProp( P_GENDER)==1?"seinen":"ihren")+" Fuessen einen "+
    "seltsamen Tanz.", 78));
  daem->move( environment( caster ), M_TPORT );
  daem->SetProp( CHAOS_DAEM_FOLLOW_TIME, time() + 2000 + 500 * suc/1000);
  daem->SetProp( CHAOS_DAEM_NO_DISAPPEAR, 1);
  if( result != DF || random( 100) > daemon["yrintri"][DAEM_FALSE] )
    caster->AddPursuer( daem);
  if( result != DF || random( 100) > daemon["yrintri"][DAEM_FALSE] ) 
    caster->AddDefender(daem);
  if(p) p->starte_entfernen(10);     
  return ERFOLG;
}                 

int check_result( mapping daem, object caster, int pentaf, int kreisf, int abil)
{
int align;
align = caster->QueryProp( P_ALIGN);
if( align > 200) align = 200;
align = -align/6;
if( !pentaf) pentaf = - daem[WRONG_DAEM];
if( !kreisf) kreisf = - (daem[DAEM_DISAPPEAR]+daem[DAEM_AGGRESSIVE]+
  daem[DAEM_FALSE])/2;
if( pentaf/4+random(50+pentaf * 5+abil/100+align) <= daem[WRONG_DAEM]) 
  return WD;
if( kreisf/4+random(50+kreisf * 5+abil/100+align) <= daem[DAEM_AGGRESSIVE]) 
  return DA;
if( kreisf/4+random(50+kreisf * 5+abil/100+align) <= daem[DAEM_DISAPPEAR]) 
  return DD;
if( (kreisf+pentaf)/4+random(50+(pentaf+kreisf)*2+abil/100+align) 
  <= daem[DAEM_FALSE]) return DF;
}


falscher_daemon( object caster, int wd)
{
object daem, p, *zau, *u;
int i;
if( !caster) return;
tell_object( caster, break_string( "Oh oh! Da lief was "+
  "schief. Du hast einen entscheidenden Fehler gemacht und "+
  "so einen anderen Daemon als erwartet beschworen.", 78));
say( break_string( "Oh oh! "+caster->name()+
  " muss irgendetwas falsch gemacht haben! "+
  (caster->QueryProp(P_GENDER)==1?"Er":"Sie")+" wird ploetzlich "+
  "ganz weiss im Gesicht und flucht lautstark." , 78), caster);
switch(random(wd))
  {
  case 0..3:
    daem = clone_object( CHAOS_GILDEN_MON( "uebmatu" ));
    daem->SetProp( DAEM_AGGRESSIVE, getuid(caster));
    daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster));
    tell_room(environment(caster),
    "Ein laecherlicher Daemon, Uebmatu genannt, faellt herein.\n");
    daem->move( environment( caster), M_GO|M_SILENT);
    break;
  case 4..7:
    daem = clone_object( CHAOS_GILDEN_MON( "anthukt" ));
    daem->SetProp( DAEM_AGGRESSIVE, getuid(caster));
    daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster));
    tell_room(environment(caster),
    "Ein spinnenaehnlicher Daemon mit Ziegenkopf krabbelt herein.\n");
    daem->move( environment( caster), M_GO|M_SILENT);
    break;
  case 8..12: 
    daem = clone_object( CHAOS_GILDEN_MON( "chochos" ));
    daem->SetProp( DAEM_AGGRESSIVE, getuid(caster));
    daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster));
    tell_room(environment(caster),
    "Ein schwarzer Daemon schleicht in diese Dimension!\n");
    daem->move( environment( caster), M_GO|M_SILENT);
    break;
  case 13..18:
    daem = clone_object( CHAOS_GILDEN_MON( "daedhel" ));
    daem->SetProp( DAEM_AGGRESSIVE, getuid(caster));
    daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster));
    tell_room(environment(caster),
    "Daedhel stuermt wild herein! Flieht, Sterbliche!\n");
    daem->move( environment( caster), M_GO|M_SILENT);
    break;
  case 19..33: 
    daem = clone_object( CHAOS_GILDEN_MON( "hothrog" ));
    daem->SetProp( DAEM_AGGRESSIVE, getuid(caster));
    daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster));
    tell_room(environment(caster),
    "Ein boesartiger Daemon, er ist unter dem Namen Hothrog bekannt,\n"
    +"beschworen von "+caster->name(WEN)+", stuermt herein!\n");
    daem->move( environment( caster), M_GO|M_SILENT);
    break;   
  case 34..60:
    daem = clone_object( CHAOS_GILDEN_MON( "rythoth" ));
    daem->SetProp( DAEM_AGGRESSIVE, getuid(caster));
    daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster));
    tell_room(environment(caster),
    "Ein uebler Hetzerdaemon, bekannt unter der Bezeichnung Rythoth, hetzt\n"
    +"herein, auf der Suche nach blutigen Opfern.\n");
    daem->move( environment( caster), M_GO|M_SILENT);
    break;
  default: tell_object( caster, "Es passiert nichts.\n");
  }
if(daem) daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(caster));
}



    