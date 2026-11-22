#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS(x) break_string(x,78)

inherit  CHAOS_GILDEN_ROOM("cl2w_std");

int zustand;



create() {
  ::create();
  
  zustand = 100;  // 100 %
  
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Auf einer gefaehrlichen Haengebruecke");
  SetProp(P_INT_LONG,
  BS("Du befindest Dich auf einer Haengebruecke. Noerdlich befindet "+
  "sich die schwarze Burg, suedlich von Dir ein eisiger Huegel. "+
  "Unter Dir schwankt und wankt ein gruener See. Der Wind weht durch "+
  "deine Haare, waerend Du Dich geschockt irgendwo festhalten willst. "+
  "Im Suedosten hat jemand ein Wachhaeuschen hingebaut."));
  AddDetail(({"boden"}),BS("Kein Boden, sorry. Nur eine Haengebruecke."));
  AddDetail(({"wand","waende"}),BS("Hier gibt es auch keine Waende."));
  AddDetail(({"decke"}),BS("Die Decke befindet sich weit ueber Dir und "+
  "ist nur als leicht leuchtende Flaeche erkennbar."));
  AddDetail(({"leuchten"}),BS("Es leuchtet nur schwach von oben herab.\n"));
  AddDetail(({"flaeche"}),BS("Merkwuerdige Decke. Aber dies ist auch eine "+
  "merkwuerdige Hoehle."));
  AddDetail(({"hoehle"}),BS("Du befindest Dich in einer gigantischen "+
  "Hoehle in einem riesigen schwarzen Eisberg."));
  AddDetail(({"eisberg"}),BS("Dies ist wirklich ein Eisberg! Mannomann!"));
  AddDetail(({"eis"}),BS("Eis ist ueberall um Dich herum."));
  AddSpecialDetail(({"bruecke","haengebruecke"}),"det_bruecke");
  AddSpecialDetail(({"zustand"}),"query_zustand_string");
  AddDetail(({"see"}),BS("Wow, dieser gruene See stinkt ja entsetzlich! "+
  "Da willst Du wirklich nicht reinfallen, nein nein."));
  AddDetail(({"wind"}),BS("Er laesst die Bruecke schaukeln, wie unangenehm."));
  AddDetail(({"haare"}),BS("Viele sind es ja nicht mehr. tststss."));
  AddDetail(({"wachhaeusschen"}),BS("Es ist wohl eher ein Unterstand, gez"+
  "immert aus schwarzen Brettern. Du kannst ihn betreten, wenn Du nach "+
  "Suedosten gehst."));
  AddDetail(({"unterstand"}),BS("Im Suedosten kannst Du den Unterstand "+
  "betreten."));
  AddDetail(({"bretter"}),BS("Sie scheinen von den Baeumen dieser Hoehle "+
  "zu stammen. Nichtsdestotrotz sind sie jedoch einigermassen gerade."));
  AddSpecialDetail(({"burg"}),"det_burg");
  AddDetail(({"tuerme"}),BS("Es sind vier grosse, schwarze Tuerme. Sie int"+
  "eressieren Dich jedoch nicht allzusehr, wenn Du jetzt so auf dieser "+
  "windigen Haengebruecke hockst."));
  AddDetail(({"steine"}),BS("Die Burg wurde mit grossen, schwarzen Steinen "+
  "gebaut."));
  AddSpecialDetail(({"portal"}),"det_portal");
  AddDetail(({"seile","halteseile"}),BS("Du siehst zwei gewaltige Halteseile"+
  ", von denen jede Menge kleinerer Halteseile herabhaengen und die Holz"+
  "bohlen halten, auf welchen Du gerade hockst, halten. Hmmm. Wenn jemand "+
  "die Halteseile kappen wuerde ... Diese Bruecke wuerde in den See "+
  "stuerzen. Hehe. HEHEHEHEHEEHEEE. Hehe."));
  AddDetail(({"fuehrungsseile","fuehrungsseil"}),
  BS("Die Fuehrungsseile sehen wirklich duenn aus. Wenn "+
  "man die Halteseile kappen wuerde, wuerden diese hier garantiert nicht "+
  "mehr halten."));
  AddDetail(({"bohlen","holzbohlen"}),BS("Sie knarren und knacken."));
  AddDetail(({"menge"}),BS("JEDE Menge!"));
  AddDetail(({"jemand"}),BS("Jemand zueckt eine Axt und grinst haemisch."));
  AddDetail(({"gestank"}),BS("BAEH!"));
  
  AddSmells(SENSE_DEFAULT,BS("Es stinkt fuerchterlich nach Saeure."));
  AddSmells(({"saeure"}),BS("Baeh, die stinkt wirklich erbaermlich."));
  
  AddSounds(SENSE_DEFAULT,BS("Tropf Troph Huuuuuuh Huuuuuuh."));
  
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2w8"));
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl2br3"));
  AddExit("norden",CHAOS_GILDEN_ROOM("cl2br2"));
  
  AddCmd(({"kapp","kappe"}),"kappen");
  AddCmd(({"springe","spring"}),"springe");
  SetProp(P_KILL_NAME,"Eine zusammenbrechende Bruecke");
  
  AddItem(CHAOS_GILDEN_MON("cl2_chaot2"),REFRESH_DESTRUCT,
          (["chaos_guard":"norden",
            "chaos_guard_money":400+random(100),
            "chaos_guard_msg":"Der Chaot sagt: Also neh neh neh. "+
                       "Dich als Nicht-Chaoten lass ich aber so\n"+
                "Der Chaot sagt: nicht hier durch. Du zahlst mir "+
                "erst mal %d Muenzen.\n"]));
  AddItem(CHAOS_GILDEN_MON("cl2_dwaechter1"),REFRESH_DESTRUCT,
         (["chaos_guard":"norden",
           "chaos_guard_money":500+random(100),
            "chaos_guard_msg":"Der Daemon bruellt: Armttr Ambu Gmurs! "+
                              "Yque Kaspartar! Yque Kroeter!\n"+
                              "Der Daemon roehrt und bruellt: Xorchm "+
                              "%d Muenzen! Krozx!\n"]));
}

int fakekill(string str1, string str2,object opfer)
{
    object ob;
    SetProp(P_KILL_NAME,str1);
    SetProp(P_KILL_MSG,str2);
    opfer->SetProp(P_GHOST,1);
    ob = clone_object("/room/death/death_mark");
    if (!objectp(ob)) return 1;
    ob->move(opfer,M_NOCHECK);
    SetProp(P_KILL_NAME,"Eine zusammenbrechende Bruecke");
    SetProp(P_KILL_MSG,0);
    return 1;
}

int springe(string was) {
   notify_fail("Von was moechtest Du springen?\n");
   if (was != "von bruecke")
      return 0;
   write("Du springst mutig in den See.\nDu bist sofort tot.\n");
   say(this_player()->Name(WER)+" springt in den See, welch mutige Tat.\n", 
       this_player());
   fakekill("Ein Sprung von der Bruecke","Selbstmord ist keine Loesung!\n",
   this_player());
   return 1;
}

int set_zustand(int i)
{
  if (i>=0 && i <= 100)
     zustand = i;
  else
     return 0;
  return 1;
}

int query_zustand()
{
  return zustand;
}

string query_zustand_string()
{
   if (zustand>=0 && zustand <= 100)
   return
     ({"Diese Bruecke haengt nurnoch an einem (seidenen?) Faden!\n",
       "Mit dieser Bruecke ist es bald vorbei. Viel haelt sie nicht mehr aus.\n",
       "Diese Bruecke befindet sich in einem ganz ganz schlechten Zustand.\n",
       "Diese Bruecke befindet sich in einem sehr schlechten Zustand.\n",
       "Diese Bruecke befindet sich in einem schlechten Zustand.\n",
       "Den Zustand dieser Bruecke kann man als mittelmaessig beschreiben.\n",
       "Hui, diese Bruecke befindet sich in einem ueberdurchschnittlichen Zustand.\n",
       "Diese Bruecke befindet sich in einem guten Zustand.\n",
       "Diese Bruecke befindet sich in einem sehr guten zustand.\n",
       "Diese Bruecke befindet sich in einem hervorragenden Zustand!\n",
       "Diese Bruecke befindet sich in einem TOP-Zustand! Gratulation!\n"})
       [zustand/10];
    else
      return "Diese Bruecke befindet sich in einem Fehler im Raum-Zeit-Gefuege.\n";
}      

string det_bruecke()
{
   return BS("Du balancierst auf einigen Holzbohlen, welche von zwei "+
   "recht duenn erscheinenden Fuehrungsseilen verbunden werden. Von den "+
   "zwei dicken Halteseilen rechts und links von Dir fuehren andere "+
   "Halteseile zu den Bohlen und stabilisieren sie. Du betrachtest die "+
   "Bruecke und kommst zu folgendem Schluss: "+query_zustand_string());
}

string det_burg()
{
   return BS("Vor Dir erhebt sich die grosse schwarze Burg mit ihren "+
   "Tuermen, ihren gewaltigen, schwarzen Steinen, ihrer Finsternis und "+
   "ihrem grossem Portal. Das Portal ist momentan "+
   ((call_other(CHAOS_GILDEN_ROOM("cl2br2"),"portal_status")==1)?
   "geoeffnet.":"geschlossen."));
}

string det_portal()
{
   return BS("Das Portal ist momentan "+
   ((call_other(CHAOS_GILDEN_ROOM("cl2br2"),"portal_status")==1)?  
   "geoeffnet.":"geschlossen."));
}


int reduce_zustand(int i,object me)
{
   object *ob;
   object *ob2;
   
   zustand-=i;
   if (zustand<0) zustand = 0;
   if (zustand) 
     return 1;
   
   tell_room(this_object(),"DIE BRUECKE REISST! DU FAELLST! AAAAAAAH!\n");
   tell_room(find_object(CHAOS_GILDEN_ROOM("cl2br2")),
                            "DIE BRUECKE REISST! DU FAELLST! AAAAAAAH!\n");
   tell_room(find_object(CHAOS_GILDEN_ROOM("cl2br4")),
                               "DIE BRUECKE REISST!\n");
   call_other("/d/polar/files.chaos/obj/glocke","burg_msg",
              "Die Bruecke zerreisst, faellt in den See und reisst ihre Passanten in den Tod.\n");
   SetProp(P_KILL_NAME,"Eine zusammenbrechende Bruecke");
   SetProp(P_KILL_MSG,"Er kappte selbst das Seil! Welch Held!");
   (CHAOS_GILDEN_ROOM("cl2br2"))->SetProp(P_KILL_MSG,"Er kappte selbst das Seil! Welch Held!");
   me->move("/room/void",M_SILENT|M_NO_SHOW|M_GO,"in die Tiefe");
   me->die();
   
   SetProp(P_KILL_MSG,0);
   (CHAOS_GILDEN_ROOM("cl2br2"))->SetProp(P_KILL_MSG,0);
   call_other(CHAOS_GILDEN_ROOM("cl2br2"),"???");

   ob = all_inventory(this_object());
   if (!ob) ob = ({});
   if (!pointerp(ob)) ob = ({ob});
   
   ob2 = all_inventory(find_object(CHAOS_GILDEN_ROOM("cl2br2")));
   if (!ob2) ob2 = ({});
   if (!pointerp(ob2)) ob2 = ({ob2});
   
   ob += ob2;
   map_objects(ob, "move","/room/void", M_GO | M_NO_SHOW,"in die Tiefe");
   ob = filter_array(ob,#'living);   
   map_objects(ob, "die");
   return 1;  
}

int kappen(string was) {
   object ob;
   string *dtypes;
   
   notify_fail("Was moechtest Du kappen?\n");
   if (was != "seile" && was != "halteseile")
     return 0;
     
   if (this_player()->QueryProp("chaos_last_stroke")>time()-2)
   {
      write("So schnell geht das nicht!\n");
      return 1;
   }
   if (!this_player()->id("daemon")) // Daemonen duerfen das.
   {
   if (!(ob=this_player()->QueryProp(P_WEAPON)))
   {
      write("Wie willst Du die Seile denn kappen? Mit deinen Haenden? Doch wohl nicht.\n");
      say(this_player()->Name(WER)+" zerrt an den Seilen. Was fuer ein Idiot.\n",this_player());
      return 1;
   }
   dtypes = ob->QueryProp(P_DAM_TYPE);
   if (!pointerp(dtypes)) dtypes = ({dtypes});
   
   if (member_array(DT_SLASH,dtypes)==-1 &&
       member_array(DT_RIP,dtypes)==-1 )
   {
      write("Mit "+ob->name(WEM)+" kannst Du doch kein solches Seil kappen!\n");
      say(this_player()->Name(WER)+" fuhrwerkt mit "+ob->name(WEM)+" an den "+
      "Halteseilen rum. Erbaermlich.\n",this_player());
      return 1;
   }
   }
   this_player()->SetProp("chaos_last_stroke",time());
   write("Du hackst auf die Haltetaue ein. Die Bruecke schwankt bedrohlich.\n");
   say(this_player()->Name(WER)+" hackt auf die Haltetaue ein.\n",this_player());
   tell_room(CHAOS_GILDEN_ROOM("cl2br2"),"Im Sueden versucht "+
             this_player()->name(WER)+", die Seile zu kappen!!!\nDie Bruecke schwankt bedrohlich!\n");
   tell_room(CHAOS_GILDEN_ROOM("cl2br4"),"Auf der Bruecke versucht "+
             this_player()->name(WER)+", die Seile zu kappen!!!\n");

   reduce_zustand(5+random(5),this_player());
   return 1;
}

void exit() 
{
  if (objectp(this_player()))
  this_player()->SetProp("chaos_last_stroke");
}

int BecomesNetAlive(object me) {
  if (zustand==0)
  {
    tell_object(me,
    "Du schaust Dich um.\nWo ist die Bruecke?\nWO IST DIE BRUECKE???\nWAAAH!!\n");
    fakekill("Ein Erwachen in grosser Hoehe","Hier sollte man auch nicht einschlafen",me);
    return 1;
  }
  return ::BecomesNetAlive(me);
}
