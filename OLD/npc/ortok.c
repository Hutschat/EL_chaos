// ortok.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

static string query_bloedsinn(object pl, int mon)
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
        return pl->Name(WER,1)+" sollte sich erstmal etwas anstaendiges zum "
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
          
protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(15,120);
  SetProp(P_SHORT,"Tyoorthok der Weise");
  SetProp(P_LONG,
   "Dieser ergraute, baertige Daemon strahlt eine Weisheit aus, die man "
   "nur bei Wesen findet, denen irdische Belange nichts bedeuten. Bestimmt "
   "kannst auch Du aus dem grossen Schatz seiner Erfahrung profitieren."); 
  SetProp(P_NAME,"Tyoorthok");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_ALIGN,0);
  SetProp(P_HANDS,({" mit seinem langen, weissen Bart",160,DT_WHIP}));
  SetProp(P_BODY,40);
  SetProp(P_SIZE,90);
  SetProp(P_WEIGHT,15000);
  SetProp(P_MSGIN, "schlurft herein");
  SetProp(P_MSGOUT,"schlurft davon");
  SetProp(P_MMSGIN,"schlurft herein"); 
  SetProp(P_NOCORPSE,1);
  SetProp(P_DIE_MSG," grummelt in seinen Bart und verschwindet.\n");
  SetProp(P_REJECT,({REJECT_KEEP,"\n"}));
  AddId(({"tyoorthok","chaos_gilden_daemon","\ntyoorthok"}));
  AddCmd(({"befehle","befehl"}),"daemon_befehl");
}

static int daemon_befehl(string str)
{
  object mon;
  string ich,wem,s,mon_name,ret,rret;

  if(!str)
    return 0;

  if(::befehle_daemon(str))
    return 1;

  if(sscanf(str,"%s untersuch %s", ich,wem) != 2 &&
     sscanf(str,"%s untersuche %s",ich,wem) != 2) return 0;
  
  if(!id(ich)) 
    return 0;
  
  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER))
  {
    notify_fail(Name(WER)+" pfeift lieber kleinen, suessen Spielerinnen "
                "nach.\n");
    return 0;
  }
  if(wem == "mich" || wem == ME->QueryProp("chaos_daem_beschwoerer"))
  {
    if(QueryProp(DAEM_FALSE))
      s = query_bloedsinn(PL,0);

    ret = total_soak(PL,0)+
          total_drink(PL,0)+
          total_alc(PL,0)+
          total_pois(PL,0)+
          total_deaf(PL);
    
    tell_object(PL,break_string(Name(WER)+" rueckt seine Brille zurecht und "
                   "spricht geheime Worte ueber Deinem Haupte. Danach "
                   "gruebelt er einen Augenblick und murmelt:")+ret);
    
    say(PL->Name(WER)+" befiehlt "+name(WEM)+" eine Untersuchung.\n"+
        "Der Daemon laechelt milde und rueckt seine Brille zurecht.\n",PL);

    wech(PL,5);
  
    return 1;
  }
  else
  {
    if(PL->QueryProp(P_GUILD_LEVEL)>=7)
    {
      if(mon = present(wem,environment(PL)))
      {
        if(QueryProp(DAEM_FALSE))
        { 
          s = query_bloedsinn(PL,0);
          wech(PL,5);
         return 1; 
        }
        if(living(mon) && mon != PL)
        {
          ret=total_soak (mon,1)+
              total_drink(mon,1)+
              total_alc  (mon,1)+
              total_pois (mon,1);

          rret=total_soak (PL,0)+
               total_drink(PL,0)+
               total_alc  (PL,0)+
               total_pois (PL,0);    
        
          tell_object(PL,break_string("\n"+Name(WER)+" rueckt seine Brille "
                      "zurecht und spricht geheime Worte ueber "
                      +mon->name(WESSEN)+" Haupte. Danach gruebelt er einen "
                      "Augenblick und murmelt: ")+ret);
          
          tell_room(environment(ME),break_string("\n"+Name(WER)+" rueckt "
                    "seine Brille zurecht und spricht geheime Worte ueber "
                    +mon->name(WESSEN)+" Haupte."),({mon,PL}));

          tell_object(mon,break_string("\n"+Name(WER)+" rueckt seine Brille "
                      "zurecht und spricht geheime Worte ueber Deinem "
                      "Haupte. Danach gruebelt er einen Augenblick und "
                      "murmelt:")+rret);
          wech(PL,5);
          return 1;
        }
      }
    }
  }  
  return 0;
}    

void give_notify(object ob)
{
  ::give_notify(ob);

  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER))
  {
     tell_object(PL,break_string(Name(WER)+" steckt "+ob->name(WEN)+
                    " in seine Tasche und dreht Dir den Ruecken zu."));
     
     tell_room(environment(ME),Name(WER)+" wendet sich voller Ekel von "
               +PL->Name(WEN)+" ab.\n",({PL}));
     ob->remove(); 
     return;
  }   
  
  if(ob->QueryProp(P_BUY_VALUE) <= 420)
  {
     tell_object(PL,break_string(Name(WER)+" schaut Dich, mitleidig "
                 "laechelnd, an und laesst "+ob->name(WEN)+" fallen."));

     ob->move(environment(ME),M_NOCHECK);
  }
  else
  {
    tell_object(PL,break_string(Name(WER)+" nickt Dir unmerklich zu und "
                "laesst "+ob->name(WEN)+" in seiner Tasche verschwinden."));

    tell_room(environment(ME),Name(WER)+" nickt "+PL->Name(WEN)+" kaum "
              "merklich zu.\n",({PL}));

    ob->remove();

    call_out("remove_krankheiten",0);
  }
}

static void remove_krankheiten()
{
  int ok;
  
  foreach(object dis: all_inventory(PL))
  {
    if(dis->is_class_member(CL_DISEASE))
    {
      dis->remove();

      tell_object(PL,Name(WER)+" fasst Dir an die Schlaefen und drueckt "
                  "kurz aber schmerzhaft zu.");

      tell_room(environment(ME),Name(WER)+" fasst "+PL->name(WEM)+" an die "
                "Schlaefen und scheint einmal fest zuzudruecken.\n",({PL}));

      PL->reduce_hit_points(5+random(3));
      ok++;
    } 
  }    
  if(!ok)
    tell_object(PL,Name(WER)+" teilt Dir mit: Ich konnte keine Krankheiten "
                "bei Dir finden.\n");
}
 