#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit "/std/room";


#define BS(x) break_string(x,78)

string query_int_long()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS(
    "Du stehst auf dem Wehrgang der Burg und befindest Dich nun in "+
    "etwa ueber dem Portal. Die Dunkelheit, welche die Burg in ihren "+
    "Klauen haelt, ist hier nicht ganz so stark, und so kannst Du "+
    "den See unter Dir erkennen, und recht undeutlich noch das andere "+
    "Ufer mit seinem Huegel. Zwischen dem Ufer und der Burg ist nur der "+
    "See. Die Bruecke ist zerstoert und haengt in Einzelteilen am anderen "+
    "Ufer.");
  return BS("Du stehst auf dem Wehrgang der Burg und befindest Dich nun in "+
    "etwa ueber dem Portal. Die Dunkelheit, welche die Burg in ihren "+
    "Klauen haelt, ist hier nicht ganz so stark, und so kannst Du "+
    "den See unter Dir erkennen, und recht undeutlich noch das andere "+
    "Ufer mit seinem Huegel. Die Haengebruecke schwingt sich majestaetisch "+
    "vom Ufer zur Burg. Sie ist so lang, dass man sie in zwei Abschnitte "+
    "einteilen kann, nennen wir sie Abschnitt 1 und Abschnitt 2.");
}

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Auf einem Wehrgang");
  SetProp(P_INT_LONG,"@@query_int_long@@");
  AddDetail(({"wehrgang"}),BS("Du stehst auf einem langem Wehrgang, welcher "+
  "sich ueber diese Seite der Burg spannt. Momentan stehst Du oberhalb des "+
  "Portals, welches in die Burg fuehrt."));
  AddDetail(({"seite"}),BS("Es gibt eine Ober- und Unterseite. Aber die "+
  "meinen wir jetzt nicht. Eher Vorder- und Rueckseite, obwohl das auch "+
  "nicht so passt. Also sagen wir einfach mal: Die Seite, wo das Portal is, "+
  "die is gemeint."));
  AddDetail(({"oberseite","unterseite","vorderseite","rueckseite"}),
  BS("Hmmm. Ob diese Seite wirklich ... ? Oder, vielleicht erst, wenn "+
  "man die Burg auf links zieht? Du weisst es nicht."));
  AddDetail(({"portal"}),BS("Du kannst es von hier aus nicht sehen, denn "+
  "Du befindest Dich ja _darueber_!"));
  AddDetail(({"burg"}),BS("In dieser Burg ist es fuerchterlich dunkel. Man "+
  "sieht kaum die Hand vor Augen. Auf dem Wehrgang hier ist es etwas besser, "+
  "man kann wenigstens den See und das andere Ufer erkennen. Umgeben bist "+
  "Du noch immer von diesen grossen, schwarzen Steinbloecken. Na, was auch "+
  "sonst."));
  AddDetail(({"hand","haende"}),BS("Zwei Haende sind eine gute Sache, ein "+
  "Chaot kann seine Chaosbaelle aber auch ohne Haende feuern. Das sollte "+
  "man immer bedenken."));
  AddDetail(({"sache"}),BS("Ne GUTE Sache."));
  AddDetail(({"chaosbaelle","chaosball"}),BS("Chaosbaelle sind gefaehrliche "+
  "Ansammlungen chaotischer, elementarer Kraft. Sie sind auesserst gefaehr"+
  "lich."));
  AddDetail(({"ansammlungen","gefaehrliche ansammlungen"}),
  BS("GEFAEHRLICHE Ansammlungen, jawollja."));
  AddDetail(({"kraft","elementare kraft","chaotische kraft"}),BS(
  "Chaosbaelle beziehen ihre Kraft aus reinstem Chaos."));
  AddDetail(({"chaos","chaot"}),BS("Als Chaot beherrscht man das Chaos und "+
  "dient ihm. Es gibt nichts besseres, als Chaot zu sein."));
  AddDetail(({"augen"}),BS("Du hast sogar zwei davon!"));
  AddDetail(({"see"}),BS("Er befindet sich weeeeit unter Dir und ist in "+
  "dieser Dunkelheit nur als graue Masse zu erkennen. Erfreulicherweise "+
  "scheint diese Huelle aus Dunkelheit um die Burg auch den Gestank des "+
  "Sees abzuhalten, was eine wirklich gute Sache ist."));
  AddDetail(({"masse","graue masse"}),BS("Das ist keine graue Masse, das "+
  "ist der See :-)"));
  AddDetail(({"gestank"}),BS("Gluecklicherweise scheint der Gestank des "+
  "Sees von der gleichen Kraft zurueckgehalten zu werden, die auch die "+
  "Burg verdunkelt."));
  AddDetail(({"huelle"}),BS("Diese ganze Burg ist abgeschirmt durch eine "+
  "merkwuerdige Art von Huelle. Weder Licht noch der Gestank des Sees "+
  "kann diese Huelle anscheinend durchdringen."));
  AddDetail(({"art","arten"}),BS("ART. Akzeptiers."));
  AddDetail(({"licht","dunkelheit"}),BS("Es ist hier sehr viel dunkler als "+
  "in der Hoehle selbst. Eine merkwuerdige Kraft scheint das Licht von "+
  "dieser Burg fernzuhalten."));
  AddDetail(({"ufer"}),BS("Das Ufer ist nur als dunkler Schatten zu erkennen. "+
  "Gerade noch kannst Du die zwei angespitzten Baumstaemme vor dem dunklen "+
  "Hintergrund ausmachen."));
  AddDetail(({"hintergrund"}),BS("Der Hintergrund ist einfach grau."));
  AddDetail(({"grau"}),BS("Genau. Grau."));
  AddDetail(({"baumstaemme"}),BS("Du kannst nicht viel mehr als ihre "+
  "Silhouetten ausmachen. IST das dunkel hier."));
  AddDetail(({"silhouetten"}),BS("HEY! Da sind ja die beiden Baumstaemme!!!"));
  AddDetail(({"klauen"}),BS("Maechtige, gefaehrliche Klauen!"));
  AddDetail(({"saeure"}),BS("Du kannst sie wegen der Dunkelheit nicht "+
  "sehen und ausserdem nicht riechen! Und das ist eine gute Sache."));
  AddDetail(({"boden"}),BS("Der Boden besteht aus den ueblichen grossen "+
  "Steinbloecken, deren Einheitlichkeit und Oede Du schon langsam "+
  "verfluchst. Aber auf diesen Steinbloecken, hossa!, siehst Du einen "+
  "riesen Haufen Felsbrocken!"));
  AddDetail(({"steinbloecke"}),BS("Sie sind pechschwarz und richtig "+
  "gross. Mehr kann man ueber diese Steinbloecke wirklich nicht sagen."));
  AddDetail(({"haufen"}),BS("Wow, das sind aber eine Menge Felsbrocken!"));
  AddDetail(({"menge"}),BS("Das ist wirklich eine GROSSE Menge!"));
  AddDetail(({"felsbrocken"}),BS("Das sind richtig grosse, fiese "+
  "Felsbrocken. Man kann sie nehmen und Leuten auf den Kopf werfen. "+
  "Da sich diese Leute entweder in Abschnitt 1 oder Abschnitt 2 der "+
  "Bruecke befinden, ist der Syntax hierzu: 'wirf felsbrocken auf "+
  "<wen> in abschnitt 1/2'."));
  AddDetail(({"leute"}),BS("Genau. Die Leute dort unten auf der Bruecke."));
  AddDetail(({"kopf"}),BS("Diese Leute da unten haben bestimmt Koepfe! HAHAHA!"));
  AddDetail(({"huegel"}),BS("Du kneifst Deine Augen zusammen und starrst "+
  "in die Dunkelheit. Da! Ganz undeutlich und grau in grau glaubst Du das "+
  "andere Ufer auszumachen, und mit ihm den Huegel!"));
  AddDetail(({"schatten"}),BS("Alles hier ist voller Schatten!"));
  AddDetail(({"abschnitte"}),BS("Naja, Du weisst schon, abschnitt 1 und "+
  "abschnitt 2."));
  AddDetail(({"urteil"}),BS("Auf Dein Urteil wirst Du Dich doch wohl ver"+
  "lassen, nicht?"));
  AddDetail(({"regen"}),BS("Kein Regen. Wow. Ist das merkwuerdig hier."));
  AddDetail(({"decke"}),BS("Du kannst sie in der Dunkelheit nicht erkennen."));
  AddDetail(({"hoehle"}),BS("Jaja, Du befindest Dich in einer gigantischen "+
  "Hoehle in einem Eisberg. Aber das wird langsam alt."));
  AddDetail(({"eisberg"}),BS("Er ist ueberall um Dich herum blah blah."));
  AddDetail(({"wand","waende"}),BS("Sie bestehen aus den schon bekannten "+
  "grossen Felsbloecken."));
  
  AddSpecialDetail(({"bruecke","haengebruecke"}),"det_bruecke");
  AddSpecialDetail(({"konstruktion"}),"det_konstruktion");
  AddSpecialDetail(({"planken","holzplanken","holzbohlen"}),"det_holzplanken");
  AddSpecialDetail(({"seil","seile"}),"det_seile");
  AddSpecialDetail(({"einzelteile"}),"det_einzelteile");
  AddSpecialDetail(({"abschnitt 1"}),"abschnitt1");
  AddSpecialDetail(({"abschnitt 2"}),"abschnitt2");
  
  
  AddSmells(SENSE_DEFAULT,BS("*Sniff Sniff* Du riechst nichts besonderes."));
  AddSounds(SENSE_DEFAULT,BS("Wow, wo ist der Regen? Es ist totenstill hier."));
  
  AddCmd(({"akzeptier","akzeptiere"}),"akzeptiere");
  AddCmd(({"nimm","nehme"}),"take");
  AddCmd(({"wirf","werfe"}),"throw");

  AddExit("unten",CHAOS_GILDEN_ROOM("cl2bu1"));
  
  
}


int akzeptiere(string was) {
  notify_fail("Was moechtest Du akzeptieren?\n");
  if (was != "art") return 0;
  write("Na da bin ich aber froh.\n");
  say(this_player()->Name(WER)+" ist bereit, zu akzeptieren.\n",this_player());
   
return 1;
}

string det_bruecke() {
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS(
    "Welche Bruecke? Die Bruecke ist weg! Die Einzelteile haengen, wirklich "+
    "kaum sichtbar, am anderen Ufer in den See!");
    
  return BS("Die Bruecke schwingt sich majestaetisch vom Ufer bis zum "+
    "Portal unter Dir, eine brilliante Konstruktion aus Seilen und "+
    "schwarzen Holzplanken. Sie ist so gross, dass man sie in zwei "+
    "Abschnitte aufteilen muss, nennen wir diese Abschnitte Abschnitt 1 "+
    "und Abschnitt 2. Du betrachtest die Bruecke und kommst zu folgendem "+
    "Urteil: "+call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand_string"));
}

string det_konstruktion()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS("So brilliant diese Konstruktion auch wahr, jetzt ist sie "+
    "zerstoert.");
  
  return BS("Sie ist wundervoll. Am besten bewundert man sie, indem man "+
  "sich auf die Bruecke begibt!");
}

string det_holzplanken()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS("Du kannst sie eigentlich nicht wirklich erkennen, wie sie "+
    "dort am anderen Ufer in den See haengen, gehalten von diversen Seilen... "+
    "Nein, das kannst Du im Grunde wirklich nicht sehen.");

  return BS("Sie sehen schwarz und bruechig und nicht sehr vertrauenerweckend "+
    "aus.");
}      

string det_seile()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS("Du kannst die Seile, welche am anderen Ufer in den Sees an "+
    "den grossen Baumstaemmen haengen, eigentlich nicht erkennen.");
  
  return BS("Wow, es gibt da die verschiedensten Arten von Seilen. Das "+
    "sieht alles so fuerchterlich interessant aus da unten!");
   
}

string det_einzelteile()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS("Du kannst sie kaum erkennen, schliesslich haengen sie am "+
    "anderen Ufer und es ist verflucht finster hier. Nein, im Grunde "+
    "kannst Du sie garnicht erkennen.");
    
  return BS("So eine Haengebruecke ist schon eine verflucht komplizierte "+
  "Sache. All die vielen Einzelteile ... Wahnsinn.");
}


string abschnitt1()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS("Du siehst nur den grauen See unter Dir.");
  
  return "Du siehst folgendes:\n"+
    call_other(CHAOS_GILDEN_ROOM("cl2br2"),"int_long",this_player(),this_player());
}    


string abschnitt2()
{
  if (call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
    return BS("Du siehst nur den grauen See unter Dir.");
  
  return "Du siehst folgendes:\n"+
    call_other(CHAOS_GILDEN_ROOM("cl2br1"),"int_long",this_player(),this_player());
}    

int take(string was) {
    if (was != "fels" && was != "felsbrocken") return 0;
    
    write(BS("Du nimmst diese Felsbrocken automatisch, wenn Du sie jemandem "+
    "auf den Kopf werfen willst. Der Syntax dazu ist uebrigens : "+
    "'wirf felsbrocken auf <wen> in abschnitt 1/2'. Viel Spass."));
    
    return 1;
}


int throw(string was) {
   string wer,wen;
   int wo;
   int erfolg;
   object ob;
   string filen;
   
   
   
   if (sscanf(was,"felsbrocken auf %s in abschnitt %d",wer,wo) < 2) return 0;
   if (wo == 1)
     filen = CHAOS_GILDEN_ROOM("cl2br2");
   else if (wo == 2)
     filen = CHAOS_GILDEN_ROOM("cl2br1");
   else {
     write("Diesen Abschnitt gibt es nicht!\n");
     return 1;
   }
   
   if (time() - this_player()->QueryProp("chaos_last_throw") < 2)
   {
      write("So schnell geht das nicht...\n");
      return 1;
   }
   
   if (!find_object(  filen  ) ||
       call_other(CHAOS_GILDEN_ROOM("cl2br1"),"query_zustand")==0)
   {
     write("Die Bruecke existiert nicht...\n");
     return 1;
   }
   
   if (!ob = present(wer,find_object(filen)))
   {
     write("Aber "+wer+" befindet sich garnicht in Abschnitt "+wo+"...\n");
     return 1;
   }
   if (!living(ob))
   {
     write("Aber "+ob->name(WER)+" lebt doch garnicht!\n");
     return 1;
   }
   erfolg = (random(100)*this_player()->QueryAttribute(A_DEX))/19;
   if (wo == 2) erfolg/=2;
   if (erfolg < 20) erfolg = 0;
   
   wen = ob->name(WEN);
   write(BS("Du schnappst Dir einen Felsbrocken und wirfst ihn mit "+
   "aller Kraft nach "+ob->name(WEM)+"."));
/*
   write(({"Du verfehlst "+wen+".\n",
           "Du verfehlst "+wen+".\n",
           "Du streifst "+wen+" leicht am Arm.\n",
           "Du streifst "+wen+" leicht am Koerper.\n",
           "Du triffst "+wen+" am Arm.\n",
           "Du triffst "+wen+" am Koerper.\n",
           "Du streifst "+wen+" am Kopf.\n",
           "Du triffst "+wen+" hart am Koerper.\n",
           "Du triffst "+wen+" hart am Kopf.\n"
           "Du triffst "+wen+" kritisch am Koerper.\n",
           "Du triffst "+wen+" kritisch am Kopf.\n"})[erfolg/10]);
*/           
   tell_object(ob,BS("Vom Wehrgang aus wirft "+this_player()->name(WER)+
   " Felsbrocken nach Dir."));
/*
 Sie treffen Dich "+
          ({"nicht","nicht","leicht","leicht","hart","hart","sehr hart",
            "sehr hart","extrem hart","extrem hart","kritisch"})[erfolg/10]));
*/
   tell_room(filen,"Ein Felsbrocken faellt auf "+wen+" herab.\n",
         ({ob}));
   ob->Defend((erfolg*35)/10,({DT_BLUDGEON}),([SP_SHOW_DAMAGE:1]),this_player());
   this_player()->SetProp("chaos_last_throw",time());
   return 1;
}


void exit()
{
  this_player()->SetProp("chaos_last_throw");
}

