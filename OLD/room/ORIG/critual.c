
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include "gilde.h"

create()
{
	::create();

SetProp(P_INT_SHORT, "Der Beschwoerungsraum");
SetProp( P_INT_LONG,break_string(
  "Du befindest Dich nun in Wuqours Haus, in seinem Reich. Dieses Haus ist "+
  "boese, Du kannst es fuehlen. Waende, Decke und Boden sind von rostroter "+
  "Farbe. Dann und wann tritt ein Tropfen Blut aus der Wand aus und fliesst "+
  "sie langsam herab. Ueberall an den Waenden und der Decke befinden sich "+
  "magische Symbole, finstere Runen und maechtige Bannsprueche, welche "+
  "rot auf den dunkelroten Waenden leuchten. Der Boden jedoch ist eine glatte, "+
  "schwarze, leere Flaeche. Hier zeichnen Chaoten ihre Pentagramme und Bann"+
  "kreise, unter dem wachsamen und kritischen Augen von Wuqour und Igor. "+
  "Nach Westen fuehrt eine Tuer aus dem Haus, nach Sueden fuehrt ein Durchgang "+
  "tiefer in dieses Gebaeude herein.",78));
SetProp(P_LIGHT, 0);
SetProp( P_INDOORS, 1 );
AddDetail(({"wand","waende"}),break_string(
  "Die Waende sind von rostroter Farbe. Dann und wann tritt ein Tropfen "+
  "Blut aus einer der Waende und fliesst die Wand herab zu Boden. Dort "+
  "versickert er dann im glatten, festen Fussboden. Du kannst Dir das "+
  "nicht erklaeren. An den Waenden befinden sich auch leuchtende Symbole, "+
  "Runen und Bannsprueche, geschrieben in fremden Zeichen, welche Dir "+
  "bei naeherer Betrachtung Kopfschmerzen bereiten, da sie sich langsam, "+
  "aber sicher zu bewegen, zu veraendern scheinen. All diese Symbole "+
  "leuchten in einem tiefen Rot in die Finsternis dieses Raumes hinein. "+
  "Du bist Dir sicher, dass all dies in Blut geschrieben und gezeichnet "+
  "wurde. Durch die Macht der Zeichen und die chaotischen Energien dieses "+
  "Hauses jedoch wurde all dies zum Leuchten gebracht.",78));
AddDetail(({"durchgang"}),break_string(
  "Dieser merkwuerdige Durchgang fuehrt nach Sueden.",78));
AddDetail(({"sueden","westen"}),break_string(
  "Dort kannst Du hingehen!",78));
AddDetail(({"flaeche"}),break_string(
  "Der Boden dieses Raumes bildet eine einzige, zusammenhaengende, glatte "+
  "schwarze Flaeche. Wie merkwuerdig.",78));
AddDetail(({"symbole","runen"}),break_string(
  "Die Symbole und Runen sind Dir unverstaendlich, sie scheinen Dir jedoch "+
  "aeusserst maechtig und boesartig zu sein. Sie wurden in Blut an die "+
  "Waende gemalt, und ihre Macht laesst sie duester in die Finsternis "+
  "dieses Raumes leuchten.",78));
AddDetail(({"finsternis","dunkelheit","licht","leuchten"}),break_string(
  "Finsternis herrscht. Das einzige Licht stammt vom duesteren Leuchten "+
  "der Runen und Symbole an den Waenden. Ihr Licht reicht jedoch laengst "+
  "nicht aus, um wirklich etwas sehen zu koennen.",78));
AddDetail(({"zeichen"}),break_string(
  "Du kannst die Zeichen auf den Waenden nicht entziffern. Sie sind Dir "+
  "voellig fremd. Wuqour muss sie gezeichnet haben. Dieser Mann weiss "+
  "wirklich viel ueber das, was er tut.",78));
AddDetail(({"betrachtung","kopfschmerzen"}),break_string(
  "Die Betrachtung der Symbole und Runen an den Waenden verursacht bei Dir "+
  "starke Kopfschmerzen. Du weisst nicht warum, eventuell jedoch, weil "+
  "sich alles an diesen Symbolen langsam zu bewegen, ja zu veraendern "+
  "scheint.",78));
AddDetail(({"energie","energien"}),break_string(
  "Chaotische Energien, was es hier nicht alles gibt. Andererseits, wenn "+
  "es irgendwo in dieser Burg starke chaotische Energien gibt, dann gibt "+
  "es sie hier.",78));
AddDetail(({"augen"}),break_string(
  "Wuqours Augen sind scharf und vergeben nichts.",78));
AddDetail(({"bannsprueche"}),break_string(
  "Bannsprueche sind so etwas aehnliches wie Bannzauber, jedoch nicht "+
  "genau das gleiche.",78));
AddDetail(({"tod"}),break_string(
  "Der Tod scheint fast gegenwaertig in diesem Haus.",78));
AddDetail(({"teufel"}),break_string(
  "Du glaubst, dass er nicht fern ist. Nein, nicht fern...",78));
AddDetail(({"decke"}),break_string(
  "Die Decke ueber Dir hat die gleiche, rostrote Farbe wie die Waende. "+
  "Wenigstens fallen jedoch keine Blutstropfen von der Decke. Das waere "+
  "Dir naemlich wirklich unangenehm. Falls die rostbraune Farbe jedoch "+
  "wirklich die Farbe getrockneten Blutes ist, so fragst Du Dich, wie "+
  "derart viel Blut an die Decke kommen konnte. Du erschauerst.",78));
AddDetail(({"boden","fussboden"}),break_string(
  "Der Boden ist flach, glatt, makellos und schwarz. Er ist kalt und glatt "+
  "wie schwarzer Marmor, doch es ist kein schwarzer Marmor. Du weisst nicht, "+
  "was dies ist, doch dieser Boden eignet sich exzellent zum Zeichnen "+
  "von Pentagrammen oder Bannkreisen.",78));
AddDetail(({"marmor"}),break_string(
  "Der Boden besteht sicherlich nicht aus Marmor.",78));
AddDetail(({"zeichnen"}),break_string(
  "Genau, auf diesem Boden soll man Pentagramme zeichnen.",78));
AddDetail(({"raum","haus","gebaeude"}),break_string(
  "Dies ist das Haus von Wuqour, dem Meister der Rituale. Es ist sicherlich "+
  "das aussergewoehnlichste Gebaeude in dieser Burg. Schon von aussen sah "+
  "es aus, als ob es mit Blut uebergossen worden ist. Hier drinnen jedoch "+
  "scheint es so, als wuerden die Waende teilweise aus Blut bestehen. Immer "+
  "wieder treten kleine Blutstropfen aus den Waenden aus den Waenden aus und "+
  "fliessen herab zum Boden, wo sie einfach zu versickern scheinen. Du weisst "+
  "nicht, was hier geschieht, doch Wuqour ist sicherlich der maechtigste "+
  "aller Chaoten, und er hat hier anscheinend Dinge getan, welche Du "+
  "garnicht wissen moechtest.",78));
AddDetail(({"blutstropfen","tropfen"}),break_string(
  "Kleine Blutstropfen treten immer wieder aus der Wand aus und laufen an "+
  "ihr herab. Es scheint fast, als wuerde die Wand selber bluten. Du hast "+
  "so etwas noch nie gesehen, vermutest jedoch, dass es mit den Ritualen "+
  "zu tun hat, welche hier vollzogen werden. Wie schrecklich muessen sie "+
  "gewesen sein, um selbst die Waende zum Bluten zu bringen? Du weisst es "+
  "nicht.",78));
AddDetail(({"wuqour"}),break_string(
  "Wuqour ist der Meister der Rituale der Chaosgilde. Er ist ein aeusserst "+
  "maechtiger Mann. Wenn er dann und wann auch etwas zerstreut wirkt, so "+
  "liegt das daran, dass er derart satanisch ist, dass seine Denkweise "+
  "sich unglaublich von Deiner unterscheidet. Man darf Wuqour keinesfalls "+
  "unterschaetzen. Er erschuf, mit Hilfe von finstersten Maechten, welche "+
  "Kruuolq durch Pakte band, diese Burg und den Eisberg darum herum. Er "+
  "weiss alles, was in dieser Burg vor sich geht und ist der Waechter "+
  "ueber das Gleichgewicht dieser Burg. Ohne ihn wuerde diese Burg nicht "+
  "mehr lange existieren, denn nur er hat die Macht, diese Maechte unter den "+
  "tieferen Ebenen der Burg zu bannen und zu kontrollieren.",78));
AddDetail(({"dinge"}),break_string(
  "In dieser Burg, speziell in diesem Haus, gehen Dinge vor sich, welche "+
  "Du garnicht kennen moechtest. Denn es sind satanische, gottlose Dinge "+
  "von sicherlich unaussprechlicher Brutalitaet.",78));
AddDetail(({"brutalitaet"}),break_string(
  "Wuqour und Chaoten ueberhaupt sind fuer ihre Brutalitaet bekannt. Was "+
  "in diesem Gebaeude jedoch vor sich geht, wuerde jeden Chaoten erschauern "+
  "lassen.",78));
AddDetail(({"kruuolq"}),break_string(
  "Kruuolq ist in gewisser Weise der oberste Waechter dieser Gilde, ja.",78));
AddDetail(({"gleichgewicht"}),break_string(
  "Obwohl es sicher nicht so aussieht, herrscht in dieser Burg ein sehr em"+
  "pfindliches Gleichgewicht, eine Koexistenz der oberen Ebenen der Burg "+
  "mit dem, was unter den unteren Ebenen haust.",78));
AddDetail(({"koexistenz","raetsel"}),break_string(
  "Wie lange diese Koexistenz bestehen wird, ist Dir ein einziges Raetsel.",78));
AddDetail(({"denkweise","bahnen"}),break_string(
  "Du koenntest weder Kruuolqs noch Wuqours Denkweise jemals begreifen. "+
  "Die beiden denken in voellig anderen Bahnen als Du. Bei beiden ist die "+
  "Frage, in wie weit sie noch als menschlich zu bezeichnen sind, nicht "+
  "einfach zu beantworten.",78));
AddDetail(({"frage"}),break_string(
  "Die Frage, wie menschlich Kruuolq und Wuqour noch sind, ist nicht "+
  "wirklich einfach zu beantworten.",78));
AddDetail(({"eisberg"}),break_string(
  "Diese Burg befindet sich in einem gewaltigen, schwarzen Eisberg. Du "+
  "hast ihn ja gesehen, hast ihn betreten, um die Burg zu erreichen. "+
  "Solch ein Eisberg braucht Jahrtausende, um zu entstehen. Dieser hier "+
  "ist in wenigen Stunden entstanden, und er ist pechschwarz. Etwas "+
  "derart unnatuerliches hast Du noch nie gesehen.",78));
AddDetail(({"jahrtausende","zeit"}),break_string(
  "So ein Eisberg benoetigt schon eine verdammt "+
  "lange Zeit, um zu entstehen.",78));
AddDetail(({"stunden"}),break_string(
  "Wie konnte ein derartiger Eisberg nur so schnell entstehen?",78));
AddDetail(({"ebenen"}),break_string(
  "Kaum jemand weiss, was in den unteren Ebenen dieser Burg geschieht. "+
  "Kaum jemand will es ueberhaupt wissen, denn es sind boesartige, satanische "+
  "Dinge. Was jedoch UNTER diesen unteren Ebenen vor sich geht, dass weiss "+
  "niemand. Doch etwas geht dort vor. Noch sei jedoch nicht verraten, was.",78));
AddDetail(({"blut","lebenssaft"}),break_string(
  "Blut. Essenz des Lebens. Suesser Lebenssaft. Du kannst Dir nicht vorstel"+
  "len, wieviel in dieser Burg davon schon vergossen wurde, doch in diesem "+
  "Haus fliesst das Blut schon aus den Waenden heraus. Dir wird ganz anders. "+
  "Auch die rostrote Farbe der Waende erinnert sehr an getrocknetes Blut. "+
  "Du weisst nicht, welche Rituale hier abgehalten werden, doch sie schein"+
  "en dieses Haus veraendert zu haben, in etwas anderes, fremdes verwandelt "+
  "zu haben. Du bist Dir nicht sicher, aber es koennte sein, dass nur "+
  "Wuqours Anwesenheit Dich davor schuetzt, von den Waenden gefressen "+
  "zu werden.",78));
AddDetail(({"farbe","farben"}),break_string(
  "Die Farbe der Waende ist rostrot, dunkelrotes Blut fliesst an "+
  "ihnen herab. Diese ganzen Farben machen Dich ganz krank.",78));
AddDetail(({"anwesenheit"}),break_string(
  "Wenn Wuqour hier ist, kannst Du Dich einigermassen sicher fuehlen. Welch "+
  "eine Ironie.",78));
AddDetail(({"ironie"}),break_string(
  "Die Ironie hierbei ist, dass Wuqour wohl das gefaehrlichste ist, was Dir "+
  "in dieser Burg begegnen kann, wenn Du Dich nicht zu tief herunterwagst. "+
  "Und genau diese Kreatur garantiert hier Deine Sicherheit.",78));
AddDetail(({"sicherheit"}),break_string(
  "Natuerlich ist Sicherheit etwas sehr relatives, besonders hier in der "+
  "schwarzen Burg.",78));
AddDetail(({"chaosgilde","gilde"}),break_string(
  "Die Burg, in welcher Du Dich gerade befindest, ist die boesartige Chaos"+
  "gilde. Ihr oberster Meister ist Kruuolq, ein aeusserst boesartiger "+
  "und chaotischer Mann. Ihm zur Seite stehen Hutschat, der Verwalter des "+
  "Chaos, und Wuqour, der Meister der Rituale, sowie eine grosse Menge an "+
  "anderen Kreaturen. Die Chaosgilde beherrscht das Chaos, welches ihnen "+
  "grosse Macht gibt. Doch das Chaos ist eine Macht, welche die Ordnung "+
  "zerstoert, eine zerstoererische Macht, und so sind Chaoten boesartige, "+
  "satanische Geschoepfe der Finsternis. In diesem Haus vollfuehren die "+
  "Chaoten satanische Rituale, um Daemonen aus finsteren Kerkerdimensionen "+
  "zu rufen und an sich zu binden, auf dass sie ihnen zu Diensten sind.",78));
AddDetail(({"kruuolq"}),break_string(
  "Kruuolq ist der oberste Meister der Chaosgilde. Er leitet sie, zusammen "+
  "mit Hutschat, seinem erbaermlichen Schreiberling. Kruuolq ist ein "+
  "sehr maechtiger Chaot. Er weiss vielleicht nicht soviel darueber wie "+
  "Wuqour, doch er schloss die Pakte mit den Maechten, welche die Chaoten "+
  "Daemonen beschwoeren lassen, und er fuehrt die Gilde, plant und intrig"+
  "iert wie kaum ein zweiter. Kruuolq zu unterschaetzen ist sicherlich der "+
  "letzte Fehler, den man macht.",78));
AddDetail(({"menge"}),break_string(
  "In dieser Gilde arbeiten eine grosse Menge von Kreaturen, und die aller"+
  "meisten von ihnen tun dies nicht freiwillig. Die Chaoten sind sehr stolz "+
  "darauf, derart viele Kreaturen damit quaelen zu koennen, fuer sie zu "+
  "arbeiten.",78));
AddDetail(({"geschoepfe"}),break_string(
  "Chaoten sind abgrundtief boese Geschoepfe, Kreaturen der Finsternis, "+
  "blutruenstige Monster. Sie werden gemieden und verachtet, und sie sind "+
  "fuerchterlich stolz darauf.",78));
AddDetail(({"finsternis","dunkelheit","licht"}),break_string(
  "Tiefe Dunkelheit herrscht in diesem Raum. Lediglich die Symbole an den "+
  "Waenden leuchten dunkel vor sich hin. Dieser Raum ist somit passend "+
  "beleuchtet fuer das Ritual der Beschwoerung, welches hier abgehalten "+
  "werden soll. Er ist passend beleuchtet fuer die Chaoten, jene finsteren "+
  "Kreaturen, welche hier, in ihm, arbeiten wollen.",78));
AddDetail(({"mann","maenner"}),break_string(
  "Es gibt hier viele Maenner. Sei praeziser.",78));
AddDetail(({"seite"}),break_string(
  "Tatsaechlich stehen Kruuolq Hutschat und Wuqour nicht direkt zur Seite, "+
  "nein sie haben beide eigene Raeume. Diese sind natuerlich nicht so "+
  "beeindruckend wie der von Kruuolq, aber immerhin.",78));
AddDetail(({"raeume"}),break_string(
  "Sowohl Hutschat als auch Wuqour besitzen eigene Raeume hier in der Burg.",78));
AddDetail(({"rituale","ritual"}),break_string(
  "Wuqour ist der Meister der Rituale. Hier kann man unter seiner strengen "+
  "Aufsicht das Ritual durchfuehren, mit dem man einen Daemon beschwoert.",78));
AddDetail(({"aufsicht"}),break_string(
  "In diesem Haus fuehrt Wuqour die Aufsicht.",78));
AddDetail(({"schreiberling"}),break_string(
  "Damit ist Hutschat gemeint. Hehe.",78));
AddDetail(({"fehler","genie"}),break_string(
  "Kruuolq zu unterschaetzen ist ein Fehler, den man sich wirklich nicht "+
  "erlauben kann. Dieser Mann ist ein satanisches Genie.",78));
AddDetail(({"hutschat","einzigen","verwalter"}),break_string(
  "Ueber Hutschat sollte man nicht viel sagen. Er ist erbaermlich. Keiner "+
  "weiss, wie er hier ueberhaupt an die Gilde kam. Er ist ein jammerndes "+
  "Weichei. Naja, ziemlich. Andererseits ist er der einzige, welcher in "+
  "das Chaos dieser Gilde eine gewisse Ordnung bringen kann. Ausserdem "+
  "hat er bis heute ueberlebt, und das in dieser Gilde. Das ist eine "+
  "Leistung, welche ganz klar fuer ihn spricht. Vielleicht ist er ja doch "+
  "kein solcher Warmduscher, wie alle denken. Vielleicht ist er ja etwas "+
  "ganz anderes...",78));
AddDetail(({"weichei","warmduscher"}),break_string(
  "Ach, Du meinst sicher Hutschat.",78));
AddDetail(({"leistung"}),break_string(
  "Die grosse Leistung von Hutschat war, bis heute, umgeben von voellig "+
  "kaputten Chaoten, zu ueberleben.",78));
AddDetail(({"ordnung"}),break_string(
  "Hutschat ist wohl der Einzige, welcher in diese Gilde noch eine gewisse "+
  "Ordnung bringen kann. Wie er das macht, weiss aber keiner so genau.",78));
AddDetail(({"burg"}),break_string(
  "Du befindest Dich in der schwarzen Burg, der chaotischen Burg, der "+
  "Burg des Chaos, welche die satanische Chaosgilde beheimatet. Hier "+
  "leben die Chaoten, boesartige Kreaturen der Finsternis, welche Tod "+
  "und Verderben mit sich bringen. Dies ist Wuqours Haus, welches sich "+
  "im Innenhof der Burg befindet. Wenn Du mehr von der Burg sehen moechtest, "+
  "so schau Dich nur um! Doch sei gewarnt, denn was Du hier sehen wirst, "+
  "koennte Dich schockieren und entsetzen.",78));
AddDetail(({"chaoten","chaot","krieger","krieger des chaos"}),break_string(
  "Die Chaoten sind die Krieger des Chaos, die Mitglieder der satanischen "+
  "Chaosgilde. Chaoten sind boesartig, gemein und fies, sie leben um "+
  "zu toeten und zu zerstoeren. Sie beherrschen das Chaos, und was sich "+
  "ihnen entgegenstellt, werden sie entweder vernichten, oder es wird sie "+
  "vernichten. Chaoten fuerchten weder Tod noch Teufel, nein, dies sind "+
  "sogar ihre engsten Freunde. Nichts laesst sich mit einem Chaoten ver"+
  "gleichen.",78));
AddDetail(({"verderben"}),break_string(
  "Tod und Verderben sind fast gegenwaertig in diesem Raum. Du erschauerst.",78));
AddDetail(({"freunde"}),break_string(
  "Die engsten Freunde eines Chaoten sind Tod und Teufel. Es sind deshalb "+
  "die engsten Freunde, weil Chaoten keine anderen Freunde haben.",78));
AddDetail(({"futterplatz"}),break_string(
  "Du schauderst. Diese Welt als Futterplatz fuer eine gewaltige Daemonen-"+
  "Armee. Das darf nicht geschehen.",78));
AddDetail(({"armee","daemonen-armee"}),break_string(
  "Sie wartet schon seit Aeonen in den Kerkerdimensionen auf ihre Chance.",78));
AddDetail(({"chance"}),break_string(
  "Diese Chance wird sicherlich irgendwann kommen. Dir schaudert.",78));
AddDetail(({"mitglieder"}),break_string(
  "Die Mitglieder der Chaosgilde sind die Chaoten. Haeufig nennt man sie "+
  "auch die Krieger des Chaos, denn das sind sie. Boesartige und entsetz"+
  "liche Krieger, versessen auf das Blut ihrer Gegner.",78));
AddDetail(({"gegner"}),break_string(
  "Fuer einen Chaoten ist jeder ein Gegner, der nicht selbst ein Chaot "+
  "ist. Und manchmal gilt nicht einmal das.",78));
AddDetail(({"chaos"}),break_string(
  "Das Chaos ist eine gewaltige Macht. Sie erfuellt das MorgenGrauen, ist "+
  "ueberall, erfuellt es. Das Chaos ist maechtig und stark, unkontrollier"+
  "bar, stehts darauf aus, die Ordnung zu zerstoeren und sich so auszu"+
  "breiten. Warum Chaoten in der Lage sind, das Chaos zumindest teilweise "+
  "zu beherrschen, ist eines der vielen Geheimnisse dieser Gilde. Man "+
  "munkelt jedoch von unheiligen, grausamen Pakten, welche Kruuolq mit "+
  "finstersten Maechten geschlossen haben soll. Welcher Art diese Pakte "+
  "jedoch waren, ist jedoch voellig unklar.",78));
AddDetail(({"geheimnisse"}),break_string(
  "Die satanischen Geheimnisse der Chaosgilde werden nun natuerlich nicht "+
  "enthuellt. Wo kaemen wir da hin.",78));
AddDetail(({"gewissen"}),break_string(
  "GeWas?",78));
AddDetail(({"lage"}),break_string(
  "Chaoten sind in der Lage, die Maechte des Chaos zu kontrollieren, wenn "+
  "auch nicht vollstaendig. Wieso sie dazu in der Lage sind, ist jedoch "+
  "noch voellig ungeklaert.",78));
AddDetail(({"gewas"}),break_string(
  "GeWiSsen? Wie merkwuerdig. Das kann man sicher essen.",78));
AddDetail(({"igor"}),break_string(
  "Warum ist denn Igor nicht hier?",78));
AddDetail(({"innenhof"}),break_string(
  "Du erreichst den Innenhof, indem Du dieses Haus nach Westen verlaesst, "+
  "sozusagen durch die Tuer.",78));
AddDetail(({"morgengrauen","welt"}),break_string(
  "Diese Welt ist das MorgenGrauen. Sie ist flach und gross und bietet "+
  "unglaubliche Ueberraschungen. Es ist eine wirklich tolle Welt.",78));
AddDetail(({"ueberraschungen"}),break_string(
  "Das MorgenGrauen bietet wirklich Ueberraschungen jedweder Art.",78));
AddDetail(({"art"}),break_string(
  "Sei bloss artig!",78));
AddDetail(({"macht","maechte"}),break_string(
  "Wenn Chaoten von etwas besessen sind, dann ist es Macht. Der Wunsch, "+
  "sie zu besitzen beseelt sie, verfolgt sie, erfuellt sie. Sie schliessen "+
  "unsaegliche Pakte mit anderen, finstersten Maechten, um an sie zu ge"+
  "langen und wuerden alles tun, um sie zu behalten. Es sind boesartige, "+
  "satanische Kreaturen ohne Gewissen und ohne eine Spur von Reue.",78));
AddDetail(({"spur","reue"}),break_string(
  "Diese Chaoten besitzen nicht eine Spur von Reue.",78));
AddDetail(({"wunsch"}),break_string(
  "Der Wunsch nach Macht in einem Chaoten ist gewaltig, uebermaechtig.",78));
AddDetail(({"pakte"}),break_string(
  "Die Pakte, welche Chaoten schmieden, sind unsaeglich. Sie werden mit "+
  "Maechten in finstersten Kerkerdimensionen geschlossen, mit Maechten, "+
  "welche einzig und allein von Leid und Schmerzen leben und nichts anderes "+
  "wuenschen als endlich in diese Welt zu gelangen, um sie zu ihrem "+
  "Futterplatz zu machen. Die Pakte, welche Chaoten schmieden, sind "+
  "boesartig und unglaublich gefaehrlich. Sie koennten das Ende der "+
  "Welt bedeuten. Doch das kuemmert die Chaoten nicht in ihrem zerstoer"+
  "erischen Streben.",78));
AddDetail(({"streben"}),break_string(
  "Chaoten streben danach, dass das Chaos einst wahrlich herrschen wird.",78));
AddDetail(({"leid","schmerzen"}),break_string(
  "Die Maechte, welche in den Kerkerdimensionen nur darauf warten, diese "+
  "Welt zu ueberrennen, ernaehren sich von Leid und Schmerzen. Es wuerde "+
  "das Ende der Welt bedeuten, wenn sie es schaffen wuerden, ihre "+
  "Dimension zu verlassen.",78));
AddDetail(({"ende","wahnsinn"}),break_string(
  "Das Ende der Welt. Wow. Wahnsinn.",78));
AddDetail(({"welten","dimensionen","kerkerdimensionen","kerkerdimension"}),
  break_string(
  "Man weiss wenig, ausserhalb der Chaosgilde fast garnichts, ueber die "+
  "fremden Dimensionen jenseits dieser Welt, und ueber die Kerkerdimen"+
  "sionen weiss man noch weniger. Man weiss, aus ihnen stammen die "+
  "Daemonen, welche die Chaoten beschwoeren. Man weiss auch, in diesen "+
  "Dimensionen gibt es andere, sehr viel schlimmere Maechte, welche "+
  "seit Aeonen versuchen, die Barrieren zwischen den Dimensionen nieder"+
  " zu reissen und in diese Welt zu gelangen, um sie zu verwuesten und "+
  "sich an den Eingeborenen zu laben. Man weiss, die Chaosgilde, "+
  "repraesentiert durch ihren obersten Meister Kruuolq, hat geheime "+
  "Pakte mit einigen dieser Maechte geschlossen. Niemand weiss jedoch, "+
  "was dies fuer Pakte sind und was sie fuer das MorgenGrauen bedeuten "+
  "koennen.",78));
AddDetail(({"aeonen"}),break_string(
  "Wow. DAS ist lange.",78));
AddDetail(({"material"}),break_string(
  "Dieses Material ist wirklich komisch.",78));
AddDetail(({"daemonen","daemon"}),break_string(
  "Daemonen sind Monster, gewalttaetige Kreaturen, welche entstanden "+
  "sind aus purem Hass und Boshaftigkeit. Sie stammen aus unbekannten "+
  "Welten und werden unter anderem durch Chaoten in diese Welt gerufen, "+
  "um ihnen zu dienen. Doch diese Daemonen sind erfuellt von Hass und "+
  "Wut auf ihre Meister, ihre Beschwoerer. Sie wuerden nichts lieber tun, "+
  "als sie auf grausamste Weise zu quaelen und zu toeten. Doch die Chaoten "+
  "besitzen Macht ueber die Daemonen, welche sie beschworen haben, beson"+
  "ders, wenn sie sie mit einem maechtigen Pentagramm und einem ebensolchen "+
  "Bannkreis beschworen haben. So erhalten sie die Kontrolle und ihre "+
  "Daemonen muessen sich ihrem Willen beugen. In diesem Haus kann man "+
  "derartige Pentagramme und Bannkreise zeichnen, um sie von Kruuolq "+
  "schaetzen zu lassen und sie vielleicht von ihm mit einem Bannzauber "+
  "versehen zu lassen.",78));
AddDetail(({"wille"}),break_string(
  "Beschworene Daemonen muessen sich dem Willen ihrer Beschwoerer beugen.",78));
AddDetail(({"kreatur","kreaturen","monster"}),break_string(
  "Du meinst sicher die Daemonen. Oder die Chaoten. Hehe. Je nachdem.",78));
AddDetail(({"hass","boshaftigkeit","wut"}),break_string(
  "Daemonen sind erfuellt von Hass, Boshaftigkeit und Wut. Dies ist ihre "+
  "Essenz, ihr Wesen. Der Hass und die Wut auf alles Lebende ist das, "+
  "was sie definiert.",78));
AddDetail(({"essenz","wesen"}),break_string(
  "Was ist das Wesen oder die Essenz eines Daemons? Wut? Hass? "+
  "Unheiliges Protoplasma? Man weiss es nicht genau. Daemonen sind uns "+
  "voellig fremd. Selbst innerhalb der Chaosgilde weiss man nur wenig "+
  "ueber ihr Wesen, und ausserhalb weiss man noch viel weniger.",78));
AddDetail(({"protoplasma"}),break_string(
  "Darueber weiss ich nichts. Aber das Wort klingt gut, find ich.",78));
AddDetail(({"wort"}),break_string(
  "Das Wort war: Unheiliges Protoplasma.",78));
AddDetail(({"lebendes","leben"}),break_string(
  "Nun, Du lebst zum Beispiel. Und das ist richtig gut, denn sonst "+
  "waerst Du tot!",78));
AddDetail(({"beispiel"}),break_string(
  "Du warst das Beispiel. Du errinerst Dich sicherlich.",78));
AddDetail(({"meister","beschwoerer"}),break_string(
  "Die Chaoten sind die Beschwoerer ihrer Daemonen und somit auch ihre "+
  "Meister. Doch der beschworene Daemon wird dies nicht so einfach "+
  "hinnehmen und sich immer wieder zu befreien versuchen. Deshalb ist "+
  "es wichtig, dass ein Chaot stehts auf alles vorbereitet ist.",78));
AddDetail(({"weise"}),break_string(
  "Ja, ich bin weise. Ich bin froh, dass Du das auch so siehst wie ich.",78));
AddDetail(({"pentagramm","pentagramme"}),break_string(
  "Pentagramme sind wichtig fuer das Beschwoeren von Daemonen. Sie geben "+
  "dem Beschwoerer Macht ueber den Daemonen und zwingen den Daemonen, "+
  "sich dem Ruf des Beschwoerers zu fuegen und zu ihm zu kommen. Wirklich "+
  "maechtig wird ein Pentagramm jedoch erst durch denn Bannkreis, welcher "+
  "um ihn herum gezeichnet wird. Ein Pentagramm kann man mit besonderen "+
  "Materialien zeichnen, unter anderem mit Kreide. Um mit Kreide ein Pent"+
  "agramm zu zeichen, gibt es den Befehl 'zeichne pentagramm mit kreide'.",78));
AddDetail(({"befehl"}),break_string(
  "Der Befehl war 'zeichne pentagramm mit kreide'. Um ein so gezeichnetes "+
  "Pentagramm wieder zu verwischen, gibt es den Befehl 'wische pentagramm "+
  "weg'.",78));
AddDetail(({"ruf","beschwoerung","daemonenbeschwoerung"}),break_string(
  "Die Beschwoerung eines Daemonen ist vielfaeltig und mystisch. Sie "+
  "ist prinzipiell jedoch ein gewaltiger Ruf, welcher ueber die Barrieren "+
  "der Dimensionen hinausreicht, um einen Daemon in die Welt des Morgen"+
  "Grauens zu bringen. Natuerlich werden die maechtigeren Daemonen sich "+
  "aeusserst ungern dem Ruf eines kleinen Schnoesels fuegen, weshalb man "+
  "seinen Ruf mit einem Pentagramm und einem Bannkreis verstaerken sollte.",78));
AddDetail(({"schnoesel"}),break_string(
  "Natuerlich sind Chaoten keine Schnoesel. Wie konnte ich das nur sagen. "+
  "Pfui Pfui Pfui.",78));
AddDetail(({"barrieren"}),break_string(
  "Zwischen den Welten, zwischen den Dimensionen, besonders zwischen den "+
  "Kerkerdimensionen und dieser Welt liegen grosse, uralte Barrieren. "+
  "Kaum jemand weiss wirklich viel darueber, doch diese Barrieren sind "+
  "sehr wichtig, denn sie hindern die Kreaturen der Kerkerdimensionen daran, "+
  "unsere Welt zu ueberrennen und alles Leben auf ihr zu vernichten. "+
  "Diese Barrieren sind jedoch keineswegs starr, sie sind biegsam und "+
  "sie werden schwaecher. Nur deshalb ist es einem Chaoten moeglich, "+
  "ueber die Barrieren hinweg Daemonen zu beschwoeren.",78));
AddDetail(({"prinzip"}),break_string(
  "Das Prinzip ist immer aeusserst wichtig.",78));
AddDetail(({"bannkreis","bannkreise"}),break_string(
  "Bannkreise sind sicher ebenso wichtig wie Pentagramme, denn waehrend "+
  "ein Pentagramm dafuer sorgt, dass ein Daemon auch wirklich erscheint "+
  "(und keinen seiner aggressiven Verwandten vorbeischickt), sorgt ein "+
  "Bannkreis dafuer, dass er seinen Beschwoerer nicht angreift oder "+
  "sich gleich wieder in seine Kerkerdimension verzieht. Deshalb ist es "+
  "gerade bei Kampfdaemonen unglaublich wichtig, einem Daemon mit einem "+
  "guten Bannkreis und einem schoenen Bannzauber zu beschwoeren, welcher "+
  "diesen Bannkreis noch verstaerkt. Nur so wird man die Kontrolle ueber "+
  "seinen Daemon auch wirklich behalten.",78));
AddDetail(({"bannzauber"}),break_string(
  "Der Bannzauber ist maechtige chaotische Magie, welche Chaoten wirken "+
  "koennen. Sie verstaerkt einen bereits gezeichneten Bannkreis (und ein "+
  "bereits gezeichnetes Pentagramm), auf dass sie groessere Macht besitzen "+
  "und auch maechtigere Daemonen in ihre Schranken verweisen koennen als "+
  "normale Bannkreise, welche mit den gleichen Materialien gezeichnet "+
  "wurden.",78));
AddDetail(({"magie"}),break_string(
  "Chaoten beherrschen maechtige, chaotische Magie. Diese befaehigt sie "+
  "unter anderem zum Wirken von maechtigen Bannzaubern, um ihre Penta"+
  "gramme und Bannkreise zu verstaerken. Die Magie dazu fliesst ihnen "+
  "aus dem puren Chaos zu.",78));
AddDetail(({"schranken"}),break_string(
  "Es ist sehr schwierig, maechtige Daemonen in ihre Schranken zu verwe"+
  "isen. Dazu benoetigt man oft die Hilfe exzellenter Pentagramme und "+
  "Bannkreise.",78));
AddDetail(({"hilfe"}),break_string(
  "Um wirklich gefaehrliche Daemonen zu rufen und dies erfolgreich zu "+
  "tun, benoetigt man die Hilfe guter Pentagramme, Bannkreise, Bannzauber "+
  "sowie exzellenter Materialien.",78));
AddDetail(({"materialien","materialie"}),break_string(
  "Ueber die Materialien zur Daemonenbeschwoerung soll hier nicht uebermae"+
  "ssig viel verraten werden. Soviel sei jedoch gesagt: Es gibt schlechte "+
  "Materialien zum Zeichnen von Pentagrammen und gute Materialien dafuer. "+
  "Es gibt schlechte Materialien zum Zeichnen von Bannkreisen und gute "+
  "Materialien dafuer. Etwas, was wirklich gut fuer Pentagramme ist, "+
  "kann sehr schlecht fuer Bannkreise geeignet sein. Deshalb ist es immer "+
  "wichtig, sich die Materialien gut anzusehen, bevor man sie benutzt. "+
  "Kruftur weiss einiges ueber Materialien zu sagen, wenn man sie ihm "+
  "gibt. Es gibt auch Materialien, mit denen man bereits gezeichnete "+
  "Pentagramme bestuecken kann, um sie zu verbessern, wie zum Beispiel "+
  "schoene schwarze Kerzen. Darueber musst Du jedoch selber mehr herausfinden.",78));
AddDetail(({"kruftur","denkdaemon"}),break_string(
  "Kruftur ist ein Denkdaemon. Er weiss vieles ueber viele Dinge.",78));
AddDetail(({"kreide","kerze","kerzen"}),break_string(
  "So etwas sind moegliche Materialien fuer Pentagramme und Bannkreise!",78));
AddDetail(({"kontrolle"}),break_string(
  "Einen Daemon unter Kontrolle zu halten ist nicht leicht. Nur Chaoten "+
  "vermoegen dies wirklich zu tun.",78));
AddDetail(({"verwandte"}),break_string(
  "Daemonen haben laut einhelliger Meinungen eigentlich keine Verwandte, "+
  "da sie nicht geboren, sondern erschaffen werden. Dies ist jedoch noch "+
  "nicht zweifelsfrei erwiesen worden, und so koennen Autoren derartige "+
  "literarische Schnitzer verziehen werden.",78));
AddDetail(({"meinungen","meinung"}),break_string(
  "Ach, von denen gibt es so viele auf dieser Welt...",78));
AddDetail(({"autor","autoren"}),break_string(
  "Der fuer diesen Schnitzer verantwortliche Autor heisst Feuerwehr, aber "+
  "wie gesagt kann man ihm diesen Schnitzer vergeben, da nicht zweifels"+
  "frei erwiesen ist, dass es wirklich ein Schnitzer ist.",78));
AddDetail(({"feuerwehr"}),break_string(
  "Feuerwehr ist der Autor dieses Hauses. Zumindest zum groessten Teil.",78));
AddDetail(({"teil"}),break_string(
  "Der Teil ist wirklich gross, den Feuerwehr geschrieben hat.",78));
AddDetail(({"schnitzer"}),break_string(
  "Der hier angeprangerte Schnitzer war, dass die Autoren erwaehnt haben, "+
  "dass Daemonen aggressive Verwandte schicken koennte, obwohl Daemonen "+
  "laut einhelliger Meinung keine Verwandten haben, da sie nicht geboren "+
  "wurden, sondern erschaffen, und man fuer Verwandte dann doch geboren "+
  "worden sein muss. DA dies jedoch nicht eindeutig bewiesen ist und "+
  "ebenfalls von der jeweiligen Definition von Verwandtschaft abhaengt, "+
  "sollte man den Autoren diesen Schnitzer vergeben.",78));
AddDetail(({"verwandtschaft","definition"}),break_string(
  "Die Definition von Verwandtschaft ist noch immer recht strittig und "+
  "kontrovers, weshalb man hier nicht darueber diskutieren sollte.",78));
AddDetail(({"kampfdaemonen","kampfdaemon","dienstdaemonen"}),break_string(
  "Generell kann man die Daemonen, welche Chaoten beschwoeren, einteilen "+
  "in Dienstdaemonen, welche Dienste fuer den Beschwoerer erledigen, jedoch "+
  "nicht an seiner Seite kaempfen, und Kampfdaemonen, welche mit ihm gegen "+
  "alles kaempfen, was sich dem Beschwoerer in den Weg stellt. Kampfdaemonen "+
  "sind klar die gefaehrlicheren Daemonen, bei ihrer Beschwoerung ist deshalb "+
  "grosse Vorsicht geboten.",78));
AddDetail(({"dienste"}),break_string(
  "Die Dienste von Dienstdaemonen sind vielfaeltig und sollen hier nicht "+
  "weiter erlaeutert werden. Frag einfach mal rum, dann erfaehrst Du mehr "+
  "darueber. Es gibt auch eine grosse Bibliothek.",78));
AddDetail(({"bibliothek"}),break_string(
  "Die Bibliothek befindet sich ebenfalls hier in der Burg. Geh ruhig mal "+
  "hin, dort stehen wirklich interessante Dinge drinnen.",78));
AddDetail(({"umgang","vorsicht","voraussetzungen"}),break_string(
  "Beim Umgang mit Daemonen ist stets grosse Vorsicht angebracht. Eine gute "+
  "Ruestung und eine ebensolche Waffe sind Voraussetzungen fuer eine "+
  "Beschwoerung mit Ueberlebenschancen, besonders bei maechtigen Kampfdaem"+
  "onen.",78));
AddDetail(({"ueberlebenschancen"}),break_string(
  "Die Ueberlebenschancen fuer Chaoten sind traditionell sehr gering, doch "+
  "man muss sich ja nicht bewusst in den Tod stuerzen. Deshalb ist eine "+
  "gewisse Vorsicht durchaus angebracht, wenn man mit Daemonen hantiert.",78));
AddDetail(({"ruestung","waffe"}),break_string(
  "Wenn man einen maechtigen Daemon, besonders einen Kampfdaemon, beschwoert, "+
  "sollte man immer eine gute Waffe und eine tolle Ruestung angezogen "+
  "bzw. bereit zum zuecken haben, denn ganz sicher kann man nie wissen, ob "+
  "ein Daemon nun gehorchen wird oder nicht.",78));
AddDetail(({"weg"}),break_string(
  "Was sich einem Chaoten mit einem Kampfdaemon in den Weg stellt, sollte "+
  "wirklich stark sein, denn sonst ist er bald ziemlich tot. Das war jetzt "+
  "ein bisschen ueberzogen dargestellt, aber etwas Werbung muss ja auch "+
  "mal sein.",78));
AddDetail(({"werbung"}),break_string(
  "C H A O S    R U L E Z ! ! !  Kommt in die Chaosgilde!",78));
AddDetail(({"nichts","niemand"}),break_string(
  "Hehe. Bleiben wir mal realistisch hier.",78));
AddSounds(SENSE_DEFAULT,"Es herrscht eine unheimliche, boesartige Stille.\n");
AddSmells(({"blut",SENSE_DEFAULT}),"Es riecht hier stark nach Blut.\n");

AddSpecialDetail(({"tuer"}),"det_tuer");

AddItem( CHAOS_GILDEN_MON( "wuqour"), REFRESH_REMOVE,
         (["chaos_NeueGilde":1]));
AddItem( C_112_MON( "cl2_igor"),REFRESH_REMOVE,
         (["chaos_guard":"sueden",
           "chaos_guard_money":1000,
           "chaos_guard_chaos":1,
            "chaos_guard_msg":"Igor fluestert: Zu diesem Raum hast Du "+
                              "keinen Zutritt. Verpiss Dich.\n"]));

AddSpecialExit( "sueden", "ex_sueden");
AddCmd( "westen", "ex_westen");    
AddCmd(({"oeffne"}),"open");
AddCmd(({"schliess","schliesse"}),"close");

}


int ex_sueden() {
  if (this_player()->QueryProp("chaos_behandlung") &&
      present("wuqour",this_object()))
      return write("Du kannst Dich nicht bewegen. Wuqour behandelt Dich gerade.\n"),1;
  this_player()->move(C_112_ROOM("cl2_cbeh1"),M_GO,"nach Sueden");
  return 1;
}

string det_tuer()
{
    return break_string(
    "Die Tuer besteht aus dem gleichen, pechschwarzen und makell"+
    "osen Material, welches Du hier ueberall als Tuer findest. Die Tuer "+
    "ist uebrigens gerade "+(
     call_other(C_112_ROOM("cl2bu6"),"querydoor")==0?
     "geschlossen":"geoeffnet")+".",78);
}

string GetExits(object ob) {
  if (!call_other(C_112_ROOM("cl2bu6"),"querydoor")) 
    return "Es gibt einen sichtbaren Ausgang: sueden.\n";
  return "Es gibt zwei sichtbare Ausgaenge: westen und sueden.\n";
}

int ex_westen()
{
  if (this_player()->QueryProp("chaos_behandlung") &&
      present("wuqour",this_object()))
      return write("Du kannst Dich nicht bewegen. Wuqour behandelt Dich gerade.\n"),1;
  if (!call_other(C_112_ROOM("cl2bu6"),"querydoor"))
  {
     write("Du knallst gegen die geschlossene Tuer.\n");
     say(this_player()->Name(WER)+" rennt gegen die geschlossene Tuer.\n",this_player());
     return 1;
  }
  this_player()->move(C_112_ROOM("cl2bu6"),M_GO,"nach Westen");
  return 1;
} 

int open(string was)
{  
   notify_fail("Was moechtest Du denn oeffnen?\n");
   if (was != "tuer") return 0;
   
   if (!call_other(C_112_ROOM("cl2bu6"),"opendoor"))
   {
     write("Aber die Tuer ist schon geoeffnet...\n");
     return 1;
   }
   write("Du oeffnest eine Tuer.\n");
   say(this_player()->Name(WER)+" oeffnet eine Tuer.\n",this_player());
   return 1;
}  

int close(string was)
{  
   notify_fail("Was moechtest Du denn schliessen?\n");
   if (was != "tuer") return 0;

   if (!call_other(C_112_ROOM("cl2bu6"),"closedoor"))
   {
     write("Aber die Tuer ist schon gescholossen...\n");
     return 1;
   }
   write("Du schliesst eine Tuer.\n");
   say(this_player()->Name(WER)+" schliesst eine Tuer.\n",this_player());
   return 1;
}  
