// Sting/Galerie-Raum 2
// -----------------------------------

#include <properties.h>
#include "/gilden/files.chaos/gilde.h"

#define BS break_string

inherit "/std/room";


create() {
        ::create();

        SetProp( P_INT_SHORT, "Ein Raum der 'Daemonischen Galerie'" );
        SetProp( P_INT_LONG, BS("Du stehst jetzt im zweiten Raum der "+
                 "daemonischen Galerie. Auch hier ist alles mit "+
                 "Teppichen verkleidet, und auch hier findest Du zwei "+
                 "Wandteppiche. Hier findest Du nicht ganz soviele "+
                 "Gemaelde, aber es reicht :) Die Decke ist hier total "+
                 "schwarz, wie der Boden, kein Pentagramm zu sehen. "+
                 "Ansonsten erkennst Du auch hier die Kerzenstaender "+
                 "die den Raum beleuchten, und auch von hier aus kann man "+
                 "den unten liegenden Saal erkennen.",78));

        SetProp( P_LIGHT, 1);
        SetProp( P_INDOORS, 1);



        AddDetail( ({ "decke" }), BS(
                 "Hier ist die Decke einfach nur Schwarz, kein "+
                 "Pentagramm ziert sie.",78));
        AddDetail( ({ "pentagramm" }), BS(
                 "Da stand: KEIN Pentagramm.",78));
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
                 "hast.",78));
        AddDetail( ({ "wand", "waende" }), BS(
                 "An den Waenden erkennst Du Gemaelde und Wandteppiche, "+
                 "Du kannst sie dir einzeln anschauen.",78));
        AddDetail( ({ "wandteppiche", "wandteppich" }), BS(
                 "Welchen meinst Du? Den linken oder den rechten?",78));
        AddDetail( ({ "linker wandteppich", "linken wandteppich" }), BS(
                 "Auf dem linken Wandteppich kannst du eine Horde "+
                 "daemonisch aussehender Orks sehen, von denen einer "+
                 "sogar einen Chaosball auf einen harmlosen Spieler "+
                 "wirft. Im Hintergrund steht ausserdem noch ein "+
                 "Goblin.",78));
        AddDetail( ({ "horde" }), BS(
                 "Naja, so an die zwanzig werdens schon sein.",78));
        AddDetail( ({ "orks" }), BS(
                 "Orks sind dumm und stinken!",78));
        AddDetail( ({ "chaosball", "messerschnitt" }), BS(
                 "Ein eisiger Messerschnitt :)",78));
        AddDetail( ({ "spieler" }), BS(
                 "Das koenntest Du sein!",78));
        AddDetail( ({ "hintergrund" }), BS(
                 "Naja, hinten eben.",78));
        AddDetail( ({ "goblin", "chaosgoblin" }), BS(
                 "Ist wohl der gefuerchtete Chaosgoblin in Orkhausen",78));
        AddDetail( ({ "orkhausen" }), BS(
                 "Bekannt durch seine Bugs.",78));
        AddDetail( ({ "bugs" }), BS(
                 "Das willst Du gar nicht wissen, glaub mir.",78));
        AddDetail( ({ "rechter wandteppich", "rechter wandteppich" }), BS(
                 "Irgendwie ist dieser Wandteppich merkwuerdig... "+
                 "Die Umgebung verschwimmt vor deinen Augen, und kurz "+
                 "kannst du folgendes Szenario erblicken: "+
                 "/*Hier Bild von Seher-Raeubern*/",78));
        AddDetail( ({ "umgebung" }), BS(
                 "Mach mal 'unt raum'.",78));
        AddDetail( ({ "gemaelde" }), BS(
                 "In diesem Raum erkennst du nur 14 Gemaelde, aber "+
                 "es lohnt sich sicherlich, auch diese anzuschauen.",78));
        AddDetail( ({ "gemaelde 1", "hetzerdaemon" }), BS(
                 "Bei der Macht des Chaos, so etwas furchtbares hast Du "+
                 "noch nie erblickt. Der wirklichkeitgewordene Alptraum "+
                 "des Boesen ist das. Dunkelblaugeschuppt, ueberall mit "+
                 "Eiter und Schleim uebersaet und mit saebelartigen Klauen "+
                 "versehen, von denen purpurnes Gift tropft.",78));
        AddDetail( ({ "macht" }), BS(
                 "Eine grosse Macht.",78));
        AddDetail( ({ "chaos" }), BS(
                 "Schwer zu beschreiben :)",78));
        AddDetail( ({ "alptraum", "alptraeume" }), BS(
                 "Nicht jeder hat die gleichen Alptraeume, aber dieser "+
                 "Hetzerdaemon zaehlt wohl dazu.",78));
        AddDetail( ({ "schuppen" }), BS(
                 "Die sind dunkelblau, stand doch da!",78));
        AddDetail( ({ "eiter", "schleim" }), BS(
                 "Buaeh.",78));
        AddDetail( ({ "klauen" }), BS(
                 "Die sehen sehr gefaehrlich aus.",78));
        AddDetail( ({ "gift" }), BS(
                 "Purpur und eklig.",78));
        AddDetail( ({ "intarbir", "ombatis", "gnill", "tutszt"
                      "yrintri", "hothrog"  }), BS(
                 "So heisst wohl dieser Daemon.",78));
        AddDetail( ({ "gemaelde 2" }), BS(
                 "Auf diesem Gemaelde glaubst du zuerst nur Rauchschwaden "+
                 "zu erkennen, dann jedoch fallen dir noch zwei rote "+
                 "Augen auf, die dir die Seele aus dem Koerper zu reissen "+
                 "scheinen.",78));
        AddDetail( ({ "rauchschwaden", "rauch" }), BS(
                 "Rauchig...",78));
        AddDetail( ({ "seele" }), BS(
                 "Die ist schwarz.",78));
        AddDetail( ({ "augen" }), BS(
                 "Sie starren dich an!",78));
        AddDetail( ({ "gemaelde 3" }), BS(
                 "Ein widerlich aussehender, fetter Daemon, der gemein "+
                 "grinst, und staemmige, kurze Beine hat ist hier zu "+
                 "erkennen. Das Wort 'Ombatis' ist aussserdem noch "+
                 "aufgemalt.",78));
        AddDetail( ({ "beine" }), BS(
                 "Kurz und staemmig.",78));
        AddDetail( ({ "gemaelde 4" }), BS(
                 "Klein, bucklig und teuflisch. So wuerdest Du den "+
                 "Daemon auf diesem Gemaelde wohl am ehesten beschreiben. "+
                 "Aus seinem Maul scheinen irgendwelche Gase zu dringen, "+
                 "eventuell ist das seine Waffe. Uebrigens steht da noch " +
                 "'Gnill' drunter.",78));
        AddDetail( ({ "maul" }), BS(
                 "Daraus dringen Gase.",78));
        AddDetail( ({ "gase" }), BS(
                 "Eventuell seine Waffe.",78));
        AddDetail( ({ "waffe", "waffen" }), BS(
                 "Um etwas ueber Waffen zu erfahren, gehst Du am besten "+
                 "in unser Waffenarsenal.",78));
        AddDetail( ({ "waffenarsenal" }), BS(
                 "Das findest Du schon.",78));
        AddDetail( ({ "gemaelde 5", "saeuredaemon" }), BS(
                 "Auf diesem Gemaelde erkennt man einen Saeuredaemon, "+
                 "aber irgendwie hat er etwas besonderes an sich. "+
                 "Eventuell liegt es an den Saeurebaellen die er bei sich "+
                 "traegt.",78));
        AddDetail( ({ "saeurebaelle" }), BS(
                 "Die koennten eine Waffe sein!",78));
        AddDetail( ({ "gemaelde 6" }), BS(
                 "Auf diesem Gemaelde erkennst Du einen grossen "+
                 "Menschenkoerper, aber darauf sitzt ein furchtbar "+
                 "aussehender Schakalkopf. Du erkennst ausserdem "+
                 "noch das kleine Wort 'Hothrog'.",78));
        AddDetail( ({ "schakalkopf" }), BS(
                 "Ist von einem Schakal.",78));
        AddDetail( ({ "schakal" }), BS(
                 "Ein Schakal halt.",78));
        AddDetail( ({ "menschenkoerper", "koerper" }), BS(
                 "Das solltest Du kennen!",78));
        AddDetail( ({ "wuqour" }), BS(
                 "Der ist nicht hier.",78));
        AddDetail( ({ "faehigkeiten" }), BS(
                 "Dazu musste schon zu Wuqour.",78));
        AddDetail( ({ "gemaelde 7" }), BS(
                 "Huch, hier haengt ja gar kein Gemaelde. Muss wohl "+
                 "jemand geklaut haben. Du "+
                 "denkst . o O (Boese Chaoten!)",78));
        AddDetail( ({ "chaoten" }), BS(
                 "Du gehoerst auch zu denen.",78));
        AddDetail( ({ "wort", "woerter" }), BS(
                 "Du musst schon sagen, welches Wort.",78));
        AddDetail( ({ "gemaelde 8", "blutdaemon" }), BS(
                 "WOW. Das ist das erste was dir in den Sinn kommt, "+
                 "wenn Du den Daemon auf diesem Gemaelde betrachtest, "+
                 "denn dies ist einer der letzten Blutdaemonen seiner "+
                 "Art. Boese und finster blickt er drein, und seine "+
                 "unglaubliche Gier nach Blut gab ihm seinen Namen, "+
                 "der direkt darunter steht: 'Tutszt'",78));
        AddDetail( ({ "sinn" }), BS(
                 "Du fragst dich, ob das hier eigentlich Sinn macht.",78));
        AddDetail( ({ "gier" }), BS(
                 "Schier unermaesslich",78));
        AddDetail( ({ "blut" }), BS(
                 "Danach lechzt er foermlich.",78));
        AddDetail( ({ "art", "daemonenart", "daemonenarten" }), BS(
                 "Du erkennst hier so ziemlich alle Daemonenarten.",78));
        AddDetail( ({ "gemaelde 9" }), BS(
                 "Der Daemon hier sieht eigentlich harmlos aus, doch "+
                 "dieser Eindruck kann taeuschen. Eventuell erfaehrst Du "+
                 "etwas ueber ihn, wenn du Wuqour einmal nach 'Yrintri' "+
                 "fragst, denn dieses Wort steht auch auf dem Gemaelde.",78));
        AddDetail( ({ "eindruck" }), BS(
                 "Kann taeuschen!",78));
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
        AddDetail( ({ "farbe" }), BS(
                 "Riech doch mal.",78));
        AddDetail( ({ "gemaelde 10" }), BS(
                 "Ein fledermausartiger Daemon, jedoch mit menschlichem "+
                 "Gesicht ist hier zu sehen. Jedoch lassen die langen "+
                 "Reisszaehne und der dornenbesetzte Schwanz nichts gutes "+
                 "erahnen...",78));
        AddDetail( ({ "gesicht" }), BS(
                 "Wirkt irgendwie menschlich, aber irgendwie doch "+
                 "nicht.",78));
        AddDetail( ({ "reisszaehne", "zaehne" }), BS(
                 "*zitter*",78));
        AddDetail( ({ "schwanz" }), BS(
                 "Mit Dornen durchsetzt.",78));
        AddDetail( ({ "dornen" }), BS(
                 "Spitzig... SEHR spitzig.",78));
        AddDetail( ({ "gemaelde 11", "statue" }), BS(
                 "Seltsam, auf diesem Gemaelde ist doch nur eine "+
                 "Statue aus Stein zu sehen... Zugegeben, irgendwie "+
                 "wirkt sie schon daemonisch, vielleicht sollte man "+
                 "vorsichtig mit ihr umgehen.",78));
        AddDetail( ({ "stein" }), BS(
                 "Grauer Stein, ansonsten aber daemonisch (irgendwie).",78));
        AddDetail( ({ "gemaelde 12", "schatten" }), BS(
                 "Auf dem zwoelften Gemaelde ist nichts. Oder ? Hm. "+
                 "Du glaubst jedenfalls dass da nichts ist... Und doch "+
                 "ist auf dem Bild etwas zu erkennen. Die Woerter "+
                 "'Daemonischer Schatten' sind darauf gemalt.",78));
        AddDetail( ({ "gemaelde 13" }), BS(
                 "Der Daemon auf diesem Gemaelde scheint vollstaendig "+
                 "aus Wasser zu bestehen, dessen Form er jedoch scheinbar "+
                 "beliebig veraendern kann. Er sieht sehr gefaehrlich "+
                 "aus.",78));
        AddDetail( ({ "gemaelde 14", "giftdaemon" }), BS(
                 "Gruener, ekliger Schleim. Aus mehr scheint dieses "+
                 "Wesen wohl nicht zu bestehen. Untote und tote Materie "+
                 "trachten dir nach dem Leben. Dies ist wohl einer der "+
                 "gefuerchteten Giftdaemonen aus den Katakomben im "+
                 "Verlorenen Land.",78));
        AddDetail( ({ "schleim", "materie" }), BS(
                 "Sieht eklig aus!",78));
        AddDetail( ({ "gemaelde 14" }), BS(
                 "Eis. Einfach nur Eis. Alles an diesem Monster scheint "+
                 "aus kristallblauem Eis zu bestehen. Alles bis auf die "+
                 "feurig roten Augen, aus denen es Dich hasserfuellt "+
                 "anstarrt. So etwas findet man nur in den Katakomben "+
                 "des Verlorenen Landes.",78));
        AddDetail( ({ "gemaelde 15" }), BS(
                 "Soviele gibts doch (noch) gar nicht!",78));

        AddSounds( SENSE_DEFAULT,BS(
                   "Hier ist es absolut still. Fast schon unheimlich, "+
                   "aber auch nur fast.",78));
        
        AddSmells( SENSE_DEFAULT, BS(
                   "Riecht irgendwie nach Farbe, aber nur ganz leicht.",78));
        AddSmells( ({ "farbe" }), BS(
                   "Wenn ueberhaupt, dann riecht man die nur leicht.",78));
        AddExit("sueden",CHAOS_GILDEN_ROOM("galerie1"));
}




