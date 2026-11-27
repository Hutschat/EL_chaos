// dmaker.c - Die Räume der Burg Zwielichtstein
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu

#pragma strong_types
#pragma no_clone
#pragma no_inherit

#include "def.h"

inherit "/std/virtual/it_compiler_dmaker";

// Höhe eines Raums relativ zum Burghof
static void hoehe(object o, int diff) {
  o->SetProp(P_ENVIRONMENT,o->QueryProp(P_ENVIRONMENT)+
             ([ENV_ALTITUDE: CHAOS_BURG_HOEHE+diff]));
}

public varargs void create_room(string file, object o) {
  if(!::create_room(file,o,CHAOS_VC_BURG)) {
    return;
  }
  switch(file) {
    // Das Burgtor. Im Westen führt der Pfad hinunter ins Schattental.
    case "[+007+051+08]":
    o->SetProp(P_INT_SHORT,"Im Tor der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Du stehst im halb eingestürzten Tor der Burg Zwielichtstein. Das "
       "Fallgitter hängt verbogen und rostig über dir, ein Torflügel "
       "liegt zerborsten am Boden. Im Osten öffnet sich der Burghof, im "
       "Westen führt ein Pfad hinunter ins Schattental. Über dem Tor "
       "zucken violette Blitze.");

    o->AddDetail(({"tor","burgtor","torbogen"}),
       "Das Tor ist halb eingestürzt. Der Torbogen hält nur noch, weil "
       "die Chaosmagie es so will.");

    o->AddDetail(({"fallgitter","gitter"}),
       "Das Fallgitter hängt verbogen und rostig über dir. Hoffentlich "
       "hält es noch eine Weile.");

    o->AddDetail(({"rost"}),
       "Rotbrauner Rost frisst sich durch das alte Eisen.");

    o->AddDetail(({"eisen","weile"}),
       "Das Eisen sieht nicht mehr sehr vertrauenerweckend aus.");

    o->AddDetail(({"torfluegel","torflügel","fluegel","flügel"}),
       "Ein Torflügel liegt zerborsten am Boden, vom anderen ist nichts "
       "mehr zu sehen.");

    o->AddDetail(({"burghof","hof"}),
       "Im Osten liegt der verwilderte Burghof.");

    o->AddDetail(({"pfad"}),
       "Der Pfad führt im Westen steil hinunter ins Schattental.");

    o->AddSound(({"fallgitter","gitter"}),
       "Das Fallgitter quietscht leise im Wind.");

    o->AddExit("westen",     CHAOS_BURGPFAD);
    o->AddExit("osten",      CHAOS_GILDEN_ROOM("[+008+051+08]"));
    break;

    // Der Burghof. Von hier geht es überall hin.
    case "[+008+051+08]":
    o->SetProp(P_INT_SHORT,"Im Burghof der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Der Burghof ist verwildert und von Schutt übersät. Im Norden "
       "ragt ein schiefer Turm in den Dunst, im Osten führt ein breites "
       "Portal in den Rittersaal, und im Süden liegt die Bibliothek. Im "
       "Westen geht es durch das Tor hinaus. Mitten im Hof führt eine "
       "Treppe hinunter in den Kerker.");

    o->AddDetail(({"burghof","hof"}),
       "Der Burghof ist verwildert und voller Schutt.");

    o->AddDetail(({"schutt","truemmer","trümmer"}),
       "Überall liegen herabgefallene Steine und zerbrochene Balken.");

    o->AddDetail(({"balken"}),
       "Die Balken sind morsch und schwarz verkohlt.");

    o->AddDetail(({"turm"}),
       "Der Turm im Norden steht gefährlich schief. Ganz oben flackert "
       "violettes Licht.");

    o->AddDetail(({"licht"}),
       "Das violette Licht flackert ganz oben auf dem Turm.");

    o->AddDetail(({"portal","rittersaal"}),
       "Ein breites, rundbogiges Portal führt im Osten in den Rittersaal.");

    o->AddDetail(({"bibliothek"}),
       "Die Bibliothek liegt im Süden. Ihre Tür ist längst verschwunden.");

    o->AddDetail(({"tuer","tür"}),
       "Von der Tür der Bibliothek sind nur noch die Angeln übrig.");

    o->AddDetail(({"angeln"}),
       "Rostige Angeln, mehr nicht.");

    o->AddDetail(({"tor"}),
       "Im Westen geht es durch das Tor hinaus.");

    o->AddDetail(({"treppe","kerker"}),
       "Eine ausgetretene Treppe führt mitten im Hof hinunter in den "
       "Kerker. Von unten dringt ein Scharren herauf.");

    o->AddDetail(({"scharren"}),
       "Hören kannst du es, sehen nicht.");

    o->AddSound(({"scharren","kerker"}),
       "Als würde unten etwas kratzen.");

    o->AddExit("westen",     CHAOS_BURGTOR);
    o->AddExit("osten",      CHAOS_RITTERSAAL);
    o->AddExit("sueden",     CHAOS_GILDEN_ROOM("[+008+050+08]"));
    o->AddExit("norden",     CHAOS_GILDEN_ROOM("[+008+052+08]"));
    o->AddExit("unten",      CHAOS_GILDEN_ROOM("[+008+051+07]"));
    break;

    // Die Bibliothek mit den alten Schriften der Gilde
    case "[+008+050+08]":
    o->SetProp(P_INT_SHORT,"In der Bibliothek der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Die Bibliothek ist ein langer, staubiger Raum. An den Wänden "
       "stehen Regale voller alter Schriften, manche angesengt, manche "
       "seltsam flimmernd. Auf einem Lesepult liegt ein Verzeichnis. Im "
       "Norden geht es zurück in den Burghof.");

    o->AddDetail(({"regal","regale"}),
       "Die Regale biegen sich unter der Last der alten Schriften.");

    o->AddDetail(({"bibliothek","raum"}),
       "Ein langer, staubiger Raum voller Regale.");

    o->AddDetail(({"schriften","schrift","buecher","bücher","buch"}),
       "Alte Schriften der Gilde des Chaos. Welche es gibt, steht im "
       "Verzeichnis.");

    o->AddDetail(({"gilde"}),
       "Die Gilde des Chaos hat hier gesammelt, was sie weiß.");

    o->AddDetail(({"burghof"}),
       "Der Burghof liegt im Norden.");

    o->AddDetail(({"lesepult","pult"}),
       "Auf dem Lesepult liegt das Verzeichnis der Schriften.");

    o->AddDetail(({"verzeichnis","inhalt"}),
       "Das Verzeichnis kannst du lesen ('lies inhalt'). Die Schriften "
       "selbst liest du mit 'lies <kürzel>'.");

    o->AddDetail(({"last"}),
       "Schwer, sehr schwer.");

    o->AddSmell(({DEFAULT_SMELL,"papier"}),
       "Es riecht nach Staub, alt und muffig.");

    o->AddExit("norden",     CHAOS_GILDEN_ROOM("[+008+051+08]"));
    break;

    // Der Kerker unter dem Burghof
    case "[+008+051+07]":
    hoehe(o,-5);
    o->SetProp(P_INT_SHORT,"Im Kerker der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Der Kerker ist feucht, kalt und düster. An den Wänden reihen "
       "sich Zellen mit rostigen Gittern, hinter denen Dämonen scharren, "
       "fauchen und mit glühenden Augen hervorstarren. Eine Treppe führt "
       "hinauf in den Burghof.");

    o->SetProp(P_LIGHT,0);

    o->AddDetail(({"zelle","zellen","gitter"}),
       "Hinter den rostigen Gittern hocken gefangene Dämonen. Sie zerren "
       "an den Stäben, kommen aber nicht heraus.");

    o->AddDetail(({"daemon","dämon","daemonen","dämonen"}),
       "Die Dämonen in den Zellen fauchen dich an. Manche sind klein und "
       "flink, andere groß und wuchtig. Alle haben glühende Augen.");

    o->AddDetail(({"staebe","stäbe"}),
       "Die Stäbe sind rostig, halten aber.");

    o->AddDetail(({"augen"}),
       "Glühende Augen starren dich aus der Dunkelheit an.");

    o->AddDetail(({"dunkelheit"}),
       "Hier unten ist es fast völlig dunkel.");

    o->AddDetail(({"treppe","burghof"}),
       "Die Treppe führt hinauf in den Burghof.");

    o->AddDetail(({"kerker"}),
       "Ein feuchter, kalter Kerker voller Zellen.");

    o->AddSound(({DEFAULT_SOUND,"scharren","fauchen"}),
       "Es scharrt, faucht und kratzt unablässig.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es stinkt nach Moder und nach Schwefel.");

    o->AddSmell(({"moder"}),
       "Feucht und modrig.");

    o->AddExit("oben",       CHAOS_GILDEN_ROOM("[+008+051+08]"));
    break;

    // Der Turm, unten
    case "[+008+052+08]":
    o->SetProp(P_INT_SHORT,"Im Turm der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Du stehst im schiefen Turm der Burg. Eine Wendeltreppe "
       "windet sich an der Wand hinauf, von oben fällt flackerndes, "
       "violettes Licht herein. Im Süden geht es zurück in den Burghof.");

    o->AddDetail(({"turm"}),
       "Der Turm steht so schief, dass dir fast schwindelig wird.");

    o->AddDetail(({"burghof"}),
       "Der Burghof liegt im Süden.");

    o->AddDetail(({"wendeltreppe","treppe"}),
       "Die Wendeltreppe windet sich an der Wand hinauf. Ein paar Stufen "
       "fehlen.");

    o->AddDetail(({"stufen","stufe"}),
       "Ausgetreten und brüchig. Ein paar fehlen ganz.");

    o->AddDetail(({"licht"}),
       "Violettes Licht flackert von oben herein.");

    o->AddExit("sueden",     CHAOS_GILDEN_ROOM("[+008+051+08]"));
    o->AddExit("oben",       CHAOS_GILDEN_ROOM("[+008+052+09]"));
    break;

    // Die Turmspitze mit dem Riss, aus dem die Chaosmagie sickert
    case "[+008+052+09]":
    hoehe(o,15);
    o->SetProp(P_INT_SHORT,"Auf der Spitze des Turms");
    o->SetProp(P_INT_LONG,
       "Die Spitze des Turms hat kein Dach mehr. Mitten über der "
       "Plattform klafft ein Riss, aus dem violettes Licht und "
       "Chaosmagie sickern. Er pulsiert, als würde er atmen. Hier ist "
       "einst ein Ritual schiefgegangen. Im Westen führt ein "
       "Durchgang auf den Wehrgang, unten geht es zurück in den Turm.");

    o->SetProp(P_LIGHT,2);
    o->SetProp(P_LIGHT_TYPE,LT_MAGIC);

    o->AddDetail(({"riss"}),
       "Der Riss schwebt über der Plattform, gut mannshoch und von "
       "violettem Licht erfüllt. Wenn du hineinschaust, siehst du Dinge, "
       "die keinen Sinn ergeben, und hörst ein fernes Flüstern.");

    o->AddDetail(({"licht"}),
       "Das violette Licht pulsiert unablässig.");

    o->AddDetail(({"turm","spitze","turmspitze"}),
       "Du stehst ganz oben auf dem schiefen Turm.");

    o->AddDetail(({"fluestern","flüstern"}),
       "Hören kannst du es, sehen nicht.");

    o->AddDetail(({"plattform"}),
       "Die Plattform ist rissig und mit verblassten Zeichen bedeckt.");

    o->AddDetail(({"zeichen"}),
       "Reste eines Pentagramms und eines Bannkreises. Wer auch immer "
       "sie gezeichnet hat, hat dabei etwas falsch gemacht.");

    o->AddDetail(({"pentagramm","bannkreis"}),
       "Beide sind halb verwischt. Die Linien führen direkt unter den "
       "Riss.");

    o->AddDetail(({"linien"}),
       "Verwischt und angesengt.");

    o->AddDetail(({"ritual"}),
       "Niemand weiß, wer das Ritual gewirkt hat. Seitdem ist der Riss "
       "offen.");

    o->AddDetail(({"dach"}),
       "Vom Dach ist nichts mehr übrig.");

    o->AddDetail(({"durchgang","wehrgang"}),
       "Im Westen führt ein Durchgang auf den Wehrgang.");

    o->AddDetail(({"dinge","sinn"}),
       "Du schaust lieber nicht zu lange hinein.");

    o->AddSound(({DEFAULT_SOUND,"riss","fluestern","flüstern"}),
       "Fern und vielstimmig, kaum zu verstehen.");

    o->AddRoomMessage(({
      "Der Riss pulsiert, und violettes Licht flutet ueber die "
      "Plattform.\n",
      "Aus dem Riss dringt ein fernes, vielstimmiges Fluestern.\n",
      "Fuer einen Augenblick glaubst du, eine Klaue im Riss zu sehen.\n",
    }),45);

    o->AddExit("unten",      CHAOS_GILDEN_ROOM("[+008+052+08]"));
    o->AddExit("westen",     CHAOS_GILDEN_ROOM("[+007+052+09]"));
    break;

    // Der Wehrgang über dem Burgtor
    case "[+007+052+09]":
    hoehe(o,15);
    o->SetProp(P_INT_SHORT,"Auf dem Wehrgang der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Der Wehrgang zieht sich über dem Burgtor an der Westmauer "
       "entlang. Die Zinnen sind größtenteils abgebrochen. Von hier "
       "aus siehst du tief unten im Westen das Schattental mit dem "
       "Labyrinth der Menagerie. Im Osten geht es zurück auf die "
       "Turmspitze.");

    o->AddDetail(({"wehrgang"}),
       "Schmal und zugig.");

    o->AddDetail(({"zinnen","zinne"}),
       "Die meisten Zinnen sind abgebrochen. Lehn dich besser nicht zu "
       "weit hinaus.");

    o->AddDetail(({"westmauer"}),
       "Die Westmauer ist rissig, hält aber noch.");

    o->AddDetail(({"labyrinth","menagerie"}),
       "Tief unten im Westen windet sich das Labyrinth der Menagerie "
       "zwischen schwarzen Wänden.");

    o->AddDetail(({"waende","wände"}),
       "Von hier oben sehen die schwarzen Wände der Menagerie winzig "
       "aus.");

    o->AddDetail(({"turmspitze","turm"}),
       "Im Osten liegt die Turmspitze mit dem Riss.");

    o->AddDetail(({"burgtor","tor"}),
       "Das Burgtor liegt direkt unter dir.");

    o->AddExit("osten",      CHAOS_GILDEN_ROOM("[+008+052+09]"));
    break;

    // Der Rittersaal zwischen Burghof und Gildenhalle
    case "[+009+051+08]":
    o->SetProp(P_INT_SHORT,"Im Rittersaal der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Der Rittersaal ist groß und düster. Die Decke ist an einer Stelle "
       "eingestürzt, durch das Loch siehst du violette Blitze im Dunst. "
       "Eine lange Tafel steht umgestürzt zwischen den Trümmern. Im "
       "Osten liegt die Gildenhalle, im Westen geht es zurück in den "
       "Burghof. Eine schmale Treppe führt hinunter in die Schänke, aus "
       "der es laut und fröhlich heraufschallt.");

    o->AddDetail(({"loch"}),
       "Durch das Loch in der Decke siehst du violette Blitze im Dunst.");

    o->AddDetail(({"blitze","dunst"}),
       "Violette Blitze zucken lautlos durch den Dunst über der Burg.");

    o->AddDetail(({"tafel"}),
       "Eine lange, schwere Tafel aus schwarzem Holz, umgestürzt und "
       "zerkratzt.");

    o->AddDetail(({"holz"}),
       "Schwarzes, hartes Holz.");

    o->AddDetail(({"truemmer","trümmer"}),
       "Steine aus der eingestürzten Decke.");

    o->AddDetail(({"gildenhalle"}),
       "Im Osten liegt die Gildenhalle.");

    o->AddDetail(({"rittersaal","saal"}),
       "Ein großer, düsterer Saal.");

    o->AddDetail(({"burghof"}),
       "Der Burghof liegt im Westen.");

    o->AddDetail(({"treppe","schaenke","schänke"}),
       "Eine schmale Treppe führt hinunter in die Schänke.");

    o->AddSound(({DEFAULT_SOUND,"stimmen","gelaechter","gelächter"}),
       "Laut und fröhlich.");

    o->AddExit("westen",     CHAOS_GILDEN_ROOM("[+008+051+08]"));
    o->AddExit("osten",      CHAOS_GILDENROOM);
    o->AddExit("unten",      CHAOS_SCHAENKE);
    break;

    // Die Schänke unter dem Rittersaal
    case "[+009+051+07]":
    o->SetProp(P_INT_SHORT,"In der Schänke der Burg Zwielichtstein");
    o->SetProp(P_INT_LONG,
       "Die Schänke ist ein niedriges Gewölbe unter dem "
       "Rittersaal. Ein Feuer prasselt in einem Kamin, über dem Tresen "
       "hängt eine Speisekarte. Durch einen feinen Riss in der Wand "
       "sickert violettes Licht und färbt die Getränke seltsam bunt. Eine "
       "Treppe führt hinauf in den Rittersaal.");

    o->AddDetail(({"feuer","kamin"}),
       "Im Kamin prasselt ein Feuer, dessen Flammen manchmal violett "
       "aufflackern.");

    o->AddDetail(({"flammen"}),
       "Sie flackern gelb, rot und hin und wieder violett.");

    o->AddDetail(({"tresen","theke"}),
       "Ein alter, klebriger Tresen. Über ihm hängt die Speisekarte.");

    o->AddDetail(({"speisekarte","karte"}),
       "Die Speisekarte hängt über dem Tresen. Lies sie doch.");

    o->AddReadDetail(({"speisekarte","karte"}),"@@menue_text@@");

    o->AddDetail(({"riss","licht"}),
       "Durch einen feinen Riss in der Wand sickert violettes Licht.");

    o->AddDetail(({"getraenke","getränke"}),
       "Im violetten Licht schimmern sie in allen möglichen Farben.");

    o->AddDetail(({"farben"}),
       "Bunt. Sehr bunt.");

    o->AddDetail(({"treppe","rittersaal"}),
       "Die Treppe führt hinauf in den Rittersaal.");

    o->AddSmell(({DEFAULT_SMELL}),
       "Es riecht nach Rauch, verschüttetem Bier und ein wenig nach "
       "Schwefel.");

    o->AddSmell(({"rauch","bier"}),
       "Rauchig, schal und verschüttet.");

    o->AddDetail(({"schaenke","schänke"}),
       "Eine gemütliche, verrauchte Schänke.");

    o->AddSound(({DEFAULT_SOUND,"feuer"}),
       "Es prasselt und klirrt.");

    o->AddToMenu("Chaos-Becher",
         ({"becher","chaos-becher","chaos becher","chaos","chaosbecher"}),
         ([P_HP:28, P_SP:28, P_DRINK:2, P_ALCOHOL:10, P_BUY_VALUE:150]),
         5, "chaos_becher");

    o->AddToMenu("Riss-Schnaps",
         ({"schnaps","riss-schnaps","riss"}),
         ([P_HP:10, P_SP:60, P_DRINK:3, P_ALCOHOL:15, P_BUY_VALUE:150]),
         10,
         ({
           "Du kippst den violett schimmernden Schnaps hinunter. Er "
           "brennt im Hals und klärt den Kopf.",

           "&& kippt einen violett schimmernden Schnaps hinunter."
         }));

    o->AddToMenu("Schwefelsuppe",
         ({"suppe","schwefelsuppe"}),
         ([P_HP:60, P_SP:10, P_FOOD:8, P_BUY_VALUE:150]),
         10,
         ({
           "Du löffelst die gelbe Suppe. Sie stinkt grässlich, macht aber "
           "satt und wärmt von innen.",

           "&& löffelt eine stinkende, gelbe Suppe."
         }));

    o->AddToMenu("Kerkerbrot",
         ({"brot","kerkerbrot"}),
         ([P_HP:20, P_SP:0, P_FOOD:3, P_BUY_VALUE:30]),
         5,
         ({
           "Du kaust auf dem harten, grauen Brot herum. Es schmeckt nach "
           "nichts, aber es füllt den Magen.",

           "&& kaut auf einem harten, grauen Brot herum."
         }));

    o->AddToMenu("Fauliges Leitungswasser",
         ({"wasser","leitungswasser"}),
         ([P_HP:0, P_SP:0, P_DRINK:2, P_BUY_VALUE:5]),
         0,
         ({
           "Du trinkst das faulige Wasser. Igitt.",

           "&& trinkt fauliges Wasser und verzieht das Gesicht."
         }));

    o->AddExit("oben",       CHAOS_RITTERSAAL);
    break;
  }
}
