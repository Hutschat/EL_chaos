#include "gilde.h"

inherit CHAOS_GILDEN_ROOM("cl2_std_kneipe");
#include <properties.h>
#include <rooms.h>
#include <combat.h>
 
create() {
  cl2_std_kneipe::create();
  SetProp(P_INT_LONG,QueryProp(P_INT_LONG)+"In einer Ecke des Raumes entdeckst Du tatsaechlich einen Dimensionsspalt.\n");
  AddDetail(({"ecke"}),"In einer Ecke steht ein leerer Kaefig. In der anderen entdeckst Du einen\nDimensionsspalt.\n");
  AddSpecialDetail(({"dimensionsspalt","spalt"}),"det_spalt");
  AddDetail(({"raum"}),QueryProp(P_INT_LONG));
  

AddToMenu("Chaos-Becher", ({"becher", "chaos-becher", "chaos becher", 
	"chaos" }), 
  ([ P_BUY_VALUE : 100,
     P_HP : 28,
     P_SP : 28,
     P_ALCOHOL : 8,
     P_DRINK : 1]),5, "tot" );

AddDrink( "Fausttaler Drogenfrei", ({ "fausttaler", "drogenfrei", 
	"fausttaler drogenfrei" }),
  70, 50, 0, 7,
({ "Du kannst kaum glauben, aber dieses harmlose Gesoeff wird tatsaechlich\n"
+"in so einer harten Kneipe ausgeschenkt. Sein Ruf ist wirklich nicht\n"
+"untertrieben: Hier kannst Du lange auf eine richtige Droehnung warten.\n",
"&& schaut sich schamvoll um und trinkt dann heimlich einen Fausttaler\n"
+"Drogenfrei.\n" }));

AddDrink( "Pilz (licht)", ({ "pilz", "pilz (licht)" }), 300,200,21,10,
({ "Du bist zwar kein Experte in Mykologie aber es ist doch ganz deutlich,\n"
+"dass dieser Pilz kein Pilz ist, sondern ein bieraehnliches Getraenk.\n"
+"Da Du dem Wirt keine Legastenie unterstellen willst, trinkst Du diesen\n"
+"oder dieses 'Pilz' ohne zu meckern aus. Was aber die zusaetzliche Angabe\n"
+"'licht' zu bedeuten hat, ist Dir nun voellig unklar, denn das Getraenk\n"
+"hat ueberhaupt gar nicht geleuchtet.\n",
"&& bestellt sich einen Pilz der weder eine Pflanze ist noch leuchtet.\n"}));


 AddToMenu("Freunds Kampfkater (vorgekaut)",
 ({"kater","kampfkater","rusty","freunds kampfkater"}),
 ([
  P_HP:0,
  P_SP:61,
  P_BUY_VALUE:400,
  P_ALCOHOL : 3,
  P_FOOD : 3,
  P_DRINK:3 ]),
 7,
 ({
 BRS("Der Wirt setzt Dir einen dampfenden Kampfkater vor die Nase, ueber "
 "den Du Dich sofort hermachst. Unglaublich! Dieser Kater schmeckt wirklich "
 "besonders zart! "
 "Wie wohl einer schmeckt, den der Wirt nicht vorher vorgekaut hat??"),
 "&& isst voller Hingebung einen Kampfkater.\n"}),
 0,10,({
 BRS("Der Wirt sagt: Kampfkater? Kleinen Augenblick! Die Biester sind rar!")+
 BRS("Der Wirt verschwindet mit einer Axt. Kurz darauf vernimmst Du in der "
 "Ferne Rustys Winseln."),
 BRS("Der Wirt sagt: Kampfkater? Kleinen Augenblick! Die Biester sind rar!")+
 BRS("Der Wirt verschwindet mit einer Axt. Kurz darauf vernimmst Du in der "
 "Ferne Rustys Winseln.") }));

 AddToMenu("Zauberersaft (heiss)",
 ({"saft","zauberersaft"}),
 ([
  P_HP:0,
  P_SP:61,
  P_BUY_VALUE:300,
  P_ALCOHOL : 2,
  P_FOOD : 1,
  P_DRINK:2 ]),
 4,
 ({"\
 Du bekommst eine Tasse mit heissem Zauberersaft, er schmeckt beschissen.\n","\
 && trinkt eine Tasse mit heissem Zauberersaft und muss fast kotzen.\n"}),
 0,10,({
 "Der Wirt sagt: Zauberersaft? Moment! Ich presse mal einen frisch aus...\n",
 "Der Wirt sagt: Zauberersaft? Moment! Ich presse mal einen frisch aus...\n"}));

 AddToMenu("Kaempferblut auf Eis",
 ({"blut","kaempferblut","eisblut"}),
 ([
  P_HP:61,
  P_SP:0,
  P_BUY_VALUE:300,
  P_ALCOHOL : 2,
  P_DRINK : 2,
  P_FOOD:1 ]),
 4,
 ({BRS("Der Wirt schmeisst noch einen schwarzen Eiswuerfel in den Humpen und "
 "reicht ihn Dir."),
 "&& bekommt einen Humpen Kaempferblut auf Eis.\n"}),
 0,10,({
 "Der Wirt kichert: Moment! Kaempfer sind immer so zickig beim Blutspenden.\n",
 "Der Wirt kichert: Moment! Kaempfer sind immer so zickig beim Blutspenden.\n"}));

 AddToMenu("Keys Special (geruehrt)",
 ({"key","keys","keys special","special"}),
 ([
  P_HP:0,
  P_SP:68,
  P_BUY_VALUE:350,
  P_ALCOHOL :0,
  P_FOOD : 0,
  P_DRINK:5 ]),
 8,
 ({BRS("Du bekommst Dein Gesoeff und trinkst es aus. Dieser Special war "
 "nicht nur gut, er war sogar besonders ekelig."),
 "&& trinkt mit Ekel im Gesicht einen Special.\n"}),
 0,15,({
 "Der Wirt bruellt: Verdammt! Schon wieder diese Ploerre! DAS DAUERT!\n",
 "Der Wirt bruellt: Verdammt &&! Schon wieder diese Ploerre! DAS DAUERT!!"}));


 AddToMenu("Feuer aus der Feuerebene",
 ({"feuer"}),
 ([
  P_HP:68,
  P_SP:0,
  P_BUY_VALUE:350,
  P_ALCOHOL :0,
  P_FOOD : 0,
  P_DRINK:5 ]),
 8,
 ({BRS("Du bekommst ein Glas reinen Feuers und fuehlst Dich danach hart "
 "wie Kruppstahl."),
 "&& trinkt ein Glas reinen Feuers und verbrennt sich nichtmal die Fresse...\n"}),
 0,15,({
 "Der Wirt nickt, zuendet ein Glas mit purem Methylalkohol an\n"
 "und sagt: Gleich!",
 "Der Wirt nickt && zu, zuendet ein Glas mit purem Methylalkohol an\nund "
 "sagt: Gleich!"}));

 AddCmd(({"betritt","betrete"}),"enter");
 AddCmd(({"bruelle","bruell"}),"call");
 AddCmd(({"wirf","werfe"}),"throw");
 AddCmd(({"raeum","raeume"}),"clean");
 
 RemoveExit("sueden");
 AddExit( "osten", C_112_ROOM( "cl2bu5" ) );
 
}

int call(string was)
{
  
  notify_fail("Was moechtest Du in den Spalt bruellen?\n");
  if (!was) return 0;
  was = this_player()->_unparsed_args();
  write(was+"\n");
  
  if (was[<8..] != "in spalt") return 0;
  was = was[0..sizeof(was)-10];
  write(break_string("Du bruellst: "+was+" in den Spalt.",78));
  say(break_string(this_player()->Name(WER)+" bruellt: "+was+" in den Spalt.",
      78),this_player());
  if (find_object(CHAOS_GILDEN_ROOM("ckneipe_fake")))
    tell_room(CHAOS_GILDEN_ROOM("ckneipe_fake"),
    break_string(was,78,"Eine Stimme bruellt: "));
  return 1;
}

int throw(string was)
{
   object ob;
   notify_fail("Was moechtest Du in den Spalt werfen?\n");
   if (!sscanf(was,"%s in spalt",was)) return 0;
   if (!(ob=present(was,this_player())))
     if (!(ob=present(was,this_object())))
       return 0;
   if (ob->QueryProp(P_NOGET))
   {
      if (stringp(ob->QueryProp(P_NOGET)))
        write(ob->QueryProp(P_NOGET));
      else
        write(ob->Name(WER)+" ist doch viel zu schwer!\n");
      return 1;
   }
   if ((ob->QueryProp(P_NODROP) || ob->QueryProp(P_CURSED)) &&
       environment(ob) == this_player())
   {
      write(ob->Name(WER)+" kannst Du einfach nicht loswerden!\n");
      return 1;
   }
   write("Du wirfst "+ob->name(WEN)+" durch den Spalt.\n");
   say(this_player()->Name(WER)+" wirft "+ob->name(WEN)+" durch den Spalt.\n");
   if (find_object(CHAOS_GILDEN_ROOM("ckneipe_fake")))
     tell_room(CHAOS_GILDEN_ROOM("ckneipe_fake"),
       break_string(ob->Name(WER)+" kommt durch den Spalt geflogen.",78));
   ob->move(find_object(CHAOS_GILDEN_ROOM("ckneipe_fake")),M_NOCHECK);
   return 1;
}

int clean(string was)
{
  object *ob;
  int i;
  
  notify_fail("Whut?\n");
  if (was != "kneipe auf") return 0;
  write("Du raeumst die Kneipe auf.\n");
  ob = all_inventory(this_object());
  for (i=sizeof(ob)-1;i>=0;i--)
    if(!ob[i]->QueryProp(P_NOGET) && !living(ob[i]))
    {
      write("Du wirfst "+ob[i]->name(WEN)+" durch den Spalt.\n");
      say(this_player()->Name(WER)+" wirft "+ob[i]->name(WEN)+" durch den Spalt.\n");
      if (find_object(CHAOS_GILDEN_ROOM("ckneipe_fake")))
        tell_room(CHAOS_GILDEN_ROOM("ckneipe_fake"),
          break_string(ob[i]->Name(WER)+" kommt durch den Spalt geflogen.",78));
      ob[i]->move(find_object(CHAOS_GILDEN_ROOM("ckneipe_fake")),M_NOCHECK);
    }
  return 1;
}

string det_spalt()
{
  call_other(CHAOS_GILDEN_ROOM("ckneipe_fake"),"??");
  return 
    "Du kannst ihn mit \"betritt spalt\" betreten. Durch den Spalt siehst Du:\n"+
    call_other(CHAOS_GILDEN_ROOM("ckneipe_fake"),"int_long",this_player(),this_player())+
    "-----------------------------------------------------------------------------\n"+
    "Du kannst in den Spalt bruellen, Dinge in den Spalt werfen oder die Kneipe\n"+
    "aufraeumen, ganz wie Du willst. Nur boesartig und chaotisch solltest Du sein.\n"+
    "Wie schon erwaehnt, kannst Du ihn auch betreten.\n";    
}
int enter(string was) {
  notify_fail("Was moechtest Du betreten?\n");
  if (was != "spalt")
    return 0;
  this_player()->move(CHAOS_GILDEN_ROOM("ckneipe_fake"),M_GO,"durch den Spalt");
  return 1;
}

tot(object spend, object drinker){
  SetProp(P_KILL_NAME,"Ein Becher voller Chaos" );
  SetProp(P_KILL_MSG,"Prost!");
  if(drinker->QueryProp(P_GUILD)=="chaos"){
    write(BRS("Der Becher voll Chaos ist genau das richtige fuer einen "
    "hartgesottenen Krieger des Chaos. Er schmeckt Dir nicht nur sehr "
    "gut, er ist es sogar."));
    say(this_player()->name()+" trinkt hastig einen Becher Chaos und fuehlt "
    "sich gut.\n");
    return 1;
  }
  write(BRS("Als Nicht-Mitglied der Gilde des Chaos haettest Du ihr "
  "staerkstes Gebraeu besser nicht bestellt. Dir dreht sich der Magen um "
  "und mit einem Schlag wird Dir furchtbar uebel."));
  say(drinker->name()+" trinkt einen Becher mit Chaos und schaut sehr "
  "seltsam drein.\n");
  drinker->do_damage(40+random(50),this_object());
  if (objectp(drinker))
  drinker->restore_spell_points(-80);
  return 1;
}

