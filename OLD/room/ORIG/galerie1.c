// Sting/Galerie-Raum 1
// -----------------------------------

#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
        ::create();

        SetProp( P_INT_SHORT, "Ein Raum der 'Daemonischen Galerie'" );
        SetProp( P_INT_LONG, BS("Du stehst im ersten Raum der daemonischen "+
                 "Galerie. Der gesamte Raum ist mit Teppichen verkleidet, "+
                 "ein riesiger schwarzer Teppich bedeckt den "+
                 "Boden, und an den Waenden haengt links und rechts je "+
                 "ein Wandteppich. Dazwischen haengen zahlreiche Gemaelde, "+
                 "die einem Feigling das Gruseln lehren wuerden. An der "+
                 "Decke ist ein riesiges Pentagramm, erstaunlich, wie das "+
                 "wohl dahin gekommen ist. In den Ecken steht jeweils "+
                 "ein Kerzenstaender, der den Raum beleuchtet. Uebrigens "+
                 "kann man von hier aus auch den unten liegenden Saal "+
                 "erkennen.",78));

        SetProp( P_LIGHT, 1);
        SetProp( P_INDOORS, 1);



        AddDetail( ({ "boden" }), BS(
	         "Der Boden ist komplett mit einem riesigen, schwarzen "+
                 "Teppich ausgekleidet.",78));
        AddDetail( ({ "teppich" }), BS(
	         "Meinst du den schwarzen Teppich, oder einen der "+
                 "Wandteppiche?",78));
        AddDetail( ({ "schwarzer teppich" }), BS(
	         "Der schwarze Teppich auf dem Boden ist einfach nur "+
                 "schwarz, aber ein so tieeeeeeefes Schwarz, das es "+
                 "einen regelrecht zu verschlucken scheint...",78));
        AddDetail( ({ "schwarz" }), BS(
	         "Das ist das schwaerzeste Schwarz, das du JE gesehen "+
                 "hast. (Schwarzer Humor)",78));
                 
        AddSpecialDetail( ({ "humor", "schwarzer humor" }), "det_humor");
	AddDetail( ({ "wandteppiche", "wandteppich" }), BS(
	         "Welchen meinst Du? Den linken oder den rechten?",78));
        AddDetail( ({ "linker wandteppich" }), BS(
	         "Auf dem linken Wandteppich sind zahlreiche daemonische "+
                 "Fratzen gewebt.",78));
        AddDetail( ({ "fratzen" }), BS(
	         "Die Fratzen wurden offensichtlich mit einem schwarzen "+
                 "Faden gewebt. Erstaunlich das man sie erkennt, denn der "+
                 "Hintergrund des Teppichs selber, ist ja auch "+
                 "schwarz...",78));
        AddDetail( ({ "faden" }), BS(
	         "Muss wohl magisch sein, wenn man schwarz auf schwarz "+
                 "erkennt.",78));
        AddDetail( ({ "hintergrund" }), BS(
	         "SCHWARZ, aber offensichtlich helleres Schwarz als der "+
                 "Faden",78));
        AddDetail( ({ "rechter wandteppich" }), BS(
	         "Auf dem rechten Wandteppich erkennst Du eine eisige "+
                 "Landschaft, in deren Vordergrund ein Frosch sitzt. "+
                 "Irgendwie strahlt er eine tiefe Boesartigkeit aus, "+
                 "und sie muss wirklich TIEF sein, wenn man bedenkt, "+
                 "dass das hier nur ein Wandteppich ist...",78));
        AddDetail( ({ "landschaft" }), BS(
	         "Brrrr, eisig.",78));
        AddDetail( ({ "vordergrund" }), BS(
	         "Da sitzt der Frosch.",78));
        AddDetail( ({ "boesartigkeit" }), BS(
	         "*zitter*",78));
        AddDetail( ({ "tiefe" }), BS(
	         "Unvorstellbar tief!",78));
        AddDetail( ({ "frosch" }), BS(
	         "Er scheint in allen moeglichen Farben zu schimmern, "+
                 "und auch sein Aeusseres ist recht undeutlich zu "+
                 "erkennen... Er hat einen Finger im Maul (Ihhh).",78));
        AddDetail( ({ "farben" }), BS(
	         "Alle moeglichen halt.",78));
        AddDetail( ({ "aeusseres" }), BS(
	         "Undefinierbar!",78));
        AddDetail( ({ "finger" }), BS(
	         "Ein langer, duenner, schwarzer Finger.",78));
        AddDetail( ({ "maul" }), BS(
	         "Wow, ist das haesslich!",78));
        AddDetail( ({ "kerzenstaender" }), BS(
	         "Die Kerzenstaender sind aus einem schwarzem Material, "+
                 "und auf ihnen steht jeweils eine Kerze.",78));
        AddDetail( ({ "material" }), BS(
	         "Unbekannt.",78));
        AddDetail( ({ "kerze", "kerzen" }), BS(
	         "Pechschwarz, mit einer roten Flamme.",78));
        AddDetail( ({ "flamme" }), BS(
	         "Einfach nur rot, nix besonderes.",78));
        AddDetail( ({ "saal" }), BS(
	         "Hier bitte Blick auf Saal",78));
        AddDetail( ({ "decke" }), BS(
	         "An der Decke ist ein riesiges Pentagramm, wirklich "+
                 "sehr merkwuerdig, muss wohl Micheldaemono gewesen "+
                 "sein.",78));
        AddDetail( ({ "pentagramm" }), BS(
	         "Riesig.",78));
        AddDetail( ({ "micheldaemono" }), BS(
	         "Ein hierzulande unbekannter daemonischer Kuenstler.",78));
        AddDetail( ({ "kuenstler" }), BS(
	         "Du meinst wohl Micheldaemono? Von ihm sind auch die "+
                 "ganzen Gemaelde gemalt worden.",78));
        AddDetail( ({ "farbe" }), BS(
	         "Riech doch mal.",78));
        AddDetail( ({ "gemaelde" }), BS(
	         "In diesem Raum erkennst du insgesamt 20 Gemaelde, Du "+
                 "kannst sie Dir jeweils einzeln mit 'Gemaelde 1-20' "+
                 "anschauen.",78));
        AddDetail( ({ "gemaelde 1", "feuerdaemon" }), BS(
	         "Auf dem ersten Gemaelde erkennst du einen relativ "+
                 "grossen Feuerdaemon, der offensichtlich in einem "+
                 "Raum mit irgendeinem dunklen Gestein steht.",78));
        AddDetail( ({ "raum", "gestein" }), BS(
	         "Du kannst nicht erkennen, wo das sein soll.",78));
        AddDetail( ({ "gemaelde 2" }), BS(
	         "Auf dem zweiten Gemaelde ist ein gefluegelter Daemon "+
                 "zu sehen, dessen scharfer, spitzer Schnabel dich wohl "+
                 "in Stuecke reissen koennte. Mit blitzenden Augen scheint "+
                 "er dich anzuschauen. Ausserdem erkennst du das Wort "+
                 "'Bknor' darunter.",78));
        AddDetail( ({ "daemon" }), BS(
	         "Da musst du schon praeziser werden.",78));
        AddDetail( ({ "schnabel" }), BS(
	         "Der ist wirklich SEHR spitzig und SEHR scharf...",78));
        AddDetail( ({ "stuecke" }), BS(
	         "Das willst Du gar nicht so genau wissen, glaub mir.",78));


        AddDetail( ({ "bknor", "hothrog", "daedhel", "rythoth",
                      "kriik", "irkitis", "harkuhu", "chochos",
                      "kruftur",  }), BS(
	         "So heisst wohl dieser Daemon.",78));



        AddDetail( ({ "gemaelde 3" }), BS(
	         "Ein riesiger dunkler Daemon ist auf dem dritten Gemaelde "+
                 "zu erkennen. Er hat einen schwarzen Umhang sowie eine "+
                 "dunkle Ruestung an, und eine grosse Axt gezueckt.",78));
        AddDetail( ({ "umhang", "ruestung", "axt" }), BS(
	         "Kommt dir unbekannt vor. (Was aber nichts heissen "+
                 "muss...",78));
        AddDetail( ({ "gemaelde 4" }), BS(
	         "Ein kleiner, recht intelligent aussehender Daemon "+
                 "ist hier aufgemalt. Er wirkt mit seiner hohen Stirn "+
                 "und den fast roentgenartigen Augen wie jemand, der auf "+
                 "einen Blick die Staerken und Schwaechen seines Gegners "+
                 "abschaetzen kann. Zusaetzlich wurde hier noch das Wort "+
                 "'Intarbir' draufgemalt.",78));
        AddDetail( ({ "stirn" }), BS(
	         "Hoch. SEHR hoch.",78));
        AddDetail( ({ "augen" }), BS(
	         "Sie durchleuchten dich :)",78));
        AddDetail( ({ "blick" }), BS(
	         "Naja, manchmal auch auf den zweiten Blick.",78));
        AddDetail( ({ "staerken", "schwaechen", "gegner" }), BS(
	         "Also solche Dinge erklaer ich hier nicht!",78));
        AddDetail( ({ "dinge" }), BS(
	         "Dinge halt.",78));
        AddDetail( ({ "gemaelde 5" }), BS(
	         "Ein riesiger, schwarzer Drache scheinbar nur, jedoch "+
                 "glaubst du eine starke daemonische Aura zu erkennen. "+
                 "Ausserdem wirkt dieses Gemaelde sehr plastisch, fast "+
                 "so, als koennte man hineingreifen...",78));
        AddDetail( ({ "drache" }), BS(
	         "Riesig und schwarz.",78));
        AddDetail( ({ "aura" }), BS(
	         "Sie scheint daemonischer Art zu sein.",78));
        AddDetail( ({ "gemaelde 6" }), BS(
	         "Du siehst einen saeuretriefenden Daemon, der mit seinen "+
                 "aetzenden Klauen nach dir schlagen will.",78));
        AddDetail( ({ "klauen" }), BS(
	         "Die triefen foermlich vor Saeure.",78));
        AddDetail( ({ "gemaelde 7" }), BS(
	         "Huch, das ist ja ne Raritaet. Du siehst hier wirklich "+
                 "eine DaemonIN. Schlank und klein, aber doch gemein und "+
                 "niedertraechtig aussehend, aber scheinbar mit einem "+
                 "grossen Weitblick ausgestattet.",78));
        AddDetail( ({ "raritaet" }), BS(
	         "Damit ist ein weiblicher Daemon gemeint.",78));
        AddDetail( ({ "weitblick" }), BS(
	         "Du kannst ja mal Wuqour nach ihren Faehigkeiten "+
                 "fragen...",78));
        AddDetail( ({ "wort", "woerter" }), BS(
	         "Du musst schon sagen, welches Wort.",78));
        AddDetail( ({ "gemaelde 8", "Eisdaemonenkoenig" }), BS(
	         "Ein grosser Eisdaemon, der eine Eiskrone traegt, "+
                 "ist auf diesem Gemaelde zu sehen. Vermutlich ist er "+
                 "ein Herrscher seiner Art.",78));
        AddDetail( ({ "eiskrone" }), BS(
	         "Du kannst nichts genaues an ihr erkennen.",78));
        AddDetail( ({ "herrscher" }), BS(
	         "Der Eisdaemonenkoenig.",78));
        AddDetail( ({ "art", "daemonenart", "daemonenarten" }), BS(
	         "Du erkennst hier so ziemlich alle Daemonenarten.",78));
        AddDetail( ({ "gemaelde 9",  "Dunkelelf" }), BS(
	         "Auf den ersten Blick scheint es ein Dunkelelf zu sein, "+
                 "der das neunte Gemaelde ziert, jedoch erinnert er auch "+
                 "an einen Daemon. Die Woerter 'Daedhel, der Schattenelf' "+
                 "sind auch noch zu erkennen.",78));
        AddDetail( ({ "gemaelde 10", "Wasserdaemon" }), BS(
	         "Du siehst den Erzfeind des auf Gemaelde sechs "+
                 "gezeigten Daemons: Einen Wasserdaemon. Er besteht "+
                 "scheinbar nur aus  waessrigen Schuppen.",78));
        AddDetail( ({ "Erzfeind" }), BS(
	         "Schau dir halt das Gemaelde 6 an.",78));
        AddDetail( ({ "schuppen" }), BS(
	         "Sieht richtig fischig aus (baehh).",78));
        AddDetail( ({ "gemaelde 11" }), BS(
	         "Auf dem elften Gemaelde kommt zur Abwechslung "+
                 "mal ein relativ harmlos aussehender Daemon, "+
                 "der irgendwo in einer relativ feurigen Region "+
                 "steht. Du glaubst einige Merkmale der Feuerregion "+
                 "der Schreckensspitze zu erkennen.",78));
        AddDetail( ({ "merkmale" }), BS(
	         "Naja, Feuer, Feuer und Feuer halt :)",78));
        AddDetail( ({ "abwechslung" }), BS(
	         "Das nennt sich auch Veraenderung.",78));
        AddDetail( ({ "veraenderung" }), BS(
	         "Siehe Abwechslung.",78));
        AddDetail( ({ "feuer" }), BS(
	         "Das brennt.",78));
        AddDetail( ({ "region", "feuerregion" }), BS(
	         "In der Schreckensspitze.",78));
        AddDetail( ({ "schreckensspitze" }), BS(
	         "Frag mal die Seher danach.",78));
        AddDetail( ({ "seher" }), BS(
	         "Das sind zuviele um alle aufzuzaehlen.",78));
        AddDetail( ({ "gemaelde 12" }), BS(
	         "Auf diesem Gemaelde erkennt man einen wahrlich "+
                 "furchteinfloessenden Daemon, der extrem lange "+
                 "krallenbewehrte Arme hat, und leicht nach vorne "+
                 "gebeugt da steht. Darunter erkennt man das Wort "+
                 "'Rythoth'",78));
        AddDetail( ({ "arme" }), BS(
	         "Sie sind lang und krallenbewehrt.",78));
        AddDetail( ({ "gemaelde 13" }), BS(
	         "Ein haesslicher Daemon mit zwei sehr spitzen "+
                 "Hoerner ist hier abgebildet. Mit seinen "+
                 "blutunterlaufenen Augen scheint er dich zu "+
                 "laehmen. Irgendwie meinst du das Wort 'Kriik' zu "+
                 "erkennen.",78));
        AddDetail( ({ "hoerner" }), BS(
	         "Man, sind die spitzig.",78));
        AddDetail( ({ "gemaelde 14", "halbdunkeldaemon" }), BS(
	         "Halbdunkeldaemon nennt sich sowas wohl, was Du "+
                 "auf diesem Gemaelde erkennst. Recht flink sieht "+
                 "er aus, aber auch wild. Darunter ist das Wort "+
                 "'Irkitis' gemalt.",78));
        AddDetail( ({ "gemaelde 15" }), BS(
	         "Irgendwie sieht er lustig aus, dieser Lichtdaemon, "+
                 "Du glaubst zumindest dass es ein Lichtdaemon ist, "+
                 "seine gedrungene Gestalt, und die kleinen Blitze "+
                 "die um ihn kreisen, deuten darauf hin. Ausserdem "+
                 "steht da auch noch das Wort 'Harkuhu' drunter.",78));
        AddDetail( ({ "gestalt" }), BS(
	         "Wirklich gedrungen, was immer das auch heisst.",78));
        AddDetail( ({ "blitze" }), BS(
	         "Zum Glueck sind sie nur auf das Gemaelde gemalt.",78));
        AddDetail( ({ "glueck" }), BS(
	         "Das hast Du nicht noetig.",78));
        AddDetail( ({ "gemaelde 16" }), BS(
	         "Hier kannst Du einen giftig aussehenden Daemon "+
                 "erblicken. Der Ort in dem er steht, ist von "+
                 "giftigen Daempfen durchdrungen.",78));
        AddDetail( ({ "ort" }), BS(
	         "Wo das ist, musst Du schon selbst herausfinden.",78));

        AddSpecialDetail( ({ "daempfe" }),"det_daempfe");
        AddDetail( ({ "gemaelde 17" }), BS(
	         "Einem Schatten gleich, fast unsichtbar, aber dennoch "+
                 "hinterhaeltig wirkt dieser Daemon. Das Wort "+
                 "'Chochos' ist noch zu erkennen.",78));
        AddDetail( ({ "schatten" }), BS(
	         "Es wirkt nur so.",78));
        AddDetail( ({ "gemaelde 18" }), BS(
	         "Niedlich, ein kleiner, ernst dreinblickender Daemon "+
                 "ist hier zu erkennen, der aber ein unheimliches "+
                 "Wissen ausstrahlt. Das Wort 'Kruftur' ist ueber ihm "+
                 "aufgemalt.",78));
        AddDetail( ({ "wissen" }), BS(
	         "Der scheint wirklich viel zu wissen...",78));
        AddDetail( ({ "gemaelde 19" }), BS(
	         "Unglaublich, aber doch wahr: Der Daemon auf diesem "+
                 "Gemaelde sieht wie eine Kreuzung zwischen einer "+
                 "Spinne, einem Mensch und einer Ziege aus. Doch trotz "+
                 "seines grotesken Aussehens wirkt er nicht halb so "+
                 "gefaehrlich wie die anderen Daemonen.",78));
        AddDetail( ({ "kreuzung" }), BS(
	         "Darauf geh ich jetzt nicht naeher ein... Koennten "+
                 "ja Minderjaehrige da sein!",78));
        AddDetail( ({ "minderjaehrige" }), BS(
	         "Du bist ja hoffentlich keiner, oder?",78));
        AddDetail( ({ "spinne", "mensch", "ziege", "aussehen" }), BS(
	         "Wirklich grotesk.",78));
        AddDetail( ({ "gemaelde 20" }), BS(
	         "Feurig, alles ist einfach nur feurig auf diesem "+
                 "Gemaelde, und mitten darin steht ein wahrlich "+
                 "RIESIGER Feuerdaemon, wohl der grosse Bruder "+
                 "des Daemons auf dem ersten Gemaelde.",78));
        AddDetail( ({ "bruder" }), BS(
	         "Naja, richtige Brueder sind die sicher nicht :)",78));
        AddDetail( ({ "gemaelde 21" }), BS(
	         "Das gibts hier nicht, geh mal weiter.",78));



        AddSounds( SENSE_DEFAULT,BS(
                   "Hier ist es absolut still. Fast schon unheimlich, "+
                   "aber auch nur fast.",78));
        
        AddSmells( SENSE_DEFAULT, BS(
                   "Riecht irgendwie nach Farbe, aber nur ganz leicht.",78));
        AddSmells( ({ "farbe" }), BS(
                   "Wenn ueberhaupt, dann riecht man die nur leicht.",78));

        AddCmd( ({ "greife", "greif" }), "greif1" );
        AddCmd( ({ "kletter","klettere" }), "greif2" );
        
        AddExit("norden",CHAOS_GILDEN_ROOM("galerie2"));
        AddExit("osten",CHAOS_GILDEN_ROOM("waffenlager"));

}

greif1( str )
{
  notify_fail( "In was willst Du denn greifen?\n" );
  if(!str) return 0;
  
  if(member(({"gemaelde", "in gemaelde"}),str)!=-1)
  {
      write(BS("Du greifst tatsaechlich _in_ das Gemaelde, und deine "+
               "Hand verschwindet komplett in ihm. Schnell ziehst Du sie "+
               "wieder heraus. Wenn du mutig genug bist, koenntest Du "+
               "versuchen in das Gemaelde zu klettern, gross genug "+
               "waere es...",78) );
      say(this_player()->Name(WER)+" greift in ein Gemaelde.\n");
       
      return 1; 
   }
   return 0; 
} 


greif2( str )
{
  notify_fail( "In was willst Du denn klettern?\n" );
  if(!str) return 0;
  
  if(member(({"gemaelde", "in gemaelde"}),str)!=-1)
  {
      write(BS("Du steigst durch das Gemaelde hindurch, und landest "+
               "ploetzlich an einem anderen Ort.",78) );
      say(this_player()->Name(WER)+" klettert durch ein Gemaelde hindurch.\n");
      return 1; 
   }
   return 0; 
} 

string det_humor()
{
  this_player()->reduce_hit_point(5);
  return BS("DAS ist schwarzer Humor!",78);
}

string det_daempfe()
{
  if (!this_player()->QueryProp(P_POISON))
      this_player()->SetProp(P_POISON,1);
  return BS("Argl, diese Daempfe sind aber SEHR realistisch!",78);
}
    