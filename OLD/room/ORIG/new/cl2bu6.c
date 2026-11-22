#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2bu_std");

#define BS(x) break_string(x,78)

int door;

create() {

  door = 0; //open
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu7"));
  SetProp(P_LIGHT,0);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In der chaotischen Burg");
  SetProp(P_INT_LONG,BS("Du befindest Dich in tiefer Dunkelheit. "+
  "Im Westen eroeffnet sich der grosse Platz, den Du von hier aus "+
  "natuerlich nicht sehen kannst. Im Osten befindet sich eines der "+
  "schwarzen Haeuser, wie sie hier in dieser Burg typisch zu sein "+
  "scheinen. Im Norden und Sueden glaubst Du, weitere derartige "+
  "Haeuser ausmachen zu koennen. Das Haus oestlich von Dir bestitzt "+
  "eine Tuer wie die meisten anderen hier auch, doch ueber der Tuer "+
  "prangt nicht ein mystisches, leuchtendes Symbol, sondern ein "+
  "schreiender, vor Schmerzen geradezu quiekender Daemon."));
  AddDetail(({"boden"}),BS("Der Boden ist bedeckt von schwarzen "+
  "Pflastersteinen. Nicht dass Dich das sonderlich interessieren wuerde, "+
  "aber so ist es."));
  AddDetail(({"pflastersteine","schwarze pflastersteine"}),BS("Wow. "+
  "So schwarze Pfalstersteine hast Du ja noch nie gesehen!"));
  AddDetail(({"decke"}),BS("Es ist hier zu dunkel, um die Decke "+
  "noch erkennen zu koennen."));
  AddDetail(({"wand","waende"}),BS("Dies hier ist ein Innenhof. Du befindest "+
  "Dich demnach im Freien. Waende gibt es hier kaum welche, ausser vielleicht "+
  "der Hauswand im Osten. Aber die haettest Du sicherlich mit 'hauswand' oder "+
  "'mauer' untersucht."));
  AddDetail(({"hoelle"}),BS("Hehe, jaaa, fluch ruhig. Wo, wenn nicht hier?"));
  AddDetail(({"hauswand","mauer"}),BS("Diese Hauswand ist von dunkelroter "+
  "Farbe und besteht aus den hier ueblichen Backsteinen. Du stutzt. Dunkel"+
  "rote Farbe???? Voellig verwirrt bist Du nicht einmal faehig, "+
  "Verwunderung ueber den halbtoten Daemon ueber der Tuer zu empfinden. "+
  "Dunkelrote Farbe... HOELLE!"));
  AddDetail(({"farbe","dunkelrote farbe"}),BS("Oh Hoelle. Die ganze Hauswand "+
  "ist dunkelrot gefaerbt, und zwar DICK. Ueber und ueber in dieser ... Farbe? "+
  "Du bist Dir klar darueber, dass dies Blut ist. Das irgend jemand dieses "+
  "ganze Haus mit ganzen Faessern von Blut ueber und ueber getuencht (uebergo"+
  "ssen???) hat. Dir wird ganz schlecht."));
  AddDetail(({"jemand"}),BS("Jemand versteckt ein Fass Blut ungeschickt "+
  "hinter seinem Ruecken und pfeift unschuldig."));
  AddDetail(({"ruecken"}),BS("Jemand dreht sich mit Dir, so dass er immer "+
  "zwischen Dir und dem Fass steht."));
  AddDetail(({"fass","faesser"}),BS("Oh Hoelle, das muessen ja Faesser voll "+
  "Blut gewesen sein! Wie ... Warum ... Was ... WUQOUR! OH HOELLE!"));
  AddDetail(({"wuqour"}),BS("Du bist Dir absolut sicher, in diesem "+
  "Haus wohnt Wuqour, der Meister der Rituale."));
  AddDetail(({"rituale","meister"}),BS("Wuqour ist der Meister der Rituale."));
  AddDetail(({"steine","backsteine"}),BS("Die Steine in dieser Hauswand "+
  "sind von dunkelroter Farbe. Du bist Dir sicher, dass sie einst schwarz "+
  "waren, doch nun wurden so von ... etwas ... gefaerbt."));
  AddDetail(({"etwas"}),BS("Das Etwas befindet sich garantiert nicht hier."));
  AddDetail(({"freies"}),BS("Fuehl Dich frei. Macht mir nix aus."));
  AddDetail(({"verwunderung"}),BS("Du bist voellig baff."));
  AddDetail(({"blut"}),BS("*Aechz* So viel BLUT! Oh Hoelle! Was ist hier "+
  "nur passiert????"));
  AddDetail(({"haus"}),BS("Es befindet sich oestlich von Dir."));
  AddDetail(({"dunkelheit","finsternis"}),BS("Die Finsternis, in der Du Dich "+
  "hier befindest, ist geradezu widernatuerlich, jawohl. So isses."));
  AddDetail(({"burg"}),BS("Dies ist die chaotische Burg, die Burg des Chaos, "+
  "und hier befindet sich die beruechtigte Chaosgilde, Heim der Chaoten."));
  AddDetail(({"chaos","chaosgilde","krieger"}),BS("Die Chaosgilde herrscht ueber das "+
  "Chaos. Die Chaoten sind die Krieger des Chaos."));
  AddDetail(({"chaoten"}),BS("Die Chaoten sind die Mitglieder der Chaosgilde."));
  AddDetail(({"mitglieder"}),BS("Jup, das sind die Chaoten."));
  AddDetail(({"hoehle"}),BS("Jajaa, Du befindest Dich in einer gewaltigen "+
  "Hoehle. Davon merkst Du hier aber nichts, denn es ist so verdammt finster "+
  "hier...."));
  AddDetail(({"eisberg"}),BS("Juhuuu, Du weisst es noch. Ja, dies ist eine "+
  "gewaltige Hoehle in einem schwarzen Eisberg."));
  AddDetail(({"platz"}),BS("Es ist zu dunkel um mehr zu erkennen, als das er "+
  "da ist..."));
  AddDetail(({"osten"}),BS("Im Osten befindet sich ein Haus."));
  AddDetail(({"haeuser"}),BS("In dieser verdammten Burg gibt es ziemlich "+
  "viele Haeuser, alles was recht ist..."));
  AddDetail(({"symbol"}),BS("Neiiin, da ist kein dreckiges Symbol, dort haengt "+
  "etwas sehr viel lustigeres! Ein halbtoter Daemon, der vor Schmerzen "+
  "halb wahnsinnig vor sich hinbruellt!"));
  AddDetail(({"schmerzen"}),BS("Oooooh, muss dieser Daemon leiden! Wow!"));
  AddDetail(({"daemon"}),BS("Es ist ein sehr kleiner Daemon, wohl einen "+
  "knappen halben Meter gross, wenn nicht weniger. Er ist noch jung, "+
  "besitzt weder Hoerner noch Fluegel, trotzdem wuerde er ziemlich gefaehr"+
  "lich aussehen, hinge er nicht wie festgeklebt an dieser Hauswand und "+
  "waere sein Koerper nicht derart zerfetzt, dass es einem Wunder gleicht, "+
  "dass er noch lebt."));
 AddDetail(({"fluegel","hoerner"}),BS("Dieser Daemon hat weder Hoerner noch "+
 "Fluegel. Er ist noch jung."));
 AddDetail(({"koerper"}),BS("Dieser Koerper wurde mit geradezu chirurgi"+
 "scher Praezision zerstueckelt. Du wird ganz anders... Brrrrr."));
 AddDetail(({"praezision"}),BS("Wer dies gemacht hat, wusste ganz genau, "+
 "was er tat..."));
 AddDetail(({"wunder"}),BS("Hier solltest Du wirklich nicht auf Wunder "+
 "hoffen."));
 
  AddSmells(SENSE_DEFAULT,BS("Du kannst nichts besonderes riechen."));
  AddSounds(SENSE_DEFAULT,BS("Der Daemon kreischt wie eine Furie."));
  
  AddSpecialDetail(({"tuer"}),"det_tuer");
    
  AddExit("westen",CHAOS_GILDEN_ROOM("cl2bu5"));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2bu8"));
  AddExit("norden",CHAOS_GILDEN_ROOM("cl2bu7"));
  AddCmd("osten","osten");
  
  AddRoomMessage(
  ({"Der Daemon bruellt vor Schmerzen.\n",
    "Der Daemon roehrt seine Wut hinaus.\n",
    "Der Daemon bruellt: Nur Chaoten hier rein! Alle anderen draussenbleiben!\n",
    "Der Daemon bruellt: Ich mach es nie wieder Wuqour!\n",
    "Der Daemon bruellt: Verschwindet! Es gibt hier nichts zu sehen!\n",
    "Der Daemon bruellt: Ich lasse nur Chaoten hier rein! Alle anderen weg hier!\n",
    "Der Daemon versucht, seine Innereien mit seinen Klauen zurueckzuschieben.\n",
    "Der Daemon quiekt schmerzerfuellt.\n",
    "Der Daemon stiert in unglaublichem Hass.\n",
    "Der Daemon bruellt: Ich wollte Dich nicht so nennen, Wuqour!\n",
    "Der Daemon bruellt: Du bist kein printenlutschendes Weichei, Wuqour!\n",
    "Der Daemon bruellt: WUUUUQOOOUUUUUUUR! Es tut mir leeeeeeeeiiiiiiiid!\n",
    "Der Daemon bruellt: Wuqour! BITTE! LASS MICH GEEEEEEEEEHHEEEEEEEEN!\n",
    "Der Daemon bruellt: Verschwinde! Geh mir aus den Augen!\n",
    "Der Daemon bruellt: Nur Chaoten kommen hier rein! Geht alle weg!\n",
    "Der Daemon stoehnt vor Schmerzen.\n"
  }),12,0);
  
  AddCmd(({"frag","frage"}),"ask_him");
  AddCmd(({"oeffne"}),"open");
  AddCmd(({"schliess","schliesse"}),"close");
  AddItem(CHAOS_GILDEN_MON("cl2dchaot"),REFRESH_DESTRUCT);
   
}


int ask_him(string was)
{
  string *str;
  
  if (was[0..10] == "daemon nach")
  {
     write("Du fragst den Daemon nach "+capitalize(was[12..])+".\n");
     say(this_player()->Name(WER)+" fragt den Daemon nach "+capitalize(was[12..])+".\n",
         this_player());
     tell_room(this_object(),"Der Daemon bruellt: Verschwinde! Mit Dir red ich nicht!\n");
     return 1;
  }
  return 0;
}  

string det_tuer()
{
    return BS("Die Tuer besteht aus dem gleichen, pechschwarzen und makell"+
    "osen Material, welches Du hier ueberall als Tuer findest. Die Tuer "+
    "ist uebrigens gerade "+(door==0?"geschlossen":"geoeffnet")+".");
}

int open(string was)
{
   notify_fail("Was moechtest Du denn oeffnen?\n");
   if (was != "tuer") return 0;
   
   if (door)
   {
     write("Aber die Tuer ist schon geoeffnet...\n");
     return 1;
   }
   write("Du oeffnest eine Tuer.\n");
   say(this_player()->Name(WER)+" oeffnet eine Tuer.\n",this_player());
   tell_room(CHAOS_GILDEN_ROOM("cl2_critual"),"Von aussen oeffnet jemand die Tuer.\n");
   door = 1;
   return 1;
}

int close(string was)
{
   notify_fail("Was moechtest Du denn schliessen?\n");
   if (was != "tuer") return 0;
   
   if (!door)
   {
     write("Aber die Tuer ist schon gescholossen...\n");
     return 1;
   }
   write("Du schliesst eine Tuer.\n");
   say(this_player()->Name(WER)+" schliesst eine Tuer.\n",this_player());
   tell_room(CHAOS_GILDEN_ROOM("cl2_critual"),"Von aussen schliesst jemand die Tuer.\n");
   door = 0;
   return 1;
}
 
     
int opendoor()
{
   if (door) return 0;
   tell_room(this_object(),"Von Innen oeffnet jemand die Tuer.\n");
   door = 1;
   return 1;
}
     
int closedoor()
{
   if (!door) return 0;
   tell_room(this_object(),"Von Innen schliesst jemand die Tuer.\n");
   door = 0;
   return 1;
}

int querydoor()
{
   return door;
}

string GetExits(object ob) {
  if (!door) return "Es gibt drei sichtbare Ausgaenge: norden, westen und sueden.\n";
  return "Es gibt vier sichtbare Ausgaenge: osten, norden, westen und sueden.\n";
}

int osten()
{
  if (!door)
  {
     write("Du knallst gegen die geschlossene Tuer.\n");
     say(this_player()->Name(WER)+" rennt gegen die geschlossene Tuer.\n",this_player());
     return 1;
  }
  if (this_player()->QueryProp(P_GUILD) != "chaos")
  {
     write("Du willst nach Osten gehen.\n"+
     "Der kleine, unscheinbare Daemon schleudert einen Flammensturm auf Dich.\n");
     say(this_player()->Name(WER)+" will durch die Tuer gehen.\n"+
         "Der Daemon spuckt Feuer auf ihn.\n",this_player());
     this_player()->reduce_hit_point(20+random(20));
     tell_room(this_object(),
        "Der Daemon bruellt: BLEIB DA JA RAUS, SCHATTENPARKER! WARMDUSCHER! WEICHEI!\n"+
        "Der Daemon bruellt: Wenn Wuqour einen von Deiner Sorte in seinen Hallen sieht,\n"+
        "Der Daemno bruellt: wird er tagelang sauer. Und das wird schlimmer fuer mich,\n"+
        "Der Daemon bruellt: als Du Dir vorstellen kannst! Knackarsch!\n");
     return 1;
  }
  this_player()->move(CHAOS_GILDEN_ROOM("cl2_critual"),M_GO,"nach Osten");
  return 1;
}
