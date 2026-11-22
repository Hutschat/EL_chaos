/* 11.09.98  Feuerwehr     Aenderung in zum_nichts         */   
                             
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <combat.h>
#include <new_skills.h>
#include <wizlevels.h>
#include "gilde.h"

/*
"Dies ist die Tribuene und gleichzeitig der Zugang zur gefuerchteten\n"
+"Kampfarena. Nach Suedwesten kann man die Arena betreten, wenn man fuer\n"
+"einen Kampf zugelassen wird, aber man kann auch einfach einem Kampf\n"
+"zuschauen, wenn man denn Lust dazu hat (Syntax: 'beobachte an' bzw.\n"
+"'beobachte aus'. Dies gilt nur fuer die Kampfarena! Kaempfe in der\n"
+"Duellarena, also Erzmeisterkaempfe lassen sich so nicht beobachten!\n"
+"Die Tribuene ist sehr schlicht ausgestattet. Nichtmal einen\n"
+"Bauchladenverkaeufer gibt es hier!\n" );
*/

create()
{
	::create();

SetProp(P_INT_SHORT, "Die Tribuene der Kampfarena");
SetProp( P_INT_LONG, break_string(
  "Du befindest Dich in einer grossen Halle auf einer Tribuene. Unter Dir "+
  "befindet sich die gefuerchtete Kampfarena. Die Tribuene zieht sich ganz "+
  "um die Arena herum und bietet eine glaenzende Sicht auf die Vorgaenge unter "+
  "Dir. Grosse Fackeln in den Waenden rund um die Arena tauchen alles in "+
  "ein gespenstisches, blutiges Licht. Nach unten fuehrt ein Gang in die "+
  "Arena hinein. Nach Norden fuehrt ein Durchgang aus diesem Gebaeude "+
  "heraus in den Innenhof der Burg.",78));
SetProp(P_LIGHT, 1);
SetProp( P_INDOORS, 1 ); 
AddDetail(({"halle","raum","haus","gebaeude"}),break_string(
  "Du befindest Dich in einem grossen Gebaeude in der schwarzen Burg. "+
  "Das Gebaeude ist noch sehr viel groesser, als es von aussen den Anschein "+
  "hat, und besteht aus einer einzigen Halle. Diese ist extrem hoch, wurde "+
  "tief in den Boden hineingebaut. Du befindest Dich momentan in Hoehe des "+
  "Eingangs, auf der Tribuene, und schaust hinab auf die Kampfarena. Das "+
  "ganze wird flackernd und duester beleuchtet von vielen grossen Fackeln "+
  "in den Waenden der Arena.",78));
AddDetail(({"hoehe"}),break_string(
  "Du befindest Dich hier in Hoehe des Eingangs. Aber das wusstest Du sicher "+
  "schon.",78));
AddDetail(({"eingang","ausgang"}),break_string(
  "Durch den Eingang (der eigentlich ein Ausgang ist)) kannst Du die "+
  "Tribuene verlassen und in den Innenhof der Burg kommen. Er befindet sich "+
  "noerdlich von Dir.",78));
AddDetail(({"durchgang"}),break_string(
  "Dieser Durchgang ist der Eingang der Kampfarena. Durch ihn verlaesst man "+
  "dieses Gebaeude und kommt in den Innenhof der schwarzen Burg.",78));
AddDetail(({"fackeln"}),break_string(
  "Es gibt hier Dutzende von ihnen und sie stecken in den Waenden. Hell "+
  "erleuchten sie das Geschehen in der Kampfarena unter Dir.",78));
AddDetail(({"geschehen","vorgaenge"}),break_string(
  "Hier ist ein kleiner Hinweis angebracht. Du kannst von hier aus einem "+
  "Kampf in der Kampfarena zuschaun, wenn Du Lust hast (Syntax 'beobachte "+
  "an', 'beobachte aus'. Einen Kampf in der Duellarena der Erzmeisterkaempfe "+
  "kannst Du von hier aus nicht beobachten, du kannst diese Duellarena "+
  "jedoch untersuchen, genau wie die Kampfarena hier.",78));
AddDetail(({"kampf","kaempfe"}),break_string(
  "Kaempfe sind sehr wichtig fuer Chaoten. In dieser Kampfarena werden die "+
  "Kaempfe ausgetragen, welche die Wuerdigkeit von Chaoten zeigen sollen. "+
  "In der Duellarena, welche gut versteckt anderorts liegt, werden die "+
  "Kaempfe ausgetragen, welche den neuen Erzmeister bestimmen.",78));
AddDetail(({"wuerdigkeit"}),break_string(
  "Hehe. Chaoten muessen zeigen, dass sie der naechste Gildenstufe "+
  "wuerdig sind, indem sie einen Kampf hier in der Kampfarena bestehen.",78));
AddDetail(({"erzmeister","erzmeisterkaempfe"}),break_string(
  "Wer der neue Erzmeister wird, wird durch ein Duell von mindestens drei "+
  "Meistern des Chaos entschieden. Diese Duelle finden in der Duellarena "+
  "statt, welche zwar gut versteckt ist, welche man jedoch von hier aus "+
  "untersuchen kann.",78));
AddDetail(({"duelle","duell"}),break_string(
  "Derartige Duelle sind stets sehr blutig. Deshalb soll hier nichts "+
  "weitergehendes ueber sie verraten werden.",78));
AddDetail(({"hinweis"}),break_string(
  "Den Hinweis hast Du gerade erhalten.",78));
AddDetail(({"lust"}),break_string(
  "Du musst die Kaempfe der Kampfarena natuerlich nicht beobachten, wenn "+
  "Du keine Lust hast.",78));
AddDetail(({"syntax"}),break_string(
  "Tja, mit dem Syntax hat man leicht seine Probleme. Deshalb ist es gut, "+
  "ihn so gesagt zu bekommen wie eben (-8.",78));
AddDetail(({"probleme"}),break_string(
  "Erzaehl sie irgendwem, aber nicht mir.",78));
AddDetail(({"arena"}),break_string(
  "Du musst Dich jetzt entscheiden zwischen der Kampfarena, welche sich "+
  "unter Dir befindet, und der Duellarena fuer Erzmeisterkaempfe, die "+
  "Du magischerweise ebenfalls von hier aus sehen kannst.",78));
AddDetail(({"burg","schwarze burg"}),break_string(
  "Die Kampfarena befindet sich in der schwarzen Burg, mitten in einem "+
  "Saeuresee in einem schwarzen Eisberg. Diese Burg ist etwas gewaltiges, "+
  "etwas erhabenes, etwas boesartiges, ein Monument des Chaos. Sie beher"+
  "bergt die satanische Chaosgilde, und dies ist der Grund, warum die "+
  "Kampfarena dieser Gilde sich in ihr befindet.",78));
AddDetail(({"grund"}),break_string(
  "Der Grund, dass die Kampfarena der Chaosgilde hier ist ist, dass auch "+
  "die Chaosgilde hier ist. Das sollte jetzt klar sein.",78));
AddDetail(({"see","saeuresee"}),break_string(
  "Der Saeuresee umgibt die schwarze Burg vollkommen. Die Burg erhebt sich "+
  "stolz aus ihm, gebaut auf einem gewaltigen, grauen Felsen, welchen sich "+
  "keiner so richtig erklaeren kann. Von hier aus kannst Du den See natuer"+
  "lich nicht sehen, denn dieses Gebaeude besitzt gar keine Fenster.",78));
AddDetail(({"felsen"}),break_string(
  "Der Felsen, auf dem die Burg steht, ist recht merkwuerdig. Unter anderem "+
  "gibt es keine anderen Felsen im ganzen Eisberg. Ausserdem erhebt er sich "+
  "senkrecht aus dem See und besitzt genau die richtige Groesse fuer die "+
  "Burg, welche sich auf ihm befindet. All diese merkwuerdigen Zufaelle "+
  "bringen einen schon ziemlich zum Nachdenken.",78));
AddDetail(({"eisberg","eisberge"}),break_string(
  "Der Eisberg ist ein Problem fuer sich. Waehrend normale Eisberge sich "+
  "in Jahrtausenden langsam aufschichten, ist dieser hier innerhalb weniger "+
  "Stunden entstanden, und waehrend normale Eisberge relativ weiss aussehen, "+
  "ist dieser Eisberg vollkommen schwarz. Er besteht, zumindest aussen, "+
  "aus merkwuerdigem, schwarzen Eis.",78));
AddDetail(({"jahre","jahrtausende"}),break_string(
  "Das ist schon eine verdammt lange Zeit.",78));
AddDetail(({"stunden"}),break_string(
  "Wie soll sich ein Eisberg nur derart schnell entwickelt haben? Dir ist "+
  "das voellig schleierhaft. Sicherlich hat boesartige, finstere Magie "+
  "damit zu tun.",78));
AddDetail(({"magie"}),break_string(
  "Die Magie dieser Burg und dieses Eisbergs ist furchterregend und boes"+
  "artig. Du kannst sie nicht wirklich verstehen, und Du willst es auch "+
  "nicht. Finstere, boesartige Kraefte waren dort am Werk, da bist Du "+
  "Dir sicher.",78));
AddDetail(({"kraefte"}),break_string(
  "Du weisst nicht, welche Kraefte diese Burg erschufen und den Eisberg "+
  "um sie herum, doch sie waren sicherlich boesartig und gemein.",78));
AddDetail(({"werk"}),break_string(
  "Diese Burg und der ganze Eisberg um sie herum sind sicherlich das Werk "+
  "finsterer Kraefte.",78));
AddDetail(({"zeit"}),break_string(
  "Leider hast Du deine Armbanduhr gerade nicht dabei.",78));
AddDetail(({"armbanduhr"}),break_string(
  "Du hast sie sicher irgendwo liegen gelassen und nun verloren. Nun, "+
  "sowas passiert.",78));
AddDetail(({"problem"}),break_string(
  "Natuerlich ist der Eisberg nicht wirklich ein Problem. Er ist halt ein"+
  "fach da. Du kannst ihn Dir jedoch nicht erklaeren, und das beschaeftigt "+
  "Dich. Deshalb ist er schon ein gewissen Problem, wenn auch nur "+
  "mental gesehen. Physisch gesehen kann man ihm wenig vorwerfen.",78));
AddDetail(({"eis","schwarzes eis"}),break_string(
  "Du hast noch nie von schwarzem Eis gehoert, doch es fuehlte sich "+
  "irgendwie merkwuerdig an, als Du es beruehrtes. Irgendwie aggressiv, "+
  "boesartig, anders.",78));
AddDetail(({"groesse"}),break_string(
  "Die Groesse des Felsens war gerade richtig fuer die schwarze Burg, doch "+
  "das soll nichts heissen. Es ist ja genausogut moeglich, dass man die "+
  "Burg fuer den Felsen entworfen hat und nicht den Felsen fuer die Burg... "+
  "Lange gruebelst Du ueber diese Aussage nach.",78));
AddDetail(({"aussage"}),break_string(
  "Die Aussage war, dass die Burg genausogut fuer den Felsen haette "+
  "konzipiert sein koennen anstatt der Felsen fuer die Burg. Und irgendwie "+
  "macht Dir diese Aussage zu schaffen.",78));
AddDetail(({"nachdenken"}),break_string(
  "Du gruebelst ein bisschen vor Dich hin.",78));
AddDetail(({"zufaelle"}),break_string(
  "All die Zufaelle in diesem merkwuerdigen Eisberg fuegen sich langsam zu "+
  "einem einzigen, sorgfaeltig ausgearbeiteten Plan zusammen.",78));
AddDetail(({"plan"}),break_string(
  "Das ist irgendwie witzig, denn dieser Plan wuerde bedeuten, dass der "+
  "gesamte Eisberg einzig und allein fuer die Burg konzipiert wurde und "+
  "nicht anders herum. Das ist jedoch schlicht lachhaft... Oder?",78));
AddDetail(({"fenster"}),break_string(
  "Hier gibt es keine Fenster.",78));
AddDetail(({"monument"}),break_string(
  "Die schwarze Burg ist ein gewaltiges Monument des Chaos. Sie beherbergt "+
  "die boesartige und satanische Chaosgilde. Manche behaupten sogar, sie "+
  "waere die Chaosgilde. Dies ist jedoch nicht wahr. Sie ist etwas anderes, "+
  "sie ist mehr und sehr viel dunkler, als es den Anschein haben mag.",78));
AddDetail(({"anschein"}),break_string(
  "Wenn die schwarze Burg sehr viel dunkler ist als sie aussieht, dann muss "+
  "sie wirklich extrem duester sein, denn sie besteht aus den absolut schwaer"+
  "zesten Steinen, welche Du jemals gesehen hast.",78));
AddDetail(({"steine"}),break_string(
  "Die Steine der schwarzen Burg sind absolut fuerchterlich hyperschwarz, "+
  "wenn ich das mal so sagen darf.",78));
AddDetail(({"chaosgilde","gilde"}),break_string(
  "Die Chaosgilde ist eine boesartige, dunkle Gilde, welche in dieser "+
  "Burg residiert. Die Mitglieder der Chaosgilde sind die Chaoten, und "+
  "diese koennen das Chaos beherrschen sowie Daemonen beschwoeren. All "+
  "dies macht sie aeusserst maechtig und gefaehrlich.",78));
AddDetail(({"mitglieder","chaoten","krieger","krieger des chaos"}),break_string(
  "Die Mitglieder der Chaosgilde sind die Chaoten. Oft nennt man sie auch "+
  "die Krieger des Chaos. Es gibt kaum etwas boesartigeres als einen Chaoten.",78));
AddDetail(({"chaos","macht"}),break_string(
  "Das Chaos ist eine gewaltige, unueberwindliche Macht, welche ueberall "+
  "existiert. Es ist eine zerstoererische Macht, welche jede Ordnung zu "+
  "erschuettern versucht, um letztendlich zu herrschen. Nur die Chaoten "+
  "sind in der Lage, diese Macht zumindest teilweise zu beherrschen.",78));
AddDetail(({"ordnung","gegensaetze"}),break_string(
  "Ordnung und Chaos. Die Gegensaetze dieser Welt. Sie werden niemals "+
  "friedlich koexistieren. Stets wird das Chaos versuchen, die Ordnung "+
  "zu zerstoeren, um ueber sie zu triumphieren.",78));
AddDetail(({"lage"}),break_string(
  "Warum die Chaoten in der Lage sind, das Chaos zu beherrschen, ist "+
  "ein gut gehuetetes Geheimnis.",78));
AddDetail(({"geheimnis"}),break_string(
  "Nein, das wird jetzt nicht verraten.",78));
AddDetail(({"daemonen","daemon"}),break_string(
  "Ueber Daemonen gibt es viel zu erzaehlen, doch dies ist nicht der Ort "+
  "dafuer. Frage Wuqour oder Kruuolq, die koennen Dir sicher viel darueber "+
  "erzaehlen. Daemonen sind jedenfalls boesartig und gefaehrlich. Unten "+
  "in der Kampfarena muessen Chaoten oft gegen Daemonen kaempfen, um zu "+
  "zeigen, dass sie wuerdig sind, eine neue Gildenstufe zu erreichen.",78));
AddDetail(({"ort"}),break_string(
  "Dies hier ist die Tribuene der Kampfarena. Du weisst schon :-).",78));
AddDetail(({"kruuolq","vorsteher"}),break_string(
  "Kruuolq ist der Vorsteher dieser Gilde. Er weiss viele, wichtige Dinge "+
  "ueber alles, was Chaoten angeht.",78));
AddDetail(({"wuqour","rituale","meister"}),break_string(
  "Wuqour ist der Meister der Rituale. Er kann Dir vieles erzaehlen, was "+
  "fuer einen Chaoten wichtig ist. Natuerlich nur, wenn er Dich fuer "+
  "wuerdig erachtet, mit ihm zu sprechen.",78));
AddDetail(({"stufen","gildenstufe","gildenstufen"}),break_string(
  "Diese Gilde besitzt viele Gildenstufen. Je hoeher man aufsteigt, um "+
  "so maechtigere Sprueche und Daemonen kann man beherrschen. Um auf "+
  "eine neue Gildenstufe aufzusteigen, muss man seine Sprueche ausreichend "+
  "gut beherrschen und einen Kampf in der Kampfarena gegen einen boesartigen "+
  "Daemon ueberstanden haben.",78));
AddDetail(({"sprueche"}),break_string(
  "Chaoten beherrschen viele Sprueche. Doch auch hierzu koennen Dir Wuqour "+
  "oder Kruuolq sicherlich viel mehr erzaehlen, deshalb wird hier nichts "+
  "verraten.",78));
AddDetail(({"tribuene"}),break_string(
  "Die Tribuene ist schlicht bis zum aeussersten. Keine Sitzplaetze sind zu "+
  "sehen. Kein Bauchladenverkaeufer ist in Sicht. Man steht auf dem "+
  "schwarzen Steinboden, schaut herab auf die Kampf"+
  "arena und betrachtet die Vorgaenge dort unten. Du kannst von hier aus einem "+
  "Kampf in der Kampfarena zuschaun, wenn Du Lust hast (Syntax 'beobachte "+
  "an', 'beobachte aus'. Einen Kampf in der Duellarena der Erzmeisterkaempfe "
  "kannst Du von hier aus nicht beobachten, du kannst diese Duellarena "+
  "jedoch untersuchen, genau wie die Kampfarena hier.",78));
AddDetail(({"sitzplaetze"}),break_string(
  "Verdammt, nicht mal Sitzplaetze.",78));
AddDetail(({"bauchladenverkaeufer"}),break_string(
  "Es gab hier einmal fuer kurze Zeit einen Bauchladenverkaeufer. Er wurde "+
  "nach kurzer Zeit zerhackt in einer Ecke der Tribuene gefunden. Anscheinend "+
  "war ein Zuschauer mit der Qualitaet seiner Waren nicht zufrieden gewesen. "+
  "Es ist nicht gelungen, einen Nachfolger fuer diesen Mann zu finden.",78));
AddDetail(({"nachfolger","personal"}),break_string(
  "Irgendwie hat sich niemand als Nachfolger fuer den Bauchladenverkaeufer "+
  "gemeldet. *seufz* Es ist so schwierig, gutes Personal zu finden.",78));
AddDetail(({"ecke","ecken"}),break_string(
  "Du weisst nicht, in welcher Ecke der Tribuene er aufgefunden wurde. "+
  "Man sagt sogar, dass er in mehreren Ecken aufgefunden wurde, was das "+
  "ganze noch etwas schwieriger macht.",78));
AddDetail(({"zuschauer"}),break_string(
  "Die Zuschauer hier auf der Tribuene sind meistens Chaoten.",78));
AddDetail(({"qualitaet","waren"}),break_string(
  "Haette der Bauchladenverkaeufer vorher geahnt, wie erregbar Chaoten "+
  "nach einem richtig guten Gemetzel in der Kampfarena werden, haette er "+
  "sicher besser auf die Qualitaet seiner Waren geachtet. Oder er waere "+
  "nie hierher gekommen. Beides waere sehr weise gewesen.",78));
AddDetail(({"gemetzel"}),break_string(
  "In der Kampfarena geht es oft ziemlich ab!",78));
AddDetail(({"boden"}),break_string(
  "Der Boden der Tribuene ist ein schwarzer Steinboden. Der Boden der "+
  "Kampfarena ist sicher auch interessant, doch von hier kannst Du nicht "+
  "genau bestimmen, woraus er besteht. Was immer es jedoch ist, es ist "+
  "rot.",78));
AddDetail(({"steinboden"}),break_string(
  "Wie bereits erwaehnt besteht der Boden aus schwarzen Steinen. Mehr soll "+
  "nicht dazu gesagt werden.",78));
AddDetail(({"wand","waende"}),break_string(
  "Selbst die Waende bestehen aus schwarzen Steinen, wie oede. Diverse "+
  "grosse, brennende Fackeln lockern das Ganze dann jedoch ein wenig auf "+
  "und tauchen alles in flackerndes, huschendes Licht.",78));
AddDetail(({"decke"}),break_string(
  "Die Decke ist schwarz und zu weit ueber Dir, um sie genau zu erkennen. "+
  "Du tippst auch bei ihr auf schwarze Steine.",78));
AddDetail(({"licht","finsternis","dunkelheit"}),break_string(
  "Das Licht wird hier durch viele brennende Fackeln erzeugt, welche in "+
  "den Waenden der Arena stecken. Sie tauchen dies alles hier in flackerndes "+
  "Licht.",78));
AddDetail(({"gang"}),break_string(
  "Der Gang fuehrt nach unten. Durch ihn kannst Du die Kampfarena betreten, "+
  "falls Du einen Kampf angemeldet hast.",78));
AddDetail(({"innenhof"}),break_string(
  "Geh nach Norden, schau ihn Dir an!",78));
AddDetail(({"norden"}),break_string(
  "Da kannst Du hingehen.",78));
AddDetail(({"welt"}),break_string(
  "Sie ist ueberall um Dich herum.",78));

AddSpecialDetail(({ "duellarena" }), "duell_arena" );
AddSpecialDetail(({ "kampfarena" }), "kampf_arena" );
AddDetail( "morgengrauen",
"Sowas kannst Du ueberall finden.\n");                                                          
AddSpecialExit( "unten", "betritt_arena" );
AddSpecialExit( "norden", "einfach_hier_raus" ); 
AddCmd(({ "beobachte", "beobacht", "beo" }), "beobachte_kampf" );
}

                                                   
int betritt_arena()
  {
  object *inv;
  int i;
  if( this_player()->QueryProp( P_GUILD) == "chaos" &&
    CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 
      this_player()->QueryProp( P_GUILD_LEVEL ) + 1 ))
  {
    write( "Du hast die Pruefung fuer die naechste Stufe schon bestanden.\n");
    return 1;
  }
  if( !this_player()->QueryProp( CHAOS_PRUEFUNG ))
  {
    write( "Du darfst die Kampfarena nur betreten, wenn dies bei dem Versuch einer \n"
      +"Gildenstufenerhoehung verlangt wird.\n");
    return 1;
  }
  (CHAOS_GILDEN_ROOM("ckampf.c"))->idle_raus();
  inv = all_inventory( find_object( CHAOS_GILDEN_ROOM( "ckampf" )));
  for( i = sizeof(inv)-1; i>=0; i-- )
  {
    if( !living( inv[i])) continue;
    if( !query_once_interactive( inv[i])) continue;
    if(inv[i]) 
    {              
      write( "Es ist schon jemand in der Kampfarena.\n" );
      return 1;
    }
  }
  this_player()->move( CHAOS_GILDEN_ROOM( "ckampf" ), M_GO, "in die Kampfarena");
  return 1;
}          



int einfach_hier_raus()
{  
  this_player()->SetProp( "kampf_zuschauen", 0);
  this_player()->move( C_112_ROOM("cl2bu5"), M_GO, "nach Norden");
  return 1;
}               


string kampf_arena()
{  
  int i;
  object *inv;                  
  string s;
  s = "In der Kampfarena siehst Du:\n";
  (CHAOS_GILDEN_ROOM("ckampf"))->idle_raus();
  inv = all_inventory( find_object( CHAOS_GILDEN_ROOM( "ckampf" )));
  inv = filter_array( filter_array( inv, #'living ), #'objectp );
  if( !sizeof(inv)) s += "Leider niemanden.\n";
  for( i = sizeof(inv)-1; i>=0; i-- )
  { 
    if( inv[i]->QueryProp(P_INVIS)) continue;
    s += inv[i]->short();
  }
  return s;
}
                                    

int beobachte_kampf(string str)
{
  notify_fail( "Beobachte an oder aus?\n");
  if( !str) return 0;
  if( str == "an" )
  {
    this_player()->SetProp( "kampf_zuschauen", 1);
    write( "Du beobachtest nun die Kampfarena.\n");
    return 1;
  }          
  if( str == "aus" )
  {
    this_player()->SetProp( "kampf_zuschauen", 0);
    write( "Du beobachtest die Kampfarena jetzt nicht.\n");
    return 1;
  }
  return 0;
}
 
      
string duell_arena()
{
  string s;
  int i;
  mapping arena;
  arena = ([]);
  (CHAOS_ARENA_ROOM( "no"))->argl();
  (CHAOS_ARENA_ROOM( "nw"))->argl();  
  (CHAOS_ARENA_ROOM( "so"))->argl();
  (CHAOS_ARENA_ROOM( "sw"))->argl();
  arena[ "nw" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("nw"))),
    #'living );
  arena[ "no" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("no"))),
    #'living );  
  arena[ "sw" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("sw"))),
    #'living );
  arena[ "so" ] = filter_array( all_inventory(find_object(CHAOS_ARENA_ROOM("so"))),
    #'living );
  s = "               Die Duellarena der Meister des Chaos!\n"
  +"---------------------------------------------------------------------------\n";
  for( i = 0;i<8;i++)
  {
     if( sizeof(arena["nw"]) < i+1) 
       s += sprintf( "| %-35s| ", "");
     else 
     {
       if( !interactive( arena["nw"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["nw"][i]->name()), 
           capitalize(arena["nw"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["nw"][i]->QueryProp(P_HP) );
           
       else
         s += sprintf( "| %-13s (HP: %-3d | SP: %-3d)  | ", 
           capitalize(arena["nw"][i]->name()), arena["nw"][i]->QueryProp(P_HP),
           arena["nw"][i]->QueryProp( P_SP) );
     }
     if( sizeof(arena["no"]) < i+1) 
       s += sprintf( "%-35s|\n", "");
     else 
     {
       if( !interactive( arena["no"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["no"][i]->name()), 
           capitalize(arena["no"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["no"][i]->QueryProp(P_HP) );
       else    
         s += sprintf( "%-13s (HP: %-3d | SP: %-3d)  |\n", 
           capitalize(arena["no"][i]->name()), arena["no"][i]->QueryProp(P_HP),
           arena["no"][i]->QueryProp( P_SP) );
     }
  }
  s += "---------------------------------------------------------------------------\n";
  for( i = 0;i<8;i++)
  {
     if( sizeof(arena["sw"]) < i+1) 
       s += sprintf( "| %-35s| ", "");
     else
     {
       if( !interactive( arena["sw"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["sw"][i]->name()), 
           capitalize(arena["sw"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["sw"][i]->QueryProp(P_HP) );
       else     
         s += sprintf( "| %-13s (HP: %-3d | SP: %-3d)  | ", 
           capitalize(arena["sw"][i]->name()), arena["sw"][i]->QueryProp(P_HP),
           arena["sw"][i]->QueryProp( P_SP) );
     }
     if( sizeof(arena["so"]) < i+1) 
       s += sprintf( "%-35s|\n", "");
     else
     {
       if( !interactive( arena["so"][i]))
         s += sprintf( "| %-10s von %-11s(HP:%-3d) | ",
           capitalize(arena["so"][i]->name()), 
           capitalize(arena["so"][i]->QueryProp( CHAOS_DAEM_BESCHWOERER)),
           arena["so"][i]->QueryProp(P_HP) );
       else     
         s += sprintf( "%-13s (HP: %-3d | SP: %-3d)  |\n", 
           capitalize(arena["so"][i]->name()), arena["so"][i]->QueryProp(P_HP),
           arena["so"][i]->QueryProp( P_SP) );
     }
  }
  s += "---------------------------------------------------------------------------\n";
  return s;
} 
