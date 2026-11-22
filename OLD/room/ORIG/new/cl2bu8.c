#include <properties.h>
#include "/gilden/files.chaos/gilde.h"
inherit CHAOS_GILDEN_ROOM("cl2bu_std");

#define BS(x) break_string(x,78)

create() {
  ::create();
  SetProp("chaos_sink_room",CHAOS_GILDEN_ROOM("cl3bu10"));
  SetProp(P_LIGHT,1);
  SetProp(P_INDOORS,0);
  SetProp(P_INT_SHORT,"In der chaotischen Burg");
  SetProp(P_INT_LONG,BS("Du befindest Dich in tiefster Dunkelheit. Um Dich "+
  "herum ist alles wie von einer schwarzen Decke bedeckt. Du siehst nicht "+
  "die Burg um Dich herum, oder den Platz nordwestlich von Dir. Du kannst "+
  "so gut wie garnichts von der Gasse erkennen, welche sich nach Suedosten "+
  "erstreckt, und von den Gebaeuden im Osten und Westen von Dir kannst Du "+
  "nicht mehr als etwas erahnen... Alles in allem ist es hier ziemlich "+
  "total absolut finster!"));
  AddDetail(({"boden"}),BS("Er ist schwarz, kaum zu erkennen. Du beugst "+
  "Dich seeehr weit herab, liegst fast auf ihm und kannst dann die pech"+
  "schwarzen Pflastersteine erkennen, mit denen er belegt wurde."));
  AddDetail(({"pflastersteine"}),BS("Sie scheinen pechschwarz zu sein. Ihre "+
  "sonstige Form ist nicht sonderlich Aufsehen erregend. Und bei ihrer "+
  "Farbe bist Du Dir auch nicht sonderlich sicher. In dieser Finsternis "+
  "sieht einfach alles pechschwarz aus..."));
  AddDetail(({"form"}),BS("Naja, welche Form werden Pflastersteine schon "+
  "haben... mal so mal so halt."));
  AddDetail(({"farbe","schwarz"}),BS("Alles hier ist so fuerchterlich "+
  "schrecklich schwarz. Es scheint keine andere Farbe zu existieren ... "+
  "Wie erschreckend ... und eintoenig..."));
  AddDetail(({"aufsehen"}),BS("Niemand wird hierherkommen und sagen : "+
  "'Oh, ein Pflasterstein!'"));
  AddDetail(({"niemand"}),BS("Niemand sagt: 'Hui, schick, ein Pflasterstein!'."));
  AddDetail(({"finsternis","dunkelheit"}),BS("Die Finsternis bedeckt Dich "+
  "wie eine schwarze, samtene Decke. Du kannst nicht weiter sehen als ... "+
  "als ... naja, eigentlich kannst Du wirklich total nix sehen. Ausser dem "+
  "einen oder anderen Schatten, kurz bevor Du wo gegen laeufst."));
  AddDetail(({"schatten"}),BS("Schatten sind schon Highlights in dieser "+
  "Burg. Ansonsten ist alles pech-, kohlraben-, unglaublich schwarz."));
  AddDetail(({"highlights"}),BS("Naja, Schatten als Highlights zu bezeichnen "+
  "sagt schon einiges ueber diese Burg aus."));
  AddDetail(({"wand","waende"}),BS("Dies hier ist ein Innenhof. Obwohl Du "+
  "Dir selbst da nicht so sicher bist. Es ist so verflucht dunkel hier, dass "+
  "drei Meter ueber Dir durchaus eine Decke sein koennte, Du wuerdest sie "+
  "nicht erkennen. Mannomann, ist das dunkel hier. Auf jeden Fall glaubst "+
  "Du nicht, dass es hier Waende gibt. Hoechstens Gebaeude."));
  AddDetail(({"meter"}),BS("Du weisst, was eine Decke ist. Aeh. Ein Meter. "+
  "Ich bin nicht ganz da..."));
  AddDetail(({"decke"}),BS("Eiiiine Decke mit zwei Bergen drunt im tiefen "+
  "weiten Meer. Aehm, nein, Moment. Decke. Decke. Decke. Da war was. Hmmm. "+
  "Decke. Moment. Gleich hast Dus. Decke. Ah. Genau. Du kannst sie nicht "+
  "sehen, denn es ist so verdammt finster hier. Die Finsternis umhuellt Dich "+
  "fast wie eine Decke. Jawohl."));
  AddDetail(({"insel","berge"}),BS("Neeeeh, sowas siehst Du hier nicht..."));
  AddDetail(({"moment"}),BS("Der Moment ist vorbei."));
  AddDetail(({"burg"}),BS("Du kannst von dieser Burg wirklich kaum etwas "+
  "sehen, denn es ist so fuerchterlich dunkel! Nun, es ist natuerlich die "+
  "chaotische Burg und die Burg der Chaosgilde und alles, aber ... also "+
  "es ist wirklich verdammt dunkel hier."));
  AddSpecialDetail(({"chaosgilde","chaos","chaoten"}),"det_chaos");
  AddDetail(({"hoehle"}),BS("Eine Hoehle! Wo? Nein, die kannst Du von "+
  "hier aus wirklich nicht erkennen, obwohl Du Dich sicherlich in ihr "+
  "befindest. Und selbst da beginnst Du schon zu zweifeln. In der Hoehle "+
  "war es zwar dunkel, aber NICHT so stockfinster wie hier."));
  AddDetail(({"eisberg","schwarzer eisberg"}),BS("Den siehst Du von "+
  "hier aus nicht, genau wie die Hoehle in diesem riesigen Eisberg. "+
  "Und das, obwohl Du Dich in dieser Hoehle befindest! Wow!"));
  AddDetail(({"platz"}),BS("Es ist ein grosser, machtig grosser Platz. "+
  "Er represaentiert die Maechte des Chaos und ihre Herrschaft auf dieser "+
  "Welt. Du waerest sicherlich fuerchterlich beeindruckt von diesem "+
  "ueberaus aussergewoehnlichen Platz, doch leider ist es so fuerchterlich "+
  "dunkel hier, dass Du absolut nichts davon erkennen kannst."));
  AddDetail(({"maechte","herrschaft","maechte des chaos","herrschaft","welt"}),
  BS("Diese Dinge sind als geheim eingestuft. Du bist nicht befugt, "+
  "darueber informiert zu werden. Geh weg."));
  AddDetail(({"dinge"}),BS("Davon brauchst Du nichts zu wissen."));
  AddDetail(({"gasse"}),BS("Das ist eigentlich keine richtige Gasse, "+
  "in der Du jetzt stehst, sondern der suedoestliche Auslaeufer des "+
  "grossen Platzes hier in der Burg. Die Gasse beginnt quasi etwa hier "+
  "und fuehrt nach Suedosten in die Dunkelheit. Und das hoert sich, um "+
  "ganz ehrlich zu sein, nicht sehr vertrauenerweckend an..."));
  AddDetail(({"gebaeude"}),BS("Es gibt hier sogar zwei Gebaeude. Eines "+
  "befindet sich oestlich, eines westlich von Dir. Natuerlich, aehm, aeh, "+
  "sind das nicht die einzigen Gebaeude in dieser grossen Burg, doch immer"+
  "hin sind es die einzigen, die Du von hier aus wenigstens erahnen kannst."));
  AddDetail(({"hauswaende","hauswand","mauer"}),BS("Hmmm. Ja, die Hauswaende "+
  " gehoeren zum oestlichen und westlichen Gebaeude."));
  AddDetail(({"westliches gebaeude","gebaeude 2"}),BS("Im Westen kannst Du "+
  "wirklich die Mauer eines Gebaeudes erahnen. Grosse Backsteine bilden "+
  "diese Mauer, und selbst diese Backsteine scheinen pechschwarz zu sein. "+
  "Du bist Dir dabei aber absolut nicht sicher. In dieser graesslichen "+
  "Dunkelheit kann man das wirklich nicht sagen."));
  AddDetail(({"steine","backsteine","backstein"}),BS("Die Steine (wie alle "+
  "Steine dieser Burg) sind pechschwarz und absolut uninteresant..."));
  AddDetail(({"oestliches gebaeude","gebaeude 2"}),BS("Es ist ein pech"+
  "schwarzes Gebaeude aus ebenso schwarzen Backsteinen. Doch halt! Eine "+
  "Tuer! Heureka! Und ueber der Tuer schimmert dunkel ein Symbol..."));
  AddDetail(({"heureka"}),BS("Das heisst sowas wie 'Hurra'."));
  AddDetail(({"hurra"}),BS("Heureka!"));
  AddDetail(({"symbol"}),BS("Das Symbol zeigt einen alten Chaoten. Er wirft "+
  "wild mit Chaosbaellen um sich, doch er sitzt in einem Rollstuhl und hat "+
  "einen total langen Bart. Du grinst in Dich herein. Hier enden sie also..."));
  AddDetail(({"chaot"}),BS("Wow, IST das ein alter Chaot!"));
  AddDetail(({"bart"}),BS("Dieser Bart ist wirklich lang. Wuerde er ihn "+
  "nicht derart zusammenknoten und um sich schlingen, waere er eine "+
  "Todesfalle..."));
  AddDetail(({"rollstuhl"}),BS("Coooool, ein Rollstuhl!"));
  AddDetail(({"chaosball","chaosbaelle"}),BS("Ein alternder Chaot wird nur "+
  "noch so gefaehrlicher."));
  
  AddSmells(SENSE_DEFAULT,BS(""));
  AddSounds(SENSE_DEFAULT,BS(""));
  
  AddExit("norden",CHAOS_GILDEN_ROOM("cl2bu6"));
  AddExit("nordwesten",CHAOS_GILDEN_ROOM("cl2bu5"));
  AddExit("suedosten",CHAOS_GILDEN_ROOM("cl2bu10"));
  
  NewDoor("osten",CHAOS_GILDEN_ROOM("cl2_altenheim"),({"tuer"}),
  ({D_NAME,"Tuer",
    D_GENDER,2,
    D_SHORT,"In das oestliche Gebaeude fuehrt eine %se Tuer.",
    D_LONG,BS("In dieser fuerchterlichen Dunkelheit kann man nicht mehr "+
    "erkennen, als das die Tuer da ist. Sie scheint schwarz zu sein, "+
    "aber das kann man von hier kaum erkennen."),
    D_FLAGS, DOOR_CLOSED|DOOR_NEEDKEY|DOOR_RESET_CL 
  }));
  
}



string det_chaos()
{
  if (this_player()->QueryProp(P_GUILD) == "chaos")
    return BS("Juhuuuu, es gibt nix cooleres!");
  return BS("Du verfluchst alles, was mit Chaos, Chaoten und dieser "+
  "verdammten Finsternis zu tun hat.");
}
