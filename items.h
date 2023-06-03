/* from calc.c */
void pretty_print(void); /* get_item */

/* from material.c */
int material;
#define HIDE (material>23 && material<28)

int equip;
#define SHIELD  (12==equip)
#define HELM    (13==equip)
#define HAT     (14==equip)
#define HAUBERK (15==equip)
#define ROBE    (16==equip)
#define RING    (18==equip)
#define BOOTS   (19==equip)
#define SHOES   (20==equip)
#define PENDANT (23==equip)

int sharp,heavy,force,tech,strike,slash,thrust,magic;
void perc150(int *);
void perc125(int *);
void perc75(int *);
void perc50(int *);


/* from essence.c */
int energy;
int wi,sh,dr,au,sa,gn,ji,un;
#define ESSTOTAL (wi+sh+dr+au+sa+gn+ji+un) /* to determine which cards to make */

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;
void taint(ESSENCE);

/* from special.c */
typedef enum { Sleep=1, Poison=2, Paralysis=4, Confusion=8,
    Darkness=16, Petrify=32, Flameburst=64, Freeze=128 } IMMUNITY;
int immunity;


/* from stats.c */
typedef enum { ALL,PWR,SKL,DEF,MAG,HP,SPR,CHM,LCK } STAT;
void stat_min(int, STAT);
void stat_limits(int, int, STAT);
void increase_stat(STAT);
void decrease_stat(STAT);


/* from cards.c */
void unsticky(void); /* holy water/garlicrown */

typedef enum { CPRINT,PREHIDDEN,HIDDEN,FIRST,SECOND,THIRD,LEAVING,WORLD } CARD_F;

typedef void (card_function)(CARD_F);

card_function
*prehidden,
no_card,
yggdrasil,
ancient_moon,
mirrored_world,
heavens_scale,
dying_earth,
ragnarok,
bed_of_thorn,
volcano,
metropolis,
tower,
spring,
ruler_of_the_sky,
mother_of_gods,
sun_god,
moon_goddess,
thunder_god,
goddess_of_love,
fertility_goddess,
ocean_god,
wind_god,
wisdom_goddess,
blacksmith_god,
god_of_war,
fallen_angel,
witch_of_moon,
lord_of_flies,
wings_of_darkness,
god_of_destruction,
beast_headed_god,
leviathan,
sage,
man_of_valor,
wanderer,
sacrificed_nymph,
enticed_nymph,
nymph_of_the_sky,
nymph_of_orchards,
nymph_of_dawn,
spirit_of_ocean,
spirit_of_forest,
spirit_of_mountain,
spirit_of_shoes,
spirit_of_housework,
pixie_of_pride,
pixie_of_laziness,
pixie_of_jealousy,
pixie_of_lust,
pixie_of_rage,
pixie_of_gluttony,
pixie_of_greed,
phoenix,
unicorn,
wisp,
shade,
dryad,
aura,
sala,
gnome,
jinn,
undine,
raven,
wolf,
sorcerer,
witch,
king,
princess,
clown,
cleric;