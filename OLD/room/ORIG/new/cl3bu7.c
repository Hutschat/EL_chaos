#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu6"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Unter einer Burg");
  SetProp(P_INT_LONG,BS("Du wanderst einen auf dunklen Pfaden. In diesem "+
  "Fall sind diese Pfade zwar Gaenge, aber dunkel sind sie allemal. Nun, "+
  "immerhin siehst Du, dass sich hier zwei Gaenge kreuzen. Einer fuehrt "+
  "von Norden nach Sueden, der andere fuehrt nach Westen fort in die "+
  "Dunkelheit, welche sich dort jedoch etwas zu heben scheint. Die Beleuch"+
  "tung wird hier uebernommen durch eine Reihe schwarzer Kerzen, welche "+
  "auf einer Reihe von Kerzenstaendern an den Waenden befestigt sind. "+
  "In der oestlichen Wand befindet sich uebrigens ein Durchgang. Die Wand "+
  "um ihn herum ist umrahmt von Drudenfuessen und mystischen Symbolen aller "+
  "Arten. Du fragst Dich wirklich, was sich hinter diesem Durchgang befinden "+
  "mag. Und ob Du es moegen wirst. Von den Waenden starren Dich Daemonenfratzen "+
  "an, welche in die Steine gemeisselt wurden."));
  AddDetail(({"pfad","pfade"}),BS("Dies hier ist ein wahrlich duesterer Pfad, "+
  "und dies gilt sowohl fuer das Licht als auch fuer die Atmosphaere dieses "+
  "Ganges. Die mystischen Zeichen, die rituellen Kerzen, dies alles verleiht "+
  "dem Gang einen sakralen, jedoch nichtsdestotrotz satanischen Touch. "));
  AddDetail(({"atmosphaere"}),BS("Die Atmosphaere aehnelt stark dem einer "+
  "satanischen Opferstaette. Wer hier wohl geopfert wird? Nervoes blickst "+
  "Du Dich um."));
  AddDetail(({"opferstaette"}),BS("Befindet sich unterhalb der chaotischen "+
  "Burg wirklich eine satanische Opferstaette, ein derart satanischer Ort? "+
  "Du zweifelst nicht daran..."));
  AddDetail(({"burg"}),BS("Du befindest Dich unterhalb einer grossen, chaot"+
  "ischen Burg. Da Du dich somit ziemlich tief unten befindest, findest Du "+
  "nur sehr wenig Licht. Nicht, dass es dort oben besser gewesen waere. "+
  "Die chaotische Burg ist anders. Sie ist etwas besonderes, sie ist hochmag"+
  "isch, extrem satanisch und beunruhigend lebendig."));
  AddDetail(({"licht","duesternis","dunkelheit"}),BS("Wie fast ueberall hier "+
  "unten ist es verflucht dunkel hier. Die rituellen Kerzen an den Waenden "+
  "sehen sehr edel und wirklich wichtig aus, doch sie verbreiten kaum Licht. "+
  "Somit musst Du schon scharf aufpassen, nicht ueberall gegenzulaufen."));
  AddDetail(({"zeichen","drudenfuesse","pentagramme",
  "symbole","gotische symbole"}),
  BS("Die Wand um den Durchgang herum ist bedeckt mit einer Vielzahl mysti"+
  "scher Symbole. Drudenfuesse finden sich neben Abbildungen von Totenkoepfen "+
  "oder seltsamen gotischen Schriftzeichen. Du bekommst langsam den Eindruck, "+
  "als ob diese ganze Ansammlung von Zeichen ein einziges, grosses "+
  "'KEIN ZUTRITT'-Schild in einer Dir nicht gelaeufigen Sprache sei."));
  AddDetail(({"vielzahl"}),BS("Das sind wirklich viele Zeichen und Symbole, "+
  "welche sich dort um den Durchgang draengen..."));
  AddDetail(({"abbildungen","totenkoepfe"}),BS("Die abgebildeten Totenkoepfe "+
  "sind eigentlich noch harmlos gegen einige der Symbole, welche dort an die "+
  "Wand geschmiert wurden. "));
  AddDetail(({"schild","zutritt"}),BS("Du bist eigentlich davon ueberzeugt, "+
  "dass als die Symbole und Pentagramme und das ganze Zeug dort im Grunde "+
  "ein grosses 'Zutritt verboten'-Schild sind."));
  AddDetail(({"zeug"}),BS("Da wurde ziemlich viel Zeug um den Durchgang "+
  "gemalt, daran besteht kein Zweifel..."));
  AddDetail(({"zweifel"}),BS("Es besteht absolut kein Zweifel. Du bist "+
  "schuldig."));
  AddDetail(({"abbildungen"}),BS("Die Abbildungen der Totenkoepfe sind "+
  "schrecklilch real und angsteinfloessend."));
  AddDetail(({"schriftzeichen"}),BS("Die Schriftzeichen sind gotisch. Soviel "+
  "ist klar."));
  AddDetail(({"touch"}),BS("Dieser Ort ist vieles, aber vor allem ist er "+
  "satanisch und durchdrungen von den finstersten Maechten des Boesen, "+
  "welche wild und geifernd nach Deiner Seele gieren."));
  AddDetail(({"maechte","maechte des boesen","boeses"}),BS("Die Maechte des "+
  "Boesen sind stark in diesem Ort. Sie durchdringen ihn und formen ihn "+
  "nach ihren eigenen, verdrehten Vorstellungen, und Wahnsinn und Tod "+
  "werden in ihn einziehen, um sich von hier aus wild wuchernd auszubreiten."));
  AddDetail(({"vorstellungen","vorstellung"}),
  BS("Die Vorstellung satanischer Maechte von "+
  "einem 'boesen' Ort sind wirklich ziemlich krank und verdreht."));
  AddDetail(({"wahnsinn"}),BS("Er wird auch Dich ereilen, zweifle nicht daran!"));
  AddDetail(({"tod"}),BS("Leg es nicht drauf an..."));
  AddDetail(({"seele"}),BS("Wenn Du noch eine besitzt, so fuerchte Dich. "+
  "Fuerchte um Deine Seele."));
  AddDetail(({"ansammlung"}),BS("Diese merkwuerdige Ansammlung von arkanen "+
  "und gotischen Symbolen ergibt fuer Dich nicht wirklich einen Sinn. Sie "+
  "scheint gewissermassen zufaellig gewaehlt worden zu sein. Oder vielleicht "+
  "auch nicht? Vielleicht ist es eine Nachricht, welche jedoch zu fremdartig "+
  "ist, als das Du sie verstehen koenntest?"));
  AddDetail(({"sinn"}),BS("Suche nicht nach dem Sinn."));
  AddDetail(({"nachricht"}),BS("Das einzige, was Du aus dieser merkwuerdigen "+
  "Ansammlung herauslesen koenntest, waere die Nachricht: Geh weg!."));
  AddDetail(({"durchgang"}),BS("Im Osten fuehrt ein Durchgang in ein mystisches "+
  "Dunkel, welches Du einfach nicht mit deinen Augen durchdringen kannst. "+
  "Der Durchgang ist umrahmt von einer beaengstigenden Ansammlung arkaner Symbole "+
  "und seltsamer Schriftzeichen. Boesartige Pentagramme runden das Gesamtbild "+
  "ab und machen Dir klar, dass Du dort wirklich nicht hineingehen solltest."));
  AddDetail(({"gesamtbild"}),BS("Das Gesamtbild ist nichts anderes als "+
  "beaengstigend und erschreckend. Was mach sich nur hinter diesem boesartigen "+
  "Durchgang befinden?"));
  AddDetail(({"augen"}),BS("Du kannst deine eigenen Augen nicht sehen! WAHHH!"));
  AddDetail(({"art","arten"}),BS("Es gibt wirklich viele Arten von arkanen "+
  "und mystischen Symbolen. Und Du hast schon wirklich viele verschiedene "+
  "gesehen. Und irgendwie hat es jemand geschafft, sie alle dort um den "+
  "Durchgang zu malen, welcher in das mystische Dunkel fuehrt."));
  AddDetail(({"dunkel"}),BS("Hinter dem Durchgang ist es so fuerchterlich "+
  "finster, dass Du garnicht erkennen kannst, was sich dahinter befindet."));
  AddDetail(({"beleuchtung"}),BS("Die Beleuchtung dieses Ganges uebernimmt "+
  "eine grosse Anzahl schwarzer Kerzen, welche in Kerzenstaendern  an den "+
  "Waenden stehen. Diese Beleuchtung ist jedoch, zugegebenermassen, nicht "+
  "besonders gut."));
  AddDetail(({"kerzen"}),BS("Die Kerzen sind schwarz und aehneln denen, die "+
  "man oben im Laden fuer rituelle Zwecke kaufen dann, doch sie sind anders. "+
  "Zwar nicht optisch, aber ... sie sind anders. Nun, immerhin geben diese "+
  "Kerzen wenigstens etwas Licht."));
  AddDetail(({"zwecke"}),BS("Rituelle Zwecke sind immer etwas geheim, deshalb "+
  "wird hier auch nichts naeheres verraten."));
  AddDetail(({"licht","finsternis","duesternis"}),BS("Hier ist es ziemlich "+
  "dunkel, trotz der vielen Kerzen an den Waenden. Nun, vielleicht haette man "+
  "nicht diese merkwuerdigen schwarzen Kerzen nehmen sollen."));
  AddDetail(({"anzahl"}),BS("Die Anzahl dieser Kerzen ist wirklich gross. "+
  "Verdammt. Eigentlich sollte es hier wirklich mal heller sein."));
  AddDetail(({"eindruck"}),BS("Falls dieser Eindruck mit dem 'Zutritt "+
  "Verboten'-Schild wirklich richtig ist, sollte man wohl nicht durch "+
  "diesen Durchgang gehen. Oder vielleicht doch, vielleicht gerade dann..."));
  AddDetail(({"fall","freier fall"}),
  BS("Du befindest Dich momentan nicht im freien Fall, "+
  "sonder sicher auf dem Boden. Und das ist gut so, denn ansonsten ginge es "+
  "rapide abwaerts mit Dir."));
  AddDetail(({"furcht"}),BS("Fuerchte Dich! Fuerchte um deine Seele!"));
  AddDetail(({"gaenge"}),BS("Hier treffen, wie schon berichtet, zwei Gaenge "+
  "Zusammen. Einer von  ihnen fuehrt von Norden nach Sueden, der andere "+
  "fuehrt von hier nach Westen fort. Beide Gaenge sind sehr hoch und "+
  "sehr spaerlich beleuchtet."));
  AddDetail(({"gang"}),BS("Hier gibt es mehr als nur einen Gang."));
  AddDetail(({"norden","sueden","westen","osten"}),BS("Geh doch hin..."));
  AddDetail(({"grund"}),BS("Im Grunde genommen wolltest Du das hier garnicht "+
  "untersuchen. Also laesst Du's sein."));
  AddDetail(({"kerzenstaender"}),BS("Jeder dieser Kerzenstaender nimmt "+
  "ein gutest Dutzend Kerzen auf. Und da es wirklich viele dieser Kerzen"+
  "staender in diesen Gaengen gibt, sollte es eigentlich richtig hell hier "+
  "sein. Leider ist es jedoch ziemlich dunkel und unheimlich. Leider? "+
  "Nun, immerhin ist dies kein normaler Ort..."));
  AddDetail(({"dutzend"}),BS("Du weisst was ein Dutzend ist."));
  AddDetail(({"laden"}),BS("Dieser merkwuerdige Laden befindet sich irgend"+
  "wo ueber Dir. Aber wie willst Du da nur jemals wieder hochkommen?"));
  AddDetail(({"ort"}),BS("Wo befindest Du Dich hier? Prinzipiell unterhalb "+
  "der Chaosgilde, jener schwarzen Burg, in einem der vielen unterirdischen "+
  "Gaenge, welche sich unter ihr befinden. Aber wo befindest Du Dich "+
  "wirklich? Und wann? Und warum? Und woher? Und wohin? Und vor allem: Wo "+
  "bleibt die Pizza?"));
  AddDetail(({"pizza"}),BS("Langsam kriegst Du richtig Hunger."));
  AddDetail(({"hunger"}),BS("Dein Magen knurrt."));
  AddDetail(({"magen"}),BS("Er knurrt ganz gewaltig."));
  AddDetail(({"chaosgilde","burg"}),BS("Die Chaosgilde befindet sich in "+
  "einer grossen, schwarzen Burg. Oder anders. Die Chaosgilde ist eine "+
  "grosse, schwarze Burg, welche sich in einem gewaltigen, schwarzen "+
  "Eisberg befindet."));
  AddDetail(({"eisberg"}),BS("Du bist Dir darueber vielleicht nicht richtig "+
  "klar, aber Du befindest Dich in einem gewaltigen Eisberg. UND unter "+
  "einer schwarzen Burg. Wow."));
  AddDetail(({"reihe"}),BS("Also, um es mal genau zu sagen: Es befinden "+
  "sich genug schwarze Kerzen in diesen Gaengen, um zehn schwarze Messen "+
  "zu erleuchten. Doch irgendwie ist es hier immernoch verdammt finster. "+
  "Absicht?"));
  AddDetail(({"messe","messen"}),BS("Du bist verdammt nah drann, auch "+
  "wenn Du es natuerlich noch nicht weisst..."));
  AddDetail(({"absicht"}),BS("Jup, war Absicht."));
  AddDetail(({"sprache"}),BS("Diese Sprache, wenn es denn eine ist, ist Dir "+
  "unbekannt."));
  AddDetail(({"decke"}),BS("Dieser Raum besitzt sehr hohe Decken. So hoch, "+
  "dass man sie von hier unten bei der miesen Beleuchtung eigentlich kaum "+
  "erkennen kann. Das einzige, was Du wirklich sehen kannst ist, dass sie "+
  "sich halbkreisfoermig ueber Dir woelbt. Sie scheint auch irgendwie "+
  "bemalt zu sein, doch dass kannst Du so wirklich nicht erkennen."));
   AddDetail(({"wand","waende"}),BS("Gaenge definieren sich haeufig durch "+
   "ihre Waende. Und die Waende dieses Ganges sind schwarz und bestehen "+
   "aus grossen, schwarzen Steinen. Das wird jedoch relativiert durch die "+
   "vielen Kerzenstaender, welche in einer Reihe vor jeder Wand stehen "+
   "und dabei ein schwaches, seltsames Licht verbreiten oder besser 'nicht "+
   "verbreiten'. Denn es ist wirklich dunkel hier."));
   AddDetail(({"stein","steine"}),BS("Diese Steine sind gewaltig. Du wund"+
   "erst Dich immer mehr, wie man so viele dieser Steine hier hat benutzen "+
   "koennen. Und warum man es getan hat. Immerhin ist man im Grunde so oder "+
   "so von Gestein umgeben. Diese gewaltigen Steine noch einmal davor zu "+
   "packen, war sicherlich voellig unsinnig. Doch wer immer diese Burg auch "+
   "gebaut hat, er hatte wohl einen grossen Sinn fuer Einheitlichkeit. "+
   "Doch andererseits wird diese Einheitlichkeit hier gestoert, denn man "+
   "hat graessliche Daemonenfratzen in die Steine gemeisselt."));
   AddDetail(({"gestein"}),BS("Du bist von Gestein umgeben. So oder so."));
   AddDetail(({"einheitlichkeit"}),BS("Diese ganze Burg wurde sehr einheit"+
   "lich gebaut. Ueberall wurden dieselben Steine genommen, was allem hier "+
   "einen sehr wuchtigen und ueberdimensionalen Touch gibt. Doch sei's drumm."));
   AddDetail(({"daemonenfratzen","fratzen"}),BS("Es sind graessliche Fratzen "+
   "von haesslichen Daemonen mit Hoernern, gewaltigen Zaehnen und stechenden "+
   "Augen, deren Gesichtszuege verzerrt und boesartig sind, waehrend ihr Maul "+
   "zu einem satanischen, schreckenerregenden Grinsen verzerrt ist."));
   AddDetail(({"daemonen"}),BS("Die hier eingemeisselten Daemonen sind "+
   "wirklich absolut haesslich. Doch trotz allem sind sie faszinierend. Sie "+
   "wirken seltsam ... lebendig. Ihre Augen scheinen genau Dich anzustarren, "+
   "und Dir ueberallhin zu folgen. Sehr beunruhigen."));
   AddDetail(({"hoerner"}),BS("Die Hoerner der Daemonen sind spitz und rela"+
   "tiv kurz. Du hast schon groessere gesehen."));
   AddDetail(({"zaehne","reisszaehne"}),BS("Die Zaehne dieser Daemonenfratzen "+
   "sind lang und messerscharf. Es sind gewaltige Reisszaehne, Werkzeuge zum "+
   "Toeten und Verstuemmeln."));
   AddDetail(({"werkzeuge"}),BS("Du meintest die Zaehne, nicht?"));
   AddDetail(({"toeten","verstuemmeln"}),BS("Los, geh und amuesier Dich."));
   AddDetail(({"gesichtszuege"}),BS("Die Gesichtszuege sind zu ekelhaften, "+
   "boesartigen Fratzen verzerrt."));
   AddDetail(({"maul","maeuler"}),BS("Wow, diese Daemonen  haben wirklich "+
   "gewaltige Maeuler."));
   AddDetail(({"grinsen"}),BS("Bei diesem Grinsen wird Dir richtig unbehaglich "+
   "zumute."));
   
   AddDetail(({"boden"}),BS("Der Boden besteht, wie koennte es anders sein, "+
   "und quasi als Bestaetigung der Einheitlichkeit dieses Ortes, aus den "+
   "uebliche, voellig schwarzen und dennoch absolut uninteressanten schwar"+
   "zen Fliesen. Du kannst Dich kaum noch halten vor lauter Begeisterung."));
   AddDetail(({"bestaetigung"}),BS("Du hast jede Bestaetigung, die Du brauchst. "+
   "Dieser Raum ist geradezu graesslich einheitlich. Das soll eine chaotische "+
   "Burg sein? Pah!"));
   AddDetail(({"begeisterung"}),BS("Sie ist gerade ziemlich gesunken. Aber "+
   "das ist durchaus verstaendlich, bei diesen Fliesen..."));
   AddDetail(({"fliesen"}),BS("Sie sind schwarz. Mehr moechtest Du prinzipiell "+
   "auch garnicht ueber sie wissen."));
   AddDetail(({""}),BS(""));
   
  AddSmells(SENSE_DEFAULT,BS("Es riecht hier nach garnix."));
  AddSounds(SENSE_DEFAULT,BS("Absolute Stille."));
  
  AddExit("westen",CHAOS_GILDEN_ROOM("cl3bu1"));
  AddExit("norden",CHAOS_GILDEN_ROOM("cl3bu8"));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl3bu10"));
  AddExit("osten",CHAOS_GILDEN_ROOM("krypta"));
  
  
}
