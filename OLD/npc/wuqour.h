// wuqour.h
//
// Letzte Aenderung:
//
// 12.03.2019 It@Efferdland                      ueberarbeitet

#ifndef __CHAOS_WUQOUR_H__
#define __CHAOS_WUQOUR_H__

#define W_HEAL 1
#define W_DEAF 2
#define W_POISON 3
#define W_FROG 4
#define W_EVIL 5
#define W_DEMON 6
#define W_BLIND 7

#define HEAL_ARRAY ({\
"Wuqour starrt dich unglaeubig an und faengt dann an, wie ein Verrueckter zu\n"+ \
"lachen.\n",8, \
"Wuqour lacht: Eine Heilung willst du ?? Du bist ein Krieger des Chaos, Du\n"+ \
"Wuqour lacht: brauchst solche Kinkerlitzchen nicht! Im Gegenteil, Dir taete\n"+ \
"Wuqour lacht: mal eine rechte Bestrafung gut!!!\n§"+ \
"Wuqour lacht: Eine Heilung willst du ?? Du bist eine Kriegerin des Chaos, Du\n"+ \
"Wuqour lacht: brauchst solche Kinkerlitzchen nicht! Im Gegenteil, Dir taete\n"+ \
"Wuqour lacht: mal eine rechte Bestrafung gut!!!\n", 14, \
"#Wuqour beschwoert finstere Maechte und entzieht Dir Lebensenergie.\n",10, \
"Wuqour grinst auf einmal schelmisch.\n",4, \
"Wuqour sagt: War nur ein kleiner daemonischer Scherz, wenn Du es unbedingt\n"+ \
"Wuqour sagt: willst werde ich Dich halt heilen.\n", 18,\
"*Wuqour beschwoert nochmal finstere Maechte, aber diesesmal anderer Art.\n"})

#define DEAF_ARRAY ({\
"Wuqour scheint daemonisch zu kichern. (Du bist ja taub!)\n",4, \
"Er schlaegt sich mit der Hand auf die Stirn, und faengt an, wild mit den\n"+ \
"Armen zu wedeln (Du verstehst nur Flughafen)\n",10, \
"Wuqour zeichnet ein Pentagramm, einen Bannkreis, huepft wie wild um das\n"+ \
"Pentagramm herum, und ploetzlich wird das Pentagramm von einem winzigen, \n"+ \
"schwarzen Strahl erleuchtet.\n", 14,\
"Du glaubst Deinen Augen nicht zu trauen, aber in dem Pentagramm steht\n"+ \
"tatsaechlich ein winziger, fies aussehender Mini-Daemon, der ploetzlich an\n"+ \
"Dir hochspringt, und bevor du es verhindern kannst, in Dein linkes Ohr\n"+ \
"kriecht.\n",16,\
"#Dir wird mulmig, und ploetzlich hoerst du es krachen und ein fuerchterlicher\n"+ \
"Schmerz faehrt Dir durchs Gehirn.\n",10, \
"#Gleich darauf zieht es nochmal schrecklich an Deinen Nerven.\n",8, \
"*Doch dann klettert der winzige Daemon aus Deinem rechten Ohr heraus und\n"+ \
"verpufft in einer eklig stinkenden Rauchwolke.\n"})
                                          
#define POISON_ARRAY ({\
"Wuqour starrt Dich an, und bruellt: Was, Dein Gift willst Du loswerden ???\n"+ \
"Eigentlich solltest Du dich ueber so etwas freuen, als ein echter\n"+ \
"Chaoskrieger!! Aber nagut, ich bin gutgelaunt, also werde ich Deinem Wunsch\n"+ \
"entsprechen.\n§"+ \
"Wuqour starrt Dich an, und bruellt: Was, Dein Gift willst Du loswerden ???\n"+ \
"Eigentlich solltest Du Dich ueber so etwas freuen, als eine echte\n"+ \
"Chaoskriegerin!! Aber nagut, ich bin gutgelaunt, also werde ich Deinem Wunsch\n"+ \
"entsprechen.\n", 10, \
"$Wuqour sagt: Folge mir nach Sueden.\n", 4,\
"Wuqour positioniert Dich an einer bestimmten Stelle im Raum.\n", 6, \
"Wuqour grinst und scheint einen imaginaeren Hebel zu betaetigen.\n", 4,\
"Etwas presst Dich zusammen. Du fuehlst Dich wie in eine Presse eingeklemmt.\n", 8,\
"#Die Presse quetscht und drueckt Dich total zusammen.\n", 6,\
"#Du ertraegst den Schmerz wie ein waschechter Krieger des Chaos.\n§"+ \
"Du ertraegst den Schmerz wie eine waschechte Kriegerin des Chaos.\n", 8, \
"*Endlich ist es vorbei, und Wuqour zeigt Dir einen Behaelter mit dem ganzen\n"+ \
"herausgepressten Gift von Dir.\n", 8,\
"Er schuettet es behutsam in einen anderen Behaelter.\n",6, \
"Er fuehrt Dich zurueck in die Halle.\n"})

#define FROG_ARRAY ({\
"Wuqour sagt: Argl, ein fieser Krieger des Chaos als Frosch?? Das kann nicht\n"+ \
"Wuqour sagt: angehen, ich kann zwar leider keinen entfrosche-Spruch, aber das\n"+ \
"Wuqour sagt: geht auch anders.\n§"+ \
"Wuqour sagt: Argl, eine fiese Kriegerin des Chaos als Frosch?? Das kann nicht\n"+ \
"Wuqour sagt: angehen, ich kann zwar leider keinen entfrosche-Spruch, aber das\n"+ \
"Wuqour sagt: geht auch anders.\n",14, \
"$Wuqour schiebt Dich vor sich her.\n",8, \
"Wuqour schnallt Dich auf der Streckbank fest.\n",10, \
"%Dann drueckt er einen bisher unscheinbaren Knopf, und ploetzlich erscheint\n"+ \
"vor dir eine wunderhuebsche (Igitt!) Prinzessin(WAAH!), die sich Dir mit\n"+ \
"geschmeidigen Bewegungen naehert.\n§"+ \
"%Dann drueckt er einen bisher unscheinbaren Knopf, und ploetzlich erscheint\n"+ \
"vor dir ein wunderhuebscher (Igitt!) Prinz(WAAH!), der sich Dir mit\n"+ \
"geschmeidigen Bewegungen naehert.\n",18, \
"Kurz vor Dir bleibt sie stehen, und beugt sich herab, um Dich zu kuessen.\n§"+ \
"Kurz vor Dir bleibt er stehen, und beugt sich herab, um Dich zu kuessen.\n§",8, \
"#Du bekommst die schiere Panik, der kalte Schweiss laeuft Dir den Ruecken\n"+ \
"runter.\n",10, \
"Sie beugt sich immer tiefer und tiefer, bis sie kurz vor deinem Froschmund\n"+ \
"ist.\n§"+ \
"Er beugt sich immer tiefer und tiefer, bis er kurz vor deinem Froschmund\n"+ \
"ist.\n",10, \
"*Du haelst das nicht laenger aus, mit einem irren Schrei bruellst du Deinen\n"+ \
"ganzen Schmerz heraus, bis es ein leises Plopp gibt.\n",14, \
"%Du schaust dich verwundert um, du bist ja gar kein Frosch mehr! Anscheinend\n"+ \
"hat Dich die pure Angst, etwas so eklig gutes zu tun, zurueckverwandelt.\n",10, \
"Beruhigt folgst du Wuqour zurueck zur Halle.\n"})

#define DEMON_ARRAY ({\
"Wuqour sagt: Deinen Chaosdaemon soll ich also wecken ? Nun gut, das kannst Du\n"+ \
"Wuqour sagt: haben, du Ausgeburt des Guten! Du bist wirklich das eklig\n"+ \
"Wuqour sagt: schoenste Geschoepf auf Erden. Sowas von einem heiligen\n"+ \
"Wuqour sagt: Charakter ist echt widerlich, man haette Dich nie in dieser\n"+ \
"Wuqour sagt: Gilde zulassen sollen! Wenn Dein Chaosdaemon wuesste, dass Du die\n"+ \
"Wuqour sagt: ganze Zeit daran denkst, _unschuldige_ Jungfrauen vor grausamen\n"+ \
"Wuqour sagt: Drachen und ueblen Todesrittern zu befreien, wuerde er\n"+ \
"Wuqour sagt: vermutlich sofort aus dir herausfahren!!!\n",20, \
"#Du spuerst einen furchtbaren Schmerz, als der Chaosdaemon in dir anfaengt zu\n"+ \
"rebellieren.\n",8, \
"*Der Daemon will sich anscheinend befreien, aber er kommt ohne deine Hilfe\n"+ \
"wohl nicht mehr heraus!\n"})
                      
#define BLIND_ARRAY ({\
"Wuqour starrt dich durchdringend an (zumindest glaubst Du das), dann nimmt er\n"+ \
"dich an der Hand (ihhhh).\n",4, \
"$Wuqour fuehrt Dich in einen anderen Raum.\n",8, \
"Wuqour schnallt Dich auf ein seltsames Bett.\n",10, \
"#Ploetzlich hoerst du ein komisch klingendes Summen, dann einen dumpfen\n"+ \
"Schlag.\n",12, \
"*Als du wieder erwachst, kannst Du wieder sehen. Jetzt fallen dir auch in\n"+ \
"einer Ecke des Raums, zwei Behaelter mit runden Dingern auf, die dich\n"+ \
"anzustarren scheinen. Auf dem einen steht Neu und auf dem anderen Gebraucht.\n",10, \
"Mit einer Gaensehaut schleichst du dich in die Halle zurueck...\n"})
                      
#define DEAMONS ({\
"intarbir","kruftur","ombatis","bhuturih","irkitis","tyoorthok","harkuhu",\
"graiop","flaxtri","tutszt","yrintri"})

#define DEAMON_TEXTS ({\
"Intarbir ist leicht zu beschwoeren. Er ist ein kleiner Daemon ohne grossen\n"+ \
"eigenen Willen. Wenn Du Dich nicht ganz daemlich anstellst, wird er Deinem\n"+ \
"Ruf Folge leisten und Dir zu Diensten sein. Hier musst Du nichts besonderes\n"+ \
"beachten.\n", \
"Kruftur ist ein Waschlappen. Er hat nicht die Kraft, sich Deinem Ruf zu widersetzen\n"+ \
"wenn Du Dich ordentlich ins Zeug legst. Durch den uralten Pakt ist\n"+ \
"er gezwungen, Dir zu dienen, und er hat nicht viel Kraft, dem zu widerstehen.\n", \
"Ombatis ist ein haessliches, ekelhaftes Biest. Dein Ruf nach ihm muss aehnlich\n"+ \
"aetzend sein. Beschimpfe ihn, sei arrogant, dass wird sein Interesse wecken.\n", \
"Bhuturih ist eine Schlampe. Sie kannst Du nicht einfach rufen. Sie musst Du\n"+ \
"locken, verfuehrerisch von dieser Dimension voller Diamanten und Maenner erzaehlen\n"+ \
", auf dass sie ihrer Gier nicht widerstehen kann.\n", \
"Irkitis ist schnell und dumm. Wenn Du ihn schnell und oft rufst, wird er Dich\n"+ \
"ignorieren, da er den Ruf vergisst, sobald er ihn gehoert hat. Nur wenn Du\n"+ \
"hartnaeckig bist, kannst Du ihn aus seiner Dimension reissen.\n", \
"Tyoorthok besitzt schon eine gewisse Macht. Er ist der maechtigste unter den\n"+ \
"Daemonen, welche nicht kaempfen koennen, und wird nur einem starken und\n"+ \
"maechtigen Ruf folgen. Du solltest die Schwierigkeit nich unterschaetzen,\n"+ \
"auch wenn Dir dieser Daemon nicht sofort das Herz aus der Brust reissen kann.\n", \
"Harkuhu ist ein Lichtdaemon, nicht sehr stark, aber schon beeindruckend\n"+ \
"maechtig. Er wird sich Deinem Ruf nur fuegen, wenn er merkt, dass Du starker\n"+ \
"bist als er. Also siehe Dich vor!\n", \
"Graiop ist stark und maechtig. Ein boesartiges Wesen. Wenn Du ihn beschwoerst,\n"+ \
"solltest Du schon ein Pentagramm gezeichnet haben, um Deinem Ruf den noetigen\n"+ \
"Nachdruck zu verleihen und Dich vor ungebetenen Gaesten zu schuetzen.\n", \
"Flaxtri ist aetzend und wirklich stark. Ohne ein gutes Pentagramm mit allen\n"+ \
"Extras solltest Du ihn niemals beschwoeren. Er ist so wild und gefaehrlich\n"+ \
"wie sein Element und wird Deinem Ruf nur folgen, wenn er wirklich keine Wahl\n"+ \
"mehr hat. Rufe Flaxtri nur, wenn Du wirklich stark und vorbereitet bist.\n", \
"Tutszt ist der Blutdaemon, und er lechzt nach eben jenem. Rueste Dich aus,\n"+ \
"sei stark, wenn Du ihn rufst. Tutszt wird alles tun, um Dir zu widerstehen\n"+ \
"und sich nicht Deinem Willen zu unterwerfen. Trage stets eine Waffe bei Dir,\n"+ \
"wenn Du ihn beschwoerst, denn oft wird er Dich angreifen, wenn Du ihn\n"+ \
"nicht optimal beschworen hast. Dein Ruf musst wahrhaft maechtig sein und\n"+ \
"bar jeder Furcht, um ihn zu beschwoeren.\n", \
"Du bist der Erzmeister des Chaos. Nur Deinem Ruf wird der maechtige Yrintri\n"+ \
"folgen, denn so will es der alte Pakt. Doch sei gewarnt, denn Yrintri ist\n"+ \
"noch sehr viel maechtiger als Tutszt, und es wird Dich jedes Quentchen Energie\n"+ \
"kosten, ihm Deinen Willen aufzuzwingen und ihn aus der Dimension zu\n"+ \
"reissen, ueber die er herrscht.\n"})

#define BHUTURIH_ARRAY ({"", \
"#Wuqour sagt: Dies hier ist Bhuturih, die Schlampe. Sie ist eine sehr\n"+ \
"Wuqour sagt: widerspenstige Daemonin, leistet aber halbwegs brauchbare\n"+ \
"Wuqour sagt: Dienste, wenn man ihre speziellen, typisch weiblichen Gelueste\n"+ \
"Wuqour sagt: befriedigt!\n", \
"#Bhuturih blickt Dich gierig an.\n", \
"#Wuqour sagt: Ich zeige Dir nun, wie man ihre Gelueste befriedigt.\n"+ \
"Wuqour grinst daemonisch.\n", \
"#Wuqour murmelt ein paar seltsam klingende Worte, die Du nicht verstehst,\n"+ \
"woraufhin er ploetzlich einiges Geld in den Haenden haelt.\n", \
"#Wuqour gibt das Geld an Bhuturih.\n", \
"",\
"#Wuqour sagt: Nun hast Du gesehen wozu die Schlampe da ist, %s.\n", \
"#Wuqour blickt Bhuturih durchdringend an und mit einem Fingerschnippen ist sie\n"+ \
"verschwunden.\n", \
"Eine suess duftende, chaotisch pulsierende Wolke schwebt auf Dich zu,\n"+ \
"durchdringt Dich mit lustvollen Gefuehlen und bereitet Dir kurzzeitig\n"+ \
"daemonische Freuden.\n",\
"#Wuqour sagt: Nun, Dir stehen die Dienste dieser Schlampe ab sofort zur\n"+ \
"Wuqour sagt: Verfuegung mit der Anrufung \"bhuturih\". Aber bedenke stets:\n"+ \
"Wuqour sagt: Ohne ihre Gelueste zu befriedigen wird Sie Dir ihre Faehigkeiten\n"+ \
"Wuqour sagt: verweigern!\n"}) 

#define FLAXTRI_ARRAY  ({\
"#Eine kleine Saeurepfuetze erscheint auf dem Boden.\n",\
"#Wuqour grummelt.\n", \
"#Wuqour ruft nach Igor, die Pfuetze wegzuwischen.\n", \
"", \
"Wuqour fluestert Dir zu: Hmm, ich habe zwar seit dem letzten Mal trainiert,\n"+ \
"Wuqour fluestert Dir zu: aber ich hab hier soviel Arbeit, da kommt man zu\n"+ \
"Wuqour fluestert Dir zu:  nix. }:(\n",\
"Wuqour macht erneut beschwoerende Gesten und ruft in das Chaos hinein.\n", \
"#Ein Saeureregen ergiesst sich von oben herab, aus dessen Bestandteilen sich\n"+ \
"rasch ein Daemon formt.\n", \
"", \
"#Wuqour grinst zufrieden.\n", \
"#Wuqour sagt: Nun, das hier ist Flaxtri, der Saeuredaemon. Er ist echt\n"+\
"Wuqour sagt: aetzend, wenn Du verstehst was ich meine :).\n", \
"#Wuqour sagt: Es gibt zwei Dinge die man bei Saeuredaemonen nie vergessen\n"+ \
"Wuqour sagt: sollte: Erstens sollte man sie nie knuddeln, es sei denn man\n"+ \
"Wuqour sagt: schuetzt sich davor. Und zweitens sind Saeuredaemonen\n"+ \
"Wuqour sagt: naturgemaess anfaellig gegen Wasser jeder Art. Deshalb achte\n"+ \
"Wuqour sagt: stets darauf ihn nie mit dieser Fluessigkeit in Kontakt zu\n"+\
"Wuqour sagt: bringen, es koennte passieren, das er sich sehr schnell\n"+ \
"Wuqour sagt: aufloest.\n", \
"#Wuqour sagt: Ansonsten ist Flaxtri ein maechtiger Kampfgefaehrte, der vor\n"+ \
"Wuqour sagt: allem dank seiner aetzenden Klauen sehr hilfreich ist.\n", \
"#Wuqour sagt: Nun, ich lasse ihn mal wieder 'verschwinden' :)\n", \
"#Wuqour verbannt Flaxtri mit einem Fingerschnippen, woraufhin nur eine kleine\n"+\
"Saeurepfuetze uebrig bleibt.\n", \
"Wuqour nimmt rasch eine kleine Phiole, fuellt sie mit der Saeure, und kippt\n"+ \
"sie ueber Dir aus, bevor Du was dagegen tun kannst. Seltsamerweise verspuerst\n"+ \
"Du jedoch keinerlei Schmerzen, im Gegenteil, irgendwie spuerst Du eine innere\n"+ \
"Bereicherung.\n", \
"#Wuqour sagt: Tut mir ueberhaupt nicht leid das getan zu haben, denn nun\n"+ \
"Wuqour sagt: kannst auch Du Flaxtri, den aetzenden Saeuredaemon beschwoeren.\n"}) 

#define GRAIOP_ARRAY   ({\
"#Ploetzlich fangen Wuqours Haende zu brennen an.\n", \
"#Wuqour schreit laut auf. Aber nicht vor Schmerz, sondern vor Ueberraschung.\n", \
"#Wuqour murmelt: Hmm, da habe ich wohl die falsche Formel gesprochen. Moment.\n", \
"#Wuqour wirbelt chaotisch mit seinen Haenden, murmelt seltsame, unheimlich\n"+ \
"klingende Worte.\n", \
"#Ein Flammenkreis erhebt sich rings um Wuqour aus dem Boden und umschliesst\n"+ \
"ihn vollstaendig.\n", \
"#Wuqour arglt.\n", \
"#Wuqour sagt: Verdammt, mit diesen brennenden Haenden geht das natuerlich\n"+ \
"nicht.\n", \
"#Wuqour murmelt wieder unheimlich klingende Worte, woraufhin sich das Feuer um\n"+ \
"seine Haende aufloest. Danach macht er noch einige beschwoerende Gesten, die\n"+ \
"den Flammenkreis zum versiegen bringen.\n", \
"#Wuqour murmelt: Also gut, auf ein neues!\n", \
"Wuqour ruft nun wieder mit bestimmender Stimme in das Chaos hinein.\n", \
"#Ein feuriger Strahl kommt von oben herab, es gibt eine kurze\n"+ \
"Miniatur-Explosion.\n", \
"", \
"#Wuqour seufzt.\n", \
"#Wuqour sagt: Ich muss wohl wieder mehr trainieren, bin ziemlich aus der\n"+ \
"Wuqour sagt: Uebung. Nun, egal, hier siehst Du jedenfalls Graiop, den\n"+ \
"Wuqour sagt: Feuerdaemon vor Dir. Er ist schon ein ziemlich maechtiger\n"+ \
"Wuqour sagt: Kampfdaemon, was nicht zuletzt an seiner Art liegt. Feuer ist\n"+ \
"Wuqour sagt: schliesslich eine maechtige Waffe. Aber pass auf, dass Du Dir\n"+ \
"Wuqour sagt: nicht die Finger an ihm verbrennst, seine Art befaehigt ihn zwar\n"+ \
"Wuqour sagt: dazu Raeume zu erhellen, aber man sollte nie mit Feuer spielen!\n", \
"#Wuqour meint: Hmm, da dies dein erster Kampfdaemon ist, der mit einer\n"+ \
"Wuqour meint: speziellen Schadensart angreift, willst Du vielleicht gerne eine\n"+ \
"Wuqour meint: Vorfuehrung davon haben. Nun, das laesst sich einrichten!\n", \
"#Wuqour macht beschwoerende Gesten und murmelt mysterioese Worte.\n", \
"", \
"#Wuqour befiehlt Graiop den Hasen zu toeten.\n", \
"#Wuqour sagt zufrieden: Feuer ist wirklich etwas maechtiges, wenn man es\n"+ \
"Wuqour sagt zufrieden: richtig einzusetzen weiss!\n", \
"#Wuqour schaut Graiop an, und meint: Aber dich brauche ich jetzt nicht mehr.\n", \
"#Wuqour verbannt Graiop mit einem Fingerschnippen.\n", \
"Eine winzige Flamme jagt aus den Ueberresten von Graiop auf Dich zu, und\n"+ \
"brennt sich in dein Gehirn ein, ohne jedoch Schmerzen bei Dir zu verursachen.\n"+ \
"Nun kannst Du wohl auch Graiop beschwoeren!\n"}) 

#define HARKUHU_ARRAY  ({\
"#Ein ungeheurer Lichtblitz blendet Dich. Du bist blind.\n"+ \
"Wuqour schreit laut auf.\n", \
"#Wuqour sagt: Verdammt, das war wohl ein bisschen zu stark.\n", \
"#Wuqour murmelt mysterioese Worte, und tut irgendwelche Dinge.\n"+ \
"Ein wohliges Gefuehl durchstroemt dich. Du kannst wieder sehen.\n", \
"#Wuqour seufzt.\n"+ \
"Wuqour sagt: Ich werde alt.\n", \
"Wuqour ruft noch einmal in das Chaos hinein.\n", \
"", \
"#Wuqour sieht zufrieden aus.\n"+ \
"Wuqour sagt: Dies ist Harkuhu, dein zweiter Kampfdaemon. Er schlaegt zwar\n"+ \
"Wuqour sagt: nicht ganz so stark zu wie Irkitis, dafuer hat er aber eine\n"+ \
"Wuqour sagt: groessere Ausdauer, und noch eine nuetzliche Eigenheit: Er ist\n"+ \
"Wuqour sagt: ein Lichtdaemon, und deshalb leuchtet er auch, also brauchst Du\n"+ \
"Wuqour sagt: mit ihm nie eine Fackel oder die Nachtsicht!\n", \
"#Wuqour sagt: Eine Kampfdemonstration von ihm ist eigentlich nicht noetig, es\n"+ \
"Wuqour sagt: ist besser wenn Du ihn selbst in Aktion erlebst, in dem Du ihn\n"+ \
"Wuqour sagt: in deinen Kaempfen gegen gute Gegner mitnimmst!\n", \
"#Wuqour schnippt mit den Fingern, woraufhin Harkuhu sich aufloest.\n", \
"Der Lichtblitz in dem er verschwunden ist, scheint auf dich zuzurasen, und\n"+ \
"durchdringt dein Gehirn.\n", \
"#Wuqour sagt: Nun ist es an Dir diesen Lichtkampfdaemon sinnvoll einzusetzen, \n"+ \
"%s, moege er Dir gute Dienste erweisen.\n"})

#define INTARBIR_ARRAY ({\
"#Intarbir sagt: Meister, Du hast mich gerufen?\n", \
"#Wuqour sagt: Ja, Intarbir. Zeige %s was Du kannst!\n", \
"", \
"#Wuqour sagt: Nun gut, Du hat nun gesehen was Intarbir kann, jetzt wirst Du\n"+ \
"Wuqour sagt: seine chaotische Essenz in Dich aufnehmen!\n", \
"#Wuqour verbannt Intarbir mit einem Fingerschnippen.\n", \
"Eine kleine chaotisch pulsierende Wolke schwebt von der Stelle an der eben\n"+ \
"noch Intarbir stand, auf Dich zu, durchdringt Dich, erfuellt Dich!\n", \
"#Wuqour sagt: Du bist nun bereit den Daemon Intarbir fuer Dich zu\n"+ \
"Wuqour sagt: beschwoeren, moege er Dir gute Dienste erweisen (wenn nicht,\n"+ \
"Wuqour sagt: schick den verdammten Daemon zu mir!).\n", \
"#Wuqour sagt: Achja, rufen kannst Du ihn mit dem Befehl \"intarbir\", aber\n"+ \
"Wuqour sagt: benutze sicherheitshalber ein Pentagramm nebst Bannkreis.\n"}) 

#define IRKITIS_ARRAY  ({"", \
"#Wuqour arglt.\n", \
"#Wuqour schnippt mit dem Finger. Der Wirbelwind verschwindet.\n", \
"#Wuqour grummelt, und ruft noch einmal in das Chaos hinein.\n", \
"#Ein Daemon, schnell wie der Wind, kommt einem Schatten gleich hereingerannt.\n", \
"", \
"#Wuqour nickt Dir zufrieden zu.\n", \
"#Wuqour sagt: Nun, dies hier ist ein sehr wichtiger Daemon, %s,\n"+ \
"Wuqour sagt: denn es wird dein erster Kampfdaemon sein. Irkitis ist schnell\n"+ \
"Wuqour sagt: wie der Wind und wird Dich gut im Kampf unterstuetzen. Seine\n"+ \
"Wuqour sagt: Ausdauer ist allerdings begrenzt, also achte stets auf seine\n"+ \
"Wuqour sagt: Verfassung (dieser Tipp gilt natuerlich fuer alle Daemonen).\n"+ \
"Wuqour sagt: Hier eine kurze Vorfuehrung seiner Staerke:\n", \
"#Wuqour murmelt magische Worte. Ein niedliches Huhn huepft herein.\n", \
"#Wuqour befiehlt Irkitis das Huhn zu toeten!\n", \
"#Wuqour sagt: Nun, das duerfte als Vorfuehrung reichen.\n", \
"#Wuqour verbannt Irkitis mit einem Fingerschnippen.\n", \
"Ein zurueckgebliebener Schatten senkt sich auf Dich und durchdringt dich.\n", \
"#Wuqour sagt: Gut, Du kannst nun auch Irkitis, deinen ersten Kampfdaemon\n"+ \
"Wuqour sagt: beschwoeren, aber wenn Du ihn ernsthaft brauchst, bedenke\n"+ \
"Wuqour sagt: immer, ein Pentagramm nebst Bannkreis fuer die Beschwoerung\n"+ \
"Wuqour sagt: zu benutzen!\n"}) 

#define KRUFTUR_ARRAY  ({\
"#Kruftur sagt: Meister, Gnaaade!\n"+ \
"Wuqour sagt: Sei still, du Wurm! Ich will dass Du %s Dein Koennen\n"+ \
"Wuqour sagt: beweist! Schaetze einfach irgendetwas fuer Ihn ein, das er\n"+ \
"Wuqour sagt: dabei hat!\n", \
"", \
"#Wuqour sagt: %s, Du hast nun mit eigenen Augen gesehen, was dieser\n"+ \
"Wuqour sagt: Wurm von Denkdaemon zu leisten imstande ist. Die Maechte\n"+ \
"Wuqour sagt: des Chaos werden dafuer sorgen, dass er Dir immer gut zu\n"+ \
"Wuqour sagt: Diensten ist, nicht wahr Kruftur?\n", \
"#Wuqour grinst Kruftur diabolisch an.\n"+ \
"Kruftur sagt mit zittriger Stimme: Natuerlich, Meister!\n", \
"#Wuqour lacht abfaellig, und verbannt Kruftur mit einem Fingerschnippen.\n", \
"Eine kleine chaotisch pulsierende Wolke schwebt von der Stelle an der\n"+ \
"eben noch Kruftur stand, auf Dich zu, durchdringt Dich, erfuellt Dich!\n", \
"#Wuqour sagt: Der Daemon Kruftur steht Dir ab sofort fuer Deine boesen\n"+ \
"Wuqour sagt: Zwecke zur Verfuegung. Du rufst ihn einfach mit dem Befehl\n"+ \
"Wuqour sagt: \"kruftur\". Aber bedenke: Es ist immer besser einen Daemon\n"+ \
"Wuqour sagt: mit Pentagramm und Bannkreis zu beschwoeren, selbst wenn\n"+ \
"Wuqour sagt: es nur ein kleiner Wurm wie Kruftur ist.\n"})
                         
#define OMBATIS_ARRAY  ({\
"#Ploetzlich faengt es an nach Schwefel zu stinken.\n", \
"#In einer eklig aussehenden Wolke materialisiert ein furchtbar fetter und\n"+ \
"haesslicher Daemon.\n", \
"#Wuqour grinst gemein.\n"+ \
"Wuqour sagt: Ahh, Ombatis, einer meiner Lieblinge. Ombatis ist in seinem\n"+ \
"Wuqour sagt: speziellen Fachgebiet ein sehr maechtiger Daemon, er kann\n"+ \
"Wuqour sagt: naemlich nerven, das man sich seinen Tod herbeiwuenscht\n"+ \
"Wuqour sagt: (wobei das Ombatis nicht stoeren wuerde).\n", \
"#Ombatis stupst Wuqour an, und meint grinsend: Hey, Wuqour, Dich habe\n"+ \
"ich schon lange nicht mehr so richtig genervt.\n", \
"#Wuqour erbleicht fuer Sekundenbruchteile.\n", \
"#Wuqour sagt: Du gehorchst mir, ist das klar?\n", \
"#Ombatis schuettelt grinsend den fetten Kopf.\n", \
"#Ombatis sagt: Hey, Wuqour, du erwartest ja Kruuolq, Achtarch und huch,\n"+ \
"Ombatis sagt: wie eklig, sogar Arkshat ???\n", \
"#Ombatis tritt Wuqour ans Schienbein.\n", \
"#Wuqour arglt.\n", \
"#Wuquor sagt: Verdammt, da muss was bei der Beschwoerung schiefgelaufen\n"+ \
"Wuquor sagt: sein. Hrmpf, egal, hattest Du eben ne spezielle\n"+ \
"Wuquor sagt: Vorfuehrung seiner Kuenste.\n", \
"#Wuqour murmelt duestere Worte der Macht, woraufhin Ombatis in einer\n"+ \
"ekligen Schwefelwolke verpufft.\n", \
"Die Schwefelduenste steigen Dir in die Nase, dringen bis in dein\n"+ \
"Gehirn vor.\n", \
"#Wuqour sagt: Auch wenn diese Demonstration etwas misslungen war, so\n"+ \
"Wuqour sagt: kannst Du ab sofort trotzdem die Dienste dieses\n"+ \
"Wuqour sagt: widerspenstigen Daemons fuer Dich beanspruchen. Aber sei\n"+ \
"Wuqour sagt: gewarnt: Du kannst Dir damit viele Feinde machen (was\n"+ \
"Wuqour sagt: Du eigentlich ja auch sollst :))\n"})

#define TUTSZT_ARRAY   ({\
"#Ploetzlich ergiesst sich ein Schwall aus Blut ueber Wuqour.\n", \
"#Wuqour flucht: Manor, Sarrss enx Vmoepouel.\n", \
"#Wuqour ruft Igor herbei, der ihn sofort von dem Blut reinigt.\n", \
"#Wuqour sagt: Nicht das ich etwas gegen Blut haette, im Gegenteil, Blut\n"+ \
"Wuqour sagt: ist nicht nur schoen, sondern auch wichtig. Aber es\n"+ \
"Wuqour sagt: ueberall am Koerper zu haben kann auf die Dauer dann doch\n"+ \
"Wuqour sagt: stoerend sein.\n", \
"#Wuqour sagt: Nun, dann werde ich die Beschwoerung etwas verfeinern.\n", \
"#Wuqour fuchtelt chaotisch mit den Haenden herum, vollfuehrt einen\n"+ \
"kurzen teuflischen Tanz und murmelt daemonisch klingende Woerter.\n", \
"#Ein blutroter Strahl schiesst auf den Boden herab.\n", \
"", \
"#Wuqour kichert daemonisch.\n", \
"#Wuqour grinst Dich an: Du hast hier einen der maechtigsten Daemonen\n"+ \
"Wuqour grinst Dich an: ueberhaupt vor Dir: Tutszt, den Blutdaemon!\n", \
"#Tutszt schaut blutgierig drein.\n", \
"#Wuqour sagt: Tutszt ist ein Daemon der nur sehr schwer unter\n"+ \
"Wuqour sagt: Kontrolle zu halten ist, vor allem wenn er einmal Blut\n"+ \
"Wuqour sagt: gewittert hat. Deshalb sorge dafuer das er moeglichst\n"+ \
"Wuqour sagt: nie zuviel von deinem eigenen Blut zu sehen bekommt,\n"+ \
"Wuqour sagt: denn sonst kann ich fuer nichts mehr garantieren!\n", \
"#Wuqour sagt: Tutszt dafuer aber auch ein SEHR maechtiger\n"+ \
"Wuqour sagt: Kampfdaemon, der hier nur noch von Yrintri\n"+ \
"Wuqour sagt: uebertroffen wird. Seine Blutgier ist so gross, das er\n"+ \
"Wuqour sagt: sich ohne Ruecksicht auf deine Gegner stuerzen wird, um\n"+ \
"Wuqour sagt: ihr Blut zu bekommen. Seine Ausdauer und seine\n"+ \
"Wuqour sagt: Kampfstaerke uebertrifft die von allen niedrigeren \n"+ \
"Wuqour sagt: Daemonen bei weitem. Eine Vorfuehrung hiervon halte ich\n"+ \
"Wuqour sagt: nichtmal fuer noetig, Du wirst es sehen sobald Du ihn\n"+ \
"Wuqour sagt: neben Dir im Kampf hast!\n", \
"#Wuqour verbannt Tutszt mit einem Fingerschnippen.\n", \
"#Wuqour erklaert: Wenn ein Blutdaemon wie Tutszt stirbt, bleibt\n"+ \
"Wuqour erklaert: immer eine Blutlache uebrig, sozusagen eine Art\n"+ \
"Wuqour erklaert: daemonischer Ueberreste. Auch das ist einmalig bei\n"+ \
"Wuqour erklaert: Daemonen, und dieses Blut musst Du nun trinken!\n", \
"#Wuqour starrt dich kurz durchdringend an.\n", \
"#Wuqour grinst daemonisch.\n", \
"#Wuqour sagt: Nun, Du bist ein Meister des Chaos, der jetzt auch den\n"+ \
"Wuqour sagt: Meisterdaemon beherrscht. Nun fehlt Dir nur noch ein\n"+ \
"Wuqour sagt: Daemon!\n"})

#define TYOORTHOK_ARRAY ({\
"#Ein uralt aussehender Daemon mit !Bart! erscheint direkt vor Dir.\n", \
"Er blickt dich fordernd an.\n", \
"#Wuqour erklaert: Dies ist Tyoorthok, der Weise. Behandel ihn seinem\n"+ \
"Wuqour erklaert: Alter entsprechend, und er wird dir stets wichtige\n"+ \
"Wuqour erklaert: Auskuenfte erteilen. Ich gebe dir mal ein Beispiel\n"+ \
"Wuqour erklaert: davon!\n", \
"#Wuqour befiehlt Tyoorthok %s zu analysieren.\n", \
"Tyoorthok schaut dich kontrollierend an.\n", \
"#Wuqour grinst.\n", \
"#Wuqour sagt: Das ist aber noch nicht alles, was dieser weise, alte\n"+ \
"Wuqour sagt: Daemon kann. Manche sagen zwar, es steht im Gegensatz\n"+ \
"Wuqour sagt: zu unserer Gildenphilosophie, und da moegen Sie\n"+ \
"Wuqour sagt: teilweise sogar Recht haben, aber nichtsdestotrotz\n"+ \
"Wuqour sagt: kann dieser Daemon auch Krankheiten heilen. Umsonst\n"+ \
"Wuqour sagt: macht er dies allerdings nicht, obwohl er als Weiser\n"+ \
"Wuqour sagt: eigentlich materielle Dinge ablehnen muesste (aber er\n"+ \
"Wuqour sagt: ist eben ein Daemon, und damit kein Vergleich). Also\n"+ \
"Wuqour sagt: trage stets ein paar Muenzen mit Dir herum wenn Du\n"+ \
"Wuqour sagt: seine besonderen Dienste beanspruchen willst!\n", \
"#Wuqour schnippt kurz mit den Fingern und verbannt Tyoorthok.\n", \
"Eine Welle konzentrierter Weisheit durchflutet dich kurz. Du\n"+ \
"spuerst dass Du diesen Daemon nun beschwoeren kannst!\n"})

#define YRINTRI_ARRAY   ({\
"#Nichts passiert.\n", \
"#Wuqour tippt mit dem Fuss auf den Boden.\n", \
"#Immer noch nichts passiert.\n", \
"#Wuqour flucht.\n", \
"#Wuqour sagt: Ach, VERDAMMT. Immer vergesse ich, dass ich ja nicht der\n"+ \
"Wuqour sagt: Erzmeister bin!\n", \
"Wuqour starrt Dich durchdringend an und zwingt dich zu: 'yrintri'.\n", \
"#Eine Wolke puren Chaos erscheint.\n", \
"#Langsam materialisiert sich daraus ein furcherregend aussehender\n"+ \
"Daemon.\n", \
"Wuqour grinst Dich an.\n", \
"#Wuqour deutet auf den Daemon.\n", \
"#Wuqour sagt: Yrintri, der maechtigste Daemon in den Diensten des Chaos. Einer\n"+ \
"Wuqour sagt: der letzten existierenden Wandlerdaemonen. Du kannst ihm \n"+ \
"Wuqour sagt: befehlen mit allen uns moeglichen magischen Schadensarten\n"+ \
"Wuqour sagt: anzugreifen! Doch das ist noch nicht alles! Denn Yrintri ist\n"+ \
"Wuqour sagt: auf eine so starke Weise mit dem Chaoserzmeister verbunden, das\n"+ \
"Wuqour sagt: er sich, solltest Du einmal in grosse Lebensgefahr sein, vor\n"+ \
"Wuqour sagt: Dich werfen wird um Dein Leben mit seiner Existenz zu \n"+ \
"Wuqour sagt: beschuetzen! Darum veraergere ihn besser nie, denn wenn Du das\n"+ \
"Wuqour sagt: tust, hast du einen SEHR maechtigen und starken Feind gegen\n"+ \
"Wuqour sagt: dich. Ich gebe dir mal ein Beispiel seiner Kraft!\n", \
"#Wuqour murmelt beschwoerende Worte, fuchtelt chaotisch mit den Haenden herum.\n", \
"#Er versucht sofort zu fliehen, jedoch ist er in einer Art Aura eingehuellt,\n"+ \
"die ihm verweigert zu fliehen. Hehe.\n", \
"#Wuqour grinst: Hehe, dies ist ein Mann heiligen Charakters, dem es nicht\n"+ \
"Wuqour grinst: schmecken wird, mit unheiligen Klauen angegriffen zu werden!\n", \
"#Wuqour befiehlt Yrintri wandel dich zu Boese.\n", \
"#Yrintri blickt Wuqour an, und bruellt auf daemonisch irgendwelche Worte.\n", \
"#Wuqour grummelt: Verdammt, schon wieder vergessen, dass Yrintri nur dem\n"+ \
"Wuqour grummelt: Erzmeister gehorcht!\n", \
"Wuqour zwingt Dich zu: befehle Yrintri wandel dich zu Boese.\n", \
"Wuqour zwingt dich zu: befehle Yrintri toete Mann.\n", \
"", \
"#Wuqour kichert boesartig.\n", \
"#Wuqour schnippt mit den Fingern, schafft es aber nicht sofort Yrintri zu\n"+ \
"verbannen.\n", \
"", \
"#Wuqour bruellt wuetend ein Wort, welches Dir Schmerzen zufuegt.\n", \
"#Wuqour sagt stolz: Siehst Du, Yrintri ist wirklich etwas besonderes. Du\n"+ \
"Wuqour sagt stolz: kannst stolz auf deinen Titel und deine\n"+ \
"Wuqour sagt stolz: Erzmeisterfaehigkeiten sein!\n"})

#endif
