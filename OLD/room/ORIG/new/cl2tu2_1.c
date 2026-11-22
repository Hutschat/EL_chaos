#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Untergeschoss eines Turms." );
  SetProp( P_INT_LONG, BS("Du befindest Dich ganz unten in einem Turm "+
                          "der Chaosgilde. Die Waende, der Boden als auch "+
                          "die Decke ist aus grossen, schwarzen "+
                          "Steinbloecken gebaut. In hinteren Teil des "+
                          "Raums fuehrt eine eiserne Leiter durch ein "+
                          "schmales Loch weiter nach oben.",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Der komplette Boden besteht, ebenso wie die Decke und die "+
          "Waende, aus schwarze, grossen Steinbloecken.",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke sowie die Waende und der Boden besteht aus "+
          "schwarzen, grossen Steinbloecken. An der Stelle wo die Leiter "+
          "hindurch fuehrt, wurde ein schmales Loch herausgehauen.",78));
  AddDetail( ({ "stein", "gestein"}), BS(
          "Hier besteht fast alles aus diesen schwarzen, grossen "
          "Steinbloecken.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Die Waende bestehen aus dem selben schwarzen Stein wie die "+
          "Decke und der Boden. Im hinteren Teil des Raums fuehrt eine "+
          "eiserne Leiter an der Wand nach oben. Ausserdem haengen an "+
          "kleinen Halterungen dutzende kleiner, schwarz leuchtender "+
          "Kugeln, die fuer das matte Licht hier sorgen.",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "leiter" }), BS(
          "Eine Leiter, die aus dunklem Eisen zu bestehen scheint, fuehrt "+
          "an der hinteren Wand nach oben. Sie ist mit zahlreichen "+
          "Kratzern uebersaet.",78));
  AddDetail( ({ "kratzer" }), BS(
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
          "ARGL! Du siehst genauer hin und erkennst: Es sind tatsaechlich "+
          "Gesichter! Aber es sind keine normalen Gesichter, es sind die "+
          "Gesichter dir bekannter Verraeter des Chaos! Es gibt "+
          "eigentlich nur eine Erklaerung fuer diese seltsame Begebenheit: "+
          "In diesen Kugeln sind jeweils die Seelenhaelften der Verraeter "+
          "gefangen, um fuer ewig ihr laecherliches Dasein in einer "+
          "_Lichtkugel_ zu fristen. ",78));
  AddDetail( ({ "verraeter" }), BS(
          "Du erkennst die Gesichter der Verraeter nicht genau genug, sie "+
          "verschwimmen die ganze Zeit.",78));
  AddDetail( ({ "zeit" }), BS(
          "Zeit ist relativ.",78));
  AddDetail( ({ "chaos" }), BS(
          "Das Chaos ist immerdar!",78));
  AddDetail( ({ "erklaerung", "begebenheit" }), BS(
          "Die steht doch schon dran!",78));
  AddDetail( ({ "seelenhaelften" }), BS(
          "Die Teile, die der Seelenfresser einbehalten hat...",78));
  AddDetail( ({ "teile", "seelenfresser" }), BS(
          "Genauer willst Du es gar nicht wissen...",78));
  AddDetail( ({ "dasein" }), BS(
          "Erbaermlich. Hehe.",78));
  AddDetail( ({ "loch" }), BS(
          "Ein schmales Loch wuerde dich, dank der Leiter an der Wand "+
          "weiter nach oben lassen, wenn Du es versuchst.",78));
  AddDetail(({"turm"}),BS("Du stehst drinnen...",78));
  AddDetail(({"chaosgilde"}),BS("Nun, *huestel* die Chaosgilde ist natuer"+
  "lich lange nicht so gut wie die Abenteurer-Gilden, denn die ist "+
  "*kicher* natuerlich immernoch die beste aller Gilden *waelz*. Du "+
  "verstehst.",78));
  AddDetail(({"abenteurer","gilde","abenteurer-gilde"}),BS("Die Abenteurer-"
  "Gilde ist die beste aller Gilden. Hihi.",78));
  AddDetail(({"gilden","beispiel"}),BS("Nimm zum Beispiel die Chaosgilde!"));
  AddDetail(({"eisen"}),BS("Wow, diese Leiter besteht wirklich aus "+
  "Eisen! Wie erstaunlich!",78));
  AddDetail(({"lichtkugel"}),BS("Es gibt kaum etwas schlimmeres, als sein "+
  "unsterbliches Dasein als lebende Lichtquelle fristen zu muessen. Nun, "+
  "natuerlich gibt es schlimmere Arten, da ist diese eine ... oder .. ja. "+
  "Es gibt wirklich schlimmeres. Aber, um ehrlich zu sein, nicht viel "+
  "schlimmeres.",78));
  AddDetail(({"lichtquelle"}),BS("Na, diese Kugeln kann man eigentlich "+
  "kaum Lichtquelle nennen.",78));
  AddDetail(({"arten","dasein"}),BS("Das unsterbliche Dasein kann man auf "+
  "sehr viele verschiedene angenehme und weniger angenehme Arten fristen...",78));
  AddDetail(({"schwarzlicht"}),BS("Das Schwarzlicht geht von den Kugeln "+
  "an den Waenden aus!",78));
  AddDetail(({"teil","hinterer teil"}),BS("Im hinteren Teil des Raumes fuehrt "+
  "eine Leiter nach oben in das grauenhafte dunkle Ungewisse...",78));
  AddDetail(({"ungewisse","ungewisses"}),BS("Das Ungewisse befindet sich "+
  "uber Dir.",78));
  AddDetail(({"stelle"}),BS("Das Loch ist genau an der Stelle, wo die Leiter "+
  "durch die Decke fuehrt. Na wie praktisch!"));
  
  AddSounds( SENSE_DEFAULT,
                BS("Von weiter oben meinst du ab und zu ein Kratzen, wie "+
                   "von Klauen, die an der Wand entlangfahren zu "+
                   "vernehmen...",78));
  AddSounds( ({ "kratzen" }), "Vielleicht solltest Du einfach weiter "+
                              "nach oben gehen, vielleicht aber auch "+
                              "nicht...");
  


  AddSmells( SENSE_DEFAULT, BS(
                "Du riechst nur den allwaehrenden Geruch des Chaos :)",78));
  AddSmells( ({ "geruch", "chaos" }), BS(
                   "Der Geruch des Chaos laesst sich schwer beschreiben, "+
                   "wie Du Dir sicher denken kannst :)",78));

  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2bu3"));
  AddExit("oben",CHAOS_GILDEN_ROOM("cl2tu2_2"));
}
