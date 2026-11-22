#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Im Treppenaufgang eines zerstoerten Turms." );
  SetProp( P_INT_LONG, BS("Dieser Raum hier scheint noch dunkler, "+
                          "kleiner und unheimlicher als der Raum "+
                          "darueber zu sein. Hier erkennst Du mit "+
                          "aeusserster Anstrengung ausser den "+
                          "normalen Gegebenheiten eines Raums nur "+
                          "noch die weiter nach unten fuehrende "+
                          "Wendeltreppe und ausserdem noch viel "+
                          "mehr Truemmerstuecke als zuvor.",78));

  SetProp( P_LIGHT, -3);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "gegebenheiten" }), BS(
          "Naja, die Wand, die Decke und den Boden eben.",78));
  AddDetail( ({ "boden" }), BS(
          "Hier liegen noch viel mehr Truemmerstuecke herum, als im "+
          "darueberliegenden Raum... Scheinbar naeherst Du dich der "+
          "Quelle der Zerstoerungskraft.",78));
  AddDetail( ({ "quelle" }), BS(
          "Die liegt vermutlich weiter unten...",78));
  AddDetail( ({ "zerstoerungskraft" }), BS(
          "Auch wenn ich mich wiederhole... Es ist eine SEHR starke, "+
          "chaotische Zerstoerungskraft, und Du solltest NOCH "+
          "vorsichtiger als zuvor schon sein!",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke, wie auch die Waende und der Boden besteht aus "+
          "grossen, schwarzen Steinbloecken. In der Decke ist ein "+
          "kleines Loch, durch das die schmale Wendeltreppe in die "+
          "Dunkelheit fuehrt.",78));
  AddDetail( ({ "loch" }), BS(
          "Naja, ein dunkles, kleines Loch eben.",78));
  AddDetail( ({ "stein", "steinbloecke" }), BS(
          "Die Steinbloecke, aus denen die Waende, der Boden und die "+
          "Decke bestehen sind gross, schwarz und ziemlich grob. "+
          "Ausserdem fehlen an vielen Stellen Teile davon, sind wohl "+
          "durch irgendeine Zerstoerung herausgebrochen...",78));
  AddDetail( ({ "stellen" }), BS(
          "Es sind wirklich viele Stellen, an denen Teile der Wand "+
          "herausgebrochen sind.",78));
  AddDetail( ({ "teile" }), BS(
          "Die herausgebrochenen Teile sind die Truemerstuecke auf "+
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
  AddDetail( ({ "krieger", "chaos" }), BS(
          "Dieser Ort gehoert zur Heimat der Krieger des Chaos.",78));
  AddDetail( ({ "wendeltreppe", "treppe" }), BS(
          "Die Wendeltreppe ist schmal, und es ist hier trotz deiner "+
          "Lichtquelle noch dunkler, so dass man NOCH vorsichtiger "
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
  AddDetail( ({ "dunkelheit" }), BS(
          "Dunkelheit sieht man doch nicht!",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "anstrengung" }), BS(
          "Sehr anstrengend!",78));

  AddSounds( SENSE_DEFAULT,
                BS("Hier herrscht eine totale, unheimliche Stille.",78));
        


  AddSmells( SENSE_DEFAULT, BS(
                "Absolut geruchslos, dieser Raum...",78));


  AddExit("oben",CHAOS_GILDEN_ROOM("cl2tu1_2"));
  AddSpecialExit("unten","uffgepasst");
}

int uffgepasst(string was) {
  if (this_player()->QueryProp(P_WIMPY)< 140)
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
  this_player()->move(CHAOS_GILDEN_ROOM("cl2tu1_4"),M_GO,
                      "ganz vorsichtig abwaerts");
  return 1;
}