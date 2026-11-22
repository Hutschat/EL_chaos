#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2bu_std");
#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu11"));
  SetProp(P_INT_SHORT,"In der chaotischen Burg.");
  SetProp(P_INT_LONG,break_string("Dunkel. Dunkel Dunkel Dunkel hier. Finster. "+
  "Verdammt verflucht fuerchterlich finster. Dunkel Dunkel Dunkel. "+
  "Mist Mist Mist. AUTSCH! AH! SHIT!\n"+
  "Du reibst Dir Dein Knie und versuchst zu erkennen, gegen was Du hier eig"+
  "entlich gestossen bist. IST das dunkel hier. Ahhh, ein spitzer, grosser, "+
  "pechschwarzer, so gut wie nicht zu sehender Felsbrocken. Hinter ihm tuer"+
  "men sich jede Menge weiterer Felsbrocken auf. Es sieht aus wie ein Truem"+
  "merfeld hier. Du erhebst deinen Blick in die Finsternis ueber Dir. Du "+
  "kannst den Turm natuerlich nicht sehen, der sich hier erhebt, doch Du "+
  "bist Dir sicher, dass er sich hier erhebt, stolz hinauf in die Nacht. "+
  "Ob die Truemmer von ihm herabgefallen sind? Auf jeden Fall blockieren sie "+
  "jegliche Zugangsmoeglichkeit zum Turm.\n"+
  "Du schaust Dich weiter um. Du stehst somit in einer Gasse, welche "+
  "Du nach Nordosten verlassen kannst und die zum groessten Teil mit diesen "+
  "Truemmern bedeckt ist. Im Sueden erhebt sich majestaetisch (und in dieser "+
  "Dunkelheit fast unsichtbar) die grosse Burgmauer und im Norden die "+
  "Hauswand eines der Gebaeude hier in der Burg.",78,0,1));
  AddDetail(({"knie"}),BS("Ahhh, das tu weh! So ein Mist aber auch!"));
  AddDetail(({"mist"}),BS("Pfff. Dies ist eine ordentliche Burg. Mist "+
  "kannst Du woanders suchen..."));
  AddDetail(({"boden"}),BS("Der Boden ist hier groesstenteils bedeckt mit "+
  "Truemmern, also gewaltigen Steinbrocken. Dort, wo Du ihn (in der "+
  "Finsternis natuerlich nicht allzu genau) sehen kannst, ist er mit "+
  "schwarzen Pflastersteinen bedeckt und sieht fuerchterlich dunkel und "+
  "uninteressant aus. Aber naja, Du bist halt gruendlich. Das waere sicher"+
  "lich lobenswert, waere diese Burg nicht so fuerchterlich stupide..."));
  AddDetail(({"pflastersteine","pflasterstein"}),BS("*Gaeeeehn*. Ja, hier, "+
  "ein schwarzer Pflasterstein. Wie fuerchterlich interessant. Du kannst "+
  "Dich kaum noch aufrecht halten vor Aufregung. Doch dann die Ernuechterung"+
  ": Es ist nix besonderes an ihm zu erkennen."));
  AddDetail(({"aufregung","ernuechterung"}),BS("So ist das Leben. Aufregung "+
  "und Ernuechterung, ein ewiger Kreislauf..."));
  AddDetail(({"leben"}),BS("Das Leben ist schoeeeen, schoeeeeeen mit Jadeeee!"));
  AddDetail(({"jade"}),BS("OK, ok, keine weiteren Werbespots hier."));
  AddDetail(({"werbespots"}),BS("Einfach gut! Bei McDonalds ist es einfach gut! ...."));
  AddDetail(({"mcdonalds"}),BS("Arghs! Nein! Keine Werbespots mehr! Nein!"));
  AddDetail(({"kreislauf"}),BS("Das Leben ist ein gewaltiger Kreislauf, auch "+
  "wenn Du das jetzt vielleicht noch nicht ermessen kannst."));
  AddDetail(({"steinbrocken","steine","truemmer"}),BS("Die Steinbrocken und "+
  "Teile von Steinbrocken und Truemmer im allgemeinen tuermen sich hier ziem"+
  "lich hoch gegen die suedliche und oestliche Burgmauer auf. Du weisst nicht "+
  "wie sie hierhergekommen sind, ob ein Teil des Turmes eingestuerzt ist oder "+
  "jemand sie einfach n ur hierhin gekippt hat. Es sind schwere Steinbrocken, "+
  "welche Du wohl nicht von der Stelle bewegen koennen wirst. Sie tuermen "+
  "sich wohl drei Meter und hoeher auf. Da ist wirklich kein Durchkommen."));
  AddDetail(({"teile"}),BS("Viele Teile ergeben ein Ganzes."));
  AddDetail(({"ganzes"}),BS("Ja, untersuch ruhig das Ganze hier. Ich wuensche "+
  "Dir viel Erfolg!"));
  AddDetail(({"erfolg"}),BS("Ich wuensche Dir viel davon!"));
  AddDetail(({"suedliche burgmauer"}),BS("Sie sieht in etwa so aus wie die "+
  "oestliche Burgmauer."));
  AddDetail(({"oestliche burgmauer"}),BS("Die kannst Du von hier aus garnicht "+
  "erkennen, aber sie wird wohl so aehnlich aussehen wie die suedliche Burg"+
  "mauer. Naja, warum auch nicht."));
  AddDetail(({"burgmauer","burgmauern"}),BS("Jawohl, dies hier ist eine Burg, "+
  "deshalb besitzt sie auch ein paar Burgmauern. Das ist schon aufgrund der "+
  "Atmosphae ein Muss. Doch diese Mauer erfuellt noch mehr Aufgaben als "));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl2bu8"));
}
