inherit "/std/thing";

#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <language.h>
#include <wizlevels.h>
#include <new_skills.h>
#include "gilde.h"

#define lausch_level 8

int gilden_news(){
  this_player()->more(CHAOS_GILDEN_TXT("g_news"));
  return 1;
}

string *finde_chaoten(){
  return (map_array(
    call_other("/std/user_filter","filter_users","gilde chaos"),#'getuid));
}
int check_clevel(){
  if(!living(environment(this_object()))) return 0;
  if(this_player()->QueryProp("guild_level")<lausch_level||
     this_player()->QueryProp(P_GUILD)!="chaos") return 0;
  return 1;
}
int gilden_wer(){
  object pl;
  string *tmp,sym;
  int i;
  if(!check_clevel()) return 0;
  tmp=finde_chaoten();
  write("\n\tFolgende Krieger des Chaos sind momentan anwesend:\n"
        "\t--------------------------------------------------\n");
  if(i=sizeof(tmp)){
    do{
      i--;
      if(pl=find_player(tmp[i])){
        if(pl->QueryProp(P_C_LAUSCHEN)) sym="*";
        else sym="-";
        write("\t\tLevel.."+pl->QueryProp("guild_level"));
        write("\t"+sym+pl->QueryProp(P_NAME)+"\n");
      
      }
    }while(i>0);
  }
  write("\n\t--------------------------------------------------\n\n");
  return 1;
}
int clausche(string str){
  if(!check_clevel()) return 0;
  if(!str){
    if(this_player()->QueryProp(P_C_LAUSCHEN)){
      write("Du lauschst den Chaoskriegern.\n");
      return 1;
    }
    write("Du lauschst den Chaoskriegern nicht.\n");
    return 1;
  }
  if(str!="ein"&&str!="aus"){
    write("'clausche' ein oder aus?\n");
    return 1;
  }
  if(str=="ein"){
    if(this_player()->QueryProp(P_C_LAUSCHEN)){
      write("Du lauschst doch schon.\n");
      return 1;
    }
    this_player()->SetProp(P_C_LAUSCHEN,1);
    write("Du lauschst nun bei den Chaoskriegern.\n");
    return 1;
  }
  if(!this_player()->QueryProp(P_C_LAUSCHEN)){
    write("Aber Du lauschst doch gar nicht.\n");
    return 1;
  }
  this_player()->SetProp(P_C_LAUSCHEN,0);
  write("Du lauschst den Chaoskriegern nicht mehr.\n");
  return 1;
}
int chaos_sagen(string was){
  string *tmp,wer;
  object pl;
  int i;
  if(!check_clevel()) return 0;
  was = this_interactive()->_unparsed_args();
  if(!was){
    write("Was moechtest Du den Chaoskriegern mitteilen?\n");
    return 1;
  }
  if(!this_player()->QueryProp(P_C_LAUSCHEN)){
    write("Du lauschst Doch noch gar nicht!\n");
    return 1;
  }
  wer=capitalize(this_player()->query_real_name());
  tmp=finde_chaoten();
  write(break_string(was,78,"Du sagst chaotisch: "));
  if(i=sizeof(tmp)){
    do{
      i--;
      if(getuid(this_player())!=tmp[i]){
        if(pl=find_player(tmp[i])){
          if(pl->QueryProp(P_C_LAUSCHEN)&&present("\nchaos_ruestung",pl)&&
            pl->QueryProp("guild_level")>=lausch_level){
            tell_object(pl,break_string(was,78,wer+ " sagt chaotisch: "));
          }
        }
      }
    }while(i>0); 
  }
  return 1;
}

create(){
  if( !is_clone( this_object())) return;
  ::create();
  SetProp(P_SHORT,"haut-master");
  SetProp(P_LONG,"haut-master");
  AddId(({ "\nchaos_mobj"}));
  AddCmd(({"chaosinfo", "chaosinfos" }), "gilden_news" );
  AddCmd(({"chaoswer"}),"gilden_wer");
  AddCmd(({"chaossag","chaossage"}),"chaos_sagen");
  AddCmd(({"chaoslausche","chaoslausch"}),"clausche");
} 
