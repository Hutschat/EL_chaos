#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Versteckt im Wald");
  SetProp(P_INT_LONG,
  BS("Du befindest Dich versteckt in einem derartig kleinen Wald, dass Du garnicht "+
  "gedacht haettest, dass ein derartiges Versteck wie dieses dort moeglich "+
  "waere. Trotzdem befindest Du Dich an einer kleinen, sorgsam gerodeten "+
  "Lichtung mitten im Wald. Die verwachsenen Baeume ragen um Dich herum auf "+
  "und versperen Dir fast die ganze Sicht. An einer Stelle kannst Du jedoch "+
  "durch das Unterholz und die Baeume blicken und dort auf einen Weg blicken, "+
  "welcher sorgsam mit Kies befestigt durch diesen Wald fuehrt. Du kannst nicht "+
  "anders, als diese sorgsam praeparierte Stelle fuer einen Hinterhalt zu "+
  "bewundern. Vom Weg aus hat man sicherlich keine Moeglichkeit, diesen "+
  "Ort zu entdecken. Grinsend stehst Du da, waehrend der Regen auf Dich "+
  "herabtroepfelt."));
  AddDetail(({"wald"}),BS("Dies ist ein Wald. Jaaa, ein kleiner Wald, aber "+
  "ein Wald, der immerhin Platz fuer dieses wunderbare Versteck bietet. "+
  "Ausserdem hat dieser Wald Baeume (schwarz, kraenklich und alles andere "+
  "als gerade, aber immerhin Baeume) und ein dichtes Unterholz (das irgend"+
  "wie an Gummi erinnert, aber extrem dornig ist und somit durchaus als "+
  "Unterholz durchgeht), womit er alle Voraussetzungen erfuellt, ein Wald "+
  "zu sein."));
  AddDetail(({"versteck"}),BS("Dies ist ein ganz vorzuegliches Versteck, "+
  "da es alle Kriterien erfuellt, die ein gutes Versteck haben sollte: Man "+
  "kann erstens den Weg, den man ueberwachen will, gut beobachten, und "+
  "wird zweitens nicht von denen gesehen, welche auf dem Weg vorbeikommen. "+
  "Dies ist ein Platz, welcher jedes Chaotenherz hoeherschlagen laesst."));
  AddDetail(({"kriterien"}),BS("Die Kriterien fuer ein gutes Versteck sind "+
  "a) nicht gesehen werden und b) alles sehen koennen. Und diese Kriterien "+
  "erfuellt dieses Versteck geradezu vorbildlich."));
  AddDetail(({"platz"}),BS("Dieser Platz hier ist ein absolut gutes "+
  "Versteck fuer einen Hinterhalt! Wow!"));
  AddSpecialDetail(({"weg"}),"det_weg");
  AddDetail(({"hinterhalt","gedicht"}),
  "Ah, der Hinterhalt!\n"+
  "Welches boesartiges  Spiel!\n"+
  "Den Ahnungslosen ueberfiel,\n"+
  "Aus dem Versteck, das garnicht zu sehen ist,\n"+
  "Beschmiert mit Dreck, und voller Hinterlist,\n"+
  "Ein Chaot, ein ganz ganz uebler Mann,\n"+
  "Er zueckt sein Schwert und holt weit aus!\n"+
  "Er tut jetzt, was er am besten kann!\n"+
  "Der Ahnungslose  haucht  sein  Leben aus!\n"+
  "Mit grimmigem Gesicht, und satanischem Grinsen,\n"+
  "Verscharrt der Chaot den verstorbenen Mann.\n"+
  "Er graebt ihn tief ein, bedeckt ihn mit Binsen,\n"+
  "Und saeubert den Platz, so schnell er nur kann.\n"+
  "Dann versteckt er sich sorgsam wieder.\n"+
  "Es ist nass hier und ganz bitterlich kalt.\n"+
  "Eine Dunkelheit senkt sich auf ihn nieder.\n"+
  "Und er lauert auf den naechsten Hinterhalt.\n\n"+
  "                    Unbekannter (boesartiger) Chaot, 1998\n") ;
  AddDetail(({"spiel","ahnungsloser","dreck","mann","schwert","gesicht",
  "grinsen","binsen"}),BS("Wow, was fuer ein boesartiges Gedicht!\n"));
  AddDetail(({"hinterlist"}),BS("Hinterlist ist sehr wichtig fuer jeden "+
  "Chaoten. Ein Chaot ohne Hinterlist ist ein guter Chaot! Und DAS ist "+
  "eine verdammte Schande fuer ihn!"));
  AddDetail(({"chaot","chaoten"}),BS("Chaoten sind die besten!"));
  AddDetail(({"schande"}),BS("Es gibt keine groessere Schande fuer einen "+
  "Chaoten, als ein GUTER Chaot zu sein. Ein satanischer Chaot macht "+
  "seiner Gilde Ehre, ein boeser Chaot ist akzeptabel, aber ein GUTER "+
  "Chaot ist eine Schande!"));
  AddDetail(({"gilde","gilden","chaosgilde"}),BS("Die Chaosgilde ist die "+
  "satanischste aller Gilden. Und etwas anderes wollte sie niemals sein."));
  AddDetail(({"herz","chaotenherz"}),BS("Ein Chaotenherz ist schwarz und "+
  "kalt. Erfuellt ist es von den Maechten der Finsternis!"));
  AddDetail(({"maechte","maechte der finsternis"}),BS("Werde Chaot! Ergib "+
  "Dich der dunklen Seite der Macht!"));
  AddDetail(({"seite","macht","dunkle seite der macht"}),
  BS("Die dunkle Seite IST staerker. Mach Dir das klar. Da gibt es kein "+
  "Vertun. Ergib Dich der dunklen Seite der Macht. Fuehle die Maechte des "+
  "Chaos."));
  AddDetail(({"vertun"}),BS("Es gibt kein Vertun. Ergib Dich der dunklen "+
  "Seite der Macht!"));
  AddDetail(({"finsternis"}),BS("Spuere die Finsternis! Ergib Dich der "+
  "Finsternis! Werde Chaot!"));
  AddDetail(({"baeume"}),BS("Jau, dieser Wald hat auch einige Baeume. Sie "+
  "sehen schwarz und verkrueppelt aus, sind aber voellig gesund. Sie sind "+
  "nur ... anders, eine Gattung, welche Du anderorts noch nie gesehen hast!"));
  AddDetail(({"gattung"}),BS("Du weisst nicht, zu welcher Gattung diese "+
  "Baeume gehoeren. Ihre steinharte Rinde, ihre dicken, schwarzen Blaetter, "+
  "ihr ungewoehnlicher Wuchs machen sie absolut andersartig."));
  AddDetail(({"rinde"}),BS("Boh, ist die hart!"));
  AddDetail(({"blaetter"}),BS("Diese Blaetter fasst Du NICH an!"));
  AddDetail(({"wuchs"}),BS("Diese Baeume wachsen nicht einfach hinauf in "+
  "dieh Hoehe, nein, sie nehmen ihren eigenen, individuellen Weg."));
  AddDetail(({"hoehe"}),BS("Die Baeume sind durchschnittlich etwa doppelt "+
  "so hoch wie ein Elf."));
  AddDetail(({"elf"}),BS("Naja, wenigstens sinds keine Hobbits :)."));
  AddDetail(({"hobbits"}),BS("Hoehoehoe."));
  AddDetail(({"lichtung"}),BS("Hier hat jemand mit viel Muehe eine kreis"+
  "runde Lichtung in den Wald geschlagen. Man sieht noch die Stuempfe der "+
  "Baeume, welche hier standen. Diese Muehe hat sich jedoch gelohnt. Dies "+
  "hier ist ein perfektes Versteck fuer einen Hinterhalt."));
  AddDetail(({"muehe"}),BS("Diese Baeume mit ihrer steinharten Rinde zu "+
  "faellen, wird sicherlich keine einfache Sache sein. Aber es hat sich "+
  "gelohnt."));
  AddDetail(({"sache"}),BS("Neeh, Sache beschreibe ich jetzt nicht."));
  AddDetail(({"stuempfe"}),BS("Diese Baeume wurden anscheinend mit Aexten "+
  "gefaellt (aber womit auch sonst? :))"));
  AddDetail(({"aexte"}),BS("Du weisst, was Aexte sind."));
  AddDetail(({"gummi"}),BS("Gummi??? Was'n das?"));
  AddDetail(({"stelle"}),BS("An dieser Stelle stehen die Baeume nicht ganz "+
  "so dicht wie sonst in diesem (kleinen) Wald. So kann man hier gut den "+
  "Weg beobachten, welcher hier vorbeifuehrt."));
  AddDetail(({"sicht"}),BS("Du bist ueberall von Baeumen umgeben und die "+
  "Sicht ist dementsprechend lausig. An einer Stelle jedoch kannst Du "+
  "durch den Wald bis auf einen Weg sehen, der nicht weit von dieser Lichtung "+
  "vorbeifuehrt."));
  AddDetail(({"unterholz"}),BS("Das Unterholz hier ist so dicht wie eh und "+
  "jeh. An einer Stelle jedoch ist es etwas abgerodet worden, so dass man "+
  "sich dort durch die Buesche zwaengen kann und so auf den Weg gelangt,"+
  "der hier vorbeifuehrt!"));
  AddDetail(({"buesche"}),BS("Das Unterholz besteht aus gummiartigen, dornig"+
  "em Gestruepp und Bueschen der gleichen Art."));
  AddDetail(({"gestruepp","buesche"}),BS("*Seufz* Da gehen Deine Hosen hin."));
  AddDetail(({"hosen"}),BS("Lass uns hier nicht ueber Hosen reden."));
  AddDetail(({"art"}),BS("Sei bloss ARTig!"));
  AddDetail(({"ort"}),BS("Du befindest Dich in einer Hoehle in einem Eisberg. "+
  "Aber das wusstest Du sicherlich schon."));
  AddDetail(({"hoehle"}),BS("Diese Hoehle ist wirklich gewaltig gross!"));
  AddDetail(({"eisberg"}),BS("Es ist ein schwarzer Eisberg, und er ist "+
  "ueberall um Dich herum!"));
  AddDetail(({"decke"}),BS("Du kannst die Decke nur als eine schwach "+
  "leuchtende Flaeche weit ueber Dir ausmachen."));
  AddDetail(({"flaeche"}),BS("Sie leuchtet! Und das ist gut, denn sonst "+
  "waer es hier noch viel dunkler als es jetzt schon ist."));
  AddDetail(({"dunkelheit"}),BS("Die Dunkelheit ist die Verbuendete eines "+
  "jeden Chaoten."));
  AddDetail(({"kies"}),BS("Er liegt auf dem Weg."));
  AddDetail(({"moeglichkeit"}),BS("Du bist schon auf diesem Weg gewesen. "+
  "Die Chancen, dieses Versteck zu entdecken, sind quasi gleich null."));
  AddDetail(({"chancen"}),BS("Naja, aber fast so gut wie null!"));
  AddDetail(({"verbuendete"}),BS("Und eine starke Verbuendete ist sie..."));
  AddDetail(({"grinsen"}),BS("Hehehe."));
  AddDetail(({"regen"}),BS("Das Schmelzwasser troepfelt leicht, aber stetig, "+
  "auf Dich herab. *Brrrrr*. Es ist verdammt kalt."));
  AddDetail(({"schmelzwasser"}),BS("Das Schmelzwasser sammelt sich an der "+
  "Decke dieser Hoehle und faellt dann als leichter Regen zur Erde herab."));
  AddDetail(({"erde"}),BS("Naja, das ist keine Erde unter Dir, das sind "+
  "Eis und Schnee."));
  AddDetail(({"boden"}),BS("Der Boden ist mit Unterholz ueberwuchert, doch "+
  "wie Du weisst, besteht er aus Eis und einer duennen, aber gefaehrlichen, "+
  "Lage Schnee."));
  AddDetail(({"eis"}),BS("Das Eis hier ist weiss mit einem leichtem Stich "+
  "ins gruenliche, aber ansonsten absolut normal."));
  AddDetail(({"stich"}),BS("Der Farbton des Eises macht Dich ein klein wenig "+
  "nervoes, ist aber ansonsten kein Grund zur Beunruhigung."));
  AddDetail(({"grund"}),BS("Im Grunde ist das kein Grund. Aber andererseits..."));
  AddDetail(({"farbton","farbe"}),
  BS("Es ist ein Weiss mit einem leichten Stich ins Gruenliche"));
  AddDetail(({"gruen"}),BS("GRUEN."));
  AddDetail(({"beunruhigung"}),BS("Na, wer wird denn schon wegen der Farbe des "+
  "Eises nervoes werden???"));
  AddDetail(({"kaelte"}),BS("Du befindest Dich in einem Eisberg. Kein Wunder, "+
  "dass es hier extrem kalt ist."));
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht hier durchdringend nach Saeure."));
  AddSmells(({"saeure"}),BS("Es stinkt geradezu ekelhaft. Jawohl!"));
  
  AddSounds(SENSE_DEFAULT,BS("Der Wind pfeift durch die Baeume."));
  AddSounds(({"wind"}),BS("Huuuuh Huuuuuh"));
  
  AddCmd(({"fass","fasse"}),"fasse");
  AddCmd(({"zwaeng","zwaenge"}),"zwaenge");
  AddItem(CHAOS_GILDEN_MON("cl2_chaot1"),REFRESH_DESTRUCT);  
}

int fasse(string was) {
  if (was != "blaetter an")
  {
     notify_fail("Was willst Du anfassen?\n");
     return 0;
  }
  write("Du fasst die Blaetter an. Deine Haende brennen wie Feuer.\n");

  this_player()->reduce_hit_point(random(5));
  say(this_player()->Name(WER)+" fasst die Blaetter an und sagt: Autsch!\n",
      this_player()); 

  return 1;
}

int zwaenge(string was) {
  if (was != "durch gebuesch" && was != "durch unterholz"  && 
      was != "durch buesche")
  {
    notify_fail("Wodurch moechtest Du Dich zwaengen?\n");
    return 0;
  }
  write("Du zwaengst Dich durch die Buesche.\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2w2"),M_GO,"durch die Buesche",
  "zwaengt sich","zwaengt sich durch die Buesche");
  return 1;
}

string det_weg()
{
  if (!find_object(CHAOS_GILDEN_ROOM("cl2w2")))
    return "DU KANNST GARNIX SEHEN! GANZ KLAR EIN FEHLER IM RZG!!! WAAAAAAAH!\n";

  tell_room(this_player()->Name(WER)+" beobachtet den Weg.\n",({this_player()}));
  return (CHAOS_GILDEN_ROOM("cl2w2"))->int_long(this_player(),this_player());
}    
