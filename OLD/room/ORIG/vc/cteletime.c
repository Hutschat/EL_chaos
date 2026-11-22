// 04.07.99 Feuerwehr debugging


#include "../gilde.h"

inherit "std/room";

#define BS break_string
#define TP this_player()
#define TO this_object()

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "Zwischen den Dimensionen");
  SetProp( P_INT_LONG, BS(
     "Viele bunte Farben gleiten an Dir vorbei. Wer sagt die Daemonendimensionen "
    +"waeren alle dunkel, der hat sie wohl noch nicht bereist... Du durchdringst "
    +"blitzeschnell Dimensionen und Welten, die Du nie zuvor gesehen hast... "
    +"...und die Du auch nie wieder sehen wirst. In affenartiger Geschwindigkeit "
    +"strebst Du Deinem Ziel entgegen.",78,0,1) );

  AddDetail( ({"detail", "details"}), "Also so einfach geht das nicht! :)\n");
  AddDetail( ({"dimension", "daemonendimension"}), BS("Hier gibt es nicht nur EINE "
    +"Dimension, hier gibt es UNZAEHLIGE Dimensionen",78) );
  AddDetail( ({"dimensionen", "daemonendimensionen"}), BS("Du durchfliegst sie mit "
    +"so hoher Geschwindigkeit, dass Dir keine Zeit zum untersuchen bleibt.",78) );
  AddDetail( ({"geschwindigkeit"}), BS("Affenartig!!!",78) );
  AddDetail( ({"zeit"}), BS("Zeit ist hier relativ!",78) );
  AddDetail( ({"farben"}), BS("Sind sie nicht bunt?",78) );
  AddDetail( ({"welt", "welten"}), BS("Welten schiessen an Dir vorbei, zu schnell um "
    +"einen genaueren Blick zu erhaschen...",78) );
  AddDetail( ({"blick"}), BS("Ist mit Deinem Blick was nicht in Ordnung?",78) );
  AddDetail( ({"ordnung"}), BS("Die suchst Du hier vergebens. Hier gehts ueberall "
    +"drunter und drueber... chaotisch gehts hier zu :)",78) );
  AddDetail( ({"ziel"}), BS("Wenn nicht DU, _wer_sonst_ soll das Ziel Deiner Reise "
    +"kennen???",78) );
  AddDetail( ({"reise", "vergnuegungsreise"}), BS("Diese Reise ist KEINE "
    +"Vergnuegungsreise!!!",78) );

  AddSounds( SENSE_DEFAULT, BS("Nichts zu hoeren!",78) );

  AddSmells( SENSE_DEFAULT, BS("Nichts zu riechen!",78) );

  SetProp( P_LIGHT, 1);

  AddRoomMessage(({
    BS("Du zitterst. Zwischen den Dimensionen ist es ja richtig kalt!",78),
    BS("Irgendetwas - oder irgendjemand? zischt an Dir vorbei.\n"
      +"Ein anderer Reisender?",78,0,1),
    BS("Geisterhafte Stimmen versuchen Dich einzulullen.\nVorsichtshalber "
      +"ignorierst Du sie.",78,0,1),
    BS("Eine riesige, daemonenhafte Fratze erscheint direkt vor Dir und schnappt nach "
      +"Dir und reisst Dich in Stuecke... oh das war nur eine Illusion. "
      +"Jof sei Dank!",78),
    BS("Finstere Schatten versuchen Dich einzuholen.\nDu bist aber etwas schneller. "
      +"Oder?",78,0,1),
    BS("Du bist in eine kollabierende Dimension geraten. Schnell wechselst Du in "
      +"eine andere (auch wenn Du nicht weisst wie), bevor Dich der Sog ins Verderben "
      +"reissen kann.",78),
    BS("Ein riesiger Tentakel materialisiert aus dem Nichts und verfehlt Dich "
      +"knapp.",78),
    BS("Die Dimensionen um Dich erzittern, Dein Flug verlaeuft aeusserst unruhig. "
      +"Freu Dich - Du bist Zeuge eines der seltenen 'Dimensionsbeben'.",78),
    BS("Wie Du so durch die Dimensionen fliegst, siehst Du ploetzlich ein seltsames "
      +"Objekt vor Dir auftauchen. Schnell greifst Du danach. Nanu? Eine verbeulte, "
      +"zerknuellte Cola-Buechse. Dass die Leute aber auch ueberall ihren Muell "
      +"abladen muessen. Veraergert wirfst Du das Ding wieder weg, das sofort zwischen "
      +"den Dimensionen verschwindet.",78),
    BS("Deine Flugbahn veraendert sich abrupt.\nOder ist das nur Dein verwirrter Geist, "
      +"der Dir wieder mal etwas vorgaukelt?",78,0,1),
    BS("Farbkaskaden explodieren um Dich herum. Fast wie ein Feuerwerk... Aber Dich "
      +"beunruhigt der Gedanke, es koennte sich um explodierende Universen handeln, "
      +"was Du da siehst...",78)
  }), 4 );

}


varargs string GetExits( object viewer ) 
{
  return "";
}


string int_short(mixed viewer, mixed viewpoint)
{
  if( !present(TP) )   // fwer ort oder andere P_SHORT abfrage des Raumes von aussen?
    return QueryProp(P_INT_SHORT);
  return "";
}


string int_long(mixed viewer, mixed viewpoint)
{
  string str;
  object pl;
  if( !present(TP) )   // Bild von ausserhalb beschworen?
  {
    str=this_interactive()->_unparsed_args();
    if( pl=present(str) )
    {
      return BS(pl->Name(WER)+" nimmt gerade eine Abkuerzung durch die "
        +"Daemonendimensionen.\nDie Umgebung wechselt zu rasch, Du kannst nichts "
        +"naeheres erkennen!",78,0,1);
    }
    else
      return BS("Den/Die Du suchst ist wohl verlorengegangen...",78);
  }
  return ::int_long(viewer, viewpoint);
}


void init()
{
  write("Du tauchst ein in den Strudel der Dimensionen.\n");
  ::init();
}


void ausgang(object pl, int zeit, string zielraum)
{
  call_out("geh_endlich", zeit, pl, zielraum);
}

void geh_endlich(object pl, string zielraum)
{
  if( present(pl) )               // Spieler im Raum?
    pl->move(zielraum, M_TPORT);  //   -> Teleport zum Zielraum!
  if( !present(pl) )              // Spieler jetzt nicht mehr im Raum?
    call_out("remove",4);         //   -> Raum zerstoeren!
}
