#include "calc.h"

/* needs energy, resistances, essences */

int power2[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

/* level raise */
int drLR,auLR,saLR,gnLR,jiLR,unLR;

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

void decrease(ESSENCE essence){
	switch(essence){
	case   WISP: if(wi>0){wi--;energy+=wiR*power2[wi];}break;
	case  SHADE: if(sh>0){sh--;energy+=shR*power2[sh];}break;
	case  DRYAD: if(dr>0&&energy>=4){dr--;energy+=drR*power2[dr];}break;
	case   AURA: if(au>0&&energy>=4){au--;energy+=auR*power2[au];}break;
	case   SALA: if(sa>0&&energy>=4){sa--;energy+=saR*power2[sa];}break;
	case  GNOME: if(gn>0&&energy>=4){gn--;energy+=gnR*power2[gn];}break;
	case   JINN: if(ji>0&&energy>=4){ji--;energy+=jiR*power2[ji];}break;
	case UNDINE: if(un>0&&energy>=4){un--;energy+=unR*power2[un];}break;
	}
}

void taint(ESSENCE essence){
	int i;

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
		else if( wi<sh ){for(i=wi;i>0;i--)decrease(WISP);}
		break;
	case  SHADE:
		if( energy>=8 ){ increase(SHADE); }
		if( wi<sh ){for(i=wi;i>0;i--)decrease(WISP);}
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
		if( wi>sh ){for(i=sh;i>0;i--)decrease(SHADE);}
		break;
	case  SHADE:
		if( 0==wi && energy>=8 ){ increase(SHADE); }
		else if( wi>sh ){for(i=sh;i>0;i--)decrease(SHADE);}
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

int main(void){

	char dump[256];
	int item_code,i,material;
	item_function *item;

	hidden=no_card;first=no_card;second=no_card;third=no_card;
	wi=0;sh=0;dr=0;au=0;sa=0;gn=0;ji=0;un=0;

	printf(material_list);
	while(scanf("%d",&material)==0 || material>55 || material<1){
		scanf("%s",dump);
		printf(material_list);
	}

	printf(item_list);
	while(0==0){

		while(scanf("%d",&item_code)==0){
			scanf("%s",dump);
			printf(item_list);
		}

		/* get item */
		if( item_code>120 || item_code<1 ) {
			printf("UNKNOWN:%d\n",item_code);
			item=no_item;
		} else {
			item=if_array[item_code];
		}

		/* initialization */
		wiR=mat_props[material][9];
		shR=mat_props[material][10];
		drR=mat_props[material][11];
		auR=mat_props[material][12];
		saR=mat_props[material][13];
		gnR=mat_props[material][14];
		jiR=mat_props[material][15];
		unR=mat_props[material][16];
		drLR=0;auLR=0;saLR=0;gnLR=0;jiLR=0;unLR=0;
		prehidden=no_card;leaving=no_card;
		sticky=STICKY;

		/* set active world card */
		awc=NONE;
		third(WORLD);second(WORLD);first(WORLD);hidden(WORLD);

		/* get energy from tempered item */
		item(ENERGY);

		/* material code */
		mat_code(mat_type[material]);

		/* tempered item code */
		item(CODE);

		/* push in cards */
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
    if(PIXIE_THIRD){
      if(PIXIE_SECOND){
        if(PIXIE_FIRST){
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

		/* leaving, third, second, first, hidden card code */
		leaving(LEAVING);third(THIRD);second(SECOND);first(FIRST);hidden(HIDDEN);

		/* increase essences */
		for(i=drLR;i>0;i--)increase( DRYAD);
		for(i=auLR;i>0;i--)increase(  AURA);
		for(i=saLR;i>0;i--)increase(  SALA);
		for(i=gnLR;i>0;i--)increase( GNOME);
		for(i=jiLR;i>0;i--)increase(  JINN);
		for(i=unLR;i>0;i--)increase(UNDINE);

		item(IPRINT);printf("\n");
		printf(" resists:%2d %2d %2d %2d %2d %2d %2d %2d\n",wiR,shR,drR,auR,saR,gnR,jiR,unR);
		printf("essences:%2d %2d %2d %2d %2d %2d %2d %2d\n",wi,sh,dr,au,sa,gn,ji,un);
		printf("excess energy: %d\n",energy);
		printf("(");hidden(CPRINT);printf(")\n ");
		 first(CPRINT);printf("\n ");
		second(CPRINT);printf("\n ");
		 third(CPRINT);printf("\n");
		printf(">");leaving(CPRINT);printf(">\n\n");
	}
	printf(item_list);
	return 0;
}
