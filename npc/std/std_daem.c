// std_daem.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 10.12.2018 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            Fehler für neuen Driver behoben
// 27.11.2026 It@Efferdland            Schänke der Burg

#pragma no_clone
#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/npc";

int tell_hitpoints(object enemy);

static int lasthp,lastwarn;     // Dauerhafte Variablen fuer tell_hitpoints
static int intervall;           // Unnoetig, sie als Property zu speichern.  

static string *spot=({ "Hoehoe, gruess Lars von mir!",
                "Und dabei hab ich Dich grad mal gekitzelt.",
                "Hoffentlich tut es weh!",
                "Und sowas ist Chaot, ich muss mal mit Kruuolq reden ...",
                "Na, das ueben wir aber nochmal ...",
                "Hehe, das wird der Brueller beim naechsten Daemonen-StaTi.",
                "Gib doch nicht so schnell auf, also wirklich!",
                "*seufz* Selbst ein Kleriker haelt mehr aus ...",
                "Ich wars nicht!",
                "Ha, mit blossen Haenden. Was bin ich gut!",
                "Geh mit Satan, aber geh!",
                "Bruchk rulez!",
                "Na endlich hab ich meine Ruhe.",
                "Haha, wie peinlich :-)"});

static string *CLD=({ "zuckt unter Schmerzen zusammen",
               "versucht, eine Krankheit zu ueberwinden",
               "wirft uebelste Worte gegen sich",
               "grummelt etwas von 'Scheiss Gegend hier'",
               "schaut Dich vorwurfsvoll an",
               "spuckt gruenen Schleim",
               "seufzt: Rummelmupf Bruchk",
               "flucht laut und unanstaendig" });

static varargs void wech(object|string pl,int tm)
{ 
  if(objectp(pl))
    pl = getuid(pl);
  
  if(find_call_out("daemon_verschwinde") == -1)
    call_out("daemon_verschwinde",tm,pl);
}

static string killmsg()
{
 string spots;

 spots = spot[random(13)];

 if(getuid(PL)==QueryProp(CHAOS_DAEM_BESCHWOERER))
   return spots;
  return 0;
}

static int ichsehwennsdunkelist()
{
  return 2;
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  enable_commands();
  SetProp(P_NOFIRSTKILL,1);
  SetProp(P_XP,1);
  SetProp(DAEM_DEFEND_FAKTOR,0);
  SetProp(DAEM_FOLLOW,1);
  Set(P_KILL_MSG,#'killmsg,F_QUERY_METHOD);
  SetProp(P_NO_GLOBAL_ATTACK,1);
  SetProp(P_RESISTANCE,([DT_LIGHT: 0.3,DT_DARKNESS: -0.3]));
  Set(P_PLAYER_LIGHT,#'ichsehwennsdunkelist,F_QUERY_METHOD);
  AddClass(({
    CL_DEMON,
    CL_SKIN,
    CL_WALKING,
    CL_BREATH_AIR
  }));
  SetProp(P_RACE,CL_DEMON);
  
  AddId(({CHAOS_ID_GILDENDAEMON,"daemon"}));

  AddCmd(({"befehl","befehle"}),"befehle_daemon" );
  AddCmd(({"ende"}),"entzoegere_ende");
  
  call_out("setze_long",5);

  lasthp    = lastwarn = 0;
  intervall = 10;
}

void setDaemBeschwoerer(object ob)
{
  if (!ob) return;

  SetProp(CHAOS_DAEM_BESCHWOERER,getuid(ob));

  if (query_once_interactive(ob))
    SetProp(CHAOS_DAEM_BESCHWOERER_NAME,getuid(ob));

  else
    SetProp(CHAOS_DAEM_BESCHWOERER_NAME,ob->name(WER));
}

// p -> pentagramm, s -> SkillAbility.
void setPower(object p,object c,int s)
{
  int pf,bf,dp;
  float faktor,faktor2;
  string dmesg;
  mixed *hands;
  
  dp = QueryProp(DAEM_PROZENT);

  if (!dp) return;
/* 
Berechnung der Pentagramm-Faktoren. Der Success des Bannzauber faellt 
mit 10 % in die Berechnung ein 
*/
  if (!p || !p->QueryProp(CHAOS_NEUES_PENTA))
  {
    pf = 35;
    bf = 35;
  }
  else
  {
    pf = p->QueryProp(CHAOS_PENTAGRAMM_FAKTOR) +
         (7*p->QueryProp(CHAOS_BANNZAUBER_FAKTOR))/(dp*100);
  
    bf = p->QueryProp(CHAOS_BANNKREIS_FAKTOR) +
         (7*p->QueryProp(CHAOS_BANNZAUBER_FAKTOR))/(dp*100);
  }
  if (c)
    dmesg = getuid(c)+" : "; else dmesg = "";
  
  dmesg += "PF "+pf+" BF "+bf+" -> "+ (((pf+bf)*100)/140)+ " %";
  
  // Boese. Wir berechnen, wieviel Prozent dieser Daemon haben wird...
  faktor = ((pf+bf)*100.0)/(140.0*dp);
  
  if (faktor>1.0)
    faktor = 1.0;
  
  dmesg += ". Fuer "+QueryProp(P_NAME)+" "+(faktor*100)+" %.\n";
  dmesg += "Skill: "+(s/100)+" % -> ";
  
  // Nun kommt der Random durch den Skill dazu...
  if (s<5000)
    s = 5000;
  
  if (s<9000) 
    faktor2= 1.0 - random(9000-s)/20000.0;
  
  else
    faktor2= 1.0;
    
  faktor *= faktor2;
  
  SetProp(P_DAEMON_QUALITY,to_int((100.0*faktor)));

  dmesg += (faktor2*100.0)+" % -> "+(100.0*faktor)+" %.\n";
  
  SetProp(P_MAX_HP,(int)(QueryProp(P_MAX_HP)*faktor));
  SetProp(P_HP,QueryProp(P_MAX_HP));
  SetProp(P_FOOD,0);
  SetProp(P_DRINK,0);
  SetProp(P_ALCOHOL,0);
  
  hands    = QueryProp(P_HANDS);
  hands[1] = (int)(hands[1]*(0.8+faktor/5.0));
  
  SetProp(P_HANDS,hands);
  SetProp(P_BODY,(int)(QueryProp(P_BODY)*(0.75+(faktor/4))));
  
  dmesg += "HP: "+QueryProp(P_MAX_HP)+", BODY: "+QueryProp(P_BODY)+
           ", Hands: "+hands[1]+".\n";
/*  
Speziell fuer Feuerdaemonen: Staerke auf 18 fuer Level 11 -Chaoten mit 
60%-Pentagramm...
*/
  if (QueryProp(CHAOS_DAEMON_TYP)=="feuerdaemon" && objectp(c) && 
      c->QueryProp(P_GUILD_LEVEL) >= 11 && faktor >= 0.6)
    SetProp(P_ATTRIBUTES,(["int":12,"con":12,"str":18,"dex":12]));
}

int entzoegere_ende(string str)
{
  if(str) return 0;

  SetProp(P_DISABLE_ATTACK, QueryProp(P_DISABLE_ATTACK)+3);

  PL->SetProp(P_DISABLE_ATTACK, 
    PL->QueryProp(P_DISABLE_ATTACK)+3);

  return 0;
}

void gemeiner_daemon(object caster)
{
  tell_room(environment(caster),break_string(
      "HOHOHOO, "+capitalize(getuid(caster))+"! Ein Daemon reicht hier wohl! "
      "Ich geh was trinken.",0,Name(WER)+" sagt: "));

  remove();
}

int submit_disease(int i)
{

  object en = environment(); 

  if(!en) return 0;

  if(i)
  {
    tell_room(en,Name(WER,1)+" "+CLD[random(sizeof(CLD))]+".\n");        
    call_out("submit_disease",5,i-1);
    return 1;
  }
  else
  {
    object *inv = all_inventory(ME);

    foreach(object ob : inv)
        if(ob->is_class_member(CL_DISEASE))
        {
          ob->destruct();
        
          tell_room(en,Name(WER,1)+" ueberwindet eine Krankheit.\n");
        }

    return 1;
  }
  return 0;
}          
                                  
void team_is_doof(object caster)
{
    object *inv;

    if (caster)

    tell_object(caster,break_string(Name(WER,1) + " befreit sich wuetend "
      "aus Deiner Kontrolle. Du kannst nur hilflos zusehen, eingezwaengt in "
      "Deiner Team-Reihe."));
     
    inv = all_inventory(environment(ME));

    foreach(object ob : inv)
    {
      if(IS_LEARNER(ob))
        continue;
    
      if(!interactive(ob))
        continue;
      
      Kill(ob);
    }
    SetProp("kill_all",1);
}

public varargs void init(object origin)
{
  mapping daem_map;
  ::init(origin);

  object caster = find_player(QueryProp(CHAOS_DAEM_BESCHWOERER)); 

  if(QueryProp("kill_all") && interactive(PL) && 
     PL->QueryProp(P_LEVEL)>10 && !IS_LEARNER(PL) && 
     !PL->QueryProp(P_GHOST) && 
     PL->QueryProp(P_HP)>130)
  {
    if(query_idle(PL)<30)
      Kill( PL);
  }
  if(caster&&caster->QueryProp(P_GHOST)){
    wech(caster);
    return;
  }
  if (id("\nkampfdaemon") && caster && !QueryProp("kill_all")) 
    if (caster->TeamPrefix() != "" && caster->PresentPosition()>1)
      call_out("team_is_doof",0,caster);
  
  if(PL->QueryProp(CHAOS_DAEM_BESCHWOERER) == 
     QueryProp(CHAOS_DAEM_BESCHWOERER) && 
     PL->id("\nkampfdaemon") && id("\nkampfdaemon"))
  {
    tell_room(environment(),Name(WER,1)+" geraet voellig ausser "
    "Kontrolle.\n");
  
    if(caster)
      Kill(caster); return;
  }
  daem_map = QueryProp(DAEM_FAKTOR_MAPPING);

  if(QueryProp(CHAOS_DAEM_FOLLOW_TIME) && 
     time()>QueryProp(CHAOS_DAEM_FOLLOW_TIME))
  {
    wech(QueryProp(CHAOS_DAEM_BESCHWOERER));
    return;
  }
  if(!mappingp(daem_map))
    return;
  
  if(QueryProp(DAEM_DISAPPEAR)&&random(100)<daem_map[DAEM_DISAPPEAR]/2)
  {
    wech(QueryProp(CHAOS_DAEM_BESCHWOERER),5+random(10));
 
    return;
  }
  if(QueryProp(DAEM_AGGRESSIVE))
  {
    if(!caster)
      return;
    
    Kill(caster);
    
    if(random(100)<daem_map[DAEM_AGGRESSIVE]/3)
      SetProp("kill_all",1);
    
    return;
  }
  if(PL == caster &&
     PL->QueryProp(P_CHAOS_MASKE) &&
     id("\nkampfdaemon") &&
     object_name(environment()) != CHAOS_SCHAENKE )
  {
    gemeiner_daemon(caster);
    return;
  }
  if(caster&&PL==caster && id("\nkampfdaemon")) 
    caster->AddDefender(ME);
}

static void setze_long()
{
  string s;
  object caster;

  s = QueryProp(P_LONG); 

  if(!stringp(QueryProp(CHAOS_DAEM_BESCHWOERER)))
    return;

  if (QueryProp(CHAOS_DAEM_BESCHWOERER_NAME))
    s += "Dieser Daemon wurde von "+
        capitalize(QueryProp(CHAOS_DAEM_BESCHWOERER_NAME))+" beschworen.\n";
    
  else
    s += "Dieser Daemon wurde von "+
          capitalize(QueryProp(CHAOS_DAEM_BESCHWOERER))+" beschworen.\n";

  SetProp(P_LONG,s);
}

void reset()
{
  ::reset();

  if(!environment())
    return;

  string caster = QueryProp(CHAOS_DAEM_BESCHWOERER);

  if(!caster)
  {
    wech(caster);
    return;
  }
  if(QueryProp(DAEM_FALSE))
    SetProp(CHAOS_DAEM_NO_DISAPPEAR,0);
  
  if(!find_player(QueryProp(CHAOS_DAEM_BESCHWOERER)))
  {
    wech(caster);
    return;
  }
  if(QueryProp(CHAOS_DAEM_NO_DISAPPEAR))
    return;
  
  wech(caster);
}   

varargs void die(int bla)
{
  object penta;

  if(penta=present("\nchaos_gilden_pentagramm_"+
     QueryProp(CHAOS_DAEM_BESCHWOERER),environment(ME))) 
    penta->starte_entfernen(4);

  if(find_call_out("submit_disease")>0)
    remove_call_out("submit_disease");

  ::die(bla);
}

int PreventFollow(object dest)
{
  int i, l, si;
  string *v, f;

  if(!QueryProp(DAEM_FOLLOW))
    return 1; 

  if (GUILD_HELPER->GH_get_npc_forbidden_rooms(object_name(dest)))
    return 1;
  
  return 0;
}

static int befehle_daemon(string str)
{
  string b, wer, tmp, tmp_waffe;
  object waffe, *ruestungen;
  int i;

  if(!str) return 0;
 
  if(sscanf(str, "%s %s",wer,b)!=2) return 0;
 
  if(!id(wer)) return 0;
 
  if(id("ombatis")) return 0;
 
  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER))
    return 0;
 
  if(QueryProp("kill_all") || QueryProp(DAEM_AGGRESSIVE))
  {
    write(Name(WER,1)+" gehorcht Dir nicht.\n");
    return 1;
  }
  if(IsEnemy(PL))
  {
    write(Name(WER,1)+" lacht ueber Dich!\n");
    return 1;
  }
  ruestungen = QueryProp(P_ARMOURS);

  if(waffe = QueryProp(P_WEAPON))
    tmp_waffe = waffe->QueryProp(P_IDS)[0];

  if(sscanf(b,"toete %s",wer))
  {
    object enemy;
  
    if(!id("\nkampfdaemon"))
      return write(Name(WER,1)+" versteht Deinen Befehl nicht.\n"),1;

    if(!enemy=present(wer,environment(ME)))
      return write(Name(WER,1)+" findet "+capitalize(wer)+" nicht.\n"),1;

    if(IsEnemy(enemy))
      return write(Name(WER,1)+" kaempft doch schon gegen "+enemy->name(WEN,1)+
                   ".\n"),1;
    Kill(enemy);

    if(!PL->IsEnemy(enemy))
      PL->Kill(enemy);

    return 1;
  }
  notify_fail(Name(WER,1)+" versteht den Befehl nicht.\n");
  
  switch(b)
  {
    case "folge":
    case "folg":
    case "folge mir":
      if(PL->QueryProp(P_CHAOS_MASKE))
      {
        write(Name(WER)+" lacht Dich aus.\n");
        break;
      }
      write(Name(WER,1)+" folgt Dir.\n");
      SetProp(P_FOLLOW_SILENT,0);
      SetProp(DAEM_FOLLOW,1);
      break;

    case "stop":
    case "stopp":
    case "bleibe stehen":
    case "bleib stehen":
    case "halt":
      if(InFight())
      {
        write(Name(WER,1)+" gehorcht nicht.\n");
        break;
      }
      write(Name(WER,1)+" bleibt stehen.\n");
      SetProp( DAEM_FOLLOW,0);
      break;
    
    case "folge leise":
    case "folg leise":
      if(PL->QueryProp(P_CHAOS_MASKE))
      {
        write(Name(WER,1)+" lacht Dich aus.\n");
        break;
      }
      write(Name(WER,1)+" folgt Dir leise.\n");
      SetProp(P_FOLLOW_SILENT,1);
      SetProp(DAEM_FOLLOW,1);
      break;
    
    case "schweig":
    case "sei still":
        if (!QueryProp(DAEM_DONT_SPEAK))
        {
          write(Name(WER,1)+" bruellt: JAWOLL, "+
           upperstring(PL->name())+"!\n");
        
          SetProp(DAEM_DONT_SPEAK,1);
        }
        else
          write(Name(WER,1)+" schweigt doch schon!\n");
        break;        
    
    case "sei laut":
    case "sprich":
        if (QueryProp(DAEM_DONT_SPEAK))
        {
          write(Name(WER,1)+" bruellt: JAWOLL, "+
           upperstring(PL->name())+"!\n");
        
          SetProp(DAEM_DONT_SPEAK,0);
        }
        else
          write(Name(WER,1)+" spricht doch schon!\n");
        break;
    
    case "wirf alles weg":
    case "werfe alles weg":
      if(!id("\nkampfdaemon")) return 0;
    
      if(i=sizeof(ruestungen))
      {
        do{
          i--;
          tmp=ruestungen[i]->QueryProp(P_IDS)[0];
          command_me("wirf "+tmp+" weg");
        }while(i>0);
        i++;
      }   
      if(tmp_waffe)
        command_me("wirf "+tmp_waffe+" weg");

      if(!tmp_waffe && !i)
      {
        tell_object(PL,Name(WER,1)+" teilt Dir mit: "
        +"Rueste mich erstmal aus, Wursti! Dann sprechen wir\n"+
        Name(WER,1)+" teilt Dir mit: weiter!\n");
      }
      break;

    case "wirf waffe weg":
    case "werfe waffe weg":
      
      if(!id("\nkampfdaemon")) return 0;
      
      if(tmp_waffe)
        command_me("wirf "+tmp_waffe+" weg");
      
      else
      {  
        tell_object(PL,Name(WER,1)+" teilt Dir mit: "
        "Sowas wuerde ich nichtmal wegwerfen, wenn ich's haette!\n");
      }
      break;

    case "wirf ruestungen weg":
    case "werfe ruestungen weg":
    case "wirf ruestung weg":
    case "werfe ruestung weg":
      if(!id("\nkampfdaemon")) return 0;

      if(i=sizeof(ruestungen))
      {
        do{
          i--;
          tmp = ruestungen[i]->QueryProp(P_IDS)[0];
          command_me("wirf "+tmp+" weg");
        }while(i>0);
      }
      else
      {
        tell_object(PL,Name(WER,1)+" teilt Dir mit: "
        +"He! Ich bin nackt! So ein Scheiss aber auch!\n");
      }
      break;                                                                   
    
    default: 
      return 0;
      break;
  }
  return 1;
}
  
varargs void daemon_verschwinde(string spieler)
{
  if(!spieler)
    return;
    
  if(!stringp(spieler))
    return;

  if(!environment())
    return;

  tell_room(environment(ME),Name(WER,1)+
    ME->QueryProp(P_DIE_MSG));

  remove();
}

void InformDefend(object enemy)
{
  if(!present(enemy,environment(ME)))
    return;
  
  if(!objectp(enemy))
    return;
  
  if(!living(enemy))
    return;
  
  Kill(enemy);
}
                              

void do_my_special_attack(object enemy)
{
  switch(random(10))
  {
    case 0..3:
      tell_object(enemy,Name(WER,1)+" wirft einen Chaosball auf Dich!\n");
      
      say(Name(WER,1)+" wirft einen Chaosball auf "+enemy->name(WEN)+".\n");
      
      enemy->Defend(100+random(400),DT_SOUND,1,ME);

      break;

    default:                    
      tell_object(enemy,Name(WER,1)+" gibt Dir einen kraeftigen Tritt!\n");
      
      say(Name(WER,1)+" gibt "+enemy->name(WEM)+" einen kraeftigen Tritt.\n",
        ({enemy}));

      enemy->Defend(50+random(200),DT_BLUDGEON,0,ME);

      break;
  }
}

void Attack(object enemy)
{
  int count_down;
  mixed special;

  if(!environment())
    return;

  if(!living(enemy))
    return;

  count_down = QueryProp(DAEM_COUNT_DOWN);

  if(QueryProp(DAEM_DISAPPEAR) && 
     random(100)<QueryProp(DAEM_FAKTOR_MAPPING)[DAEM_DISAPPEAR]/2) 
    wech(QueryProp(CHAOS_DAEM_BESCHWOERER));

  if(count_down)
  {
    count_down --;
    if(!count_down)
      wech(QueryProp(CHAOS_DAEM_BESCHWOERER));
    SetProp(DAEM_COUNT_DOWN, count_down );
  }
  if(!interactive(enemy) && enemy->QueryProp(P_HP)<20 && 
     !QueryProp("daemon_wants_kill")) return 0;

  if(special=QueryProp("darf_zaubern") && random(100)<special)
    do_my_special_attack(enemy);

  if (QueryProp(DAEM_CAN_SPEAK) && !QueryProp(DAEM_DONT_SPEAK)
      && !QueryProp(DAEM_AGGRESSIVE) && !QueryProp("hurt_all"))
   tell_hitpoints(enemy);

  return::Attack(enemy);
}

int Defend(int dam, mixed dam_type, int spell, object enemy)
{
  mapping daem_map;
  object *inv, pl, caster, *en;

  int def;

  if(!environment())
    return 0;
  
  if(!objectp(enemy))
    return 0;
  
  if(!living(enemy))
    ::Defend(dam, dam_type, spell, enemy);
  
  def = QueryProp(DAEM_DEFEND_FAKTOR);    

  if(!def)
    return::Defend(dam, dam_type, spell, enemy);     

  if(query_once_interactive(enemy)) 
    return::Defend(dam, dam_type,spell, enemy);
  
  if(enemy->id("\nkampfdaemon"))
    return::Defend(dam, dam_type,spell,enemy);
  
  if(QueryProp(DAEM_AGGRESSIVE))
    return::Defend(dam, dam_type, spell,enemy);
  
  caster = find_player(QueryProp(CHAOS_DAEM_BESCHWOERER)); 

  if(!caster)
  {
    wech(QueryProp(CHAOS_DAEM_BESCHWOERER));
    return::Defend(dam, dam_type, spell, enemy);
  }
  if(!present(caster, environment(ME)))
  {
    if(!QueryProp(DAEM_FOLLOW))
      wech(QueryProp(CHAOS_DAEM_BESCHWOERER));

    return ::Defend(dam, dam_type, spell, enemy);
  }
  daem_map = QueryProp(DAEM_FAKTOR_MAPPING);

  if(QueryProp(DAEM_FALSE) && random(100)<daem_map[DAEM_FALSE]/2 && 
     !IsEnemy(caster))
  {
    tell_room(environment(ME), 
      capitalize(Name(WER,1))+" aendert seine Meinung.\n");

    inv = all_inventory(environment(ME));

    foreach(object ob : inv)
    {
      if(IS_LEARNER(ob))
        continue;
      
      if(!interactive(ob))
        continue;
      
      Kill(ob);
    }
    SetProp("kill_all",1);
    return 0;
  }
  if(daem_map[DAEM_FALSE]>20 && random(100)<daem_map[DAEM_FALSE]/3)
  {
    if(caster && !IsEnemy(caster) && 
       caster->QueryProp(P_HP)*3 < caster->QueryProp(P_MAX_HP))
    {
      tell_room(environment(ME), 
        Name(WER,1)+" greift seinen Beschwoerer an.\n");
      
      ME->StopHuntFor(enemy);
      
      enemy->StopHuntFor(ME);
      
      SetProp("kill_all",1);
      
      Kill(caster);
      
      return 0;
    }
  }
  if (id("\nkampfdaemon") && caster && !QueryProp("kill_all")) 
    if (caster->TeamPrefix() != "" && caster->PresentPosition()>1)
      call_out("team_is_doof",0,caster);

  if(random(100)>def)
    return::Defend(dam, dam_type,spell, enemy);

  if(sizeof(enemy->QueryEnemies()))
  {
    tell_room(environment(ME),Name(WER,1)+" weicht dem Angriff "
              "aus.\n");
    
    inv = enemy->QueryEnemies()[0];
    
    en = ({});
    
    foreach(object ob : inv)
    {
      if(!objectp(ob))
        continue;
      
      if(!living(ob))
        continue;
      
      if(!interactive(ob))
        continue;
      
      if(!present(ob,environment(ME)))
        continue;
      
      if(IS_LEARNER(ob))
        continue;
      
      en += ({ob});
    }
    if(member(en,caster)==-1)
      en+=({caster});
    
    pl = en[random(sizeof(en))];
    
    if(!objectp(pl))
      pl=caster;
    
    pl->Defend(dam,dam_type,spell,enemy);
    
    ME->StopHuntFor(pl);
    
    pl->StopHuntFor(ME);
    
    return 0;
  }
  return::Defend(dam, dam_type,spell, enemy);
}

int PreventInsert(object ob)
{
  ::give_notify(ob);

  if (!objectp(ob))
    return 0;

  if(ob->is_class_member(CL_DISEASE))
  {
    tell_room(environment(),Name(WER,1)+" flucht lautstark und "
              "faengt an zu zucken.\n");

    if(find_call_out("submit_disease")==-1)
    {
      int i = ((100-(QueryProp(P_DAEMON_QUALITY)))/10);
      call_out("submit_disease",3,i+1);
    }
    return 0;
  }
  return 1;
}

void give_notify(object ob)
{
  object waffe;
  string comm;
  ::give_notify(ob);

  if(QueryProp(CHAOS_DAEMON_TYP)=="orakeldaemon")
    return;
  
  if(ob->id(CHAOS_TRANK)&&comm=ob->QueryProp(CHAOS_TRANK_TRINKEN))
  {
    command(comm); 
    return;
  }
  if(ob->id(CHAOS_HANDSCHUH))
  {
    command("ziehe handschuhe an");
    SetProp(CHAOS_HANDSCHUH,1);
  }
  if(QueryProp(CHAOS_HANDSCHUH)&&ob->QueryProp(P_WEAPON_TYPE))
  {
    if(objectp(waffe=QueryProp(P_WEAPON)))
      drop_obj(waffe);

    command("zuecke "+ob->QueryProp(P_IDS)[sizeof(ob->QueryProp(P_IDS))-1]);
  }  
}

int tell_hitpoints(object enemy)
{
  int tmp; 
  
  int hp        = QueryProp(P_HP);
  int max_hp    = QueryProp(P_MAX_HP);
  string n      = Name(WER);
  object caster = find_player(QueryProp( CHAOS_DAEM_BESCHWOERER) );

  if( ! objectp(caster) || ! interactive(caster))
    return 1;

  string *msg = ({
  n+" bruellt: WIR SEHN UNS IN DER HOELLE, "+upperstring(getuid(caster))+"!",
  n+" bruellt: Und Ich geh nicht zum Aaarzt, nein, zum Arzt geh ich nicht!",
  n+" bruellt: Meine Verfassung ist schlecht, aber fuer "+enemy->name(WEN)+
             " reichts noch!",
  n+" bruellt: Wow, alles schwankt und wankt um mich herum!",
  n+" bruellt: Ich mag Mitgenommen aussehen, aber ich bin voll hinter Dir!",
  n+" bruellt: Haha, "+enemy->name(WER)+" sieht auch nicht allzu frisch aus!",
  n+" bruellt: Huch, da hat mich doch irgendwas gekratzt! Sowas...\n"
  });
/* 
Isses schon wieder soweit?
Alle >= 4 Sec, es sei denn er ist fast auf Schwelle...
*/
  if (time() >= lasthp+4 || (hp/max_hp)*10<=2)
  {
     tmp = (hp*10)/max_hp;

     if (tmp < intervall && tmp < 7)
     {
       tell_object(caster,break_string(msg[tmp]));
       intervall = tmp;
       lasthp    = time();
     }
     else if (tmp > intervall+1 && time() >= lasthp + 4)
     {
       tell_object(caster,break_string
            (n+" bruellt: Mir gehts super. Lass uns weiterkaempfen!"));
     
       intervall = tmp;
       lasthp    = time();
     }
  }
  if (time() >= lastwarn+60 && time() >= 
       environment()->QueryProp(CHAOS_DAEM_FOLLOW_TIME)-120)
  {
    if (random(10)<8)
      tell_object(caster,break_string
           (n+" bruellt: Wow, ich fuehl mich recht kribbelig...",78));
  
    lastwarn = time();
  }
  return 1;
}

public varargs int Flee(object oldenv, int force) {
  return 0;
}

static void CheckWimpyAndFlee()
{
  return;
}

int move_kneipe()
{
  ME->move(CHAOS_SCHAENKE,M_GO,"was trinken");
  return 1;
}
