#pragma no_clone
#pragma no_inherit

#include "def.h"

mapping mitglieder;
string erzmeister; // Der Erzmeister des Chaos (es kann nur einen geben)
string exerz;
string *duellier; // Die Duellanten um den Erzmeistertitel

int duellzeit;

/* Die Herausforderung des Ex-Erzmeisters */
string herausforderer;
int    hfzeit;

void save_me()
{
  save_object(CHAOS_GILDEN_MASTER("save/gilden_master"));
}

mixed restore_me()
{
  return restore_object(CHAOS_GILDEN_MASTER("save/gilden_master"));
}

protected void create()
{
  seteuid(getuid(this_object()));
  if(!restore_me())
  {
    mitglieder     = ([]);
    erzmeister     = "zardoz";
    duellzeit      = 0;
    duellier       = ({});
    herausforderer = 0;
    hfzeit         = 0;
    return;
  }
  restore_me();
}

int NeuesMitglied( string mitglied)
{
  if(member(mitglieder,mitglied))
    return -1;

  if(!find_player(mitglied))
    return -2;

  mitglieder += ([ mitglied:([STUFE:1 ]) ]);

  save_me();

  return 1;
}

int LoescheMitglied( string mitglied)
{
  if(!member(mitglieder, mitglied))
    return -1;

  mitglieder -=([ mitglied ]);

  save_me();

  return 1;
}

int SetzePruefung( string mitglied, int level)
{
  if(!member(mitglieder, mitglied))
    return -1;

  if(mitglieder[mitglied][PRUEFUNG]== level)
    return 0;

  mitglieder[mitglied] += ([ PRUEFUNG: level ]);

  save_me();

  return 1;
}

int SetzeAufgabe( string mitglied, string aufgabe)
{
  if(!member(mitglieder, mitglied))
    return -1;

  if(mitglieder[mitglied][AUFGABE] == aufgabe)
    return 0;

  mitglieder[mitglied] += ([ AUFGABE: aufgabe ]);

  save_me();

  return 1;
}


int QueryPruefung( string mitglied, int level)
{
  if(!member(mitglieder, mitglied))
    return 0;

  if(mitglieder[mitglied][PRUEFUNG] == level)
    return 1;

  return 0;
}

int QueryAufgabe( string mitglied, string aufgabe)
{
  if(!member(mitglieder, mitglied))
    return 0;

  if(mitglieder[mitglied][AUFGABE] == aufgabe)
    return 1;

  return 0;
}

int SetzeStufe( string mitglied, int stufe)
{
  if(!member(mitglieder, mitglied))
    return 0;

  if(stufe <= 0) return 0;

  mitglieder[mitglied][STUFE] = stufe;

  return 1;
}

int LoescheMagier( string mitglied)
{
  if(!member(mitglieder, mitglied))
    return 0;

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

  m = map(sort_array(m_indices(mitglieder ), #'>), #'capitalize);

  return break_string( "In der Gilde der Krieger des Chaos sind "+
         sizeof(mitglieder)+" "+"Spieler Mitglied:\n"+ implode( m, ", ")+
         ".",0,0,1);
}

string CheckWert(int w)
{
  return (GUILD_HELPER->GH_skill_to_text(w,0));
}

mapping StufenAnforderung(int stufe)
{
  mapping stufen;

  stufen =
  ([
    2:(["nachtsicht":      4500 ]),

    3:(["nachtsicht":      5000,
        "dunkelheit":      4000 ]),

    4:(["nachtsicht":      5500,
        "dunkelheit":      5000,
        "chaosruestung":   4000,
        "kontrolle":       4500 ]),

    5:(["nachtsicht":      6000,
        "dunkelheit":      4500,
        "chaosruestung":   4500,
        "kontrolle":       5000,
        "bannzauber":      4500,
        "schutz":          4000,
        "orakeldaemon":    4500 ]),

    6:(["nachtsicht":      6500,
        "dunkelheit":      5000,
        "chaosruestung":   4500,
        "kontrolle":       5500,
        "bannzauber":      5000,
        "schutz":          4500,
        "chaosball":       5000,
        "orakeldaemon":    4500 ]),

    7:(["nachtsicht":      6500,
        "dunkelheit":      5500,
        "chaosruestung":   5000,
        "kontrolle":       5500,
        "bannzauber":      5500,
        "schutz":          5500,
        "chaosball":       5500,
        "chaosschaden":    4500,
        "orakeldaemon":    5000 ]),

    8:(["nachtsicht":      7000,
        "dunkelheit":      6000,
        "chaosruestung":   5000,
        "kontrolle":       5500,
        "bannzauber":      6000,
        "schutz":          6000,
        "chaosball":       6500,
        "chaosschaden":    5000,
        "schattendaemon":  5000,
        "verbanne":        5500,
        "orakeldaemon":    5500 ]),

    9:(["nachtsicht":      7000,
        "dunkelheit":      6500,
        "chaosruestung":   6000,
        "kontrolle":       6000,
        "bannzauber":      6500,
        "schutz":          7000,
        "chaosball":       7500,
        "chaosschaden":    6500,
        "schattendaemon":  6500,
        "verbanne":        6500,
        "finsternis":      5500,
        "lichtdaemon":     6000,
        "orakeldaemon":    6500 ]),

   10:(["nachtsicht":      7500,
        "dunkelheit":      7000,
        "chaosruestung":   7500,
        "kontrolle":       8000,
        "bannzauber":      7000,
        "schutz":          8000,
        "chaosball":       9000,
        "chaosschaden":    8000,
        "schattendaemon":  7000,
        "verbanne":        7000,
        "finsternis":      7000,
        "lichtdaemon":     6500,
        "feuerdaemon":     6000,
        "binde":           7000,
        "orakeldaemon":    7000 ]),

   11:(["nachtsicht":      9000,
        "dunkelheit":      7500,
        "chaosruestung":   8500,
        "kontrolle":       8500,
        "bannzauber":      8500,
        "schutz":          8500,
        "chaosball":       10000,
        "chaosschaden":    9000,
        "schattendaemon":  8000,
        "verbanne":        8000,
        "finsternis":      9000,
        "lichtdaemon":     7000,
        "feuerdaemon":     6700,
        "binde":           9000,
        "saeuredaemon":    6700,
        "orakeldaemon":    7500 ]),
  ]);
  return stufen[stufe];
}

mixed ErhoehungsCheck(object pl)
{
  int flag;
  string *sprueche, s;
  mapping stufen;

  stufen   = StufenAnforderung(pl->QueryProp(P_GUILD_LEVEL)+1);
  s        = "";

  foreach(string tmp: m_indices(stufen))
  {
    if(pl->QuerySkillAbility(tmp) < stufen[tmp])
    {
      mapping d = CHAOS_DAEMONEN_MASTER->QueryTyp(tmp);

      flag = 1;
      // Dämonen mit ihrem Namen, z.B. "Orakeldämon"
      s   += (d ? CTSA(d[CD_NAME]) : capitalize(tmp))+" musst Du "+

      CheckWert(stufen[tmp])+", ";
    }
  }
  if( flag )
    return "Du kannst Deine Stufe noch nicht erhoehen. Grund:\n"+
           s[0..<3]+" koennen.\n";
  return 0;
}


int ist_erz( object spieler)
{
  if(!spieler)
    return 0;

  if(getuid(spieler) == erzmeister)
    return 1;

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

  if(!pl = find_player(exerz))
    return;

  if(pl->QueryProp(P_GUILD) != "chaos")
    return;

  if(pl->QueryProp(P_GUILD_LEVEL) <= 11)
    return;

  pl->SetProp(P_GUILD_LEVEL,11);

  if(mitglieder[exerz])
    mitglieder[exerz][STUFE] = 11;
  else
    exerz = 0;
}

int set_kruuolq_erzi(object spieler)
{
  string txt;

  if(!spieler)
    return -1;

  if(spieler->QueryProp(P_GUILD) != "chaos")
    return -2;

  if(spieler->QueryProp(P_GUILD_LEVEL) < 11)
    return -3;

  erzmeister = "it";
  exerz      = getuid(spieler);
  duellier = ({});

  if(mitglieder[exerz])
    mitglieder[exerz][STUFE] = 11;

  else
    exerz = 0;
  /*
  Der naechste Erzi-Kampf kann sofort stattfinden
  */
  duellzeit = 0;

  txt="Ich habe soeben "+capitalize(getuid(spieler))+" als Erzmeister"+
      (spieler->QueryProp(P_GENDER)==1?"":"in")+" des Chaos abgeloest. "
      "Um Euch nicht vollends zu blamieren, werde ich an dem naechsten "
      "Kampf nicht teilnehmen >:)";

  write_file(CHAOS_GILDEN_LOG("erzmeister"),
    "Kruuolq setzt "+capitalize(getuid(spieler))+" ab: "+dtime(time())+".\n");

  call_other(CHAOS_GILDENROOM,"sach_was",txt);

//!!!!!!!!!!!!!!!!!!!!!!  call_other(C_SWIFT_ROOM("cl2_hutschatraum"),"add_erzmeister",erzmeister);
  save_me();

  return 1;
}

static varargs void tell_member(string msg, int lev, string*|mapping arr)
{
  object ob;

  string *tmp_arr;

  if(mappingp(arr) || !arr)
    tmp_arr = m_indices(arr);
  else
    tmp_arr = arr;

  foreach(string tmp:tmp_arr)
    if(ob = find_player(tmp))
      if(ob->QueryProp(P_GUILD_LEVEL) >= lev)
        tell_object(ob,msg);
}

int set_erzmeister( object spieler)
{
  string msg,txt;

  if(!spieler)
    return -3;

  if(spieler->QueryProp( P_GUILD) != "chaos" )
    return -2;

  if(spieler->QueryProp(P_GUILD_LEVEL) < 11 )
    return -1;

  exerz = erzmeister;
  /* Zusaetzliche Abfrage eingebaut, da beim austreten aus der Gilde
   * offenbar nicht ueberprueft wird, ob der Spieler Erzmeister ist.
   * 21.10.97 - Silvana
   */

  if(mitglieder[exerz])
    mitglieder[exerz][STUFE] = 11;
  else
    exerz = 0;

  erzmeister = getuid(spieler);
  duellier   = ({});
  duellzeit  = time() + 432000;
  spieler->SetProp(P_GUILD_LEVEL, 12);
/*
Verkuenden wer neuer Erzi ist:
*/
  txt = capitalize(erzmeister)+" hat im blutigen Kampf das Koennen unter "
        "Beweis gestellt und darf sich nun "+
       (spieler->QueryProp(P_GENDER)==1?"Erzmeister":"Erzmeisterin")+" des "
        "Chaos nennen. Erzittert vor "+
       (spieler->QueryProp(P_GENDER)==1?"seiner":"ihrer")+" Macht!";

  call_other(CHAOS_GILDENROOM,"sach_was",txt);

  msg = break_string( capitalize(erzmeister)+" ist "+
       (spieler->QueryProp(P_GENDER)==1?"der neue Erzmeister":
      "die neue Erzmeisterin")+" der Gilde!",0, "Kruuolq teilt Dir mit: ");

  object ob;

  tell_member(msg);

  ZAR(msg);
  ME->BerechneTopWert(spieler);

  if(stringp(exerz))
    low_exerz_level();

  write_file(CHAOS_GILDEN_LOG("erzmeister"),
    "Neuer Erzmeister: "+capitalize(erzmeister)+": "+dtime(time())+".\n");
//!!!!!!!!!!!!!!!!!!!!!!!!  call_other(C_SWIFT_ROOM("cl2_hutschatraum"),"add_erzmeister",erzmeister);
  save_me();
  return 1;
}

void tell_meister(string msg)
{
  tell_member(msg,11);
}

int AddKaempfer( object spieler)
{
  if(!objectp(spieler)) return 0;

  if(member(duellier, getuid(spieler)) != -1)
    return 0;

  duellier += ({ getuid(spieler) });

  return 1;
}

int IstKaempfer( object spieler)
{
  if(!objectp(spieler)) return 0;

  if(member(duellier, getuid(spieler)) != -1)
    return 1;

  return 0;
}

int LoescheKaempfer( object spieler)
{
  string msg;
  object gewinner;

  if(!objectp(spieler))
    return 0;

  if(member(duellier,getuid(spieler)) == -1)
    return 0;

  duellier -= ({ getuid(spieler) });

  if( sizeof(duellier) == 1)
  {
    gewinner = find_player(duellier[0]);

    if(!objectp(gewinner))
      return 0;

    if(!ist_erz(gewinner))
      set_erzmeister( gewinner);

    else
    {
      msg = break_string(capitalize(erzmeister)+" ist "+
           (spieler->QueryProp(P_GENDER)==1?"der neue und alte Erzmeister":
           "die neue und alte Erzmeisterin")+" der Gilde!",0,
           "Kruuolq teilt Dir mit: ");

      tell_member(msg);

      write_file(CHAOS_GILDEN_LOG("erzmeister"),
        "Alter & Neuer Erzmeister: "+capitalize(erzmeister)+": "
        +dtime(time())+".\n");
    }
    duellier = ({});
    gewinner->StopHuntingMode(1);
    gewinner->move(CHAOS_GILDEN_ROOM("vc/stop+"+getuid(gewinner)),
                                         M_TPORT | M_NO_SHOW);
    (CHAOS_GILDEN_ARENA("no"))->aufraeumen();
    (CHAOS_GILDEN_ARENA("nw"))->aufraeumen();
    (CHAOS_GILDEN_ARENA("so"))->aufraeumen();
    (CHAOS_GILDEN_ARENA("sw"))->aufraeumen();

    return 1;
  }
  msg = " -> -> "+capitalize(getuid(spieler))+
        " hat den Kampf beendet! <- <-\n";

  tell_member(msg,0,duellier);

  return 1;
}

void let_him_die(object ob)
{
  call_other(CHAOS_GILDENROOM,"let_him_die",ob);
}

int IstKampf()
{
  if(sizeof(duellier))
    return 1;

  return 0;
}

mixed query_duellier(){ return duellier; }

int loesche_duellier(string player)
{
  if(member(duellier, player) == -1)
    return 0;

  duellier -= ({ player });

  return 1;
}

void loesche_alle(){ duellier = ({}); }

void BerechneTopWert(object pl)
{
  string wer;
  mapping skill;
  int wert;

  if(!objectp(pl))
    return;

  if(pl->QueryProp(P_GUILD) != "chaos")
    return;

  wer = getuid(pl);

  if(IS_LEARNER(pl) || pl->QueryProp(P_TESTPLAYER))
  {
    call_out( "LoescheMagier", 0, wer);
    return;
  }

  mitglieder[wer][STUFE] = pl->QueryProp( P_GUILD_LEVEL );
  skill                  = pl->QueryProp( P_SKILLS );

  if(!mappingp(skill)) return;

  wert   = 0;

  foreach(mixed tmp: m_indices(skill))
  {
    if(!mappingp(skill[tmp]))
      wert += skill[tmp];

    else
      wert += skill[tmp][SI_SKILLABILITY];
  }
  if(mitglieder[wer][ZAUBER])
    mitglieder[wer][ZAUBER] = wert;
  else
    mitglieder[wer] += ([ ZAUBER:wert ]);

  save_me();
}


void reset()
{
  string msg, *mit;
  mapping liste;
  object erz, her, pl;
  int i, wert;
  int w, *z;

  z     = ({});
  liste = ([]);
  mit   = m_indices(mitglieder);

  if(stringp(exerz))
    low_exerz_level();

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
  save_me();
}

/*
 * EMKampfCheck wird zu Beginn des EM-Kampfs aufgerufen und testet, ob
 * der aktuelle EM die letzte Stunde nicht da war. In diesem Fall
 * werden die Variablen herausforderer und hfzeit gesetzt, so dass der
 * Ex-EM den neuen EM herausfordern kann.
 */
void EMKampfCheck()
{
   object em;              /* Unser aller Erzmeister */
   int last;               /* Sein Ausloggdatum      */

   if(!find_player(erzmeister))
   {

   /* Wir versuchen, sein Ausloggdatum zu erfahren.
    * a) netztot, b) mit ende ausgeloggt
    * Bei ende wird Spielerfile gespeichert -> wir koennen file_time nehmen.
    */
     if(em = find_netdead(erzmeister))
       last = em->QueryProp(P_LAST_LOGOUT) ||
              file_time("/save/"+erzmeister[0..0]+"/"+erzmeister+".o");

     else
       last = file_time("/save/"+erzmeister[0..0]+"/"+erzmeister+".o");

     /* War der Erzmeister nicht waehrend der Anmeldephase anwesend? */
     if (time()-last >= 60*60)
     {
       herausforderer = erzmeister;
       hfzeit         = time()+60*60*24;

       save_me();

       return;
     }
   }
   /* Ha! Er WAR anwesend! Keine Herausforderung moeglich. */
   herausforderer = 0;
   hfzeit         = 0;

   save_me();
}

string get_herausforderer()
{
  return herausforderer;
}

int get_hfzeit()
{
  return hfzeit;
}

void set_herausforderer(string wer)
{
   herausforderer = wer;
}

void set_hfzeit(int i)
{
   hfzeit = i;
}
