#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS(x) break_string(x,78)

inherit CHAOS_GILDEN_ROOM("cl2w_std");


create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Am Rande einer gewaltigen Hoehle");
  SetProp(P_INT_LONG,break_string
  ("\bDu stehst am Rande eines steilen Abhangs. Hoch ueber Dir erhebt sich "+
  "das Gewoelbe dieser unglaublichen Hoehle. Sie erstreckt sich derart weit "+
  "vor- und unter Dir, dass sich ihre Grenzen in der Dunkelheit verlieren. "+
  "Es ist, als befaendest Du Dich in einer gewaltigen ... Blase im Eis. "+
  "Nahezu glatt und von perfekter ovaler Form praesentiert sich Dir dieses "+
  "... Monument.\n"+
  "Nachdem Du die schwarzen Eisschichten hinter Dir gelassen hast, praesent"+
  "ieren sich die Waende der Hoehle nun in weisser, leicht gruenlicher "+
  "Farbe. Zu deinen Fuessen eroeffnet sich Dir ein bemerkenswertes Panorama. "+
  "Das Licht scheint diffus und unerklaerlich durch die Eisschichten herab "+
  "und taucht die Hoehle in ein unheimliches Halbdunkel.\n"+
  "Es ist kalt hier, kalt und nass. Ein merkwuerdiger Wind fegt durch die "+
  "Hoehle und fegt Dich fast zurueck zum Schacht. Vor Dir beginnt der "+
  "schmale Pfad, welcher steil abwaerts hinab in die Hoehle fuehrt. Etwas h"+
  "inter Dir fuehrt der Schacht, durch den Du Dich einst abgeseilt hast, "+
  "in die oberen, schwarzen Eisschichten.",78,0,1));
  
  AddDetail(({"boden"}),BS("Der Boden besteht aus Eis von weisser, leicht "+
  "gruenlicher Farbe. Es ist von zahlreichen Fuessen zertrampelt, und diese "+
  "Spur stellt einen kleinen Pfad dar. Dieser Pfad wiederum endet etwas hin"+
  "ter Dir unter dem Schacht oder fuehrt nach Unten den Abhang hinab."));
  AddDetail(({"eis"}),BS("Es ist einfach gefrorenes Wasser. Kein Geheimnis "+
  "dabei."));
  AddDetail(({"wasser"}),BS("Das Wasser troepfelt von der Decke der Hoehle. "+
  "Immerhin befindest Du Dich in einem Eisberg."));
  AddDetail(({"geheimnis"}),BS("Huuuh Huuuuh, Geheimnisse! Huuh Huuuh!"));
  AddDetail(({"eisberg"}),BS("Du befindest Dich in einem Eisberg. Einem "+
  "gewaltigen, unglaublichen, absolut wahnsinnigem Eisberg, welcher teil"+
  "weise aus schwarzem Eis besteht. Um Dich herum tuermen sich Millionen "+
  "und Abermillionen Gallonen Wasser auf und warten nur darauf, auf Dich "+
  "herabzustuerzen."));
  AddDetail(({"millionen","gallonen","masseinheiten"}),
  BS("Du kennst diese Masseinheiten."));
  AddDetail(({"hoehle"}),BS("Du befindest Dich in einer Hoehle. In einer "+
  "gewaltigen Blase mitten in einem Eisberg. Deine Beine schlottern ein "+
  "wenig."));
  AddDetail(({"blase","luftblase"}),
  BS("Du weisst nicht genau, was das fuer eine "+
  "Blase hier darstellt, aber es sieht auf jeden Fall aus wie eine Luftblase "+
  "im Eis..."));
  AddDetail(({"fall"}),BS("Ich loes den Fall auf jeden Fall."));
  AddDetail(({"schwarzes eis"}),BS("Hier ist kein schwarzes Eis. Das befindet "+
  "sich in den oberen Schichten. Du erreichst es, wenn Du den Schacht hinauf"+
  "kommst."));
  AddDetail(({"schichten","obere schichten","untere schichten"}),
  BS("Die oberen Schichten dieses Eisbergs bestehen aus merkwuerdigem, "+
  "schwarzen Eis, waehrend die tieferen Schichten aus ebenso merkwuerdigem, "+
  "aber immerhin weissem, Eis bestehen."));
  AddDetail(({"weisses Eis"}),BS("Du bist davon umgeben!"));
  AddDetail(({"decke"}),BS("Sie befindet sich so weit ueber Dir, dass Du "+
  "sie garnicht richtig erkennen kannst. Von ihr herab scheint ein diffuses "+
  "Licht. Wie alles um Dich herum besteht auch die Decke aus Eis."));
  AddDetail(({"farbe"}),BS("Das Eis hat eine weisse, aber leicht gruenliche "+
  "Farbe. Das gruen kommt Dir irgendwie merkwuerdig vor."));
  AddDetail(({"gruen"}),BS("Merkwuerdig, dieses Gruen. Warum nur?"));
  AddDetail(({"fuesse"}),BS("Yo, Du hast sogar 2 davon! Gratulation!"));
  AddDetail(({"spur"}),BS("Pruefend betrachtest Du die Spur. Hier sind "+
  "schon viele Leute hergegangen. Mit Stiefeln. .... Mehr kannst Du momentan "+
  "nicht daraus lesen. Recht peinliche Darbietung, aber naja."));
  AddDetail(({"stiefel"}),BS("Du weisst, was Stiefel sind. Vertrau mir."));
  AddDetail(({"darbietung"}),BS("Na, das muss aber noch besser werden."));
  AddDetail(({"pfad"}),BS("Der Pfad (wenn man ihn denn Pfad nennen darf) "+
  "endet etwas hinter Dir unter einem Schacht und fuehrt den Abhang hinab "+
  "in die Tiefen des Tals, welches sich vor Dir ausbreitet."));
  
  AddDetail(({"panorama"}),break_string(
  "\bDieses Panorama mag nicht schoen sein, kein "+
  "Zeugnis fuer die Schoenheit der Natur, aber es ist auf jeden Fall beein"+
  "druckend und laesst Deinen Atem stocken.\n"+
  "Vor Dir breitet sich ein unvergleichliches Tal aus. Es misst sicherlich "+
  "einige Kilometer im Durchmesser und faellt leicht zu seiner Talsohle hin "+
  "ab, welche sich in der Mitte dieser leicht ovalen Hoehle befindet.\n"+
  "In dieser Sohle befindet sich ein grosser See von giftgruener Farbe. "+
  "Leichte gruene Schwaden sind ueber dem See zu sehen. Und in der Mitte des "+
  "Sees steht eine schwarze Burg. Sie sieht von hier aus winzig aus, mit "+
  "4 Tuermen und einer ziemlich dicken Burgmauer. Die Burg ist ueber eine "+
  "Art Bruecke mit dem Ufer des Sees verbunden.\n"+
  "Dieser Pfad scheint direkt hinab zur Burg zu fuehren. Er windet sich "+
  "den Abhang hinab und durch eine kleine Ansammlung seltsam schwarz aus"+
  "sehender, merkwuerdiger Baeume, bis er schliesslich den See erreicht. "+
  "Im Osten des Tals befindet sich eine weitere Ansammlung dieser Baeume, "+
  "welche dort einen ganzen Wald zu bilden scheinen.\n"+
  "Ueberall in der Hoehle haben sich kleinere dieser gruenen Seen gebildet, "+
  "ueber welchen leichte, gruene Schlieren schweben.",78,0,1));
  AddDetail(({"abhang"}),BS("Der Abhang ist an dieser Stelle sehr steil, "+
  "wird dann aber relativ schnell flacher. Er besteht aus nassem Schnee "+
  "und Eis, was die ganze Sache etwas interessanter macht. Da muss man "+
  "verflucht aufpassen, um sich nicht alles zu brechen..."));
  AddDetail(({"schnee","schneeschicht"}),
  BS("Eine duenne, schlammige Schneeschicht bedeckt "+
  "den Boden und macht ihn zu einem gefaehrlichen Pflaster."));
  AddDetail(({"pflaster"}),BS("Das ist natuerlich sowieso ein gefaehrliches "+
  "Pflaster hier..."));
  AddDetail(({"sache"}),BS("Die Sache halt :)"));
  AddDetail(({"zeugnis","schoenheit","natur"}),BS("Wenn Du ein Zeugnis fuer "+
  "die Schoenheit der Natur suchst, geh ins Gebirge."));
  AddDetail(({"gebirge"}),BS("Das Gebirge ist doch schick."));
  AddDetail(({"atem"}),BS("Er stockt. Du hustest."));
  AddDetail(({"tal"}),BS("Das Tal unter Dir ist atemberaubend. Allein die "+
  "Tatsache, dass so etwas innherhalb eines Eisbergs existiert ist ja schon "+
  "der helle Wahnsinn, aber dieses Tal hat noch andere Ueberraschungen zu "+
  "bieten. Denn an dieser kalten, nassen Staette, hat jemand eine Burg "+
  "errichtet, eine Burg in einem gruenen See. Ausserdem wachsen hier "+
  "Baeume, oder hatten zumindest bis vor einiger Zeit. Du fragst Dich, wie "+
  "dies alles wohl entstanden ist."));
  AddDetail(({"tatsachen"}),BS("Genau. Lasst uns hier von den Tatsachen "+
  "sprechen."));
  AddDetail(({"wahnsinn"}),BS("Du gibst ein wahnsinniges Kichern von Dir "+
  "und wirfst Dich in den Schnee, um ein bisschen zu strampeln."));
  AddDetail(({"kichern"}),BS("Hihihihihihiii."));
  AddDetail(({"ueberraschungen"}),BS("Davon gibt es hier jede Menge, vertrau "+
  "mir..."));
  AddDetail(({"baeume"}),BS("Die Baeume hier sehen schwarz und verkrueppelt "+
  "aus. Du muesstest aber naeher an sie herankommen, um naehere Angaben "+
  "machen zu koennen."));
  AddDetail(({"angaben"}),BS("Die Angaben sind bis jetzt noch recht wage..."));
  AddDetail(({"menge"}),BS("Oh, wirklich jede Menge. Ehrlich."));
  AddDetail(({"staette"}),BS("Dieses Tal ist wirklich kalt, nass und unange"+
  "nehm."));
  AddDetail(({"zeit"}),BS("Oha. So spaet schon!"));
  AddDetail(({"burg"}),BS("Die Burg sieht von hier oben sehr klein aus, dennoch "+
  "kann man jedoch einiges erkennen. Die Burg ist schwarz, absolut schwarz. "+
  "Sie wurde aus grossen Felsen zusammengesetzt, denn man kann diese von "+
  "hier oben noch erkennen. Sie hat vier Ecktuerme und ein grosses Tor. "+
  "Ihre Burgmauer ist voellig ueberdimensioniert dick fuer eine Burg dieser "+
  "Groesse. Merkwuerdig. Eine anscheinend kaum befestigte Bruecke fuehrt "+
  "ueber den gruenen See zum Ufer."));
  AddDetail(({"felsen"}),BS("Diese Felsen sind gewaltig! Ueber welche Ent"+
  "fernungen muss man diese Dinger transportiert haben, um sie in diesen "+
  "Eisberg zu transportieren? Ausser der Tatsache, dass sie so gewaltig sind, "+
  "sind sie absolut schwarz."));
  AddDetail(({"entfernungen"}),BS("Hmmm. Wo gibts solche Felsen ueberhaupt? "+
  "Wahnsinn, das ist absoluter Wahnsinn!"));
  AddDetail(({"tatsache","tatsachen"}),
  BS("OK, halten wir uns an die Tatsachen. :)"));
  AddDetail(({"schwarz"}),BS("Schwarz."));
  AddDetail(({"ecktuerme"}),BS("Du kannst kaum etwas an ihnen erkennen. "+
  "Im Grunde garnichts ausser der Tatsache, dass es vier davon gibt."));
  AddDetail(({"tor"}),BS("Das Tor ist anscheinend mit zwei grossen Torflue"+
  "geln versehen, welche nach aussen oeffnen."));
  AddDetail(({"fluegel","torfluegel"}),BS("Du kannst von hier oben kaum "+
  "etwas an ihnen erkennen. Du bist wirklich noch zu weit entfernt."));
  AddDetail(({"dinger"}),BS("Diese Dinger sind Felsen!"));
  AddDetail(({"bruecke"}),BS("Diese Bruecke scheint eine Art Haengebruecke "+
  "zu sein. Naeheres kannst Du von hier oben aber nicht erkennen."));
  AddDetail(({"ufer"}),BS("Zu diesem Ufer scheint der Pfad zu fuehren, auf "+
  "dem Du Dich gerade befindest."));
  AddDetail(({"see","seen"}),BS("Die Seen dieses Tales sind saemtlichst "+
  "gruen. Ausserdem schwebt ein leichter gruener Schleier ueber ihnen. "+
  "Was auch in diesen Seen ist, es ist kein Wasser."));
  AddDetail(({"schleier"}),BS("Er ist gruen und scheint durch den Wind in "+
  "der Hoehle zu verfliegen."));
  AddDetail(({"wind"}),BS("Der Wind blaesst ganz schoen hier oben und "+
  "macht den Abstieg sicherlich nicht einfacher. Du fragst Dich, wo er "+
  "wohl herkommen mag."));
  AddDetail(({"burgmauer"}),BS("Die Burgmauer scheint wirklich ziemlich "+
  "dick zu sein. Katapulte haben hier wohl kaum eine Chance, ein Loch "+
  "zu verursachen."));
  AddDetail(({"katapulte"}),BS("Hier siehst Du keine."));
  
  AddDetail(({"rand"}),BS("Dies ist der Rand eines Abhangs. Hier gehts "+
  "runter."));
  AddDetail(({"stelle"}),BS("Du befindest Dich am Rande eines Abhangs."));
  AddDetail(({"tiefen"}),BS("Bis zur Talsohle geht es hier ziemlich tief "+
  "abwaerts."));
  AddDetail(({"unten"}),BS("Da geht es _abwaerts_ ..."));
  AddDetail(({"gewoelbe"}),BS("Das Gewoelbe (also, aehm, die Decke) "+
  "befindet sich hoch ueber Dir."));
  AddDetail(({"beine"}),BS("Auf denen stehst Du!"));
  AddDetail(({"grenzen"}),BS("Die Grenzen dieser Hoehle verlieren sich im "+
  "grauen Halbdunkel. Wie gross mag diese Hoehle wirklich sein?"));
  AddDetail(({"dunkelheit","halbdunkel"}),BS("Durch die Eisschichten "+
  "des Gewoelbes ueber Dir scheint schwach etwas Licht (die Sonne?) auf "+
  "Dich herab. Dieses reicht jedoch nicht annaehhernd aus, dieses Tal zu "+
  "erhellen, weshalb Du Dich nun in einem duesteren Halbdunkel befindest."));
  AddDetail(({"licht","sonne","sonnenlicht"}),
  BS("Was fuer ein Licht strahlt hier "+
  "herein? Ist es Sonnenlicht? Offensichtlich nicht, Du befindest Dich zu "+
  "tief im Berg, als dass hier noch Sonnenlicht scheinen koennte. Ganz "+
  "davon abgesehen bestehen die oberen Eisschichten aus schwarzem Eis, "+
  "wodurch das Sonnenlicht direkt abgeblockt werden wuerde. Irgend etwas "+
  "merkwuerdiges geht vor hier. Du fragst Dich nur, .... was?"));
  AddDetail(({"merkwuerdiges"}),BS("Huuuuuh Huuuuuuuuh"));
  AddDetail(({"eisschichten","schichten"}),
  BS("Ein Eisberg besteht aus jeder Menge "+
  "Schichten. Schichten aus Eis. Eisschichten."));
  AddDetail(({"form"}),BS("Diese Blase hat eine ovale Form und sieht "+
  "so aehnlich aus wie ein Ei."));
  AddDetail(({"ei"}),BS("Das war jetzt nur mal so ein Beispiel."));
  AddDetail(({"monument"}),BS("Monument ist ein passender Ausdruck fuer "+
  "... das hier."));
  AddDetail(({"ausdruck"}),BS("Er hiess 'Monument'."));
  
  AddDetail(({"waende","wand"}),BS("Die Waende dieser Hoehle bestehen aus "+
  "Eis und sind dementsprechend kalt. Ihre Farbe ist fast weiss, mit einem "+
  "Stich ins gruenliche."));
  AddDetail(({"abstieg"}),BS("Huuuh, der wird sicher nicht einfach."));
  AddDetail(({"ohren"}),BS("Sie werden langsam kalt."));
  AddDetail(({"schacht"}),BS("Er fuehrt nach oben in die Finsternis der "+
  "schwarzen Eisschichten. Merkwuerdigerweise kannst Du dort oben jedoch "+
  "einen Eisvorsprung erkennen. Welche Magie mag hier nur wirken?"));
  AddDetail(({"magie"}),BS("Es ist eine Art Magie...  (c) Queen 1986"));
  AddDetail(({"queen"}),BS("Das ist ne Baeeeeend, Du DUSSEL!"));
  AddDetail(({"dussel"}),BS("Wenn Du nicht mal Queen kennst...."));
  AddDetail(({"baend"}),BS("Die Baeeeend, Elwood! Die Baeeeeeend!"));
  AddDetail(({"elwood"}),BS("Erinnerst Du Dich nicht? Dann ist es mir egal."));
  AddDetail(({"eisvorsprung","vorsprung"}),BS("Wenn Du ein Seil haettest, "+
  "koenntest Du es nach dem Vorsprung werfen und so den Schacht "+
  "hinaufklettern."));
  AddDetail(({"seil"}),BS("Na, hast Du eins?"));
  
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht hier nach abgestandener Luft. "+
  "Dennoch ist der Geruch stechend und riecht irgendwie nach ... Saeure?"));
  AddSmells("saeure",BS("Es riecht hier ganz eindeutig nach Saeure! Ploetz"+
  "lich hast Du eine ziemlich gute Idee, was dort unten in diesen Seen auf "+
  "Dich wartet."));
  AddSounds(SENSE_DEFAULT,BS("Der Wind pfeift Dir um die Ohern."));
  
  AddSpecialExit("unten","go_down");
  AddCmd(({"wirf","werfe"}),"throw");
}


// Hier kommt was fieses, ist schliesslich ein fieser Abstieg..
int go_down()
{
  tell_room(CHAOS_GILDEN_ROOM("cl2w4"),this_player()->Name(WER)+" kommt "+
  "von Suedosten auf dem Pfad heran.\n");
  tell_room(CHAOS_GILDEN_ROOM("cl2w5"),this_player()->Name(WER)+" kommt "+
  "von Suedosten auf dem Pfad heran.\n");
  
  this_player()->move(CHAOS_GILDEN_ROOM("cl2w2"),M_GO,"den Berg hinab",
                      "klettert","kommt herabgeklettert");
  return 1;
}


//VORERST, bis andere Raeume fertig sind.
init()
{
  ::init();
  (CHAOS_GILDEN_ROOM("cl2w_mas"))->add(this_player());
}

int throw(string was) {
  object seil;
  if (was != "seil nach vorsprung" && was !="seil nach eisvorsprung")
  {
    if (was[0..3] == "seil") write("Versuchs mit 'wirf seil nach eisvorsprung'.\n");
    return 0;
  }
  if(!objectp(seil=present("seil", this_player())))
  {
    write("Wie willst Du das bewerkstelligen ohne Seil???\n");
    return 1;
  }
  if(file_name(seil)[0..27]=="/players/anthea/obj/seherobj" ||
     file_name(seil)[0..11]=="/p/zauberer/")
  {
      write( BS("Dieses Seil ist zu instabil, als dass Du daran "+
                "heraufklettern koenntest!!!") );
      return 1;
  }
  if (random(30)>=this_player()->QueryAttribute(A_DEX))
  {
     write("Mist! Daneben geworfen!\n");
     say(this_player()->Name(WER)+" wirft sein Seil in die Hoehe. Wie lustig.\n",
        this_player());
     return 1;
  }
  write("Du triffst mit deinem Seil den Felsvorsprung.\nDu kletterst hinauf.\n");
  say(this_player()->Name(WER)+" wirft sein Seil in den Schacht hinauf. "+
      "Und es haelt!\n",this_player());
  this_player()->move(CHAOS_GILDEN_ROOM("cl1w5"),M_GO,"den Schacht hinauf",
                      "klettert","kommt heraufgeklettert");
  return 1;
}