#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu2"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In einem dunklen Gang");
  SetProp(P_INT_LONG,BS("Du befindest Dich in einem hohen Gang, welcher von "+
  "Norden nach Sueden fuehrt. Schwacher Lichtschein scheint von den wenigen "+
  "Fackeln an den Waenden, welche ungewoehnlich stark zu flackern scheinen "+
  "und hoechst merkwuerdige Schatten produzieren. Zwischen den Fackeln "+
  "haengen einige Bilder an den Waenden.Im Osten siehst Du eine "+
  "merkwuerdige Art von Tuer."));
  AddDetail(({"decke"}),BS("Dieser Gang ist ebenso hoch wie lang :). Nun, "+
  "vielleicht nicht ganz so hoch. Aber immerhin ziemlich hoch. Die Decke "+
  "ist in der Duesternis eigentlich kaum zu erkenne, doch sie woelbt sich "+
  "kuppelartig ueber den Gang. Was dort oben wohl alles auf Dich lauert..."));
  AddDetail(({"duesternis","finsternis","licht","dunkelheit"}),BS("Die viel "+
  "zu wenigen Fackeln verbreiten nur wenig Licht in diesem dunklen, kalten "+
  "Gang. Kaum etwas ist in mehr als Grautoenen zu erkennen."));
  AddDetail(({"toene","grautoene","grau"}),
  BS("Alles hier sieht irgendwie nur Grau in Grau aus. "));
  AddDetail(({"fackeln"}),BS("Die Fackeln haben eine schwarze Farbe und "+
  "flackern unnatuerlich stark, als ob sie von einem starken Wind verweht "+
  "wuerden. Dabei ist es hier jedoch absolut windstill. Dinge gehen hier "+
  "vor, die Dir absolut nicht geheuer sind."));
  AddDetail(({"wind"}),BS("Hier ist wirklich kein Wind. Alles ist absolut "+
  "windstill. Aber wenn es so windstill ist, was laesst dann die Fackeln "+
  "so stark flackern?"));
  AddDetail(({"dinge"}),BS("Die Dinge, welche in dieser Burg geschehen, sind "+
  "absolut merkwuerdig und oft unerklaerlich. Doch Du bist derart Dinge "+
  "gewoehnt, denn schliesslich beherrschst Du das Chaos."));
  AddDetail(({"burg"}),BS("Du befindest Dich unterhalb der chaotischen Burg, "+
  "welche die maechtige und satanisch Chaosgilde beheimatet."));
  AddDetail(({"chaosgilde","chaos"}),BS("Die Chaosgilde ist die satanischste "+
  "Gilde des Morgengrauens. Hier kommen nur Leute rein, die WIRKLICH boese "+
  "sind."));
  AddDetail(({"leute"}),BS("Genau. Nur wirklich satanische Leute kommen in "+
  "die Chaosgilde."));
  AddDetail(({"gilde","morgengrauen","gilden"}),BS("Das Morgengrauen ist "+
  "wirklich schrecklich gross. Deshalb beinhaltet es auch sehr viele Gilden. "+
  "Aber die Chaosgilde ist die absolut satanischste aller Gilden."));
  AddDetail(({"wand","waende"}),BS("Die Waende dieses Ganges bestehen dies"+
  "mal aus gruenen Gummibaerchen. Ha. Ok. Das hast Du bestimmt nicht geglaubt. "+
  "Und Du hattest recht. Denn die Waende dieses Ganges bestehen aus grossen, "+
  "schwarzen Steinen, genauso wie die meisten Waende in dieser Burg. In die "+
  "Waende geschlagen wurden einige Fackelhalter mit darin steckenden Fackeln, "+
  "welche wild flackern fuer ein wenig Licht sorgen. Ausserdem haengen einige "+
  "Bilder an den Waenden, welche saemtlichst an die zwei Meter gross sind. "+
  "In der oestlichen Wand befindet sich eine merkwuerdige Tuer, ueber der "+
  "eine Inschrift auf die Steine gemalt wurde."));
  AddDetail(({"gummibaerchen"}),BS("Natuerlich bestehen die Waende dieses "+
  "Ganges NICHT aus gruenen Gummibaerchen. Wo kaemen wir denn da hin."));
  AddDetail(({"gang"}),BS("Du stehst in einem langen, hohen Gang."));
  AddDetail(({"stein","steine"}),BS("Grosse schwarze Steine bilden die Waende "+
  "dieses Ganges. Sie sind wirklich gewaltig und sehen fast unzerstoerbar "+
  "aus. Das sind sie natuerlich nicht. Irgend jemand hat sogar Fackelhalter "+
  "in diese Steine getrieben."));
  AddDetail(({"jemand"}),BS("Jemand sagt: Einer musste es tun. Und es war "+
  "verflucht schwer. Glaub mir."));
  AddDetail(({"fackelhalter"}),BS("Die Fackelhalter sind eisern, massiv und "+
  "ohne jede Zierde. Sie sind einzig und allein dazu dar, die Fackeln zu "+
  "halten, was sie momentan auch tun."));
  AddDetail(({"bilder","gemaelde"}),BS("Es sind im Grunde nur drei Bilder. "+
  "Man kann sie sich einzeln ansehen."));
  AddDetail(({"bild 1","achtarch","haendler","achtarch der haendler"}),
  BS("Das erste Bild zeigt Achtarch, den Haendler. "+
  "Mit kuehler Professionalitaet blickt Dich dieser knappe zwei Meter "+
  "grosse, hagere Mann an. Die Medaille der Ladenbesitzervereinigung haengt "+
  "locker um seinen Hals und weisst ihn als einen der erfolgreichsten "+
  "Haendler des Morgengrauens aus."));
  AddDetail(({"professionalitaet"}),BS("Achtarch strahlt kuehle Profession"+
  "alitaet aus. Und die besitzt er wirklich. Geruechte besagen, dass Achtarch "+
  "sich noch nie zu einem unbesonnenen Kauf hat hinreissen lassen. Fuer "+
  "seine Professionalitaet spricht ausserdem, dass er Chaoten nichts abkauft."));
  AddDetail(({"chaot","chaoten"}),BS("Chaoten gehoeren zur Chaosgilde."));
  AddDetail(({"mann"}),BS("Hey, das ist Achtarch."));
  AddDetail(({"geruechte","kauf"}),BS("Wie schon erwaehnt besagt dass geruecht, "+
  "dass Achtarch noch nie unueberlegt gekauft hat. Und das ist bemerkenswert "+
  "in einer Gilde, in der Chaoten einem alles, aber auch wirklich alles "+
  "anzudrehen versuchen."));
  AddDetail(({"medaille","ladenbesitzervereinigung",
  "medaille der ladenbesitzervereinigung"}),BS("Sie ist golden. Auf ihr ist "+
  "ein gefuellter Geldbeutel abgebildet."));
  AddDetail(({"geldbeutel"}),BS("So einen haettest Du auch gern..."));
  AddDetail(({"bild 2","achmed"}),BS("Auf dem zweiten Bild siehst Du "+
  "'crazy' Achmed, den Verkaeufer. Waehrend sein Bruder Achtarch auf dem "+
  "Bild volle Professionalitaet ausstrahlt, strahlt Achmed mit jeder Faser "+
  "seines Koerpers seinen Wahnsinn aus. Kleiner als Achtarch steht er fast "+
  "sprungbereit da und schaut Dich mit einem irren Grinsen an."));
  AddDetail(({"verkaeufer"}),BS("Achmed ist der Verkaeufer. Achtarch ist "+
  "der Haendler."));
  AddDetail(({"bruder"}),BS("Achtarch ist der Bruder von Achmed, auch wenn "+
  "er das niemals zugeben wuerde."));
  AddDetail(({"faser","koerper"}),BS("Ein Koerper besitzt schrecklich viele "+
  "Fasern. Wenn Achmed mit jeder Faser seines Koerpers Wahnsinn ausstrahlt, "+
  "dann soll das schon was heissen."));
  AddDetail(({"wahnsinn"}),BS("Achmed muss absolut wahnsinnig sein. Sonst "+
  "wuerde er nicht so aussehen. Und nicht so grinsen."));
  AddDetail(({"grinsen"}),BS("Das Grinsen von Achmed ist schrecklich "+
  "ansteckend. Achmed ist wahnsinnig, jedoch auf eine recht lustige Art "+
  "und Weise. Somit ist er bei den Chaoten recht unbeliebt, denn Chaoten "+
  "grinsen nie. Jedenfalls nicht, bevor sie jemanden umgebracht haben."));
  AddDetail(({"art","weise"}),BS("Ok Ok, ist untersucht."));
  AddDetail(({"bild 3","igor"}),BS("Das dritte Bild zeigt Igor. Es ist "+
  "etwas kleiner als die anderen Bilder, denn Igor ist sehr klein. "+
  "Ausserdem ist er ausgesprochen abstossend haesslich. Er hat einen gewa"+
  "ltigen Buckel und ein Gesicht, welches stark einer Rosine aehnelt, so "+
  "verschrumpelt und haesslich ist es. Mit einem boshaften Gesichtsausdruck "+
  "starrt Dich Igor an. Dir wird bei diesem Blick ganz anders."));
  AddDetail(({"buckel"}),BS("Igors Buckel ist gewaltig und zwingt ihn dazu, "+
  "sich nurnoch gebueckt fortzubewegen. Igor ist wirklich zu bemitleiden. "+
  "Was natuerlich kein wahrer Chaot tun wuerde (der an seinem Leben haengt)."));
  AddDetail(({"leben"}),BS("Auch Chaoten haengen an ihrem Leben, wenn auch "+
  "nicht so stark wie andere Gilden."));
  AddDetail(({"gesicht","rosine"}),BS("Das Gesicht von Igor ist entstellt "+
  "und unglaublich haesslich. Es aehnelt entfernt einer Rosine, so sehr "+
  "ist es von Runzeln und Furchen ueberzogen."));
  AddDetail(({"runzeln","furchen"}),BS("Igors Gesicht scheint nurnoch aus "+
  "Runzeln und Furchen zu bestehen."));
  AddDetail(({"gesichtsausdruck","blick"}),BS("Igors Gesichtsausdruck ist "+
  "boese, sogar satanisch. Und sein Blick ist noch viel schlimmer. Bei "+
  "diesem Blick wird Dir ganz anders."));
  AddDetail(({"lichtschein","schatten"}),
  BS("Der Lichtschein der Fackeln scheint sich "+
  "in diesem merkwuerdigen Wind zu winden und zu zucken. Dementsprechend "+
  "bewegen sich natuerlich auch die Schatten auf eine sehr merkwuerdige "+
  "und lebendige Weise. Manchmal scheinen in den Schatten sogar kleine "+
  "rote Punkte zu gluehen..."));
  AddDetail(({"punkte"}),BS("Die Punkte sehen aus wie Augen. Jedoch kann "+
  "das eigentlich nicht sein, es sei denn die Schatten selbst haetten "+
  "Augen. Welch beunruhigende Vorstellung."));
  AddDetail(({"vorstellung"}),BS("Schatten mit Augen sind nicht gerade "+
  "das, was Du Dir unter einer beruhigenden Vorstellung vorstellst."));
  AddDetail(({"tuer"}),BS("Diese Tuer ist wirklich mysterioes, denn sie "+
  "besitzt weder Klinke noch Riegel. Ausserdem besitzt sie kein Scharnier "+
  "und scheint nicht einmal aufschwingen zu sollen. Wie soll man dann nur "+
  "in den Raum oestlich von hier kommen?"));
  AddDetail(({"klinke","riegel"}),BS("Diese Tuer besitzt weder Klinke noch "+
  "Riegel. Und das ist hoechst merkwuerdig."));
  AddDetail(({"aufschwingen"}),BS("Diese Tuer soll wohl garnicht aufschwin"+
  "gen. Die Frage ist: Was soll sie dann?"));
  AddDetail(({"frage"}),BS("Was soll sie dann?"));
  AddDetail(({"raum"}),BS("Du befindest Dich in einem Raum, und oestlich "+
  "von Dir befindet sich ein Raum. Wie kommst Du aber in den Raum oestlich "+
  "von Dir, wenn die verdammte Tuer nicht aufgeht?"));
  AddDetail(({"inschrift"}),BS("Die Inschrift zu lesen wuerde Dir sicher"+
  "lich mehr bringen."));
  AddReadDetail(({"inschrift"}),"        E I N S A T Z Z E N T R A L E\n");
  AddDetail(({"augen"}),BS("Du hast zwei davon. Das ist auch Ok. Aber die "+
  "Schatten hier scheinen teilweise auch welche zu haben. Und das findest "+
  "Du dann wirklich nicht gut."));
  AddDetail(({"bild"}),BS("Es gibt sogar mehrere davon..."));
  AddDetail(({"farbe"}),BS("Die Farbe der Fackeln ist ebenso wie die "+
  "Farbe der Steine ... schwarz. Aber das ueberrascht Dich nicht."));
  AddDetail(({"fasern"}),BS("Wie gesagt besitzt ein Koerper viele Fasern."));
  AddDetail(({"grund"}),BS("Du siehst hier keinen Grund."));
  AddDetail(({"hals"}),BS("Achtarch hat einen langen Hals."));
  AddDetail(({"meter"}),BS("Natuerlich weisst Du, was ein Meter ist."));
  AddDetail(({"scharnier"}),BS("Diese Tuer besitzt kein Scharnier."));
  AddDetail(({"zierde"}),BS("An den Fackelhaltern entdeckst Du keinerlei "+
  "Zierde."));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
 
  AddExit("norden",CHAOS_GILDEN_ROOM("cl3bu5"));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl3bu3"));
  
  AddCmd(({"oeffne"}),"open_door");
  AddCmd(({"schiebe","ziehe","schieb","zieh","drueck","druecke"}),"move_door");
  AddCmd(({"osten"}),"osten");
  
  
}


int open_door(string was) {
  if (was != "tuer")
    return notify_fail("Was moechtest Du denn oeffnen?\n"),0;
  write("Das geht nicht.\n");
  return 1;
}

int move_door(string was) {
  if (was != "tuer")
    return notify_fail("So geht das nicht...\n"),0;
  write("Die Tuer bewegt sich keinen Millimeter.\n");
  return 1;
}

int osten(string was) {
  if (this_player()->QueryProp(P_GUILD) != "chaos" ||
      this_player()->QueryProp(P_GUILD_LEVEL) < 11) {
    write("Du knallst gegen die geschlossene Tuer.\n");
    say(this_player()->Name(WER)+" laeuft gegen die geschlossene Tuer.\n",
        this_player());
    return 1;
  }
  write("Die Tuer oeffnet sich und laesst Dich passieren.\n");
  say("Die Tuer oeffnet sich, kurz bevor "+this_player()->Name(WER)+" sie "+
  "erreicht.\n",this_player());
  this_player()->move(CHAOS_GILDEN_ROOM("cerz1"),M_GO,"nach Osten");
  tell_room(this_object(),"Die Tuer schliesst sich.\n");
  return 1;
}
  