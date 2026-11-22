#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2w_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"In einem Wald in einer Hoehle unter Eis");
  SetProp(P_INT_LONG,break_string("Du befindest Dich zwischen den schwarzen "+
  "Baeumen, welche Du schon vom Abhang oben gesehen hast. Was Du jedoch "+
  "fuer verkrueppelte und tote Baeume gehalten hast, sind in Wirklichkeit "+
  "gesunde Baeume, welche weder tot noch verkrueppelt sind. Abgesehen "+
  "davon sind sie natuerlich sehr sonderbar. Sie scheinen nicht normal "+
  "in die Hoehe zu wachsen, sondern sich manchmal kreisartig, manchmal im "+
  "Zickzack, nach oben vorzuarbeiten. Ihre Blaetter sind klein und mit "+
  "einer Art Film einer Fluessigkeit bedeckt. Ausserdem sind diese "+
  "Baeume schwarz, oder zumindest von sehr dunkelgrauer Farbe. Du hast "+
  "solche Baeume ausserhalb dieser Hoehle noch nie gesehen.\n"+
  "Neben den Baeumen gibt es hier auch dorniges Unterholz, welches es "+
  "unmoeglich macht, vom Pfad abzuweichen.\n Der Weg fuehrt nach Nordwesten "+
  "und im Sueden den Abhang hinauf. Ein leichter Nieselregen faellt auf "+
  "Dich herab.",78,0,1));
  AddDetail(({"boden"}),BS("Der Boden besteht natuerlich aus Eis und "+
  "einer duennen Lage durchweichtem Schnee, was einen Spaziergang nur um "+
  "so interessanter macht. In das Eis haben sich die schwarzen Baeume hier "+
  "ihre Wurzeln gegraben und ziehen aus ihm die wenigen Naehrstoffe, die "+
  "sie bekommen koennen. Das gleiche gilt fuer das dornige, gestrueppartige "+
  "Unterholz hier. Quer durch das Unterholz wurde ein Weg (frei-)geschlagen, "+
  "welcher mit Kies gestreut wurde (was einen Spaziergang wiederum fuerchter"+
  "lich langweilig macht)."));
  AddDetail(({"eis"}),BS("Das Eis in dieser Hoehle scheint normales Eis zu "+
  "sein, auch wenn seine Farbe einen kleinen Gruenstich hat. In dieser Hin"+
  "sich bist Du aber sehr tolerant."));
  AddDetail(({"hoehle"}),BS("Oh wow! Du befindest Dich in einer Hoehle mitten "+
  "in einem Eisberg! Wer haette Das gedacht..."));
  AddDetail(({"eisberg"}),BS("Dies ist ein Eisberg, und Du befindest Dich "+
  "mitten drinnen..."));
  AddDetail(({"farbe","gruenstich"}),BS("Das Eis hat hier eine weissliche Farbe "+
  "mit einem leichten Gruenstich darin."));
  AddDetail(({"hinsicht"}),BS("Wo willst Du hinsehen?"));
  AddDetail(({"lage"}),BS("Es ist wirklich nur eine sehr duenne Lage Schnee, "+
  "und hier im Wald ist sie schon fast verschwunden."));
  AddDetail(({"kaelte"}),BS("*Bibber* Es ist wirklich ziemlich kalt hier unten."));
  AddDetail(({"wald"}),BS("Nuuun, diese kleinere Annsammlung verkrueppelter "+
  "Baeume (die natuerlich nicht wirklich verkrueppelt sind) kann man kaum "+
  "einen 'Wald' nennen. Eher ... aehm ... eine Ansammlung falsch gewachsener "+
  "Baeume."));
  AddDetail(({"ansammlung"}),BS("Soo viele Baeume sind das nicht ..."));
  AddDetail(({"baum","baeume"}),BS("Die Baeume in dieser Hoehle sind schwarz "+
  "und wachsen, ihrem eigenen, verdrehten Richtungssinn folgend, wild in der "+
  "Gegend umher. Ihre Blaetter sind klein, schwarz und dick. Ausserdem sind "+
  "sie mit einem feinen Film einer Fluessigkeit bedeckt. Die Rinde der Baeume "+
  "scheint steinhart zu sein."));
  AddDetail(({"schwarz"}),BS("SCHWARZ. Naja, oder zumindest ein ziemlich du"+
  "nkles Grau."));
  AddDetail(({"grau"}),BS("OK, aber es ist ein sehr dunkles Grau!"));
  AddDetail(({"richtungssinn"}),BS("Der Richtungssinn dieser Baeume scheint "+
  "durch irgend etwas gestoert zu werden. Vielleicht ist es die fehlende "+
  "Sonne hier unten..."));
  AddDetail(({"sonne"}),BS("Hier siehst Du keine Sonne."));
  AddDetail(({"licht"}),BS("Diffuses, halbdunkles Licht leuchtet durch das "+
  "Eis zu Dir herab"));
  AddDetail(({"gegend"}),BS("Diese 'Gegend' ist eine Hoehle innerhalb eines "+
  "Eisbergs!"));
  AddDetail(({"blaetter"}),BS("Sie sind klein und dick und mit einer Flue"+
  "ssigkeit bedeckt."));
  AddSpecialDetail(({"film","fluessigkeit"}),"de_aetzend");
  AddDetail(({"feuer"}),BS("Hier brennts nicht. Vertrau mir."));
  AddDetail(({"rinde"}),BS("Die Rinde ist schwarz, geriffelt und steinhart. "+
  "Damit kann man wirklich nichts anfangen."));
  AddDetail(({"schnee"}),BS("Der Schnee ist aufgeweicht und matschig."));
  AddDetail(({"spaziergang"}),BS("Was fuer ein merkwuerdiger Ort fuer einen "+
  "Spaziergang!"));
  AddDetail(({"ort"}),BS("Du befindest Dich in einem Eisberg!"));
  AddDetail(({"wurzeln","naehrstoffe"}),BS("Mit diesen starken schwarzen "+
  "Wurzeln saugen sich die Baeume das Wasser und die Naehrstoffe aus dem "+
  "Boden, die sie brauchen. Obwohl Du Dir nicht vorstellen kannst, was es "+
  "in diesem Boden fuer Naehrstoffe geben koennte. Schliesslich ist das "+
  "Eis!"));
  AddDetail(({"gestruepp","unterholz","dorniges gestruepp"}),
  BS("Das Unterholz besteht hier aus schwarzem, dornigen Gestruepp. "+
  "Es ist gummiartig und kaum zu zerreissen. Seine Dornen jedoch sind "+
  "hart und schmerzhaft. Vom Pfad abzuweichen duerfte schwierig sein. "+
  "Durch dieses Unterholz kann sich sicherlich nicht mal ein Hobbit zwaengen."));
  AddDetail(({"hobbit","hobbits"}),BS("Hobbits sind sooooo keiiiin ... und "+
  "sueeeeeeeeeeeesss!"));
  AddSpecialDetail(({"dornen"}),"de_dornen");
  AddDetail(({"weg","pfad"}),BS("Der Weg wurde mit Kies gestreut und ist "+
  "somit relativ befestigt. Suedlich, hinter Dir, fuehrt er als kaum "+
  "ausgetretener Pfad den Abhang hinauf. Nach Nordwesten fuehrt er weiter "+
  "in den Wald (naja, die Ansammlung von Baeumen) hinein."));
  AddDetail(({"abhang"}),BS("Er fuehrt suedlich von Dir hinauf zu den "+
  "Gaengen, durch die Du diesen Eisberg verlassen kannst."));
  AddDetail(({"gaenge"}),BS("Die Gaenge im Sueden fuehren aus dem Eisberg "+
  "hinaus."));
  AddDetail(({"wirklichkeit"}),BS("Die Wirklichkeit ist eine Sache der "+
  "individuellen Wahrnehmung. Ich dachte, Du wuesstest das."));
  AddDetail(({"wahrnehmung"}),BS("Die eigene Wahrnehmung definiert die "+
  "eigene Sicht der Wirklichkeit, die Realitaet."));
  AddDetail(({"sicht"}),BS("Die Sicht der Wirklichkeit ist fuer zwei "+
  "Personen niemals gleich. Wir sind alle verschieden. Und das macht die "+
  "Sache gerade so spannend."));
  AddDetail(({"personen"}),BS("Na, Personen wie ich und Du."));
  AddDetail(({"sache"}),BS("Nein, wir reden hier nicht ueber Sex."));
  AddDetail(({"sex"}),BS("Huuuuuuuh. Aehm, nein. Sex ist keine Loesung."));
  AddDetail(({"loesung"}),BS("Frag mich nicht, was die Loesung ist, aber "+
  "Sex ist es nicht."));
  AddDetail(({"realitaet"}),BS("Die Realitaet ist die Wirklichkeit, welche "+
  "am haertesten ist. Damit musst Du leben. Werd einfach damit fertig."));
  AddDetail(({"hoehe"}),BS("Diese Hoehle ist verdammt hoch. Da koennten "+
  "die Baeume schon wirklich hoch wachsen. Das tun sie aber nicht, wohl "+
  "wegen der fehlenden Sonne."));
  AddDetail(({"zickzack","heu"}),BS("ZickeZacke ZickeZacke Heu Heu Heu."));
  AddDetail(({"art"}),BS("Yeah, this is true art."));
  AddDetail(({"kies"}),BS("Das ist ganz normaler Kies. Nicht besonderes "+
  "dabei."));
  AddDetail(({"waende"}),BS("Hier gibt es keine Waende."));
  AddDetail(({"decke","gewoelbe"}),BS("Die Decke dieser Hoehle ist derart "+
  "hoch, dass Du sie von hier unten nur als leichtes, helles Schimmer "+
  "wahrnimmst."));
  AddDetail(({"schimmern"}),BS("Das Licht, Elwood! Siehst Du das Licht???"));
  AddDetail(({"licht","elwood"}),BS("Aeeeeeeeeeehm, vergeessen wirs."));
  AddDetail(({"wind"}),BS("Es ist windig hier. Nicht so windig wie oben "+
  "auf dem Abhang, doch immernoch windig."));
  AddDetail(({"regen","nieselregen"}),BS("Huuh, das ist kein Nieselregen, "+
  "das ist Schmelzwasser, welches von der Decke tropft. Ob das ein gutes "+
  "Zeichen ist?"));
  AddDetail(({"zeichen"}),BS("Nein."));
  AddDetail(({"schmelzwasser"}),BS("Es tropft von der Decke dieser Hoehle!"));
  
  AddSmells(SENSE_DEFAULT,BS("Es riecht hier relativ scharf und nach Saeure."));
  AddSmells("saeure",BS("Das stinkt schon so langsam..."));
  AddSounds(SENSE_DEFAULT,BS("Der Wind pfeift durch die Baeume."));
  AddSpecialExit("oben","ex_oben");
  AddSpecialExit("nordwesten","ex_nordwesten");
  AddCmd(({"zwaeng","zwaenge"}),"zwaenge");
  
  call_other(CHAOS_GILDEN_ROOM("cl2w4"),"???");
  call_other(CHAOS_GILDEN_ROOM("cl2w5"),"???");  
  AddItem(CHAOS_GILDEN_MON("cl2_kopka"),REFRESH_DESTRUCT,
          (["chaos_guard":"nordwesten",
            "chaos_guard_money":500,
            "chaos_guard_msg":"Kopka haelt Dich auf sagt: Ah Ah Ah. Erst mal "+
            "Wegezoll zahlen, ok?\n"]));
   
}


string de_aetzend()
{
  this_player()->reduce_hit_point(random(5));
  return "AUTSCH! Diese Fluessigkeit brennt wie Feuer!\n";
}

string de_dornen()
{
   this_player()->reduce_hit_point(random(5));
   return "Die Dornen stechen schmerzhaft. Dein Daumen brennt wie Feuer!\n";
}

int ex_nordwesten()
{
   object ob;
   if (ob=this_player()->QueryEnemy())
   {
     write(ob->Name(WER)+" laesst Dich einfach nicht durch!\n");
     return 1;
   }
   tell_room(CHAOS_GILDEN_ROOM("cl2w4"),this_player()->Name(WER)+
   " verschwindet auf dem Pfad nach Nordwesten\n");
   tell_room(CHAOS_GILDEN_ROOM("cl2w5"),this_player()->Name(WER)+
   " verschwindet auf dem Pfad nach Nordwesten\n");
   
   this_player()->move(CHAOS_GILDEN_ROOM("cl2w3"),M_GO,"nach Nordwesten");
   return 1;
}

int ex_oben()
{
   tell_room(CHAOS_GILDEN_ROOM("cl2w4"),this_player()->Name(WER)+
   " verschwindet in Richtung Abhang.\n");
   tell_room(CHAOS_GILDEN_ROOM("cl2w5"),this_player()->Name(WER)+
   " verschwindet in Richtung Abhang.\n");
   
   this_player()->move(CHAOS_GILDEN_ROOM("cl2w1"),M_GO,"nach Oben");
   return 1;
}

int zwaenge(string was) {

    string dummy;
    notify_fail("So geht das nicht...\n");
    if (!was) return 0;
    if (was == "durch buesche" || was == "durch gebuesch" || 
        was == "durch unterholz")
    {
      notify_fail("So einfach geht das nicht. Wohin willst Du Dich denn "+
      "durch die Buesche zwaengen?\n");
      return 0;
    }
    if (sscanf(was,"durch %s nach %s",dummy,was)<2) return 0;
    
    if (was == "westen")
    {
      write("Du zwaengst Dich durch die Buesche nach Westen.\n");
      this_player()->move(CHAOS_GILDEN_ROOM("cl2w4"),M_GO,"durch das Unterholz");
      return 1;
    }
    if (was == "norden")
    {
      write("Du zwaengst Dich durch die Buesche nach Norden.\n");
      this_player()->move(CHAOS_GILDEN_ROOM("cl2w5"),M_GO,"durch das Unterholz");
      return 1;
    }
    write("Das Unterholz scheint undurchdringlich.\n");
    return 1;
}