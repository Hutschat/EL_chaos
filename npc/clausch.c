// clausch.c
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz
// 17.05.1998 Bierchen@MorgenGrauen    ueberarbeitet
// 10.12.2018 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            Tippfehler P_NO_ATTACK

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_chaot");

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(4,120);
  SetProp(P_SHORT, "Ein unfairer Schiedsrichter" );
  SetProp(P_LONG,
  "Dies ist der Schiedsrichter der Kampfarena der Chaosgilde. Er ist "
  "befangen und parteiisch. Beschwerden ignoriert er schon aus Prinzip. "
  "Ausserdem hat er immer unrecht und steht staendig im Weg.");
  SetProp(P_SIZE,200);
  SetProp(P_WEIGHT,130000);
  SetProp(P_ALIGN,-30);
  AddClass(({
    CL_HAIR,
    CL_SKIN,
    CL_WALKING,
    CL_HUMAN,
    CL_BREATH_AIR
  }));
  SetProp(P_RACE,CL_HUMAN);
  SetProp(P_NAME_ADJ,"unfair");
  SetProp(P_NAME, "Schiedsrichter");
  SetProp(P_NO_ATTACK, " sagt: Sooo unfair bin ich auch wieder nicht!\n");
  SetProp(P_GENDER,MALE);
  AddId(({"schiedsrichter","mann","richter","unfairer schiedsrichter",
  	  "unfairen schiedsrichter" }));
}

void catch_tell(string str)
{
  ::catch_tell(str);
  
  catch(call_other(CHAOS_GILDEN_ROOM("ctrib"),"???");publish);
  
  object room;
  
  if(room = find_object(CHAOS_GILDEN_ROOM("ctrib")))
    foreach(object pl:filter(all_inventory(room),#'interactive))
      if(pl->QueryProp("kampf_zuschauen"))
        tell_object(pl,str);
}
