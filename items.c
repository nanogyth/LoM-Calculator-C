#include <stdio.h>
#include <string.h>
#include "items.h"

/* get_item() at bottom */

typedef enum { IPRINT,ENERGY,CODE } ITEM_F;
typedef void (item_function)(ITEM_F);
item_function *item;

void item_energy(void){
	item(ENERGY);
}
void item_code(void){
	item(CODE);
}
void print_item(void){
	printf("Last Item: ");
	item(IPRINT);
	printf("\n");
}

char *item_list=
" 1 Wisp Gold  25 Round Seed 49 Orcaplant  73 Giant's Ho  97 Mercury   \n"
" 2 Shade Gold 26 Oblong See 50 Garlicrown 74 Scissors    98 Stinky Bre\n"
" 3 Dryad Gold 27 Crooked Se 51 Honey Onio 75 Healing Cl  99 Ghost's Ho\n"
" 4 Aura Gold  28 Big Seed   52 Sweet Moai 76 Zombie Cla 100 Dragon's B\n"
" 5 Sala Gold  29 Small Seed 53 Spiny Carr 77 Vampire Fa 101 Virgin's S\n"
" 6 Gnome Gold 30 Long Seed  54 Conchurnip 78 Little Eye 102 Electricit\n"
" 7 Jinn Gold  31 Flat Seed  55 Cornflower 79 Sleepy Eye 103 Moss      \n"
" 8 Undine Gol 32 Spiny Seed 56 Cabadillo  80 Silly Eye  104 Ear Of Whe\n"
" 9 Wisp Silve 33 Bellgrape  57 Needlettuc 81 Dangerous  105 Baked Roac\n"
"10 Shade Silv 34 Diceberry  58 Cherry Bom 82 Angry Eye  106 Blackened \n"
"11 Dryad Silv 35 Mangoeleph 59 Masked Pot 83 Blank Eye  107 Sulpher   \n"
"12 Aura Silve 36 Loquat-sho 60 Lilipods   84 Wicked Eye 108 Poison Pow\n"
"13 Sala Silve 37 Pear o'Hea 61 Rocket Pap 85 Creepy Eye 109 Sleepy Pow\n"
"14 Gnome Silv 38 Squalphin  62 Orange'opu 86 Angel Feat 110 Knockout D\n"
"15 Jinn Silve 39 Citrisquid 63 Bumpkin    87 Raven Feat 111 Rust      \n"
"16 Undine Sil 40 Springanan 64 Heart Mint 88 Clear Feat 112 Grave Dirt\n"
"17 Fire Stone 41 Peach Pupp 65 Spade Basi 89 Moth Wing  113 Ash       \n"
"18 Earth Ston 42 Apricat    66 Dialaurel  90 Flaming Qu 114 Hairball  \n"
"19 Wind Stone 43 Applesocks 67 Gold Clove 91 White Feat 115 Needle    \n"
"20 Water Ston 44 Whalamato  68 Mush-In-A- 92 Aroma Oil  116 Mirror Pie\n"
"21 Sun Crysta 45 Pine o'Clo 69 Toadstools 93 Dragon Blo 117 Wad Of Woo\n"
"22 Moon Cryst 46 Fishy Frui 70 All Meat   94 Acid       118 Messy Scro\n"
"23 Glow Cryst 47 Boarmelon  71 Sharp Claw 95 Holy Water 119 Greenball \n"
"24 Chaos Crys 48 Rhinoloupe 72 Poison Fan 96 Ether      120 Tako Bug  \n";

void no_item(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("No Item");break;
	case ENERGY: energy=0;break;
	case   CODE: break;
	}
}
void wisp_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Wisp Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(WISP);
		if(energy>=8){prehidden=wisp;}
		break;
	}
}
void shade_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Shade Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(SHADE);
		if(energy>=8){prehidden=shade;}
		break;
	}
}
void dryad_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Dryad Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void aura_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Aura Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(AURA);
		if(energy>=8){prehidden=aura;}
		break;
	}
}
void sala_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Salamander Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(SALA);
		if(energy>=8){prehidden=sala;}
		break;
	}
}
void gnome_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Gnome Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(GNOME);
		if(energy>=8){prehidden=gnome;}
		break;
	}
}
void jinn_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Jinn Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(JINN);
		if(energy>=8){prehidden=jinn;}
		break;
	}
}
void undine_gold(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Undine Gold");break;
	case ENERGY: energy=64;break;
	case   CODE:
		taint(UNDINE);
		if(energy>=8){prehidden=undine;}
		break;
	}
}
void wisp_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Wisp Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(WISP);
		if(energy>=8){prehidden=wisp;}
		break;
	}
}
void shade_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Shade Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(SHADE);
		if(energy>=8){prehidden=shade;}
		break;
	}
}
void dryad_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Dryad Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void aura_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Aura Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(AURA);
		if(energy>=8){prehidden=aura;}
		break;
	}
}
void sala_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Salamander Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(SALA);
		if(energy>=8){prehidden=sala;}
		break;
	}
}
void gnome_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Gnome Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(GNOME);
		if(energy>=8){prehidden=gnome;}
		break;
	}
}
void jinn_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Jinn Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(JINN);
		if(energy>=8){prehidden=jinn;}
		break;
	}
}
void undine_silver(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Undine Silver");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(UNDINE);
		if(energy>=8){prehidden=undine;}
		break;
	}
}
void fire_stone(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Fire Stone");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(SALA);
		if(energy>=8){prehidden=sala;}
		break;
	}
}
void earth_stone(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Earth Stone");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(GNOME);
		if(energy>=8){prehidden=gnome;}
		break;
	}
}
void wind_stone(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Wind Stone");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(JINN);
		if(energy>=8){prehidden=jinn;}
		break;
	}
}
void water_stone(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Water Stone");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(UNDINE);
		if(energy>=8){prehidden=undine;}
		break;
	}
}
void sun_crystal(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Sun Crystal");break;
	case ENERGY: energy=48;break;
	case   CODE:
		if( wi>=3 && ESSTOTAL>=5 && energy>=8 ){prehidden=sun_god;}
		taint(WISP);
		break;
	}
}
void moon_crystal(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Moon Crystal");break;
	case ENERGY: energy=48;break;
	case   CODE:
		if( sh>=3 && ESSTOTAL>=5 ){prehidden=moon_goddess;}
		taint(SHADE);
		break;
	}
}
void glow_crystal(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Glow Crystal");break;
	case ENERGY: energy=96;break;
	case   CODE:
		if(energy>=8){prehidden=nymph_of_dawn;}
		break;
	}
}
void chaos_crystal(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Chaos Crystal");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if(energy>=16){prehidden=ancient_moon;}
		break;
	}
}
void round_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Round Seed");break;
	case ENERGY: energy=16;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void oblong_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Oblong Seed");break;
	case ENERGY: energy=16;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void crooked_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Crooked Seed");break;
	case ENERGY: energy=16;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void big_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Big Seed");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void small_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Small Seed");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void long_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Long Seed");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void flat_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Flat Seed");break;
	case ENERGY: energy=48;break;
	case   CODE:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	}
}
void spiny_seed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Spiny Seed");break;
	case ENERGY: energy=48;break;
	case   CODE:
		if( dr>=5 && energy>=8 ){prehidden=yggdrasil;}
		taint(DRYAD);
		break;
	}
}
void bellgrapes(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Bellgrapes");break;
	case ENERGY: energy=64;break;
	case   CODE:
		stat_limits(-5,10,MAG);
		increase_stat(MAG);
		break;
	}
}
void diceberry(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Diceberry");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( ji>=3 && ESSTOTAL>=5 ){prehidden=wind_god;}
		increase_stat(LCK);
		break;
	}
}
void mangoelephant(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Mangoelephant");break;
	case ENERGY: energy=64;break;
	case   CODE:
		stat_limits(-5,10,HP);
		increase_stat(HP);
		break;
	}
}
void loquat_shoes(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Loquat-Shoes");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if(BOOTS||SHOES){
			perc125(&strike);
			perc125(&slash);
			perc125(&thrust);
		}
		if( energy>=16 ){prehidden=spirit_of_shoes;}
		break;
	}
}
void pear_oheels(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Pear O'Heels");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if(BOOTS||SHOES){
			perc125(&strike);
			perc125(&slash);
			perc125(&thrust);
		}
		if( energy>=16 ){prehidden=spirit_of_shoes;}
		break;
	}
}
void squalphin(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Squalphin");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( un>=3 && ESSTOTAL>=5 && energy>=8 ){prehidden=ocean_god;}
		taint(UNDINE);
		break;
	}
}
void citrisquid(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Citrisquid");break;
	case ENERGY: energy=8;break;
	case   CODE:
		perc75(&sharp);
		perc125(&heavy);
		perc75(&slash);
		perc125(&strike);
		break;
	}
}
void springanana(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Springanana");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( energy>=8 ){prehidden=heavens_scale;}
		break;
	}
}
void peach_puppy(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Peach Puppy");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if( energy>=8 ){prehidden=wolf;}
		perc125(&sharp);
		perc75(&heavy);
		break;
	}
}
void apricat(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Apricat");break;
	case ENERGY: energy=8;break;
	case   CODE:
		perc75(&force);
		perc125(&tech);
		break;
	}
}
void applesocks(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Applesocks");break;
	case ENERGY: energy=64;break;
	case   CODE:
		stat_limits(-5,10,SKL);
		increase_stat(SKL);
		if( ESSTOTAL>=5 && energy>=16 ){prehidden=nymph_of_orchards;}
		break;
	}
}
void whalamato(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Whalamato");break;
	case ENERGY: energy=32;break;
	case   CODE:
		stat_limits(-5,10,HP);
		stat_min(10,HP);
		if( gn>=3 && un>=3 && energy>=8 ){prehidden=unicorn;}
		break;
	}
}
void pine_oclock(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Pine O'Clock");break;
	case ENERGY: energy=24;break;
	case   CODE:
		immunity=Sleep;
		/* ??? 80 81(88 7B)80 */
		if( sa*gn*ji*un>0 && energy>=8 ){ /* ??? 80 81(88 7C)80 - */
			prehidden=ragnarok;
		}
		break;
	}
}
void fishy_fruit(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Fishy Fruit");break;
	case ENERGY: energy=32;break;
	case   CODE:
		prehidden=spring;
		stat_limits(-1,3,MAG);
		increase_stat(MAG);
		taint(UNDINE);
		break;
	}
}
void boarmelon(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Boarmelon");break;
	case ENERGY: energy=32;break;
	case   CODE:
		stat_limits(-1,3,PWR);
		increase_stat(PWR);
		break;
	}
}
void rhinoloupe(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Rhinoloupe");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&sharp);
		immunity=Poison;
		break;
	}
}
void orcaplant(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Orcaplant");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if( un>=3 && ESSTOTAL>=5 ){prehidden=ocean_god;}
		break;
	}
}
void garlicrown(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Garlicrown");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( energy>=8 ){prehidden=king;}
		unsticky();
		taint(AURA);
		break;
	}
}
void honey_onion(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Honey Onion");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if( energy>=8 ){prehidden=princess;}
		taint(DRYAD);
		break;
	}
}
void sweet_moai(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Sweet Moai");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if(HELM){
			perc125(&strike);
			perc125(&slash);
			perc125(&thrust);
		} else if(HAT){
			perc150(&strike);
			perc150(&slash);
			perc150(&thrust);
		}
		break;
	}
}
void spiny_carrot(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Spiny Carrot");break;
	case ENERGY: energy=8;break;
	case   CODE:
		perc125(&sharp);
		perc75(&heavy);
		taint(UNDINE);
		break;
	}
}
void conchurnip(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Conchurnip");break;
	case ENERGY: energy=16;break;
	case   CODE:
		stat_limits(-1,3,DEF);
		increase_stat(DEF);
		if( energy>=16 ){prehidden=spirit_of_ocean;}
		break;
	}
}
void cornflower(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Cornflower");break;
	case ENERGY: energy=24;break;
	case   CODE:
		taint(WISP);
		break;
	}
}
void cabadillo(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Cabadillo");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if(HAUBERK){
			perc125(&strike);
			perc125(&slash);
			perc125(&thrust);
			perc50(&magic);
		}
		break;
	}
}
void needlettuce(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Needlettuce");break;
	case ENERGY: energy=24;break;
	case   CODE:
		perc125(&sharp);
		perc75(&heavy);
		if( 0==sa && dr>0 && energy>=8 ){prehidden=bed_of_thorn;}
		break;
	}
}
void cherry_bombs(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Cherry Bomb");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if(RING){stat_limits(-3,9,ALL);}
		break;
	}
}
void masked_potato(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Masked Potato");break;
	case ENERGY: energy=24;break;
	case   CODE:
		perc75(&sharp);
		perc125(&heavy);
		break;
	}
}
void lilipods(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Lilipods");break;
	case ENERGY: energy=8;break;
	case   CODE:
		stat_limits(-1,3,SPR);
		increase_stat(SPR);
		if( energy>=8 ){prehidden=enticed_nymph;}
		break;
	}
}
void rocket_papaya(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Rocket Papaya");break;
	case ENERGY: energy=64;break;
	case   CODE:
		stat_limits(-5,10,CHM);
		increase_stat(CHM);
		if( 0==ji && wi>0 && energy>=8 ){prehidden=tower;}
		break;
	}
}
void orangeopus(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Orange'opus");break;
	case ENERGY: energy=64;break;
	case   CODE:
		stat_limits(-5,10,DEF);
		increase_stat(DEF);
		if( 0==sa && gn>=5 && energy>=8 ){prehidden=leviathan;}
		break;
	}
}
void bumpkin(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Bumpkin");break;
	case ENERGY: energy=24;break;
	case   CODE:
		stat_limits(-1,3,LCK);
		stat_min(3,LCK);
		if( energy>=8 ){prehidden=clown;}
		break;
	}
}
void heart_mint(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Heart Mint");break;
	case ENERGY: energy=8;break;
	case   CODE:
		stat_limits(-1,3,CHM);
		increase_stat(CHM);
		if( sh>=2 && gn>=2 && un>=2 && energy>=8 ){prehidden=mother_of_gods;}
		break;
	}
}
void spade_basil(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Spade Basil");break;
	case ENERGY: energy=16;break;
	case   CODE:
		perc125(&sharp);
		if( wi>=3 && ESSTOTAL>=6 && energy>=8 ){prehidden=ruler_of_the_sky;}
		break;
	}
}
void dialaurel(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Dialaurel");break;
	case ENERGY: energy=64;break;
	case   CODE:
		if( 0==sa && sh>0 && energy>=8 ){prehidden=metropolis;}
		break;
	}
}
void gold_clover(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Gold Clover");break;
	case ENERGY: energy=64;break;
	case   CODE:
		perc125(&heavy);
		break;
	}
}
void mush_in_a_box(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Mush-In-A-Box");break;
	case ENERGY: energy=32;break;
	case   CODE:
		taint(SHADE);
		break;
	}
}
void toadstoolshed(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Toadstoolshed");break;
	case ENERGY: energy=64;break;
	case   CODE:
		increase_stat(ALL);
		taint(SHADE);
		break;
	}
}
void all_meat(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Any Meat");break;
	case ENERGY: energy=16;break;
	case   CODE: break;
	}
}
void sharp_claw(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Sharp Claw");break;
	case ENERGY: energy=24;break;
	case   CODE:
		perc150(&sharp);
		perc50(&heavy);
		if( 0==un && sa>=5 && energy>=8 ){prehidden=god_of_destruction;}
		break;
	}
}
void poison_fang(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Poison Fang");break;
	case ENERGY: energy=8;break;
	case   CODE:
		perc50(&force);
		perc150(&tech);
		if( 0==au && dr>=5 && energy>=8 ){prehidden=beast_headed_god;}
		break;
	}
}
void giants_horn(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Giant's Horn");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc50(&sharp);
		perc150(&heavy);
		if( 0==sa && gn>=5 && energy>=8 ){prehidden=leviathan;}
		break;
	}
}
void scissors(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Scissors");break;
	case ENERGY: energy=16;break;
	case   CODE:
		perc150(&force);
		perc50(&tech);
		break;
	}
}
void healing_claw(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Healing Claw");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if(SHIELD){
			immunity|=Poison;
		}
		if( 0==sa && wi>0 && energy>=8 ){prehidden=tower;}
		break;
	}
}
void zombie_claw(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Zombie Claw");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if(PENDANT){
			immunity|=Paralysis;
		}
		break;
	}
}
void vampire_fang(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Vampire Fang");break;
	case ENERGY: energy=24;break;
	case   CODE:
		stat_limits(-3,5,CHM);
		stat_limits(-3,5,SPR);
		increase_stat(CHM);
		increase_stat(SPR);
		if( 0==ji && un>=5 && energy>=8 ){prehidden=witch_of_moon;}
		break;
	}
}
void little_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Little Eye");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&slash);
		if( energy>=4 ){prehidden=pixie_of_pride;}
		break;
	}
}
void sleepy_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Sleepy Eye");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&thrust);
		if( energy>=4 ){prehidden=pixie_of_laziness;}
		break;
	}
}
void silly_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Silly Eye");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&heavy);
		if( energy>=4 ){prehidden=pixie_of_gluttony;}
		break;
	}
}
void dangerous_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Dangerous Eye");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&strike);
		if( energy>=4 ){prehidden=pixie_of_greed;}
		break;
	}
}
void angry_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Angry Eye");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&force);
		if( energy>=4 ){prehidden=pixie_of_rage;}
		break;
	}
}
void blank_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Blank Eye");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&tech);
		if( energy>=4 ){prehidden=pixie_of_jealousy;}
		break;
	}
}
void creepy_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Creepy Eye");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc125(&magic);
		if( energy>=4 ){prehidden=pixie_of_lust;}
		break;
	}
}
void wicked_eye(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Wicked Eye");break;
	case ENERGY: energy=48;break;
	case   CODE:
		perc125(&sharp);
		break;
	}
}
void angel_feather(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Angel Feather");break;
	case ENERGY: energy=32;break;
	case   CODE:
		stat_limits(-3,5,CHM);
		increase_stat(CHM);
		if( 0==sh && wi>=5 && energy>=8 ){prehidden=fallen_angel;}
		taint(WISP);
		break;
	}
}
void raven_feather(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Raven Feather");break;
	case ENERGY: energy=24;break;
	case   CODE:
		stat_limits(-3,5,SPR);
		increase_stat(SPR);
		if( energy>=8 ){prehidden=raven;}
		taint(SHADE);
		break;
	}
}
void clear_feather(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Clear Feather");break;
	case ENERGY: energy=24;break;
	case   CODE:
		perc50(&heavy);
		perc150(&tech);
		if( 0==gn && ji>=5 && energy>=8 ){prehidden=lord_of_flies;}
		break;
	}
}
void moth_wing(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Moth Wing");break;
	case ENERGY: energy=32;break;
	case   CODE:
		perc75(&strike);
		perc75(&slash);
		perc75(&thrust);
		perc150(&magic);
		if( energy>=8 ){prehidden=spirit_of_forest;}
		break;
	}
}
void flaming_quill(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Flaming Quill");break;
	case ENERGY: energy=64;break;
	case   CODE:
		stat_limits(-3,5,PWR);
		stat_min(5,PWR);
		if( sa>=3 && ji>=3 && energy>=4 ){prehidden=phoenix;}
		break;
	}
}
void white_feather(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("White Feather");break;
	case ENERGY: energy=32;break;
	case   CODE:
		stat_limits(-3,5,SKL);
		stat_min(5,SKL);
		if( wi>0 && ESSTOTAL>=3 && energy>=8 ){prehidden=nymph_of_the_sky;}
		break;
	}
}
void aroma_oil(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Aroma Oil");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if(HIDE){
			perc150(&strike);
			perc150(&slash);
			perc150(&thrust);
		}
		if( ESSTOTAL>=6 && energy>=8 ){prehidden=wisdom_goddess;}
		break;
	}
}
void dragon_blood(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Dragon Blood");break;
	case ENERGY: energy=64;break;
	case   CODE:
		increase_stat(ALL);
		if( sa>=3 && ESSTOTAL>=5 && energy>=8 ){prehidden=god_of_war;}
		break;
	}
}
void acid(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Acid");break;
	case ENERGY: energy=48;break;
	case   CODE: break;
	}
}
void holy_water(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Holy Water");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( energy>=8 ){prehidden=cleric;}
		unsticky();
		break;
	}
}
void ether(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Ether");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( au>=3 && gn>=3 && energy>=8 ){prehidden=blacksmith_god;}
		if( au< 3 || gn< 3 ){prehidden=spirit_of_mountain;}
		break;
	}
}
void mercury(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Mercury");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if(energy>=4){prehidden=witch;}
		break;
	}
}
void stinky_breath(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Stinky Breath");break;
	case ENERGY: energy=16;break;
	case   CODE:
		immunity=Poison+Confusion;
		if( energy>=4 ){prehidden=pixie_of_lust;}
		break;
	}
}
void ghosts_howl(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Ghost's Howl");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if( energy>=8 ){prehidden=sacrificed_nymph;}
		break;
	}
}
void dragons_breath(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Dragon's Breath");break;
	case ENERGY: energy=24;break;
	case   CODE:
		perc125(&force);
		perc125(&tech);
		if( wi>0 && sa>0 && ESSTOTAL>=3 && energy>=8 ){prehidden=man_of_valor;}
		break;
	}
}
void virgins_sigh(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Virgin's Sigh");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( sh>=3 && dr>=3 && energy>=8 ){prehidden=goddess_of_love;}
		break;
	}
}
void electricity(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Electricity");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if( wi>=3 && sa>=3 && ji>=3 && energy>=8 ){prehidden=thunder_god;}
		break;
	}
}
void moss(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Moss");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if(HELM){
			immunity|=Darkness;
		}
		break;
	}
}
void ear_of_wheat(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Ear Of Wheat");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if( dr>=3 && ESSTOTAL>=5 && energy>=8 ){prehidden=fertility_goddess;}
		break;
	}
}
void baked_roach(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Baked Roach");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if(ROBE){
			immunity|=Poison;
		}
		break;
	}
}
void blackened_bat(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Blackened Bat");break;
	case ENERGY: energy=48;break;
	case   CODE:
		if(PENDANT){
			immunity|=Darkness;
		}
		if( 0==wi && sh>=5 && energy>=8 ){prehidden=wings_of_darkness;}
		break;
	}
}
void sulpher(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Sulpher");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if(energy>=4){prehidden=sorcerer;}
		break;
	}
}
void poison_powder(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Poison Powder");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( energy>=4 ){prehidden=pixie_of_rage;}
		break;
	}
}
void sleepy_powder(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Sleepy Powder");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( energy>=4 ){prehidden=pixie_of_jealousy;}
		break;
	}
}
void knockout_dust(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Knockout Dust");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( energy>=4 ){prehidden=pixie_of_gluttony;}
		break;
	}
}
void rust(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Rust");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( energy>=4 ){prehidden=pixie_of_laziness;}
		break;
	}
}
void grave_dirt(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Grave Dirt");break;
	case ENERGY: energy=32;break;
	case   CODE:
		if( energy>=8 ){prehidden=dying_earth;}
		break;
	}
}
void ash(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Ash");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( energy>=8 ){prehidden=volcano;}
		break;
	}
}
void hairball(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Hairball");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( energy>=8 ){prehidden=spirit_of_housework;}
		break;
	}
}
void needle(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Needle");break;
	case ENERGY: energy=8;break;
	case   CODE:
		if( 0==sa && dr>0 && energy>=8 ){prehidden=bed_of_thorn;}
		break;
	}
}
void mirror_piece(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Mirror Piece");break;
	case ENERGY: energy=24;break;
	case   CODE:
		if( ESSTOTAL>=3 && energy>=8 ){prehidden=mirrored_world;}
		break;
	}
}
void wad_of_wool(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Wad Of Wool");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( sh>0 && dr>0 && ESSTOTAL>=3 && energy>=8 ){prehidden=wanderer;}
		break;
	}
}
void messy_scroll(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Messy Scroll");break;
	case ENERGY: energy=16;break;
	case   CODE:
		if( ji>0 && un>0 && ESSTOTAL>=3 && energy>=8 ){prehidden=sage;}
		break;
	}
}
void greenball_bun(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Greenball Bun");break;
	case ENERGY: energy=8;break;
	case   CODE:
		increase_stat(HP);
		break;
	}
}
void tako_bug(ITEM_F item_f){
	switch(item_f){
	case IPRINT: printf("Tako Bug");break;
	case ENERGY: energy=8;break;
	case   CODE:
		increase_stat(CHM);
		break;
	}
}

item_function *if_array[121]={
no_item,
wisp_gold,shade_gold,dryad_gold,aura_gold,sala_gold,gnome_gold,
jinn_gold,undine_gold,wisp_silver,shade_silver,dryad_silver,aura_silver,
sala_silver,gnome_silver,jinn_silver,undine_silver,fire_stone,earth_stone,
wind_stone,water_stone,sun_crystal,moon_crystal,glow_crystal,chaos_crystal,
round_seed,oblong_seed,crooked_seed,big_seed,small_seed,long_seed,
flat_seed,spiny_seed,bellgrapes,diceberry,mangoelephant,loquat_shoes,
pear_oheels,squalphin,citrisquid,springanana,peach_puppy,apricat,
applesocks,whalamato,pine_oclock,fishy_fruit,boarmelon,rhinoloupe,
orcaplant,garlicrown,honey_onion,sweet_moai,spiny_carrot,conchurnip,
cornflower,cabadillo,needlettuce,cherry_bombs,masked_potato,lilipods,
rocket_papaya,orangeopus,bumpkin,heart_mint,spade_basil,dialaurel,
gold_clover,mush_in_a_box,toadstoolshed,all_meat,sharp_claw,poison_fang,
giants_horn,scissors,healing_claw,zombie_claw,vampire_fang,little_eye,
sleepy_eye,silly_eye,dangerous_eye,angry_eye,blank_eye,wicked_eye,
creepy_eye,angel_feather,raven_feather,clear_feather,moth_wing,flaming_quill,
white_feather,aroma_oil,dragon_blood,acid,holy_water,ether,
mercury,stinky_breath,ghosts_howl,dragons_breath,virgins_sigh,electricity,
moss,ear_of_wheat,baked_roach,blackened_bat,sulpher,poison_powder,
sleepy_powder,knockout_dust,rust,grave_dirt,ash,hairball,
needle,mirror_piece,wad_of_wool,messy_scroll,greenball_bun,tako_bug
};

#define STR_IS(stryngi) (0==strcmp(dump,stryngi))

void get_item(void){
	int item_code;
	char dump[256];
	while(scanf("%d",&item_code)==0 || item_code>120 || item_code<1){
		scanf("%s",dump);
		if(STR_IS("?")){printf(item_list);}
		if(STR_IS("/")){pretty_print();}
	}
	item=if_array[item_code];
}

void init_item(void){
	item=no_item;
}