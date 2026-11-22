#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit  CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)

int portal_status()
{
  return "/obj/doormaster"->QueryDoorStatus(CHAOS_GILDEN_ROOM("cl2bu1"));
  
}


string int_long(object ob1,object ob2)
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")>0)
   return ::int_long(ob1,ob2);
  return "Du befindest Dich hoch in der Luft.\n"+
         "Tief unter Dir befindet sich der Saeuresee.\n"+
         "Oh Ohhhhh.\n";
}


create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Auf einer schwankenden Haengebruecke");
  SetProp(P_INT_LONG,BS("Du haeltst Dich verzweifelt an einer schwankenden "+
  "Haengebruecke fest. Weit unter Dir siehst Du das gruene Wasser des Sees, "+
  "welches so absolut verdaechtig nach Saeure riecht. Vor Dir ragt die "+
  "grosse schwarze Burg in all ihrer Dunkelheit und mit ihrem grossen, "+
  "rettenden Portal vor Dir auf. Suedlich von Dir befindet sich in einiger "+
  "Entfernung der Huegel, ebenfalls ein rettendes Ufer. Der Wind laesst "+
  "die Bruecke beunruhigend schwanken, waehrend Du beunruhigt zum Wehrgang "+
  "ueber dem Portal aufschaust. Ob dort oben jemand lauert, um etwas auf "+
  "Dich herabzuwerfen?"));
  AddDetail(({"boden"}),BS("Der Boden unter deinen Fuessen besteht aus "+
  "schwarzen, knarrenden und knirschenden Holzbohlen, welche von duennen "+
  "Seilen davon abgehalten werden, in den See unter Dir zu stuerzen und "+
  "dort spontan zu verdampfen."));
  AddDetail(({"fuesse"}),BS("Hehe. Hast Du Quanten. Hehe."));
  AddDetail(({"bohlen","holzbohlen","planken"}),BS("So wie sie hier knirschen und "+
  "knarren, bist Du nicht so richtig mit ihnen zufrieden. Da doch lieber "+
  "was stabiles, vielleicht aus Eiche..."));
  AddDetail(({"eiche"}),BS("Was immer dies auch fuer ein Holz ist, in "+
  "Eiche haettest Du mehr Vertrauen."));
  AddDetail(({"holz"}),BS("Du weisst nicht, was dies fuer ein Holz ist, "+
  "aber es knirscht und knarrt nicht gerade vertrauenerweckend."));
  AddDetail(({"vertrauen"}),BS("Holz war schon immer eine Sache des "+
  "Vertrauens"));
  AddDetail(({"sache"}),BS("Sache Sache Popache."));
  AddDetail(({"wand","waende"}),BS("Keine da."));
  AddDetail(({"decke"}),BS("Die Decke befindet sich hoch ueber Deinem Kopf. "+
  "So hoch, dass Du sie eigentlich kaum erkennen kannst. Aber wenigstens "+
  "etwas kannst Du erkennen: Die Decke leuchtet. Schwach, aber sehbar."));
  AddDetail(({"kopf"}),BS("Ist da."));
  AddDetail(({"leuchten"}),BS("Ein schwaches Leuchten leuchtet von der "+
  "Decke herab."));
  AddDetail(({"see"}),BS("Weit unter deinen Fuessen befindet sich ein "+
  "groosser See gruener Faerbung, der verdaechtig nach hoechst gefaehrlicher "+
  "Saeure riecht. Ausserdem ist er gruen. Alles in allem kein erfreulicher "+
  "Anblick, insbesondere nicht von einer schwankenden Haengebruecke."));
  AddDetail(({"farbe","faerbung"}),BS("Dieser See ist GRUEN! Wer hat denn "+
  "sowas schon gesehen. Wow. Waere sicherlich richtig ulkig, wuerde der "+
  "See nicht nach Saeure riechen."));
  AddDetail(({"saeure"}),BS("Die kann ganz schreckliche Dinge mit Dir an"+
  "stellen, glaub mir das!"));
  AddDetail(({"dinge"}),BS("DINGE!! Also fuerchte Dich. Fuerchte Dich sehr!"));
  AddDetail(({"saeure"}),BS("Ob dieser See komplett aus Saeure besteht? "+
  "Du weisst es nicht. Aber moeglich waers..."));
  AddDetail(({"anblick"}),BS("Er ist weder ermutigend noch erfreulich. Des"+
  "halb halte Dich an die goldene Regel: NICHT NACH UNTEN SEHEN!"));
  AddDetail(({"regel","goldene regel"}),BS("Diese Regel ist golden und "+
  "besagt: NICHT NACH UNTEN SEHEN!"));
  AddSpecialDetail(({"haengebruecke","bruecke"}),"det_bruecke");
  AddDetail(({"seile","halteseile"}),BS("Die beiden grossen Halteseile "+
  "sind durchaus in Reichweite. Man KOENNTE mit einem Schwert oder aehn"+
  "lichem Werkzeug versuchen, diese Seile zu kappen. Aber wozu? Dann "+
  "wuerde es schliesslich abwaerts gehen..."));
  AddDetail(({"fuehrungsseile","fuehrungsseil"}),BS("Es ist recht duenn "+
  "und wird wohl nicht allzuviel aushalten. Also keinesfall die "+
  "Abwesenheit der Halteseile..."));
  AddDetail(({"schwert"}),BS("Mit einem Schwert koennte man diese "+
  "Halteseile vielleicht kappen. Mit etwas Muehe."));
  AddDetail(({"muehe"}),BS("*Aechz*"));
  AddDetail(({"abwesenheit"}),BS("Die Abwesenheit von Halteseilen koennte "+
  "diese Bruecke nicht verkraften."));
  AddDetail(({"werkzeug"}),BS("Naja, sei halt mal kreativ."));
  AddDetail(({"wasser","gruenes wasser"}),BS("Ist das wirklich nur "+
  "gruenes Wasser? Du weisst es nicht. Aber Du hast einen dringenden "+
  "Verdacht, dass dies in Wirklichkeit ein See aus SAEURE ist!!!"));
  AddDetail(({"verdacht"}),BS("Es stinkt hier derart, dass Du Dir mit "+
  "diesem Verdacht sehr sicher bist."));
  AddSpecialDetail(({"burg"}),"det_burg");
  AddDetail(({"wehrgang"}),BS("Ein Zinnenbewehrter Wehrgang erhebt sich "+
  "ueber dem Portal. Von diesem Wehrgang kannst Du von hier unten aber "+
  "lediglich die Zinnen ausmachen."));
  AddDetail(({"zinnen"}),BS("Sie bestehen aus den gleichen grossen "+
  "schwarzen Steinbloecken wie die Burgmauer."));
  AddDetail(({"mauer","burgmauer"}),BS("Die Burgmauer besteht aus grossen, "+
  "schwarzen Steinen. Jetzt, wo Du vor ihnen stehst, siehst Du das erste "+
  "Mal wirklich, wie gross sie sind. Beeindruckend."));
  AddDetail(({"steine","steinbloecke"}),BS("Die Steinbloecke sind pech"+
  "schwarz und manchmal einen, manchmal sogar zwei Meter hoch. Was "+
  "fuer eine Leistung, sie alle hierher zu schaffen."));
  AddDetail(({"meter"}),BS("Du weisst, wer ein Meter ist."));
  AddDetail(({"leistung"}),BS("Wow. Gute Leistung. Gratulation."));
  AddDetail(({"entfernung"}),BS("Es ist nicht wirklich weit. Nicht auf "+
  "sicherem Boden, jedenfalls."));
  AddDetail(({"sicherer boden"}),BS("Dies ist nicht gerade das, was man als "+
  "sicheren Boden bezeichnen wuerde."));
  AddDetail(({"huegel"}),BS("Suedlich von Dir endet die Bruecke irgendwann "+
  "auf einem Huegel aus Eis. Wie merkwuerdig."));
  AddDetail(({"ufer"}),BS("Das Ufer im Sueden ist relativ steil und "+
  "endet auf einem Huegel als eine Art Steilkueste."));
  AddDetail(({"steilkueste"}),BS("Du betrachtest es nicht als Alternative, "+
  "von dort aus Kopfspruenge zu ueben. Nichtsdestotrotz ist es eine "+
  "Steilkueste."));
  AddDetail(({"kopfspruenge"}),BS("Nein, das wuerdest Du hier wirklich "+
  "nur aeusserst ungern tun. "));
  
  AddSmells(SENSE_DEFAULT,BS("Baeeh! Es stinkt hier nach BAEH!"));
  AddSmells(({"baeh"}),BS("OK, OK, ich meinte Saeure."));
  AddSmells(({"saeure"}),BS("Es stinkt durchdringend nach Saeure."));
  
  AddSounds(SENSE_DEFAULT,BS("HUUUUH HUUUUUUUUUH Tropf Tropf HUUUUUUH!"));
  
  NewDoor("norden",CHAOS_GILDEN_ROOM("cl2bu1"),({"portal"}),
    ({D_NAME,"Portal",
      D_GENDER,0,
      D_SHORT,"Die Bruecke endet vor einem %sen Portal.",
      D_LONG,BS("Das Portal besteht aus fugenlosem, schwarzen Material, "+
                "welches irgendwie an das Holz in dieser Hoehle erinnert, "+
                "jedoch im Gegensatz dazu makellos ist. Die Fluegel muessen "+
                "ziemlich schwer sein. Ob es wohl von einem einzelnen Mann "+
                "geoeffnet werden kann?")
    }));
  AddExit("sueden",CHAOS_GILDEN_ROOM("cl2br1"));
  AddCmd(({"schau","schaue","siehe","sieh","sehe"}),"abwaerts");
  AddCmd(({"sei"}),"kreativ");
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


int abwaerts(string was) {
  if (was != "nach unten") return 0;
  write("WAAAAAAAAAH! ALLES DREHT SICH! DU FAELLST!\n");
  say(this_player()->Name(WER)+" schaut nach unten und faellt von der Bruecke.\n",this_player());
  fakekill("Ein Sturz von der Bruecke",((this_player()->QueryProp(P_GENDER)==2)?
           "Sie":"Er")+" haette nicht nach unten sehen sollen.",this_player());
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

string det_bruecke()
{
  return BS("Du stehst drauf. OK, etwas mehr Infos. Es gibt zwei duenne "+
  "Fuehrungsseile, an denen diese schrecklichen Planken befestigt sind, "+
  "zwei armdicke Halteseile und jede Menge Halteseile von diesen zweien "+
  "zu den Planken. Du untersuchst die Bruecke genauer und kommst zu fol"+
  "gendem Schluss: "+call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand_string"));
}  

int kreativ(string was) {
  if(was != "kreativ")
    return 0;
  write("Netter Versuch, aber das meinte ich etwas anders :-)\n");
  say(this_player()->Name(WER)+" ist kreativ.\n",this_player());
  return 1;
}

string det_burg()
{
 return BS("Vor Dir ragt die Burg auf. Du kannst prinzipiell nur das "+
 "grosse Portal mit seinem Wehrgang darueber erkennen, da Du jetzt quasi "+
 "direkt vor dem Portal stehst. Das Portal ist uebrigens "+
 ((portal_status()==1)?"geoeffnet":"geschlossen")+".");
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
   if (!this_player()->id("daemon"))
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
   tell_room(CHAOS_GILDEN_ROOM("cl2br1"),"Im Norden versucht "+
             this_player()->name(WER)+", die Seile zu kappen!!!\nDie Bruecke schwankt bedrohlich!\n");
   tell_room(CHAOS_GILDEN_ROOM("cl2br4"),"Auf der Bruecke versucht "+
             this_player()->name(WER)+", die Seile zu kappen!!!\nDie Bruecke schwankt bedrohlich!\n");
             
   call_other(CHAOS_GILDEN_ROOM("cl2br1"),"reduce_zustand",5+random(5),
   this_player());
   return 1;
}

void exit() 
{
  if (objectp(this_player()))
    this_player()->SetProp("chaos_last_stroke");
}

int BecomesNetAlive(object me) {
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
  {
    tell_object(me,
    "Du schaust Dich um.\nWo ist die Bruecke?\nWO IST DIE BRUECKE???\nWAAAH!!\n");
    call_out("fakekill",0,"Ein Erwachen in grosser Hoehe","Hier sollte man auch nicht einschlafen!",me);
    return 1;
  }
  return ::BecomesNetAlive(me);
}  
    
int check_way() {
  if ( call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
  {
     write("Waaaaaaaaah!\nKEINE BRUECKE! KEINE BRUECKE!!!!!!!!!\nWAAAAAAAAAAAAAAAH!\n"+
     "Du wirfst Dich herum und schaffst es, Dich in die Burg zu ziehen.\n");
     this_player()->move(CHAOS_GILDEN_ROOM("cl2bu1"),M_GO);
     return 1;
  }
  return 0;
}
  