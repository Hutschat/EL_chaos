// Der restliche Muell

#ifndef CHAOS___MISC
#define CHAOS___MISC

#define ZAR(x) if(find_player("zardoz"))\
  tell_object(find_player("zardoz"), x );

#define bs(x) break_string( x, 78)
#define BRS(x) break_string(x,77)
  
#define CHAOS_SPELL_FAILURE -3500
#define C_DONT_LEARN "dont_learn"
#define KROLKR_BRATRUU "krolkr_bratruu"

#define P_CHAOS_NO_FRIENDS "chaos_no_friends"
#define P_CHAOS_TEMP       "chaos_temp"

#define CHAOS_TRANK "\nchaos_trank"
#define CHAOS_TRANK_TRINKEN "_trinke_dummen_chaos_trank"

// Chaosmaske
  // Id jeder Dämonenmaske
#define CHAOS_MASKE_ID       "\nchaos_maske"
  // Der Shadow, der die Verwandlung macht
#define CHAOS_MASKE_SHADOW   (CHAOS_GILDEN_SHADOWS("mask_shadow"))
  // Verwandlung einer Maske, siehe shadows/mask_shadow.c
#define P_CHAOS_MASKE_DATEN  "chaos_maske_daten"
  // Liefert 1, solange ein Chaot verwandelt ist
#define P_CHAOS_MASKE        "chaos_maske"

#endif
