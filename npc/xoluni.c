// xoluni.c
//
// Letzte Aenderung:
//
// 12.03.2019 It@Efferdland            ueberarbeitet
// 27.11.2026 It@Efferdland            init() für neuen Driver

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc( 2);
  SetProp(P_SHORT, "Ein winziges Licht" );
  SetProp(P_LONG,
  "Dieses kleine Licht fliegt staendig herum und bleibt nie an einer "
  "Stelle ruhig stehen. Es verbreitet dabei ein angenehmes Leuchten.");
  SetProp(P_NOFIRSTKILL,1);
  SetProp(P_NAME, "Irrlicht");
  SetProp(P_GENDER,0);
  SetProp(P_MAX_HP,1);
  SetProp(P_HP,1);
  SetProp(P_XP,0);
  SetProp(P_ALIGN, 10);
  SetProp(P_HANDS, ({" mit flammenden Flossen", 140 }));
  SetProp(P_BODY, 0);
  SetProp(P_FOLLOW_SILENT, 1);
  SetProp(P_MMSGIN,  "erscheint flackernd");
  SetProp(P_MMSGOUT, "loest sich auf");
  SetProp(P_MSGIN,   "erscheint flackernd");
  SetProp(P_MSGOUT,  "flackert");
  SetProp(P_DIE_MSG, " flackert ein letztes Mal auf.\n");
  SetProp(P_NOCORPSE, 1);
  SetProp(P_LIGHT, 1);
  SetProp(P_RACE, "Irrlicht");
  SetProp(P_CLASS,({CL_FREAK}));
  AddId(({"licht", "irrlicht", "\nchaos_irrlicht", "xoluni" }));
}

public varargs void init(object origin)
{
  ::init(origin);
  if(time() > QueryProp( CHAOS_DAEM_FOLLOW_TIME))
  {
    this_object()->die();
    return;
  }
  if(query_once_interactive(this_player()))
    return;

  if(this_player()->id( "\nchaos_irrlicht") && !random(10))
    call_out( "irrlicht_attack", 0, this_player());
}

void irrlicht_attack( object mon)
{	
  if(!mon) return;
    this_object()->Kill(mon);
}


