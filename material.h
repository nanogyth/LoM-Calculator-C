/* from cards.c */
typedef enum { CPRINT,PREHIDDEN,HIDDEN,FIRST,SECOND,THIRD,LEAVING,WORLD } CARD_F;
typedef void (card_function)(CARD_F);
card_function *prehidden, *hidden, *first, *second, *third, phoenix, witch, raven, wolf, dryad;
int card_price(void);

/* from essence.c */
int energy_ge(int);

int wi,sh,dr,au,sa,gn,ji,un;
#define ESSTOTAL (wi+sh+dr+au+sa+gn+ji+un) /* growth control */

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;
void taint(ESSENCE); /* WOOD material code */
void decrease(ESSENCE); /* AEROLITE material code */


/* from special.c */
typedef enum { Thrust, Shot, Caduceus, Chaotic_Avenger,
    Green_Princess, Gungnir, Magical_Shot, Phoenix_Falling,
    Solar_Flare, Spear_of_Light, Trident } PLUNGE1;
PLUNGE1 plunge1;

typedef enum { No_Effect, No_Regen, No_Revive, Auto_Revive,
    Fast_Revive, Extra_Exp, Extra_Lucre, Stare_Immunity,
    Share_Exp, Move_Regen } SPECIAL;
SPECIAL special;

