
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <combat.h>
#include <new_skills.h>
#include <wizlevels.h>
#include "gilde.h"

/*
"Dies ist die gefuerchtete Kampfarena der Chaosfestung wo die kaempferischen\n"
+"Faehigkeiten der Mitglieder oder der Anwaerter getestet werden. Es ist\n"
+"eigentlich nur ein leerer Raum mit sandbedecktem Boden. Das einzig\n"
+"auffaellige ist das riesige Schild.\n");
*/

create()
{
	::create();

SetProp(P_INT_SHORT, "In der Kampfarena der schwarzen Burg");
SetProp( P_INT_LONG,break_string(
  "Dies ist die gefuerchtete Kampfarena der schwarzen Burg, wo die kaempferischen "+
  "Faehigkeiten der Mitglieder oder der Anwaerter getestet werden. Hoch ueber "+
  "Dir erhebt sich die Tribuene. Fackeln beleuchten erfuellen den Raum mit "+
  "zuckenden Schatten. Ein Gang fuehrt von hier zu den Tribuenen hinauf. Ein "+
  "Schild wurde an einer der Waende angebracht.",78));
SetProp(P_LIGHT, 1);
SetProp( P_INDOORS, 1 );
AddDetail(({"arena","kampfarena","raum","halle"}),break_string(
  "Du befindest Dich in der Kampfarena der Chaosgilde. Hier musst Du einen "+
  "Kampf mit einem ueblen Daemon bestreiten, wenn Du in der Gilde aufgenommen "+
  "werden moechtest oder Deine Gildenstufe erhoehen moechtest. Doch das weisst "+
  "Du sicherlich schon alles. Alle anderen wichtigen Tips zur Arena stehen auf "+
  "dem Schild, welches hier an der Wand vor Dir angebracht wurde.",78));
AddDetail(({"schatten"}),break_string(
  "Sie zucken hin und her, als waeren sie lebendig. Wie unheimlich."));
AddDetail(({"chaosgilde","gilde"}),break_string(
  "Du weisst natuerlich, was die Chaosgilde ist. kaempfst Du in ihrer Arena :-).",78));
AddDetail(({"chaos"}),break_string(
  "Chaos rulez!",78));
AddDetail(({"kampf","kaempfe"}),break_string(
  "Die Kaempfe in dieser Arena sind meist sehr blutig und brutal. Du solltest "+
  "Dir wirklich ueberlegen, ob Du diesen Kampf durchfuehren willst. Wenn Du "+
  "dies nicht willst, solltest Du die Arena verlassen. Ansonsten stehen auf dem "+
  "Schild alle noetigen Hinweise.",78));
AddDetail(({"tips","hinweise"}),break_string(
  "Hier gibts keine Tips! :-) Naja, zumindest fast keine. Ein paar stehen auf "+
  "dem Schild, welches an eine der Waende angebracht wurde.",78));
AddDetail(({"gegner","daemon"}),break_string(
  "Dein Gegner in diesem Kampf wird ein boesartiger Daemon werden, ein fuerch"+
  "terliches, erschreckendes Biest. Du solltest Dir ueberlegen, ob Du stark "+
  "genuf fuer ihn bist...",78));
AddDetail(({"biest"}),break_string(
  "Oooooh, das wird hart.",78));
AddDetail(({"gildenstufe","erhoehung"}),break_string(
  "Als Chaot muss man vor jeder Erhoehung der Gildenstufe einen Kampf in "+
  "dieser Arena bestehen. Nur so zeigt man, dass man wuerdig ist.",78));
AddDetail(({"wuerde"}),break_string(
  "Wuerdig hat in diesmal mit Wuerde nur sehr wenig zu tun :).",78));
AddDetail(({"gang"}),break_string(
  "Der Gang fuehrt nach oben, heraus aus dieser Arena.",78));
AddDetail(({"schild"}),break_string(
  "Wow, Du kannst es lesen!",78));
AddDetail(({"burg"}),break_string(
  "Du befindest Dich in der schwarzen Burg.",78));
AddDetail(({"faehigkeiten"}),break_string(
  "Deine kaempferischen Faehigkeiten muessen ganz ausserordentlich sein, "+
  "wenn Du diesen Kampf gewinnen moechtest...",78));
AddDetail(({"mitglieder"}),break_string(
  "Ach, Du weisst schon. Die Mitglieder der Chaosgilde sind hier gemeint.",78));
AddDetail(({"anwaerter"}),break_string(
  "Jeder Anwaerter, der in der Chaosgilde aufgenommen werden will, muss hier "+
  "einen Kampf gegen einen boesartigen Daemon bestehen.",78));
AddDetail(({"tribuene","tribuenen"}),break_string(
  "Die Tribuenen werden von den flackernden Fackeln beleuchtet. Du hoerst "+
  "die wilden Anfeuerungsrufe der Chaoten, welche sich dort oben draengen, "+
  "um Deinem Sieg beizuwohnen.",78));
AddDetail(({"anfeuerungsrufe"}),break_string(
  "Sie klingen brutal und blutig, doch sie geben Dir Kraft.",78));
AddDetail(({"kraft"}),break_string(
  "Du wirst Kraft brauchen, um diesen Kampf zu bestehen.",78));
AddDetail(({"chaoten"}),break_string(
  "Sie draengen sich oben auf der Tribuene und feuern Dich an!",78));
AddDetail(({"chaot"}),break_string(
  "Chaot zu sein ist einfach das groesste!",78));
AddDetail(({"sieg"}),break_string(
  "Na, wir wollen doch mal hoffen, dass Du siegreich sein wirst!",78));
AddDetail(({"wand","waende"}),break_string(
  "Die Waende bestehen aus dunkelrot gefaerbten Steinen. Zwischen den Steinen "+
  "schauen immerwieder Knochensplitter, teils mit, teils ohne Fleischfetzen "+
  "daran, hervor.",78));
AddDetail(({"knochensplitter","splitter"}),break_string(
  "Diese Knochensplitter wurden erstaunlich weit in die Waende hineinge"+
  "trieben. Wer immer dies getan hat, muss gewaltige Kraft besessen haben. "+
  "Dies alles ist garnicht gut!",78));
AddDetail(({"kraft"}),break_string(
  "Du haettest diese Knochensplitter nicht derart weit in die Waende treiben "+
  "koennen. Wer immer das getan hat, war kraeftiger als Du!",78));
AddDetail(({"fleischfetzen","fetzen"}),break_string(
  "Diese vielen Fetzen liegen hier ueberall herum. Sie sind anscheinend zu "+
  "klein, um bei den hier ueblichen groben Saeuberungen beachtet zu werden. "+
  "Und so rotten sie hier langsam vor sich hin. Einige Fackeln ragen uebrigens "+
  "auch noch aus den Waenden und beleuchten den Raum mit ihrem flackernden "+
  "Schein.",78));
AddDetail(({"reinigung","saeuberungen"}),break_string(
  "Die Saeuberungen sind hier nie sehr gruendlich. Es ist so schrecklich "+
  "schwer, gutes Personal fuer derartige Aufgaben zu bekommen.",78));
AddDetail(({"personal"}),break_string(
  "Gutes Personal ist fuer die einen Ort wie diesen fast unmoeglich zu finden.",78));
AddDetail(({"knochen"}),break_string(
  "Nein, Knochen siehst Du hier nicht. Wenigstens diese werden wohl fort"+
  "geschafft, wenn hier sauber gemacht wird.",78));
AddDetail(({"fackeln"}),break_string(
  "Die Fackeln stecken in den Waenden. Lass sie da stecken, dann kannst Du "+
  "besser sehen.",78));
AddDetail(({"schein"}),break_string(
  "Der Schein der Fackeln ist flackernd.",78));
AddDetail(({"aufgaben"}),break_string(
  "*Huestel* Wir sprechen hier vom Reinigen der Arena.",78));
AddDetail(({"decke"}),break_string(
  "Die Decke kannst Du von hier unten nicht mehr richtig erkennen.",78));
AddDetail(({"boden"}),break_string(
  "Der Boden ist mit dunkelrotem Sand bedeckt, um das viele Blut besser auf"+
  "nehmen zu koennen. Kleine Fleischfetzen liegen vereinzelt auf ihm herum. "+
  "Es knirscht stets unangenehm, wenn Du Dich bewegst.",78));
AddDetail(({"sand"}),break_string(
  "Der Sand ist dunkelrot von all dem Blut, welches hier schon vergossen "+
  "wurde.",78));
AddDetail(({"blut"}),break_string(
  "Blut ist hier ueberall.",78));
AddDetail(({"stein","steine"}),break_string(
  "Sie sind rot gefaerbt von Blut.",78));

AddReadDetail(({ "schild", "pfeil" }),
"Wenn Du die Kampfpruefung beginnen willst, dann druecke diesen Knopf.\n"
+"Dabei gibt es aber folgendes zu beachten: Wenn Du fliehst, dann beginnt\n"
+"der Kampf beim naechsten Mal von vorne!\n"
+"Sobald Du dem Schiedsrichter zugenickt hast beginnt der Kampf sofort!\n");

AddSounds(SENSE_DEFAULT,"Von den Tribuenen jubeln Dir die Chaoten zu!\n");
AddSmells(SENSE_DEFAULT,"Es riecht nach Tod und Verwesung.\n");
AddSmells(({"tod","verwesung"}),"Igitt!\n");



// AddCmd(({ "druecke", "drueck" }), "druecke_knopf" );
AddCmd(({"ja","nick","nicke"}),"do_it");

AddSpecialExit( "oben", "verlasse_raum" );
AddItem( CHAOS_GILDEN_MON( "clausch" ), REFRESH_REMOVE );
}   

  

void init()
{
::init();
if( IS_LEARNER( this_player()) && getuid(this_player())!="feuerwehr")
  this_player()->move( "/gilden/chaos", M_GO | M_SILENT | M_NO_SHOW);
}
void reset()
{
  ::reset();
  if( !present( "Interactive", this_object())) return;
  call_out( "idle_raus", 0); 
}


idle_raus()
{
  object *inv;
  int i;
  inv = all_inventory( this_object());
  for( i = 0; i < sizeof(inv); i++ )  
  {
    if( !query_once_interactive( inv[i])) continue;
    if( query_idle(inv[i]) < 120 ) continue;
    tell_object( inv[i], "Hier darf man nicht Idlen!\n");
    inv[i]->move( CHAOS_GILDEN_ROOM( "challe"), M_TPORT );
  }
}

int verlasse_raum()
{
  object da;
  if( da = present( "\nchaos_gilden_pruefungs_daemon", this_object()))
  {
    da->verschwinde();
    write( "Du hast den Kampf nicht gewonnen! Komm spaeter wieder und versuche es nochmal.\n");
  }
  else
  {
    if( this_player()->InFight())
    {
      write( "Du kannst nicht fliehen. Es ist ein Kampf auf Leben und Tod!\n");
      return 1;
    }
  }
  this_player()->move( CHAOS_GILDEN_ROOM( "ctrib"), M_GO, "nach Nordosten");
  return 1;
}


int do_it( string str)
{
  int hp, level, mp, hands, i, st, dex;
  object daem, *inv;
  if (str!=0 && str!="schiedsrichter" && str!="schiedsrichter zu")
    return 0;
  if( this_player()->QueryProp( P_GHOST)) 
  {
    write( "Als Geist kannst Du hier nicht kaempfen.\n");
    return 1;
  }
  if( this_player()->QueryProp( P_GUILD) != "chaos" && 
    this_player()->QueryProp( CHAOS_KAMPF_BESTANDEN))
  {
    write( "Du hast doch schon einen Kampf gewonnen!\n");
    return 1;
  }
  if( CHAOS_GILDEN_MASTER->QueryPruefung( getuid(this_player()), 
    this_player()->QueryProp( P_GUILD_LEVEL) +1) )
  {
    write( "Du hast doch schon einen Kampf gewonnen!\n");
    return 1;
  } 
  if( this_player()->QueryProp( P_GUILD_LEVEL) >= 11 &&
    this_player()->QueryProp( P_GUILD) == "chaos" )
  {
    write( "Du kannst hier nur einen Kampf um den Erzmeistertitel machen!\n"+
    "Das druecken des Knopfes ist also sinnlos!\n" );
    return 1;
  }
  write( "Du drueckst den Knopf und rufst damit Deinen Gegner herbei.\n");
  hp = this_player()->QueryProp( P_MAX_HP );      
  mp = this_player()->QueryProp( P_MAX_SP );
  dex = this_player()->QueryAttribute( A_DEX );
  st =  this_player()->QueryAttribute( A_STR );
  inv = deep_inventory( this_player());
  for( i = 0; i<sizeof(inv); i++ )
  {
    if( inv[i]->id( "bumerang" )) hp += 25; 
    if( inv[i]->id( "dynamit" )) hp += 300;
    if( inv[i]->id( "eisstab" )) hp += 15;
    if( inv[i]->id( "magiering" )) hp += 15;
    if( inv[i]->id( "goblinring" )) hp += 20;
    if( inv[i]->id( "saeureball" )) hp += inv[i]->QueryProp(P_AMOUNT)*15;
    if( inv[i]->id( "flammenkugel" )) hp += inv[i]->QueryProp(P_AMOUNT)*20;
    if( inv[i]->id( "vodoonadel" )) hp += inv[i]->QueryProp(P_AMOUNT)*18;
  }
  if( this_player()->QueryProp( P_GUILD ) != "chaos" )
  {
    level = this_player()->QueryProp( P_LEVEL );
    daem = clone_object( CHAOS_GILDEN_MON( "yruruu" ));
    daem->SetAttribute( A_STR, st);
    daem->SetAttribute( A_DEX, dex);
    daem->SetProp( P_MAX_HP, hp);      
    daem->SetProp( P_HP, hp);
    daem->SetProp( P_BODY, 45 + level);
    hands = level * 12;
    if( level > 8) hands = 90 + 3 * level;
    daem->SetProp( P_HANDS, ({ " mit geballter Wut", hands, DT_SLASH }));
    if( level >= 11) daem->SetAttackChats( 20, ({ "@@spells@@" }));
    if( level >= 15 ) daem->SetProp( "kann_feuerbaelle", 1);
    daem->move( this_object(), M_GO );
    return 1;
  }
  level = this_player()->QueryProp( P_GUILD_LEVEL );   
  daem = clone_object( CHAOS_GILDEN_MON( "ziumtu" ));
  daem->SetAttribute( A_STR, st);
  daem->SetAttribute( A_DEX, dex);
  daem->SetProp( P_MAX_HP, hp);      
  daem->SetProp( P_HP, hp);
  if( this_player()->QueryProp( P_GUILD_LEVEL) < 5)
    daem->SetProp( P_BODY, level * 12);
  else daem->SetProp( P_BODY, level * 18);
  if( level >= 5 ) daem->SetAttackChats( 20, ({ "@@spells@@" }));
  if( level >= 8 ) daem->SetProp( "kann_finsternis", 1);
  hands = level * 30;
  if( level > 4) hands = 120 + 4 * level;
  daem->SetProp( P_HANDS, ({ " mit geballter Wut", hands, DT_SLASH }));
  daem->move( this_object(), M_GO);
  return 1;
}

NotifyPlayerDeath(object player, object killer, int le )
{
  if( killer->id( "yruruu")) killer->verschwinde();
  if( killer->id( "ziumtu")) killer->verschwinde();  
  if( interactive(killer) && interactive(player) )
  { 
    if( CHAOS_GILDEN_MASTER->ist_erz(killer ))
    {
      tell_object( killer, "Du hast Deinen Titel als Erzmeister erfolgreich verteidigt!\n");
      tell_object( player, "Du konntest den Erzmeister nicht besiegen!\n");
    }
    if( CHAOS_GILDEN_MASTER->ist_erz(player))
    {
      tell_object( killer, "Du hast den Erzmeister besiegt!\n" );
      tell_object( player, "Du bist kein Erzmeister mehr!\n");
      CHAOS_GILDEN_MASTER->set_erzmeister(killer, player );
    }
  } 
}
