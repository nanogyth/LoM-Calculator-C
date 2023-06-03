/* from essence.c */
int energy; /* needed for pixies/NoD */

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;
void taint(ESSENCE); /* essence cards */


/* from material.c */
int wiR,shR,drR,auR,saR,gnR,jiR,unR; /* witch/sorcerer */

int equip;
#define KNIFE   (1==equip)
#define SWORD   (2==equip)
#define AXE     (3==equip)
#define THSWORD (4==equip)
#define THAXE   (5==equip)
#define HAMMER  (6==equip)
#define SPEAR   (7==equip)
#define STAFF   (8==equip)
#define GLOVE   (9==equip)
#define FLAIL   (10==equip)
#define BOW     (11==equip)
#define SHIELD  (12==equip)
#define HAT     (14==equip)
#define HAUBERK (15==equip)
#define ROBE    (16==equip)
#define RING    (18==equip)
#define BOOTS   (19==equip)
#define SHOES   (20==equip)
#define MANTLE  (22==equip)
#define PENDANT (23==equip)

int sharp,heavy,force,tech,strike,slash,thrust,magic;
void perc150(int *);
void perc125(int *);
void perc75(int *);
void perc50(int *);


/* from stats.c */
typedef enum { ALL,PWR,SKL,DEF,MAG,HP,SPR,CHM,LCK } STAT;
void stat_min(int, STAT);
void stat_limits(int, int, STAT);
void increase_stat(STAT);
void decrease_stat(STAT);


/* from special.c */
typedef enum { Thrust, Shot, Caduceus, Chaotic_Avenger,
    Green_Princess, Gungnir, Magical_Shot, Phoenix_Falling,
    Solar_Flare, Spear_of_Light, Trident } PLUNGE1;

typedef enum { Uppercut, Double_Shot, Dragonslayer, Elven_Archer,
    Flame_Tongue, Game_of_Death, Hand_of_Midas, Lunar_Shot,
    Poison_Blade, Quick_Blade, Sunlight, Vampsword } PLUNGE2;

typedef enum { Jump, Demonicide, Electrosceptre, Golden_Touch,
    Magma_Hammer, Mjolnir, Moonlight, Quake_Hammer, Ragnarok,
    Red_Dream, Sinister_Blade, Sledge_Hammer, Treefeller,
    Woodchopper} PLUNGE3;

typedef enum { No_Effect, No_Regen, No_Revive, Auto_Revive,
    Fast_Revive, Extra_Exp, Extra_Lucre, Stare_Immunity,
    Share_Exp, Move_Regen } SPECIAL;

typedef enum { Sleep=1, Poison=2, Paralysis=4, Confusion=8,
    Darkness=16, Petrify=32, Flameburst=64, Freeze=128 } IMMUNITY;

PLUNGE1 plunge1;
PLUNGE2 plunge2;
PLUNGE3 plunge3;
SPECIAL special;
int immunity;
