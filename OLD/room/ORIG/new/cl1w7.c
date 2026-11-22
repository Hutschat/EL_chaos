
#include "gilde.h"

inherit CHAOS_GILDEN_ROOM("cl1w_m1");

#define BS break_string
#define TP this_player()
#define TO this_object()

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "Im schwarzen Eisberg");
  SetProp( P_INT_LONG, BS(
     "Dieser Teil der Hoehle muss etwas Besonderes sein. Das schwarze Eis, das "
    +"Dich wie gewohnt von allen Seiten umgibt, verbreitet auch hier Dunkelheit und "
    +"Kaelte. Aber das Wispern und Raunen, das hier allgegenwaertig zu sein scheint, "
    +"sowie die seltsamen Zeichnungen auf dem eisigen Boden kann man einfach nicht "
    +"uebersehen.",78,0,1) );

  AddSounds( ({"raunen", "wispern"}), "Nach menschlichen Stimmen hoert sich das aber "
    +"nicht an!\n");
  AddSounds( ({"stimmen", "geraeusche", "geraeuschen"}), BS(
     "Du kannst nicht erkennen, WAS sie wispern, aber dir laeufts bei den Geraeuschen "
    +"eiskalt den Ruecken runter!",78) );
  AddDetail( ({"raunen", "wispern"}), "Richtig unheimlich!\n");

  AddDetail( ({"pentagramm"}), BS(
     "Die seltsamen Zeichnungen stellen wohl tatsaechlich ein Pentagramm dar :)",78) );
  AddDetail( ({"gilde", "gilden", "chaosgilde"}),
     "Wieviel Gilden gibts hier unten wohl?\n");
  AddDetail( "vermutung", "Besser als gar nix.\n");
  AddDetail( ({"krieger", "kaempfer"}), "Bist Du selber keiner?\n");
  AddDetail( ({"geflederten"}), "Ist nicht da.\n");
  AddDetail( ({"maak'baltzath", "beschwoerung"}), BS(
     "Das ist wohl das komplizierte Pentagramm fuer die Beschwoerung des "
    +"Geflederten!",78) );
  AddDetail( ({"dienste", "sklavendienste"}), "Sklavendienste halt!\n");
  AddDetail( ({"fluch"}), "Du weisst doch was ein Fluch ist - oder???\n");
  AddDetail( ({"urzeiten"}), BS(
     "Diese Zeiten sind laengst vergangen, aber damals war alles besser...",78) );
  AddDetail( ({"teil"}), "Dieser Ort hat eine Bestimmung. Soviel ist klar.\n");
  AddDetail( ({"bestimmung"}), "Hmm evtl. sollst Du einfach nur viel untersuchen? :)\n");
  AddDetail( ({"besonderes"}),
     "Du moechtest bestimmt wissen was!? Dann untersuch mal schoen! :)\n");
  AddDetail( ({"leiche", "leichen"}), "Du kannst keine sehen!\n");
  AddDetail( ({"eingang", "ausgang"}),
     "War der nicht irgendwo im suedlichen Teil der Hoehle?\n");
  AddDetail( ({"eishoehle", "hoehle", "ort", "umgebung"}),
     "Tust Du das nicht schon die ganze Zeit?\n");
  AddDetail( ({"farbe", "nachtschwarz"}), "Die Farbe des Eises ist Nachtschwarz!\n");
  AddDetail( ({"feind", "feinde"}), "Keine Feinde in der Naehe! Oder? :)\n");
  AddDetail( "kaelte", "Die Kaelte scheint hier noch kaelter als kalt zu sein.\n");
  AddDetail( "macht", "Beschaff Dir Wissen!\n");
  AddDetail( "wissen", "Das kann nie schaden!\n");
  AddDetail( "naehe", "Klar, ausserdem ists nachts kaelter als draussen.\n");
  AddDetail( "schiss", "Pass auf dass das nicht in die Hose geht!\n");
  AddDetail( "hose", "Fliegen die Tauben aus oder warum machst Du das?\n");
  AddDetail( "zentrum", "Das Zentrum ist in der Mitte.\n");
  AddDetail( "mitte", "Die Mitte ist im Zentrum.\n");
  AddDetail( "zeit", "Nimm Dir viel davon zum Untersuchen!\n");
  AddDetail( ({"wesen", "kreaturen"}), "Wesen bzw. Kreaturen sind wir doch alle, "
    +"oder?\n");
  AddDetail( "seiten", "Die Seiten umgeben das Zentrum.\n");
  AddDetail( ({"entfernung", "abstand"}), "Den Abstand zur Decke kannst Du nicht "
    +"klar bestimmen.\n");
  AddDetail( ({"eiswueste", "wueste"}), "Dazu musst Du die Hoehle verlassen!\n");
  AddDetail( ({"tauben"}), BS(
     "Dieses Detail konnte hier nicht ueberleben und ist bereits vor laengerer Zeit "
    +"verschieden.",78) );
  AddDetail( ({"detail", "details"}), "Welches Detail meinst Du denn?\n");
  AddDetail( "gedanke",
     "Ich denke, also bin ich. Auf orkisch: Ich fresse, also bin ich.\n");
  AddDetail( "ueberall", BS("Na ueberall halt... auf dem Boden, den Waenden und der "
    +"Decke z.B.",78) );
  AddDetail( "atmosphaere", "Duester und unheimlich...\n");
  AddDetail( "luftzug", "Hmmm, im Moment ist keiner zu sehen. :)\n");
  AddDetail( ({"moment", "augenblick"}),
     "Ein Moment dauert meist nur einen Augenblick.\n");
  AddDetail( ({"kruuolq"}),
     "Den siehst Du hier nicht.\n");

  AddSpecialDetail( ({"luft", "duft", "geruch", "gestank"}), "luft");
  AddSpecialDetail( ({"boden", "fussboden", "hoehlenboden", "zeichnung",
     "zeichnungen"}), "boden");
  AddSpecialDetail( ({"decke", "hoehlendecke"}) ,"decke");
  AddSpecialDetail( ({"dunkelheit", "dunkel", "finsternis"}), "dunkelheit");
  AddSpecialDetail( "chaos", "chaos");
  AddSpecialDetail( "licht", "licht");
  AddSpecialDetail( ({"wand", "waende"}), "waende");
  AddSpecialDetail( ({"berg", "eisberg"}), "berg");
  AddSpecialDetail( ({"eis"}), "eis");
  AddSpecialDetail( "geschmack", "geschmack");
  AddSpecialDetail( ({"schwefel", "moder", "modergeruch"}), "gerueche");
  AddSpecialDetail( ({"gefuehle", "gefuehl"}), "gefuehl");
  AddSpecialDetail( "schutz", "schutz");

  SetProp( P_LIGHT, -2);

  AddCmd( ({"konzentrier", "konzentriere", "konzentration"}), "chaos_abkuerzung");

  AddExit( "westen", CHAOS_GILDEN_ROOM("cl1w8") );
  AddExit( "suedwesten", CHAOS_GILDEN_ROOM("cl1w6") );
}


string luft()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Hier riechts richtig gut. Leichter Schwefel- und Modergeruch, durchsetzt vom "
    +"bekannten Duft vor sich hinfaulender Leichen...",78);
  else
    return BS(
     "Baeh! Hier stinkts ekelhaft nach Schwefel und Moder. Ausserdem glaubst Du "
    +"den widerlichen Gestank von verfaulenden Leichen zu erkennen!",78);
}
string boden()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das Pentagramm von Maak'Baltzath, um das es sich bei den seltsamen Zeichnungen "
    +"handelt, bedeckt den gesamten Boden. Konzentriere Dich darauf und "
    +"rufe so den Geflederten herbei, der Dich augenblicklich in die Gilde bringen "
    +"wird. So will es der seit Urzeiten wirkende Fluch Kruuolqs, der den Daemon in "
    +"die Dienste der Krieger des Chaos gezwungen hat.",78);
  else
    return BS(
     "Wilde Zeichnungen bedecken den Boden, es koennte evtl. ein Pentagramm sein, "
    +"aber das ist eine blosse Vermutung. Absolut chaotisch wuerdest Du sagen...",78);
}
string decke()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das schwarze, dunkle Eis gibt Dir ein Gefuehl des Schutzes.",78);
  else
    return BS(
     "Bei dem schwarzen, unheimlichen Eis ist es nicht leicht, die Entfernung zur "
    +"Decke zu bestimmen. Sie koennte direkt ueber Dir liegen, evtl. aber auch in "
    +"mehreren Meter Hoehe. Vielleicht senkt sie sich ja gerade, um Dich zu "
    +"erdruecken?",78);
}
string dunkelheit()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Ja, hier fuehlst Du Dich wohl! Ein Ort ganz nach Deinem Geschmack: Duester, "
    +"kalt und unheimlich.",78);
  else
    return BS(
     "Hier wirkt alles duester und bedrohlich. Kein 'normales' Wesen koennte sich "
    +"an einem derart schrecklichen Ort wohlfuehlen. Du willst doch sicherlich "
    +"zu den 'normalen' Wesen gehoeren? Dann verlass die Hoehle lieber schnell "
    +"wieder! :)",78);
}
string chaos()
{
  if(TP->QueryProp(P_RACE) == "Hobbit")   // Hobbit??? *lach*
    return BS(
     "*Bibber* Ueberhaupt bei dem Gedanken an das Chaos wird Dir so uebel, dass "
    +"Du Dich gleich mal uebergibst. Wahrscheinlich hast Du mal wieder zuviel "
    +"gefr... aeh gegessen. Auf jeden Fall: Das Chaos ist nix fuer Hobbits, weil "
    +"... Chaos ist so .........chaotisch!",78);
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Ja, dieser Ort strahlt die Macht des Chaos aus, das kannst Du deutlich fuehlen. "
    +"Das Zentrum der Macht kann nicht sehr weit entfernt sein.",78);
  else
    return BS(
     "Ein seltsames Gefuehl, dunkel und unheilvoll, schleicht zu Deinem Herzen. "
    +"Schnell konzentrierst Du Dich auf etwas anderes.",78);
}
string licht()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Licht ist der Feind der Dunkelheit, welche Du zu Deinen Verbuendeten zaehlst!",78);
  else
    return BS(
     "Das schwarze Eis der Hoehle strahlt eine gewisse Dunkelheit und Finsternis aus, "
    +"das jeglichem Licht regelrecht entgegenzuwirken scheint.",78);
}
string waende()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das schwarze, hier allesbeherrschende Eis umgibt Dich von allen Seiten und "
    +"gibt Dir ein Gefuehl des Schutzes.",78);
  else
    return BS(
     "Das schwarze, hier allesbeherrschende Eis umgibt Dich von allen Seiten. "
    +"Wenn das so weitergeht, bekommst Du noch Platzangst... Dazu kommt diese "
    +"duestere Atmosphaere hier... grauenhaft!!!",78);
}
string berg()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Du befindest Dich im Inneren des schwarzen Eisbergs. Ueberall bist Du von dem "
    +"herrlich schwarzen Eis umgeben.",78);
  else
    return BS(
     "Du befindest Dich in einem unheimlichen, schwarzen Eisberg. Schwarzes Eis? "
    +"Ja, hier scheints sowas zu geben, auch wenn Du Dir die Sache nicht erklaeren "
    +"kannst. Irgendwie unheimlich...",78);
}
string eis()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das Eis ist von nachtschwarzer Farbe und eiskalt. Einfach herrlich!",78);
  else
    return BS(
     "Normales Eis ist dies hier nicht, sonst waers wohl nicht schwarz. Na wenigstens "
    +"ist es kalt, aber das troestet Dich nicht ueber die unheimliche Atmosphaere, die "
    +"dieser Ort verbreitet, hinweg!",78);
}
string geschmack()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Dieser Ort entspricht ganz Deinem Geschmack, hier fuehlst Du Dich wohl.",78);
  else
    return BS(
     "Also der Schoepfer dieses Raumes hat bestimmt keinen, da bist Du Dir sicher. "
    +"Welches kranke Wesen mag sich an solch einem Ort wohlfuehlen?",78);
}
string gerueche()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Ein herrlicher Geruch.",78);
  else
    return BS(
     "Pfui stinkt das! Dir wird ganz uebel bei so nem Gestank!",78);
}
string gefuehl()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Gefuehle hast Du als Kaempfer des Chaos ja normalerweise nicht, aber wohlfuehlen "
    +"tust Du Dich hier!",78);
  else
    return BS(
     "Du hast wohl Schiss!?",78);
}
string schutz()
{
  if(TP->QueryProp(P_GUILD) == "chaos")   // Chaot???
    return BS(
     "Das kalte, schwarze Eis vermittelt Dir ein Gefuehl des Schutzes.",78);
  else
    return BS(
     "Den haettest Du wohl gerne hier, was?",78);
}

int chaos_abkuerzung(string str)
{
  string titel,wem;
  notify_fail( "Auf WAS willst Du Dich konzentrieren?\n");
  if(!str) return 0;
  if( str!="auf pentagramm" && str != "dich auf pentagramm") return 0;
  if( TP->QueryProp(P_GUILD) != "chaos" )   // Kein Chaot ?
  {
    tell_room( TO, BS("Das Pentagramm beginnt unheilig zu gluehen.\n"
      +"Schwarze Blitze loesen sich daraus und treffen "+TP->Name(WEN)+".\n"
      +TP->Name(WER)+" kruemmt sich vor Schmerzen.",78,0,1), ({TP}) );
    tell_object( TP, BS("Das Pentagramm beginnt unheilig zu gluehen.\n"
      +"Schwarze Blitze loesen sich daraus und treffen Dich.\n"
      +"Du kruemmst Dich vor Schmerzen!",78,0,1) );
    TP->reduce_hit_point( 20 + random(50) );
    return 1;
  }
  else   // Nur wenn sichs um nen CHAOS-krieger handelt... :)
  {
    if( TP->QueryProp(P_GENDER) == MALE) wem="dem heftig zappelnden Chaoten";
    if( TP->QueryProp(P_GENDER) == FEMALE) wem="der heftig zappelnden Chaotin";
    if( TP->QueryProp(P_GENDER) == NEUTER) wem="dem heftig zappelnden Etwas";
    if( TP->QueryProp(P_GUILD_LEVEL) < 8)
    {
      titel="Krieger des Chaos";
      if( TP->QueryProp(P_GENDER) == FEMALE) titel="Kriegerin des Chaos";
    }
    else
    {
      titel="";
      if( sizeof(TP->QueryProp(P_GUILD_TITLE)) > 4)
        titel=TP->QueryProp(P_GUILD_TITLE)[4..];
    }
    tell_room( TO, BS("Das Pentagramm beginnt unheilig zu gluehen.\n"
      +"Die Dunkelheit verdichtet sich, und ein geflederter Daemon erscheint.\n"
      +"Der Daemon bruellt: Komm mit mir, "+TP->Name(WER)+", "+titel+"!",78,0,1) );
    tell_object( TP, BS("Der Daemon packt Dich und laedt Dich nach kurzem Flug mitten "
      +"in der Gilde ab.",78) );
    TP->move("/gilden/chaos", M_GO|M_NOCHECK|M_SILENT);
    tell_room( environment(TP), BS( TP->Name(WER)+" wird von einem geflederten Daemon "
      +"hereingetragen.",78), ({TP}) );
    tell_room( TO, BS("Der Daemon packt "+TP->Name(WEN)+ " und verschwindet mit "
      +wem+" in der Finsternis.",78) );
    return 1;
  }
}
