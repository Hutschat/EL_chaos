#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu10"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Unter der Gilde");
  SetProp(P_INT_LONG,BS("Dunkel ist es hier, aber nicht ganz so dunkel wie "+
  "sonst auf dieser fuerchterlich dunklen Ebene. Deshalb kannst Du noch "+
  "relativ gut erkennen, dass Du Dich in einem grossem Raum befindest, der "+
  "eine ziemlich hohe Decke hat. Dies wenigstens ist wohl ueberall auf dieser "+
  "Ebene gleich. Das Licht stammt von jeder Menge Kerzen, die in den hier "+
  "ueblichen schwarzen Kerzenhaltern vor den Waenden stehen. Ein Gang fuehrt "+
  "aus diesem Raum fort nach Nordwesten. Im Osten befindet sich ein grosses, "+
  "hoelzernes Portal in der Wand, ueber dem ein grosses Schild angebracht ist."));
  AddDetail(({"ebene"}),BS("Wo befindest Du Dich hier? Das ist eine gute Frage. "+
  "Du befindest Dich auf einer Ebene mit einigen Gaengen und Raeumen. Ueber "+
  "Dir, da bist Du ziemlich sicher, befindet sich die sagenumwobene, grausame "+
  "Chaosgilde. Um Dich herum befindet sich Gestein, und dann ein gruener, dam"+
  "pfender Saeuresee. Ja, damit ist deine derzeitige Position wohl recht "+
  "gut beschrieben."));
  AddDetail(({"frage"}),BS("Die Frage war: 'Wo befindest Du Dich hier?'."));
  AddDetail(({"gaenge"}),BS("Es gibt auf dieser Ebene einige Gaenge, und diese "+
  "sehen eigentlich alle ziemlich gleich aus. Sie sind dunkel, sie sind hoch "+
  "und relativ kalt, ohne wirklich kalt zu sein. Sie sind gemauert aus schwar"+
  "zen, gewaltigen Steinen und sind manchmal mit Gemaelden geschmueckt."));
  AddDetail(({"kaelte"}),BS("Es ist hier relativ kalt, aber nicht wirklich kalt."));
  AddDetail(({"gemaelde"}),BS("Hier siehst Du keine Gemaelde, aber im Gang, "+
  "im Nordwesten, findest Du sicherlich welche."));
  AddDetail(({"nordwesten"}),BS("Geh einfach hin..."));
  AddDetail(({"raeume"}),BS("Du befindest Dich natuerlich gerade in nur einem "+
  "Raum. Doch auf dieser Ebene befinden sich noch mehr Raeume, auch wenn Du "+
  "eventuell keinen Zugang dazu hast."));
  AddDetail(({"zugang"}),BS("Zugang verweigert."));
  AddDetail(({"gang"}),BS("Der Gang fuehrt fort nach Nordwesten, hinein in "+
  "eine ungewisse, seltsam lebendige Finsternis."));
  AddDetail(({"gilde","chaosgilde"}),BS("Die Chaosgilde ist die Gilde des Chaos, "+
  "das Heim der Chaoten, der sagenumwobenen Krieger des Chaos. Sie befindet "+
  "sich in einer schwarzen Burg in einer gewaltigen Hoehle in einem noch gewalt"+
  "igeren schwarzen Eisberg."));
  AddDetail(({"chaos"}),BS("Chaos Rulez!"));
  AddDetail(({"chaot","chaoten","krieger","krieger des chaos"}),BS("Die Chaoten "+
  "sind die maechtigen, gefuerchteten, abgrundtief boesen und wirklich wider"+
  "lichen Krieger des Chaos. Sie sind weit und breit gefuehrchtet und verhasst. "+
  "Du bist wirklich stolz, zu ihnen zu gehoeren."));
  AddDetail(({"gestein"}),BS("Du siehst das Gestein des Felsens nicht, auf dem "+
  "die schwarze Burg gebaut wurde. Die Waende wurden auf der gesamten Ebene "+
  "mit grossen Steinen vermauert und verwehren jeglichen Durchblick."));
  AddDetail(({"durchblick"}),BS("Ist schon ok, Du hast den totalen Durchblick :)."));
  AddDetail(({"burg"}),BS("Die schwarze Burg ist das Heim der Chaoten. In ihr "+
  "befindet sich die sagenhafte Chaosgilde. Sie wurde auf einem grossen Felsen "+
  "gebaut, mitten in einem gruenen, dampfenden Saeuresee."));
  AddDetail(({"see","saeuresee"}),BS("Der See ist von hier aus auch nicht zu "+
  "sehen. Du untersuchst aber auch jeden Scheiss."));
  AddDetail(({"scheiss"}),BS("Das war jetzt klar :-)."));
  AddDetail(({"hoehle"}),BS("Die Hoehle ist riesengross und eiskalt und ueber"+
  "all um Dich herum. Du kannst sie natuerlich von hier aus keineswegs sehen."));
  AddDetail(({"berg","eisberg"}),BS("Ein Eisberg ist ein verdammt cooler Berg. "+
  "Besonders wenn er schwarz ist..."));
  AddDetail(({"position"}),BS("Du befindest Dich auf einer nicht naeher defi"+
  "nierten Ebene unterhalb der Chaosgilde innerhalb einer grossen Hoehle in "+
  "ein schwarzen Eisberg."));
  AddDetail(({"felsen"}),BS("Die schwarze Burg wurde auf einen grossen, grauen "+
  "Felsen gebaut, der aus einem grossen, gruenen, dampfenden Saeuresee ragt. "+
  "Diesen Felsen kannst Du von hier aus natuerlich nicht sehen. Wie auch :)."));
  AddDetail(({"finsternis","dunkelheit","licht"}),
  BS("Es ist hier nicht ganz so dunkel "+
  "wie in den anderen Raeumen hier unten. Dieser Umstand liegt an den Unmengen "+
  "von Kerzen, die an den Waenden aufgereiht stehen, auf ebenso viele Kerzen"+
  "staender gesteckt und wild vor sich hinflackernd. Ueberraschenderweise "+
  "ist es hier sogar hell genug, um vage die Decke dieses Raumes zu erkennen."));
  AddDetail(({"kerze","kerzen"}),BS("Die Kerzen sind schwarz und scheinen "+
  "aus keinem normalen Wachs geformt zu sein. Ihre Flamme flackert auch "+
  "ohne jeden Luftzug und verbreitet nur sehr wenig. Man benoetigt all die "+
  "Unmengen Kerzen in diesem Raum, um eine gewisse (noch immer unzulaengliche) "+
  "Helligkeit zustande zu bkommen. Dafuer scheinen sie jedoch niemals abzu"+
  "brennen. Das sind wirklich aussergewoehnliche Kerzen."));
  AddDetail(({"wachs"}),BS("Ist es Wachs, aus dem die Kerzen geformt sind? "+
  "Du glaubst es nicht. Das Material fuehlt sich anders an, fest und kalt und "+
  "irgendwie glitschig. Es ist unangenehm, diese Kerzen anzufassen. Deshalb "+
  "laesst Du es auch schnell wieder bleiben."));
  AddDetail(({"material"}),BS("Das Material, aus dem die Kerzen geformt wurden, "+
  "ist sicherlich kein Wachs. Es ist etwas anderes, magisches. Du weisst nur "+
  "nicht genau was."));
  AddDetail(({"magie"}),BS("Die Kerzen muessen magisch sein. Immerhin brennen "+
  "sie einfach nicht herunter!"));
  AddDetail(({"flamme","flammen"}),BS("Natuerlich haben die Kerzen Flammen, aber auch diese "+
  "unterscheiden sich stark von denen normaler Kerzen. Sie flacken wild ohne "+
  "jeden Luftzug und verbreiten so gut wie garkeine Helligkeit, und noch wenig"+
  "er Waerme. Es sind boesartige, merkwuerdige, unnatuerliche Flammen. Mehr "+
  "weisst Du nicht darueber zu sagen."));
  AddDetail(({"luft","luftzug"}),BS("Die Luft scheint hier unten geradezu zu "+
  "stehen. Kein Hauch bewegt sich. Dennoch ist die Luft relativ rein und klar, "+
  "wenn sie auch etwas merkwuerdig riecht. Trotzdem flackern die Kerzen jedoch "+
  "wild vor sich hin. Was sind das nur fuer Dinger."));
  AddDetail(({"hauch","lufthauch"}),BS("Hier regt sich nicht der geringste Luft"+
  "hauch."));
  AddDetail(({"dinger"}),BS("Du meinst bestimmt die Kerzen. Nun, dass sind "+
  "wirklich merkwuerdige und unerklaerliche Dinger. Sie erzeugen in Dir ein "+
  "grosses Unbehagen. Du magst sie nicht, besonders da es so viele sind, die "+
  "um Dich herumstehen."));
  AddDetail(({"unbehagen"}),BS("Diese Kerzen sind merkwuerdig. Du magst sie nicht."));
  AddDetail(({"heim"}),BS("Das Heim ist wo das Herz ist."));
  AddDetail(({"herz"}),BS("Das schwarze, kalte, verdorbene Herz eines Chaoten "+
  "haengt an seiner Gilde."));
  AddDetail(({"kerzenhalter","kerzenstaender"}),BS("Jawoll, es stehen wirklich "+
  "jede erdenkliche Menge Kerzenstaender hier vor den Waenden rum. Waeren sie "+
  "in irgendeiner Weise huebsch oder auch nur was wert, koennte man mit den "+
  "Dingern sicherlich ein Vermoegen machen. Aber Du kannst Dir wirklich "+
  "niemanden vorstellen, der fuer sowas auch nur eine Muenze springen liesse."));
  AddDetail(({"menge"}),BS("Es gibt hier jede Menge Kerzenstaender und Unmengen "+
  "von Kerzen auf den Kerzenstaendern."));
  AddDetail(({"vermoegen"}),BS("Mit den Kerzenstaendern kannst Du bestimmt "+
  "kein Vermoegen machen. Dann waeren die sicher alle schon gestohlen worden."));
  AddDetail(({"niemand"}),BS("Niemand sagt: Noooeh, dafuer zahl ich nix."));
  AddDetail(({"muenze"}),BS("Ei wo issie denn?"));
  AddDetail(({"ei"}),BS("Pfffffff :)"));
  AddDetail(({"helligkeit"}),BS("Es ist hier wirklich nicht hell. Im Gegenteil "+
  "ist es sogar ziemlich dunkel. Doch immerhin ist es nicht so dunkel wie sonst "+
  "ueberall auf dieser Ebene, sondern einen Tuck heller. Und das ist doch "+
  "schon mal was wert."));
  AddDetail(({"gegenteil"}),BS("Es ist hier nicht total dunkel, sondern im "+
  "Gegenteil, aehm, nun, oeh, nicht ganz so dunkel."));
  AddDetail(({"tuck"}),BS("Hier ist es einen Tuck heller als anderswo in den "+
  "Gaengen dieser Ebene."));
  AddDetail(({"dunkel"}),BS("Eine ziemliche Finsternis umhuellt Dich."));
  AddDetail(({"raum"}),QueryProp(P_INT_LONG));
  AddDetail(({"umstand"}),BS("Der Umstand, der diesen Raum von den anderen "+
  "in dieser Ebene unterscheidet, ist seine Helligkeit. Nun, seien wir "+
  "gerecht, weniger seine Helligkeit, sondern seine etwas geringere Finsternis."));
  AddDetail(({"eichenbalken","balken"}),BS("Na DAS sind ja mal dicke Dinger. Du fragst "+
  "Dich wirklich, wie man diese Balken in diese Hoehle geschafft hat, "+
  "ganz zu schweigen von dieser Ebene der Burg."));
  AddDetail(({"schloss"}),BS("Das Schloss an der Tuer ist verschlossen. Man "+
  "braeuchte wohl einen Schluessel, um es zu oeffnen."));
  AddDetail(({"schluessel"}),BS("Na, hast Du einen?"));
  AddDetail(({"schild"}),BS("Du kannst es lesen."));
  AddReadDetail(({"schild"}),"         P  O  R  N  S  K  Z\n\n");
  AddDetail(({"unmengen"}),BS("Das sind wirklich verdammt viele Kerzen."));
  AddDetail(({"waerme"}),BS("Die Kerzen verbreiten ja garnichts! Sie "+
  "brennen nicht gut und strahlen auch keine Waerme aus! Was fuer merkwuerdige "+
  "Kerzen."));
  AddDetail(({"wand","waende"}),BS("Die Waende... Oeeeh. Hmmm. Ja. Es sind "+
  "hohe Waende, wirklich hohe Waende, gebaut aus gewaltigen, schwarzen Stein"+
  "en. Vor ihnen stehen, in einer langen Reihe, jede Menge Kerzenstaender "+
  "mit Unmengen schwarzen Kerzen auf ihnen."));
  AddDetail(({"reihe","reihen"}),BS("Die vielen Kerzenstaender stehen in "+
  "einer langen Reihe vor den Waenden dieses Raumes."));
  AddDetail(({"boden"}),BS("Klar gibts hier nen Boden. Sonst wuerdest Du "+
  "ja runterfallen. Schaun wir uns den doch mal an. Er besteht aus schwar"+
  "zen, steinernen Fliesen, welche uneben und scharfkantig und reinste "+
  "Stolperfallen sind. Ansonsten ist er aber fuerchterlich uninteressant."));
  AddDetail(({"fliesen"}),BS("Die Fliesen sind scharfkantig und von der "+
  "gleichen, lichtabsorbierenden Farbe wie die Steine, aus denen die Waende "+
  "gebaut wurden. Das ist gefaehrlich, da die Fliesen uneben angeordnet "+
  "sind und so zu den reinsten Stolperfallen werden koennen."));
  AddDetail(({"farbe"}),BS("Die beherrschende Farbe hier ist die Farbe "+
  "der Steine und Fliesen. Es ist ein absolut dunkles, lichtabsorbierendes, "+
  "fieses, boesartiges Schwarz."));
  AddDetail(({"schwarz"}),BS("Wow ist das ein Schwarz."));
  AddDetail(({"stolperfallen"}),BS("Huuuh, hier muss man verdammt gut auf"+
  "passen, sonst faellt man gnadenlos hin."));
  AddDetail(({"decke"}),BS("Es ist hier zwar etwas heller als in den uebrigen "+
  "Raeumen dieser Ebene, und im Gegensatz zu denen kann man auch so ungefaehr "+
  "erkennen, wo die Decke befindet und dass sie sich kuppelartig ueber Dir "+
  "woelbt. Leider kann man aber auch nicht mehr erkennen als das. Die Decke "+
  "scheint jedoch nicht in dem Schwarz gefaerbt zu sein, in dem die Waende "+
  "oder der Boden glaenzen."));
  AddDetail(({"gegensatz"}),BS("Jaja, ok, das hast Du jetzt auch untersucht."));
  AddDetail(({"steine"}),BS("Es gibt jede Menge grosser Steine hier. Sie "+
  "sind schwarz und bilden, aufeinandergeschichtet und gemauert, die Waende "+
  "dieses grossartigen Raumes."));
  
  AddSmells(SENSE_DEFAULT,BS("Die Luft riecht irgendwie komisch."));
  AddSmells("luft","*Sniff Sniff* Merkwuerdig, aber atembar.\n");
  AddSounds(SENSE_DEFAULT,BS("Du hoerst garnix."));
  
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl3bu10"));
  NewDoor("osten",CHAOS_GILDEN_ROOM("cl3quartiere"),({"tuer","portal"}),
    ({D_NAME,"Portal",
      D_GENDER,0,
      D_SHORT,"Im Osten ragt ein grosses, %ses Portal auf.",
      D_FLAGS, DOOR_CLOSED | DOOR_NEEDKEY | DOOR_RESET_CL,
      D_LONG,BS("Im Osten ragt das grosse, hoelzerne Portal auf. Es ist ein "+
      "sehr massives Portal und wurde aus massiven, dicken Eichenbalken "+
      "geschaffen. Ein gewaltiges Schloss ziehrt es und verwehrt Dir den "+
      "Zugang. Ueber dem Portal haengt ein grosses Schild.") }));

}
