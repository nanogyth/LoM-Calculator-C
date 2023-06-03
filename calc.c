#include "calc.h"

int main(void){

	char dump[256];
	int item_code,i,attack;
	item_function *item;

	hidden=no_card;first=no_card;second=no_card;third=no_card;
	wi=0;sh=0;dr=0;au=0;sa=0;gn=0;ji=0;un=0;

	/* get equipment */
	printf(equip_list);
	while(scanf("%d",&equip)==0 || equip>23 || equip<1){
		scanf("%s",dump);
		printf(equip_list);
	}

	/* get material */
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
		sharp=mat_props[material][1];
		heavy=mat_props[material][2];
		force=mat_props[material][3];
		tech=mat_props[material][4];
		strike=mat_props[material][5];
		slash=mat_props[material][6];
		thrust=mat_props[material][7];
		magic=mat_props[material][8];
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
		leaving(LEAVING);third(THIRD);second(SECOND);
		first(FIRST);hidden(HIDDEN);

		/* increase essences */
		for(i=drLR;i>0;i--)increase( DRYAD);
		for(i=auLR;i>0;i--)increase(  AURA);
		for(i=saLR;i>0;i--)increase(  SALA);
		for(i=gnLR;i>0;i--)increase( GNOME);
		for(i=jiLR;i>0;i--)increase(  JINN);
		for(i=unLR;i>0;i--)increase(UNDINE);

		/* calculate attack/defense */
	if(equip<12){ /* weapon */
		attack=sharp*equip_props[equip][0]+
			heavy*equip_props[equip][1]+
			force*equip_props[equip][2]+
			tech*equip_props[equip][3];
		attack=attack*(mat_props[material][0]+ESSTOTAL)/
			mat_props[material][0]/128;
		if(attack>999){
			attack=999;
		}
	} else { /* armor */
		attack=strike*equip_props[equip][0]/64+
			slash*equip_props[equip][1]/64+
			thrust*equip_props[equip][2]/64+
			magic*equip_props[equip][3]/64;
	}

		/*printf(" resists:%2d %2d %2d %2d %2d %2d %2d %2d\n",
			wiR,shR,drR,auR,saR,gnR,jiR,unR);
		printf("excess energy: %d\n",energy);*/

		printf("\n%2d %2d %2d %2d %2d %2d %2d %2d : %3d\n",
			wi,sh,dr,au,sa,gn,ji,un,attack);
		item(IPRINT);printf("\n");
		printf("(");hidden(CPRINT);printf(")\n ");
		 first(CPRINT);printf("\n ");
		second(CPRINT);printf("\n ");
		 third(CPRINT);printf("\n");
		printf(">");leaving(CPRINT);printf(">\n");
	}
	return 0;
}
