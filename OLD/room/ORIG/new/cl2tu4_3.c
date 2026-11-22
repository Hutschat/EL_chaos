#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Im Dachgeschoss eines unheiligen Turms." );
  SetProp( P_INT_LONG, BS("Du stehst in einem bizarr wirkenden Raum. "+
                          "Die Waende, Decke und der Boden sind mit "+
                          "Pentagrammen, Runen und unheiligen Symbolen "+
                          "vollgemalt. Grosse schwere, schwarze Vorhaenge "+
                          "sind rundherum aufgehaengt worden. In der Mitte "+
                          "des Raumes steht ein grosser, pechschwarzer "+
                          "Altar, auf dem etwas eingraviert ist.",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Der schwarze Stein, aus dem der Boden besteht wird hier fast "+
          "vollstaendig durch ein riesiges silbernes Pentagramm bedeckt.",78));
  AddDetail( ({ "decke" }), BS(
          "An der Decke siehst du ausser einer grossen Daemonenfratze "+
          "nichts besonderes.",78));
  AddDetail( ({ "stein", "gestein"}), BS(
          "Schwarz und ueberall mit vollgemalt.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Viele Pentagramme und Symbole zieren die schwarzen Waende. "+
          "Ausserdem erkennst Du noch viele kleine Schalen, die dem "+
          "Geruch nach zu urteilen, mit Schwefelwasser gefuellt sind.",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "wendeltreppe", "treppe" }), BS(
          "Die Wendeltreppe ist breit, schwarz und fuehrt hier nur "+
          "nach unten.",78));
  AddDetail( ({ "farbe" }), BS(
          "Schwarz wie die Nacht.",78));
  AddDetail( ({ "nacht" }), BS(
          "Die Nacht ist gegensaetzlich zum Tag.",78));
  AddDetail( ({ "tag" }), BS(
          "Der Tag ist gegensaetzlich zur Nacht.",78));
  AddDetail( ({ "atmosphaere" }), BS(
          "Man koennte sie als daemonisch und unheilig bezeichnen.",78));
  AddDetail( ({ "turm" }), BS(
          "Ein unheiliger Turm. Du befindest dich in ihm.",78));
  AddDetail( ({ "pentagramme", "pentagramm" }), BS(
          "Viele Pentagramme zieren diesen Raum, aber auf dem Boden ist "+
          "das groesse, es ist silbern.",78));
  AddDetail( ({ "daemonenfratze", "fratze" }), BS(
          "An der Decke ist eine grosse Daemonenfratze aufgemalt. Sie "+
          "scheint Dich anzustarren und irgendwelche Worte zu sagen...",78));
  AddDetail( ({ "worte" }), BS(
          "Das kannst Du nicht sehen, Du koenntest hoechstens versuchen "+
          "der Fratze zu lauschen.",78));
  AddDetail( ({ "symbole", "runen" }), BS(
          "Jede Menge unheiliger Symbole und Runen bedecken die Waende. Du "+
          "kannst sie jedoch nicht lesen.",78));
  AddDetail( ({ "vorhaenge" }), BS(
          "Die schweren, schwarzen Vorhaenge sollen wohl die unheimliche "+
          "Atmosphaere dieses Raums unterstuetzen (verstaerken).",78));
  AddDetail( ({ "mitte" }), BS(
          "In der Mitte des Raums steht ein grosser schwarzer Altar.",78));
  AddDetail( ({ "altar" }), BS(
          "Gross, schwarz und unheimlich. So wuerdest Du diesen Altar "+
          "beschreiben. Wozu er wohl gut ist ? Opferungen ? Unheimliche "+
          "Rituale ? Nun, Du kannst versuchen die Runen auf ihm zu lesen, "+
          "vielleicht findest Du dann eine Erklaerung... Auffaellig ist "+
          "auch noch die kleine Matte direkt vor dem Altar, die deiner "+
          "Aufmerksamkeit bisher entgangen ist.",78));
  AddDetail( ({ "matte" }), BS(
          "Sieht schon ziemlich abgenutzt aus. Als ob da schon viele "+
          "drauf gelegen oder gestanden haben.",78));
  AddDetail( ({ "opferungen", "rituale" }), BS(
          "Vielleicht bekommst Du es heraus, wenn du versuchst die Runen "+
          "zu lesen.",78));

  AddReadDetail( ({ "runen", "satz" }), BS(
        "Es scheint ein ganzer Satz zu sein: "+
        "'Lumkroz qualasar, ambu Bruchk rtt Zzrusta moerksl trookasr "+
        "Ronam iamti erdasu'",78));





  AddSounds( SENSE_DEFAULT,
                BS("Die Stille ist hier auf dem Hoehepunkt angelangt "+
                   "Selbst eine fallende Stecknadel wuerde hier bei dir "+
                   "einen Herzinfarkt ausloesen...",78));
  AddSounds( ({ "fratze", "daemonenfratze" }), "Die Daemonenfratze scheint "+
                "zu sagen: 'cutralk Bruchasut rtt Onrurlas' Was immer das "+
                "zu bedeuten hat...");
        


  AddSmells( SENSE_DEFAULT, BS(
                "Die Luft ist durchsetzt vom Geruch von Schwefel.",78));

  AddSmells( ({ "schwefel", "schwefelgeruch" }), BS(
                   "Der Schwefelgeruch kommt wohl von den vielen "+
                   "mit Schwefelwasser gefuellten Schalen an den "+
                   "Waenden.",78));

  AddCmd( ({ "betritt", "betrete" }), "pent" );
  
  AddExit("unten",CHAOS_GILDEN_ROOM("cl2tu4_2"));
  
}

int pent( string str )
{
  notify_fail( "Was willst Du denn betreten?\n" );
  if(!str) return 0;
  
  if(str != "pentagramm")
  {
      write(BS("Du betrittst das silberne Pentagramm...",78) );
      say(this_player()->Name(WER)+" ist ploetzlich verschwunden.\n");
      
      return 1; 
   }
   return 0; 
}

/*
!!Beim Betreten des Pentagramms soll man irgendwo anders rauskommen, am
  besten random irgendwo in der gilde :))

!!Die Syntax um zu "beten" soll sein "beschwoere schwarzen daemon"
es sollte aber auch gehen: "beschwoere daemon" und auf daemonisch
sollte es auch gehen, wie steht ja auf dem schild...
*/