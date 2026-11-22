// uebmatu.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet

#include "def.h"

inherit CHAOS_GILDEN_MON("std/aggdaem");  

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(1,30);
  SetProp(P_SHORT, "Der kleine Uebmatu" );
  SetProp(P_LONG,
  "Uebmatu ist ein kleiner Wasserdaemon, was ihn aber nicht daran hindert "
  "gemein und hinterhaeltig zu sein. Er ist fuer seine Groesse ziemlich "
  "frech und schreckt auch nicht vor groesseren Gegner zurueck.");

  SetProp(P_SIZE,120);
  SetProp(P_WEIGHT,100000);
  SetProp(P_NAME, "Uebmatu");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE, 0);
  SetProp(P_ALIGN, -10);
  SetProp(P_HANDS, ({" mit etwas Wasser", 30,DT_WATER }));
  SetProp(P_BODY, 30);
  SetProp(P_MMSGIN, "erscheint mit einem Platschen" );
  SetProp(P_MSGIN,  "erscheint mit einem Platschen" );
  SetProp(P_MSGOUT, "verschwindet in einem Schwall aus Wasser" );
  SetProp(P_DIE_MSG, " zerfliesst.\n");
  SetProp(P_NOCORPSE, 1);
  SetProp(AGG_CHANCE, 5);
  SetProp(P_MATERIAL,
  ([
    MAT_WATER: 80,
    MAT_MAGIC_BLACK:10,
    MAT_LIVING: 10,
  ]));
  SetProp(DAEM_HUNTING_TIME, 10);
  AddId(({"uebmatu", "wasserdaemon",}));
}
