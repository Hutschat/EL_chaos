
//
// Letzte Aenderung:
//
// xx.xx.xxxx Zardoz                   neu
// 17.03.2019 It@Efferdland            ueberarbeitet

#pragma no_inherit

#include def.h

inherit "std/thing";

protected void create()
{
  if(!clonep())
  {
    set_next_reset(-1);
    return;
  }
  ::create();
  SetProp(P_SHORT, "Ein daemonisches Woerterbuch");
  SetProp(P_LONG,
  "Du haeltst die zweite Ausgabe des legendaeren Klassikers\n"+
  "            LANGENSCHWEIT: ' DAEMONISCH-VERSTAENDLICH '\n"+
  "in den Haenden. Sie ist kostbar eingebunden und nun Seite fuer Seite\n"+
  "lesbar fuer den, welcher tiefer in die Mysterien der Daemonen hinab-\n"+
  "steigen moechte, als es gesund fuer ihn ist.\n");
  SetProp(P_NAME, "Woerterbuch");
  SetProp(P_GENDER, 0);
  SetProp(P_BUY_VALUE, 1700);
  SetProp( P_MATERIAL, ([ MAT_PAPER:100,]));
  SetProp(P_WEIGHT, 200);
  AddId(({ "buch", "woerterbuch", "daemonenbuch" }));

  AddCmd(({"lies", "lese", "les"}), "read");
}

static int read(string str)
{
  notify_fail("Was willst Du denn lesen ?\n");
  if (!str) return 0;
  if (this_object() == present(str,this_player()))
    return write("Du musst dieses Buch seitenweise lesen!\n"),1;
  switch (str)
  {
   case "seite 1":
   case "erste seite":
   case "seite 2":
   case "zweite seite":
                     
   write("\n");
   write("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
    +"|                                     ||Diese kleine Einfuehrung hat es sich |\n"
    +"|    Langenschweit-Woerterbuch        ||zum Ziel gemacht, die seltene und    |\n"
    +"|    -------------------------        ||schwere Sprache der Daemonen einem   |\n"
    +"|                                     ||breiten Interessentenkreis nahe zu   |\n"
    +"|    DAEMONISCH --                    ||bringen. Es enthaelt daher nur die   |\n"
    +"|                  VERSTAENDLICH      ||wichtigsten Begriffe und Ausdrucks-  |\n"
    +"|                                     ||weisen, die Sie im alltaeglichen Um- |\n"
    +"|                                     ||gang mit Daemonen staendig anwenden  |\n"
    +"|                                     ||und benutzen. Ein wesentlich umfang- |\n"
    +"|                                     ||reicheres und vollstaendigeres Werk  |\n"
    +"|              2. Auflage             ||finden sie natuerlich in der tollen  |\n"
    +"|                                     ||Langenschweit-Serie.                 |\n"
    +"|                                     ||                                     |\n"
    +"|+++++++++++++++++++++++++++++++++++++||Vorwort:                             |\n"
    +"|                                     ||-----------                          |\n"
    +"|Eine kleine Einfuehrung in die selt- ||In dieser kleinen Ausgabe wurden     |\n"
    +"|    same Sprache der Daemonen        ||extra die haeufigsten Woerter        |\n"
    +"|                                     ||zusammengestellt, um dem ge-         |\n"
    +"\\_____________________________________/\\_____________________________________/\n"
    );
       return 1;
       case "seite 3":
       case "dritte seite":
       case "seite 4":
       case "vierte seite":
       
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"|neigten Interessentenkreis einen     ||die Worte so aus, wie man sie        |\n"
             +"|leichteren Umgang mit Daemonen zu    ||schreibt.Das koennte aber manchmal zu|\n"
             +"|ermoeglichen. Auf Grusswoerter wie:  ||Verwechslungen fuehren, die sich nie |\n"
             +"|'Hallo, Hi, Wie gehts?..' wurde ver- ||ausschliessen lassen.                |\n"
             +"|zichtet, da Daemonen diese Worte aus ||                                     |\n"
             +"|dem Munde von Zwergen, Menschen oder ||DANKSAGUNG                           |\n"
             +"|Elfen (und auch den meisten Magiern) ||----------                           |\n"
             +"|als Beleidigung auffassen. SEI ALSO  ||                                     |\n"
             +"|GEWARNT! Nur weil Du ihre Sprache    ||Hiermit moechte ich die Gelegenheit  |\n"
             +"|sprichst, werden Daemonen nicht um-  ||wahrnehmen allen zu DANKEN, die      |\n"
             +"|gaenglicher! Sie verachten nun mal   ||diese Ausgabe erst ermoeglichten.    |\n"
             +"|alles Lebende.                       ||Unter grossen Opfern und zahlreichen |\n"
             +"|                                     ||Verlusten ist es dem umfangreichen   |\n"
             +"|Desweiteren wurde auf eine Laut-     ||Forscherteam gelungen, in die Kerker-|\n"
             +"|schrift verzichtet, da die Worte fuer||dimensionen vorzudringen und das     |\n"
             +"|menschliche (zwergische/elfische)    ||Reich der Daemonen aufzusuchen. Dabei|\n"
             +"|Kehlen nur sehr schwer aussprechbar  ||kam es leider zu einer direkten Aus- |\n"
             +"|sind. Im Zweifelsfalle spricht man   ||einandersetzung mit den Daemonen,    |\n"
             +"\\_____________________________________/\\_____________________________________/\n"
             );
       return 1;
       case "seite 5": 
       case "fuenfte seite":
       case "seite 6":
       case "sechste seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"|die unsere friedlichen Absichten ein-||Vorwort zur 2. Ausgabe:              |\n"
             +"|fach nicht verstehen wollten. Folgen-||                                     |\n"
             +"|de tapfere Forscher sind leider ein  ||Die Zeit steht nicht still. Alles    |\n"
             +"|Opfer dieser Expedition geworden:    ||veraendert sich. Laengst hat sich ein|\n"
             +"|                                     ||reissendes Interesse an Daemonen ent-|\n"
             +"|Bendeigid, Toeter, Mesirii, Sterber, ||wickelt, immer mehr verwegene Chaoten|\n"
             +"|Steve, Warlord, Kieselstein, Grimm-  ||wagen sich in die tiefen Kerkerdimen-|\n"
             +"|born, Gundur, Oetti, Pampers, Pantof-||sionen vor und bringen, falls sie je |\n"
             +"|fel, Khidar, Morgana, Caradhras, Sly-||wieder gesehen werden, grosses Wissen|\n"
             +"|fox, Slash und Kotzbrocken.          ||mit.                                 |\n"
             +"|                                     ||                                     |\n"
             +"|Gedenket den Helden der Forschung!   ||Das grosse Interesse und die vielen  |\n"
             +"|-----------------------------------  ||Anfragen brachten die Leute von Lan- |\n"
             +"|                                     ||genschweidt dazu, dieses kleine Woer-|\n"
             +"|Fuer die 2. Ausgabe expeditierten    ||terbuch ein wenig zu komplettieren   |\n"
             +"|und starben unter anderem:           ||und in schoen gebundener Form fuer   |\n"
             +"|Bierchen, Sting, Feuerwehr, Swift,   ||viel mehr Geld auf den Markt zu wer- |\n"
             +"|Tilly und viele 'zivile Verluste'... ||fen.                                 |\n"
             +"\\_____________________________________/\\_____________________________________/\n"
             );
       return 1;
       case "seite 7": 
       case "siebte seite":
       case "seite 8":
       case "achte seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| ambu          schwarz               || mimal kaspartar Herrchen             |\n"
             +"| Argfuk        Post                  || mimal kroeter  Huendchen             |\n"
             +"|                                     || Mimal Sufzk    Bierchen              |\n"
             +"| Armttr        Besitz                || mimal vitar    jetzt                 |\n"
             +"| A(a)rmttr     besitzen(d), haben    || mimal Vitar    Moment(s)             |\n"
             +"| Armtur-/i     Besitzer-/in          || mimal vitar    momentan,nun,sofort   |\n"

             +"|                                     || mimal Ymdel    Haendchen             |\n"
             +"| asutur        beschwoeren(d)        || Mimal Ymdelchen Fingerchen           |\n"
                 Avis          Vogel
             +"|                                     || chaola        schnell               |\n"
             +"|                                     || (C)chaoloe    (G)gut,gute,guten     |\n"
             +"| bimula        loeschen              || chaoputm      langsam               |\n"
             +"| bmlel         wem,wessen            || crant         dein(e)               |\n"
             +"|                                     || (C)cutralk    betreten,Betretung    |\n"
             +"| Bruchasut     Pentagramm            || drukck        morgen                |\n"
             +"| Bruchk        Daemon(s/es)          || ek            auch,wie              |\n"
                 Cruzio        Schmerz, Schmerzen
             +"| bruchtka      daemonisch            || enbkema       schliessen            |\n"
             +"| mimal         klein                 || erdasu        bekommen,bekommst     |\n"
             +"|                                     || exa           ende(n),Endes         |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 9": 
       case "neunte seite":
       case "seite 10":
       case "zehnte seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| (F)frumpf     (E)essen              || harus         sein(bin,bist,        |\n"
             +"| frumtlx       heut,heute            ||               seist,sind,...)       |\n"
             +"| fruual        waessrig              || hoech         sauber                |\n"
             +"| Fruual        Wasser                || hoechhoech    putzen                |\n"
             +"| Ghmlesn       Jagd,Jagdten,Jagens   || hohowuz       wuscheln              |\n"
             +"| Gmdemh        Schild,Schildes       || Hrumtels      Zwerg                 |\n"
             +"| Gmdler        Ruestung              || Humrm         Portal                |\n"
             +"| Gmdowe        Helm                  || hux           alt                   |\n"
             +"| Gmurs         Burg                  ||             |\n"
             +"| grrum         abwesend,fort,nicht,  || inark         im,in,ins             |\n"
             +"|               nichts, weg           || Inarkzzrusta  Eingeweide            |\n"
             +"| +grrumrisstars unmenschlich          || irimtus       finden                |\n"
             +"| +grrumtsacol   taeglich              || itram         rot                   |\n"
             +"| +Grrumtsacol   Tag                   ||                   |\n"
             +"| Grumm         Abwesenheit           ||                                     |\n"
             +"| +grrumtrtinark leer                  || Kaspar        Herr(ens/es)          |\n"
             +"| +grrumtrtinarkydel  ausnehmen        || kaspartar     herrschen             |\n"
             +"| har           ja                    || Kaspartar     Herrscher,Koenig      |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 11": 
       case "elfte seite":
       case "seite 12":
       case "zwoelfte seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| Kauz          Sau,Schwein           || krx           aus, heraus   
                                                        Licht         Lumus        |\n"
             +"| kauz          schweinisch           || loemuq        oeffne,oeffnen,offen  |\n"
             +"| klumsl        untergeben            || Lumkroz       Anflehen,Anflehung    |\n"
             +"| Klumslrm      Untergebener          || lumkroz       anflehen,flehen       |\n"
             +"| Klumslsm      Diener                || lumsloq       dienen,gehorchen      |\n"
             +"| Klumsltm      Sklave                || lumuar        gestern               |\n"
             +"| kra           zu,zum,zur            || luqosm        ergib,ergebene        |\n"
             +"| krant         euer,eur*,mein*,      || lyheart       maennlich             |\n"
             +"|               unser*,               || Lyheart/i     Mann/Frau             |\n"
             +"| Kroeter       Hund                  || Malitrr       Feuer                 |\n"
             +"| Kroeterwirmk  Katze                 || malitrr       feurig                |\n"
             +"| Kroszbruchk   Chaosdaemon           || +Malitrramoerl Feueraxt              |\n"
             +"| krotzlik      doof                  ||                                     |\n"
             +"| Krotzlikvacuhm  Dummkopf            ||                                     |\n"
             +"| Kroxx         Chaot                 ||                                     |\n"
             +"| Krozx         Chaos                 || Manok         Hoelle                |\n"
             +"| krozx         chaotisch(st)         || Manor         Tod                   |\n"
             +"| krunk         vor                   || Manorm        sterben               |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 13": 
       case "dreizehnte seite":
       case "seite 14":
       case "vierzehnte seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| Manorzulsch   Todesfalle            || +nyrks ooltesh  aengstlich,schrecklich|\n"
             +"| Manqurs       Pest                  || +nyrks Ooltesh  Aengstlichkeit,Angst, |\n"
             +"| maxkra        zuviel                ||               Schrecken             |\n"
             +"| Mdem          List                  || +nyrks zulsch   gefahrlos,harmlos     |\n"
             +"| mdem          listig                || oatar         osten,oestlich        |\n"
             +"| mesiry        blau                  || Oelkurs       Elf                   |\n"
             +"| moerkskal     mit,mittels           || oermks        fast                  |\n"
             +"| moerksl       in, ins, mit          || +oermks ambu    grau                  |\n"
             +"| Motz          Bild, Bildnis,Photo   ||                                     |\n"
             +"| murms         der,das               ||        |\n"
             +"| nurns         dem, die, den, des    || +Oermks lyheart-/i Junge-/Maedchen    |\n"
             +"| nagam         gelb                  || +oermks vitar   gleich                |\n"
             +"| Namakri       Farbe                 || ohoh          dies,diese,jene,jenes|\n"
             +"| namakri       farbig                ||               welche, welches,...   |\n"
             +"| natar         norden                || ohohpornsk    hier,hierher,hierhin  |\n"
             +"| nok           von,vom               || Onrurlas      Transport             |\n"
                 Nox           Dunkelheit, Finsternis
             +"| nurms         die,dem,den,des,dessen|| oolms         feige                 |\n"
             +"| nyrks         etwas,kein*,wenig     || Oolms         Feigheit              |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 15": 
       case "seite 16":
       case "sechzehnte seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| Ooltesh       Mut                   || + qulasar zulsch gefaehrlich           |\n"
             +"| ooltesh       mutig                 || +qulasar Zulsch Gefahr                |\n"
             +"| ox            ab                    || Quralsch      Drache                |\n"
             +"| pahh          an                    || Ramtalq       Eis                   |\n"
             +"| +Pahh Zzrusta   Haut                  || ramtalq       eisig                 |\n"
             +"| pfuck         ich,man               || Risstars      Mensch                |\n"
             +"| Pfuivmoepouel Kaempfer              || romtsch       leise,leises,ruhe,    |\n"
             +"| pllmda        hinterlistig          ||               ruhen,ruht,still,     |\n"
             +"| Pllmdem       Hinterlist            ||               Stille,...            |\n"
             +"| pollm         wie                   || +romtsch prrem  Friedhof              |\n"
             +"| pollmms       wieso,weshalb,warum   || romtz         laut                  |\n"
             +"| Pornsk        Raum                  || Romtzz        Laute                 |\n"
             +"| +pornsk inark Fruual  Insel            || Ronam         Leben                 |\n"
             +"| psiwqrx       jetzt, sofort         || ronam         leben                 |\n"
             +"| Qolsarm       Hoehle                || Rontk         Hebel                 |\n"
             +"| Qolsmm        Haus                  || rrum          gegen                 |\n"
             +"| Qulasar       Groesse               || rtt           fuer, wegen           |\n"
             +"| qulasar       gross                 || rufurt        gruen                 \n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 17": 
       case "siebzehnte seite":
       case "seite 18":
       case "achtzehnte seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| rummelmupf    arm                   || shirz         beschaeftigen(d)      |\n"
             +"| runzelbrum    komm,komme,kommt,..   || Shirz         Beschaeftigung        |\n"
             +"| sabbre        gern,gerne            || shockl        sing,singen,singend   |\n"
             +"| Sameln        Schwert               || shockllsl     schreien,schreiend    |\n"
             +"| Samklerl      Waffe                 || Shot          Lied                  |\n"
             +"| Samoerl       Axt                   || stoeckm       geh,gehe              |\n"
             +"| Samorx        Nadel                 || Strunz        Macht                 |\n"
             +"| samorx        spitz                 || strunz        maechtig              |\n"
             +"| samorxm       stechen               || Strunz!       Machtvolle(s)         |\n"
             +"| Samower       Messer                || Sufzk         Bier                  |\n"
             +"| sorrss        goettlich             || sufzzz        trink,trinken,trinkt  |\n"
             +"| Sorrss        Gott                  || tramsllwl     rede, reden           |\n"
             +"| Sarrss        Satan,Satanas,Teufel  || tramslm       sag,sagen,sagte,      |\n"
             +"| satar         noerdlich,suedlich,   ||               sprich,sprechen       |\n"
             +"|               sueden                || Tramslm       Sprache               |\n"
             +"| Schhhi        Wind                  || tramslsl      sprechen              |\n"
             +"| schhhi        windig                || tramslmx  !!    ruf,rufen,ruft        |\n"
             +"| shiffz        pinkeln               || trookasr      neu, neues            |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 19": 
       case "neunzehnte seite":
       case "seite 20":
       case "zwanzigste seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| troomt        nerven                || uiurks krotzlik    bescheuert        |\n"
             +"| trt           alle,alles,allerlei,  || uiurks qulasar     groesser          |\n"
             +"|               jede,jedem,viel,vieles|| uiurks stoeckm     rennen,renne      |\n"
             +"| trtinark      voll                  || uiurks trt     ausschliesslich,nur   |\n"
             +"| Trtweslmachx  Krieg                 || Uiurks vacuhm  Koepfchen             |\n"
             +"| trxu          ist                   || uiurks wesltam grausam               |\n"
             +"| trueyk        test,teste,Tester,... || Uiurks wesltam Grausamkeit           |\n"
             +"| Tsacol        Nacht                 || Ummsl         Seil                  |\n"
             +"| tsacol        nachts                || Ummwl         Schlaufe              |\n"
             +"| Tsacolschhhiz Nachtwind             || unar          koennen               |\n"
             +"| tzmus         wenn, wann            || urhoech       weiss                 |\n"
             +"| Ubelrs        Schwefel              || Urksvitar     Spaet,spaeter,        |\n"
             +"| uemsguel      nach,nachdem          ||               spaetestens           |\n"
             +"| uenkl         ein,einer,...         || uurks         sehr                  |\n"
             +"| uiurks        extrem                || uurkskrotzlik bloed                 |\n"
             +"| uiurks mimal winzig                || uurksstoeckm  lauf,laufen           |\n"
             +"| uiurks mimla Ummsl Faden              || uurksuiurksvitar zukuenftig         |\n"
             +"| uiurks mimla Yluars Dorf,Siedlung     || Uurksuiurksvitar Zukunft            |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 21": 
       case "einundzwanzigste seite":
       case "seite 22":
       case "zweiundzwanzigste seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| Vacuhm        Kopf                  || weslmge       toedlich              |\n"
                 Vipera        Schlange
             +"| Vitar         Zeit                  || wesltam       gemein                |\n"
             +"| vitarl        zeitig,zeitlich       || Wirmk         Feind                 |\n"
             +"| vmoepouel     kaempf,kaempfen,      || wit           was                   |\n"
             +"|               metzeln               || Wrijlksod     Gruss, Gruesse        |\n"
             +"| Vmoepouel     Kampf,Krieger,Metzler || Xarmst        Freund                |\n"
             +"| vmoepouel     nerven,nervig         || xarmst        freundlich            |\n"
             +"| vmoetuzz      suchen                || Xorchm        Gabe, Geschenk        |\n"
             +"| vmoewole      hau,hauen             || xorchm        geb,geben,gib,schenke,|\n"
             +"| Vmoewqld      Mord                  ||               verschenke            |\n"
             +"| vmoewqld      morde,morden          || xrox          aber,oder,und         |\n"
             +"|                  || xuh           jung, neu             |\n"
             +"| watar         westen                || Xurns         Verraeter             |\n"
             +"| watar         westlich              || Xurnszf       Verrat                |\n"
             +"| weselmsj      giftig                || xurnszf       verraten              |\n"
             +"| weselmteml    (heim)tueckisch       || Xxmrem        Gemeinheit            |\n"
             +"| Weselmu       Gift                  || Xxmremz       Gemeinheiten          |\n"
             +"| weslmachx     toete,toeten          || Ydel          Herstellung           |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       case "seite 23":
       case "dreiundzwanzigste seite":
       case "seite 24":
       case "vierundzwanzigste seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"| ydel          mach,machen,tun       || Zrlulurlyheart  Arbeiter            |\n"
             +"| ydeltrtinark  fuellen               || zulisch       fallen,stuerzen       |\n"
             +"| Yluars        Stadt                 || Zulisch       Sturz                 |\n"
             +"| Ymdel         Hand                  || Zulsch        Falle                 |\n"
             +"| Ymdelchen     Finger                || zulsch Zirlsch Fallgrube             |\n"
             +"| Ymdelkmera    Kralle                || Zurlism       Tor,Tuer              |\n"
             +"| Ymdelkmerm    Krallen               || zzak          anschaulich           |\n"
             +"| yorchm        nimm,nehmen           || Zzep          Arm                   |\n"
             +"| yque          dich,dir,du,mein,     || Zzrusta       Koerper               |\n"
             +"|               mich,mir, wir         || zzrusta       koerperlich           |\n"
             +"| zak           anschauen,ansehen,se- ||                                     |\n"
             +"|               hen,betrachten,schauen||                                     |\n"
             +"| Zirlsch       Grube                 ||                                     |\n"
             +"| zlah          als                   ||                                     |\n"
             +"| Zllmoer       Knopf                 ||                                     |\n"
             +"| Zllssr        Schalter              ||                                     |\n"
             +"| Zrlulur-/i    Arbeit                ||                                     |\n"
             +"| Zrlulurbhuturih Arbeiterin          ||                                     |\n"
             +"\\_____________________________________/\\_____________________________________/\n");

       return 1;
       case "seite 25":
       case "fuenfundzwanzigste seite":
       case "seite 26":
       case "sechsundzwanzigste seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
             +"|     GRAMMATIKALISCHER ANHANG        ||   Worte wird schon durch ihre Teil- |\n"
             +"|-------------------------------------||   worte klar. Wenn ein Daemon mit   |\n"
             +"|In der daemonischen Sprache gibt es  ||   Uiurksbuzzx droht, sollte man die |\n"
             +"|eine aeusserst interessante grammati-||   Beine in die Hand nehmen und      |\n"
             +"|kalische Struktur, von der hier nur  ||   schaun, wie weit man kommt.       |\n"
             +"|drei grundlegende Eigenheiten darge- ||                                     |\n"
             +"|stellt werden sollen.                ||                                     |\n"
             +"|1) Die Mehrzahl eines Wortes wird    ||                                     |\n"
             +"|   durch das Wort selbst und ein an- ||        Werxxox nok Yardoz.          |\n"
             +"|   gehaengtes 'z' erreicht. So heisst||        Werxxox nok Malitrrwirmk.    |\n"
             +"|   z.B. Haende: Ymdelz.              ||        Groszca Werxxox.             |\n"
             +"|2) Ein angehaengtes 'y' bezeichnet   ||        Werxxox nok Itrar.           |\n"
             +"|   die weibliche Form. So heisst     ||                                     |\n"
             +"|   Besitzerin: Armtury.
             
                3) angehaengtes x bezeichnet das Verb,
                   oder ein Adjectiv
                   Beschwoerung: Asutur
                   beschwoeren Asuturx              ||                                     |\n"
             +"|3) Ein Grossteil daemonischer Woer-  ||              Strunz!                |\n"
             +"|   ter werden teilweise aus Grund-   ||                                     |\n"
             +"|   Teilworten gebildet wie uiurks    ||                                     |\n"
             +"|   oder mimal. Die Bedeutung vieler  ||                                     |\n"
             +"\\_____________________________________/\\_____________________________________/\n");
       return 1;
       default : return 0;
     }

}































/*
       case "erste seite":
       write ("\n");
       write ("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"|                                     ||                                     |\n"
             +"\_____________________________________/\_____________________________________/\n"
             +"\n");
       return 1;
*/
