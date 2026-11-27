// maske.c - Basis der Dämonenmasken
//
// Eine Dämonenmaske ist ein Helm. Trägt ein Chaot sie und spricht den
// Spruch 'chaosmaske', verwandelt er sich über den Masken-Shadow
// (shadows/mask_shadow.c) in den Dämon der Maske. Nimmt er die Maske
// ab, ist die Verwandlung vorbei.
//
// Die Verwandlung steht in P_CHAOS_MASKE_DATEN, Schlüssel wie beim
// Shadow beschrieben.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types

#include "../def.h"

inherit "/std/armour";

protected void create() {
  if(!clonep()) {
    set_next_reset(-1);
    return;
  }
  ::create();

  SetProp(P_ARMOUR_TYPE,AT_HELMET);
  SetProp(P_AC,2);
  SetProp(P_GENDER,FEMALE);
  SetProp(P_NAME,"Dämonenmaske");
  SetProp(P_WEIGHT,1000);
  SetProp(P_SIZE,40);
  SetProp(P_BUY_VALUE,500);
  SetProp(P_MATERIAL,([MAT_LEATHER:100]));

  AddId(({"maske","dämonenmaske",CHAOS_MASKE_ID}));
}

// Damit erkennt der Spruch 'chaosmaske' eine Dämonenmaske.
public int is_chaosmaske() {
  return 1;
}

// Wer die Maske abnimmt, verwandelt sich zurück.
protected void InformUnwear(object pl, int silent, int all) {
  object sh;

  ::InformUnwear(pl,silent,all);

  if(objectp(pl) && objectp(sh = pl->QueryShadow(CHAOS_MASKE_SHADOW))) {
    sh->maske_aus();
  }
}
