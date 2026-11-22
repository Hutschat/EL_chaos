#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

inherit CHAOS_GILDEN_ROOM("cl2bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu4"));
  SetProp(P_LIGHT,0);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In einer dunklen Gasse der chaotischen Burg");
  SetProp(P_INT_LONG,BS(
  "Du befindest Dich in einer Gasse. Wenn es ueberhaupt noch geht, "+
  "ist es hier noch dunkler geworden. Die Burgmauer ragt gespenstisch "+
  "neben Dir auf. Aus dem Dunkel ueber Dir haengt an der Mauer ein "+
  "dickes Seil mit Schlinge zu Dir herab. Im Osten wird die schmale "+
  "Gasse durch die Rueckwand eines Hauses begrenzt, ebenfalls ein "+
  "schwarzer Schatten, welcher sich ueber Dich erhebt. Unheimlich "+
  "hallen deine Schritte in dieser unnatuerlichen Stille wieder."));
  AddDetail(({"boden"}),BS("Der Boden besteht aus schwarz aussehenden "+
  "steinernen Fliesen (Oder sind es Pflastersteine? Du weisst es nicht)."));
  AddDetail(({"fliesen"}),BS("Nein, es sind wohl doch Pflastersteine."));
  AddDetail(({"pflastersteine"}),BS("Diese merkwuerdig schwarzen "+
  "Steine bedecken den Boden unter Dir. Als Du sie naeher betrachtest, "+
  "fallen Dir diverse Kratzspuren auf dem Boden unterhalb des Seils "+
  "(des Galgens?) auf."));
  AddDetail(({"kratzspuren","spuren"}),BS("Hmmmmm. Ist das Holz?"));
  AddDetail(({"holz"}),BS("Ja, es scheint in der Tat Holz in den Kratz"+
  "spuren zu befinden. Es scheint, als haette man hier eine Art Holz"+
  "block hin- und herbewegt oder so. Du blickst auf zur Schlinge "+
  "(zum Galgen?). Oh."));
  AddDetail(({"block","holzblock"}),BS("Der ist nicht da. Vielleicht hat "+
  "ihn jemand mitgehen lassen. Es gibt ja kranke Leute."));
  AddDetail(({"jemand"}),BS("Jemand sagt: Nein, ich war das wirklich nicht!"));
  AddDetail(({"leute","kranke leute"}),BS("Ja, kranke Leute. Leute wie ... DU!"));
  AddDetail(({"seil","schlinge","galgen"}),
  BS("Dieses Seil mit dieser Schlinge "+
  "stellt wohl einen Galgen dar. Und das ist recht ungewoehnlich. Chaoten "+
  "haengen eigentlich keine Leute. Sie schlitzen ihnen eher die Baeuche "+
  "auf und legen ihren Opfern die Gedaerme in die Hand, oder zeigen "+
  "ihnen ihr noch schlagendes Herz, doch jemanden aufzuhaengen, das waere "+
  "... zu human. Es haette keinen Stil. Keine Klasse."));
  AddDetail(({"chaos","chaot","chaoten","krieger des chaos"}),
  BS("Dies ist die Burg des Chaos. "+
  "Hier befindet sich die beruechtigte und verschriene Chaosgilde. Die "+
  "beherbergt die fuerchterlichen Krieger des Chaos, die Chaoten. Chaoten "+
  "sind so ungefaehr das Boesartigste und Gefaehrlichste, was Dir hier "+
  "begegnen kann (es sei denn, du begegnest Nesaja. Dann aber gute Nacht). "+
  "Diese Chaoten sind fiese, satanische Kreaturen der Finsternis. Sie "+
  "paktieren mit daemonischen Kraeften und sind verdammt stolz drauf."));
  AddDetail(({"chaosgilde"}),BS("Die boesartigste Gilde, die es gibt."));
  AddDetail(({"gilde"}),BS("CHAOS! CHAOS! CHAOS! CHAOS!"));
  AddDetail(({"kreaturen","kreaturen der finsternis"}),BS(
  "Ja, sie sind Kreaturen der Nacht. Und sie haben grosse, gelbe Zaehne!"));
  AddDetail(({"zaehne","gelbe zaehne"}),BS("Das war ein Zitat aus einem "+
  "bekannten Film. Na, kannst Du mir den Namen sagen?"));
  AddDetail(({"zitat","film","name"}),BS("Aus welchem Film stammte das "+
  "Zitat mit den grossen gelben Zaehnen? Wie war sein Name? Naaaaaa?"));
  AddDetail(({"finsternis","dunkelheit","licht"}),
  BS("In dieser Burg herrscht eine geradezu unnatuerliche Dunkelheit. "+
  "Eine Finsternis, welche nicht von dieser Welt ist, ein Antilicht "+
  "daemonischer Natur."));
  AddDetail(({"welt","antilicht"}),BS("Diese Dunkelheit ist mehr als die "+
  "Abwesenheit von Licht. Sie ist etwas anderes, eine entfleuchende Substanz "+
  "habendes ... etwas, ein Antilicht, etwas boesartiges, welches hier, in "+
  "dieser Burg lebt und in ihr ... waechst, gedeiht."));
  AddDetail(({"abwesenheit"}),BS("Nicht da."));
  AddDetail(({"substanz"}),BS("Langsam macht Dich das alles hier nervoes."));
  AddDetail(({"etwas"}),BS("Du solltest hier verschwinden. Sofort."));
  AddDetail(({"kraefte","daemonische kraefte"}),BS("Daemonische Kraefte "+
  "kaempfen an der Seite der Chaoten, was ihnen unschaetzbare Vorteile "+
  "einbringt, denn diese Kraefte sind ebenso boeartig wie die Chaoten."));
  AddDetail(({"vorteile"}),BS("Glaub mir. Es sind wirkliche Vorteile."));
  AddDetail(({"baeuche","bauch","gedaerme","spielchen"}),BS("Hehehe. Chaoten spielen "+
  "dann immer wieder lustige Spielchen. Mit mehreren Leuten ist ein "+
  "Renner: Welche Gedaerme gehoeren nun wem?"));
  AddDetail(({"herz","schlagende herzen","schlagendes herz"}),
  BS("Jemandem sein schlagendes Herz zu zeigen ist eine verdammt schwierige "+
  "Sache, die eine ziemliche Portion Fingerspitzengefuehl und perfektes "+
  "Timing erfordert. Chaoten sind in solchen Dingen oft etwas grobschlaechtig. "+
  "Bei ihnen ist das Opfer oft schon einige Minuten tot, bis sie mit dem Loeffel "+
  "ueberhaupt bis zum Herzen vorgedrungen sind. Nun, der boese Wille zaehlt."));
  AddDetail(({"sache","timing","fingerspitzengefuehl","portion"}),BS(
  "Die Sache mit dem schlagenden Herzen benoetigt wirklich viel Timing und "+
  "Fingerspitzengefuehl. Das ist nich einfach."));
  AddDetail(({"dinge","loeffel"}),BS("Chaoten gehen diese Dinge immer mit "+
  "viel Enthusiasmus an. Und mit Loeffeln, hehe."));
  AddDetail(({"minuten"}),BS("Wenn jemand schon einige Minuten tot ist, "+
  "so macht es irgendwie keinen Spass mehr, ihm sein Herz vors Gesicht "+
  "zu halten."));
  AddDetail(({"spass"}),BS("SPAAAAAAAAAASSSSS!"));
  AddDetail(({"gesicht"}),BS("Igitt. Hast Du schonmal an Waschen gedacht?"));
  AddDetail(({"tat"}),BS("ICH WARS NICH!"));
  AddDetail(({"renner"}),BS("Renn so schnell Du kannst! Dies ist die Burg "+
  "des Chaos!"));
  AddSpecialDetail(({"krieger","krieger des chaos"}),"det_krieger");
  AddDetail(({"nesaja"}),
  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH!!!!!\n"+
  "Du hoerst einen veraengstigten Magier in der Ferne verschwinden.\n"+
  "Du solltest wirklich niemanden so erschrecken.\n");
  AddDetail(({"ferne"}),BS("So weit kannst Du hier nicht sehen."));
  AddDetail(({"burg"}),BS("Dies ist die chaotische Burg, die Burg des "+
  "Chaos, erfuellt von einer daemonischen Dunkelheit, befallen von "+
  "daemonischen, boesartigen Kraeften und Heim der boesartigsten "+
  "Kreaturen des Morgengrauens, der CHAOTEN!"));
  AddDetail(({"morgengrauen"}),BS("Du befindest Dich in ihm."));
  AddDetail(({"wand","waende"}),BS("Zur Auswahl stehende Waende waeren hier "+
  "einmal die Burgmauer und zum zweiten die Rueckwand eines nicht naeher "+
  "benannten Hauses."));
  AddDetail(({"haus","haeuser"}),BS("Du weisst nicht, welche Art von Haus dies ist. "+
  "Nein, lass mich das anders sagen. Du weisst, dies ist eines dieser "+
  "dunklen schwarzen Haeuser der Burg des Chaos. Was Du nicht weisst ist, "+
  "was sich in diesem Haus befindet. Obwohl, so leise wie es hier ist, "+
  "kann das wohl nur eine Kneipe sein."));
  AddDetail(({"art"}),BS("Ich hasse dieses Detail."));
  AddDetail(({"detail"}),BS("Untersucht."));
  AddDetail(({"kneipe"}),BS("Ja, so langsam kriegst Du Durst."));
  AddDetail(({"durst"}),BS("Geh in die Kneipe."));
  AddDetail(({"decke"}),BS("Du kannst sie in der Finsternis nicht erkennen."));
  AddDetail(({"burgmauer"}),BS("Du Burgmauer ragt, in der Finsternis bedroh"+
  "lich und vage, vor Dir empor. Sie besteht aus gewaltigen Felsbloecken, "+
  "welche von was weisst Du wo hierhertransportiert wurden. An der Burgmauer "+
  "haengt ein Seil mit einer Schlaufe aus der Dunkelheit herab."));
  AddDetail(({"felsbrocken"}),BS("Das sind wirklich grosse Felsbrocken! "+
  "Und sie sind pechschwarz! Wo die wohl herkommen?"));
  AddDetail(({"rueckwand"}),BS("Die Rueckwand dieses Hauses besteht aus, "+
  "wie sollte es auch anders sein, pechschwarzen Backsteinen."));
  AddDetail(({"steine","backsteine"}),BS("Du betrachtest die Backsteine "+
  "der Rueckwand naeher und entdeckst eine (eigentlich recht grosse) "+
  "Inschrift in einer merkwuerdigen Sprache."));
  AddDetail(({"sprache"}),BS("Welch merkwuerdige Sprache."));
  AddDetail(({"inschrift"}),BS("Lies sie."));
  AddReadDetail(({"inschrift"}),
  "             ohoh Ummsl moerksl Ummwl harus rtt trt,\n"+
  "                     murms nurms Krozx Xurnszf\n\n"+
  "                       Manorm pollm Kroeter!\n\n"+
  "             HOHOOOOOO HOHOHOOOHHHOOOOOOHOHO HOOOOOHOOO\n");
  // dieses seil mit schlaufe ist fuer alle, die das chaos verraten
  // sterbt wie hunde
  AddDetail(({"gasse"}),BS("Durch diese hohe Gasse muss er kommen ... "+
  "Aehm, nein. Diese Gasse ist erfuellt von unirdischer Finsternis und "+
  "ist auch recht eng, begrenzt von der Rueckwand eines Hauses und einem "+
  "Teil der Burgmauer."));
  AddDetail(({"teil"}),BS("Das ist natuerlich nicht die ganze Burgmauer."));
  AddDetail(({"dunkel"}),BS("Ist das aber auch eine Finsternis!"));
  AddDetail(({"schatten"}),BS("Diese Gasse ist erfuellt von Schatten in "+
  "Schatten auf Schatten..."));
  AddDetail(({"schritte"}),BS("Trap Trap Trap Trarrap..."));
  AddDetail(({"stille"}),BS(" . . . . "));
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht alles etwas alt hier, aber sonst "+
  "nicht weiter unangenehm."));
  AddSounds(SENSE_DEFAULT,BS("Du kannst nur deine eigenen Schritte hoeren."));
  AddSounds(({"schritte"}),BS("Trap Trap Trap........"));
  
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2bu1"));
  AddExit("norden",CHAOS_GILDEN_ROOM("cl2bu3"));
  AddCmd(({"ja","nein","sag","sage"}),"jaein");
  AddCmd(({"erschreck","erschrecke"}),"joke");
    
}


int jaein(string was) {
   if (was == "ja" || query_verb() == "ja")
      write("Mach mal. Besser ist das.\n");
   if (was == "nein" || query_verb() == "nein")
      write("Nicht? Ich wuerd das aber mal tun. Puuuh, das sieht aus...\n");

   return 0;
}

string det_krieger() {
   if (this_player()->QueryProp(P_GUILD)=="chaos")
     return BS("Jaa, Du bist ein Krieger des Chaos!");
   return BS("Tritt der Chaosgilde bei! Werde Chaot!");
}

int joke(string was) {
  if (was == "niemanden")
  {
    write("Du erschreckst Niemanden.\n"+
    "Niemand sagt AAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH!\n"+
    "Niemand rennt schreiend davon.\n");
    return 1;
  } 
  return 0;
}
