//---------------------------------------------------------------------------//
//                   (c) 18/04/98 Tilly@mg.uni-muenster.de                   //
//---------------------------------------------------------------------------//

/*
Letzte Aenderung:

21/08/00 Jenandra (Typos)

*/

inherit "std/room";
#include <properties.h>
#include <rooms.h>
#include <combat.h>
#include "gilde.h"
#include <language.h>
#include <moving.h>
#include <new_skills.h>
#include "gilde.h"
#include <wizlevels.h>

#define BS break_string

static int licht_da = 1;
static int holz_da = 1;

void create(){
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INT_SHORT,"Die Bibliothek des Chaos");
  SetProp(P_INT_LONG,
   BS("Inmitten von umgestuerzten Regalen und hunderten von Buechern, "
    "Schriftrollen und anderen Zeugnissen der Druckkunst stehst Du in "
    "der Bibliothek, die dem Aussehen nach nur zu gut zu dieser Gilde "
    "passt. Zum Teil zu Stapeln aufgetuermt oder achtlos und zerfleddert "
    "beiseite geworfen, liegen die Schriftstuecke ueberall herum und "
    "bilden ein wahres Durcheinander. Vom Boden kannst Du so gut wie "
    "nichts erkennen, an den Waenden haengen die Reste von Regalen und "
    "von der Decke baumelt das anscheinend einzig intakte Stueck "
    "dieses Raumes: Ein riesiger schwarzer Kronleuchter.",78)); 
  AddDetail(({"boden","fussboden"}),
   BS("Der Fussboden ist ueber und ueber bedeckt von Buechern, "
    "Schriftrollen, Ueberreste der Regale und anderen Kleinigkeiten. "
    "Von dem urspruenglichen Belag ist nichts mehr zu erkennen. Einzig ein "
    "Haufen in der einen Ecke erregt Deine Aufmerksamkeit.",78));
  AddDetail(({"gilb"}),
   "Dr. Beckmann kommt herein.\n"
   "Der Doktor packt den sich lebhaft wehrenden Gilb am Kragen und schleift\n"
   "ihn hinter sich her.\n"
   "Dr. Beckmann geht.\n");
  AddDetail(({"dr","doktor","dr beckmann","doktor beckmann"}),
   BS("Der hat eben den Gilb abgeholt.",78));
  AddDetail(({"kragen"}),
   BS("Der wurde eben mit dem Gilb zusammen abgeholt.",78));
  AddDetail(({"riss","risse"}),
   BS("Jaja, die Schriftrollen wurden nicht immer pfleglich behandelt.",78));
  AddDetail(({"schmutz"}),
   BS("Hoehoe, davon gibt es hier zuviel. Drueck Dich etwas genauer aus.",78));   
  AddDetail(({"decke"}),
   BS("Die Decke besteht aus einem mattglaenzenden, schwarzen Gestein. Sie "
    "ist ueber und ueber bedeckt mit Ornamenten und Verzierungen, die ein "
    "riesiges Pentagramm umrunden, in dessen Mitte ein Kronleuchter "
    "angebracht ist.",78));
  AddDetail(({"wand","waende"}),
   BS("An den Waenden haengen immer noch die Ueberreste der Regale, die wohl "
    "einst dort gehangen haben. Jedenfalls sind sie jetzt kahl und eroeffnen "
    "einen Blick auf das Material, aus denen sie sind. So ganz genau ist es "
    "nicht zu erkennen, es scheint ein schwarzes Gestein zu sein. Bei "
    "genauerer Betrachtung verschwimmt es jedoch vor Deinen Augen und gibt "
    "den Blick frei auf etwas, das sich dahinter befindet.",78)); 
  AddDetail(({"regal","regale"}),
   BS("Einst schmueckten Dutzende von Regalen die Waende, in denen die Buecher, "
    "Schriftrollen und andere wichtige Dokumente der schwarzen Magie aufbewahrt "
    "wurden. Nun liegen eben diese Regale zerstoert und in kleine Stueckchen "
    "zerschmettert am Boden und taugen hoechstens noch zu Brennholz.",78));
  AddDetail(({"buch","buecher"}),
   BS("Buecher ueber Buecher. Grosse, dicke, duenne, alte, neue, in Leder "
    "gebundene, in Leinen, Menschenhaut oder andere Materialien. Buecher ueber "
    "boese Zauber, schwarze Magie, Daemonen, andere Dimensionen. Eine Uebersicht "
    "der Buecher, die Du zur Zeit lesen kannst bekommst Du mit "
    "'inhaltsverzeichnis', oder abgekuerzt 'ih'.",78));
  AddDetail(({"aussehen"}),
   BS("Das Aussehen der Bibliothek passt nur zu gut in die Raeumlichkeiten "
    "dieser Gilde.",78));
  AddDetail(({"teil"}),
   BS("Zum Teil achtlos und zerfleddert auf dem Boden verteilt, oder zu hohen "
    "Stapeln aufgetuermt liegen die Schriftstuecke in der ganzen Bibliothek "
    "herum und bilden mit den Ueberresten der Regale und anderen Kleinigkeiten "
    "ein heiloses Durcheinander.",78));
  AddDetail(({"stapel"}),
   BS("In den Ecken tuermen sich hohe Stapel von Buechern bis an die Decke. "
    "Anscheinend hat sich hier schonmal jemand die Muehe gemacht, etwas fuer "
    "Ordnung sorgen zu wollen, dann aber resigniert aufgegeben.",78));
  AddDetail(({"stuecke","schriftstuecke","schriftstueck"}),
   BS("Die verschiedenen Schriftstuecke liegen achtlos in diesem Durcheinander "
    "herum. Du hast Muehe Dir die Dokumente rauszusuchen, die Du lesen "
    "moechtest. Mit 'inhaltsverzeichnis' bekommst du die derzeit verfuegbaren "
    "Titel.",78));
  AddDetail(({"durcheinander"}),
   BS("Inmitten dieses Durcheinanders stehst Du und schuettelst unmerklich "
    "den Kopf. Achtlos durcheinandergeworfen liegen die Buecher und "
    "Schriftrollen auf dem Boden zwischen den Resten der Tuer und der Regale. "
    "So chaotisch die Gilde, so chaotisch auch ihre Raeumlichkeiten.",78));
  AddDetail(({"rest","reste"}),
   BS("Ueberall im Raum verstreut liegen die Reste der Regale und Tuer. Mal in "
    "handliche Stuecke zertruemmert, tauglich als Brennholz aber auch "
    "einzelne Bretter kannst Du entdecken.",78));
  AddDetail(({"stueck"}),
   BS("Nebst den Buechern und Schriftrollen scheint der Kronleuchter das "
    "einzig intakte Stueck in diesem Raum zu sein.",78));
  AddDetail(({"ausgang"}),
   BS("Es gibt nur einen sichtbaren Ausgang. Den im Westen in die "
    "Halle des Chaos.",78));
  AddDetail(({"tuer","tuere"}),
   BS("Die Tuer ist nur noch ein kuemmerliches Ueberbleibsel ihrer selbst. "
    "Zertreten in ihre Einzelteile haengen nur noch lose Bretter in den "
    "Angeln, der Rest liegt verstreut auf dem Boden herum.",78));
  AddDetail(({"verwaltungsraum","halle","chaoshalle"}),
     BS("Dort ist Kruuolq.",78));
  AddDetail(({"zeugnis","zeugnisse"}),
   BS("Nebst Buechern und Schriftrollen siehst Du auch noch andere Zeugnisse "
    "der Druckkunst. Beschriebene Tontafeln zum Beispiel, "
    "Hefte und einiges mehr.",78));
  AddDetail(({"heft","hefte"}),
   BS("In dem ganzen Durcheinander liegen auch einige zerfledderte Hefte.",78));
  AddDetail(({"druckkunst","kunst"}),
   BS("Die Druckkunst ist eine hochentwickelte und wichtige Kunst. Durch sie "
    "wurde die Weitergabe und Verbreitung alten Wissens an nachfolgende "
    "Generationen erst moeglich.",78));
  AddDetail(({"generation","generationen"}),
   BS("An Deine zum Beispiel.",78));
  AddDetail(({"beispiel"}),
   BS("Das Beispiel war 'Generation'.",78)); 
  AddDetail(({"raum","bibliothek"}),   
   BS("Du stehst mitten drin, schau Dich um.",78)); 
  AddDetail(({"rolle","rollen","schriftrolle","schriftrollen"}), 
   BS("Die Schriftrollen liegen groesstenteils ausgerollt zwischen dem "
    "Durcheinander und tragen zu ihm ueberhaupt erst bei. Einige von ihnen "
    "sind bereits eingerissen und verschmutzt. Das vergilbte Papyrus macht "
    "es schwer, denn Text noch zu lesen. Eine Uebersicht der verfuegbaren "
    "Titel bekommst Du mit 'inhaltsverzeichnis'.",78));
  AddDetail(({"belag","bodenbelag","fussbodenbelag"}),
   BS("Von dem Fussboden beziehungsweise seinem Belag ist nichts zu erkennen, "
    "da er ueber und ueber mit Buechern und anderen Kleinigkeiten bedeckt "
    "ist. Selbst Du stehst eigentlich nicht auf dem Boden, sondern auf "
    "dem Durcheinander, das ihn verbirgt.",78));
  AddDetail(({"kleinigkeiten","kleinigkeit" }),   
   BS("Neben den verschiedenen Zeugnissen der Druckkunst, immerhin bist Du "
    "in einer Bibliothek, siehst Du noch diverseste Kleinigkeiten, die sich "
    "hier so im Laufe der Jahre angesammelt haben. Bruchstuecke von Kreiden "
    "und anderem Mal-Zubehoer, Essensreste, Blutspuren, verdorbene Zutaten "
    "von daemonischen Beschwoerungsritualen und jede Menge Staub.",78));
  AddDetail(({"jahr","jahre"}),
   BS("Derer sind wohl schon viele vergangen.",78));
  AddDetail(({"menge"}),
   BS("Eben sehr viel.",78));
  AddDetail(({"bruchstuecke","bruchstueck"}),
   BS("Bruchstuecke, gross und klein, von veschiedenen Kreiden.",78));
  AddDetail(({"kreide","kreiden","kreidenstuecke","kreidenstueck",
    "kreidenbruchstueck","kreidenbruchstuecke","kreidestueck","kreidestuecke"
    "kreidebruchstueck","kreidebruchstuecke"}),
   BS("Die Bruchstuecke der Kreiden sind so klein und zersplittert, dass sie "
    "sicher nicht mehr zu gebrauchen sind.",78));
  AddDetail(({"essenreste","essensreste"}),
   BS("Verfaulte und abscheulich stinkende Essenreste.",78));
  AddDetail(({"blutspur","blutspuren"}),
   BS("An den Waenden und auf dem Boden finden sich einige Blutspuren. Schon "
    "laengst vertrocknet zeugen sie dennoch von den finsteren Ritualen, die "
    "hier einst abgehalten wurden.",78));
  AddDetail(({"haufen","buecherhaufen"}),
   BS("Dort in der einen Ecke liegt ein gewaltiger Buecherhaufen. Uebersaet "
    "von Dreck, Staub und Holzstuecken. Jetzt, wo Du etwas genauer hinsiehst, "
    "entdeckst Du doch tatsaechlich eine Hand, die aus diesem Gewirr "
    "herausragt.",78));
  AddDetail(({"dreck"}),
   BS("Du schaust Dir den Dreck lieber nicht genauer an, wer weiss, was sich "
    "da so alles drin befindet.",78));
  AddDetail(({"gewirr"}),
   BS("Der Haufen in der einen Ecke bildet sich aus einem Gewirr von Staub, "
    "Dreck, Holzstueckchen, Buechern und anderen Dokumenten. Eine Hand ragt "
    "daraus hervor.",78));
  AddDetail(({"holzstueckchen"}),
   BS("Kleine Holzstueckchen wohlgemerkt.",78));
  AddDetail(({"kleine holzstueckchen"}),
   BS("Genau, schau nur wie klein sie sind!",78));     
  AddDetail(({"hand"}),
   BS("Mitten aus dem Gewirr, spaerlich verdeckt von Buechern und bedeckt mit "
    "einer dicken Staubschicht, ragt sie aus dem Haufen hervor. Sie umschlingt "
    "etwas, was Du bei genauerem Hinsehen als Zettel identifizieren kannst.",78));
  AddDetail(({"hinsehen"}),
   BS("Du schaust sicherheitshalber erneut nach, entdeckst aber weiter "
    "nichts.",78));  
  AddDetail(({"aufmerksamkeit"}),
   BS("Aufmerksamkeit, nunja. Du bemuehst Dich, irgendwie einen Durchblick "
    "angesichts dieses Durcheinanders zu bekommen und immer wieder wandert "
    "Dein Blick auf diesen ominoesen Haufen Buecher in der einen Ecke.",78));
  AddDetail(({"ecke","ecken","zimmerecke","zimmerecken"}),
   BS("In den Ecken der Bibliothek liegen hohe Stapel von Buechern, die bis "
    "an die Decke reichen. Einzig in einer ist ein wuester Haufen aufgetuermt, der "
    "Deine Aufmerksamkeit erregt.",78));
  AddDetail(({"steine","stein","gestein"}),
   BS("Schwarzes, mattglaenzendes Gestein.",78));
  AddDetail(({"ornament","ornamente"}),
   BS("Kunstvolle Ornamente zieren einen Grossteil der Decke. Sie sind von "
    "verschnoerkelten Verzierungen eingefasst, die um ein riesiges Pentagramm "
    "angeordnet sind, das an der Decke aufgezeichnet ist.",78));
  AddDetail(({"verzierung","verzierungen"}),
   BS("Die Verzierungen umgeben die kunstvollen Ornamente. Sie bestehen aus "
    "seltsamen Symbolen und Runen, die wohl eine tiefere Bedeutung "
    "haben.",78));
  AddDetail(({"pentagramm"}),
   BS("In der Mitte der Decke ist ein riesiges Pentagramm auf das Gestein "
    "gezeichnet oder eingemeisselt worden. Seine Zacken zeigen in die "
    "fuenf Ecken des Raumes. Eingefasst wird das Pentagramm von vielen "
    "Ornamenten und Verzierungen. Genau in der Mitte des Pentagramms haengt "
    "ein gigantischer Kronleuchter herab, der mit schwarzen Kerzen bestueckt "
    "ist.",78));
  AddDetail(({"mitte"}),
   BS("In der Mitte des Pentagramms an der Decke haengt ein wahrhaft "
    "riesiger Kronleuchter.",78));
  AddDetail(({"blick"}),
   BS("Deinem wachen Blick entgeht wahrscheinlich nichts von dem, was sich "
    "hier befindet.",78));
  AddDetail(({"art"}),
   BS("Hmja, so in der Art zumindest.",78));  
  AddDetail(({"material"}),
   BS("Es scheint sich um eine Art schwarzen Gesteins zu handeln. Genaueres "
    "ist jedoch nicht auszumachen.",78));
  AddDetail(({"betrachtung"}),
   BS("Bei genauerer Betrachtung scheint das Material, aus dem Waende und "
    "Decke bestehen vor Deinem Auge zu veschwimmen. Zumindest kommt es Dir "
    "so vor, da es sich nicht fixieren laesst.",78));
  AddDetail(({"auge","augen"}),
   BS("Nanu, wo kommt das denn auf einmal her?",78));
  AddDetail(({"uebersicht"}),
   BS("Eine Uebersicht der verfuegbaren Titel bekommst Du mit "
    "'inhaltsverzeichnis'.",78));
  AddDetail(({"inhaltsverzeichnis","verzeichnis"}),
   BS("'inhaltsverzeichnis' ohne Argument reicht voellig.",78));
  AddDetail(({"argument","argumente"}),
   BS("Die brauchst Du nicht, um das Inhaltsverzeichnis zu bekommen.",78));  
  AddDetail(({"titel"}),
   BS("Schau Dir doch einfach das Inhaltsverzeichnis an.",78));
  AddDetail(({"zauberer"}),
   BS("Weicheier.",78));
  AddDetail(({"leinen"}),
   BS("Eingehend untersuchst Du die Leinen-Einbaende, kannst aber nichts "
    "Besonderes entdecken.",78));
  AddDetail(({"haut","menschenhaut"}),
   BS("Feine, duenne Menschenhaut. Sie eignet sich hervorragend, Buecher "
    "von brisantem Inhalt einzubinden.",78));
  AddDetail(({"angel","angeln","tuerangel","tuerangeln"}),
   BS("An den Tuerangeln haengen nur noch kuemmerliche Reste der einst dort "
    "befestigten Tuer.",78));
  AddDetail(({"brennholz"}),
   BS("Das Holz aus dem die Regale und die Tuer bestanden haben, taugt inzwischen "
    "nur noch als Brennholz.",78));
  AddDetail(({"symbol","symbole"}),
   BS("Die Symbole sind mystischen Ursprungs und ohne Hilfe nicht zu "
    "deuten.",78));        
  AddDetail(({"materialien"}),
   BS("Die Buecher sind in verschiedene Materialien eingebunden. Nebst Leinen, "
    "Leder und Menschenhaut siehst du einige, die Dir nicht bekannt sind.",78));
  AddDetail(({"papyrus"}),
   BS("Das Papyrus ist schon alt und vergilbt. Die Texte darauf sind kaum "
    "zu lesen.",78));
  AddDetail(({"text","texte"}),
   BS("Die zur Zeit verfuegbaren Texte bekommst du mit 'inhaltsverzeichnis'.",78));
  AddDetail(({"leder"}),
   BS("Das Leder ist dunkel und schon sehr abgegriffen.",78));
  AddDetail(({"zauber","zauberei"}),
   BS("Was fuer Zauberei es auch sein mag, sie dient sicherlich keinem guten "
    "oder gar heiligem Zwecke.",78));
  AddDetail(({"magie"}),
   BS("Die schwarze Magie ist eine hohe Kunst, die von den Kriegern des Chaos "
    "nach und nach erlernt und zum Ergoetzen ihrer Meister angewandt werden "
    "kann.",78));
  AddDetail(({"dimension","dimensionen"}),
   BS("Die anderen bekannten und unbekannten Dimensionen sind von aeusserster "
    "Wichtigkeit fuer einen jeden Chaoten, beherrscht er doch die Faehigkeit, "
    "durch boese Zauber ein Tor dorthin zu oeffnen und sich Unterstuetzung im "
    "Kampf gegen das Gute in dieser Welt zu holen.",78));
  AddDetail(({"faehigkeit","faehigkeiten"}),
   BS("Dazu fragst Du lieber Kruuolq.",78));  
  AddDetail(({"daemon","daemonen"}),
   BS("Daemonen sind die Lebewesen aus anderen Dimensionen. Sie zu beschwoeren "
    "oder gar zu beherrschen ist nur den wahren Kriegern des Chaos moeglich.",78));
  AddDetail(({"wesen","lebewesen"}),
   BS("Auf die ein oder andere Art zumindest sind es wirklich welche.",78));
  AddDetail(({"dokument","dokumente"}),
   BS("Derer gibt es hier viele, immerhin ist dies eine Bibliothek.",78));
  AddDetail(({"ueberbleibsel","ueberreste"}),
   BS("Die kuemmerlichen Ueberbleibsel der Tuer liegen im ganzen Raum "
    "verstreut herum.",78));
  AddDetail(({"einzelteil","einzelteile"}),
   BS("Ausser einigen Einzelteilen ist nichts mehr von einer Tuer zu erkennen. "
    "Lose Holzstuecke und Bretter bedecken den Boden und einiges haengt auch "
    "noch in den Angel.",78));
  AddDetail(({"bretter","brett","holzbretter","holzbrett"}),
   BS("Diese Bretter bildeten wohl einst eine formschoene und stabile "
    "Tuer.",78));
  AddDetail(({"holz"}),
   BS("Dunkles und sehr sehr hartes Uktarholz.",78)); 
  AddDetail(({"rune","runen"}),
   BS("Die Runen um das Pentagramm sind von wundervollen Verzierungen "
    "eingefasst. Welche Bedeutung sie allerdings haben, weisst Du nicht. "
    "Wahscheinlich ist jedoch, dass sie zu einem maechtigen Ritual "
    "gehoeren.",78));
  AddDetail(({"bedeutung"}),
   BS("Dir ist die Bedeutung des Pentagramms, der Verzierungen und Runen "
    "nicht bekannt. Vielleicht findest Du irgendwo alte Aufzeichnungen, "
    "die Dir weiterhelfen.",78)); 
  AddDetail(({"aufzeichnungen"}),
   BS("Na, ein bisschen mehr musst Du Dich schon anstrengen um welche zu "
    "finden.",78));   
  AddDetail(({"inhalt"}),
   BS("Der Inhalt einiger Buecher scheint ziemlich brisant zu sein und ist "
    "nur fuer eingeweihte Krieger des Chaos zu lesen.",78));
  AddDetail(({"hilfe"}),
   BS("Selbst so ein gestandender Chaot wie Du hat sie anscheinend ab und an "
    "mal noetig.",78));
  AddDetail(({"zweck","zwecke"}),
   BS("Die Krieger des Chaos kennen nur einen Zweck: Die Verbreitung des "
    "Boesen in dieser viel zu guten Welt.",78));
  AddDetail(({"zutat","zutaten"}),
   BS("Ausser etwas verdorbenem Daemonenschleim und altem Knochenmehl siehst "
    "Du keine anderen Zutaten.",78));
  AddDetail(({"schleim","daemonenschleim"}),
   BS("Der Daemonenschleim sieht einfach nur widerlich und "
    "ekelig aus. Du weisst zwar nicht genau warum, aber dieser Schleim laesst "
    "sich angeblich zum Zeichnen von Pentagrammen verwenden. Er ist schon "
    "sehr vertrocknet und sicher nicht mehr zu gebrauchen.",78));
  AddDetail(({"mehl","knochenmehl"}),
   BS("Das Knochenmehl stammt von einem urzeitlichen Ungeheuers, "
    "das nur sehr schwer zu erledigen ist. Aus diesem Grunde ist "
    "das Knochenmehl aeusserst wertvoll, nur dieses hier ist nicht mehr zu "
    "gebrauchen.",78));
  AddDetail(({"grund"}),
   BS("Der ist wohl nicht offentsichtlich.",78));  
  AddDetail(({"ungeheuer"}),
   BS("Also hier in der Bibliothek wird es sich sicher nicht aufhalten, da "
    "musst Du schon woanders suchen.",78));
  AddDetail(({"zubehoer","malzubehoer","mal-zubehoer"}),
   BS("Neben einigen Kreiden siehst Du vom Staub bedecktes anderes Zubehoer, "
    "welches zum Zeichnen von Pentagrammen und Bannkreisen benoetigt "
    "wird.",78));
  AddDetail(({"bannkreis","bannkreise","kreis","kreise"}),
   BS("Du weisst, was ein Bannkreis ist. Ich bin mir sicher.",78));  
  AddDetail(({"zettel"}),
   BS("Auf dem Zettel steht etwas geschrieben. Du kannst versuchen, die "
    "Schrift zu entziffern.",78));
  AddDetail(({"schrift"}),
   BS("Die Schrift ist recht unleserlich, dennoch koenntest Du versuchen, "
    "sie zu entziffern.",78));  
  AddDetail(({"zentrum"}),
   BS("Im Zentrum des Pentagramms ist ein gewaltiger Haken in die Decke "
    "getrieben, an dem der noch gewaltigere Kronleuchter haengt.",78));
  AddDetail(({"haken"}),
   BS("An dem gewaltigen Haken ist der Kronleuchter befestigt.",78));
  AddDetail(({"worte","wort"}),
   BS("Sind dies die drei letzten Worte eines hier ungluecklich zu Tode "
    "gekommenen Chaoten?",78));
  AddDetail(({"chaot","chaoten"}),
   BS("Dort unter dem Haufen scheint tatsaechlich die Ruhestaette eines "
    "verstorbenen Chaoten zu sein. Ausser der Hand, die etwas hervorragt, "
    "siehst Du aber nichts.",78));
  AddDetail(({"staette","ruhestaette"}),
   BS("Naja, etwas stilvoller moechtest Du schon begraben werden.",78));
  AddDetail(({"wissen"}),
   BS("Wissen erlangt man nicht durch blosses Untersuchen.",78));
  AddDetail(({"untersuchen","untersuchung"}),
   BS("Gewissenhaft untersuchst Du nochmal Deine vorherige Untersuchung, "
    "wirst aber dadurch auch nicht schlauer.",78));
  AddDetail(({"wichtigkeit"}),
   BS("Angesichts der vielen Daemonen, die ein Krieger des Chaos beschwoeren "
    "kann, erklaert sich die Wichtigkeit dieser Dimensionen schon von "
    "alleine.",78));
  AddDetail(({"welt"}),
   BS("Hast Du Dir da nicht ein bisschen viel vorgenommen?",78));
  AddDetail(({"weitergabe","verbreitung"}),
   BS("Die Weitergabe und Verbreitung des Wissens ob der boesen Maechte und "
    "Zauber wurde frueher muendlich von Meister zu Lehrling vollzogen. "
    "Nach Entdecken des Papyrus und der Weiterentwicklung auf diesem "
    "Gebiet, konnte das Wissen auch in schriftlicher Form an nachfolgende "
    "Generationen weitergegeben werden.",78));
  AddDetail(({"lehrling"}),
   BS("Der ist gestern leider verstorben. Er frug zuviel, wenn Du verstehst "
    "was ich meine.",78));  
  AddDetail(({"gebiet"}),
   BS("Das der Entwicklung. Welche sag ich nicht.",78));
  AddDetail(({"form"}),
   BS("In Schriftform sozusagen.",78));
  AddDetail(({"schriftform"}),
   BS("Diese siehst Du vor Dir.",78));   
  AddDetail(({"zeichnen"}),
   BS("Noch hast Du doch gar nichts gezeichnet!",78));
  AddDetail(({"entwicklung","weiterentwicklung"}),
   BS("Da diese Entwicklung immer noch voranschreitet, waere alles schon "
    "ueberholt, sobald ich es erwaehnen wuerde.",78));
  AddDetail(({"meister"}),
   BS("Es kann nur einen geben. Und wenn Du wissen moechtest, wer das momentan "
    "ist, frag Kruuolq oder Hutschat.",78));
  AddDetail(({"hutschat","kruuolq"}),
   BS("Der ist im Verwaltungsraum der Gilde.",78));
  AddDetail(({"ursprung"}),
   BS("Wie das meist bei solch alten Symbolen ist, liegt ihr Ursprung im "
    "Mystischen.",78));
  AddDetail(({"unterstuetzung"}),
   BS("Zur Unterstuetzung bei der Verbreitung des Chaos und Boesen in dieser "
    "Welt koennen die Krieger des Chaos Daemonen beschwoeren und sich "
    "dunkler Zauber bedienen. Was fuer ein Spass.",78));
  AddDetail(({"spass"}),
   BS("Einem hartgesottenen Chaoten glaenzt das Gesicht vor Freude wenn sich "
    "seine Feinde in Schmerzen vor ihm auf dem Boden winden.",78));
  AddDetail(({"gesicht"}),
   BS("So nennt sich ein Teil unseres Koerpers.",78));
  AddDetail(({"koerper"}),
   BS("Doktorspielchen oder was, ohne mich!",78));
  AddDetail(({"spielchen","doktorspielchen"}),
   "Hutschat teilt Dir mit: Komm mal eben her, ich glaub wir muessen dringend\n"
   "Hutschat teilt Dir mit: miteinander reden.\n");
  AddDetail(({"freude"}),
   BS("Ja, das ist es wirklich!",78));
  AddDetail(({"schmerz","schmerzen"}),
   BS("Vernachlaessigbar solangs nicht die eigenen sind.",78));
  AddDetail(({"uktarholz"}),
   BS("Dunkles und sehr sehr festes Uktarholz aus einem Wald in der "
    "Unterwelt.",78));
  AddDetail(({"wald","uktarwald"}),
   BS("Der befindet sich irgendwo in einer riesigen Hoehle unter einer "
    "Insel.",78));
  AddDetail(({"hoehle"}),
   BS("Die befindet sich unter einer Insel.",78));
  AddDetail(({"insel"}),
   BS("Die befindet sich irgendwo auf dem Meer.",78));
  AddDetail(({"meer"}),
   BS("Das befindet sich um der Insel, sonst waers ja keine.",78));
  AddDetail(({"unterwelt"}),
   BS("Die Unterwelt ist nahezu ueberall.",78));
  AddDetail(({"tor","dimensionstor"}),
   BS("Durch dieses Tor gelangen die Daemonen in unsere Welt.",78));
  AddDetail(({"tafel","tafeln","tontafel","tontafeln"}),
   BS("Auch einige Tontafeln siehst Du, die komischerweise alle "
    "unzerstoert sind.",78));
  AddDetail(({"stueckchen"}),
   BS("Dies sind die Ueberbleibsel von Regalen und Tuer.",78));
  AddDetail(({"staub"}),
   BS("Ueber der ganzen Unordnung in diesem Raum liegt schon eine dicke "
    "Schicht Staub.",78));
  AddCmd(({"unordnung"}),
   BS("Durch den Staub ist sie schon gar nichmehr zu sehen. Schade "
    "eigentlich.",78));  
  AddCmd(({"halterung"}),
   BS("Wirklich nuetzlich so eine stabile Halterung, sie haelt naemlich den "
    "Kronleuchter und sorgt dafuer, dass er Dir nicht auf den Kopf "
    "faellt.",78));
  AddDetail(({"kopf"}),
   BS("Du hast einen, und Du weisst das auch.",78));  
  AddDetail(({"schicht","staubschicht"}),
   BS("Die Staubschicht ist wirklich nicht zu uebersehen, jemand hat etwas "
    "hineingezeichnet.",78));
  AddDetail(({"zeichnung"}),
   BS("Hat entfernte Aehnlichkeit mit einer Sau, aber sicher bist Du Dir "
    "nicht.",78));
  AddDetail(({"aehnlichkeit"}),
   BS("Die Aehnlichkeit ist tatsaechlich verblueffend.",78));
  AddDetail(({"sau"}),
   BS("Die Sau im Staub scheint Dich anzublinzeln und etwas sagen zu wollen, "
    "vielleicht kannst Du ihr ja lauschen.",78));
  AddDetail(({"zacke","zacken"}),
   BS("Die fuenf Zacken des Pentagramms an der Decke zeigen in die fuenf "
    "Ecken dieses Raumes.",78));
  AddDetail(({"schimmer"}),
   BS("Die Umrisse des Pentagramms sind von einem magischen Schimmer "
    "umgeben, der sich ab und an in zischelnden Entladungen in den "
    "Kronleuchter aeussert.",78));
  AddDetail(({"umriss","umrisse"}),
   BS("So etwas muss ein Krieger des Chaos wissen!",78));
  AddDetail(({"entladung","entladungen"}),
   BS("Die Entladungen schlagen in regelmaessigem Abstand von der Decke in "
    "den Kronleuchter ein.",78));
  AddDetail(({"blitz"}),
   BS("Formschoen schlaegt er in die Wand neben Dir ein. Du bist "
    "entzueckt.",78));
  AddDetail(({"tod"}),
   BS("Lars grinst Dich aus der Ferne an.",78));
  AddDetail(({"lars"}),
   BS("Nein, dem moechtest Du jetzt nicht begegnen.",78));
  AddDetail(({"ferne"}),
   BS("Sei froh. Staende er neben Dir, waere es sicher schon zu spaet.",78));
  AddDetail(({"abstand","abstaende"}),
   BS("Etwa alle zehn Minuten zuengelt ein heller Blitz in den Kronleuchter.",78));
  AddDetail(({"minuten","minute"}),
   "Harkuhu kommt an.\n"
   "Dieses Detail wird von Harkuhu gierig aufgefressen. Er grinst Dich an und\n"
   "verschwindet wieder.\n");
  AddDetail(({"schatten"}),
   BS("Tanzenden Schatten gleich ist das Licht der Kerzen, die diese in "
    "den Raum werfen.",78));
  AddDetail(({"ritual","beschwoerungsritual","rituale","beschwoerungsrituale"}),
   BS("Die Verzierungen und Runen an der Decke gehoeren augenscheinlich "
    "zu einem maechtigen Beschwoerungsritual. Vielleicht findest Du "
    "irgendwo Aufzeichnungen darueber.",78));
  AddDetail(({"raeumlichkeit","raeumlichkeiten"}),
   BS("Schau sie Dir nur an, es hindert Dich keiner daran.",78));
  AddDetail(({"ordnung"}),
   BS("Scheinbar hat einmal jemand versucht, etwas Ordnung hier zu schaffen, "
    "dann aber resigniert aufgegeben.",78));
  AddDetail(({"muehe"}),
   BS("Ein Krieger des Chaos wuerde nie zugeben, an etwas Muehe zu haben. "
    "Ausser vielleicht zu anderen Kriegern des Chaos.",78));
  AddDetail(({"kampf"}),
   BS("Du weisst wirklich nicht, um was fuer einen Kampf es sich da handeln "
    "koennte.",78));
  AddDetail(({"rache"}),
   BS("Ja, RACHE!",78));  
  AddDetail(({"holzstueck","holzstuecke"}),
   BS("Viele kleine und zersplitterte Holzstuecke, doch glaenzt dort nicht "
    "etwas? Vielleicht lohnt es sich, einmal in den Holzstuecken zu "
    "wuehlen.",78));

  AddSpecialDetail(({"chaos"}),"c_chaos");
  AddSpecialDetail(({"feind","feinde"}),"meine_feinde"); 
  AddSpecialDetail(({"zeit"}),"zeit");
  AddSpecialDetail(({"gilde","chaosgilde","chaos-gilde"}),"c_gilde");
  AddSpecialDetail(({"leuchter","kronleuchter"}),"k_leuchter");
  AddSpecialDetail(({"kerze","kerzen"}),"k_kerzen");  
  AddSpecialDetail("erzmeister","erzi");
  AddSpecialDetail(({"licht","kerzenlicht"}),"k_licht");
  
  AddCmd(({"zerbreche","zerbrech","zerbrich"}),"tontafel");
  AddCmd(({"entziffer","entziffere"}),"schrift");
  AddCmd(({"ess","esse","iss"}),"essen");
  AddCmd(({"wisch","wische"}),"wischen");
  AddCmd(({"ih","inhaltsverzeichnis"}),"inhalt"); 
  AddCmd(({"lies","lese","les"}),"bibo");
  AddCmd(({"zuende","zuend"}),"zuend_an");
  AddCmd(({"loesche","loesch"}),"loesche_kerze");
  AddCmd(({"wuehl","wuehle"}),"h_stueck");
  
  AddSmells(({"gestank","essensreste","essenreste"}),
   BS("Puhhhh, obwohl die Essenreste hier schon geraume Zeit liegen, haben "
    "sie dennoch nichts von ihrem widerlichen Gestank verloren.",78));

  AddSounds(({"sau"}),
   BS("Oink, oink, iss mich. Ich bin ein Schnitzel.",78));

  AddSpecialExit("westen","westen");
}

static string meine_feinde() {
  object pl;
  mixed feinde;
  feinde=this_player()->QueryProp("enemies");
  if(!pointerp(feinde)||!sizeof(feinde))
  return "Ja, verflucht! Du hast keine!?!\n";
  return BS("Als da waeren: "+implode( map_array( feinde, #'capitalize),",")
           +". Reicht Dir das etwa?\n",78);
}

static string zeit() {
  return dtime(time())[19..28]+"\n";
}

static string erzi(){
 if(CHAOS_GILDEN_MASTER->ist_erz(this_player()))
   return "Schau Dich doch an, also wirklich!\n";
 else
   return "Du bist es schonmal nicht, soviel ist sicher.\n";
}
     
static int tontafel(string str){
 notify_fail("Was moechtest Du zerbrechen?\n");
 if(!str) return 0;
 if(str=="tontafel"||str=="tontafeln"||str=="tafel"||str=="tafeln"){
   write(BS("Du nimmst eine der Tontafeln in die Hand und bemuehst Dich "
    "redlich, sie zu zerbrechen. Jedoch scheiterst Du klaeglich, wie "
    "peinlich.",78));
   return 1;
  }
 return 0;
}
    
static int essen(string str){
 notify_fail("Was moechtest Du denn hier essen?\n");
 if(!str) return 0;
 if(str=="schnitzel"){
    write(BS("Lass das mal lieber bleiben, davon wuerdest Du nur einen fiesen "
     "Staubmagen holen.",78));
   return 1;
  }
 return 0;
}
     
static int wischen(string str){
 notify_fail("Was moechtest Du wischen?\n");
 if(!str) return 0;
 if(str=="staub"){
    write("Finger weg vom Chaos und Dreck in diesem Raum! BANAUSE!\n");
    return 1;
   }
 return 0;
}
    
static int h_stueck(string str) {
 object holz;
  notify_fail("Worin willst Du denn wuehlen?\n");
  if(!str) return 0;
  if(str=="in holzstuecken"||str=="in holzstuecke"){
    if(holz_da){
      write(BS("Du wuehlst ein bisschen in den Holzstuecken und findest ein "
       "unscheinbar glaenzendes Stueck Uktarholz, welches Du "
       "sofort einsteckst.",78));
      holz = clone_object("/d/inseln/tilly/volgonen/obj/misc/spion");
      holz->move(this_player(),M_GET);
      holz_da = 0;
     return 1;
    }
   else
    write(BS("Du wuehlst ein bisschen in den Holzstuecken, findest jedoch "
     "nichts dolles.",78));
  return 1; 
 }     
}    
   
static string k_licht() {
 if(licht_da)
   return(BS("Das lackernde Licht der Kerzen wirft tanzende Schatten an "
    "Wand. Schoen schaurig.",78));
  else
   return(BS("Licht, welches Licht denn bitte?",78));
}
       
static string k_leuchter() {
 if(licht_da)
   return(BS("Der riesige schwarze Kronleuchter baumelt von der Decke. Seine "
    "Halterung ist in der Mitte eines dort aufgezeichneten Pentagrammes "
    "befestigt. Hunderte von schwarzen Kerzen werfen ihr unruhig flackerndes "
    "Licht in den Raum. Das Material, aus dem der Leuchter besteht, scheint "
    "kein herkoemmliches zu sein. Denn ab und an bemerkst Du einen leichten "
    "magischen Schimmer, der sich in zischelnden Entladungen aeussert, die "
    "in gewissen Abstaenden vom Zentrum des Pentagrammes ueberspringen.",78));
  else 
   return(BS("Der riesige schwarze Kronleuchter baumelt von der Decke. Seine "
    "Halterung ist in der Mitte eines dort aufgezeichneten Pentagrammes "
    "befestigt. Das Material, aus dem der Leuchter besteht, scheint "
    "kein herkoemmliches zu sein. Denn ab und an bemerkst Du einen leichten "
    "magischen Schimmer, der sich in zischelnden Entladungen aeussert, die "
    "in gewissen Abstaenden vom Zentrum des Pentagrammes ueberspringen. "
    "Er ist mit hunderten von schwarzen Kerzen bestueckt.",78));
}

static string k_kerzen() {
 if(licht_da)
   return(BS("Die schwarzen Kerzen werfen ein unruhig flackerndes Licht "
    "in die Bibliothek, tanzenden Schatten gleich.",78));
  else 
   return("Die Kerzen stecken auf dem Kronleuchter, sie brennen nicht.\n");
}     
   
static int schrift(string str) {
  notify_fail("Was moechtest Du denn entziffern?\n");
  if(!str) return 0;
  if(str=="schrift")
    write(BS("Mit zusammengekniffenen Augen versuchst Du, die Schrift zu "
     "entziffern. Doch ausser den Worten 'Erzmeister', 'Kampf' und 'Rache' "
     "kannst Du nichts lesen.",78));
 return 1;
}      
     
static string c_gilde() {
  return("Kruuolq teilt Dir mit: Wie was 'unt gilde'! Komm Du mir mal her...\n");
  say(this_player()->name()+" zuckt erschrocken zusammen.\n");
}

int westen(){
 write("Du steigst ueber die Ueberreste der Tuer nach Westen.\n");
 return this_player()->move(CHAOS_GILDEN_ROOM("challe"),M_GO,
 "nach Westen","geht","kommt aus der Bibliothek");
}
 
int inhalt(){
 this_player()->More(read_file("/gilden/files.chaos/texte/inhalt.txt"));
 return 1;
}

int bibo(string str){
 string text;
 if(stringp(text=([
  "mft": "jamalski.txt",
  "m1" : "wuqour.txt",
  "s1" : "sprueche.txt",
  "d1" : "daemonen.txt",
  "c1" : "chaos.txt",
  "b2" : "burg.txt",
  "a2" : "neu.txt",
  "m2" : "hutschat.txt",
  "a1" : "arena.txt",
  "q1" : "quest.txt",
  "m3" : "kruuolq.txt",
  "r1" : "raenge.txt",
  "m4" : "achtarch.txt",
  "c2" : "chaoshaut.txt",
  "z1" : "zutaten.txt",
  "z2" : "zardoz.txt",
  "n1" : "notizen.txt",
  "n3" : "notizen3.txt",
  "n2" : "notizen2.txt",
  "p1" : "pentagramm.txt",
  "p2" : "messe.txt",
  "e1" : "erzi.txt"])[str]))   
   {
    this_player()->More(read_file("/gilden/files.chaos/texte/"+text));
    return 1;
   }
 if(stringp(text=([
  "b1" : "beichte.txt"])[str]))   
   {
    this_player()->More(read_file("/d/polar/files.chaos/swift/log/"+text));
    return 1;
   }
 if(str=="tafel"||str=="tafeln"||str=="tontafeln"||str=="tontafel"){
   write(BS("Auf den Tontafeln sind nur viele ausgeblichene Symbole oder "
    "aehnliches zu sehen. Du kannst sie beim besten Willen nicht lesen, "
    "noch erahnst Du, von was sie handeln.",87));
   return 1;
  }   
 return 0;
}  


static int size_request(){
  switch(this_player()->QueryProp(P_SIZE)){
    case 0..169:
    return 0;
   break;
    default:
    return 1;
   break;
  }
}

static int zuend_an(string str){
 notify_fail("Was willst Du anzuenden?\n");
   if(str=="kerze an"||str=="kerzen an"){
     if(licht_da){
       write("Die Kerzen brennen doch schon!\n");
      return 1;
     }
     else if(!size_request()){
       write("Du bist viel zu klein dafuer!\n");
      return 1;
     }
     else {
      licht_da=1;
      SetProp(P_LIGHT,1);
       write(BS("Du zuendest die Kerzen an. Die Bibliothek wird in ein "
        "schattenhaftes Licht gehuellt.",78));
       say(this_player()->name(WER)+" zuendet die Kerzen des Leuchters an.\n");
      return 1;
     }
   }
 return 0;
}

static int loesche_kerze(string str){
 notify_fail("Was willst Du denn loeschen?\n");
   if(str=="kerzen"||str=="kerze"){
      if(!licht_da)
       write("Aber die Kerzen sind doch schon verloschen!\n");
     else {
      if(!size_request()){
       write("Du bist viel zu klein dafuer!\n");
      return 1;
     }
     licht_da=0;
     SetProp(P_LIGHT,-1);
      write(BS("Du loeschst die Kerzen. Die Bibliothek versinkt in "
       "Dunkelheit.",78));
      say(this_player()->name(WER)+" loescht die Kerzen des Leuchters.\n");
     }
    return 1;
   }
 return 0;
}
                                                                                               
void reset(){
  ::reset();
    licht_da=1;
    if(!licht_da)
     write("Die Kerzen des Kronleuchters entzuenden sich ploetzlich.\n");
    SetProp(P_LIGHT,1);
}
            
static string c_chaos() {
  return("\n\n"
   "          ###      ###     ###          #             ###           ###    \n"  
   "        ### ###     ##     ##         ## ##          ## ##        ### ###  \n"
   "      ###    ##     ##     ##        ##   ##       ##     ##     ##     ###\n"
   "      ###           ##     ##       ##     ##    ###       ###   ##        \n"
   "      ###           #########      ###########   ###       ###    ######## \n"
   "      ###           ##     ##      ##       ##   ###       ###           ##\n" 
   "      ###    ##     ##     ##      ##       ##     ##     ##     ###     ##\n"                     
   "        ### ###     ##     ##      ##       ##       ## ##         ### ### \n" 
   "          ###      ###     ###    ###       ###       ###            ###   \n"
   "                                                                           \n"
   "   ###########################################################################\n\n"
   "                         NICHT IMMER ABER IMMER OEFTER!                    \n");
}   
                               
