// mask_shadow.c - Shadow für die Chaosmasken
//
// Verwandelt einen Spieler für eine bestimmte Zeit in einen Dämon (oder
// bei einem missglückten Spruch in etwas ganz anderes). Gestartet wird
// er vom Spruch 'chaosmaske' im Spellbook:
//
//   sh = clone_object(CHAOS_MASKE_SHADOW);
//   sh->maske_an(spieler, daten, dauer, erfolg);
//
// daten ist ein Mapping mit diesen Schlüsseln (alle optional):
//
//   P_NAME    Name in der Verwandlung (z.B. "Feuerdämon"). Bei
//             schwachen Substantiven ein Array mit allen vier Fällen,
//             z.B. ({"Teddybär","Teddybären","Teddybären","Teddybären"})
//   P_GENDER  Geschlecht des Namens
//   P_RACE    Rasse in der Verwandlung
//   P_SHORT   Kurzbeschreibung, @WER1 usw. ist der Spieler
//   P_LONG    Langbeschreibung, @WER1 usw. ist der Spieler
//   P_MSGIN   Meldung beim Betreten eines Raums
//   P_MSGOUT  Meldung beim Verlassen eines Raums
//   P_HANDS   Hände ({text, wc, damage_types}), die WC wird mit dem
//             Erfolg des Spruchs auf 50 bis 100 Prozent gesetzt
//   P_IDS     zusätzliche Ids
//
// Die Verwandlung endet, wenn die Zeit um ist, wenn der Spieler stirbt
// oder wenn er die Maske abnimmt (armour/std/maske.c).
//
// Letzte Aenderung:
//
// 11.03.2019 It@Efferdland            neu
// 27.11.2026 It@Efferdland            überarbeitet, Dauer, Hände, Tod

#pragma strong_types
#pragma no_inherit
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit "/std/shadow";

static object  player;
static mapping daten;
static mixed  *haende;

public varargs string Name(int casus, int demon);
public int _query_gender();

public varargs void maske_aus(int silent) {
  if(objectp(player) && !silent) {
    tell_object(player,break_string(
      "Du spürst, wie die Kraft des Chaos aus dir weicht. Du bist "
      "wieder du selbst."));
    if(environment(player)) {
      tell_room(environment(player),break_string(
        Name(WER,1)+" verschwimmt vor deinen Augen. "
        "Plötzlich steht "+player->name(WER,1)+" vor dir."),({player}));
    }
  }
  while(remove_call_out("maske_aus") != -1);
  destruct_shadow();
}

public void maske_an(object pl, mapping map, int dauer, int erfolg) {
  int wc;

  if(!objectp(pl) || !mappingp(map) ||
     AddShadow(pl,NO_MULTI_SHADOW) != SHADOWING_OK) {
    destruct(ME);
    return;
  }
  player = pl;
  daten  = deep_copy(map);

  // Die WC der Hände hängt vom Erfolg ab: 50 bis 100 Prozent
  if(pointerp(daten[P_HANDS]) && sizeof(daten[P_HANDS]) >= 3) {
    erfolg = max(0,min(10000,erfolg));
    wc = daten[P_HANDS][1] * (50 + erfolg/200) / 100;
    haende = ({daten[P_HANDS][0],wc,daten[P_HANDS][2]});
  }
  (CHAOS_GILDEN_MASTER("shadow_master"))->RegisterShadow(ME);
  call_out("maske_aus",max(dauer,10));
}

// Die Gildendämonen erkennen damit einen verwandelten Chaoten
public int _query_chaos_maske() {
  return 1;
}

public string *_query_ids() {
  return (player->Query(P_IDS)||({})) + (daten[P_IDS]||({}));
}

public string _query_race() {
  return daten[P_RACE] || player->Query(P_RACE);
}

public int _query_gender() {
  return member(daten,P_GENDER) ? daten[P_GENDER]
                                : player->Query(P_GENDER);
}

// Artikel nach Geschlecht (NEUTER, MALE, FEMALE) und Fall
static string *artikel_best = ({
  "das ","des ","dem ","das ",
  "der ","des ","dem ","den ",
  "die ","der ","der ","die ",
});
static string *artikel_unbest = ({
  "ein ","eines ","einem ","ein ",
  "ein ","eines ","einem ","einen ",
  "eine ","einer ","einer ","eine ",
});

// P_NAME ist ein String oder ein Array mit den vier Fällen
public varargs string name(int casus, int demon) {
  mixed n = daten[P_NAME];
  string wort;
  int g;

  if(!n) {
    return player->name(casus,demon);
  }
  if(casus < WER || casus > WEN) {
    return pointerp(n) ? n[WER] : n;
  }
  g = _query_gender() % 3;

  if(pointerp(n)) {
    wort = n[casus];
  }
  else if(casus == WESSEN && g != FEMALE && n[<1] != 's') {
    wort = n+"s";
  }
  else {
    wort = n;
  }
  return (demon ? artikel_best : artikel_unbest)[g*4+casus] + wort;
}

public varargs string Name(int casus, int demon) {
  return capitalize(name(casus,demon)||"");
}

public string short() {
  if(!daten[P_SHORT]) {
    return player->short();
  }
  return CTSA(capitalize(replace_personal(daten[P_SHORT],({player}))))+
         ".\n";
}

public varargs string long() {
  if(!daten[P_LONG]) {
    return player->long();
  }
  return break_string(replace_personal(daten[P_LONG],({player}),1));
}

public string _query_presay() {
  return "";
}

public mixed _query_title() {
  return 0;
}

public string _query_msgin() {
  return daten[P_MSGIN] || player->Query(P_MSGIN);
}

public string _query_msgout() {
  return daten[P_MSGOUT] || player->Query(P_MSGOUT);
}

public mixed _query_hands() {
  // Nicht QueryProp(), das würde wieder hier landen
  return haende || player->Query(P_HANDS);
}

// Wer stirbt, verwandelt sich zurück
public varargs int second_life(object corpse) {
  int ret = player->second_life(corpse);

  maske_aus(1);
  return ret;
}
