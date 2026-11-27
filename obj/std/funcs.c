// funcs.c
//
// Letzte Aenderung:
//
// 09.08.2019 It@Efferdland            neu
// 27.11.2026 It@Efferdland            Fehlendes return

#pragma no_clone

#include "def.h"

protected void create() {
}

string Funcs_DamText(string|string* dam_type, status plural) {

  if(stringp(dam_type)) // Chaosschaden
  {
    if(!dam_type || !stringp(dam_type)) {
      return "";
    }
    switch(dam_type){
      case DT_FIRE:
        if(plural) return "lodernde Flammenkugeln";
        return "eine lodernde Flammenkugel";
      case DT_AIR:
        if(plural) return "todbringende Stuerme";
        return "einen todbringenden Sturm";
      case DT_MAGIC:
        if(plural) return "magische Strahlen";
        return "einen magischen Strahl";
      case DT_WATER:
        if(plural) return "ueble Wasserstrahlen";
        return "einen ueblen Wasserstrahl";
      case DT_COLD:
        if(plural) return "frostige Eiswolken";
        return "eine frostige Eiswolke";
      case DT_ACID:
        if(plural) return "aetzende Saeureregen";
        return "einen aetzenden Saeureregen";
      case DT_LIGHTNING:
        if(plural) return "fuerchterliche Blitze";
        return "einen fuerchterlichen Blitz";
      case DT_BLUDGEON:
        if(plural) return "harte Felsbrocken";
        return "einen harten Felsbrocken";
      case DT_PIERCE:
        if(plural) return "eherne Pfeile";
        return "einen ehernen Pfeil";
      case DT_SLASH:
        if(plural) return "rotierende Messer";
        return "ein rotierendes Messer";
      case DT_POISON:
        if(plural) return "konzentrierte Gifte";
        return "konzentriertes Gift";
      case DT_SOUND:
        if(plural) return "schrille Kampfschreie";
        return "einen schrillen Kampfschrei";
      case DT_DARKNESS:
        if(plural) return "satanische Flueche";
        return "einen satanischen Fluch";
      case DT_TERROR:
        if(plural) return "hinterhaeltige Terrorattacken";
        return "eine hinterhaeltige Terrorattacke";
      case DT_WHIP:
        if(plural) return "wirbelnde Peitschenhiebe";
        return "einen wirbelnden Peitschenhieb";
      case DT_SQUEEZE:
        if(plural) return "Daumenschrauben";
        return "eine Daumenschraube";
      case DT_EXPLOSION:
        if(plural) return "explosive Magierschaedel";
        return "einen explosiven Magierschaedel";
      case DT_RIP:
        if(plural) return "gemeine Widerhaken";
        return "einen gemeinen Widerhaken";
    }
    if(plural) {
      return "unbekannte Angriffe";
    }
    return "einen Chaosball";
  }
  else if(pointerp(dam_type)) { // chaoskontrolle
    if(!dam_type) {
      return "";
    }
    string ret;
    
    switch(dam_type[0]){
      case DT_FIRE:
        if(plural) ret="brennende";
        else ret="einen brennenden";
        break;
      case DT_AIR:
        if(plural) ret="stuermische";
        else ret="einen stuermischen";
        break;
      case DT_MAGIC:
        if(plural) ret="magische";
        else ret="einen magischen";
        break;
      case DT_WATER:
        if(plural) ret="fluessige";
        else ret="einen fluessigen";
        break;
      case DT_COLD:
        if(plural) ret="eisige";
        else ret="einen eisigen";
        break;
      case DT_ACID:
        if(plural) ret="aetzende";
        else ret="einen aetzenden";
        break;
      case DT_LIGHTNING:
        if(plural) ret="blitzende";
        else ret="einen blitzenden";
        break;
      case DT_SOUND:
        if(plural) ret="schreiende";
        else ret="einen schreienden";
        break;
      case DT_DARKNESS:
        if(plural) ret="satanische";
        else ret="einen satanischen";
        break;
      case DT_TERROR:
        if(plural) ret="terror verbreitende";
        else ret="einen terrorverbreitenden";
        break;
      case DT_POISON:
        if(plural) ret="giftige";
        else ret="einen giftigen";
        break;
      default:
        if(plural) ret="unbekannte";
        else ret="einen unbekannten";
        break;
    }

    // Mechanische Schaeden

    switch(dam_type[1])
    {
      case DT_BLUDGEON:
        if(plural) ret+=" Felsbrocken";
        else ret+=" Felsbrocken";
        break;
      case DT_PIERCE:
        if(plural) ret+=" Pfeile";
        else ret+=" Pfeil";
        break;
      case DT_SLASH:
        if(plural) ret+=" Messerschnitte";
        else ret+=" Messerschnitt";
        break;
      case DT_RIP:
        if(plural) ret+=" Widerhaken";
        else ret+=" Widerhaken";
        break;
      case DT_WHIP:
        if(plural) ret+=" Peitschenhiebe";
        else ret+=" Peitschenhieb";
        break;
      case DT_EXPLOSION:
        if(plural) ret+=" Magierschaedel";
        else ret+=" Magierschaedel";
        break;
      case DT_SQUEEZE:
        if(plural) ret+=" Daumenschrauben";
        else ret+=" Daumenschrauber";
        break;
      default:
        if(plural) ret+=" Angriffe";
        else ret+=" Chaosball";
        break;
    }
    return ret;
  }
  return "";
}

varargs string|int Funcs_CheckRuestung(object caster) {
  if(!present_clone(CHAOS_GILDEN_ARMOUR("chaosruestung"),caster)) {
    return "Du musst fuer diesen Spruch eine Chaosruestung tragen!\n";
  }
  return 0;
}

public varargs int Funcs_GetKreisfaktor(object ob) {
  int faktor;

  if(ob) {
    faktor = ob->QueryProp(CHAOS_BANNKREIS_FAKTOR);

    if(ob->QueryProp(CHAOS_NEUES_PENTA)) {
      faktor += ob->QueryProp(CHAOS_BANNKREIS_RANDOM);
    }
  }
  return faktor;
}

public varargs int Funcs_GetPentagrammfaktor(object ob) {
  int faktor;

  if(ob) {
    faktor = ob->QueryProp(CHAOS_PENTAGRAMM_FAKTOR);
    
    if(ob->QueryProp(CHAOS_NEUES_PENTA)) {
      faktor += ob->QueryProp(CHAOS_PENTAGRAMM_RANDOM);
    }
  }
  return faktor;
}

public object Funcs_GetPentagramm(object caster) {
  return present(CHAOS_ID_PENTAGRAMM+"_"+getuid(caster),environment(caster));
}

public int Funcs_TestPentagramm(mapping daem,object caster,int pentaf,
                                int kreisf,int abil) {

  int align = caster->QueryProp(P_ALIGN);

  if(align>200) {
    align = 200;
  }
  align =- align/6;

  if(!pentaf) {
    pentaf =- daem[WRONG_DAEM];
  }
  if(!kreisf) {
    kreisf =- (daem[DAEM_DISAPPEAR]+daem[DAEM_AGGRESSIVE]+daem[DAEM_FALSE])/2;
  }
  if(pentaf/4+random(50+pentaf*5+abil/100+align) <= daem[WRONG_DAEM]) {
    return WD;
  }
  if(kreisf/4+random(50+kreisf*5+abil/100+align) <= daem[DAEM_AGGRESSIVE]) {
    return DA;
  }
  if(kreisf/4+random(50+kreisf*5+abil/100+align) <= daem[DAEM_DISAPPEAR]) {
    return DD;
  }
  if((kreisf+pentaf)/4+random(50+(pentaf+kreisf)*2+abil/100+align) <=
      daem[DAEM_FALSE]) {
    return DF;
  }
  return 0;
}

