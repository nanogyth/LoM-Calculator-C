#include <stdio.h>
#include "essence.h"

int energy;
int wi,sh,dr,au,sa,gn,ji,un;
int drLR,auLR,saLR,gnLR,jiLR,unLR;

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;

int power2[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

void init_essences(void){
	wi=0;sh=0;dr=0;au=0;sa=0;gn=0;ji=0;un=0;
	drLR=0;auLR=0;saLR=0;gnLR=0;jiLR=0;unLR=0;
}

void print_essences(void){
	printf(" %2d %2d %2d %2d %2d %2d %2d %2d",
	wi,sh,dr,au,sa,gn,ji,un);
}

void print_resists(void){
	printf("Resists: %2d %2d %2d %2d %2d %2d %2d %2d\n",
	wiR,shR,drR,auR,saR,gnR,jiR,unR);
}

void increase(ESSENCE essence){
	switch(essence){
	case   WISP: if(wi<15&&energy>=wiR*power2[wi]){energy-=wiR*power2[wi];wi++;}break;
	case  SHADE: if(sh<15&&energy>=shR*power2[sh]){energy-=shR*power2[sh];sh++;}break;
	case  DRYAD: if(dr<15&&energy>=drR*power2[dr]){energy-=drR*power2[dr];dr++;}break;
	case   AURA: if(au<15&&energy>=auR*power2[au]){energy-=auR*power2[au];au++;}break;
	case   SALA: if(sa<15&&energy>=saR*power2[sa]){energy-=saR*power2[sa];sa++;}break;
	case  GNOME: if(gn<15&&energy>=gnR*power2[gn]){energy-=gnR*power2[gn];gn++;}break;
	case   JINN: if(ji<15&&energy>=jiR*power2[ji]){energy-=jiR*power2[ji];ji++;}break;
	case UNDINE: if(un<15&&energy>=unR*power2[un]){energy-=unR*power2[un];un++;}break;
	}
}

void increase_essences(void){
	for(;drLR>0;drLR--)increase( DRYAD);
	for(;auLR>0;auLR--)increase(  AURA);
	for(;saLR>0;saLR--)increase(  SALA);
	for(;gnLR>0;gnLR--)increase( GNOME);
	for(;jiLR>0;jiLR--)increase(  JINN);
	for(;unLR>0;unLR--)increase(UNDINE);
}

void decrease(ESSENCE essence){
	switch(essence){
	case   WISP: if(wi>0)           {wi--;energy+=wiR*power2[wi];}break;
	case  SHADE: if(sh>0)           {sh--;energy+=shR*power2[sh];}break;
	case  DRYAD: if(dr>0&&energy>=4){dr--;energy+=drR*power2[dr];}break;
	case   AURA: if(au>0&&energy>=4){au--;energy+=auR*power2[au];}break;
	case   SALA: if(sa>0&&energy>=4){sa--;energy+=saR*power2[sa];}break;
	case  GNOME: if(gn>0&&energy>=4){gn--;energy+=gnR*power2[gn];}break;
	case   JINN: if(ji>0&&energy>=4){ji--;energy+=jiR*power2[ji];}break;
	case UNDINE: if(un>0&&energy>=4){un--;energy+=unR*power2[un];}break;
	}
}

void taint(ESSENCE essence){
if( ANCIENT_MOON==awc ){
	switch(essence){
	case   WISP:if(energy>=8){ increase( WISP); }break;
	case  SHADE:if(energy>=8){ increase(SHADE); }break;
	case  DRYAD:if(energy>=8){          drLR++; }break;
	case   AURA:if(energy>=8){          auLR++; }break;
	case   SALA:if(energy>=8){          saLR++; }break;
	case  GNOME:if(energy>=8){          gnLR++; }break;
	case   JINN:if(energy>=8){          jiLR++; }break;
	case UNDINE:if(energy>=8){          unLR++; }break;
	}
} else if( MIRRORED_WORLD==awc ){
	switch(essence){
	case   WISP:
		if( 0==sh && energy>=8 ){ increase(WISP); }
		else if( wi<sh ){while(wi>0)decrease(WISP);}
		break;
	case  SHADE:
		if( energy>=8 ){ increase(SHADE); }
		if( wi<sh ){while(wi>0)decrease(WISP);}
		break;
	case  DRYAD:
		if( 0==au || wi==sh ){ if( energy>=8 ) drLR++; }
		else if( wi<sh ){ decrease(  AURA); if( energy>=8 ) drLR++; }
		break;
	case   AURA:
		if( 0==dr || wi==sh ){ if( energy>=8 ) auLR++; }
		else if( sh<wi ){ decrease( DRYAD); if( energy>=8 ) auLR++; }
		break;
	case   SALA:
		if( 0==gn ){ decrease(UNDINE); if( energy>=8 ) saLR++; }
		break;
	case  GNOME:
		if( 0==ji ){ decrease(  SALA); if( energy>=8 ) gnLR++; }
		break;
	case   JINN:
		if( 0==un ){ decrease( GNOME); if( energy>=8 ) jiLR++; }
		break;
	case UNDINE:
		if( 0==sa ){ decrease(  JINN); if( energy>=8 ) unLR++; }
		break;
	}
} else { /* normal_world */
	switch(essence){
	case   WISP:
		if( energy>=8 ){ increase(WISP); }
		if( wi>sh ){while(sh>0)decrease(SHADE);}
		break;
	case  SHADE:
		if( 0==wi && energy>=8 ){ increase(SHADE); }
		else if( wi>sh ){while(sh>0)decrease(SHADE);}
		break;
	case  DRYAD:
		if( 0==au || wi==sh ){ if( energy>=8 ) drLR++; }
		else if( wi>sh ){ decrease(  AURA); if( energy>=8 ) drLR++; }
		break;
	case   AURA:
		if( 0==dr || wi==sh ){ if( energy>=8 ) auLR++; }
		else if( sh>wi ){ decrease( DRYAD); if( energy>=8 ) auLR++; }
		break;
	case   SALA:
		if( 0==un ){ decrease( GNOME); if( energy>=8 ) saLR++; }
		break;
	case  GNOME:
		if( 0==sa ){ decrease(  JINN); if( energy>=8 ) gnLR++; }
		break;
	case   JINN:
		if( 0==gn ){ decrease(UNDINE); if( energy>=8 ) jiLR++; }
		break;
	case UNDINE:
		if( 0==ji ){ decrease(  SALA); if( energy>=8 ) unLR++; }
		break;
	}
}
}
