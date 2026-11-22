#include <properties.h>
#include <class.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl3bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_float_room",CHAOS_GILDEN_ROOM("cl2bu5"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"Im Kuppelsaal");
  SetProp(P_INT_LONG,BS("Du befindest Dich in einem grossen Saal, der sich "+
  "zu einer Kuppel ueber Dir auftuermt und Dich im ersten Moment an eine "+
  "Kirche denken laesst. Das kann natuerlich nicht sein. Von der Decke "+
  "haengen schwere Kronleuchter, verziert mit schwarzen Ketten und mit "+
  "schwarzen Kerzen bestueckt, welche ein schummriges Licht in den Saal "+
  "werfen, dass nur zu oft von sich seltsam bewegenden Schatten erfuellt ist. "+
  "Der Boden ist mit wahllos geformten Fliesen bedeckt, welche mit arkanen "+
  "Mustern bedeckt sind. In der unruhigen Duesternis seiner aeusseren Berei"+
  "che fuehren einige Durchgaenge aus dem Saal hinaus. Ansonsten sind die "+
  "Waende mit kostbaren Wandteppichen bedeckt, welche den Eindruck von Alter "+
  "und Wuerde verstaerken, den dieser Raum ausstrahlt."));
  AddDetail(({"saal","kuppelsaal"}),
    BS("Du stehst in einem grossen Kuppelsaal."));
  AddDetail(({"kuppel"}),BS("Die Kuppel tuermt sich hoch ueber Dir auf, "+
  "wohl hoeher als zehn Elfen uebereinandergestellt. Die Kuppel wird von "+
  "nichts gehalten, keine Saeulen sind zu sehen. Um so groesser ist Deine "+
  "Begeisterung fuer dieses architektonische Wunder. Von der Decke haengen "+
  "einige schwere, grosse Kronleuchter, deren schwarze Kerzen den Raum mit "+
  "einer daemmrigen Duesternis erfuellen. Eine merkwuerdige Bemalung bedeckt "+
  "die gesamte Kuppel."));
  AddDetail(({"elfen","elf"}),BS("Elfen sind schon ziemlich hoch, muss man "+
  "neidlos anerkennen."));
  AddDetail(({"saeulen"}),BS("Hier siehst Du keine Saeulen."));
  AddDetail(({"begeisterung"}),BS("Wow, ist das cool hier!"));
  AddDetail(({"wunder","architektonisches wunder"}),BS("Jemand singt: "+
  "Wunder, gibt es immer wieder, heute oder morgen..."));
  AddDetail(({"jemand"}),BS("Jemand hoert auf zu singen."));
  AddDetail(({"leuchter","kronleuchter"}),BS("Die Kronleuchter sind ziemlich "+
  "gross und wiegen bestimmt eine ganze Menge. Es sind Konstruktionen aus "+
  "schwarzem Stahl, besetzt mit schwarzen Kerzen. Ein kaltes, schwarzes "+
  "Gebilde, welches hierher zu passen scheint."));
  AddDetail(({"gebilde","konstruktion","konstruktionen"}),
  BS("Diese Kronleuchter sind wirklich aeusserst beeindruckend."));
  AddDetail(({"menge"}),BS("Diese Kronleuchter wiegen wirklich viel."));
  AddDetail(({"stahl"}),BS("Es sind schwere, wuchtige Kronleuchter aus schwar"+
  "zem Stahl. Sie sind weder elegant noch schoen, doch in irgend einer Weise "+
  "passend."));
  AddDetail(({"weise"}),BS("Ja, ich bin weise. Schoen das Du das weisst."));
  AddDetail(({"finsternis","duesternis"}),BS("Die schwarzen Kerzen erfuellen "+
  "den Raum mit einer merkwuerdigen, drohenden Duesternis. Schwarze Schatten "+
  "ziehen zuckend durch den Raum und lassen Schauer an Dir herablaufen."));
  AddDetail(({"schauer"}),BS("Schauer ueber Schauer erfassen Dich."));
  AddDetail(({"kirche"}),BS("Du befindest Dich nicht in einer Kirche. Wirklich "+
  "nicht. Soviel ist sicher."));
  AddDetail(({"decke"}),BS("Die Decke ist eine grosse Kuppel, welche sich hoch "+
  "ueber Dir woelbt."));
  AddDetail(({"kerzen"}),BS("Die Kerzen sind schwarz und verbreiten nur wenig "+
  "Licht. Sie sehen aus wie die Ritualkerzen, welche man bei boesartigen "+
  "Beschwoerungen verwendet. Seltsamerweise scheinen sie nicht niederzubrennen."));
  AddDetail(({"ritualkerzen"}),BS("Ritualkerzen sind bei boesartigen Beschwoer"+
  "ungen absolut unerlaesslich. Sie sind dort quasi das A und O. Ohne derartige "+
  "Kerzen gehen selbst die uebelsten Beschwoerungen nur als wilde Folklore "+
  "durch."));
  AddDetail(({"folklore"}),BS("*Lach* Nein, ich sing jetzt nicht."));
  AddDetail(({"a","o"}),BS("Du untersuchst aber auch alles *lach*."));
  AddDetail(({"beschwoerung","beschwoerungen"}),BS("Ein Chaot *lebt* fuer der"+
  "artige boesartige Beschwoerungen. Sie sind sein Lebensinhalt, sie sind "+
  "seine Berufung!"));
  AddDetail(({"lebensinhalt","berufung"}),BS("Die Berufung eines Chaoten "+
  "sind finstere Beschwoerungen abgrundtief boesartiger Daemonen. Nun, eigent"+
  "lich ist das nicht die Berufung eines Chaoten. Die Berufung ist, mit "+
  "diesen Daemonen moeglichst viel Chaos und Zerstoerung anzurichten."));
  AddDetail(({"chaos","zerstoerung"}),BS("Chaos und Zerstoerung sind das "+
  "absolut sinnvollste, was es gibt. Denn ohne Chaos, was waere da schon? "+
  "Ordnung! Wie oede!"));
  AddDetail(({"leben","chaot"}),BS("Das Leben eines Chaoten ist spannend, "+
  "aufregend und abwechslungsreich!"));
  AddDetail(({"ordnung"}),BS("Ieeeeeeeeeeh."));
  AddDetail(({"licht","schatten"}),BS("Licht und Schatten scheinen sich hier "+
  "zu bewegen, sich zu jagen, ein merkwuerdiges, finsteres Spiel miteinander "+
  "zu treiben, dessen Regeln Dir unbekannt sind. Wie merkwuerdig."));
  AddDetail(({"spiel","regeln"}),BS("Die kennst die Regeln des Spiels nicht. "+
  "Wenn es wirklich ein Spiel ist."));
  AddDetail(({"boden"}),BS("Der Boden ist mit Fliesen bedeckt. Diese Fliesen "+
  "sind jedoch mal gross mal klein, von verschiedenster Form und sehen eher "+
  "aus wie Scherben als Fliesen. Der Boden ist auch keineswegs eben. Er kann "+
  "leicht zur Stolperfalle werden. Mal geht es auf, mal ab. Wie merkwuerdig."));
  AddDetail(({"form"}),BS("Die dieser Fliesen erinnert wirklich stark an die "+
  "von Scherben, besonders wegen ihrer verschiedenen Form. Keine Fliese sieht "+
  "aus wie die andere."));
  AddSpecialDetail(({"bemalung"}),"det_bemalung");
  AddDetail(({"scherben","fliesen","fliese"}),BS("Es sind schon merkwuerdige Fliesen, "+
  "welche hier herumliegen. Sie sind saemtlichst bemalt mit merkwuerdigen "+
  "Mustern. Du wirst aus ihnen aber nicht so recht schlau."));
  AddDetail(({"muster"}),BS("Die einzelnen Muster scheinen zusammen zu passen. "+
  "Du weisst aber nicht genau wie. Irgendwie fehlt Dir hier der Ueberblick. "+
  "Hmmm..."));
  AddDetail(({"ueberblick"}),BS("Ueberblick. Hmmm...."));
  AddSpecialDetail(({"falle","stolperfalle"}),"det_falle");
  AddDetail(({"chaoten"}),BS("Chaoten sind immernoch die besten! :)"));
  AddDetail(({"durchgaenge"}),BS("Sie fuehren in verschiedene Richtungen. "+
  "Schon sehr frueh werden sie von der Dunkelheit verschluckt. Wohin sollst "+
  "Du Dich nur wenden?"));
  AddDetail(({"richtungen"}),BS("Na, da gibt es jetzt einige zur Auswahl."));
  AddDetail(({"auswahl"}),BS("Die Auswahl ist gross."));
  AddDetail(({"gehirn"}),BS("*Knot Knot*"));
  AddDetail(({"farbtoene"}),BS("Die Farbtoene sind roetlich oder fast "+
  "schwarz, jedoch ausnahmslos grell und unangenehm."));
  AddDetail(({"daemon","daemonen"}),BS("Daemonen sind die absolut boesartigs"+
  "ten Kreaturen, welche es geben kann. Sie sind das absolut Boese, sind "+
  "wirklich absolut fuerchterlich fies."));
  AddDetail(({"boeses"}),BS("Und was genau?"));
  AddDetail(({"kreaturen"}),BS("Du meinst die Daemonen, nicht?"));
  AddDetail(({"raum"}),BS("Das ist kein Raum, das ist ein Saal."));
  AddDetail(({"bereiche"}),BS("In den aeusseren Bereichen dieses Saals wird "+
  "e dann doch zeimlich duster."));
  AddDetail(({"wand","waende"}),BS("Die Waende sind schwarz und bestehen "+
  "aus gewaltigen, kalten Steinen. Diese Steine jedoch bedecken sehr viele "+
  " Wandteppiche, auf welchen diverse Szenen dargestellt werden. Entdecker "+
  "der Du bist, schaust Du vorsichtig hinter alle Wandteppiche, um etwaige "+
  "Geheimtueren zu entdecken. Leider bleibt Deine Suche jedoch erfolglos."));
  AddDetail(({"steine"}),BS("Die Steine sind schwarz, aehnlich den Steinen "+
  "der oberen Burg. Dennoch wirken sie auf subtile Weise anders, als wuerde "+
  "es den Steinen hier nicht mehr darum gehen, Kaelte und Finsternis auszu"+
  "strahlen. Es scheint, als ob die Steine hier friedlicher waeren, als ob "+
  "sie hier hingehoerten. Das ist natuerlich Dummfug."));
  AddDetail(({"burg"}),BS("Du befindest Dich unterhalb der Burg."));
  AddDetail(({"kaelte","finsternis"}),BS("Die Steine strahlen natuerlich "+
  "noch immer Kaelte und Finsternis aus, aber auf eine andere, nettere "+
  "Weise. Nein, nicht netter. Auf eine andere Weise."));
  AddDetail(({"dummfug","unfug"}),BS("Dummfug ist noch schlimmer als Unfug."));
  AddDetail(({"wandteppiche","wandteppich"}),
  BS("Die Wandteppiche sind dick und doch fein "+
  "gearbeitet. Es gibt jede Menge von ihnen. Meistens werden irgendwelche "+
  "merkwuerdigen Szenen auf ihnen dargestellt. Der Kuenstler, welcher diese "+
  "Teppiche einst herstellte, hatte wohl jede Menge roter Faeden zur "+
  "Verfuegung. Oder er hatte eine grosse Schwaeche fuer Rot."));
  AddDetail(({"faeden"}),BS("Ein Wandteppich bsteht aus einer grossen Menge "+
  "von bunten Faeden."));
  AddDetail(({"kuenstler"}),BS("Du fragst Dich wirklich, was das fuer "+
  "Kuenstler sind, welche Kunstwerke fuer die Chaosgilde schaffen."));
  AddDetail(({"kunstwerke","kunstwerk"}),
  BS("Nimm Wandteppiche! Oder die Bemalung der "+
  "Kuppel! Selbst die Anordnung der Fliesen ist ein Kunstwerk, auch wenn "+
  "Du es von hier aus nicht so richtig wuerdigen kannst..."));
  AddDetail(({"anordnung"}),BS("Hmmmmmmm......."));
  AddDetail(({"szene","szenen"}),BS("Meistens geht es in diesen Szenen um "+
  "Foltern, Toeten, Zerstueckeln und aehnliches. Du entdeckst aber auch "+
  "einige wirklich haessliche Darstellungen einiger Daemonen."));
  AddDetail(({"foltern","toeten","zerstueckeln"}),BS("Bitte nicht hier. "+
  "Den Dreck kriegt man so schlecht aus den Wandteppichen raus."));
  AddDetail(({"dreck"}),BS("Hier ist alles sauber! Ehrlich!"));
  AddDetail(({"darstellungen"}),BS("*Brrr*. Was fuer haessliche Daemonen. "+
  "Sowas wuerdest DU nicht beschwoeren. Wie ekelhaft."));
  AddDetail(({"chaosgilde"}),BS("Du befindest Dich unter der schwarzen "+
  "Burg, welche die Chaosgilde darstellt."));
  AddDetail(({"alter","wuerde"}),BS("Dieser Raum strahlt mit seinen Kronleuchtern, "+
  "Fliesen und Wandteppichen wirklich ein gewisses Alter und eine gewisse "+
  "Wuerde aus."));
  AddDetail(({"dunkelheit"}),BS("Die schwarzen Kerzen verbreiten nur un"+
  "genuegend Licht, um diesen Raum hier erhellen zu koennen."));
  AddDetail(({"entdecker"}),BS("Was es hier nicht alles zu entdecken gibt? "+
  "Du kannst es kaum erwarten! Naja, aber andererseits entdeckt man auch "+
  "relativ schnell seinen eigenen Tod, zerhackt von ein teuflischen Falle. "+
  "Also geht man ganz vorsichtig vor."));
  AddDetail(({"tod"}),BS("Tooooood..."));
  AddDetail(({"falle","fallen"}),BS("Nimm Dich hier stehts in Acht vor Fallen."));
  AddDetail(({"acht"}),BS("Ok, hast Du untersucht."));
  AddDetail(({"geheimtueren"}),BS("Natuerlich kannst Du so keine entdecken. "+
  "Sonst waeren es ja keine Geheimtueren."));
  AddDetail(({"gemaelde"}),BS("Du meinst die Bemalung der Kuppel. Also unter"+
  "such auch die, und keine nicht vorhandenen Gemaelde. Ich kann auch un"+
  "gemuetlich werden, jawohl."));
  AddDetail(({"ketten"}),BS("An den Kronleuchtern sind schwarze Ketten "+
  "aus Stahl angebracht, welche irgendwie zum Ambiente dieses Raumes passen."));
  AddDetail(({"ambiente"}),BS("Es ist ein erstaunliches Ambiente. Es ist "+
  "keinesfalls schoen, aber erstaunlich und beeindruckend."));
  AddDetail(({"eindruck"}),BS("Dieser Raum hat wirklich einen bleibenden "+
  "Eindruck in Dir hinterlassen."));
  AddDetail(({"knoten"}),BS("Ieks! Das tut ja weh!"));
  AddDetail(({"komposition"}),BS("Der Kuenstler, welcher diese Bemalung "+
  "erschaffen hat, war entweder nicht menschlich oder vollkommen wahnsinnig."));
  AddDetail(({"laenge"}),BS("Wow, bist Du lang :)"));
  AddDetail(({"moment"}),BS("Ist vorbei."));
  AddDetail(({"rot"}),BS("Hier gibt es richtig viel Rot, da hast Du durchaus "+
  "recht."));
  AddDetail(({"schwaeche"}),BS("Ich werde mich hier nicht ueber Schwaechen "+
  "von Kuenstlern auslassen."));
  AddDetail(({"teppiche"}),BS("Es sind Wandteppiche."));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  
  AddCmd(({"knot","knote","binde","bind"}),"binde_seil");
  AddCmd(({"werfe","wirf"}),"wirf_seil");
  
  AddExit("suedwesten",CHAOS_GILDEN_ROOM("cl3bu2"));
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl3bu6"));
  AddExit("osten",CHAOS_GILDEN_ROOM("cl3bu7"));
  
  
}


int binde_seil(string was) {
  if (was != "seil an kronleuchter" && was != "seil an leuchter" &&
      was != "seil an kette" && was != "seil an ketten")
      return notify_fail("Wo moechtest Du ein Seil drann binden?\n"),0;
  if (!present("seil",this_player()))
    return write("Du hast doch garkein Seil!\n"),1;
  write(BS("Das ist aber wirklich viel zu hoch fuer Dich. Da musst Du Dir "+
  "schon mal was anderes einfallen lassen."));
  return 1;
}

int wirf_seil(string was) {
  if (!was) return 0;
  if (was == "seil an kronleuchter" || was == "seil an leuchter" || 
      was == "seil um ketten" || was == "seil nach kronleuchter") {
      if (!present("seil",this_player()))
        return write("Aber Du hast doch garkein Seil!\n"),1;
      write(BS("Du wirfst, aber das Seil fliegt laengst nicht weit genug. "+
      "Da musst Du Dir schon was anderes einfallen lassen."));
      say(this_player()->Name(WER)+" wirft ein Seil in die Luft.\n",
          this_player());
      return 1;
  }
  return 0;
}
string det_bemalung() {
  if (this_player()->QueryProp(P_RACE) != "daemon")
    return BS("Es ist eine merkwuerdige Bemalung, eine unharmonische "+
    "Komposition schriller roter und schwarzer Farbtoene, welche Dein "+
    "Gehirn zum Knoten bringen. Man muss wohl Daemon sein, um in diesem "+
    "Gemaelde etwas erkennen zu koennen.");
  return BS("Wow, you're Daemon. This Detail isn't implemented yet for your kind. "+
  "Please mail feuerwehr for further implementations.");
}

string det_falle() {
   say(this_player()->Name(WER)+" faellt der Laenge nach auf den Boden.\n",
   this_player());
   return "Waaaaah! *Plaetsch!* Du faellst der Laenge nach hin.\n";
}

init() {
  ::init();
  if (this_player() && this_player()->is_class_member(CL_DEMON) &&
      !this_player()->QueryProp("chaos_cl3decke") &&
      find_call_out("decke_schaun")==-1)
    call_out("decke_schaun",2,this_player());
}

decke_schaun(object wer) {
  if (wer && environment(wer) == this_object()) {
    tell_room(this_object(),wer->Name(WER)+
              " schaut bewundernd zur Decke hoch.\n",({wer}));
     tell_object(wer,"Du schaust bewundernd die Bemalung "+
                    "der Decke an. Welch Meisterwerk.\n");
     wer->SetProp("chaos_cl3decke",1);
  }
}

    