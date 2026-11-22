#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2bu_std");
#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu8"));
  SetProp(P_LIGHT,-1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In der chaotischen Burg");
  SetProp(P_INT_LONG,break_string("\bEs ist fuerchterlich dunkel hier, und das "+
  "nicht nur, weil es in dieser verdammten Burg immer so verflucht "+
  "dunkel ist. Dies ist auch eine hoellisch dunkle Ecke der Burg. "+
  "Und im Nordosten wird es noch schlimmer!\n"+
  "Nichtsdestotrotz kannst Du zwei Gebaeude erkennen, eines noerdlich von "+
  "Dir und eines oestlich von Dir. Beide wurden anscheinend aus den gleichen "+
  "pechschwarzen Steinen gebaut wie alle anderen auch. Das Noerdliche besitzt "+
  "eine dieser fuerchterlich makellosen schwarzen Tueren. Die Daemonen, welche "+
  "diese Burg gebaut haben, hatten vielleicht Kraft und Bosheit gehabt, aber "+
  "keine Kreativitaet im Bezug auf das Baugewerbe.\n"+
  "Das einzige bisschen Licht stammt von den duester leuchtenden Symbolen "+
  "ueber der noerdlichen Tuer und dem oestlichen Durchgang.",78,0,1));
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  
  AddDetail(({"boden"}),BS("Der Boden unter Dir besteht aus "+
  "schwarzen, pechschwarzen Pflastersteinen. Hmmmmmmmm, denkst Du "+
  "Dir. Sowas wuerde sich bestimmt gut in meinem Seherhaus machen, "+
  "da sieht man den Staub nicht sofort!"));
  AddDetail(({"pflastersteine"}),BS("Diese Pflastersteine sind im wirklich "+
  "SCHWARZ! PechSCHWARZ! Total, absolut super abgedunkelt schwarz. Und das "+
  "ist gut so, denn so sieht man den Staub und Dreck hier nicht so schnell. "+
  "Und Putzfrauen hat diese Burg schon seit Jahren nicht mehr gesehen."));
  AddDetail(({"staub","dreck"}),BS("Du bist Dir ziemlich sicher, dass diese "+
  "Burg ziemlich staubig und absolut dreckig ist. Der einzige Knackpunkt "+
  "dabei ist, dass niemand das bemerken wird, denn alles hier ist absolut "+
  "kohlraben-SCHWARZ!"));
  AddDetail(({"knackpunkt"}),BS("*Knack*"));
  AddDetail(({"niemand"}),BS("Niemand sagt: Doch! Ich habs gesehen! Ich h"+
  "abs gesehen!"));
  AddDetail(({"putzfrau","putzfrauen"}),BS("Die letzte Putzfrau hat Wuqour "+
  "noch etliche Jahre unter wirklich entsetzlichen Schmerzen am Leben erhal"+
  "ten, bevor sie gestorben ist. Sie hatte eines seiner Pentagramme "+
  "verwischt, was wieder einmal zeigt, wie schrecklich gefaehrlich der "+
  "Job einer Putzfrau ist."));
  AddDetail(({"job"}),BS("Der Job einer Putzfrau ist absolut wahnwitzig "+
  "gefaehrlich, besonders in dieser Burg! Nun, eigentlich nur in dieser "+
  "Burg. Ansonsten ist er eigentlich ganz ok."));
  AddDetail(({"seherhaus"}),BS("Ein Seherhaus zu haben hat einige Vorteile. "+
  "Ausserdem will man schliesslich auch ein bisschen repraesentieren, wenn "+
  "mans bis zum Seher geschafft hat."));
  AddDetail(({"vorteile"}),BS("Seherhaeuser haben unuebersehbare Vorteile. "+
  "Da sind zum Beispiel ihre Eigenschaften als vorgezogene Metzelbasen!"));
  AddDetail(({"eigenschaft","eigenschaften","metzelbasen"}),BS("Nichts "+
  "eignet sich besser, um Ausruestung und Beute zu verstauen!"));
  AddDetail(({"nichts"}),BS("Hehe, druecke diesen Knopf und es wird Nichts "+
  "boeses passieren!"));
  AddDetail(({"ausruestung","beute"}),BS("Seherhaeuser sind perfekt geeig"+
  "net, um Ausruestung und Beute zu verstauen."));
  AddDetail(({"wand","waende"}),BS("Also. Es gibt hier keine richtigen Waende, "+
  "denn Du befindest Dich in einem Innenhof! Allerdings siehst Du von hier "+
  "aus zwei Mauern von Haeusern. Eines befindet sich noerdlich von Dir, "+
  "eines oestlich."));
  AddDetail(({"innenhof"}),BS("Dies ist der Innenhof der chaotischen Burg!"));
  AddDetail(({"burg"}),BS("Dies ist die chaotische Burg blah blah Chaosgilde "+
  "blah Chaoten blah blah. Du weisst Bescheid."));
  AddDetail(({"chaos","chaosgilde"}),BS("Blah Chaosgilde blah blah super "+
  "gut, blah herrscht ueber das Chaos blah."));
  AddDetail(({"blah"}),BS("Blah Blah."));
  AddDetail(({"chaoten"}),BS("Chaoten blah Chaosgilde blah blah."));
  AddDetail(({"blah blah"}),BS("Blah blah blah."));
  AddDetail(({"blah blah blah"}),BS("Bli blo blub."));
  AddDetail(({"bli blo blub"}),BS("Blibbu blobbu blubbu."));
  AddDetail(({"blibbu blobbu blubbu"}),BS("Bloing Bling Blang."));
  AddDetail(({"bloing bling blang"}),BS("Blobberbobberblamb."));
  AddSpecialDetail(({"blobberbobberblamb"}),"loggen_blob");
  AddDetail(({"hoehle","eisberg"}),BS("Blah Blah Hoehle in Eisberg blah "+
  "blah schwarz blah."));
  AddDetail(({"decke"}),BS("Es ist zu verdammt finster, um diese Decke "+
  "zu erkennen. Naja, aber, immerhin befindest Du Dich im Freien, deshalb "+
  "ist das nicht ganz so bedrohlich."));
  AddDetail(({"freies"}),BS("Du befindest Dich wirklich im Freien."));
  AddDetail(({"mauer","mauern","hauswand","hauswaende"}),
  BS("Es gibt zwei Mauern, also Hauswaende hier. Eine ist noerdlich, eine "+
  "oestlich von Dir. Du kannst sie aber auch mit hauswand 1, hauswand 2 "+
  "ansprechen."));
  AddDetail(({"noerdliche mauer","noerdliche hauswand","mauer 1","hauswand 1"}),
  BS("Das Gebaeude vor Dir ist recht klein, so sieht es jedenfalls von vorne "+
  "aus. Es wurde mit Backstein gemauert und ist so hoch, dass man sein Ende "+
  "in dieser Dunkelheit nicht ausmachen kann. Naja, andererseits war das bei "+
  "fast jedem Gebaeude in dieser verfluchten Burg so. Das Gebaeude hat eine "+
  "grosse Tuer, welche ebenso makellos schwarz ist wie alle anderen Tueren "+
  "in dieser Burg. Ueber der Tuer leuchtet ein mystisches Symbol."));
  AddDetail(({"backstein","backsteine"}),BS("Diese Backsteine sind genauso "+
  "schwarz wie die Pflastersteine. Nun, dann sieht man den Dreck an den "+
  "Waenden bestimmt nicht so schnell."));
  AddDetail(({"ende"}),BS("Alles hat ein Ende nur die Wurst hat zwei,..."));
  AddDetail(({"wurst"}),BS("Jawoll mein Schatz, es ist vorbei..."));
  AddDetail(({"schatz"}),BS("Doch Du musst nicht traurig sein, Du bleibst ja "+
  "nicht lang alleeeeeinne!"));
  AddDetail(({"gebaeude"}),BS("In dieser Burg gibt es jede Menge Gebaeude!"));
  AddDetail(({"menge"}),BS("Totaaaal viele Gebaeude ey!"));
  AddDetail(({"symbol","symbole"}),BS("Es gibt da ja mehrere hier. Nennen wir "+
  "sie einfach Symbol 1 und Symbol 2..."));
  AddDetail(({"symbol 1","noerdliches symbol"}),
  "Das noerdliche Symbol sieht folgendermassen aus:\n\n"+
  "                             \n"+
  "  \\   /    \\   /     \\   /   \n"+
  "   \\ /      \\ /       \\ /    \n"+
  "    X        X         X     \n"+
  "   / \\      / \\       / \\    \n"+
  "  /   \\    /   \\     /   \\   \n"+
  "                             \n");
  AddDetail(({"oestliche mauer","oestliche hauswand","mauer 2","hauswand 2"}),
  BS("Hoho, oestlich von Dir befindet sich noch ein Gebaeude! Es ist ebenso "+
  "schwarz und unheimlich wie das noerdliche, besitzt jedoch keine Tuer, son"+
  "dern einen dunklen Durchgang, welcher in das Innere des Hauses fuehrt. "+
  "Ueber diesem Durchgang prangt ein weiteres, duester leuchtendes, myst"+
  "isches Symbol. Welch merkwuerdige Burg, in der Du Dich befindest..."));
  AddDetail(({"durchgang"}),BS("Es ist ein schwaaaaaaaarzer, unheimlicher "+
  "Durchgang in das absolut Ungewisse!!! (beziehungsweise in das Innere d"+
  "es oestlichen Gebaeudes)"));
  AddDetail(({"ungewisse","ungewisses","inneres"}),BS("Was sich im "+
  "Innern des oestlichen Gebaeudes befindet, ist absolut ungewiss."));
  AddDetail(({"symbol 2","oestliches symbol"}),BS("Es stellt einen grossen "+
  "Berg Muenzen dar! Na endlich mal etwas positives und Handfestes! Ein "+
  "Grinsen schleicht sich auf deine Zuege!"));
  AddDetail(({"muenzen","berg muenzen"}),BS("Na, in diesesm Gebaeude muessen "+
  "ja wirklich viele Muenzen drinnen sein, wenn es so ein Symbol besitzt!"));
  AddDetail(({"grinsen","zuege"}),BS("Na bitte! Mit einem Grinsen sieht alles "+
  "doch gleich viel froehlicher aus!"));
  AddDetail(({"ecke"}),BS("Dies ist eine der wirklich dunklen Ecken dieser "+
  "Burg. Mann ist das hier dunkel!"));
  AddDetail(({"mann"}),BS("*Huestel* Ich wollte hier natuerlich niemanden "+
  "diskriminieren..."));
  AddDetail(({"steine","stein"}),BS("Meinst Du Backsteine oder "+
  "Pflastersteine?"));
  AddDetail(({"tueren"}),BS("Es gibt nur eine Tuer, und die ist im Norden :)"));
  AddDetail(({"daemonen","daemon"}),BS("Es ist ein offenes Geheimnis, dass "+
  "diese Burg von Daemonen erbaut wurde, ebenso wie diese ganze Hoehle "+
  "durch finstere, chaotische Magie und noch finstere Pakte mit absolut "+
  "finsteren Maechten entstanden ist. Was man sich jedoch nicht vorstellen "+
  "kann ist, _wie_ es konkret vonstatten gegangen sein kann."));
  AddDetail(({"magie","finstere magie","pakt","pakte","maechte","finstere "+
  "maechte","absolut finstere maechte"}),BS("Komm in die Chaosgilde und "+
  "lerne mehr ueber derlei Dinge!"));
  AddDetail(({"dinge"}),BS("Diiiiiiiinnnnnnnngeeeeeeee! *bedrohlich bibbernd*"));
  AddDetail(({"kraft","bosheit"}),BS("Wenn Daemonen etwas besitzten, dann "+
  "ist es Kraft und Bosheit. Ein Daemon definiert sich durch diese beiden "+
  "Eigenschaften."));
  AddDetail(({"eigenschaften"}),BS("Die Eigenschaften sind Kraft und Bosheit."));
  AddDetail(({"kreativitaet","baugewerbe"}),BS("Kreativitaet im Baugewerbe "+
  "kann man von einem Daemon eigentlich auch wirklich nicht verlangen. Dazu "+
  "wurde er einfach nicht geschaffen. Im Grunde war diese Burg fuer die "+
  "Daemonen eine absolute Meisterleistung, welche es vorher noch nie gegeben "+
  "hat."));
  AddDetail(({"grund","meisterleistung"}),BS("Dies war im Grunde wirklich "+
  "eine Meisterleistung. Man muss jedoch immer bedenken, dass die Daemonen "+
  "sowohl unter dem Druck ihres Oberdaemonen standen als auch unter dem "+
  "Einfluss von Wuqour, dem Meister der Rituale. Und Wuqour hat seine Methoden, "+
  "Daemoen zu Hoechstleistungen anzutreiben."));
  AddDetail(({"wuqour","meister","rituale","methoden"}),BS("Wuqour ist der "+
  "Meister der Rituale. Und er ist verflucht genial bei dem, was er tut. "+
  "Seine Methoden wuerden selbst Dich in den Wahnsinn treiben."));
  AddDetail(({"wahnsinn"}),BS("Er lauert hier an jeder Ecke!"));
  AddDetail(({"licht"}),BS("Das einzige Licht hier stammt von den merkwuer"+
  "digen Symbolen an den Hauswaenden, welche duester vor sich ihn leuchten."));
  
  AddExit("nordosten",CHAOS_GILDEN_ROOM("cl2bu9"));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2bu6"));
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl2bu5"));
  AddExit("osten",CHAOS_GILDEN_ROOM("cl2_claden"));
  
  NewDoor("norden",CHAOS_GILDEN_ROOM("cl2_xxx"),({"tuer"}),
  ({D_NAME,"Tuer",
    D_GENDER,2,
    D_SHORT,"In das noerdliche Haus fuehrt eine %se Tuer.",
    D_LONG,"Diese komische Tuer besteht aus dem gleichen, makellosen, "+
    "Material wie\ndie anderen Tueren in dieser Burg auch!\n"+
    "Ueber der Tuer schimmert duester ein mystisches Symbol!\n",
    D_FLAGS, DOOR_CLOSED | DOOR_RESET_CL | DOOR_NEEDKEY
  }));
 
  AddCmd(({"sag","sage"}),"say");
   
}


int say(string was) {
  if (was == "backsteine" || was == "pflastersteine")
    write("DANN UNTERSUCH DAS AUCH GEFAELLIGST!\n");
  
  return 0;
}

string loggen_blob()
{
  write_file(CHAOS_GILDEN_LOG("feuerwehr"),dtime(time())+": "+getuid(this_player())+" untersucht globbob :-).\n");
  return "Du bist ja total bloeeeeeed :-)\n";
}
  