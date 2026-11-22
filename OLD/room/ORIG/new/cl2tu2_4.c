#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
  ::create();
  SetProp( P_INT_SHORT, "Obergeschoss des Flugdaemonen-Turms." );
  SetProp( P_INT_LONG, BS("Du hast es geschafft! Du bist ganz oben "+
                          "im Turm angekommen. Nun weisst Du auch was "+
                          "der Hauptzweck dieses Turms ist: Ein "+
                          "Landepunkt fuer Flugdaemonen! Zu erkennen "+
                          "ist dies zum einen an dem grossen Fenster "+
                          "in der Wand, und zum anderen natuerlich an "+
                          "den vielen Flugdaemonen-Exkrementen am "+
                          "Boden.@@fdaemon@@",78));

  SetProp( P_LIGHT, -1);
  SetProp( P_INDOORS, 1);


  AddDetail( ({ "boden" }), BS(
          "Der komplette Boden besteht, ebenso wie die Decke und die "+
          "Waende, aus schwarze, grossen Steinbloecken. Du erkennst "+
          "viele Kratzspuren an ihm. Ausserdem liegen hier jede "+
          "Menge Flugdaemonen-Exkremente rum.",78));
  AddDetail( ({ "decke" }), BS(
          "Die Decke sowie die Waende und der Boden besteht aus "+
          "schwarzen, grossen Steinbloecken. An der Stelle wo die Leiter "+
          "hindurch fuehrt, wurde ein schmales Loch herausgehauen. Und "+
          "selbst an der Decke sind Kratzspuren zu sehen... "+
          "Sie stammen wohl von den hier oft ankommenden Flugdaemonen.",78));
  AddDetail( ({ "stein", "gestein"}), BS(
          "Hier besteht fast alles aus diesen schwarzen, grossen "
          "Steinbloecken.",78));
  AddDetail( ({ "wand", "waende" }), BS(
          "Die Waende bestehen aus dem selben schwarzen Stein wie die "+
          "Decke und der Boden. An der einen Wand ist ein grosses Fenster "+
          "zu erblicken, durch das wohl die Flugdaemonen hereinfliegen "+
          "koennen.",78));
  AddDetail( ({ "raum" }), BS(
          "Du stehst drin.",78));
  AddDetail( ({ "wesen" }), BS(
          "Damit sind die Flugdaemonen gemeint!",78));
   AddDetail( ({ "kratzer", "kratzspuren", "spuren" }), BS(
          "Die stammen natuerlich von den Flugdaemonen.",78));
  AddDetail( ({ "treppe" }), BS(
          "Eine steinerne Treppe, schwarz, natuerlich. Auf ihr erkennst "+
          "Du Kratzspuren der Flugdaemonen. Sie fuehrt weiter nach "+
          "unten.",78));
  AddDetail( ({ "angst" }), BS(
          "ANGST! PURE ANGST! Solltest Du jedoch ein Chaoskrieger sein, "+
          "so hast Du selbige natuerlich nicht.",78));
  AddDetail( ({ "chaoskrieger" }), BS(
          "Die fangen den Schaden mit der Brust ab!",78));
  AddDetail( ({ "schaden", "brust" }), BS(
          "Hmm, ist nur so ein Sprichwort :)",78));
  AddDetail( ({ "sprichwort" }), BS(
          "Hoer auf damit!",78));
  AddDetail( ({ "hauptzweck" }), BS(
          "Ein Landepunkt der Flugdaemonen.",78));
  AddDetail( ({ "landepunkt" }), BS(
          "Naja, das hier ist wohl sowas.",78));
  AddDetail( ({ "flugdaemonen" }), BS(
          "Sollten keine da sein, musst Du eben warten...",78));
  AddDetail( ({ "exkremente", "flugdaemonen-exkremente" }), BS(
          "Hmm, Flugdaemonen verursachen Exkremente ? Seltsam, aber "+
          "aber man lernt ja nie aus :)",78));
  AddDetail(({"beschwoerung"}),BS("Versuchs mal mit 'beschwoere "+
          "flugdaemon'.",78));
  AddDetail(({"fenster"}),BS("Das Fenster ist riesig. Gross genug "+
  "sogar, um einem Flugdaemon ein bequemes Starten und landen zu "+
  "ermoeglichen. Durch das Fenster kannst Du die Burg und die Hoehle "+
  "dort draussen sehen.",78));
  AddDetail(({"flugdaemon"}),BS("Flugdaemonen sind grosse, boesartige "+
  "Wesen. Denke immer daran: Sie sind gefaehrlich!",78));
  AddDetail(({"starten","landen"}),BS("Wow. Hier koennte sogar ein "+
  "gewaltiger Flugdaemon Starten und Landen!",78));
  AddDetail(({"burg"}),BS("Von der Burg kannst Du kaum mehr erkennen "+
  "als die Spitzen der anderen Tuerme. Der Rest ist von einer gewaltigen "+
  "Kugel aus purer Dunkelheit bedeckt.",78));
  AddDetail(({"spitzen"}),BS("Wow, diese Kugel ist ja richtig gewaltig! "+
  "Man kann nur die Spitzen der Tuerme erkennen! ",78));
  AddDetail(({"tuerme"}),BS("Diese Burg hat vier Tuerme. Du kannst nur "+
  "einen anderen Turm erkennen, und selbst den nicht sehr gut.",78));
  AddDetail(({"turm"}),BS("Uuuuuh, aeeeeeeh, ja, der ist da. Mehr kannst "+
  "Du aber wirklich nicht sagen, denn es ist sehr dunkel hier in dieser "+
  "Hoehle.",78));
  AddDetail(({"hoehle"}),BS("Du befindest Dich in einer grossen Hoehle. "+
  "Das sollte Dir klar sein. Du kannst nicht viel von ihr erkennen, da "+
  "es so fuerchterlich dunkel ist.",78));
  AddDetail(({"rest"}),BS("Der Rest ist hier alles von den Spitzen der "+
  "Tuerme aus abwaerts.",78));
  AddDetail(({"kugel"}),BS("Eine gewaltige Kugel aus purer Finsternis brei"+
  "tet sich unter Dir aus. Wie unheimlich.",78));
  AddDetail(({"finsternis","dunkelheit"}),BS("Es ist verflucht finster "+
  "da unten. Du bist froh, hier oben zu sein und nicht in dieser Dunkelheit.",78));
  AddDetail(({"menge"}),BS("Ooooooh, das ist wirklich eine Menge. Baeeeh!",78));
  AddDetail(({"loch"}),BS("Durch dieses Loch fuehrt eine Leiter in die "+
  "ungewissen Tiefen unter Dir.",78));
  AddDetail(({"tiefen"}),BS("Huuuuuuuh Huuuuuuuuh! Gefaehhrlich.",78));
  AddDetail(({"zinne"}),BS("Die Zinne ist auf dem anderen Turm. Du kannst "+
  "sie kaum erkennen.",78));
  AddDetail(({"leiter"}),BS("Sie sieht sehr wacklig aus und fuehrt in die "+
  "duesteren Tiefen unter Dir...",78));
  AddDetail(({"stelle"}),BS("Huiiii. Ein Loch!"));
  

  AddSounds( SENSE_DEFAULT,
                BS("Jetzt weisst Du auch woher das Kratzen kommt: Von den "+
                   "Flugdaemonen! Ebenso das Fluegelschlagen.",78));
  AddSounds( ({ "kratzen", "fluegelschlagen", "geraeusch" }), "Ich "+
                "sagte doch schon: Von den Flugdaemonen.");
        


  AddSmells( SENSE_DEFAULT, BS(
                "Du riechst nur den allwaehrenden Geruch des Chaos :)",78));
  AddSmells( ({ "geruch", "chaos" }), BS(
                   "Der Geruch des Chaos laesst sich schwer beschreiben, "+
                   "wie Du Dir sicher denken kannst :)",78));

  AddExit("unten",CHAOS_GILDEN_ROOM("cl2tu2_3"));
  AddItem(CHAOS_GILDEN_MON("cl2_fdaemon"),REFRESH_DESTRUCT);
  AddCmd(({"beschwoer","beschwoere"}),"summon");
}

string fdaemon()
{
  call_other(CHAOS_GILDEN_ROOM("cl2tu1_1"),"???");
  if (present("\nflugdaemon",find_object(CHAOS_GILDEN_ROOM("cl2tu1_1"))))
    return "\nAuf einer Zinne des anderen Turms siehst Du einen grossen Flugdaemon\n"+
           "Vielleicht koenntest Du ihn durch eine Beschwoerung hierher-\n"+
           "holen?";
  return "";
}


int summon(string was) 
{
  object ob;
  if (was != "daemon" && was != "flugdaemon")
    return notify_fail("Was moechtest Du beschwoeren?\n"),0;
  if (!find_object(CHAOS_GILDEN_ROOM("cl2tu1_1")))
    return write("Du siehst einen boesen Fehler im RZG.\n"),1;
  if (!(ob = present("\nflugdaemon",find_object(CHAOS_GILDEN_ROOM("cl2tu1_1")))))
    return write("Da ist aber garkein Flugdaemon!\n"),1;  
  if (this_player()->QueryProp(P_ALIGN)>200) {
    write(break_string("Hallooooo! Lieber Flugdaemon! Komm doch rueber, "+
    "ich hab auch ein Leckerchen fuer Dich!",78,"Du rufst: "));
    say(break_string("Hallooooo! Lieber Flugdaemon! Komm doch rueber, "+
       "ich hab auch ein Leckerchen fuer Dich!",78,this_player()->Name(WER)+
       " ruft: "),this_player());
    tell_room(this_object(),"Der Flugdaemon bewegt sich keinen Millimeter.\n");
    return 1;
  }
  write(break_string("Oh boesartiger Daemon! Oh Geschoepf der tiefsten Hoellen, "+
  "oh Diener finsterster Maechte, oh Herr des Himmels, oh gefluegeltes Biest "+
  "der Tiefe! Ich beschwoere Dich, gehorche meinem Befehl. Eile herbei! Eile "+
  "herbei!",78,"Du intonierst: "));
  say(break_string("Oh boesartiger Daemon! Oh Geschoepf der tiefsten Hoellen, "+
  "oh Diener finsterster Maechte, oh Herr des Himmels, oh gefluegeltes Biest "+
  "der Tiefe! Ich beschwoere Dich, gehorche meinem Befehl. Eile herbei! Eile "+
  "herbei!",78,this_player()->Name(WER)+" intoniert: "),this_player());
  tell_room(this_object(),"Der Daemon erhebt sich von der Zinne.\n");
  ob->move(this_object(),M_GO);
  this_player()->restore_spell_points(-5);
  return 1;
}
