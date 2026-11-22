// Sting/Hutschat-Raum (Chaosgilde)
// -----------------------------------

#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Der Verwaltungsraum der Chaosgilde." );
  SetProp( P_INT_LONG, BS("Du hast einen total nuechtern und langweilig "+
                          "aussehenden Raum betreten. Das einzige was es "+
                          "hier an Moebeln gibt, ist ein Schreibtisch, "+
                          "zwei Stuehle und ein hohes Regal. Was jedoch "+
                          "sofort extrem auffaellt, ist die Farbe von "+
                          "Wand, Decke und Boden, die sind naemlich weiss. "+
                          "Hinter dem Schreibtisch sitzt normalerweise "+
                          "Hutschat, der Verwalter der Gilde.",78));

  SetProp( P_LIGHT, 1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "decke", "wand", "boden", "waende" }), BS(
        "Die Decke, die Waende und der Boden sind weiss. Nanu... "+
        "WEISS ?? Ja, das ist tatsaechlich weiss. Hmm... Passt "+
        "irgendwie ueberhaupt nicht zur ansonsten recht duesteren "+
        "Atmosphaere der Gilde... Wirklich komisch, vielleicht "+
        "kann dir ja Hutschat was drueber sagen. An der einen Wand siehst "+
        "Du ausserdem auch noch einen Wandkalender.",78));
  AddDetail( ({ "weiss" }), BS(
        "Das ist tatsaechlich reinstes Weiss.",78));
  AddDetail( ({ "atmosphaere" }), BS(
        "Normalerweise ist die duester und boese, doch hier ist sie eher "+
        "ernuechternd und langweilig. Irgendwie passt sie also optimal zu "+
        "einem Verwaltungsraum.",78));
  AddDetail( ({ "verwaltungsraum" }), BS(
        "Du stehst mitten drin.",78));
  AddDetail( ({ "moebel" }), BS(
        "Muss ich alles zweimal beschreiben? NEIN! Lies halt genauer!",78));
  AddDetail( ({ "farbe" }), BS(
        "Ist tatsaechlich Weiss.",78));

  AddDetail( ({ "wandkalender", "kalender" }), BS( ctime(time()),78));
        // Hier bitte immer das aktuelle Datum anzeigen lassen //

  AddDetail( ({ "schreibtisch" }), BS(
        "Der Schreibtisch besteht offensichtlich aus edlem Mahagoni-Holz. "+
        "Auf ihm erkennst du ein kleines Bild mit Rahmen, ein paar Stifte, "+
        "einen weissen Block und ein paar Formulare. Ausserdem siehst Du "+
        "noch zwei geschlossene Schubladen, und eine schwarze Pflanze.",78));
  AddDetail( ({ "holz" }), BS(
          "Welches Holz meinst Du?",78));
  AddDetail( ({ "mahagoniholz", "mahagoni-holz" }), BS(
        "Aus diesem besteht der Schreibtisch und der Stuhl von Hutschat. "+
        "Sieht sehr edel aus.",78));
  AddDetail( ({ "rahmen" }), BS(
        "Der Rahmen des Bildes ist vergoldet.",78));
  AddDetail( ({ "gold", "blattgold" }), BS(
          "Das ist nur Blattgold.",78));
  AddDetail( ({ "bild" }), BS(
        "Auf dem Bild erkennst du eine freundlich blickende, alte Frau, "+
        "die Dir freundlich zuzuwinken scheint. Am unteren Rand stehen ein "+
        "paar Worte geschrieben, vielleicht kannst Du sie ja lesen.",78));
  AddDetail( ({ "worte" }), BS(
          "Versuchs mal mit lesen!",78));
  AddDetail( ({ "frau" }), BS(
          "Alt, aber freundlich blickend, scheint sie dir zuzuwinken.",78));
  AddDetail( ({ "rand" }), BS(
          "Da stehen ein paar Worte geschrieben.",78));
  AddDetail( ({ "stifte" }), BS(
          "Nicht gerade das edelste vom edelsten, aber vermutlich "+
          "zweckerfuellend. Auf den Stiften erkennst du winzig kleine "+
          "Daemonen.",78));
  AddDetail( ({ "daemonen" }), BS(
        "Die sind wohl auf die Stifte aufgedruckt. Oder sie sind IN die "+
        "Stifte hineinverbannt worden, wer weiss...",78));
  AddDetail( ({ "schreibblock", "block" }), BS(
          "Der Schreibblock ist leer, eine Menge Blaetter sind das "+
          "einzige was er zu bieten hat.",78));
  AddDetail( ({ "blaetter", "menge", "stueck" }), BS(
        "Sind schon nen paar Stueck, aber viel zu bieten haben sie "+
        "nicht :)",78 ));
  AddDetail( ({ "formulare" }), BS(
        "Die Formulare sind in einer Dir unbekannten Sprache geschrieben. "+
        "Koennte Beamtisch sein.",78));
  AddDetail( ({ "sprache", "beamtisch" }), BS(
        "Das blickst du auf keinem Auge.",78));
  AddDetail( ({ "auge" }), BS(
          "Nein, auch nicht auf zweien.",78));
  AddDetail( ({ "schubladen", "schublade" }), BS(
          "Die sind geschlossen, und ohne die Erlaubnis von Hutschat "+
          "wirst Du die wohl auch nicht aufkriegen.",78));
  AddDetail( ({ "erlaubnis" }), BS(
        "Kannst ihn ja mal danach fragen.",78));
  AddDetail( ({ "mahagoni" }), BS(
        "Ist sehr edel.",78));
  AddDetail( ({ "sperrholz" }), BS(
        "Das billigste vom billigsten.",78));
  AddDetail( ({ "stuhl", "stuehle" }), BS(
        "Du siehst zwei Stuehle in diesem Raum, der eine ist hinter dem "+
        "Schreibtisch, er besteht aus edlem Mahagoni. Der andere scheint "+
        "schon einiges mitgemacht zu haben, er wackelt schon, und ist "+
        "wohl auch aus billigem Sperrholz gemacht.",78));
  AddDetail( ({ "sperrholz" }), BS(
        "Das billigste vom billigen. Die guten Sachen hat, wie immer in "+
        "so einem Verwaltungsraum, nur der Verwalter.",78));
  AddDetail( ({ "sachen" }), BS(
        "Damit ist der Schreibtisch und der Stuhl von Hutschat "+
        "gemeint.",78));
  AddDetail( ({ "pflanze" }), BS(
        "Also entweder ist diese Pflanze daemonischen Ursprungs, oder "+
        "Hutschat ist zu faul sie zu giessen.",78));
  AddDetail( ({ "ursprung" }), BS(
        "Daran glaubst Du eigentlich weniger.",78));
  AddDetail( ({ "regal" }), BS(
        "Das hohe Regal ist aus einem unbekannten Holz gemacht, sehr "+
        "hoch, und es steht eine grosse Zahl langweilig aussehender Ordner "+
        "darin.",78));
  AddDetail( ({ "zahl" }), BS(
        "Du kannst ja mal zaehlen.",78));
  AddDetail( ({ "wunder" }), BS(
        "Wunder gibt es immer wieder...",78));
  AddDetail( ({ "erzmeisterliste" }), BS(
        "Lies mal den Ordner 4.",78));
  AddDetail( ({ "gildenmitglieder", "mitglieder" }), BS(
        "Im Ordner 2 steht was dazu.",78));
  AddDetail( ({ "verwalter" }), BS(
        "Schau doch einfach Hutschat an.",78));
  AddDetail( ({ "ordner" }), BS(
        "Du kannst dir die Ordner einzeln betrachten, wobei nur die " +
        "ersten fuenf interessant aussehen. Natuerlich kannst Du sie "+
        "auch lesen.",78));

  AddDetail( ({ "ordner 1" }), BS(
        "Auf dem ersten Ordner, es ist ein sehr duenner, steht "+
        "'Die Titel der Gildenmitglieder'.",78));

  AddDetail( ({ "ordner 2" }), BS(
        "Der zweite Ordner ist schon wesentlich dicker als der erste, "+
        "auf ihm steht in verschnoerkelten Buchstaben geschrieben: "+
        "'Die Liste aller Chaoskrieger'.",78));
  AddDetail( ({ "buchstaben", "verschnoerkelungen" }), BS(
        "Die Verschnoerkelungen sehen aus wie winzige Pentagramme",78));
  AddDetail( ({ "pentagramme" }), BS(
        "Naja, sind aber trotzdem nur Verschnoerkelungen.",78));

  AddDetail( ({ "ordner 3" }), BS(
        "'Der Chaosrat' ist der Titel von diesem Ordner.",78));
  AddDetail( ({ "gruppe" }), BS(
        "Lies genauer, es steht dran um wen es geht!",78));
 
 AddDetail( ({ "ordner 4" }), BS(
        "Die Beschriftung dieses Ordners lautet 'Die Erzmeisterliste'",78));

 AddDetail( ({ "ordner 5" }), BS(
        "In grossen schoenen Lettern steht hier geschrieben: "+
        "'Das groesste Ereigniss im Leben - Die Eintritte in die "+
        "Chaosgilde.",78));
  AddDetail( ({ "letter", "lettern" }), BS(
        "Schoen und gross sehen sie aus, sie zeugen von dem Ruhm der "+
        "Gilde.",78));
  AddDetail( ({ "ruhm" }), BS(
        "Wahrlich, gross ist er!",78));
  AddDetail( ({ "eintritte" }), BS(
        "Lies dazu den Ordner 5.",78));

  AddDetail( ({ "ordner 6" }), BS(
        "Wow, dieser Ordner strahlt eine toedliche Aura aus. "+
        "Offenbar mit Blut wurde daraufgeschrieben: "+
        "'Der Augenblick des Todes - Die Verdammten und Ausgetretenen "+
        "der Chaosgilde.",78));
  AddDetail( ({ "aura" }), BS(
        "Toedlich.",78));
  AddDetail( ({ "chaosgilde", "gilde" }), BS(
        "Du stehst mitten drin.",78));
  AddDetail( ({ "blut" }), BS(
        "Sieht blutig aus.",78));



  AddReadDetail( ({ "worte" }), BS(
        "Da steht: Fuer meinen Hutschie, in Liebe, deine Mutter. "+
        "Du denkst . o O (Oh Mann, und das ist der Verwalter der "+
        "Chaosgilde, was fuer ein Waschlappen.)",78));
  AddReadDetail( ({ "ordner 1" }),
        " 1. Kleiner Chaot                 #  kleine Chaotin\n"
        " 2. Chaot                         #  Chaotin\n"
        " 3. Wahnwitziger                  #  Wahnwitzige\n"
        " 4. Kaempfer des Chaos            #  Kaempferin es Chaos\n"
        " 5. finsterer Chaos-Kaempfer      #  finstere Chaos-Kaempferin\n"
        " 6. Krieger des Chaos             #  Amazone des Chaos\n"
        " 7. finsterer Chaos-Krieger       #  finstere Chaos-Amazone\n"
        " 8. Daemonen-Beschwoerer          #  Daemonen-Beschwoererin\n"
        " 9. Dunkelmagier des Chaos        #  Dunkelmagierin des Chaos\n"
        "10. Schwarzmagier des Chaos       #  Schwarzmagierin des Chaos\n"
        "11. Verbreiter des CHAOS          #  Verbreiterin des CHAOS");

  AddReadDetail( ({ "ordner 3" }), BS(
        "Du staunst schwer, als Du die ersten paar Seiten liest. "+
        "Dieser Ordner behandelt offensichtlich eine kleine Gruppe "+
        "von Leuten, die sich selbst den 'Chaosrat' nennen. So wie "+
        "es sich liest, haben diese Leute innerhalb der Chaosgilde "+
        "eine nicht zu unterschaetzende Macht inne, auch wenn sich "+
        "ihr Tun meistens auf Meckern und Noergeln beschraenkt :) "+
        "Ihre Namen stehen auch noch darin: Key, Sting, Tweeg, Tyrion. "+
        "Bei solch klangvollen Namen ist es kein Wunder, dass der "+
        "'Chaosrat' eine solche Macht besitzt.",78));

  AddSounds( SENSE_DEFAULT,
                BS("Totale Stille... Hmm, oder doch nicht ? "+
                   "Ab und zu meinst Du das Heulen und Schreien "+
                   "von irgendwelchen Wesen aus der Ferne zu "+
                   "vernehmen.",78));
  AddSounds( ({ "heulen", "schreien", "wesen" }), "Hmm, Du kannst es nicht "+
                                         "richtig einordnen.");
  AddSounds( ({ "ferne" }), "Ist wohl schon ein ganzes Stueck weit weg.");
 
  AddReadDetail("ordner 2","@@ordner2@@");
  AddReadDetail("ordner 4","@@ordner4@@");
  AddReadDetail("ordner 5","@@ordner5@@");
  AddReadDetail("ordner 6","@@ordner6@@");


  AddSmells( SENSE_DEFAULT, BS(
                "So einen geruchsneutralen Raum findet man selten. "+
                "Hier riecht man wirklich gar nichts.",78));



  AddCmd( ({ "zaehle", "zaehl" }), "zaehlen" );

  
}

zaehlen( str )
{
  notify_fail( "Was willst du denn zaehlen?\n" );
  if(!str) return 0;
  
  if(member(({"ordner"}),str)!=-1)
  {
      write(BS("Du zaehlst die Ordner, und kommst auf die Zahl 35.",78) );
      return 1; 
   }
   return 0; 
}


string ordner2()
{
  this_player()->More(call_other(CHAOS_GILDEN_OBJ("g_master"),"Liste"),0);
  return "";
}

string ordner4()
{
  write("Du liest die Liste der letzten Erzmeister\n"+
  "------------------------------------------------------------------------\n");
  tail(CHAOS_GILDEN_LOG("erzmeister"));
  return "";
}

string ordner5()
{
  write("Du liest die Liste der letzten Eintritte:\n"+
  "------------------------------------------------------------------------\n");
  tail(CHAOS_GILDEN_LOG("gilde-eintritt.log"));
  return "";
}

string ordner6()
{
  write("Du liest die Liste der letzten Austritte:\n"+
  "------------------------------------------------------------------------\n");
  tail(CHAOS_GILDEN_LOG("gilde-austritt.log"));
  return "";
}
 