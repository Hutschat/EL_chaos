// namen.c - Die Daemonen der Chaosgilde haben keine festen Namen, diese
//           Werden per Random hierraus erzeugt.
//
// Letzte Aenderung:
//
// 16.08.2021 It@Efferdland            neu
// 27.11.2026 It@Efferdland            Tippfehler MALE

#include "def.h"

static mapping namen = ([
  "abaddon"       : MALE,
  "abigar"        : MALE,                      
  "abdiel"        : MALE,
  "achamoth"      : MALE,
  "acheron"       : MALE,
  "aeshma"        : MALE,
  "agash"         : MALE,
  "agrimoth"      : MALE,
  "aguares"       : MALE,
  "ahriman"       : MALE,
  "akatash"       : MALE,
  "alastor"       : MALE,
  "anthukt"       : MALE,
  "antrabir"      : MALE,
  "antrux"        : MALE,
  "ammit"         : MALE, 
  "amon"          : MALE,
  "anshaka"       : MALE,
  "andras"        : MALE,
  "ankou"         : MALE,
  "asag"          : MALE,
  "ssfaloth"      : MALE,
  "asmodeus"      : MALE,
  "asasel"        : MALE,
  "astaroth"      : MALE,
  "atarozh"       : MALE,
  "avnas"         : MALE,
  "ayanet"        : MALE,
  "baalphegor"    : MALE,
  "bael"          : MALE,
  "baka"          : MALE,
  "balan"         : MALE,
  "bana"          : MALE,
  "baobhan"       : MALE,
  "befana"        : MALE,
  "belhalhar"     : MALE,
  "belial"        : MALE,
  "belshirash"    : MALE,
  "beng"          : MALE,
  "berith"        : MALE,
  "botis"         : MALE,
  "buer"          : MALE,
  "buduh"         : MALE,
  "buiti"         : MALE,
  "byleth"        : MALE,
  "charon"        : MALE,
  "charun"        : MALE,
  "charus"        : MALE,
  "caym"          : MALE,
  "chith"         : MALE,
  "daath"         : MALE,
  "danavas"       : MALE,
  "dankal"        : MALE,
  "dyall"         : MALE,
  "dogai"         : FEMALE,
  "dre"           : FEMALE,
  "druij"         : FEMALE,
  "eskates"       : MALE,
  "finrik"        : MALE,
  "flaga"         : FEMALE,
  "furfur"        : MALE,
  "ganga"         : FEMALE,
  "garm"          : MALE,
  "gelal"         : MALE,
  "gor"           : MALE,
  "halpahs"       : MALE,
  "harkuhu"       : MALE,
  "indra"         : FEMALE,
  "inikris"       : MALE,
  "iribaar"       : MALE,
  "irkitis"       : MALE,
  "karuhu"        : FEMALE,
  "kaia"          : FEMALE,
  "kukuth"        : MALE,
  "legba"         : MALE,
  "lilith"        : FEMALE,
  "nagrach"       : MALE,
  "nakritis"      : MALE,
  "ortok"         : MALE,
  "tiamat"        : FEMALE,
  "tukz"          : MALE,
  "tumael"        : MALE,
  "xoluni"        : FEMALE,
]);

static mapping namen_tmp = copy(namen);

static mapping titel = ([
  DT_FIRE:   ({"ignis","ignas","ignal","ignur","ignasur"}),
  DT_ACID:   ({"asir","asus","asure","asar","asis"}),
  DT_LIGHT:  ({"lith","leth","lethot"}),
]);

public varargs mixed get_name(string type) {
  if(!sizeof(namen_tmp)){
    namen_tmp = copy(namen);
  }

  mixed tmp = m_indices(namen_tmp);
 
  tmp = tmp[random(sizeof(tmp))];

  namen_tmp -= ([tmp]);

  return tmp;
}
