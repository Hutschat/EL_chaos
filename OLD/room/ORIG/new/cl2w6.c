#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In einer Hoehle im Eisberg");
  SetProp(P_INT_LONG,break_string("\bDu befindest Dich in einer gewaltigen Hoehle, "+
  "umgeben von Unmengen Eis. Im Suedosten befindet sich ein kleines "+
  "Waldstueck, welches bis an den Rand dieser Hoehle heranreicht. Im "+
  "Nordwesten befindet sich in einiger Entfernung ein grosser, gruener "+
  "See, in dessen Mitte sich eine schwarze Burg erhebt. Im Nordosten en"+
  "ntdeckst Du, weit entfernt, einen weiteren Wald, schwarz wie der im "+
  "Suedosten. Der Weg fuehrt aus dem Wald im Suedosten nach Norden und "+
  "teilt sich dann, um zum Wald und zur Burg zu fuehren.\n"+
  "Leichter Regen faellt auf Dich herab und die Luft ist erfuellt von "+
  "eine Geruch nach Saeure. Es ist bitterkalt.",78,0,1));
  AddDetail(({"unmengen","mengen"}),
  BS("Mann, dass sind waaaaaahnsinnige Mengen!"));
  AddDetail(({"see","gruener see"}),
  BS("Im Nordosten erkennst Du einen grossen, gruenen "+
  "See, in dem eine Burg gebaut wurde. Merkwuerdigerweise scheint die Burg "+
  "mit ihren schwarzen Steinen noch dunkler und schlechter zu sehen sein als "+
  "es eigentlich normal waere. Es ist, als wuerde sie sich in diesem duesteren "+
  "Halbdunkel in einen noch dunkleren Mantel der Dunkelheit huellen. Ueber den "+
  "merkwuerdigen gruenen See wurde eine Art Haengebruecke zur Burg gebaut."));
  AddDetail(({"mantel"}),BS("Welch merkwuerdige, finstere Burg..."));
  AddDetail(({"art"}),BS("So eine Art eben."));
  AddDetail(({"burg"}),BS("Die Burg sieht aus der Entfernung nicht allzu "+
  "gross aus. Sie erhebt sich hoch aus dem gruenen See und wurde aus "+
  "schwarzen, gewaltigen Steinen erbaut. Vier grosse Tuerme erheben sich "+
  "aus ihr, einer an jeder Ecke der Burg. Ein grosses Tor fuehrt aus ihr "+
  "heraus ueber eine Bruecke hinueber zum Ufer des Sees. Merkwuerdigerweise "+
  "scheint es in und um die Burg herum noch sehr viel dunkler zu sein als "+
  "es hier in der Hoehle so oder so schon ist."));
  AddDetail(({"steine"}),BS("Das sind aber maeaechtige schwarze Steine. Du "+
  "kannst von hier aus nicht so viel erkennen, aber Du fragst Dich schon, "+
  "wo die wohl herkommen."));
  AddDetail(({"tuerme"}),BS("Ausser ihrer Anwesenheit kannst Du nicht viel "+
  "an ihnen erkennen."));
  AddDetail(({"anwesenheit"}),BS("Jup, die Tuerme sind da..."));
  AddDetail(({"tor"}),BS("Die Burg hat ein grosses schwarzes Tor, eine "+
  "Art Portal, welches ebenso schwarz ist, wie die Steine um es herum."));
  AddDetail(({"bruecke"}),BS("Die Bruecke sieht lustig aus. Sie fuehrt hoch "+
  "ueber den gruenen See hinweg und sieht fuerchterlich rudimentaer aus, "+
  "als waere sie sehr schnell zusammengezimmert. Merkwuerdig ist das alles."));
  AddDetail(({"ufer"}),BS("Hurraaaaaaa! Der See hat ein Ufer!"));
  AddDetail(({"rand"}),BS("Mit 'Rand' sind hier wohl eher die Waende "+
  "der Hoehle gemeint. Hehe. Etwas literarische Freiheit, Du verstehst."));
  AddDetail(({"freiheit","literarische freiheit"}),BS("Literarische Freiheit? "+
  "PAH! Meine Idee, das Morgengrauen durch eine Magnetschwebebahn zu verbin"+
  "den wurde kommentarlos abgeschmettert! IGNORANTEN!"));
  AddDetail(({"idee","magnetschwebebahn"}),BS("JAWOHL! Diese Idee wurde "+
  "abgeschmettert! PAH!"));
  AddDetail(({"ignoranten","doofies"}),BS("GENAU! IGNORANTEN! DOOFIES!"));
  AddDetail(({"wald"}),BS("Im Nordosten siehst Du in der Dunkelheit einen "+
  "grossen, schwarzen Wald. Du kannst nicht viel von ihm erkennen, ausser "+
  "seiner Groesse, und die ist um ein vielfaches Groesser als das Waldstueck "+
  "im Suedosten."));
  AddDetail(({"groesse"}),BS("Na das ist aber ein GROSSER Wald."));
  AddDetail(({"regen"}),BS("Das Tauwasser troepfelt leise auf Dich herab."));
  AddDetail(({"tauwasser","wasser"}),
  BS("Das Eis der Hoehlendecke taut langsam und "+
  "faellt als leichter Regen auf Dich herab. Das Wasser ist eiskalt."));
  AddDetail(({"luft"}),BS("Die Luft stinkt nach Saeure."));
  AddDetail(({"saeure"}),BS("Die kannst Du nur riechen."));
  AddDetail(({"kaelte"}),BS("*Brrrrrrrrrr*"));
  AddDetail(({"boden"}),BS("Der Boden besteht aus Eis mit einer duennen "+
  "Schneeschicht darueber. Gluecklicherweise ist der Weg, auf dem Du Dich "+
  "befindest, mit Kies gestreut, was den ganzen Ausflug um einiges sicherer "+
  "macht."));
  AddDetail(({"ausflug"}),BS("OK, es ist etwas mehr als ein simpler Ausflug "+
  "hier..."));
  AddDetail(({"kies"}),BS("Das ist guter Kies. Wenn auch reichlich uninter"+
  "essant."));
  AddDetail(({"sicht"}),BS("Du kannst wirklich nicht allzuweit sehen."));
  
  AddDetail(({"hoehle"}),BS("Du befindest Dich wirklich in einer Hoehle "+
  "mitten in einem schwarzen Eisberg! Gewaltige, erstarrte Wassermassen "+
  "umgeben Dich von allen Seiten. Ein mulmiges Gefuehl ist das, wenn "+
  "staendig Schmelzwasser von der Decke tropft und man sich fragen muss, "+
  "wie lange diese gewaltige Decke ueber Dir wohl nach halten wird."));
  AddDetail(({"eisberg","schwarzer eisberg"}),BS("Du befindest Dich in einem "+
  "gewaltigen Eisberg aus schwarzem Eis! Nun, wenigstens die aeussersten "+
  "Schichten bestehen aus schwarzem Eis. In dieser Hoehle siehst Du nur "+
  "weisses Eis mit einem Stich ins Gruene."));
  AddDetail(({"schwarzes eis"}),BS("WAAAAAAAAAH! Schwarzes EIS!!! Ups, "+
  "garkeins hier..."));
  AddDetail(({"eis","weisses eis"}),BS("Das Eis in dieser Hoehle ist von "+
  "weisser Farbe und sieht voellig unkritisch aus fuer Dich. Obwohl da noch "+
  "ein leichter Gruenstich im Eis ist, was Dich etwas vorsichtig stimmt."));
  AddDetail(({"farbe"}),BS("Die Farbe ist weiss mit einem Stich ins gruenliche."));
  AddDetail(({"stich","gruenstich"}),BS("Wow, dieses Eis hat einen Gruenstich "+
  "in sich drinn!"));
  AddDetail(({"gruen"}),BS("GRUEN! BSSSSSSSS! BSSSSSSSSSSSSSSSSSS!"));
  AddDetail(({"wassermassen"}),BS("Du willst garnicht wissen, wieviele "+
  "Tonnen und Abertonnen Wasser Dich hier umgeben, bereit, sofort auf Dich "+
  "herabzustuerzen...."));
  AddDetail(({"tonne","tonnen"}),BS("Du weisst, was Tonnen sind."));
  AddDetail(({"wasser"}),BS("Es ist uebrigens gefrorenes Wasser, aber das "+
  "weisst Du bestimmt schon."));
  AddDetail(({"gefuehl"}),BS("Es ist hier bitterkalt, ausserdem ist Dir "+
  "sehr mulmig in dieser merkwuerdigen Hoehle."));
  AddDetail(({"schichten","aeussere schichten","innere schichten"}),
  BS("Dieser Eisberg besteht aus verschiedenen Schichten von Eis. Waehrend "+
  "die aeusseren Schichten aus schwarzem, boesartigem und absolut merkwuer"+
  "digem Eis bestehen, bestehen die inneren Schichten aus relativ normalem, "+
  "weissen Eis."));
  AddDetail(({"decke"}),BS("Die Decke dieser Hoehle ist so weit entfernt, "+
  "dass Du sie nur als ferne, leicht leuchtende Flaeche ausmachen kannst. "+
  "Irgend etwas scheint durch dieses Eis, doch es kann kein Tageslicht sein. "+
  "Du fragst Dich wirklich, was das ist."));
  AddDetail(({"flaeche"}),BS("Die Decke erscheint Dir nur als leicht leuch"+
  "tende Flaeche. Allerdings kannst Du in diesem Halbdunkel hier auch nicht "+
  "wirklich viel sehen."));
  AddDetail(({"licht","halbdunkel","dunkelheit"}),BS("Alles Licht in dieser Hoehle "+
  "stammt von der Decke, und das ist nicht wirklich viel."));
  AddDetail(({"viel"}),BS("Jaaaaaaa, klar."));
  AddDetail(({"tageslicht"}),BS("Hier unten kann es kein Tageslicht mehr geben. "+
  "Es sollte hier unten tiefste Nacht sein. Was geht hier nur vor?"));
  AddDetail(({"nacht"}),BS("Ist es Nacht? Ist es Tag? Im Morgengrauen ist man "+
  "da nie so sicher."));
  AddDetail(({"morgengrauen"}),BS("Es ist ueberall um Dich herum!"));
  AddDetail(({"waldstueck"}),BS("Im Suedosten fuehrt der Weg in ein kleines "+
  "Waldstueck, welches sich quasi an die Hoehlenwand schmiegt. Dort scheint "+
  "ein Ausgang aus der Hoehle zu sein."));
  AddDetail(({"ausgang"}),BS("Na, das hoffst Du zumindest."));
  AddDetail(({"hoehlenwand","wand","waende"}),BS("Ja, diese Hoehle hat Waende. "+
  "Allerdings sind sie alle viel zu weit entfernt, um sie genau betrachten zu "+
  "koennen."));
  AddDetail(({"gelaende"}),BS("Flach isses hier :)"));
  AddDetail(({"weg"}),BS("Es ist ein unscheinbarer Kiesweg, und er fuehrt "+
  "von Suedosten nach Norden."));
  AddDetail(({"schnee","schneeschicht"}),BS("Der Boden hier ist mit einer "+
  "duennen, schlammigen Schneeschicht bedeckt, welche jedes Abweichen vom "+
  "Weg unweigerlich in eine gefaehrliche Rutschpartie verwandelt."));
  AddDetail(({"entfernung","entfernungen"}),BS("In dieser Dunkelheit kann "+
  "man Entfernungen nicht richtig einschaetzen."));
  AddDetail(({"ecke","ecken"}),BS("Diese Burg hat annaehernd quadratische "+
  "Formen und smit vier Ecken. (Natuerlich hat sie um einiges mehr Ecken, "+
  "aber lasst uns mal abstrakt bleiben...)"));
  AddDetail(({"mitte"}),BS("In der Mitte des Sees befindet sich die Burg."));
  
  AddSmells(SENSE_DEFAULT,BS("Baeh! Es stinkt hier nach Saeure."));
  AddSmells(({"saeure"}),BS("Ja, OK. Ich moechte mich hier allen Vorwuerfen "+
  "stellen, dass etwas nicht 'nach Saeure' riecht, sondern  nach Schwefel- "+
  "Salz-, meinetwegen Buttersaeure (baeeh). Ihr habt absolut recht. Aber "+
  "wenn ich da jetzt hinschreiben wuerde: Es riecht nach einem Gemisch aus "+
  "Schwefel- und Salzsaeure, in das irgend jemand alten Kaese getunkt hat, "+
  "um den Geruch WIRKLICH eklig zu machen, so _passt_ das einfach nicht "+
  "richtig in die Atmosphaere. Also sei so nett und akzeptiere die Beschrei"+
  "bungen wie sie sind, ok?"));
  
  AddSounds(SENSE_DEFAULT,BS("Ein leichter Wind zieht leise heulend ueber "+
  "das Gelaende."));
  AddSounds(({"wind"}),BS("Huuuh Huuuuuh!"));
  
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl2w3"));
  AddExit("norden",CHAOS_GILDEN_ROOM("cl2w7"));
}
