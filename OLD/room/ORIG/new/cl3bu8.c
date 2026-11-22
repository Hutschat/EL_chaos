#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu7"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In einem dunklen Gang");
  SetProp(P_INT_LONG,BS("Du befindest Dich tief unter einer gewaltigen, "+
  "chaotischen Burg. Durch einen dunklen Gang schleichst Du Dich voran, "+
  "immer auf der Hut vor den ... Dingen, die hier unten auf Dich lauern "+
  "koennten. Dieser Ort ist vom Boesen durchdrungen, ein Ort boesartigster, "+
  "satanischer Energien. Selbst Du, boesartig wie Du bist, gehoerst eigent"+
  "lich nicht hierher. Die schwarzen Kerzen um Dich herum flackern und wer"+
  "fen wabbernde Schatten an die kalten, schwarzen Waende, an denen zwei "+
  "grosse Gemaelde prangen."));
  AddDetail(({"burg"}),BS("Dies ist die chaotische Burg. Dies ist die "+
  "Burg des Chaos, eine Burg, geschaffen aus satanischer, daemonischer, "+
  "abgrundtief boeser Energie, wie es sie nirgendwo ein zweites Mal gibt. "+
  "Und Du befindest Dich unter ihr, tief in ihren Eingeweiden, tief in "+
  "ihren steinernen Tiefen. Wer weiss, ob Du jemals wieder aus ihnen heraus"+
  "treten wirst."));
  AddDetail(({"chaos","chaosgilde","chaoten"}),BS("Du befindest Dich unter  "+
  "der chaotischen Burg, welche die grosse Bastion der Chaosgilde darstellt. "+
  "Die Chaosgilde ist die Gilde des Chaos und das Heim aller Krieger und "+
  "Kriegerinnen des Chaos. Leute wie Du, entschlossen, Boeses zu tun und "+
  "das Chaos zu verbreiten bis in die finstersten Winkel dieser Welt."));
  AddDetail(({"bastion"}),BS("Die chaotische Burg ist stark und sicher. "+
  "Sie stellt eine Bastion des Boesen dar, und wird fuer immer und ewig "+
  "bestehen. Hail Chaos Hail."));
  AddDetail(({"krieger","kriegerinnen","streiter"}),BS("Ja, wir sind Krieger "+
  "und Kriegerinnen. Streiter fuer das Boese sind wir, und fuerchten sollen "+
  "uns die, welche uns im Wege stehen."));
  AddDetail(({"weg","wege"}),BS("Wir verfolgen unseren Weg. Und wer uns im "+
  "Weg steht, der hat nur Boeses von uns zu erwarten."));
  AddDetail(({"energie","energien"}),
  BS("Diese Burg wurde durch boesartige, satanische "+
  "Energie geschaffen, genau wie der Eisberg um sie herum."));
  AddDetail(({"eisberg"}),BS("Du weisst schon. Der Eisberg."));
  AddDetail(({"boeses","herrschaft"}),
  BS("Das Boese wird herrschen, bis in alle Ewigkeit und noch laenger."));
  AddDetail(({"ewigkeit"}),BS("Das ist noch verdammt lange hin..."));
  AddDetail(({"heim"}),BS("Das Heim der Chaoten ist die wunderbare Chaosgilde."));
  AddDetail(({"winkel"}),BS("Wir werden das Chaos tragen bis in die finster"+
  "sten Winkel, wir werden es fuehren zur ewigen Herrschaft, jawohl das wer"+
  "den wir."));
  AddDetail(({"leute"}),BS("Leute, Leute wie Du, ..."));
  AddDetail(({"mal"}),BS("Mal mal..."));
  AddDetail(({"eingeweide"}),BS("Du befindest Dich in den tiefen Eingeweiden "+
  "der Chaosgilde, tief unter der chaotischen Burg."));
  AddDetail(({"tiefen"}),BS("Ob Du hier jemals wieder herauskommst? Niemand "+
  "kann es wissen."));
  AddDetail(({"niemand"}),BS("Niemand sagt: Doch, ich weiss es, aber ich sags nich!"));
  AddDetail(({"gang","gaenge"}),BS("Gaenge wie diese gibt es hier viele unter "+
  "der Burg. Die Waende sind hier hoch, so hoch, dass man die Decke trotz der "+
  "vielen Kerzen an den Waenden nicht sehen kann. Fort fuehren sie in die "+
  "Dunkelheit und in das Ungewisse."));
  AddDetail(({"ungewisses"}),BS("Das kann man nie wissen, und noch viel weniger "+
  "untersuchen..."));
  AddDetail(({"licht","dunkelheit","dunkel","finsternis"}),BS("An diesem Ort "+
  "herrscht die Finsternis. Nichts und niemand wird das jemals aendern koennen."));
  AddDetail(({"kerzen"}),BS("Dutzende schwarzer Kerzen flackern auf hohen "+
  "Kerzenstaendern vor sich hin. Trotzdem verbreiten sie jedoch extrem wenig "+
  "Licht und flackern ziemlich. Sie scheinen fast mehr Schatten als Licht "+
  "zu erzeugen."));
  AddDetail(({"kerzenstaender"}),BS("Es sind hohe, schwarze Kerzenstaender "+
  "aus massiven Metall, welche sehr viele Kerzen tragen. Sie sind allesamt "+
  "recht grob geschmiedet und ohne viel Sorgfalt, doch sie halten die "+
  "Kerzen, und mehr kann man nicht verlangen."));
  AddDetail(({"metall"}),BS("Ob das wohl Eisen ist?"));
  AddDetail(({"eisen"}),BS("Ja, das ist bestimmt Eisen."));
  AddDetail(({"sorgfalt"}),BS("Beim Schmieden dieser Kerzen hat man nicht "+
  "viel Sorgfalt walten lassen. Naja, hier ist es eh zu dunkel, um die "+
  "Kerzenstaender wirklich bewundern zu koennen."));
  AddDetail(({"schatten"}),BS("Die Schatten zucken im flackernden Licht der "+
  "Kerzen auf den Waenden hin und her und generieren die Illusion "+
  "zuckender Bewegungen ueberall um Dich herum."));
  AddDetail(({"illusion","bewegungen"}),BS("Sind die Bewegungen in den "+
  "Schatten um Dich herum wirklich nur Illusion, oder sind sie es nicht? "+
  "Und wenn sie es nicht sind, solltest Du rennen????"));
  AddDetail(({"dutzend","dutzende"}),BS("Du weisst, was ein Dutzend ist."));
  AddDetail(({"gilde"}),BS("Du meinst die Chaosgilde, nicht?"));
  AddDetail(({"hut"}),BS("Isch habe garkeinen Hut, Segnorina..."));
  AddDetail(({"segnorina"}),BS("Wie gesagt, kein Hut."));
  AddDetail(({"nichts"}),BS("."));
  AddDetail(({"ort"}),BS("Du befindest Dich in den finsteren, dunklen "+
  "Gaengen unterhalb der fuerchterlichen Chaosgilde."));
  AddDetail(({"ungewisse","ungewisses"}),BS("Das Ungewisse ist ueberall um Dich, "+
  "besonders hier unten..."));
  AddDetail(({"wand","waende"}),BS("Die Waende bestehen aus schwarzen Steine"+
  "n, vor denen gespenstische Schatten hin- und herzucken. Einige Kerzen"+
  "staender vor ihnen sorgen fuer zumindest ein wenig Licht und beleuchten "+
  "somit die zwei Gemaelde, welche an den Waenden haengen."));
  AddDetail(({"stein","steine"}),BS("Die Waende bestehen aus den gewaltigen, "+
  "schweren schwarzen Steinen, welche man ueberall hier findet. Sie sehen "+
  "noch viel unheimlicher aus als sonst, da nun zuckende, merkwuerdige Schat"+
  "ten auf ihnen hin- und herzucken."));
  AddDetail(({"gemaelde"}),BS("Die Gemaelde sind lebensgross und somit wohl "+
  "zwei Meter hoch. Du  kannst sie einzeln betrachten."));
  AddDetail(({"meter"}),BS("Du weisst, was ein Meter ist."));
  AddDetail(({"gemaelde 1"}),BS("Das erste Gemaelde zeigt einen boesartigen "+
  "kleinen Zwerg. Fies starrt er Dich von der zwei Meter grossen Leinwand "+
  "an, auf der er ein wenig klein geraten, aber nichtsdestotrotz extrem ge"+
  "faehrlich aussieht. Er traegt ein (fuer ihn) gewaltiges Schwert und in "+
  "seinen Augen leuchtet das Chaos. Es ist Kopka, ein Chaot in Diensten "+
  "der Chaosgilde."));
  AddDetail(({"zwerg","kopka"}),BS("Dieses Gemaelde zeigt Kopka, einen finsteren "+
  "Chaoten. Er ist ein Zwerg, doch das macht ihn nur um so gefaehrlicher."));
  AddDetail(({"chaot","chaoten"}),BS("Chaoten sind so ziemlich das Gefaehrli"+
  "chste, was einem ueber den Weg laufen kann..."));
  AddDetail(({"weg"}),BS("Du bist jetzt nicht mehr als abwesend gekennzeichnet."));
  AddDetail(({"gefaehrlichstes","gefaehrlichste"}),BS("Du  meinst Chaoten."));
  AddDetail(({"dienst"}),BS("Kopka dient der Chaosgilde nicht in dem Sinne. "+
  "Ein Chaot dient niemanden. Doch Kopka hat mit Kruuolq eine ... fuer beide "+
  "Seiten vorteilhafte Vereinbarung getroffen."));
  AddDetail(({"sinn"}),BS("Gib doch auch. Hat doch alles keinen Sinn..."));
  AddDetail(({"kruuolq"}),BS("Kruuolq ist der Herr der Chaosgilde."));
  AddDetail(({"herr"}),BS("Der Herr der Chaosgilde ist Kruuolq."));
  AddDetail(({"seiten","seite"}),BS("Die eine Seite ist Kruuolq, die andere "+
  "ist Kopka."));
  AddDetail(({"vereinbarung"}),BS("Diese Vereinbarung ist ebenso geheim wie "+
  "graesslich."));
  AddDetail(({"schwert","waffe"}),
  BS("Hihi denkst Du, dieses Schwert ist groesser "+
  "als Kopka selbst. Irgendwie vergeht Dir das Lachen aber schnell, denn "+
  "der Zwerg scheint absolut keine Probleme mit der Waffe zu haben, und sie "+
  "sieht wirklich gefaehrlich aus."));
  AddDetail(({"lachen"}),BS("Das Lachen vergeht Dir schnell."));
  AddDetail(({"probleme"}),BS("Du hast Probleme. Ich nicht."));
  AddDetail(({"gemaelde 2"}),BS("Das zweite Gemaelde, zwei Meter gross wie "+
  "das erste, zeigt ein Wesen, welches dank seiner Stacheln sehr viel groesser "+
  "ist als Kopka. Es ist Spikey, einer der seltenen Dornendaemonen, welche "+
  "diesseits der Barriere leben. Spikey sieht aus wie ein Igel, der mit "+
  "einigen starken Wachstumshormonen "+
  "traktiert wurde, die dann voellig ausser Kontrolle gerieten. Obwohl "+
  "die Kreatur selbst nur knappe anderthalb Meter gross ist, sind seine "+
  "Stacheln laenger und bedecken jeden Zentimeter seines Koerpers."));
  AddDetail(({"wesen","spikey"}),BS("Dies ist Spikey. Spikey ist dank seiner "+
  "Dornen ein sehr gut geschuetzter Kerl, der schwer zu toeten ist..."));
  AddDetail(({"kerl"}),BS("Du meinst Spikey, nicht?"));
  AddDetail(({"dornen","stacheln"}),BS("Spikeys Dornen sind extrem spitz und "+
  "teilweise so gross wie er selbst..."));
  AddDetail(({"igel"}),BS("Spikey ist kein Igel, auch wenn er wie einer aus"+
  "sieht."));
  AddDetail(({"wachstumshormone"}),BS("Damit sollte man wirklich nicht herum"+
  "spielen..."));
  AddDetail(({"dornendaemon","dornendaemonen"}),BS("Spikey ist ein Dornendaemon "+
  "und gehoert somit zu einer sehr seltenen Art von Daemonen."));
  AddDetail(({"barriere"}),BS("Ueber die Barriere werde ich nichts verraten."));
  AddDetail(({"kreatur"}),BS("Das ist Spikey, ein ziemlich harter Kerl..."));
  AddDetail(({"zentimeter"}),BS("Du weisst recht genau, was ein Zentimeter ist."));
  AddDetail(({"koerper"}),BS("Man kann Spikeys Koerper wegen der ganzen Stacheln "+
  "garnicht richtig erkennen."));
  AddDetail(({"kontrolle"}),BS("Kontrolle ist fuer einen Chaoten sehr wichtig, "+
  "besonders wenn die Chaosruestung mal durchdreht. :-)"));
  AddDetail(({"chaosruestung"}),BS("Die Chaosruestung macht einen Chaoten erst "+
  "zu einem wirklich maechtigen Krieger."));
  AddDetail(({"krieger"}),BS("Chaoten sind maechtige Krieger."));
  AddDetail(({"daemonen"}),BS("Du bist Chaot. Du weisst, was Daemonen sind."));
  AddDetail(({"augen"}),BS("In Kopkas Augen leuchte in wildem Rot das Chaos."));
  AddDetail(({"rot"}),BS("Rot leuchtet das Chaos in Kopkas Augen."));
  AddDetail(({"art"}),BS("Die Art der Dornendaemonen ist eine sehr seltene Art "+
  "diesseits der Barriere."));
  AddDetail(({"dienste"}),BS("Die Dienste, welche Kopka der Chaosgilde leistet, "+
  "sind fies, gemein und verabscheuungswuerdig. Kopka liebt seinen Job."));
  AddDetail(({"job"}),BS("Was genau Kopkas Job ist, ist ein Geheimnis zwischen "+
  "ihm und Kruuolq."));
  AddDetail(({"geheimnisse","geheimnis"}),BS("Geheimnisse werden nicht verraten!"));
  AddDetail(({"dinge"}),BS("Hier hausen Dinge, die man nicht naeher definieren "+
  "kann. Dinge halt."));
  AddDetail(({"leinwand"}),BS("Die Leinwand, auf denen die Gemaelde gemalt wurden, "+
  "ist hart, dick und robust. Diese Gemaelde halten sicherlich einiges aus."));
  AddDetail(({"sinne"}),BS("Nein nein, es geht hier um den 'Sinn', nicht um "+
  "'Sinne'."));
  AddDetail(({"welt"}),BS("Die Welt ist grooooooooooooss!"));
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht nach nix."));
  AddSounds(SENSE_DEFAULT,BS("Du hoerst nix."));
  AddExit("nordosten",CHAOS_GILDEN_ROOM("cl3bu9"));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl3bu7"));
  
  
}
