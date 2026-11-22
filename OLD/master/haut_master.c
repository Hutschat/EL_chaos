// haut_master.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Bierchen@MorgenGrauen    neu
// 11.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit
#pragma no_clone

#include "def.h"

inherit "/std/thing";
inherit "/std/util/pager";

static int lausch_level=8;
static int magier,seher,spieler;
static string *brain;

string *banish_list;
string *provider_list;

static void save_me()
{
  save_object(CHAOS_GILDEN_MASTER("save/haut_master"));
}
static void restore_me()
{
  restore_object(CHAOS_GILDEN_MASTER("save/haut_master"));
}
/* wie: 0 -> chaossagen, 1 -> chaosemote */
static int csag_brain(string pl,string was,int wie)
{
  string pl_name,msg;
  string *ms;
  string date;
  int i,month;

  ms = ({"","Jan","Feb","Mar","Apr","Mai","Jun","Jul","Sep","Okt","Nov","Dez"});

  date  = dtime(time());
  month = member(ms,date[9..11]);

  pl_name = capitalize(pl);

  if(sizeof(brain) > 30)
    brain = brain[1..];

  switch(wie)
  {
    case 0:
       brain+=({break_string(was+" <"+date[5..7]+month+"., "+date[19..]+
               ">",0,"["+pl_name+"] ")});
       break;
    case 1:
    default:
      msg = "                               ";
      i = sizeof(pl);
      brain+=({ pl+ " " +break_string(was+". <"+date[5..8]+month+"., "+
                date[19..]+">",0,msg[0..i])[i+1..]});
      break;
  }
  return 1;
}

static int csag_info(object chaot,string wie)
{
  int i,v;
  int anzahl;
  string tmp;

  if(i = sizeof(brain))
  {
    tell_object(chaot,"Folgendes ist bei den Chaoskriegern geschehen:\n");

    tell_object(chaot,
      "------------------------------------------------------------------"+
      "-------------\n");

    tmp = implode(brain,"");

    if(wie && sscanf(wie,"%d",anzahl) == 1 && anzahl < sizeof(brain))
        tmp = implode(brain[sizeof(brain)-anzahl..],"");

    chaot->More(tmp);
  }
  else
    tell_object(chaot,"Es ist keine Geschichte verfuegbar.\n");

  return 1;
}

mixed banish_chaot(string chaot)
{
  if(member(CHAOS_GILDEN_MAGIER,getuid(previous_object()))==-1)
    return 0;

  if(chaot)
  {
    chaot = lowerstring(chaot);

    if(member(CHAOS_GILDEN_MAGIER,chaot)!=-1)
      return 0;

    if(!sizeof(banish_list))
    {
      banish_list = ({chaot});
      save_me();
      return chaot+" in die schwarze Liste eingetragen.";
    }
    else if(member(banish_list,chaot)!=-1)
      return chaot+" steht schon auf der schwarzen Liste.";

    else
    {
      banish_list+=({lowerstring(chaot)});
      save_me();
      return chaot+" in die schwarze Liste eingetragen.";
    }
  }
  return 0;
}

mixed unbanish_chaot(string chaot)
{
  int i;

  if(member(CHAOS_GILDEN_MAGIER,getuid(previous_object())) == -1)
    return 0;

  if(!sizeof(banish_list))
    return 0;

  if(chaot)
  {
    chaot = lowerstring(chaot);

    if((i=member(banish_list,chaot))!=-1)
    {
      banish_list-=({chaot});
      save_me();
      return chaot+" aus der schwarzen Liste entfernt.";
    }
  }
  return 0;
}

mixed banish_list()
{
  if(member(CHAOS_GILDEN_MAGIER,getuid(previous_object())) == -1)
    return 0;

  if(pointerp(banish_list) && sizeof(banish_list))
    return array2string(banish_list);
  
  return 0;
}

mixed add_provider(string provider)
{
  if(member(CHAOS_GILDEN_MAGIER,getuid(previous_object())) == -1)
    return 0;

  if(provider && stringp(provider))
  {
    provider = lower_case(provider[0..20]);
    if(!sizeof(provider_list))
    {
      provider_list=({provider});
      save_me();
      return provider+" in die Liste eingetragen.";
    }

    else if(member(provider_list,provider)!=-1)
      return provider+" ist schon eingetragen.";

    else
    {
      provider_list+=({lowerstring(provider)});
      save_me();
      return provider+" in die Liste eingetragen.";
    }
  }
  return 0;
}

mixed del_provider(string provider)
{
  int i;
  if(member(CHAOS_GILDEN_MAGIER,getuid(previous_object())) == -1)
    return 0;

  if(!sizeof(provider_list))
    return 0;

  if(provider && stringp(provider))
  {
    provider = lowerstring(provider);

    if((i=member(provider_list,provider))!=-1)
    {
      provider_list-=({provider});
      save_me();
      return provider+" aus der Liste entfernt.";
    }
  }
  return 0;
}

string *provider_list()
{
  int i;

  if(member(CHAOS_GILDEN_MAGIER,getuid(previous_object())) == -1)
    return 0;

  if(i=sizeof(provider_list))
    return provider_list;

  return 0;
}

static int gilden_news(object chaot)
{
  if(!chaot->QueryProp("chaos_last_news"))
    chaot->Set("chaos_last_news",SAVE,F_MODE_AS);

  chaot->SetProp("chaos_last_news",file_time(CHAOS_GILDEN_TXT("g_news")));
  chaot->more(CHAOS_GILDEN_TXT("g_news"));

  return 1;
}

static int greater_level(object ob1, object ob2)
{
  return (ob1->QueryProp(P_GUILD_LEVEL)>ob2->QueryProp(P_GUILD_LEVEL));
}

static int is_wiz_level_ge(object ob, mixed x)
{
  return (query_wiz_level(ob)>=x);
}

static string *finde_chaoten(object chaot)
{
  object *objs,ob;

  objs    = call_other("/std/user_filter","filter_users","gilde chaos");
  magier  = sizeof(filter(objs,"is_wiz_level_ge",ME,LEARNER_LVL));
  seher   = sizeof(filter(objs,"is_wiz_level_ge",ME,SEER_LVL)) - magier;
  spieler = sizeof(objs) - magier - seher;

  if(!IS_LEARNER(chaot))
    foreach(ob:objs)
      if(IS_LEARNER(ob) &&  ob->QueryProp(P_GUILD_LEVEL)>11 &&
          member(CHAOS_GILDEN_MAGIER,getuid(ob))==-1)
        ob->SetProp(P_GUILD_LEVEL,8);

  objs = sort_array(objs,"greater_level",ME);
  return map(objs,#'getuid);
}

static int check_clevel(object chaot)
{
  if(chaot->QueryProp("guild_level")<lausch_level||
     chaot->QueryProp(P_GUILD)!="chaos")
  {
    tell_object(chaot,break_string("Du musst erst Erfahrungen "
    "in der Chaosgilde sammeln, um dies zu beherrschen!"));
    return 0;
  }
  return 1;
}

static int check_banish(object chaot)
{
  if(sizeof(banish_list)&&member(banish_list,getuid(chaot))!=-1)
  {
    tell_object(chaot,"Das Chaos hat diesen Befehl vernichtet.\n");
    return 1;
  }
  return 0;
}

static int in_para(object ob)
{
  if(ob->QueryProp(P_PARA)) return 1;
  
  return 0;
}

static int div_info(string str,object chaot)
{
  mixed tmp;
  string *line = ({}),ret = "";
  object *player_list = ({}),player;
  
  foreach(tmp:finde_chaoten(chaot))
  {
    if(player = find_player(tmp))
      if(!player->QueryProp(P_TESTPLAYER))// && !IS_LEARNER(player))
        player_list += ({player});
        
  }

  switch (str)
  {
    case "para":
    case "in para":
    case "in parallelwelt":
    case "parallelwelt":
      ret+="    Folgende Chaoten befinden sich zur Zeit in der Parallelwelt:\n";
      ret+=" ------------------------------------------------------------------------------\n";

      foreach(tmp:filter(player_list,#'in_para))
        line += ({capitalize(getuid(tmp))});
      
      if(sizeof(line))
        ret += break_string(array2string(line),0,"   ");

      else ret+="    Pfff, alles Weicheier!\n";

      break;
    
    case "normalwelt":
    case "in normalwelt":
    case "in normal":
    case "normal":
      ret+="    Folgende Chaoten befinden sich zur Zeit in der Normalwelt:\n";
      ret+=" ------------------------------------------------------------------------------\n";

      player_list -= filter(player_list,#'in_para);

      foreach(tmp:player_list)
        line += ({capitalize(getuid(tmp))});

      if(sizeof(line))
        ret += break_string(array2string(line),0,"   ");

      else ret+="    Keine Chaoten in der normalen Welt gefunden!\n";

      break;
      
    case "fast bei lars":
    case "fast tot":
      ret+="    Folgende Chaoten trinken bald Kaffee mit Lars:\n";
      ret+=" ------------------------------------------------------------------------------\n";

      foreach(tmp:player_list)
        if (tmp->QueryProp(P_HP)<=20)
          line += ({capitalize(getuid(tmp))});
      
      if(sizeof(line))
        ret += break_string(array2string(line),0,"    ");
      
      else
        ret+="    Sieht so aus, als wenn hier niemand etwas wagt...";
  
      break;
    case "hilfe":
    case "help":
      ret+="Folgende Befehle stehen Dir momentan zur Verfuegung:\n";
      ret+="  'chaoswer'               : Zeigt alle anwesenden Chaoten an.\n";
      ret+="                             C = Chaosmagier\n"
           "                             E = Ehrenchaosmagier\n"
           "                             S = Seher\n"
           "                             s = Spieler\n";
      ret+="  'chaoswer in para'       : Zeigt alle Chaoten in der Parallelwelt an.\n";
      ret+="  'chaoswer in normal'     : Zeigt alle Chaoten in der Normalwelt an.\n";
      ret+="  'chaoswer fast bei lars' : Zeigt alle Chaoten an, die bald auf -Tod\n"
          +"                             erscheinen.\n";
      ret+="  'chaossag <text>'        : Teilt (fast) allen Chaoten etwas mit.\n";
      ret+="  'chaosemote <text>'      : Emotet (fast) allen Chaoten etwas.\n";
      ret+="  'chaoslausche <ein/aus>' : Falls Dich das 'chaossag' mal nerven sollte.\n";
      ret+="  'chaoshist'              : Zeigt an, was so ueber Dich geredet wurde.\n";
      ret+="  'chaoswer hilfe'         : Diese Kurzhilfe.\n";
      break;
    default:
      ret="Diese Info gibs nicht. Punkt.\n";
      break;
  }
  chaot->More(ret);
  return 1;
}

static string pl_symbol(object chaot)
{
  if(IS_LEARNER(chaot))
  {
    if(member(CHAOS_GILDEN_MAGIER,getuid(chaot))!=-1)
      return "[C]";

    else
      return "[E]";
  }
  else if(IS_SEER(chaot))
    return "[S]";

  else
    return "[s]";
}

static string pl_name(object chaot)
{
  if(IS_LEARNER(chaot))
    if(chaot->QueryProp(P_INVIS))
      return("("+capitalize(getuid(chaot))+")");

  return(capitalize(getuid(chaot)));
}

static string pl_idletime(object chaot)
{
  int hours,mins,secs,idle,i;
  string ret;

  idle  = query_idle(chaot);
  hours = idle/3600;
  idle -= hours*3600;
  mins  = idle/60; 
  idle -= mins*60;
  secs  = idle;
  ret   = sprintf("%2'0'd:%2'0'd:%2'0'd",hours,mins,secs);

  return(ret);
}

static string pl_lsymbol(object chaot)
{
  if(sizeof(banish_list)&&member(banish_list,getuid(chaot))!=-1)
    return "x";

  if(chaot->QueryProp(P_C_LAUSCHEN) && present_clone(CHAOS_CHAOSHAUT,chaot))
    return "*";

  return "-";
}

static string ret_list(object pl)
{
  mixed txt;

  if(pl->QueryProp(P_TESTPLAYER))
  {
    spieler--;
    if(spieler<=0)
      spieler=0;
  }
  else if(pl->QueryProp("chaos_chaoswer_nicht_anzeigen")&&
          IS_LEARNER(pl))
  {
    magier--;

    if(magier<=0)
      magier=0;
  }
  else
  {
    txt=sprintf("   %-9d%-5d%-10s%-2s%-4s%-20s\n",
         pl->QueryProp(P_GUILD_LEVEL),
         pl->QueryProp(P_LEVEL),
         pl_idletime(pl),
         pl_lsymbol(pl),
         pl_symbol(pl),
         pl_name(pl));
  }
  if(stringp(txt))
    return txt;

  else
    return "";
}

static int gilden_wer(object chaot)
{
  object pl;
  string ret_txt;
  mixed mitglieder;
  int i;
  mixed tmp;
  
  string ret = "";
  
  mitglieder=(["chaosmagier":"",
               "ehrenmagier":"",
               "divmagier":"",
               "spieler":""
             ]);

  foreach(tmp:finde_chaoten(chaot))
  {
    if(pl = find_player(tmp))
    {
      if(member(CHAOS_GILDEN_MAGIER,getuid(pl))!=-1)
        mitglieder["chaosmagier"] += ret_list(pl);

      else if(member(CHAOS_GILDEN_EHRENMAGIER,getuid(pl))!=-1)
        mitglieder["ehrenmagier"] += ret_list(pl);

      else
        mitglieder["divmagier"] += pl_lsymbol(pl)+" "+pl_name(pl)+" ";
    }
    else
    {
      if(!pl->QueryProp(P_TESTPLAYER)&& 
         !pl->QueryProp("chaos_chaoswer_nicht_anzeigen"))
        mitglieder["spieler"]+=ret_list(pl);
    }
  }

  ret  = "";
  ret += sprintf("\n    Folgende Krieger des Chaos sind momentan anwesend: "
                 "(M="+magier+", S="+seher+", s="+spieler+")\n");
  ret += sprintf(" ------------------------------------------------------------------------------\n");
  ret += sprintf(" GLevel   PLevel   Idle           Name                        \n");
  ret += mitglieder["chaosmagier"];
  ret += mitglieder["ehrenmagier"];
  ret += mitglieder["spieler"];

  if(sizeof(mitglieder["divmagier"]))
  {
    ret += sprintf(" ------------------------------------------------------------------------------\n");
    ret += sprintf(break_string(" Weitere Magier: "
           +mitglieder["divmagier"]));
    ret += sprintf(" ------------------------------------------------------------------------------\n");
  }
  chaot->More(ret);
  return 1;
}

static int clausche(string str,object chaot)
{
  if(!str)
  {
    if(chaot->QueryProp(P_C_LAUSCHEN))
    {
      tell_object(chaot,"Du lauschst den Chaoskriegern.\n");
      return 1;
    }
    tell_object(chaot,"Du lauschst den Chaoskriegern nicht.\n");
    return 1;
  }
  if(str!="ein"&&str!="aus")
  {
    tell_object(chaot,"'chaoslausche' ein oder aus?\n");
    return 1;
  }
  if(str=="ein")
  {
    if(chaot->QueryProp(P_C_LAUSCHEN))
    {
      tell_object(chaot,"Du lauschst doch schon.\n");
      return 1;
    }
    chaot->SetProp(P_C_LAUSCHEN,1);
    tell_object(chaot,"Du lauschst nun bei den Chaoskriegern.\n");
    return 1;
  }
  if(!chaot->QueryProp(P_C_LAUSCHEN))
  {
    tell_object(chaot,"Aber Du lauschst doch gar nicht.\n");
    return 1;
  }
  chaot->SetProp(P_C_LAUSCHEN,0);
  tell_object(chaot,"Du lauschst den Chaoskriegern nicht mehr.\n");
  return 1;
}

/* wie : 0 -> sagen, 1: emote */
static int chaos_sagen(string was,object chaot,int wie)
{
  string wer,gag,msg;
  object pl;
  mixed tmp;
  string *chaoten;

  was = chaot->_unparsed_args();

  if(!was)
  {
    tell_object(chaot,"Was moechtest Du den Chaoskriegern mitteilen?\n");
    return 1;
  }
  if(!chaot->QueryProp(P_C_LAUSCHEN))
  {
    tell_object(chaot,"Du lauschst Doch noch gar nicht!\n");
    return 1;
  }

  wer = pl_name(chaot);

  if(IS_LEARNER(chaot))
  {
    gag = chaot->QueryProp("chaos_cloaked");

    if(gag)
    {
      if(member(CHAOS_GILDEN_MAGIER,getuid(chaot))!=-1)
      {
        if(intp(gag))
          wer = "Etwas";

        else if(stringp(gag))
          wer = capitalize(gag);

        else
        {
          chaot->SetProp("chaos_cloaked",0);
          tell_object(chaot,break_string("chaos_cloaked besass das falsche "
                      "Format und wurde daher entfernt. Ein Senden auf der "
                      "internen Chaosebene wurde abgebrochen."));
          return 1;
        }
      }
    }
  }

  tmp = 0;
  
  switch(wie)
  {
    case 0:
      tell_object(chaot,break_string(was,0,"Du sagst chaotisch: "));
      msg = break_string(was,0,wer+ " sagt chaotisch: ");
      break;
    case 1:
    default:
      msg = "                         ";
      tmp = sizeof(wer);
      if (chaot->QueryProp(P_GENDER) == 2)
      {
        wer = "Chaotin "+wer;
        tmp += 8;
        msg = wer+ " " +break_string(was+".",0,msg[0..tmp])[tmp+1..];
      }
      else
      {
        wer = "Chaot "+wer;
        tmp += 6;
        msg = wer+ " " +break_string(was+".",0,msg[0..tmp])[tmp+1..];
      }
      tell_object(chaot,msg);
      break;
  }
  csag_brain(wer,was,wie);
  
  chaoten = finde_chaoten(chaot);
  
  foreach(tmp:chaoten)
  {
    if(tmp != getuid(chaot))
    {
      if(pl=find_player(tmp))
      {
        if(sizeof(banish_list) && member(banish_list,getuid(pl))!=-1)
          pl->SetProp(P_C_LAUSCHEN,0);

        if(pl->QueryProp(P_C_LAUSCHEN) && present_clone(CHAOS_CHAOSHAUT,pl) &&
           pl->QueryProp("guild_level")>=lausch_level)
         tell_object(pl,msg);
      }
    }
  }
  return 1;
}

static void c_hist(string wie,object chaot)
{
  csag_info(chaot,wie);
}

static void chaosblockade(string ein,object chaot)
{
  int aktiv;

  aktiv = chaot->QueryProp(CHAOSBALL_BLOCKADE);
  if (ein != "ein" && ein != "aus")
  {
    tell_object(chaot,"Deine Chaosblockade ist momentan "+
    (aktiv?"aktiviert":"deaktiviert")+
    ".\n\"chaosblockade ein/aus\" wechselt ihren Zustand.\n");
    return;
  }
  if (ein == "ein")
  {
    if (aktiv)
      tell_object(chaot,"Deine Chaosblockade ist bereits aktiv.\n");

    else
    {
      chaot->SetProp(CHAOSBALL_BLOCKADE,1);
      tell_object(chaot,"Du aktivierst Deine Chaosblockade.\n");
    }
  }
  else
  {
    if (!aktiv)
      tell_object(chaot,"Deine Chaosblockade ist doch garnicht aktiv.\n");

    else
    {
      chaot->SetProp(CHAOSBALL_BLOCKADE,0);
      tell_object(chaot,"Du deaktivierst Deine Chaosblockade.\n");
    }
  }
}

void chaos_input(string chaos_cmd,string chaos_args,object chaot)
{
  if(!chaot||!chaos_cmd)
    return;

  switch (chaos_cmd)
  {
    case "chaosinfo":
    case "chaosinfos":
      if(check_banish(chaot))
        return;

      gilden_news(chaot);
      break;
    case "chaoswer":
      if(chaos_args)
        div_info(chaos_args,chaot);

      else
        gilden_wer(chaot);

      break;
    case "chaoslausche":
    case "chaoslausch":
      if(check_banish(chaot))
        return;

      if(!check_clevel(chaot))
        return;

      clausche(chaos_args,chaot);
      break;
    case "chaossag":
    case "chaossage":
      if(check_banish(chaot))
        return;

      if(!check_clevel(chaot))
        return;

      chaos_sagen(chaos_args,chaot,0);
      break;

    case "chaosemote":
      if(check_banish(chaot))
        return;

      if(!check_clevel(chaot))
        return;

      chaos_sagen(chaos_args,chaot,1);
      break;

    case "chaoshist":
    case "chaoshistory":
      if(check_banish(chaot))
        return;

      if(!check_clevel(chaot))
        return;

      c_hist(chaos_args,chaot);
      break;

    case "chaosblockade":
      chaosblockade(chaos_args,chaot);
      break;
    default: break;
  }
}

protected void create()
{
  seteuid(getuid(ME));
  provider_list = ({});
  restore_me();
  brain         = ({});
}
