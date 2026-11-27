// orakel.c - Der Orakeldämon der Chaosgilde
//
// Fasst die alten Dämonen Intarbir (Monster einschätzen), Kruftur
// (Gegenstände identifizieren) und Tyoorthok (die eigene Konstitution)
// zusammen. Was er beantwortet, hängt von der Gildenstufe des
// Beschwörers ab:
//
//   ab Stufe 4: frage <name> nach <monster>
//   ab Stufe 5: frage <name> nach <gegenstand>, frage <name> nach
//               pentagramm, oder ihm einen Gegenstand geben
//   ab Stufe 7: frage <name> nach mir
//
// Nach ein paar Fragen verschwindet er (je höher die Gildenstufe,
// desto mehr Fragen).
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu, aus Intarbir, Kruftur und
//                                     Tyoorthok

#pragma strong_types

#include "def.h"

inherit CHAOS_GILDEN_MON("daemon");
inherit CHAOS_GILDEN_OBJ("std/funcs");

#define STUFE_MONSTER     4
#define STUFE_GEGENSTAND  5
#define STUFE_KOERPER     7

static int use = 12;

string Schaden(mixed ar, string *einschaetzung);
string query_information(object mon);
string info_daemonen(object p);
string prozente(float prozent,int pfaktor,int bfaktor);

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  daemon::create();
  funcs::create();
}

// Name eines Dämonentyps ("Schattendämon")
static string typ_name(string t) {
  mapping d = CHAOS_DAEMONEN_MASTER->QueryTyp(t);

  return d ? d[CD_NAME] : capitalize(t);
}

// Zählt die Fragen herunter. Wenn alle verbraucht sind, verschwindet
// der Dämon.
static int zaehle_runter(object pl) {
  switch(pl->QueryProp(P_GUILD_LEVEL)) {
    case 1..3:
      use = 0;
      break;
    case 4..6:
      use -= 6;
      break;
    case 7..9:
      use -= 4;
      break;
    default:
      use -= 3;
      break;
  }
  if(use <= 0) {
    wech(pl,5);
  }
  return 1;
}

static void sag(object pl, string txt) {
  tell_object(pl,break_string(txt,0,Name(WER,1)+" sagt: "));
}

// ---- Einschätzen und Identifizieren (aus den alten Dämonen) ----

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
  tell_object(pl,break_string(result,0,Name(WER,1)+" sagt: "));
  zaehle_runter(pl);
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

static string gegenstand_bloedsinn(object ob)
{
  string s;

  switch(random(43))
  {
    case 0: 
      s = "Hmmm... ich hab keine Ahnung.";
      break;
    case 1: 
      s = ob->Name(WER,1)+" hat magische Kraefte.";
      break;
    case 2: 
      s = ob->Name(WER,1)+" ist nur fuer Magier zugelassen.";
      break;
    case 3: 
      s = "Ich sah nur einen Fehler im Raum-Zeit-Gefuege.";
      break;
    case 4: 
      s = ob->Name(WER,1)+" lebt doch gar nicht!";
      break;
    case 5: 
      s = "Entsorge es beim Troedelhaendler.";
      break;
    case 6:
      if(!interactive(ob)) 
        s = capitalize(getuid(ob))+
            " ist fuer diesen Bloedsinn verantwortlich.";
      else 
        s = ob->Name(WER,1)+" ist saubloed.";
      break;
    case 7: 
      s = "Das Zauberwort ist: serwpol.";
      break;
    case 8: 
      s = "Wenn Du "+ob->name(WEN,1)+" anziehst, dann hast Du den besten "
          "Schutz im Efferdland.";
      break;
    case 9: 
      s = "Du kannst "+ob->name(WEN)+" zuecken.";
      break;
    case 10: 
      s = ob->Name(WER,1)+" ist nur fuer Karateka interessant.";
      break;
    case 11: 
      s =ob->Name(WER,1)+" ist nur fuer Zauberer."; 
      break;
    case 12: 
      s = "Damit kann man Wolpertinger toeten.";
      break;
    case 13: 
      s = "Bitte verstaendige einen Erzmagier oder Gott!";
      break;
    case 14: 
      s = "Error: operating on destructed object.";
      break;
    case 15: 
      s = ob->Name(WER,1)+" ist 2 Rubel wert.";
      break;
    case 16: 
      s = "Du brauchst "+ob->name(WER,1) +" fuer die Geisterhaus-Quest.";
      break;
    case 17: 
      s = "Du brauchst "+ob->name(WER,1)+" fuer die Rattenplage-Quest.";
      break;
    case 18: 
      s = "Das Zauberwort ist: gremussul.";
      break;
    case 19: 
      s = ob->Name(WER,1)+" ist ein hocherotisches Objekt.";
      break;
    case 20: 
      s = "Du kannst "+ob->name(WER,1)+" auch im Seherladen kaufen.";
      break;
    case 21: 
      s = "Du kannst hiermit den Zaubertrank aus der Eiszinne oeffnen.";
      break;
    case 22: 
      s = "Du kannst "+ob->name(WEN,1)+" beim Untier fuer "
          "ein Zauberschwert eintauschen."; 
      break;
    case 23: 
      s = "Du kannst "+ob->name(WEN,1)+" als Beutel benutzen."; 
      break;
    case 24: 
      s = ob->Name(WER,1)+" hat keinen materiellen Wert."; 
      break;
    case 25: 
      s = ob->Name(WER,1)+" ist nicht identifizierbar.";
      break;
    case 26: 
      s = ob->Name(WER,1)+" ist magisch geschuetzt.";
      break;
    case 27: 
      s = "Du kannst "+ob->name(WEN,1)+" mit \"toete\" angreifen.";
      break;
    case 28: 
      s = ob->Name(WER,1)+" ist schoen anzusehen.";
      break;
    case 29: 
      s = "Erzmagier sind doof und stinken!";
      break;
    case 30: 
      s = "Zardoz ist voellig unschuldig.";
      break;
    case 31:
      if(interactive(ob))
        s = ob->Name(WER,1)+" sollte am Besten Selbstloeschung machen.";
      else 
        s = "Das Wetter ist mal wieder total mies.";
      break;
    case 32: 
      s = "Der Muelleimer wuerde sich ueber "+ob->name(WEN,1)+" sehr freuen.";
      break;
    case 33: 
      s = ob->Name(WEN,1)+" gibt es nur in der Parallelwelt.";
      break;
    case 34: 
      s = ob->Name(WER,1)+" ist ein Geheimprojekt der Russen.";
      break;
    case 35: 
      s = ob->Name(WEN,1)+" ist hoch versichert.";
      break;
    case 36: 
      s = ob->Name(WER,1)+" kann Geige spielen.";
      break;
    case 37: 
      s = "Frag Kruuolq!";
      break;
    case 38: 
      s = "Frag Hutschat!";
      break;
    case 39: 
      s = ob->Name(WEN,1)+" musst Du Kruuolq geben.";
      break;
    case 40: 
      s = ob->Name(WEN,1)+" kann man an ein Feuerschwert nageln.";
      break;
    case 41:
      s = ob->Name(WEN,1)+" kann man als Analbuerste benutzen.";
      break;
    default: 
      s = "Du musst den Nippel durch die Lasche ziehen.";
      break;
  }
  return s;
}

int get_pf(object p)
{
  int pentaf = 0;

  if (p) 
  {
    pentaf = p->QueryProp(CHAOS_PENTAGRAMM_FAKTOR);
  
    if (p->QueryProp(CHAOS_NEUES_PENTA))
      pentaf += p->QueryProp(CHAOS_PENTAGRAMM_RANDOM);
  }
  return pentaf;
}

int get_kf(object p) 
{
  int kreisf = 0;

  if (p)
  {
    kreisf = p->QueryProp(CHAOS_BANNKREIS_FAKTOR);
    
    if (p->QueryProp(CHAOS_NEUES_PENTA))
      kreisf += p->QueryProp(CHAOS_BANNKREIS_RANDOM);
  }
  return kreisf;
}

string prozente(float prozent,int pfaktor,int bfaktor)
{
  int tmp;
  string *werte;
  
  // Soviel addiert der Bannkreis auf den allgemeinen Faktor (pfkaktor)
  tmp = (int)((bfaktor*7)/(prozent*10000));
  if (tmp>7)
    tmp=7;

  pfaktor += tmp;
  
  // Fuer diesen Daemon ist das Pentagramm jetzt tmp-Prozentig:
  tmp = (int)((pfaktor*100)/(prozent*70));

  if (tmp>100)
    tmp = 100;
  
  werte = ({"fast unbrauchbar",            //0-9
            "sehr sehr uebel",             //10-19
            "sehr sehr schwach",           //20-29
            "schwach",                     //30-39
            "mittelmaessig stark",         //40-49
            "ueberdurchschnittlich stark", //50-59
            "sehr stark",                  //60-69
            "maechtig",                    //70-79
            "sehr maechtig",               //80-89
            "aeusserst maechtig",          //90-99
            "absolut maechtig"});          //100
  return " "+werte[tmp/10];
}

string info_daemonen(object p)
{
  string *welche;
  mapping faktoren;
  int i;
  string str;
  int pfaktor,bfaktor;
  
  pfaktor = p->QueryProp(CHAOS_PENTAGRAMM_FAKTOR)+
            p->QueryProp(CHAOS_BANNKREIS_FAKTOR);

  pfaktor = (pfaktor/2);

  bfaktor = p->QueryProp(CHAOS_BANNZAUBER_FAKTOR);
  

  welche   = ({"schattendaemon","lichtdaemon","feuerdaemon",
                "saeuredaemon","blutdaemon","wandler"});
  faktoren = (["schattendaemon":0.5, "lichtdaemon":0.6, "feuerdaemon":0.7,
               "saeuredaemon":0.8, "blutdaemon":0.9, "wandler":1.0]);

  for (i=sizeof(welche)-1;i>=0;i--)
    if (!PL->QuerySkill(welche[i]))
      welche-=({welche[i]});

  if (!sizeof(welche))
    return "";
  
  if (sizeof(welche)==1)
    return " Durch dieses Pentagramm wird ein "+typ_name(welche[0])+
       prozente(faktoren[welche[0]],pfaktor,bfaktor)+" werden.\n";
  
  str = " Durch dieses Pentagramm wird ";
  
  for (i=0;i<sizeof(welche);i++) 
  {
    str += "ein "+typ_name(welche[i]) +
           prozente(faktoren[welche[i]],pfaktor,bfaktor);
    
    if (i==sizeof(welche)-2)
      str+=" und ";
    
    else if (i==sizeof(welche)-1)
      str+=" werden.\n";
    
    else str+=", ";
  }
  return str;
}

int beurteilung()
{
  object p;     
  string s;
  int penta, kreis;

  if(!p = present( "\nchaos_gilden_pentagramm_"+getuid(PL),
     environment(ME)))
  {
    tell_room( environment(),break_string( 
      "Zeichne erstmal ein Pentagramm. Wie soll ich Dein "+
      "Pentagramm denn sonst untersuchen?",0,Name(WER)+" sagt: "));
      return 1;
  }
  penta = get_pf(p);

  switch(penta){
    case 0..25: 
      s="Das ist ein ganz mieses Pentagramm. ";
      break;
    case 26..55:
      s="Das Pentagramm ist ganz ordentlich. ";
      break;
    case 56..75:
      s="Das Pentagramm ist boese geworden. ";
      break; 
    case 76..100:
      s="Das Pentagramm ist sehr boese geworden. ";
      break;
    case 101..130:
      s="Das Pentagramm ist ausgezeichnet gelungen. ";
      break; 
    case 131..160:
      s="Das Pentagramm ist unglaublich boese. ";
      break; 
    case 161..20000:
      s="Dies ist das bestmoegliche Pentagramm. ";
      break; 
    default: 
      s="Das gibts doch gar nicht! Wie kann man nur so ein "+
      "schlechtes Pentagramm zeichnen? ";
      break; 
  }
  if(!p->QueryProp(CHAOS_BANNKREIS ))
    s += "Du hast noch keinen Bannkreis um das Pentagramm gezeichnet.";

  else
  {
    kreis = get_kf(p);

    switch(kreis){
      case 0..15:
        s+="Das ist kein Bannkeis, das ist ein Sechseck.";
        break;
      case 16..40:
        s+="Der Bannkreis ist schlecht geworden.";
        break;
      case 41..65:
        s+="Der Bannkreis ist Dir ganz ordentlich gelungen.";
        break;
      case 66..80:
        s+="Der Bannkreis ist ganz boese.";
        break;
      case 81..115:
        s+="Ja, der Bannkreis ist boese.";
        break;
      case 116..140:
        s+="Der Bannkreis ist sehr boese."; 
        break;
      case 141..170:
        s+="Der Bannkreis ist ausgezeichnet gelungen.";
        break;
      case 171..220:
        s+="Der Bannkreis ist spitzenmaessig.";
        break;
      case 221..20000:
        s+="Dies ist der bestmoegliche Bannkreis.";
        break;
      default: 
        s+="So einen stuemperhaften und schaebigen Bannkreis "+
           "hab ich in meinem ganzen Leben noch nicht gesehen!";
        break;
    }
  }
  if(p->QueryProp(CHAOS_BANNKREIS)==1)
    s+=" Du hast noch keinen Bannzauber auf den Bannkreis gelegt.";

  /* und jetzt wirds hart...*/
  if (p->QueryProp(CHAOS_NEUES_PENTA))
    s+= info_daemonen(p);
  
  tell_room(environment(),break_string(s,0,Name(WER)+" sagt: " ));

  zaehle_runter(PL);
  return 1;
}

string query_information(object mon)
{
  string s,mon_gen;
  int wert, level, dam, total;

  mon_gen = mon->QueryPronoun(WER);
  s       = mon->QueryProp(P_INFO); 
  level   = PL->QueryProp(P_GUILD_LEVEL);
  
  if(!s) 
    s = "Ich konnte nichts besonderes erkennen. ";

  if(!living(mon) && level>7)
  {
    wert = mon->QueryProp(P_BUY_VALUE);

    if(!wert)
      s += mon->Name(WER)+" hat keinen materiellen Wert. ";

    else
      s += mon->Name(WER)+" hat einen Wert von "
           +ChangeCurrency(wert,KREUZER,RUBEL)+" Rubel. ";
  }
  if(!living(mon))
  {
    if(mon->QueryProp(P_CONTAINER))
    {
      int i,j;
      s += "In "+mon->name(WER)+" kannst Du Sachen hineinstecken, ";
      i  = mon->QueryProp(P_MAX_WEIGHT);
      j  = mon->QueryProp(P_WEIGHT_PERCENT);
      
      switch(i)
      {
        case 0..9999: s+="wenn auch nur eine Handvoll. ";
         break;
        case 10000..19999: s+="aber nicht besonders viel. ";
         break;
        case 20000..29999: s+="da passt einiges hinein. ";
         break;
        case 30000..39999: s+="recht viele sogar. ";
         break;
        case 40000..49000: s+="und wenn es auch sehr viele sind. "; 
         break;
        default: s+="und zwar jede Menge. ";
         break;      
       }
      s += capitalize(mon->QueryPronoun(WER))+" ist zum Tragen ";

      switch(j){
        case 0..39: s+="absolut perfekt geeignet. ";
         break;
        case 40..49: s+="perfekt geeignet. ";
         break;
        case 50..59: s+="hervorragend geeignet. ";
         break;
        case 60..69: s+="ausgezeichnet geeignet. ";
         break;
        case 70..79: s+="gut geeignet. ";
         break;
        case 80..89: s+="befriedigend geeignet. ";
         break; 
        case 90..99: s+="maessig geeignet. ";
         break; 
        default: s+="ueberhaupt nicht geeignet. ";
         break; 
      }
    }
  }
  if(!living(mon)&&level>8)
  {
    wert  = mon->QueryProp(P_WEIGHT);
    wert += -100+random(201);
    
    s += capitalize(mon->QueryPronoun())+ " wiegt etwa "+wert+" Gramm.\n";

    if(mon->QueryProp(P_WEAPON_TYPE) || mon->QueryProp(P_ARMOUR_TYPE))
    {
      if(dam = mon->QueryDam())
      {
        if(mon->QueryProp(P_ARMOUR_TYPE))
          total = dam + mon->QueryProp(P_AC);

        else if(mon->QueryProp(P_WEAPON_TYPE))
          total = dam + mon->QueryProp(P_WC);
        
        switch((total/100)*dam){
          case 0..10:
            s+=mon->Name(WER)+" ist leicht beschaedigt.\n";
            break;
          case 11..20:
            s+=mon->Name(WER)+" ist etwas beschaedigt.\n";
            break;
          case 21..30:
            s+=mon->Name(WER)+" hat schon boese einen abbekommen.\n";
            break;
          case 31..40:
            s+=mon->Name(WER)+" hat schon ziemlich gelitten.\n";
            break;
          case 41..50:
            s+=mon->Name(WER)+" ist nur noch die Haelfte wert.\n";
            break;
          case 51..60:
            s+=mon->Name(WER)+" ist etwas weniger als die "+
               "Haelfte wert.\n";
            break;
          case 61..70:
            s+=mon->Name(WER)+" wuerde ich nicht geschenkt nehmen.\n";
            break;
          case 71..80:
            s+=mon->Name(WER)+" wuerde ich nur einem Feind "+
               "schenken.\n";
            break;
          case 81..90:
            s+=mon->Name(WER)+" ist einfach nur Dreck.\n";
            break;
          default:
            s+=mon->Name(WER)+" ist absuluter Muell, wer hat "+
               "Dir denn diesen Mist angedreht??\n";
            break;
        }
      }
      if(mon->QueryProp(P_CURSED))
        s+="Ausserdem ist "+mon_gen+" verflucht, was mir persoenlich "
           "sehr gefaellt.\n";
    }
  }
  return s;
}

static string koerper_bloedsinn(object pl, int mon)
{
  switch(random(28))
  {
    case 0:
      if(mon) 
        return pl->Name(WER,1)+" steht auf der Schwelle des Todes.";
      return "Du stehst auf der Schwelle des Todes.";
      break;
    case 1:
      if(mon)
        return pl->Name(WER,1)+" hat eine Lebensmittelvergiftung und die "
              "Scheisserei.";

      return "Du hast eine Lebensmittelvergiftung und die Scheisserei.";
      break;
    case 2:
      if(mon)
        return pl->Name(WER,1)+" riecht aus dem Mund wie eine Kuh aus dem "
               "Arsch.";
      return "Du riechst aus dem Mund wie eine Kuh aus dem Arsch.";
      break;
    case 3:
      if(mon)
        return pl->Name(WER,1)+" sollte dringend mal wieder duschen.";
      return "Du solltest dringend mal wieder duschen.";
      break;
    case 4:
      if(mon)
        return pl->Name(WER,1)+" hat Zahnfaeule.";
      return "Du hast Zahnfaeule.";
      break;  
    case 5:
      if(mon)
        return pl->Name(WER,1)+" muss unbedingt zum Friseur.";
      return "Du musst unbedingt zum Friseur.";
      break;
    case 6:
      if(mon)
        return pl->Name(WER,1)+" sollte besser einen Arzt aufsuchen.";
      return "Du solltest besser einen Arzt aufsuchen.";
      break;
    case 7:
      if(mon)
        return pl->Name(WER,1)+" hat zuwenig Muenzen bei sich.";
      return "Du hast zuwenig Muenzen bei Dir.";
      break;
    case 8:
      if(mon)
        return pl->Name(WER,1)+" braucht gruendlich Hiebe.";
      return "Du brauchst gruendlich Hiebe.";
      break;
    case 9:
      if(mon)
        return pl->Name(WESSEN)+" Fingernaegel sind zu lang.";
      return "Deine Fingernaegel sind zu lang.";
      break;
    case 10:
      if(mon)
        return "Ich seh echt keinen Ausweg fuer "+pl->name(WEN,1);
      return "Ich seh echt keinen Ausweg fuer Dich.";
      break;
    case 11:
      if(mon)
        return pl->Name(WER,1)+" sollte sich erstman was anstaendiges zum "
               "Trinken besorgen.";
      return "Besorg mir erstmal was anstaendiges zum Trinken.";
      break;
    case 12:
      return "Lass mich in Ruhe mit Deinem Geflenne!";
      break;
    case 13:
      if(mon)
        return pl->Name(WER,1)+" sollte zu einem Kleriker gehen, diese Memme.";
      return "Geh doch zu den Klerikern, Memme.";
      break;
    case 14:
      return "Scheiss Job hier.";
      break;
    case 15:
      if(mon)
        return pl->Name(WESSEN,1)+" Beine sind zu kurz.";
      return "Deine Beine sind zu kurz.";
      break;
    case 16:
      return "Deine Sicherheitsstufe ist nicht hoch genug.";
      break;
    case 17:
      return "Frag lieber wen anders, ich hab keine Lust.";
      break;
    case 18:
      if(mon)
        return pl->Name(WER,1)+" ist zu fett und saeuft zuviel.";
      return "Du bist zu fett und saeufst zuviel.";
      break;
    case 19:
      return "Sag mal 'AAAAAAAAAAAAAAAAAAAAAAH'.";
      break;
    case 20:
      return "Huste zweimal hintereinander und spuck in die Luft.";
      break;
    case 21:
      return "30 Minuten Luft anhalten und Kopfstand machen.";
      break;
    case 22:
      return "Mit gekreuzten Beinen eine Viertelstunde bei Fencheltee "
             "meditieren.";
      break;
    case 23:
      return "Die Pupillen kreisen und sechszehn Liter Bier trinken.";
      break;
    case 24:
      return "Mach Dich mal nackig.";
      break;
    case 25:
      return "Dreimal um den Block laufen und danach ein heisses Bad nehmen.";
      break;
    case 26:
      if(mon)
        return pl->Name(WESSEN,1)+" Leber ist geschrumpft, die Nieren sind "
               "futsch und eigentlich interessiert das wirklich kein "
               "Schwein.";
      return "Deine Leber ist geschrumpft, Deine Nieren sind futsch und "
             "eigentlich interessiert das wirklich kein Schwein.";  
  }
  return "Die Rechnung schick ich per Nachnahme.";
}

string total_deaf(object pl)
{
  if(pl->QueryProp(P_DEAF))
    return "Du bist taub, da kann ich ja fein laestern.\n";

 return "Du bist nicht taub.\n";
}

string total_soak(object pl, int mon)
{
  switch(pl->QueryProp(P_FOOD)*100/pl->QueryProp(P_MAX_FOOD))
  {
   case 0..24:
    if(mon)
      return pl->Name(WESSEN,1)+" Magen vertraegt noch ein 5-Gaenge-Menue "
             "inklusive Nachspeisen.";

    return "Dein Magen vertraegt noch ein 5-Gaenge-Menue inklusive "
           "Nachspeisen.";
  
   case 25..49:
    if(mon)
       return "In "+pl->name(WESSEN,1)+" Magen passt noch einiges rein.";

    return "In Deinen Magen passt noch einiges rein."; 
  
   case 50..74:
    if(mon)
      return "Oha, bei diesem Essverhalten bekommt "+pl->name(WER,1)+"sicher "
             "bald Magengrimmen.";
   
    return "Oha, bei Deinem Essverhalten bekommst du sicher bald "
           "Magengrimmen.";

   case 75..94:
     return "Vielleicht noch ein Pfefferminzblaettchen, aber mehr nicht!";

  }
  if(mon)
    return pl->Name(WER)+" muss unbedingt eine Zeitlang fasten.";

  return "Du musst unbedingt eine Zeitlang fasten.";
}

string total_alc(object pl,int mon)
{
 switch(pl->QueryProp(P_ALCOHOL)*100/pl->QueryProp(P_MAX_ALCOHOL))
 {
  case 0..9:
   if(mon)
     return pl->Name(WER,1)+" kann jedes Gelage mitmachen.";
   return "Du kannst jedes Gelage mitmachen.";
  
  case 10..19:
   if(mon)
     return "Diese paar Glaeschen hauen "+pl->name(WEN,1)+" so schnell "
            "nicht um.";
   return "Diese paar Glaeschen hauen Chaoten nicht so schnell um.";
  
  case 20..29:
   if(mon)
     return pl->Name(WER,1)+" ist nichtmehr sonderlich nuechtern.";
   return "Du bist nichtmehr sonderlich nuechtern. Brav so!";
  
  case 30..39:
   if(mon)
     return pl->Name(WER,1)+" hat Muehe, die Sinne beieinander zu halten. "
            "Deine Chance! Bring "+pl->name(WEN,1)+" um!";
   return "Du hast Muehe, Deine Sinnen beieinander zu halten.";
  
  case 40..49:
   if (mon)
     return pl->Name(WER,1)+" faengt schon an zu schwanken. Sieht witzig "
            "aus.";
   return "Du faengst schon an zu schwanken.";
  
  case 50..59:
   if(mon)
     return pl->Name(WER,1)+" schwankt, wankt und sieht mich wahrscheinlich "
            "doppelt.";
   return "Du schwankst und wankst, siehst Du mich doppelt?";

  case 60..69:
   if(mon)
     return pl->Name(WER,1)+" wankt schon aufs Uebelste.";
   return "Du wankst schon aufs Uebelste.";

  case 70..79:
   if(mon)
     return "Noch eine Flasche und "+pl->name(WEM,1)+" wird schlecht.";
   return "Noch eine Flasche und Dir wird schlecht.";

  case 80..89:
   if(mon)
     return "Noch ein Schluck und "+pl->name(WER,1)+" muss sich uebergeben.";
   return "Noch ein Schluck und Du musst Dich uebergeben.";
  
  case 90..98:
   if(mon)
     return "Noch ein Tropfen und "+pl->name(WER,1)+" kotzt in die Ecke.";
   return "Noch ein Tropfen und Du kotzt in die Ecke.";
  }
  if(mon)
    return "So regungslose Pupillen hab ich noch nie gesehen.";
  return "Du bist ein besoffenes Schwein!";
}

string total_pois(object pl,int mon)
{
 string str;

 if(mon) 
   str = pl->Name(WER,1)+" ist ";

 else 
   str = "Du bist ";

 switch(pl->QueryProp(P_POISON))
 {
  case 0:
   return str+"nicht vergiftet, so ein Scheiss.";
  case 1..4:
   return str+"vergiftet, nettes Blau im Gesicht.";
  case 5..8:
   return str+"ziemlich vergiftet, gefaellt mir.";
  case 9..11:
   return str+"extrem vergiftet, was fuer ein Glueck.";
 }
 return str+"bei Lars mit der Menge an Gift, gruess ihn mal von mir.";
}

string total_drink(object pl,int mon)
{
 switch(pl->QueryProp(P_DRINK)*100/pl->QueryProp(P_MAX_DRINK))
 {
  case 0..14:
   if(mon)
     return pl->Name(WESSEN,1)+" Blase schreit nach Arbeit.";
   return "Deine Blase schreit nach Arbeit.";
 
  case 15..29:
   if(mon)
     return pl->Name(WESSEN,1)+" Blase hat noch freien Speicher.";
   return "Deine Blase hat noch freien Speicher.";

  case 30..44:
   if(mon)
     return pl->Name(WESSEN,1)+" Blase blubbert vor sich hin.";
   return "Deine Blase blubbert vor sich hin.";

  case 45..59:
   if(mon)
     return "So langsam kommt "+pl->name(WESSEN,1)+" Blase ins Schwitzen.";
   return "So langsam kommt Deine Blase ins Schwitzen.";

  case 60..74:
   return "Naja, ein bisschen passt schon noch rein in das Biest.";

  case 75..89:
   if(mon)
     return "Ohweh, so langsam solltest "+pl->name(WER,1)+" eher was essen "
            "als trinken.";
   return "Ohweh, so langsam solltest du eher was essen als trinken.";
  }
  return "So eine prallgefuellte Blase habe ich noch nie gesehen.";
}

// Ein Monster einschätzen (Intarbir)
static void frage_monster(object pl, object mon) {
  if(object_name(mon)[0..7] == "/secure/" ||
     object_name(mon)[0..4] == "/obj/") {
    sag(pl,"Über "+mon->name(WEN,1)+" sag ich nichts! Nicht, dass ich "
        "Angst hätte, so was kenne ich nicht! Aber das Mistbiest stinkt "
        "schlimmer als eine alte Unterhose von Zardoz!");
    return;
  }
  say(pl->Name(WER)+" fragt "+name(WEN,1)+" nach "+mon->name(WEM,1)+
      ".\n",({pl,mon}));
  tell_room(environment(),Name(WER,1)+" schaut "+mon->name(WEN,1)+
            " abschaetzend an.\n",({mon}));
  tell_object(mon,Name(WER,1)+" schaut dich abschaetzend an und grinst "
              "fies.\n");

  if(find_call_out("schaetze_monster") == -1) {
    call_out("schaetze_monster",2,pl,mon);
  }
}

// Einen Gegenstand identifizieren (Kruftur)
static void frage_gegenstand(object pl, object ob) {
  string s;

  say(pl->Name(WER)+" fragt "+name(WEN,1)+" nach "+ob->name(WEM,1)+
      ".\n"+Name(WER,1)+" nickt.\n",pl);

  if(QueryProp(DAEM_FALSE)) {
    s = gegenstand_bloedsinn(ob);
  }
  else {
    s = query_information(ob);
  }
  tell_room(environment(),break_string("Ich habe folgende Information "
    "über "+ob->name(WEN,1)+" erhalten: "+s,0,Name(WER,1)+" sagt: "));
  zaehle_runter(pl);
}

// Den Körper des Beschwörers untersuchen (Tyoorthok)
static void frage_koerper(object pl) {
  string ret;

  if(QueryProp(DAEM_FALSE)) {
    ret = break_string(koerper_bloedsinn(pl,0));
  }
  else {
    ret = break_string(implode(({total_soak(pl,0),total_drink(pl,0),
          total_alc(pl,0),total_pois(pl,0),total_deaf(pl)})," "));
  }
  tell_object(pl,break_string(Name(WER,1)+" rückt eine Brille zurecht "
    "und spricht geheime Worte über deinem Haupt. Danach grübelt "+
    QueryPronoun(WER)+" einen Augenblick und murmelt:")+ret);
  say(pl->Name(WER)+" laesst sich von "+name(WEM,1)+" untersuchen.\n",pl);
  zaehle_runter(pl);
}

static string zu_niedrig(int stufe) {
  return "Dafür bist du noch nicht weit genug. Komm wieder, wenn du "
         "Gildenstufe "+stufe+" erreicht hast.";
}

// frage <name> nach <monster|gegenstand|pentagramm|mir>
int frage(string str) {
  string wer, was;
  object pl = PL, ob, *obs;
  int stufe;

  str = extern_call() ? pl->_unparsed_args() : str;

  if(!str || sscanf(lower_case(str),"%s nach %s",wer,was) != 2 ||
     !id(wer)) {
    return ::frage(str);
  }
  if(getuid(pl) != QueryProp(CHAOS_DAEM_BESCHWOERER)) {
    tell_object(pl,Name(WER,1)+" gibt dir einen Tritt in den Hintern.\n");
    tell_room(environment(),Name(WER,1)+" gibt "+pl->name(WEM)+
              " einen Tritt in den Hintern.\n",({pl}));
    pl->reduce_hit_points(3);
    return 1;
  }
  stufe = pl->QueryProp(P_GUILD_LEVEL);

  if(was == "mir" || was == "mich" || was == "mich selbst" ||
     was == lower_case(pl->name(RAW))) {
    if(stufe < STUFE_KOERPER) {
      sag(pl,zu_niedrig(STUFE_KOERPER));
    }
    else {
      frage_koerper(pl);
    }
    return 1;
  }
  if(id(was)) {
    sag(pl,"Netter Versuch! Ich bin zwar ein Dämon, aber nicht völlig "
        "verblödet!");
    return 1;
  }
  if(was == "pentagramm") {
    if(stufe < STUFE_GEGENSTAND) {
      sag(pl,zu_niedrig(STUFE_GEGENSTAND));
    }
    else {
      call_out("beurteilung",2);
      tell_room(environment(),Name(WER,1)+" grinst nickend.\n");
    }
    return 1;
  }
  // Lebewesen im Raum: einschätzen
  ob = present(was,environment());

  if(objectp(ob) && living(ob)) {
    if(stufe < STUFE_MONSTER) {
      sag(pl,zu_niedrig(STUFE_MONSTER));
    }
    else {
      frage_monster(pl,ob);
    }
    return 1;
  }
  // Gegenstand beim Spieler oder im Raum: identifizieren
  obs = pl->find_obs(was,PUT_GET_NONE) || ({});

  if(!sizeof(obs) && objectp(ob)) {
    obs = ({ob});
  }
  if(!sizeof(obs)) {
    sag(pl,capitalize(was)+" kann ich hier nicht finden.");
    return 1;
  }
  if(stufe < STUFE_GEGENSTAND) {
    sag(pl,zu_niedrig(STUFE_GEGENSTAND));
    return 1;
  }
  frage_gegenstand(pl,obs[0]);
  return 1;
}

// Gibt man ihm einen Gegenstand, identifiziert er ihn und gibt ihn
// zurück
void give_notify(object ob) {
  ::give_notify(ob);

  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER) ||
     PL->QueryProp(P_GUILD_LEVEL) < STUFE_GEGENSTAND) {
    write(Name(WER,1)+" sagt: Fuer dich mache ich gar nichts.\n");
  }
  else {
    frage_gegenstand(PL,ob);
  }
  if(present(ob,ME)) {
    if(ob->move(PL,M_GO) > 0) {
      write(Name(WER,1)+" gibt dir "+ob->name(WEN,1)+" zurueck.\n");
    }
    else {
      ob->move(environment(),M_NOCHECK);
      write(Name(WER,1)+" laesst "+ob->name(WEN,1)+" fallen.\n");
    }
  }
}
