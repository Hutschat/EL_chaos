#include <properties.h>
#include "../gilde.h"

#define BS(x) break_string(x,78)

#define ON_BANK "cl2_cbeh_bank"
#define IN_CLOSET "cl2_cbeh_closet"
#define FOOT_AWAY "cl2_cbeh_foot"

inherit "/std/room";

int open;

string schrank_info() {
  return "Dieser 'Schrank' ist etwas, was man gemeinhin "+
  "als 'eiserne Jungfrau'\nbezeichnet. Ein Schrank, der innen mit langen "+
  "Spitzen ausgestattet sind,\nwelche jeden durchboren, welcher in betritt "+
  "und dann die Tuer schliesst. Eine\nwirklich fiese Art zu sterben.\n"+
  ((open==0)?"Die Tuer ist geschlossen.\n":"Die Tuer ist offen.\n");
}


string door_info() {
  return "Die Tuer wurde ebenfalls mit diesen scharfen "+
  "Spitzen ausgestattet. Wenn man\nsich in dem Schrank befindet, waehrend "+
  "die Tuer geschlossen wird, ist das\nbestimmt recht unangenehm und toedlich."+
  "\n"+((open==0)?"Die Tuer ist geschlossen.\n":"Die Tuer ist offen.\n");
}

create() {
  ::create();
  open = 0;
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Im Behandlungsraum");
  SetProp(P_INT_LONG,break_string(
  "\bDies ist der Behandlungsraum der Chaosgilde. Wenn ein Chaot irgendwelche "+
  "gesundheitlichen Probleme hat, so kann er sich hier von Wuqour helfen "+
  "lassen. Der Raum ist sehr gross und angefuellt mit den merkwuerdigsten "+
  "Geraetschaften.\nMitten im Raum steht ein grosser, massiver Tisch, an dessen "+
  "Fussseite diverse Ketten und Lederschlingen angebracht sind, waehrend an "+
  "der Kopfseite eine Kurbel mit einem komplexen Flaschenzug verbunden ist. "+
  "Alles sieht sehr komplex aus und ist rot von getrocknetem Blut.\n"+
  "An der Ostwand steht ein weiterer, fast ebenso grosser Tisch, der mit "+
  "Hilfmitteln aller Art ueberladen ist. Du entdeckst einige Daumenschrauben, "+
  "einen spanischen Schuh, diverse Zangen, Brenneisen und Vorschlaghaemmer "+
  "sowie eine breit gefaecherte Sammlung an Nadeln, Skalpellen, Dolchen, "+
  "Aexten und fast allem, was irgendwo eine Spitze oder Klinge aufweisst.\n"+
  "An der Nordwand entdeckst Du einen grossen, wohl 3 Meter im Durchmesser "+
  "messenden Kamin, ueber den ein stabiles Rost gelegt wurde. An dem Rost "+
  "entdeckst Du jede Menge Ketten.\n"+
  "An der Westwand schliesslich entdeckst Du einen Schrank, in dem im Innern "+
  "ueberall rot gefaerbte Spitzen angebracht sind. Du moechtest da wirklich "+
  "nicht drinn stehen, wenn jemand die Tuer schliesst...",78,0,1));
  AddDetail(({"behandlungsraum"}),BS("Jup, genau dieses ist das hier. Hier "+
  "stehtst Du grad drinnen."));
  AddDetail(({"methode"}),BS("Diese Methode ist eigentlich unfehlbar, wenn "+
  "sie auch dann und wann mit dem Tode des Patienten endet. Aber Schnitt ist "+
  "immer."));
  AddDetail(({"schnitt"}),BS("Schnitt is immer."));
  AddDetail(({"raum"}),BS("Du stehst drinn."));
  AddDetail(({"dinge"}),BS("Hier gibt es ... Dinge, von denen Du zwar schon "+
  "einmal gehoert hast, sie jedoch noch nie auf solch einem ... Haufen gese"+
  "hen hast. "));
  AddDetail(({"haufen"}),BS("Na gut, es ist kein Haufen. Im Grunde ist alles "+
  "sogar sehr schick aufgereiht und geordnet."));
  AddDetail(({"grund"}),BS("Och, Grund beschreibe ich jetzt mal nicht."));
  AddDetail(({"gilde","chaosgilde"}),BS("Die Chaosgilde ist die beste Gilde, "+
  "die es gibt!"));
  AddDetail(({"tode"}),BS("Na, Du hast ja auch schon ein paar aufm Buckel."));
  AddDetail(({"hilfsmittel"}),BS("Auf dem Instrumententisch liegen die "+
  "merkwuerdigsten Hilfsmittel rum. Wahnsinn."));
  AddDetail(({"wahnsinn"}),BS("HAHAHAHAAAHAHA! HAHAHAHAHAHAAA!\nBEWARE!!!!!!"));
  AddDetail(({"daumenschrauben","daumenschraube"}),BS("Du betrachtest die "+
  "Daumenschrauben. Du betrachtest Deinen Daumen. Du schuettelst energisch "+
  "den Kopf und erschauerst."));
  AddDetail(({"daumen"}),BS("Dein Daumen ist Dir ziemlich teuer."));
  AddDetail(({"kopf"}),BS("Dein Kopf ist Dir auch ziemlich teuer."));
  AddDetail(({"schuh","spanisher schuh"}),BS("Er besteht aus roetlich "+
  "gefaerbten Material. Du kannst ein Schaudern nicht unterdruecken, als "+
  "Du dieses Folterwerkzeug betrachtest. Der Schuh hat eine boese aussehende "+
  "Schraube an der Seite. Man koennte dort seinen Fuss "+
  "hineinstecken... Du magst garnicht daran denken..."));
  AddDetail(({"seite"}),BS("Oha. Eine boese aussehende Schraube!"));
  AddDetail(({"schraube"}),BS("Die Schraube sieht boesartig aus. Man kann "+
  "sie drehen..."));
  
  AddDetail(({"schaudern"}),BS("Du bibberst vor Dich hin."));
  AddDetail(({"folterwerkzeug"}),BS("Wuqour nennt es Medizin, andere nennen "+
  "es Folter... im Grunde sind dies alles nur Namen, oder ?"));
  AddDetail(({"namen","name","beispiel"}),BS("Nimm zum Beispiel Pubert."));
  AddDetail(({"pubert"}),BS("Pubert ist ein Name."));
  AddDetail(({"zangen"}),BS("Du siehst hier die verschiedensten Arten von "+
  "Zangen. Lange Zangen und kurze Zangen, Kneifzangen, also wirklich fast alles."));
  AddDetail(({"kneifzangen"}),BS("Die Kneifzangen sind schmutzig und mit "+
  "Blut bedeckt."));
  AddDetail(({"lange zangen","kurze zangen"}),BS("Du fragst Dich, wozu all "+
  "diese Zangen wohl benoetigt werden."));
  AddDetail(({"brenneisen"}),BS("Auf den Brenneisen ist jeweils ein grosses "+
  "'C' abgebildet. Was hier wohl gebrandmarkt wird???"));
  AddDetail(({"arm"}),BS("Zum Glueck hast Du 2 davon!"));
  AddDetail(({"glueck"}),BS("Mit dem Glueck ist das immer so ne Sache, nicht?"));
  AddDetail(({"sache"}),BS("Ne ganz heikle Sache ist das."));
  AddDetail(({"profi"}),BS("Und vertrau mir, Wuqour IST derart professionell, "+
  "dass man es fast Besessenheit nennen kann."));
  AddDetail(({"fleischfetzen"}),BS("YIK!"));
  AddDetail(({"auswahl"}),BS("Dies ist die Auswahl des Horrors..."));
  AddDetail(({"horror"}),BS("Du zitterst."));
  AddDetail(({"menge"}),BS("Das sind schon ziemlich viele Fesseln."));
  AddDetail(({"konstruktion"}),BS("Da hat sich Wuqour wirklich Muehe gegeben."));
  AddDetail(({"muehe"}),BS("Vergiss nie: Wuqour ist ein Profi."));
  AddDetail(({"einiges"}),BS("Na, ne ganze Menge..."));
  AddDetail(({"dinger"}),BS("Du meinst wohl Widerhaken, nicht?"));
  AddDetail(({"leber"}),BS("Wo ist die Leber? Wo ist die Leber? Unter Chaoten "+
  "ist dieses Spiel der absolute Renner."));
  AddDetail(({"spiel"}),BS("Es nennt sich 'Such die Leber'."));
  AddDetail(({"renner"}),BS("Der ABSOLUTE Renner."));
  AddDetail(({"rolle"}),BS("'Such die Leber' mit einer Axt zu spielen erhoeht "+
  "zwar den Schwierigkeitsgrad, aber auch den SPASS!"));
  AddDetail(({"schwierigkeitsgrad"}),BS("Mit Axt liegt er so etwa bei 2.9, "+
  "jedenfalls auf einer Skala von 3 bis Q."));
  AddDetail(({"skala","3","Q"}),BS("Die Skala geht von 3 bis Q."));
  AddDetail(({"spass"}),BS("SPAAAAAASSS!"));
  AddDetail(({"blut"}),BS("Dieser Raum ist voll von Blut. Leider ist alles "+
  "schon getrocknet."));
  AddDetail(({"ostwand"}),BS("Vor der Ostwand steht der grosse Instrumenten"+
  "tisch mit all seinen lustigen Hilfsmitteln."));
  AddDetail(({"medizin","folter"}),BS("Medizin, Folter... Im Grunde gehts "+
  "doch nur darum, dass sich der Patient nachher besser fuehlt, oder?"));
  AddDetail(({"arten"}),BS("Hier liegen die verschiedensten Arten von Hilfs"+
  "mitteln zur erfolgreichen Schmerzbereitung herum."));
  AddDetail(({"schmerzbereitung"}),BS("Siehe Schmerzen."));
  AddDetail(({"c"}),BS("Ein GROSSES 'C'."));
  AddDetail(({"schaedel"}),BS("Du fuehlst nach ... ah, er ist noch da."));
  AddDetail(({"sammlung"}),BS("So eine Sammlung hast Du noch nie gesehen."));
  AddDetail(({"besessenheit"}),BS("Wuqour ist besessen. Mehrfach."));
  AddDetail(({"dolche"}),BS("Die Dolche sehen noch relativ harmlos aus, "+
  "bis auf diverse Giftkanuelen in ihnen und einigen Widerhaken, die man "+
  "manuell ausfahren kann..."));
  AddDetail(({"giftkanuelen"}),BS("Dein Koerper gehorcht Dir nicht."));
  AddDetail(({"spitze","klinge"}),BS("Dein Teddy knuddelt Dich ein letztes mal."));
  AddDetail(({"nordwand"}),BS("Die Nordwand ist ueber und ueber mit Russ "+
  "bedeckt. Vor ihr steht ein  richtig grosses Kohlebecken, groesser als "+
  "ein Elf, mit einem schicken Rost darueber, an dem jede Menge Ketten ange"+
  "bracht sind. Ueber dem Rost beginnt dann irgendwann der Kamin. Das "+
  "Rost ist blutrot gefaerbt."));
  AddDetail(({"kohlebecken"}),BS("Im Kohlebecken befinden sich gluehende "+
  "Kohlen."));
  
  AddDetail(({"kurbel"}),BS("Sie besteht aus Eisen. Vielleicht kann man sie "+
  "ja kurbeln..."));
  AddDetail(({"flaschenzug"}),BS("Der Flaschenzug stellt wirklich eine sehr "+
  "geniale Konstruktion dar. Damit kann man bestimmt ohne viel Kraft einiges "+
  "bewegen. Am Flaschenzug ist ein Rad angebracht."));
  AddDetail(({"rad"}),BS("Mit diesem Rad kann man den Patienten auf der "+
  "Streckbank bestimmt ziemlich in die Laenge ziehen..."));
  AddDetail(({"laenge"}),BS("Hihihiiiii :-)"));
  AddDetail(({"kraft"}),BS("Genau. Ohne viel Kraft."));
  AddDetail(({"tisch 2","instrumententisch"}),BS("Der Instrumententisch ist "+
  "nicht so gross wie die Streckbank, aber immernoch gross genug. Er ist "+
  "bedeckt mit so ziemlich allem, was Zacken, Spitzen, Schneiden und/oder "+
  "boesartige Nadeln hat. Neben den gewalttaetig aussehenden Aexten siehst "+
  "Du ausserdem Skalpelle, eine breite Auswahl an Naegeln, einige Vorschlag"+
  "haemmer und jede Menge Zeugs. Alles ist mit Blut beschmiert und, offen"+
  "sichtlich durch regen Gebrauch, voellig verdreckt."));
  AddDetail(({"zeug"}),BS("Jede Menge Zeug. Das aufzuzuaehlen, wuerde dann "+
  "doch den Ramen sprengen."));
  AddDetail(({"ramen"}),BS("Egal. Den Ramen halt. Frag nich."));
  AddDetail(({"zacken","spitzen","schneiden"}),BS("An sowas kann man sich "+
  "boese verletzen!"));
  AddDetail(({"nadeln"}),BS("Diese Nadeln sind derartig verdreckt, dass man "+
  "sich bestimmt den ganzen Arm aufreisst, wenn man sie irgendwo ansetzen "+
  "will."));
  AddDetail(({"skalpell","skalpelle"}),BS("Mit solchen Geraeten kann ein "+
  "Profi einem Opfer absolut hoellische Schmerzen bereiten."));
  AddSpecialDetail(({"schmerzen"}),"mach_schmerzen");
  AddDetail(({"naegel"}),BS("Diese Naegel reichen von klein bis ganz ganz "+
  "gross. Du fragst Dich, was oder wen man hier wohl an die Waende oder "+
  "den Boden nagelt ... brrrrrr."));
  AddDetail(({"haemmer","vorschlaghaemmer"}),BS("Mit diesen Haemmern werden "+
  "wohl die verschiedenen Naegel in Decke/Boden/Waende getrieben. Es sind "+
  "durchweg schwere, massive Haemmer, mit denen man auch Schaedel oder "+
  "aehnliches einschlagen koennte."));
  AddDetail(({"gebrauch"}),BS("Alles in diesem Raum erfreut sich anscheinend "+
  "reger Benutzung."));
  AddDetail(({"wand","waende"}),BS("Jaa, die sind auch da. In der Westwand "+
  "sind einige Ketten mit Hand- und Fussschellen in die Wand eingelassen. "+
  "Ansonsten sind die Waende aehnlich verdreckt wie der Boden."));
  AddDetail(({"westwand"}),BS("In der Westwand entdeckst Du einige Ketten "+
  "mit Hand- und Fussschellen. Ausserdem steht an der Westwand dieser "+
  "schicke Schrank."));
  AddDetail(({"schellen","handschellen","fussschellen"}),BS("Diese Schellen "+
  "sind von wirklich guter Qualitaet. Wenn sie einmal angelegt wurden, "+
  "bekommt man sie alleine bestimmt nicht mehr auf."));
  AddDetail(({"decke"}),BS("Die Decke ist von Russ geschwaerzt und teilweise "+
  "sogar mit eingetrocknetem Blut bedeckt. Du fragst Dich, wie das wohl dort "+
  "hingekommen ist. Unter all diesem Dreck jedoch entdeckst Du ein Bild, "+
  "welches die komplette Decke einnimmt."));
  AddDetail(({"dreck"}),BS("Blut, Russ, Staub, Fleischfetzen, hier findet man "+
  "fast alles."));
  AddDetail(({"russ"}),BS("Waende und Decke sind mit Russ bedeckt."));
  AddDetail(({"staub"}),BS("Die letzte Putzfrau endete auf dem Ofen. "+
  "Sie wusste zuviel."));
  AddDetail(({"putzfrau","putzfrauen"}),
  BS("Putzfrauen, die sich selbst fuer intellektuell "+
  "halten, kann Wuqour ja garnicht leiden."));
  AddDetail(({"bild"}),BS("Es stellt eine gewaltige, haessliche, Daemonen"+
  "fratze dar, mit leuchtend roten Augen und einem gewaltigen Maul und einem "+
  "extremen Unterbiss. Die Zaehne sind messerscharf und muessen, wenn das "+
  "die richtigen Proportionen sind, wohl einen halben Meter gross sein. Die "+
  "Augen scheinen wirklich zu leuchten und Dir durch den Raum zu folgen..."));
  AddDetail(({"daemonen","daemon"}),BS("Wenn er wirklich so gross ist wie "+
  "auf diesem Bild, so muss er mehr als zehn- bis zwanzigmal so gross wie "+
  "ein Mensch sein. Welch beunruhigende Vorstellung."));
  AddDetail(({"proportionen"}),BS("Man muss das alles in den richtigen "+
  "Proportionen sehen :)"));
  AddDetail(({"mensch","menschen"}),BS("Menschen... pffff :)"));
  AddDetail(({"vorstellung"}),BS("Die Vorstellung ist vorbei, kommt wann "+
  "anders wieder."));
  AddDetail(({"maul","unterbiss","unterkiefer","oberkiefer"}),
  BS("Das Maul besitzt fuenf Reihen messer"+
  "scharfer Zaehne, zumindest im Unterkiefer. Deshalb schaut dieser "+
  "weit ueber den Oberkiefer heraus. Welch merkwuerdige Kreatur."));
  AddDetail(({"daemonenfratze"}),BS("Meinst Du das Bild? Ja, bestimmt meinst "+
  "Du das Bild."));
  AddDetail(({"zaehne"}),BS("Es sind messerscharfe, Zaehne von wohl einem "+
  "halben Meter groesse... entsetzlich."));
  AddDetail(({"augen"}),BS("Sie leuchten und folgen Dir durch den Raum, ganz "+
  "als ob das garkein Bild waere, sonder als ob es ... leben ... wuerde..."));
  AddDetail(({"boden"}),BS("Der Boden ist voellig verdreckt und von rostroter "+
  "Farbe."));
  AddDetail(({"farbe"}),BS("Es ist die Farbe getrockneten Blutes."));
  AddDetail(({"chaot","chaoten"}),BS("Ein Chaot zu werden ist der Sinn des Lebens."));
  AddDetail(({"sinn","leben"}),BS("Kennst Du den Film 'Der Sinn des Lebens'? "+
  "Ein absolut gewaltiger Film! :)"));
  AddDetail(({"film"}),BS("Meinst Du etwa 'Der Sinn des Lebens'?"));
  AddDetail(({"probleme","problem","gesundheitliche probleme"}),
  BS("Was auch immer Du fuer ein Problem hast, hier kann man es absolut klein "+
  "und nebensaechlich erscheinen lassen. Und das ist eigentlich die Methode, "+
  "nach der Wuqour meistens vorgeht."));
  AddDetail(({"wuqour"}),BS("Wuqour ist der Meister der Rituale."));
  AddDetail(({"meister","rituale"}),BS("Der Meister der Rituale ist momentan "+
  "Wuqour."));
  AddDetail(({"raum"}),QueryProp(P_INT_LONG));
  AddDetail(({"geraetschaften"}),BS("Es ist eine wirre Sammlung von Dingen, "+
  "deren einziger Zusammenhang ihre dreckigen Spitzen und Kanten sind."));
  AddDetail(({"spitzen","kanten"}),
  BS("Sie sehen aus, als waeren sie schon diversen "+
  "Kreaturen in Maegen oder andere Koerperteile gerammt worden."));
  AddDetail(({"koerper"}),BS("Huuh, ja, reglose, aehm, tote... Vergessen wir "+
  "dieses Detail."));
  AddDetail(({"detail"}),BS("Ich sagte: VERGESSEN WIR'S!"));
  AddDetail(({"maegen"}),BS("Du hast ploetzlich gar keinen Hunger mehr."));
  AddDetail(({"koerperteile"}),BS("*Brrrr* Du kannst viele von ihnen gar"+
  "nicht mehr erkennen. Ist das alles EKELHAFT!"));
  AddDetail(({"hunger"}),BS("Och, noeeeh, jetzt nicht."));
  AddDetail(({"tisch","tische"}),BS("Es gibt zwei Tische hier, nennen wir sie "+
  "Tisch 1 und Tisch 2. Wahlweise koennte man sie jedoch auch Streckbank und "+
  "Instrumententisch nennen. Wir sind da extrem flexibel."));
  AddDetail(({"tisch 1","streckbank"}),BS("Man muss nur einen kurzen Blick auf "+
  "diesen Tisch werfen, um die Streckbank zu erkennen. Er ist wohl doppelt so "+
  "gross wie ein Elf und scheint sich reger Benutzung zu erfreuen. "+
  "Die Fussfesseln an seinem Fussende stehen wahlweise dicke Stahlketten oder "+
  "feste Lederfesseln zur Auswahl. Der Koerper wird ausserdem mit einer "+
  "starken Eisenkette am Tisch gehalten. Die Arme werden dann in dicken Fesseln "+
  "mit diesem Flaschenzug am Kopfende des Tisches befestigt und sind dann "+
  "bereit, ein wenig gestreckt zu werden. Der Tisch sieht allerdings derart "+
  "aus, als ob er auch dazu benutzt wuerde, Patienten hier erst mal festzust"+
  "recken und dann erheiternde Operationen an ihnen vorzunehmen, in denen "+
  "Aexte eine nicht unbedeutende Rolle spielen."));
  AddDetail(({"blick"}),BS("Du wirfst ein paar Blicke in den Raum."));
  AddDetail(({"elf","kerle","kerl","elfen"}),
  BS("Elfen sind wirklich lange Kerle."));
  AddDetail(({"benutzung"}),BS("Alles hier im Keller ist zwar fuerchterlich "+
  "verdreckt, scheint sich aber reger Benutzung zu erfreuen."));
  AddDetail(({"fussfessel","fussfesseln"}),BS("Du hast hier die Auswahl "+
  "zwischen Lederfesseln und Eisenketten."));
  AddDetail(({"lederfessel","lederfesseln"}),BS("Das sind wirklich dicke "+
  "Fesseln, aus denen kommt man bestimmt nicht so schnell raus."));
  AddDetail(({"ketten","stahlketten","eisenkette","eisenketten"}),
  BS("Die Ketten haben daumendicke und noch "+
  "dickere Ringe. Was zum Henker soll man damit festhalten? Elefanten?"));
  AddDetail(({"elefanten"}),BS("Troerooooooeeeeeeeeee!"));
  AddDetail(({"henker"}),BS("Hier siehst Du keinen Henker."));
  AddDetail(({"ringe","kette"}),BS("Eine Kette besteht aus jeder Menge ineinander "+
  "verwurschtelter Ringe."));
  AddDetail(({"fussende","kopfende","fussseite","kopfseite"}),
  BS("Dieser Tisch hat ein Fuss- und ein "+
  "Kopfende! Jajaaa, das ist schon ein Tisch, was?"));
  AddDetail(({"arme"}),BS("Wow, Du hast gleich 2 davon!"));
  AddDetail(({"fessel","fesseln"}),BS("Diese Streckbank besitzt eine MENGE "+
  "Fesseln! :)"));
  AddDetail(({"patienten","leute"}),BS("Patienten... Leute wie Du halt."));
  AddDetail(({"operationen","operation"}),BS("Solche Operationen koennen in fuerchterlich "+
  "lustige Parties ausarten! Schade ist nur, dass der Patient meisst mitten "+
  "waehrend des 'Such die Leber'-Spiels zusammenklappt."));
  AddDetail(({"axt","aexte"}),BS("Da liegen einige wirklich blutig und "+
  "ausserordentlich fies aussehende Aexte auf Tisch 2. Du fragst Dich, "+
  "ob Aexte mit Widerhaken eigentlich wirklich vorteilhafte Operationsmittel "+
  "sind oder nicht..."));
  AddDetail(({"widerhaken"}),BS("Haessliche Dinger, solche Widerhaken..."));
  AddDetail(({"mittel","operationshilfsmittel","operationsmittel"}),
  BS("Du bezweifelst, das Aexte mit Widerhaken wirklich nuetzliche "+
  "Hilfsmittel fuer eine Operation darstellen. Obwohl, fuer Wuqour vielleicht "+
  "schon..."));
  AddDetail(({"durchmesser"}),BS("Dieser Kamin hat einen Durchmesser von "+
  "etwa drei Metern."));
  AddDetail(({"meter"}),BS("Du weisst was ein Meter ist."));
  AddDetail(({"eisen"}),BS("Eisen ist ein Metall."));
  AddDetail(({"metall"}),BS("Nimm zum Beispiel Eisen!"));
  AddDetail(({"fuss","fuesse"}),BS("Hier gibt es Fussschellen fuer jeden "+
  "Geschmack und jede Groesse!"));
  AddDetail(({"geschmack"}),BS("IGITT! Also, aehm, wirklich, reden "+
  "wir doch lieber nicht vom Geschmack von Fuessen, ok???"));
  AddDetail(({"groesse","groessen"}),BS("Fuesse koennen wirklich unterschiedliche "+
  "Groessen haben. Nimm zum Beispiel Hobbit- und Elfenfuesse!"));
  AddDetail(({"hobbitfuesse","elfenfuesse"}),BS("Hobbitfuesse sind richtig "+
  "dicke Dinger, also, WIRKLICHE Kawenzmaenner, sozusagen. Elfenfuesse sind "+
  "dagegen so klein, dass man sich fragt, wie die Kerle sich damit aufrecht "+
  "halten koennen..."));
  AddDetail(({"kawenzmaenner"}),BS("Hobbits sind mehr Fuss als Hobbit. "+
  "Sozusagen."));
  AddDetail(({"hobbits","hobbit"}),BS("Hobbits sind dooof. So. Ha!"));
  AddDetail(({"hand","haende"}),BS("Hihi, ich gebs ja offen zu: Nicht alles "+
  "hier hat Hand UND Fuss :-)"));
  AddDetail(({"kamin"}),BS("Der Kamin ist dunkelrot, fast schwarz gefaerbt. "+
  "Es ist ein gewaltiges, massives Biest von bemerkenswerten Proportionen. "+
  "Er befindet sich ueber einer Feuerstelle, welche einen Durchmesser von "+
  "wohl 3 Metern hat. In ihr gluehen schwarz Kohlen in einem daemonichem "+
  "... schwarz! Du fragst Dich, ob Wuqour wohl eine Leiche in seinem Kamin "+
  "versteckt hat :-)"));
  AddDetail(({"biest"}),BS("RENN! RENN SCHNELL!"));
  AddDetail(({"proportionen"}),BS("Die Proportionen sind wirklich gewaltig!"));
  AddDetail(({"feuerstelle"}),BS("Die Feuerstelle hat einen Durchmesser "+
  "von 3 Metern. Sie ist mit einem Ring schwarzer Steine befestigt, auf "+
  "denen ein grosses, stabiles Rost gelegt wurde. In der Feuerstelle gluehen "+
  "schwarze Kohlen vor sich hin und verbreiten eine wahrhaft hoellische "+
  "Hitze."));
  AddDetail(({"ring"}),BS("Die Feuerstelle wird, wie schon erwaehnt, durch "+
  "einen Ring schwarzer Steine befestigt."));
  AddDetail(({"steine"}),BS("Wow. Die schwarzen Steine hier sind nicht mal "+
  "warm. Erstaunlich. Wieder einmal fragst Du Dich, was das fuer Steine "+
  "sind, aus denen diese Burg gebaut wurde."));
  AddDetail(({"burg"}),BS("Du befindest Dich in der schwarzen Burg."));
  AddDetail(({"kohlen","kohle"}),BS("Die Kohlen in der Feuerstelle sind "+
  "fuerchterlich, geradezu hoellisch heiss. Sie gluehen auch, jedoch in "+
  "einem daemonischen, lediglich dunkel erscheinendem Schwarz."));
  AddDetail(({"schwarz"}),BS("Diese Kohlen sind wirklich ... ungewoehnlich. "+
  "Boesartig. Satanisch. Anders."));
  AddDetail(({"gluehen"}),BS("Das Gluehen dieser Kohlen ist eine merkwuer"+
  "dige Art von Schwarz."));
  AddDetail(({"eisberg"}),BS("Diese Burg befindet sich in einem grossen, "+
  "schwarzen Eisberg."));
  AddDetail(({"rost"}),BS("Auf dem Rost wurden diverse Ketten befestigt. "+
  "Hier lagen die Patienten wohl, wenn sie fuer die Waermetherapie einge"+
  "tragen wurden. Das Rost ist in einem dunklen Rot, fast schwarz einge"+
  "faerbt und ist groesstenteils mit Russ bedeckt."));
  AddDetail(({"rot"}),BS("Rot ist eine Farbe."));
  AddDetail(({"leiche"}),BS("Um sie zu finden, muesstest Du schon in "+
  "den Kamin klettern!"));
  AddDetail(({"keller"}),BS("Ups, das war wohl ein Verschreiber. Das hier "+
  "ist ja garkein Keller (obwohl alles hier sehr gut in einen Keller "+
  "passen wuerde..."));
  AddDetail(({"verschreiber"}),BS("Verzeih mir!"));
  AddDetail(({"kreatur","kreaturen"}),BS("Welche Kreaturen in diesen "+
  "Raeumlichkeiten wohl schon alles behandelt wurden? Und wieviele ueberlebt "+
  "haben, um davon zu berichten ... das alles sind Fragen, auf die man "+
  "besser keine Antwort suchen sollte. Ansonsten koennte es naemlich "+
  "schnell pasieren, dass man zuviel weiss. Und das ist bei Wuqour "+
  "ein richtig grosses (und toedliches) Problem."));
  AddDetail(({"raeumlichkeiten"}),BS("Du willst hier eigenltich nurnoch "+
  "raus."));
  AddDetail(({"fragen"}),BS("In dieser Burg sollte man wirklich aufpassen, "+
  "welche Fragen man stellt..."));
  AddDetail(({"antwort"}),BS("Hier stellt sich wirklich folgendes Raetsel: "+
  "Was ist gefaehrlicher: Die Frage ... oder die Antwort, die man auf "+
  "sie erhaelt?"));
  AddDetail(({"raetsel"}),BS("Was ist die Wurzel aus 443556?"));
  AddDetail(({"taschenrechner"}),BS("So einen siehst Du hier wirklich nicht!"));
  AddDetail(({"lederschlingen","lederschlinge"}),BS("Die Lederschlingen "+
  "sind noch das Angenehmste hier in diesem Raum."));
  AddDetail(({"material"}),BS("Das muss eine Art Metall sein!"));
  AddDetail(({"ofen"}),BS("Der Ofen besteht aus dem Kamin und der Feuerstelle."));
  AddDetail(({"opfer","patient"}),
  BS("Du schaust Dich um. Du schaust an Dir herab. "+
  "Dir wird ganz anders."));
  AddDetail(({"parties","party"}),BS("Chaoten koennen Parties feiern, da wird "+
  "wird einem ganz anders. Also ... WIRKLICH anders! Sozusagen schlecht! Also, "+
  "wirklich schlecht!"));
  AddDetail(({"qualitaet"}),BS("Das sind wirklich alles gute Handschellen "+
  "von ganz erlesener Qualitaet. Die haben schon so manchen aufgehalten."));
  AddSpecialDetail("schrank","schrank_info");
  AddDetail(({"art"}),BS("Dieses Detail ist vorhanden."));
  AddDetail(({"jungfrau","eiserne jungfrau"}),BS("Du hast absolut Recht. "+
  "Dieser Schrank ist in Wirklichkeit eine eiserne Jungfrau!"));
  AddDetail(({"recht","ordnung"}),BS("Recht und Ordnung ?*huestel* Sagen "+
  "wirs mal so: Vergiss es :-)"));
  AddDetail(({"wirklichkeit"}),BS("Gibs zu, Du kannst die Wirklichkeit doch "+
  "garnicht ertragen!"));
  AddSpecialDetail("tuer","door_info");
  AddDetail(({"zusammenhang"}),BS("Hehe. Hier lernst Du abstraktes Denken :)"));
  AddDetail(({"denken","abstraktes denken"}),BS("Schoene Sache das!"));
  AddDetail(({"buckel"}),BS("Trag ihn mit Wuerde... :-)"));
  
  AddSpecialDetail(({"prinzessin"}),"det_princess");
  
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht nach Blut hier."));
  AddSounds(SENSE_DEFAULT,BS("Stille."));
  
  AddSpecialExit("norden","ex_norden");
  
  AddCmd(({"verzeih","verzeihe"}),"absolution");
  AddCmd(({"kletter","klettere"}),"climb");
  AddCmd(({"sag","sage","antworte"}),"sach");
  AddCmd(({"gib","gebe"}),"give_in");
  AddCmd(({"trag","trage"}),"tragen");
  AddCmd(({"lege","liege"}),"lay_down");
  AddCmd(({"steh","stehe"}),"stand_up");
  AddCmd(({"loes","loese"}),"open_bounds");
  AddCmd(({"dreh","drehe","bewege"}),"move_wheel");
  AddCmd(({"steck","stecke"}),"stick_in");
  AddCmd(({"zieh","ziehe"}),"pull_out");
  AddCmd(({"oeffne"}),"open_door");
  AddCmd(({"betritt","betrete"}),"enter_closet");
  AddCmd(({"schliess","schliesse"}),"close_door");
    
  
  
  
}
/*
#define ON_BANK "cl2_cbeh_bank"
#define IN_CLOSET "cl2_cbeh_closet"
#define FOOT_AWAY "cl2_cbeh_foot"
*/

int fakekill(string str1, string str2,object opfer)
{
    object ob;
    SetProp(P_KILL_NAME,str1);
    SetProp(P_KILL_MSG,str2);
    opfer->SetProp(P_GHOST,1);
    ob = clone_object("/room/death/death_mark");
    if (!objectp(ob)) return 1;
    ob->move(opfer,M_NOCHECK);
    return 1;
}



mixed check_used_obj(string str)
{
   object *ob;
   int i;
   ob = all_inventory(this_object()) & users();
   for (i=sizeof(ob)-1;i>=0;i--) if (ob[i]->QueryProp(str)) return ob[i];
   return 0;
}

string check_used(string str)
{
   object ob;
   ob = check_used_obj(str);
   if (objectp(ob)) return ob->Name(WER);
   return 0;
}

int lay_down(string was) {
   string str;
  
   if (was == "auf rost" || was == "in kamin")
     return write("Ja bist Du denn deppert?\n"+
                  "Die Hitze wuerde Dich umbringen!\n"),1;

   if (was != "auf bank" && was != "auf streckbank" &&
       was != "auf tisch")
      return notify_fail("Worauf moechtest Du liegen?\n"),0;
   if (this_player()->QueryProp(ON_BANK))
     return write("Da liegst Du schon drauf!\n"),1;
   if (this_player()->QueryProp(IN_CLOSET))
     return write("Du befindest Dich gerade in der eisernen Jungfrau!\n"),1;
   if (this_player()->QueryProp(FOOT_AWAY))
     return write("Dein Fuss ist gewissermassen festgeschraubt.\n"),1;
   if ((str = check_used(ON_BANK))) 
     return write(str+" liegt aber schon auf der Bank!\n"),1;
   
   write(BS("Du legst Dich auf die Streckbank, legst provisorisch die "+
   "Ketten an und sagst: OK Jungs, zieht an!"));
   say(BS(this_player()->Name(WER)+" legt sich auf die Streckbank, kettet sich "+
   "provisorisch an und sagt: OK, zieht an, Leute!"),this_player());
   this_player()->SetProp(ON_BANK,1);
   return 1;
}

int stand_up(string was) {
   if (was != "auf" && was != 0)
      return notify_fail("Moechtest Du etwa aufstehen?\n"),0;
   if (!this_player()->QueryProp(ON_BANK))
     return write("Da liegst garnicht auf der Bank!\n"),1;
   if (this_player()->QueryAttribute(A_DEX)<=random(30)) {
     write("Du versuchst, Deine Fesseln zu loesen, doch es will nicht klappen!\n");
     say(this_player()->Name(WER)+" versucht vergeblich, seine Fesseln zu loesen.\n",this_player());
     return 1;
   }
   write(BS("Du schaffst es, Deine Fesseln zu loesen und erhebst Dich!"));
   say(BS(this_player()->Name(WER)+" loest seine Fesseln und erhebt sich von "+
   "der Streckbank!"),this_player());
   this_player()->SetProp(ON_BANK);
   return 1;
}  

int open_bounds(string was) {
  string wer;
  object ob;
  if (!was || sscanf(was,"fesseln von %s",wer)<1)
    return notify_fail("Der Syntax waere 'losese fesseln von <Name>'.\n"),0;
  if (!(ob=present(wer,this_object())))
    return write("Aber "+capitalize(wer)+" ist doch garnicht hier...\n"),1;
  if (!ob->QueryProp(ON_BANK))
    return write("Aber "+capitalize(wer)+" ist doch garnicht angeschnallt!\n"),1;
  if (this_player()->QueryProp(IN_CLOSET))
    return write("Du bist gerade im Schrank...\n"),1;
  if (this_player()->QueryProp(FOOT_AWAY))
    return write("Erst mal solltest Du Dir was wegen Dieses Schuhs ueberlegen!\n"),1;
  if (ob == this_player())
    return stand_up("auf");
  
  write("Du loest "+ob->name(WESSEN)+" Fesseln.\n"+
        ob->Name(WER)+" steht auf.\n");
  tell_object(ob,this_player()->Name(WER)+" loest Deine Fesseln. Du stehst auf.\n");
  tell_room(this_object(),this_player()->Name(WER)+" loest "+ob->name(WESSEN)+
            " Fesseln.\n"+ob->Name(WER)+" steht auf.\n",({this_player(),ob}));
  ob->SetProp(ON_BANK);
  return 1;
}

int move_wheel(string was) {
   object ob;
   
   if (was == "schraube") {
     if (this_player()->QueryProp(ON_BANK))
       return write("Sorry, Du bist angekettet!\n"),1;
     if (this_player()->QueryProp(IN_CLOSET))
       return write("Nein, Du bist gerade im Schrank und musst erst mal raus.\n"),1;
     write("Du drehst an der Schraube am Schuh.\n");
     say(this_player()->Name(WER)+" dreht an der Schraube am Schuh.\n",
         this_player());
     
     ob = check_used_obj(FOOT_AWAY);
     if (!objectp(ob))
       return tell_room(this_object(),"Es passiert nich viel.\n"),1;
     if (present("\nchaos_badfoot",ob))
       return write("Dein Fuss ist schon hin, es passiert nicht viel.\n"),1;
     
     if (!random(4)) {
       write("Oh oooh. Das war wohl zu fest. Der Fuss ist hin.\n");
       tell_object(ob,"Du spuerst, wie deine Knochen brechen und dein Fuss zu Muss\n"+
                      "zermatscht wird.\n");
       tell_room(this_object(),"Der Fuss von "+ob->name(WEM)+" bricht "+
                 "und wird zerquetscht.\n",({ob,this_player()}));
       ob->reduce_hit_point(10+random(10));
       if (ob->QueryProp(P_HP) < 3)
         fakekill(this_player()->Name(WER),"Was man mit einem spanischen Schuh nicht "+
                  "alles machen kann...",ob);
       ob->SetProp(FOOT_AWAY);
       clone_object(CHAOS_GILDEN_OBJ("cl2_badfoot"))->move(ob,M_NOCHECK);
       return 1;
     }
     tell_object(ob,"WAAAAAAAAAAH! Verdammt tut das WEH!!!\n");
     tell_room(this_object(),ob->Name(WER)+" zuckt wild hin und her.\n",({ob}));
     return 1;
   }
   
   if (was != "rad")
     return notify_fail("Willst Du etwa das Rad drehen?\n"),0;
   if (this_player()->QueryProp(ON_BANK))
     return write("Sorry, Du bist angekettet!\n"),1;
   if (this_player()->QueryProp(IN_CLOSET))
     return write("Nein, Du bist gerade im Schrank und musst erst mal raus.\n"),1;
   if (this_player()->QueryProp(FOOT_AWAY))
     return write("Mit diesem Fuss machst Du erstmal garnix.\n"),1;
     
   write("Du drehst am Rad.\n");
   say(this_player()->Name(WER)+" dreht am Rad des Flaschenzugs.\n",this_player());
   ob = check_used_obj(ON_BANK);
   if (!objectp(ob))
     return tell_room(this_object(),"Es passiert nich viel.\n"),1;
   
   ob->reduce_hit_point(random(20));
   tell_object(ob,({"Du schreisst vor Schmerzen.\n",
                    "Du beisst tapfer die Zaehne zusammen.\n",
                    "Verdammt TUT DAS WEH!\n",
                    "AAAAAAAAAAAARRRRRRRRRRRRRGGGGGHHHHH!\n"})[random(4)]);
   tell_room(this_object(),ob->Name(WER)+" windet sich vor Schmerzen.\n",
             ({ob}));
   if (ob->QueryProp(P_HP) < 3)  // death
     fakekill(this_player()->Name(WER),"Ich habe ihn zu Tode gefoltert. HAHAHAAHAAAA!\n",ob);
   return 1;
}

int stick_in(string was) {
   string str;
   
   if (was == "daumen in daumenschraube" || was == "daumen in schraube")
     return write("Du steckst einen Daumen in die Daumenschraube.\n"+
            "Du erschauerst. Du ziehst den Daumen wieder heraus.\n"+
            "Nein Nein Nein.\n"),1;
            
   if (was != "fuss in schuh" && was != "fuss in spanischen schuh")
     return notify_fail("Was willst Du wo reinstecken?\n"),0;

   if (this_player()->QueryProp(ON_BANK))
     return write("Du bist gerade etwas festgeschnallt...\n"),1;
   if (this_player()->QueryProp(FOOT_AWAY))
     return write("Dein Fuss steckt schon tief genug drinnen...\n"),1;
   if (this_player()->QueryProp(IN_CLOSET))
     return write("Du stehst gerade im Schrank, wenn ich das bemerken darf.\n"),1;
   if ((str = check_used(FOOT_AWAY)))
     return write(str+" hat seine Fuss gerade im Schuh!\n"),1;
   if (present("\nchaos_badfoot",this_player()))
     return write("Dein Fuss ist schon hin, vergiss es.\n"),1;
     
   write("Du steckst Deinen Fuss in den spanischen Schuh. Oh Ohhhhh.\n"+
   "Mit 'ziehe fuss aus schuh' kriegst Du ihn (hoffentlich) wieder raus...\n");
   say(this_player()->Name(WER)+" steckt seinen Fuss in den spanischen Schuh.\n",
       this_player());
   this_player()->SetProp(FOOT_AWAY,1);
   return 1;
}

int pull_out(string was) {
  if (was != "fuss aus schuh")
    return notify_fail("Was willst Du woraus ziehen?\n"),0;
  if (!this_player()->QueryProp(FOOT_AWAY))
    return write("Aber dein Fuss ist garnicht im Schuh!\n"),1;
  
  this_player()->SetProp(FOOT_AWAY);
  write("Du ziehst Deinen Fuss aus dem Schuh und seufzst erleichtert.\n");
  say(this_player()->Name(WER)+" zieht seinen Fuss aus dem Schuh.\n",this_player());
  return 1;
}

string mach_schmerzen()
{
  if (!present("\nchaos_schmerzen",this_player()))
  {
     clone_object("/d/polar/files.chaos/obj/schmerzen")->move(this_player());
     return "Das sind Schmerzen:\n";
  }
  return "Du weisst jetzt so ungefaehr, was Schmerzen sind.\n";
}


int absolution(string was) {
   if (!was || was == "dir" || was == "feuerwehr")
   {
      say(this_player()->Name(WER)+" verzeiht Feuerwehr.\n",this_player());
      write("Ich bin sehr froh. Danke Danke Danke!\n");
      return 1;
   }
   if (was == "nicht")
   {
       say(this_player()->Name(WER)+" verzeiht Feuerwehr nicht.\n",
           this_player());
       write("*Sniff* Es tut mir laaaaaaaaaaaaaaiiiiiiiiiiiiiidd!\n");
       return 1;
    }
    notify_fail("Wem willst Du (nicht) verzeihen?\n");
    return 0;
}

int climb(string was) {
  if (was != "in kamin")
    return notify_fail("Wohin moechtest Du klettern?\n"),0;
  write("Bist Du verrueckt? Die Hitze der Kohlen wuerde Dich umbringen!\n");
  say(BS(this_player()->Name(WER)+" versucht, in den Kamin zu klettern, muss "+
  "jedoch aufgeben."),this_player());
  return 1;
}

int sach(string was) {
  if (was != "666")
     return 0;
  write("Heyyyy, hat da jemand den Taschenrechner benutzt? Graats!\n");
  return 1;
}

int give_in(string was) {
  if (was == "es zu")
  {
     write("HA! Siehst Du! SUCHTIEEE! SUCHTIEEE!\n");
     return 1;
  }
  if (was == "es nicht zu")
  {
     write("Du befindest Dich noch in der "+
           "Leugnen-Phase, was? Na, das kommt noch!\n");
     return 1;
  }
  return 0;
  
}

int tragen(string was) {
  if (was == "buckel mit wuerde") {
    write("Du traegst Deinen Buckel mit viel Wuerde.\n");
    return 1;
  }
  if (was == "buckel ohne wuerde") {
    write("Naja, dann eben nicht :-).\n");
    return 1;
  }
  return 0;
}

int open_door(string was) {
  if (was != "tuer")
    return notify_fail("Was moechtest Du oeffnen?\n"),0;
  if (open)
    return write("Die Tuer ist schon offen!\n"),1;
  if (this_player()->QueryProp(ON_BANK))
    return write("Du bist gerade etwas festgeschnallt...\n"),1;
  if (this_player()->QueryProp(FOOT_AWAY))
    return write("Dein Fuss steckt gerade fest...\n"),1;
  if (this_player()->QueryProp(IN_CLOSET))
    write("Du stehst gerade im Schrank, wenn ich das bemerken darf.\nAber egal.\n");
  write("Du oeffnest die Tuer.\n");
  say(this_player()->Name(WER)+" oeffnet die Tuer der eisernen Jungfrau.\n",this_player());
  open = 1;
  return 1;
}


int close_door(string was) {
  object ob;
  if (was != "tuer")
    return notify_fail("Was moechtest Du schliessen?\n"),0;
  if (!open)
    return write("Die Tuer ist schon geschlossen!\n"),1;
  if (this_player()->QueryProp(ON_BANK))
    return write("Du bist gerade etwas festgeschnallt...\n"),1;
  if (this_player()->QueryProp(FOOT_AWAY))
    return write("Dein Fuss steckt gerade fest...\n"),1;
  write("Du schliesst die Tuer.\n");
  say(this_player()->Name()+" schliesst die Tuer der eisernen Jungfrau.\n",this_player());
  ob = check_used_obj(IN_CLOSET);
  tell_object(ob,"Der Boden oeffnet sich und Du faellst in "+
                 "die Tiefe, bevor die Spitzen Dich\nerreichen.\n");
  tell_room(CHAOS_GILDEN_ROOM("cl2_cbeh2"),this_player()->Name(WER)+"faellt herein.\n");
  ob->move(CHAOS_GILDEN_ROOM("cl2_cbeh2"),M_GO,"",M_SILENT);
  ob->SetProp(IN_CLOSET,0);
  open = 0;
  return 1;
}

int enter_closet(string was) {
  object ob;
  if (was != "schrank" && was != "jungfrau")
    return notify_fail("Was moechtest Du betreten?\n"),0;
  if (!open)
    return write("Die Tuer ist geschlossen!\n"),1;
  if (this_player()->QueryProp(ON_BANK))
    return write("Du bist gerade etwas festgeschnallt...\n"),1;
  if (this_player()->QueryProp(FOOT_AWAY))
    return write("Dein Fuss steckt gerade fest...\n"),1;
  if (this_player()->QueryProp(IN_CLOSET))
    return write("Du stehst gerade im Schrank, wenn ich das bemerken darf.\n"),
  ob = check_used_obj(IN_CLOSET);
  if (objectp(ob))
    return write("Aber "+ob->Name(WER)+" benutzt bereits den Schrank!\n"),1;
  write("Du betrittst den Schrank. Ooooooh Ooooooooh.\n");
  say(this_player()->Name(WER)+" betritt die eiserne Jungfrau. Heheheeee.\n",
      this_player());
  this_player()->SetProp(IN_CLOSET,1);
  return 1;
}


int ex_norden() {
  if (this_player()->QueryProp("chaos_behandlung") &&
      present("wuqour",this_object()))
      return write("Du kannst Dich nicht bewegen. Wuqour behandelt Dich gerade.\n"),1;
  this_player()->move(CHAOS_GILDEN_ROOM("cl2_critual"),M_GO,"nach Norden");
  return 1;
}


string int_long(object ob1,object ob2)
{
  if (ob1->QueryProp("chaos_frog"))
    return ::int_long(ob1,ob2)+"Eine wuuunderschoene Prinzessin.\n";
  return ::int_long(ob1,ob2);
}

string det_princess() {
  if (this_player()->QueryProp("chaos_frog"))
    return "WAAAAAAAAAH! IST DIE SUEEEEESSS! NIMM SIE WEG! NIMM SIE WEG!\n";
  return "So etwas siehst Du hier nicht.\n";
} 