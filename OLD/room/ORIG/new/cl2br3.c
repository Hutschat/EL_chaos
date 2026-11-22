#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

inherit "/std/room";

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"In einem Unterstand");
  SetProp(P_INT_LONG,BS("Du stehst in einem kleinem Unterstand. Seine "+
  "Waende bestehen aus dem schwarzen Holz, welches man hier ueberall "+
  "in dieser Hoehle findet. Fenster gibt es keine. Du stehst im Schnee"+
  "matsch und frierst Dich hier zu Tode. Durch den Eingang kannst Du "+
  "die Bruecke beobachten. Nun, dass war dann wohl auch der Sinn dieser "+
  "Huette."));
  AddDetail(({"huette","unterstand","bretterverschlag"}),"Du stehst drinn.\n");
  AddDetail(({"waende","wand"}),BS("Die Waende hier bestehen aus steinhar"+
  "ten, pechschwarzen Brettern, welche Dir irgendwie unheimlich sind. "+
  "Naja, wenigstens halten sie den Regen ab."));
  AddDetail(({"bretter","holz"}),BS("Dieses merkwuerdige schwarze Holz "+
  "hast Du schon ueberall in dieser Hoehle gesehen."));
  AddDetail(({"hoehle"}),BS("Sie ist dort draussen...."));
  AddDetail(({"fenster"}),BS("Hier siehst Du keine Fenster."));
  AddDetail(({"tod","tode"}),BS("Jemand sagt: BALD. BALD."));
  AddDetail(({"jemand"}),BS("Jemand sagt: UPS. DEINE ZEIT "+
              "IST NOCH NICHT REIF. ICH KOMME SPAETER WIEDER."));
  AddDetail(({"regen"}),BS("Er trommelt leicht auf das Dach des Unterstandes."));
  AddDetail(({"decke","dach"}),BS("Das Dach dieses Unterstands besteht "+
  "aus dem gleichen schwarzen, steinharten Holz wie die Waende und scheint "+
  "lediglich notduerftig mit Teer abgedichtet worden zu sein."));
  AddDetail(({"teer"}),BS("Du kannst in in den Ritzen zwischen den "+
  "Dachbrettern erkennen. Das wurde nicht allzu fachmaennisch angebracht, "+
  "aber es haelt."));
  AddDetail(({"dachbretter"}),BS("Die Bretter des Daches wurden mit Teer "+
  "abgedichtet."));
  AddDetail(({"eisberg"}),BS("Wow, Du befindest Dich in einem Unterstand "+
  "innerhalb eines Eisbergs! Wahnsinn! Huiiiiii!"));
  AddDetail(({"wahnsinn"}),BS("Jemand sagt: BALD. BALD."));
  AddDetail(({"zeit"}),BS("Jemand sagt: HUCH. SO SPAET? ICH MUSS GEHEN.\nJemand winkt."));
  AddDetail(({"boden"}),BS("Du stehst in Schneematsch und auf weissem "+
  "Eis. Es ist ziemlich kalt in diesem Unterstand."));
  AddDetail(({"kaelte"}),BS("Kaelte sieht man nicht. Man fuehlt sie."));
  AddDetail(({"eis","weisses eis"}),BS("Dies hier ist ein Eisberg. Kein "+
  "Wunder, dass der Boden aus Eis besteht!"));
  AddDetail(({"sinn"}),BS("Der Sinn dieses Unterstandes liegt darin, "+
  "die Bruecke zu beobachten und waehrenddessen nicht im Regen stehen zu "+
  "muessen."));
  AddDetail(({"eingang"}),BS("Naja, dieser Unterstand hat nur 3 Waende. "+
  "Die fehlende Wand symbolisiert somit den Eingang."));
  AddDetail(({"schneematsch"}),BS("Die Lage Schneematsch ist duenn und "+
  "pampig und glatt und zu nichts zu gebrauchen."));
  AddDetail(({"nichts"}),BS("Nein nein :)"));
  AddSpecialDetail(({"bruecke","haengebruecke"}),"det_bruecke");
  
     
  AddSmells(SENSE_DEFAULT,BS("Es stinkt hier nach Saeure!"));
  AddSounds(SENSE_DEFAULT,BS("Der Regen trommelt auf die Decke."));
  AddSounds(({"regen"}),BS("*Trommel Trommel*"));
  AddSmells(({"saeure"}),BS("BAEEEEH! Stinkt das!"));
  
  AddCmd(({"wink","winke"}),"wink");
  AddCmd(({"fuehl","fuehle"}),"fuehle");
  AddSpecialExit("nordwesten","nw");
  
}

int nw()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
  {
     write("Aber es ist keine Bruecke da! Du wuerdest sterben! Nein Nein Nein, so nicht!\n");
     return 1;
  }
  this_player()->move(CHAOS_GILDEN_ROOM("cl2br1"),M_GO,"auf die Bruecke");
  return 1;
}

int wink(string was) {
  if (was != "jemand" && was != "jemand zu") return 0;
  write("Du winkst Jemandem zu.\nJemand laechelt dankbar und verschwindet.\n");
  return 1;
}

int fuehle(string was) {
  notify_fail("Was willst Du fuehlen?\n");
  if (was != "kaelte") return 0;
  write("*Bibber*.\n");
  return 1;
}


string det_bruecke()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
  return BS("Mein GOTT! Dort ist garkeine Bruecke! Nur der Saeuresee! "+
  "Du kommst aus dieser Huette nie wieder raus! WAAAAAAAAAAAAH!");
  return "Du siehst folgendes:\n"+
         call_other(CHAOS_GILDEN_ROOM("cl2br1"),"int_long",this_player(),
                    this_player());
}