#include "/gilden/files.chaos/gilde.h"

inherit "/gilden/chaos";


create() {
  ::create();
  new_chaos_rooms = 1;
  RemoveDetail(0);
  RemoveExit(0);
  RemoveItem(CHAOS_GILDEN_MON("hutschat"));
  SetProp( P_INT_LONG,break_string( 
  "Du befindest Dich in einem grossen, schwarzen Raum, fast einem Saal. "+
  "Fuenf grosse Feuer brennen lichterloh und markieren die Ecken eines "+
  "stilisierten blutroten Pentagramms, welches in den Boden eingelassen ist. "+
  "In der Mitte des Pentagramms haengt ein grosses Banner von der Decke "+
  "herab in den Raum und weht leicht im nicht vorhandenen Wind. Die Waende "+
  "sind bedeckt mit Waffen, Schilden und anderen Ruestungsteilen sowie "+
  "den Koepfen einiger erlegter Gegner. Blut bedeckt alle Waffen und "+
  "Ruestungen, auch bei den Koepfen hat sich niemand die Muehe gemacht, "+
  "sie kunstvoll zu drappieren oder zu saeubern. Alles sieht etwas verkommen "+
  "und dreckig aus.",78)+
  break_string("Eine Aura der Gewalt und des Boesen herrscht in diesem Raum.",78));
  AddDetail(({"gewalt","aura","boeses"}),break_string(
    "Eine Aura der Gewalt und des Boesen herrscht in diesem Raum.",78));
  AddDetail(({"raum","saal"}),break_string(
    "Dieser Raum ist wirklich gross. Hier versammeln sich die Krieger und "+
    "Kriegerinnen des Chaos, um ihre Siege zu feiern und ihre Plaene zu "+
    "schmieden. Hier residiert Kruuolq, der oberste Meister des Chaos, "+
    "welcher ueber diese Gilde herrscht. Dieser Saal ist das Zentrum der "+
    "Chaosgilde, dies ist ihr Mittelpunkt.",78));
  AddDetail(({"krieger","kriegerinnen","chaoten","chaot","chaotin"}),break_string(
    "Die Mitglieder der Chaosgilde sind die Chaoten. Sie sind die Krieger "+
    "und Kriegerinnen des Chaos, sie besitzen die Macht, welche das Chaos "+
    "mit sich bringt. Es sind boesartige, fiese Kreaturen der Dunkelheit, "+
    "mordende und brandschatzende Bestien, welche die Hoelle ihr Zuhause "+
    "nennen.",78));
  AddDetail(({"mitglieder"}),break_string(
    "Die Mitglieder der Chaosgilde sind die Chaoten.",78));
  AddDetail(({"muehe"}),break_string(
    "Hier mal sauber zu machen wuerde aber auch WIRKLICH VIEL Muehe machen.",78));
  AddDetail(({"macht","chaos"}),break_string(
    "Das Chaos besitzt gewaltige Macht. Es beherscht das Morgengrauen. "+
    "Es erfuellt es. Nichts kann sich mit ihm vergleichen. Beherscht "+
    "man das Chaos, so beherscht man die Welt. Das Chaos ist eine Macht, "+
    "welche die Ordnung zerstoert, eine gewaltige, zerstoererische "+
    "Macht. Nichts kann gegen sie bestehen.",78));
  AddDetail(({"morgengrauen","welt"}),break_string(
    "Diese Welt ist das Morgengrauen. Es ist eine grosse, weite Welt "+
    "voller Abenteuer und Ueberraschungen.",78));
  AddDetail(({"abenteuer","ueberraschungen"}),break_string(
    "Davon wirst Du in dieser Welt viele finden.",78));
  AddDetail(({"ordnung"}),break_string(
    "Ordnung und Chaos koennen nicht gleichzeitig bestehen. Das Chaos "+
    "strebt stets danach, die Ordnung zu zerstoeren. Und einst wird "+
    "das Chaos endgueltig siegen.",78));
  AddDetail(({"kreaturen","bestien"}),break_string(
    "Chaoten sind boesartig, fies und gemein. Sie sind ueberall auf der "+
    "Welt als fiese Kreaturen und boesartige Bestien verschrien und "+
    "sind auch noch stolz darauf.",78));
  AddDetail(({"hoelle","zuhause"}),break_string(
    "Die Krieger und Kriegerinnen des Chaos sind derart boesartige "+
    "Kreaturen, dass sie die Hoelle ihr Zuhause nennen wuerden. "+
    "Natuerlich sind sie dort nicht zuhause, denn sie leben hier, "+
    "im Morgengrauen. Hier leben und hier toeten sie.",78));
  AddDetail(({"siege","sieg"}),break_string(
    "Das Chaos wird letztendlich den Sieg ueber die Ordnung davontragen. "+
    "Nichts kann dies verhindern. Doch bis dahin ist noch viel zu tun, "+
    "und so werden auch die kleineren Siege hier gefeiert.",78));
  AddDetail(({"plaene"}),break_string(
    "Keine andere Gilde kann derart verruchte Plaene schmieden wie die "+
    "Chaosgilde. Kruuolqs Plaene sind derart teuflisch und durchtrieben, "+
    "das kaum jemand ueberhaupt in der Lage ist, sie zu verstehen.",78));
  AddDetail(({"lage"}),break_string(
    "Du bist sicherlich nicht in der Lage, Kruuolq's Plaene zu verstehen.",78));
  AddDetail(({"kruuolq","oberhaupt"}),break_string(
    "Kruuolq ist der oberste Meister des Chaos, das Oberhaupt dieser "+
    "verruchten Gilde. Nichts geschieht hier ohne ihn.",78));
  AddDetail(({"nichts"}),break_string(
    "Hiermit ist natuerlich nicht Nichts gemeint, sondern Nichts. Denn "+
    "selbst Nichts koennte das Chaos nicht aufhalten, denn Nichts kann "+
    "dies. Dies erwaehne ich nur, damit Nichts nicht falsch verstanden "+
    "wird, denn das moechte ich um Nichts in der Welt.",78));
  AddDetail(({"gilde","chaosgilde"}),break_string(
    "Dies hier ist das Zentrum der Chaosgilde. Die Chaosgilde ist eine "+
    "Gilde in dieser verruchten Welt, wie es keine zweite gibt. Sie ist "+
    "verrucht und verabscheuungswuerdig, schlecht und boshaft, gewalt"+
    "taetig und schlicht boese. Ihre Mitglieder sind die Krieger und "+
    "Kriegerinnen des Chaos, boesartige Kreaturen, welche ueber die "+
    "Macht des Chaos herrschen und es zu ihren dunklen Zwecken einsetzen. "+
    "Gedenkend alter Pakte besitzen die Chaoten Macht ueber maechtige "+
    "Daemonen, welche ihnen zu Diensten sind, falls die Chaoten stark "+
    "genug sind, diese zu kontrollieren. All dies macht Chaoten zu "+
    "sehr maechtigen, gefaehrlichen und boshaften Kreaturen. Chaoten "+
    "bringen den Tod und sterben fast ebenso schnell, wenn sie sich "+
    "nicht vorsehen, denn das Chaos ist gefaehrlich und die Daemonen "+
    "noch sehr viel mehr.",78));
  AddDetail(({"zwecke"}),break_string(
    "Das Chaos wird nur zu verruchten, boesartigen Zwecken eingesetzt. "+
    "Denn nur so wird das Chaos letztendlich wirklich herrschen.",78));
  AddDetail(({"tod","leben"}),break_string(
    "Der Tod ist einem Chaoten nicht fremd. Chaoten sterben sogar recht "+
    "haeufig, denn ihr Leben ist gefaehrlich und die Macht, mit welcher "+
    "sie ringen, vergibt nichts. Jeder noch so kleine Fehler wird von "+
    "den Daemonen oder dem Chaos mit dem Tode bestraft.",78));
  AddDetail(({"verwesung"}),break_string(
    "Es stinkt hier stark nach Verwesung.",78));
  AddDetail(({"fehler"}),break_string(
    "Chaoten machen Fehler. Deshalb sterben sie.",78));
  AddDetail(({"zentrum","mitte","mittelpunkt"}),break_string(
    "Dieser Saal ist das Zentrum, ist der zentrale Raum der Chaosgilde.",78));
  AddDetail(({"pakte"}),break_string(
    "Die Chaosgilde hat duestere Pakte mit dunklen Maechten geschlossen, "+
    "und dies schon vor langer Zeit. Diese Pakte geben ihnen die Macht "+
    "ueber finsterste, uebelste Daemonen.",78));
  AddDetail(({"zeit"}),break_string(
    "Oha. Schon so spaet.",78));
  AddDetail(({"maechte"}),break_string(
    "Diese Maechten waren derart boesartig, dass man sie hier nicht mehr "+
    "beschreiben sollte.",78));
  AddDetail(({"dienste"}),break_string(
    "Die Dienste der Daemonen sind vielfaeltig und sollen hier nicht "+
    "eingehender beschrieben werden, den sie gehoeren zu den Geheimnissen "+
    "dieser Gilde.",78));
  AddDetail(({"geheimnisse"}),break_string(
    "Diese Gilde besitzt viele, duestere Geheimnisse. Die werden jedoch "+
    "nicht verraten, denn sonst waehren es keine Geheimnisse mehr. Und das "+
    "waere eine ganz boese Sache.",78));
  AddDetail(({"sache"}),break_string(
    "Geheimnisse sind wichtig. Also lassen wir's jetzt erst mal bleiben "+
    "und verraten nichts.",78));
  AddDetail(({"daemonen"}),break_string(
    "Daemonen sind so ziemlich das Boesartigste und Teuflischste, was man "+
    "sich vorzustellen vermag. Sie sind Kreaturen aus fremden Dimensionen, "+
    "gebunden durch uralte Pakte, den Chaoten zu dienen. Doch sie sind "+
    "wild, voller Wut und Hass und begierig darauf, ihren Herren zu "+
    "toeten, zu zerfetzen und zu zerreissen, um dann auf ihm herumzutrampeln "+
    "und ihn zu schaenden.",78));
  AddDetail(({"herren"}),break_string(
    "Das war vielleicht falsch gesagt. Daemonen haben keine Herren, sie "+
    "werden hoechsten von gewissen Chaoten kontrolliert.",78));
  AddDetail(({"wut","hass"}),break_string(
     "Daemonen sind stets erfuellt von Wut und Hass. Es erfuellt sie, es "+
     "erhaelt sie. Sie SIND Wut, Hass und Agressivitaet.",78));
  AddDetail(({"dimensionen","kerkerdimensionen"}),break_string(
    "Daemonen sind Kreaturen, welche aus den finsteren Kerkerdimensionen "+
    "jenseits der Hoelle stammen. Ueber diese Dimensionen wird ob ihrer "+
    "unaussprechlichen Grausamkeit nun jedoch nichts weiter gesagt.",78));
  AddDetail(({"grausamkeit"}),break_string(
    "Grausamkeit ist einem Chaoten durchaus nicht fremd, doch die Grausam"+
    "keit der Kerkerdimensionen ist mit nichts zu vergleichen.",78));
  AddDetail(({"feuer"}),break_string(
    "Fuenf Feuer lodern hell und erleuchten die Dunkelheit dieses Saals. "+
    "Sie lodern auf steinernen Sockeln und scheinen ohne Holz oder Oel "+
    "zu brennen, wild und ungestuehm, als wuerden sie von einem Sturm "+
    "entfacht. Dies kann jedoch nicht sein, denn hier regt sich kein "+
    "Lueftchen.",78));
  AddDetail(({"sockel"}),break_string(
    "Die Sockel bestehen aus dreckigem schwarzen Marmor. Sie sind nicht "+
    "wirklich rund und scheinen mit primitivsten Werkzeugen geformt worden "+
    "zu sein.",78));
  AddDetail(({"marmor"}),break_string(
    "Der schwarze Marmor sieht recht dreckig aus, ist ansonsten jedoch "+
    "makellos.",78));
  AddDetail(({"werkzeuge"}),break_string(
    "Die Werkzeuge muessen aeusserst primitiv gewesen sein, um derart "+
    "schlecht gearbeitet zu haben. Oder man hat sich nicht wirklich "+
    "mit ihnen ausgekannt.",78));
  AddDetail(({"holz","oel"}),break_string(
    "Derartiges kannst Du hier nicht wirklich entdecken.",78));
  AddDetail(({"sturm","lueftchen"}),break_string(
    "Im Saal bewegt sich kein Lueftchen, alles ist still. Trotzdem brennen "+
    "die Feuer, als wuerden sie von einem gewaltigen Sturm angepeitscht. "+
    "Du kannst Dir das nicht erklaeren. Doch Du kannst Dir auch vieles "+
    "anderes hier nicht erklaeren, deshalb ist das ok.",78));
  AddDetail(({"ecken"}),break_string(
    "Fuenf hoch auflodernde Feuer bilden die Ecken des grossen, blutroten "+
    "Pentagramms, welches hier in den steinernen Fussboden eingelassen "+
    "wurde. Du fragst Dich, was es wohl mit diesem Pentagramm auf sich "+
    "hat.",78));
  AddDetail(({"pentagramm"}),break_string(
    "Das Pentagramm ist blutig rot. Es wurde nicht nur auf den Boden "+
    "gemalt, es wurde vertieft in den Steinboden eingelassen und bildet "+
    "somit ein Rinnensystem, in welchem der Boden aus dunkelrotem "+
    "Gestein besteht.",78));
  AddDetail(({"rinnen","rinnensystem"}),break_string(
    "Dir schauderts, als Du daran denkst, was hier wohl durchfliesst.",78));
  AddDetail(({"gestein"}),break_string(
    "Das Gestein ist blutrot, fuehlt sich ansonsten jedoch nicht anders "+
    "an als normales Gestein. Somit kannst Du nicht viel mehr darueber "+
    "sagen.",78));
  AddDetail(({"wind"}),break_string(
    "Hier herrscht kein Wind. Nicht das kleinste Lueftchen regt sich. "+
    "Trotzdem blaeht sich das Banner, als wuerde es von einem starken "+
    "Wind erfasst werden. Es ist ein erhebender Anblick, dieses Banner "+
    "dort zu sehen. Erhebend und erschreckend.",78));
  AddDetail(({"anblick"}),break_string(
    "Das Banner im Wind ist ein wirklich erhebender Anblick. Trotzdem "+
    "macht es Dir auf merkwuerdige Weise Angst.",78));
  AddDetail(({"weise"}),break_string(
    "Ich bin weise, ich weiss das.",78));
  AddDetail(({"angst"}),break_string(
    "Alles hier ist auf gewisse Weise sehr bedrohlich und aengstigend. "+
    "Hier werden Maechte beschworen, welche sicherlich besser nicht "+
    "beschworen werden sollten.",78));
  AddDetail(({"banner"}),break_string(
    "Das Banner ist schwarz und scheint recht dreckig zu sein. "+
    "Auf ihm ist ein reich verzierter, grosser "+
    "Schild abgebildet, auf dem zwei gekreuzte Aexte dargestellt sind. "+
    "Auf diesen Aexten wiederum ist ein boesartiger Totenschaedel mit "+
    "gewaltigen Reisszaehnen dargestellt. Das Banner flattert wild im "+
    "nicht vorhandenen Wind des Saals. Es strahlt eine grosse Aggressi"+
    "vitaet und einen grossen Hass aus.",78));
  AddDetail(({"schild"}),break_string(
    "Auf dem Banner ist ein grosser Schild abgebildet. Er ist mit allerlei "+
    "Verzierungen versehen, welche jedoch von den zwei Aexten ueberdeckt "+
    "werden, welche sich auf dem Schild kreuzen, sowie vom Totenschaedel, "+
    "welcher Dir darueber entgegengrinst.",78));
  AddDetail(({"verzierungen"}),break_string(
    "Die Verzierungen sind sehr fein und edel dargestellt. Dieses Banner "+
    "ist ein Meisterwerk. Du wirst das Gefuehl nicht los, dass Du dieses "+
    "Banner, dieses Schild kennen solltest. Du kommst jedoch nicht darauf, "+
    "woher...",78));
  AddDetail(({"meisterwerk"}),break_string(
    "Das Banner ist wahrlich ein Meisterwerk.",78));
  AddDetail(({"meister"}),break_string(
    "Du meinst sicherlich Kruuolq.",78));
  AddDetail(({"gefuehl"}),break_string(
    "Du hast dieses Banner, dieses Schild schon einmal gesehen. Aber wo? "+
    "Du kommst einfach nicht darauf.",78));
  AddDetail(({"aexte","henkersaexte"}),break_string(
    "Die Aexte sind zwei seinseitige Henkersaexte mit gewaltigen Blaettern, "+
    "welche schwer und brutal aussehen. Auch die Aexte sind, wie das "+
    "Schild, reich verziert und scheinen noch nicht benutzt worden zu "+
    "sein. Sie sehen trotzdem jedoch extrem gewalttaetig und brutal aus.",78));
  AddDetail(({"blaetter","axtblaetter"}),break_string(
    "Die Axtblaetter sind ueberdimensioniert, jedoch fein verziert mit "+
    "feinen Mustern. Dennoch sehen sie extrem scharf aus.",78));
  AddDetail(({"muster"}),break_string(
    "Die Muster sehen wirklich fein aus. Dies sind aeusserst edle Aexte.",78));
  AddDetail(({"totenschaedel"}),break_string(
    "Der Totenschaedel ist sicher nicht menschlich. Er scheint nicht mensch"+
    "lich zu sein mit seinen Hauern und Reisszaehnen. Boesartig grinsen "+
    "Dich seine leeren, toten Augenhoehlen an, und Dir wird ganz anders.",78));
  AddDetail(({"hauer"}),break_string(
    "Der Totenschaedel besitzt zwei voellig ueberdimensionierte Hauer, "+
    "welche fast bis zu seinen Augenhoehlen reichen. Sie sehen scharf und "+
    "extrem gefaehrlich aus.",78));
  AddDetail(({"augenhoehlen"}),break_string(
    "Die Augenhoehlen des Totenschaedels sind tot und leer. Nun, wenigstens "+
    "leuchten sie nicht in einem duesterem, daemonischen Rot. Man muss mit "+
    "dem zufrieden sein, was man hat.",78));
  AddDetail(({"reisszaehne"}),break_string(
    "Die Reisszaehne sehen gefaehrlich aus. Dieser Totenschaedel gehoert "+
    "einer mordenden, gewalttaetigen Bestie, obwohl er sonst recht mensch"+
    "lich aussieht. Du fragst Dich, wo er wohl herkommen mag.",78));
  AddDetail(({"bestie"}),break_string(
    "Verdammt, wessen Totenschaedel IST das?",78));
  AddDetail(({"burg"}),break_string(
    "Du befindest Dich hier in der gewaltigen, boesartigen, schwarzen "+
    "Burg, dem Heim der Chaosgilde!",78));
  AddDetail(({"heim"}),break_string(
    "Das Heim der Chaosgilde ist diese schwarze Burg, in der Du Dich bef"+
    "indest.",78));
  
  AddDetail(({"waffen"}),break_string(
    "Die Waende sind bedeckt mit alten, blutigen, boesartigen Waffen. Sie "+
    "haben sicher unzaehlige Schlachten erlebt und sich somit einen Platz "+
    "in diesem Saal verdient. Ausserdem sind sie jedoch allesamt ob ihres "+
    "Alters unbrauchbar geworden. Trotzdem erschrecken sie Dich noch immer, "+
    "denn sie sind allesamt mit Zacken, Dornen und anderen fiesen "+
    "Assecoires ausgestattet, welche Dich schlucken lassen.",78));
  AddDetail(({"dornen","zacken","assecoires","mordwerkzeuge"}),break_string(
    "Oh Hoelle. Das sind keine Waffen, das sind uebelste Mordwerkzeuge.",78));
  AddDetail(({"platz"}),break_string(
    "Es gibt in diesem Saal wirklich viel Platz.",78));
  AddDetail(({"alter"}),break_string(
    "Die Waffen an den Waenden sind allesamt alt und unbrauchbar. Man hat "+
    "sie anscheinend erst hier hergehaengt, als sie nicht mehr zum Toeten "+
    "geeignet waren.",78));
  AddDetail(({"toeten"}),break_string(
    "Das Toeten ist anscheinend sehr wichtig fuer diese boesartige Gilde.",78));
  AddDetail(({"schlachten"}),break_string(
    "Diese Waffen haben sicherlich schon viel mitgemacht. Du fragst Dich, "+
    "wie alt sie wohl sein moegen.",78));
  AddDetail(({"schilde"}),break_string(
    "Die Schilde an den Waenden sind ebenso alt und unbrauchbar wie die "+
    "Waffen, welche neben ihnen haengen. Du hast den Verdacht, dass es "+
    "keinen Sinn machen wuerde, neuere Waffen hierher zu haengen. "+
    "Sicherlich wuerde es Chaoten gewaltig freuen, ihre eigene Gilde "+
    "zu bestehlen und sich somit zu beweisen. Was fuer ein gemeiner Haufen.",78));
  AddDetail(({"verdacht"}),break_string(
    "Dein Verdacht war der, dass Chaoten ihre eigene Gilde bestehen wuerden.",78));
  AddDetail(({"sinn"}),break_string(
    "Da Chaoten selbst ihre eigene Gilde bestehlen wuerden, macht es keinen "+
    "Sinn, in der Gilde wertvolle Dinge auszustellen.",78));
  AddDetail(({"dinge"}),break_string(
    "Wertvolle Dinge halten sich hier nicht sehr lange. Das ist leider "+
    "wahr.",78));
  AddDetail(({"durchgaenge"}),break_string(
    "Sie fuehren nach Osten und Suedwesten.",78));
  AddDetail(({"haufen"}),break_string(
    "Diese Chaoten sind schon ein kranker und verrueckter Haufen.",78));
  AddDetail(({"koepfe"}),break_string(
    "Die Koepfe sind blutverkrustet und verwesen vor sich hin. Die meisten "+
    "von ihnen sind lediglich blanke Totenschaedel, welche Dich von den "+
    "Waenden aus anzustarren scheinen. Dir faellt etwas merkwuerdiges auf. "+
    "Manche Koepfe sehen exakt gleich aus, als haette man den gleichen "+
    "Gegner mehrmals getoetet und alle Koepfe zum Spott hier aufgehaengt. "+
    "Einige Koepfe glaubst Du noch zu erkennen. Diese armen Kerle, denkst "+
    "Du Dir.",78));
  AddDetail(({"gegner"}),break_string(
    "Als Chaot ist man niemals ohne Gegner, und wenn es die Oma ist, der "+
    "man ueber die Strasse helfen soll.",78));
  AddDetail(({"oma","strasse"}),break_string(
    "Ein Chaot wird der Oma natuerlich ueber die Strasse helfen, aber er "+
    "wird merhmals laufen muessen, um auch alles dorthin zu kriegen. Und "+
    "dann das Blut...",78));
  AddDetail(({"blut"}),break_string(
    "Blut ist hier ueberall zu finden. Die Waffen und Ruestungen sind mit "+
    "ihnen verschmiert, die Koepfe lassen es herabtropfen und in den Rinnen "+
    "des Pentagramms scheint es oefter zu fliessen. Es riecht sogar nach "+
    "Blut und Verwesung in diesem Saal.",78));
  AddDetail(({"ruestungen","ruestungsteile"}),break_string(
    "Die Ruestungen an den Waenden sind zu verbeult und loechrig, um noch "+
    "irgendwie nuetzlich zu sein. Sie sind dreckig und mit Blut bedeckt. "+
    "Es scheint jedoch mehr Waffen als Ruestungsteile an den Waenden zu "+
    "geben, was Dir zu denken gibt.",78));
  AddDetail(({"spott"}),break_string(
     "Du koenntest natuerlich ueber die armen Kerle spotten, deren Koepfe "+
     "hier an den Waenden haengen. Aber das waere nicht fein.",78));
  AddDetail(({"kerle"}),break_string(
     "Du erkennst Arkshat, den Mulai Orlon tir Tairngire, die Koepfe vierer "+
     "Engel, den Kopf Water Luh's und viele viele andere Koepfe.",78));
  AddDetail(({"kopf","arkshat","mulai","engel","water","water luh"}),break_string(
     "Der Kopf haengt zerfetzt an der Wand, blutbesudelt und tot, ohne "+
     "jeden Respekt, ohne jede Sorgfalt dort angenagelt. Dir wird ganz "+
     "anders.",78));
  AddDetail(({"respekt","sorgfalt"}),break_string(
     "Etwas derartiges suchst Du hier vergebens.",78));
  AddDetail(({"boden","fussboden","steinboden"}),break_string(
     "Dies ist ein schlichter Steinboden, dessen Steine nicht einmal schwarz "+
     "sind, sonder nur eine undefinierbar dreckig-dunkle Farbe besitzen. "+
     "Das ist bemerkenswert, denn man hat diese Steine sicherlich aus der "+
     "alten Gilde hierhergeschafft, um sie hier wieder zu verwenden. In den "+
     "Steinboden versenkt ist das dunkelrote Pentagramm, an dessen Ecken die "+
     "Feuer auf ihren Sockeln brennen, und irgendwo liegt auch eine dreckige, "+
     "schaebige Topliste.",78));
  AddDetail(({"steine"}),break_string(
     "Die Steine sind dreckig und schaebig und sehen derart anders aus als "+
     "die Steine dieser Burg, dass sie sicherlich aus der alten Gilde hierher "+
     "transportiert wurden. Sie sind jedoch nicht wirklich interessant.",78));
  AddDetail(({"alte gilde"}),break_string(
     "Sie befindet sich weit suedlich von hier.",78));
  AddDetail(({"farbe"}),break_string(
     "Die Farbe der Steine ist auf jeden Fall kein Schwarz. Sie ist irgend"+
     "etwas, welches jetzt nicht mehr zu identifizieren ist, doch es war nicht "+
     "schwarz, und das ist bemerkenswert.",78));
  AddDetail(({"schwarz"}),break_string(
     "SCHWARZ.",78));
  AddDetail(({ "liste", "topliste", "top-liste","beachtung" }),
     "Ueber diese Top-Liste sind schon viele Leute gelaufen. Sie scheint wenig\n"
     +"Beachtung zu finden.\n");
  AddDetail(({"leute"}),break_string(
     "Irgendwelche Leute latschen immer ueber die Topliste. Das ist nicht "+
     "gut.",78));
  AddDetail(({"wand","waende"}),break_string(
     "Die Waende sind bedeckt mit Ruestungen, Schilden und Waffen, welche "+
     "von den Siegen dieser Gilde berichten. Zwischen ihnen haengen die "+
     "Koepfe getoeteter Feinde blutverschmiert herab. Die Waende sind "+
     "dreckig und verkommen. Du dankst der herrschenden Dunkelheit, denn "+
     "sie verdeckt all dies. In der Finsternis kannst Du jedoch noch "+
     "immer zwei grosse Steintafeln erkennen, welche an einer der Waende "+
     "befestigt sind. Nach Osten und Suedwesten fuehren Durchgaenge in "+
     "den Waenden aus diesem Raum heraus.",78));
  AddDetail(({"feinde","feind"}),break_string(
     "Die Chaosgilde hat mehr Feinde als jede andere Gilde. Das kommt "+
     "jedoch groesstenteils daher, dass jeder fuer die Gilde ein Feind ist"+
     ", der nicht herkommt, all seine Besitztuemer abliefert und sich "+
     "auf hoechst amuesante Weise selbst umbringt. Dies ist prinzipiell "+
     "auch der Grund dafuer, dass die Chaosgilde so wenige Verbuendete "+
     "hat.",78));
  AddDetail(({"verbuendete","verbuendeten"}),break_string(
     "Die Chaosgilde besitzt, um das jetzt einmal ganz klar und offen zur "+
     "Sprache zu bringen, keinen einzigen Verbuendeten. Das ist erbaerm"+
     "lich, aber so ist es, und die Chaoten sind aeusserst stolz darauf.",78));
  AddDetail(({"sprache"}),break_string(
     "Du bist ihrer durchaus maechtig.",78));
  AddDetail(({"besitztuemer","gold"}),break_string(
     "Die Chaosgilde macht sich nicht sonderlich viel aus Besitztuemern. "+
     "Chaoten mit viel Gold verlieren es mit gewaltiger Geschwindigkeit "+
     "in der Chaoskneipe. Man glaubt garnicht, wieviel die saufen koennen.",78));
  AddDetail(({"geschwindigkeit"}),break_string(
     "Die Geschwindigkeit, mit der Chaoten ihr Gold versaufen koennen, ist "+
     "nichts weniger als phaenomenal.",78));
  AddDetail(({"chaoskneipe","ort"}),break_string(
     "Die Chaoskneipe ist der Ort, an dem Chaoten wirklich gluecklich sein "+
     "koennen. Mit einem Chaosbecher, unter guten Feinden, ja, da laesst "+
     "es sich gut leben und sterben.",78));
  AddDetail(({"chaosbecher"}),break_string(
     "Den wirklich guten richtigen Chaosbecher gibt es nur hier in der "+
     "Chaosgilde.",78));
  AddDetail(({"dunkelheit","finsternis","licht"}),break_string(
     "In diesem Saal herrscht eine schummrige Dunkelheit, erhellt von fuenf "+
     "Feuern, welche doch eigentlich sehr viel mehr Licht spenden muessten. "+
     "Dennoch legt sich die Dunkelheit wie ein duesterer Schleier ueber "+
     "alles und jeden und huellt diesen Saal in Finsternis. Nun, Du hast "+
     "nicht weniger erwartet, hier in der Chaosgilde.",78));
  AddDetail(({"schleier"}),break_string(
     "Die Dunkelheit senkt sich wie ein Schleier ueber alles und jeden.",78));
  AddDetail(({"decke"}),break_string(
     "Die Decke ist zu hoch, um sie in der Dunkelheit noch zu erkennen.",78));
  AddDetail(({"steintafeln","steintafel","tafeln","tafel"}),break_string(
     "Es sind zwei Steintafeln. Du kannst sie einzeln betrachten.",78));
  AddDetail(({"tafel 1","steintafel 1"}),break_string(
     "Auf dieser Tafel stehen die Namen aller Mitglieder der Gilde. Du "+
     "kannst sie lesen.",78));
  AddDetail(({"namen"}),break_string(
     "Sie stehen auf der ersten Steintafel.",78));
  AddReadDetail( ({"steintafel 1","tafel 1"}), "@@my_liste@@" );
  AddDetail(({"tafel 2","steintafel 2"}),break_string(
     "Auf dieser Tafel stehen die neuesten Aenderungen, die in der Gilde "+
     "vorgenommen wurden. Wow, Du kannst sie lesen!",78));
  AddDetail(({"aenderungen"}),break_string(
     "Du kannst sie auf diesem Zettel lesen!",78));
  AddDetail(({"aggressivitaet"}),break_string(
     "Dieser Raum ist angefuellt davon!",78));
  AddSmells(SENSE_DEFAULT,"Es riecht hier stark nach Blut und Verwesung. "+
  "Was fuer ein Gestank!\n");
  AddSmells(({"blut","verwesung","gestank"}),"Dieser Gestank ist noch "+
  "auszuhalten, aber schoen ist er nicht.\n");
  AddSounds(SENSE_DEFAULT,"Es ist still hier bis auf das leise Flattern "+
  "des Banners und das leise\nHeulen des nicht vorhandenen Windes.\n");
  AddSounds(({"banner","wind","geraeusche","flattern"}),
  "Diese Geraeusche sind wirklich sehr leise, kaum zu hoeren.\n");
  AddReadDetail( ({"tafel 2","steintafel 2"}), "@@my_zettel@@" );
  AddExit("osten",CHAOS_GILDEN_ROOM("cl2_challe"));
  AddExit("suedwesten",C_SWIFT_ROOM("cl2_hutschatraum"));
}