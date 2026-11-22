#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Mitten in einem Turm." );
  SetProp( P_INT_LONG, BS("Du stehst jetzt wohl kurz vor dem Dachgeschoss "+
                          "dieses Turmes. Die Treppe fuehrt weiter hinauf, "+
                          "jedoch findest Du hier noch viel mehr "+
                          "Kratzspuren als weiter unten... Du bekommst "+
                          "es allmaehlich mit der Angst zu tun!",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Der komplette Boden besteht, ebenso wie die Decke und die "+
          "Waende, aus schwarze, grossen Steinbloecken. Du erkennst "+
          "viele Kratzspuren an ihm.",78));
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
          "Decke und der Boden. Ausserdem haengen an kleinen Halterungen "+
          "dutzende kleiner, schwarz leuchtender Kugeln, die fuer das "+
          "matte Licht hier sorgen, und es sind auch hier viele "+
          "Kratzspuren zu erkennen.",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "wesen" }), BS(
          "Hmm, denen wirst Du vermutlich noch begegnen...",78));
   AddDetail( ({ "kratzer", "kratzspuren", "spuren" }), BS(
          "Hmm, woher die wohl kommen?",78));
  AddDetail( ({ "halterungen" }), BS(
          "Die Halterungen scheinen aus dunklem Eisen zu bestehen. "+
          "An ihnen haengen jeweils mehrere kleine dunkle Kugeln.",78));
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
          "Boden... Sie fuehrt weiter nach oben und nach unten.",78));
  AddDetail( ({ "angst" }), BS(
          "ANGST! PURE ANGST! Solltest Du jedoch ein Chaoskrieger sein, "+
          "so hast Du selbige natuerlich nicht.",78));
  AddDetail( ({ "chaoskrieger" }), BS(
          "Die fangen den Schaden mit der Brust ab!",78));
  AddDetail( ({ "schaden", "brust" }), BS(
          "Hmm, ist nur so ein Sprichwort :)",78));
  AddDetail( ({ "sprichwort" }), BS(
          "Hoer auf damit!",78));
  AddDetail(({"dachgeschoss"}),BS("Das Dachgeschoss befindet sich natuerlich "+
  "ueber Dir. Dementsprechend befindest Du Dich unter dem Dachgeschoss, nicht "+
  "davor. Aber egal.",78));
  AddDetail(({"steinbloecke"}),BS("Es sind grosse, schwarze Steinbloecke, die "+
  "sich verdaechtig kalt anfuehlen.",78));
  AddDetail(({"turm"}),BS("Du befindest Dich in einem schwarzen Turm innerhalb "+
  "der boesartigen Burg des Chaos!",78));
  AddDetail(({"burg"}),BS("Diese Burg ist die Festung der Chaoten.",78));
  AddDetail(({"festung"}),BS("Diese Festung haelt so gut wie alles aus!",78));
  AddDetail(({"chaos","chaoten"}),BS("Chaoten sind die Besten, denn sie "+
  "dienen dem Chaos.",78));
  AddDetail(({"beste"}),BS("Jaha, Chaoten! Ich sags Dir.",78));
  AddDetail(({"schwarzlicht"}),BS("Das ist wirklich das unheimlichste Licht, "+
  "das Du je gesehen hast!",78));

  AddSounds( SENSE_DEFAULT,
                BS("Das Kratzen ist hier schon verdammt laut zu hoeren, "+
                   "ausserdem glaubst Du ein seltsames Geraeusch, wie "+
                   "Fluegelschlagen zu hoeren...",78));
  AddSounds( ({ "kratzen", "fluegelschlagen", "geraeusch" }), "Vielleicht "+
                "solltest Du einfach weiter nach oben gehen, vielleicht "+
                "aber auch nicht...");
        


  AddSmells( SENSE_DEFAULT, BS(
                "Du riechst nur den allwaehrenden Geruch des Chaos :)",78));
  AddSmells( ({ "geruch", "chaos" }), BS(
                   "Der Geruch des Chaos laesst sich schwer beschreiben, "+
                   "wie Du Dir sicher denken kannst :)",78));

    AddExit("unten",CHAOS_GILDEN_ROOM("cl2tu2_2"));
    AddExit("oben",CHAOS_GILDEN_ROOM("cl2tu2_4"));
      

}
