#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu1"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In einer chaotischen Burg");
  SetProp(P_INT_LONG,break_string(
  "\bDa stehst Du nun. Dies hier waere sicherlich ein grosser und ueberaus "+
  "beeindruckender Platz, der einem mit Sicherheit Ehrfurcht vor den "+
  "gewaltigen Maechten des Chaos eingefloesst haette, wenn man nur "+
  "weiter als ein paar lausige Zentimeter weit sehen koennte. So besteht "+
  "deine Orientierung jedoch groesstenteils darin, mit ausgestrecken "+
  "Armen herumzulaufen und zu versuchen, nicht gegen die einzelnen "+
  "Gebaeude zu laufen.\n"+
  "Und Gebaeude gibt es hier insgesamt drei, zumindest drei, welche Du von "+
  "diesem Platz aus erkennen kannst. Da die Beschreibung hier sonst zu lang "+
  "wuerde, wurden ihre Beschreibungen uebrigens die Details noerdliches, "+
  "suedliches und westliches Gebaeude ausgelagert.",78,0,1));
  AddDetail(({"gebaeude 1","haus 1","noerdliches gebaeude","noerdliches haus"}),
  BS("Beginnen wir mit dem groessten, selbst "+
  "in dieser blutigen Finsternis beeindruckenden Gebaeude. Es ist extrem "+
  "hoch, hoeher, als Du in dieser Finsternis sehen kannst, sogar hoeher "+
  "als die Burgmauern, wie Du von ausserhalb hast erkennen koennen. Schwarz "+
  "wie die Nacht, ohne jegliche Fenster, erhebt es sich noerdlich von Dir. "+
  "Ein grosses Tor ermoeglicht den Zutritt. Ueber dem Tor wurde ein grosses, "+
  "unheimliches Symbol gemalt. Eigentlich sollte man es in dieser Dunkelheit "+
  "garnicht sehen, doch es leuchtet mysterioes und unheimlich in die "+
  "Nacht hinaus.\n"));
  AddDetail(({"gebaeude 2","haus 2","suedliches gebaeude","suedliches haus"}),
  BS("Das zweite Gebaeude ist nicht ganz so gross wie das im Norden. Es er"+
  "streckt sich entlang der suedlichen Burgmauer, ist zwar nicht so "+
  "hoch wie das noerdliche, aber immernoch beeindruckend. Was da wohl "+
  "drinnen ist. Ein (dunkler) Eingang fuehrt in das Gebaeude hinein. Auch "+
  "hier prangt ein Symbol ueber dem Eingang, welches unheilig in die "+
  "Finsternis leuchtet.\n"));
  AddDetail(({"gebaeude 3","haus 3","westliches gebaeude","westliches haus"}),
  BS("Im Westen befindet sich das dritte Gebaeude. Es ist recht klein und "+
  "beschaulich, jedenfalls von aussen. Die Reste der Tuer haengen noch in "+
  "den Angeln. Wie die beiden anderen hat sie keine Fenster und ein "+
  "mystisches Symbol ueber seiner Tuer. Und auch dieses leuchtet fies in "+
  "die Dunkelheit. Was geht hier nur vor..."));
  AddDetail(({"boden"}),BS("Da gibt es hier so viele interessante Sachen zu "+
  "betrachten, und Du kriechst wieder auf dem Boden rum. Pfffffff. Ok. "+
  "Er ist da. Er ist schwarz. Er besteht aus Pflastersteinen. Er ist ziem"+
  "lich zerkratzt, als wuerden hier ziemlich viele Leute herumtrampeln in "+
  "mit Spikes versehenen Stiefeln. Nun ja. Ansonsten erwaehnenswert ist nur "+
  "der kleine, unscheinbare Schalter, den Du gerade entdeckst."));
  AddDetail(({"schalter"}),BS("Oh ohhhhhhh. Nein. Du wirst ihn nicht "+
  "druecken. Nein Nein."));
  AddDetail(({"sachen"}),BS("Da gibt es so viele Gebaeude, so viele mysti"+
  "sche Symbole, aber neeee, Du betrachtest den Boden unter deinen Fuessen."));
  AddDetail(({"fuesse"}),BS("Puuuuuuuh. Du haettest nicht hinsehen sollen..."));
  AddDetail(({"kratzer"}),BS("Diese Kratzer koennten durch Leute mit sehr "+
  "eigenwilliger Fussbekleidung entstanden sein... Sie KOENNTEN aber auch "+
  "sehr viel boesartigere, satanischere Ursachen haben..."));
  AddDetail(({"ursachen"}),BS("Naja, wahrscheinlich warens doch die "+
  "Stiefel! :)"));
  AddDetail(({"stiefel","spikes","fussbekleidung"}),BS("Jeder kennt den "+
  "ausgefallenen Geschmack von Chaoten in Bezug auf Stiefel..."));
  AddDetail(({"geschmack"}),BS("Nun, derart ausgefallen ist der Geschmack "+
  "nicht. Es sollte halten, es sollte nicht weh tun, wenn jemand drauftritt, "+
  "es sollte extrem weh tun, wenn man jemanden damit tritt. Wirklich "+
  "ganz gemein aetzend weh. Das ist wichtig."));
  AddDetail(({"jemand"}),BS("Jemand beteuert: Ich wuerd niemandem auf die "+
  "Fuesse treten!"));
  AddDetail(({"niemand"}),BS("Niemand ruft: Doch, Jemand! Das hast Du ge"+
  "macht, und alle hams gesehn!"));
  AddDetail(({"alle"}),BS("Alle rufen: Jawoll, das stimmt!"));
  AddDetail(({"pflastersteine","pflastersteine"}),BS("Sie sind schwarz, "+
  "bestehen aus Stein und ihre Farbe ist schwarz, pechschwarz. Ansonsten "+
  "kann man diesen Steinen nicht allzuviel abgewinnen."));
  AddDetail(({"stein","steine"}),BS("Du befindest Dich in einer Burg, "+
  "einer gewaltigen, schwarzen Burg. Und in dieser schwarzen und wirklich "+
  "grossen Burg besteht fast alles aus Stein. Also drueck Dich verdammt "+
  "noch mal ein klein bisschen praeziser aus."));
  AddDetail(({"farbe"}),BS("Die vorherschende Farbe hier ist ganz klar "+
  "schwarz."));
  AddDetail(({"schwarz"}),BS("PECHSCHWARZ, um genau zu sein."));
  AddDetail(({"pechschwarz"}),BS("Mann, ist das dunkel hier."));
  AddDetail(({"leute"}),BS("Viele Leute scheint es hier ja nicht zu geben. "+
  "Doch andererseits sieht der Boden hier derart zerkratzt aus, als wuerden "+
  "ziemlich viele hier rumrennen. Langsam wird Dir hier ziemlich mulmig..."));
  AddDetail(({"decke"}),BS("Die Decke befindet sich derartig weit ueber "+
  "Dir, dass Du sie irgendwie in dieser Dunkelheit sehen koenntest."));
  AddDetail(({"dunkelheit","finsternis"}),BS("Es ist wirklich verflucht "+
  "dunkel hier. Fuer genauere Beschreibungen der Dunkelheit untersuche "+
  "bitte andere Raeume."));
  AddDetail(({"beschreibungen"}),BS("Du untersuchst sie aufmerksam, und "+
  "das ist gut so."));
  AddDetail(({"raeume"}),BS("Diese Burg hat wirklich viele Raeume."));
  AddDetail(({"wand","waende"}),BS("Es gibt hier viele Waende. Wirklich "+
  "viele. Die Burgmauer kannst Du von hier aus in der Dunkelheit nicht "+
  "erkennen, aber es gibt einige Hauswaende. Diese sind jedoch im Grunde "+
  "alle gleich oede. Was fuer eine merkwuerdige dunkle Burg."));
  AddDetail(({"hauswaende","hauswand"}),BS("Generell bestehen die Hauswaende aus "+
  "pechschwarzen Ziegelsteinen. Sie passen zwar absolut in diese Atmosphaere, "+
  "und die Burg wuerde mit anderen Ziegelsteinen wohl garnicht existieren, "+
  "aber momentan wuenschst Du Dir wirklich, irgendjemand wuerde sich eine "+
  "Spruehdose schnappen und hier etwas Abwechslung reinbringen."));
  AddDetail(({"spruehdose","spruehdosen"}),BS("Spruehdosen gibts in der "+
  "Unterwelt oder beim Punker."));
  AddDetail(({"unterwelt"}),BS("*Huestel* Ja. aehm. Schoen ... da. Da gibts "+
  "ne Spruehdose, aber mit der kann man kein Grafitty machen. Schade aber "+
  "auch."));
  AddDetail(({"punker"}),BS("Der Punker steht weiiiiiiit im Norden. Jawohl."));
  AddDetail(({"norden"}),BS("Da lang."));
  AddDetail(({"abwechslung","grafitty"}),BS("Bei aller Liebe zum Morbiden, "+
  "aber diese Burg driftet langsam in die Gefilde ab, wo es oede wird. Ein "+
  "richtig gutes Grafitty wuerde hier mal richtig Abwechslung bringen."));
  AddDetail(({"liebe"}),BS("Wo ist sie hin? Wann hast Du sie verloren? "+
  "Du weisst es nicht mehr ... einsam und allein driftest Du dahin ..."));
  AddDetail(({"morbides"}),BS("Diese Burg ist genau das, was man unter "+
  "morbid verstehen sollte. Obwohl. Nein. Eigentlich nicht."));
  AddDetail(({"gefilde"}),BS("Vergiss es."));
  AddDetail(({"platz"}),BS("Dieser Platz ist riesig. Er wird von allgemein "+
  "von drei Gebaeuden begrenzt, die Du von hier aus sehen kannst. Im Osten "+
  "geht er jedoch weiter, in die Dunkelheit hinein. Er waere sicherlich "+
  "grossartig, gewaltig und beeindruckend, wenn man nur ein bisschen mehr "+
  "sehen koennte."));
  AddDetail(({"sicherheit"}),BS("Sicherheit wirst Du in dieser Burg "+
  "schwerlich finden. Da schon eher den Tod."));
  AddSpecialDetail(({"tod"}),"tod");
  AddDetail(({"ehrfurcht"}),BS("Wer keine Ehrfurcht vor den gewaltigen "+
  "Maechten des Chaos hat, kann sehr leicht Ehrfurcht vor den gewaltigen "+
  "Maechten von Lars bekommen."));
  AddDetail(({"lars"}),BS("Den wirst Du HIER nicht finden. AHAHHAAAAA...."));
  AddDetail(({"maechte","maechte des chaos"}),BS("Die Maechte sind "+
  "gewaltig, unermesslich, unfassbar gross. Das kannst Du niemals erfassen."));
  AddDetail(({"chaos"}),BS("Dies ist die schwarze Burg, die chaotische "+
  "Burg, die Burg des Chaos. Es herrscht hier, unangefochten, unbesiegbar, "+
  "maechtig und stark. Mach Dir das klar, sonst koenntest Du hier schnell "+
  "den Tod finden."));
  AddDetail(({"zentimeter"}),BS("Ein paar Zentimeter sind wirklich nicht all"+
  "zu weit..."));
  AddDetail(({"orientierung"}),BS("Hier in dieser verfluchten Dunkelheit "+
  "ist die Orientierung doppelt schwierig. Hier orientiert man sich mit "+
  "seinen Haenden."));
  AddDetail(({"haende","hand"}),BS("Los! Waschen! Sofort!"));
  AddDetail(({"arme"}),BS("Wow, Du hast sogar zwei davon! Und Haende sind "+
  "auch noch dabei, wie praktisch!!!"));
  AddDetail(({"gebaeude"}),BS("Hossa, hier scheint sogar jemand zu wohnen. "+
  "Nun, bei dieser Lage kann die Miete ihm ja nicht die Haare vom Kopf "+
  "fressen. Ok, es gibt drei Gebaeude, und Du kannst sie mit noerdliches "+
  "/ westliches / suedliches Gebaeude oder mit gebaeude 1 / 2 / 3 unters"+
  "uchen. Jedoch nur, wenn Du dazu bereit bist."));
  AddDetail(({"beschreibung","langbeschreibung"}),BS("Die Langbeschreibung "+
  "dieses Raumes wurde durch die Beschreibung der einzelnen Gebaeude zu "+
  "lang, um sie richtig lesen zu koennen. Deshalb wurden diese in "+
  "Details ausgelagert."));
   AddDetail(({"details"}),BS("Genau. Darum gehts hier. Details."));
   AddDetail(({"burgmauern","burgmauer"}),BS("Die Burgmauern sind zu "+
   "weit entfernt. Man kann sie in dieser Dunkelheit nicht erkennen."));
   AddDetail(({"nacht","tag"}),BS("Es gibt hier natuerlich weder Nacht "+
   "noch Tag, doch wenn es eine Nacht geben wuerde, so koennte sie "+
   "niemals schwaerzer sein als diese Burg. Jawohl. So ist das."));
   AddDetail(({"fenster"}),BS("Hier siehst Du nirgendwo Fenster. Wie "+
   "merkwuerdig..."));
   AddDetail(({"symbole","symbol"}),BS("An jedem der drei Gebaeude prangt "+
   "ein merkwuerdiges Symbol. Man kann sie einzelnuntersuchen, genau wie "+
   "die Gebaeude."));
   AddDetail(({"symbol 1","noerdliches symbol"}),BS(
   "Das noerdliche Symbol leuchtet, duester und doch majestaetisch, in "+
   "die Dunkelheit dieser Burg. Es ist ein komplexes Symbol, in seinem "+
   "Zentrum der Schaedel eines Monsters, boesartig, mit Hauern versehen "+
   "und messerscharfen Zaehnen. Hinter ihm sind zwei gekreuzte Aexte auf"+
   "gezeichnet. Es sind grosse, klobige Aexte mit einer Schneide, wie "+
   "sie von Henkern genutzt werden. Und hinter diesen Aexten siehst Du "+
   "ein mit komplexen Mustern versehenes, rundes ... Objekt, vielleicht "+
   "ein Schild. Unter diesem Bild hat jemand uebrigens einen Slogan "+
   "geschmiert, der ebenso leuchtet wie das Symbol ueber ihm."));
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
   AddDetail(({"zentrum"}),BS("Das Zentrum ist die Mitte, und die Mitte "+
   "ist das Zentrum. Nur damit Du es weisst."));
   AddDetail(({"eingang"}),BS("Der Eingang fuehrt in die Schwaerze hinein. "+
   "Was sich wohl in diesem Gebaeude befindet..."));
   AddDetail(({"slogan"}),BS("Er leuchtet!"));
   AddReadDetail(({"slogan"}),"\n\n\n\n                    C  H  A  O  S      R  U  L  E  Z  !  !  !\n\n\n\n\n");
   AddDetail(({"suedliches symbol","symbol 2"}),BS("Dieses Symbol sieht nicht "+
   "ganz so chaotisch und verwirrend aus wie das noerdliche. Auf dem Symbol "+
   "siehst Du einen Chaoten (denn niemand sonst kann derart satanisch grinsen) "+
   "und einen finsteren Daemon, welche sich gegenseitig zu zerfleischen schei"+
   "nen. Unangenehmerweise macht der Chaot hier einen sehr viel zerfledderten "+
   "Eindruck als der Daemon, gegen den er kaempft. Es sieht ziemlich danach "+
   "aus, als wuerde er diesen Kampf verlieren."));
   AddDetail(({"chaoten","chaot"}),BS("Die Chaoten sind die Krieger des "+
   "Chaos. Das solltest Du wirklich wissen."));
   AddDetail(({"daemon"}),BS("Der Daemon auf dem suedlichen Symbol sieht eig"+
   "entlich noch ganz ok aus, waehrend der Chaot ihm gegenueber schon ziem"+
   "lich am Boden zu liegen scheint. Das IST aber auch ein fieser Daemon, "+
   "so wies aussieht..."));
   AddDetail(({"eindruck"}),BS("Der Eindruck draengt sich Dir ziemlich stark "+
   "auf, muss man sagen..."));
   AddDetail(({"kampf"}),BS("Auf dem suedlichen Symbol wird ein Kampf "+
   "zwischen einem Daemonen und einem Chaoten dargestellt."));
   AddDetail(({"tuer","reste","angeln"}),BS("Die Tuer zum westlichen Gebaeude "+
   "haengt (zumindest ihre Reste haengen) zerfetzt in ihren Angeln. Anschein"+
   "end sollte hier mal wer nicht reinkommen, der dann doch reingekommen ist. "+
   "Oder jemand sollte drinnenbleiben, der dann herausgekommen ist. Du weisst "+
   "nicht recht, was davon schlimmer ist..."));
   AddDetail(({"symbol 3","westliches symbol"}),BS("Na dieses Symbol kannst "+
   "Du doch endlich mal verstehen. Es leuchtet duester in die Dunkelheit um "+
   "Dich herum und stellt einen Chaosbecher dar. Du hast schon genug Geschicht"+
   "en um dieses unglaubliche Getraenk gehoert, welches fuer jedes lebende "+
   "Wesen ausser einem Chaoten absolut ungeniessbar ist."));
   AddSpecialDetail(({"chaosbecher","becher"}),"det_becher");
   AddDetail(({"geschichten"}),BS("Fuerchterliche Geschichten, horrende "+
   "Geschichten von Monstern, die aus Bauchhoelen kriechen und so..."));
   AddDetail(({"monster"}),BS("Fiese, schleimige Monster, die aus "+
   "Bauchhoehlen klettern, gehoeren zu den wirklich ekelhaften. Das kann "+
   "man nicht anders sagen."));
   AddDetail(({"bauchhoehlen"}),BS("Du hast ploetzlich ziemliche, also "+
   "wirklich, ganz ekelhafte Bauchschmerzen."));
   AddSpecialDetail(({"bauch","bauchdecke","schmerzen","bauchschmerzen"}),
                      "det_bauch");
   
   
  AddSmells(SENSE_DEFAULT,BS("Es riecht irgendwie fies hier."));
  AddSounds(SENSE_DEFAULT,BS("Du hoerst nichts. Totenstille."));

  AddCmd(({"drueck","druecke"}),"push_button");
  AddCmd(({"ja","nein","sag","sage"}),"janein");
  AddCmd(({"wasch","wasche"}),"wash");
  
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl2bu4"));
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl2bu1"));
  AddExit("nordosten",CHAOS_GILDEN_ROOM("cl2bu7"));
  AddExit("osten",CHAOS_GILDEN_ROOM("cl2bu6"));
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl2bu8"));
  AddSpecialExit("westen","kneipe");
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2_ctrib"));

  NewDoor("norden",CHAOS_GILDEN_ROOM("cl2_challe"),({"tor"}),
  ({D_NAME,"Tor",
    D_GENDER,0,
    D_SHORT,"Das duestere Tor zum noerdlichen Gebaeude ist %s.",
    D_LONG,BS("In dieser verdammten Dunkelheit kann man aber auch "+
              "wirklich nix erkennen.")}));
              
  AddItem("/d/polar/files.chaos/obj/glocke",REFRESH_DESTRUCT);
  AddItem(CHAOS_GILDEN_MON("cl2_spikey"),REFRESH_DESTRUCT);
 
}


int push_button(string was) {
   if (was == "praeziser aus" || was == "klein bisschen praeziser aus")
   {
      write("JAAAAAAAAA, es geht doch!\n");
      say(this_player()->Name(WER)+" drueckt sich praeziser aus.\n",this_player());
      return 1;
   }
   if (was != "schalter") return 0;
   write("Dein Koerper gehorcht Dir nicht.\n"+
         "[Tod:Lars] Das Druecken eines Schalters hat gerade "+capitalize(getuid(this_player()))+" umgebracht.\n"+
         "[Tod:Ein Schalter] Ok, ich habs nicht getan. Es gab mich garnicht. War 'n Joke.\n");
   say(this_player()->Name(WER)+" drueckt einen Schalter.\n",this_player());      
   return 1;
}

int janein(string was) {
  if (!was) was = query_verb();
  if (was == "ja")
    write ("OK, nicht mehr dran denken. Sehr brav.\n");
  if (was == "nein")
    write("Pfffffffff. Mir doch egal.\n");
return 0;
}


string tod()
{
   write("Du findest den Tod.\n"+
         "Dein Koerper gehorcht Dir nicht.\n"+
         "[Tod:Lars] Ein Detail hat gerade "+capitalize(getuid(this_player()))+" umgebracht.\n"+
         "[Tod:Ein Detail] Ich bin der Tod!!!\n");
   if (find_call_out("resolve")==-1)
      call_out("resolve",2,this_player());
   return "";
}

int resolve(object ob)
{
  if (objectp(ob))
    tell_object(ob,"War nur Spass.\n");
}      

int wash(string was)
{
   notify_fail("Was moechtest Du Dir waschen?\n");
   if (was != "haende") return 0;
   write("Wie denn ohne Wasser?\nPffff.... Sowas.\n");
   say(this_player()->Name(WER)+" reibt seine Haende. Hat er einen Schaden?\n",
       this_player());
   return 1;
}


string det_becher()
{
   if (this_player()->QueryProp(P_GUILD)=="chaos")
     return BS("Der absolut beste Drink, den es gibt. Du kennst nichts besseres.");
   return BS("Es gibt kein ekelhafteres Gebraeu als dieses.");
}

string det_bauch()
{
   return "Schmerzen erfuellen Dich, als etwas Durch deine Bauchdecke bricht.\n"+
         "Dein Teddy knuddelt Dich ein letztes Mal.\n"+
         "Dein Koerper gehort Dir nicht.\n"+
         "[Tod:Lars] Ein Monster hat gerade "+capitalize(getuid(this_player()))+" umgebracht.\n"+
         "[Tod:Ein Monster] Ich wuchs in seinem Bauch heran!\n";         
}

kneipe(){
  string gilde;
  gilde=this_player()->QueryProp(P_GUILD);
  if(gilde=="chaos"||gilde=="bierschuettler"||gilde=="abenteurer"||
     gilde=="katzenkrieger"){
    if(deep_present("sarg",this_player())){
      write("Tsts, da hast Du wohl etwas dabei, was absoluter "+
      "Mist ist.\n");
      return 1;
    }
    this_player()->move(CHAOS_GILDEN_ROOM( "cl2_ckneipe" ),M_GO);
    return 1;
  }
  this_player()->move(CHAOS_GILDEN_ROOM( "cl2_ckneipe_fake" ),M_GO);
  return 1;
}
