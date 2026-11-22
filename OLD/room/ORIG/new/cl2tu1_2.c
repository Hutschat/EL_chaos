#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Im Treppenaufgang eines zerstoerten Turms." );
  SetProp( P_INT_LONG, BS("Du stehst in einem dunklen, kleinen  und "+
                          "irgendwie unheimlich wirkenden Raum, "+
                          "indem es ausser Decke, Boden und Wand "+
                          "eigentlich nur drei Dinge gibt: Eine Luke an "+
                          "der Decke, massenweise herumliegende Truemmer, "+
                          "und eine schmale Wendeltreppe, die weiter nach "+
                          "unten fuehrt.",78));

  SetProp( P_LIGHT, -1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "dinge" }), BS(
          "Kannst Du nicht lesen? Die Luke, die Truemmer und die "+
          "Wendeltreppe!",78));
  AddDetail( ({ "boden" }), BS(
          "Auf dem Boden liegen ueberall massenweise Truemmerstuecke "+
          "herum. Dieser Turm ist wirklich sehr in Mitleidenschaft "+
          "gezogen. Vermutlich kommen die meisten Truemmerstuecke aus dem "+
          "oberen Raum durch die Luke an der Decke, jedoch sind hier auch "+
          "Teile der Waende herausgebrochen. Welche Macht kann so eine "+
          "destruktive Wirkung haben???",78));
  AddDetail( ({ "wirkung" }), BS(
          "Ziemlich zerstoererische Wirkung, vielleicht solltest Du "+
          "besser gehen, solange Du noch kannst",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke, wie auch die Waende und der Boden besteht aus "+
          "grossen, schwarzen Steinbloecken. Ausserdem siehst Du noch "+
          "eine schmale Luke, die Du vielleicht oeffnen koenntest.",78));
  AddSpecialDetail( ({ "luke" }), "det_luke");
  AddDetail( ({ "holz" }), BS(
          "Dunkles, grobes Holz.",78));
  AddDetail( ({ "muehe" }), BS(
          "Die musst Du dir schon machen.",78));
  AddDetail( ({ "stein", "steinbloecke" }), BS(
          "Die Steinbloecke, aus denen die Waende, der Boden und die "+
          "Decke bestehen sind gross, schwarz und ziemlich grob. "+
          "Ausserdem fehlen stellenweise Teile davon, sind wohl durch "+
          "irgendeine Zerstoerung herausgebrochen...",78));
  AddDetail( ({ "stellen" }), BS(
          "Es sind tatsaechlich einige Stellen, an denen Teile der Wand "+
          "herausgebrochen sind.",78));
  AddDetail( ({ "teile" }), BS(
          "Die herausgebrochenen Teile sind wohl die Truemerstuecke auf "+
          "dem Boden.",78));
  AddDetail( ({ "truemmer", "truemmerstuecke" }), BS(
          "Die Truemmerstuecke liegen ueberall verstreut auf dem Boden "+
          "rum. Sie wirken hoechst merkwuerdig, irgendwie so, als ob sie "+
          "von einer gewaltigen Kraft herausgerisssen worden waeren.",78));
  AddDetail( ({ "kraft", "macht", "zerstoerung" }), BS(
          "Anhand der total verrueckten und chaotischen Verhaeltnisse "+
          "hier, kann man eigentlich schon ahnen, welche boese Macht "+
          "fuer diese Zerstoerung hier verantwortlich ist... Das CHAOS!",78));
  AddDetail( ({ "verhaeltnisse" }), BS(
          "Die sind wirklich chaotisch. An einem solchen Ort kann sich "+
          "vermutlich nur einer der fiesen und maechtigen Krieger des "+
          "Chaos wohlfuehlen.",78));
  AddDetail( ({ "ort" }), BS(
          "Damit koennte man auch alle boesen Orte dieses Landes "+
          "meinen :)",78));
  AddDetail( ({ "krieger", "chaos", "heimat" }), BS(
          "Dieser Ort gehoert zur Heimat der Krieger des Chaos.",78));
  AddDetail( ({ "wendeltreppe", "treppe" }), BS(
          "Die Wendeltreppe ist schmal, und es ist hier trotz deiner "+
          "Lichtquelle irgendwie dunkel, so dass man SEHR vorsichtig "
          "sein sollte, wenn man weiter runtergehen will!",78));
  AddDetail( ({ "lichtquelle" }), BS(
          "Also die solltest Du schon selbst wissen.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Die Wand besteht, wie auch der Boden und die Decke aus "+
          "grossen, schwarzen Steinbloecken, die grob gearbeitet sind, "+
          "jedoch mit dem Unterschied, dass hier an vielen Stellen "+
          "Teile davon scheinbar 'herausgebrochen' sind... Der Grund "+
          "dafuer ist nicht ersichtlich.",78));
  AddDetail( ({ "unterschied" }), BS(
          "Der Unterschied von Wand zu Decke und Boden.",78));
  AddDetail( ({ "grund" }), BS(
          "Ob du den wohl je herausfinden wirst?",78));
  AddDetail( ({ "schutzdaemon" }), BS(
          "Scheint schon wieder weg zu sein, wenn ueberhaupt einer "+
          "da war...",78));
  AddDetail( ({ "turm", "raum" }), BS(
          "Da befindest Du dich gerade.",78));
  AddDetail( ({ "mitleidenschaft" }), BS(
          "Ziemlich mitgenommen!",78));

  AddSounds( SENSE_DEFAULT,
                BS("Hier herrscht eine unheimliche Stille. Nur ab "+
                   "und zu glaubst Du ueber dir ein Scharren oder "+
                   "Kratzen zu hoeren...",78));
  AddSounds( ({ "scharren", "kratzen" }), "Du kannst es nicht "+
                                          "genauer einordnen.");
        


  AddSmells( SENSE_DEFAULT, BS(
                "Absolut geruchslos, dieser Raum...",78));


  AddSpecialExit(({"unten"}),"uffgepasst");
  AddCmd(({"oeffne"}),"open");
  AddCmd(({"schlies","schliesse"}),"close");
  AddCmd(({"oben"}),"noeeh");
  AddCmd(({"zwaenge","zwaeng"}),"zwaenge");
  
  

}


int uffgepasst(string was) {
  if (this_player()->QueryProp(P_WIMPY)< 120)
  {
     write(BS("Du warst nicht vorsichtig genug und rutschst ab, jedoch "+
     "hast du wohl irgendeinen unsichtbaren Schutzdaemon, der dich packt "+
     "und wieder in deinen Ausgangsraum traegt.",78));
     say(this_player()->Name(WER)+" rutscht fuerchterlich auf der "+
     "Treppe aus.\n",this_player());
     this_player()->reduce_hit_point(20);
     return 1;
  }
  write("Du gehst gaaaaaaaanz vorsichtig nach unten.\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2tu1_3"),M_GO,
                      "ganz vorsichtig abwaerts");
  return 1;
}


string det_luke()
{
  if (!call_other(CHAOS_GILDEN_ROOM("cl2tu1_1"),"getluke"))
   return BS(
          "Die Luke ist nicht sehr gross, aber mit etwas Muehe koenntest "+
          "Du dich wohl durchzwaengen, jedoch solltest Du sie natuerlich "+
          "zuerst oeffnen. Sie besteht aus dunklem Holz.",78);
  else
    return BS(
          "Die Luke ist nicht sehr gross, aber mit etwas Muehe koenntest "+
          "Du dich wohl durchzwaengen, und tollerweise ist sie sogar schon "+
          "geoeffnet. Sie besteht aus dunklem Holz.",78);
}



int open(string was) {
  notify_fail("Was moechtest Du denn oeffnen?\n");
  if (was != "luke") return 0;
  if (call_other(CHAOS_GILDEN_ROOM("cl2tu1_1"),"openluke"))
  {
     write("Du oeffnest die Luke.\n");
     say(this_player()->Name(WER)+" oeffnet die Luke.\n",this_player());
     return 1;
   }
   write("Leider ist die verdammte Luke schon offen.\n");
   return 1;
}

int close(string was) {
  notify_fail("Was moechtest Du denn schliessen?\n");
  if (was != "luke") return 0;
  if (call_other(CHAOS_GILDEN_ROOM("cl2tu1_1"),"closeluke"))
  {
     write("Du schliesst die Luke.\n");
     say(this_player()->Name(WER)+" schliesst die Luke.\n",this_player());
     return 1;
   }
   write("Leider ist die verdammte Luke schon zu.\n");
   return 1;
}

int noeeh()
{
  if (!call_other(CHAOS_GILDEN_ROOM("cl2tu1_1"),"getluke"))
    write("PFFFFF, die Luke ist zu.\n");
  else
    write("Das ist viel zu eng.\n"+
        "Obwohl, vielleicht koenntest Du Dich durch die Luke zwaengen...\n");
  return 1;
}

int zwaenge(string was) {
  notify_fail("Wodurch moechtest Du Dich zwaengen?\n");
  if (was != "durch luke") return 0;
  if (!call_other(CHAOS_GILDEN_ROOM("cl2tu1_1"),"getluke"))
  {
     write ("Leider ist die Luke geschlossen.\n");
     return 1;
  }
  write("Du zwaengst Dich durch die Luke.\nMann ist das eng.\n");
  this_player()->move(CHAOS_GILDEN_ROOM("cl2tu1_1"),M_GO,"durch die Luke",
                      "zwaengt sich","klettert herauf");
  return 1;
}