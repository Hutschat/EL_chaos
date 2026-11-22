#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"In einem kleinem Wald in einer grossen Hoehle");
  SetProp(P_INT_LONG,break_string(
  "Du befindest Dich immernoch im kleinen Wald. Der Pfad fuehrt von "+
  "Suedosten nach Nordwesten. Im Nordwesten glaubst Du das Ende des "+
  "Waldes schon ungefaehr ausmachen zu koennen, da es dort etwas "+
  "heller wird.\n"+
  "Das Unterholz ist biegsam und dornig wie eh und je, es macht das "+
  "Abweichen vom Pfad fast unmoeglich. Der scharfe Geruch von Saeure "+
  "wird hier schon staerker. Der leichte Nieselregen troepfelt weiter "+
  "auf Dich herab. Dies ist ein sehr trostloser Ort, denkst Du Dir.",78,0,1));
  AddDetail(({"wald"}),BS("Aehaem. Nun, es ist eigentlich ein sehr kleiner "+
  "Wald, gerade wenn er schon da vorne zuende ist. Andererseits besteht "+
  "er aus merkwuerdigen, schwarzen Baeumen und merkwuerdigem, schwarzen "+
  "Unterholz."));
  AddDetail(({"baeume","baum"}),
  BS("Die Baeume sehen schwarz aus und wachsen in "+
  "so ziemlich alle Richtungen, nur nicht nach oben. Vielleicht liegt es "+
  "an der Kaelte, dass sie sich lieber am warmen Boden halten. Du weisst "+
  "es nicht. Ihre Blaetter sehen ledrig aus und ebenso schwarz wie der "+
  "Rest des Baumes. Alles in allem nichts, was man sich gerne in den "+
  "Vorgarten stellen wuerde."));
  AddDetail(({"richtungen"}),BS("Manche Baeume knicken sogar in einer "+
  "gewissen Hoehe wieder um und wachsen nach UNTEN! Sachen gibts!"));
  AddDetail(({"hoehe"}),BS("Die Hoehe dieser Baeume ist extrem unterdurch"+
  "schnittlich, um es mal vorsichtig auszudruecken. Sie sind vielleicht "+
  "doppelt so hoch wie Du, durchschnittlich gesehen."));
  AddDetail(({"kaelte"}),BS("Es ist wirklich bitter kalt hier."));
  AddDetail(({"blaetter"}),BS("Diese kleinen Blaetterchen sind schwarz "+
  "und Du kannst keine Adern irgendwelcher Art in ihnen erkennen. Anderer"+
  "seits sind sie jedoch auch extrem dick."));
  AddDetail(({"blaetterchen"}),BS("Na guuuut, es sind Blaetter."));
  AddDetail(({"art"}),BS("This ist the seduction of art."));
  AddDetail(({"adern"}),BS("Du kannst in den Blaettern keine erkennen."));
  AddDetail(({"rest"}),BS("Der Rest des Baumes ist schwarz und ist von "+
  "einer steinharten Rinde umgeben."));
  AddDetail(({"rinde"}),BS("Wow, ist die hart."));
  AddDetail(({"vorgarten"}),BS("Nur Weicheier haben Vorgaerten."));
  AddDetail(({"weicheier","weichei"}),BS("Ja genau! Ich sagte: WEICHEIER! "+
  "JAWOLL! DAS SAGTE ICH! UND WENN DU WAS DAGEGEN HAST, DANN KOMM HER, UND "+
  "WIR TRAGEN DAS AUS WIE MAENNER! JA? HAST DU MICH VERSTANDEN? WEICHEI! "+
  "WEICHEI!"));
  AddDetail(({"maenner"}),BS("Hoehoe."));
  AddDetail(({"boden"}),BS("Ist da. Er besteht aus Eis und Schnee und ist "+
  "teilweise vom Unterholz ueberwuchert. Quer durch den Wald zieht sich "+
  "jedoch ein mit Kies befestigter Weg."));
  AddDetail(({"eis"}),BS("Das Eis in dieser Hoehle ist verflucht kalt! *Brrr*"));
  AddDetail(({"schnee"}),BS("Es ist eher Schneematsch..."));
  AddDetail(({"schneematsch"}),BS("Er bedeckt den Boden unt fuehrt zur Gefahr "+
  "von ueberfrierender Naesse."));
  AddDetail(({"gefahr"}),BS("WAAAAAAAAH! GEFAHR! GEFAHR! GEFAHR!"));
  AddDetail(({"naesse","ueberfrierende naesse"}),BS("Dieser Schneematsch, be"+
  "sonders auf Eis, fuehrt zur grossen Gefahr ueberfrierender Naesse."));
  AddDetail(({"hoehle"}),BS("Diese Hoehle ist wirklich verdammt gross. Du "+
  "befindest Dich in ihr, dieser Hoehle innerhalb eines gewaltigen Eisbergs."));
  AddDetail(({"eisberg"}),BS("Er ist ueberall um Dich herum!"));
  AddDetail(({"ende"}),BS("Im Nordwesten kannst Du das Ende des Waldes er"+
  "kennen."));
  AddDetail(({"licht"}),BS("Das Licht am Ende des Waldes leuchtet schwach zu "+
  "Dir. Andererseits nehmen die Baeume um Dich herum soviel Licht weg, dass "+
  "Du es gut erkennen kannst."));
  AddDetail(({"decke"}),BS("Du kannst Die Decke nicht so richtig erkennen. "+
  "Lediglich hier und da entdeckst Du zwischen den Baeumen eine schwach "+
  "leuchtende Flaeche."));
  AddDetail(({"flaeche"}),BS("Das ist leider nicht der Himmel, sondern die "+
  "Decke dieser gewaltigen Hoehle."));
  AddDetail(({"himmel"}),BS("Welcher Himmel?"));
  AddDetail(({"unterholz"}),BS("Das Unterholz hier besteht aus dornigen, "+
  "zaehen Bueschen, welche von schwarzer Farbe und gummiartiger Konsistenz "+
  "sind."));
  AddDetail(({"buesche"}),BS("Die Buesche sind dornig, zaeh und widerstands"+
  "faehig. Sie haben sich an ihre rauhe Umgebung sehr gut angepasst."));
  AddDetail(({"umgebung"}),BS("Diese Umgebung ist nicht gerade freundlich. "+
  "ist kalt, nass und riecht nach Saeure."));
  AddDetail(({"farbe"}),BS("Schwarz."));
  AddDetail(({"schwarz"}),BS("SCHWARZ."));
  AddDetail(({"konsistenz"}),BS("So viele Fremdwoerter verwirren Dich "+
  "hoffentlich nicht..."));
  AddDetail(({"fremdwoerter"}),BS("KON-SIS-TENZ! Huuuuuuuh *shiver*"));
  AddDetail(({"sachen"}),BS("Sachen halt :)"));
  AddDetail(({"durchschnitt"}),"Wo schneiden wir Dich jetzt durch? Ahh, "+
  "da.\nDein Koerper gehorcht Dir nicht.\n");
  AddDetail(({"koerper"}),BS("Huuuuuuuuuuh :-)"));
  AddDetail(({"pfad","weg"}),BS("Der Weg fuehrt aus dem Suedosten in den "+
  "Nordwesten. Er ist mit Kies bestreut und macht einen ganz ordentlichen "+
  "Eindruck. "));
  AddDetail(({"suedosten","nordwesten"}),BS("Das sind Richtungen."));
  AddDetail(({"saeure"}),BS("Es riecht hier ziemlich stark nach Saeure."));
  AddDetail(({"abweichen"}),BS("Durch das dichte Unterholz wird ein "+
  "Abweichen vom vorgegebenen Pfad ein aeusserst schwieriges Unterfangen."));
  AddDetail(({"unterfangen"}),BS("Nun, dieses Unterfangen wird Dir hoechst"+
  "wahrscheinlich sowohl deine Beinkleider kosten als auch erfolglos enden."));
  AddDetail(({"beinkleider"}),BS("Schicke Beinkleider sind immer von Vorteil."));
  AddDetail(({"vorteil"}),BS("Nutze jeden Vorteil, den Du bekommen kannst."));
  AddDetail(({"erfolg"}),BS("Hier wirst Du wohl keinen Erfolg haben."));
  AddDetail(({"nieselregen"}),BS("Das Tauwasser troepfelt von der hohen "+
  "Decke dieser Hoehle auf Dich hernieder. Im Grunde ist es nur ein sehr "+
  "sehr leichter Regen, doch es troepfelt staendig. Langsam fragst Du Dich, "+
  "ob vielleicht irgendwann dieser ganze Eisberg ueber Dir zusammenfallen "+
  "koennte. Welch unangenehme Vorstellung."));
  AddDetail(({"tauwasser"}),BS("Das Tauwasser tropft von der hohen Decke "+
  "dieser Hoehle auf Dich herab. Es ist nicht viel, ab es tropft stetig."));
  AddDetail(({"regen"}),BS("Das Tauwasser tropft in einer Art Regen auf "+
  "Dich herab, obwohl Du noch keine normalen, so sporadischen Regen mit"+
  "gemacht hast."));
  AddDetail(({"grund"}),BS("Grund wird hier nicht beschrieben."));
  AddDetail(({"vorstellung"}),BS("*Brrr*, welch unangenehme Vorstellung."));
  
  AddDetail(({"ort"}),break_string("Du fasst fuer Dich selbst zusammen:\n"+
  "Du befindest Dich in einer Hoehle in einem merkwuerdigem Eisberg aus "+
  "schwarzen Eis. Es ist fuerchterlich kalt und ein eisiger Regen troepfelt "+
  "staendig und stetig auf Dich herab. Die Luft ist erfuellt von intensivem "+
  "Gestank nach Saeure und die Natur scheint verdreht und krank. Du hast "+
  "schon die verschiedensten Orte besucht, und dieser gehoert ganz klar zu "+
  "den Trostlosesten.",78,0,1));
  AddDetail(({"schwarzes eis"}),BS("Hier gibt es kein schwarzes Eis. Das "+
  "ist auch gut, denn sonst gaebe es vielleicht garkein Licht."));
  AddDetail(({"luft"}),BS("Die Luft riecht abgestanden trotz des leichten "+
  "Windes, den Du hier unten spuerst. Ausserdem ist sie von einem Gestank "+
  "von Saeure erfuellt. Nun, sagst Du Dir, wenigstens kann man sie atmen."));
  AddDetail(({"wind"}),BS("Er blaesst leicht durch diesen kleinen Wald. "+
  "Einerseits ist er angenehm, andererseits bringt er aber auch den Gestank "+
  "nach Saeure mit sich."));
  AddDetail(({"geruch","gestank"}),BS("Der intensive Gestank von Saeure "+
  "erfuellt die Luft und ist extrem unangenehm."));
  AddDetail(({"natur"}),BS("Wenn man sich diese Baeume ansieht, dann kann "+
  "man sich einerseits wundern, wo die Natur ueberall Leben hervorbringen "+
  "kann und sich andererseits fragen, was hier wohl mit der Natur geschehen "+
  "ist."));
  AddDetail(({"leben"}),BS("Das Leben findet immer einen Weg..."));
  AddDetail(({"orte"}),BS("Diese Hoehle im Eisberg gehoert sicherlich zu "+
  "den trostlosesten Orten, die Du kennst."));
  AddDetail(({"trostlose orte"}),BS("Diese Hoehle gehoert sicher dazu."));
  
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht hier nach abgestandener Luft und "+
  "stark nach Saeure"));
  AddSmells(({"saeure"}),BS("Baeeh, das riecht scheusslich."));
  
  AddSounds(SENSE_DEFAULT,BS("Der Wind erzeugt ein leichtes Heulen und der "+
  "Regen tropft trommelnd auf Dich herab."));
  AddSounds(({"wind"}),BS("Der Wind heult ein wenig, wenn er durch diese "+
  "Hoehle weht."));
  AddSounds(({"regen"}),BS("*tropf tropf*"));
  
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl2w6"));
  AddSpecialExit("suedosten","cl2w2");
}


int cl2w2()
{
  tell_room(CHAOS_GILDEN_ROOM("cl2w4"),this_player()->Name(WER)+
  " kommt aus dem Nordwesten den Pfad entlang.\n");
  tell_room(CHAOS_GILDEN_ROOM("cl2w5"),this_player()->Name(WER)+
  " kommt aus dem Nordwesten den Pfad entlang.\n");
  
  this_player()->move(CHAOS_GILDEN_ROOM("cl2w2"),M_GO,"nach Suedosten");
  return 1;
}