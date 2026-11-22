/*
     Last changed:   8.6.2000 Bierchen neues file, enthaelt die namen 
                              der gildenmagier.
*/

#ifndef CHAOS___GILDENMAGIER
#define CHAOS___GILDENMAGIER

#define CHAOS_GILDEN_MAGIER   ({"it"})
#define CHAOS_GILDEN_EHRENMAGIER ({"zardoz"})
#define CHAOS_MAGIER(x)       (member_array(getuid(x),CHAOS_GILDEN_MAGIER)>-1)

#endif
