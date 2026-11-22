#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu5"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In einem Gang unter einer Burg");
  SetProp(P_INT_LONG,BS("Du befindest Dich in einem langen Gang, "+
  "welcher von Nordosten nach Suedwesten fuehrt. Der Gang ist recht "+
  "hoch, die Decke in der Dunkelheit kaum mehr zu erkennen. Die kahlen "+
  "schwarzen Waende sind teilweise mit Fellen verhaengt, um die gewaltigen "+
  "Steine zu verbergen, welche die Waende des Ganges bilden. In gewissen "+
  "Abstaenden haengen einige der beliebten magischen Fackeln in Fackelhal"+
  "tern. Ein praechtiger Durchgang fuehrt nach Suedosten."));
  AddDetail(({"gang"}),BS("Dies ist ein Gang, in der Tat."));
  AddDetail(({"tat"}),BS("Pffffff."));
  AddDetail(({"decke"}),BS("Die Decke ist recht hoch, selbst ein Elf kann "+
  "hier die Decke (ohne Hilfsmittel) nicht einmal springend erreichen. "+
  "Dementsprechend dunkel ist es aber auch da oben, und dementsprechend kalt "+
  "hier unten. Diese Gaenge sind wirklich schwer zu heitzen. Nicht, dass "+
  "es jemand versucht haette."));
  AddDetail(({"jemand"}),BS("Jemand versteckt einen Holzscheit hinter seinem "+
  "Ruecken und pfeift unschuldig."));
  AddDetail(({"scheit","holzscheit"}),BS("Jemand hat ihn gut hinter seinem "+
  "Ruecken versteckt."));
  AddDetail(({"ruecken"}),BS("Jemand ist ja eigentlich garnicht da. Deshalb "+
  "erspare ich mir, seinen nicht vorhandenen Ruecken zu beschreiben."));
  AddDetail(({"elf"}),BS("Ein Elf ist wirklich lang. Es gibt kaum was "+
  "laengeres."));
  AddDetail(({"hilfsmittel"}),BS("Als unzulaessiges Hilfsmittel wuerde zum "+
  "Beispiel ein Trampolin zaehlen."));
  AddDetail(({"trampolin","trampoline"}),BS("Trampoline sind nicht erlaubt."));
  AddDetail(({"gaenge"}),BS("Langsam langsam. Momentan befindest Du Dich erst "+
  "mal in einem Gang."));
  AddDetail(({"nordosten","suedwesten"}),BS("Der Gang fuehrt in der Tat "+
  "von Nordosten nach Suedwesten. Wie interessant. Noch interessanter ist "+
  "sicherlich der Durchgang nach Suedosten, welcher wirklich praechtig ist!"));
  AddDetail(({"dunkelheit"}),BS("Es ist wirklich dunkel hier. Die wenigen "+
  "Fackeln, welche in den Fackelhaltern stecken, verbreiten nur ungenuegend "+
  "Licht, und so ist der Gang in merkwuerdige, hin und herhuschende Schatten "+
  "eingetaucht."));
  AddDetail(({"licht"}),BS("Das wenige Licht in diesem Raum stammt von den "+
  "Fackeln, welche in ihren Fackelhaltern vor sich hinbrennen."));
  AddDetail(({"fackel","fackeln"}),BS("Die Fackeln in diesem Raum sind sicher"+
  "lich magische Fackeln. Es wird kaum alle paar Stunden ein Chaot vorbeikommen "+
  "und die Fackeln austauschen. Ausserdem bist Du davon ueberzeugt, dass eine "+
  "normale Fackel mehr Licht verbreiten wuerde, als diese merkwuerdigen Dinger. "+
  "Damit niemand diese Kuriositaeten klaut, wurden sie in ihren Fackelhaltern "+
  "fest eingeklemmt."));
  AddDetail(({"stunden","stunde"}),BS("Eine Fackel brennt niemals laenger "+
  "als eine Stunde, wenn sie nicht magisch ist."));
  AddDetail(({"chaot","chaoten"}),
  BS("Chaoten wuerden sich nie zum Austauschen von "+
  "Fackeln herablassen. So etwas tut ein richtiger Chaot nicht. Jawohl."));
  AddDetail(({"dinger"}),BS("Diese Fackeln sind wirklich merkwuerdig."));
  AddDetail(({"kuriositaeten"}),BS("Sicherlich will jeder so eine schicke "+
  "chaotische Fackel haben, denn sie macht sich wirklich gut ... irgendwo, "+
  "wo man sie nicht sieht :). Um dies zu vermeiden, wurden die Fackeln fest "+
  "mit den Fackelhaltern verbunden."));
  AddDetail(({"fackelhalter"}),BS("Die Fackelhalter bestehen aus Eisen und "+
  "stecken fest in den Waenden dieses Ganges. Also in den grossen Steinen, "+
  "welche die Waende bilden. Die kriegst Du da niemals raus."));
  AddDetail(({"eisen"}),BS("Du weisst, was Eisen ist. Deshalb werde ich es "+
  "nicht noch einmal erklaeren."));
  AddDetail(({"wand","waende"}),BS("Die Waende wurden aus den gewaltigen "+
  "Steinen zusammengefuegt, welche Du auch in der oberen Burg gesehen hast. "+
  "Zur Dekoration wurden diese jedoch teilweise mit alten Fellen verhaengt."));
  AddDetail(({"dekoration"}),BS("Hey, ein Chaot lebt nicht in einem fiesen "+
  "dreckigen Loch, in dem das Wasser von der Decke tropft und die Ratten "+
  "das Abendessen klauen. Wer wuerde auf solche Ideen kommen? Ha! Chaoten "+
  "wissen Komfort durchaus zu schaetzen."));
  AddDetail(({"loch"}),BS("Dies hier ist alles, aber kein dunkles Loch. "+
  "Loecher haben keine schicken Felle an den Waenden."));
  AddDetail(({"wasser"}),BS("Hier ist alles trocken."));
  AddDetail(({"ratten"}),BS("Hier siehst Du keine Ratten. Ratten wissen, in "+
  "Wuqours unmittelbarer Naehe zu leben hat mit ziemlicher Sicherheit einen "+
  "aeusserst schmerzvollen Tod in irgend einer Apparatur zur Folge."));
  AddDetail(({"wuqour"}),BS("Wuqour ist ein maechtiger, also wirklich "+
  "total absolut hyper uebel verdammt maechtiger Chaot. Soviel dazu"));
  AddDetail(({"naehe"}),BS("So ziemlich ueberall im Polar ist in Wuqours "+
  "Naehe, was Ratten angeht."));
  AddDetail(({"polar"}),BS("Dies ist der Polar."));
  AddDetail(({"sicherheit"}),BS("In dieser Burg ist Sicherheit ein sehr "+
  "relativer Begriff."));
  AddDetail(({"begriff"}),BS("Sicherheit war der besprochene Begriff."));
  AddDetail(({"tod"}),BS("Tod sagt: BALD IST ES ZEIT, MIT MIR ZU KOMMEN."));
  AddDetail(({"apparatur"}),BS("Frag am besten garnicht. Das wird eklig."));
  AddDetail(({"folge"}),BS("Hier konvergiert nix."));
  AddDetail(({"abendessen"}),BS("Dein Magen knurrt."));
  AddDetail(({"magen"}),BS("Er knurrt! Zeit fuers Abendessen."));
  AddDetail(({"zeit"}),BS("Sie schreitet fort."));
  AddDetail(({"komfort"}),BS("Diese schicken Felle an den Waenden zaehlen "+
  "zu einem guten Komfort."));
  AddDetail(({"fell","felle"}),BS("Es sind groesstenteils Ork- und Troll"+
  "felle, dazu ein paar Hobbitfelle und die Haut einiger Drachenbabies."));
  AddDetail(({"orkfelle","trollfelle"}),BS("Diese Felle sind schon relativ "+
  "alt und riechen etwas komisch. Ansonsten sind sie aber noch in Ordnung."));
  AddDetail(({"ordnung"}),BS("Ach was. Hier gibts keine Ordnung. Hier "+
  "regiert das Chaos."));
  AddDetail(({"chaos"}),BS("Chaos ist cool."));
  AddDetail(({"hobbitfelle"}),BS("Hobbitfelle sind recht  klein, was ein "+
  "Problem ist. Man muss schon mehrere Hobbits aneinandernaehen, um ein "+
  "einigermassen grosses Fell zu erhalten."));
  AddDetail(({"hobbits"}),BS("Hobbits sind lecker."));
  AddDetail(({"drachenbaby","drachenbabies"}),BS("Die Felle der Drachenbabies "+
  "werden hier nur aus sentimentalen Gruenden aufgehangen. Sie sehen aber auch "+
  "suess aus, die kleinen Biester."));
  AddDetail(({"biester"}),BS("Damit meinte ich die Drachenbabies."));
  AddDetail(({"haut"}),BS("Drachenbabies haben kein richtiges Fell. Sie haben "+
  "eine Haut."));
  AddDetail(({"stein","steine"}),BS("Die Steine sind gewaltig, schwarz und "+
  "ohne Makel. Naja, fast ohne Makel. Einige Fackelhalter wurden in den "+
  "Stein gerammt, um den Raum etwas zu beleuchten."));
  AddDetail(({"makel"}),BS("Diese Steine sind (so gut wie) ohne Makel."));
  AddDetail(({"gruende"}),BS("Die Gruende werde ich jetzt nicht erlaeutern. "+
  "Sie sind auf jeden Fall sentimental."));
  AddDetail(({"boden"}),BS("Der Boden des Ganges besteht aus schwarzen Fliesen, "+
  "welche eigentlich nicht naeher interessant sind."));
  AddDetail(({"fliesen"}),BS("Die Fliesen sind schwarz, quadratisch und bestehen "+
  "aus Stein. Sie besitzen keinerleich bemerkenswerte Eigenschaften."));
  AddDetail(({"eigenschaften"}),BS("Die Eigenschaften dieser Fliesen sind alles, "+
  "aber nicht interessant."));
  AddDetail(({"durchgang"}),BS("Nach Suedosten fuehrt ein praechtiger Durch"+
  "gang. Er ist verziehrt mit Totenschaedeln, diversen Knochen unbekannter "+
  "Herkunft und mit arkanen Zeichen bemalt. Ueber allem prangt wie Banner "+
  "das Symbol, welches schon ueber dem Gildengebaeude geprangt hat."));
  AddDetail(({"symbol"}),BS(
   "Das Symbol leuchtet, duester und doch majestaetisch, in "+
   "die Dunkelheit dieses Ganges. Es ist ein komplexes Symbol, in seinem "+
   "Zentrum der Schaedel eines Monsters, boesartig, mit Hauern versehen "+
   "und messerscharfen Zaehnen. Hinter ihm sind zwei gekreuzte Aexte auf"+  
   "gezeichnet. Es sind grosse, klobige Aexte mit einer Schneide, wie "+  
   "sie von Henkern genutzt werden. Und hinter diesen Aexten siehst Du "+
   "ein mit komplexen Mustern versehenes, rundes ... Objekt, vielleicht "+   
   "ein Schild."));
   AddDetail(({"schaedel","monster"}),BS("Der Schaedel des Monsters "+ 
   "ist vage humanoid, besitzt jedoch gewaltige, messerscharfe Hauer "+
   "und ebensolche Zaehne."));
   AddDetail(({"hauer","zaehne"}),BS("Die Zaehne des Monsters sind messer"+
   "scharf und sehen toedlich aus, insbesondere die zwei Hauer!"));   
   AddDetail(({"axt","aexte"}),BS("Es sind einschneidige, schwere Aexte. "+
   "Du hast sie schon oft gesehen. Meist in der Hand von Henkern."));
   AddDetail(({"henker"}),BS("Das sind diese Typen mit den schicken "+
   "schwarzen Kapuzen."));
   AddDetail(({"typen","kapuzen"}),BS("Die Typen in den schwarzen Kapuzen "+
   "sind Henker. Das musst Du Dir merken. Vermeide beruflichen Kontakt mit "+
   "ihnen."));
   AddDetail(({"kontakt"}),BS("Huuuh, so weit bin ich nicht nicht..."));
   AddDetail(({"muster"}),BS("Sie sind ineinander verschnoerkelt und sehr "+
   "verwirrend."));   
   AddDetail(({"objekt","schild"}),BS("Das Objekt koennte ein Schild sein. "+
   "Oder einfach ein Muster. Du weisst es nicht. Aber es macht Dich wuschig, "+
   "dieses Muster."));
   AddDetail(({"zentrum","mitte"}),BS("Das Zentrum ist die Mitte, und die Mitte "+
   "ist das Zentrum. Nur damit Du es weisst."));
  AddDetail(({"totenschaedel"}),BS("Ein gutes Dutzend Totenschaedel wurden "+
  "ueber diesem Durchgang angebracht und sehen aus wie eine Reihe stummer "+
  "Waechter, welche diesen Gang bewachen. Dir wird irgendwie mulmig."));
  AddDetail(({"reihe"}),BS("Die zwoelf Totenschaedel wurden in einer Reihe "+
  "angebracht."));
  AddDetail(({"waechter"}),BS("Naja, die Waechter sind tot, wenn man den "+
  "Totenschaedeln glauben darf."));
  AddDetail(({"knochen"}),BS("Ausser den Totenschaedeln wurden auch einige "+
  "Knochen am Durchgang angebracht und bilden eine Art Rahmen um den "+
  "Durchgang. Du kannst nicht sagen, von was fuer Wesen diese Knochen "+
  "gehoerten. Sie sind wirklich hoechst merkwuerdig."));
  AddDetail(({"art"}),BS(".... Hmpf ..."));
  AddDetail(({"rahmen"}),BS("Die Knochen bilden einen Rahmen fuer den "+
  "Durchgang."));
  AddDetail(({"abstaende"}),BS("Die Abstaende sind recht gross, deshalb "+
  "ist es in diesem Gang sehr dunkel."));
  AddDetail(({"banner"}),BS("Das Symbol leuchtet wie ein Banner in die "+
  "Dunkelheit des Gangs hinein."));
  AddDetail(({"burg"}),BS("Du befindest Dich unterhalb der chaotischen "+
  "Burg, der Burg des Chaos."));
  AddDetail(({"beispiel"}),BS("Als Beispiel hatte ich hier das Trampolin "+
  "angefuehrt."));
  AddDetail(({"dutzend"}),BS("12 sind ein Dutzend. Das weisst Du. Also "+
  "nerv nich."));
  AddDetail(({"fall"}),BS("Fall mir hier nicht hin :)"));
  AddDetail(({"gildengebaeude"}),BS("Es befindet sich irgendwo ueber Dir."));
  AddDetail(({"hand","haende"}),BS("Henker haben Haende. Das macht sie "+
  "so gefaehrlich."));
  AddDetail(({"herkunft"}),BS("Die Herkunft dieser merkwuerdigen Knochen "+
  "ist Dir unbekannt."));
  AddDetail(({"ideen"}),BS("Ja klaaar."));
  AddDetail(({"ork","orks"}),BS("Du hast schon einige getoetet."));
  AddDetail(({"problem"}),BS("Ja, mit Hobbits hat man eigentlich dauernd "+
  "Probleme. Sie sind wirklich schlimm."));
  AddDetail(({"loecher"}),BS("Die Loecher befinden sich uebrigens in den "+
  "Steinen."));
  AddDetail(({"schatten"}),BS("Wow! Da gluehen rote Augen in den Schatten!"));
  AddDetail(({"augen"}),BS("Jetzt sind sie weg. Du musst Dich verguggt haben."));
  AddDetail(({""}),BS(""));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  AddExit("nordosten",CHAOS_GILDEN_ROOM("cl3bu1"));
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl3bu3"));
  AddSpecialExit("suedosten","erzmeister");
}

int erzmeister() {
  if(this_player()->QueryProp(P_GUILD_LEVEL)==12||
     IS_WIZARD(this_player())) {
    this_player()->move(CHAOS_GILDEN_ROOM("daem_halle"),M_GO,"nach Suedosten");
    return 1;
  }
  write(BS("Du bewegst Dich auf den Durchgang zu, als sich ploetzlich die Wand "+
  "zu Dir hinwoelbt und Dich verschluckt."));
  say(BS(this_player()->Name(WER)+" wird von einer Wand verschluckt, als er "+
  "den Durchgang durchqueren will."),this_player());
  this_player()->move(CHAOS_GILDEN_ROOM("cl3_stein"),M_GO | M_SILENT);
  return 1;
}
 