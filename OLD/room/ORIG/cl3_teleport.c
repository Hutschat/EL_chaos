// 26.02.2000  Swift     Mit Genehmigung von Ulo Ziel Fernwest eingebaut, auf seinen
//                       Wunsch wird dieses Ziel paar Wochen geloggt in
//                       /log/swift/gilde/chaosteleport.log

#include "/d/polar/files.chaos/swift/swift_files.h"

inherit C_SWIFT_ROOM("gilde_std");

#define CTELETIME CHAOS_GILDEN_ROOM("vc/cteletime")
#define WAHNSINN  C_SWIFT_OBJ("chaoswahn.c")

void create()
{
  ::create();
  SetProp( P_INT_SHORT, "An einem unheimlichen, unrealen ...Ort");
  SetProp( P_INT_LONG, BS(
     "Finstere Schatten greifen nach Dir, Du hoerst schreckliche ...Geraeusche, Dinge "
    +"die Dein Verstand nicht erfassen kann winden sich ueber Dir, unter Dir...\n"
    +"Hier gibt es keine Realitaet, dieser ...Ort befindet sich im Morgengrauen und "
    +"doch auch nicht, Du siehst das Resultat der missglueckten Beschwoerung eines "
    +"maechtigen Daemons. Die Pforten in die Daemonendimensionen scheinen stabil(?) "
    +"und geoeffnet zu sein, Du hoffst dass der Bannkreis noch funktioniert. Aber das "
    +"muss er ja, sonst haetten diese ...Dinge die Welt schon ueberrannt.   Oder?"
    +"",78,0,1) );

  AddDetail( ({"detail", "details"}), "Also so einfach geht das nicht! :)\n");
  AddDetail( ({"schatten"}), "Finstere, dunkle Schatten.\n");
  AddDetail( ({"verstand"}), BS("Dein Verstand wuerde nicht fertig mit dem was Du "
    +"da siehst. Das wuerde Dich in den Wahnsinn treiben.",78) );
  AddDetail( ({"wahnsinn"}), BS("Bekomm ihn erst, dann kannste ihn untersuchen!",78) );
  AddDetail( ({"pforten", "tor"}), BS("Ob es nun die Daemonendimensionen sind oder "
    +"etwas anderes, hier ueberschneiden sich verschiedenste Dimensionen und "
    +"ermoeglichen reifen Beherrschern der Chaosmagie die Teleportation zu weit "
    +"entfernten Flecken dieser Welt.",78) );
  AddDetail( ({"seher"}), BS("Das sind die mit dem grossen 'S' :)",78) );
  AddDetail( ({"flecken"}), BS("Das kannst Du nur vor Ort!",78) );
  AddDetail( ({"teleportation"}), BS("Jeder Seher sollte wissen was gemeint ist!",78) );
  AddDetail( ({"chaos", "krieger"}), "Chaos gibts ueberall. Aber hier besonders.\n");
  AddDetail( ({"gilde"}), BS("Du meinst Dass Du Dich in der Gilde der Krieger des "
    +"Chaos befindest. Bzw. in einem Raum davon. Wenn das hier ein Raum ist. "
    +"Aeh...",78) );
  AddDetail( ({"resultat", "ergebnis"}), BS("Das Ergebnis des Geschehens damals.",78) );
  AddDetail( ({"geschehen"}), BS("Damit kann ja wohl nur die missglueckte "
    +"Beschwoerung damals gemeint sein. Was fuer Details hast Du denn seither "
    +"untersucht, dass Du das nicht weisst?",78) );
  AddDetail( ({"chaosmagie"}), BS("Die wird von den Kriegern des Chaos "
    +"praktiziert.",78) );
  AddDetail( ({"dunkelmagier"}), "Dunkelmagier ist man ab Chaos-Gildenlevel 9.\n");
  AddDetail( ({"beherrscher"}), BS("Jeder Dunkelmagier des Chaos wird den Kraeften "
    +"hier gewachsen sein und vermag sie zu nuetzen. Alle schwaecheren... ihre Asche "
    +"moege in ewiger Verdammnis ruhen!",78) );
  AddDetail( ({"asche"}), BS("Mehr wird im Falle eines Versagens nicht uebrigbleiben, "
    +"als Asche...",78) );
  AddDetail( ({"fall", "falle"}), BS("Stell Dir den Fall gar nicht erst vor!",78) );
  AddDetail( ({"gildenlevel"}), BS("Die Gildenlevel stellen den Grad der Bewertung "
    +"innerhalb einer Gilde, in diesem Fall der Chaoten, dar.",78) );
  AddDetail( ({"bewertung", "grad"}), BS("Irgendwie MUSS man das Koennen bewerten "
    +"koennen!",78) );
  AddDetail( ({"koenner", "koennen"}), BS("Chaoten sollten Koenner sein.",78) );
  AddDetail( ({"chaoten"}), BS("Chaoten sollten sich chaotisch benehmen.",78) );
  AddDetail( ({"versagen"}), BS("Versag erst mal, dann kannst Du das untersuchen.",78) );
  AddDetail( ({"verdammnis"}), BS("Jeder Unberechtigte wird erfahren, was dieses Wort "
    +"bedeutet.",78) );
  AddDetail( ({"wort"}), BS("V E R D A M M N I S",78) );
  AddDetail( ({"unberechtigte", "unberechtigen", "unberechtiger", "berechtigung"}), BS(
     "Berechtigt sind nur Chaoten ab mind. Gildenlevel 9.",78) );
  AddDetail( ({"morgengrauen"}), BS("Sowas siehst Du da nicht! - Aber irgendwie doch, "
    +"ist es doch die Welt, aus der Du stammst. Und in der Du Dich befindest. Noch. "
    +"Oder?",78) );
  AddDetail( ({"welt"}), "Hier? In diesem unrealen Raum?\n");
  AddDetail( ({"ausgang", "norden"}), BS("Sieht wie ein Ausgang in die Realitaet aus. "
    +"Sicher bist Du Dir aber nicht!",78) );
  AddDetail( ({"bannkreis", "kreis"}), BS("Du hoffst dass er noch existiert, auch "
    +"wenn Du ihn nicht sehen kannst.",78) );
  AddDetail( ({"beschwoerung"}), BS("Welcher Daemon hier versucht wurde zu "
    +"beschwoeren, laesst sich nicht mehr genau sagen. Aber es muss ein maechtiger "
    +"gewesen sein. Als die Beschwoerung schiefging, manifestierte sich seine Macht "
    +"in diesem Raum und loeschte alles Leben aus. Die Kraefte, die da wirkten, waren "
    +"so ungeheuerlich stark, dass Realitaet und Dimensionen in diesem Raum verzerrt "
    +"wurden, bis zum heutigen Tag. Konstanten werden hier zu Variablen, die "
    +"Grundgesetze der Physik sind ausser Kraft.",78) );
  AddDetail( ({"tag"}), BS("Sowas siehst Du hier nicht. Nicht tief unter der "
    +"Erde. :)",78) );
  AddDetail( ({"erde", "tageslicht"}), BS("Unter der Erde gibts meistens kein "
    +"Tageslicht!",78) );
  AddDetail( ({"variablen"}), BS("Variablen sind variabel. Deshalb heissen sie wohl "
    +"so.",78) );
  AddDetail( ({"physik"}), BS("Wer braucht schon Physik im MorgenGrauen!?",78) );
  AddDetail( ({"macht"}), BS("Wer zu solchen Taten in der Lage ist, der hat Macht. "
    +"Und zwar nicht zu knapp!!!",78) );
  AddDetail( ({"taten"}), BS("Bist Du blind? Schau Dich um!",78) );
  AddDetail( ({"sache"}), BS("Das Geschehen hier.",78) );
  AddDetail( ({"lage"}), BS("Der Daemon war anscheinend in der Lage, deshalb hat ers "
    +"gemacht.",78) );
  AddDetail( ({"leben"}), BS("Das hat keiner ueberlebt. Ist aber auch wirklich lange "
    +"her, daher juckt das heute keinen mehr.",78) );
  AddDetail( ({"kraefte", "kraft"}), BS("Hier wirken die unheimlichen Kraefte eines "
    +"starken Daemons, der wohl falsch beschworen wurde, bis zur heutigen Zeit und "
    +"verzerren die Realitaet und Dimensionen in diesem Raum.",78) );
  AddDetail( ({"daemon"}), BS("Von dem Daemon, der dies bewirkt hat, ist nichts "
    +"zu sehen. Kein Wunder, das muss ja auch vor langer Zeit gewesen sein. Er hat "
    +"die Sache bestimmt schon vergessen!",78) );
  AddDetail( ({"zeit"}), BS("Das Geschehen hier liegt lange zurueck. Bis zum "
    +"heutigen Tag sind die Auswirkungen zu spueren, wie Du selbst sehen kannst!",78) );
  AddDetail( ({"auswirkungen"}), BS("Mach Deine Augen auf!",78) );
  AddDetail( ({"augen"}), BS("Das geht?",78) );
  AddDetail( ({"wunder"}), BS("Nach so langer Zeit ist das eher NORMAL!",78) );
  AddDetail( ({"daemonendimensionen", "daemonendimension", "dimension", "dimensionen"}),
      BS("Hier wurde ein Daemon "
    +"beschworen, wenn die Realitaet und Dimensionen verzerrt sind und ein Tor in "
    +"andere Dimensionen bilden, dann werden es wohl die Daemonendimensionen sein. "
    +"Oder?",78) );
  AddDetail( ({"dinge", "kreaturen"}), BS("...Ekelhafte, sich windende Kreaturen(?), "
    +"die sich Deinem Blick entziehen. Zum Glueck vielleicht, sonst wuerdest Du "
    +"bestimmt dem Wahnsinn anheimfallen!",78) );
  AddDetail( ({"blick"}), BS("Entweder ist Dein Blick getruebt fuer die Wirklichkeit, "
    +"was auf beginnenden Wahnsinn hindeuten koennte, oder hier siehts wirklich so aus. "
    +"Du weisst nicht so recht, welche der beiden Moeglichkeiten Dir lieber "
    +"waere.",78) );
  AddDetail( ({"moeglichkeit", "moeglichkeiten"}), BS("Die zweite Moeglichkeit ist Dir "
    +"bestimmt lieber!",78) );
  AddDetail( ({"wirklichkeit", "realitaet"}), BS("An diesem ...Ort ist NICHTS real, "
    +"nichts Wirklichkeit. Und doch: Du hast allen Grund, Dich vor dieser "
    +"...Unrealitaet zu fuerchten!",78) );
  AddDetail( ({"unrealitaet", "unwirklichkeit"}), BS("Dein Geist ist nicht geschaffen "
    +"fuer unreale Dinge. Wenn Du ernsthaft versuchen wuerdest, die hier herrschende "
    +"Unwirklichkeit zu begreifen, wuerde der Wahnsinn in Deine Knochen kriechen und "
    +"Du wuerdest Dich wohl selbst zerfleischen...",78) );
  AddDetail( ({"knochen"}), BS("Solange Du aus Fleisch und Blut bist, geht das nicht "
    +"so einfach!",78) );
  AddDetail( ({"ort", "raum"}), BS("Dieser ...Ort ist seltsam. Nicht wirklich. Irgenwie "
    +"...unreal.",78) );
  AddDetail( ({"fleisch", "blut"}), BS("Sieht gut aus. Zumindest JETZT noch.",78) );
  AddDetail( ({"geist"}), BS("Hmm. Was ist wohl damit gemeint?",78) );
  AddDetail( ({"geraeusch", "geraeusche"}), BS("Du kannst versuchen, ihnen zu lauschen, "
    +"aber ob das ratsam ist?",78) );
  AddDetail( ({"glueck"}), BS("Glueck ist relativ. Vor allem an solch einem "
    +"...Ort.",78) );
  AddDetail( ({"konstanten"}), BS("Hier ist NICHTS konstant.",78) );
  AddDetail( ({"grund"}), BS("Wenn nichts real ist, was ist denn dann mit DIR?",78) );
  AddDetail( ({"gesetze", "grundgesetze", "regeln"}), BS("Die existieren hier nicht "
    +"mehr. Die Regeln der Physik unterliegen der ...Unwirklichkeit dieses "
    +"...Ortes!",78) );

  AddSounds( SENSE_DEFAULT, BS(
     "Unheimliche Geraeusche lassen Dich erschauern. Denn Dir ist keines der "
    +"Geraeusche bekannt, aber gefaehrlich klingt es allemal.",78) );
  AddSounds( ({"geraeusche"}), BS(
     "Schrecklich!",78) );

  AddSmells( SENSE_DEFAULT, BS(
     "Hier riecht es nach allem. Und nichts. Na evtl. nach etwas Schwefel...",78) );
  AddSmells( ({"schwefel"}), BS(
     "Als ob der Hoellenherrscher hier gewesen waere...",78) );

  SetProp( P_LIGHT, 0);

  AddCmd(({ "teleport", "teleportiere" }), "tele" );

  AddExit( "norden", C_112_ROOM("cl3bu6") );
}


varargs string GetExits( object viewer ) 
{
  int n, i;
  string exits;
  string *numbers;
  string *indices;
  string *hidden;
  if (QueryProp(P_DOOR_INFOS))
    call_other(DOOR_MASTER,"init_doors");
  numbers = ({"zwei","drei","vier","fuenf","sechs","sieben","acht"});
  indices = m_indices(Query(P_EXITS)||rescueExit());
  if (pointerp(hidden=QueryProp(P_HIDE_EXITS)))
    indices-=hidden;
  n = sizeof(indices);
  switch (n)
  {
    case 0:
    return "Es scheint im Moment keine Ausgaenge zu geben.\n";
    case 1:
    return "Du glaubst, im "+CAP(indices[0])+" den Ausgang zu sehen.\n";
    case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    exits = "Es sieht aus, als gaebe es "+numbers[n-2]+" Ausgaenge: ";
    break;
    default:
    exits = "Es scheint viele Ausgaenge zu geben: ";
  }
  for (i = 0; i < n-2; i++)
    exits += indices[i]+", ";
  exits += indices[n-2]+" und "+indices[n-1]+".\n";
  return BS(exits,78);
}

string int_long(mixed viewer, mixed viewpoint)
{
  string txt;
  object ob;
  txt="Du siehst einen unheimlichen, unrealen ...Ort. Die Dimensionen "
    +"verschwimmen, ...Dinge winden sich...";
  if( TP->QueryProp(P_GUILD) == "chaos" )
    return ::int_long(viewer, viewpoint);
  if(  query_verb() != "beschwoer"
    && query_verb() != "beschwoere"
    && query_verb() != "find"
    && query_verb() != "finde"
    && query_verb() != "konzentrier"
    && query_verb() != "konzentriere")
  {
    txt="Ein 'Glueck', dass Du schon wahnsinnig bist, sonst wuerdest Du es jetzt!";
    if( !present("\nchaoswahn", TP) )
    { 
      ob=clone_object(WAHNSINN);
      ob->move(TP, M_NOCHECK);
      txt="Der Anblick ist zuviel fuer Dich, Du merkst wie der Wahnsinn Dich "
        +"umnachtet.";
    }
    return ::int_long(viewer, viewpoint) + BS(txt);
  }
  else
  {
    if( TP->QueryProp(P_WIMPY) > 0      // Vorsicht gesetzt?
      || query_verb() == "konzentrier" || query_verb() == "konzentriere" )
        return BS("Du siehst einen unheimlichen, unrealen ...Ort. Schnell wendest Du "
          +"Deine Augen ab. Glueck gehabt. Sonst haette Dich bestimmt der Wahnsinn "
          +"gepackt!!!",78);
    if( !present("\nchaoswahn", TP) )
    { 
      ob=clone_object(WAHNSINN);
      ob->move(TP, M_NOCHECK);
    }
    else
    {
      return BS(txt+" Ein Glueck dass Du schon wahnsinnig bist, sonst wuerdest Du "
        +"es jetzt mit Sicherheit!",78);
    }
  } 
  return BS(txt+" und Du merkst wie sich Dein Geist verwirrt. Du warst zu unvorsichtig "
    +"und hast das surreale Bild wohl etwas zu lange betrachtet. Der Wahnsinn greift "
    +"nach Dir...",78);
}


int tele(string str)
{
  string ort;
  object leiche,ob;
  if( TP->QueryProp(P_GUILD) != "chaos" )
  {
    SetProp(P_KILL_NAME,"Daemonische Kraefte");
    SetProp(P_KILL_MSG, ({"sollte man nie unterschaetzen!!!", MSG_EMOTE, PLURAL}) );
    tell_object(TP, BS("DAS haettest Du besser NICHT versucht. Da Du kein Chaot bist, "
      +"verlierst Du sofort jegliche Kontrolle ueber die gewaltigen Kraefte, die hier "
      +"wirken. Du wirst regelrecht zerfetzt!",78) );
    TP->die();
    tell_room(TO, BS("Die Leiche wird von den gewaltigen, unfassbaren Kraeften in "
      +"diesem Raum regelrecht zerfetzt!",78), ({TP}) );
    if( leiche=present("leiche") )
      if( leiche->QueryProp("original_name") == TP->Name(WER) )
        leiche->remove();
    return 1;
  }
  if( TP->QueryProp( P_GUILD_LEVEL) < 9 )
  {
    tell_object(TP, BS("Du hast Dich wohl ueberschaetzt. Dein Geist verwirrt "
                      +"sich...",78) );
    if( !present("\nchaoswahn", TP) )
    { 
      ob=clone_object(WAHNSINN);
      ob->move(TP, M_NOCHECK);
    }
    return 1;
  }

  if(!str)
  {
    notify_fail( "Du musst schon wissen, wohin Du teleportieren willst.\n");
    return 0;
  }
  notify_fail( "Wohin willst Du teleportieren?\n");
  if( !sscanf( str, "zur %s", ort) && !sscanf( str, "zum %s", ort) 
    && !sscanf( str, "nach %s", ort) && !sscanf( str, "zu %s", ort)) 
        return 0;
  switch( ort)
  {
    case "gruft":
       TP->move("/d/polar/terrorist/room/gruft3",M_TPORT);
       break;
    case "gilde":
    case "abenteurergilde":
    case "abenteuergilde":
      TP->move( "/gilden/abenteurer", M_TPORT);
      break;
    case "moulokin":
    case "moloukin":
    case "hunnar":
      TP->move( "/d/polar/alle/room/Moulokin/mk_seeloewe3", M_TPORT );
      break;
    case "drachenhort":
    case "bank":
    case "drachenzinnen":
    case "seherbank":
      TP->move("/d/ebene/room/dra_str1",M_TPORT);
      break;
    case "katakomben":
      TP->move("/d/vland/morgoth/room/kata/kata12", M_TPORT|M_SILENT );
      break;
    case "portvain":
    case "port vain":
    case "port":
    case "vain":
      TP->move( "/d/ebene/room/PortVain/laden", M_TPORT);
      break;
    case "weihnachtsmann":
    case "nordpol":
      TP->move( "/d/polar/alle/room/nordpol", M_TPORT);
      break;
    case "zwerge":
    case "zwergen":
    case "zwergenstadt":
    case "zwergenkneipe":
    case "zwergenladen":
      TP->move( "/d/gebirge/room/zladen", M_TPORT);
      break;
    case "burg":
    case "daemonenburg":
    case "daemonen":
    case "beschwoerungsraum":
      if( deep_present( "boings hoellenfeuer", TP))
        return write( "Boings Hoellenfeuer verhindert den Teleport!\n"),1;
      TP->move( "/d/ebene/zardoz/burg/workroom", M_TPORT);
      break;
    case "parallelwelt":
    case "parawelt":
      write( "Irgendwas scheint passiert zu sein...\n");
      TP->SetProp( P_PARA, 1);
      break;        
    case "welt":
    case "normale welt":
    case "normalen welt":
    case "normalwelt":
      write( "Nichts passiert... oder doch?\n");
      TP->SetProp( P_PARA, 0);
      break;
    case "tod":
    case "tot":
    case "zu meinem tod":
    case "gevatter tod":    
      write( "Du kannst von Glueck sagen, dass Zardoz nicht fies ist!\n");
      TP->reduce_hit_point(250);
      break;            
    case "hochebene":
    case "gebirge":
      TP->move( "/d/gebirge/room/he1x1", M_TPORT);
      break;
    case "ssp":
    case "musikschloss":
    case "schreckensspitze":
    case "schreckenspitze":
      TP->move( "/d/gebirge/boing/sm/l1/m5x1", M_TPORT );
      break;
    case "seherladen":
    case "svolvaer":
      TP->move( "/players/loco/latte/svolvaer/seherladen", M_TPORT);
      break;
    case "wueste":
    case "arena":
    case "duellarena":
      TP->move( "/d/wueste/room/arena/vorplatz", M_TPORT);
      break;
    case "hoelle":
      TP->move( "/d/unterwelt/raeume/hoelle2", M_TPORT );
      break;
    case "elfen":
    case "elf":
    case "elfenladen":
    case "elfendorf":
    case "elfenhain":
      TP->move( "/d/wald/quasimodo/room/strasse2", M_TPORT );
      break;
    case "architekt":
    case "archi":
    case "architekten":
    case "f&e":
    case "forschung und entwicklung":
      TP->move( "/players/rochus/quest_3player/room/eingang", M_TPORT);
      break;
    case "dschungel":
    case "urwald":
      TP->move( "/d/dschungel/gum/rooms/bruecke", M_TPORT);
      break;
    case "zardoz":
    case "zardoz workroom":
      TP->move( "/players/zardoz/workroom", M_TPORT );
      break;
    case "aurora":
    case "tarko reub":
    case "troedler":
    case "troedelhaendler":
      TP->move( "/d/inseln/wargon/aurora/room/wald2", M_TPORT);
      break;
    case "moron":
      TP->move( "/d/ebene/calum/Moron/room/weg3", M_TPORT );
      break;
    case "steinbeisser":
    case "steinbeisserhoehle":
    case "hoehle":
    case "beisserhoehle":
      TP->move( "/d/gebirge/boing/beisser/room/beisshoehle5", M_TPORT );
      break;
    case "wald":
    case "glockenwald":
      TP->move( "/d/wald/troy/room/gwald3x2", M_TPORT );
      break;

//--- Neue Ziele im Zuge der neuen Chaosgilde (Jahr 1999) ---
    case "aboleth":
    case "aboleths":
    case "wasserebene":
    case "wasserelementar":
      TP->move( "/d/gebirge/boing/sm/l5/m5x2", M_TPORT); // Gen. v. Boing
      break;
    case "duesterwald":
    case "peter":
      TP->move( "/d/gebirge/feuerwehr/dwald/rooms/wald01", M_TPORT); // Gen. v. 112
      break;
    case "dunkelelfen":
      TP->move( "/d/unterwelt/cadra/room/town/guardscave", M_TPORT); // Gen. v. Padreic
      break;
    case "feuerinsel":
    case "coffeeshop":
    case "piet":
      TP->move( "/d/inseln/bierchen/feuerinsel/rooms/coffeeshop", M_TPORT); //G.Bierchen
      break;
    case "wechhier":
    case "magieinsel":
      TP->move( "/d/inseln/bierchen/minsel/rooms/iturm1_0", M_TPORT); // Gen. v. Bierchen
      break;
    case "ruinenstadt":
    case "huegel":
      TP->move( "/d/gebirge/kaenguruh/room/huegel", M_TPORT); // Gen. v. Bierchen
      break;
    case "orklager":
      TP->move( "/d/polar/pilgrim/orklager/room/o2", M_TPORT); // Gen. v. Pilgrim
      break;
    case "eismine":                         // Genehmigt v. Tsunami (Bed.: 5 Sek./15 KP)
      if( TP->QueryProp(P_SP) < 16 )
      {
        tell_object(TP, "Es mangelt Dir an Konzentration fuer dieses Ziel!\n");
        break;
      }
      TP->move( CTELETIME+"+"+getuid(TP), M_TPORT);
      (CTELETIME+"+"+getuid(TP))->ausgang(TP, 6,
        "/d/polar/tsunami/eismine/ebene3/eisraum41");
      TP->SetProp(P_SP, TP->QueryProp(P_SP)-15); // 15 KP abziehen!
      break;
    case "drakonien":
      TP->move( "/d/wald/paracelsus/room/wweg2_4", M_TPORT); // Gen. v. Paracelsus
      break;
    case "katzmandu":
      TP->move( "/d/dschungel/paracelsus/room/frei3", M_TPORT); // Gen. v. Paracelsus
      break;
    case "bergwerk":
    case "zwergenbergwerk":
      TP->move( "/d/gebirge/wurzel/room/aufunten", M_TPORT); // Gen. v. Wurzel
      break;
    case "kobolde":
    case "koboldhoehle":
      TP->move( "/d/unterwelt/wurzel/uwelt/k1", M_TPORT); // Gen. v. Wurzel
      break;
    case "toeter":
    case "toeters insel":
    case "akhar nth'tar":
    case "akhar nth tar":
    case "kaempfer":
    case "kaempferinsel":
      TP->move( "/d/inseln/toeter/room/wald/waldrand", M_TPORT);
      break;
//--- Neue Ziele (Jahr 2000) ---
    case "karategilde":
    case "fernwest":
    case "xian":
    case "funakoshi":
      log_file("swift/gilde/chaosteleport.log",
        sprintf("%s  %s nach Fernwest\n",
        ctime(time())[4..15],capitalize(geteuid(TP)) ));
      TP->move( "/d/fernwest/li/xian/room/str_3", M_TPORT);  // Gen. v. Ulo
      break;

    default:
      write( "Nichts passiert...\n" );
      break;
    }
  return 1;
}
