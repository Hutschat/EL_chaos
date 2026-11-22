// arena.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                    neu
// 17.05.1998 Bierchen@MorgenGrauen     ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet
// 06.03.2020 It@Efferdland             Debung

#include "def.h"

inherit CHAOS_GILDEN_ROOM("std/std_chaos");

static void  check_feige(object spieler);

static string *arena_rooms = ({"nw","so","sw","no"});

static object *get_targets(string *where) {
  object *tg = ({});
  string room;
  
  if(!pointerp(where)) {
    return tg;
  }
  foreach(room:arena_rooms) {
    call_other(CHAOS_GILDEN_ARENA(room),"???",0);
    
    if(member(where,room) != -1) {
      tg += map(filter(all_inventory(find_object(CHAOS_GILDEN_ARENA(room))),
                  #'interactive ), #'getuid);
    }
  }
  return tg;
}

static void room_damage(int val) {
  object ob;
  
  foreach(ob:filter(all_inventory(),#'living)) {
    ob->reduce_hit_point(val);
  }
}

static string arena() {
  mixed tg;
  mixed rooms   = QueryProp(P_EXITS);
  string ret    = "",act;
  string *index = sort_array(m_indices(rooms),#'>);

  foreach(act:index) {
    if(rooms[act][1]) {
      call_other(rooms[act][1],"???",0);
      tg = map(filter(all_inventory(find_object(rooms[act][1])),
           #'interactive ), #'getuid);
      
      ret += sprintf("%-25s %s\n","Im "+capitalize(act)+" siehst Du:",
                             (sizeof(tg)?array2string(tg):"Niemand"));
    }
  }
/*
  foreach(act:arena_rooms) {
     call_other(CHAOS_GILDEN_ARENA(act),"???",0);
     target = map( filter(all_inventory(find_object(CHAOS_GILDEN_ARENA(act))),
           #'interactive ), #'getuid);
      
     ret += sprintf("%-25s %s\n","Im "+capitalize(act)+" siehst Du:",
                             (sizeof(target)?array2string(target):"Niemand"));
  }
*/
  return ret+"\n";
}

protected void create() {
  ::create();
  SetProp(P_NOMAP,"Das Chaos hier ist nicht kartierbar!\n"); 
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_KILL_NAME,"Das Chaos");
  SetProp(P_INT_SHORT,"In der Duellarena");
  AddSpecialDetail(({"duellarena","arena","kampfplatz","chaosarena"}),
  "arena");
  
  Set(P_INT_LONG_EXT,#'arena,F_QUERY_METHOD);
  AddDetail("blut",
  "Du hast in Deinem Leben schon viel Blut gesehen (und es war sicherlich "
  "groesstenteils das Blut Deiner Gegner), aber was Du hier siehst, "
  "uebertrifft wirklich Deine schlimmsten Phantasien.");
            
  AddDetail("decke",
  "Es gibt keine Decke, da die Arena nach oben hin offen ist. Dafuer "
  "darfst Du Dir aber den unheimlichen, duesteren Himmel der Schattenwelt "
  "anschauen.");

  AddDetail("himmel",
  "Dies ist der Himmel der immerwaehrenden Duesternis, dem die "
  "Duesterkatakomben auch ihren Namen verdanken. Ueber diesen Himmel zieht "
  "fuer gewoehnlich der blasse, schmutzig-weisse Mond.");

  AddDetail( "mond",
  "Diese Duellarena sollte urspruenglich in den Duesterkatakomben stehen, "
  "da aber diese eh noch ewig auf sich warten lassen, hat Zardoz diese "
  "Raeume durchs halbe EL getragen und hier aufgebaut. Deshalb gibt es "
  "auch keinen Mond.");

  AddCmd("","command_check",1 );
}


void weg_mit_dem_spieler(object player) {
  if(!objectp(player)) {
    return;
  }
  player->move(CHAOS_GILDEN_ROOM("vc/stop+"+getuid(player)),M_GO|M_NO_SHOW);
}
     
int command_check(string str) {           
  string v;

  v = query_verb();

  if(v == "ende" || v == "quit") {
    TRIB( "Wieso macht "+PL->name(WER)+" eigentlich 'ende'? "+
      "Naja, jedenfalls war dies das Ende des Kampfes fuer "+
      PL->QueryPronoun(WEN) );
    
    weg_mit_dem_spieler(PL);
    check_feige(PL);

    CHAOS_GILDENMASTER->LoescheKaempfer(PL);

    return 1;
  }
  if((v == "schlaf" || v == "schlafe" ) && str == "ein") {                                                   
    write( "Einschlafen ist wie Aufgeben!\n");     

    TRIB(PL->Name(WER)+" zieht es vor, einfach in der Duellarena "
         "einzuschlafen. Tja, das wars dann wohl." );

    check_feige(PL);
    
    CHAOS_GILDENMASTER->LoescheKaempfer(PL);
    
    PL->StopHuntingMode();
    
    weg_mit_dem_spieler(PL);
    
    return 1;
  }
  return 0;
}
                                                         
void BecomesNetDead(object player) {                                                                   
  TRIB(player->Name(WER)+" ist leider netztot und damit aus "+
    "raus aus dem Kampf um den Erzmeistertitel." );

  player->StopHuntingMode();

  weg_mit_dem_spieler(player);

  CHAOS_GILDENMASTER->LoescheKaempfer(player);
}


void NotifyPlayerDeath(object player,object killer,int le) {
  TRIB(player->Name(WER)+" ist leider von uns gegangen. :)" );

  CHAOS_GILDENMASTER->LoescheKaempfer(player);
}


void aufraeumen() {
  map_objects(all_inventory(),"move",CHAOS_GILDEN_ROOM("ctrib"),
                                     M_GO|M_NO_SHOW);
}

static void check_feige(object spieler) {
  if(spieler->QueryProp(P_HP) > (spieler->QueryProp(P_MAX_HP)*3)/4) {
    if(interactive(spieler)) {
      tell_object(spieler,"Kruuolq erscheint.\n"+
                 break_string("Du, "+spieler->Name(WER)+", warst "
                 "FEIGE! Ich verurteile Dich wegen Feigheit in einer "
                 "Schlacht! Du wirst nun STERBEN.",0,
                 "Kruuolq sagt: "));

      call_out("let_him_die",4,spieler);
    }
  }
}

int let_him_die(object ob) {
  if (objectp(ob) && interactive(ob)) {
     SetProp(P_KILL_NAME,"Kruuolq");
//     SetProp(P_KILL_MSG,({"sagen: Wir verurteilen Dich wegen Feigheit im Kampf.",
//      MSG_EMOTE,PLURAL}));
     ob->die();
     return 1;
  }
}

varargs void exit() {
  ::exit();
  // Daemonen befrieden... keine gute Loesung aber ok.
  if(!interactive(PL)) {
    PL->StopHuntingMode();
  }
}
