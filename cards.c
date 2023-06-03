#include <stdio.h>
#include "cards.h"

typedef enum { CPRINT,PREHIDDEN,HIDDEN,FIRST,SECOND,THIRD,LEAVING,WORLD } CARD_F;

typedef void (card_function)(CARD_F);

card_function *prehidden,*hidden,*first,*second,*third,*leaving,
no_card,tower,sacrificed_nymph,spring,volcano,
pixie_of_jealousy,pixie_of_laziness,pixie_of_lust,pixie_of_pride,
pixie_of_gluttony,pixie_of_rage,pixie_of_greed,
fallen_angel,witch_of_moon,lord_of_flies,wings_of_darkness,
god_of_destruction,leviathan,beast_headed_god,enticed_nymph,metropolis;

typedef enum { NONE,YGGDRASIL,HEAVENS_SCALE,DYING_EARTH,RAGNAROK,
	ANCIENT_MOON,MIRRORED_WORLD,BED_OF_THORN } WORLD_CARD;
WORLD_CARD awc;

void set_active_world_card(void){
	awc=NONE;
	third(WORLD);second(WORLD);first(WORLD);hidden(WORLD);
}

typedef enum { STICKY,UNSTICKY } STICKY_F;
STICKY_F sticky;

void init_cards(void){
	hidden=no_card;first=no_card;second=no_card;third=no_card;
}

void sub_init_cards(void){
	prehidden=no_card;leaving=no_card;sticky=STICKY;
}

void unsticky(void){
	sticky=UNSTICKY;
}

#define PIXIE(pos) (pixie_of_jealousy==(pos)||pixie_of_laziness==(pos)||\
 pixie_of_lust==(pos)||pixie_of_pride==(pos)||pixie_of_gluttony==(pos)||\
 pixie_of_rage==(pos)||pixie_of_greed==(pos))

void push_cards(void){
if(no_card!=prehidden){
  if(no_card==hidden){
    hidden=prehidden;
  }else if(no_card==first){
    first=hidden;hidden=prehidden;
  }else if(no_card==second){
    second=first;first=hidden;hidden=prehidden;
  }else if(no_card==third){
    third=second;second=first;first=hidden;hidden=prehidden;
  }else if(STICKY==sticky){
    if(PIXIE(third)){
      if(PIXIE(second)){
        if(PIXIE(first)){
          leaving=hidden;hidden=prehidden;
        }else{
          leaving=first;first=hidden;hidden=prehidden;
        }
      }else{
        leaving=second;second=first;first=hidden;hidden=prehidden;
      }
    }else{
      leaving=third;third=second;second=first;first=hidden;hidden=prehidden;
    }
  }else{
    leaving=third;third=second;second=first;first=hidden;hidden=prehidden;
  }
}
}

void activate_cards(void){
	leaving(LEAVING);
	  third(THIRD);
	 second(SECOND);
	  first(FIRST);
	 hidden(HIDDEN);
}

void print_cards(void){
	    printf("\t(");
	 hidden(CPRINT);printf(")\n\t ");
	  first(CPRINT);printf("\n\t ");
	 second(CPRINT);printf("\n\t ");
	  third(CPRINT);printf("\n\t>");
	leaving(CPRINT);printf(">");
}

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
	case  THIRD:
		increase_stat(CHM);
		taint(WISP);
		break;
	}
}
void shade(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Shade");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(SPR);
		taint(SHADE);
		break;
	}
}
void dryad(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Dryad");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(HP);
		taint(DRYAD);
		break;
	}
}
void aura(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Aura");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(LCK);
		taint(AURA);
		break;
	}
}
void sala(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Salamander");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(PWR);
		taint(SALA);
		break;
	}
}
void gnome(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Gnome");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(DEF);
		taint(GNOME);
		break;
	}
}
void jinn(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Jinn");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(SKL);
		taint(JINN);
		break;
	}
}
void undine(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Undine");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(MAG);
		taint(UNDINE);
		break;
	}
}
void pixie_of_pride(CARD_F card_f){ /* pixie(1) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Pride");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){
    if(pixie_of_pride==third){third=fallen_angel;}
    else if(pixie_of_pride==second){second=fallen_angel;}
    else if(pixie_of_pride==first){first=fallen_angel;}
    else {printf("error with pixie_of_pride\n");}
}
			fallen_angel(FIRST);
		} else {
			stat_limits(-1,3,ALL);
			decrease_stat(ALL);
			increase_stat(CHM);
		}
		break;
	}
}
void pixie_of_laziness(CARD_F card_f){ /* pixie(2) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Laziness");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){
    if(pixie_of_laziness==third){third=witch_of_moon;}
    else if(pixie_of_laziness==second){second=witch_of_moon;}
    else if(pixie_of_laziness==first){first=witch_of_moon;}
    else {printf("error with pixie_of_laziness\n");}
}
			witch_of_moon(FIRST);
		} else {
			stat_limits(-1,3,ALL);
			decrease_stat(ALL);
			increase_stat(MAG);
		}
		break;
	}
}
void pixie_of_jealousy(CARD_F card_f){ /* pixie(3) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Jealousy");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){
    if(pixie_of_jealousy==third){third=lord_of_flies;}
    else if(pixie_of_jealousy==second){second=lord_of_flies;}
    else if(pixie_of_jealousy==first){first=lord_of_flies;}
    else {printf("error with pixie_of_jealousy\n");}
}
			lord_of_flies(FIRST);
		} else {
			stat_limits(-1,3,ALL);
			decrease_stat(ALL);
			increase_stat(SKL);
		}
		break;
	}
}
void pixie_of_lust(CARD_F card_f){ /* pixie(4) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Lust");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){
    if(pixie_of_lust==third){third=wings_of_darkness;}
    else if(pixie_of_lust==second){second=wings_of_darkness;}
    else if(pixie_of_lust==first){first=wings_of_darkness;}
    else {printf("error with pixie_of_lust\n");}
}
			wings_of_darkness(FIRST);
		} else {
			stat_limits(-1,3,ALL);
			decrease_stat(ALL);
			increase_stat(SPR);
		}
		break;
	}
}
void pixie_of_rage(CARD_F card_f){ /* pixie(5) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Rage");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){
    if(pixie_of_rage==third){third=god_of_destruction;}
    else if(pixie_of_rage==second){second=god_of_destruction;}
    else if(pixie_of_rage==first){first=god_of_destruction;}
    else {printf("error with pixie_of_rage\n");}
}
			god_of_destruction(FIRST);
		} else {
			stat_limits(-1,3,ALL);
			decrease_stat(ALL);
			increase_stat(PWR);
		}
		break;
	}
}
void pixie_of_gluttony(CARD_F card_f){ /* pixie(6) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Gluttony");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){
    if(pixie_of_gluttony==third){third=leviathan;}
    else if(pixie_of_gluttony==second){second=leviathan;}
    else if(pixie_of_gluttony==first){first=leviathan;}
    else {printf("error with pixie_of_gluttony\n");}
}
			leviathan(FIRST);
		} else {
			stat_limits(-1,3,ALL);
			decrease_stat(ALL);
			increase_stat(HP);
		}
		break;
	}
}
void pixie_of_greed(CARD_F card_f){ /* pixie(7) */
	switch(card_f){
	case CPRINT:	printf("Pixie of Greed");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if( RAGNAROK==awc ){
			if( energy>=8 ){
    if(pixie_of_greed==third){third=beast_headed_god;}
    else if(pixie_of_greed==second){second=beast_headed_god;}
    else if(pixie_of_greed==first){first=beast_headed_god;}
    else {printf("error with pixie_of_greed\n");}
}
			beast_headed_god(FIRST);
		} else {
			stat_limits(-1,3,ALL);
			decrease_stat(ALL);
			increase_stat(DEF);
		}
		break;
	}
}
void sorcerer(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Sorcerer");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
	if( tower==first || tower==second || tower==third ){
		stat_limits(-3,5,ALL);
		increase_stat(MAG);
		increase_stat(SPR);
		increase_stat(CHM);
		wiR=wiR/2; if(wiR<1) wiR=1;
		drR=drR/2; if(drR<1) drR=1;
		saR=saR/2; if(saR<1) saR=1;
		gnR=gnR/2; if(gnR<1) gnR=1;
	} else {
		stat_limits(-1,3,ALL);
		increase_stat(MAG);
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
		stat_limits(-3,5,ALL);
		increase_stat(MAG);
		increase_stat(SPR);
		increase_stat(CHM);
		shR=shR/2; if(shR<1) shR=1;
		auR=auR/2; if(auR<1) auR=1;
		jiR=jiR/2; if(jiR<1) jiR=1;
		unR=unR/2; if(unR<1) unR=1;
	} else {
		stat_limits(-1,3,ALL);
		increase_stat(MAG);
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
	case  FIRST:
	case SECOND:
	case  THIRD:
	if( metropolis==first || metropolis==second || metropolis==third ){
		stat_limits(-3,5,ALL);
		increase_stat(PWR);
	} else {
		stat_limits(-1,3,ALL);
		increase_stat(PWR);
	}
	if(GLOVE){
		plunge2=Hand_of_Midas;
	}
	break;
	}
}
void princess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Princess");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
	if( metropolis==first || metropolis==second || metropolis==third ){
		stat_limits(-3,5,ALL);
		increase_stat(DEF);
	} else {
		stat_limits(-1,3,ALL);
		increase_stat(DEF);
	}break;
	}
}
void clown(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Clown");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
	if( metropolis==first || metropolis==second || metropolis==third ){
		stat_limits(-5,12,ALL);
	} else {
		stat_limits(-3,9,ALL);
	}
	if(KNIFE){
		plunge2=Quick_Blade;
	}
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
	case  FIRST:
	case SECOND:
	case  THIRD:
	if( metropolis==first || metropolis==second || metropolis==third ){
		stat_limits(-3,5,ALL);
		increase_stat(MAG);
		increase_stat(SPR);
		increase_stat(CHM);
	} else {
		stat_limits(-1,3,ALL);
		increase_stat(SPR);
	}
	if(STAFF){
		plunge3=Demonicide;
	}
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
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-3,9,PWR);
		stat_limits(-3,9,MAG);
		stat_min(9,PWR);
		stat_min(9,MAG);
		if(SPEAR){
			plunge1=Gungnir;
		}else if(STAFF){
			plunge3=Electrosceptre;
		}
		break;
	}
}
void mother_of_gods(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Mother of Gods");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-3,5,MAG);
		stat_limits(-3,5,SPR);
		stat_limits(-3,5,CHM);
		stat_min(5,MAG);
		stat_min(5,SPR);
		stat_min(5,CHM);
		if(FLAIL){
			plunge1=Green_Princess;
			plunge2=Game_of_Death;
			plunge3=Red_Dream;
		}
		break;
	}
}
void sun_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Sun God");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,10,CHM);
		stat_min(10,CHM);
		if(SWORD){
			plunge2=Sunlight;
		}else if(BOW){
			plunge1=Solar_Flare;
		}
		break;
	}
}
void moon_goddess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Moon Goddess");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,10,SPR);
		stat_min(10,SPR);
		if(SWORD){
			plunge3=Moonlight;
		}else if(BOW){
			plunge2=Lunar_Shot;
		}
		break;
	}
}
void thunder_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Thunder God");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-3,5,PWR);
		stat_limits(-3,5,SKL);
		stat_limits(-3,5,DEF);
		stat_min(5,PWR);
		stat_min(5,SKL);
		stat_min(5,DEF);
		if(HAMMER){
			plunge3=Mjolnir;
		}
		break;
	}
}
void goddess_of_love(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Goddess of Love");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-3,9,SPR);
		stat_limits(-3,9,CHM);
		stat_min(7,SPR);
		stat_min(7,CHM);
		if(PENDANT){
			special=Extra_Lucre;
		}
		break;
	}
}
void fertility_goddess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Fertility Goddess");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,10,HP);
		stat_min(10,HP);
		immunity|=Petrify;
		if(RING){
			special=Share_Exp;
		}
		break;
	}
}
void ocean_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Ocean God");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-3,9,PWR);
		stat_limits(-3,9,SKL);
		stat_min(7,PWR);
		stat_min(7,SKL);
		if(SPEAR){
			plunge1=Trident;
		}
		immunity|=Flameburst;
		break;
	}
}
void wind_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wind God");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,10,SKL);
		stat_min(10,SKL);
		if(STAFF){
			/* ??? 80 81 88 7D 80 */
			plunge1=Caduceus;
		}
		if(SANDALS){
			strike+=10;
			slash +=10;
			thrust+=10;
			magic +=10;
			immunity|=Paralysis;
		}
		break;
	}
}
void wisdom_goddess(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wisdom Goddess");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,10,MAG);
		stat_min(10,MAG);
		if(SHIELD){
			special=Stare_Immunity;
		}
		break;
	}
}
void blacksmith_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Blacksmith God");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,10,DEF);
		stat_min(10,DEF);
		if(HAMMER){
			plunge3=Sledge_Hammer;
		}
		break;
	}
}
void god_of_war(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("God of War");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,10,PWR);
		stat_min(10,PWR);
		if(AXE){
			plunge2=Dragonslayer;
		}
		break;
	}
}
void fallen_angel(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Fallen Angel");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-10,20,ALL);
		stat_min(15,CHM);
		decrease_stat(ALL);
		if(THSWORD){
			plunge1=Chaotic_Avenger;
		}
		break;
	case LEAVING:
		if( sacrificed_nymph==third ){
			third=fallen_angel;
		} else if( sacrificed_nymph==second ){
			second=fallen_angel;
		} else if( sacrificed_nymph==first ){
			first=fallen_angel;
		}break;
	}
}
void witch_of_moon(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Witch of Moon");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-10,20,ALL);
		stat_min(15,MAG);
		decrease_stat(ALL);
		if(SWORD){
			plunge2=Vampsword;
		}
		break;
	case LEAVING:
		if( sacrificed_nymph==third ){
			third=witch_of_moon;
		} else if( sacrificed_nymph==second ){
			second=witch_of_moon;
		} else if( sacrificed_nymph==first ){
			first=witch_of_moon;
		}break;
	}
}
void lord_of_flies(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Lord of Flies");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-10,20,ALL);
		stat_min(15,SKL);
		decrease_stat(ALL);
		if(KNIFE){
			plunge3=Sinister_Blade;
		}
		break;
	case LEAVING:
		if( sacrificed_nymph==third ){
			third=lord_of_flies;
		} else if( sacrificed_nymph==second ){
			second=lord_of_flies;
		} else if( sacrificed_nymph==first ){
			first=lord_of_flies;
		}break;
	}
}
void wings_of_darkness(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wings of Darkness");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-10,20,ALL);
		stat_min(15,SPR);
		decrease_stat(ALL);
		if(STAFF){
			plunge3=Golden_Touch;
		}
		break;
	case LEAVING:
		if( sacrificed_nymph==third ){
			third=wings_of_darkness;
		} else if( sacrificed_nymph==second ){
			second=wings_of_darkness;
		} else if( sacrificed_nymph==first ){
			first=wings_of_darkness;
		}break;
	}
}
void god_of_destruction(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("God of Destruction");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-10,20,ALL);
		stat_min(15,PWR);
		decrease_stat(ALL);
		if(SWORD){
			plunge2=Flame_Tongue;
		}
		immunity|=Freeze;
		break;
	case LEAVING:
		if( sacrificed_nymph==third ){
			third=god_of_destruction;
		} else if( sacrificed_nymph==second ){
			second=god_of_destruction;
		} else if( sacrificed_nymph==first ){
			first=god_of_destruction;
		}break;
	}
}
void beast_headed_god(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Beast-headed God");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-10,20,ALL);
		stat_min(15,HP);
		decrease_stat(ALL);
		if(KNIFE){
			plunge2=Poison_Blade;
		}
		break;
	case LEAVING:
		if( sacrificed_nymph==third ){
			third=beast_headed_god;
		} else if( sacrificed_nymph==second ){
			second=beast_headed_god;
		} else if( sacrificed_nymph==first ){
			first=beast_headed_god;
		}break;
	}
}
void leviathan(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Leviathan");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-10,20,ALL);
		stat_min(15,DEF);
		decrease_stat(ALL);
		if(THAXE){
			plunge3=Treefeller;
		}
		break;
	case LEAVING:
		if( sacrificed_nymph==third ){
			third=leviathan;
		} else if( sacrificed_nymph==second ){
			second=leviathan;
		} else if( sacrificed_nymph==first ){
			first=leviathan;
		}break;
	}
}
void phoenix(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Phoenix");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-3,5,PWR);
		stat_limits(-3,5,SKL);
		stat_min(3,PWR);
		stat_min(3,SKL);
		if(RING||PENDANT){
			if(volcano==first||volcano==second||volcano==third){
				special=Auto_Revive;
			}
		}
		break;
	}
}
void unicorn(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Unicorn");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-3,5,DEF);
		stat_limits(-3,5,MAG);
		stat_min(3,DEF);
		stat_min(3,MAG);
		if(RING||PENDANT){
			if(spring==first||spring==second||spring==third){
				special=Fast_Revive;
			}
		}
		break;
	}
}
void spirit_of_ocean(CARD_F card_f){ /* spirit(1) */
	switch(card_f){
	case CPRINT:	printf("Spirit of Ocean");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(CHM);
		if(HAT){
			immunity|=Confusion;
		}
		break;
	}
}
void spirit_of_forest(CARD_F card_f){ /* spirit(2) */
	switch(card_f){
	case CPRINT:	printf("Spirit of Forest");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(SPR);
		increase_stat(CHM);
		if(BOW){
			plunge2=Elven_Archer;
		}
		break;
	}
}
void spirit_of_mountain(CARD_F card_f){ /* spirirt(3) */
	switch(card_f){
	case CPRINT:	printf("Spirit of Mountain");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(DEF);
		increase_stat(HP);
		if(HAMMER){
			plunge3=Quake_Hammer;
		}
		break;
	}
}
void spirit_of_shoes(CARD_F card_f){ /* spirit(4) */
	switch(card_f){
	case CPRINT:	printf("Spirit of Shoes");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(SKL);
		if(BOOTS){
			immunity|=Paralysis;
		}
		if(SANDALS){
			special=Extra_Exp;
		}
		break;
	}
}
void spirit_of_housework(CARD_F card_f){ /* spirit(5) */
	switch(card_f){
	case CPRINT:	printf("Spirit of Housework");break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		increase_stat(LCK);
		if(MANTLE){
			immunity|=Sleep;
		}
		if(RING){
			special=Extra_Lucre;
		}
		break;
	}
}
void yggdrasil(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Yggdrasil");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=YGGDRASIL;}break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if(STAFF){stat_limits(-3,9,ALL);}
		else {   stat_limits(-5,10,ALL);}
		increase_stat(ALL);
		break;
	}
}
void heavens_scale(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Heaven's Scale");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=HEAVENS_SCALE;}break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		special=No_Revive;
		break;
	}
}
void dying_earth(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Dying Earth");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=DYING_EARTH;}break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		stat_limits(-5,12,ALL);
	if(enticed_nymph!=first&&enticed_nymph!=second&&enticed_nymph!=third){
		decrease_stat(ALL);
	}
		break;
	}
}
void ragnarok(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Ragnarok");break;
	case HIDDEN: if(awc!=NONE&&awc!=BED_OF_THORN){hidden=no_card;}break;
	case  WORLD: if(awc==NONE){awc=RAGNAROK;}break;
	case  FIRST:
	case SECOND:
	case  THIRD:
		if(THSWORD){
			plunge3=Ragnarok;
		}
		break;
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
		stat_limits(-1,3,ALL);
		special=No_Regen;
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
		if(HAMMER){
			plunge3=Magma_Hammer;
		}
		if(HAUBERK){
			immunity|=Freeze;
		}
		break;
	}
}
void metropolis(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Metropolis");break;
	case FIRST:
	case SECOND:
	case THIRD:
		if(ROBE){
			perc150(&magic);
			immunity|=Confusion;
		} else {
			perc125(&magic);
		}
		break;
	}
}
void tower(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Tower");break;
	case FIRST:
	case SECOND:
	case THIRD:
		stat_limits(-3,5,ALL);
		break;
	}
}
void spring(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Spring");break;
	case FIRST:
	case SECOND:
	case THIRD:
		stat_limits(-3,5,ALL);
		if(ROBE){
			immunity|=Flameburst;
		}
		if(PENDANT){
			immunity|=Sleep;
		}
		break;
	}
}
void sacrificed_nymph(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Sacrificed Nymph");break;
	case FIRST:
	case SECOND:
	case THIRD:
		if(PENDANT){
			immunity|=Petrify;
		}
		break;
	}
}
void nymph_of_the_sky(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Nymph of the Sky");break;
	case FIRST:
	case SECOND:
	case THIRD:
		if(MANTLE){
			special=Move_Regen;
		}
		break;
	}
}
void nymph_of_orchards(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Nymph of Orchards");break;
	case FIRST:
	case SECOND:
	case THIRD:
		if(RING){
			special=Fast_Revive;
		}
		break;
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
	case FIRST:
	case SECOND:
	case THIRD:
		stat_limits(-3,5,ALL);
		increase_stat(MAG);
		increase_stat(DEF);
		if(BOW){
			plunge1=Phoenix_Falling;
		}
		break;
	}
}
void man_of_valor(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Man of Valor");break;
	case FIRST:
	case SECOND:
	case THIRD:
		stat_limits(-3,5,ALL);
		increase_stat(PWR);
		increase_stat(HP);
		if(SPEAR){
			plunge1=Spear_of_Light;
		}
		break;
	}
}
void wanderer(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wanderer");break;
	case FIRST:
	case SECOND:
	case THIRD:
		stat_limits(-3,5,ALL);
		increase_stat(SKL);
		increase_stat(SPR);
		if(AXE){
			plunge3=Woodchopper;
		}
		break;
	}
}
void nymph_of_dawn(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Nymph of Dawn");break;
	case SECOND:
	case  THIRD:
		if(energy<=24){
			if(nymph_of_dawn==third){third=no_card;}
			else if(nymph_of_dawn==second){second=no_card;}
			else {printf("error in nymph_of_dawn\n");}
			energy+=192;
		}
		break;
	case LEAVING: energy+=192;break;
	}
}
void raven(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Raven");break;
	case FIRST:
	case SECOND:
	case THIRD:
		stat_limits(-3,5,MAG);
		stat_limits(-3,5,CHM);
		stat_min(3,MAG);
		stat_min(3,CHM);
		break;
	}
}
void wolf(CARD_F card_f){
	switch(card_f){
	case CPRINT:	printf("Wolf");break;
	case FIRST:
	case SECOND:
	case THIRD:
		stat_limits(-3,5,SKL);
		stat_limits(-3,5,HP);
		stat_min(3,SKL);
		stat_min(3,HP);
		break;
	}
}
