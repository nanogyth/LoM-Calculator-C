#include "calc.h"

void no_card(CARD_F card_f){
	switch(card_f){
	case CPRINT: printf("--");break;
	}
}
void wisp(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wisp");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(WISP);break;
	}
}
void shade(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Shade");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(SHADE);break;
	}
}
void dryad(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Dryad");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(DRYAD);break;
	}
}
void aura(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Aura");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(AURA);break;
	}
}
void sala(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Salamander");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(SALA);break;
	}
}
void gnome(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Gnome");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(GNOME);break;
	}
}
void jinn(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Jinn");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(JINN);break;
	}
}
void undine(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Undine");break;
	case  FIRST:
	case SECOND:
	case  THIRD:	taint(UNDINE);break;
	}
}
void pixie_of_pride(CARD_F card_f){ /* pixie(1) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Pride");break;
	case  FIRST:
		if( RAGNAROK==awc ){
			if( energy>=8 ){first=fallen_angel;}
			fallen_angel(FIRST);
		}break;
	case SECOND:
		if( RAGNAROK==awc ){
			if( energy>=8 ){second=fallen_angel;}
			fallen_angel(SECOND);
		}break;
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){third=fallen_angel;}
			fallen_angel(THIRD);
		}break;
	}
}
void pixie_of_laziness(CARD_F card_f){ /* pixie(2) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Laziness");break;
	case  FIRST:
		if( RAGNAROK==awc ){
			if( energy>=8 ){first=witch_of_moon;}
			witch_of_moon(FIRST);
		}break;
	case SECOND:
		if( RAGNAROK==awc ){
			if( energy>=8 ){second=witch_of_moon;}
			witch_of_moon(SECOND);
		}break;
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){third=witch_of_moon;}
			witch_of_moon(THIRD);
		}break;
	}
}
void pixie_of_jealousy(CARD_F card_f){ /* pixie(3) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Jealousy");break;
	case  FIRST:
		if( RAGNAROK==awc ){
			if( energy>=8 ){first=lord_of_flies;}
			lord_of_flies(FIRST);
		}break;
	case SECOND:
		if( RAGNAROK==awc ){
			if( energy>=8 ){second=lord_of_flies;}
			lord_of_flies(SECOND);
		}break;
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){third=lord_of_flies;}
			lord_of_flies(THIRD);
		}break;
	}
}
void pixie_of_lust(CARD_F card_f){ /* pixie(4) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Lust");break;
	case  FIRST:
		if( RAGNAROK==awc ){
			if( energy>=8 ){first=wings_of_darkness;}
			wings_of_darkness(FIRST);
		}break;
	case SECOND:
		if( RAGNAROK==awc ){
			if( energy>=8 ){second=wings_of_darkness;}
			wings_of_darkness(SECOND);
		}break;
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){third=wings_of_darkness;}
			wings_of_darkness(THIRD);
		}break;
	}
}
void pixie_of_rage(CARD_F card_f){ /* pixie(5) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Rage");break;
	case  FIRST:
		if( RAGNAROK==awc ){
			if( energy>=8 ){first=god_of_destruction;}
			god_of_destruction(FIRST);
		}break;
	case SECOND:
		if( RAGNAROK==awc ){
			if( energy>=8 ){second=god_of_destruction;}
			god_of_destruction(SECOND);
		}break;
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){third=god_of_destruction;}
			god_of_destruction(THIRD);
		}break;
	}
}
void pixie_of_gluttony(CARD_F card_f){ /* pixie(6) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Gluttony");break;
	case  FIRST:
		if( RAGNAROK==awc ){
			if( energy>=8 ){first=leviathan;}
			leviathan(FIRST);
		}break;
	case SECOND:
		if( RAGNAROK==awc ){
			if( energy>=8 ){second=leviathan;}
			leviathan(SECOND);
		}break;
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){third=leviathan;}
			leviathan(THIRD);
		}break;
	}
}
void pixie_of_greed(CARD_F card_f){ /* pixie(7) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Greed");break;
	case  FIRST:
		if( RAGNAROK==awc ){
			if( energy>=8 ){first=beast_headed_god;}
			beast_headed_god(FIRST);
		}break;
	case SECOND:
		if( RAGNAROK==awc ){
			if( energy>=8 ){second=beast_headed_god;}
			beast_headed_god(SECOND);
		}break;
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){third=beast_headed_god;}
			beast_headed_god(THIRD);
		}break;
	}
}
void sorcerer(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Sorcerer");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
	if( tower==first || tower==second || tower==third ){
		wiR=wiR/2; if(wiR<1) wiR=1;
		drR=drR/2; if(drR<1) drR=1;
		saR=saR/2; if(saR<1) saR=1;
		gnR=gnR/2; if(gnR<1) gnR=1;
	} else {
		wiR=(wiR/4)*3; if(wiR<1) wiR=1;
		drR=(drR/4)*3; if(drR<1) drR=1;
		saR=(saR/4)*3; if(saR<1) saR=1;
		gnR=(gnR/4)*3; if(gnR<1) gnR=1;
	}break;
	}
}
void witch(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Witch");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
	if( tower==first || tower==second || tower==third ){
		shR=shR/2; if(shR<1) shR=1;
		auR=auR/2; if(auR<1) auR=1;
		jiR=jiR/2; if(jiR<1) jiR=1;
		unR=unR/2; if(unR<1) unR=1;
	} else {
		shR=(shR/4)*3; if(shR<1) shR=1;
		auR=(auR/4)*3; if(auR<1) auR=1;
		jiR=(jiR/4)*3; if(jiR<1) jiR=1;
		unR=(unR/4)*3; if(unR<1) unR=1;
	}break;
	}
}
void king(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("King");break;
	}
}
void princess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Princess");break;
	}
}
void clown(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Clown");break;
	case FIRST:
	case SECOND:
	case THIRD:
		perc150(&sharp);
		perc50(&heavy);
		perc150(&thrust);
		perc50(&strike);
		break;
	}
}
void cleric(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Cleric");break;
	case FIRST:
	case SECOND:
	case THIRD:
		perc50(&sharp);
		perc150(&heavy);
		perc150(&strike);
		perc50(&slash);
		break;
	}
}
void ruler_of_the_sky(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Ruler of the Sky");break;
	}
}
void mother_of_gods(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Mother of Gods");break;
	}
}
void sun_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Sun God");break;
	}
}
void moon_goddess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Moon Goddess");break;
	}
}
void thunder_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Thunder God");break;
	}
}
void goddess_of_love(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Goddess of Love");break;
	}
}
void fertility_goddess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Fertility Goddess");break;
	}
}
void ocean_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Ocean God");break;
	}
}
void wind_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wind God");break;
	}
}
void wisdom_goddess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wisdom Goddess");break;
	}
}
void blacksmith_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Blacksmith God");break;
	}
}
void god_of_war(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("God of War");break;
	}
}
void fallen_angel(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Fallen Angel");break;
	case LEAVING:
		if( sacrificed_nymph==first ){
			first=fallen_angel;
		} else if( sacrificed_nymph==second ){
			second=fallen_angel;
		} else if( sacrificed_nymph==third ){
			third=fallen_angel;
		}break;
	}
}
void witch_of_moon(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Witch of Moon");break;
	case LEAVING:
		if( sacrificed_nymph==first ){
			first=witch_of_moon;
		} else if( sacrificed_nymph==second ){
			second=witch_of_moon;
		} else if( sacrificed_nymph==third ){
			third=witch_of_moon;
		}break;
	}
}
void lord_of_flies(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Lord of Flies");break;
	case LEAVING:
		if( sacrificed_nymph==first ){
			first=lord_of_flies;
		} else if( sacrificed_nymph==second ){
			second=lord_of_flies;
		} else if( sacrificed_nymph==third ){
			third=lord_of_flies;
		}break;
	}
}
void wings_of_darkness(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wings of Darkness");break;
	case LEAVING:
		if( sacrificed_nymph==first ){
			first=wings_of_darkness;
		} else if( sacrificed_nymph==second ){
			second=wings_of_darkness;
		} else if( sacrificed_nymph==third ){
			third=wings_of_darkness;
		}break;
	}
}
void god_of_destruction(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("God of Destruction");break;
	case LEAVING:
		if( sacrificed_nymph==first ){
			first=god_of_destruction;
		} else if( sacrificed_nymph==second ){
			second=god_of_destruction;
		} else if( sacrificed_nymph==third ){
			third=god_of_destruction;
		}break;
	}
}
void beast_headed_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Beast-headed God");break;
	case LEAVING:
		if( sacrificed_nymph==first ){
			first=beast_headed_god;
		} else if( sacrificed_nymph==second ){
			second=beast_headed_god;
		} else if( sacrificed_nymph==third ){
			third=beast_headed_god;
		}break;
	}
}
void leviathan(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Leviathan");break;
	case LEAVING:
		if( sacrificed_nymph==first ){
			first=leviathan;
		} else if( sacrificed_nymph==second ){
			second=leviathan;
		} else if( sacrificed_nymph==third ){
			third=leviathan;
		}break;
	}
}
void phoenix(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Phoenix");break;
	}
}
void unicorn(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Unicorn");break;
	}
}
void spirit_of_ocean(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Spirit of Ocean");break;
	}
}
void spirit_of_forest(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Spirit of Forest");break;
	}
}
void spirit_of_mountain(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Spirit of Mountain");break;
	}
}
void spirit_of_shoes(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Spirit of Shoes");break;
	}
}
void spirit_of_housework(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Spirit of Housework");break;
	}
}
void yggdrasil(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Yggdrasil");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=YGGDRASIL;}break;
	}
}
void heavens_scale(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Heaven's Scale");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=HEAVENS_SCALE;}break;
	}
}
void dying_earth(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Dying Earth");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=DYING_EARTH;}break;
	}
}
void ragnarok(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Ragnarok");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=RAGNAROK;}break;
	}
}
void ancient_moon(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Ancient Moon");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=ANCIENT_MOON;}break;
	}
}
void mirrored_world(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Mirrored World");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=MIRRORED_WORLD;}break;
	}
}
void bed_of_thorn(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Bed of Thorn");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=BED_OF_THORN;}break;
	case FIRST:
	case SECOND:
	case THIRD:
		perc150(&strike);
		perc150(&slash);
		perc150(&thrust);
		perc150(&magic);
		break;
	}
}
void volcano(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Volcano");break;
	case FIRST:
	case SECOND:
	case THIRD:
		perc150(&force);
		perc50(&tech);
		break;
	}
}
void metropolis(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Metropolis");break;
	case FIRST:
	case SECOND:
	case THIRD:
		if(16==equip){ /* robe */
			perc150(&magic);
		} else {
			perc125(&magic);
		}
		break;
	}
}
void tower(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Tower");break;
	}
}
void spring(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Spring");break;
	}
}
void sacrificed_nymph(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Sacrificed Nymph");break;
	}
}
void nymph_of_the_sky(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Nymph of the Sky");break;
	}
}
void nymph_of_orchards(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Nymph of Orchards");break;
	}
}
void enticed_nymph(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Enticed Nymph");break;
	}
}
void sage(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Sage");break;
	}
}
void man_of_valor(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Man of Valor");break;
	}
}
void wanderer(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wanderer");break;
	}
}
void nymph_of_dawn(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Nymph of Dawn");break;
	case SECOND:if(energy<=24){second=no_card; energy+=192;}break;
	case  THIRD:if(energy<=24){ third=no_card; energy+=192;}break;
	case LEAVING: energy+=192;break;
	}
}
void raven(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Raven");break;
	}
}
void wolf(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wolf");break;
	}
}
