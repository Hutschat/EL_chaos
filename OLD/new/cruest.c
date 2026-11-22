
inherit "/std/armour";

#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <language.h>
#include <wizlevels.h>
#include <new_skills.h>
#include "gilde.h"
#define bs(x) break_string( x, 78)
#define P_C_LAUSCHEN "_den_chaoten_zuhoehren_"
veraendere_stats(int flag);
int clevel = 0;
void create()
{
if( !is_clone( this_object())) return;
::create();
SetProp( P_SHORT, "Deine chaotisch mutierte Haut" );
SetProp( P_LONG,
"Die Chaosruestung ist eigentlich Deine chaotisch mutierte Haut, in der \n"
+"sich ein Chaosdaemon befindet. Sie ist dadurch viel widerstandsfaehiger \n"
+"geworden und behindert ueberhaupt nicht Deine Bewegungen (wenn der Daemon\n"
+"gut gelaunt ist).\n" );
SetProp( P_NAME, "chaotisch mutierte Haut" );
SetProp( P_GENDER, 2);
SetProp( P_ARMOUR_TYPE, AT_MISC);
SetProp( P_AC, 0 );
SetProp( P_WEIGHT, 0);
SetProp( P_BUY_VALUE, 0);
SetProp( P_CURSED, 1);
Set( P_CURSED, 1, F_QUERY_METHOD);
AddId(({ "\nchaos_ruestung", "_chaos_ruestung_", "chaosruestung", "haut",
  "chaoshaut", "mutierte haut", "chaotisch mutierte haut",
  "neue_ruestung" }));
AddCmd(({ "chaosinfo", "chaosinfos" }), "gilden_news" );
AddCmd(({ "chaoswer"}),"gilden_wer");
AddCmd(({ "csag"}),"chaossag");
AddCmd(({ "clausche"}),"clausche");
AddCmd(({ "chaossprache", "chaossag", "chaossage" }), "chaossprache" );
AddCmd(({ "verbanne" }), "verbanne_haut" );
SetDefendFunc( this_object());
SetRemoveFunc( this_object());
seteuid( getuid( this_object()));
} 
string *finde_chaoten(){
  return (map_array(
    call_other("/std/user_filter","filter_users","gilde chaos"),#'getuid));
}
int check_clevel(){
  if(this_player()->QueryProp("guild_level")<=4) return 0;
  return 1;
}
int gilden_wer(){
  object pl;
  string *tmp;
  int i;
  if(!check_clevel()) return 0;
  tmp=finde_chaoten();
  write("\tFolgende Krieger des Chaos sind momentan anwesend:\n"
        "\t--------------------------------------------------\n");
  if(i=sizeof(tmp)){
    do{
      i--;
      if(pl=find_player(tmp[i])){
        write(
        "\t\tLevel "+pl->QueryProp("guild_level")+
        "\t  "+pl->QueryProp(P_NAME)+"\n");
      }
    }while(i>0);
  }
  return 1;
}
int clausche(string str){
  if(!check_clevel()) return 0;
  if(!str){
    if(this_player()->QueryProp(P_C_LAUSCHEN)){
      write("Du lauschst den Chaoskriegern.\n");
      return 1;
    }
    write("Du lauschst den Chaoskriegern nicht.\n");
    return 1;
  }
  if(str!="ein"&&str!="aus"){
    write("'clausche' ein oder aus?\n");
    return 1;
  }
  if(str=="ein"){
    if(this_player()->QueryProp(P_C_LAUSCHEN)){
      write("Du lauschst doch schon.\n");
      return 1;
    }
    this_player()->SetProp(P_C_LAUSCHEN,1);
    write("Du lauschst nun bei den Chaoskriegern.\n");
    return 1;
  }
  if(!this_player()->QueryProp(P_C_LAUSCHEN)){
    write("Aber Du lauschst doch gar nicht.\n");
    return 1;
  }
  this_player()->SetProp(P_C_LAUSCHEN,0);
  write("Du lauschst den Chaoskriegern nicht mehr.\n");
  return 1;
}
int chaossag(string str){
  object pl;
  string *tmp,wer;
  int i;
  if(!check_clevel()) return 0;
  if(!str){
    write("Was moechtest Du den Chaoskriegern mitteilen?\n");
    return 1;
  }
  if(!this_player()->QueryProp(P_C_LAUSCHEN)){
    write("Du lauschst Doch noch gar nicht!\n");
    return 1;
  }
  wer=capitalize(this_player()->query_real_name());
  tmp=finde_chaoten();
  write(break_string(str,78,"Du sagst chaotisch: "));
  if(i=sizeof(tmp)){
    do{
      i--;
      if(getuid(this_player())!=tmp[i]){
        if(pl=find_player(tmp[i])){
          if(pl->QueryProp(P_C_LAUSCHEN)&&present("\nchaos_ruestung",pl)&&
            pl->QueryProp("guild_level")>=5){
            tell_object(pl,break_string(str,78,wer+ " sagt chaotisch: "));
          }
        }
      }
    }while(i>0); 
  }
  return 1;
}
                                                            
int verbanne_haut(string str)
{
  if( this_player()->QueryProp( P_GUILD_LEVEL) >= 7 ) return 0;
  notify_fail( "Was willst Du verbannen?\n");
  if( !id(str)) return 0;
  say( this_player()->Name()+" murmelt finstere Worte der Verbannung.\n");
  if( QueryProp( DAEM_FALSE))
    return write( "Du solltest den Daemon der Chaosruestung erstmal unter Kontrolle bringen!\n"),1;
  write( "Du murmelst finstere Worte der Verbannung! Der Daemon in Deiner Haut\n"
         "heult kurz auf und verschwindet dann.\n");
  this_player()->SetProp(P_C_LAUSCHEN,0);
  call_out( "remove_it", 0 );
  return 1;
}  

// ToDo (Bierchen)

int gilden_news()
{
this_player()->more( "/players/zardoz/texte/g_news" );
return 1;
}


int chaossprache(string str)
{
  if( !IS_LEARNER(this_player()) || !this_player()->QueryProp(P_TESTPLAYER))
     return 0;
  /* Message( s, MSGFLAG_SAY );*/
  return 1;
}
  


string short()
{
return "Deine chaotisch mutierte Haut.\n";
}


void init()
{
object env;
::init();
if( !env = environment()) return;
if( !living( env) || env->QueryProp(P_GHOST) )
  {
  call_out( "remove_it", 0);
  return;
  }
 if( QueryProp( DAEM_FALSE) && find_call_out( "chaos_chaos_chaos") == -1)
  call_out( "chaos_chaos_chaos", 1, 0); 
}


remove_zauberer(object ob, object pl)
{
   tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt Zaubererdreck ab.\n");
   ob->remove();
   if(ob) destruct(ob);
   return;
}

InsertNotify(object ob)
{
  object pl;
  if(!ob) return;
  if( !pl = QueryProp( P_WORN)) return;
  if( !interactive(pl)) return;
  if( QueryProp( DAEM_FALSE)) return;
  if(ob->id( "\nstfluch" ))
  {
    tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt die Furzkrankheit ab.\n");
    ob->remove();
    if(ob) destruct(ob);
    return;
  }
  if(ob->id( "__syph__" ))
  {
    tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt etwas Unangenehmes ab.\n");
    ob->remove();
    if(ob) destruct(ob);
    return;
  }
  
  // ohne call_out buggen die zauberer wie nix gutes.
  
  if( ob->id("\nSoundObject"))
  {
     call_out("remove_zauberer",0,ob,pl);
     return;
  } 
  if( ob->id("grippe"))
  {
     tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt die Grippe ab.\n");
     ob->remove();
     if(ob) destruct(ob);
     return;
  } 

  if( ob->id("dschungelschnupfen"))
  {
     tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt einen Schnupfen ab.\n");
     ob->remove();
     if(ob) destruct(ob);
     return;
  } 
  
  if( ob->id("malaria"))
  {
     tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt die Malaria ab.\n");
     ob->remove();
     if(ob) destruct(ob);
     return;
  } 

  if( ob->id("fieber"))
  {
     tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt Fieber ab.\n");
     ob->remove();
     if(ob) destruct(ob);
     return;
  } 

  if( ob->id("__aids__" ))
  {
     tell_object(pl, "Der Daemon Deiner Chaoshaut wehrt eine schwere Krankheit ab.\n");
     ob->remove();
     if(ob) destruct(ob);
     return;
  }    
  /* weitere Krankheiten folgen noch, erstmal die pfadnamen rausfinden... */
}    

void remove_it()
{
Set( P_CURSED, 0, F_QUERY_METHOD );
SetProp( P_CURSED, 0); 
remove();
}


void reset()
{
  object pl;
  int idle;
  ::reset();
  if( !pl = environment(this_object())) return;
  if( !interactive(pl)) return;
  if( !QueryProp( P_WORN)) 
  {
    call_out( "remove_it", 0);
    return;
  }     
  if( CHAOS_GILDEN_MASTER->ist_erz(pl)) return;
    // Der Erzmeister hat keine Probleme mit der Chaoshaut
  idle = query_idle( pl);
  if( idle > 20 ) return;
  tell_object(pl,
    "\nDER DAEMON IN DEINER HAUT WIRD GLEICH VERSUCHEN SICH ZU BEFREIEN!!!\n\n");
  SetProp( DAEM_FALSE, 1);
  call_out( "chaos_chaos_chaos", 40, 0 );
}


RemoveFunc()
{
if( !this_player()) return 1;
if( this_player()->QueryProp( P_GHOST))
  {
  Set( P_CURSED, 0, F_QUERY_METHOD);
  SetProp( P_CURSED, 0);
  }
// veraendere_stats(2);
return 1;
}

starte_anziehen( int suc)
{
object pl;
int level, rue;
if( !pl = environment()) return;
if( !query_once_interactive(pl)) return;
if( !QueryProp( P_WORN)) 
  {
  call_out( "remove_it", 0);
  return;
  }
level = QueryProp( RUEST_CASTER_LEVEL);
tell_object( pl, "Der Daemon ist in Deine Haut eingedrungen.\n");
pl->reduce_hit_point( 4 * ( 3 + level - suc/1000));
call_out( "chaos_chaos_chaos", 10, 0);
if( level < 6 ) return;
switch(random((level + 2 + suc/1000)/2))
  {
  case 0:
    tell_object( pl, "Die Chaosruestung ist ein klein wenig schlechter als erwartet.\n");
    SetProp( RUEST_ZUSATZ, -10);
    break;
  case 1..3: 
    SetProp( RUEST_ZUSATZ, 5);
    break;
  case 4..6:
    tell_object(pl, "Die Chaosruestung ist etwas besser als erwartet.\n");
      SetProp( RUEST_ZUSATZ, 10);
    call_out( "GuteRuestung", 0);
    break;
  case 7..8:
    call_out( "GuteRuestung", 0);
    SetProp( RUEST_ZUSATZ, 20);
    tell_object(pl, 
      "Die Chaosruestung ist viel besser als erwartet!\n");
    break;
  case 9..11:
    call_out( "GuteRuestung", 0);
    SetProp( RUEST_ZUSATZ, 30);
    tell_object( pl,
      "Die Chaosruestung ist absolut genial geworden!\n");
  }
  pl->AddInsertHook( this_object());
}

GuteRuestung()
{
string *schaden, dam_type, bla, *dam;
dam = ({ DT_AIR, DT_FIRE, DT_COLD, DT_WATER, DT_LIGHTNING, DT_MAGIC }); 
dam_type = dam[random(sizeof(dam))];
switch( dam_type)
  {
  case DT_AIR: bla = "stuermischen";
  break;
  case DT_FIRE: bla = "flammenden";
  break;
  case DT_COLD: bla = "frostigen";
  break;
  case DT_WATER: bla = "waessrigen";
  break;
  case DT_LIGHTNING: bla = "blitzenden";
  break;
  case DT_MAGIC: bla = "magischen";
  break;
  }
tell_object( environment(), "Die Chaosruestung schuetzt zusaetzlich vor einem "+
  bla+" Schaden.\n");
SetProp( P_LONG, QueryProp(P_LONG) 
  +"Die Chaosruestung schuetzt zusaetzlich vor einem "+bla+" Schaden.\n");
SetProp( "element_schutz", ({ dam_type }));
}


kontrolle_erfolgreich( int suc)
{
object pl;
int level;
if( !pl = environment()) return;
if( !query_once_interactive(pl)) return;
if( !QueryProp( P_WORN)) 
  {
  call_out( "remove_it", 0);
  return;
  }
level = QueryProp( RUEST_CASTER_LEVEL);
tell_object( pl, "Der Daemon baeumt sich ein letztes mal auf. Dann hast Du ihn unter Kontrolle.\n");
pl->do_damage( 4 * level - 2 * suc/1000, this_object()); 
SetProp( DAEM_FALSE, 0);
}


DefendFunc( mixed dam_type, int spell, object enemy)
{
  string schutz;
  int def;
  schutz = QueryProp( "element_schutz" );
  def = QueryProp( RUEST_ZUSATZ );     
  if( stringp(dam_type)) dam_type = ({ dam_type });
  if( member( dam_type, schutz) != -1 )
  {
    def += random( 2 * def);
  }
  return random(def);
}


chaos_chaos_chaos(int count_up)
{
object pl, daem;
int level, time;
if( !pl = environment()) return;
if( !interactive(pl))
  {
  call_out( "warte_schleife", 20, 0);
   return;
  }
if( !QueryProp( P_WORN)) 
  {
  call_out( "remove_it", 0);
  return;
  }
if( pl->QueryProp( P_GHOST))
  {
  call_out( "remove_it", 0);
  return;
  }
if( count_up == 0 && query_idle(pl) > 41 ) return;
if( query_idle(pl) > 30 )
{
    call_out( "warte_schleife", 10, 1 );
    return;
}
level = QueryProp( RUEST_CASTER_LEVEL);
if( !QueryProp( DAEM_FALSE )) return;
switch( count_up)
  {
  case 0:
    tell_object( pl, 
      "\nDER DAEMON IN DEINER HAUT FAENGT GLEICH AN ZU TOBEN!!\n\n");
    tell_room(environment(pl), pl->name()+" faengt ploetzlich an zu zucken.\n",
    ({ pl }));
    pl->reduce_hit_point( random(level));
    time = 18;
    break;
  case 1:
    call_out( "random_effekt", 0 );
    time = 12;
    break;
  case 2:
    tell_object( pl,
      bs( "Deine Haut faengt ueberall an zu brennen und zu jucken. "+
      "Es bilden sich kleine Risse, als ob etwas durch die Haut "+
      "dringen wolle."));
    tell_room(environment(pl), bs( "Unter der Haut von "+pl->name()+" bewegt sich irgend etwas, "+
      "was "+(pl->QueryProp(P_GENDER)==1?"ihm":"ihr")+
      " ueberhaupt nicht zu gefallen scheint."), ({pl }));
    pl->reduce_hit_point( random(level));
    time = 12;
    break;
  case 3:
    call_out( "random_effekt", 0);
    time = 10;
    break;
  case 4:
    call_out( "random_effekt", 0);
    time = 15;
    break;
  case 5:
    tell_object( pl,
      bs( "Du wirst bald wahnsinnig! Die Haut und der ganze Koerper "+
      "schmerzen und Du moechtest Dir am liebsten die Haut vom Leibe "+
      "reissen." ));
    tell_room(environment(pl), bs(pl->name()+" zuckt voellig unkontrolliert herum, schuettelt "+
    "sich und faengt an laut zu schreien." ),({ pl}) );
    pl->reduce_hit_point( random( level * 4));
    time = 13;
    break;
  case 6:
    call_out( "random_effekt", 0);
    time = 10;
    break;
  case 7:
    call_out( "random_effekt", 0);
    time = 9;
    break;
  case 8:
    tell_object( pl, 
      bs( "Du faengst an Dich ueberall wie wild zu kratzen und zu "+
      "schlagen. Die Schmerzen lassen Deinen Koerper zittern. Du "+
      "schwitzt tierisch, Dir wird hoellisch heiss." ));
    tell_room(environment(pl), bs("Ploetzlich schiesst Schweiss aus allen Poren von "
    +pl->name()+" heraus, "+(pl->QueryProp(P_GENDER)==1?"er":"sie")+
    " bekommt heftige Fieberanfaelle und schuettelt sich ohne Sinn und "+
    "Verstand."), ({pl }));
    pl->reduce_hit_point( random( level * 4), this_object());
    time = 11;
    break;
  case 9:
    call_out( "random_effekt", 0);
    time = 9;
    break;
  case 10:
    call_out( "random_effekt", 0);
    time = 11;
    break;
  case 11:
    tell_object( pl, 
      bs( "Du kannst Dich nicht mehr beherrschen und faengst laut "+
      "an zu Schreien, dann wirfst Du Dich mit spastischen Zuckungen "+
      "auf den Boden, waehrend der Daemon in Dir immer staerker wird."));
    tell_room(environment(pl),bs( pl->name()+" schreit laut und wirft sich in spastischen "+
    "Zuckungen zu Boden."), ({pl}));
    pl->reduce_hit_point(  random( level * 4));
    time = 9;
    break;
  case 12:
    call_out( "random_effekt", 0);
    time = 12;
    break;
  case 13:
    call_out( "random_effekt", 0);
    time = 9;
    break;
  case 14:
    tell_object( pl, 
      bs( "Du windest Dich hilflos auf dem Boden. Du kannst zwar "+
      "immer wieder kurz aufstehen und einige Schritte laufen, aber "+
      "dann kruemmt sich Dein ganzer Koerper zusammen und die "+
      "unglaublichen Schmerzen rauben Dir fast die Sinne." ));
    tell_room(environment(pl), bs( pl->name()+" windet sich hilflos auf dem Boden. "+   
      (pl->QueryProp(P_GENDER)==1?"Sein":"Ihr")+
      " Koerper kruemmt sich unter Schmerzen zusammen."), ({pl}));
    pl->do_damage( random(level * 4), this_object());
    time = 15;
    break;
  case 15:
    call_out( "random_effekt", 0);
    time = 9;
    break;
  case 16:
    call_out( "random_effekt", 0);
    time = 14;
    break;
  case 17:
    tell_object( pl,
      bs( "Die Schmerzen haben ihren Hoehepunkt erreicht. Sie werden "+
      "zwar nicht aber es sieht nicht so aus, als ob sie nachlassen "+
      "wuerden." ));
    pl->do_damage( random( level * 5), this_object());
    time = 13;
    break;
  case 18:
    call_out( "random_effekt", 0);
    time = 10;
    break;
  case 19:
    tell_object(pl, 
      bs( "An einigen Stellen bricht ploetzlich die Haut auf und "+
      "dicke Strahlen rotes Blut schiessen heraus." ));
    tell_room(environment(pl), bs( "Huch! Aus "+pl->name(WESSEN)+" Haut schiessen ploetzlich "+
    "dicke Strahlen roten Blutes heraus."), ({pl}) );
    pl->do_damage( random( level * 5), this_object());
    time = 12;
    break;
  case 20:
    call_out( "random_effekt", 0);
    time = 10;
    break;
  case 21:
    call_out( "random_effekt", 0);
    time = 11;
    break;
  case 22:
    tell_object(pl,
      bs( "Die Risse in Deiner Haut werden immer groesser und breiter. "+
      "Dir kommt es vor, als ob Du bei lebendigem Leibe gehaeutet "+
      "wuerdest." ));
    tell_room(environment(pl), bs( "Es sieht so aus, als ob sich "+pl->name()+
      " haeuten wolle." ), ({pl}));
    pl->reduce_hit_point( random( level * 5));
    time = 16;
    break;
  case 23:
    call_out( "random_effekt", 0);
    time = 11;
    break;
  case 24:
    call_out( "random_effekt", 0);
    time = 14;
    break;
  case 25:
    call_out( "random_effekt", 0);
    time = 17;
    break;
  case 26:
    tell_object(pl,
      bs( "Mit einem letzten Aufbaeumen befreit sich der Daemon aus "+
      "Deiner Haut und greift Dich sofort an." ));
    tell_room(environment(pl), bs( "Ploetzlich bricht aus "+pl->name(WESSEN)+
    " Haut ein uebler Daemon hervor, der sehr schlecht gelaunt zu sein "+
    "scheint."),({ pl}));
    pl->reduce_hit_point( level + random( level * 6));
    if( query_idle(pl) > 180 ) return;
    daem = clone_object( CHAOS_GILDEN_MON( "zurkur" ));
    daem->setze_stats( level, pl );
    daem->SetProp( DAEM_AGGRESSIVE, getuid(pl));
    daem->SetProp( CHAOS_DAEM_BESCHWOERER, getuid(pl));
    daem->SetProp( AGG_CHANCE, level * 2);
    daem->SetProp( P_MMSGOUT, "hetzt "+pl->name()+" hinterher");
    daem->move( environment(pl), M_TPORT );
    daem->Kill(pl);
    call_out( "remove_it", 0);
    return;
  }
count_up ++;
SetProp( "chaos_count_up", count_up );
call_out( "chaos_chaos_chaos", time, count_up);
}



random_effekt()
{
object pl, *inv, env;
string dir;
int level, i;
if( !pl = environment()) return;
if( !interactive(pl)) return;
if( !QueryProp(P_WORN)) 
  {
  call_out( "remove_it", 0);
  return;
  }
if( pl->QueryProp( P_GHOST))
  {
  call_out( "remove_it", 0);
  return;
  }
if( !QueryProp( DAEM_FALSE ) ) return;
level = QueryProp( RUEST_CASTER_LEVEL);    
switch( random(100))
  {
  case 0..8:
    inv = all_inventory( environment(pl));
    for( i = 0; i < sizeof( inv ); i++)
      {
      if( !living(inv[i])) continue;
      if( query_once_interactive(inv[i])) continue;
      tell_object( pl, "Der Daemon in Dir zwingt Dich zu: toete "+
        inv[i]->name()+"\n");
      if( inv[i]->id( "kruuolq") || inv[i]->id( "wuqour" ) || 
        inv[i]->id( "hutschat") || 
        (inv[i]->id( "\nchaos_gilden_daemon") && 
        inv[i]->QueryProp( CHAOS_DAEM_BESCHWOERER) == getuid(pl))  )
        {
        tell_object( pl, "Du kannst Dich gerade noch beherrschen.\n");
        break;
        }
      pl->Kill( inv[i]);
      break;
      }
    break;
  case 9:
    if( pl->QueryProp( P_BLIND)) break;
    tell_object( pl, "Der Daemon in Dir laesst Dich erblinden!\n");
    tell_room(environment(pl), pl->name()+" erblindet ploetzlich ohne sichtbaren Grund!\n",({ pl}));
    pl->SetProp( P_BLIND, 1);
    break;
  case 10..24:
    tell_object( pl, "Wie wild schmeisst Du alles von Dir!\n");
    tell_room(environment(pl), pl->name()+" schmeisst ploetzlich alles von sich.\n",({ pl}));
    pl->command_me( "wirf alles weg" );
    break;
  case 25..34:
    tell_object( pl, bs( "Dir wird einfach zu heiss! Du reisst Dir "+
    "die Kleidung vom Leibe." ));
    tell_room(environment(pl), bs( pl->name()+" scheint es zu warm zu werden. "+
      (pl->QueryProp(P_GENDER)==1?"Er":"Sie")+" reisst sich die "+
      "Kleider vom Leib.") ,({pl}));
    inv = pl->QueryProp( P_ARMOURS);
    for( i = 0;i<sizeof(inv); i++)
      {
      if( !objectp(inv[i])) continue;
      if( inv[i]->QueryProp( P_CURSED)) continue;
      pl->command_me( "ziehe "+inv[i]->QueryProp(P_IDS)[1]+
        " aus" );
      }
    break; 
  case 35..79:
    tell_object( pl,
      "Der Daemon laesst Dich unkontrolliert herumlaufen.\n");
    tell_room(environment(pl), capitalize(getuid(pl))+" laeuft unkontrolliert herum.\n",({pl}));
    env = environment(pl);
    inv = m_indices( env->QueryProp( P_EXITS ));
    inv += m_indices( env->QueryProp( P_SPECIAL_EXITS));
    if( sizeof(inv) < 1) break;
    dir = inv[random(sizeof(inv))]; 
    pl->command_me( dir );
    break;
  case 80..93:
    tell_object( pl,
       bs( "Der Daemon in Deiner Haut raubt Dir den Verstand. Du "+
       "bist wie betaeubt." ));
    tell_room(environment(pl), bs( pl->name()+" schlaegt sich immer wieder mit der Hand "+
    "gegen den Kopf." ), ({pl}));
    pl->SetProp( P_DISABLE_ATTACK, level * 3);
    break;
  case 94..99:
    tell_object( pl, "\nDir wird ploetzlich ganz uebel! Der Daemon hat Dich VERGIFTET!\n\n");
    tell_room(environment(pl), pl->name()+" wird ploetzlich ganz weiss im Gesicht.\n",({ pl}));
    pl->SetProp( P_POISON, pl->QueryProp( P_POISON) +1);
    break;
  }
}
   

warte_schleife( int zahl)
{
if( !QueryProp( DAEM_FALSE)) return;
if( interactive( environment()) && QueryProp( DAEM_FALSE))
  {
    if( query_idle( environment()) > 30 )
    {
      zahl ++;
      call_out( "warte_schleife", 30, zahl );
      return;
    }
  call_out( "chaos_chaos_chaos", 0, QueryProp( "chaos_count_up"));
  return;
  }
if( zahl > 20) return;
zahl++;
call_out( "warte_schleife", 60, zahl);
}



void verbessere_ruestung( int ac, int zeit)
{
  if( QueryProp( RUEST_SCHUTZ)) return;
  SetProp( RUEST_SCHUTZ, ac );
  SetProp( RUEST_ZUSATZ, QueryProp( RUEST_ZUSATZ) + ac );
  call_out( "verschlechtere_ruestung", zeit );
}

void verschlechtere_ruestung()
{
  int ac;
  ac = QueryProp( RUEST_ZUSATZ);
  ac -= QueryProp( RUEST_SCHUTZ);
  SetProp( RUEST_ZUSATZ, ac );
  SetProp( RUEST_SCHUTZ, 0);
  if( living( environment()))
    tell_object( environment(), "Der magische Schutz der Chaoshaut verschwindet.\n");
}

NotifyPlayerDeath(object player, object killer, int le )
{
  object pl;
  if( objectp(pl = QueryProp( P_WORN)) && pl == player)
    remove_it();
}
  