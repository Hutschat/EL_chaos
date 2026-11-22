#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu9"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Westlich des Nichts'");
  SetProp(P_INT_LONG,BS("Die Welt ist schon ein merkwuerdiger Ort. Die "+
  "Chaosgilde mit ihrem schwarzen Eisberg gehoert dzu den merkwuerdigeren "+
  "Orten dieser Welt. Und dieser Raum gehoert zu den merkwuerdigeren "+
  "Raeumen der Chaosgilde. Nach Suedwesten fuehrt ein Gang fort in die "+
  "duestere Ungewissheit, doch im Osten beginnt alles zu wabbern und zu "+
  "verschwimmen und sich in etwas merkwuerdiges, Dunkles zu verformen. "+
  "Wohin es dort wohl geht, du weisst es nicht..."));
  AddDetail(({"welt"}),BS("Die Welt ist ein sehr grosser Ort. Es gibt "+
  "viel, sehr viel sogar, auf ihr zu sehen. Normales und Merkwuerdiges, "+
  "obwohl man das meisst kaum auseinander halten kann. Die Chaosgilde "+
  "ist jedoch garantiert etwas Merkwuerdiges, selbst in einer Welt wie "+
  "dieser. Es gibt kaum andere Orte auf dieser Welt, welche dieser "+
  "Gilde aehneln."));
  AddDetail(({"ort","orte"}),BS("Auf einer derart grossen Welt wie "+
  "dieser gibt es jede Menge merkwuerdigster Orte. Die Chaosgilde "+
  "und der schwarze Eisberg gehoeren zu diesen Orten."));
  AddDetail(({"menge"}),BS("Jede Menge. Du weisst schon."));
  AddDetail(({"normales","merkwuerdiges"}),BS("Normales und Merkwuerdiges "+
  "zu unterscheiden ist nicht einfach. Im Grunde ist es ja auch eine "+
  "rein subjektive Empfindung. Manchmal, bei einigen wenigen Orten, ist "+
  "diese Empfindung jedoch nicht subjektiv, sondern objektiv. So zum "+
  "Beispiel bei der Chaosgilde."));
  AddDetail(({"grund"}),BS("Es gibt niemals einen Grund. Es herrscht "+
  "das Chaos."));
  AddDetail(({"chaos"}),BS("Chaos rulez!"));
  AddDetail(({"empfindung","empfindungen"}),
  BS("Empfindungen sind fast immer subjektiv. "+
  "Manchmal jedoch, in schrecklich extremen Faellen, sind sie objektiv."));
  AddDetail(({"faelle"}),BS("Die Chaosgilde ist eine dieser Faelle."));
  AddDetail(({"beispiel"}),BS("Nimm zum Beispiel die Chaosgilde."));
  AddDetail(({"chaosgilde","burg","schwarze burg"}),BS("Die Chaosgilde "+
  "ist in einer maechtigen, schwarzen Burg beheimatet. Diese Burg befindet "+
  "sich in einem gewaltigen, schwarzen Eisberg. Nirgendwo sonst gibt es "+
  "etwas derartiges. Die Chaosgilde gehoert somit zu den merkwuerdigsten "+
  "Orten dieser Welt, und zwar ohne Zweifel."));
  AddDetail(({"eisberg","schwarzer eisberg"}),BS("Das ist wirklich ein "+
  "aeusserst merkwuerdiger Eisberg. Nicht nur ist er schwarz, er ist "+
  "ausserdem innerhalb weniger Augenblicke aus dem Boden gewachsen! Das "+
  "ist wirklich unglaublich."));
  AddDetail(({"augenblicke"}),BS("Die sind schon laengst vorbei!"));
  AddDetail(({"zweifel"}),BS("Zweifel kannst Du Dir hier nicht erlauben. "+
  "Dies ist ein Ort, an dem sie sehr schnell zum Tode fuehren koennen."));
  AddDetail(({"tod","tode"}),BS("Tod sagt: ICH KOMME, DICH ZU HOLEN."));
  AddDetail(({"ungewissheit"}),BS("Im Osten befindet sich nur die brodelnde "+
  "Ungewissheit, ohne den geringsten Hinweis, was Dich dort erwarten koennte. "+
  "Mutig starrst Du der Bedrohung entgegen."));
  AddDetail(({"hinweis"}),BS("Es gibt nicht den geringsten Hinweis darauf, "+
  "was dort wohl existieren moege, in diesem merkwuerdigen, geheimnisvollen "+
  "Dunkel."));
  AddDetail(({"mut"}),BS("Mut musst Du hier unten schon haben, sonst laeufst "+
  "Du bald nurnoch wild schreiend durch die Gegend, und das wollen wir alle "+
  "nicht."));
  AddDetail(({"gegend"}),BS("Die Gegend hier unten ist fuerchterlich duester "+
  "und unheimlich. Man muss schon verdammt viel Mut haben, um nicht sofort "+
  "schreiend durch die Gegend zu laufen."));
  AddDetail(({"dunkel","dunkles"}),BS("Der Raum verformt sich im Osten, er "+
  "dreht sich, wirbelt und verschiebt sich gar fuerchterlich. Er wird "+
  "dunkler, scheint auf merkwuerdige Weise alles Helle abzuweisen und zu "+
  "reflektieren, doch hinter dem reflektierten Licht erkennst Du ein schwarzes, "+
  "dunkles Nichts, ebenso unwirklich und irreal wie alles darum herum."));
  AddDetail(({"osten","oestliche seite"}),BS("Dieser Raum ist quasi zweigeteilt, "+
  "hat quasi zwei Seiten. Du befindest Dich auf der westlichen Seite, und "+
  "diese sieht noch wie ein normaler Raum aus. Doch im Osten, auf der anderen "+
  "Seite des Raumes, da beginnt sich der Raum zu verdrehen, sich zu verschieben, "+
  "auf merkwuerdige Weise aus diesem Universum zu entfernen und sich zu "+
  "verwandeln, zu verschwimmen und zu etwas anderem, etwas Dunklen zu werden. "+
  "Um ganz ehrlich zu sein, Du willst da eigentlich nicht nach Osten. Lieber "+
  "bleibst Du hier. Hier ist es sicher, hier ist es gemuetlich... naja, viell"+
  "eicht nicht gemuetlich, aber immerhin sicher. Und das ist wichtig."));
  AddDetail(({"seiten"}),BS("Dieser Raum hat sozusagen zwei Seiten. Eine "+
  "westliche Seite und eine oestliche Seite."));
  AddDetail(({"westen","westliche seite"}),BS("Die westliche Seite ist eine "+
  "gute Wahl. Du bist gerne hier. Sie ist so normal, so gewoehnlich, in all "+
  "ihrer Absonderlichkeit. Hier sieht es fast aus wie in einem normalen "+
  "Raum. Es gibt normale Waende (nun, relativ normal) und vor der Westwand "+
  "stehen sogar die ueblichen Horden von Kerzenstaendern. Von hier aus fuehrt "+
  "ein Gang fort nach Suedwesten. Es ist so nett hier ... so normal."));
  AddDetail(({"wahl"}),BS("Du tust gut, hier zu bleiben. Wirklich eine gute Wahl."));
  AddDetail(({"absonderlichkeit"}),BS("Alles hier ist absonderlich. Schau "+
  "Dir nur diese gewaltigen schwarzen Steine an, oder die merkwuerdigen "+
  "schwarzen Kerzen, oder die ekligen Kerzenstaender! So ziemlich alles hier "+
  "ist absonderlich, aber lange nicht so absonderlich wie die oestliche Seite "+
  "dieses Raumes."));
  AddDetail(({"raum"}),BS("Schau Dich nur um!"));
  AddDetail(({"horden"}),BS("Nun, es sind nicht wirklich Horden von Kerzenstaen"+
  "dern, aber es sind schon eine ganze Menge. Dafuer verbreiten die Kerzen "+
  "auf ihnen aber wirklich wenig Licht."));
  AddDetail(({"licht","dunkelheit","finsternis"}),BS("Das Licht in diesem "+
  "Raum stammt von den vielen Kerzen auf den vielen Kerzenstaendern an der "+
  "Westwand. Wie gewohnt verbreiten diese Kerzen nur ungenuegend Licht, und "+
  "dieses flackert auch noch. Immerhin wird das Licht von der oestlichen "+
  "Seite des Raumes auf merkwuerdige Weise reflektiert, so dass es hier ein "+
  "wenig heller ist als sonst. Viel ist das allerdings nichts. Diese Gegend "+
  "ist wohl fuer ewig in Finsternis getaucht. Wow."));
  AddDetail(({"weise"}),BS("Du nicht wirklich weise. Du besitzt Mut, sicher"+
  "lich. Du bist tollkuehn, das auf jeden Fall. Aber weise? Nein, weise "+
  "bist Du wirklich nicht."));
  AddDetail(({"fall"}),BS("*Waaaaaah* Plaetsch!"));
  AddDetail(({"bedrohung"}),BS("Du bist Dir nicht sicher, ob sich dort, "+
  "auf der oestlichen Seite des Raumes, eine Bedrohung fuer Dich befindet, "+
  "aber dein Leben wuerdest Du nur ungern auf das Gegenteil verwetten. "+
  "Deshalb bleibst Du auch lieber hier."));
  AddDetail(({"leben"}),BS("Das Leben ist so schoen..."));
  AddDetail(({"gegenteil"}),BS("Du glaubst nicht wirklich, dass die "+
  "oestliche Seite dieses Raumes sicher ist. Nein, wirklich nicht."));
  AddDetail(({"gang"}),BS("Ein hoher, dunkler Gang fuehrt nach Suedwesten "+
  "fort aus diesem Raum. Das Licht reicht kaum in ihn herein, doch im "+
  "Gegensatz zur oestlichen Seite dieses Raumes sieht er wirklich "+
  "extrem sicher und einladend aus."));
  AddDetail(({"gegensatz"}),BS("Der Gang nach Suedwesten steht im krassen "+
  "Gegensatz zur oestlichen Seite dieses Raumes. Und der Gang ist sicher"+
  "lich die bessere Alternative."));
  AddDetail(({"alternative"}),BS("Geh nach Osten! Nimm den Gang. Besser ist das."));
  AddDetail(({"gilde","gilden"}),BS("Dies hier ist die Chaosgilde, und "+
  "sie ist wirklich boesartig und satanisch. Ausserdem ist sie erschreckend "+
  "und andersartig in ihrem schwarzen Eisberg und der gewaltigen Hoehle, "+
  "mit ihrem merkwuerdigen Licht und den Saeureseen. Oft scheint es, als "+
  "gehe es hier nicht mit rechten Dingen zu. Und das stimmt absolut."));
  AddDetail(({"hoehle"}),BS("Du befindest Dich in einem riesigen, schwarz"+
  "zein Eisberg. Doch das ist noch nicht einmal das Merkwuerdigste. "+
  "Denn in diesem gewaltigen schwarzen Eisberg befindet sich eine riesige "+
  "Hoehle, und in dieser Hoehle befindet sich eine gewaltige, schwarze "+
  "Burg in einem grossen Saeuresee. Und auf die Burg herunter leuchtet ein "+
  "ebenso unglaubliches Licht, von dem niemand weiss, woher es kommt."));
  AddDetail(({"see","saeuresee","seen","saeureseen"}),BS("Die Chaosgilde "+
  "ist eine gewaltig, schwarze Burg, welche hoch ueber einem stinkenden "+
  "Saeuresee gebaut wurde. Woher dieses Seen kommen, weisst Du nicht. "+
  "Eine weitere Merkwuerdigkeit."));
  AddDetail(({"niemand"}),BS("Niemand sagt: Ich weiss es, ich weiss es!"));
  AddDetail(({"dinge"}),BS("Diese Dinge sind nicht recht!"));
  AddDetail(({"merkwuerdigkeit"}),BS("Woher mag all diese Saeure kommen? "+
  "Regnet sie von der Decke der Hoehle? Du weisst es nicht."));
  AddDetail(({"saeure"}),BS("Wie aetzend!"));
  AddDetail(({"merkwuerdigstes"}),BS("Das Merkwuerdigste zu finden in einer "+
  "Gegend wie dieser, ist fast ein Ding der Unmoeglichkeit."));
  AddDetail(({"unmoeglichkeit","ding"}),BS("Ding der Unmoeglichkeit. Ok, "+
  "ist untersucht. Baeh!"));
  AddDetail(({"nichts"}),BS(""));
  AddDetail(({"raeume"}),BS("Um Dich herum befinden sich jede Menge Raeume."));
  AddDetail(({"seite"}),BS("Welche Seite meinst Du? Die westliche Seite "+
  "oder die oestliche Seite?"));
  AddDetail(({"universum"}),BS("Das Phaenomen, welches Du hier im Osten "+
  "siehst, verlaesst anscheinend dieses Universum, zumindest wie wir es kennen."));
  AddDetail(({"phaenomen"}),BS("Wie soll man die oestliche Seite dieses "+
  "Raumes anders beschreiben als mit dem Wort Phaenomen?"));
  AddDetail(({"wort"}),BS("Das Wort war 'Phaenomen'."));
  AddDetail(({"wand","waende"}),BS("Lediglich die Westwand ist noch voellig "+
  "normal in diesem Raum. Nun, normal soweit man das in dieser Gegend sagen "+
  "kann. Die anderen Waende sind jedoch kaum mehr als Waende zu bezeichnen. "+
  "Mitten im Raum beginnen sie sich, wie der uebrige Raum auch, wild zu "+
  "drehen und zu verzerren, bis sie nicht mehr zu erkennen sind. Wie krank."));
  AddDetail(({"mitte"}),BS("Die Mitte des Raumes trannt die westliche Seite "+
  "von der oestlichen Seite."));
  AddDetail(({"westwand"}),BS("Die Westwand ist super, die Westwand ist cool. "+
  "Und zwar deshalb, weil sie so gewoehnlich ist, zumindest fuer die Raeume "+
  "hier unten. Sie besteht aus den ueblichen gewaltigen schwarzen Steinen, "+
  "welche das Licht so merkwuerdig absorbieren."));
  AddDetail(({"steine"}),BS("Die Steine sind gross, fuerchterlich schwer und "+
  "absolut schwarz."));
  AddDetail(({"kerzenstaender"}),BS("Die Kerzenstaender sind wie immer "+
  "schwarz und tragen wirklich viele Kerzen."));
  AddDetail(({"kerzen"}),BS("Die Kerzen sind schwarz und verbreiten nur sehr "+
  "wenig, wild flackerndes Licht."));
  AddDetail(({"decke"}),BS("Es ist noch immer zu dunkel, um die Decke zu "+
  "erkennen, und das trotz der merkwuerdigen Reflektion des Lichts durch "+
  "die oestliche Seite des Raums."));
  AddDetail(({"reflektion"}),BS("Das Licht wird von der oestlichen Seite "+
  "des Raumes auf merkwuerdige Weise reflektiert."));
  AddDetail(({"boden"}),BS("Soweit Du es erkennen kannst, besteht der Boden "+
  "noch immer aus den ueblichen schwarzen Fliesen, welche ueberall in dieser "+
  "Burg gleich langweilig zu sein scheinen."));
  AddDetail(({"fliesen"}),BS("Die Fliesen sind schwarz. Mehr ist dazu nicht "+
  "zu sagen."));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl3bu8"));
  AddSpecialExit("osten","into_the_void");
}

int into_the_void() {
  write("Du schaffst es einfach nicht.\n");
  return 1;
}