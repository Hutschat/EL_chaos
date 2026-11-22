#include <bank.h>

// Der Muell muss ja nicht zwischen den anderen Sachen liegen...

#define FSHOP_OBJ(x)  "/gilden/files.chaos/obj/fobj/"+x
#define ANZ(x)          x
#define PREIS(x)        x
#define TP              this_player()
#define TPN             this_player()->name()
#define TO              this_object()
#define BS              break_string
#define P_COFFEESHOP_ITEM	"coffeeshop_item"

/* Ding ist im Coffeeshop erhaeltlich, wenn != 0 */

#define IT_NO_ITEM	0	/* nicht im Coffeeshop erhaeltlich */
#define IT_DOPE		1	/* dope */
#define IT_DEVICE	2	/* geraet */
#define IT_MISC		4	/* sonstiges */

#define P_FSHOP_ITEMS		"_f_shop_items_"
/* was gibt es denn hier? */

