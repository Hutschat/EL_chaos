#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Mitten in einem Turm." );
  SetProp( P_INT_LONG, BS("Du stehst jetzt etwas unterhalb der Mitte "+
                          "von diesem Turm. Im grossen und ganzen sieht "+
                          "er genauso aus wie der Raum unter Dir. Bis "+
                          "auf zwei Kleinigkeiten: Zum einen fuehrt hier "+
                          "keine Leiter weiter hinauf, sondern eine Treppe "+
                          "und zum anderen siehst Du vermehrt Kratzspuren "+
                          "an Wand, Decke und Boden.",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Der komplette Boden besteht, ebenso wie die Decke und die "+
          "Waende, aus schwarze, grossen Steinbloecken. Du erkennst "+
          "einige Kratzspuren an ihm. Weiter hinten ist noch ein Loch "+
          "im Boden, durch das die Leiter hinab fuehrt.",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke sowie die Waende und der Boden besteht aus "+
          "schwarzen, grossen Steinbloecken. Seltsamerweise sind selbst "+
          "an der Decke Kratzspuren zu sehen... Das muessen fliegende "+
          "Wesen sein, die diese Spuren hinterlassen haben!",78));
  AddDetail( ({ "stein", "gestein"}), BS(
          "Hier besteht fast alles aus diesen schwarzen, grossen "
          "Steinbloecken.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Die Waende bestehen aus dem selben schwarzen Stein wie die "+
          "Decke und der Boden. Im hinteren Teil des Raums fuehrt eine "+
          "eiserne Leiter an der Wand nach unten. Ausserdem haengen an "+
          "kleinen Halterungen dutzende kleiner, schwarz leuchtender "+
          "Kugeln, die fuer das matte Licht hier sorgen, und es sind "+
          "auch hier einige Kratzspuren zu erkennen.",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "wesen" }), BS(
          "Hmm, denen wirst Du vermutlich noch begegnen...",78));
  AddDetail( ({ "leiter" }), BS(
          "Eine Leiter, die aus dunklem Eisen zu bestehen scheint, fuehrt "+
          "durch ein Loch an der hinteren Wand nach unten. Sie ist mit "+
          "zahlreichen Kratzern uebersaet.",78));
  AddDetail( ({ "kratzer", "kratzspuren", "spuren" }), BS(
          "Hmm, woher die wohl kommen?",78));
  AddDetail( ({ "halterungen" }), BS(
          "Die Halterungen scheinen ebenso wie die Leiter aus dunklem "+
          "Eisen zu bestehen. An ihnen haengen jeweils mehrere kleine "+
          "dunkle Kugeln.",78));
  AddDetail( ({ "licht" }), BS(
          "Nach den Kugeln nach zu urteilen muss es wohl Schwarzlicht "+
          "sein.",78));
  AddDetail( ({ "kugeln" }), BS(
          "Du betrachtest die Kugeln naeher, eigentlich sind sie einfach "+
          "nur schwarz, jedoch meinst du kurz Gesichter aufblitzen zu "+
          "sehen.",78));
  AddDetail( ({ "gesichter" }), BS(
          "Gesichter! Ja, es sind Gesichter... Aber sie scheinen "+
          "seltsam verzerrt zu sein... Das muessen genau wie unten "+
          "Gesichter von Chaos-Verraetern sein!",78));
  AddDetail( ({ "verraeter", "chaos-verraeter" }), BS(
          "Du erkennst die Gesichter der Verraeter nicht genau genug, sie "+
          "verschwimmen die ganze Zeit.",78));
  AddDetail( ({ "zeit" }), BS(
          "Zeit ist relativ.",78));
  AddDetail( ({ "chaos" }), BS(
          "Das Chaos ist immerdar!",78));
  AddDetail( ({ "loch" }), BS(
          "Ein schmales Loch wuerde dich, dank der Leiter an der Wand "+
          "weiter nach oben lassen, wenn Du es versuchst.",78));
  AddDetail( ({ "treppe" }), BS(
          "Eine steinerne Treppe, schwarz, natuerlich. Auf ihr erkennst "+
          "Du mehr Kratzspuren als an den Waenden, der Decke oder dem "+
          "Boden... Sie fuehrt weiter nach oben.",78));
  AddDetail( ({ "kleinigkeiten" }), BS(
          "Die Treppe und die Kratzspuren sind damit gemeint.",78));
  AddDetail(({"mitte"}),BS("Du befindest Dich nicht oben im Turm und nicht "+
  "unten im Turm. Nein, Du befindest Dich mitten drinn, sozusagen. Ob das "+
  "gut ist, kannst Du nicht so recht sagen...",78));
  AddDetail(({"schwarzlicht"}),BS("Wow, wenn das noch rythmisch flackern "+
  "wuerde, koennte man hier bestimmt angesagtere Parties feiern als in "+
  "stillgelegten U-Bahn Schaechten.",78));
  AddDetail(({"parties"}),BS("Die angesagtesten Parties feiert man immernoch "+
  "in stillgelegten U-Bahn Schaechten.",78));
  AddDetail(({"schacht","schaechte","u-bahn","u-bahn schaechte"}),
  BS("Vergiss es, sowas gibt es hier nicht :-).",78));
  AddDetail(({"steinbloecke"}),BS("Das sind wirklich dicke, schwarze, schwere "+
  "Dinger. Die hierher zu schaffen, hat bestimmt eine Menge Arbeit gekostet.",78));
  AddDetail(({"arbeit"}),BS("Nix Arbeit, hier wird entspannt.",78));
  AddDetail(({"dinger"}),BS("Na DAS sind aber mal dicke Dinger.",78));
  
 AddDetail(({"turm"}),BS("Dies ist einer der vier Tuerme dieser Burg.",78));
 AddDetail(({"tuerme"}),BS("Es gibt vier Tuerme. Du befindest Dich in einem "+
 "von ihnen.",78));
 AddDetail(({"burg"}),BS("Dies ist die schwarze Burg. Es ist eine boese, "+
 "maechtige Burg.",78));
 AddDetail(({"teil"}),BS("Im hinteren Teil des Raumes befindet sich die "+
 "besagte Leiter.",78));
 AddDetail(({"menge"}),BS("Genau. Eine Meeeeeeenge Arbeit.",78));
 AddDetail(({"eisen"}),BS("Dafuer, dass diese Leiter aus Eisen ist, sieht "+
 "diese Leiter aber wirklich wacklig aus...",78));
 

  AddSounds( SENSE_DEFAULT,
                BS("Das Kratzen ist hier schon lauter zu hoeren...",78));
  AddSounds( ({ "kratzen" }), "Vielleicht solltest Du einfach weiter "+
                              "nach oben gehen, vielleicht aber auch "+
                              "nicht...");
        


  AddSmells( SENSE_DEFAULT, BS(
                "Du riechst nur den allwaehrenden Geruch des Chaos :)",78));
  AddSmells( ({ "geruch", "chaos" }), BS(
                   "Der Geruch des Chaos laesst sich schwer beschreiben, "+
                   "wie Du Dir sicher denken kannst :)",78));
  
  AddExit("unten",CHAOS_GILDEN_ROOM("cl2tu2_1"));
  AddExit("oben",CHAOS_GILDEN_ROOM("cl2tu2_3"));

}
