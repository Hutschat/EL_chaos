#include <properties.h>
#include "../gilde.h"

#define BS(x) break_string(x,78)
inherit "/std/room";


create() {
  ::create();
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
  "Du dieses Folterwerkzeug betrachtest."));
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
  "bewegen."));
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
  AddDetail(({"mensch"}),BS("Menschen... pffff :)"));
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
  AddDetail(({"chaot"}),BS("Ein Chaot zu werden ist der Sinn des Lebens."));
  AddDetail(({"sinn","leben"}),BS("Kennst Du den Film 'Der Sinn des Lebens'? "+
  "Ein absolut gewaltiger Film! :)"));
  AddDetail(({"film"}),BS("Meinst Du etwa 'Der Sinn des Lebens'?"));
  AddDetail(({"probleme","gesundheitliche probleme"}),
  BS("Was auch immer Du fuer ein Problem hast, hier kann man es absolut klein "+
  "und nebensaechlich erscheinen lassen. Und das ist eigentlich die Methode, "+
  "nach der Wuqour meistens vorgeht."));
  AddDetail(({"wuqour"}),BS("Wuqour ist der Meister der Rituale."));
  AddDetail(({"meister","rituale"}),BS("Der Meister der Rituale ist momentan "+
  "Wuqour."));
  AddDetail(({"raum"}),QueryProp(P_INT_LONG));
  AddDetail(({"geraetschaften"}),BS("Es ist eine wirre Sammlung von Dingen, "+
  "deren einziger Zusammenhang ihre dreckigen Spitzen und Kanten sind."));
  AddDetail(({"spitzen"}),BS("Sie sehen aus, als waeren sie schon diversen "+
  "Kreaturen in Maegen oder andere Koerperteile gerammt worden."));
  AddDetail(({"koerper"}),BS("Huuh, ja, reglose, aehm, tote... Vergessen wir "+
  "dieses Detail."));
  AddDetail(({"detail"}),BS("Ich sagte: VERGESSEN WIR'S!"));
  AddDetail(({"maegen"}),BS("Du hast ploetzlich gar keinen Hunger mehr."));
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
  AddDetail(({"elf","kerle","kerl"}),BS("Elfen sind wirklich lange Kerle."));
  AddDetail(({"benutzung"}),BS("Alles hier im Keller ist zwar fuerchterlich "+
  "verdreckt, scheint sich aber reger Benutzung zu erfreuen."));
  AddDetail(({"fussfessel","fussfesseln"}),BS("Du hast hier die Auswahl "+
  "zwischen Lederfesseln und Eisenketten."));
  AddDetail(({"lederfessel","lederfesseln"}),BS("Das sind wirklich dicke "+
  "Fesseln, aus denen kommt man bestimmt nicht so schnell raus."));
  AddDetail(({"ketten","eisenkette","eisenketten"}),
  BS("Die Ketten haben daumendicke und noch "+
  "dickere Ringe. Was zum Henker soll man damit festhalten? Elefanten?"));
  AddDetail(({"elefanten"}),BS("Troerooooooeeeeeeeeee!"));
  AddDetail(({"henker"}),BS("Hier siehst Du keinen Henker."));
  AddDetail(({"ringe"}),BS("Eine Kette besteht aus jeder Menge ineinander "+
  "verwurschtelter Ringe."));
  AddDetail(({"fussende","kopfende","fussseite","kopfseite"}),
  BS("Dieser Tisch hat ein Fuss- und ein "+
  "Kopfende! Jajaaa, das ist schon ein Tisch, was?"));
  AddDetail(({"arme"}),BS("Wow, Du hast gleich 2 davon!"));
  AddDetail(({"fessel","fesseln"}),BS("Diese Streckbank besitzt eine MENGE "+
  "Fesseln! :)"));
  AddDetail(({"patienten","leute"}),BS("Patienten... Leute wie Du halt."));
  AddDetail(({"operationen"}),BS("Solche Operationen koennen in fuerchterlich "+
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
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht nach Blut hier."));
  AddSounds(SENSE_DEFAULT,BS("Stille."));
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

