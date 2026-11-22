inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include "gilde.h"

#define BS break_string

void create(){
  ::create();
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,1);
  SetProp(P_INT_SHORT,"Schatzkammer von Kruuolq");
  SetProp(P_INT_LONG,
   BS("Die ist die Schatzkammer von Kruuolq, dem Meister des Chaos und "
    "des Boesen. Du siehst nicht den Hauch von Einrichtung oder anderen "
    "Gegenstaenden. Denn hier bringt er alles hin, was er vorlauten "
    "Nichtsnutzen abgenommen hat, die den Fehler begangen haben, ihn "
    "anzugreifen.",78));
  AddDetail(({"boden","fussboden"}),
   BS("Der Fussboden ist kalt und grau.",78));
  AddDetail(({"wand","waende"}),
   BS("Die Waende sind grau und aeusserst schmucklos.",78));
  AddDetail(({"decke"}),
   BS("Die Decke ist feucht und grau. Eine kleine Lampe haengt dort und "
    "verbreitet nur unzureichend etwas Licht.",78));
  AddDetail(({"lampe"}),
   BS("Die Lampe haengt an der grauen, feuchten Decke und verbreitet ein nur "
    "unzureichendes Licht.",78));
  AddDetail(({"licht"}),
   BS("Es reicht gerade aus, um Dich umsehen zu koennen.",78));
  AddDetail(({"kammer","schatzkammer"}),
   BS("Genau dort stehst Du gerade.",78));
  AddDetail(({"kruuolq","meister"}),
   BS("Der ist doch nicht hier, Dummerchen.",78));
  AddDetail(({"dummerchen","erzmeister"}),
   BS("Du untersuchst Dich gewissenhaft.",78));
  AddDetail(({"chaos"}),
   BS("Aeh sag mal, wie bist Du denn bitte Erzmeister geworden?",78));
  AddDetail(({"hauch"}),
   BS("Nicht einen Hauch siehst Du.",78));
  AddDetail(({"einrichtung"}),
   BS("Es ist keine Einrichtung vorhanden, von der Lampe an der Decke einmal "
    "abgesehen.",78));
  AddDetail(({"gegenstaende","gegenstand"}),
   BS("Du solltest schon etwas genauer sagen, was Dich interessiert.",78));
  AddDetail(({"nichtsnutz","nichtsnutze"}),
   BS("Einfach alle, die keine Chaoten sind. So einfach ist das.",78));
  AddDetail(({"chaoten"}),
   BS("Schau Dich doch nur an!",78));
  AddDetail(({"fehler"}),
   BS("Du kannst echt nicht begreifen, wie man soooo bloed sein kann.",78));      

  AddSpecialExit("portal","heile_welt");
}

int heile_welt(){
  write("Du betrittst das Portal und verlierst kurz Deine Orientierung.\n");
  this_player()->move("/d/polar/files.chaos/swift/room/cl2tu1_4",
   M_GO|M_SILENT);
 return 1; 
}
