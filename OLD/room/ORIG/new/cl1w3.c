
#include "gilde.h"

inherit CHAOS_GILDEN_ROOM("cl1w_m1");

#define BS break_string
#define TP this_player()

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "Im schwarzen Eisberg");
  SetProp( P_INT_LONG, BS(
     "Hier ist es noch etwas dunkler als beim Eingang der Hoehle. "
    +"Das schwarze Eis, das Dich von allen Seiten umgibt, verbreitet Dunkelheit und "
    +"Kaelte. Im Westen scheint es etwas heller zu sein, im Norden ist es "
    +"zappenduster.",78,0,1) );

  AddDetail( ({"leiche", "leichen"}), "Du kannst keine sehen!\n");
  AddDetail( ({"eingang", "ausgang"}), "Etwas weiter im Sueden meinst Du etwas "
    +"Licht zu erkennen, vielleicht ist da der Eingang/Ausgang!?\n");
  AddDetail( ({"eishoehle", "hoehle", "ort", "umgebung"}),
     "Tust Du das nicht schon die ganze Zeit?\n");
  AddDetail( ({"farbe", "nachtschwarz"}), "Die Farbe des Eises ist Nachtschwarz!\n");
  AddDetail( ({"feind", "feinde"}), "Keine Feinde in der Naehe! Oder? :)\n");
  AddDetail( "kaelte", "Die Kaelte ist kalt. Meistens jedenfalls :)\n");
  AddDetail( "macht", "Beschaff Dir Wissen!\n");
  AddDetail( "wissen", "Na Du weisst doch: Wissen ist Macht. (aber nichts wissen macht "
    +"auch nix)\n");
  AddDetail( "naehe", "Klar, ausserdem ists nachts kaelter als draussen.\n");
  AddDetail( "schiss", "Pass auf dass das nicht in die Hose geht!\n");
  AddDetail( "hose", "Laeufst Du denn OHNE Hose rum???\n");
  AddDetail( "zentrum", "Das Zentrum ist in der Mitte.\n");
  AddDetail( "mitte", "Die Mitte ist im Zentrum.\n");
  AddDetail( "zeit", "Nimm Dir viel davon zum Untersuchen!\n");
  AddDetail( ({"wesen", "kreaturen"}), "Wesen bzw. Kreaturen sind wir doch alle, "
    +"oder?\n");
  AddDetail( "seiten", "Die Seiten umgeben das Zentrum.\n");
  AddDetail( ({"entfernung", "abstand"}), "Den Abstand zur Decke kannst Du nicht "
    +"klar bestimmen.\n");
  AddDetail( ({"eiswueste", "wueste"}), "Dazu musst Du die Hoehle verlassen!\n");
  AddDetail( ({""}), BS(
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

  AddSpecialDetail( ({"luft", "duft", "geruch", "gestank"}), "luft");
  AddSpecialDetail( ({"boden", "fussboden", "hoehlenboden"}), "boden");
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

  SetProp( P_LIGHT, -1);

  AddExit( "westen", CHAOS_GILDEN_ROOM("cl1w4") );
  AddExit( "norden", CHAOS_GILDEN_ROOM("cl1w6") );
  AddExit( "sueden", CHAOS_GILDEN_ROOM("cl1w1") );
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
     "Alles hier besteht aus dem herrlich schwarzen Eis, auch der Boden!",78);
  else
    return BS(
     "Der Boden dieser Eishoehle ist widerlich schwarz und kalt.",78);
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
