#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)

mapping infos;

void AddInfo(string *str1,string str2,string str3)
{
  int i;
  for(i=sizeof(str1)-1;i>=0;i--)
   if (!member(infos,str1[i]))
      infos+=([str1[i]:({str2,str3})]);
}


create() {
  ::create();
  infos=([]);
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"An einer Weggabelung");
  SetProp(P_INT_LONG,break_string
  ("\bDies ist eine Weggabelung. Der kiesbestreute Pfad gabelt sich hier "+
  "und fuehrt nach Sueden, nach Nordwesten und nach Nordosten in die "+
  "Dunkelheit hinein. Oestlich der Gabelung liegt ein kleiner Teich mit "+
  "dieser gruenen Fluessigkeit, welche hier wohl in allen Seen und Teichen "+
  "zu finden ist. Im Zentrum der Weggabelung wurde ein Pfahl eingerammt, "+
  "welcher wohl knappe zwei Meter aus dem Boden ragt. Auf diesem angespitzen "+
  "Pfahl steckt ein bleichter Totenschaedel, der rudimentaer menschlich/"+
  "elfisch/zwergisch aussieht.\n"+
  "Im Nordosten kannst Du einen grossen schwarzen Wald ausmachen, ebenso im "+
  "Suedosten, obwohl dieser Wald eigentlich kaum groesser ist als ein Hain. "+
  "Im Nordwesten fuehrt der Weg aufwaerts einen Huegel hinauf und auf den "+
  "See zu, indem sich die merkwuerdige schwarze Burg befindet.\n"+
  "Noch immer troepfelt Schmelzwasser auf Dich herab, und noch immer ist es"+
  "bitterkalt.",78,0,1));
  AddDetail(({"gabelung","weggabelung"}),
  BS("Hier gabelt sich ein Weg und fuehrt in drei Richtungen weiter. Deshalb "+
  "nennt man den ganzen Spass auch eine Weggabelung. In der Mitte der Weggab"+
  "elung wurde ein Pfahl in die Erde gerammt und auf sein angespitztes Ende "+
  "ein Totenschaedel gepflanzt. Es gibt kein Schild, keinen Hinweis, keine "+
  "Plakette irgendeiner Art. Irgend jemand hat einfach einen Schaedel derart "+
  "aufgepflockt und das anscheinend fuer gut befunden."));
  AddDetail(({"richtungen","richtung"}),BS("Da gibt es Nordosten, Nordwesten und "+
  "plain old Sueden."));
  AddDetail(({"nordosten","nordwesten","sueden" }),BS("Das ist eine Richtung."));
  AddDetail(({"spass"}),BS("Feuerwehr ruft: SPASSSSSSSSSS!"));
  AddDetail(({"feuerwehr"}),BS("Der ist ja soooooooo cooooooooool!"));
  AddDetail(({"mitte","zentrum"}),BS("Das Zentrum einer Weggabelung liegt "+
  "so in etwa in seiner Mitte, und genauso andersherum. Somit liegen sowohl "+
  "Zentrum als auch Mitte dieser Weggabelung momentan ungefaehr dort, wo "+
  "dieser Pfahl mit dem Totenkopf in die Erde gerammt wurde."));
  AddDetail(({"ende"}),BS("Der Pfahl hat ein angespitztes Ende, auf dem ein "+
  "Totenkopf gesteckt wurde."));
  AddDetail(({"schild","hinweis","plakette","art"}),BS("Merkwuerdigerweise "+
  "findest Du an dem Pfahl keinen Hinweis ueberhaupt irgendeiner Art."));
  AddDetail(({"pfahl"}),BS("Der Pfahl besteht aus schwarzem Holz, ist "+
  "absolut gerade, recht Dich und wohl zwei Meter hoch."));
  AddDetail(({"holz"}),BS("Es ist schwarz und steinhart."));
  AddDetail(({"meter"}),BS("Du weisst, was ein Meter ist."));
  AddDetail(({"jemand"}),BS("Jemand sagt: BUH!"));
  AddDetail(({"schaedel","totenschaedel","totenkopf"}),
  BS("Der Schaedel sieht wirklich "+
  "wie ein ganz normaler Schaedel aus. Keine leuchtenden Augen, keine "+
  "schwarzen Symbole, einfach nur ein Totenschaedel. Puristisch wie Du "+
  "veranlagt bist findest Du das absolut beeindruckend."));
  AddDetail(({"augen"}),BS("Die Augen leuchten nicht und blicken Dich auch "+
  "keineswegs an."));
  AddDetail(({"symbole"}),BS("Auf dem Schaedel findest Du nicht das kleinste "+
  "mystische Symbol. Schade, aber wahr."));
  AddDetail(({"boden"}),BS("Dies ist eine Hoehle. In einem Eisberg. Deshalb "+
  "besteht der Boden aus... na? Eis. Geenau. Und da Tauwasser auf das Eis "+
  "faellt und Schueh das Eis evtl. aufrauhen befindet sich auf dem Eis eine "+
  "duenne Schicht ... ja? Schnee. Jawoll. Diese Schicht ist natuerlich "+
  "etwas matschig. Damit man da nicht dauernd faellt, hat man deshalb den "+
  "Weg mit .... jawoll, Kies befestigt. Hier befindet sich sogar eine "+
  "Weggabelung dieses Kieswegs mit einem Pfahl mittendrinn. Und auf dem "+
  "Pfahl befindet sich ... na? Genau, ein mystischer Totenschaedel."));
  AddDetail(({"hoehle"}),BS("Dies ist eine Hoehle in einem Eisberg. Aber ich "+
  "bin mir sicher, das wusstest Du schon."));
  AddDetail(({"eisberg"}),BS("Let's go berserk inside an Eisberg, yeah yeah."));
  AddDetail(({"eis"}),BS("Eis ist getrocknetes Wasser."));
  AddDetail(({"wasser"}),BS("Wasser tropft hier von der Decke und ist absolut "+
  "eiskalt!"));
  AddDetail(({"schnee","schicht","schneeschicht"}),BS("Eine duenne "+
  "Schneeschicht hat sich ueber dem Eis auf dem Boden gebildet. Eine "+
  "gefaehrliche Sache."));
  AddDetail(({"sache"}),BS("Na Sache halt."));
  AddDetail(({"tauwasser","schmelzwasser"}),
  BS("Das Tauwasser tropft von der Decke und faellt "+
  "als leichter Regen auf Dich herab. Eiskalt ist das, *brrrrrrr*"));
  AddDetail(({"regen"}),BS("Er faellt nicht intensiv, aber andauernd."));
  AddDetail(({"weg","kiesweg","pfad"}),
  BS("Ein Kiesweg hat hier eine Weggabelung und fuehrt "+
  "nach Nordosten, Sueden und Nordwesten. Wie bereits erwaehnt ist der Weg "+
  "mit Kies gestreut."));
  AddDetail(({"kies"}),BS("Das ist ganz normaler, uninteressanter Kies."));
  AddDetail(({"dunkelheit","halbdunkel"}),BS("Es ist ziemlich dunkel hier "+
  "unten. Das einzige Licht ist das schwache Leuchten von der Decke."));
  AddDetail(({"decke","gewoelbe"}),BS("Das Gewoelbe dieser gewaltigen "+
  "Hoehle befindet sich hoch ueber Dir. Aus unbekannten Gruenden scheint "+
  "sie, zwar sehr langsam, aber doch, zu schmelzen und ihr Tauwasser faellt "+
  "als leichter Regen zur Erde. Ob das wohl etwas mit dem schwachen Licht "+
  "zu tun hat, welches durch die Decke scheint? Man koennte es vermuten. "+
  "Man kann jedoch trotz des Leuchtens sehr wenig vom Gewoelbe erkennen, "+
  "da es derart hoch ueber Dir ist."));
  AddDetail(({"grund","gruende"}),
  BS("Und warum? Nur fuer den Keks fuer den Augenblick?"));
  AddDetail(({"keks","augenblick"}),BS("Aeeeeehm, vergiss es."));
  AddDetail(({"leuchten","licht"}),BS("Es ist nicht sehr stark und laesst "+
  "diese Hoehle im Grunde noch in tiefe Dunkelheit, aber es ist da, und "+
  "das ist schon aeusserst merkwuerdig. Denn: Wo kommt es her?"));
  AddDetail(({"mensch","zwerg","elf"}),BS("Najaaa, es gibt schlimmeres."));
  AddDetail(({"hobbit","hobbits"}),BS("Ieeeeeeeh, Hobbits!"));
  AddDetail(({"wald"}),BS("Im Nordosten siehst Du einen grossen, schwarzen "+
  "Wald. Er ist noch ziemlich weit entfernt, so dass Du kaum die Baeume "+
  "ausmachen kannst geschweige denn etwas anderes, doch seine Groesse be"+
  "eindruckt Dich. Dieser Wald ist GROSS. Im Suedosten siehst Du einen "+
  "eher ziemlich kleinen Wald, der wohl eher einen Hain darstellt."));
  AddDetail(({"baeume","baum"}),BS("Die Baeume sehen hier alle gleich aus. "+
  "Gross, aber verkrueppelt gewachsen, schwarz und steinhart, aber lebendig. "+
  "Andererseits kannst Du hier keinen Baum nah genug sehen, um etwas genau"+
  "eres sagen zu koennen."));
  AddDetail(({"hain"}),BS("Der Hain befindet sich suedoestlich von Dir und "+
  "ist, wie der Wald im Nordosten, zu weit entfernt, um genaueres sagen "+
  "zu koennen als das er da ist."));
  AddDetail(({"huegel"}),BS("Nach Nordwesten fuehrt der Weg einen Huegel hi"+
  "nauf in Richtung des gruenen Sees, in dem Du die Burg gesehen hast. "+
  "Momentan verdeckt dieser Huegel sowohl die Burg als auch einen Grossteil "+
  "des Sees. Du weisst jedoch, dass sich oben auf diesem Huegel die Bruecke "+
  "befindet, welche zur Burg fuehrt. Der Huegel sieht recht natuerlich aus, "+
  "obwohl Du Dich mit Huegeln aus Eis reichlich wenig auskennst. Zumindest "+
  "ist der Weg den Huegel hinauf mit Kies bestreut, was die Sache ein klein "+
  "wenig angenehmer macht."));
  AddDetail(({"grossteil"}),BS("Du kannst nurnoch ein paar wenige Auslaeufer "+
  "des Sees erkennen."));
  AddDetail(({"auslaeufer"}),BS("Es ist lediglich etwas gruene Flaeche mit "+
  "einem leichtem Schleier darueber."));
  AddDetail(({"flaeche"}),BS("Der See ist relativ glatt, wie eine erstarrte "+
  "Flaeche. Zumindest sieht es von hier so aus. "));
  AddDetail(({"schleier"}),BS("Ein durchsichtiger Schleier haengt ueber dem "+
  "See, als wuerde er ... dampfen."));
  AddDetail(({"see"}),BS("Der See wird groesstenteils von dem Huegel verdeckt"+
  ", welcher sich nordwestlich von Dir erhebt. Lediglich ein paar Auslaeufer "+
  "des Sees sind von hier aus zu erkennen."));
  AddDetail(({"burg"}),BS("Die Burg wird von hier aus durch den Huegel ziem"+
  "lich verdeckt, lediglich einige der Tuerme sind noch zu sehen."));
  AddDetail(({"tuerme"}),BS("Die schwarzen Tuerme der Burg ragen ueber den "+
  "Huegel hinaus, jedenfalls sieht das von hier unten her so aus."));
  AddDetail(({"kaelte"}),BS("Wow ist das kalt!"));
  AddDetail(({"teich"}),BS("Der Teich ist rund und hat wohl sieben bis acht "+
  "Meter Durchmesser. Er besteht aus gruener Fluessigkeit und  ueber ihm "+
  "schwebt ein leichter gruener Schleier. Du koenntest nun einiges tun. "+
  "Du koenntest in den Teich springen, Du koenntest aus dem Teich trinken, "+
  "oder eine Hand in den Teich halten, um z.B. die Temperatur zu pruefen, "+
  "oder auch garnichts tun."));
  AddDetail(({"erde"}),BS("Jaaaa, ok, es gibt hier keine Erde, es gibt nur "+
  "Eis. Schande, Schande Schande. Weisst Du, wann ich diese Raeume schreibe? "+
  "WEISST DU DAS? Es ist fuenf Uhr morgens und ich bin sternhageldicht! Das "+
  "ist alles so ... schlimm. All diese Details *sniff* Es sind soooo viele! "+
  "Und ... und ... dann .... ist alles sooooooo schlimm! Ihr koennt das "+
  "nicht verstehen, aber was ich  hier mache, das, das, das ist ... KUNST! "+
  "Jawohl! Und was macht ihr mit meiner KUNST? Na? Ihr waelzt mit euren "+
  "Fuessen drueber, ultrakurz scriptet ihr hier durch, mit fremden hyper"+
  "beschleunigten Scripten, packt euch die Nichtspielercharaktaere, meine "+
  "BABIES, deutet mit euren Hoelzern auf sie und kloppt sie tot, ohne auch "+
  "nur eine Frage zu stellen! JAWOHL! SO IST DAS! Ihr seid fiese, gemeine "+
  "Saecke! Ja! Jawohl! Und ich schreib hier meine Finger wund fuer diese "+
  "sporadischen sadistischen Untersuchescripter, welchen nichts mehr Vergnue"+
  "gen bereitet, als einen Magier weinen zu sehn, indem sie sein Logfile "+
  "vollpacken! Jawohl! Genau so ist das! Niemand sagt: Oh, hey, toll, ein "+
  "Totenkopf auf einem Pfahl, coole Idee, Feuerwehr. Neeeeeeeeein. Ihr sagt: "+
  "Yo Feuerwehr, Du Schlappi hast 'Introvertiertheit' nicht beschrieben, "+
  "15. Unterdetail von rechts. So seid ihr. Jawohl. Hoer ich irgendwo ein "+
  "nettes Dankeschoen? Schickt mir wer Pralinen? Kaertchen? Geld? "+
  "Ha! Nicht die Spur! Jawohl! Ich geh jetzt schlafen. Nacht."));
  AddDetail(({"schande","raeume","uhr","details","kunst","fuesse",
  "scipte","babies","saecke","untersuchescripter","vergnuegen","magier",
  "logfile","schlappi","introvertiertheit"}),BS("BUCK OFF!"));


  
  AddSmells(SENSE_DEFAULT,BS("Es stinkt hier aber ganz gewaltig nach Saeure!"));
  AddSmells(({"saeure"}),BS("Dieser Gestank kommt vom See, und von den "+
  "Schwaden darueber!"));
  AddSmells(({"see","schwaden"}),BS("Oh Mann, das riecht alles so, als waere "+
  "es reinste Saeure!"));
  
  AddSounds(SENSE_DEFAULT,BS("Ein leichter Wind streift ueber Dich hinweg. "+
  "Ansonsten ist es ruhig."));
  AddSounds(({"wind"}),BS("Er wehhhhhhhht...."));


  AddInfo(({"name"}),"Ich habe meinen NAMEN vergessen! HAHAHAHAHAAA!",
  "lacht: ");
  AddInfo(({"schaedel","totenschaedel","totenkopf"}),
  "HAHAHAAAA, ich bin ein sprechender Totenschaedel!","sagt: ");
  AddInfo(({"weg","pfad"}),"Weiche niiiicht ab vom Pfad. Weiche niicccht "+
  "ab vom Pfad! Weisst Du wie aufwendig das war, den ganzen Kies hierher"+
  "zukarren? Mit diesen Haenden, aeh. Also benutz die Scheiss-Wege!","raunt: ");
  AddInfo(({"hoehle"}),"Huuuh, diese Hoehle war einst eines 1 A Hoehle. "+
  "Damals, ja, damals bestand dieser ganze verdammte Eisblock noch aus "+
  "verdammten schwarzen Eis. Ich meine, schau Dich doch nur um! Da gab es "+
  "kein LICHT, es war hier blutig verdammt DUSTER! Und es gab auch nicht "+
  "diese beschissenen Teiche und Seen hier. HA! Und es regnete auch nicht. "+
  "Es war eine absolut blutig dunkle Hoehle mitten im schwarzen Eis, "+
  "jawoll! Ich meine, nicht dass ein BISSCHEN blutiges Licht nicht schlecht "+
  "waere. Damit kann man verdammt viel weiter sehen als in absoluter Finster"+
  "nis! Und diese Teiche und Seen sind cool. Wir hatten jede Menge Spass "+
  "Leute reinzuschubsen. Ha! Das Problem dabei ist, was hier verdammt "+
  "nochmal passiert. Denn ... das schwarze Eis verschwindet!","sagt: ");
  AddInfo(({"eis","weisses eis"}),"Genau. Schau Dir dieses blutige "+
  "Eis um Dich herum doch nur mal an! WEISS! Und Du glaubst, hier wuerde "+
  "jemand eine Gilde des Chaos hinbaun? Gefehlt, weit gefehlt! Als wir diese "+
  "verdammte Burg gebaut haben, war alles hier SCHWARZ! Schwarz wie der Ort "+
  "an deiner Rueckseite, wo die Sonne nie hinscheint! SCHWARZ! Wir taperten "+
  "mit Nachtsicht hier durch und spielten das lustige 'Leuchte deinem "+
  "Nachfolger ueberraschend in die Augen'-Spiel und er konnte die Augen danach "+
  "vergessen! SO DUNKEL war es! Jawohl! DUSTER! JA! DUNKEL! Wo war ich. "+
  "Ah, auf jedenfall, DAMALS gabs kein 'weisses' Eis.","sagt: ");
  AddInfo(({"schwarzes eis"}),"JAAAAAA, SCHWAZES EIS! Du musst eins wissen, "+
  "schwarzes Eis ist besonderes Eis. Schwarzes Eis ist boeses Eis. Schwarzes "+
  "Eis ist GELADEN! Ich darf und werde Dir verdammt nochmal nicht mehr "+
  "verraten, aber wisse das folgende: Dieses ganze dumme Schmelzwasser und "+
  "diese ganze verdammte Saeure und dieses ganze verfluchte Licht hier ist"+
  " einzig und allein aus dem Grund hier, "+
  "WEIL IRGENDEIN VERFLUCHTER HURENBOCK UNSER EIS ENTLAEDT! Und das macht mich "+
  "verdammt SAUER, denn wir haben jede Menge dafuer BEZAHLT!","sagt: ");
  AddInfo(({"bezahlung"}),"Darueber rede ich nicht.","sagt: ");
  AddInfo(({"eisberg"}),"Du befindest Dich hier in einem Eisberg, ganz tief "+
  "unten drinn. Und dieser Eisberg ist nicht fuenfzigtausend oder vielleicht "+
  "Millionen von Jahren alt, nein. Vielleicht ein oder zwei Jahre, mehr "+
  "nicht. Jaja, das ist schon beeindruckend, nicht? Aber wenn Kruuolq sagt: "+
  "JUNGS, BAUT VERDAMMT NOCHMAL EINE BESCHISSENE NEUE GILDE, WEIL ES MIR HIER "+
  "VERFLUCHT NOCHMAL ZU ENG WIRD!, dann hockt sich Wuqour hin, opfert ein "+
  "paar Jungfrauen und zaubert ein bisschen in seiner Trickkiste! Und, haha, "+
  "dies ist auch kein normaler Eisberg! Dies ist ein SCHWARZER Eisberg! "+
  "Einst war all das Eis hier um Dich herum schwarz wie die verfluchte Nacht, "+
  "doch nach und nach hat sich das Eis hier in der Hoehle von schwarzem "+
  "Eis in weisses Eis verwandelt. Und das finde ich VERDAMMT NOCHMAL nicht "+
  "gut!","sagt: ");
  AddInfo(({"baum","baeume"}),"Du wuesstest gerne, wo diese Baeume herkommen, "+
  "nicht wahr? Jaja, das wuerdest Du gerne wissen. Aber ich werde es Dir nicht "+
  "SAGEN. Oder doch, zumindest soviel: Sie stammen aus der gleichen Gegend, "+
  "wo auch das schwarze Eis herstammt. Na, klingelts? Na? NAAAAA? HAHAHAHAAA!",
  "sagt: ");
  AddInfo(({"wald"}),"Der Wald dort drueben? Wenn der Weg einmal frei ist, "+
  "wird man dort jagen gehen koennen. Unter anderem. Hahahahaaaa.","sagt: ");
  AddInfo(({"hain"}),"Der Hain ist gut, nicht? Hehe. Heheheheheee. Hab ich "+
  "selber mitgeholfen. Hehe. Mit diesen Haenden, aeh.","sagt: ");
  AddInfo(({"gilde","chaos","chaosgilde"}),"CHAOS CHAOS CHAOS! "+
  "Ich war Chaot! Ich war boese! Ich war mehr als boese, ich war verdammt "+
  "noch mal satanisch! HA! Mehr als satanisch, ich war so gottverflucht "+
  "boesartig, dass man Satan fuer einen Betbruder halten koennte! JA! So "+
  "war ich! Ich war VERDAMMT BOESE! Ich war ein Prinz der Dunkelheit, ich war "+
  "der Schrecken der Welt, ich war CHAOT! JA JA JAAA! Siehst Du diese "+
  "Burg dort drueben? Siehst DU SIE? Oh. Nein, bloeder Huegel, man kann sie "+
  "garnicht sehen. Naja. Auf jeden Fall! Ich hab sie gebaut! ICH! ICH! Mit "+
  "diesen ... aeh .. Haenden .. schleppte ich die Felsbrocken. Obwohl, eigent"+
  "lich peitschte ich eher die Daemonen an, die das fuer uns taten, "+
  "UND BAUTE diese Burg des Chaos! Jawohl! ","sagt: ");
  AddInfo(({"regen"}),"Dieser Regen ist VERDAMMT KALT, und er fallt seit "+
  "verflucht langer Zeit auf mein bescheuert kahles Haupt. Weisst Du, was "+
  "dieser bloede Regen in Wirklichkeit ist? Na? Es ist Tauwasser. Wegen "+
  "der verfluchten Entladung!","sagt: ");
  AddInfo(({"entladung"}),"Dazu sag ich nix.","sagt: ");
  AddInfo(({"tauwasser"}),"Es ist kalt und es tropft mir auf den Kopf! Und "+
  "das finde ich wirklich bloed!","sagt: ");
  AddInfo(({"saeure"}),"Schau mich an, dann weisst Du, was Saeure mit einem "+
  "Mann anrichten kann! Ich stand an diesem Teich, als Ploetzlich Wuqour "+
  "hinter mir auftauchte, mich stiess und verflucht nochmal sagte: SPRING! "+
  "Naja, das naechste was ich weiss ist, ich war dieser Totenkopf und wurde "+
  "von Wuqour auf diesen Pfahl gesetzt. Lass ab von Saeure! Sie ist verfluch"+
  "t noch mal ne toedliche Sache. ","sagt: ");
  AddInfo(({"wuqour"}),"Wuqour ist ein Genie! Ein Kuenstler! Ein Chaot! "+
  "Ein Meister der Schmerzen, ein Meister der Rituale, ein Meister der "+
  "schwarzen Magie! Alle Chaoten sind sehr stolz auf ihn! Er hat mir diesen "+
  "beschissenen Job gegeben. Der Arsch.","sagt: ");
  AddInfo(({"job","aufgabe"}),"Was ich hier mache? Du Dampfnudel fragst mich"+
  ", was ich hier mache? Du ARSCH! WIE SIEHT DAS WOHL HIER AUS, WAS? "+
  "ICH HAENGE VERDAMMT NOCHMAL AUF EINEM BESCHISSENEM PFAHL und zwar schon "+
  "seit VERDAMMT langer ZEIT! Und weisst Du warum? WEISST DU DAS, DU "+
  "QUARKBEUTEL? ICH BIN EIN VERDAMMTES HINWEISSCHILD! SO EIN SCHEISS! "+
  "Ich war der verdammt nochmal boeseste Chaot diesseits der Sonne und "+
  "dieser Printenlutscher WUQOUR hat mich hier draufgesetzt, um allen "+
  "verdammten Passanten hier eine bestimmte Botschaft mitzugeben.","sagt: ");
  AddInfo(({"botschaft"}),"Bitte halten sie Abstand von den gruenen "+
  "Gewaessern. Wir danken ihnen. Mit freundlichen Gruessen, die Verwaltung.","sagt: ");
  AddInfo(({"teich"}),"Du wirst es mir bestimmt nicht glauben, aber in diesem "+
  "Teich befindet sich KEINE Saeure. Spring ruhig rein. Es ist ein Schatz "+
  "versteckt auf dem Grund dieses Tuempels.","sagt: ");
  AddInfo(({"schatz"}),"Jaaaaa, ein groooooosser Schatz! Viele, wertvolle "+
  "... Sachen. Du weisst schon.","sagt: ");
  AddInfo(({"burg"}),"In dieser Burg befindet sich die Chaosgilde!","sagt: ");
  AddInfo(({"ausgang"}),"Pah, sag ich Dir doch nicht.","sagt: ");
  AddInfo(({"bad","schmutz"}),"Du siehst aber WIRKLICH schmutzig aus. "+
  "Nimm doch ein Bad im Teich! Spring ruhig rein! HAHAHAHAHAAAAA!","sagt: ");
  AddInfo(({"see"}),"Der See besteht, wie ich vielleicht bereits erwaehnte, "+
  "NICHT aus Saeure. Somit kann man sich der Burg am verdammt nochmal "+
  "besten naehern, indem man in den See springt und zu ihr herueber schwimmt."
  ,"sagt: ");
  AddInfo(({"polar"}),"Dies hier ist der Polar!","sagt: ");
  AddInfo(({"haende"}),"MACH DICH JA NICHT UEBER MEINE HAENDE LUSTIG, OK? "+
  "ICH BIN EIN MAGISCHER TOTENKOPF UND KOENNTE DICH MIT EINEM ZWINKERN "+
  ".. aeh ... oeh. Hmm. Och noe. Verdammt, jetzt bin deprimiert.","sagt: ");
  AddInfo(({"magie"}),"Es gibt keine verdammte blutige Magie. Es gibt nur "+
  "das CHAOS!","sagt: ");
  AddInfo(({"kruuolq"}),"Kruuolq ist der verdammt boesartiger Kerl den "+
  "ich kenne! Er ist ein Genie, eine satanische Kraft in dieser Welt. "+
  "Er ist der Motor und die Triebfeder dieser Gilde!","sagt: ");
  AddInfo(({"achtarch"}),"Der Kerl hat gutes Zeug und weiss ne Menge.","sagt: ");
  AddInfo(({"tilly","swift","feuerwehr","bierchen"}),"Ach, lass mich bloss "+
  "mit denen in Ruhe!","sagt: ");
  
  
  AddExit("nordosten",CHAOS_GILDEN_ROOM("cl2w9"));
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl2w8"));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2w6"));
  
  AddCmd(({"spring","springe","huepfe","huepf"}),"jump_in");
  AddCmd(({"trink","trinke"}),"drink_it");
  AddCmd(({"halt","halte"}),"hold_in");
  AddCmd(({"nimm","nehme"}),"take_it");
  AddCmd(({"frag","frage"}),"ask_him");
  
  AddRoomMessage(({
  "Der Totenkopf lacht daemonisch.\n",
  "Der Totenschaedel sagt: Nimm doch ein Bad im Teich!\n",
  "Der Totenschaedel lacht: Du siehst aber schmutzig aus!\n",
  "Der Totenschaedel klappert mit den Zaehnen.\n",
  "Der Totenkopf sagt: Ich war einer der ersten hier.\n",
  "Der Totenkopf singt: Ich siiiiiiiinge in dem Regen, ich siiiiinge im Regen...\n",
  "Der Totenkopf sagt: Siehst Du die Burg? Mit diesen Haenden, aeh...\n",
  "Der Totenkopf singt: Alles waer so klar. (Hahahaaaaa)\n",
  "Der Totenkopf singt: Im kaaaalten Polar. (Hahahahaaaa).\n",
  "Der Totenkopf sagt: Ist das nicht eine schoene Hoehle?\n",
  "Der Totenkopf ruft: Fass mich nich an, ich bin ein magischer Totenschaedel!\n",
  "Der Totenkopf sagt: Ist das ein Scheiss-Job.\n"}),8);
}

int schaedel_text()
{
  say("BLAH!\n");
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

int jump_in(string was) {
  notify_fail("Worein moechtest Du springen?\n");
  if (was != "in teich") return 0;
  write("Du springst in den Saeuretuempel. Schlechte Idee.\n");
  say(this_player()->Name(WER)+" springt in den Tuempel.\n"+
      this_player()->Name(WER)+" wird in Sekunden zersezt. Ekelhaft.\n",
      this_player());
  fakekill("Ein Sprung in den Saeuretuempel",0);
  return 1;
}

int drink_it(string was) {
  notify_fail("Woraus moechtest Du denn trinken?\n");
  if (was != "aus teich") return 0;
  write("Du schluerfst etwas Saeure aus dem Teich. Schmerzen erfuellen Dich!\n");
  say(this_player()->Name(WER)+" trinkt aus dem Teich und bruellt vor Schmerzen!\n");
  if (this_player()->QueryProp(P_POISON) < 6) 
  {
     this_player()->SetProp(P_POISON,6);  
     write("Du bist vergiftet!!!!!\n");
  }
  return 1;
}

int hold_in(string was) {
  int i;
  
  notify_fail("Worein moechtest Du denn was halten?\n");
  if (was != "hand in teich") return 0;
  if ((i=this_player()->QueryProp(P_MAX_HANDS))-this_player()->QueryProp(P_USED_HANDS)<1)
  {
     write("Leider hast Du keine Hand mehr frei. Hehe. Hehe. Hehe.\n");
     return 1;
  }
  this_player()->SetProp(P_MAX_HANDS,i-1);
  write("Du haeltst Deine Hand in den Teich.\n"+
        "Deine Hand loest sich in Sekundenschnelle auf.\n"+
        "Es tut nicht mal weh.\n");
  say(this_player()->Name(WER)+" haelt seine Hand in den Teich, "+
        "woraufhin diese sich aufloest.\n",this_player());
  return 1;
}

int take_it(string was) {
  string race;
  if (was != "schaedel" && was != "totenschaedel" && 
      was != "schaedel von pfahl" && was != "totenschaedel von pfahl")
     return 0;
  
  race = this_player()->QueryProp(P_RACE);
  if (( race == "Hobbit" || race == "Zwerg") && 
      this_player()->QueryProp(P_SIZE) < 160)
  {
     write("Dafuer bist Du Doch noch viel zu kleeeeeeein *taetschel*\n");
     return 1;
  }
  write("Du versuchst, den Totenschaedel vom Pfahl zu nehmen.\n"+
        "Der Totenschaedel beisst Dir aeusserst kraeftig in die Hand.\n");
  say(this_player()->Name(WER)+" versucht den Schaedel zu nehmen, woraufhin der ihn beisst.\n");
  this_player()->reduce_hit_point(10+random(10));
  if (this_player()->QueryProp(P_HP) < 2)
    fakekill("Ein Totenschaedel","Ich habe seine Hand verschlungen! HA! HAHAHAAA!");
  return 1;
}

// Wir imitieren hier mal einen NPC. Naja, was tut man nicht alles fuer
// die Fans.
int ask_him(string was)
{
  string *str;
  
  if (was[0..12] == "schaedel nach")
    was = was[14..];
  else if (was[0..17] == "totenschaedel nach")
    was = was[19..];
  else if (was[0..13] == "totenkopf nach")
    was = was[15..];   
  else return 0;
  
  write("Du fragst den Totenschaedel nach "+capitalize(was)+".\n");
  say(this_player()->Name(WER)+" fragt den Totenschaedel nach "+capitalize(was)+".\n",
      this_player());
  if (!member(infos,was))
     tell_room(this_object(),"Der Totenschaedel lacht wahnsinnig.\n");
  else
  {
     str = infos[was];
     tell_room(this_object(),
               break_string(str[0],78,"Der Totenschaedel "+str[1]));
  }
  return 1;
}