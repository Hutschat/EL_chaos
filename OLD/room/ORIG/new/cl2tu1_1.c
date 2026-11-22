#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


int luke;


create() {
  ::create();
  luke = 0;
  SetProp( P_INT_SHORT, "Ganz oben in einem zerstoertem Turm." );
  SetProp( P_INT_LONG, BS("Zerstoerung. Das ist wohl das erste was man "+
                          "denkt, wenn man diesen Raum sieht. Auf dem "+
                          "Boden liegen ueberall schwarze Gesteinstruemmer "+
                          "herum, die vermutlich alle von der eingebroch"+
                          "enen Decke stammen. Da ist naemlich nur ein "+
                          "ziemlich grosses Loch. Die Waende bestehen aus "+
                          "grossen schwarzen Steinbloecken, und sind ueber"+
                          "saet mit Kratzspuren, koennte von den Flug"+
                          "daemonen sein, die hier offensichtlich ihr "+
                          "Zuhause haben. Was einem auch sofort ins Auge "+
                          "sticht, ist das Flugdaemonennest an der Sued"+
                          "wand.@@fdaemon@@",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Ueberall liegen Gesteinstruemmer herum, manche gross, manche "+
          "klein, aber alle schwarz. Sie scheinen von der Decke zu "+
          "stammen, von der ist naemlich nichts mehr uebrig. Das Loch da "+
          "oben ist sogar gross genug fuer einen grossen Flugdaemon "+
          "Vor der Westwand ist noch eine Luke zu sehen. Sie hebt "+
          "sich von den normalen, schwarzen Steinbloecken deutlich "+
          "ab",78));
  AddSpecialDetail( ({ "luke" }),"det_luke");
  AddDetail( ({ "holz" }), BS(
          "Dunkles, grobes Holz, auf dem eine dicke Staubschicht liegt, "+
          "die Luke ist wohl lange nicht mehr geoeffnet worden.",78));
  AddDetail( ({ "staub", "staubschicht" }), BS(
          "Die Luke koennte man ruhig mal wieder abstauben.",78));
  AddDetail( ({ "muehe" }), BS(
          "Na wenn dir das schon zuviel ist, dann warte am besten auf den "+
          "naechsten Flugdaemon, und geh wieder!",78));
  AddDetail( ({ "decke", "turmdecke" }), BS(
          "Welche Decke? Du kannst wohl nicht lesen, hier gibt es keine "+
          "Decke mehr, Du siehst ueber dir in weiter Ferne nur die "+
          "Hoehlendecke",78));
  AddDetail( ({ "hoehlendecke" }), BS(
          "Die ist zu weit weg, genaueres erkennst Du von hier aus nicht. "+
          "Ab und zu sieht man allerdings einen dunklen Schatten vorueber"+
          "ziehen.",78));
  AddDetail( ({ "schatten" }), BS(
          "Das werden wohl Flugdaemonen sein, die da oben ihre Kreise "+
          "ziehen.",78));
  AddDetail( ({ "kreise", "kreis" }), BS(
          "So sieht ein Kreis aus: o Ist zwar nur ein kleiner, aber "+
          "immerhin :)",78));
  AddDetail( ({ "ferne" }), BS(
          "Weite Ferne!",78));
  AddDetail( ({ "truemmer", "gesteinstruemmer" }), BS(
          "Davon hat es hier wirklich massenhaft, scheinbar mehr als es "+
          "eigentlich an der Decke gegeben haben koennte... Eventuell "+
          "kannst Du sie ja einmal durchsuchen.",78));
  AddDetail( ({ "loch" }), BS(
          "Das Loch wo sich normalerweise die Decke des Turms befinden "+
          "sollte ist gross genug, um Durchlass fuer einen groesseren "+
          "Flugdaemon zu bieten.",78));
  AddDetail( ({ "durchlass" }), BS(
          "Damit ist das Loch an der ehemaligen Turmdecke gemeint.",78));
  AddDetail( ({ "flugdaemon", "flugdaemonen" }), BS(
          "Falls Du hier gerade keinen siehst, hat wieder mal jemand "+
          "das Flugdaemonenbaby getoetet. Derjenige hat aber vermutlich "+
          "seine gerechte Strafe von einem der anderen Flugdaemonen "+
          "bekommen...",78));
  AddDetail( ({ "strafe" }), BS(
          "Den TOD, was sonst?",78));
  AddDetail( ({ "westwand" }), BS(
          "Die Westwand sieht aus, wie die ganzen anderen Waende auch, mit "+
          "dem Unterschied, das davor eine kleine Luke am Boden zu "+
          "erkennen ist.",78));
  AddDetail( ({ "unterschied" }), BS(
          "Der Unterschied zwischen der Westwand und den anderen Waenden "+
          "ist die kleine Luke auf dem Boden davor.",78));
  AddDetail( ({ "ostwand", "nordwand" }), BS(
          "An dieser Wand ist nichts besonderes, nur die typischen Kratz"+
          "spuren, die hier ueberall an den grossen, schwarzen Stein"+
          "bloecken zu sehen sind.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Eigentlich ist das hier ja ein runder Turm. Paradoxerweise hat "+
          "er jedoch trotzdem eine Ost-, West-, Nord-, und Suedwand, die "+
          "Du getrennt untersuchen kannst.",78));
  AddDetail( ({ "paradox" }), BS(
          "In einem runden Turm vier Waende.. Das ist wirklich paradox",78));
  AddDetail( ({ "stein", "steinbloecke" }), BS(
          "Die Steinbloecke, aus denen die Waende und der Boden bestehen, "+
          "und die Decke vermutlich einmal bestanden HAT, sind gross, "+
          "schwarz, und mit unzaehligen Kratzspuren ueberzogen.",78));
  AddDetail( ({ "spuren", "kratzer", "kratzspuren" }), BS(
          "Die Kratzspuren an den Waenden sind sehr unterschiedlich. "+
          "Manche tief und kurz, andere sehr lang, aber nicht besonders "+
          "tief. Eins haben sie aber alle gemeinsam: Sie machen dir Angst. "+
          "Denn das ist klar: Sie stammen sicherlich von den Krallen der "+
          "hier wohnenden Flugdaemonen. Leg dich also besser nicht mit "+
          "ihnen an...",78));
  AddDetail( ({ "angst" }), BS(
          "Du HAST Angst, glaub mir...",78));
  AddDetail( ({ "krallen" }), BS(
          "Schau dir doch einfach einmal die Flugdaemonen an! Aber pass "+
          "auf, das Du nichts falsches machst.",78));
  AddDetail( ({ "zerstoerung" }), BS(
          "Ueberall diese Gesteinstruemmer, die eingestuerzte Decke und "+
          "auch die von Kratzspuren geradezu uebersaeten Waende zeugen "+
          "von einer tiefen Zerstoerung, die vielleicht auf das Wirken "+
          "einer starken, boesen Macht zurueckzufuehren ist. Auch wenn "+
          "die Kratzspuren wohl eher von den Krallen der Flugdaemonen "+
          "sind :)",78));
  AddDetail( ({ "wirken" }), BS(
          "Da hat definitiv eine boese Macht gewirkt, nur welche, fragt "+
          "sich...",78));
  AddDetail( ({ "macht" }), BS(
          "Eine boese und starke Macht? Hm, das kann hier eigentlich nur "+
          "die Chaosgilde gewesen sein, jemand anderes getraut sich "+
          "nicht so starke Kraefte heraufzubeschwoeren.",78));
  AddDetail( ({ "chaosgilde", "gilde" }), BS(
          "Ja, auch dieser Turm gehoert zur Chaosgilde.",78));
  AddDetail( ({ "kraefte" }), BS(
          "BOESE, DUNKLE UND MAECHTIGE KRAEFTE!",78));
  AddDetail( ({ "suedwand" }), BS(
          "An der Suedwand siehst Du ein typisches Flugdaemonenest. Moment "+
          "mal... Was heisst hier ein \"typisches Flugdaemonennest\"? Hat "+
          "man jemals davon gehoert, das ein Flugdaemon Nester fuer seine "+
          "Kinder baut? Nun, hier ist es jedenfalls so, und damit "+
          "Basta!",78));
  AddDetail( ({ "moment" }), BS(
          "Der Moment ist auch schon wieder vorbei.",78));
  AddDetail( ({ "nest", "flugdaemonenest" }), BS(
          "Das Flugdaemonennest an der Suedwand besteht hauptsaechlich "+
          "aus den hier ueberall herumliegenden Gesteinstruemmern, "+
          "ansonsten erkennst Du noch ein bisschen schwarzes Stroh und "+
          "einen Riesenberg mit Diamanten. Alles in allem sieht das sehr "+
          "unbequem aus, aber Daemonen moegen das vermutlich.",78));
  AddDetail( ({ "stroh" }), BS(
          "Schwarzes Stroh. Sowas findet man auch nicht ueberall, aber "+
          "in dieser Hoehle unter dem Schwarzen Eisberg findet man sicher "+
          "einige seltsame Sachen.",78));
  AddDetail( ({ "hoehle" }), BS(
          "In dieser grossen unterirdischen Hoehle befindet sich auch "+
          "die Burg, zu der dieser Turm gehoert.",78));
  AddDetail( ({ "burg" }), BS(
          "Falls Du noch nicht in ihr warst, solltest du das schleunigst "+
          "nachholen!",78));
  AddDetail( ({ "eisberg" }), BS(
          "Er besteht vollkommen aus schwarzem Eis, wie du dich erinnern "+
          "kannst.",78));
  AddDetail( ({ "eis" }), BS(
          "Das Eis des Eisberges ist schwarz.",78));
  AddDetail( ({ "sachen" }), BS(
          "Kuck dich mal um, hat sicher was interessantes dabei...",78));
  AddDetail( ({ "riesenberg", "berg", "diamanten" }), BS(
          "Hoppla, da hat dir deine Phantasie wohl einen Streich gespielt, "+
          "hier ist kein Berg Diamanten, nichtmal ein einziger davon ist "+
          "hier zu sehen.... Naja, wer in so einem Raum so etwas erwartet "+
          "muss auch schoen bloed sein *daemonisch grins*",78));
  AddDetail( ({ "phantasie" }), BS(
          "Die blueht zur Zeit wohl.",78));
  AddDetail( ({ "zeit" }), BS(
          "Siehst Du hier vielleicht irgendwo eine Uhr?",78));
  AddDetail( ({ "uhr" }), BS(
          "Nein, siehst du nicht!",78));
  AddDetail( ({ "streich" }), BS(
          "Boeser Streich, hast Du wohl einem Chaoten zu verdanken :)",78));
  AddDetail( ({ "raum", "turm" }), BS(
          "Das ist DA, wo DU gerade BIST. *patsch auf die Stirn*",78));
  AddDetail( ({ "auge" }), BS(
          "ARGL, Jemand hat dir gerade ins Auge gestochen!",78));
  AddDetail( ({ "jemand" }), BS(
          "Ein Jemand.",78));
  AddDetail(({"beschwoerung"}),BS("Ach was, untersuchen ist hier nicht "+
          "angesagt. Versuchs einfach mit 'beschwoere flugdaemon'.",78));
  




  AddSounds( SENSE_DEFAULT,
                BS("Ab und zu hoerst du das laute Schlagen von "+
                   "Flugdaemonenfluegeln. Ansonsten ist es hier relativ "+
                   "still.",78));
  AddSounds( ({ "schlagen" }), "Die Flugdaemonen kommen hier oefter mal "+
                               "vorbei.");
        


  AddSmells( SENSE_DEFAULT, BS(
                "Von dem Flugdaemonennest geht ein leichter Geruch aus, "+
                "aber Gestank ist das keiner. Ansonsten riecht es nur "+
                "ziemlich alt.",78));
  AddSmells( ({ "nest", "flugdaemonennest", "geruch", "gestank" }), BS(
                "Riecht merkwuerdig, aber stinken tuts nicht :)",78));

  AddSpecialDetail( ({ "klappe" }),"det_klappe");
  AddSpecialDetail( ({ "phiole" }),"det_phiole");
  AddSpecialDetail( ({ "fluessigkeit", "blut" }),"det_blut");


  AddCmd( ({ "durchsuche" }), "truemmer" );
  AddCmd( ({ "staube" }), "staub" );
  AddCmd(({"oeffne"}),"open");
  AddCmd(({"schliesse","schliess"}),"close");
  AddCmd(({"unten"}),"noeeh");
  AddCmd(({"zwaeng","zwaenge"}),"zwaenge");
  AddCmd(({"beschwoer","beschwoere"}),"summon");
  
  
  AddItem(CHAOS_GILDEN_MON("cl2_fbaby"),REFRESH_DESTRUCT);
  AddItem(CHAOS_GILDEN_MON("cl2_fdaemon"),REFRESH_DESTRUCT);
}  


int truemmer( string str )
{
  notify_fail( "Was willst Du denn durchsuchen?\n" );
  if(!str) return 0;
  if( str == "truemmer" || str == "gesteinstruemmer" )
  {
     write( BS("Du durchsuchst Die Gesteinstruemmer, und findest eine "+
            "kleine schwarze Kreide, die Du schnell einsteckst.",78) );
     return 1; 
  }
  return 0; 

}  


int staub( string str )
{
  notify_fail( "Was willst Du denn abstauben?\n" );
  if(!str) return 0;
  if( str == "luke" || str == "luke ab" )
  {
     write( BS("Du staubst die Luke ab, jedoch bildet sich sofort wieder "+
            "neuer Staub darauf. Du denkst . o O (Jedesmal das gleiche)",78) );
     return 1; 
  }
  return 0; 

}


int open(string was) {
  notify_fail("Was moechtest Du denn oeffnen?\n");
  if (was != "luke") return 0;
  if (luke)
  {
    write("Die Luke ist aber schon offen!\n");
    return 1;
  }
  write("Du oeffnest die Luke.\nNun koenntest Du Dich vielleicht durch die Luke zwaengen.\n");
  say(this_player()->Name(WER)+" oeffnet heldenhaft die Luke.\n",this_player());
  luke = 1;
  
  return 1;
}



int close(string was) {
  notify_fail("Was moechtest Du denn schliessen?\n");
  if (was != "luke") return 0;
  if (!luke)
  {
    write("Die Luke ist aber schon geschlossen!\n");
    return 1;
  }
  write("Du schliesst die Luke.\n");
  say(this_player()->Name(WER)+" schliesst die Luke.\n");
  luke = 0;
  
  return 1;
}


int noeeh()
{
  if (!luke)
    write("PFFFFF, die Luke ist zu.\n");
  else
    write("Das ist viel zu eng.\n"+
        "Obwohl, vielleicht koenntest Du Dich durch die Luke zwaengen...\n");
  return 1;
}

int zwaenge(string was) {
  notify_fail("Wodurch moechtest Du Dich zwaengen?\n");
  if (was != "durch luke") return 0;
  if (!luke)
  {
     write ("Leider ist die Luke geschlossen.\n");
     return 1;
  }
  write("Du zwaengst Dich durch die Luke.\nMann ist das eng.\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2tu1_2"),M_GO,"durch die Luke",
                      "zwaengt sich","faellt herein");
  return 1;
}


reset() {
  ::reset();
  if (luke)
    tell_room(this_object(),"Die Luke faellt zu.\n");
  luke = 0;
}


int closeluke()
{
  if (luke)
  {
   tell_object(this_object(),"Die Luke wird von unten geschlossen.\n");
   luke = 0;
   return 1;
  }
  return 0;
}


int getluke()
{
  return luke;
}

int openluke()
{
  if (!luke)
  {
   tell_object(this_object(),"Die Luke wird von unten geoeffnet.\n");
   luke = 1;
   return 1;
  }
  return 0;
}


string det_luke()
{
  if (!luke)
    return BS(
          "Die Luke ist nicht sehr gross, aber mit etwas Muehe koenntest "+
          "Du dich wohl durchzwaengen, jedoch solltest Du sie natuerlich "+
          "zuerst oeffnen. Sie besteht aus dunklem Holz.",78);
  return BS(
          "Die Luke ist nicht sehr gross, aber mit etwas Muehe koenntest "+
          "Du dich wohl durchzwaengen, sie ist dabei sogar schon geoeffnet. "+
          "Sie besteht aus dunklem Holz.",78);
}
  

string fdaemon()
{
  call_other(CHAOS_GILDEN_ROOM("cl2tu2_4"),"???");
  if (present("\nflugdaemon",find_object(CHAOS_GILDEN_ROOM("cl2tu2_4"))))
    return "\nIm obersten Raum eines der anderen Tuerme siehst Du durch ein gewaltiges\n"+
           "Fenster einen grossen Flugdaemon sitzen. Vielleicht koenntest Du ihn durch\n"+
           "eine Beschowerung hierher holen?";
  return "";
}


int summon(string was) 
{
  object ob;
  if (was != "daemon" && was != "flugdaemon")
    return notify_fail("Was moechtest Du beschwoeren?\n"),0;
  if (!find_object(CHAOS_GILDEN_ROOM("cl2tu2_4")))
    return write("Du siehst einen boesen Fehler im RZG.\n"),1;
  if (!(ob = present("\nflugdaemon",find_object(CHAOS_GILDEN_ROOM("cl2tu2_4")))))
    return write("Da ist aber garkein Flugdaemon!\n"),1;  
  if (this_player()->QueryProp(P_ALIGN)>200) {
    write(break_string("Hallooooo! Lieber Flugdaemon! Komm doch rueber, "+
    "ich hab auch ein Leckerchen fuer Dich!",78,"Du rufst: "));
    say(break_string("Hallooooo! Lieber Flugdaemon! Komm doch rueber, "+
       "ich hab auch ein Leckerchen fuer Dich!",78,this_player()->Name(WER)+
       " ruft: "),this_player());
    tell_room(this_object(),"Der Flugdaemon bewegt sich keinen Millimeter.\n");
    return 1;
  }
  write(break_string("Oh boesartiger Daemon! Oh Geschoepf der tiefsten Hoellen, "+
  "oh Diener finsterster Maechte, oh Herr des Himmels, oh gefluegeltes Biest "+
  "der Tiefe! Ich beschwoere Dich, gehorche meinem Befehl. Eile herbei! Eile "+
  "herbei!",78,"Du intonierst: "));
  say(break_string("Oh boesartiger Daemon! Oh Geschoepf der tiefsten Hoellen, "+
  "oh Diener finsterster Maechte, oh Herr des Himmels, oh gefluegeltes Biest "+
  "der Tiefe! Ich beschwoere Dich, gehorche meinem Befehl. Eile herbei! Eile "+
  "herbei!",78,this_player()->Name(WER)+" intoniert: "),this_player());
  tell_room(this_object(),"Der Daemon hebt vom anderen Turm ab.\n");
  ob->move(this_object(),M_GO);
  this_player()->restore_spell_points(-5);
  return 1;
}
  