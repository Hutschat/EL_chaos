// chaosnpc.h - Fuer die Chaos-Daemonen
//
// Letzte Aenderung
//
// 11.03.2019 It@AnderLand             FOLGEN_VERBOTEN raus
// 27.11.2026 It@Efferdland            VERBOTENE_RAEUME raus

#ifndef CHAOS___NPC
#define CHAOS___NPC

// Die Räume, in denen keine Dämonen beschworen werden dürfen, verwaltet
// die Mudlib: GUILD_HELPER->GH_get_npc_forbidden_rooms()

// Return-Werte fuer den Daemonen-Check:

#define WD 1
#define DD 2
#define DA 3
#define DF 4

 // Fuer Daemonen-Ruestungen in obj/std_drue.c

#define DRUE_DEFEND_BONUS "drue_defend_bonus"
 // Bonus-Random-Wert fuer Defend

#define DRUE_WEAR_TXT     "drue_wear_txt"
 // Text fuer Spieler beim Versuch, die Ruestung anzusziehen
    
#define DAEM_MAY_SPEAK "daem_may_speak"
  /* Der Daemon darf das Sprechen erlernen
    (HP-Ausgaben an den Caster) */

#define DAEM_CAN_SPEAK "daem_can_speak"
  /* Der Daemon hat es gelernt, zu sprechen. */

#define DAEM_DONT_SPEAK "daem_dont_speak"
  /* Der Daemon bleibt still */
        
#define DAEM_PROZENT "chaos_daemon_prozent"
  /* Mit diesem Prozentwert wird der Daemon perfekt. */

#define P_DAEMON_QUALITY "_daemon_quality_"
  /* Prozentuale Guete des Daemonen */
 
#define KILL_ALL "kill_all" 
  // Wenn der Daemon wirklich sauer ist

#define CHAOS_DAEM_FOLLOW_TIME "chaos_daem_follow_time"
  /* Der Name sagt ja wohl alles :-) */


#define DAEM_FOLLOW "daem_follow"
  /* Ist 1, wenn der Daemon dem Caster folgen soll. */

#define CHAOS_DAEM_NO_DISAPPEAR "chaos_daem_no_disappear"
  /* Wenn der Daemon nach einem Reset nicht verschwinden soll */


#define CHAOS_AGG_DAEM_NO_DISAPPEAR "chaos:remove_me_while_reset"
  // Wenn Agg-Daemon im reset nicht verschwinden soll, auf
  // 0 setzen
  
#define AGG_CHANCE "agg_chance"
  /* Wert fuer die allgemeine Aggessivitaet */

#define DAEM_COUNT_DOWN "daem_count_down"
  /* Soll der Daemon nur eine bestimmte Anzahl von Attacken machen. */

#define DAEM_HUNTING_TIME "daem_hunting_time"
  /* Der Daemon verfolgt den Caster in random(wert) Sekunden. Diese
     Variable ist nur fuer unerwuenschte Daemonen! Die beschworenen
     Daemonen folgen per Pursuer. */

#define DAEM_AGGRESSIVE "daem_aggressive"
  /* Wahrscheinlichkeit fuer die Aggressivitaet des Daemonen gegenueber
     dem Caster */
    
#define DAEM_DISAPPEAR "daem_disappear"
  /* Wahrscheinlichkeit, dass der Daemon vorzeitig verschwindet */
      
#define DAEM_FALSE "daem_false"
  /* Wahrscheinlichkeit, dass der Daemon nicht das tut, was er soll,
     bzw. dass er eine falsche Information gibt */
          
#define WRONG_DAEM "wrong_daem"
  /* Wahrscheinlichkeit, dass bei der Beschwoerung ein anderer Daemon
     erscheint */
              
#define DAEM_FAKTOR_MAPPING "daem_faktor_mapping"
  /* Dieses mapping speichert die obigen vier Werte. Sie wird dem
     geclonten Daemonen zur weiteren Bearbeitung uebergeben. */
                  
#define CHAOS_DAEM_BESCHWOERER "chaos_daem_beschwoerer"
  /* UID des Beschwoerers */
                    
#define CHAOS_DAEM_BESCHWOERER_NAME "chaos_daem_beschwoerer_name"
  /* Name des Beschwoerers (fuer NPCs) */
                      
#define CHAOS_NPC_BESCHWOERER "chaos_npc_beschwoerer"
  /* War der Beschwoerer ein Chaos-Npc? Dann hilft Wuqour nicht */

#define DAEM_DEFEND_FAKTOR "daem_defend_faktor"
  /* Prozent der Schlaege, die der Daemon nicht abfaengt */

#endif
