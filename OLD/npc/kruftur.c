// kruftur.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet
           
#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

string query_bloedsinn(object ob);
string query_information(object mon);
static int use = 12;

int zaehle_runter(object pl)
{
   int glevel;

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
    return 1;
}                                                                                               

string query_bloedsinn(object ob)
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
  

  welche   = ({"irkitis","harkuhu","graiop","flaxtri","tutszt","yrintri"});
  faktoren = (["irkitis":0.5, "harkuhu":0.6, "graiop":0.7, "flaxtri":0.8, 
               "tutszt":0.9, "yrintri": 1.0]);
  
  for (i=sizeof(welche)-1;i>=0;i--)
    if (!PL->QuerySkill(welche[i]))
      welche-=({welche[i]});
  
  if (!sizeof(welche))
    return "";
  
  if (sizeof(welche)==1)
    return " Durch dieses Pentagramm wird "+capitalize(welche[0])+
       prozente(faktoren[welche[0]],pfaktor,bfaktor)+" werden.\n";
  
  str = " Durch dieses Pentagramm wird ";
  
  for (i=0;i<sizeof(welche);i++) 
  {
    str += capitalize(welche[i]) + 
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

  if(use<=0)
    wech(PL,4);

  return 1;
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(10,50);
  SetProp(P_SHORT,capitalize(CHAOS_ID_KRUFTUR)+" der Denkdaemon");
  SetProp(P_LONG,
  capitalize(CHAOS_ID_KRUFTUR)+" ist einer der ganz seltenen Denkdaemonen. Er "
  "ist in der Lage, Besonderheiten in Gegenstaenden oder an Monstern zu "
  "erkennen. Vielleicht hilft er Dir sogar.");
  SetProp(P_NAME,capitalize(CHAOS_ID_KRUFTUR));
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_ALIGN,-100);
  SetProp(P_HANDS,({" mit blossen Klauen",120,DT_RIP}));
  SetProp(P_BODY,60);
  SetProp(P_MMSGIN,"erscheint in einer Gedankenwolke");
  SetProp(P_SIZE,120);
  SetProp(P_WEIGHT,34000);
  SetProp(P_NOCORPSE,1);
  SetProp(P_DEFAULT_INFO, 
    "sagt: Keine Ahnung. Aber ich notiere mir die Frage.\n");
  SetProp(P_DIE_MSG," verschwindet als Inspirationspartikel.\n");
  AddId(({CHAOS_ID_KRUFTUR,CHAOS_ID_GILDENDAEMON}));
  AddCmd(({"befehle","befehl"}),"daemon_befehl");
}

void give_notify(object ob)
{
  string s;
  ::give_notify(ob);

  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER))
  {
    write(Name(WER)+" sagt: Fuer Dich mache ich gar nichts.\n"+
          Name(WER)+" laesst "+ob->name(WEN)+" fallen.\n");

    ob->move(environment(ME));

    return;
  }
  if(QueryProp(DAEM_FALSE))
    s = query_bloedsinn(ob);

  else
    s = query_information(ob);

  tell_room(environment(PL), 
            break_string("Ich habe folgende Information ueber "+
            ob->name(WEN,1)+" erhalten: "+s,0, Name(WER)+" sagt: "));

  if(present(ob,ME))
  {
    if(ob->move(PL,M_GO)>0)
      write(Name(WER)+" gibt Dir "+ob->name(WEN)+" zurueck.\n");

    else
    {
      ob->move(environment(ME));
      write(Name(WER)+" laesst "+ob->name(WEN)+" fallen.\n");
    }
  }
  zaehle_runter(PL);

  if(use<=0)
    wech(PL,5);

  return;
}

int daemon_befehl(string str)
{
  string ich, monster, abhauen;
  object mon;
  object *obs;
  string s;

  if(!str)
    return 0;

  if(::befehle_daemon(str))
    return 1;

  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER) &&
     !present(CHAOS_ID_KRUFTUR+"_"+getuid(PL),environment()))
  {
    tell_object(PL,Name(WER)+" gibt Dir einen Tritt in den Hintern.\n");
   
    tell_room(environment(ME),Name(WER)+" gibt "
             +PL->name(WEM)+" einen Tritt in den Hintern.\n",({PL}));

    PL->reduce_hit_points(3);
    return 1;
  }
  else
  {
    if(sscanf(str,"%s identifiziere %s",ich,monster) !=2 &&
       sscanf(str,"%s identifizier %s",ich,monster)  !=2)
      if(sscanf(str,"%s verschwinde",ich)!=1)
        return 0;

    if(sscanf(str,"%s verschwinde",ich)==1)
      abhauen = "verschwinde";

    if(ME != present(ich,environment()))
      return 0;

    if(abhauen)
    {
      if(abhauen=="verschwinde")
      {
        if(use==12)
        {
          tell_room(environment(ME),Name(WER)+" haut "+
                    PL->name(WEM)+" eine in die Fresse.\n",({PL}));

          tell_object(PL,Name(WER)+" haut Dir eine in die Fresse.\n");

          PL->reduce_hit_points(3);
          return 1;
        }
        tell_room(environment(ME),PL->name(WER)+" befiehlt "+
                  name(WEN,1)+", zu verschwinden.\n",({PL}));

        tell_object(PL,"Du befiehlst "+name(WEN)+", zu verschwinden.\n");
        
        wech(PL,5);
        
        return 1;
      }
      return 0;
    }
    else if(monster)
    {
      obs = PL->find_obs(monster,PUT_GET_NONE);
      
      if (!sizeof(obs))
      {
        tell_object(PL,"Der Daemon teilt Dir mit: "+capitalize(monster)+
                       " kann ich hier nicht finden.\n");
        return 1;
      }
      mon = obs[0];

      if(mon=present("\nchaos_gilden_pentagramm_"+getuid(PL), 
                     environment(ME)))
      {
        call_out("beurteilung",2);
        tell_room(environment(ME),Name(WER)+" grinst nickend.\n");
        return 1;
      }
      say(PL->Name(WER)+" sagt: "+Name(WER)+", identifiziere "
          +mon->name(WEN)+".\n"+"Der Daemon nickt.\n",PL);
 
      if(QueryProp(DAEM_FALSE))
        s = query_bloedsinn(mon);
      
      else 
        s = query_information(mon);
      
      tell_room(environment(ME),break_string("Ich habe folgende Information "
                "ueber "+mon->name(WEN)+" erhalten: "+s,0, 
                Name(WER)+" sagt: "));       
      
      if(present(mon,ME))
      {
        if(mon->move(PL,M_GO)>0)
          write(Name(WER)+" gibt Dir "+mon->name(WEN)+" zurueck.\n");

        else
        {
          mon->move(environment(ME));
        
          write(Name(WER)+" laesst "+mon->name(WEN)+" fallen.\n");
        }
      }
      zaehle_runter(PL);

      if(use<=0)
        wech(PL,5);

      return 1;
    }
    return 0;
  }
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
