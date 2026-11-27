#include "../def.h"

inherit "/std/thing";

static object  shadow;
static mapping args;

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();

  SetProp(P_SHORT,"Eine feuerrote Maske");
  SetProp(P_LONG, 
  "Diese Maske gehoerte einst einem maechtigen und gefuerchteten "
  "Feuerdaemon von grosser Macht. Die daemonische Haut seines Gesichtes "
  "wurde abgehaeuted, in eine passende Maskenform gebracht und getrocknet. "
  "Die Maske ist deshalb feuerrot und stellt die gemeine Fratze des Daemons "
  "wieder.");

  SetProp(P_GENDER,FEMALE);
  SetProp(P_WEIGHT,1000);
  SetProp(P_SIZE,40);
  SetProp(P_NAME,"Daemonenmaske");
  AddId(({"maske"}));
  
  AddDetail(({"daemon","feuerdaemon"}),
  "Feuerdaemonen sind sehr unangenehme, boesartige Gestalten. Das Feuer, "
  "welches sie umgibt, ist heiss, doch der Hass in ihren Herzen ist noch "
  "viel heisser.");
  
  AddDetail(({"gestalten"}),
  "Du meinst wohl Feuerdaemonen...");
  
  AddDetail(({"hitze","feuer","glut"}),
  "Diese Maske ist gluecklicherweise kuehl und leblos...");
  
  AddDetail(({"hass"}),
  "Daemonen werden von unirdischem Hass am Leben erhalten. Sie verhalten "
  "sich nicht immer so, doch ihr Innerstes ist zerfressen und erfuellt "
  "davon.");
  
  AddDetail(({"innerstes"}),
  "Du solltest das schwarze Herz eines Daemons einmal sehen! Dies ist "
  "natuerlich rein bildlich gesprochen, den Daemonen haben kein Herz.");
  
  AddDetail(({"herz","daemonenherz"}),
  "Daemonen haben natuerlich kein Herz. Das war jetzt rein bildlich "
  "gesprochen.");
  
  AddDetail(({"macht"}),
  "Daemonen sind keineswegs alle gleich maechtig. Doch das wusstest fu "
  "sicherlich schon.");
  
  AddDetail(({"haut","daemonenhaut"}),
  "Die Maske besteht aus einer daemonischen Haut. Du findest es erstaunlich, "
  "dass Feuerdaemonen eine Haut haben. Sachen gibts...");
  
  AddDetail(({"sachen"}),
  "Sachen halt...");
  
  AddDetail(({"gesicht","fratze"}),
  "Also, puuh, diese Fratze ist wirklich, also, WIRKLICH haesslich.");
  
  AddDetail(({"maskenform","form"}),
  "Maskenform halt. Du weisst schon.");

  AddDetail(({"wissen"}),
  "Du weisst schon. Du WEISST schon...");

  AddDetail(({"farbe","rot","feuerrot"}),
  "Wow. Eine feuerrote Maske. Cool.");
  
  AddCmd("on","an");
  AddCmd("off","aus");
}

static int an(string str)
{
  shadow = clone_object(CHAOS_GILDEN_SHADOWS("mask_shadow"));
  
  if(objectp(shadow))
  {
    shadow -> on(PL,
    ([
      P_HANDS:   ({" mit feurigen Klauen",30,({DT_RIP,DT_FIRE}) }),
      P_MSGIN:   "schleicht feurig herein",
      P_MSGOUT:  "schlecht feurig",
      P_TITLE:   "der blutige Feuerdaemon",
      P_RACE:    "daemon",
      P_GENDER:  MALE,
      P_NAME:    "Feuerdaemon",
      P_CLASS:   ({CL_DEMON,CL_WALKING}),
      P_SHORT:   "@WER1, verwandelt in einen Feuerdaemon.",
      P_LONG:    "@WER1 hat rotgluehende Augen und ist von einer feurigen Aura "
                 "umgeben. @WENQPPFP1 Haut ist schwarz und @WENQPPFP1 "
                 "krallenbewaehrten Faenge zucken unkontrolliert. Schwarzes "
                 "Blut tritt an einigen Stellen aus @WESSEN2 Haut aus und "
                 "fliesst an der Haut herab.",
      P_LIGHT:   1,
      P_IDS:     PL->QueryProp(P_IDS),
      P_CHAOS_TEMP: "mask_feuer",
    ]));
  }
  return 1;
}

static int aus(string str)
{
  if(objectp(shadow))
  {
    shadow->off();
  
    if(shadow) destruct(shadow);
  }
  return 1;
}

