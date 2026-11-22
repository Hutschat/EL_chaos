#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2bu_std");
#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu9"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In der chaotischen Burg");
  SetProp(P_INT_LONG,break_string("\bWow ist das dunkel hier. Geradezu erschreckend "+
  "uebernatuerlich dunkel! Du befindest in einer wirklich absolut fin"+
  "steren Gasse in der Burg des Chaos. Im Norden und Osten von Dir befindet "+
  "sich die maechtige Burgmauer mit ihren gewaltigen Felsbrochen, welche "+
  "Du in dieser Form noch nie gesehen hast. Im Sueden siehst Du gerade "+
  "so eine Hauswand, bevor Du dagegenlaeufst. Die Gasse fuehrt weiter "+
  "nach Westen in die Dunkelheit hinein.\n"+
  "Noerdlich von Dir muss sich wohl einer der grossen Tuerme dieser Burg "+
  "majestaetisch in den Himmel erheben. Das weisst Du wegen der Tuer in der "+
  "noerdlichen Burgmauer. Du  kannst nicht einmal annaehernd weit genug "+
  "sehen, um das obere Ende der Mauer zu erkennen.",78,0,1));
  AddDetail(({"boden"}),BS("Der Boden ist genau so schwarz und duester wie "+
  "deine Umgebung, wenn nicht noch finsterer. Die Pflastersteinen sind im "+
  "schwaerzestem Schwarz gefaerbt, was Du je gesehen hast. Sie saugen jeg"+
  "liches Licht in sich auf und es ist, als wuerden deine Augaepfel ebenfalls "+
  "aus ihren Hoehlen gerissen werden, um ebenfalls von diesem hungrigen "+
  "Boden verschlungen zu werden. Zitternd wendest Du Deinen Blick aufwaerts. "+
  "Hmpf. Auch nicht viel besser."));
  AddDetail(({"umgebung"}),BS("Deine Umgebung ist diese Burg, wuerde ich mal "+
  "so sagen..."));
  AddDetail(({"burg"}),BS("Du befindest Dich in einer sehr merkwuerdigen, "+
  "schwarzen Burg."));
  AddDetail(({"hoehle","eisberg"}),BS("Dies ist eine Hoehle in einem gewaltigen, "+
  "schwarzen Eisberg."));
  AddDetail(({"schwarz"}),BS("Oh wooooooow! DAS ist ein schwarz!"));
  AddDetail(({"licht"}),BS("Das wenige Licht wird von den Steinen um Dich "+
  "herum geradezu aufgesogen..."));
  AddDetail(({"augaepfel"}),BS("Puuuuh, Du kneifst Deine Augen zusammen."));
  AddDetail(({"hoehlen"}),BS("Deine Augaepfel befinden sich noch in ihren "+
  "Hoehlen. Alles ist in bester Ordnung."));
  AddDetail(({"ordnung"}),BS("Dies ist die chaotische Burg. Hier gibt es keine "+
  "Ordnung. Und schon gar keine 'beste Ordnung'."));
  AddDetail(({"blick"}),BS("Ueberall scheint das Licht aus deinen Augen "+
  "weggesogen zu werden, als waeren diese Steine gierig, alles Licht aufzu"+
  "nehmen, was sie ergattern koennen."));
  AddDetail(({"augen"}),BS("Deine Augen sind wichtig."));
  AddDetail(({"steine","stein"}),BS("Alle Steine in dieser verfluchten Burg "+
  "scheinen gleich zu sein, egal ob Pflastersteine, Felsbrocken oder die "+
  "Backsteine, aus denen die Haeuser gemauert wurden. Sie alle sind verflucht "+
  "schwarz und entziehen sich absolut Deinem Verstaendnis."));
  AddDetail(({"haeuser"}),BS("Hier kannst Du nur ein Haus sehen, und auch "+
  "das nur vage. Ist das dunkel hier..."));
  AddDetail(({"haus"}),BS("Das Haus befindet sich suedlich von Dir."));
  AddDetail(({"pflastersteine"}),BS("Du stehst drauf :). Nun, sie sind "+
  "schwarz, sie halten Dein Gewicht, somit genuegen sie Deinen Anspruechen."));
  AddDetail(({"gewicht"}),BS("Na, koenntest auch mal etwas mehr Sport "+
  "treiben..."));
  AddDetail(({"sport"}),BS("*seufz* Naja, sonst lass es."));
  AddDetail(({"ansprueche"}),BS("In dieser Burg sollte man seine Ansprue"+
  "che so klein wie moeglich halten..."));
  AddDetail(({"felsbrocken"}),BS("Die Felsbrocken bilden die gewaltige, "+
  "maechtige Burgmauer. Sie sind ebenso schwarz wie die Pflastersteine..."));
  AddDetail(({"burgmauer"}),BS("Die Burgmauer, breit, maechtig und stark, "+
  "erhebt sich noerdlich und oestlich von Dir. Sie ist derart hoch "+
  "(beziehungsweise Du kannst derart wenig sehen), dass man ihr oberes Ende "+
  "nicht erkennen kann."));
  AddDetail(({"chaos","chaoten","gilde","chaosgilde"}),BS("Jup, hier "+
  "befindet sich die Chaosgilde, Heim der Chaoten..."));
  AddDetail(({"heim"}),BS("Heim .... ein Heim haben ... *seeeeeufz*"));
  AddDetail(({"ende","oberes ende"}),BS("Du kannst das obere Ende der "+
  "Burgmauer nicht erkennen."));
  AddDetail(({"gasse"}),BS("Dies ist eine wirklich fuerchterlich dunkle "+
  "Gasse."));
  AddDetail(({"form"}),BS("Vergiss die _Form_! Solche Steine hast Du ueber"+
  "haupt noch nie gesehen!!!"));
  AddDetail(({"dunkelheit","finsternis"}),BS("Es ist absolut hypermegasuper"+
  "absolut dunkel hier. Ehrlich."));
  AddDetail(({"backstein","backsteine"}),BS("In die Backsteine dieser Haus"+
  "wand wurde eine Inschrift eingeritzt."));
  AddDetail(({"inschrift"}),BS("Du kannst sie lesen..."));
  AddReadDetail("inschrift","ShockllsL! ZurlisM LoemuQ PsiwqrX!\n");
  // schreie Tuer oeffne sofort
  AddDetail(({"tuerme"}),BS("Du weisst, dass diese Tuerme hier sind. Du "+
  "hast sie von draussen genau gesehen (naja, eher schemenhaft, aber ok). "+
  "Hier drinnen kannst Du sie aber nicht erkennen, weil es so fuerchterlich "+
  "dunkel ist."));
  AddDetail(({"turm"}),BS("Er muesste sich hoch und stolz ueber Dir "+
  "erheben, Du kannst ihn jedoch nicht erkennen. Lediglich eine Tuer, wel"+
  "che anscheinend in die Burgmauer hineinfuehrt."));
  AddDetail(({"hauswand"}),BS("Die Hauswand besteht aus Backsteinen. Jemand "+
  "hat eine Inschrift hineingeritzt."));
  AddDetail(({"jemand"}),BS("Jemand sagt: Iiich? Ein Vandale? Nie!!!"));
  AddDetail(({"vandale"}),BS("Ein Vandale rennt weg, so schnell er kann..."));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  AddCmd(({"treib","treibe"}),"sport");
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl2bu7"));
  NewDoor("norden",CHAOS_GILDEN_ROOM("cl2tu3_1"),({"tuer"}),
  ({D_NAME,"Tuer",
    D_GENDER,2,
    D_SHORT,"Eine %se Tuer fuehrt in den mysterioesen Turm.",
    D_LONG,BS("Von dieser Tuer kannst Du nicht viel mehr erkennen, als das "+
    "sie existiert und schwarz ist."),
    D_FLAGS, DOOR_CLOSED | DOOR_RESET_CL
  }));
  
  AddCmd(({"schrei","schreie"}),"scream");
  
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


int sport(string was) {
  if (was != "sport") return 0;
  write("Kennst Du den Ausdruck 'Sport ist Mord'?\n");
  fakekill("Sport","Sport ist Mord...");
  return 1;
}

int scream(string was) {
  if (was != "zurlism loemuq psiwqrx") return write("Nope.\n"),0;
  write("Du rufst: ZURLiSM LOEmUq PSIwQRX!\n");
  say(this_player()->Name(WER)+" bruellt etwas fremdartiges.\n",this_player());
  this_player()->move(CHAOS_GILDEN_ROOM("cl2bu11"),M_GO,"durch die Wand");
  return 1;
}
