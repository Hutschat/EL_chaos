#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Im Mittelpunkt des unheiligen Turms." );
  SetProp( P_INT_LONG, BS("Du hast nun die Mitte des Turms erreicht. "+
                          "Auch hier ist saemtliche Einrichtung in "+
                          "schwarzer Farbe gehalten. An den Waenden "+
                          "sind ueberall unheilige Artefakte angebracht. "+
                          "Die Treppe fuehrt weiter nach oben, in den "+
                          "obersten Raum des Turms.",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Der ist auch hier komplett aus schwarzem Stein.",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke sowie die Waende und der Boden besteht aus "+
          "schwarzem, glatten Stein. Die Wendeltreppe fuehrt "+
          "nach oben in das Obergeschoss.",78));
  AddDetail( ({ "stein", "gestein"}), BS(
          "Hier besteht einfach alles aus diesem schwarzen, glatten "
          "Gestein.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Die Waende bestehen aus dem selben schwarzen Stein wie die "+
          "Decke und der Boden. Ueberall siehst Du Artefakte.",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "wendeltreppe", "treppe" }), BS(
          "Die Wendeltreppe ist breit, schwarz und fuehrt hier nach "+
          "oben und unten.",78));
  AddDetail( ({ "einrichtung" }), BS(
          "Die Waende, die Decke, der Boden und die Artefakte ist damit "+
          "gemeint.",78));
  AddDetail( ({ "farbe" }), BS(
          "Schwarz wie die Nacht.",78));
  AddDetail( ({ "nacht" }), BS(
          "Die Nacht ist gegensaetzlich zum Tag.",78));
  AddDetail( ({ "tag" }), BS(
          "Der Tag ist gegensaetzlich zur Nacht.",78));
  AddDetail( ({ "artefakte" }), BS(
          "Umgedrehte Kreuze, Schalen mit Schwefelwasser, Pentagramme, "+
          "Daemonenfratzen sowie Runenaehnliche Symbole.",78));
  AddDetail( ({ "kreuze" }), BS(
          "Die Kreuze in diesem Raum sind nichts besonderes. Sieh Dir "+
          "besser mal die im unteren Raum an.",78));
  AddDetail( ({ "schalen" }), BS(
          "Die schwarzen Schalen sind bis obenhin mit Schwefelwasser "+
          "gefuellt.",78));
  AddDetail( ({ "schwefel", "schwefelwasser" }), BS(
          "Das Schwefelwasser riecht ziemlich stark. Jedoch traegt es "+
          "seinen Teil zur Atmosphaere dieses Turms bei.",78));
  AddDetail( ({ "atmosphaere" }), BS(
          "Man koennte sie als daemonisch und unheilig bezeichnen.",78));
  AddDetail( ({ "turm" }), BS(
          "Ein unheiliger Turm. Du befindest dich in ihm.",78));
  AddDetail( ({ "pentagramme" }), BS(
          "Das uebliche.",78));
  AddDetail( ({ "daemonenfratzen", "fratzen" }), BS(
          "Die sieht man ueberall in den Raeumen der Gilde.",78));
  AddDetail( ({ "raeume", "chaosgilde", "gilde" }), BS(
          "Die anderen Raeume der Gilde musst Du Dir schon selbst "+
          "anschauen.",78));
  AddDetail( ({ "symbole", "runen" }), BS(
          "Sehen wie Runen aus, sind aber anscheinend keine. Du kannst "+
          "Sie jedenfalls nicht lesen.",78));




  AddSounds( SENSE_DEFAULT,
                BS("Die unheimliche Stille erzeugt eine geradezu "+
                   "unheilige Atmosphaere.",78));
        


  AddSmells( SENSE_DEFAULT, BS(
                "Die Luft ist geschwaengert von Schwefelgeruch.",78));

  AddSmells( ({ "schwefel", "schwefelgeruch" }), BS(
                   "Der Schwefelgeruch kommt wohl von den vielen "+
                   "mit Schwefelwasser gefuellten Schalen an den "+
                   "Waenden.",78));

  AddExit("oben",CHAOS_GILDEN_ROOM("cl2tu4_3"));
  AddExit("unten",CHAOS_GILDEN_ROOM("cl2tu4_1"));
  
}