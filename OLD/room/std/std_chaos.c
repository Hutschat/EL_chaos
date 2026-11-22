// std_chaos.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland             ueberarbeitet


#include "def.h"

inherit "/std/room";

protected void create()
{
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Irgendwo in der Chaosgilde");
  SetProp(P_INT_LONG,
  "Irgendwo in der Chaosgilde.");
  AddSpecialDetail(({"raum","ort","umgebung"}),"_query_int_long");
}
