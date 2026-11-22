
/* Master der Chaos-Gilde, der die Pruefungen zu den einzelnen Stufen 
   regelt, erstellt die Top-Liste der Gilde und verwaltet die Duell 
   zur Ermittlung des Erzmeister.  */

#include "gilde.h"
#include <properties.h>
#include <new_skills.h>
#include <wizlevels.h>
#include <moving.h>


mapping mitglieder;
string erzmeister; // Der Erzmeister des Chaos (es kann nur einen geben)  
string exerz;
string *duellier; // Die Duellanten um den Erzmeistertitel

int duellzeit;

void create()
{        
  seteuid( getuid(this_object())); 
  if( !restore_object( CHAOS_GILDEN_OBJ( "save" )))
  {
    mitglieder = ([]);
    erzmeister = "zardoz";
    duellzeit = 0;
    duellier = ({});
    return;
  }
restore_object( CHAOS_GILDEN_OBJ( "save"));
}          

int NeuesMitglied( string mitglied)
{
  if( member( mitglieder, mitglied) ) return -1;
  if( !find_player( mitglied)) return -2;
  mitglieder += ([ mitglied:([STUFE:1 ]) ]);
  save_object( CHAOS_GILDEN_OBJ( "save"));
  return 1;
}

int LoescheMitglied( string mitglied)
{
  if( !member( mitglieder, mitglied) ) return -1; 
  mitglieder -=([ mitglied ]);
  save_object( CHAOS_GILDEN_OBJ( "save"));
  return 1;
}


int SetzePruefung( string mitglied, int level)
{
  if( !member( mitglieder, mitglied) ) return -1;       
  if( mitglieder[mitglied][PRUEFUNG]== level) return 0;
  mitglieder[mitglied] += ([ PRUEFUNG: level ]);
  save_object( CHAOS_GILDEN_OBJ( "save"));
  return 1;
}

int SetzeAufgabe( string mitglied, string aufgabe)
{
  if( !member( mitglieder, mitglied) ) return -1;       
  if( mitglieder[mitglied][AUFGABE] == aufgabe) return 0;
  mitglieder[mitglied] += ([ AUFGABE: aufgabe ]);     
  save_object( CHAOS_GILDEN_OBJ( "save"));
  return 1;
}


int QueryPruefung( string mitglied, int level)
{
  if( !member( mitglieder, mitglied) ) return 0;
  if( mitglieder[mitglied][PRUEFUNG] == level) return 1;
  return 0;
}

int QueryAufgabe( string mitglied, string aufgabe)
{
  if( !member( mitglieder, mitglied) ) return 0;
  if( mitglieder[mitglied][AUFGABE] == aufgabe) return 1;
return 0;
  }

int SetzeStufe( string mitglied, int stufe )
{
  if( !member( mitglieder, mitglied) ) return 0;
  if( stufe <= 0) return 0;
  mitglieder[mitglied][STUFE] = stufe;
  return 1;
}

int LoescheMagier( string mitglied)
{
  if( !member( mitglieder, mitglied)) return 0;
  mitglieder -= ([ mitglied ]);
  return 1;
}

mapping QueryStufen()
{
  return mitglieder;
}

mixed AlleMitglieder()
{
  return m_indices(mitglieder);
}


string Liste()
{
  string *m;
  m = map_array(sort_array( m_indices( mitglieder ), #'>), #'capitalize);
  return break_string( "In der Gilde der Krieger des Chaos sind "+
  sizeof(mitglieder)+" "+
    "Spieler Mitglied:\n"+ implode( m, ", ")+".", 78, 0, 1);
}


string Relativ( int w)
{
  switch( w)
  {
    case 0..100:
      return "";
    case 101..200:    
      return "fast ";
    case 201..300:                
      return "bald schon ";
    case 301..400:   
      return "noch laengst nicht ";
    default:
      return "weit entfernt von ";  
  }
}
	


string CheckWert(int w)
{                       
  string s;
  switch( w )
    {
    case 0..600:
       s = Relativ(600-w);
       return s+"absolut superuebel";
    case 601..1100: 
       s = Relativ(1100-w);
      return s +"superuebel";
    case 1101..1600: 
       s = Relativ(1600-w);
      return s +"sehr sehr uebel";
    case 1601..2100: 
       s = Relativ(2100-w);
      return s +"sehr uebel";
    case 2101..2600: 
       s = Relativ(2600-w);
      return s +"uebel";
    case 2601..3100:
       s = Relativ(3100-w);            
       return  s+"sehr sehr schlecht";
    case 3101..3600: 
       s = Relativ(3600-w);
      return s +"sehr schlecht";
    case 3601..4100: 
       s = Relativ(4100-w);
      return s +"schlecht";
    case 4101..4600: 
       s = Relativ(4600-w);
      return s +"maessig";
    case 4601..5100: 
       s = Relativ(5100-w);
      return s +"durchschnittlich";
    case 5101..5600: 
       s = Relativ(5600-w);
      return s +"befriedigend";
    case 5601..6100: 
       s = Relativ(6100-w);
      return s +"sehr befriedigend";
    case 6101..6600: 
       s = Relativ(6600-w);
      return s +"recht gut";
    case 6601..7100: 
       s = Relativ(7100-w);
      return s +"ganz gut";
    case 7101..7600: 
       s = Relativ(7600-w);
      return s +"gut";
    case 7601..8100: 
       s = Relativ(8100-w);
      return s +"sehr gut";
    case 8101..8600: 
       s = Relativ(8600-w);
      return s +"ausgezeichnet";
    case 8601..9100: 
       s = Relativ(9100-w);
      return s +"hervorragend";            
    case 9101..9600: 
       s = Relativ(9600-w);
      return s +"perfekt";
    case 9601..10100:
      s = Relativ(10100-w); 
      return s + "absolut perfekt";
    default: return "absolut perfekt";
    }
return "Fehler im Raum-Zeit-Gefuege";
}
                                                     


mapping StufenAnforderung(int stufe)
{
mapping stufen;
stufen =([2:(["nachtsicht":4500]), 
    3:(["nachtsicht":5000,"dunkelheit":4000]),
    4:(["nachtsicht":5500, "dunkelheit":5000, "chaosruestung":4000, 
    "kontrolle":4500 ]), 
    
    5:(["nachtsicht":6000,"dunkelheit":4500,
    "chaosruestung":4500,"kontrolle":5000,"intarbir":4500,"bannzauber":4500,
    "schutz":4000 ]), 
    
    6:(["nachtsicht":6500,"dunkelheit":5000,
    "chaosruestung":4500,"kontrolle":5500,"intarbir":4500,"bannzauber":5000,  
    "schutz":4500, "chaosball":5000, "kruftur":4500 ]), 
    
    7:(["nachtsicht":6500,"dunkelheit":5500,"bhuturih":5000, 
    "chaosruestung":5000,"kontrolle":5500,"intarbir":5000,"bannzauber":5500,  
    "schutz":5500, "chaosball":5500, "chaosschaden":4500, "kruftur":5000, 
    "ombatis":4000 ]), 
    
    8:(["nachtsicht":7000,"dunkelheit":6000,"bhuturih":5500,"tyoorthok":4200,     
    "chaosruestung":5000,"kontrolle":5500,"intarbir":5500,"bannzauber":6000,  
    "schutz":6000, "chaosball":6500,"chaosschaden":5000, "kruftur":5500, 
    "irkitis":5000, "ombatis":4500, "verbanne":5500]), 
    
    9:(["nachtsicht":7000,"dunkelheit":6500,"bhuturih":6500,"tyoorthok":4600,     
    "chaosruestung":6000,"kontrolle":6000,"intarbir":6000,"bannzauber":6500,  
    "schutz":7000, "chaosball":7500, "chaosschaden":6500, "kruftur":6500, 
    "irkitis":6500, "ombatis":5000, "verbanne":6500, "finsternis":5500, 
    "harkuhu":6000 ]),
    
    10:(["nachtsicht":7500,"dunkelheit":7000,"bhuturih":7000,"tyoorthok":5200,
    "chaosruestung":7500,"kontrolle":8000,"intarbir":7000,"bannzauber":7000,
    "schutz":8000, "chaosball":9000, "chaosschaden":8000, "kruftur":7000,
    "irkitis":7000, "ombatis":5500, "verbanne":7000, "finsternis":7000,
    "harkuhu":6500, "graiop":6000, "binde":7000 ]),
                    
    11:(["nachtsicht":9000,"dunkelheit":7500,"bhuturih":7500,"tyoorthok":6200,
    "chaosruestung":8500,"kontrolle":8500,"intarbir":7500,"bannzauber":8500,
    "schutz":8500, "chaosball":9900, "chaosschaden":9000, "kruftur":7500,
    "irkitis":8000, "ombatis":6000, "verbanne":8000, "finsternis":8000,
    "harkuhu":7000, "graiop":6700, "binde":9000, "flaxtri":6700 ]),
  ]);
return stufen[stufe];
}

mixed ErhoehungsCheck(object pl)
{
int i, flag;
string *sprueche, s;
mapping stufen;
stufen = StufenAnforderung(pl->QueryProp( P_GUILD_LEVEL)+1);
sprueche = m_indices(stufen);
s = "";
for(i=sizeof(sprueche)-1;i>=0;i--)
    {
    if( pl->QuerySkillAbility(sprueche[i]) < stufen[sprueche[i]])
        {
        flag = 1;
        s += capitalize(sprueche[i])+" musst Du "+
            CheckWert(stufen[sprueche[i]])+", ";
        }
    }
if( flag )
    return "Du kannst Deine Stufe noch nicht erhoehen. Grund:\n"+
        s[0..<3]+" koennen.\n";
return 0;
}       


int ist_erz( object spieler)
{
  if( !spieler) return 0;
  if( getuid(spieler) == erzmeister ) return 1;
  return 0;
}     

string query_erzmeister()
{
  return erzmeister;
}                          

int query_duellzeit()
{
  return duellzeit;
} 


void set_duellzeit(int zeit)
{
  duellzeit = zeit;
}
                    
void low_exerz_level()
{
  object pl;
  if( !pl = find_player( exerz)) return;
  if( pl->QueryProp( P_GUILD) != "chaos" ) return;
  if( pl->QueryProp( P_GUILD_LEVEL) <= 11) return;
  pl->SetProp( P_GUILD_LEVEL, 11 );
  /* Zusaetzliche Abfrage eingebaut, da beim austreten aus der Gilde
   * offenbar nicht ueberprueft wird, ob der Spieler Erzmeister ist.
   * 21.10.97 - Silvana
   */
  if(mitglieder[exerz])mitglieder[exerz][STUFE] = 11;
  else exerz = 0;
  exerz = 0;
}

int set_erzmeister( object spieler)
{
  string msg;
  if( !spieler ) return -3;
  if( spieler->QueryProp( P_GUILD) != "chaos" ) return -2;
  if( spieler->QueryProp(P_GUILD_LEVEL) < 11 ) return -1;
  exerz = erzmeister;
  /* Zusaetzliche Abfrage eingebaut, da beim austreten aus der Gilde
   * offenbar nicht ueberprueft wird, ob der Spieler Erzmeister ist.
   * 21.10.97 - Silvana
   */
  if(mitglieder[exerz])mitglieder[exerz][STUFE] = 11;
  else exerz = 0;
  erzmeister = getuid(spieler);
  duellier = ({});
  duellzeit = time() + 432000;
  spieler->SetProp( P_GUILD_LEVEL, 12);
  msg = break_string( capitalize(erzmeister)+" ist "+
      (spieler->QueryProp(P_GENDER)==1?"der neue Erzmeister":
      "die neue Erzmeisterin")+" der Gilde!", 78, "Kruuolq teilt Dir mit: ");
  map_array( filter_array(map_array( m_indices(mitglieder), #'find_player),
    #'objectp), #'tell_object, msg );
  ZAR( msg );    
  this_object()->BerechneTopWert(spieler);
  if( stringp( exerz)) low_exerz_level();
  write_file(CHAOS_GILDEN_LOG("erzmeister"), 
    "Neuer Erzmeister: "+capitalize(erzmeister)+": "+dtime(time())+".\n");
  save_object( CHAOS_GILDEN_OBJ( "save"));
  return 1;
}   


void tell_meister(string msg)
{
  object *pl;
  int i;
  pl = filter_array( map_array( m_indices(mitglieder), #'find_player),
    #'objectp);
  for( i=sizeof(pl)-1;i>=0;i--)
  {
    if( pl[i]->QueryProp( P_GUILD_LEVEL) < 11) continue;
    tell_object( pl[i], msg );
  }
}
             
           

int AddKaempfer( object spieler)
{
  if( !objectp(spieler)) return 0;
  if( member( duellier, getuid(spieler)) != -1) return 0;
  duellier += ({ getuid(spieler) });
  return 1;
}
                                 

int LoescheKaempfer( object spieler)
{   
  string msg;
  object gewinner;
  if( !objectp( spieler)) return 0;
  if( member( duellier, getuid(spieler)) == -1) return 0;
  duellier -= ({ getuid(spieler) });       
  if( sizeof(duellier) == 1)
  {
    gewinner = find_player( duellier[0]);
    if( !objectp(gewinner)) return 0;
    if( !ist_erz(gewinner)) set_erzmeister( gewinner);
    else
    {
      msg = break_string( capitalize(erzmeister)+" ist "+
        (spieler->QueryProp(P_GENDER)==1?"der neue und alte Erzmeister":
        "die neue und alte Erzmeisterin")+" der Gilde!", 78, 
        "Kruuolq teilt Dir mit: ");
      map_array( filter_array(map_array( m_indices(mitglieder), #'find_player),
        #'objectp), #'tell_object, msg );
    }
    duellier = ({});
    gewinner->StopHuntingMode(1);
    gewinner->move( CHAOS_GILDEN_ROOM( "vc/stop+"+getuid(gewinner)), M_TPORT | M_NO_SHOW);
    (CHAOS_ARENA_ROOM( "no"))->aufraeumen();
    (CHAOS_ARENA_ROOM( "nw"))->aufraeumen();
    (CHAOS_ARENA_ROOM( "so"))->aufraeumen();   
    (CHAOS_ARENA_ROOM( "sw"))->aufraeumen();
    return 1;
  }
  msg = " -> -> "+capitalize(getuid(spieler))+" hat den Kampf beendet! <- <-\n";
  map_array( filter_array( map_array( duellier, #'find_player),#'objectp),
    #'tell_object, msg );
  return 1;
}

int let_him_die(object ob)
{
  call_other("/gilden/chaos","let_him_die",ob);
}

int IstKampf()
{
  if( sizeof(duellier)) return 1;
  return 0;
}


mixed query_duellier(){ return duellier; }

int loesche_duellier(string player)
{
  if( member(duellier, player) == -1 ) return 0;
  duellier -= ({ player });
  return 1;
}
  
void loesche_alle(){ duellier = ({}); }


void BerechneTopWert(object pl)
{
  string wer;  
  mapping skill;
  mixed zauber;
  int wert, w;
  if( !objectp(pl) ) return;
  if( pl->QueryProp( P_GUILD) != "chaos") return;
  wer = getuid(pl);
  if( IS_LEARNER(pl) || pl->QueryProp( P_TESTPLAYER) )
  {
    call_out( "LoescheMagier", 0, wer );    	
    return;
  }

  mitglieder[wer][STUFE] = pl->QueryProp( P_GUILD_LEVEL );
  skill = pl->QueryProp( P_NEWSKILLS );
  if( !mappingp(skill)) return;
  zauber = m_indices(skill);
  wert = 0;
  for(w = sizeof(zauber) -1; w >= 0; w--)
  {
    if( !mappingp(skill[zauber[w]])) wert += skill[zauber[w]];
    else wert += skill[zauber[w]][SI_SKILLABILITY];     
  }
  if( mitglieder[wer][ZAUBER] ) 
        mitglieder[wer][ZAUBER] = wert;
  else mitglieder[wer] += ([ ZAUBER:wert ]);
  save_object( CHAOS_GILDEN_OBJ("save" ));
}


void reset()
{             
  string msg, *mit;
  mapping liste;
  object erz, her, pl;
  int i, wert;
  int w, *z;
  z = ({});
  liste = ([]);
  mit = m_indices( mitglieder );
  if( stringp( exerz)) low_exerz_level();
  /*
  rm( CHAOS_GILDEN_OBJ( "cliste" ));
  for( i = sizeof(mit)-1;i>=0;i--)
  {
    wert = mitglieder[mit[i]][ZAUBER]*mitglieder[mit[i]][STUFE];
    if( !wert) continue;
    z += ({ wert });
    liste += ([ wert:mit[i] ]);
  }
  z = sort_array( z, #'<);
  write_file( CHAOS_GILDEN_OBJ( "cliste"), "Die Top-Liste der Krieger des Chaos! (Stand: "+explode( dtime(time()),", ")[2]+" )\n\n"+
  "Platz | Name     | Stufe |  Zauberfaehigkeit \n"+
    "---------------------------------------------------------------------------\n");
  w = sizeof(z);
  for( i = 0;i< w;i++)
  {
    if( i >= 99) break;
    write_file( CHAOS_GILDEN_OBJ( "cliste"), 
    	sprintf( " %-2d.   %-11s   %-2d    %-34s (%d)\n", (i+1),
    	capitalize(liste[z[i]]), mitglieder[liste[z[i]]][STUFE],
    	CheckWert( (z[i]/mitglieder[liste[z[i]]][STUFE])/20), 
    	  (z[i]/mitglieder[liste[z[i]]][STUFE]) ));
  } 
  */
  save_object( CHAOS_GILDEN_OBJ( "save" ));
}

