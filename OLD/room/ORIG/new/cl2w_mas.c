/*
   Feuerwehr@mg. Dieser Master fuer die Weg-Raeume der neuen Chaos-Gilde
   sorgt fuer das, was man einen global-Tell-Room fuer alle Weg-Raeume
   nennen koennte. Er arbeitet mit dem Weg-Standard-Raum cl2w_std zusammen
   und mit den Aus-bzw. Eingaengen in diese Wegraeume.
   
   Falls keine Spieler da sind, wird der call_out gestoppt (sonst kommt
   Padreic wie der Wind!!!!)
   
   Das Dingen hier soll spaeter ein paar fliegende Daemonen managen, 
   welche die Hoehle durchstreifen und in einem der Tuerme der Burg nisten.
   Wie gesagt ... spaeter.
*/



inherit "/std/thing";

#define DBF(x) if (find_player("feuerwehr")) tell_object(find_player("feuerwehr"),"CL2W: "+x+"\n");


object *players;            

void create()
{
  players = ({});
}


// Debug-Ausgaben
int infos() {
  string txt;
  int i;
  txt = "";
  if (sizeof(players))
    for (i=0;i<sizeof(players);i++)
      txt += getuid(players[i])+" ";
  DBF("Anzahl Spieler: " + sizeof(players)+txt);
  return 1;
}

// Spieler verlaesst den Weg.
int delete(object ob)
 {
   if (member_array(ob,players)>-1)
     players -= ({ob});
   if (!sizeof(players))
      while(remove_call_out("ausgaben") != -1);
   return 1;
}

// Spieler betritt nen Weg.
int add(object ob)
{
   if (member_array(ob,players)==-1)
      players += ({ob});
   if (sizeof(players) == 1)
     if (find_call_out("ausgaben") == -1)
       call_out("ausgaben",15+random(5));
   return 1;
}


// Tell_ROOM (fuer alle anwesenden Spieler :)
int ausgaben()
{
  int i;
  for (i=sizeof(players)-1;i>=0;i--)
    if (objectp(players[i]) && interactive(players[i]) && file_name(environment(players[i]))[0..28] == "/gilden/files.chaos/room/cl2w")
    {
       if (!random(3))    
       tell_object(players[i],
       ({"In der Ferne siehst Du einen schwarzen Schatten vorbeifliegen.\n",
         "Etwas verdunkelt ueber Dir den Himmel. Schnell ist es verschwunden.\n",
         "Kurz glaubst Du eine grosse Feldermaus knapp unter der Decke fliegen zu sehen.\n",
         "Ein daemonischer Schrei hallt von irgendwo zu Dir herab.\n",
         "Irgend etwas war dort eben hinter (ueber?) Dir. Du bist Dir ganz sicher.\n",
         "Du hoerst aus der Naehe ein merkwuerdiges Fluegelschlagen.\n"})[random(6)] );
    }
    else
       players -= ({players[i]});
  if (sizeof(players)>0)
      call_out("ausgaben",15+random(5));
}

object getPlayer() {
  if (sizeof(players)>0)
    return players[random(sizeof(players))];
  return 0;
}