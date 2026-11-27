// daemon.c - Ein beschworener Dämon der Chaosgilde
//
// Der Dämon wird geclont und mit konfiguriere() auf seinen Typ
// eingestellt (Typtabelle in master/daemonen.c). Den Namen bekommt er
// aus master/namen.c. Der Orakeldämon hat eine eigene Datei
// (npc/orakel.c), die diese erbt.
//
// Besonderheiten der Typen:
//   feuerdaemon, saeuredaemon  verletzen jeden, der sie anfasst
//   lichtdaemon                kämpft gegen NPCs nicht mit (WC 0)
//   blutdaemon, wandler        sagen dem Beschwörer, wie es dem Gegner
//                              geht
//   wandler                    verwandelt seine Klauen auf Befehl und
//                              rettet dem Beschwörer das Leben
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu, ersetzt Irkitis, Harkuhu,
//                                     Graiop, Flaxtri, Tutszt und
//                                     Yrintri

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");

static string typ;
static object caster;

// Der Wandler kann seine Klauen verwandeln
#define WANDEL_SCHADEN ([\
  "feuer":  ({DT_FIRE,      "brennenden"}),\
  "eis":    ({DT_COLD,      "eisigen"}),\
  "sturm":  ({DT_AIR,       "stürmischen"}),\
  "magie":  ({DT_MAGIC,     "magischen"}),\
  "wasser": ({DT_WATER,     "wässrigen"}),\
  "blitz":  ({DT_LIGHTNING, "blitzenden"}),\
  "saeure": ({DT_ACID,      "säuretriefenden"}),\
  "gift":   ({DT_POISON,    "giftigen"}),\
  "boese":  ({DT_DARKNESS,  "unheiligen"}),\
  "terror": ({DT_TERROR,    "terrorverbreitenden"}),\
])

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_ARTICLE,0);
  SetProp(P_NOCORPSE,1);
  SetProp(P_REJECT,({REJECT_GIVE,"@WER1 sagt irgendetwas Daemonisches.\n"}));

  AddCmd(({"knuddel","knuddle","wuschel","wuschle","umarme","umarm",
           "wuerge","wuerg","streichel","streichle","kuesse","kuess"}),
         "anfassen");
  AddCmd(({"befehl","befehle"}),"befehle_wandel");
}

public string QueryTyp() {
  return typ;
}

// Stellt den Dämon auf seinen Typ ein. name und gender kommen aus
// master/namen.c, titel ist eines der Titelworte des Typs.
public void konfiguriere(string t, string name, int gender, string titel) {
  mapping d = CHAOS_DAEMONEN_MASTER->QueryTyp(t);
  string art, long;

  if(!mappingp(d)) {
    return;
  }
  typ = t;
  art = (gender == FEMALE) ? d[CD_NAME_W] : d[CD_NAME];

  create_default_npc(d[CD_NPC_LEVEL],d[CD_NPC_HP]);

  SetProp(CHAOS_DAEMON_TYP,t);
  SetProp(P_NAME,name);
  SetProp(P_GENDER,gender);
  SetProp(P_SHORT,name+" "+titel+", "+(gender == FEMALE ? "die " : "der ")
                  +d[CD_BEIWORT]+" "+art);
  long = regreplace(d[CD_LONG],"@NAME",name,1);
  long = regreplace(long,"@ART",(gender == FEMALE ? "eine " : "ein ")+art,1);
  SetProp(P_LONG,long);
  SetProp(P_ALIGN,d[CD_ALIGN]);
  SetProp(P_HANDS,d[CD_HANDS]);
  SetProp(P_BODY,d[CD_BODY]);
  SetProp(P_SIZE,d[CD_SIZE]);
  SetProp(P_WEIGHT,d[CD_WEIGHT]);

  if(d[CD_PROZENT]) {
    SetProp(DAEM_PROZENT,d[CD_PROZENT]);
  }
  if(d[CD_ATTRIBUTE]) {
    SetProp(P_ATTRIBUTES,d[CD_ATTRIBUTE]);
  }
  if(d[CD_LIGHT]) {
    SetProp(P_LIGHT,d[CD_LIGHT]);
  }
  if(d[CD_RESISTANCE]) {
    SetProp(P_RESISTANCE,d[CD_RESISTANCE]);
  }
  if(d[CD_MATERIAL]) {
    SetProp(P_MATERIAL,d[CD_MATERIAL]);
  }
  if(d[CD_MSGIN]) {
    SetProp(P_MSGIN,d[CD_MSGIN]);
    SetProp(P_MSGOUT,d[CD_MSGOUT]);
  }
  // Nicht SetProp(): _set_mmsgin() der Mudlib setzt P_MSGIN
  Set(P_MMSGIN,CTSA(d[CD_MMSGIN]),F_VALUE);
  SetProp(P_DIE_MSG,d[CD_DIE_MSG]);

  if(typ == "blutdaemon") {
    SetProp(P_NOCORPSE,0);
    SetProp(P_CORPSE,CHAOS_GILDEN_OBJ("blutfleck"));
  }
  if(typ == "lichtdaemon") {
    // Gegen NPCs kämpft der Lichtdämon nicht mit, siehe Attack()
    SetProp(P_HANDS,({d[CD_HANDS][0],-200,d[CD_HANDS][2]}));
  }
  AddId(({lower_case(name),lower_case(titel)})+(d[CD_IDS]||({})));

  if(d[CD_KAMPF]) {
    AddId(CHAOS_ID_KAMPFDAEMON);
  }
}

// Wie geht es dem Gegner? Für Blutdämon und Wandler
static void melde_gegner(object enemy) {
  int hp, maxhp;
  string msg;

  hp    = enemy->QueryProp(P_HP);
  maxhp = max(enemy->QueryProp(P_MAX_HP),1);

  if(hp < maxhp/10) {
    msg = " steht auf der Schwelle zu einer besseren Welt.";
  }
  else if(hp < maxhp/5) {
    msg = " braucht den berühmten Arzt.";
  }
  else if(hp < maxhp*3/10) {
    msg = " hat's mit der Verfassung.";
  }
  else if(hp < maxhp*4/10) {
    msg = " wankt und schwankt. Sieht gut für uns aus :-)";
  }
  else if(hp < maxhp/2) {
    msg = " sieht zum Mitnehmen aus.";
  }
  else if(hp < maxhp*6/10) {
    msg = " ist nicht mehr frisch. Und wie Tau schon gar nicht!";
  }
  else if(hp < maxhp*7/10) {
    msg = " hat schon einige Kratzer abbekommen.";
  }
  else if(hp < maxhp*8/10) {
    msg = " fühlte sich auch schon schlechter.";
  }
  else if(hp < maxhp*9/10) {
    msg = " ist ganz, ganz leicht angeschwächt.";
  }
  else {
    msg = " ist absolut fit. Was immer das heissen mag...";
  }
  tell_object(caster,break_string(enemy->Name(WER,1)+msg,0,
              Name(WER,1)+" teilt dir mit: "));
}

void Attack(object enemy) {
  mixed *hands;

  if(typ == "lichtdaemon" && objectp(enemy)) {
    hands = QueryProp(P_HANDS);

    if(interactive(enemy) && hands[1] < 0) {
      SetProp(P_HANDS,({hands[0],140,hands[2]}));
    }
  }
  if(typ == "blutdaemon" || typ == "wandler") {
    if(!caster && !random(5)) {
      caster = find_player(QueryProp(CHAOS_DAEM_BESCHWOERER));
    }
    if(objectp(caster) && interactive(caster) && objectp(enemy) &&
       enemy != caster && !QueryProp(DAEM_FALSE) &&
       !QueryProp(DAEM_AGGRESSIVE) && !QueryProp(KILL_ALL) &&
       !QueryProp(DAEM_DONT_SPEAK) && !random(3)) {
      melde_gegner(enemy);
    }
  }
  ::Attack(enemy);
}

// Feuer- und Säuredämonen fasst man besser nicht an
static int anfassen(string str) {
  if(!str || (!id(str) && str != "alle")) {
    return 0;
  }
  if(typ == "feuerdaemon") {
    write(break_string("Du berührst "+name(WEN,1)+". Plötzlich spürst "
      "du einen brennenden Schmerz auf der Haut! "+Name(WER,1)+
      " verbrennt dich!"));
    say(break_string(PL->Name(WER)+" war so bescheuert, "+name(WEN,1)+
      " zu berühren! Dieser Fehler wird mit drei Punkten auf der nach "
      "oben offenen Dummkopf-Skala vermerkt und mit irrsinnigen "
      "Schmerzen bestraft!"),({PL}));
  }
  else if(typ == "saeuredaemon") {
    if(present("schleim",PL)) {
      return 0;
    }
    write(break_string("Du berührst "+name(WEN,1)+". Plötzlich spürst "
      "du einen brennenden Schmerz auf der Haut! "+Name(WER,1)+
      " verätzt dich sehr stark!"));
    say(break_string(PL->Name(WER)+" war so wahnsinnig, "+name(WEN,1)+
      " zu knuddeln! Dieser Fehler wird mit Lebensentzug bestraft!"),
      ({PL}));
  }
  else {
    return 0;
  }
  PL->reduce_hit_points(10+random(20));
  return 1;
}

// Der Wandler: 'befehle <name> verwandle dich in <art>'
static int befehle_wandel(string str) {
  string ich, art;
  mapping schaden = WANDEL_SCHADEN;

  if(typ != "wandler" || !str) {
    return 0;
  }
  if(sscanf(str,"%s verwandlung dich in %s",ich,art) != 2 &&
     sscanf(str,"%s verwandel dich in %s",ich,art) != 2 &&
     sscanf(str,"%s verwandle dich in %s",ich,art) != 2) {
    return 0;
  }
  if(!id(ich)) {
    return 0;
  }
  if(getuid(PL) != QueryProp(CHAOS_DAEM_BESCHWOERER)) {
    write(Name(WER,1)+" sagt: Du hast mir gar nix zu sagen!\n");
    return 1;
  }
  if(QueryProp(KILL_ALL) || QueryProp(DAEM_AGGRESSIVE)) {
    write(Name(WER,1)+" gehorcht dir nicht.\n");
    return 1;
  }
  if(IsEnemy(PL)) {
    write(Name(WER,1)+" lacht ueber dich!\n");
    return 1;
  }
  if(!member(schaden,art)) {
    write(break_string(Name(WER,1)+" kennt nur: "+
      array_to_string(sort_array(m_indices(schaden),#'>))+"."));
    return 1;
  }
  SetProp(P_HANDS,({" mit "+schaden[art][1]+" Klauen",
                    QueryProp(P_HANDS)[1],({schaden[art][0]})}));
  write(Name(WER,1)+" verwandelt "+(QueryProp(P_GENDER) == FEMALE ?
        "ihre" : "seine")+" Klauen.\n");
  return 1;
}

// Der Wandler wirft sich vor tödliche Angriffe auf den Beschwörer
public <int|string*|mapping>* DefendOther(int dam,
    string|string* dam_type, int|mapping spell, object enemy,
    object friend) {
  object c;

  if(typ != "wandler" ||
     !(c = find_player(QueryProp(CHAOS_DAEM_BESCHWOERER))) ||
     QueryProp(KILL_ALL) || QueryProp(DAEM_AGGRESSIVE) ||
     QueryProp(DAEM_FALSE)) {
    return ({dam,dam_type,spell});
  }
  if(c->QueryProp(P_HP) < dam/10) {
    tell_object(c,break_string(Name(WER,1)+" wirft sich vor den "
      "tödlichen Angriff und fängt ihn ab."));
    say(Name(WER,1)+" rettet "+c->name(WEM,1)+" das Leben!\n",c);
    wech(QueryProp(CHAOS_DAEM_BESCHWOERER),5);
    return ({0,dam_type,spell});
  }
  return ({dam,dam_type,spell});
}
