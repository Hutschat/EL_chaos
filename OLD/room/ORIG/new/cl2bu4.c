#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

inherit CHAOS_GILDEN_ROOM("cl2bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu6"));
  SetProp(P_LIGHT,0);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Innerhalb der chaotischen Burg");
  SetProp(P_INT_LONG,BS(
  "Du befindest Dich in einer sehr dunklen Gasse, und wenn es irgendeine "+
  "Gerechtigkeit auf dieser Welt gibt, dann sollte jetzt ein mit einem "+
  "Dolch bewaffneter Moerder aus einer finstren Ecke springen, denn dieser "+
  "Ort ist geradezu perfekt dafuer geeignet. Vor Dir befindet sich ein "+
  "duesteres Gebaeude ueber dessen dunkler, geradezu schattenhafter Tuer "+
  "ein duesteres Symbol gemalt wurde. Das kannst Du aber auch erst "+
  "erkennen, als Du Dich direkt davor begeben hast. Die Finsternis ist "+
  "noch immer vollstaendig und beschraenkt deine Sicht auf .. nun, so "+
  "gut wie garnichts. Du erkennst aber noch ein weiteres, grosses Gebaeude "+
  "oestlich von Dir und ein grosses Gebaeude suedlich von Dir. Wow, wer "+
  "hier wohl alles lebt... Im Suedosten siehst Du nichts mehr, dort scheint "+
  "sich wohl ein groesserer Platz zu befinden."));
  AddDetail(({"boden"}),BS("Der Boden ist mit pechschwarzen, fast nahtlos "+
  "aneinanderliegenden Pflastersteinen bedeckt. Sie sind derart schwarz, "+
  "dass Du in dieser blutenden Finsternis das Gefuehl bekommt, in einer "+
  "bodenlosen Schwaerze zu wandeln, mit nichts, was Dich hier halten "+
  "koennte. Gluecklicherweise ist dem nicht so."));
  AddDetail(({"pflastersteine"}),BS("Sie sind pechschwarz, steinhart und "+
  "haben keine anderen Eigenschaften, welche Dich in irgendeiner Weise "+
  "interessieren koennten."));
  AddDetail(({"eigenschaften"}),BS("Du hast hoffentlich jede Menge boese "+
  "Eigenschaften!"));
  AddDetail(({"boese eigenschaften"}),BS("Ich hoffe Du trinkst?"));
  AddDetail(({"weise"}),BS("Du bist nicht weise. Ha! Da koennte ja jeder "+
  "kommen."));
  AddDetail(({"gefuehl","gefuehle"}),BS("Huuuuuuuuuuh *shiver*."));
  AddDetail(({"schwaerze"}),BS("Waaaaaaah, Verdammt, Du siehst keinen "+
  "Boden!"));
  AddDetail(({"glueck"}),BS("Tja, Glueck muss man haben!"));
  AddDetail(({"finsternis","dunkelheit","licht"}),BS("Es ist wirklich total "+
  "finster hier. Aber Du weisst jetzt, dass diese Finsternis nicht natuer"+
  "lichen Ursprungs ist. Das kann sie nicht sein. So etwas ist ein Werk "+
  "dunkler Maechte."));
  AddDetail(({"ursprung"}),BS("Der Ursprung dieser Dunkelheit ist Dir "+
  "nicht bekannt, doch Du tippst auf einen verruchten Pakt von Kruuolq mit "+
  "Maechten der Finsternis."));
  AddDetail(({"pakt"}),BS("Welch unheilige Pakte Kruuolq in seinem Dasein "+
  "schon alle eingegangen ist, weiss nur Hutschat."));
  AddDetail(({"kruuolq"}),BS("Kruuolq ist das Oberhaupt der Chaosgilde. "+
  "Ein ganz ganz boeser Mann. Wirklich."));
  AddDetail(({"mann"}),BS("Du meinst wohl Kruuolq."));
  AddDetail(({"hutschat"}),BS("Hutschat ist fuer die Buchfuehrung zustaendig."));
  AddDetail(({"buchfuehrung"}),BS("Auch in einer Chaosgilde muss es "+
  "eine gewisse Ordnung .... aeh. Warte mal. Was. .... Wer? Wieso? "+
  "Was geht in dieser Gilde VOR????"));
  AddDetail(({"gilde","chaosgilde"}),BS("Die Chaosgilde ist die moerder"+
  "ischste Gilde, die unheiligste und fieseste, die absolut abstossendste "+
  "und fuerchterlichste Gilde, die Du Dir vorstellen kannst. Nur die "+
  "ganz Harten und Boesen koennen in ihr bestehen."));
  AddDetail(({"harte","boese"}),BS("Man muss wirklich hart und absolut "+
  "boesartig sein, um in die Chaosgilde zu kommen."));
  AddDetail(({"wand","waende"}),BS("Du befindest Dich in einer fuerchter"+
  "lich dunklen Gasse und wirst eingerahmt von der Hauswand mit der "+
  "Tuer im Norden und der Hauswand ohne Tuer im Sueden. Ausserdem gibt "+
  "es im Osten auch noch ein grosses Gebaeude mit einer Hauswand. Es gibt "+
  "somit genug Hauswaende fuer alle!"));
  AddDetail(({"alle"}),BS("Alle rufen: Huurraaaaaayyyyyy!!!"));
  AddDetail(({"hauswand","hauswaende"}),BS("Ok, machen wirs fuer Dich "+
  "noch etwas einfacher. Es gibt eine noerdliche Hauswand, eine oestliche "+
  "und eine suedliche Hauswand."));
  AddDetail(({"noerdliche hauswand"}),BS("Ah, eine gute Wahl. Die noerd"+
  "liche Hauswand besitzt naemlich, im Gegensatz zu den anderen beiden "+
  "Hauswaenden, eine Tuer! Und ueber dieser Tuer wurde eine Zeichnung "+
  "angebracht, welche Du in dieser verdammten Dunkelheit garnicht richtig "+
  "erkennen kann. Abgesehen davon ist die Wand aber ebenso trostlos wie "+
  "die beiden anderen mit ihren mehr als oeden pechschwarzen Ziegelsteinen. "+
  "Seufz. Was einst gar satanisch und furchterregend war, ist nun "+
  "nurnoch oede."));
  AddDetail(({"gegensatz","gegensaetze"}),BS("Gegensaetze ziehen sich an! "+
  "Das hab ich auf jeden Fall mal wo gehoert."));
  AddDetail(({"fall"}),BS("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHH!"));
  AddDetail(({"zeichnung"}),break_string("\bDu betrachtest die Zeichnung von gaaanz "+
  "nah und erkennst folgendes: Die Zeichnung stellt einen grossen, "+
  "hoelzernen Galgen dar, an dem erhaengt eine menschliche Gestalt baumelt. "+
  "An der gewaltigen Ansammlung krank aussehender Waffen und dem leicht "+
  "duemmlichen (owohl toten) Gesichtsausdruck erkennst Du zweifelsfrei, "+
  "dass dies ein Kaempfer sein muss!",78,0,1));
  AddDetail(({"galgen"}),BS("Er sieht sehr stabil aus. Das muss er auch "+
  "sein, denn dieser komische Kaempfer traegt eine unmenge Schrott mit "+
  "sich rum!"));
  AddDetail(({"gestalt","kaempfer","mensch","kerl"}),BS("Sieht sieht irgendwie "+
  "tot aus. Und ausserdem so, als haetten ihr all ihre Waffen nichts "+
  "genuetzt... Aber naja, so sind Kaempfer nun mal."));
  AddDetail(({"waffen","schrott"}),BS("*Lach* Was der alles dabei hat! "+
  "Wahnsinn!"));
  AddDetail(({"wahnsinn"}),BS("Hihihihihiiiii!!!"));
  AddDetail(({"ausdruck","gesichtsausdruck","gesicht"}),BS("Du drueckst "+
  "Dein Gesicht aus. AAAAAAH! Aehm, nein, falsch. Es ging ja um den "+
  "Kaempfer. Und, ja, der Kaempfer hat eine leeeeeeeeeicht duemmlichen "+
  "Gesichtsausdruck. Aber das muss man ihm nachsehen. Der arme Kerl hatte "+
  "wohl einen Kopfstoss zuviel verteilt. So ist das halt bei den Kaempfern."));
  AddDetail(({"kopfstoss"}),BS("Die gehen irgendwann aufs Gehirn, glaub mir."));
  AddDetail(({"gehirn"}),break_string(
  "\bI can't figure out an Attack-Plan until I get "+
  "my brain back in.\nDit anybody step on it?\n"+
  "Das ist ein Zitat aus der Violator-Miniserie von Image Comics, welche "+
  "die lustige Geschichte des Daemons Violator erzaehlt. Nur zu empfehlen :)"
  ,78,0,1));
  AddDetail(({"zitat","violator","image","comics","daemon"}),
  BS("Wer Comics mag, sollte sich diese Miniserie besorgen. Obwohl sie "+
  "auf Grund von Seltenheitswert stark im Preis gestiegen ist. Aber sie "+
  "ist absolut bahnbrechend witzig :)"));
  AddDetail(({"grund","seltenheitswert","preis"}),BS("Das beschreib ich nich."));
  AddDetail(({"oestliche hauswand"}),BS("Die oestliche Hauswand ist "+
  "derartig dunkel und oede, dass Du sie einfach nicht untersuchst. "+
  "Langsam reichts."));
  AddDetail(({"suedliche hauswand"}),BS("Sie ist da, und mehr interessiert "+
  "Dich im Moment wirklich nicht darueber. Die Haeuser hier sind absolut "+
  "ekelhaft eintoenig."));
  AddDetail(({"haeuser","gebaeude"}),BS("Es gibt jede Menge Haeuser hier!"));
  AddDetail(({"gasse"}),BS("So eine schmale, dunkle Gasse sieht man selten "+
  "(schliesslich ist es so dunkel, har har). Jedenfalls fuehrt sie nach "+
  "Nordwesten und nach Suedosten. Im Suedosten scheint sich ein "+
  "groesserer Platz zu befinden. Auf jeden Fall kann man dort nichts "+
  "sehen als Dunkelheit."));
  AddDetail(({"gerechtigkeit"}),BS("Haha! Gerechtigkeit kannst Du HIER "+
  "wirklich nicht erwarten. Und das ist eigentlich ganz gut, denn sonst "+
  "haette Dich laengst dieser ominoese bedolchte Moerder ermeuchelt..."));
  AddDetail(({"moerder"}),BS("Wo ist er? Wo Wo? Welche Ecke? Wo?"));
  AddDetail(({"ecke","ecken"}),BS("Finstere Ecken gibt es hier ueberall. "+
  "Vielleicht versteckt sich ein Moerder hinter einem der Haeuser, oder "+
  "dort, zwischen dem noerdlichen und oestlichen Haus, oder ... Ueber Dir??? "+
  "AAAAAAAAAAAAAHHHHHHHHH!"));
  AddDetail(({"dolch"}),BS("Dolche werden von Moerdern bevorzugt. Sie sind "+
  "klein, toedlich und gut zu verbergen. Es ist immer gut, einen dabei zu "+
  "haben."));
  AddDetail(({"ort"}),BS("Du befindest Dich in der chaotischen Burg, dem "+
  "Sitz der gewaltigen, boshaften und satanischen Chaosgilde! Aber das "+
  "wusstest Du, nicht?"));
  AddSpecialDetail(({"chaos"}),"chaos");
  AddDetail(({"burg"}),BS("Diese fuerchterlich finstere, geradezu pechschwar"+
  "ze Burg steht mitten in einer gewaltigen Hoehle innerhalb eines schwar"+
  "zen Eisbergs. Dies ist ein passender Ort fuer die boesartigste Gilde "+
  "diesseits der Hoelle, naemlich der Chaosgilde."));
  AddDetail(({"hoelle"}),BS("Dies ist nicht die Hoelle. Doch  man kann sie "+
  "von hier aus sehen... (das war ein Zitat? Wer weiss woher, kann mir ja "+
  "mal mailen :-)) (wer bin ich? Huch!)"));
  AddDetail(({"zitat"}),BS("Pfffffffffffffffffffffffff."));
  AddDetail(({"gebaeude"}),BS("Du kannst hier mehrere Gebaeude erkennen. "+
  "Nun ja, um ehrlich zu sein, erkennst Du lediglich einige Hauswaende."));
  AddDetail(({"symbol"}),BS("Naja, es ist eigentlich kein Symbol, sondern "+
  "eher eine Zeichnung."));
  AddDetail(({"schatten"}),BS("Diese Gasse ist voller Schatten. Es scheint "+
  "fast so, als haetten sich jede Menge Schatten hier zusammengefunden "+
  "und wuerden eine riesen Party feiern..."));
  AddDetail(({"party"}),BS("*seufz* Ja, ich haette auch gern ne Party. "+
  "Aber noeeee, ich sitz hier und progge. *seuuuuuuuuufz*."));
  AddDetail(({"menge"}),BS("JEDE Menge!"));
  AddDetail(({"sicht"}),BS("Die Sicht scheint sich hier auf einiges unter "+
  "null zu reduzieren. Wow. Das sowas ueberhaupt geht..."));
  AddDetail(({"platz"}),BS("Den kannst Du noch nicht sehen."));
  
  AddSmells(SENSE_DEFAULT,BS("Hier riecht es nicht schlimmer als anderswo."));
  AddSounds(SENSE_DEFAULT,BS("Es ist totenstill hier."));
  
  AddExit("westen",CHAOS_GILDEN_ROOM("cl2bu3"));
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl2bu5"));
  
  NewDoor("norden",CHAOS_GILDEN_ROOM("cl2_wlager"),({"tuer"}),
  ({D_NAME,"Tuer",
    D_GENDER,2,
    D_SHORT,"Die %se Tuer ist in der Finsternis kaum zu erkennen",
    D_LONG,BS("Diese Tuer ist wirklich nur als Schatten zu erkennen. "+
    "Aber im Grunde interessierst Du Dich auch nicht fuer die Tuer, "+
    "sondern fuer das, was sich dahinter befindet..."),
    D_FLAGS,DOOR_CLOSED | DOOR_RESET_CL
  }));
  
 AddCmd(({"sag","ja","nein"}),"janein");
 AddCmd(({"komm","komme"}),"igitt");
 
}


int janein(string was) {
   if (!was) was = query_verb();
   if (was == "ja")
     write("Sehr schoen. So will ich das sehen. Gute"+
     ((this_player()->QueryProp(P_GENDER)==2)?"s Maedchen":"r Junge")+
     ".\n");
   if (was == "nein")
     write("NEIN? Na, also, "+this_player()->Name(WER)+", ich bin schon "+
     "etwas enttaeuscht.\n");
   return 0;
}

int igitt(string was) {
   write("IGITT! BAEEEEEH! FERKEL!\n");
   return 1;
}


string chaos()
{
   this_player()->command_me("rufe CHAOS! CHAOS! CHAOS! HAIL CHAOS HAIL!");
   return "";
}