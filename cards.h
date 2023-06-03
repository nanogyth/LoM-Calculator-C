#define PIXIE_FIRST (pixie_of_jealousy==first||pixie_of_laziness==first||\
  pixie_of_lust==first||pixie_of_pride==first||pixie_of_gluttony==first||\
  pixie_of_rage==first||pixie_of_greed==first)
#define PIXIE_SECOND (pixie_of_jealousy==second||pixie_of_laziness==second||\
  pixie_of_lust==second||pixie_of_pride==second||pixie_of_gluttony==second||\
  pixie_of_rage==second||pixie_of_greed==second)
#define PIXIE_THIRD (pixie_of_jealousy==third||pixie_of_laziness==third||\
  pixie_of_lust==third||pixie_of_pride==third||pixie_of_gluttony==third||\
  pixie_of_rage==third||pixie_of_greed==third)

typedef enum { CPRINT,PREHIDDEN,HIDDEN,FIRST,SECOND,THIRD,LEAVING,WORLD } CARD_F;

typedef enum { NONE,YGGDRASIL,HEAVENS_SCALE,DYING_EARTH,RAGNAROK,
	ANCIENT_MOON,MIRRORED_WORLD,BED_OF_THORN } WORLD_CARD;
WORLD_CARD awc;

typedef void (card_function)(CARD_F);

card_function *prehidden,*hidden,*first,*second,*third,*leaving;

card_function
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