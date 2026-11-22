// Also: Meisterraum von Anakin, Ziel ist 200K Filesize :)
//
// Was mach ich wenn ich kein Chaot mehr bin? Die ganze Arbeit umsonst? Argh...nene
// da muss ich mir was einfallen lassen...
// Der Raum wird nie ausgeswappt -> Merlin ruft nach  jedem Reboot oder updaten
// pro Spieler einmal 
// 
// versch. Richtunegn zur Meisterzentrale noch eingeben
// den Pfad zum clonen des Rings noch machen...zeile 516 oder so
// Kruuolq brauechte die, oder sowas in der Richtung :)
//
//     AddInfo( ({"ersten meister des chaos"}), 
//                 "Anakin war der erste Meister des Chaos, als Chaoten noch richtige "
//                 "Chaoten waren.", "sagt:");

#include "def.h"

inherit "/std/room";


#define BS(x)           break_string(x)
#define NAME		capitalize(getuid(this_player()))
#define P_NO_COM        "no_com"
#define P_OLD_TITLE     "old_title"
#define P_FRIENDS	"friends"
#define P_DAEMON_KILLED "daemon_killed"	// Spaeter evt. benutzt

string zeit();
string welt();
string kammer();
string burg();

mixed *sequenz;

string stuhl;
string titel;
int schrank;
string *rufer;
int ring;


create() {

  ::create();
  SetProp(P_LIGHT, 1);
  SetProp(P_INT_SHORT, "Der Beschwoerungsraum von Anakin");
  SetProp(P_INT_LONG, BS(
    "Du stehst in einer kleinen dunklen Kammer. Die Waenden bestehen "
    "aus einem schwarzem, Dir unbekannten Gestein, das das Licht zu "
    "verschlingen scheint. Einen kleinen Schrank kannst Du in der Ecke "
    "ausmachen. In der Mitte des Raumes steht ein Stuhl."));
    
  // So jetzt eine kleine Todessequenz um meinem Ziel von 200K etwas naeher zu kommen...=8-)
  // Beileid mitloggen

    
  sequenz = ({
    0,"Du setzt dich etwas gespannt auf den Stuhl. Langsam umschliesst Du die Armlehnen.\n"
      "Du spuerst einen kleinen Stich.",
    0,"TOD",
    
    1,"TEILEMIT:)",
    
    1,"Das war es ja dann mal wieder, wer hat denn den Mist geproggt...einfach so tot.",
    
    2,"Sowas mir. Einem Topf-Seher. Jeder Anfaenger waere nicht nicht darauf reingefallen.",
    
    1,"Ungeduldig wartest Du auf Lars und den Tod. Oder auf einen anderen. Neuerdings\n"
    "kommt ja immer wieder ein anderer. Diese ganzen komischen neumodischen Todes-\n"
    "sequenzen. Du versuchst Dich an deine letzte Sequenz zu erinnern.\n",
    
    4,"....und jetzt? Kommt hier niemand?",
    
    3,"Langeweile.....Langeweile..Langeweile. Doch halt. Was war das?",
    
    3,"Ploetzlich hoerst Du ein Rumpeln von rechts hinten.",
    
    1,"Du denkst . o O (Endlich geht es voran.)",
    
    4,"Das Rumpeln wird wieder leiser.",
    
    1,"War wohl nichts.",
    
    4,"Kruuolq erscheint ploetzlich aus einer anderen Dimension.",
    
    2,"Kruuolq sagt: Na?",
    
    1,"Hmm...sieht nicht aus wie eine klassische Todessequenz.",
    
    2,"Kruuolq grinst Dich an.",
    
    4,"Kruuolq sagt: Tjaaaaaaa...das waere dem ersten Meister des Chaos \nKruuolq sagt: nicht passiert.",
    
    3,"Du nimmst dir fest vor ihn mal bei Gelegenheit nach ihm zu fragen.",
    
    1,"Kruuolq macht eine theatralische Geste.",
    
    2,"Kruuolq sagt: Die Chaoten sind auch nicht mehr das was sie mal waren.",
    
    1,"Kruuolq grummelt: Was solls, hier kannst Du nicht bleiben.",
    
    2,"Kruuolq sagt: Irgendjemand muss was gegen die Zauberer unternehmen, auch solche\nKruuolq sagt: Deppen wie Du koennen da helfen.",
    
    2,"Kruuolq gruebelt.",
    
    2,"Kruuolq wiederholt die Geste. Diesmal etwas ausschweifender.\nNichts passiert.",
    
    2,"Kruuolq flucht.",
    
    3,"Wuuqour erscheint.",
    
    1,"Wuuqour fluestert Kruuolq etwas zu.",

    1,"Kruuolq nicht grinsend.",
    
    0,"Wuuqour verschwindet wieder.",
    
    1,"Kruuolq grinst breit wie Kruoolq.",

    2,"Kruuolq greift in das Nichts und hat ploetzlich ein kleines Flaeschchen in der Hand.",
    
    1,"Kruuolq floest Dir den Inhalt des Flaschchens ein.",
    
    0,"Lars und der Tod kommen rein.",
    
    1,"Kruuolq sagt: hi",
    
    2,"Lars sagt: Hallo Kruuolq",
    
    0,"DER TOD GRUMMELT: MIST JOB",
    
    1,"Lars schaut Dich an.",
    
    1,"DER TOD SCHAUT DICH AN.",
    
    2,"Lars schaut den Tod an.",
    
    2,"DER TOD SCHAUT LARS AN.", 
    
    3,"Der Tod und Lars winken ab.",
    
    1,"Kruuolq winkt den Beiden nach.",
    
    1,"Du hoerst nur noch ein Gelaechter aus der Ferne.",
    
    0,"HAHAHAHAHAHAHA....",
    
    1,"Du spuerst die Kraft des Trankes.",
    
    2,"Kruuolq verschwindet in der Daemonendimension."});
    

    

// Ein paar Details muessen ja sein, sonst ist es oede
    
  AddDetail( ({"licht"}), BS(
    "Nur noch wenig Licht kann dem Gestein wiederstehen und verbreitet etwas "
    "Helligkeit."));
  AddDetail( ({"helligkeit"}), BS(
    "Es ist nur sehr wenig hell. Du hast Muehe alles genau auszumachen."));
  AddDetail( ({"muehe"}), BS(
    "Naja Muehe scheinst Du die ja beim Untersuchen zu geben."));  
    
  AddDetail( ({"decke"}), BS(
    "Die Decke befindet sich ueber dir. Als Du genauer hinschaust kannst Du einen "
    "Schriftzug entdecken."));
  AddDetail( ({"schrift", "schriftzug", "zug"}), BS(
    "Er wurde mit Blut an die Decke geschrieben."));
  AddDetail( ({"blut"}), BS(
    "Es ist ohne Zweifel Blut eines Daemonen."));
  AddDetail( ({"daemon"}), BS(
    "Es muss ein grosser Daemon gewesen sein. Das Blut sieht recht zaehfluessig aus. "
    "Erstaunlich, dass man das nach so langer Zeit noch erkennen kann."));
  AddDetail( ({"groesse"}), BS(
    "Du nimmst mal einfach so ca. 20002 cm an. Das koennte ungefaehr hinkommen. "));
  AddReadDetail( ({"schriftzug", "schrift"}), BS(
    "Meister der Krieger des Chaos."));
  AddDetail( ({"krieger"}), BS(
    "Du bist doch auch einer."));
  AddDetail( ({"chaos"}), 
    "Hier ist es nicht gerade chaotisch.\n");  
  AddDetail( ({"kammer"}), #'kammer);
  AddDetail( ({"waende"}), BS(
    "Die Waende bestehen aus jenem schwarzem Gestein, dass Licht verschluckt. "
    "Selbst Zardoz der Dunkle benutzte es um seine Burg zu errichten."));
  AddDetail( ({"zardoz", "dunkle"}), BS(
    "Ploetzliche Dunkelheit umgibt dich."));
  AddDetail( ({"dunkelheit"}), BS(
    "Und schon ist sie wieder weg."));
  AddDetail( ({"gestein"}), BS(
    "Nein, hier wird das Gestein nicht beschrieben, da gibt es bessere Orte "
    "wo man x-verschiedenen Beschreibungen nachlesen kann."));
  AddDetail( ({"orte"}), BS(
    "Geh doch mal in die Daemonenburg Du Feigling."));
  AddDetail( ({"feigling"}), BS(
    "Ja Du bist gemeint."));
  AddDetail( ({"burg", "daemonenburg"}), #'burg);
  AddDetail( ({"beschreibung", "beschreibungen"}),  BS(
    "Daran progge ich mir gerade die Finger wund."));    
  AddDetail( ({"finger"}), BS(
    "Argh...Du bekommst gleich eins auf die Finger."));
  AddDetail( ({"boden"}), BS(
    "Der Boden besteht aus dem selben schwarzen Gestein wie die Waende. Einige "
    "Vertiefungen und Rillen kannst Du ausmachen."));
  AddDetail( ({"vertiefung", "vertiefungen", "rillen"}), BS(
    "Die Rillen fuehren in wirren Linien ueber den Boden. Du kannst keinen Sinn darin "
    "erkennen, spuerst aber, als Du den Boden beruehst, ein leichtes vibrieren."));
  AddDetail( ({"linien"}), BS(
    "Sie gehen kreuz und quer ueber den Boden. Bei genauerer Betrachtung ergeben sie "
    "ein Muster das unglaublich kompliziert ist."));
  AddDetail( ({"betrachtung"}), BS(
    "Ja, jetzt siehst Du das Muster ganz deutlich."));
  AddDetail( ({"muster"}), BS(
    "Es sieht unwahrscheinlich kompliziert aus. Du kannst es mit deinem kleinen "
    "Gehirn nicht fassen."));
  AddSpecialDetail( ({"gehirn"}), "sd_gehirn");
  AddDetail( ({"vibration"}), BS(
    "Du kniest dich nieder um der Ursache auf die Spur zu kommen. Als Du durch "
    "den ganzen Raum gerobbt bist, siehst Du auf einmal ein Portal aus vielen "
    "kleinen dunklen Lichtstreifen nah an der Wand flimmern."));
  AddDetail( ({"ursache"}), BS(
    "Tja wenn Du die mal wuesstest."));
  AddDetail( ({"spur"}), BS(
    "Hier findest Du keine Spuren."));
  AddDetail( ({"raum"}), BS(
    "Mittlerweile solltest Du dir hier schon ne Menge angesehen haben."));
  AddDetail( ({"menge"}), BS(
    "Naja wenn Du dir jedes dumme Detail anschaust, wirst Du nie fertig."));
  AddDetail( ({"detail"}), BS(
    "Nein, hierfuer gab es keinen FP."));
  AddDetail( ({"fp"}), BS(
    "Lass mal kurz ueberlegen..das ist ein Detail in 5ter Stufe...komm ich noch tiefer?"));
  AddDetail( ({"stufe"}), BS(
    "Jetzt haben wir es aber Du bist ein Script!"));
  AddSpecialDetail( ({"script"}), "sd_script");
  AddDetail( ({"portal"}), BS(
    "Das Portal besteht aus kleinen duennen, dunklen Lichtstreifen. Man sieht es nur "
    "wenn man sich auf den Boden kniet und nach rechtsoben schaut."));
  AddDetail( ({"lichtstreifen"}), BS(
    "Also irgendwas kann hier nicht mit rechten Dingen zugehen! Dunkle Lichtstreifen! "
    "Wo gibt es denn sowas. Schon merkwuerdig."));
  AddDetail( ({"dinge", "dingen"}), BS(
    "Seltsame Dinge scheinen hier moeglich zu sein."));
  AddDetail( ({"gestein"}), BS(
    "Dieses Gestein ist vor Urzeiten durch die Konzentration dunkler Energien "
    "auf einer anderen Welt entstanden."));
  AddDetail( ({"urzeiten", "urzeit", "uhrzeit", "zeit"}), #'zeit);
  AddDetail( ({"konzentration"}), BS(
    "Du solltest dich mehr konzentrieren, so wird das nichts."));
  AddDetail( ({"energie", "energien"}), BS(
    "Diese unheimlichen Energien moechtest Du nicht kennenlernen."));
  AddDetail( ({"welt"}), #'welt);  

  AddSpecialDetail( ({"schrank"}), "sd_schrank");
  AddDetail( ({"holz"}), BS(
    "Ganz normales Holz aus Baeumen vom Grimmswald."));
  AddDetail( ({"wald", "grimmswald"}), BS(
    "Der Grimmswald hat doch gar keine Baeume? Oder wie war das?"));
  AddDetail( ({"baum", "baeume"}), BS(
    "Also einen Baum wirst Du wohl kennen. Das ist so ein Ding, sieht braun "
    "aus und hat gruene Blaetter. Meist fallen sie lautlos um. Zumindest im "
    "Verlorenen Land."));

// -> Toeters Insel 

  AddDetail( ({"land", "verlorenes land"}), BS(
    "Jaja, das verlorene Land. Man muss es betreten um nach Akhar Nth'tar zu kommen."));  
  AddDetail( ({"insel", "akhar nth'tar"}), BS(
    "Akhar Nth'tar ist eine Insel. Aber nicht nur eine Insel. Nein ein ganzer Kontinent. "
    "Legenden und Raetsel ranken sich um dieses geheimnisvolles Stueck Land."));
  AddDetail( ({"raetsel"}), BS(
    "Von hier aus kannst Du keine Raetsel erkennen."));
  AddDetail( ({"legenden"}), BS(
    "Du hast schon viel gehoert von den Legenden von Akhar Nth'tar aber nichts genaues. Es "
    "lohnt sich bestimmt dort mal vorbeizuschauen."));
  AddDetail( ({"genaues"}), BS( 
    "Du weisst nichst genaues."));
  AddDetail( ({"kontinent"}), BS(
    "Es wurde erst ein kleiner Teil von Akhar Nth'tar erforscht, aber bald taeglich dringen "
    "neue Geruechte ueber Geheimnisse und Monster zu dir."));
  AddDetail( ({"geheimnisse"}), BS(
    "Geheimnisse kann man nicht so einfach untersuchen."));
  AddDetail( ({"geruechte"}), BS(
    "Eins der letzten Geruechte war der Tod des Todschatten oder auch die Entdeckung des "
    "Weges zum Hutzelgnomkoenig."));
  AddDetail( ({"hoehle"}), BS(
    "Also die Hoehle ist nnicht hier, sondern auf Akhar Nth'tar. Geh doch einfach mal hin."));
  AddDetail( ({"entdeckung"}), BS(
    "Ja sowas passiert ab und zu."));
  AddSpecialDetail( ({"koenig", "hutzelgnom", "hutzelgnomkoenig"}), "sd_koenig");
  AddDetail( ({"tod"}), BS(
    "Du hast den Tod schon selbst kennengelernt. Du weisst also wie er aussieht."));
  AddDetail( ({"todschatten"}), BS(
    "Weisst Du was der Todschatten ist? Nein? Es ist eins der furchterregendsten Monster ueber"
    "haupt. Du solltest sehr mutig sein um ihn zu besiegen."));
  
    
// END -> Toeters Insel     
    
  AddDetail( ({"blaetter"}), BS(
    "Blaetter, Blaetter....ein Baum hat welche."));
  AddDetail( ({"ding"}), BS(
    "Ein Ding ist ein Ding ist ein Ding."));
  AddDetail( ({"ecke"}), BS(
    "Es ist eine ganz normale Ecke. In hier steht ein kleiner Holzschrank."));
  
  AddSpecialDetail( ({"stuhl"}), "sd_stuhl");  
  AddDetail( ({"lehne", "armlehne", "armlehnen"}), BS(
    "Eine normale Holzarmlehne mit kleinen Eisendornen dran."));
  AddDetail( ({"eisendornen", "dornen", "eisen"}), BS(
    "Die machen einen sehr spitzen Eindruck."));
  AddDetail( ({"eindruck"}), BS(
    "Dein Eindruck taeuscht dich nicht. Sehr spitz und auch mit etwas Gift versehen."));
  AddSpecialDetail( ({"gift"}), "sd_gift");
  AddDetail( ({"mitte"}), BS(
    "In der Mitte des Raumes steht ein Stuhl. Ob man da sich wohl setzen kann?"));
  AddDetail( ({"untersuchen"}), BS(
    "Aeh?"));
  
  
  AddCmd(({"betrete", "betritt"}), "cm_betrete");
  AddCmd(({"beschwoere"}), "cm_beschwoere");
  AddCmd(({"beruehre"}), "cm_beruehre");
  AddCmd(({"oeffne"}), "cm_oeffne");
  AddCmd(({"schliesse"}), "cm_schliesse");
  AddCmd(({"sitz", "setze"}), "cm_sitz");

  AddCmd( ({"typo"}), "cm_typo");
  AddCmd( ({"idee"}), "cm_idee");
  AddCmd( ({"fehler", "bug"}), "cm_bug");
  AddCmd( ({"nimm"}), "cm_nimm");
  schrank = 0;
  ring = 1;
  stuhl = "\njemand";
  titel = "der Trottel";
  rufer = ({});  
  AddExit("westen",CHAOS_GILDEN_ROOM("cerz1"));

}

void init() {
 
  ::init();
   if (this_player()->QueryProp(P_DAEMON_KILLED))
     this_player()->move("zentrale der meister", M_GO, "raus", "fliegt ", "kommt aus Anakin's Beschwoerungsraum geflogen.");
  add_action("nix", "", 1);
}

int nix() {

  if (this_player()->QueryProp(P_NO_COM)) {
    if( find_call_out( "go") == -1) return 0;  
    write("Dein Koerper gehorcht dir nicht!\n"); 
    return 1;
  }
  return 0;
}
  

// SpecialDetails

void gift2() {
  write("Puuh zum Glueck war es wohl doch kein Gift!\n");
}  


string sd_gift() {
   call_out("gift2", 2+random(2));
   return "Aua, jetzt hast Du dich gestochen!\n";
}

string sd_stuhl() {
  string bla;
   
   bla = "Ein normaler Stuhl mit Armlehnen. ";
   if (stuhl!="\njemand") bla = bla + stuhl+" sitzt drauf.";
   bla = bla +"\n";
   return bla;

}


string sd_koenig() {
  string rasse;
  switch (this_player()->QueryProp(P_RACE)) {
    case "Zwerg"  : rasse = "Zwerge"; break;
    case "Mensch" : rasse = "Menschen";break;
    case "Elf"    : rasse = "Elfen"; break;
    case "Hobbit" : rasse = "Hobbite"; break;
    default : rasse = "Dummkoepfe"; break;
  }
  
  return "Er sitzt in seiner Hoehle und wartet darauf kleine "+rasse+" zu fressen.\n";
}

// Das koennte evt. nerven....

string sd_script() {
  if (member(rufer, NAME)==-1) {
     rufer+=({ NAME });
     shout("Merlin ruft: "+capitalize(getuid(this_player()))+" benutzt ein Untersuchescript.\n");
     return "Merlin ruft: Ein Scripter!\nSo das hast Du jetzt davon.\n";
  }
  return "Du weisst doch, dass Du ein Script bist.\n";
}

string sd_schrank() {
  string bla;
  string blubb;
  bla = "geschlossener";
  blubb = "\n";
  if ((ring) && (schrank)) blubb = "Ein Ring liegt drin.\n";
  
  if (schrank) bla = "offener";
  return "Ein einfacher "+bla+" Schrank aus Holz. "+blubb;
}

string sd_gehirn() {
  
  say(capitalize(getuid(this_player()))+" fasst sich erstaunt an seinen Kopf.\n");
  return "Ja wo ist es denn hin?\n";
}


string welt() {
  this_player()->command_me("wer efferdland");
  return "Ist diese Welt gemeint?\n";
}

string burg() {
  write("Was Du kennst die Daemonenburg nicht?\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cerz1"), M_GO, "raus", "fliegt ob Unwissenheit ", "kommt aus Anakin's Beschwoerungsraum geflogen.");
  return "";  
}

string kammer() {
  this_player()->command_me("schau");
  return "";
}

string zeit() {
  this_player()->command_me("zeit");
  return "";
}


go(int i) {
  
  
  string *f;
  
  if (i<sizeof(sequenz)) 
   
  switch (sequenz[i+1]) {
  
     case "TEILEMIT:)" : {
              // Hat er Freunde? :)
              // Hat er so nicht mehr. - Bierchen -
              //if (present("\n\bfband", this_player())) {
              //f = this_player()->QueryProp(P_FRIENDS);
              f=this_player()->QueryProp(P_WAITFOR);
              if(sizeof(f))
              {
                write(capitalize(f[random(sizeof(f))])+
                " teilt Dir mit: Mist, wo war denn das?\n");
              }
              call_out("go", sequenz[i], i+2);
              break;
            }
      case "TOD" : {
              write("[Tod:Lars] "+NAME+" ist gerade vom Stuhl gefallen.\n[Tod:Ein Stuhl] Quatsch, der pennt doch nur....:)\n");
              call_out("go", sequenz[i], i+2);
              break;
            }
      default: { write("\n"+sequenz[i+1]+"\n");
                 call_out("go", sequenz[i], i+2);
               }
  }
  else { 
    this_player()->SetProp(P_NO_COM, 0);
    this_player()->SetProp(P_DEAF, 0);
    this_player()->SetProp(P_TITLE, titel);
    write("Du stehst etwas verwirrt auf.\n");
    say(NAME+" steht etwas verwirrt auf.\n");
    stuhl = "\njemand";
  }   
}

// Idee, Bug etc. -> eine Ausgabe, aber trotzdem ins rep-file

int cm_idee(string str) {

   write("Du Wurm hast noch Ideen? Glaub ich kaum.\n");
   return 0;
}

int cm_typo(string str) {
  
   write("Hier ein Schreibfehler? NIEMALS!\n");
   return 0;
}

int cm_fehler(string str) {

   write("Hier gibt es keine Fehler!\n");
   return 0;
}

//
int cm_nimm(string str) {
   object ob;
   notify_fail("Was willst Du woraus nehmen?\n");
   if (!str) return 0;
   if (str=="ring aus schrank") {
      if (ring) {
         if (getuid(this_player())=="anakin") {
             say(NAME+" nimmt den Ring des ersten Meister des Chaos aus dem Schrank.\n"); 
             write("Du nimmst den Ring.\n");
             ob = clone_object( CHAOS_GILDEN_OBJ("c11ring"));
             ob->SetProp( P_SHORT, "Der Chaos-Ring des ersten Meisters Anakin" );
             ob->move( this_player(), M_NOCHECK );
             return 1;
         }
         write("Du bist nicht maechtig genug den Ring zu nehmen. Mach erst mal\nnoch nen paar EP. Jaja richtig, EP!\n");    
         say("Auch "+NAME+" ist nicht maechtig genug den Ring zu nehmen.\n");
         return 1;
      }
      notify_fail("Es ist doch gar kein Ring da.\n");
      return 0;
   }   
   return 0;          
}
 

int cm_sitz(string str) {

   notify_fail("Worauf willst Du dich setzen?\n");
   if (!str) return 0;
   if (str=="auf stuhl") {
       notify_fail(stuhl+" sitzt doch schon auf dem Stuhl!\n");
       if (stuhl=="\njemand") {
           stuhl = NAME;
           write("Du setzt Dich auf den Stuhl.\n");
           say(NAME+" setzt sich auf den Stuhl.\n");
           titel=this_player()->QueryProp(P_TITLE);
           this_player()->SetProp(P_TITLE, "sitzt bewusstlos auf dem Stuhl");
           this_player()->SetProp(P_NO_COM, 1);
           this_player()->SetProp(P_DEAF, 1);
           call_out("go", 1, 0);   
           return 1;
       }
       return 0;      
   }
   return 0;
}


int cm_oeffne(string str) {
   
   notify_fail("Was willst Du oeffnen?\n");
   if (!str) return 0;
   if (str=="schrank") {
      if (schrank) {
         write("Der Schrank ist doch schon offen.\n");
         return 1;
      }
      write("Du oeffnest den Schrank.\n");
      say(NAME+" oeffnet den Schrank.\n");
      schrank = 1;
      return 1;
   }
}

int cm_schliesse(string str) {

   notify_fail("Was willst Du schliessen?\n");
   if (!str) return 0;
   if (str=="schrank") {
     if (!schrank) {
         write("Der Schrank ist doch schon geschlossen.\n");
         return 1;
     }
     write("Du schliesst den Schrank.\n");
     say(NAME+" schliesst den Schrank.\n");
     schrank = 0;
     return 1;
   }
}   




int cm_beruehre(string str) {
   
   notify_fail("Was willst Du beruehren?\n");
   if (!str) return 0;
   if (str=="boden") {
      write("Der Boden vibriert tatsaechlich.\n");
      say(capitalize(getuid(this_player()))+" kniet nieder und beruehrt den Boden.");
      return 1;
   }
   return 0;
}


int cm_beschwoere(string str) {

  object daemon;
  
  notify_fail("Wen willst Du beschwoeren?\n");
  if (!str) return 0;
  if (str=="anakin") {
/*       
     if (!present("\nanakindaemon", this_object())) {

        daemon = clone_object("daemon");
        daemon->move(this_object(), M_TPORT);
        return 1;
     }      
     write("Der Daemon ist doch schon da.\n");  
     return 1;
*/
    write("Du versuchst vergeblich Anakin zu beschwoeren. Du hoerst\nein leichtes Donnern.\n");
    say(NAME+" kniet nieder. Du hoerst ein leichtes Donnern.\n");     
    return 1;
  }
  return 0;
}



int cm_betrete(string str) {
  notify_fail("Was willst Du betreten?\n");
  if (!str) return 0;
  if (str=="portal") {
     notify_fail("Nur Anakin darf dieses Portal benutzen.\n");    
     if (getuid(this_player())!="anakin") return 0;
     this_player()->move("/d/seher/haeuser/anakinraum0", M_TPORT);
     return 1;
  }
  return 0;
}


int clean_up(int refcount) { return 1; }
