#include <stdio.h>

int  pwr, skl, def, mag, hp, spr, chm, lck;
int hpwr,hskl,hdef,hmag,hhp,hspr,hchm,hlck; /*high value*/
int lpwr,lskl,ldef,lmag,lhp,lspr,lchm,llck; /*low value*/
int mpwr,mskl,mdef,mmag,mhp,mspr,mchm,mlck; /*min value*/

typedef enum { ALL,PWR,SKL,DEF,MAG,HP,SPR,CHM,LCK } STAT;

void init_stats(void){
	pwr=0;skl=0;def=0;mag=0;hp=0;spr=0;chm=0;lck=0;
}

void init_stat_limits(void){
	lpwr=0;lskl=0;ldef=0;lmag=0;lhp=0;lspr=0;lchm=0;llck=0;
	hpwr=1;hskl=1;hdef=1;hmag=1;hhp=1;hspr=1;hchm=1;hlck=1;
	mpwr=-10;mskl=-10;mdef=-10;mmag=-10;mhp=-10;mspr=-10;mchm=-10;mlck=-10;

}

void stat_min(int min, STAT stat){
	switch(stat){
	case PWR: mpwr=min;break;
	case SKL: mskl=min;break;
	case DEF: mdef=min;break;
	case MAG: mmag=min;break;
	case  HP: mhp =min;break;
	case SPR: mspr=min;break;
	case CHM: mchm=min;break;
	case LCK: mlck=min;break;
	case ALL:
		stat_min(min,PWR);
		stat_min(min,SKL);
		stat_min(min,DEF);
		stat_min(min,MAG);
		stat_min(min,HP);
		stat_min(min,SPR);
		stat_min(min,CHM);
		stat_min(min,LCK);
		break;
	}
}

void stat_max(int max, STAT stat){
	switch(stat){
	case PWR: if(max>hpwr){hpwr=max;}break;
	case SKL: if(max>hskl){hskl=max;}break;
	case DEF: if(max>hdef){hdef=max;}break;
	case MAG: if(max>hmag){hmag=max;}break;
	case  HP: if(max>hhp ){hhp =max;}break;
	case SPR: if(max>hspr){hspr=max;}break;
	case CHM: if(max>hchm){hchm=max;}break;
	case LCK: if(max>hlck){hlck=max;}break;
	case ALL:
		stat_max(max,PWR);
		stat_max(max,SKL);
		stat_max(max,DEF);
		stat_max(max,MAG);
		stat_max(max,HP);
		stat_max(max,SPR);
		stat_max(max,CHM);
		stat_max(max,LCK);
		break;
	}
}

void stat_limits(int low, int high, STAT stat){
	switch(stat){
	case PWR:if(low<lpwr){lpwr=low;}if(high>hpwr){hpwr=high;}break;
	case SKL:if(low<lskl){lskl=low;}if(high>hskl){hskl=high;}break;
	case DEF:if(low<ldef){ldef=low;}if(high>hdef){hdef=high;}break;
	case MAG:if(low<lmag){lmag=low;}if(high>hmag){hmag=high;}break;
	case  HP:if(low<lhp ){lhp =low;}if(high>hhp ){hhp =high;}break;
	case SPR:if(low<lspr){lspr=low;}if(high>hspr){hspr=high;}break;
	case CHM:if(low<lchm){lchm=low;}if(high>hchm){hchm=high;}break;
	case LCK:if(low<llck){llck=low;}if(high>hlck){hlck=high;}break;
	case ALL:
		stat_limits(low,high,PWR);
		stat_limits(low,high,SKL);
		stat_limits(low,high,DEF);
		stat_limits(low,high,MAG);
		stat_limits(low,high,HP);
		stat_limits(low,high,SPR);
		stat_limits(low,high,CHM);
		stat_limits(low,high,LCK);
		break;
	}
}

int up_value(int value){
	switch(value){
	case -10: return -5; break;
	case -5: return -3; break;
	case -3: return -1; break;
	case -1: return 0; break;
	case 0: return 1; break;
	case 1: return 2; break;
	case 2: return 3; break;
	case 3: return 4; break;
	case 4: return 5; break;
	case 5: return 7; break;
	case 7: return 9; break;
	case 9: return 10; break;
	case 10: return 12; break;
	case 12: return 15; break;
	case 15: return 20; break;
	case 20: return 20; break;
	default:
		printf("stat error: %d found\n",value);
		return 0;
		break;
	}
}

int down_value(int value){
	switch(value){
	case -10: return -10; break;
	case -5: return -10; break;
	case -3: return -5; break;
	case -1: return -3; break;
	case 0: return -1; break;
	case 1: return 0; break;
	case 2: return 1; break;
	case 3: return 2; break;
	case 4: return 3; break;
	case 5: return 4; break;
	case 7: return 5; break;
	case 9: return 7; break;
	case 10: return 9; break;
	case 12: return 10; break;
	case 15: return 12; break;
	case 20: return 15; break;
	default:
		printf("stat error: %d found\n",value);
		return 0;
		break;
	}
}

void increase_stat(STAT stat){
	switch(stat){
	case PWR: pwr=up_value(pwr);break;
	case SKL: skl=up_value(skl);break;
	case DEF: def=up_value(def);break;
	case MAG: mag=up_value(mag);break;
	case  HP:  hp=up_value( hp);break;
	case SPR: spr=up_value(spr);break;
	case CHM: chm=up_value(chm);break;
	case LCK: lck=up_value(lck);break;
	case ALL:
		increase_stat(PWR);
		increase_stat(SKL);
		increase_stat(DEF);
		increase_stat(MAG);
		increase_stat(HP);
		increase_stat(SPR);
		increase_stat(CHM);
		increase_stat(LCK);
		break;
	}
}

void decrease_stat(STAT stat){
	switch(stat){
	case PWR: pwr=down_value(pwr);break;
	case SKL: skl=down_value(skl);break;
	case DEF: def=down_value(def);break;
	case MAG: mag=down_value(mag);break;
	case  HP:  hp=down_value( hp);break;
	case SPR: spr=down_value(spr);break;
	case CHM: chm=down_value(chm);break;
	case LCK: lck=down_value(lck);break;
	case ALL:
		decrease_stat(PWR);
		decrease_stat(SKL);
		decrease_stat(DEF);
		decrease_stat(MAG);
		decrease_stat(HP);
		decrease_stat(SPR);
		decrease_stat(CHM);
		decrease_stat(LCK);
		break;
	}
}

void calculate_stats(void){
	if(pwr<lpwr){pwr=lpwr;}if(pwr>hpwr){pwr=hpwr;}
	if(skl<lskl){skl=lskl;}if(skl>hskl){skl=hskl;}
	if(def<ldef){def=ldef;}if(def>hdef){def=hdef;}
	if(mag<lmag){mag=lmag;}if(mag>hmag){mag=hmag;}
	if(hp <lhp ){hp =lhp ;}if(hp >hhp ){hp =hhp ;}
	if(spr<lspr){spr=lspr;}if(spr>hspr){spr=hspr;}
	if(chm<lchm){chm=lchm;}if(chm>hchm){chm=hchm;}
	if(lck<llck){lck=llck;}if(lck>hlck){lck=hlck;}

	if(pwr<mpwr){pwr=mpwr;}
	if(skl<mskl){skl=mskl;}
	if(def<mdef){def=mdef;}
	if(mag<mmag){mag=mmag;}
	if(hp <mhp ){hp =mhp ;}
	if(spr<mspr){spr=mspr;}
	if(chm<mchm){chm=mchm;}
	if(lck<mlck){lck=mlck;}
}

void print_stats(void){
	printf("%3d%3d%3d%3d%3d%3d%3d%3d",pwr,skl,def,mag,hp,spr,chm,lck);
}
