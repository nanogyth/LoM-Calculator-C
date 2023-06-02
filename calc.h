#include "stdio.h"
#include "cards.h"
#include "items.h"
#include "material.h"

int energy;

/* essence levels */
int wi,sh,dr,au,sa,gn,ji,un;

#define ESSTOTAL (wi+sh+dr+au+sa+gn+ji+un)

/* resistance values */
int wiR,shR,drR,auR,saR,gnR,jiR,unR;

card_function *prehidden,*hidden,*first,*second,*third,*leaving;

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;
void taint(ESSENCE);
void decrease(ESSENCE);

typedef enum { NONE,YGGDRASIL,HEAVENS_SCALE,DYING_EARTH,RAGNAROK,
	ANCIENT_MOON,MIRRORED_WORLD,BED_OF_THORN } WORLD_CARD;
WORLD_CARD awc;
