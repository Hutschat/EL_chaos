#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Im Treppenaufgang eines unheiligen Turms." );
  SetProp( P_INT_LONG, BS("Du stehst nun im Erdgeschoss des Turms. "
                          "Die unheimliche Ruhe und Stille die hier "+
                          "vorherrscht erzeugt ein Gefuehl der "+
                          "Ehrfurcht in Dir und laesst Dich erschaudern. "+
                          "In diesem Turm scheint einfach alles aus "+
                          "schwarzem Stein zu bestehen. An den Waenden "+
                          "haengen einige umgedrehte, schwarze Kreuze. "+
                          "Eine breite Wendeltreppe fuehrt nach oben.",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Der komplette Boden besteht, ebenso wie die Decke und die "+
          "Waende, aus schwarzem, glatten Stein.",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke sowie die Waende und der Boden besteht aus "+
          "schwarzem, glatten Stein. Eine breite Wendeltreppe fuehrt "+
          "durch die Decke hindurch in den darueberliegenden Raum.",78));
  AddDetail( ({ "stein", "gestein"}), BS(
          "Hier besteht einfach alles aus diesem schwarzen, glatten "
          "Gestein.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Die Waende bestehen aus dem selben schwarzen Stein wie die "+
          "Decke und der Boden. Jedoch wurden hier an einigen Stellen "+
          "umgedrehte Kreuze aufgehaengt.",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "stellen" }), BS(
          "Es sind genau 5 Stellen, da es auch 5 Kreuze sind.",78));
  AddDetail( ({ "kreuze" }), BS(
          "An den Waenden befinden sich 5 umgedrehte Kreuze. Du kannst "+
          "Sie dir einzeln betrachten.",78));
  AddDetail( ({ "kreuz 1" }), BS(
          "Das erste Kreuz ist natuerlich ebenso wie die anderen in "+
          "schwarz gehalten. Jedoch befindet sich noch ein roter Rubin "+
          "daran, und darunter steht in silberner Schrift: 'Krozk'",78));
  AddDetail( ({ "schrift" }), BS(
          "Die Schrift auf den Kreuzen ist silbern.",78));
  AddDetail( ({ "rubin" }), BS(
          "Der Rubin ist blutrot und wunderschoen.",78));
  AddDetail( ({ "kreuz 2" }), BS(
          "Auf dem zweiten Kreuz erkennt man einen Saphir und das Wort: "+
          "'trxu'",78));
  AddDetail( ({ "saphir" }), BS(
          "Der Saphir ist Daemonenblau und erzeugt ein Kribbeln in Dir.",78));
  AddDetail( ({ "kreuz 3" }), BS(
          "Ein kleiner, runder Amethyst ist in das dritte Kreuz "+
          "eingearbeitet, direkt ueber dem Wort: 'uenkl'",78));
  AddDetail( ({ "amethyst" }), BS(
          "Gruen wie die Hoffnungslosigkeit.",78));
  AddDetail( ({ "hoffnungslosigkeit" }), BS(
          "Hier kannst Du alle Hoffnung fahren lassen.",78));
  AddDetail( ({ "kribbeln" }), BS(
          "Das kann man nicht anschauen.",78));
  AddDetail( ({ "kreuz 4" }), BS(
          "Der kleine, rechteckige Diamant auf diesem Kreuz wurde direkt "+
          "unter dem Wort: 'weslmge' angebracht.",78));
  AddDetail( ({ "diamant" }), BS(
          "Der Diamant, das Symbol der Leidenschaft des Toetens.",78));
  AddDetail( ({ "kreuz 5" }), BS(
          "Ein grosser, runder, schwarzer Stein unbekannten Materials "+
          "befindet sich auf dem fuenften Kreuz. Darunter erkennst Du "+
          "Du das Wort: 'strunz'. Was diese Woerter auf den ganzen "+
          "Kreuzen wohl zu bedeuten haben? Vielleicht solltest Du sie "+
          "einmal uebersetzen...",78));
  AddDetail( ({ "material" }), BS(
          "Unbekannt.",78));
  AddDetail( ({ "leidenschaft" }), BS(
          "Die Leidenschaft des Toetens ist die schoenste Leidenschaft!",78));
  AddDetail( ({ "lumkroz", "nurns", "ambu", "bruchk", "rtt", "Manor" }), BS(
          "Diese Woerter koennten dem Daemonischen entspringen...",78));
  AddDetail( ({ "turm" }), BS(
          "Ein unheiliger Turm.",78));
  AddDetail( ({ "ruhe", "stille" }), BS(
          "Ruhe und Stille kann man nicht sehen, hoechstens hoeren.",78));
  AddDetail( ({ "gefuehl" }), BS(
          "Ehrfurcht.",78));
  AddDetail( ({ "wendeltreppe", "treppe" }), BS(
          "Die Wendeltreppe ist breit, schwarz und fuehrt hier nur "+
          "nach oben.",78));




  AddSounds( SENSE_DEFAULT,
                BS("Die unheimliche Stille erzeugt eine geradezu "+
                   "unheilige Atmosphaere.",78));
        


  AddSmells( SENSE_DEFAULT, BS(
                "Nichts. Absolut nichts zu riechen.",78));


  AddCmd( ({ "lasse", "lass" }), "hoffnung" );
  AddExit("oben", CHAOS_GILDEN_ROOM("cl2tu4_2"));
  NewDoor("osten",CHAOS_GILDEN_ROOM("cl2bu1"),({"tuer"}),
    ({D_NAME,"Tuer",
      D_GENDER,2,
      D_SHORT,"Im Osten befindet sich eine grosse, massive, %se Tuer.",
      D_LONG,BS("Diese Tuer ist ja wirklich extrem massiv. Wooow, ist "+
                "die aus Stein? Irgendwie glaubst Du das nicht so ganz.") 
  }));
  
  


}

hoffnung( str )
{
  notify_fail( "Was willst du denn genau tun?\n" );
  if(!str) return 0;
  
  if(member(({"hoffnung fahren", "alle hoffnung fahren"}),str)!=-1)
  {
      write(BS("Das war doch nur bildlich gesprochen!!!",78) );
      return 1; 
   }
   return 0; 
}