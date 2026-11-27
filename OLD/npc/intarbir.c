// intarbir.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            Fehlendes return

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  
inherit CHAOS_GILDEN_OBJ("std/funcs");
static int use = 12;

string Schaden(mixed ar, string *einschaetzung);

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(8,200);
  SetProp(P_SHORT, "Ein kleiner Daemon namens Intarbir" );
  SetProp(P_LONG,
  "Dieser kleine Daemon sieht recht intelligent aus. Er ist nicht gerade "
  "zum Kaempfen geboren aber sein grosser Kopf mit der hohen Stirn und "
  "die fast roentgenartigen Augen lassen vermuten, dass dieser Daemon mit "
  "einem Blick ein Wesen auf seine Staerke abschaetzen kann. ");
  SetProp(P_NAME,"Intarbir");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,MALE);
  SetProp(P_ALIGN,-100);
  SetProp(P_HANDS,({" mit blossen Klauen",40,DT_RIP}));
  SetProp(P_BODY,20);
  SetProp(P_MMSGIN, "steigt aus den tiefesten Hoellen empor" );
  SetProp(P_NOCORPSE,1);
  SetProp(P_DIE_MSG," verlaesst diese Welt.\n");
  AddId(({"intarbir"}));
  AddCmd(({"befehle","befehl"}),"daemon_befehl");
}

string NochMehrDamTypes( string dt)
{
  switch(dt){
    case DT_ACID:
      return "Saeure";
    case DT_AIR:
      return "Luft";
    case DT_BLUDGEON:
      return "Schlaege";
    case DT_COLD:
      return "Kaelte";
    case DT_EXPLOSION:
      return "Explosionen";
    case DT_DARKNESS:
      return "Boese";
    case DT_FIRE:
      return "Feuer";
    case DT_LIGHTNING:
      return "Blitze";
    case DT_MAGIC:
      return "Magie";
    case DT_PIERCE:
      return "Stiche";
    case DT_POISON:
      return "Gift";
    case DT_RIP:
      return "Reissen";
    case DT_SLASH:
      return "Schnitte";
    case DT_SQUEEZE:
      return "Quetschen";
    case DT_WATER:
      return "Wasser";
    case DT_WHIP:
      return "Peitschen";
    case DT_LIGHT:
      return "Heilig";
    case DT_SMELL:
      return "Gestank";
    case DT_SOUND:
      return "Krach";
    case DT_TERROR:
      return "Terror";
  }
  return "besitzt unbekannte Faehigkeiten";
}

static int check_monster(object mon,object pl)
{
  if(object_name(mon)[0..7]=="/secure/" ||
     object_name(mon)[0..4]=="/obj/")
  {
    tell_object(pl,break_string("Ueber "
    +mon->name()+" sag ich nichts! Nicht, dass ich Angst haette, sowas "
    "kenne ich nicht! Aber das Mistbiest stinkt schlimmer als "
    "eine alte Unterhose von Zardoz! Das ist selbst fuer mich zuviel!",0,
    "Intarbir teilt Dir mit: "));
    return 1;
  } 
  if(!living(mon) && !interactive(mon) && !mon->QueryProp(P_NPC))
  {
    tell_object(pl,"Intarbir teilt Dir mit: "+mon->name()+
                   " lebt doch gar nicht!\n");
    return 1;
  }
  
  if(find_call_out("schaetze_monster") == -1)
    call_out("schaetze_monster",2,pl,mon);

  say(pl->Name(WER)+" sagt: Intarbir, schaetze "+mon->name(WEN)+
      " ein.\n",pl);
  
  tell_room(environment(ME), "Intarbir schaut "+mon->name(WEN)+
            " abschaetzend an.\n",({mon}));
  
  tell_object(mon,"Intarbir schaut Dich abschaetzend an und grinst "
              "fies.\n");
  return 1;
}

static int enemy_check_fail(string monster,object pl)
{
  if(!present(monster,environment(ME)))
  {
    tell_object(pl,"Intarbir teilt Dir mit: "+capitalize(monster)+
                " kann ich hier nicht finden.\n");
    return 0;
  }
  return 1;
}

static void nixversteh(object pl)
{
  tell_object(pl,"Intarbir versteht garnix mehr!\n");
}

int daemon_befehl(string str)
{
  string ich,monster,tmp,abhauen,was,nr;
  object mon,pl;

  if(!str)
    return 0;

  if(::befehle_daemon(str))
    return 1;

  if(sscanf(str,"%s %s",ich,was)>=2 && id(ich))
  {
    if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER) &&
       !present("intarbir_"+getuid(PL),environment(ME)))
    {
      tell_room(environment(ME),"Intarbir gibt "+
                PL->name(WEM)+" einen Tritt in den Hintern.\n",({PL}));

      tell_object(PL,"Intarbir gibt Dir einen Tritt in den Hintern.\n");

      PL->reduce_hit_points(5);

      return 1;
    }
    if(member(QueryProp(P_IDS),"intarbir_"+getuid(PL))!=-1)
    {
      if(was=="verschwinde")
      {
        if(use==12)
        {
          tell_room(environment(ME),"Intarbir haut "+
                    PL->name(WEM)+" eine aufs Maul.\n",({PL}));
          tell_object(pl,"Intarbir haut Dir eine aufs Maul.\n");
          pl->reduce_hit_points(5);
          return 1;
        }
        else
        {
          tell_room(environment(PL),PL->ame(WER)+" befiehlt "
                    "Intarbir, zu verschwinden.\n",({PL}));

          tell_object(PL,"Du befiehlst Intarbir zu verschwinden.\n");

          ME->move(CHAOS_GILDEN_ROOM("critual"),M_GO|M_SILENT);

          tell_object(PL,"Intarbir verschwindet fluchend!\n");

          ME->remove();
          return 1;
        }
      }
      if(sscanf(str,"%s schaetze %s %s ein",ich,monster,nr)==3||
         sscanf(str,"%s schaetz %s %s ein",ich,monster,nr)==3)
      {
        if(id(monster))
        {
          tell_object(PL,break_string("Netter Versuch!",0,
                      "Intarbir teilt Dir mit: "));
          
          tell_object(PL,"Intarbir beisst Dir ins Bein!\n");
          
          tell_room(environment(ME),"Intarbir beisst "+PL->name(WEM)+
               " ins Bein!\n",({pl}));
          
          PL->do_damage(5+random(10),ME);
          return 1;
        }
        else
        {
          int i = to_int(nr);

          if(i<=0)
          {
            tell_object(PL,break_string("Kannst Du nicht zaehlen, Du dummes "
                        "Miststueck!?",0,"Intarbir teilt Dir mit: "));
            return 1;
          }
          else
          {
            object j,next;
            
            for(j=first_inventory(environment(ME));j;)
            {
              next = next_inventory(j);
              if(j->id(monster)==1)
              {
                i--;
                if(i==0)
                {
                  check_monster(j,pl);
                  return 1;
                  break;
                }
              }
              if(i<0)
              {
                tell_object(pl,"Intarbir versagt grinsend.\n");
                return 1;
                break;
              }
              j=next;
            } 
            if(!enemy_check_fail(monster+" "+nr,pl))
              return 1;
          }
        }
      }
      else if(sscanf(str,"%s schaetze %s ein",ich,monster)==2||
              sscanf(str,"%s schaetz %s ein",ich,monster)==2)
      {
        if(id(monster))
        {
          tell_object(PL,break_string("Du bist ja perverser als ich! "
                      "Verdammt! Ich bin zwar ein Daemon, aber nicht voellig "
                      "verbloedet!!",0,"Intarbir teilt Dir mit: "));
          return 1;
        }
        if(!(mon=present(monster,environment(ME))))
        {
          tell_object(PL,break_string(capitalize(monster)+" kann ich hier "
                      "nicht finden!",0,"Intarbir teilt Dir mit: "));
          return 1;
        }
        else
        {
          check_monster(mon,pl);
          return 1;
        }
      }
      nixversteh(pl); 
      return 1;
    }
  }
  return 0;
}
string schaetze_resistenzen(float wert)
{
   if      (wert<=-1.0) return "ultrasuperstark";
   else if (wert<-0.5)  return "superstark";
   else if (wert<-0.3)  return "ziemlich";
   else if (wert<-0.1)  return "ein klein wenig";
   else if (wert< 0.2)  return "ein klein wenig";
   else if (wert< 0.7)  return "ziemlich";
   else if (wert< 1.2)  return "superstark";
   else if (wert< 1.5)  return "ultrasuperstark";
   else return "extrem";
}

void schaetze_monster(object pl, object victim)
{
  mapping res;
  object ob;
  int dif;
  int plw, vw;
  int i,glevel,gesch;
  mixed *dam_types, *rwerte, *vwerte;
  float resis_wert;
  string *reinsch, *veinsch;
  string vname, vnamegen, result,gilde;

  if(!pl)
    return;
  
  if(!victim)
    return;
  
  plw = pl->QueryProp(P_HP);
  vw  = victim->QueryProp(P_HP);
  dif = plw -vw;  
  i   = victim->QueryProp(P_ALIGN);
  
  if(QueryProp(DAEM_FALSE))
  {
    if(!interactive(victim) && !random(20) && ((-dif>plw) || 
      (-dif>2*plw)))
    {
      call_out("monster_boese",2,victim);
    }         
    dif = -100+random(200);
  }          
  vname    = victim->name(WER,1);
  vnamegen = victim->name(WESSEN,1);
  result   = "Also, nun. Lausche meinen Worten: ";  

  if (dif>vw/4)
    result+="Du bist etwas staerker als " + vname + 
    ", was kein Grund zu voreiliger Freude ist. ";

  else if (-dif>2*plw)
    result+="Vergiss es lieber. "+capitalize(vname) + 
    " ist hydramaessig viel staerker als Du. ";

  else if (-dif>plw)
    result+="Brech nicht gleich in Traenen aus, aber "+ capitalize(vname) + 
    " ist Dir ueberlegen. ";

  else
    result+=capitalize(vname) + " hat in etwa Deine Kragenweite. ";

  plw = pl->QueryProp(P_TOTAL_AC);  
  vw  = victim->QueryProp(P_TOTAL_AC);  
  dif = plw-vw;
  
  if(QueryProp(DAEM_FALSE)) 
    dif =- 100+random(200);                            
  
  if (dif>2*vw)
    result += "Deine Ruestung ist unglaublich viel "+
    "besser als die " + vnamegen + ". ";

  else if (dif>vw)
    result+="Deine Ruestung ist viel besser als die " + vnamegen + ". "; 

  else if (dif>vw/5)
    result+="Deine Ruestung ist besser als die " + vnamegen + ". ";

  else if (-dif>2*plw)
    result+="Die Ruestung " + vnamegen 
    +" ist unglaublich viel besser als Deine. ";

  else if (-dif>plw)
    result+="Die Ruestung " + vnamegen + " ist viel besser als Deine. ";

  else if (-dif>plw/5)
    result+="Die Ruestung " + vnamegen + " ist besser als Deine. ";

  else
    result+="Nun, eure Ruestungen sind etwa gleich gut. ";

  result += "Zu guter Letzt: "; 
  plw     = pl->QueryProp(P_TOTAL_WC);  
  vw      = victim->QueryProp(P_TOTAL_WC);
  dif     = plw-vw;

  if(QueryProp(DAEM_FALSE)) 
    dif = -100+random(200);

  if (dif>2*vw)
    result += "Deine Waffe ist eigentlich schon fast unverschaemt "
              "gut gegen so einen laecherlichen Gegner. ";
  else if (dif>vw)
    result += "Deine Waffe ist viel besser als die " +vnamegen + ". ";
  
  else if (dif>vw/5)
    result += "Deine Waffe ist besser als die " +vnamegen + ". ";
  
  else if (-dif>2*plw)
    result += "Deine Waffe ist der reinste Witz! Damit kommst Du gegen "+
              victim->name(WEN, 1)+ " nicht an. ";
  
  else if (-dif>plw)
    result += vname+" hat eine Waffe, die viel viel besser als Deine ist. ";
  
  else if (-dif>plw/5)
    result += "Die Waffe " + vnamegen + " ist besser als Deine, aber "+
              "Du schaffst das schon! ";
  else
    result += "Eure Waffen sind etwa gleich gut oder schlecht (je "+
              "nachdem :-)). ";
  
/*
  if(victim->QueryProp(P_ENABLE_IN_ATTACK_OUT))
  {
     result += capitalize(vname)+" sieht so aus, als ob "+
               victim->QueryPronoun(WER)+" sich leicht ueberraschen lassen "
               "wuerde. ";
  }     
*/

  if( environment(ME)->QueryProp(P_INT_LIGHT) < 1 )
  {
    if( !victim->CannotSee() )
       result += capitalize(vname)+" kann Dich trotz Dunkelheit sehen. ";
  }

  if(pl->QueryProp(P_GUILD_LEVEL)>=9)
  {
    if(objectp(ob=victim->QueryProp(P_WEAPON)))
    {
      result += capitalize(victim->QueryPronoun())+" kaempft mit "+
                ob->name(WEM)+" und macht damit folgenden Schaden: ";
      
      dam_types = ob->QueryProp(P_DAM_TYPE);
      
      if(stringp(dam_types))
        dam_types=({dam_types});
    }
    else
    {
      result += capitalize(victim->QueryPronoun())+" kaempft"+
                victim->QueryProp(P_HANDS)[0] +
                " und macht damit folgenden Schaden: ";
      
      dam_types = victim->QueryProp(P_HANDS)[2];
      
      if( stringp( dam_types))
        dam_types =({dam_types});
    }
    for(i=sizeof(dam_types)-1;i>=0;i--)
    {
      result += NochMehrDamTypes(dam_types[i]);

      if(i>1)
        result+= ", ";

      else if(i==1)
        result+=" und ";
      
      else
        result+=". ";
    }
  }  
  if(pl->QueryProp(P_GUILD_LEVEL)>=6)
  {
    if(QueryProp(DAEM_FALSE)) 
      i=-1000+random(2000);
  
    else
      i=victim->QueryProp(P_ALIGN);
  
    if(i>=0)
    {
      switch(i)
      {
        case 0..99:
          result += capitalize(vname) +" hat eine neutrale Gesinnung. ";
          break;
          
        case 100..299:
          result += "Naja, "+vname+" ist eine halbwegs gute Gestalt. ";
          break;
        
        case 300..599:
          result += "Ist ja ekelhaft! "+capitalize(vname)+" hat eine gute "
                    "Gesinnung. ";
          break;

        case 600..799:
          result += "Ohoh, "+vname+" ist gut und fromm. ";
          break;

        case 800..899:
          result += "Pfuih deibel, "+vname+" ist gut und fromm und noch "
                    "vielmehr! ";
          break;  

        case 900..999:
          result += "Arghs! "+vname+" koennte einer dieser Betbrueder sein! ";
          break;  

        default:
          result += "Igitt, "+vname+" ist heiliger als all das Klerikerpack "
                    "zusammen! BRING DAS VIEH UM! ";
          break;
      }
    }
    else
    {
      switch(i)
      {
        case (-99)..(-1):
          result += capitalize(vname) + " ist ein bisschen frech. ";
          break;
        
        case (-200)..(-100):
          result += capitalize(vname)+" ist recht frech. :-) ";
          break;
        
        case (-500)..(-201):
          result += capitalize(vname) + " ist richtig schoen boese! ";
          break;
        
        case (-900)..(-501):
          result += capitalize(vname)+" ist aeusserst boese :) ";
          break;
        
        default:
          result += "Hui! Nett, "+vname+" ist richtig schoen satanisch, "
                    "wie es sich gehoert. ";
          break;
      }
    }
  }
  if(pl->QueryProp(P_GUILD_LEVEL) >= 10 && !QueryProp(DAEM_FALSE))
  {
    rwerte  = ({});
    vwerte  = ({});
    reinsch = ({});
    veinsch = ({});
  
    res = victim->QueryProp(P_RESISTANCE);
  
    if(mappingp(res))
    {  
      dam_types = m_indices(res);
    
      for(i=sizeof(dam_types)-1;i>=0;i--)
      {
        if(to_float(resis_wert=to_float(res[dam_types[i]]))<to_float(0))
        { 
          rwerte  += ({dam_types[i]});
          reinsch += ({schaetze_resistenzen(resis_wert)});
        }
        if(to_float(resis_wert=to_float( res[dam_types[i]]))>to_float(0) &&
          pl->QueryProp(P_GUILD_LEVEL)>=11)
        {
          vwerte  += ({dam_types[i]});
          veinsch += ({schaetze_resistenzen(resis_wert)});
        }
      }
      result += capitalize(vname)+" ist "+Schaden(rwerte,reinsch)+
                " resistent. ";

      if(pl->QueryProp(P_GUILD_LEVEL)>=11)
        result += capitalize(vname)+" ist "+Schaden(vwerte,veinsch)+
                  " anfaellig. ";
    }
  }
  tell_object(pl,break_string(result,0,"Intarbir sagt: "));

  glevel = pl->QueryProp("guild_level");

  switch(glevel)
  {
    case 1..3:
      use=0;
      break;
    case 4..6:
      use-=6;
      break;
    case 7..9:
      use-=4;
      break;
    default:
      use-=3;
      break;
  }
  if(use<=0)
    wech(pl,5);
} 

string Schaden(mixed ar, string *einschaetzung)
{
  string s;
  int i, size;

  s    = "";
  size = sizeof(ar);

  if(!size)
    return "gegen keinen Schaden besonders";
  
  for(i=0;i<size;i++)
  {
    if(size>1&&i==size-1)
    {
      s += "und "+einschaetzung[i]+
           " gegen "+Funcs_DamText(ar[i],1);
           
           "/gilden/chaos/spellbook"->ChaosDamageText(ar[i],1);
      break;
    }
    s += einschaetzung[i]+" gegen "+ Funcs_DamText(ar[i],1);

    if(size==1)
        s=s[0..<3];
  }
  return s;
}
