// dets.c - Gemeinsame Details und die Chaosmagie der Burg Zwielichtstein
//
// Erbt nichts. Die Std-Räume erben diese Datei zusätzlich, rufen
// "*"::create() auf und in reset() bzw. init() chaos_reset() und
// chaos_init().
//
// Chaosmagie (Häufigkeiten in sys/chaosburg.h):
//   - Bei jedem Reset bekommt der Raum vielleicht eine wechselnde Zeile
//     (eigene aus P_CHAOS_VARIANTEN oder allgemeine).
//   - Wer den Raum betritt, dem passiert manchmal etwas Seltsames,
//     Harmloses.
//   - Selten schlägt ein Chaosblitz ein und hinterlässt einen
//     Chaoswicht.
//   - Versperrte Ausgänge: AddExit(richtung, ([EX_DEST: ...,
//     EX_FUNC: "versperrt"])), Text in P_CHAOS_VERSPERRT.
//
// Letzte Aenderung:
//
// 27.11.2026 It@Efferdland            neu
// 27.11.2026 It@Efferdland            Chaosmagie
// 27.11.2026 It@Efferdland            Chaoten wohnen hier

#pragma strong_types
#pragma no_clone
#pragma save_types
#pragma rtt_checks
#pragma range_check

#include "def.h"

// Der Langtext ohne wechselnde Zeile
static string chaos_grundtext;

// Wechselnde Zeilen, die in jeden Raum passen
static string *chaos_allgemein = ({
  "Die Wände flimmern unruhig, als könnten sie sich nicht entscheiden, "
  "ob sie da sein wollen.",
  "Ein feiner, violetter Staub schwebt in der Luft und sinkt nicht zu "
  "Boden.",
  "Für einen Augenblick wirft nichts hier einen Schatten.",
  "Irgendwo tropft es, aber die Tropfen fallen nach oben.",
  "Die Steine sind heute warm, als hätten sie Fieber.",
  "Ein schwacher Geruch nach Gewitter liegt in der Luft.",
  "Auf dem Boden hat jemand mit Kreide ein Pentagramm gezeichnet und "
  "dann mit dem Fuß halb wieder weggewischt.",
  "An der Wand klebt ein Zettel: »Wer hat meinen Dämon gesehen? Klein, "
  "rot, beißt. Belohnung!«",
  "In einer Ecke liegt eine angekokelte Robe, die niemand vermisst.",
  "Frische Kratzspuren ziehen sich über den Boden, als hätte hier etwas "
  "mit Krallen gespielt.",
});

// Setzt den Langtext. Die wechselnde Zeile wird bei jedem Reset
// angehängt.
public void chaos_long(string txt) {
  chaos_grundtext = txt;
  ME->SetProp(P_INT_LONG,txt);
}

public void chaos_reset() {
  string *v;

  if(!stringp(chaos_grundtext)) {
    return;
  }
  if(random(100) >= CHAOS_VARIANTE_CHANCE) {
    ME->SetProp(P_INT_LONG,chaos_grundtext);
    return;
  }
  v = ME->QueryProp(P_CHAOS_VARIANTEN);

  if(!pointerp(v) || !sizeof(v) || !random(3)) {
    v = chaos_allgemein;
  }
  ME->SetProp(P_INT_LONG,chaos_grundtext+" "+v[random(sizeof(v))]);
}

// EX_FUNC für eingestürzte und versperrte Ausgänge
public int versperrt(string verb, object pl) {
  mapping m = ME->QueryProp(P_CHAOS_VERSPERRT) || ([]);

  tell_object(pl,break_string(m[verb] ||
    "Dort ist alles eingestürzt. Da kommst du nicht weiter."));
  return 0;
}

// Etwas Seltsames, aber Harmloses passiert dem Spieler
static void chaos_effekt(object pl) {
  object *obs;
  string n;

  if(!objectp(pl) || environment(pl) != ME) {
    return;
  }
  switch(random(7)) {
    case 0:
      tell_object(pl,break_string("Dein Schatten löst sich von dir, läuft "
        "ein paar Schritte in die falsche Richtung und kehrt dann "
        "verlegen zu dir zurück."));
      tell_room(ME,break_string("Der Schatten von "+pl->name(WEM,1)+
        " macht sich kurz selbstständig."),({pl}));
      break;
    case 1:
      n = capitalize(lower_case(pl->name(RAW)||"Fremder"));
      n = capitalize(lower_case(reverse(n)));
      tell_object(pl,break_string("Ein Echo ruft deinen Namen, aber "
        "rückwärts: »"+n+"«."));
      break;
    case 2:
      tell_object(pl,break_string("Für einen Augenblick kippt die "
        "Schwerkraft zur Seite. Du taumelst, dann ist alles wieder wie "
        "vorher."));
      tell_room(ME,break_string(pl->Name(WER,1)+" taumelt plötzlich, "
        "als würde der Boden schief stehen."),({pl}));
      break;
    case 3:
      tell_object(pl,break_string("Deine Haare stellen sich knisternd auf "
        "und glimmen violett. Dann legen sie sich wieder."));
      tell_room(ME,break_string("Die Haare von "+pl->name(WEM,1)+
        " stehen plötzlich knisternd zu Berge und glimmen violett."),
        ({pl}));
      break;
    case 4:
      obs = filter(all_inventory(ME),(: !living($1) && $1->short() :));

      if(sizeof(obs)) {
        tell_room(ME,break_string(obs[0]->Name(WER,1)+" schwebt "
          "plötzlich eine Handbreit in die Höhe und plumpst wieder "
          "herunter."));
        break;
      }
      // Kein Gegenstand da: dann eben die Farben
    case 5:
      tell_object(pl,break_string("Für einen Moment ist alles um dich "
        "herum in seltsame, verkehrte Farben getaucht."));
      break;
    default:
      tell_object(pl,break_string("Direkt neben deinem Ohr flüstert eine "
        "Stimme: »Du bist nicht der Erste.« Als du dich umdrehst, ist "
        "niemand da."));
      break;
  }
}

public void chaos_init() {
  int effekt  = CHAOS_EFFEKT_CHANCE;
  int ausbruch = CHAOS_AUSBRUCH_CHANCE;

  if(!this_player() || !interactive(this_player())) {
    return;
  }
  if(ME->QueryProp(P_CHAOS_RISS)) {
    effekt   = CHAOS_RISS_EFFEKT;
    ausbruch = CHAOS_RISS_AUSBRUCH;
  }
  if(random(100) < ausbruch) {
    // Ein Chaosblitz, aus dem ein Chaoswicht entsteht
    call_out(function void() {
      object w;

      if(present_clone(CHAOS_GILDEN_MON("chaoswicht"),ME)) {
        return;
      }
      tell_room(ME,break_string("Ein violetter Blitz schlägt mit einem "
        "trockenen Knall mitten im Raum ein! Als sich der Rauch verzieht, "
        "hockt dort ein kleines, kicherndes Wesen."));
      w = clone_object(CHAOS_GILDEN_MON("chaoswicht"));
      w->move(ME,M_NOCHECK|M_SILENT);
    },2);
  }
  else if(random(100) < effekt) {
    call_out(#'chaos_effekt,1,this_player());
  }
}

protected void create() {
  ME->SetProp(P_INT_SHORT,"In der Burg Zwielichtstein");
  ME->SetProp(P_INT_LONG,"In der Burg Zwielichtstein.");

  ME->AddSpecialDetail(({"raum","umgebung","ort","stelle"}),
                       "_query_int_long");

  ME->AddDetail(({"burg","zwielichtstein","burg zwielichtstein","ruine"}),
  "Die Burg Zwielichtstein ist alt und halb verfallen. Schon lange "
  "haben sich die Chaoten darin eingenistet. Repariert haben sie nichts, "
  "aber sie wohnen darin, und das sieht man. Chaotische Magie durchzieht "
  "jeden Stein, und nichts ist hier so, wie es auf den ersten Blick "
  "scheint.");

  ME->AddDetail(({"chaoten","chaot","bewohner"}),
  "Die Chaoten wohnen hier, wie Chaoten eben wohnen: laut, unordentlich "
  "und mit vielen Brandflecken.");

  ME->AddDetail(({"brandflecken","brandfleck"}),
  "Schwarz und verkohlt. Hier ist wohl öfter etwas schiefgegangen.");

  ME->AddDetail(({"kreide","pentagramm"}),
  "Kreidestriche auf dem Boden, halb verwischt.");

  ME->AddDetail(({"striche","kreidestriche","fuss","fuß"}),
  "Verwischt. Hoffentlich hat das Pentagramm niemand mehr gebraucht.");

  ME->AddDetail(({"zettel"}),
  "Ein Zettel, eilig gekritzelt und schief angeklebt.");

  ME->AddDetail(({"daemon","dämon","belohnung"}),
  "Klein, rot, beißt. Mehr steht da nicht.");

  ME->AddDetail(({"robe","ecke"}),
  "Eine angekokelte, schwarze Robe. Sie riecht nach Schwefel.");

  ME->AddDetail(({"schwefel"}),
  "Gelb und stinkend. In der Burg riecht alles ein wenig danach.");

  ME->AddDetail(({"kratzspuren","kratzspur","krallen"}),
  "Kratzspuren, frisch und tief. Irgendetwas mit Krallen war hier.");

  ME->AddDetail(({"mauer","mauern","stein","steine","gemäuer","gemaeuer"}),
  "Die Mauern sind aus schwarzem Stein, rissig und an vielen Stellen "
  "eingestürzt. Manchmal flimmern sie seltsam, als wären sie nicht ganz "
  "da.");

  ME->AddDetail(({"riss","risse","spalt","spalten"}),
  "Durch die Risse in den Mauern sickert ein schwaches, violettes "
  "Leuchten.");

  ME->AddDetail(({"leuchten","schimmer","flimmern"}),
  "Ein violettes Leuchten, mal schwächer, mal stärker. Es kommt von der "
  "Chaosmagie, die die Burg durchzieht.");

  ME->AddDetail(({"magie","chaosmagie","chaos"}),
  "Die Chaosmagie ist überall in der Burg zu spüren. Sie kribbelt, "
  "knistert und flüstert.");

  ME->AddDetail(({"blick"}),
  "Auf den ersten Blick ist hier alles nur alt und verfallen. Auf den "
  "zweiten auch, aber irgendwie anders.");

  ME->AddDetail(({"staub","luft"}),
  "Feiner Staub, der manchmal violett glitzert.");

  ME->AddDetail(({"schatten"}),
  "Die Schatten hier benehmen sich nicht immer so, wie sie sollten.");

  ME->AddDetail(({"tropfen"}),
  "Mal fallen sie, mal steigen sie. Sie können sich nicht entscheiden.");

  ME->AddDetail(({"fieber","gewitter","augenblick"}),
  "Die Chaosmagie macht hier, was sie will.");

  ME->AddSmell(({DEFAULT_SMELL,"luft"}),
  "Es riecht nach Staub und ein wenig nach Schwefel.");

  ME->AddSmell(({"schwefel","staub"}),
  "Alt, muffig und ein wenig schweflig.");

  ME->AddSound(({DEFAULT_SOUND}),
  "Irgendwo knistert es leise, und manchmal glaubst du, ein Flüstern zu "
  "hören.");

  ME->AddSound(({"flüstern","fluestern","knistern","magie"}),
  "Es ist zu leise, um etwas zu verstehen. Vielleicht bildest du es dir "
  "auch nur ein. Vielleicht.");

  ME->AddRoomMessage(({
    "Die Mauern um dich herum flimmern fuer einen Augenblick violett.\n",
    "Aus einem Riss in der Mauer dringt ein leises Fluestern.\n",
    "Ein kalter Hauch streicht an dir vorbei, obwohl kein Wind geht.\n",
    "Fuer einen Moment scheint ein Stein in der Mauer zu atmen.\n",
    "Irgendwo in der Burg lacht jemand, hoch und schrill.\n",
    "Aus einem anderen Teil der Burg ist ein dumpfer Knall zu hoeren, "
    "dann ein lauter Fluch.\n",
    "Jemand ruft in der Ferne: \"Wer hat schon wieder meinen Daemon "
    "losgelassen?\"\n",
    "Irgendwo poltert etwas eine Treppe hinunter, gefolgt von Gekicher.\n",
    "Ein Stein loest sich aus der Mauer, schwebt kurz und faellt dann "
    "polternd zu Boden.\n",
    "Fuer einen Herzschlag laeuft die Zeit rueckwaerts. Dann wieder "
    "vorwaerts.\n",
  }),90);

  call_out(#'chaos_reset,0);
}
