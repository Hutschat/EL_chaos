// chaosruestung.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 11.03.2019 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            Fehler für neuen Driver behoben

#pragma no_inherit
#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/armour";


static int     clevel = 0;
static string *chaos_erlaubt;

// Urgs, extra-abfrage fuer den erzmeister, das hat wohl vorher
// gebuggt.

// Prototypen für Closures
void GuteRuestung();
void chaos_chaos_chaos(int count_up);
void random_effekt();
void remove_it();
static void warte_schleife(int zahl);

static int check_erzie(object pl)
{
  if((pl->QueryProp(P_GUILD)=="chaos") &&
     (pl->QueryProp(P_GUILD_LEVEL)==12))
  {
    if((CHAOS_GILDENMASTER->ist_erz(pl)) == 1)
    {
      tell_object(pl,break_string("Der Daemon in Deiner Haut "
      "unterwirft sich fluchend Deiner Macht!"));

      SetProp(DAEM_FALSE,0);

      SetProp("chaos_count_up",0);

      return 1;
    }
  }
  return 0;
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT,"Deine chaotisch mutierte Haut" );
  SetProp(P_LONG,
  "Die Chaosruestung ist eigentlich Deine chaotisch mutierte Haut, in der "
  "sich ein Chaosdaemon befindet. Sie ist dadurch viel "
  "widerstandsfaehiger geworden und behindert ueberhaupt nicht Deine "
  "Bewegungen (wenn der Daemon gut gelaunt ist).");

  SetProp(P_NAME,"chaotisch mutierte Haut" );
  SetProp(P_GENDER,FEMALE);
  SetProp(P_ARMOUR_TYPE, AT_MISC);
  SetProp(P_AC,0);
  SetProp(P_WEIGHT,0);
  SetProp(P_BUY_VALUE,0);

  SetProp(P_MATERIAL,
  ([
    MAT_SKIN:80,
    MAT_LIVING:10,
    MAT_SHADOW:5,
    MAT_MAGIC_BLACK:5,
  ]));
  Set(P_CURSED,1,F_QUERY_METHOD);
  AddId(({"\nchaos_ruestung","_chaos_ruestung_","chaosruestung","haut",
  "chaoshaut","mutierte haut","chaotisch mutierte haut",
  "neue_ruestung"}));

  AddCmd(({"verbanne"}),"verbanne_haut" );

  AddCmd(({
    "chaosinfo","chaosinfos",
    "chaoswer",
    "chaoslausch","chaoslausche",
    "chaossag","chaossage",
    "chaoshist","chaoshistory",
    "chaosemote",
    "chaosblockade"}),"ccommands");

  AddCmd(({"ende"}),
    "check_hautdaemon");

  SetProp(P_DEFEND_FUNC,ME);
  SetProp(P_REMOVE_FUNC,ME);
  SetProp(P_WEAR_FUNC,ME);

  seteuid(getuid(ME));
  chaos_erlaubt=
  ({
  });
} 

static int check_hautdaemon()
{
  if(find_call_out(#'chaos_chaos_chaos)!=-1 &&!(PL->InFight()))
  {
     tell_object(PL,break_string("Der Daemon in Deiner Haut hindert Dich "
                    "daran! Wahrscheinlich will er Dich noch etwas quaelen!"));
     return 1;
  }
  return 0;
}

static int check_prev(object obj)
{
  string fname;

  if(obj)
    fname = explode(file_name(obj),"#")[0];

  if (obj && query_once_interactive(obj))
    return 1; // fuer remove_it in die()

  if(obj&&fname)
  {
    if(fname[0..13]=="/gilden/chaos/")
        return 1;

    else if(member(chaos_erlaubt,fname)!=-1)
      return 1;

    else
    {
      SetProp(DAEM_FALSE,0);
      return 0;
    }
  }
  SetProp(DAEM_FALSE,0);
  return 0;
}
                                                                    
int WearFunc(object me, int silent)
{
  if(PL->QueryProp(P_GUILD)=="chaos")
    return 1;

  if(!silent)
  {
    write("Als Nicht-Chaot ist Dir diese Haut nicht untertan und "
          "verschwindet.\n");

    ME->remove();

    if(ME) destruct(ME);
  } 
  return 0;
}     

int ccommands(string str)
{
  (CHAOS_HAUTMASTER)->chaos_input(query_verb(),str,PL);
  return 1;
}

int _query_curse()
{
  return 1;
}                                                            

static int verbanne_haut(string str)
{
  if(PL->QueryProp(P_GUILD_LEVEL)>=7)
    return 0;

  notify_fail("Was willst Du verbannen?\n");
  
  if(!id(str))
    return 0;

  say(PL->Name(WER,1)+" murmelt finstere Worte der Verbannung.\n");
  
  if(QueryProp(DAEM_FALSE))
  {
    return write("Du solltest den Daemon der Chaosruestung erstmal unter "
                 "Kontrolle bringen!\n"),1;
  }
  write(break_string("Du murmelst finstere Worte der Verbannung! Der Daemon "
        "in Deiner Haut heult kurz auf und verschwindet dann."));

  PL->SetProp(P_C_LAUSCHEN,0);

  call_out(#'remove_it,0);

  return 1;
}  

string short()
{
  if(PL == environment(ME))
    return "Deine chaotisch mutierte Haut.\n";

  else
    return "Eine chaotisch mutierte Haut.\n";
}

varargs void init()
{
  object env;
  ::init();
  if(!env=environment())
    return;

  if(!living(env) || env->QueryProp(P_GHOST))
  {
    call_out( #'remove_it, 0);
    return;
  }
  if(QueryProp(DAEM_FALSE) && find_call_out(#'chaos_chaos_chaos)==-1)
    call_out(#'chaos_chaos_chaos,1,0); 
}

void remove_it()
{
  object prev;

  if(!(prev=previous_object()) || !check_prev(prev))
    return;

  Set(P_CURSED,0,F_QUERY_METHOD);
  SetProp(P_CURSED,0); 
  remove();
}

void reset()
{
  object pl;
  object prev;
  int idle;
  ::reset();
/*  if(prev=previous_object())
  {
    if(objectp(prev)&&!check_prev(prev))
    {
      SetProp(DAEM_FALSE,0);
      return;
    }
  }
*/
  if(!(pl=environment(ME)) || !interactive(pl))
    return;

  if(!QueryProp(P_WORN))
  {
    call_out(#'remove_it,0);
    return;
  }     
    // Der Erzmeister hat keine Probleme mit der Chaoshaut,
    // Geister auch nicht...
  if(CHAOS_GILDENMASTER->ist_erz(pl) || pl->QueryProp(P_GHOST))
  {
    SetProp(DAEM_FALSE,0);
    return;
  }
  idle = query_idle(pl);

  if(idle>=30)
    return;

  tell_object(pl,
    "\nDER DAEMON IN DEINER HAUT WIRD GLEICH VERSUCHEN SICH ZU "
    "BEFREIEN!!!\n\n");

  SetProp(DAEM_FALSE,1);

  if(find_call_out(#'chaos_chaos_chaos)==-1)
    call_out(#'chaos_chaos_chaos,40,0);
}

int RemoveFunc()
{
  if(!PL)
    return 1;

  if(PL->QueryProp(P_GHOST))
  {
    Set(P_CURSED,0,F_QUERY_METHOD);
    SetProp(P_CURSED,0);
  }
  return 1;
}

void starte_anziehen(int suc)
{
  object pl;
  int level, rue, ruest_rand;

  if(!(pl=environment(ME)) || !interactive(pl)) 
    return;

  if(!QueryProp(P_WORN))
  {
    call_out(#'remove_it,0);
    return;
  }
  level = QueryProp(RUEST_CASTER_LEVEL);

  tell_object(pl,"Der Daemon ist in Deine Haut eingedrungen!\n");

  if(pl->QueryProp("guild_level")>=8)
    pl->SetProp(P_C_LAUSCHEN,1);

  pl->reduce_hit_point(4*(3+level-suc/1000));

  if(!(CHAOS_GILDENMASTER->ist_erz(pl)) &&
     find_call_out(#'chaos_chaos_chaos)==-1)
    call_out(#'chaos_chaos_chaos,10,0);

  if(level<6)
    return;

  if(pl->QueryProp("guild_level")<11)
    ruest_rand = random((level+2+suc/1000)/2);

  // Perfektes Koennen
  else if(pl->QuerySkillAbility("chaosruestung")==10000)
    ruest_rand=12;

  else
    ruest_rand = random((level+2+suc/1000)/2)+
                 random((pl->QuerySkillAbility("chaosruestung")/2000))+1;

  switch(ruest_rand)
  {
    case 0:
      tell_object(pl,"Die Chaosruestung ist ein klein wenig schlechter als "
                     "erwartet.\n");
      SetProp(RUEST_ZUSATZ,-10);
      break;
    case 1..3: 
      SetProp(RUEST_ZUSATZ,5);
      break;
    case 4..6:
      tell_object(pl,"Die Chaosruestung ist etwas besser als erwartet.\n");
      SetProp(RUEST_ZUSATZ,10);
      call_out(#'GuteRuestung,0);
      break;
    case 7..8:
      call_out(#'GuteRuestung,0);
      SetProp(RUEST_ZUSATZ,20);
      tell_object(pl,"Die Chaosruestung ist viel besser als erwartet!\n");
      break;
    default:
      call_out(#'GuteRuestung,0);
      SetProp(RUEST_ZUSATZ,30);
      tell_object(pl,"Die Chaosruestung ist absolut genial geworden!\n");
  }
  pl->AddInsertHook(ME);
}

void GuteRuestung()
{
  string *schaden,dam_type,bla,*dam;

  dam      = ({DT_AIR,DT_FIRE,DT_COLD,DT_WATER,DT_LIGHTNING,DT_MAGIC}); 
  dam_type = dam[random(sizeof(dam))];

  switch(dam_type)
  {
    case DT_AIR: 
      bla="stuermischen";
      break;
    case DT_FIRE: 
      bla="flammenden";
      break;
    case DT_COLD: 
      bla="frostigen";
      break;
    case DT_WATER: 
      bla="waessrigen";
      break;
    case DT_LIGHTNING: 
      bla="blitzenden";
      break;
    case DT_MAGIC: 
      bla="magischen";
      break;
  }
  tell_object(environment(),"Die Chaosruestung schuetzt zusaetzlich vor "
                            "einem "+bla+" Schaden.\n");

  SetProp(P_LONG,QueryProp(P_LONG) 
                +"Die Chaosruestung schuetzt zusaetzlich vor einem "+bla+
                 " Schaden.\n");

  SetProp("element_schutz",({dam_type}));
}

void kontrolle_erfolgreich(int suc)
{
  object pl;
  int level;

  if(!(pl=environment()) || !interactive(pl))
    return;

  if(!QueryProp(P_WORN))
  {
    call_out(#'remove_it,0);
    return;
  }
  level = QueryProp(RUEST_CASTER_LEVEL);

  tell_object(pl,"Der Daemon baeumt sich ein letztes mal auf. Dann hast "
                 "Du ihn unter Kontrolle.\n");
  
  pl->do_damage(4*level-2*suc/1000,ME); 
  
  SetProp(DAEM_FALSE, 0);
}

int DefendFunc(mixed dam_type, int spell, object enemy)
{
  string schutz;
  int def;
  object pl;

  pl=environment(ME);

  if(living(pl) && pl->QueryProp(P_FROG) && pl->QueryProp(P_GUILD)=="chaos")
  {
    if(pl->QueryProp("guild_level")>=9)
    {
      pl->SetProp(P_FROG,0);
      tell_room(environment(pl),break_string("Ein Daemon lacht und "
                                "verwandelt "+pl->name(WEN)+" zurueck!"),
                                ({pl}));

      tell_object(pl,break_string("Der Daemon in Deiner Haut lacht ueber "
                     "Froesche und verwandelt Dich zurueck!"));
    }
  }
  schutz = QueryProp("element_schutz");
  def    = QueryProp(RUEST_ZUSATZ);     

  if(stringp(dam_type))
    dam_type = ({dam_type});

  if(member(dam_type,schutz)!=-1)
    def += random(2*def);

  return random(def);
}

void chaos_chaos_chaos(int count_up)
{
  object pl, daem,prev;
  int level, time;

  if(!pl=environment(ME))
    return;

  if(!(prev=previous_object()))
  {
    SetProp(DAEM_FALSE,0);
    return;
  }
  if(!(prev==ME))
    if(!check_prev(prev))
    {
      SetProp(DAEM_FALSE,0);
      return;
    }

  if(!interactive(pl))
  {
    call_out(#'warte_schleife,20,0);
    return;
  }
  if(!QueryProp(P_WORN) || pl->QueryProp(P_GHOST))
  {
    call_out(#'remove_it,0);
    return;
  }
  if(count_up==0 && query_idle(pl)>41)
    return;

  if(query_idle(pl)>30)
  {
    if(find_call_out(#'warte_schleife)==-1)
      call_out(#'warte_schleife,10,1);

    return;
  }
  level = QueryProp(RUEST_CASTER_LEVEL);

  if(!QueryProp(DAEM_FALSE))
    return;

  switch(count_up)
  {
    case 0:
      tell_object(pl,"\nDER DAEMON IN DEINER HAUT FAENGT GLEICH AN ZU "
      "TOBEN!!\n\n");
      if(check_erzie(pl))
      {
        if(find_call_out(#'chaos_chaos_chaos)!=-1)
          while (remove_call_out(#'chaos_chaos_chaos)!=-1);

        return;
      }
      tell_room(environment(pl),pl->Name(WER,1)+" faengt ploetzlich an zu "
                                "zucken.\n",({pl}));
      pl->reduce_hit_point(random(level));
      time = 18;
      break;

    case 1:
      call_out(#'random_effekt,0);
      time = 12;
      break;

    case 2:
      tell_object(pl,break_string("Deine Haut faengt ueberall an zu brennen "
                     "und zu jucken. Es bilden sich kleine Risse, als ob "
                     "etwas durch die Haut dringen wolle!"));

      tell_room(environment(pl),
                break_string("Unter der Haut von "+pl->Name(WEM,1)+" bewegt "
                "sich irgend etwas, was "+
                (pl->QueryProp(P_GENDER)==1?"ihm":"ihr")+" ueberhaupt nicht "
                "zu gefallen scheint."),({pl}));

      pl->reduce_hit_point( random(level));
      time = 12;
      break;

    case 3:
      call_out(#'random_effekt,0);
      time = 10;
      break;

    case 4:
      call_out(#'random_effekt,0);
      time = 15;
      break;

    case 5:
      tell_object(pl,break_string("Du wirst bald wahnsinnig! Die Haut und "
                     "der ganze Koerper schmerzen und Du moechtest Dir am "
                     "liebsten die Haut vom Leibe reissen!"));

      tell_room(environment(pl),
                break_string(pl->Name(WER,1)+" zuckt voellig unkontrolliert "
                "herum, schuettelt sich und faengt an laut zu schreien."),
                ({pl}));

      pl->reduce_hit_point(random(level*4));
      time = 13;
      break;

    case 6:
      call_out(#'random_effekt,0);
      time = 10;
      break;

    case 7:
      call_out(#'random_effekt,0);
      time = 9;
      break;

    case 8:
      tell_object(pl,break_string("Du faengst an, Dich ueberall wie wild zu "
                     "kratzen und zu schlagen. Die Schmerzen lassen Deinen "
                     "Koerper zittern. Du schwitzt tierisch, Dir wird "
                     "hoellisch heiss!"));

      tell_room(environment(pl),
                break_string("Ploetzlich schiesst Schweiss aus allen Poren "
                "von "+pl->name(WEM,1)+" heraus, "+
                (pl->QueryProp(P_GENDER)==1?"er":"sie")+" bekommt heftige "
                "Fieberanfaelle und schuettelt sich ohne Sinn und "
                "Verstand."),({pl}));
      pl->reduce_hit_point(random(level*4),ME);
      time = 11;
      break;

   case 9:
     call_out(#'random_effekt,0);
     time = 9;
     break;

   case 10:
     call_out(#'random_effekt,0);
     time = 11;
     break;

   case 11:
     tell_object(pl,break_string("Du kannst Dich nicht mehr beherrschen und "
                   "faengst laut an zu Schreien, dann wirfst Du Dich mit "
                   "spastischen Zuckungen auf den Boden, waehrend der Daemon "
                   "in Dir immer staerker wird!"));

     tell_room(environment(pl),
               break_string(pl->Name(WER,1)+" schreit laut und wirft sich "
               "in spastischen Zuckungen zu Boden."),({pl}));
     pl->reduce_hit_point(random(level*4));
     time = 9;
     break;

   case 12:
     call_out(#'random_effekt,0);
     time = 12;
     break;

   case 13:
     call_out(#'random_effekt,0);
     time = 9;
     break;

   case 14:
     tell_object(pl,break_string("Du windest Dich hilflos auf dem Boden. Du "
                    "kannst zwar immer wieder kurz aufstehen und einige "
                    "Schritte laufen, aber dann kruemmt sich Dein ganzer "
                    "Koerper zusammen und die unglaublichen Schmerzen rauben "
                    "Dir fast die Sinne."));

     tell_room(environment(pl),
               break_string(pl->Name(WER,1)+" windet sich hilflos auf dem "
               "Boden. "+(pl->QueryProp(P_GENDER)==1?"Sein":"Ihr")+
               " Koerper kruemmt sich unter Schmerzen zusammen."),({pl}));
     pl->do_damage(random(level*4),ME);
     time = 15;
     break;

   case 15:
     call_out(#'random_effekt,0);
     time = 9;
     break;

   case 16:
     call_out(#'random_effekt,0);
     time = 14;
     break;

   case 17:
     tell_object(pl,break_string("Die Schmerzen haben ihren Hoehepunkt "
                    "erreicht, aber es sieht nicht so aus, als ob sie "
                    "nachlassen wuerden."));

     pl->do_damage(random(level * 5),ME);
     time = 13;
     break;

   case 18:
     call_out(#'random_effekt,0);
     time = 10;
     break;

   case 19:
     tell_object(pl,break_string("An einigen Stellen bricht ploetzlich die "
                    "Haut auf und dicke Strahlen rotes Blut schiessen "
                    "heraus."));
     
     tell_room(environment(pl),
               break_string("Huch! Aus "+pl->name(WESSEN,1)+" Haut "
               "schiessen ploetzlich dicke Strahlen roten Blutes heraus."),
               ({pl}));
     pl->do_damage(random(level * 5),ME);
     time = 12;
     break;

   case 20:
     call_out( #'random_effekt,0);
     time = 10;
     break;

   case 21:
     call_out(#'random_effekt,0);
     time = 11;
     break;

   case 22:
     tell_object(pl,break_string("Die Risse in Deiner Haut werden immer "
                    "groesser und breiter. Dir kommt es vor, als ob Du bei "
                    "lebendigem Leibe gehaeutet wuerdest!"));

     tell_room(environment(pl),
               break_string("Es sieht so aus, als ob sich "+pl->name(WER,1)+
               " haeuten wolle."),({pl}));
     pl->reduce_hit_point(random(level*5));
     time = 16;
     break;
 
   case 23:
     call_out(#'random_effekt,0);
     time = 11;
     break;

   case 24:
     call_out(#'random_effekt,0);
     time = 14;
     break;

   case 25:
     call_out(#'random_effekt,0);
     time = 17;
     break;

   case 26:
     tell_object(pl,break_string("Mit einem letzten Aufbaeumen befreit sich "
                    "der Daemon aus Deiner Haut und greift Dich sofort an!"));
     tell_room(environment(pl), 
               break_string("Ploetzlich bricht aus "+pl->name(WESSEN,1)+
               " Haut ein uebler Daemon hervor, der sehr schlecht gelaunt "
               "zu sein scheint."),({pl}));
     
     pl->reduce_hit_point(level+random(level*6));
    
     if(query_idle(pl)>180)
       return;
    
     daem = clone_object(CHAOS_GILDEN_MON("zurkur"));
     
     daem->setze_stats(level,pl);
     daem->SetProp(DAEM_AGGRESSIVE,getuid(pl));
     daem->SetProp(CHAOS_DAEM_BESCHWOERER,getuid(pl));
     daem->SetProp(AGG_CHANCE,level*2);
     daem->SetProp(P_MMSGOUT,"hetzt "+pl->name(WEN,1)+" hinterher");
     daem->move(environment(pl),M_TPORT );
     daem->Kill(pl);
     call_out(#'remove_it,0);
     return;
  }
  count_up++;
  SetProp("chaos_count_up",count_up);
  call_out(#'chaos_chaos_chaos,time, count_up);
}

void random_effekt()
{
  object pl, *inv, env;
  object prev;
  string dir;
  int level, i;
  
  if(!pl=environment())
    return;
  
  if(!interactive(pl))
    return;
  
  if(!QueryProp(P_WORN)||pl->QueryProp(P_GHOST))
  {
    call_out(#'remove_it,0);
    return;
  }
  if(!(prev=previous_object()) || !check_prev(prev) ||
     !QueryProp(DAEM_FALSE))
    return;

  level = QueryProp(RUEST_CASTER_LEVEL);    

  switch(random(100))
  {
    case 0..8:

      inv = all_inventory(environment(pl));

      foreach(object ob : inv)
      {
        if(!living(ob)||query_once_interactive(ob))
          continue;

        tell_object(pl,"Der Daemon in Dir zwingt Dich zu: toete "+
        ob->name()+"\n");
        if(ob->id("kruuolq")||
           ob->id("wuqour")|| 
           ob->id("hutschat") || 
          (ob->id("\nchaos_gilden_daemon") && 
           ob->QueryProp(CHAOS_DAEM_BESCHWOERER)==getuid(pl)))
        {
          tell_object(pl,"Du kannst Dich gerade noch beherrschen.\n");
          break;
        }
        pl->Kill(ob);
        break;
      }
    break;

  case 9:
    if(pl->QueryProp(P_BLIND))
      break;

    tell_object(pl,"Der Daemon in Dir laesst Dich erblinden!\n");
    
    tell_room(environment(pl),
              pl->Name(WER,1)+" erblindet ploetzlich ohne sichtbaren "
              "Grund!\n",({pl}));

    pl->SetProp(P_BLIND,1);
    break;

  case 10:
    if(pl->QueryProp(P_DEAF))
      break;

    tell_object(pl,"Der Daemon in Dir bruellt Dich fuerchterlich an! Du "
                   "bist taub!\n");

    tell_room(environment(pl),
             pl->Name(WER,1)+" haelt sich ploetzlich die Ohren zu!\n",({pl}));
    pl->SetProp(P_DEAF,1);
    break;

  case 11..24:
    tell_object(pl,"Wie wild schmeisst Du alles von Dir!\n");

    tell_room(environment(pl),
              pl->Name(WER,1)+" schmeisst ploetzlich alles von "
              "sich.\n",({pl}));

    pl->command_me("wirf alles weg");
    break;

  case 25..34:
    tell_object(pl,break_string("Dir wird einfach zu heiss! Du reisst Dir "
                   "die Kleidung vom Leibe."));

    tell_room(environment(pl),
              break_string(pl->Name(WER,1)+" scheint es zu warm zu "
              "werden. "+(pl->QueryProp(P_GENDER)==1?"Er":"Sie")+" reisst "
              "sich die Kleider vom Leib."),({pl}));
    
    inv = pl->QueryProp(P_ARMOURS);
    
    foreach(object arm : inv)
    {
      if(!objectp(arm)||arm->QueryProp(P_CURSED))
        continue;

      pl->command_me("ziehe "+arm->QueryProp(P_IDS)[2]+" aus" );
    }
    break; 

  case 35..79:
    tell_object(pl,"Der Daemon laesst Dich unkontrolliert herumlaufen.\n");

    tell_room(environment(pl),
              pl->Name(WER,1)+" laeuft unkontrolliert herum.\n",({pl}));

    env  = environment(pl);
    inv  = m_indices(env->QueryProp(P_EXITS));

    if(sizeof(inv)<1)
      break;

    dir = (string) inv[random(sizeof(inv))]; 
    pl->command_me(dir);
    break;

  case 80..93:
    tell_object(pl,break_string("Der Daemon in Deiner Haut raubt Dir den "
                   "Verstand. Du bist wie betaeubt."));
    
    tell_room(environment(pl),
              break_string(pl->Name(WER,1)+" schlaegt sich immer wieder "
              "mit der Hand gegen den Kopf."),({pl}));
    pl->SetProp(P_DISABLE_ATTACK,level*3);
    break;
  
  case 94..99:
    tell_object(pl,"\nDir wird ploetzlich ganz uebel! Der Daemon hat Dich "
                   "VERGIFTET!\n\n");
    
    tell_room(environment(pl),
              pl->Name(WER,1)+" wird ploetzlich ganz weiss im Gesicht.\n",
              ({pl}));

    pl->SetProp(P_POISON,pl->QueryProp(P_POISON)+1);
    break;
  }
}
   
static void warte_schleife(int zahl)
{
  if(!QueryProp(DAEM_FALSE))
    return;

  if(interactive(environment()) && QueryProp(DAEM_FALSE))
  {
    if(query_idle(environment())>30)
    {
      zahl ++;
      call_out(#'warte_schleife,30,zahl);
      return;
    }
    call_out(#'chaos_chaos_chaos,0,QueryProp("chaos_count_up"));
    return;
  }
  if(zahl>20)
    return;

  zahl++;
  call_out(#'warte_schleife,60,zahl);
}

void verbessere_ruestung(int ac, int zeit)
{
  if(QueryProp(RUEST_SCHUTZ))
    return;

  SetProp(RUEST_SCHUTZ,ac);
  SetProp(RUEST_ZUSATZ,QueryProp(RUEST_ZUSATZ)+ac);
  // Nach Ablauf verschwindet der Schutz wieder
  call_out(function void() {
    SetProp(RUEST_ZUSATZ,QueryProp(RUEST_ZUSATZ)-QueryProp(RUEST_SCHUTZ));
    SetProp(RUEST_SCHUTZ,0);

    if(living(environment(ME)))
      tell_object(environment(ME),
      "Der magische Schutz der Chaoshaut verschwindet.\n");
  },zeit);
}

void NotifyPlayerDeath(object player, object killer, int le )
{
  object pl;

  if(objectp(pl=QueryProp(P_WORN)) && pl==PL)
    remove_it();
}
