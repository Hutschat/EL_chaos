#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS(x) break_string(x,78)

int last_dig,last_stone;

inherit CHAOS_GILDEN_ROOM("cl3bu_std");


create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu1"));
  last_dig = 0;
  last_stone = 0;
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Unter der Burg");
  SetProp(P_INT_LONG,BS("Du befindest Dich am Treffpunkt zweier Gaenge. "+
  "Einer fuehrt nach Nordwesten, einer nach Nordosten von Dir fort. "+
  "Hier muenden sie in einer kleinen Halle ineinander. Im Suedwesten dieser "+
  "Halle ist die Wand eingebrochen und hat einen grossen Haufen Schutt "+
  "hinterlassen. Hinter dieser Wand entdeckst Du jedoch nicht mehr als "+
  "pures, graues Gestein."));
  AddDetail(({"decke"}),BS("Wie alle Raeume hier unten hat auch dieser "+
  "Raum eine hohe Decke, welche in der Dunkelheit dieser Halle kaum zu "+
  "erkennen ist. Sie scheint sich jedoch halbkreisfoermig ueber Dir zu "+
  "woelben unt mit Mustern verziert zu sein."));
  AddDetail(({"raeume"}),BS("Hier unter der Burg befinden sich viele "+
  "Raeume. Du bist wirklich ueberrascht. Langsam kommt Dir die obere "+
  "Burg nur wie eine Fassade vor..."));
  AddDetail(({"burg"}),BS("Du befindest Dich unter einer grossen, schwar"+
  "zen Burg. Sie beinhaltet die beruehmte und beruechtigte Chaosgilde."));
  AddDetail(({"chaosgilde"}),BS("Die Chaosgilde ist die satanischste "+
  "aller Gilden. Darin kann ihr wirklich keine das Wasser reichen."));
  AddDetail(({"gilden"}),BS("Es gibt mehrere Gilden, aber die Chaosgilde "+
  "ist wirklich die beste."));
  AddDetail(({"wasser"}),BS("Alles trocken hier."));
  AddDetail(({"fassade"}),BS("Ist die obere Burg wirklich nur eine "+
  "Fassade? Sicherlich nicht. Dennoch ist sie nur ein Teil des Ganzen, "+
  "denn diese Raeume hier unten scheinen von Anfang an grosse Bedeutung "+
  "fuer die Burg und die Chaosgilde gehabt zu haben."));
  AddDetail(({"teil","ganzes","teile"}),BS("Viele Teile ergeben ein Ganzes."));
  AddDetail(({"anfang"}),BS("Diese Burg ist garnicht mal so alt. Somit "+
  "liegt der Anfang nicht sehr weit zurueck..."));
  AddDetail(({"bedeutung"}),BS("Natuerlich besitzen diese Raeume hier "+
  "grosse Bedeutung. Schau nur, wieviele es davon gibt :)."));
  AddDetail(({"dunkelheit","finsternis","duesternis","licht"}),
  BS("Hier ist es wirklich dunkel. Die wenigen Fackeln schaffen es bei "+
  "weitem nicht, den Raum adaequat zu erleuchten. Und so ist der Raum "+
  "von Schatten erfuellt, welche sich im Schein der Fackeln merkwuerdig "+
  "lebendig zu bewegen scheinen."));
  AddDetail(({"schein"}),BS("Diese Fackeln leuchten wirklich nicht sehr "+
  "hell. Du hast Fackeln eigentlich immer heller in Erinnerung gehabt."));
  AddDetail(({"erinnerung","erinnerungen"}),BS("Jeder hat Erinnerungen."));
  AddDetail(({"fackel","fackeln"}),BS("Die Fackeln leuchten schwach in "+
  "die Dunkelheit dieses Raumes hinein. Sie sind merkwuerdig schwarz "+
  "und scheinen magisch zu sein, da sie einfach nicht herabbrennen. "+
  "Um sie vor unberechtigtem Entfernen zu schuetzen, wurden sie fest "+
  "mit den Fackelhaltern in den Waenden verbunden."));
  AddDetail(({"raum","saal","halle"}),QueryProp(P_LONG));
  AddDetail(({"entfernen"}),BS("Du kannst diese Fackeln nicht entfernen. "+
  "Abgesehen davon, dass Du dazu nicht berechtigt bist, sind sie fest "+
  "mit den Fackelhaltern verbunden."));
  AddDetail(({"fackelhalter","halter"}),
  BS("Die Fackelhalter bestehen aus schwar"+
  "zem Gusseisen und sind extrem massiv. Du entdeckst keinerlei "+
  "Verzierungen an ihnen. Es sind einfach dicke, massive Halter."));
  AddDetail(({"gusseisen"}),BS("Wow, diese Fackelhalter sind massiv!"));
  AddDetail(({"verzierungen"}),BS("An den Fackelhaltern entdeckst Du "+
  "keine Verzierungen."));
  AddDetail(({"muster"}),BS("Die Muster kannst Du beim besten Willen "+
  "nicht erkennen."));
  AddDetail(({"treffpunkt"}),BS("Hehe. Hier treffen sich zwei Gaenge. "+
  "Deshalb nennt man das hier einen Treffpunkt."));
  AddDetail(({"gang","gaenge"}),BS("Einer der Gaenge fuehrt nach Nord"+
  "osten fort, der andere nach Nordwesten."));
  AddDetail(({"nordosten","nordwesten"}),BS("Geh einfach hin."));
  AddDetail(({"wille","willen"}),BS("Dein Wille mag gross sein, aber "+
  "die Muster kannst Du trotzdem nicht erkennen."));
  AddDetail(({"suedwesten"}),BS("Im Suedwesten der Halle ist die Wand "+
  "eingebrochen. Ein grosser Haufen Schutt haeuft sich dort auf dem "+
  "Boden."));
  AddDetail(({"wand","waende"}),BS("Die Waende sind sehr hoch und bestehen "+
  "aus grossen, schwarzen Steinen. In den Waenden stecken in gewissen "+
  "Abstaenden Fackelhalter mit Fackeln, welche den Raum notduerftig "+
  "erhellen. Einige Bilder an den Waenden nehmen diesem Raum einen Teil "+
  "seiner kalten, schwarzen Aura. Jedoch nur einen Teil. Im Suedwesten "+
  "ist, wie gesagt, die Wand aus unerklaerlichen Gruenden eingebrochen "+
  "und bildet nun einen grossen Haufen Schutt. Hinter der Wand entdeckst "+
  "Du jedoch nur graues Gestein."));
  AddDetail(({"stein","steine","steinbrocken"}),
  BS("Die Waende bestehen aus grossen, "+
  "schwarzen Steinen, welche unnatuerlich dunkel und kalt zu sein "+
  "scheinen. Du hast Steine wie diese schon oben in der Burg zur Genuege "+
  "gesehen. Die Steine der eingestuerzten Wand liegen als grosser Haufen "+
  "Schutt auf dem Boden dieses Saals."));
  AddDetail(({"schutt","haufen","haufen schutt"}),BS("Wow, dieser Haufen "+
  "schutt sieht wirklich interessant. Die Steine der Wand sind quasi "+
  "zerbroeselt und liegen jetzt in kleinen Brocken auf dem Boden. Was "+
  "man hier wohl alles entdecken kann, wenn man nur sucht? Ausserdem "+
  "sind dies die ersten dieser schwarzen Steine, welche Du in handlicher "+
  "Groesse antriffst..."));
  AddDetail(({"brocken"}),BS("Diese Steinbrocken sind wirklich nicht gross."));
  AddDetail(({"gestein"}),BS("Das Gestein ist grau, hart und ansonsten "+
  "geradezu schrecklich uninteressant."));
  AddDetail(({"boden","fussboden"}),BS("Der Fussboden ist mit schwarzen Fliesen "+
  "bedeckt. Ein Teil von ihm ist jedoch mit einem grossen Haufen Schutt "+
  "bedeckt, welcher von der Wand im Suedwesten stammt, welche eingestuerzt "+
  "ist."));
  AddDetail(({"fliese","fliesen"}),BS("Die Fliesen sind schwarz, gross, "+
  "quadratisch und eigentlich nicht weiter interessant."));
  AddDetail(({"abstaende"}),BS("Die Abstaende zwischen den einzelnen "+
  "Fackelhaltern sind wirklich gross. Dadurch wird dieser Saal in eine "+
  "ziemliche Dunkelheit gehuellt."));
  AddDetail(({"aura"}),BS("Die Aura dieses Raumes ist kalt und unangenehm, "+
  "fast boesartig. Das wird jedoch abgemildert durch die Fackeln und die "+
  "Gemaelde, welche an den Waenden befestigt sind."));
  AddDetail(({"bilder","gemaelde"}),BS("Es sind drei lebensgrosse Gemaelde, "+
  "welche Du hier bewundern kannst. Da sie so gross sind, kanst Du das "+
  "sogar einzeln tun."));
  AddDetail(({"bild 1","gamaelde 1"}),BS("Das erste Gemaelde zeigt, in "+
  "voller Lebensgroesse, Wuqour, den Ritualmeister der Chaosgilde. Das rote"+
  "Leuchten seiner Augen zeugt weniger von seiner Macht als die Tatsache, "+
  "dass der Raum selbst sich hinter ihm zu verbiegen und zu verschieben "+
  "scheint. Dieses Gemaelde hat den Meister wirklich gut getroffen."));
  AddDetail(({"wuqour","meister","ritualmeister"}),BS("Wuqour ist der Ritual"+
  "meister der Chaosgilde. Er beherrscht das Chaos noch besser als Kruuolq "+
  "selbst, auch wenn er jenem in Macht und Boshaftigkeit knapp unterlegen "+
  "ist. Wuqour ist einer der Maechtigsten aller Chaoten."));
  AddDetail(({"chaos"}),BS("Das Chaos zu beherrschen ist eine der groessten "+
  "Herausforderungen, welche es gibt."));
  AddDetail(({"herausforderung","herausforderungen"}),BS("Beherrsche das "+
  "Chaos! Herrsche darueber!"));
  AddDetail(({"macht","boshaftigkeit"}),BS("Kruuolq ist der boshafteste aller "+
  "Chaoten. Ausserdem ist er auch der maechtigste. Wenn schon nicht wegen "+
  "seines Koennens, in dem er Wuqour knapp unterlegen ist, so doch wegen "+
  "dem, was er ist. Kruuolq ist das Oberhaupt der Chaosgilde. Er ist der "+
  "Herr der Chaoten und der Bringer des Chaos."));
  AddDetail(({"koennen"}),BS("Koennen ist nicht alles fuer einen Chaoten. "+
  "auf die Boshaftigkeit kommt es an."));
  AddDetail(({"oberhaupt"}),BS("Kruuolq ist das Oberhaupt der Chaosgilde."));
  AddDetail(({"chaot","chaoten"}),BS("Chaoten gehoeren der Chaosgilde an."));
  AddDetail(({"bringer","herr"}),BS("Kruuolq ist der Herr der Chaoten, der "+
  "Bringer des Chaos."));
  AddDetail(({"maechtigster","macht"}),BS("Kruuolq ist der maechtigste aller "+
  "Chaoten."));
  AddDetail(({"augen"}),BS("Wuqours Augen leuchten in einem daemonischen Rot."));
  AddDetail(({"tatsache"}),BS("Das ist natuerlich nur ein Gemaelde. Da "+
  "kann man vieles hinmalen..."));
  AddDetail(({"bild 3","gemaelde 3"}),BS("Auf diesem Gemaelde abgebildet "+
  "siehst Du Kruuolq, das Oberhaupt der Chaosgilde. Aufrecht und stolz "+
  "steht er dort, eine Aura der Macht ausstrahlend, welche Dich fast koer"+
  "perlich beruehrt. Dies ist Kruuolq, Bringer des Chaos."));
  AddSpecialDetail(({"bild 2","gemaelde 2"}),"det_gemaelde");
  AddDetail(({"kruuolq"}),BS("Kruuolq ist das Oberhaupt der Chaos-Gilde. Er "+
  "ist schon recht alt, was bei der Gefaehrlichkeit des Chaos schon "+
  "recht ungewoehnlich ist. Mit einer gewaltigen Macht in seinen Augen "+
  "starrt er auf Dich herab."));
  AddDetail(({"gilde"}),BS("Du meinst wohl die Chaosgilde."));
  AddDetail(({"gefaehrlichkeit"}),BS("Das Chaos ist ungeheuer gefaehrlich."));
  AddDetail(({"groesse"}),BS("Diese Steine sind geradezu handlich. Wie "+
  "eigentuemlich."));
  AddDetail(({"lebensgroesse"}),BS("Diese Gemaelde sind wirklich gross."));
  AddDetail(({"bild"}),BS("Es gibt sogar mehrere davon!"));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  
  AddCmd(({"such","suche","durchsuch","durchsuche"}),"search_for");
  AddCmd(({"grab","grabe"}),"dig_for");
  AddCmd(({"nimm","nehme"}),"take_from");
  AddCmd(({"betritt","betrete","kletter","klettere"}),"enter");
  
  AddExit("nordosten",CHAOS_GILDEN_ROOM("cl3bu2"));
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl3bu4"));
  
}

string det_gemaelde() {
  return "Du siehst, wundervoll detailreich und lebensecht gezeichnet, etwa folgendes:\n"+
         call_other(CHAOS_GILDEN_ROOM("cl2_challe"),"int_long",this_player(),this_player())+
         "Du bewunderst die raeumliche Tiefe, welche der Kuenstler in diesem Kunstwerk\n"+
         "erschaffen hat. Es sieht fast so aus, als koennte man das Gemaelde betreten.\n";
}
         

int search_for(string was) {
  if (member_array(was,({"haufen","schutt","schutthaufen","in schutt",
                         "in haufen","in schutt","in schutthaufen"}))==-1)
     return notify_fail("Was moechtest Du durchsuchen?\n"),0;
  
  write(BS("Du suchst, stellst aber schnell fest, dass man hier eher mit "+
           "einer Schaufel graben sollte. So kommt man zu nix."));
  return 1;
}


int dig_for(string was) {
  object ob;
  if (member_array(was,({"haufen","schutt","schutthaufen","in schutt",
                         "in haufen","in schutt","in schutthaufen"}))==-1)
     return notify_fail("Worin moechtest Du denn graben?\n"),0;
  
  if (!present("schaufel",this_player()))
    return write("Ohne Schaufel macht Graben hier keinen Sinn.\n"),1;
  
  write("Du graebst im Schutthaufen umher.\n");
  say(this_player()->Name(WER)+" graebt im Schutthaufen.\n");
  
  if (time()-last_dig<1200) 
    return write("Leider findest Du nichts. Da war wohl jemand vor Dir da.\n"),1;
    
  last_dig = time();
  ob = clone_object(CHAOS_GILDEN_OBJ("cl3_haken"));
  write("Wooow, im Schutt findest Du ein eisernes .... Geraet!\n");
  say(this_player()->Name(WER)+" findet etwas.\n");
  
  if (ob->move(this_player(),M_GIVE)== ME_TOO_HEAVY) {
    ob->move(this_object(),M_NOCHECK);
    write("Du kannst es nicht mehr tragen.\n");
  }
  return 1;
}  
  
  
int enter(string was) {
  if (member_array(was,({"gemaelde","bild","in gemaelde","in bild"}))>-1)
    return write("Es gibt da mehrere Gemaelde. Welches solls denn sein?\n"),1;
  if (member_array(was,({"gemaelde 1","bild 1","in gemaelde 1","in bild 1",
                         "gemaelde 3","bild 3","in gemaelde 3","in bild 3"}))>-1)
    return write("Du knallst voll gegen das Bild. Aua!\n"),1;
  if (member_array(was,({"gemaelde 2","bild 2","in gemaelde 2","in bild 2"}))>-1)
  {
    write("Du betrittst das Bild.\n");
    this_player()->move(CHAOS_GILDEN_ROOM("cl2_challe"),M_GO,"durch das Bild");
    return 1;
  }
  return notify_fail("Was moechtest Du betreten?\n"),0;
}


int take_from(string was) {
  object ob;
  if (member_array(was,({"stein","brocken","stein von haufen","steinbrocken",
                         "brocken von haufen","steinbrocken von haufen"}))==-1)
     return notify_fail("Was moechtest Du nehmen?\n"),0;
  if (present("stein")) return 0;

  if (time()-last_stone<1200) 
    return write("Leider findest Du keinen schoenen Stein. Da war wohl jemand vor Dir da.\n"),1;
  
  write("Du suchst im Schutthaufen umher.\n");
  say(this_player()->Name(WER)+" sucht im Schutthaufen.\n");
  
    
  last_stone = time();
  ob = clone_object(CHAOS_GILDEN_OBJ("cl3_stone"));
  write("Du findest einen schwarzen Stein.\n");
  say(this_player()->Name(WER)+" findet etwas.\n");
  
  if (ob->move(this_player(),M_GIVE)== ME_TOO_HEAVY) {
    ob->move(this_object(),M_NOCHECK);
    write("Du kannst es nicht mehr tragen.\n");
  }
  return 1;
}  
