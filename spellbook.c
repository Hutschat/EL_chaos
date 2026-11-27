/* Die Zaubersprueche:
   
 last changed: 03.06.98   Tilly (Test-Daemon)
               06.06.98   Bierchen (DT_RIP als Schaden eingebaut)
               20.06.98   Feuerwehr Chaosmaske eingebaut.
               26.06.98   Bierchen check_chaosdamage()
               26.06.98   Feuerwehr Masken-Spellkosten runtergesetzt (testing)
               03.07.98   Feuerwehr Daemonen koennen "leise beschworen werden"
               13.07.98   Bierchen Chaoskontrolle. WC der Waffe fliesst nur
                          noch ein, wenn die Waffe eine WC von <=150 hat.
                          Btw. falls groesser, entfaellt damit gleichzeitig 
                          der Bonus fuer QuerySkillAbility("chaoskontrolle")) 
               19.07.98   Feuerwehr P_GUILD_LEVEL-Abfrage in SI_SKILLRESTR_USE
                          Es gab da so einen Re-Einsteiger, der mit Level 1
                          Chaosbaelle warf.... pfffffff.
               27.07.98   Bierchen SpellDefend im Chaosball und chaoskontrolle
                          max. zusatz von 150              
               29.07.98   Bierchen chaosball kostet unter chaoskontrolle jetzt
                          20 mps, dafuer chaoskontrolle nur noch 20 anstelle
                          von 30. check_align() liefert einen bonus auf den
                          chaosball von max 30%. dies haengt von der
                          differenz npc_align-caster_align ab und liegt dort
                          im bereich von 1500 (0%) bis 2000 (30%).
               29.07.98   Feuerwehr: Schutz schwach, finsternis, verbanne
                          geaendert. Alle Kampfdaemonen mit SR_GOOD versehen.
               12.08.98   Chaosball testweise aufgewertet.
                          nur für Mr. H.J. Sting.
               20.08.98   Chaosball fuer alle aufwerten. YEAH!
               23.08.98   Feuerwehr Nachtsicht geaendert.
               01.09.98   Feuerwehr Neuer Ombatis --> Anpassungen
               02.09.98   Feuerwehr Anpassungen Ombatis
               03.12.98   Bierchen  finsternis addiert nun das alte 
                          P_DISABLE_ATTACK im vic zum neuen hinzu.           
               10.01.99   Feuerwehr aenderung bei Namen von Daemonen.
               19.01.99   Bierchen chaoskontrolle           
               24.01.99   Feuerwehr RFR-Blockade ignorieren. (IST WIEDER RAUS)
               27.01.99   Bierchen  check_align, aeh, bitte durchrechnen!
               27.01.99   Feuerwehr Bierchens Aenderungen aendern :)
               31.01.99   Feuerwehr Energiespar-Modus.
               03.03.99   Feuerwehr verbanne debuggt.
               20.04.99   Feuerwehr Finsternis -> Daemonen greifen mit an.
               27.04.99   Feuerwehr Neue Pentagramm-Formeln eingebaut
               20.06.99   Bierchen Maske auskommentiert               
               03.07.99   Feuerwehr Neue Daemonenberechnung...
               13.07.99   Tilly Kosmetika
               07.08.99   Feuerwehr Tests in Yrintri, Tutszt eingebaut.
               28.10.99   Feuerwehr SpellDefend in finsternis verrueckt.
               13.12.99   Feuerwehr chaosschaden chaos
               18.12.99   Tilly Typo-Fix, u.a.
               20.12.99   Bierchen (dunkelheit gesperrt)
               20.12.99   Bierchen (aufgehoben, testweise)
               10.01.00   Feuerwehr debugging (SI_MAGIC_TYPE)
               27.11.26   It@Efferdland UTF-8, Fehler für neuen Driver
                          behoben, Ombatis entfernt
               27.11.26   It@Efferdland Chaosmaske angeschlossen
               27.11.26   It@Efferdland Dämonentypen mit Namen statt
                          Intarbir, Kruftur, Tyoorthok, Bhuturih,
                          Irkitis, Harkuhu, Graiop, Flaxtri, Tutszt
                          und Yrintri
               27.11.26   It@Efferdland GUILD_HELPER statt
                          VERBOTENE_RAEUME
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
Chaosmaske:
  Wer eine Daemonenmaske traegt, verwandelt sich im Dunkeln in deren
  Daemon (shadows/mask_shadow.c).
  SP: 40, Level: 11
Beschwoere:
  beschwoere <typ> [leise]. Jeder Daemonentyp ist ein eigener Spruch,
  der gelernt und geuebt wird, die Werte stehen in master/daemonen.c.
  Der Daemon bekommt einen Namen aus master/namen.c.
  Orakeldaemon (ab 4): schaetzt Monster ein, ab 5 identifiziert er
    Gegenstaende und Pentagramme, ab 7 erzaehlt er ueber den eigenen
    Koerper (frueher Intarbir, Kruftur und Tyoorthok).
  Schattendaemon (ab 7, frueher Irkitis): kaempft einige Runden mit,
    faengt keine Schlaege ab.
  Lichtdaemon (ab 8, frueher Harkuhu): kaempft gegen NPCs nicht mit,
    faengt aber Schlaege ab.
  Feuerdaemon (ab 9, frueher Graiop): kaempft einige Runden.
  Saeuredaemon (ab 10, frueher Flaxtri): folgt, bis er stirbt.
  Blutdaemon (ab 11, frueher Tutszt): der staerkste fuer Meister.
  Wandler (Erzmeister, frueher Yrintri): verwandelt seine Klauen und
    rettet dem Beschwoerer das Leben.

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
#include "def.h"

mapping daemon;
string ChaosDamageText( string dam_type, int plu);
string *ChaosDamage(object caster, int suc);
int check_result(mapping daem, object caster, int pentaf, int kreisf, int abil);
int get_pf(object p);
int get_kf(object p);

inherit "/std/spellbook";

protected void create() {
  ::create();
  SetProp(P_GLOBAL_SKILLPROPS,
      ([SI_SPELLFATIGUE:2,    
      SI_SKILLLEARN:2,      
      OFFSET(SI_SKILLLEARN):2 
      ]));
  AddSpell( "chaosball",15,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:5]),
       SI_SKILLRESTR_USE:([
       P_GUILD_LEVEL : 5,
       SR_FUN:"CheckRuestung"]), SI_DIFFICULTY:20 
      ]));
  AddSpell( "verbanne", 30,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:7]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"CheckRuestung",P_GUILD_LEVEL : 7]),
       SI_DIFFICULTY:50,
       SI_NOMAGIC:100,
       SI_SKILLDAMAGE_TYPE:DT_SOUND
       ])); 
  AddSpell( "schutz", 25, 
    ([ SI_SKILLRESTR_LEARN:([ P_GUILD_LEVEL:4]),
      SI_SKILLRESTR_USE:([SR_FREE_HANDS:1,
      SR_GOOD:0,
      SR_FUN:"CheckRuestung", P_GUILD_LEVEL : 4]),
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
       SI_SKILLRESTR_USE:([SR_GOOD:-100, 
       SR_FREE_HANDS:2,
       P_GUILD_LEVEL : 3]),
       SI_DIFFICULTY:70,
       SI_SPELLFATIGUE:50,
      OFFSET(SI_SKILLLEARN):10     
       ]));  
  AddSpell( "kontrolle", 20,
      ([ SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:3]),
       SI_SKILLRESTR_USE:([SR_FUN:"CheckRuestung",
       P_GUILD_LEVEL:3]),
       SI_DIFFICULTY:50,
       SI_SPELLFATIGUE:20,
       OFFSET(SI_SKILLLEARN):5,
       SI_NOMAGIC:100,
      ]));
  AddSpell( "finsternis",100,             
     ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:8]),
       SI_SKILLRESTR_USE:([
       SR_FUN:"CheckRuestung",
       SR_GOOD:-300,
       P_GUILD_LEVEL : 8]), SI_DIFFICULTY:120,  
       SI_SKILLLEARN:4,      
       ]));
  AddSpell( "chaosschaden",20,         
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:6]),
       SI_SKILLRESTR_USE:([P_GUILD_LEVEL : 6]),
       SI_DIFFICULTY:20 
       ]));
  
  // Kosten auf 20 runter (Laut 112 genehmigt), dafuer kostet der
  // Chaosball bei der Chaoskontrolle 20 anstelle von 15 mps
  
  AddSpell( "chaoskontrolle",20,         
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:11]),
       SI_SKILLRESTR_USE:([P_GUILD_LEVEL : 11]),
       SI_DIFFICULTY:-10,
       ]));
  AddSpell( "bannzauber",10,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:4]),
       SI_SKILLRESTR_USE:([P_GUILD_LEVEL : 4]),
       SI_DIFFICULTY:-10, 
       SI_SPELLFATIGUE:4     
       ]));
  AddSpell( "binde", 40,
       ([ SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:9]),
       SI_DIFFICULTY:90,
       SI_SKILLRESTR_USE:([SR_FUN:"CheckRuestung",P_GUILD_LEVEL:9]),
       SI_NOMAGIC:100,
       SI_SPELLFATIGUE:10
       ]));
  AddSpell( "chaosmaske", 40,
       ([ SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:11]),
       SI_SKILLRESTR_USE:([
       SR_GOOD:-200,P_GUILD_LEVEL:11 ]),
       SI_DIFFICULTY:30,
       SI_SPELLFATIGUE:20
       ]));
  // Die Dämonen. Jeder Typ ist ein eigener Spruch (Werte in
  // master/daemonen.c), beschworen wird über 'beschwoere <typ>'.
  daemon = ([]);

  // Kosten 1, weil AddSpell() 0 nicht annimmt. beschwoere() liefert
  // immer 0, damit kostet der Spruch selbst nichts.
  AddSpell(CHAOS_SPRUCH_BESCHWOERE, 1,
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL:4]),
       SI_SKILLLEARN:0,
       OFFSET(SI_SKILLLEARN):0,
       SI_SPELLFATIGUE:0,
       ]));

  foreach(string typ : CHAOS_DAEMONEN_MASTER->QueryTypen()) {
    mapping d = CHAOS_DAEMONEN_MASTER->QueryTyp(typ);
    mapping use = ([P_GUILD_LEVEL: d[CD_STUFE],
                    SR_FUN: d[CD_KAMPF] ? "DaemonenTest"
                                        : "CheckKleinerDaemon"]);

    if(d[CD_KAMPF]) {
      use[SR_FREE_HANDS] = 2;
    }
    if(member(d,CD_GUT_BENUTZEN)) {
      use[SR_GOOD] = d[CD_GUT_BENUTZEN];
    }
    AddSpell(typ, d[CD_KOSTEN],
       ([SI_SKILLRESTR_LEARN:([P_GUILD_LEVEL: d[CD_STUFE],
                               SR_GOOD: d[CD_GUT_LERNEN]]),
       SI_SKILLRESTR_USE: use,
       SI_DIFFICULTY: d[CD_SCHWIERIGKEIT],
       SI_SPELLFATIGUE: d[CD_PAUSE],
       ]));

    // Wahrscheinlichkeiten, mit denen der Dämon etwas Falsches tut
    daemon[typ] = ([DAEM_AGGRESSIVE: d[CD_FAKTOREN][0],
                    DAEM_DISAPPEAR:  d[CD_FAKTOREN][1],
                    DAEM_FALSE:      d[CD_FAKTOREN][2],
                    WRONG_DAEM:      d[CD_FAKTOREN][3]]);
  }
}  

string ChaosDamageText(string dam_type, int plu){
  if(!dam_type) return "";
  switch(dam_type){
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
    case DT_DARKNESS:
      if(plu) return "satanische Flueche";
      return "einen satanischen Fluch";
    case DT_TERROR:
      if(plu) return "hinterhaeltige Terrorattacken";
      return "eine hinterhaeltige Terrorattacke";
    case DT_WHIP:
      if(plu) return "wirbelnde Peitschenhiebe";
      return "einen wirbelnden Peitschenhieb";
    case DT_SQUEEZE:
      if(plu) return "Daumenschrauben";
      return "eine Daumenschraube";
    case DT_EXPLOSION:
      if(plu) return "explosive Magierschaedel";
      return "einen explosiven Magierschaedel";
    case DT_RIP:
      if(plu) return "gemeine Widerhaken";
      return "einen gemeinen Widerhaken";
    default: 
      if(plu) return "unbekannte Angriffe";
      return "einen Chaosball";
  }
}

// Fuer die Chaoskontrolle (Kombinierte Schaeden beim Chaosball)

string ChaosDamageText2(string dam_type1,string dam_type2,int plu){
  string ret_string;
  if(!dam_type1||!dam_type2) return "";
  
  // Nicht-mechanische Schaeden
  
  switch(dam_type1){
    case DT_FIRE:
      if(plu) ret_string="brennende";
      else ret_string="einen brennenden";
      break;
    case DT_AIR: 
      if(plu) ret_string="stuermische";
      else ret_string="einen stuermischen";
      break;
    case DT_MAGIC: 
      if(plu) ret_string="magische";
      else ret_string="einen magischen";
      break;
    case DT_WATER: 
      if(plu) ret_string="fluessige";
      else ret_string="einen fluessigen"; 
      break;
    case DT_COLD: 
      if(plu) ret_string="eisige";
      else ret_string="einen eisigen";
      break;
    case DT_ACID: 
      if(plu) ret_string="aetzende";
      else ret_string="einen aetzenden";
      break;
    case DT_LIGHTNING: 
      if(plu) ret_string="blitzende";
      else ret_string="einen blitzenden";
      break;
    case DT_SOUND:
      if(plu) ret_string="schreiende";
      else ret_string="einen schreienden"; 
      break;
    case DT_DARKNESS:
      if(plu) ret_string="satanische";
      else ret_string="einen satanischen";
      break;
    case DT_TERROR:
      if(plu) ret_string="terror verbreitende";
      else ret_string="einen terrorverbreitenden";
      break;
    case DT_POISON:
      if(plu) ret_string="giftige";
      else ret_string="einen giftigen";
      break;
    default: 
      if(plu) ret_string="unbekannte";
      else ret_string="einen unbekannten";
      break;
  }

  // Mechanische Schaeden
  
  switch(dam_type2){  
    case DT_BLUDGEON: 
      if(plu) ret_string+=" Felsbrocken";
      else ret_string+=" Felsbrocken";
      break;
    case DT_PIERCE: 
      if(plu) ret_string+=" Pfeile";
      else ret_string+=" Pfeil";
      break;
    case DT_SLASH: 
      if(plu) ret_string+=" Messerschnitte";
      else ret_string+=" Messerschnitt";
      break;
    case DT_RIP: 
      if(plu) ret_string+=" Widerhaken";
      else ret_string+=" Widerhaken";
      break;
    case DT_WHIP:
      if(plu) ret_string+=" Peitschenhiebe";
      else ret_string+=" Peitschenhieb";
      break;
    case DT_EXPLOSION:
      if(plu) ret_string+=" Magierschaedel";
      else ret_string+=" Magierschaedel";
      break;
    case DT_SQUEEZE:
      if(plu) ret_string+=" Daumenschrauben";
      else ret_string+=" Daumenschrauber";
      break;
    default: 
      if(plu) ret_string+=" Angriffe";
      else ret_string+=" Chaosball";
      break;
  }
  return ret_string;
}

void Misserfolg( object caster, string spell, mapping sinfo){
  int old_abil;
  write("Der Zauberspruch ist missglueckt.\n");
  old_abil=sinfo[SI_SKILLABILITY];
  Learn(caster,spell,sinfo);
  if(old_abil<caster->QuerySkillAbility(spell))
    write("Du lernst aus Deinen Fehlern.\n");
  else write("Du lernst nicht aus Deinen Fehlern.\n");
}


string CheckRuestung(object caster, mapping sinfo){
  object rue;
  if(!rue=present("\nchaos_ruestung",caster))
    return "Du musst fuer diesen Spruch eine Chaos-Ruestung tragen.\n";
  return 0;
}


/* Es gibt Raeume, die sind fuer das Beschwoeren von Daemonen ungeeignet
   (z.B. Abenteurergilde etc.) Das array ist in /gilden/files.chaos/gilde.h
   definiert */
   
// Darf hier beschworen werden? Die verbotenen Räume verwaltet die
// Mudlib (GUILD_HELPER).
static string CheckRaum(object caster) {
  if(GUILD_HELPER->GH_get_npc_forbidden_rooms(environment(caster))) {
    return "Die Umgebung ist fuer das Beschwoeren von Daemonen "
           "ungeeignet.\n";
  }
  if(caster->QueryProp(P_FROG)) {
    return "Du willst doch wohl nicht als Frosch einen Daemonen "
           "beschwoeren?\n";
  }
  return 0;
}

string CheckKleinerDaemon(object caster, mapping sinfo) {
  return CheckRaum(caster);
}

string DaemonenTest(object caster, mapping sinfo) {
  string ret;

  if(!present("\nchaos_ruestung",caster)) {
    return "Du musst fuer diesen Spruch eine Chaos-Ruestung tragen.\n";
  }
  if(ret = CheckRaum(caster)) {
    return ret;
  }
  if(caster->QueryProp(P_GENDER) == 0) {
    return "Ueber dich wuerden die Daemonen doch nur lachen!\n";
  }
  return 0;
}


int dunkelheit(object caster, mapping sinfo){
  int zeit, light, suc;
  suc=SpellSuccess(caster,sinfo);
  if(GUILD_HELPER->GH_get_npc_forbidden_rooms(environment(caster))){
    printf("Dieser Ort laesst sich nicht verdunkeln.\n");
    return 0;
  }
  if(environment(caster)->QueryProp(P_TOTAL_LIGHT) <= 
     0-caster->QueryProp(P_GUILD_LEVEL)/1){
    printf("Es ist hier zu dunkel!\n");
    return 0;
  }
  if(-2000<=suc&&suc<=0) return MISSERFOLG;
  printf("Du beschwoerst dunkle Maechte.\n");
  say(sprintf("%s beschwoert dunkle Maechte.\n",capitalize(caster->name())));
  zeit=caster->QueryProp(P_GUILD_LEVEL)*15;
  light=environment(caster)->QueryProp(P_LIGHT)-1;
  if(suc<-2000){
    printf("Mist, der Spruch ging daneben! Es wird ploetzlich heller!\n");
    light=light+2;
    TMP_PROP_MASTER->SetTmpProp(environment(caster),P_LIGHT,
      light, zeit);
    return MISSERFOLG;
  }
  TMP_PROP_MASTER->SetTmpProp(environment(caster),P_LIGHT,light,zeit);
  printf("Du verdunkelst Deine Umgebung.\n");
  return ERFOLG;
}

/* Die Chaosgilde benutzt die Maechte der Finsternis. Deshalb koennen ihre
   Mitglieder auch viel leichter die Nachtsicht benutzen, als in anderen
   Gilden. */

int nachtsicht(object caster, mapping sinfo){
  int zeit, suc;
  suc=SpellSuccess(caster, sinfo);
  if(caster->QueryProp(CHAOS_GILDEN_NACHTSICHT)>time()){
    printf("Du hast doch schon die Nachtsicht aktiviert!\n");
    return 0;
  }
  if(suc<=-2500){
    printf("Mist! Deine Augen werden nachtblind!\n");
    caster->SetProp(CHAOS_GILDEN_NACHTBLIND, time() + 60);
    return MISSERFOLG;
  }
  if(time()<caster->QueryProp(CHAOS_GILDEN_NACHTBLIND)){
    printf("Deine Augen sind zur Zeit nachtblind!\n");
    return  0;
  }
  if(suc<=0) return MISSERFOLG;
  printf("Du veraenderst magisch Deine Augen.\n");
  say(capitalize(caster->name(WESSEN))+" Augen leuchten kurz dunkelrot "
  "auf.\n",caster);
  zeit=time()+caster->QueryProp(P_GUILD_LEVEL)*40;
  caster->SetProp(CHAOS_GILDEN_NACHTSICHT,zeit);
  return ERFOLG;
}
 
int schutz(object caster, mapping sinfo){
  object victim, haut;
  int ac, level, suc, zeit;
  string str;
  str=sinfo[SI_SKILLARG];
  suc=SpellSuccess(caster,sinfo);
  haut=present("\nchaos_ruestung",caster);
  if(!haut){
    printf("Du hast keine Chaosruestung!\n");
    return 0;
  }
  if(!haut->id("neue_ruestung")){
    printf("Besorg Dir erstmal eine neue Chaosruestung!\n");
    return 0;
  } 
  if(haut->QueryProp(RUEST_SCHUTZ)){
    printf("Die Chaosruestung ist schon magisch veraendert!\n");
    return 0;
  }
  if(str&&str!="schwach"&&str!="stark"){
    printf("Diese Art von Schutz kannst Du nicht waehlen.\n");
    return 0;
  }
  if(-2000<suc&&suc<=0) return MISSERFOLG;
  level=caster->QueryProp(P_GUILD_LEVEL);
  printf("Du fuchtelst wie wild mit einer Hand herum (keiner weiss, "
  +"warum\nman das bei diesem Spruch so machen muss).\n");
  say(break_string(capitalize(caster->name())+
  " fuchtelt wie bescheuert mit einer Hand herum. Hat "+
    caster->QueryPronoun()+" einen Schaden?\n",78));
  if(suc<=-2000){
    ac=suc/100+level;
    if(ac>-1) ac=-1;
    if(ac<-20) ac=-20;
    printf("Mist, Du verschlechterst die Chaosruestung!\n");
    haut->verbessere_ruestung(ac,random(20));
    return MISSERFOLG;
  }
  if(!str||str=="schwach"){
    ac=10+suc/200+random(level*3);
    zeit=6+3*level+suc/400+random(level*6);
  }
  if(str=="stark"){
    ac=20+suc/100+3*level+random(level*7); 
    zeit=1+random(10)+suc/1000+random(level);
  }
  printf("Du verstaerkst den Schutz der Chaoshaut.\n");
  haut->verbessere_ruestung(ac,zeit);
  return ERFOLG;          
}

void BeschaedigeWaffe(object waffe){
  printf(break_string("Du hast wohl die falsche Magie durch "+
    waffe->name(WEN,1)+" fliessen lassen! "+
    capitalize(waffe->QueryPronoun())+" wird etwas beschaedigt!",78));
  waffe->Damage(5+random(20));
}  


int CheckDamTypes(mixed dt, string dam_type, object waffe){
  int wc;    
  /*
  Morgoth hat es abgeschwaecht, also ists wieder benutzbar.
  if(!random(5) && 
     explode(file_name(waffe), "#")[0] =="/d/vland/morgoth/obj/eschwert"){
    printf("Der Chaosball zerschiesst %s zu Staub!!!\n",waffe->name(WEN,1));
    waffe->remove(1);
    return -500;
  } 
  */
  wc=waffe->QueryProp(P_WC)/2;
  if(member(dt,dam_type)!=-1) return random(wc);
  switch(dam_type){
    case DT_FIRE:
      if(member(dt,DT_COLD)!=-1 || member(dt,DT_WATER)!=-1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_COLD:
      if(member(dt,DT_FIRE) != -1){
        if( !random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_WATER:
      if(member(dt,DT_FIRE) != -1 || member(dt,DT_AIR) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_AIR:
      if(member(dt,DT_SOUND) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_SOUND:
      if(member(dt,DT_MAGIC) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_LIGHTNING:
      if(member(dt,DT_COLD) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_POISON:
      if(member(dt,DT_ACID) != -1 || member(dt,DT_LIGHTNING) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_ACID:
      if(member(dt,DT_WATER) != -1 || member(dt,DT_LIGHTNING) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_DARKNESS:  
      if(member(dt,DT_LIGHT) != -1 || member(dt,DT_MAGIC) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
    case DT_MAGIC:
      if(member(dt,DT_POISON) != -1){
        if(!random(50)) BeschaedigeWaffe(waffe);
        return - random(wc);
      }
      break;
  }
  return 0;
}

string *ChaosDamage(object caster, int suc){
  string *types,*dam_type;
  int anzahl;
  string *chaos_dam_type;
  types=({ 
    DT_BLUDGEON, 
    DT_SLASH, 
    DT_PIERCE, 
    DT_FIRE, 
    DT_COLD, 
    DT_ACID,
    DT_LIGHTNING, 
    DT_WATER, 
    DT_AIR, 
    DT_MAGIC, 
    DT_POISON,
    DT_SOUND, 
    DT_DARKNESS ,
    DT_TERROR,
    DT_WHIP,
    DT_EXPLOSION,
    DT_RIP,
    DT_SQUEEZE  });
  chaos_dam_type=caster->QueryProp(CHAOS_DAM_TYPE);
  dam_type=({""});
  if(!chaos_dam_type || 
     caster->QueryProp(CHAOS_DAM_CHAOS) ||
     random(10100)>=caster->QuerySkillAbility("chaosschaden")){
       dam_type[0]=types[random(sizeof(types))];
  }
  else{
    anzahl=caster->QueryProp(CHAOS_DAM_ANZ);
    dam_type=chaos_dam_type;     
    anzahl--;
    if(anzahl==0) {
      caster->SetProp(CHAOS_DAM_TYPE,0);
      caster->SetProp(CHAOS_DAM_ANZ,0);
    }
    else{ 
      caster->SetProp(CHAOS_DAM_TYPE,dam_type);
      caster->SetProp(CHAOS_DAM_ANZ,anzahl);
    } 
  }
  return dam_type;
}
int check_align(object caster,object enemy,int dam){
  int diff;
  diff = enemy->QueryProp(P_ALIGN) - caster->QueryProp(P_ALIGN) - 1000;
  if (diff < 0) return 0;
  if (diff > 1000) diff = 1000;
  return (dam*diff)/3333;
}  
int chaosball(object caster, mapping sinfo){
  object victim, waffe;
  int dam, level, suc, anzahl,g_rate, wc;
  string vn, vnw, cn, dam_txt,check_old,dam1,dam2;
  string *chaos_dam_type;
  mixed dt;
  mixed *dam_type;
  if (caster->QueryProp(CHAOSBALL_BLOCKADE) && 
      time() - caster->QueryProp(P_LAST_MOVE) < 3) {
     write("Du denkst Dir: Halt, nein. Es ist zu frueh.\n");
     return 0;
  }
  victim=FindEnemyVictim(sinfo[SI_SKILLARG],caster,
       "Nach wem willst Du einen Chaosball werfen?\n");
  if(!victim) return 0;
  suc=SpellSuccess(caster,sinfo);
  cn=caster->name();
  vnw=victim->name(WEN,2);
  dam_type=ChaosDamage(caster,suc);
  // anzahl = caster->QueryProp(CHAOS_DAM_ANZ);
  // if(anzahl<=0)
  //   caster->SetProp(CHAOS_DAM_TYPE,0);
  if(sizeof(dam_type)==2){
    check_old=to_string(dam_type[1]);
    if(to_int(check_old)==dam_type[1]){
      write("Du benutzt einen alten Chaosschaden. Bitte diesen "
      "neu setzten!\n");
      return 0;
    }
    dam_txt=ChaosDamageText2(dam_type[0],dam_type[1],0);
  }
  else dam_txt=ChaosDamageText(dam_type[0],0);
  level=caster->QueryProp(P_LEVEL);
  if(level>27) level=27;
  
  dam=100+random(400*level)/27;

  if(sizeof(dam_type)==2){
    if(caster->QueryProp(P_SP)<sinfo[SI_SPELLCOST]+5){ 
      tell_object(caster,"Du hast zu wenig Zauberpunkte fuer diesen Spruch..\n");
      return 0;
    }
    caster->restore_spell_points(-5);
  }
  if(suc<-2500){
    printf("Hilfe! Der Spruch ging nach hinten los!\n"
    +"Du feuerst "+dam_txt+" auf Dich ab.\n");
    say(sprintf("%s feuert "+dam_txt+" auf sich ab.\n",capitalize(cn)));
    SetProp(P_NAME,"Unberechenbares Chaos");
    caster->do_damage(dam/14,caster);
    return MISSERFOLG;
  }
  if(suc<=0) return MISSERFOLG;
  say(sprintf("%s feuert "+dam_txt+" auf %s ab.\n",capitalize(cn), vnw),victim);
  printf("Du feuerst "+dam_txt+" auf %s ab.\n",vnw);
  tell_object(victim,sprintf("%s feuert "+dam_txt+" auf Dich ab.\n", 
              capitalize(cn)));
  if(objectp(waffe=caster->QueryProp(P_WEAPON))){
    dt=waffe->QueryProp(P_DAM_TYPE);
    if(stringp(dt)) dt=({dt});
    if(sizeof(dam_type)==2){
      if(member(dt,dam_type[1])!=-1 && member(dt,dam_type[0])!=-1){
        wc=waffe->QueryProp(P_WC);          
        if(!member(PHYSICAL_DAMAGE_TYPES,dam_type[0]))
          dam+=CheckDamTypes(dt,dam_type[0],waffe);  
        if(wc>150) wc=150;
        wc=wc/2;
        dam+=random(wc)+wc;                        
      }  
      dam += 50 + random(level*2);
    }
    else if(!member(PHYSICAL_DAMAGE_TYPES,dam_type[0]))
      dam+=CheckDamTypes(dt,dam_type[0],waffe);
  }
  dam+=check_align(caster,victim,dam);
  // if(anzahl>0 && !caster->QueryProp(CHAOS_DAM_CHAOS)){
  //  anzahl--;
  //  caster->SetProp(CHAOS_DAM_ANZ,anzahl);
  // }
  if(suc < victim->SpellDefend(caster,
    ([SP_NAME:"chaosball",
      SI_MAGIC_TYPE:({MT_ANGRIFF})]))){ 
    tell_object(victim,caster->Name(WESSEN)+" Chaosball zerplatzt wie "
    "eine Seifenblase.\n");
    tell_object(caster,break_string("Dein Chaosball zerplatzt wie eine "
    "Seifenblase! Aus der Ferne hoerst Du noch kurz das fiese Lachen "
    "eines Daemons. Dann wird es kurz totenstill.",78)); 
    return 1; 
  }
  sinfo += ([ SI_SKILLDAMAGE_TYPE:({ dam_type }) ]);
  TryAttackSpell(victim,dam, dam_type,([ SP_SHOW_DAMAGE:1,
  SI_SKILLDAMAGE_TYPE:dam_type ]),caster,sinfo);
  return ERFOLG;
}

int verbanne(object caster, mapping sinfo){
  string bla, blub, str;
  int resi, suc, dam;
  object victim;
  suc=SpellSuccess(caster,sinfo);
  str=sinfo[SI_SKILLARG];
  if(str=="haut"||str=="chaoshaut"||str=="chaosruestung"){   
    notify_fail("Wen willst Du verbannen?\n");
    if(!victim=present("\nchaos_ruestung",caster)) return 0;
    if(suc<=0) return MISSERFOLG;
    printf("Du richtest Deine ganze Macht gegen den Daemon in Deiner "
    +"Haut!\n");
    say(capitalize(caster->Name(WER))+" wirft wuetende Worte gegen sich "
    +"selber!\n",({caster}));
    if(suc>2000){
      victim->remove_it();
      return ERFOLG;
    }
    else if(suc>5){
      printf("Aua! Der Daemon rebelliert kurz aber kraeftig!\n");
      caster->reduce_hit_point(10+random(10));
      victim->remove_it();
      return ERFOLG;
    }
    else{
      printf("Die Verbannung hat nicht so ganz geklappt, Du hast den "
      +"Chaosdaemonen\nnur veraergert!\n");
      victim->SetProp(DAEM_FALSE,1);
      victim->chaos_chaos_chaos(26); 
      return ERFOLG;
    }
  }
  victim=FindLivingVictim(sinfo[SI_SKILLARG],caster,"Wen willst Du verbannen?\n");
  // 2x FindVictim, da das 1. ihn nicht zum Feind macht.
  // Ich machs nicht per Hand, da das Std-Spellbook evtl.
  // erweitert wird.
  if(!victim) return 0;
  if(!victim->id("daemon") && !sscanf( victim->name(), "%sdaemon%s",
     bla, blub) && !victim->QueryProp(CHAOS_DAEM_BESCHWOERER) &&
     lower_case(victim->QueryProp(P_RACE)) != "daemon" &&
     !sscanf(to_string(victim->QueryProp(P_SHORT)), "%sdaemon%s",
     bla, blub)){
    printf("%s kannst Du nicht verbannen!\n",capitalize(victim->name(WEN)));
    return 0;
  }
  victim=FindEnemyVictim(sinfo[SI_SKILLARG],caster,"Dieses Opfer ist unangreifbar.\n");
  if (!victim) return 0;
    
  if(suc<=0) return MISSERFOLG;

  if(suc < victim->SpellDefend(caster,
    ([SP_NAME:"verbanne",
      SI_MAGIC_TYPE:({MT_BEHERRSCHUNG})]))){
    tell_object(victim,caster->Name(WER)+" sagt: He, Du, geh ma weg hier!\n"+
    "Du sagst: Och noeeeeh.\n");
    tell_object(caster,"Du erhebst die Haende ueber den Kopf.\n"+
    "Du sagst: He, Du, geh ma weg hier!\n"+
    victim->Name(WER)+" sagt: Och noeeeeh.\n");
    return 1;
  }
  printf("Du hebst die Arme empor und wirfst uebelste Worte gegen %s.\n",
  victim->name(WEN) );
  say(caster->Name(WER)+" hebt die Arme empor und wirft uebelste "
  +"Worte gegen "+victim->name(WEN)+".\n");
  if(victim->id("chaos_aggressive_daemonen")){
    resi=victim->QueryProp(P_HANDS)[1];
    if(victim->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(caster))
      resi=random(resi*45);
    else 
      resi=random(resi*60);
    if(suc>resi){
        printf(break_string("Der Spruch war ein voller Erfolg! %s "+
        "verschwindet aus dieser Dimension.",78), 
        capitalize(victim->name()));
        victim->die();
        return ERFOLG;
    }
    else dam = 250 + random(700);
  }
  else if(victim->id("\nchaos_gilden_daemon")){
    resi=victim->QueryProp(DAEM_FAKTOR_MAPPING)[DAEM_AGGRESSIVE];
    if(victim->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(caster))
      resi=random(resi*285);
    else resi=random(resi*305);
    if(suc>resi){  
      printf(break_string("Der Spruch war ein voller Erfolg! %s "+
      "verschwindet aus dieser Dimension.",78), 
      capitalize(victim->name()));
      victim->die();
      return ERFOLG;
    }
    else dam=250+random(600);
  }
  else dam=400+random(500); // Gegen Nicht-Gilden-Daemonen

  TryAttackSpell(victim,dam,DT_SOUND,
  ([SP_NAME:"verbanne",SP_SHOW_DAMAGE:1]),caster,sinfo);
  return ERFOLG;
}

int finsternis(object caster, mapping sinfo){
  object victim;
  int zeit, suc, old_dattack;
  string cn, vnw;
  object *flw;
  
  
  if (caster->QueryProp(CHAOS_FINSTERNIS)>time()) {
    tell_object(caster,"Du kannst noch keine neue Finsternis zaubern.\n");
    return 0;
  }
  victim=FindEnemyVictim(sinfo[SI_SKILLARG],caster,
     "Wen willst Du mit einer Finsternis belegen?\n");
  if(!victim) return 0;
  old_dattack=victim->QueryProp(P_DISABLE_ATTACK);
  if (old_dattack>0) {
    printf("Aber %s ist doch schon verfinstert!\n",victim->name(WER));
    return 0;
  }
  suc=SpellSuccess(caster,sinfo);
  if(suc<-2000){
    printf("Oh weia! Jetzt hast Du den Zauber gegen Dich angewendet!\n");
    caster->SetProp(P_DISABLE_ATTACK,20);
  }
  if(suc<=0) return MISSERFOLG;
  caster->SetProp(CHAOS_FINSTERNIS,time()+120);
  
  if(suc < victim->SpellDefend(caster,
    ([SP_NAME:"finsternis",
      SI_MAGIC_TYPE:({MT_BEHERRSCHUNG})]))){
    tell_object(victim,caster->name(WESSEN)+" Wolke der Finsternis dreht "+
    "kurz vor Dir ab und verpufft.\n");
    tell_object(caster,break_string("Du willst "+victim->name(WEN)+
    " in eine Wolke der Finsternis huellen, doch die Wolke verzieht sich "+
    "sofort.",78));
    return 1;
  }

  cn=caster->name();
  vnw=victim->name(WEN,2);
  say(sprintf("%s huellt %s in einer Wolke aus Finsternis ein.\n",cn, vnw),
    victim);
  printf("Du huellst "+vnw+" in eine Wolke aus Finsternis ein.\n",vnw);
  tell_object(victim,
  sprintf("%s huellt Dich in eine Wolke aus Finsternis ein.\n",cn));
  zeit=4+caster->QueryAttribute(A_INT)/2+random(suc/800);
  zeit=sinfo[SI_SKILLABILITY]*zeit/MAX_ABILITY;
  if (zeit>20) zeit = 20;  // *seufz* 
  zeit = zeit * caster->QuerySkillAttribute(SA_DURATION)/100;
  victim->SetProp(P_DISABLE_ATTACK,zeit+old_dattack);
  
  // Feuerwehr: Ab jetzt greifen Daemonen bei Finsternis mit an.
  if (pointerp(caster->QueryProp(P_PURSUERS)) &&
      pointerp(caster->QueryProp(P_DEFENDERS))) {
    flw = (caster->QueryProp(P_PURSUERS)[1] & caster->QueryProp(P_DEFENDERS)) -({0});
    map_objects(flw,"Kill",victim);
  }
  return ERFOLG;
}

// Jetzt fuer Chaosschaden UND Chaoskontrolle
// gruppe: 0 mech-schaden und element-schaden
//         1 element-schaden
//         2 mech-schaden
// (Nur fuer Einzelschaeden)

static mixed check_chaosdamage(string *dam_type, int gruppe){
  mapping schaden_element,schaden_mech;
  schaden_element = ([ 
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
  schaden_mech = ([ 
    "pfeil":DT_PIERCE, 
    "messer":DT_SLASH, 
    "felsen":DT_BLUDGEON, 
    "peitsche":DT_WHIP,
    "quetschen":DT_SQUEEZE,
    "explosion":DT_EXPLOSION,
    "widerhaken":DT_RIP 
    ]);
 
 // Einzelschaeden
 
  if(sizeof(dam_type)==1){
    switch(gruppe){
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
  if(sizeof(dam_type)==2){
    if((member(schaden_element,dam_type[0])&&
        member(schaden_element,dam_type[1]))||
       (member(schaden_mech,dam_type[0])&&
        member(schaden_mech,dam_type[1]))){
      return ({});
    }
    if((member(schaden_element,dam_type[0])==0&&
        member(schaden_mech,dam_type[0])==0)||
       (member(schaden_element,dam_type[1])==0&&
        member(schaden_mech,dam_type[1])==0)){
      return ({});
    }      
    if(member(schaden_element,dam_type[0])){
      return ({schaden_element[dam_type[0]],
               schaden_mech[dam_type[1]]});
    }
    else{
      return ({schaden_element[dam_type[1]],
               schaden_mech[dam_type[0]]});
    }
  }
  return ({});
}
int chaosschaden(object caster, mapping sinfo){
  string *dam_type, str, txt1, txt2, *exp;
  int anzahl, sp, suc;
  mixed chaos_dam_type;
  dam_type=({});
  str=sinfo[SI_SKILLARG];
  chaos_dam_type = caster->QueryProp(CHAOS_DAM_TYPE);
  anzahl         = caster->QueryProp(CHAOS_DAM_ANZ);    
  suc=SpellSuccess(caster,sinfo);
  if(!str&&pointerp(chaos_dam_type)){
    if(sizeof(chaos_dam_type)==2){
      write("Verwende zum Anzeigen bitte 'chaoskontrolle'!\n");
      return 0;      
    }
    txt1=ChaosDamageText(chaos_dam_type[0],0);
    exp=explode(txt1," ");
    if(exp[0]=="einen")
    txt1="ein "+implode( exp[1..<0], " ");
    txt2=ChaosDamageText(chaos_dam_type[0],1);
    write((anzahl==1?"Der naechste Chaosball ist: "+txt1:       
      "Die naechsten "+anzahl+" Chaosbaelle sind: "+txt2)+".\n"); 
    if (caster->QueryProp(CHAOS_DAM_CHAOS))
      write("Du hast den Chaosschaden momentan deaktiviert.\n");
    return 0;
  }
  if(!str){
    printf("Du hast keinen Chaosschaden eingestellt!\n");
    return 0;
  }
  if (str == "chaos") {
    caster->restore_spell_points(19);
    if (caster->QueryProp(CHAOS_DAM_CHAOS)) {
      caster->SetProp(CHAOS_DAM_CHAOS,0);
      printf("Du verwendest wieder Deinen Chaosschaden.\n");
      return 1;
    } else {
      caster->SetProp(CHAOS_DAM_CHAOS,1);
      printf("Du verwendest keinen Chaosschaden mehr.\n");
      return 1;
    }
  }
    
  dam_type=({str});
  dam_type=check_chaosdamage(dam_type,0);
  if(!sizeof(dam_type)){
    printf("Diesen Schadenstyp kannst Du nicht waehlen.\n");
    return 0;
  }
  if(str=="boese"&&this_player()->QueryProp(P_ALIGN)>-200){
    printf("Du bist nicht boese genug um satanische Flueche zu sprechen!\n");
    return 0;
  }
  if(suc<=0) return MISSERFOLG;
  if(pointerp(chaos_dam_type)) anzahl+=
    1+random(caster->QueryProp(P_GUILD_LEVEL)); 
  else 
    anzahl=1+random(caster->QueryProp(P_GUILD_LEVEL));
  if(pointerp(chaos_dam_type)){
    if(sizeof(chaos_dam_type)==2){
      write("Du stellst den Chaosball von Chaoskontrolle auf "+
      "Chaosschaden um.\n");
    }
    else if(chaos_dam_type[0]!=dam_type[0]){  
      write("Du aenderst den Schadenstyp.\n");
    }
  }
  txt1=ChaosDamageText(dam_type[0],0);
  exp=explode(txt1," ");
  if(exp[0]=="einen") txt1="ein "+implode(exp[1..<0]," ");
  txt2=ChaosDamageText(dam_type[0],1);
  caster->SetProp(CHAOS_DAM_TYPE,({dam_type[0]}));
  caster->SetProp(CHAOS_DAM_ANZ,anzahl);
  printf((anzahl==1?"Der naechste Chaosball ist: "+txt1:
    "Die naechsten "+anzahl+" Chaosbaelle sind: "+txt2 )+".\n");
  say(capitalize(caster->name())+
    " murmelt seltsame Worte. "+(caster->QueryProp(P_GENDER)==1?"Seine": 
    "Ihre")+" Augen leuchten kurz rot auf.\n");
  return ERFOLG;
}
int chaoskontrolle(object caster, mapping sinfo){
  string str,txt1,txt2,*exp,s1,s2;
  int anzahl, sp, suc;
  mixed chaos_dam_type,dam_type;
  str=sinfo[SI_SKILLARG];
  chaos_dam_type = caster->QueryProp(CHAOS_DAM_TYPE);
  anzahl         = caster->QueryProp(CHAOS_DAM_ANZ);   
  suc=SpellSuccess(caster,sinfo);
  if(!str&&pointerp(chaos_dam_type)&&sizeof(chaos_dam_type)==2){
    txt1=ChaosDamageText2(chaos_dam_type[0],chaos_dam_type[1],0);
    exp=explode(txt1," ");
    if(exp[0]=="einen") txt1 ="ein "+implode(exp[1..<0]," ");
    txt2=ChaosDamageText2(chaos_dam_type[0],chaos_dam_type[1],1);
    write((caster->QueryProp(CHAOS_DAM_ANZ)==1?"Der naechste Chaosball ist: "+txt1:       
    "Die naechsten "+caster->QueryProp(CHAOS_DAM_ANZ)+
    " Chaosbaelle sind: "+txt2)+".\n"); 
    if (caster->QueryProp(CHAOS_DAM_CHAOS))
      write("Die Chaoskontrolle hast Du deaktiviert.\n");
    return 0;
  }
  if(!str){
    printf("Du hast keine Chaoskontrolle eingestellt!\n");
    return 0;
  }
  if (str == "chaos") {
    caster->restore_spell_points(19);
    if (caster->QueryProp(CHAOS_DAM_CHAOS)) {
      caster->SetProp(CHAOS_DAM_CHAOS,0);
      printf("Du verwendest wieder Deinen Chaosschaden.\n");
      return 1;
    } else {
      caster->SetProp(CHAOS_DAM_CHAOS,1);   
      printf("Du verwendest keinen Chaosschaden mehr.\n");
      return 1;
    }
  }
  if(sscanf(str,"%s und %s",s1,s2)!=2){
    printf("Wie nun? Chaoskontrolle <schaden1> und <schaden2>\n");
    return 0;
  }
  dam_type=({s1,s2});
  dam_type=check_chaosdamage(dam_type,0);
  if(!sizeof(dam_type)){
    printf("Diese Kombination geht leider nicht.\n");
    return 0;
  }
  if((s1=="boese"||s2=="boese")&&this_player()->QueryProp(P_ALIGN)>-300){
    printf("Du bist nicht boese genug, um dies zu kontrollieren!\n");
    return 0;
  }
  if(suc<= 0) return MISSERFOLG;
  if(pointerp(chaos_dam_type)) 
    anzahl=caster->QueryProp(CHAOS_DAM_ANZ)+1+random(caster->QueryProp(P_GUILD_LEVEL)); 
  else 
    anzahl=1+random(caster->QueryProp(P_GUILD_LEVEL));
  //if(pointerp(chaos_dam_type) && chaos_dam_type != dam_type )
  if(pointerp(chaos_dam_type)){
    if(sizeof(chaos_dam_type)==2){
      if(chaos_dam_type[0]!=dam_type[0]||chaos_dam_type[1]!=dam_type[1]){
         write("Du aenderst den Schadenstyp.\n");
       }
     }
     else if(sizeof(chaos_dam_type)==1){
       write("Du stellst den Chaosball von Chaosschaden auf "+
       "Chaoskontrolle um.\n");
     }
   }
   txt1=ChaosDamageText2(dam_type[0],dam_type[1],0);
   exp=explode(txt1, " ");
   if(exp[0]=="einen") txt1="ein "+implode(exp[1..<0]," ");
   txt2=ChaosDamageText2(dam_type[0],dam_type[1],1);
   caster->SetProp(CHAOS_DAM_TYPE,dam_type);
   caster->SetProp(CHAOS_DAM_ANZ,anzahl);
   printf((anzahl==1?"Der naechste Chaosball ist: "+txt1:
   "Die naechsten "+anzahl+" Chaosbaelle sind: "+txt2 )+".\n");
   say(capitalize(caster->name())+
   " murmelt geheimnisvolle Worte der Macht. "
   +(caster->QueryProp(P_GENDER)==1?"Seine": 
   "Ihre")+" Augen blitzen blutig-rot auf.\n");
    return ERFOLG;
}


int chaosruestung( object caster, mapping sinfo){
  object ruest;
  int level, suc, alig;
  if(present("\nchaos_ruestung",caster)){
    printf("Du kannst immer nur eine Chaosruestung besitzen.\n");
    return 0; 
  }
  level=caster->QueryProp(P_GUILD_LEVEL);
  suc=SpellSuccess(caster,sinfo);
  if(suc<-2000){
    call_out("falscher_daemon",0,caster,-(suc/1000)*level/3);
    return MISSERFOLG;
  }
  if(suc<=0) return MISSERFOLG;
  ruest=clone_object(CHAOS_CHAOSHAUT);
  alig=caster->QueryProp(P_ALIGN);
  if(alig>-2000)
    caster->SetProp(P_ALIGN,caster->QueryProp(P_ALIGN)-30*level);
    printf("Du beschwoerst einen unheimlichen Daemon, der direkt in "
    +"Deine Haut eindringt.\n");
    say(break_string(capitalize(caster->name())+" macht seltsame "
    +"Bewegungen, spricht magische Worte einer seltsamen Sprache und "
    +"beschwoert so einen unheimlichen Daemon, der sofort in " 
    +(caster->QueryProp(P_GENDER)==1?"seine":"ihre")+" Haut "
    +"eindringt und diese mutieren laesst. Es sieht einfach gruselig "
    +"aus.",78));
    ruest->move(caster,M_NOCHECK);
    ruest->SetProp(CHAOS_DAEM_BESCHWOERER,getuid(caster));
    ruest->SetProp(RUEST_CASTER_LEVEL,level);
//ruest->SetProp( P_AC, 29 + level); // raus, da jetzt AT_MISC
    ruest->do_wear("_chaos_ruestung_",1);
    ruest->SetProp(P_CURSED,1);
    ruest->SetProp(DAEM_FALSE,1);
    ruest->starte_anziehen(suc);
    return ERFOLG;
}

int kontrolle(object caster, mapping sinfo){
  int suc;
  object ob;

  ob=present("\nchaos_ruestung",caster);
  if(!ob->QueryProp(DAEM_FALSE)){
    printf("Der Daemon der Chaos-Ruestung ist doch noch friedlich.\n");
    return 0;
  }
  suc=SpellSuccess(caster,sinfo);
  if(suc<-2000){
    printf("Mist, der Spruch ging voellig daneben.\n");
    caster->reduce_hit_point( random(-suc/100));
    return MISSERFOLG;
  }
  if(suc<=0) return MISSERFOLG;
  ob->SetProp(DAEM_FALSE,0);
  printf("Du erlangst die Kontrolle ueber die Chaos-Ruestung zurueck.\n");
  say(break_string(capitalize(caster->name())+" fuchtelt mit den "
  +"Haenden herum, und spricht seltsame Worte. Ploetzlich scheinen "
  +(caster->QueryProp(P_GENDER)==1?"seine":"ihre")+
  " seltsamen Anfaelle weg zu sein.",78));
  return ERFOLG;
}

int bannzauber(object caster, mapping sinfo){
  int suc;
  object ob;
  if(!ob=present("\nchaos_gilden_pentagramm_"+getuid(caster), 
     environment(caster))){
    printf( "Du brauchst ein eigenes Pentagramm fuer diesen Spruch.\n");
    return 0;
  }
  if(!ob->QueryProp(CHAOS_BANNKREIS)){
    printf("Du musst den Bannzauber auf einen Bannkreis sprechen.\n");
    return 0;
  }
  if(ob->QueryProp(CHAOS_BANNKREIS)==2){
    printf("Auf dem Bannkreis liegt schon ein Bannzauber.\n");
    return 0;
  }
  suc=SpellSuccess(caster,sinfo);
  if(suc<-3500){
    printf("Argl! Der Spruch ging voellig daneben und zerstoert das "
    +"Pentagramm!\n");
    say(break_string(capitalize(caster->name())+" tanzt um das Pentagramm "+
    "herum, spricht magische Worte und beschwoert finstere Kraefte. "+
    "Dann schiesst ploetzlich ein heller Strahl hinab und zerstoert "+
    "das Pentagramm und den Bannkreis.",78));
    ob->reset();
    return MISSERFOLG;
  }
  if(suc<-2500){
    printf("Mist, der Spruch ging daneben. Der Spruch verschlechtert den "
    +"Bannkreis.\n");
    say(break_string( capitalize(caster->name())+" tanzt um das "+
    "Pentagramm herum, spricht magische Worte und beschwoert "+
    "finstere Kraefte. Dann schiesst ploetzlich ein heller Strahl "+
    "hinab und laesst den Bannkreis aufleuchten.",78));
    ob->SetProp(CHAOS_BANNKREIS,2);
    ob->SetProp(CHAOS_BANNKREIS_FAKTOR, 
    ob->QueryProp(CHAOS_BANNKREIS_FAKTOR)-10-random(50)); 
    return MISSERFOLG;
  }
  if(suc<=0) return MISSERFOLG;
  ob->SetProp(CHAOS_BANNKREIS,2);

  if (ob->QueryProp(CHAOS_NEUES_PENTA)) {
    ob->SetProp(CHAOS_BANNKREIS_RANDOM,ob->QueryProp(CHAOS_BANNKREIS_RANDOM)+
    caster->QueryProp(P_GUILD_LEVEL)*2+8*suc/1000);
    ob->SetProp(CHAOS_BANNZAUBER_FAKTOR,suc);
  }
  else
    ob->SetProp(CHAOS_BANNKREIS_FAKTOR,ob->QueryProp(CHAOS_BANNKREIS_FAKTOR)+
    caster->QueryProp(P_GUILD_LEVEL)*2+8*suc/1000);
  printf("Du sprichst einen Bannzauber auf den Bannkreis.\n");
  if(suc>=5000){
    printf("Der Spruch war so gut, dass auch das Pentagramm verbessert "
    +"wird.\n");

    if (ob->QueryProp(CHAOS_NEUES_PENTA)) {
      ob->SetProp(CHAOS_PENTAGRAMM_RANDOM,
      ob->QueryProp(CHAOS_PENTAGRAMM_RANDOM)+
      caster->QueryProp(P_GUILD_LEVEL)+5*suc/1000);
    }
    else
      ob->SetProp(CHAOS_PENTAGRAMM_FAKTOR, 
      ob->QueryProp(CHAOS_PENTAGRAMM_FAKTOR)+
      caster->QueryProp(P_GUILD_LEVEL)+5*suc/1000);
  }
  say(break_string(capitalize(caster->name())+" tanzt um das Pentagramm "+
  "herum, spricht magische Worte und beschwoert finstere Kraefte. Dann "+
  "schiesst ploetzlich ein blutroter Strahl hinab und laesst den "+
  "Bannkreis schaurig aufleuchten.", 78));
  return ERFOLG;
}

object FindeEigenenDaemonen(string daemon, object caster){
  object *inv;
  int i;
  if(!daemon) return 0;
  inv=filter(all_inventory(environment(caster)), (: living($1) :));
  inv=filter_objects(inv,"id",daemon);
  for(i=sizeof(inv)-1;i>=0;i--){
    if(inv[i]->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(caster))
      return inv[i];
  }
  return 0;
}

int binde( object caster, mapping sinfo){
  object daem;                                                         
  string str;
  mixed pers;
  int suc, count, zeit;
  suc=SpellSuccess(caster,sinfo);
  daem=FindeEigenenDaemonen(sinfo[SI_SKILLARG],caster);
  if(!daem){
    if (sinfo[SI_SKILLARG] &&
        present(sinfo[SI_SKILLARG],environment(caster)))
      printf("Das Ding wurde nicht von Dir beschworen.\n");
    else
      printf("So nen Daemonen findest Du hier nicht!\n"); 
    return 0;
  }
  if(!daem->id("\nchaos_gilden_daemon")){
    printf("Du kannst nur Gilden-Daemonen an Dich binden!\n");
    return 0;
  }
  if(daem->QueryProp(CHAOS_DAEM_BESCHWOERER)!=getuid(this_player())){
    printf("Du kannst nur Deine eigenen Daemonen an Dich binden!\n");
    return 0;
  }
  if(suc<=0){
    switch(random(100)){
      case 1..3:
        printf( "Der Spruch hat ueberhaupt nicht funktioniert! Seltsam, "
        +"warum\nschaut Dich der Daemon auf einmal so komisch an? Warum "
        +"grinst er bloss?\n");
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
  printf("Du stierst "+daem->name(WEN)+" finster an und sprichst Worte der "
  +"Macht.\n"
  +capitalize(daem->name())+" wird dadurch eingeschuechtert und bleibt "
  +"laenger unter\nDeiner Kontrolle.\n");
  say(capitalize(caster->name())+" stiert "+daem->name(WEN)+" finster und "
  +"boese an.\n");
  if(count=daem->QueryProp(DAEM_COUNT_DOWN)){                   
    count += random(caster->QueryAttribute(A_INT))+suc/200;
    str = capitalize(daem->name())+" wird vorraussichtlich jetzt ";
    switch(count){
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
    printf(break_string(str,78));                                      
    daem->SetProp(DAEM_COUNT_DOWN,count);
  }
  if(zeit=daem->QueryProp(CHAOS_DAEM_FOLLOW_TIME)){
    zeit += random(600)+suc/3;                                            
    str=capitalize(daem->name())+" wird Dir vorraussichtlich ";
    switch(zeit - time()){
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
    printf(break_string(str,78));                                        
    daem->SetProp(CHAOS_DAEM_FOLLOW_TIME, zeit);
    if(!pointerp(pers=caster->QueryProp(P_PURSUERS)) 
       || member(pers[1],daem)==-1)
      caster->AddPursuer(daem);
  }
  if(suc>3000) caster->AddPursuer(daem);
  return ERFOLG;
}
// Verwandlungen bei einem völlig missglückten Chaosmasken-Spruch
static mapping *masken_pech = ({
  ([
    P_NAME:   "Häschen",
    P_GENDER: NEUTER,
    P_RACE:   "Hase",
    P_SHORT:  "@WER1, verwandelt in ein flauschiges Häschen",
    P_LONG:   "@WER1 wollte wohl ein Dämon werden. Herausgekommen ist "
              "ein kleines, flauschiges Häschen mit langen Ohren und "
              "einem zuckenden Näschen.",
    P_MSGIN:  "hoppelt herein",
    P_MSGOUT: "hoppelt",
    P_HANDS:  ({" mit kleinen Hasenpfoten",10,({DT_BLUDGEON})}),
    P_IDS:    ({"häschen","hase"}),
  ]),
  ([
    P_NAME:   ({"Teddybär","Teddybären","Teddybären","Teddybären"}),
    P_GENDER: MALE,
    P_RACE:   "Teddybär",
    P_SHORT:  "@WER1, verwandelt in einen knuddeligen Teddybären",
    P_LONG:   "@WER1 wollte wohl ein Dämon werden. Herausgekommen ist "
              "ein knuddeliger Teddybär mit Knopfaugen und einer roten "
              "Schleife um den Hals.",
    P_MSGIN:  "tapst herein",
    P_MSGOUT: "tapst",
    P_HANDS:  ({" mit weichen Plüschtatzen",10,({DT_BLUDGEON})}),
    P_IDS:    ({"teddybär","teddy","bär"}),
  ]),
});

// Dauer der Verwandlung in Sekunden
static int masken_dauer(object caster, int suc) {
  int dauer = 60 + max(suc,0)/40;

  if(IS_SEER(caster)) {
    dauer += 60;
  }
  return dauer;
}

int chaosmaske(object caster, mapping sinfo) {
  object maske, sh;
  int suc;

  if(caster->QueryProp(P_CHAOS_MASKE)) {
    write("Du bist doch schon verwandelt. Verschwende deine Macht nicht "
          "so!\n");
    return 0;
  }
  maske = (filter_objects(caster->QueryProp(P_ARMOURS)||({}),
                          "id",CHAOS_MASKE_ID)+({0}))[0];
  if(!maske) {
    write(CTSA("Also, eine Dämonenmaske solltest du dafür schon "
               "tragen.\n"));
    return 0;
  }
  if(environment(caster)->QueryProp(P_TOTAL_LIGHT) > 0 &&
     !IS_LEARNER(caster)) {
    write("Es ist viel zu hell hier.\n");
    return 0;
  }
  suc = SpellSuccess(caster,sinfo);

  sh = clone_object(CHAOS_MASKE_SHADOW);

  if(suc <= -4000) {
    // Gaaaanz schlecht...
    write(break_string("Du rufst die Kraft des Chaos in deine Maske. "
      "Irgendetwas läuft dabei gründlich schief!"));
    sh->maske_an(caster,masken_pech[random(sizeof(masken_pech))],
                 masken_dauer(caster,-suc),0);
    say(break_string(caster->Name(WER,1)+" verwandelt sich unter "
      "lautem Puffen in "+caster->name(WEN)+"."),caster);
    Learn(caster,"chaosmaske",sinfo);
    return 0;
  }
  if(suc <= 0) {
    destruct(sh);
    return MISSERFOLG;
  }
  write(break_string("Du rufst die Kraft des Chaos in deine Maske. Sie "
    "verschmilzt mit deinem Gesicht, und dein Körper verwandelt sich!"));
  say(break_string(caster->Name(WER,1)+" murmelt finstere Worte und "
    "verwandelt sich vor deinen Augen."),caster);

  sh->maske_an(caster,maske->QueryProp(P_CHAOS_MASKE_DATEN),
               masken_dauer(caster,suc),suc);

  if(objectp(sh)) {
    tell_room(environment(caster),CTSA("Vor dir steht jetzt "+
      caster->name(WER)+".\n"),({caster}));
  }
  return ERFOLG;
}
// Die Dämonen ------------------------------------------------------------

// Der eigene Dämon dieses Typs im Raum
static object FindeTypDaemon(string typ, object caster) {
  return present(typ+"_"+getuid(caster),environment(caster));
}

// beschwoere <typ> [leise]
int beschwoere(object caster, mapping sinfo) {
  string arg = sinfo[SI_SKILLARG], wort, rest, typ;

  if(!arg) {
    write(CTSA("Welchen Dämon willst du beschwören?\n"));
    return 0;
  }
  if(sscanf(arg,"%s %s",wort,rest) != 2) {
    wort = arg;
    rest = 0;
  }
  typ = CHAOS_DAEMONEN_MASTER->FindeTyp(wort);

  if(!typ) {
    write(CTSA("So einen Dämon kennst du nicht.\n"));
    return 0;
  }
  if(!caster->QuerySkill(typ)) {
    write(CTSA("Diesen Dämon hast du noch nicht beschwören gelernt.\n"));
    return 0;
  }
  // Der Spruch des Typs kostet, ermüdet und wird geübt, nicht dieser
  caster->UseSpell(rest,typ);
  return 0;
}

static int beschwoere_typ(object caster, mapping sinfo, string typ) {
  mapping d = CHAOS_DAEMONEN_MASTER->QueryTyp(typ);
  object daem, p;
  int result, suc, pentaf, kreisf;
  mixed *n;

  if(!mappingp(d)) {
    return 0;
  }
  if(d[CD_ERZMEISTER] && !CHAOS_GILDENMASTER->ist_erz(caster) &&
     !CHAOS_MAGIER(caster)) {
    write("Du bist nicht der Erzmeister des Chaos!\n");
    return 0;
  }
  if(daem = FindeTypDaemon(typ,caster)) {
    write(break_string("Du beschwörst magische Kräfte, doch da "+
      daem->name(WER,1)+" schon da ist, passiert überhaupt nichts."));
    return 0;
  }
  suc = SpellSuccess(caster,sinfo);

  if(suc <= 0) {
    return MISSERFOLG;
  }
  p = present("\nchaos_gilden_pentagramm_"+getuid(caster),
              environment(caster));
  pentaf = get_pf(p);
  kreisf = get_kf(p);
  result = check_result(daemon[typ],caster,pentaf,kreisf,suc);

  // Wer starke Dämonen mit schlechtem Pentagramm beschwört, bekommt
  // einen aggressiven Dämon
  if(!result && pointerp(d[CD_MIN_PENTA]) &&
     (!objectp(p) ||
      p->QueryProp(CHAOS_PENTAGRAMM_FAKTOR) < d[CD_MIN_PENTA][0] ||
      p->QueryProp(CHAOS_BANNKREIS_FAKTOR) < d[CD_MIN_PENTA][1])) {
    result = DA;
  }
  if(result == WD) {
    call_out("falscher_daemon",0,caster,daemon[typ][WRONG_DAEM]);

    if(p && !CHAOS_MAGIER(caster)) {
      p->starte_entfernen(10);
    }
    return ERFOLG;
  }
  daem = clone_object(typ == "orakeldaemon" ? CHAOS_GILDEN_MON("orakel")
                                            : CHAOS_GILDEN_MON("daemon"));
  n = CHAOS_NAMEN_MASTER->get_name();
  daem->konfiguriere(typ,n[0],n[1],d[CD_TITEL][random(sizeof(d[CD_TITEL]))]);
  daem->setDaemBeschwoerer(caster);
  daem->AddId(typ+"_"+getuid(caster));

  if(d[CD_ABFANGEN]) {
    daem->SetProp(DAEM_DEFEND_FAKTOR,d[CD_ABFANGEN]);
  }
  if(typ == "blutdaemon" && CHAOS_GILDENMASTER->ist_erz(caster)) {
    daem->SetProp(DAEM_DEFEND_FAKTOR,20);
  }
  if(result == DD) {
    daem->SetProp(DAEM_DISAPPEAR,1);
  }
  if(result == DA) {
    daem->SetProp(DAEM_AGGRESSIVE,1);
  }
  if(result == DF) {
    daem->SetProp(DAEM_FALSE,1);
  }
  daem->SetProp(DAEM_FAKTOR_MAPPING,daemon[typ]);

  write(break_string("Du beschwörst unheimliche Kräfte und öffnest so "
    "ein Tor in andere Welten."));
  say(break_string(replace_personal(d[CD_SAY],({caster}),1)),caster);

  daem->move(environment(caster),M_TPORT);

  if(pointerp(d[CD_FOLGEZEIT])) {
    daem->SetProp(CHAOS_DAEM_FOLLOW_TIME,time()+d[CD_FOLGEZEIT][0]+
                  d[CD_FOLGEZEIT][1]*suc/1000);
  }
  if(d[CD_RUNDEN]) {
    daem->SetProp(DAEM_COUNT_DOWN,caster->QueryAttribute(A_INT)+
                  d[CD_RUNDEN]*suc/1000);
  }
  if(d[CD_BLEIBT]) {
    daem->SetProp(CHAOS_DAEM_NO_DISAPPEAR,1);
  }
  if(result != DF || random(100) > daemon[typ][DAEM_FALSE]) {
    caster->AddPursuer(daem);

    if(sinfo[SI_SKILLARG] == "leise") {
      daem->SetProp(P_FOLLOW_SILENT,1);
    }
  }
  if(d[CD_KAMPF] &&
     (result != DF || random(100) > daemon[typ][DAEM_FALSE])) {
    caster->AddDefender(daem);
  }
  if(p && !CHAOS_MAGIER(caster)) {
    p->starte_entfernen(d[CD_KAMPF] ? 8 : 10);
  }
  if(d[CD_KAMPF] && kreisf+pentaf > 50 &&
     suc+20*kreisf+20*pentaf > 7300 && !result) {
    write(break_string("Du hast "+daem->name(WEN,1)+" ungewöhnlich gut "
      "beschworen. In den Augen erkennst du eine ungewohnte Schärfe."));
    daem->SetProp(DAEM_CAN_SPEAK,1);
  }
  if(d[CD_POWER] && result != DA) {
    daem->setPower(p,caster,sinfo[SI_SKILLABILITY]);
  }
  return ERFOLG;
}

int orakeldaemon(object caster, mapping sinfo) {
  return beschwoere_typ(caster,sinfo,"orakeldaemon");
}

int schattendaemon(object caster, mapping sinfo) {
  return beschwoere_typ(caster,sinfo,"schattendaemon");
}

int lichtdaemon(object caster, mapping sinfo) {
  return beschwoere_typ(caster,sinfo,"lichtdaemon");
}

int feuerdaemon(object caster, mapping sinfo) {
  return beschwoere_typ(caster,sinfo,"feuerdaemon");
}

int saeuredaemon(object caster, mapping sinfo) {
  return beschwoere_typ(caster,sinfo,"saeuredaemon");
}

int blutdaemon(object caster, mapping sinfo) {
  return beschwoere_typ(caster,sinfo,"blutdaemon");
}

int wandler(object caster, mapping sinfo) {
  return beschwoere_typ(caster,sinfo,"wandler");
}

int check_result(mapping daem,object caster,int pentaf,int kreisf,int abil){
  int align;
  align=caster->QueryProp(P_ALIGN);
  if(align>200) align=200;
  align=-align/6;
  if(!pentaf) pentaf=-daem[WRONG_DAEM];
  if(!kreisf) kreisf=-(daem[DAEM_DISAPPEAR]+daem[DAEM_AGGRESSIVE]+
    daem[DAEM_FALSE])/2;
  //  < 17   +random( < 400 + 100 + 100 )
  if(pentaf/4+random(50+pentaf*5+abil/100+align)<=daem[WRONG_DAEM]) 
    return WD;
  if(kreisf/4+random(50+kreisf*5+abil/100+align)<=daem[DAEM_AGGRESSIVE]) 
    return DA;
  if(kreisf/4+random(50+kreisf*5+abil/100+align)<=daem[DAEM_DISAPPEAR]) 
    return DD;
  if((kreisf+pentaf)/4+random(50+(pentaf+kreisf)*2+abil/100+align)<=
      daem[DAEM_FALSE]) return DF;
  return 0;
}

int get_pf(object p) {
  int pentaf;
  pentaf = 0;
  if (p) {
    pentaf = p->QueryProp(CHAOS_PENTAGRAMM_FAKTOR);
    if (p->QueryProp(CHAOS_NEUES_PENTA))
      pentaf += p->QueryProp(CHAOS_PENTAGRAMM_RANDOM);
  }
  return pentaf;
}

int get_kf(object p) {
  int kreisf;
  kreisf = 0;
  if (p) {
    kreisf = p->QueryProp(CHAOS_BANNKREIS_FAKTOR);
    if (p->QueryProp(CHAOS_NEUES_PENTA))
      kreisf += p->QueryProp(CHAOS_BANNKREIS_RANDOM);
  }
  return kreisf;
}

void falscher_daemon(object caster, int wd){
  object daem, p, *zau, *u;
  int i;
  if(!caster) return;
  tell_object(caster,break_string("Oh oh! Da lief was "+
  "schief. Du hast einen entscheidenden Fehler gemacht und "+
  "so einen anderen Daemon als erwartet beschworen.", 78));
  say(break_string("Oh oh! "+caster->name()+
  " muss irgendetwas falsch gemacht haben! "+
  (caster->QueryProp(P_GENDER)==1?"Er":"Sie")+" wird ploetzlich "+
  "ganz weiss im Gesicht und flucht lautstark.",78),caster);
  switch(random(wd)){
    case 0..3:
      daem=clone_object(CHAOS_GILDEN_MON("uebmatu"));
      daem->SetProp(DAEM_AGGRESSIVE,getuid(caster));
      daem->setDaemBeschwoerer(caster);
      tell_room(environment(caster),
      "Ein laecherlicher Daemon, Uebmatu genannt, faellt herein.\n");
      daem->move(environment(caster),M_GO|M_SILENT);
      break;
    case 4..7:
      daem=clone_object(CHAOS_GILDEN_MON("anthukt"));
      daem->SetProp(DAEM_AGGRESSIVE,getuid(caster));
      daem->setDaemBeschwoerer(caster);
      tell_room(environment(caster),
      "Ein spinnenaehnlicher Daemon mit Ziegenkopf krabbelt herein.\n");
      daem->move(environment(caster),M_GO|M_SILENT);
      break;
    case 8..12: 
      daem=clone_object(CHAOS_GILDEN_MON("chochos"));
      daem->SetProp(DAEM_AGGRESSIVE,getuid(caster));
      daem->setDaemBeschwoerer(caster);
      tell_room(environment(caster),
      "Ein schwarzer Daemon schleicht in diese Dimension!\n");
      daem->move(environment(caster),M_GO|M_SILENT);
      break;
    case 13..18:
      daem=clone_object(CHAOS_GILDEN_MON("daedhel"));
      daem->SetProp(DAEM_AGGRESSIVE,getuid(caster));
      daem->setDaemBeschwoerer(caster);
      tell_room(environment(caster),
      "Daedhel stuermt wild herein! Flieht, Sterbliche!\n");
      daem->move(environment(caster),M_GO|M_SILENT);
      break;
    case 19..33: 
      daem=clone_object(CHAOS_GILDEN_MON("hothrog"));
      daem->SetProp(DAEM_AGGRESSIVE,getuid(caster));
      daem->setDaemBeschwoerer(caster);
      tell_room(environment(caster),
      "Ein boesartiger Daemon, er ist unter dem Namen Hothrog bekannt,\n"
      +"beschworen von "+caster->name(WEN)+", stuermt herein!\n");
      daem->move(environment(caster),M_GO|M_SILENT);
      break;   
    case 34..60:
      daem=clone_object(CHAOS_GILDEN_MON("rythoth"));
      daem->SetProp(DAEM_AGGRESSIVE,getuid(caster));
      daem->setDaemBeschwoerer(caster);
      tell_room(environment(caster),
      "Ein uebler Hetzerdaemon, bekannt unter der Bezeichnung Rythoth, "
      +"hetzt\nherein, auf der Suche nach blutigen Opfern.\n");
      daem->move(environment(caster),M_GO|M_SILENT);
      break;
    default: tell_object( caster, "Es passiert nichts.\n");
  }
  if(daem) daem->setDaemBeschwoerer(caster);
}
