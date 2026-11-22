#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

inherit  CHAOS_GILDEN_ROOM("cl2bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu5"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Innerhalb der chaotischen Burg");
  SetProp(P_INT_LONG,BS("Finsternis umgibt Dich, Schatten deuten die "+
  "Dich umgebenden Gebaeude an. Noerdlich von Dir erhebt sich schemenhaft "+
  "einer der vier Tuerme dieser Burg, kaum zu erkennen und bald in der "+
  "Dunkelheit verschwindend. Eine Tuer, undeutlich zu erkennen, bietet "+
  "Zugang zu ihm. Oestlich von Dir schaelt sich ein weiteres Gebaeude "+
  "aus der Finsternis, direkt an die maechtige Burgmauer gebaut, "+
  "welche sich noerdlich wie westlich von Dir erhebt. Ein weiteres, "+
  "groesseres und wuchtigeres, Gebaeude erhebt sich suedlich von Dir."));
  AddDetail(({"boden"}),BS("Er ist in dieser merkwuerdigen Finsternis "+
  "kaum zu erkennen... Er ist mit Pflastersteinen befestigt und hat eine "+
  "dunkelbraune Farbe."));
  AddDetail(({"farbe"}),BS("Waaaarte mal! Der Boden hat eine dunkelbraune "+
  "Farbe? Du betrachtest das ganz genau und kommst zu folgendem Schluss: "+
  "Der Boden hier ist bedeckt von getrocknetem Blut. Und zwar fast komplett. "+
  "Was hier wohl vorgefallen sein mag..."));
  AddDetail(({"blut"}),BS("Wow, hier muss viel Blut geflossen sein, um "+
  "den ganzen Boden zu bedecken. Hier ist wohl jemand elendig verblutet. "+
  "Das wunderd Dich allerdings nicht allzu sehr. Eigentlich wundert Dich "+
  "nur, dass es hier nicht ueberall so aussieht. Auf dem Boden wurde mit "+
  "Blut sogar eine satanische Zeichnung gemalt."));
  AddDetail(({"jemand"}),"Jemand roechelt: Ich bin noch garnicht tooot!\n"+
  "Jemand roechelt: Eigentlich geht es mir ganz gut!\n");
  AddDetail(({"schluss"}),BS("OHHHHH SCHEISSE! DAS IST JA BLUT!"));
  AddDetail(({"scheisse"}),BS("Nein! Da greifst Du jetzt NICHT rein!"));
  AddDetail(({"pflastersteine"}),BS("Der Boden ist mit Pflastersteinen "+
  "bedeckt. Diese Pflastersteine sind haben eine dunkelbraune Farbe, was "+
  "ziemlich ungewoehnlich ist. Eigentlich war so ziemlich alles, was Du "+
  "in dieser Burg bisher gesehen hast, absolut schwarz."));
  AddDetail(({"burg"}),BS("Dies ist die chaotische Burg, die Burg des "+
  "Chaos. Heim der Chaoten, Sitz der beruehmt- beruechtigten Chaosgilde. "+
  "Erbaut von Daemonen und durch satanische Kraefte stellt sie ein teufli"+
  "sches Meisterwerk dar."));
  AddDetail(({"chaos","chaoten","chaosgilde"}),BS("Die Chaosgilde befindet "+
  "sich hier in dieser Burg. Im Grunde IST sie diese Burg. Hier gehen "+
  "die Chaoten hin, wenn sie eine lustige Zeit haben moechten. Hier "+
  "herrscht das Chaos. Pass auf Dich auf."));
  AddDetail(({"zeit"}),BS("Hier kann man eine verdammt lustige Zeit "+
  "verbringen, wenn man ein Chaot ist."));
  AddDetail(({"daemonen"}),BS("Sind hier welche? Dann solltest Du WEGRENNEN!"));
  AddDetail(({"wand","waende","mauer","mauern"}),
  BS("Waende? Mauern? Davon gibt es jede Menge hier! "+
  "Da gibt es zum Beispiel die gewaltige Burgmauer, welche Dich noerdlich "+
  "und westlich beengt. Oder die Mauern der beiden Haeuser, die Du von "+
  "hier aus erkennen kannst."));
  AddDetail(({"burgmauer"}),BS("Die Burgmauer ragt schwarz und gewaltig "+
  "in der Dunkelheit vor Dir auf. Sie wurde mit gewaltigen, schwarzen "+
  "Steinbrocken gebaut, geschleppt von den Daemonen, welche diese Burg "+
  "einst bauten."));
  AddDetail(({"brocken","steinbrocken"}),BS("Diese Steinbrocken sind "+
  "pechschwarz und sehen keinen Steinen aehnlich, welche Du ausserhalb "+
  "dieses blutigen Eisbergs je gesehen hast. Du denkst, sie wurden von "+
  "den Daemonen mitgebracht, welche diese Burg einst bauten. Aber "+
  "woher  kamen diese? Fragen ueber Fragen..."));
  AddDetail(({"steine"}),BS("Hier gibt es wirklich viele Steine."));
  AddDetail(({"eisberg"}),BS("Du bist hier in einer Burg in einer Hoehle "+
  "eines gewaltigen schwarzen Eisbergs, umgeben von Daemonen, Chaoten und "+
  "ziemlich ueblen Gestalten."));
  AddDetail(({"gestalten"}),BS("Hehe, war nicht so gemeint."));
  AddDetail(({"hoehle"}),BS("Wow, diese Burg steht in einer riesigen "+
  "Hoehle! Was fuer eine coole Burg!"));
  AddDetail(({"fragen"}),BS("Du kannst sie nicht beantworten..."));
  AddDetail(({"finsternis","dunkelheit"}),BS("Finsternis umhuellt Dich, bewegt sich um "+
  "Dich herum und scheint fast nach Dir zu greifen, als waere es ein "+
  "lebendiges, boesartiges Wesen. Panik erfuellt Dich, denn hier, in "+
  "dieser Burg, ist das nicht nur moeglich, sondern sogar wahrscheinlich..."));
  AddDetail(({"wesen","eigenleben"}),BS("Die Finsternis scheint hier wirklich ein "+
  "Eigenleben zu fuehren. Das ist alles wirklich unheimlich."));
  AddDetail(({"panik"}),BS("WAAAAAAAAAAAAAAAAAAAH! PAAAAAAAAAANIIIIIIIK!"));
  AddDetail(({"zeichnung"}),
  "Du siehst Dir die Zeichnung an und wirst nicht recht schlau daraus. Sie sieht\n"+
  "ungefaehr so aus: \n"+
  "\n"+
  "        |     |                   \n"+
  "     X  |  0  |  X                \n"+  
  "   -----+-----+-----            \n"+  
  "        |     |                   \n"+  
  "     0  |  0  |  X                \n"+  
  "   -----+-----+-----            \n"+  
  "        |     |                   \n"+  
  "     0  |     |  X                \n");
  AddDetail(({"schatten"}),BS("Alles was Du hier siehst sind Schatten. "+
  "Die hier herrschende Finsternis laesst garnichts anderes zu. Die Gebaeude "+
  "um Dich herum sind Schatten, die Burgmauer ist ein gewaltiger Schatten, "+
  "ebenso wie der grosse Turm, der sich aus ihm erhebt..."));
  AddDetail(({"gebaeude"}),BS("Du kannst schattenhaft zwei Gebaeude "+
  "erkennen. Eines befindet sich Oestlich und eines Suedlich von Dir. "));
  AddDetail(({"gebaeude 1","oestliches gebaeude"}),BS(
  "Dieses Gebaeude liegt oestlich von Dir "+
  "und ist natuerlich nur schemenhaft zu erkennen. Verdammte Finsternis. "+
  "Das Gebaeude wurde auf jeden Fall direkt an die Burgmauer gebaut und "+
  "scheint auf dieser Seite keine Fenster zu haben. Wozu wohl auch, gibt "+
  "ja eh nix zu sehen hier."));
  AddDetail(({"gebaeude 2","suedliches gebaeude"}),BS(
  "Gebaeude 2 befindet sich suedlich von "+
  "Dir und ist ebenfalls nur als Schatten in einem Schatten erkennbar. "+
  "Es wurde nicht direkt an eine Burgmauer gebaut, sondern steht sozusagen "+
  "mitten im Hof dieser Burg."));
  AddDetail(({"hof","burghof"}),BS("Nun, sieh es so. Hier ist diese grosse Burg. Sie "+
  "besteht aus der gewaltigen Burgmauer, welche sich um die gaaanze Burg "+
  "zieht, und allem darin. Alles darin befindet sich im Burghof. Sagen "+
  "wir mal so."));
  AddDetail(({"seite"}),BS("Du kannst nur eine Seite des Gebaeudes sehen."));
  AddDetail(({"fenster"}),BS("Die Gebaeude haben keine Fenster. Wer weiss, "+
  "vielleicht soll man nicht reinschaun..."));
  AddDetail(({"tuerme"}),BS("Diese Burg hat vier grosse, schwarze Tuerme, "+
  "welche sich majestaetisch und boshaft ueber der Burg erheben. Du kannst "+
  "hier nur einen davon sehen, und von dem auch nicht allzu viel, da es "+
  "so verdammt duester ist."));
  AddDetail(({"turm"}),BS("Der Turm ist verdammt hoch. Das kannst Du jedoch "+
  "nicht sehen. Denn es ist so verdammt dunkel. Alles was Du sehen kannst "+
  "ist ein schwarzer Schatten, welcher hoch, noch ueber die Burgmauer vor "+
  "Dir aufragt und schnell in der Finsternis dieser verfluchten Hoehle ver"+
  "schwindet. Ein leicht hellere Flaeche, etwa zwei Meter hoch, deutet "+
  "die Tuer zu diesem Turm an."));
  AddDetail(({"meter"}),BS("Du weisst, was ein Meter ist."));
  AddDetail(({"flaeche"}),BS("Die etwas hellere Flaeche ist die Tuer!"));
  AddDetail(({"stein"}),BS("Du bist umgeben von Stein. Diese ganze "+
  "Burg besteht anscheinend vollstaendig aus Stein. Was eine gute Sache "+
  "ist, denn Stein brennt nicht allzu leicht. Aber es geht hier sicher"+
  "lich um die Tuer zum Turm, welche Du in der Dunkelheit kaum wahrnehmen "+
  "kannst. Sie scheint aus Stein zu bestehen, auch wenn der fuerchterlich "+
  "kalt und extrem glatt ist. Du hast solch merkwuerdigen Stein noch "+
  "nicht vorher gesehen. Allerdings hast Du in dieser Hoehle viele Dinge "+
  "gesehen, die Du vorher noch nie gesehen hast."));
  AddDetail(({"dinge","sache"}),BS("Sowas kannst Du hier ueberall sehen. "+
  "Drueck dich also praeziser aus."));
  AddDetail(({"zugang"}),BS("*CHRK* *ZZZZZZZZZRRRRRRK* ZUGANG VERWEIGERT "+
  "*CHRK* *ZRRRRRRK* *RESET*"));
  AddSpecialDetail(({"reset"}),"det_reset");
  AddDetail(({"silhouette"}),BS("Hmmmmmm... Das KOENNTE eine Tuer sein!!!"));
  AddDetail(({"decke"}),BS("Die Decke kannst Du in dieser Finsternis "+
  "nicht erkennen."));
  
  
  AddSmells(SENSE_DEFAULT,BS("Du kannst hier kaum was interessantes riechen."));
  AddSounds(SENSE_DEFAULT,BS("Welch toedliche Stille....."));
  
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl2bu4"));
  AddExit("sueden",   CHAOS_GILDEN_ROOM("cl2bu2"));
  NewDoor("norden",CHAOS_GILDEN_ROOM("cl2tu2_1"),({"tuer"}),
    ({D_NAME,"Tuer",
      D_GENDER,2,
      D_SHORT,"Im Norden siehst Du die Silhouette einer %sen Tuer.",
      D_LONG,BS("Du kannst die Tuer in der Dunkelheit nicht genau erkennen, "+
      "doch sie scheint wirklich extrem massiv zu sein. Wow, besteht Die aus "+
      "Stein?") }));
  
  AddCmd(({"greif","greife"}),"dig");
  AddCmd(({"renn","renne"}),"run_for_it");
  AddCmd(({"drueck","druecke"}),"say_it");
  
}

int dig(string was) {
  notify_fail("In was moechtest Du greifen?\n");
  if (was != "in scheisse" && was != "scheisse") return 0;
  write("NEIN NEIN NEIN! Das tust DU NICHT!\n");
  return 1;
}

int run_for_it(string was) {
  notify_fail("Wohin willst Du denn rennen?\n");
  if (was != "weg") return 0;
  write("Du nimmst Deine Beine in die Hand und RENNST!\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2bu2"),M_GO,"weg");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2bu1"),M_GO,"weg");
  write("PUUUUUUUUUUUUH. Das war harscharf.\n");
  return 1;
}

int say_it(string was) {
  notify_fail("Wie willst Du dich ausdruecken?\n");
  if (was != "praeziser aus" && was != "dich praeziser aus")
    return 0;
  write("Du drueckst Dich praeziser aus.\nDas ist schon besser.\n");
  return 1;
}

string det_reset() {
  write("Der Gamedriver ruft: "+capitalize(getuid(this_player()))+" faehrt das Spiel herunter!\n");
  this_player()->command_me("schlafe ein");
  return "";
}
