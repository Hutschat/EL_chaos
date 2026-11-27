// balal.c - Balal laeuft umher und greift alle NPCs an, die keine Daemonen sind.
//
// Letzte Aenderung:
//
// 17.03.2019 It@Efferdland            neu

#pragma strong_types
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

inherit CHAOS_GILDEN_MON("std/std_daem");  

varargs void enter(status silent)
{
  call_out(function void() {
    object *en = filter(all_inventory(environment()),#'living);

    foreach(object tmp : en)
    {
      if(tmp->QueryProp(P_OBJECT_TYPE) == OT_NPC)
        if(!(tmp->is_class_member(CL_DEMON)))
          Kill(tmp);
    }
  },2);
  
  if(!silent)
    call_out(function void() {
      tell_room(environment(),Name(WER)+" nimmt die Spur seiner Beute auf!\n");
    },1);
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  create_default_npc(14,400);
  SetProp(P_SHORT, "Balal der baerenkoepfige Daemon" );
  SetProp(P_LONG,
  "Das ist Balal, der baerenkoepfige Daemon. Er ist staendig hungrig "
  "und verleibt sich alles Getier ein, das er habhaft werden kann! Sein "
  "Koerper ist pechschwarz und anstatt zweier Haender besitzt er nur lange, "
  "scharfe Krallen, die metallisch schimmern.");
  
  SetProp(P_NAME,"Balal");
  SetProp(P_GENDER,MALE);
  SetProp(P_ARTICLE,0);
  SetProp(P_ALIGN,-300);
  SetProp(P_MNPC_WALK,1);
  SetProp(P_MNPC_DELAY,5);
  SetProp(P_MNPC_RANDOM,5);
  SetProp(P_MNPC_ENTER,"enter");
  SetProp(P_HANDS,({" mit seinen Reisszaehnen",140,DT_RIP}));
  SetProp(P_BODY,80);
  SetProp(P_MSGIN,  "stuermt bruellend herein");
  SetProp(P_MSGOUT, "stuermt bruellend");
  SetProp(P_MMSGIN, "entsteigt mit einem grauenhaften Bruellen einer "
                    "Schwefelwolke");
  SetProp(P_NOCORPSE,1);
  SetProp(P_DIE_MSG," verlaesst diese Welt.\n");
  AddId(({"balal"}));
  RemoveId("\nkampfdaemon");
  call_out(#'enter,2,1);
}
