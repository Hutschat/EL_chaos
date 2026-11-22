//---------------------------------------------------------------------------//
//                   (c) 22/05/98 Tilly@mg.uni-muenster.de                   //
//---------------------------------------------------------------------------//
inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include "gilde.h"

#define BS break_string
int chat = 0;
object _me_ = this_object();

void create(){
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Dimension der Erzmeister");
  SetProp(P_INT_LONG,
    BS("Du befindest Dich in einer gigantisch grossen Halle. An der Wand "
    "vor Dir siehst Du ein hohes Portal. Die anderen Waende verlieren "
    "sich in der unendlichen Weite. Es scheint etwas Nebel aufgezogen "
    "zu sein, jedenfalls kannst Du immer schlechter erkennen wo Du Dich "
    "befindest. Der Boden faengt an unter Dir zu wanken, doch "
    "merkwuerdigerweise bewegen sich Waende und Decke nicht.",78));
  AddDetail(({"balken","eichenbalken"}),
   BS("Aeusserst massiv bilden sie das maechtige Portal und halten "
    "unerwuenschte Eindringlinge aus dieser Halle fern.",78));
  AddDetail(({"eindringling","eindringlinge"}),
   BS("Alle Nicht-Erzmeister eben.",78));  
  AddDetail(({"wand","waende"}),
    BS("Die Waende bestehen aus einem glatt-matt glaenzenden Material, "
    "das kein Licht zu reflektieren scheint. Als Du etwas genauer hinsiehst "
    "scheint es so, als ob Du hindurchblicken koenntest.",78));
  AddDetail(({"licht"}),
   BS("Hell ist es hier, zumindest hell genug um Dich etwas genauer "
    "umzusehen. Das Licht kommt wohl von den zahlreichen Blitzen, die "
    "bestaendig in dem Nebel zucken.",78));
  AddDetail(({"material"}),
   BS("Es ist kein Material, was sich so ohne weiteres einordnen laesst. "
    "Einerseits bildet es die Waende und andererseits kannst Du auch fast "
    "hindurchblicken. Sicher ist nur, dass es matt glaenzt.",78)); 
  AddDetail(({"decke"}),
    BS("Die Decke ist sehr hoch. Schemenhaft erkennst Du eine Gestalt, die "
    "sich dort zu bewegen scheint.",78));  
  AddDetail(({"boden","fussboden","glaeserner boden","glaeserner fussboden"}),
    BS("Du blickst nach unten und stellst erschrocken fest, das es gar "
    "keinen Boden gibt. Einen Augenblick lang hast Du das Gefuehl, jeden "
    "Moment in die bodenlose Tiefe zu fallen, doch dann spuerst Du, wie "
    "eine magische Kraft Dich zu halten scheint.",78));
  AddDetail(({"augenblick","augenblicke"}),
   BS("Er ist gluecklicherweise schon wieder vorbei.",78));
  AddDetail(({"kraft"}),
    BS("Sie kommt von irgendwo. Du bist froh, dass es sie gibt, denn sonst "
    "waerst Du schon tot!",78));
  AddDetail(({"tiefe","bodenlose tiefe"}),
    BS("Noch nie hast Du eine so verdammt tiefe Tiefe gesehen. Du bemerkst "
    "einen Hauch von Nebel, durch den ab und an elektrische Blitze zu "
    "zucken scheinen.",78));
  AddDetail(({"blitz","blitze","elektrischer blitz","elektrische blitze"}),
    BS("Du siehst Dir die Blitze etwas genauer an. Ploetzlich zuckt einer "
    "aus dem Nebel heraus, faehrt durch Dich hindurch, verirrt sich in Deinem "
    "Gehirn, sucht herum, findet nichts und ist auf einmal weg.",78));
  AddDetail(({"genaues","genaueres"}),
   BS("Nichts Genaues zu erkennen.",78));
  AddDetail(({"nichts genaues","nichts genaueres"}),
   BS("Schon besser, hilft Dir aber auch nicht weiter ... :-)",78)); 
  AddDetail(({"nebel"}),
    BS("Du kannst nichts Genaues erkennen. Aber es scheinen sich Lebewesen "
    "in diesem Nebel zu befinden. Du weisst nicht warum, aber irgendwie "
    "moechtest Du ihnen nicht begegnen.",78));
  AddDetail(({"gestalt"}),
    BS("Die Gestalt kommt langsam naeher. Dir rinnt kalter Schweiss den "
    "Ruecken hinunter als Du erkennst, dass es die Blonde Pest ist. "
    "Entsetzt wendest Du Deinen Blick wieder ab, bevor Du Gefahr laeufst, "
    "blind zu werden.",78));
  AddDetail(({"blick"}),
   BS("Gerade noch rechtzeitig konntest Du ihn wieder abwenden. Nicht "
    "auszudenken was haette passieren koennen!",78));  
  AddDetail(({"halle","saal","raum"}),
    BS("Du stehst mitten darin, und kommst Dir ziemlich einsam vor.",78));
  AddDetail(({"pest","blonde pest","blonde"}),
    BS("Die Blonde Pest schwebt schnell vorueber. Gerade noch kannst Du "
    "die Inschrift auf ihrem Gewand lesen : Sex macht blind und durstig! "
    "Du hoerst lautes Hicksen und siehst wie sie im Wegfliegen "
    "immerzu gegen die Waende knallt.",78));
  AddDetail(({"gewand"}),
   BS("Das Gewand ist nichtmehr allzu sauber und traegt folgende "
    "Inschrift: 'Sex macht blind und durstig!'.",78));
  AddDetail(({"hicksen"}),
   BS("Sowas siehst Du sicher nicht.",78));
  AddDetail(({"inschrift"}),
   BS("Die Inschrift scheint zumindest bei dieser Gestalt zuzutreffen.",78));
   
  AddSounds("\ndefault",
   "Ausser einem lauten <HICKS!> dann und wann ist es absolut still.\n");
  AddSounds(({"hicks","hicksen"}),
   BS("<HICKS!> <HICKS!> <HACKS!> ... die Gestalt scheint nicht ganz "
    "nuechtern zu sein.",78));  
   
  AddItem(CHAOS_GILDEN_OBJ("cl3_penterz"),REFRESH_REMOVE);

  AddSpecialDetail(({"wesen","lebewesen"}),"b_soffen");

  AddCmd(({"lies","les","lese"}),"inschrift");
  AddCmd(({"betrete","betret","betritt"}),"was");

  NewDoor("westen","/d/polar/files.chaos/feuerwehr/room/cl3bu11",
   ({"tuer","portal"}),
   ({D_NAME,"Portal",
     D_GENDER,0,
     D_SHORT,"Im Westen ragt ein grosses, %ses Portal auf.",
     D_FLAGS, DOOR_CLOSED | DOOR_RESET_CL,
     D_LONG,BS("Im Westen ragt das grosse, hoelzerne Portal auf. Es ist ein "+
      "sehr massives Portal und wurde aus massiven, dicken Eichenbalken "+
      "geschaffen.")}));
}

static int inschrift(string str){
 notify_fail("Was moechtest Du lesen?\n");
 if(!str) return 0;
 if(str=="inschrift"){
   write("'Sex macht blind und durstig!'\n");
   return 1;
  }
 return 0;
}
   
static int was(string str){
 notify_fail("Was moechtest Du betreten?\n");
 if(!str) return 0;
 if(str=="pentagramm"){
    write("Du betrittst das Pentagramm.\n");
    this_player()->move("/d/polar/files.chaos/swift/room/cl2tu1_4",
     M_GO|M_SILENT);
   return 1;
  }
 return 0;
}
   
static b_soffen(){
  if(find_call_out("d_sequence")==-1){
    AddCmd("","block",1);
    call_out("d_sequence",0);
  }
}

static block(string s){
  string str;
  str=query_verb();
  if (str=="bug") return 0;
  write ("Die Angst laehmt Dich!\n");
  return 1;
}

static d_sequence() {
  switch(chat) {
     case 0: tell_room(_me_,
       BS("Als Du anfaengst die Lebewesen zu betrachten, spuerst Du, wie die "
       "magische Kraft nachlaesst. Mit einem gellenden Schrei stuerzt Du in "
       "die Tiefe!!",78));
       break; 
     case 1:  tell_room(_me_,
       BS("Zu Deinem Glueck materialisiert sich in diesem Augenblick ein "
       "glaeserner Fussboden, der Dich auffaengt.",78));
        break;
     case 2:  tell_room(_me_, 
       BS("Du kannst nicht erkennen wie tief Du gefallen bist.",78));
       break;
     case 3: tell_room(_me_, 
       BS("Als Du wieder nach unten blickst, siehst Du keinen "
       "Boden mehr.",78));
       break;
     default:  tell_room(_me_, 
       BS("Alles ist so wie vorher, auch die Kraft ist wieder da und haelt "
       "Dich fest.",78));
       c_clear();
       return 1;
       break;
   }
   chat++;
   call_out("d_sequence",5);
 return 1;
}

static c_clear(){
  chat=0;
  RemoveCmd("","block");
  return 1;
}

