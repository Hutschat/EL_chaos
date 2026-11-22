#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

inherit CHAOS_GILDEN_ROOM("cl2bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu3"));
  SetProp(P_LIGHT,0);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Innerhalb der Burg des Chaos");
  SetProp(P_INT_LONG,break_string(
  "\bEs ist stockduster hier. Du kaum mehr als ein "+
  "paar Meter weit sehen. Alles um Dich herum ist Schwarz in Schwarz. "+
  "Soviel siehst Du jedoch:\n"+
  "Du befindest Dich in der Burg. Das Portal, welches auf die Bruecke "+
  "fuehrt, ragt finster hinter Dir auf, ein gewaltiger schwarzer Schatten "+
  "auf grauem Hintergund. Im Westen erhebt sich, hoch ueber die Burgmauern "+
  "hinweg, einer der Tuerme dieser Burg. Du weisst nicht wie hoch, denn "+
  "er wird schnell von der Dunkelheit verschluckt. Etwas noerdlich, "+
  "abstuetzend vor eine Hauswand angebracht, steht ein merkwuerdiges graues "+
  "Objekt, aus dem Du nicht so recht schlau wirst. Es ist, wie gesagt, an "+
  "eine Hauswand gelehnt, deren Farbe ebensowenig auszumachen ist wie ihre "+
  "Struktur oder auch nur ihre Hoehe. Etwas im Osten kannst Du finster "+
  "eine weitere Hauswand erkennen, formlos in der Dunkelheit wie die erste. "+
  "Dein Weg kann Dich nach Nordosten zwischen diesen Haeusern vorbei fuehren "+
  "oder nach Nordwesten zwischen Burgmauer und Haus.",78,0,1));
  AddDetail(({"meter"}),BS("Dieses Detail hatten wir schon so oft. Du weisst "+
  "inzwischen, was ein Meter ist."));
  AddDetail(({"detail"}),BS("Untersucht."));
  AddDetail(({"schwarz"}),BS("Der Baustoff, aus welchem diese Burg gebaut "+
  "wurde, was er auch immer sein mag, ist schwarz. Er ist tiefschwarz, und "+
  "scheint das Licht quasi in sich versacken zu lassen. Dazu kommt diese "+
  "unnatuerliche Dunkelheit, welche in dieser Burg herrscht. Selbst mit dem "+
  "Licht eines blutigen Klerikers koennte man hier nicht mehr sehen als Du "+
  "jetzt, nicht mehr als Schatten in Schatten auf Schatten, Schwarz in "+
  "Schwarz auf Schwarz. Das hoechste der Gefuehl hier ist etwas Grau, "+
  "wo eigentlich Farben zu sehen sein sollten."));
  AddDetail(({"baustoff"}),BS("Da sind erst einmal die grossen Felsbrocken, "+
  "aus denen die Burgmauern gebaut wurden. Doch sie sind nicht der einzige "+
  "Baustoff. Man denke an das seltsame, makellos schwarze Material, aus "+
  "dem das Portal besteht. Oder die Steine der Hauswaende, welche Du von "+
  "hier aus sehen kannst. Sie sind allesamt schwarz und saugen das Licht "+
  "in sich auf."));
  AddDetail(({"licht"}),BS(
  "In dieser Burg gibt es kein Licht. In dieser Burg herrscht die "+
  "Finsternis, in dieser Burg herrscht das Chaos. Und zwar von Anfang an."));
  AddDetail(({"kleriker"}),BS("Jeder weiss doch: Kleriker sind Bah."));
  AddDetail(({"bah"}),BS("Kannst Du 'Bah' sagen?"));
  AddDetail(({"belohnung"}),BS("Kriegst aber keine Hehehe.\n"));
  AddDetail(({"boden"}),BS("Wow, welche Ueberraschung! Der Boden wurde mit "+
  "pechschwarzen Steinen gepflastert. Die Leute hier muessen wirklich ernst"+
  "hafte Probleme haben."));
  AddDetail(({"ueberraschung"}),BS("In Wahrheit war es natuerlich garkeine "+
  "richtige Ueberraschung..."));
  AddDetail(({"wahrheit"}),BS("Was ist schon die Wahrheit? HA!"));
  AddDetail(({"leute"}),BS("Wer mag hier nur wohnen? Naja, wer auch immer, "+
  "entweder ist er voellig wahnsinnig oder abgrundtief boese. Du weisst "+
  "nicht, welche Alternative Du vorziehen wuerdest."));
  AddDetail(({"probleme"}),BS("Grosse Probleme. Ernsthafte Probleme."));
  AddDetail(({"grosse probleme","ernsthafte probleme"}),BS(
  "Komm mit deinen Problemen nicht zu mir. Ich hab selbst genug am Hut."));
  AddDetail(({"alternative"}),BS("Also ich persoehnlich zoege abgrundtief "+
  "boese vor. Das waer mir sympatischer."));
  AddDetail(({"steine"}),BS("Steine siehst Du sowohl in den Hauswaenden als "+
  "auch im Boden, der mit Steinen gepflastert wird. Gruendlich untersuchst "+
  "Du alle Rillen und Fugen zwischen den Steinen, kannst aber nichts "+
  "auffaelliges entdecken."));
  AddDetail(({"rillen","fugen"}),BS("Es gibt eine ziemliche Menge an Rillen "+
  "und Fugen in dieser Burg. Wow, dass wird DAUERN!"));
  AddDetail(({"wand","waende"}),BS("Es gibt hier erst mal Hauswaende. Ausser"+
  "dem gibt es aber noch die Burgmauer. Was meinst Du jetzt?"));
  AddDetail(({"hauswand","hauswaende"}),BS("Du kannst die Hauswaende in die"+
  "ser Dunkelheit kaum erkennen. Sie scheinen aus poroesen, schwarzen, "+
  "groben und recht grossen Ziegelsteinen gebaut worden zu sein. Hmm. "+
  "Irgendwie nicht allzu interessant."));
  AddDetail(({"ziegelsteine"}),BS("Es sind schwarze Steine, welche in "+
  "Ziegelform gehauen wurden."));
  AddDetail(({"ziegelform"}),BS("Du weisst, was das ist."));
  AddDetail(({"burgmauer","burgmauern"}),BS("Die Burgmauer besteht aus grossen, "+
  "schwarzen Felsbrocken. Ansonsten ist sie nicht gerade interessant."));
  AddDetail(({"dunkelheit","huelle","finsternis"}),
  BS("In dieser Burg herrscht einen unnatuerliche Finsternis. Trotz all "+
  "deiner Muehen kannst Du nicht weiter als ein pahr Schritt weit sehen. "+
  "Was hier wohl vor sich geht?"));
  AddDetail(({"muehen"}),BS("Du starrst intensivst vor Dich hin."));
  AddDetail(({"schritt"}),BS("Du weisst, was ein Schritt ist."));
  AddDetail(({"burg"}),BS("Du stehst in einer schrecklich finsteren Burg."));
  AddDetail(({"schatten"}),BS("In dieser Burg herrscht die Finsternis. In "+
  "dieser Burg herrscht die Finsternis. Dies ist die Burg des Boesen, "+
  "dies ist die Burg des Chaos."));
  AddDetail(({"boeses"}),BS("Wer hier wohnt, wird Boeses planen, da bist "+
  "Du Dir ganz sicher."));
  AddDetail(({"chaos","ordnung"}),BS("Chaos herrscht ueber der Ordnung. So ist es, und "+
  "so wird es immer sein."));
  AddDetail(({"felsbrocken"}),BS("Du hast diese grossen, schwarzen Felsbrocken "+
  "schon von ausserhalb der Burg gesehen, und hier kannst Du sie noch "+
  "schlechter erkennen. Ausser ihrer wirklich uebergrossen Dimensionierung "+
  "kannst Du nichts Interessantes an ihnen erkennen."));
  AddDetail(({"dimensionierung"}),BS("Schwieriges Wort, was?"));
  AddDetail(({"wort"}),BS("Findest Du nicht auch?"));
  AddDetail(({"material"}),BS("Du kannst nicht sagen, was das ist."));
  AddDetail(({"leiter"}),BS("Diese Leiter kann man bestimmt hinaufklettern, "+
  "falls man Mumm genug hat."));
  AddDetail(({"mumm"}),BS("Du hast Mumm. Geh da rauf. Ich vertraue Dir."));
  AddSpecialDetail(({"bruecke","haengebruecke"}),"det_bruecke");
  AddDetail(({"hintergrund"}),BS("Der Hintergrund in dieser Burg ist "+
  "recht einheitlich, und zwar schwarz."));
  AddDetail(({"mauern"}),BS("Es gibt hier sowohl die gewaltigen Burgmauern "+
  "als auch die nicht ganz so maechtigen Hauswaende."));
  AddDetail(({"turm","tuerme"}),BS("Im Westen erhebt sich einer der vier "+
  "Tuerme dieser Burg. Du kannst nicht allzuweit sehen, doch Du weisst, er "+
  "erhebt sich hoch ueber die Burg. Eine unscheinbare Tuer ermoeglicht "+
  "den Zugang."));
  AddDetail(({"farbe"}),BS("Du bist Dir ziemlich sicher, dass diese Hauswand "+
  "schwarz ist. Was sollte sie auch sonst sein?"));
  AddDetail(({"struktur"}),BS("Die Steine haben eine feste Struktur. Mehr "+
  "kannst Du momentan nicht sagen."));
  AddDetail(({"hoehe"}),BS("Auch wenn Du es nicht sehen kannst, dieser Turm "+
  "ist _ziemlich_ hoch!"));
  AddDetail(({"etwas"}),BS("Das Etwas ist doch nicht in dieser Burg! Oder???"));
  AddDetail(({"weg"}),BS("Es ist eigentlich kein Weg hier. Du kannst Dich "+
  "halt lediglich nach Nordosten oder Nordwesten weden. Oder die Burg "+
  "verlassen. Oder den Turm betreten. Oder auf das Gebaeude vor Dir klettern."));
  AddDetail(({"gebaeude","haeuser"}),
  BS("Du kannst von hier aus 2 Gebaeude sehen. "+
  "Eines steht noerdlich, eines oestlich von Dir. Die Tueren muessen sich "+
  "aber wohl an anderen Seiten dieser Gebaeude befinden."));
  AddDetail(({"seiten"}),BS("Ein Gebaeude hat mehrere Seiten! Das ist einfach "+
  "so."));
  AddDetail(({"form"}),BS("Welche Form moegen diese Haeuser nur haben? "+
  "Du weisst es nicht."));
  AddDetail(({"haus"}),BS("Es gibt hier sogar zwei Haeuser."));
  AddDetail(({"silhouette"}),BS("Naja, ok, Du kannst die Tuer doch etwas "+
  "besser als nur als Silhouette erkennen. Andererseits ist sie nicht "+
  "allzu interessant."));
  
  
  
  
  AddSmells(SENSE_DEFAULT,BS("Du kannst wirklich nix besonderes riechen."));
  AddSounds(SENSE_DEFAULT,BS("Es ist totenstill hier drinn."));

  AddExit("nordosten",CHAOS_GILDEN_ROOM("cl2bu5"));
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl2bu2"));

  NewDoor("westen",CHAOS_GILDEN_ROOM("cl2tu4_1"),({"tuer"}),
    ({D_NAME,"Tuer",
      D_GENDER,2,
      D_SHORT,"Im Westen siehst Du die Silhouette einer %sen Tuer.",
      D_LONG,BS("Du kannst die Tuer in der Dunkelheit nicht genau erkennen, "+
      "doch sie scheint wirklich extrem massiv zu sein. Wow, besteht Die aus "+
      "Stein?") }));

  NewDoor("sueden",CHAOS_GILDEN_ROOM("cl2br2"),({"portal"}),
    ({D_NAME,"Portal",
      D_FUNC2,"check_way",
      D_GENDER,0,
      D_SHORT,"In der Dunkelheit suedlich von Dir ragt das grosse, %se Portal auf.\n",
      D_LONG,BS("Es ist zu dunkel, um das Portal genauer zu untersuchen, doch "+
      "das Material, aus dem es besteht, ist makellos, fremdartig und massiv. "+
      "Ploetzlich entdeckst Du neben dem Portal eine Leiter, welche in die "+
      "Dunkelheit ueber Dir fuehrt.") }));
  
  AddCmd(({"sag","sage"}),"bah");
  AddCmd(({"ja"}),"ja");
  AddCmd(({"kletter","klettere"}),"climb");
  AddItem("/d/polar/files.chaos/obj/modulator",REFRESH_DESTRUCT);
  
}

int bah(string was) {
    if (was == "ja")
    write("Ja, das ist wirklich ein schwieriges Wort, da stimmen wir also ueberein.\n");
    if (was != "bah") return 0;
    write("Schoen gemacht. Hast Dir ne Belohnung verdient.\n");
    return 0;
}

int ja() {
   return bah("ja");
}

int climb(string was) {
  notify_fail("Was moechtest Du denn hinaufklettern?\n");
  if (was == "auf gebaeude" || was == "auf haus")
  {
     write("Dazu reicht deine Geschicklichkeit nicht aus.\nHehe, nur Scherz.\n");
     return 1;
  }
  if (was != "leiter hinauf" && was != "hoch" && was != "leiter hoch") 
     return 0;
     
  write("Du kletterst die Leiter hinauf.\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2br4"),M_GO,"die Kletter hinauf",
                      "leitert","kommt heraufgeklettert");
  return 1;
}

string det_bruecke()
{
  if ("/obj/doormaster"->QueryDoorStatus(CHAOS_GILDEN_ROOM("cl2br2"))!=1)
    return BS("Du kannst die Bruecke nicht sehen. Das Portal ist geschlossen.");
 
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0) 
    return BS("Die Bruecke ist zerstoert. Du kannst sie nicht sehen.");
  
  return "Du streckst deinen Kopf durch das Portal uns siehst folgendes:\n"+
  call_other(CHAOS_GILDEN_ROOM("cl2br2"),"int_long",this_player(),
             this_player());
}

int doorshut()
{
  if ("/obj/doormaster"->QueryDoorStatus(CHAOS_GILDEN_ROOM("cl2br2"))==1)
    return 0;
  return 1;
}

init()
{
  ::init();
  add_action("command_check","",1);
}

command_check(str)
{
   string v;
   v = query_verb();
   if (!stringp(str)) return 0;

   if (member_array(v,({"frag","frage","applaudiere","begruesse","betaste",
   "danke","druecke","apllaudier","begruess","betast","drueck","gratulier",
   "gratuliere","beglueckwuensch","beglueckwuensche","grins","grinse",
   "grummel","grummle","haetschel","haetschle","huepf","huepfe","jubel",
   "juble","kitzel","kitzle","knutsche","knutsch","knurr","knurre",
   "knuddel","knuddle","kotze","kotz","kuess","kuesse","kuschel","kuschle",
   "lieb","liebe","lob","lobe","sabber","sabbere","schmieg","schmiege",
   "starr","starre","stimme","stosse","streichel","streichle","strecke",
   "stupse","tanze","tanz","tritt","trete","troeste","umarme","umarm",
   "verneige","verneig","verfluch","verfluche","wuerg","wuerge","wuschel",
   "wuschle","zwinker","zwinkere","toete","feuerball","saeurestrahl",
   "beschimpfe","kampftritt","kopfstoss","ellbogenschlag"})) != -1)
   {
     if (str == "objekt" || str == "modulator" || str == "chaosmodulator" )
     {
       write("Aber ein Objekt lebt wirklich nich.\n");
       return 1;
     }
   }
   return 0;
}


