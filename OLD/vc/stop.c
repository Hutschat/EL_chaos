/*
     18.06.99 Swift     ("Ich will keine Chaoten toeten"->"Ich bin ganz friedlich"
                         abgeaendert. say() gibt kein return 0 mehr zurueck, das
                         gesagte hoert jetzt keiner mehr im Raum bei Kruuolq. :) )
*/

#include <properties.h>
#include <moving.h>

#include "/gilden/files.chaos/gilde.h"
#define BS(x) break_string(x,78)

inherit "/std/room";


create()
{
  ::create();
  seteuid(getuid(this_object()));
  SetProp(P_LIGHT,1);
  SetProp(P_INT_SHORT, "Erstmal sicher");
  SetProp(P_INT_LONG, break_string("Wo Du bist, ist unwichtig. "+
  "Du bist sicher. Niemand wird dir etwas tun. Es ist vorbei. Du hast es "+
  "ueberlebt. Alles ist gut. Niemand will Dich toeten. Die Chaoten sind "+
  "Deine Freunde. Du toetest keine Chaoten. Du wirst aufhoeren, mit der "+
  "Hand so gefaehrlich zu zucken. Alles ist sicher. Dein Atem geht ruhig "+
  "und regelmaessig. Dein Herzschlag beruhigt sich und schlaegt im Einklang "+
  "mit dem Universum. Du bist locker und entspannt. Alles ist gut, alles "+
  "ist locker, alles ist groovy. Du hoerst auf, wild in der Luft herumzu"+
  "beissen. Du entkrampfst dein Haupt. Niemand kann Dir hier etwas tun. "+
  "Lasse Dir Zeit. Alles ist sicher, niemand ausser Dir ist hier, niemand "+
  "kann herein. Du bist locker und entspannt. Ruhig, ganz ruhig. Dein "+
  "Blickfeld klaert sich, Du kannst wieder sehen. Die Welt ist sicher und "+
  "gut. Doch darum kannst Du Dich spaeter kuemmern. Langsam und ruhig "+
  "laesst Du Deine Blicke schweifen und kannst wieder Konturen erkennen. "+
  "Alles ist gut. Alles ist locker. Du bist sicher und entspannt. Du musst "+
  "nicht mehr toeten. Niemand hier ist eine Gefahr fuer Dich. Du bist sicher. "+
  "Du bist allein. Dieser Raum gehoert Dir. Er traegt Deinen Namen. Er "+
  "wird sich zerstoeren, wenn Du ihn verlassen hast, doch solange bist "+
  "Du sicher. Du bist hier. Alles ist gut. Du bist sicher. Alles ist gut.",78));
  AddDetail("boden",break_string(
  "Dieser Boden ist sicher Du bist hier sicher. Niemand wird Dir hier etwas "+
  "tun!.",78));
  AddDetail(({"wand","waende"}), "Die Waende sind da. Sie sind sicher und gut.\n");
  AddDetail(({"sicher","sicherheit"}),BS("Du bist hier absolut sicher."));
  AddDetail(({"niemand"}),BS("Niemand sagt: Ich bin garnicht da.\nNiemand "+
  "sagt: Ich werde Dich nicht toeten."));
  AddDetail(({"chaoten"}),BS("Die Chaoten sind deine Freunde. Du musst sie "+
  "nicht toeten."));
  AddDetail(({"toeten"}),BS("Du musst nicht toeten. Zumindest nicht jetzt. "+
  "Alles ist gut. Alles ist locker."));
  AddDetail(({"freunde"}),BS("Die Chaoten sind deine Freunde. Und selbst wenn "+
  "sie das nicht sind, wenn sie deine verschworenen Feinde sind, Du musst sie "+
  "nicht toeten. Alles ist gut."));
  AddDetail(({"hand"}),BS("Du versuchst, sie ruhig zu halten."));
  AddDetail(({"atem"}),BS("Huuuuuu Puuhhhhh Huuuuuuu Puuuuuh HuPuHuPu Huuuuu Puuuuuh"));
  AddSounds(({"atem"}),BS("Er geht ruhig und regelmaessig"));
  AddSounds(({"SENSE_DEFAULT"}),BS("Leichte Musik umgarnt Dich."));
  AddDetail(({"musik"}),BS("Die kannst Du hier nicht sehen."));
  AddSounds(({"musik"}),BS("Sie ist locker.... beschwingt ... Klingt sehr beruhigend."));
  AddSounds(({"herzschlag"}),BS("PaDumm PaDumm ... Pa ..... Dumm ... Dumm ... DummPa ... DuPammPaMud ..."));
  AddDetail(({"herzschlag"}),BS("Du kannst ihn hoeren."));
  AddDetail(({"universum","einklang"}),BS("Raum und Zeit werden eins... Du befindest "+
  "Dich im Einklang... verwandelst Dich in eine gruene Tomate... explodierst."));
  AddDetail(({"tomate"}),BS("Wo ist sie hin? Wo? Woooooo?"));
  AddDetail(({"zeit","raum"}),BS("Raum und Zeit bilden eine gebogene, in sich "+
  "geknotete Linie."));
  AddDetail(({"luft"}),BS("Du kannst sie riechen."));
  AddSmells(({"luft"}),BS("Die Luft riecht ok."));
  AddDetail(({"haupt"}),BS("Das ist dein Kopf"));
  AddDetail(({"kopf"}),BS("Huuuh, der ist wohl etwas verkrampft."));
  AddDetail(({"zeit"}),BS("Tick Tack Tick Tack Tock Tuck Tick Tick...."));
  AddDetail(({"blickfeld","konturen"}),BS("Du kannst wieder sehen! Hurrraaa!"));
  AddDetail(({"blicke"}),BS("Ruhig laesst Du sie schweifen."));
  AddDetail(({"welt"}),BS("Man koennte heut abend die Herrschaft ueber sie "+
  "uebernehmen."));
  AddDetail(({"gefahr"}),BS("Hier droht Dir keine Gefahr."));
  AddDetail(({"raum"}),BS("Dies hier ist dein Raum. Er traegt Deinen Namen."));
  AddDetail(({"namen","name"}),BS("Na den wirst Du doch noch kennen, oder? :)"));
  AddDetail(({"decke"}),BS("Die Decke ist da, und sie verspricht Sicherheit."));
  
  AddRoomMessage(({
  "Leichte Musik ertoent von irgendwoher.\n",
  "Du bist ruhig.\n",
  "Du bist entspannt.\n",
  "Wenn Du Dich unter Kontrolle hast, sage: 'Ich bin ganz friedlich!!!'\n",
  "Du bist ruhig und entspannt.\n",
  "Der Kampf ist vorbei.\n",
  "Du musst keine Chaoten mehr toeten.\n",
  "Wenn Du Dich besser fuehlst, sage: 'Ich bin ganz friedlich!!!'\n",
  "Du bist hier sicher.\n",
  "Niemand kann hier herein.\n",
  "Alle Chaoten sind deine Verbuendeten.\n",
  "Du kommst hier raus, wenn Du sagst: 'Ich bin ganz friedlich!!!'\n",
  "Du fuehlst Dich wirklich gut.\n",
  "Du hast Dich unter Kontrolle.\n",
  "Das Leben ist wunderschoen.\n",
  "Wenn Du wieder klar bist, sage: 'Ich bin ganz friedlich!!!'\n",
  "Alles wird gut. Alles ist besser.\n",
  "Die seichte Musik lullt Dich beruhigend ein.\n",
  "Alles ist schoen und toll hier.\n",
  "\n",
  "Wenn Du keine Chaoten toeten willst, sage: 'Ich bin ganz friedlich!!!'\n",
  }),18);
  
  
  AddCmd(({"sag","sage"}),"say");  
}


int say(string was)
{
//   if (was != "ich will keine chaoten toeten")
   if(was != "ich bin ganz friedlich" && was != "ich bin ganz friedlich!!!")
   {
     write("Nein, das war es nicht. Beruhige Dich. Konzentriere Dich. "
          +"Nimm Dir Zeit.\n");
     return 0;
   }
   write("Du sagst: Ich bin ganz friedlich!!!\n");
   write("OK, glauben wir Dir das mal.\n");
   this_player()->move("/gilden/chaos",M_GO,"geht","herein","schwebt friedlich");
   remove();
   return 1;
}


reset()
{
  ::reset();
}

GetExits(object wer)
{
  return "Es gibt hier keinen Weg herein. Du bist absolut sicher.\n";
}

init()
{
  ::init();
  if (!query_once_interactive(this_player()))
    call_out("weg",0,this_player());
}

int weg(object ob)
{
  if (objectp(ob))
  tell_room(environment(ob),ob->Name(WER)+" wird zersetzt.\n");
  ob->remove();
}
