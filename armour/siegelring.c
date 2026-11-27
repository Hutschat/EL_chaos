// siegelring.c
//
// Letzte Aenderung:
//
// 12.03.2019 It@Efferdland            ueberarbeitet

#include "def.h"

inherit "std/armour";

int killtime;

#define MONTHS\
([\
"Jan":"Januar","Feb":"Februar","Mar":"Maerz","Apr":"April","Mai":"Mai",\
"Jun":"Juni","Jul":"Juli","Aug":"August","Sep":"September","Okt":"Oktober",\
"Nov":"November","Dez":"Dezember"\
])

string det_gravur()
{
  string km,kj,kn;

  km = MONTHS[dtime(killtime)[9..11]];
  kj = dtime(killtime)[13..16];

  if (!environment() || !query_once_interactive(environment()))
    return "Du kannst die Gravur nicht entziffern.\n";

  kn = capitalize(getuid(environment()));

  return break_string("Im "+km+" des Jahres "+kj+" toetete "+kn+" das gesamte "
         "heilige Pack und bewies sich so in heroischer Weise als "+
         ((environment()->QueryProp(P_GENDER)==1)?"wahrer Chaot":"wahre Chaotin")+
         ".");
}

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT, "Der Siegelring der Chaosgilde");
  SetProp(P_LONG,
  "Dieser Ring besteht aus schwarzem Knochen. Ein grosser Totenkopf prangt "
  "auf ihm und eine Gravur ziehrt seine Innenseite. Dies ist der "
  "Siegelring der Chaosgilde, und nur die wuerdigsten aller Chaoten "
  "duerfen ihn tragen. Er zeigt, dass Du zu einer ausgesuchten, "
  "satanischen Elite gehoerst. Du kannst mit diesem Ring andere Leute "
  "schlagen.");
   
  SetProp(P_NAME, "Siegelring");
  SetProp(P_NAME_ADJ,"schwarz");
  AddId(({"siegelring","ring","totenkopfring","\nchaos_smmq_ring"}));
  SetProp(P_INFO,
  break_string("Dies ist der schwarze Siegelring der Chaosgilde."));
  SetProp(P_GENDER, MALE);
  SetProp(P_SIZE,2);
  SetProp(P_WEIGHT, 0);
  SetProp(P_BUY_VALUE, 3000);
  SetProp(P_AC,     0);
  SetProp(P_ARMOUR_TYPE, AT_MISC);
  SetProp(P_AUTOLOADOBJ,1);
  SetProp(P_NODROP,1);
  SetProp(P_NEVERDROP,1);
  SetProp(P_MATERIAL,MAT_BONE);

  AddDetail(({"knochen"}),
  "Der Ring besteht aus schwarzem Knochen.");

  AddDetail(({"gravur"}),
  "Sie ist sehr fein, doch Du kannst sie lesen.");

  AddDetail(({"innenseite"}),
  "Wow, dieser Ring hat sogar eine Innenseite!");

  AddDetail(({"chaoten"}),
  "Chaoten sind die besten.");

  AddDetail(({"elite"}),
  "Du gehoerst zu dieser Elite.");

  AddDetail(({"leute"}),
  "Mit diesem Ring kannst Du gut andere Leute schlagen.");

  AddReadDetail("gravur","@@det_gravur@@");

  AddCmd(({"schlag","schlage"}),"hit_him");
}

void _set_autoloadobj(mixed args)
{
   if (!intp(args)) return;

   killtime = args;
}

mixed _query_autoloadobj()
{
  return killtime;
}

void set_killtime(int b)
{
  killtime = b;
}

string extra_look()
{
  if (!QueryProp(P_WORN)) return "";

  return "Die Macht des Chaos ist stark in "
         +capitalize(getuid(environment()))+".\n";
}  

int hit_him(string wen)
{

  object opfer,hit;

  if (!QueryProp(P_WORN))
    return notify_fail("Dafuer solltest Du den Ring erst einmal "
                       "anziehen!\n"),0;

  notify_fail("Wen moechtest Du denn schlagen?\n");

  if (!wen) return 0;

  if (!(opfer=present(wen,environment(PL))))
    return 0;

  if(present_clone(CHAOS_GILDEN_OBJ("sieglabdruck"),opfer))
    return write("Ach, "+opfer->Name(WER,1)+" hat schon genug.\n"),1;

  if (opfer == PL)
    return write("Sowas ist keine Loesung!\n"),1;

  if (!living(opfer)) 
    return write("Sowas tut man nicht!\n"),1;

  write("Du rammst "+opfer->name(WEM,1)+" Deine beringte Faust in die "
        "Stirn.\n");

  say(PL->Name(WER,1)+" rammt "+opfer->Name(WEM)+" die Faust in die "
      "Stirn.\n",({PL,opfer}));

  tell_object(opfer,break_string(PL->Name(WER,1)+" rammt Dir die "
             "beringte Faust in die Stirn und hinterlaesst einen "
             "deutlichen Abdruck!"));

  clone_object(CHAOS_GILDEN_OBJ("sieglabdruck"))->move(opfer,M_SILENT);

  return 1;
}
