#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Ganz unten in einem zerstoerten Turm." );
  SetProp( P_INT_LONG, BS("Du hast es tatsaechlich geschafft, und "+
                          "stehst nun im letzten, untersten Raum "+
                          "dieses dunklen und zerstoerten Turms. "+
                          "Der Anblick der sich dir hier bietet, "+
                          "laesst einem wahrlich das Blut in den "+
                          "Adern gefrieren. ALLES, aber auch wirklich "+
                          "alles ist hier uebersaet mit Truemmern, "+
                          "die sowohl aus Wand, Decke und auch "+
                          "aus dem riesigen leuchtenden Loch im "+
                          "Boden stammen.",78));

  SetProp( P_LIGHT, -4);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Hier ist wirklich alles uebersaet mit Truemmerstuecken "+
          "und es ist so dunkel das man kaum etwas erkennt, "+
          "aber eins faellt einem sofort auf: Das riesige, leuchtende "+
          "Loch auf dem Boden. Dies koennte die Quelle der Kraft sein, "+
          "die diesen Turm so zugerichtet hat...",78));
  AddDetail( ({ "blut", "adern" }), BS(
          "Das gilt natuerlich nicht fuer die Krieger des Chaos, in "+
          "deren Adern schwarzes Blut fliesst.",78));
  AddDetail( ({ "quelle" }), BS(
          "Du vermutest das sie in diesem riesigen, leuchtenden Loch "+
          "am Boden liegt.",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke, wie auch die Waende und der Boden besteht aus "+
          "grossen, schwarzen Steinbloecken, aus der jedoch ueberall "+
          "Teile herausgebrochen sind. In der Decke verschwindet "+
          "die schmale Wendeltreppe in der Dunkelheit.",78));
  AddDetail( ({ "loch" }), BS(
          "Ein riesiges, in allen Farben leuchtendes Loch ist hier "+
          "am Boden. Du koenntest hineinspringen, aber solltest Du das "+
          "wirklich wagen?",78));
 AddDetail( ({ "farben" }), BS(
          "Wirklich alle Farben die man sich denken kann.",78));
 AddDetail( ({ "stein", "steinbloecke" }), BS(
          "Die Steinbloecke, aus denen die Waende, der Boden und die "+
          "Decke bestehen sind gross, schwarz und ziemlich grob. "+
          "Allerdings ist nicht mehr viel davon vorhanden, das meiste "+
          "liegt in Form von Truemmern vor dir auf dem Boden!",78));
  AddDetail( ({ "form" }), BS(
          "Truemmer haben selten eine spezielle Form, schon gar nicht "+
          "wenn sie an einem Ort wie diesem sind.",78));
  AddDetail( ({ "ort" }), BS(
          "Tja, was das hier darstellt kannst Du auch nicht sagen.",78));
  AddDetail( ({ "krieger", "chaos", "heimat" }), BS(
          "Dies hier gehoert zur Heimat der Krieger des Chaos.",78));
  AddDetail( ({ "truemmer", "truemmerstuecke" }), BS(
          "Die Truemmerstuecke bedecken mit Ausnahme des Lochs den "+
          "ganzen Boden. Sie wirken hoechst merkwuerdig, irgendwie so, "+
          "als ob sie von einer gewaltigen Kraft herausgerisssen "+
          "worden waeren.",78));
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
          "Die Wendeltreppe ist schmal, und fuehrt nur noch nach oben "+
          "in die Dunkelheit.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Die Wand besteht, wie auch der Boden und die Decke aus "+
          "grossen, schwarzen Steinbloecken, die grob gearbeitet sind, "+
          "und auch hier sind ueberall grosse Teile davon "+
          "'herausgebrochen'. Der Grund dafuer liegt wohl in dem "+
          "riesigen, leuchtenden Loch am Boden... Ausserdem glaubst "+
          "Du noch die Umrisse einer Tuer zu erkennen.",78));
  AddDetail( ({ "umrisse", "tuer" }), BS(
          "Das wird wohl die Tuer sein, durch die man diesen Turm "+
          "frueher einmal betreten konnte. Doch nun ist sie von Truemmern "+
          "derartig verbarrikadiert, das man hier nicht mehr hereinkommen "+
          "kann.",78));
  AddDetail( ({ "grund" }), BS(
          "Ob du den wohl je herausfinden wirst?",78));
  AddDetail( ({ "dunkelheit" }), BS(
          "Dunkelheit sieht man doch nicht!",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "teile" }), BS(
          "Die herausgebrochenen Teile sind die Truemerstuecke auf "+
          "dem Boden.",78));
  AddDetail( ({ "anblick" }), BS(
          "*frier*",78));

  AddSounds( SENSE_DEFAULT,
                BS("Hier herrscht eine totale, unheimliche Stille.",78));
        


  AddSmells( SENSE_DEFAULT, BS(
                "Absolut geruchslos, dieser Raum...",78));

  AddExit("oben",CHAOS_GILDEN_ROOM("cl2tu1_3"));
  AddCmd(({"spring","springe","huepf","huepfe"}),"jump");
  
  
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


int jump(string was) {
   notify_fail("Wo moechtest Du reinspringen?\n");
   if (was != "loch" && was != "in loch") return 0;
   
   write("Du springst in ein Loch.\n");
   say(this_player()->Name(WER)+" springt in ein Loch.\n");
   fakekill("Ein bodenloses Loch","Hab ich das nicht erwaehnt?");
   return 1;
}


