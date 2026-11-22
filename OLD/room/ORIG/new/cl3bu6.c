#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu4"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In einem duesteren Gang");
  SetProp(P_INT_LONG,BS("Du wanderst einen hohen, dunklen Gang entlang. "+
  "Die Waende sind mit einigen (wenigen) Gemaelden geschmueckt und mit "+
  "merkwuerdigen Fackeln bestueckt, welche flackerndes Licht in den "+
  "Raum werfen. Im Nordwesten scheint dieses Licht heller zu werden. "+
  "Nun, nicht gerade heller, aber weniger duester. Auch im Suedosten "+
  "wird es etwas heller. Insofern ist es hier ziemlich oede. Was die "+
  "Sache aber etwas interessanter macht, ist der Durchgang nach Sueden, "+
  "welcher von diesem Gang abgeht. Und auch dieser Durchgang waere wohl "+
  "ziemlich oede, wuerde ihn nicht diese steinerne Gestalt bewachen."));
  AddDetail(({"gang"}),BS("Dieser Gang sieht im Grunde aus wie all die "+
  "anderen Gaenge in dieser Burg. Er ist hoch und sehr dunkel. Seine "+
  "Waende bestehen aus den ueblichen gewaltigen schwarzen Steinen, und "+
  "sein Boden aus den schrecklich uninteressanten schwarzen Fliesen."));
  AddDetail(({"gaenge"}),BS("Es gibt hier jede Menge Gaenge hier unten. "+
  "Immerhin befindest Du Dich unter der Erde."));
  AddDetail(({"menge"}),BS("Jede Menge Gaenge! Wow!"));
  AddDetail(({"erde"}),BS("Du bist von grossen Massen von Gestein und "+
  "Eis umgeben, jedoch nicht von Erde. In sofern ist der obige Kommentar "+
  "nicht ganz korrekt gewesen."));
  AddDetail(({"gestein"}),BS("Das Gestein, von dem Du umgeben bist, hat "+
  "eine graeuliche Farbe. Das hast Du von draussen gesehen, von ausserhalb "+
  "der Burg. Von diesem Gestein siehst Du momentan aber nichts, da die "+
  "Waende dieses Ganges aus schwarzen Steinen besteht."));
  AddDetail(({"farbe"}),BS("Die Farbe der Steine um Dich herum ist schwarz. "+
  "Und nicht irgendein Schwarz, sondern ein absolut schwarzes Schwarz."));
  AddDetail(({"schwarz"}),BS("Wow. Dieses Schwarz ist wirklich was besonderes."));
  AddDetail(({"kommentar"}),BS("Dieser Kommentar war nicht ganz korrekt."));
  AddDetail(({"eis"}),BS("Wusstest Du das nicht? Du befindest Dich in einem "+
  "gealtigen Eisberg! Diese Burg wurde darin gebaut, und der Eisberg ist "+
  "sogar ein besonderer Eisberg, denn er ist schwarz!"));
  AddDetail(({"eisberg"}),"Oh wie waer das schoen, wie waer das fein.\n"+
  "Koennt ich nur ein Eisberg sein.\n");
  AddDetail(({"decke"}),BS("Es ist so dunkel, dass Du die Decke hier nicht "+
  "richtig erkennen kannst. Da es im Suedosten und im Nordwesten jedoch "+
  "etwas heller zu sein scheint, kannst Du die Decke dort eventuell sehen. "+
  "Man soll die Hoffnung ja nie aufgeben!"));
  AddDetail(({"hoffnung"}),BS("Die Hoffnung sollte man niemals aufgeben. "+
  "Denn denke immer daran: Der Morgen stirbt nie."));
  AddDetail(({"morgen"}),BS("Der stirbt nie."));
  AddDetail(({"nordwesten","suedosten"}),BS("Dieser Gang fuehrt von Nordwesten "+
  "nach Suedosten."));
  AddDetail(({"wand","waende"}),BS("Die Waende dieses Ganges bestehen aus "+
  "gewaltigen, schwarzen Steinen. Wie immer strahlen diese Biester eine "+
  "grosse Dunkelheit und Kaelte aus, und das trotz der Fackeln, welche in "+
  "grossen Abstaenden in die Steine geschlagen wurden. Vielleicht aus diesem "+
  "Grunde hat man sich wohl dazu durchgerungen, hier zwei grosse Bilder auf"+
  "zuhaengen."));
  AddDetail(({"stein","steine"}),BS("Die Steine sind gewaltig, pechschwarz "+
  "und im Grunde ohne Makel. Nun, ohne Makel, wenn man von den Fackelhaltern "+
  "absieht, welche in diese Steine getrieben wurden."));
  AddDetail(({"grund","grunde"}),BS("Nicht alles muss einen Grund haben. "+
  "Sieh das endlich mal ein."));
  AddDetail(({"makel"}),BS("Diese Steine sind nicht makellos."));
  AddDetail(({"fackelhalter"}),BS("Die Fackelhalter sind gusseisern und "+
  "fast ebenso schwarz wie die Steine, in die sie geschlagen wurden. Es sind "+
  "wirklich haessliche Geraete, welche wohl wirklich lediglich dazu dienen, "+
  "die fast ebenso haesslichen Fackeln zu halten, welche in ihnen stecken."));
  AddDetail(({"eisen"}),BS("Die Fackelhalter bestehen aus Eisen."));
  AddDetail(({"geraete"}),BS("Diese Fackelhalter sind wirklich fuerchterlich "+
  "haesslich."));
  AddDetail(({"fackel","fackeln"}),BS("Die Fackeln sind schwarz und sehen "+
  "irgendwie ziemlich komisch aus. Sie verbreiten nur aeusserst wenig Licht, "+
  "flackern extrem und sehen ziemlich haesslich aus."));
  AddDetail(({"licht","dunkelheit","finsternis"}),BS("Der Gang ist hier ziem"+
  "lich duester. Das wenige Licht der hier angebrachten Fackeln reicht nicht "+
  "allzuweit, und so ist der Gang von beunruhigenden, zuckenden Schatten "+
  "erfuellt."));
  AddDetail(({"schatten"}),BS("Die Schatten bewegen sich mit den flackernden "+
  "Fackeln in sehr lebendiger und beunruhigender Weise. Nicht zum ersten "+
  "Mal fragst Du Dich, ob diese Schatten wohl mehr sind als bloss die Abwesen"+
  "heit von Licht."));
  AddDetail(({"weise"}),BS("Du hast voellig recht. Ich bin sehr weise."));
  AddDetail(({"nicht"}),BS("Wenn Du nicht untersuchst kannst Du auch nicht "+
  "erwarten, etwas zu finden."));
  AddDetail(({"mal"}),BS("Durch dieses Mal sollst Du ab jetzt immerdar gezei"+
  "chnet sein."));
  AddDetail(({"abwesenheit"}),BS("Das Licht in diesem Gang ist ziemlich abwe"+
  "send, doch die Schatten sehen selbst dafuer zu bedrohlich aus..."));
  AddDetail(({"biester"}),BS("Damit waren die Steine gemeint. Aber es ist "+
  "schoen, dass wir mal drueber gesprochen haben."));
  AddDetail(({"abstaende"}),BS("Die Abstaende zwischen den einzelnen Fackel"+
  "haltern ist schon extrem hoch. Hier hat wieder irgendwer extrem am "+
  "Budget gespart. So ein Mist."));
  AddDetail(({"budget","mist"}),BS("Mit einem schlechten Budget arbeiten zu "+
  "muessen ist wirklich Mist."));
  AddDetail(({"kaelte"}),BS("Diese komischen Steine strahlen, wie sollte es "+
  "auch anders sein, eine unnatuerliche, unangenehme Kaelte aus. Naja, "+
  "denkst Du Dir. Solgangs weiter nichts ist..."));
  AddDetail(({"bild","bilder","gemaelde"}),BS("Nicht nur an Fackelhaltern, "+
  "auch an den Bildern wurde gespart. Lediglich zwei haengen an den Waenden. "+
  "Dafuer sind die Bilder jedoch recht gross, immerhin knappe zwei Meter. "+
  "Du kannst die Bilder, wie immer, auch einzeln betrachten."));
  AddDetail(({"bild 1","gemaelde 1","hutschat"}),
  BS("Das erste Bild stellt Hutschat, "+
  "den Verwalter der Gilde, dar. Er ist ein eher kleiner Mann, der eigent"+
  "lich ziemlich schwaechlich und nach nix besonderen aussieht. Fehlte nur"+
  "noch, dass der Kerl ne Brille tragen wuerde. Dennoch bist Du durchaus "+
  "beeindruckt von der Gestalt auf dem Bild. Und wenn Du sie auch nicht "+
  "respektierst, so ... nun ... unterschaetzt Du sie auch nicht. Denn "+
  "Hutschat hat das unglaubliche Talent, das Chaos, welches in dieser Gilde "+
  "herrscht, zu durchschauen und (zumindest auf dem Papier) zu ordnen. "+
  "Deshalb stellt Hutschat fuer diese Gilde einen geradezu unschaetzbaren "+
  "Wert dar, auch wenn alle Chaoten ihn fuer ein jammerndes Muttersoehnchen "+
  "halten. Hutschat ist WICHTIG. Das lernt jeder Chaot als allererstes."));
  AddDetail(({"mann"}),BS("Meinst Du Hutschat oder den Schiedsrichter?"));
  AddDetail(({"kerl"}),BS("Das ist Hutschat. Er sieht zwar nach nicht "+
  "viel aus, aber er hat ne Menge in der Birne."));
  AddDetail(({"birne"}),BS("Hutschat kann wirklich viel. Das muss man ihm "+
  "lassen."));
  AddDetail(({"brille"}),BS("Natuerlich traegt Hutschat keine Brille. Das "+
  "waere auch wirklich zu gefaehrlich. Nichts tut ein Chaot lieber, als "+
  "einen Brillentraeger zu schlagen."));
  AddDetail(({"brillentraeger"}),BS("Hutschat ist gluecklicherweise kein "+
  "Brillentraeger."));
  AddDetail(({"chaot","chaoten"}),BS("Chaoten sind die Besten!"));
  AddDetail(({"besten","beste"}),BS("Na Chaoten!"));
  AddDetail(({"gestalt"}),BS("Diese Gestalt ist Hutschat, der Verwalter "+
  "der Gilde!"));
  AddDetail(({"gilde","chaosgilde","verwalter"}),BS("Die Chaosgilde ist, "+
  "noch viel mehr als andere Gilden, eine fuerchterlich chaotische Gilde. "+
  "Eine Gilde wie diese zu verwalten, dass verlangt schon nach einem Mann "+
  "wie Hutschat, dem Verwalter der Gilde."));
  AddDetail(({"gilden"}),BS("Es gibt viele Gilden, aber die Chaosgilde ist "+
  "immernoch die allerbeste."));
  AddDetail(({"talent"}),BS("Das Talent von Hutschat ist es, dass Chaos "+
  "dieser Gilde zu durchschauen und, soweit noetig, zu ordnen. Niemand "+
  "anders als Hutschat hat das jemals geschafft. Deshalb ist Hutschat so "+
  "wichtig fuer die Gilde."));
  AddDetail(({"niemand"}),BS("Niemand sagt: Ich habs mal geschafft! Ich h"+
  "abs mal geschafft!"));
  AddDetail(({"papier"}),BS("Hutschat kann mit Papier besser umgehen als "+
  "alle Kaempfer zusammengenommen mit einem Schwert."));
  AddDetail(({"kaempfer","schwert"}),BS("Das ist natuerlich keine grosse "+
  "Kunst, und wer schon einmal einen Kaempfer mit einem Schwert in "+
  "Aktion gesehen hat, wird mir da zustimmen :-)."));
  AddDetail(({"aktion"}),BS("Einen Kaempfer in Aktion zu sehen, ist schon "+
  "verdammt witzig, besonders mit einem Schwert *lach* *waelz*."));
  AddDetail(({"wert"}),BS("Hutschat ist fuer die Chaosgilde geradezu "+
  "unersetzlich."));
  AddDetail(({"muttersoehnchen"}),BS("Jeder weiss es, jeder sagt es. "+
  "Hutschat ist ein Muttersoehnchen. Aber das ist ok, denn er kann, "+
  "was sonst keiner kann."));
  AddDetail(({"burg"}),BS("Du befindest Dich, wie Du natuerlich sehr "+
  "wohl weisst, unterhalb der chaotischen Burg. Die sehr viel wichtigere "+
  "Frage ist hierbei jedoch: Wie kommst Du da wieder hoch?"));
  AddDetail(({"frage"}),BS("'Wie kommst Du da wieder hoch?'"));
  AddDetail(({"chaos"}),BS("Nur Hutschat hat das seltene Talent, das "+
  "Chaos dieser Gilde zu durchschauen und zu ordnen."));
  AddDetail(({"kunst"}),BS("Die Kunst, welcher Du Dich verschreiben hast, "+
  "ist die Kunst des Chaos."));
  AddDetail(({"massen"}),BS("Die Massen von Gestein, welche Dich umgeben, "+
  "sind wirklich gewaltig!"));
  AddDetail(({"meter"}),BS("Wie auch sonst schon immer: Du weisst, wie lang "+
  "ein Meter ist."));
  AddDetail(({"raum"}),BS("Dies ist kein Raum, dies ist ein Gang. Ich mein, "+
  "natuerlich ist auch ein Gang ein Raum, aber wir wollen doch mal "+
  "praezise bleiben."));
  AddDetail(({"bild 2","gemaelde 2","schiedsrichter"}),
  BS("Das zweite Gemaelde zeigt einen unfairen Schiedsrichter. Der boesar"+
  "tig dreinschauende Bube schaut wirklich fies und gemein aus. Er scheint "+
  "jedoch recht schwaechlich zu sein und keineswegs bedrohlich. Hmm. Nun. "+
  "Dieser Mann ist auch Mitarbeiter der Chaosgilde. Seine Bedeutung fuer "+
  "die Gilde wird meistens unterschaetzt. ... . Aehm ja. Und zwar ... "+
  "hmmm ... weil, aehm, oeeeh. Hmmm. Ach, genau: Weil nur durch ihn die "+
  "vielen Zuschauer eines Kampfes mitkriegen, was da unten eigentlich "+
  "wirklich passiert!"));
  AddDetail(({"bube"}),BS("Boooh. Sieht der boese aus. Wow."));
  AddDetail(({"mitarbeiter"}),BS("Sowohl Hutschat als auch der Schiedsrichter "+
  "sind Mitarbeiter der wunderbaren Chaosgilde."));
  AddDetail(({"bedeutung"}),BS("Die Bedeutung des Schiedsrichter ist ... "+
  "nun ... also, genauer gesehen ... fuer die Chaosgilde ... minimal."));
  AddDetail(({"zuschauer"}),BS("Bei den vielen Kaempfen in der Chaosgilde "+
  "schauen natuerlich auch viele Zuschauer zu. Und das sogar, wenn die "+
  "Kaempfe in der Arena stattfinden!"));
  AddDetail(({"kampf","kaempfe"}),BS("Die Kaempfe in der Chaosgilde sind immer "+
  "lustig. Und manchmal finden sie sogar in der Kampfarena statt!"));
  AddDetail(({"arena","kampfarena"}),BS("Jaja, die Chaosgilde hat sowas!"));
  AddDetail(({"nichts"}),BS("Ja klaaaaaaaaar!"));
  AddDetail(({"sache"}),BS("Die Sache halt :)"));
  AddDetail(({"durchgang"}),BS("Er fuehrt nach Sueden."));
  AddDetail(({"gestalt"}),BS("Oooooh. Jetzt ist sie weg. Wo ist sie hin?"));
  AddDetail(({"boden"}),BS("Der Boden besteht aus unscheinbaren schwarzen "+
  "Fliesen."));
  AddDetail(({"fliesen"}),BS("Diese Fliesen sind absolut uninteressant."));
  
  
  
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl3bu5"));
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl3bu1"));
  AddSpecialExit("sueden","ex_sueden");
  
  AddItem(CHAOS_GILDEN_MON("cl3_stonedaem"),REFRESH_DESTRUCT);
}

int ex_sueden() {
  if (this_player()->QueryProp(P_GUILD) != "chaos") return 0;
  if (this_player()->QueryProp(P_GUILD_LEVEL) >8)
    this_player()->move(CHAOS_GILDEN_ROOM("cl3_teleport"),M_GO,"nach sueden");
  if (!present("\nstone_daemon",this_object()))
    reset();
  write("Der steinerne Waechter haelt Dich auf.\n");
  say("Der steinerne Waechter haelt "+this_player()->name(WEN)+" auf.\n",this_player());
  tell_room(this_object(),
  "Der steinerne Waechter sagt: Auf Grund der Kontaminierung dieses Raumes ist\n"+
  "Der steinerne Waechter sagt: der Zutritt fuer Chaoten unterhalb dem Level\n"+
  "Der steinerne Waechter sagt: eines Dunkelmagiers gesperrt. Geh weg.\n");
  return 1;
}