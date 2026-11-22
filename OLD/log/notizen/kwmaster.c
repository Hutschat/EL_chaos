#include "gilde.h"

#define KW_MASTER "/gilden/files.chaos/log/notizen/kwmaster"
#define BS        break_string

static mapping aktuell;    
mapping mitteilungen;      

void create(){
  seteuid(getuid(this_object()));
  if(!restore_object(KW_MASTER)){
    aktuell=([]);
    mitteilungen=([]);
   }
}

query_aktuell() { return aktuell; }
query_mitteilungen(){ return mitteilungen; } 

texte(){                     
 string s;
 int i, si;
 si=sizeof(aktuell);
 if(!si)
   s="Es haengen derzeit keine Notizen aus.\n\n";
 else  
   s="Es haeng"+(si==1?"t":"en")+" derzeit "+si+" Notiz"+(si==1?"":"en")+" aus:\n\n";
 for(i=1;i<=si;i++){
   if(!aktuell[i]){
     s+="\n"+sprintf("%-d. Hier wurde eine Notiz entfernt.\n",i); 
     continue;
    }
     s +="\n"+sprintf( " %-d. %-12s: %-s\n", i,
            (aktuell[i,1]?mitteilungen[aktuell[i]]:mitteilungen[aktuell[i]]),
                   aktuell[i] );
  } 
 return s;
}

int note_notice(int nr){
 int ges;
 string s;
 ges=sizeof(aktuell);
 if(!ges){
    write("Es haengen keine Notizen an der Korkwand.\n");
   return 1;
  }
 if(nr>ges){
    write("So viele Zettel haengen nicht an der Korkwand.\n");
   return 1;
  }        
 if(nr<1){
    write("Eine solche Notiz gibt es nicht.\n");
   return 1;
  }
 s="";
 if(!member(mitteilungen,aktuell[nr])){
    s+="Diese Notiz wurde entfernt.\n";
   }
 else{
    s+=sprintf("\n %-12s: %s\n",mitteilungen[aktuell[nr]],aktuell[nr]);
    s+=BS(mitteilungen[aktuell[nr],1],78,0,1);
  }    
 this_player()->More(s);
 return 1;
}


notice(string titel,string txt){
  mitteilungen += ([ titel:capitalize(getuid(this_player()));txt]);
  aktuell += ([ sizeof(aktuell)+1:titel;0 ]);
  save_object(KW_MASTER);
}

delete_notice(int zahl){
  if(!member(aktuell,zahl)){
     write("Eine Notiz dieser Nummer gibt es nicht.\n");
    return 1;
   }
  if(aktuell[zahl,1]){
     write("Diese Notiz darfst Du nicht loeschen.\n");
     return 1;
   }
  if(!stringp(mitteilungen[aktuell[zahl]])){
     write("Diese Notiz wurde schon entfernt.\n");
    return 1;
   }
  if((lower_case(mitteilungen[aktuell[zahl]])!=getuid(this_player())) 
     &&(member(CHAOS_GILDEN_MAGIER,getuid(this_player()))!=-1)){
     write( "Du darfst nur Deine eigenen Notizen entfernen.\n");
    return 1;
   }
  write("Du entfernst Notiz Nr. "+zahl+".\n");
  say(capitalize(this_player()->name())+" entfernt eine Notiz von der "
   +"Korkwand.\n");
  mitteilungen-=([aktuell[zahl]]);
  aktuell[zahl]=0;
  save_object(KW_MASTER);
 return 1;
}
