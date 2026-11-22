#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu8"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Unter der chaotischen Burg");
  SetProp(P_INT_LONG,BS("Ein hoher, dunkler Gang fuehrt hier durch das "+
  "Gestein des grauen Felsens, auf dem sich die schwarze Burg befindet. "+
  "Genau wie in der chaotischen Burg ueber Dir herrscht auch hier die "+
  "Finsternis. Die wenigen Kerzen an den Waenden scheitern fast erbaremlich "+
  "in ihrem Versuch, die Finsternis von hier zu vertreiben. Du kannst kaum "+
  "etwas erkennen. Zu den wenigen Dingen, die Du noch erkennen kannst, "+
  "gehoeren zwei grosse Gemaelde, welche an den Waenden haengen und Dir, "+
  "von den flackernden Kerzen angestrahlt, gefaehrliche lebendig vorkommen."));
  AddDetail(({"gang","raum"}),BS("Du befindest Dich doch tatsaechlich in "+
  "einem Gang, sogar in einem hohen und dunklen Gang. Es ist recht kalt "+
  "hier, obwohl nicht der geringste Luftzug zu spueren ist. Die Decke "+
  "ist, wie immer, zu hoch, um sie genau zu erkennen, und es sind noch "+
  "weniger Kerzen vorhanden als gewoehnlich. Deshalb tappst Du hier auch "+
  "ziemlich im Dunkeln."));
  AddDetail(({"kaelte"}),BS("Es ist nicht richtig kalt hier, nur relativ kalt. "+
  "Die Kaelte ist somit zwar unangenehm, aber nicht schmerzhaft."));
  AddDetail(({"felsen"}),BS("Die schwarze Burg wurde auf einem hohen, "+
  "grauen Felsen inmitten eines Saeuresees gebaut. Diesen Felsen hast Du bis "+
  "jetzt nur aus der Ferne gesehen, und selbst jetzt bekommst Du ihn nicht "+
  "zu seinen. Die Waende hier sind naemlich mit grossen Steinen vermauert "+
  "worden, so dass man das Gestein nicht sehen kann. Wahrscheinlich passte "+
  "die graue Farbe einfach nicht in diese Gilde, weshalb man sie aus der Burg "+
  "verbannt hat."));
  AddDetail(({"see","saeuresee"}),BS("Der See befindet ist ueberall um "+
  "Dich herum. Lediglich die starken Waende um Dich herum halten die "+
  "Saeure davon ab, hereinzustroemen und Dich qualvoll aufzuloesen. Welch "+
  "qualvoller Gedanke."));
  AddDetail(({"saeure"}),BS("Wie aetzend."));
  AddDetail(({"gedanke"}),BS("Du willst nicht sterben. Aber wer will das schon."));
  AddDetail(({"farbe"}),BS("Die Farbe dieses Felsens ist grau."));
  AddDetail(({"wand","waende"}),BS("Vor den Waenden stehen einige wenige "+
  "Kerzenstaender mit Kerzen. Sie beleuchten die Waende jedoch nur ungenue"+
  "gend, und in den Ecken kann man sowieso nichts erkennen. Was Du jedoch "+
  "leidlich gut erkennen kannst, sind zwei Gemaelde, welche an den Waenden "+
  "aufgehaengt wurden. Sie lockern die einheitliche Schwaerze etwas auf, "+
  "welche die grossen Steine ausstrahlen, aus denen die Waende gemauert "+
  "wurden."));
  AddDetail(({"kerzenstaender"}),BS("Wie immer bestehen die Kerzenstaender "+
  "aus schwarzen Eisen und sind eher praktisch als schoen. Nun, eigentlich "+
  "sind sie sogar ausgesprochen haesslich. Nun, deshalb werden sie wohl "+
  "wenigstens nicht geklaut, das ist immerhin schon etwas."));
  AddDetail(({"eisen"}),BS("Die Kerzenstaender bestehen aus schwarzen Eisen, "+
  "soviel ist schon mal klar."));
  AddDetail(({"kerzen"}),BS("Hier brennen nur sehr wenige Kerzen, welche "+
  "auf schwarzen Kerzenstaendern vor den Waenden stecken. Diese Kerzen "+
  "verbreiten dazu auch noch so gut wie garkein Licht, was dazu fuehrt, "+
  "dass dieser Raum in grosse Finsternis gehuellt ist, noch mehr als die "+
  "anderen Raeume um Dich herum. Nur wenig flackerndes Licht erreicht hier "+
  "Deine Augen. Schatten regieren diesen Gang."));
  AddDetail(({"raeume"}),BS("Um Dich herum gibt es viele Raeume, und alle "+
  "sind mehr oder weniger dunkel. Aber dieser hier scheint der dunkelste "+
  "von allen zu sein."));
  AddDetail(({"augen"}),BS("Wow, Du hast sogar 2 davon."));
  AddDetail(({"schatten"}),BS("Im Grunde ist zu wenig Licht da, um wirklich "+
  "Schatten zu erzeugen. Trotzdem glaubst Du immer wieder huschende, "+
  "schnelle Bewegungen in der Dunkelheit zu sehen. Und das muessen doch "+
  "Schatten sein. Oder?"));
  AddDetail(({"bewegungen"}),BS("In der Dunkelheit glaubst Du immer wieder "+
  "Bewegungen zu entdecken, doch wenn Du nachschaust, ist nichts dort, "+
  "was auf jemand Fremden hinweisen wuerde."));
  AddDetail(({"licht","dunkelheit","finsternis"}),BS("Es ist wirklich extrem "+
  "dunkel hier. Du kannst die zwei Gemaelde, welche an den Waenden haengen, "+
  "garnicht richtig erkennen. Doch das ist noch garnichts. In der Ecke dieses "+
  "abknickenden Ganges ist die Finsternis so stark, dass man wirklich ueber"+
  "haupt nichts erkennen kann. Das einzige Licht in diesem Gang stammt wirk"+
  "lich von den wenigen flackernden, schwarzen Kerzen an den Waenden."));
  AddDetail(({"ecke"}),BS("In der Ecke dieses Ganges ist es viel zu dunkel, "+
  "um etwas zu erkennen. Du fragst Dich, welche Geheimnisse wohl dort auf "+
  "Dich warten. Nun ja, wahrscheinlich nur eine leere Ecke mit oeden Steinen."));
  AddDetail(({"geheimnisse"}),BS("Um die Geheimnisse dieser Ecke zu erforschen, "+
  "muesstest Du schon in die Ecke kriechen."));
  AddDetail(({"stein","steine"}),BS("Die Steine in den Waenden dieses Ganges "+
  "sind wie alle anderen Steine in dieser gross, schwer, kalt, makellos und "+
  "absolut schwarz. Das schwarz dieser Steine ist geradezu atemberaubend. "+
  "Diese Steine scheinen das wenige Licht der Kerzen magisch anzusehen und "+
  "zu verschlucken."));
  AddDetail(({"gemaelde"}),BS("Es gibt zwei Gemaelde, nennen wir sie Gemaelde "+
  "1 und Gemaelde 2. Sie sind so gross, dass eine einzelne Untersuchung von "+
  "ihnen durchaus gerechtfertigt scheint."));
  AddDetail(({"gemaelde 1"}),BS("Das erste Gemaelde zeigt einen maennlichen "+
  "Chaoten, den Du gut kennst. Es erscheint so lebensecht, dass Du fast die "+
  "Alkoholfahne zu riechen glaubst, welche dieser Gestalt auf Schritt und "+
  "Tritt folgt. Denn auf diesem Gemaelde siehst Du Winkrieg, seines Zeichens "+
  "Chaot. Winkrieg gehoert quasi zum Inventar der Chaosgilde. Er betreibt "+
  "aktive Forschung ueber Daemonen, groesstenteils indem er sie beschwoert, "+
  "abfuellt und nach ihren Problemen ausfragt. Seiner Meinung nach gibt es "+
  "keine besseren Saufkumpane als Daemonen. Und da mag er durchaus recht haben. "+
  "Winkrieg ist ein Mensch und fuer einen solchen nicht einmal besonders gross. "+
  "Seine Gesichtsfarbe ist erschreckende rosig fuer einen Chaoten und seine "+
  "Nase geradezu rot. Doch in seinen Augen leuchtet noch immer das Chaos, und "+
  "Bosheit verzerrt sein Gesicht."));
  AddDetail(({"chaot","chaoten"}),BS("Chaoten sind die besten!"));
  AddDetail(({"alkoholfahne"}),BS("*Sniff Sniff* Wow, der Kuenstler, welcher "+
  "dieses Gemaelde schuf, hat es anscheinend mit Alkohol getraenkt. Du riechst "+
  "tatsaechlich eine Alkoholfahne. Sowas."));
  AddDetail(({"kuenstler"}),BS("Diese Gemaelde wurden von waren Kuenstlern "+
  "hergestellt."));
  AddDetail(({"alkohol"}),BS("Du WEISST, was Alkohol ist."));
  AddDetail(({"gestalt"}),BS("Die Gestalt auf diesem Gemaelde ist Winkrieg, ein "+
  "sehr bekannter Chaot."));
  AddDetail(({"winkrieg"}),BS("Winkrieg ist ein bekannter Chaot. Jeder kennt "+
  "ihn. Und wenn man ihn auch nicht fuer wirklich boesartige Taten und Erfolge "+
  "kennt, so ... nun, kennt man ihn wenigstens, und das ist immerhin schon "+
  "etwas."));
  AddDetail(({"jeder"}),BS("Jeder sagt: Klar kenn ich Winkrieg."));
  AddDetail(({"taten","erfolge"}),BS("Hmmm. Also eigentlich kennst Du garkeine "+
  "Taten oder Erfolge, die man Winkrieg anrechnen kann. Er weiss aber immer"+
  "hin ziemlich viel ueber Alkohol. Das muss man ihm lassen."));
  AddDetail(({"mensch"}),BS("Winkrieg ist ein Mensch."));
  AddDetail(({"gesichtsfarbe"}),BS("Chaoten bevorzugen eine bleiche Gesichtsfarbe. "+
  "Sie sind Geschoepfe der Nacht. Winkriegs Gesichtsfarbe ist aber relativ "+
  "rosig, was eigentlich eine Schande fuer ihn ist."));
  AddDetail(({"geschoepfe","nacht","geschoepfe der nacht"}),BS("Chaoten sind "+
  "Geschoepfe der Nacht. Deshalb sind sie auch immer so bleich."));
  AddDetail(({"schande"}),BS("Winkrieg macht sich nicht allzuviel aus Schande. "+
  "Dazu ist er meisst viel zu betrunken."));
  AddDetail(({"inventar"}),BS("Winkrieg gehoert schon quasi zum Inventar der "+
  "Chaosgilde."));
  AddDetail(({"meinung","meinungen"}),
  BS("Winkrieg hat viele Meinungen, und sogar einige "+
  "recht ausgefallene. Das waere an sich auch gar nicht schlimm, doch Winkrieg "+
  "hat die Angewohnheit, seine Meinung zu nachtschlafender Zeit wild herumzubruellen "+
  "und dann wild auf irgend etwas einzuschlagen."));
  AddDetail(({"angewohnheit"}),BS("Nuun, diese Angewohnheit sieht man Winkrieg "+
  "gerne nach, nachdem man ihn verpruegelt und ausgeraubt hat."));
  AddDetail(({"zeit"}),BS("Huch, schon so spaet?"));
  AddDetail(({"forschung"}),BS("Winkriegs Forschung ist extrem ... praxisnah "+
  "und ... hochprozentig. Bis jetzt hat er auch noch keine wirklich brauchbaren "+
  "Ergebnisse vorweisen koennen. Doch das stoert ihn nicht."));
  AddDetail(({"ergebnisse"}),BS("Winkrieg hat bis jetzt keine brauchbaren Ergeb"+
  "nisse seiner Forschung vorzeigen koennen. Doch wer weiss, vielleicht "+
  "aendert sich das irgendwann."));
  AddDetail(({"saufkumpane","saufkumpan"}),BS("Winkriegs Saufkumpane sind "+
  "ausnahmslos Daemonen. Das ist aber ziemlich eklig, denn ein betrunkener "+
  "Daemon verhaelt sich oft extrem eklig."));
  AddDetail(({"daemon","daemonen"}),BS("Du weisst, was Daemonen sind."));
  AddDetail(({"probleme"}),BS("Keiner weiss mehr ueber die Probleme von "+
  "Daemonen als Winkrieg."));
  AddDetail(({"bosheit"}),BS("Winkrieg soll, wenn er nicht gerade betrunken "+
  "ist, ein absolut satanischer und boshafter Kerl sein. Dies ist jedoch "+
  "nur ein Geruecht, denn kaum einer hat Winkrieg je nuechtern gesehen."));
  AddDetail(({"kerl"}),BS("Du meinst wohl Winkrieg."));
  AddDetail(({"geruecht"}),BS("Das Geruecht besagt, dass Winkrieg eigentlich "+
  "ein fuerchterlich boshafter und satanischer Kerl ist, wenn er mal nichts "+
  "getrunken hat."));
  AddDetail(({"burg"}),BS("Du befindest Dich tief unter der chaotischen "+
  "Burg. Wenn Du also die Burg untersuchen willst, solltest Du irgendwie "+
  "dort wieder herauf kommen."));
  AddDetail(({"chaos","chaosgilde"}),BS("Die Chaosgilde ist die beste und "+
  "satanischste Gilde, die es gibt. Sie befindet sich in einer schwarzen "+
  "Burg in einem grossen Saeuresee."));
  AddDetail(({"dinge"}),BS("Du kannst nurnoch wenig erkennen. Zu den wenigen "+
  "Dingen, die Du wie gesagt noch erkennen kannst, gehoeren die zwei "+
  "Gemaelde an den Waenden."));
  AddDetail(({"ecken"}),BS("Es gibt in diesem Gang nur eine Ecke. Sozusagen."));
  AddDetail(({"fremdes","fremder"}),BS("Du bist Dir sicher, dass Du hier nicht "+
  "allein bist. Aber andererseits wirst Du nicht angegriffen und somit relativ "+
  "zufrieden."));
  AddDetail(({"gesicht"}),BS("Winkriegs Gesicht ist von Bosheit entstellt. "+
  "Das ist jedoch lediglich auf dem Gemaelde so. Meisst hat Winkrieg sein "+
  "Gesicht laengst nicht so gut unter Kontrolle, um eine derartige Grimasse "+
  "zu ziehen."));
  AddDetail(({"kontrolle"}),BS("Winkriegs Kontrolle ueber sein Gesicht ist "+
  "normalerweise eher bescheiden."));
  AddDetail(({"grimasse"}),BS("Winkrieg schneidet auf dem Gemaelde eine ziem"+
  "liche Grimasse."));
  AddDetail(({"gestein"}),BS("Du kannst das graue Gestein des Felsens von hier "+
  "aus nicht sehen. Ueberall um Dich herum sind die grossen Steine, welche "+
  "ueberall in der Gilde verbaut wurden."));
  AddDetail(({"gilde"}),BS("Du meinst sicher die Chaosgilde. Das ist eine "+
  "wirklich gemeine Gilde. Jawoll."));
  AddDetail(({"grund"}),BS("Im Grunde ist das ziemlich grundlos, denkst Du."));
  AddDetail(({"luftzug"}),BS("Hier herrscht nicht ein Luftzug. Aber es ist "+
  "recht kalt hier. *Brrr*."));
  AddDetail(({"nase"}),BS("Winkriegs Nase ist rot."));
  AddDetail(({"schritt","tritt"}),BS("Wohin Winkrieg auch geht, auf Schritt "+
  "und Tritt folgt ihm diese stinkende Alkoholfahne. Man kann den Kerl schon "+
  "von Weitem riechen."));
  AddDetail(({"schwaerze"}),BS("Diese Schwaerze ist absolut schwarz. Wow, welch "+
  "sinnloser Satz."));
  AddDetail(({"satz"}),BS("'Diese Schwaerze ist absolut schwarz.'"));
  AddDetail(({"untersuchung"}),BS("Eine einzelne Untersuchung der beiden "+
  "Gemaelde ist durchaus angebracht. Immerhin sind die beiden Gemaelde "+
  "ziemlich gross."));
  AddDetail(({"versuch"}),BS("Der Versuch der Kerzen, diesen Raum zu erleuch"+
  "ten, scheitert klaeglich, da ihre Anzahl so erschreckend gering ist."));
  AddDetail(({"anzahl"}),BS("Du siehst hier nur sehr wenige Kerzen. Weni"+
  "ger als anderswo."));
  AddDetail(({"zeichen"}),BS("Winkrieg ist Chaot."));
  AddDetail(({"gemaelde 2"}),BS("Das zweite Gemaelde zeigt einen sturzbet"+
  "runkenen Daemon. Er ist wohl einer von Winkriegs Opfern. Anscheinend "+
  "ruelpst er gerade und starrt wild in die Gegend. Wie erbaermlich."));
  AddDetail(({"opfer"}),BS("Winkriegs Opfer findet man oft bewusstlos und "+
  "gluecklich in irgendwelchen Graeben wieder."));
  AddDetail(({"graeben"}),BS("Solche Graeben gibt es ueberall :-)."));
  AddDetail(({"gegend"}),BS("Die Gegend hier ist echt kalt. Sowas."));
  AddDetail(({"decke"}),BS("Es ist viel zu dunkel, als das Du die Decke "+
  "erkennen koenntest."));
  AddDetail(({"boden"}),BS("Jaaaaaaa, der Boden. Hmmm. Also. Er ist da, "+
  "Du kannst ihn aber wegen des Lichts schlecht erkennen, blah blah, "+
  "Steinfliesen, fuerchterlich oede, hmmmm, ja, oft wegen schlechtem "+
  "Licht nichts zu erkennen blah blah. Mit freundlichen Gruessen, der "+
  "Programmierer."));
  AddDetail(({"gruesse","programmierer"}),BS("Gruesse. Ich bin Feuer"+
  "wehr, Chaot."));
  AddDetail(({"feuerwehr"}),BS("Feuerwehr ist Chaot."));
  AddDetail(({"fliesen","steinfliesen"}),BS("Gott sind die oede. Sie sind "+
  "schwarz, uneben und absolut uninteressant."));
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht nach Alkohol."));
  AddSmells("alkohol",BS("Du riechst Alkohol. Hat hier wer eine Alkoholfahne?"));
  AddSounds(SENSE_DEFAULT,BS("Du hoerst garnichts."));
  AddExit("norden",CHAOS_GILDEN_ROOM("cl3bu7"));
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl3bu11"));
}
