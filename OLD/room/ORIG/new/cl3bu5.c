#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu3"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Am Ufer eines gruenen Sees");
  SetProp(P_INT_LONG,BS("Du befindest Dich in einer grossen Halle. Dueste"+
  "res Licht scheint von draussen herein. Es scheint deshalb von draussen "+
  "herein, weil die Nordwestwand nicht existiert und somit eine Seite des "+
  "Fuenfecks, welches dieser Raum darstellt, frei ist. Man koennte einfach "+
  "dort weitergehen und in den Saeuresee springen, welcher dort gruen und "+
  "leise vor sich hinblubbert. Die restlichen Waende bestehen aus schwarzen "+
  "Stein, in den eiserne Fackelhalter geschlagen wurden, obwohl die darin "+
  "befindlichen Fackeln jetzt eigentlich nichts mehr bringen. Immerhin "+
  "macht sich hier eine gewisse Kontinuitaet breit. Die hohen Gaenge fuehren "+
  "weiter nach Suedosten und Sueden."));
  AddDetail(({"halle"}),BS("Dies ist eine Halle, wie sie fuer die Raeumlich"+
  "keiten unterhalb der chaotischen Burg typisch ist. Nun, gewissermassen "+
  "typisch, bis auf die Tatsache, dass dieser Raum die Form eines Fuenfecks "+
  "hat und seine Nordwestliche Wand fehlt. Ja. Darauf laeuft das wohl hinaus."));
  AddDetail(({"raeumlichkeiten"}),BS("Die Raeumlichkeiten hier sind exklu"+
  "siv und exquisit. Du befindest Dich unterhalb der chaotischen Burg in "+
  "den tieferen Raeumen der Chaosgilde."));
  AddDetail(({"burg","chaosgilde"}),BS("Du befindest Dich hier unterhalb der "+
  "schwarzen Burg, welche die beruechtigte Chaosgilde beheimatet. Diese "+
  "Burg wurde auf einem Felsen ueber einem grossen Saeuresee gebaut, und "+
  "hier stehst Du nun direkt am Rande dieses Sees."));
  AddDetail(({"fels","felsen"}),BS("Die chaotische Burg steht auf einem "+
  "grossen Felsen. Dieser Felsen wiederum wurde ausgehoehlt, um die Raeum"+
  "lichkeiten zu schaffen, in denen Du Dich befindest. Um den Felsen herum "+
  "blubbert friedlich ein gruener Saeuresee, den Du von hier aus bequem "+
  "erreichen kannst."));
  AddDetail(({"see","saeuresee"}),BS("Die Farbe dieses Saeuresees ist "+
  "bezeichnenderweise gruen. Er scheint recht warm zu sein, und Blasen "+
  "steigen in ihm auf, so dass er permanent zu blubbern scheint. Welch "+
  "unscheinbarer Anblick fuer einen derart gefaehrlichen See. Der See "+
  "reicht bis direkt an den Raum heran."));
  AddDetail(({"anblick"}),BS("Der See sieht eigentlich ueberhaupt nicht "+
  "gefaehrlich aus. Doch er ist es. Das und mehr."));
  AddDetail(({"blasen"}),BS("Andauernd steigen Blasen aus dem Saeuresee "+
  "auf und lassen ihn leise vor sich hinblubbern. Warum dies geschieht, "+
  "ist auch Dir nicht ganz klar."));
  AddDetail(({"raeume"}),BS("Auf dieser Ebene befinden sich sehr viele "+
  "Raeume. Diese Raeumlichkeiten sind nur fuer Chaoten erreichbar, oder "+
  "sie sollten es jedenfalls sein. Deshalb befindest Du Dich an einem "+
  "hoechst exklusiven Ort."));
  AddDetail(({"chaot","chaoten"}),BS("Chaoten sind die KriergerInnen "+
  "des Chaos, die Mitglieder der beruechtigten Chaosgilde."));
  AddDetail(({"krieger","kriegerinnen"}),BS("Das ist wahr. Chaoten "+
  "sind Krieger oder Kriegerinnen. Sie waren es schon immer, und sie "+
  "werden es immer sein."));
  AddDetail(({"chaos"}),BS("Sieh das Chaos!!!"));
  AddDetail(({"farbe","gruen"}),BS("Die Farbe des Saeuresees ist ein "+
  "gemeines, dunkles Gruen."));
  AddDetail(({"licht"}),BS("Das Licht in diesem Raum stammt zu einem Teil "+
  "von den Fackeln, welche in gusseisernen Fackelhaltern an den Waenden "+
  "dieses Raumes haengen. Zu einem anderen Teil scheint das Licht jedoch "+
  "von draussen durch die nicht vorhandene Wand in den Raum hinein. Auch "+
  "dieses Licht ist sehr duester, aber immerhin noch heller als die "+
  "wenigen Fackeln dieses Raumes."));
  AddDetail(({"raum"}),BS("Dieser Raum hat die Form eines Fuenfecks. Er "+
  "etwa aus wie ein Quadrat, dessen nordwestliche Ecke abgeschnitten wurde. "+
  "Und, um das Ganze noch schlimmer zu machen, wurde die Wand auf dieser "+
  "Seite entfernt oder garnicht erst geschaffen. Durch diese Seite kann "+
  "man problemlos in den Saeuresee fallen, wenn man nicht aufpasst..."));
  AddDetail(({"form"}),BS("Die Form dieses Raumes ist die eines Fuenfecks."));
  AddDetail(({"fuenfeck","ecken","flaeche"}),BS("Ein Fuenfeck ist eine "+
  "konvexe Flaeche, welche fuenf Ecken besitzt. Nur dass das klar ist."));
  AddDetail(({"quadrat"}),BS("Ein Quadrat ist .... ach, Du weisst das. "+
  "Ich vertrau Dir da voellig. "));
  AddDetail(({"ecke"}),BS("Dieser Raum hat wirklich eine Form, als haette "+
  "man einem Quadrat eine Ecke abgeschnitten."));
  AddDetail(({"finsternis","duesternis","dunkelheit"}),BS("In diesem Raum "+
  "ist es nicht so finster wie in den anderen Raeumen hier unten. Das ist "+
  "jedoch verstaendlich, denn immerhin fehlt hier eine komplette Wand..."));
  AddDetail(({"nordwestwand"}),BS("Die Nordwestwand fehlt. Es scheint so, "+
  "als haette sie noch niemals existiert."));
  AddDetail(({"decke"}),BS("Die Decke ist hier ziemlich hoch, doch das "+
  "ist sie hier unten ja ueberall. Immerhin ist es hier hell genug um "+
  "sehen zu koennen, wie sie aussieht. Sie sieht chaotisch aus. Eine "+
  "seltsam surreale Bemalung bedeckt sie, eine Sammlung wilder Farbkleckse "+
  "in allen Schattierungen von Rot ohne Bedeutung oder Substanz."));
  AddDetail(({"bemalung"}),BS("Die Bemalung ist fuerchterlich. Sie sieht "+
  "fast kindlich aus, hat aber blutruenstige, gewalttaetige Untertoene, "+
  "welche Dich zutiefst beunruhigen. Die Mischung all dieser Rottoene "+
  "hat etwas ... graessliches und fuerchterliches an sich."));
  AddDetail(({"untertoene"}),BS("Die Untertoene dieser Bemalung sind "+
  "gewalttaetig, blutruenstig und graesslich."));
  AddDetail(({"mischung","mischungen","toene","rottoene","schattierungen",
              "rot","farbe"}),
  BS("Diese Bemalung benutzt ganz spezielle Schattierungen und Mischungen "+
  "der Farbe Rot, welche in Dir Gewalttaetigkeit und Entsetzen zugleich "+
  "wachrufen."));
  AddDetail(({"gewalttaetigkeit","entsetzen"}),BS("Was fuer eine schreckliche "+
  "Bemalung."));
  AddDetail(({"kleckse","farbkleckse"}),BS("Diese Farbkleckse sind alles "+
  "andere als zufaellig. Sie scheinen nichts konkretes zu bedeuten, doch "+
  "sie wecken ein merkwuerdiges Grauen in Dir."));
  AddDetail(({"grauen","gewalttaetigkeit","entsetzen"}),BS("Du wendest "+
  "Deinen Blick schnell von dieser Bemalung ab und bist froh, dass es in "+
  "den anderen Raeumen zu dunkel ist, um die Decke zu sehen."));
  AddDetail(({"sammlung"}),BS("Die Bemalung besteht aus einer Sammlung "+
  "roter Farbkleckse."));
  AddDetail(({"farbe"}),BS("Die Farbe ist ROT."));
  AddDetail(({"wand","waende"}),BS("Nun, bis auf die Nordwestwand sind alle "+
  "Waende vorhanden. Die Waende bestehen aus schwarzen, grossen Steinen, "+
  "in welche in grossen Abstaenden Fackelhalter eingeschlagen wurden."));
  AddDetail(({"steine","stein"}),BS("Die Steine hier sind wirklich gross, "+
  "so wie Du es von den anderen Raeumen hier unten oder der Burg dort "+
  "oben erwarten wuerdest. Hier erlebst Du leider keine Ueberraschung."));
  AddDetail(({"ueberraschung"}),BS("Man ist diese Burg oeeeedeeeeee..."));
  AddDetail(({"blick"}),BS("Du wendest Deinen Blick schnell ab."));
  AddDetail(({"fackelhalter"}),BS("Die bekannten gusseisernen Fackelhalter "+
  "stecken fest in den Steinen der Waende. Ihre schwarze, zeitlose "+
  "Eleganz wird durch keinerlei Schnoerkel und Verzierungen gestoert. "+
  "In den Fackelhaltern stecken schwarze, ebenso zeitlose Fackeln."));
  AddDetail(({"eleganz"}),BS("*Huestel* Ok, diese Fackelhalter mit "+
  "'zeitloser Eleganz' zu beschreiben, war wohl wirklich etwas "+
  "uebertrieben. Aber was soll ich machen? Hey, sein wir mal ehrlich. Diese "+
  "Fackelhalter sind verflucht oede. So. Da hast Du's nun."));
  AddDetail(({"schnoerkel","verzierungen"}),BS("Schnoerkel und Verzierungen "+
  "sucht man bei diesen Fackelhaltern vergebens. Sie bestehen aus massiven "+
  "Eisen und bestechen durch ihre schlichte Linienfuehrung."));
  AddDetail(({"eisen"}),BS("Wow. Massives Eisen."));
  AddDetail(({"linienfuehrung"}),BS("Die Linienfuehrung dieser Fackelhalter ist "+
  "wirklich _ziemlich_ schlicht."));
  AddDetail(({"fackeln"}),BS("Die Fackeln sind schwarz und magisch. Sie "+
  "verbreiten deshalb kaum Licht und flackern unnatuerlich stark, sie brennen "+
  "jedoch auch nie herunter..."));
  AddDetail(({"flackern"}),BS("Diese Fackeln flackern tierisch."));
  AddDetail(({"boden"}),BS("Der Boden besteht aus nicht weiter interessanten "+
  "schwarzen Fliesen, die Du eigentlich wirklich nicht naeher untersuchen "+
  "solltest, wenn mans genau nimmt."));
  AddDetail(({"fliesen"}),BS("Hmpf. Nix. Ich sagte Dir schon, voellig uninter"+
  "essant."));
  AddDetail(({"gaenge"}),BS("Die Gaenge fuehren nach Sueden und nach Suedosten."));
  AddDetail(({"abstaende"}),BS("Die Abstaende zwischen den Fackelhaltern sind "+
  "wirklich gross."));
  AddDetail(({"bedeutung","substanz"}),BS("Die Bedeutung und Substanz der "+
  "Bemalung an der Decke ist Dir momentan noch verborgen. Doch wer weiss, "+
  "vielleicht loest Du auch dieses Raetsel einmal."));
  AddDetail(({"raetsel"}),BS("'Was bedeutet die Bemalung der Decke?'"));
  AddDetail(({"ebene"}),BS("Diese Ebene befindet sich unter der chaotischen "+
  "Burg."));
  AddDetail(({"kontinuitaet"}),BS("Ueberall hier auf dieser Ebene gibt es "+
  "diese wirklich abgrundtief haesslichen Fackelhalter mit ihren dummen "+
  "schwarzen Fackeln. Das ist zwar fuerchterlich aetzend, gibt dieser "+
  "Ebene jedoch eine gewisse Kontinuitaet."));
  AddDetail(({"mitglieder","gilde"}),BS("Die Chaosgilde ist eine sehr grosse Gilde "+
  "mit wirklich vielen, boesartigen Mitgliedern."));
  AddDetail(({"ort"}),BS("Dieser Ort ist die untere Ebene der Chaosgilde!"));
  AddDetail(({"rand","ufer"}),BS("Du befindest Dich direkt am Ufer des "+
  "grossen Saeuresees."));
  
  AddSmells(SENSE_DEFAULT,BS("Der See stinkt ziemlich."));
  AddSounds(SENSE_DEFAULT,BS("Der Saeuresee blubbert leise vor sich hin."));
  AddSounds(({"see","saeuresee"}),BS("*Blubber Blubber*"));
  AddSmells(({"see","saeuresee"}),BS("Er riecht scheusslich."));
  
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl3bu6"));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl3bu4"));
  
  AddCmd(({"spring","springe","huepfe","huepf"}),"jump_in");
  AddCmd(({"trink","trinke"}),"drink_it");
  AddCmd(({"halt","halte"}),"hold_in");
  
  
}

int fakekill(string str1, string str2)
{
    object ob;
    SetProp(P_KILL_NAME,str1);
    SetProp(P_KILL_MSG,str2);
    this_player()->SetProp(P_GHOST,1);
    ob = clone_object(this_player()->QueryProp(P_CORPSE)||"/std/corpse");
    if (objectp(ob))
    {
        ob->move(environment(this_player()),M_NOCHECK);
        ob->Identify(this_player());
    }
    ob = clone_object("/room/death/death_mark");
    if (!objectp(ob)) return 1;
    ob->move(this_player(),M_NOCHECK);
    return 1;

}

int jump_in(string was) {
  notify_fail("Worein moechtest Du springen?\n");
  if (was != "in see" && was != "in saeuresee") return 0;
  write("Du springst in den Saeuresee. Schlechte Idee.\n");
  say(this_player()->Name(WER)+" springt in den Saeuresee.\n"+
      this_player()->Name(WER)+" wird in Sekunden zersezt. Ekelhaft.\n",
      this_player());
  fakekill("Ein Sprung in den Saeuresee",0);
  return 1;
}

int drink_it(string was) {
  notify_fail("Woraus moechtest Du denn trinken?\n");
  if (was != "aus see") return 0;
  write("Du schluerfst etwas Saeure aus dem See. Schmerzen erfuellen Dich!\n");
  say(this_player()->Name(WER)+" trinkt aus dem See und bruellt vor Schmerzen!\n");
  if (this_player()->QueryProp(P_POISON) < 6) 
  {
     this_player()->SetProp(P_POISON,6);  
     write("Du bist vergiftet!!!!!\n");
  }
  return 1;
}

int hold_in(string was) {
  int i;
  
  notify_fail("Worein moechtest Du denn was halten?\n");
  if (was != "hand in see" && was != "hand in saeuresee") return 0;
  if ((i=this_player()->QueryProp(P_MAX_HANDS))-this_player()->QueryProp(P_USED_HANDS)<1)
  {
     write("Leider hast Du keine Hand mehr frei. Hehe. Hehe. Hehe.\n");
     return 1;
  }
  this_player()->SetProp(P_MAX_HANDS,i-1);
  write("Du haeltst Deine Hand in den See.\n"+
        "Deine Hand loest sich in Sekundenschnelle auf.\n"+
        "Es tut nicht mal weh.\n");
  say(this_player()->Name(WER)+" haelt seine Hand in den See, "+
        "woraufhin diese sich aufloest.\n",this_player());
  return 1;
}
