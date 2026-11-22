// certz1.c
//
// Letzte Aenderung:
//
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit "/std/room";

#define P_LL_TIME "_p_last_lausch_time_"
#define LAUSCHER "\nlauscher"

protected void create()
{
 ::create();
 SetProp(P_INT_SHORT,"Die Einsatzzentrale der Meister des Chaos");
 SetProp(P_INT_LONG,
 "Dies ist die Einsatzzentrale der Meister des Chaos. Man "
 "sieht sofort, dass hier Chaoten am Werke sind. Auf mehreren Schreibtischen "
 "liegen riesige Haufen von Notizen, Zetteln, seltsamen Listen, "
 "Einsatzplaenen und Karten herum. Selbst der Boden ist davon "
 "groesstenteils bedeckt, und nur kleine Trampelpfade, die zu den "
 "Ausgaengen des Raumes fuehren, sind einigermassen freigeraeumt. An der "
 "Wand haengt eine grosse Bekanntmachung und die Erzmeisterliste. "
 "Im Westen befindet sich eine geschlossene Tuer in der Wand, nach "
 "Norden und Osten jedoch fuehren Durchgaenge aus diesem Raum heraus.");
 
 SetProp(P_LIGHT,1);
 SetProp(P_INDOORS,1);

 AddDetail("erzmeisterliste",
 "Du kannst Die Erzmeisterliste lesen.");

 AddReadDetail("erzmeisterliste","@@erz_liste@@");

 AddDetail("bekanntmachung",
 "Du kannst die Bekanntmachung lesen.");
 
 AddReadDetail("bekanntmachung","@@bekanntmachung@@");

 AddDetail(({"raum"}),
 "Dies ist die Einsatzzentrale der Meister des Chaos. Sie ist auf "
 "chaotischste Weise mit den merkwuerdigsten Dingen angefuellt, so "
 "dass der Raum selbst kaum noch zu sehen ist. Dennoch siehst Du noch "
 "genug, um zu erkennen, dass dieser Raum etwas besonderes ist. So "
 "bestehen weder der Boden noch die Waende aus den ultraschwarzen "
 "Felsbloecken, welche diese Burg ueberall verzieren. Im Gegenteil "
 "ist das Gestein, welches den Boden bildet, zwar schwarz, aber nicht "
 "so schwarz, wie man es in dieser Burg gewohnt ist. Ausserdem leuchtet "
 "die Decke in einem warmen Licht, damit man all die Zettel und Plaene "
 "gut studieren kann, welche hier herumliegen. Etwas derartiges hast "
 "Du hier noch nicht gesehen.");
 
 AddDetail(({"dinge"}),
  "Hier liegen die verschiedensten Dinge herum. Viele von ihnen sind "+
  "ueberhaupt nicht mehr benutzbar, doch einige sind sicherlich "+
  "aeusserst nuetzlich.");

 AddDetail(({"felsbloecke"}),
 "Die schwarze Burg wurde groesstenteils aus gewaltigen, schwarzen "
 "Felsbloecken gebaut, welche das Licht zu absorbieren scheinen. "+
 "Hier hat man jedoch anderes Gestein benutzt, welches sicherlich "
 "aus der alten Gilde uebernommen wurde. Man hat sich sehr viel " 
 "Muehe gegeben, diesen Raum so aufzubauen, wie er frueher aussah.");
 
 AddDetail(({"licht","finsternis","dunkelheit"}),break_string(
  "Warmes Licht "+
  "strahlt von der Decke herab, falls nicht gerade jemand Dunkelheit "+
  "uebt. Doch welcher Meister des Chaos hat so etwas schon noch "+
  "noetig.",78));
 AddDetail(({"burg"}),break_string(
  "Du befindest Dich in der schwarzen Burg, "+
  "der Burg des Chaos. Du bist ein Meister des Chaos, deshalb sollte "+
  "Dir dies eigentlich klar sein.",78));
 AddDetail(({"chaosgilde"}),break_string(
  "Die Chaosgilde ist die Gilde des Chaos.",78));
 AddDetail(({"ausgaenge","ausgang"}),break_string(
  "Es gibt zwei Durchgaenge, einen  nach Norden und einen nach Osten. "+
  "Nach Westen fuehrt eine Tuer, welche aber anscheinend geschlossen "+
  "ist.",78));
 AddDetail(({"durchgang","durchgaenge"}),break_string(
  "Die Durchgaenge fuehren nach Norden und Osten. Es sind einfache, "+
  "mannshohe Loecher in den Waenden, an denen nichts wirklich interessant "+
  "ist.",78));
 AddDetail(({"loecher"}),break_string(
  "Oh verdammt! Da sind Loecher in der Wand!",78));
 AddDetail(({"wand","waende"}),break_string(
  "Die Waende sind kahl und leer. Um so mehr faellt auf, dass sie zwar "+
  "aus schwarzem Gestein bestehen, dieses jedoch um Laengen heller ist "+
  "als die ueblichen Felsbloecke dieser Gilde. An den Waenden haengen "+
  "lediglich eine Bekanntmachung und eine Erzmeisterliste.",78));
 AddDetail(({"tuer"}),break_string(
  "Die Tuer ist wirklich merkwuerdig. Sie besitzt keine Griffe, "+
  "Schluesselloecher oder andere Eigenheiten. Ausserdem erkennst "+
  "Du keine Scharniere. Vielleicht ist dies ja eine Schiebetuer, "+
  "aber wie soll man sie oeffnen? Wie bist Du ueberhaupt hier "+
  "reingekommen?",78));
 AddDetail(({"griffe","schluesselloecher"}),break_string(
  "So etwas scheint die Tuer nicht zu besitzen. Wie merkwuerdig. Nun, "+
  "vielleicht ist dies ja garkeine Tuer. Aber was ist es dann?",78));
 AddDetail(({"eigenheiten"}),break_string(
  "Jede Tuer hat so ihre Eigenheiten.",78));
 AddDetail(({"schiebetuer"}),break_string(
  "Selbst wenn man annimmt, dass dies eine Schiebetuer ist, kann man "+
  "sie nicht schieben. Wie oeffnet man sie nur? Du bist ratlos.",78));
 AddDetail(({"schreibtisch","schreibtische","tische","tisch"}),
  break_string("Die Schreibtische sind voellig ueberladen und kaum noch "
   "unter den Bergen von Listen und Zetteln zu finden. Ein Tisch besitzt "
   "eine auffaellige Schublade.",78));
 AddDetail("schublade", 
  break_string("Die Schublade ist verschlossen. Aber irgendwo im "
   "MorgenGrauen muss es doch einen Schluessel dafuer geben.",78));
 AddDetail("decke",
  break_string("Die Decke ist ueber Dir und schimmert in einem warmen Licht, "
   "dass den Raum erhellt, wenn hier nicht mal wieder jemand den "
   "'Dunkelheits-Zauber' uebt, was ja die Meister eigentlich nicht mehr "
   "noetig haben sollten. Du bist ueberrascht ueber das viele Licht hier "+
   "im Raum. So kann man all die Plaene und Zettel sehr schoen lesen.",78));
 AddSpecialDetail(({"dunkelheitszauber","zauber","dunkelheits-zauber"}),
  "dunkelheit" );
 AddReadDetail(({"notizen","notiz"}),
  "Die Notizen sind alle ziemlich schwachsinnig.\n");
 AddDetail(({"karten","karte"}),
  break_string("Die Karten zeigen das gesammte MorgenGrauen. Jeder Raum, "
   "jedes noch so geheime Versteck ist hier verzeichnet.",78));
 AddDetail(({"versteck"}),break_string(
  "Najaaa, vielleicht nicht JEDES Versteck. Du weisst schon.",78));
 AddDetail("morgengrauen", 
  "Dir graut es vor morgen.\n");
 AddDetail("werk",
  "Das Werk von den wilden Kriegern des Chaos ist leicht zu erkennen.\n");
 AddDetail(({"berge","berg","haufen"}),
  break_string("Du durchwuehlst einen grossen Haufen und entdeckst ganz "
   "unvermutet einen seltsamen Spiegel.",78));
 AddDetail("spiegel",
  break_string("Der Spiegel ist schon sehr mehrwuerdig, denn er ist voellig "
   "truebe. Du kannst Dich darin nicht sehen. Dafuer kann man aber damit "
   "einen kleinen Spionage-Daemon beschwoeren, der andere Spieler "
   "beobachtet. Dies geht mit 'beobachte <spieler>'. Die Beobachtung "
   "beendet man mit 'aufhoeren'. Der Daemon kann auch sprechen. Du kannst "
   "ihm mit 'csag <text>' Worte in den Mund legen. Ausserdem kann er sich "
   "mit 'cschau' umschauen.",78));
 AddDetail(({"schluessel"}),break_string(
   "Hier ist er nicht. Wo ist er nur?",78));
 AddDetail(({"scharnier","scharniere"}),break_string(
   "Merkwuerdig. Diese Tuer hat ueberhaupt keine Scharniere!",78));
 AddDetail(({"gildenmitglieder","mitglieder","gildenmitglied","mitglied"}),
  "Sowas solls ja geben. Scheint aber nur ein Geruecht zu sein.\n");
 AddDetail(({"chaoten","chaos","chaot"}),
  "Sowas solls ja geben, hab ich gehoert...\n");
 AddDetail(({"einsatzzentrale","zentrale"}),
  break_string("Ja genau. Dies ist die Einsatzzentrale der Meister des "
   "Chaos. Welche Einsaetze sie hier vorbereiten ist allerdings voellig "
   "unklar.",78));
 AddDetail(({"einsatz","einsaetze"}),
  "Dies ist ein Satz.\n");
 AddDetail("boden",
  break_string("Der Boden koennte aus schwarzem Gestein bestehen. Leider "
   "kann man ihn kaum sehen, denn ueberall liegen Berge von Zetteln, "
   "Notizen, Zetteln, Karten und nochmals Zettel.",78));
 AddDetail("zettel",
  break_string("Wie schon erwaehnt, so findet man hier zahllose Zettel. Du "
   "stoeberst etwas herum, doch findest nichts interessantes darunter. Nur "
   "auf einem Zettel steht etwas recht undeutlich geschrieben.",78));
 AddReadDetail("zettel",
  "Als Meister des Chaos kann man hier cfingern...\n" );
 AddDetail(({"plaene","plan","einsatzplan","einsatzplaene"}),
  break_string("Ein Einsatzplan faellt Dir im Durcheinander besonders auf. "
   "Du solltest ihn vielleicht mal lesen.",78));
 AddReadDetail(({"plan","plaene","einsatzplan","einsatzplaene"}),"@@plan@@");
 AddDetail("gestein",
  break_string("Das Gestein ist zwar schwarz, aber leider nicht so schwarz, "
   "wie Du es von anderen schwarzen Gesteinsarten gewoehnt bist, und im "+
   "Gegensatz zu den Felsbloecken dieser Burg geradezu weiss. Anscheinend "+
   "wurden diese Steine aus der alten Chaosgilde hierher geschafft.",78));
 AddDetail(({"arten","gesteinsart","gesteinsarten"}),
  "Schwarz ist nicht gleich schwarz. Und das gilt auch fuer Gestein.\n");
 AddDetail(({"pfad","pfade","trampelpfade","trampelpfad"}),
  break_string("Immerhin hat hier jemand ein paar Zettel aus dem Weg "
   "geraeumt, damit man nicht staendig ueber sie hinweglaeuft.",78));
 AddDetail(({"liste","listen"}),
  break_string("Die Listen sind teilweise gar nicht mehr zu lesen, da "
   "ueberall Kaffeeflecken drauf sind. Nur eine Liste ist sowohl leserlich, "
   "als auch interessant genug um Deine Aufmerksamkeit zu erregen.",78));
 AddDetail(({"kaffee","kaffeeflecken"}),break_string(
  "Diese dummen Kaffeeflecken machen die ganzen Listen unlesbar. Sowas dummes.",78));
 AddDetail("aufmerksamkeit",
  break_string("Du bist sehr aufmerksam. Sonst haettest Du Dir dieses Detail "
   "nicht angeschaut!",78));
 AddDetail(({"notizen","notiz"}), 
  break_string("Unter den vielen sinnlosen Notizen findest Du einen "
   "seltsamen Bericht von einem Dir bislang unbekanntem Mitglied der "
   "Gilde.",78));
 AddDetail("bericht",
  break_string("Der Bericht ist recht unleserlich geschrieben. Er scheint "
   "in grosser Eile abgefasst worden zu sein.",78));
 AddReadDetail("bericht","@@bericht@@");
 AddDetail(({"details","detail"}),
  break_string("Hier gibt es leider nicht sehr viele Details. Wenn Du mehr "
   "Details sehen willst, dann gehe bitte nach Orkhausen.",78));
 AddDetail("orkhausen",
  break_string("Nein, nach Orkhausen wird man sicherlich nie von der Gilde "
   "aus teleportieren koennen!!!!",78));
 AddDetail("gilde",
  break_string("Du befindest Dich in der Gilde. Das sollte Dir als Meister "
   "des Chaos eigentlich klar sein!",78));
 AddReadDetail(({"liste"}),"@@gilden_liste@@");
 AddCmd(({"beobachte","beobacht"}),"belausche_mitglied");
 AddCmd(({"aufhoeren","aufhoere","aufhoer"}),"exit");
 
 AddExit("osten",CHAOS_GILDEN_ROOM("anakinraum"));
 AddExit("norden",C_112_ROOM("cl3_cerz3"));
 AddCmd(({"westen"}),"ex_westen");
 
 AddCmd(({"cfinger","chaosfinger"}),"cfinger" );
 AddCmd("oeffne","schublade");
 AddCmd(({"csag","csage"}),"csag");
 AddCmd(({"cschau","cschaue"}),"cschau");
 
 AddCmd(({"schiebe","ziehe","schieb","zieh","drueck","druecke"}),"move_door");
 AddCmd(({"tritt","trete"}),"jump_door");
 
}                        

int jump_door(string was) {
  if (was != "tuer" && was != "tuer ein") return 0;
  write("Du trittst mit voller Kraft gegen die Tuer.\n");
  say(this_player()->Name(WER)+" tritt mit voller Kraft gegen die Tuer.\n",this_player());
  tell_room(this_object(),"Die Tuer zeigt sich gaenzlich unbeeindruckt.\n");
  return 1;
}

int move_door(string was) {
  if (was != "tuer")
    return notify_fail("So geht das nicht...\n"),0;
  write("Die Tuer bewegt sich keinen Millimeter.\n");
  return 1;
}

int ex_westen(string was) {
  tell_room(C_112_ROOM("cl3bu4"),"Die Tuer oeffnet sich.\n");
  tell_room(this_object(),"Die Tuer oeffnet sich.\n"); 
  this_player()->move(C_112_ROOM("cl3bu4"),M_GO,"nach Westen");
  tell_room(C_112_ROOM("cl3bu4"),"Die Tuer schliesst sich.\n");                 
  tell_room(this_object(),"Die Tuer schliesst sich.\n"); 
  return 1;
}


string erz_liste(){
  this_player()->More(read_file(CHAOS_GILDEN_LOG("erzmeister")));
 return "";
}

int schublade(string str){
  string schluessel;
  object ob;
  if(!str) return 0;
  if(str=="tuer") {
    write("Das geht nicht.\n");
    return 1;
  }
  if(str=="schublade"){
    write("Die Schublade ist verschlossen.\n");
   return 1;
  }
  if(!sscanf(str,"schublade mit %s",schluessel)) return 0;
  if(!ob=present(schluessel,this_player())){
    write("Sowas hast Du nicht!\n");
   return 1;
  }
  if(ob->id("\cerz_schluessel")){
    write("Du oeffnest mit "+ob->name(WEM)+" die Schublade.\n");
    say(capitalize(this_player()->name())+" oeffnet die Schublade.\n");
    if(present("chaos-ring",this_player())|| 
      this_player()->QueryProp(P_GUILD_LEVEL)<11){
      write("Leider ist die Schublade leer.\n");
      say("\n");
     return 1;
    }
    write("Leider zerbricht dabei der schoene Schluessel.\n");
    ob->remove();
    write(break_string("Du findest einen seltsamen Ring, den Du sofort "
     "nimmst! Danach schliesst Du die Schublade wieder und hoerst das "
     "Schloss einrasten.",78));
    say(capitalize(this_player()->QueryPronoun())+" nimmt etwas heraus.\n");
    clone_object(CHAOS_GILDEN_OBJ("c11ring"))->move(this_player(),M_NOCHECK);
   return 1;
  }
  if(ob->id("zt")){
     write(break_string("Als Du versuchst die Schublade mit dem Zaubertrank "
      "zu oeffnen, zerbricht der Verschluss! Das Flaeschchen ist nun "
      "offen!",78));
     say(capitalize(this_player()->name())+" oeffnet einen Zaubertrank an "
      +"der Schublade.\n");
     ob->remove();
     clone_object(CHAOS_GILDEN_OBJ("zt"))->move(this_player());
    return 1;
   }
  write(break_string("Du versuchst mit "+ob->name(WEM)+" die Schublade zu "
   "oeffnen, doch leider passt "+ob->name()+" nicht.",78));
  say(capitalize(getuid(this_player()))+" versucht mit "
   +ob->name(WEM)+" die Schublade zu oeffnen.\n");
 return 1;
}

string gilden_liste(){
  object *pl;
  string s;
  int i;
  pl=users();
  s = "Folgende Mitglieder der Gilde des Chaos kannst Du finden:\n"+
      "---------------------------------------------------------\n";
  for(i=sizeof(pl)-1;i>=0;i--)
  {
    if(IS_LEARNER(pl[i])) continue;
    if(pl[i]->QueryProp(P_TESTPLAYER)) continue;
    if(pl[i]->QueryProp(P_GUILD)!="chaos") continue;
    s += sprintf( "%-13s (Stufe: %-2d): %s.\n", capitalize(getuid(pl[i])),
      pl[i]->QueryProp(P_GUILD_LEVEL), 
      environment(pl[i])->QueryProp(P_INT_SHORT));
  }
 return s;
}
     
string dunkelheit(){
  if(this_player()->QueryProp(P_GUILD)=="chaos" &&
     this_player()->QueryProp(P_GUILD_LEVEL)>=11){     
     if(this_player()->QueryProp(P_GENDER)==1)
        this_player()->SetProp(P_TITLE,"der Schwarzmagier des Chaos");
        else this_player()->SetProp(P_TITLE,"die Schwarzmagierin des Chaos");
   }
  return break_string("Was? Du kennst den Dunkelheits-Zauber nicht????? "
   "Deine Stufe wird gerade wieder herabgesetzt. Du bist jetzt "
   +this_player()->name()+" "+this_player()->QueryProp( P_TITLE)+".",78);
}

string bericht(){
  string s;
  object etwas;
  s = "Bericht von Xrukuu, dem Kaempfer des Chaos:\n";
  etwas = find_living( "etwas");
  if( !etwas || !environment( etwas))
    s += "Lange suchte ich die ganze Ebene vergebens ab, ich durchsuchte den\n"
      "Grimmswald, ich lief die Akademiestrasse rauf und runter und\n"
      +"wagte mich sogar in die alte Ruine, doch ich fand Etwas nicht.\n"+
      "So muss ich leider vermelden, dass Etwas tot ist!\n"+
      "Gezeichnet:   Xrukuu.\n";
  else 
    s = "Ich suchte lange vergebens die ganze Ebene ab, doch dann entdeckte\n"
      "ich es: Das namenlose Etwas konnte ausfindig gemacht werden! Hier meine\n"+
      "Beschreiung der Stelle, wo ich es zuletzt sah:\n\n"+
      environment(etwas)->QueryProp(P_INT_LONG)+
      "\nIch hoffe, ich konnte mit diesem Hinweis helfen, denn ich musste\n"
      +"grosse Muehen auf mich nehmen.\n"+
      "Gezeichnet:   Xrukuu.\n";
 return s;
}

    
string plan(){
  string s;
  s="Hmm. Hier stehen wirklich seltsame Sachen:\n\n";
  if(find_living("hydra"))
    s+="Die Hydra wuetet gerade im Lupinental! Es ist Vorsicht geboten!\n";
    else s+="Die Hydra nervt mal nicht das Lupinental.\n";
  if(find_living("weghier"))
    s+="Der Weghier wartet auf dumme Seher.\n";
    else s+="Der Weghier ist selber weg hier.\n";
  if(find_living("schlammdrache"))
    s+="Der Schlammdrache hat einen Ring zu verschenken.\n";
    else s+="Wer hat dem Schlammdrachen den Ring abgenommen?\n";
  if(find_object("/d/vland/patryn/npc/orkseebaer"))
    s+="Ein Seebaer saeuft noch immer wie ein Loch.\n";
    else s+="Ein Seebaer sieht die See nie wieder.\n";
  if(find_living("daemonendrache"))
    s+="Der Daemonendrache nervt mal wieder in der Daemonenburg.\n";
    else s+="Nur ein Drachenpanzer ist vom Daemonendrachen uebrig geblieben.\n";
  if(find_living("wurzelzwerg"))
    s+="Der Wurzelzwerg wurzelt zwergisch.\n";
    else s+="Wer hat den Wurzelzwerg verwurzelt?\n";
  if(find_living("schamane"))
    s+="Der Schamane trollt sich irgendwo in der SSP.\n";
    else s+="Der Wassertroll-Schamane toetet erstmal nicht mehr arme Spieler.\n";
  if(find_living("leronis"))
    s+="Eine Leronis steht dumm in der Gegend rum.\n";
    else s+= "Einer Leronis hat auch ihr rotes Haar nichts genuetzt.\n";
  if(find_living("bruder_des_schwertmeisters"))
    s+="Der Bruder des Schwertmeisters putzt sein Schwert.\n";
    else s+="Der Bruder des Schwertmeisters hat ausgekaempft.\n";
  if(find_living("wasserunwesen"))
    s+="Das Wasserunwesen treibt sein Unwesen im Wasser.\n";
    else s+="Das Wasserunwesen ist jetzt ein Un-Wesen.\n";
  if(find_object("/d/polar/troy/q2p/npc/lofwyr"))
    s+="Lofwyr der Dunkle verbreitet die Dunkelheit.\n";
    else s+="Der Dunkle Lofwyr weicht dem Tag.\n";
  if(find_living("lilith"))
    s+="Lilith kratzt sich ihre Warze.\n";
    else s+="Lilith kratzt sich vorerst nicht die Warzen.\n";  
 return s;
}


int belausche_mitglied( string str){
  object pl,lau;
  string s;
  notify_fail("Wen willst Du beobachten?\n");
  if(!str) return 0;
  if(!pl=find_player(str)) return 0;
  if(this_player()->QueryProp(P_GUILD)!="chaos"|| 
     this_player()->QueryProp(P_GUILD_LEVEL)<11){
     write("Du darfst niemanden beobachten!\n");
    return 1;
   } 

//Nach Absprache auskommentiern:
 
  if(IS_LEARNER(pl)||pl->QueryProp(P_TESTPLAYER)){
     write("Magier und Testspieler kannst Du nicht beobachten!\n");
    return 1;
   }
  if(pl==this_player()){
     write("Du kannst Dich nicht selber beobachten!\n");
    return 1;
   }
  if(present("\nchaos_lauscher",environment(pl))){
     write(pl->name()+" wird schon beobachtet!\n");
    return 1;
   }
  if(this_player()->QueryProp("lausch")){
     write("Du beobachtest schon jemanden!\n");
    return 1;
   }
  if(this_player()->QueryProp(P_SP)<60){
     write("Du hast nicht mehr genug Magiepunkte!\n");
    return 1;
   }
  if(time() <=(pl->QueryProp(P_LL_TIME)+1800)){
     write(pl->name()+" wurde vor kurzem schon beobachtet.\n");
    return 1;
   }
  pl->SetProp(P_LL_TIME,time());    
  this_player()->SetProp(P_SP,this_player()->QueryProp(P_SP)-60);
  write (break_string("Du beobachtest nun "+pl->name(WEN)+". Dies hoert auf, "
   "sobald Du den Raum verlaesst oder 'aufhoeren' eingibst.",78));
  lau=clone_object(CHAOS_GILDEN_MON("csn"));
  lau->SetProp(LAUSCHER,getuid(this_player()));
  lau->SetProp("opfer",getuid(pl));
  this_player()->SetProp("lausch",getuid(pl));
  lau->SetProp(P_SHORT,"Der Spionage-Daemon von "
    +capitalize(getuid(this_player())));
  lau->SetProp(P_NAME,capitalize(this_player()->name(WESSEN))+
    " Spionage-Daemon");
  this_player()->SetProp("\nlausch_daem",lau);
  lau->move(environment(pl),M_GO);
  if (pl->QueryProp(P_GUILD) == "chaos")
  s=break_string(capitalize(getuid(this_player()))+
    (this_player()->QueryProp(P_GENDER)==1?", Dein Meister der Chaos-Gilde ":
    ", Deine Meisterin der Chaos-Gilde ")+"moechte Deine Handlungen beobachten. "+
    "Dies ist kein Snoop, es ist nur so, als ob "+capitalize(getuid(this_player()))+
    " im selben Raum waere.",78);
  else
  s=break_string(capitalize(getuid(this_player()))+
    (this_player()->QueryProp(P_GENDER)==1?", ein Meister der Chaos-Gilde ":
    ", eine Meisterin der Chaos-Gilde ")+"moechte Deine Handlungen beobachten. "+
    "Dies ist kein Snoop, es ist nur so, als ob "+capitalize(getuid(this_player()))+
    " im selben Raum waere.",78);
  
  s+=break_string("WENN DU DIES NICHT WILLST, DANN KANNST DU JEDERZEIT MIT 'aufhoeren'\n"+
     "DIE VERBINDUNG UNTERBRECHEN:",78);
  tell_object(pl,s);
  pl->AddPursuer(lau);
 return 1;
}

int exit(){
  object pl,lau;
  string s;
  if (!this_player() || !(s=this_player()->QueryProp("lausch")))
    return 0;
  if(pl=find_player(s)){
     tell_object(pl,capitalize(getuid(this_player()))+" lauscht nicht mehr.\n");
   }
   
  if((lau=this_player()->QueryProp("\nlausch_daem")) && objectp(lau))
     lau->remove();
  this_player()->SetProp("lausch",0);
  this_player()->SetProp("\nlausch_daem",0);
  write("Du beobachtest nun nicht mehr.\n");
 return 1;
}


csag(string str){
  object lau;
  notify_fail("Was soll Dein Spionage-Daemon sagen?\n");
  if(!str) return;
  if(!objectp(lau=this_player()->QueryProp("\nlausch_daem"))){
     write("Du beobachtest niemanden.\n");
    return 1;
   } 
  str=this_player()->_unparsed_args();
  lau->command_me("sag "+str);
  write(break_string(str,78,"Dein Spionage-Daemon sagt: "));
 return 1;
}

cschau(){
  object lau;
  if(!lau=this_player()->QueryProp("\nlausch_daem")){
     write("Du beobachtest niemanden.\n");
    return 1;
   }
  if(!objectp(lau)){
     write("Du beobachtest niemanden.\n");
    return 1;
   } 
  write(environment(lau)->int_long(this_player(),lau));
 return 1;
}

int cfinger(string str){
  object pl,daem;
  string s,dname;
  notify_fail("Kein solcher Spieler.\n");
  if(!pl=find_player(str)) return 0;
  if(this_player()->QueryProp(P_GUILD)!="chaos"){
     write("Du kannst diesen Befehl nicht verwenden.\n");
    return 1;
   }
  if(pl->QueryProp(P_GUILD)!="chaos"){
     write("Du kannst nur Gilden-Mitglieder fingern.\n");
    return 1;
   }
  if(IS_LEARNER(pl)||pl->QueryProp(P_TESTPLAYER)){
     write("Ne ne!\n");
    return 1;
   }
  daem=present("\nchaos_gilden_daemon",environment(pl));
  if(daem && daem->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(pl)){
    dname=daem->name();
   }
  else dname="Keiner";
  s="Gilden Informationen ueber "+capitalize(getuid(pl))+":\n"
    + sprintf( "%-11s %-20s (Stufe: %-2d)  Daemon: %-8s\n",
      capitalize(getuid(pl)), pl->QueryProp(P_GUILD_TITLE), 
      pl->QueryProp( P_GUILD_LEVEL), dname );
  daem=present("\nchaos_ruestung",pl);
  if(daem){
    if(daem->QueryProp(DAEM_FALSE)) dname="Wuetend";
    else dname="Friedlich";
    if(daem->QueryProp(RUEST_SCHUTZ)) dname+="/Schutz";
   }
  else dname="Keine";
  s+= sprintf( "Chaosruestung: %-16s  Idle: %s\n",
    dname, (query_idle(pl)<60?"nein":time2string( "%m %M", query_idle(pl))));
  s+= sprintf( "Lebenspunkte: [%-3d]  Magiepunkte: [%-3d]  Vorsicht: [%-3d]\n",
    pl->QueryProp( P_HP), pl->QueryProp( P_SP ), pl->QueryProp( P_WIMPY));
  s+= "Aufenthaltsort: "+environment(pl)->QueryProp( P_INT_SHORT)+".\n";
  write(s);
 return 1;
}

string bekanntmachung(){
  this_player()->More(read_file("/gilden/files.chaos/texte/erz.txt"));
 return "";
}
