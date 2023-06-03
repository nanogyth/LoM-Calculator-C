#include "stdio.h"

/* from cards.c */
typedef enum { CPRINT,PREHIDDEN,HIDDEN,FIRST,SECOND,THIRD,LEAVING,WORLD } CARD_F;
typedef void (card_function)(CARD_F);
card_function *prehidden, dryad;


/* from essence.c */
int energy;

int wi,sh,dr,au,sa,gn,ji,un;
#define ESSTOTAL (wi+sh+dr+au+sa+gn+ji+un)

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;
void taint(ESSENCE);
void decrease(ESSENCE);

