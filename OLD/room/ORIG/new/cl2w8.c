#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)



string query_int_long()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
  return break_string(
  "\bDu befindest Dich auf einem Huegel in einer gewaltigen Hoehle. Soviel "+
  "ist klar. Vor Dir ragt eine grosse, schwarze Burg in die Hoehe und bie"+
  "tet einen beeindruckenden Anblick. Zur Burg fuehrte eine grosse Haenge"+
  "bruecke, welche vor Dir begann und am Eingang der Burg endete. Nun ist "+
  "die Bruecke jedoch nicht mehr da. Teile von ihr, dicke Halteseile und einige "+
  "Planken, haengen noch zum See hinunter, und die grossen Baumstaemme "+
  "hier stehen noch, doch man kann nicht mehr zur Burg gelangen. "+
  "Neben die ehemalige Bruecke wurde (noch hier auf dem "+
  "Huegel) ein Wachhaeuschen gebaut.\n"+
  "Mit etwas mehr Licht haettest Du von hier oben eine malerische Aussicht. "+
  "Vor Dir erstreckt sich der gruene See um die Burg herum, Weit im Osten "+
  "befindet sich ein grosser schwarzer Wald und im Suedosten liegt ein "+
  "kleiner schwarzer Hain.",78,0,1);

  return break_string(
  "\bDu befindest Dich auf einem Huegel in einer gewaltigen Hoehle. Soviel "+
  "ist klar. Vor Dir ragt eine grosse, schwarze Burg in die Hoehe und bie"+
  "tet einen beeindruckenden Anblick. Zur Burg fuehrt eine grosse Haenge"+
  "bruecke, welche vor Dir beginnt und am Eingang der Burg endet. Es "+
  "wurden zwei wohl sicherlich zehn, zwoelf Meter hohe Baumstaemme hier "+
  "in das Eis gerammt, richtig dicke Dinger. Zwei maechtige Seile ziehen "+
  "sich von den Spitzen dieser Pfaehle bis zu aehnlichen Vorrichtungen "+
  "in der Burgmauer. Von diesen Seilen fuehren immer wieder Halteseile "+
  "zu den Planken fuehren. Neben die Bruecke wurde (noch hier auf dem "+
  "Huegel) ein Wachhaeuschen gebaut.\n"+
  "Mit etwas mehr Licht haettest Du von hier oben eine malerische Aussicht. "+
  "Vor Dir erstreckt sich der gruene See um die Burg herum, Weit im Osten "+
  "befindet sich ein grosser schwarzer Wald und im Suedosten liegt ein "+
  "kleiner schwarzer Hain.",78,0,1);
  
}


create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Auf einem Huegel in einer Hoehle in einem Eisberg");
  AddDetail(({"boden"}),BS("Du stehst auf einem Weg in einem Eisberg. "+
  "Dementsprechend besteht der Boden aus weissen, leicht gruenlichen Eis, "+
  "auf welchen Kies zur Befestigung des Weges gestreut wurde. Vor Dir "+
  "beginnt jedoch die Haengebruecke mit ihren Holzplanken und Seilen. "+
  "Irgendwie sieht sie immer weniger vertrauenerweckend aus, je naeher man "+
  "an sie herankommt."));
  SetProp(P_INT_LONG,"@@query_int_long@@");
  AddDetail(({"weg"}),BS("Der Weg ist mit Kies bestreut und fuehrt nach "+
  "Suedosten den Huegel herab, waehrend er im Norden vor einer Haengebruecke "+
  "endet."));
  AddDetail(({"kies"}),BS("Das ist ganz normaler Kies."));
  AddDetail(({"huegel"}),BS("Du stehst hier auf einem Huegel innerhalb eines "+
  "Eisbergs, was gewissermassen erstaunlich ist. Auf jeden Fall hast Du eine "+
  "super Sicht auf die Burg vor Dir und die Hoehle um Dich herum. Oh ja. Und "+
  "auf den Saeuresee."));
  AddDetail(({"sicht"}),BS("Die Sicht hier ist wirklich gut, aber was Du "+
  "siehst, gefaellt Dir ganz und garnicht. Zum Beispiel diese wackelige "+
  "Haengebruecke."));
  AddDetail(({"beispiel"}),BS("Nimm einfach mal die Haengebruecke!"));
  AddDetail(({"fall"}),BS("Wow, von dieser Bruecke kannst Du verdammt tief "+
  "herunterfallen. In den Saeuresee. Das ist garnicht gut."));
  AddDetail(({"hoehle"}),BS("Du befindest Dich in einer gewaltigen Hoehle "+
  "und bist umgeben von Saeure und Eis. Vor Dir siehst Du eine grosse "+
  "schwarze Burg. Und all das befindet sich innerhalb eines schwarzen Eisbergs. "+
  "Wahnsinn."));
  AddDetail(({"eisberg"}),BS("Dies ist ein gewaltiger, schwarzer Eisberg."));
  AddDetail(({"wahnsinn"}),BS("Bald hat er Dich! Hahahahhaaaa!"));
  AddDetail(({"eis","weisses eis"}),BS("Du bist umgeben von weissen, leicht "+
  "gruenlichen Eis. Was Du von hier aus nicht sehen kannst, sind die Schich"+
  "ten schwarzen Eises, welche diesen Eisberg so schwarz erscheinen lassen."));
  AddDetail(({"schwarzes eis"}),BS("Das schwarze Eis befindet sich in den "+
  "aeusseren Schichten. Du kannst es von hier aus nicht sehen."));
  AddDetail(({"schichten"}),BS("Ein Eisberg ist aus sehr vielen Schichten "+
  "aufgebaut. Aber das wusstest Du schon, nicht wahr?"));
  AddDetail(({"saeure"}),BS("Ueberall in diesem Eisberg scheint es diese "+
  "merkwuerdige Saeure zu geben. Sie ist gruen, stinkt schrecklich und zer"+
  "setzt wohl so ziemlich alles. Vor Dir fuehrt eine Haengebruecke ueber "+
  "einen ganzen See von dieser Saeure."));
  AddDetail(({"see"}),BS("Du stehst auf einem Huegel. Vor Dir geht es "+
  "ziemlich steil abwaerts zu einem See von gruener Farbe. Aus eben diesem "+
  "See erhebt sich ein grosser Block weissen Eises, auf dem eine schwarze "+
  "Burg steht. Ueber den See und zur Burg fuehrt diese nicht gerade Vertrauen "+
  "einfloessende Haengebruecke."));
  AddDetail(({"farbe"}),BS("Der See hat eine gruene Farbe."));
  AddDetail(({"burg"}),BS("Woooow. Vor Dir erhebt sich eine grosse, schwarz"+
  "e Burg. Sie steht auf einem gewaltigen Eisblock in einem gruenen See. "+
  "Ihre Mauern bestehen aus grossen, schwarzen Steinbloecken mit kleinen, "+
  "schlitzartigen Fenstern. Ein grosses Portal fuehrt in die Burg. "+
  "Vier grosse Tuerme erheben sich aus ihr, ragen wie schwarze Finger in "+
  "das Halbdunkel ueber Dir. Ein Turm scheint leicht beschaedigt zu sein. "+
  "Ueber dem Portal siehst Du einen zinnenbewehrten Wehrgang, von dem man "+
  "sicherlich lustige Dinge werfen kann. Merkwuerdigerweise scheint es "+
  "um und ueber der Burg noch dunkler zu sein als sonst schon. Vielleicht "+
  "hast Du Dich da aber auch gestaeuscht..."));
  AddDetail(({"eisblock"}),BS("Der grosse weisse Eisblock erhebt sich aus "+
  "dem gruenen See."));
  AddDetail(({"mauer","mauern","burgmauer","burgmauern"}),
  BS("Die Mauern bestehen aus grossen, "+
  "schwarzen Steinbloecken, welche nahtlos aneinander angepasst wurden. "+
  "Du fragst Dich, wie diese ganzen Steinbloecke hierher gekommen sind."));
  AddDetail(({"steinbloecke"}),BS("Das sind aber verdammt grosse Steinbloecke!"));
  AddDetail(({"fenster"}),BS("Sind das Fenster oder sind das Schiessscharten?"));
  AddDetail(({"schiessscharten"}),BS("Sie sehen gefaehrlich aus. Ob da wohl "+
  "einer hinter steht?"));
  AddDetail(({"einer","einen"}),BS("Du kannst nix sehen..."));
  AddDetail(({"portal"}),BS("Dieses Portal ist schwarz, was auch sonst. "+
  "Du kannst nicht genau erkennen, woraus es besteht, doch die Fluegel "+
  "scheinen eine durchgehende Flaeche zu sein."));
  AddDetail(({"fluegel","torfluegel","flaeche"}),
  BS("Welch merkwuerdige Torfluegel. Ist das Holz? Ist das Stein? Ist das "+
  "Protoplasma? Du weisst es nicht."));
  AddDetail(({"stein","holz","protoplasma"}),BS("Du kannst Dich wirklich "+
  "nicht entscheiden."));
  AddDetail(({"tuerme","turm"}),BS("Diese Burg hat vier grosse Tuerme, "+
  "welche sich jeweils an den Ecken der Burg erheben. Sie bestehen aus "+
  "den gleichen schwarzen Steinbloecken wie die Mauern der Burg. Einer der "+
  "Tuerme scheint an seiner Spitze beschaedigt zu sein. Du siehst dort ein "+
  "Loch in der Mauer."));
  AddDetail(({"loch"}),BS("Es scheint, dass dort die Decke eingestuerzt ist."));
  AddDetail(({"spitze"}),BS("Auch Tuerme haben Spitzen, auch wenn diese "+
  "nicht allzu spitz sind in diesem Fall."));
  AddDetail(({"finger"}),BS("Die Tuerme ragen wie schwarze Finger, mahnend "+
  "ausgestreckt, in die Hoehe."));
  AddDetail(({"hoehe"}),BS("Diese Tuerme sind schon recht hoch."));
  AddSpecialDetail(({"wehrgang"}),"det_wehrgang");
  AddDetail(({"dinge"}),BS("LUSTIGE Dinge."));
  AddDetail(({"lustige dinge"}),BS("Heheheheeee,"));
  AddDetail(({"dunkelheit"}),BS("Die Dunkelheit scheint sich um diese "+
  "Burg zusammen, scheint sie zu umhuellen, zu bedecken wie ein uebergro"+
  "sses Laken. Es ist ein schauderhafter Anblick."));
  AddDetail(({"laken"}),BS("Du weisst, was ein Laken ist. Ausserdem war "+
  "dies eine Metapher."));
  AddDetail(({"metapher"}),BS("Wenn Du nicht weisst, was eine Metapher "+
  "ist, bist Du besser drann auf dieser Welt."));
  AddDetail(({"welt"}),BS("Sie ist schrecklich."));
  AddDetail(({"anblick"}),BS("Es ist ein ganz schauderhafter, unheiliger "+
  "Anblick."));
  AddSpecialDetail(({"haengebruecke","bruecke"}),"det_bruecke");
  AddSpecialDetail(({"bohlen","holzbohlen","planken"}),"det_bohlen");
  AddDetail(({"seite"}),BS("Meinst Du die Ober- oder die Unterseite?"));
  AddDetail(({"oberseite","unterseite"}),BS("Wovon?"));
  AddDetail(({"oberseite von bruecke","unterseite von bruecke"}),
  BS("Fuer eine sichere Ueberquerung wuerde ich die Oberseite der Bruecke "+
  "empfehlen. Hehe."));
  AddSpecialDetail(({"fuehrungsseil"}),"det_fuehrungsseil");
  AddSpecialDetail(({"halteseil","halteseile"}),"det_halteseil");
  AddDetail(({"baumstaemme","baumstamm","pfaehle"}),
  BS("Es sind zwei wirklich dicke "+
  "Baumstaemme, schwarz wie die Nacht und steinhart. Die kriegt man nicht "+
  "so schnell klein."));
  AddDetail(({"seile"}),BS("Du meinst bestimmt die 2 maechtigen Halteseile, "+
  "nicht wahr?"));
  AddDetail(({"vorrichtungen"}),BS("Die Vorrichtungen in der Burgmauer sind "+
  "massive, eiserne Ringe, welche in die Mauer eingelassen wurden."));
  AddDetail(({"spitzen"}),BS("Auch Pfaehle haben Spitzen. Jedenfalls wenn "+
  "man sie angespitzt hat."));
  AddDetail(({"nacht"}),BS("Diese Baumstaemme sind schwarz wie die "+
  "Nacht."));
  AddDetail(({"dinger"}),BS("Das SIND aber auch dicke Dinger!"));
  AddDetail(({"menge"}),BS("Das sind wirklich viele Seile!"));
  AddDetail(({"wachhaeusschen"}),BS("Es ist eher ein Unterstand. Hier "+
  "koennen sich Wachen unterstellen, wenn der Regen sie zermuerbt hat."));
  AddDetail(({"wachen"}),BS("Natuerlich gibt es hier Wachen! Was denkst "+
  "Du denn?"));
  AddDetail(({"regen"}),BS("Er faellt leicht, aber stetig, von der Decke "+
  "dieser Hoehle auf Dich herab."));
  AddDetail(({"decke"}),BS("Sie befindet sich hoch ueber Dir und leuchtet "+
  "leicht. Leichter Regen faellt von ihr auf Dich herab."));
  AddDetail(({"leuchten"}),BS("Es ist nicht sehr hell. Besonders hier."));
  AddDetail(({"licht"}),BS("Es ist ziemlich dunkel hier. Mit etwas mehr "+
  "Licht haette man hier eine richtig gugte Aussicht."));
  AddDetail(({"aussicht"}),BS("Eine gute Aussicht hast Du nicht, da es "+
  "hier zu dunkel ist."));
  AddDetail(({"wald","hain"}),BS("Du kannst den Wald in der Dunkelheit "+
  "kaum erkennen."));
  
  
  AddSmells(SENSE_DEFAULT,BS("Es stinkt hier nach Saeure."));
  AddSmells(({"saeure"}),BS("BAEEEEEEEH!"));
  
  AddSounds(SENSE_DEFAULT,BS("Tropf Tropf."));
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl2w7"));
  AddSpecialExit("norden","exit_norden");
}

string det_wehrgang()
{
  return "Ja, ist da.\n";
}

string det_bruecke()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
  return BS("Die Haengebruecke ist zerstoert. Eine Halteseile haengen noch "+
  "von den grossen Baumstaemmen hier, einige Fuehrunsseile haengen in "+
  "den gruenen See hinab, beladen mit einigen der Holzbohlen, welche langsam "+
  "hin- und herschwingen. Wie soll man jetzt nur zur Burg gelangen.");
  
  return BS("Die Haengebruecke schwingt sich ueber "+
  "den gruenen See, um am Portal der Burg zu enden. Sie besteht aus "+
  "jeder Menge Holzbohlen, welche quer von einer Seite der Bruecke zur "+
  "anderen fuehren. Diese Bohlen werden durch ein duennes Fuehrungsseil "+
  "gehalten, welches von der Burg zum Huegel fuehrt. Von den zwei dicken "+
  "Halteseilen fuehren immer wieder Seile hinab zu den Bohlen und zum "+
  "Fuehrungsseil. Na, wenn das mal haelt.");
}

string det_bohlen()
{
   if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
   return BS("Sie schwingen leicht hin- und her, wenn sie so in den See "+
   "herabhaengen.");
   
   return BS("*Bibber* Sehr vertrauenerweckend "+
  "sehen die aber nicht aus...");
}

string det_fuehrungsseil()
{
   if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
     return BS("Es haengt teilweise noch in den See hinab.");
   return BS("Es ist so ... duenn! Ob es wohl halten wird...");
}


string det_halteseil()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS("Die Halteseile haengen zerrissen und gekappt in den See "+
    "hinab. Einige Bohlen schwingen an ihnen hin- und her.");
    
  return BS("OK, es gibt hier zwei Arten von Halteseilen. Das eine sind "+
  "die zwei ganz dicken vom Huegel zur Burg, das andere sind jede Menge "+
  "weniger dicke Halteseile, welche von den zwei dicken hinab zu den "+
  "Bohlen fuehren.");
}


int exit_norden()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
  {
     write("OH NEIN! Da gehst Du nicht hin! Schliesslich fehlt die Bruecke!\n");
     return 1;
  }
  this_player()->move(CHAOS_GILDEN_ROOM("cl2br1"),M_GO,"auf die Bruecke");
  return 1;
}

