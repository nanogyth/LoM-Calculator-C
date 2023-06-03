#include <stdio.h>
#include "material.h"

int material;
#define WOOD (material>11 && material<20)
#define AEROLITE (material>39 && material<48)

int equip;
#define BOW     (11==equip)
#define RING    (18==equip)
#define PENDANT (23==equip)
#define WEAPON  (equip<12)


int sharp,heavy,force,tech,strike,slash,thrust,magic;
int wiR,shR,drR,auR,saR,gnR,jiR,unR;

char *equip_list=
" 1 Knife    12 Shield  \n"
" 2 Sword    13 Helm    \n"
" 3 Axe      14 Hat     \n"
" 4 2H Sword 15 Hauberk \n"
" 5 2H Axe   16 Robe    \n"
" 6 Hammer   17 Gauntlet\n"
" 7 Spear    18 Ring    \n"
" 8 Staff    19 Boots   \n"
" 9 Glove    20 Shoes   \n"
"10 Flail    21 Armor   \n"
"11 Bow      22 Mantle  \n"
"            23 Pendant \n";

void get_equipment(void){
	char dump[256];
	printf(equip_list);
	while(scanf("%d",&equip)==0 || equip>23 || equip<1){
		scanf("%s",dump);
		printf(equip_list);
	}
}

char *material_list=
" 1 MenosBronze  21 Obsidian     41 HalleyRock   \n"
" 2 ForsenaIron  22 PedanStone   42 AnkhRock     \n"
" 3 GranzSteel   23 Gaeus'sTears 43 VinekRock    \n"
" 4 LorantSilver 24 AnimalHide   44 TuttleRock   \n"
" 5 WendelSilver 25 GatorSkin    45 NemesisRock  \n"
" 6 VizelGold    26 CentaurHide  46 BiellaRock   \n"
" 7 IshePlatinum 27 DragonSkin   47 SwifteRock   \n"
" 8 LorimarIron  28 FishScales   48 Adamantite   \n"
" 9 AltenaAlloy  29 LizardScales 49 Fullmetal    \n"
"10 MaiaLead     30 SnakeScales  50 Coral        \n"
"11 Orihalcon    31 DragonScales 51 TortoiseShell\n"
"12 OakWood      32 AnimalBone   52 Shell        \n"
"13 HollyWood    33 Ivory        53 Emerald      \n"
"14 BaobabWood   34 CursedBone   54 Pearl        \n"
"15 EbonyWood    35 Fossil       55 LapisLazuli  \n"
"16 MapleWood    36 ToppleCotton \n"
"17 DiorWood     37 Sultan'sSilk \n"
"18 AshWood      38 JuddHemp     \n"
"19 FossilWood   39 AltenaFelt   \n"
"20 Marble       40 JacobiniRock \n";

void get_material(void){
	char dump[256];
	printf(material_list);
	while(scanf("%d",&material)==0 || material>55 || material<1){
		scanf("%s",dump);
		printf(material_list);
	}
}

/* weapon/armor stats[4], marker level[1], menos sell price[1] */

int equip_props[24][6]={
 0, 0, 0, 0, 3,  0, /*No Wep  */
44,16,12,48, 1, 45, /*Knife   */
32,32,32,32, 1, 50, /*Sword   */
28,36,48,16, 2, 50, /*Axe     */
40,40,40,40, 2, 75, /*2H Sword*/
40,40,64,16, 3, 75, /*2H Axe  */
 8,72,64,16, 3, 75, /*Hammer  */
52,20,24,48, 2, 60, /*Spear   */
 4,44,16,32, 1, 30, /*Staff   */
 0,32,24,56, 2, 40, /*Glove   */
 0,40,28,44, 3, 40, /*Flail   */
40, 4,20,40, 1, 35, /*Bow     */
 8, 8, 8, 4, 1, 10, /*Shield  */
 8, 7, 6, 2, 2, 25, /*Helm    */
 4, 2, 2, 4, 2, 15, /*Hat     */
12,16,16, 2, 2, 60, /*Hauberk */
 6, 6, 6, 8, 2, 30, /*Robe    */
 7, 6, 8, 2, 2, 25, /*Gauntlet*/
 1, 1, 1,16, 1,  5, /*Ring    */
 6, 8, 7, 2, 2, 25, /*Boots   */
 2, 4, 2, 4, 2, 10, /*Shoes   */
26,26,26, 4, 3, 75, /*Armor   */
 4, 4, 4,12, 2, 20, /*Mantle  */
 0, 0, 0,24, 1,  5  /*Pendant */
};

void print_markers(void){
	int level=equip_props[equip][4];

	printf("Markers:");
	if(WEAPON){
		if(wi>=level){printf(" wi");}else{printf("   ");}
		if(sh>=level){printf(" sh");}else{printf("   ");}
		if(dr>=level){printf(" dr");}else{printf("   ");}
		if(au>=level){printf(" au");}else{printf("   ");}
		if(sa>=level){printf(" sa");}else{printf("   ");}
		if(gn>=level){printf(" gn");}else{printf("   ");}
		if(ji>=level){printf(" ji");}else{printf("   ");}
		if(un>=level){printf(" un");}else{printf("   ");}
	}else{ /* armor */
		if(sh>=level){printf(" wi");}else{printf("   ");}
		if(wi>=level){printf(" sh");}else{printf("   ");}
		if(au>=level){printf(" dr");}else{printf("   ");}
		if(dr>=level){printf(" au");}else{printf("   ");}
		if(gn>=level){printf(" sa");}else{printf("   ");}
		if(ji>=level){printf(" gn");}else{printf("   ");}
		if(un>=level){printf(" ji");}else{printf("   ");}
		if(sa>=level){printf(" un");}else{printf("   ");}
	}
	printf("\n");
}

/* growth control[1], weapon stats[4], armor stats[4], resistances[8], raw sell price[1] */

int mat_props[56][18]={
 1,  0, 0, 0, 0,  0, 0, 0, 0,  1, 1, 1, 1, 1, 1, 1, 1,    0, /*No Material  */
18, 10,10,10,10, 10,10,10,10,  8, 8, 8, 8, 8, 8, 8, 8,  150, /*MenosBronze  */
20, 15,15,15,15, 15,15,15,15,  9, 9, 9, 9, 9, 9, 9, 9,  300, /*ForsenaIron  */
24, 20,20,20,20, 20,20,20,20,  9, 9, 9, 9, 9, 9, 9, 9,  600, /*GranzSteel   */
12, 25,25,25,25, 25,25,25,25,  8, 6, 7, 7, 7, 7, 7, 7,  750, /*LorantSilver */
16, 30,30,30,30, 30,30,30,30,  9, 7, 8, 8, 8, 8, 8, 8,  900, /*WendelSilver */
16, 35,35,35,35, 35,35,35,35,  7, 9, 9, 9, 9, 9, 9, 9, 1200, /*VizelGold    */
16, 40,40,40,40, 40,40,40,40,  7, 7, 8, 8, 8, 8, 8, 8, 1500, /*IshePlatinum */
16, 45,45,45,45, 45,45,45,45,  7, 9, 9, 9, 9, 9, 9, 9, 1800, /*LorimarIron  */
18, 50,50,50,50, 50,50,50,50, 10,10,10,10,10,10,10,10, 2250, /*AltenaAlloy  */
48, 36, 3,68,18,  3,18,36,36, 32,32,32,32,32,32,32,32, 1350, /*MaiaLead     */
12, 28,28,28,28, 28,28,28,28,  8, 8, 7,10, 7, 9, 6, 8, 1050, /*Orihalcon    */
16, 10, 6,14, 4, 16, 5, 7, 9,  7, 8, 6, 9,10, 7, 7, 7,  150, /*OakWood      */
14, 15, 9,21, 6, 24, 7,10,13,  7, 8, 6, 9,10, 7, 7, 7,  360, /*HollyWood    */
24, 20,12,28, 8, 32,10,14,18,  7, 8, 6, 9,10, 7, 7, 7,  660, /*BaobabWood   */
24, 25,15,35,10, 40,12,17,22,  7, 8, 6, 9,10, 7, 7, 7,  900, /*EbonyWood    */
12, 35,21,49,14, 56,17,24,31,  7, 8, 6, 9,10, 7, 7, 7, 1200, /*MapleWood    */
10, 50,30,70,20, 80,25,35,45,  7, 8, 5, 9,10, 7, 7, 7, 1560, /*DiorWood     */
11, 30,18,42,12, 48,15,21,27,  7, 8, 6, 9,10, 7, 7, 7, 1050, /*AshWood      */
22, 40,24,56,16, 64,20,28,36,  7, 6, 6, 9,10, 6, 7, 7, 1500, /*FossilWood   */
28, 12, 2,21,16,  7, 9,12,15,  7, 8, 9, 7, 7, 6,10, 7,  300, /*Marble       */
32, 24, 4,43,33, 14,18,24,30,  8, 6, 9, 7, 7, 6,10, 8,  660, /*Obsidian     */
24, 36, 7,64,50, 21,27,36,45,  7, 8, 9, 7, 7, 7,11, 7, 1350, /*PedanStone   */
20, 48, 9,86,67, 28,36,48,60,  8, 8, 9, 7,10, 6,10, 6, 1950, /*Gaeus'sTears */
 8, 10, 1, 1, 1, 20, 8,12,10,  8, 8, 7, 9, 9, 7, 7, 7,   90, /*AnimalHide   */
12, 18, 1, 1, 1, 36,14,21,18,  8, 8, 7, 9, 9, 8, 8, 6,  180, /*GatorSkin    */
20, 26, 1, 1, 1, 52,20,31,26,  8, 8, 9, 7, 8, 7, 8, 8,  360, /*CentaurHide  */
20, 35, 1, 1, 1, 70,28,42,35,  8, 8, 7, 9, 5,10, 5,10,  540, /*DragonSkin   */
20,  8, 8, 7, 7,  9, 9, 8, 4,  8, 8, 8, 8, 8, 8, 8, 6,  120, /*FishScales   */
20, 16,17,14,14, 19,19,16, 8,  7, 9, 8, 8, 7, 8, 8, 9,  240, /*LizardScales */
20, 24,26,21,21, 28,28,24,12,  9, 7, 8, 8, 8, 7, 8, 7,  360, /*SnakeScales  */
14, 60,66,54,54, 72,72,60,30,  7, 7, 7, 7, 6, 7, 7, 7, 3000, /*DragonScales */
20, 14,10,12,12,  9,15, 6, 9,  9, 6, 8, 8, 8, 8, 8, 8,   60, /*AnimalBone   */
20, 28,21,24,24, 18,30,12,18,  7, 6, 7, 7, 8, 6, 7, 7,  240, /*Ivory        */
20, 43,32,36,36, 27,45,18,27,  9, 5, 9, 7, 9, 7, 9, 7,  270, /*CursedBone   */
20, 57,43,48,48, 36,60,24,36,  9, 6, 8, 8,10, 6,10, 6,  540, /*Fossil       */
10, 18, 1, 1, 1,  9, 9, 9, 9,  6, 8, 6,10,10, 7, 7, 6,   30, /*ToppleCotton */
10, 28, 1, 1, 1, 14,14,14,14,  6, 8, 6,10,10, 7, 7, 6,   90, /*Sultan'sSilk */
10, 38, 1, 1, 1, 19,19,19,19, 10, 6, 6,10,10, 7, 7, 6,  150, /*JuddHemp     */
10, 48, 1, 1, 1, 24,24,24,24,  7, 7, 7, 9,10, 7, 7, 6,  300, /*AltenaFelt   */
16, 15,11,22,24, 15,13,18,24,  7, 8,10, 7, 7, 8, 9, 8,  360, /*JacobiniRock */
16, 20,15,30,32, 20,18,24,32,  7, 8,10, 7, 7, 8, 9, 8,  600, /*HalleyRock   */
16, 25,18,37,40, 25,22,30,40,  7, 8,10, 7, 7, 8, 9, 8,  660, /*AnkhRock     */
16, 30,22,45,48, 30,27,36,48,  7, 8,10, 7, 7, 8, 9, 8, 1050, /*VinekRock    */
16, 35,26,52,56, 35,31,42,56,  7, 8,10, 7, 7, 8, 9, 8, 1260, /*TuttleRock   */
16, 40,30,60,64, 40,36,48,64,  7, 8,10, 7, 7, 8, 9, 8, 1500, /*NemesisRock  */
16, 45,33,67,72, 45,40,54,72,  7, 8,10, 7, 7, 8, 9, 8, 1650, /*BiellaRock   */
16, 50,37,75,80, 50,45,60,80,  7, 8,10, 7, 7, 8, 9, 8, 1800, /*SwifteRock   */
20, 62,46,93,99, 62,31,93,62,  8, 8, 8, 8, 8, 8, 8, 8, 3600, /*Adamantite   */
20, 55,41,68,66, 44,27,99,27,  8, 8, 8, 8, 8, 8, 8, 8, 3300, /*Fullmetal    */
12, 18,21,14,12, 23, 9,32, 9,  9, 6, 7, 7, 9, 7, 9, 5,  240, /*Coral        */
20, 26,31,20,18, 33,13,46,13,  8, 8, 9, 7, 9, 8, 9, 7,  150, /*TortoiseShell*/
14, 20,24,16,14, 26,10,36,10,  8, 7, 9, 8, 9, 7, 9, 6,   90, /*Shell        */
 8,  2, 2, 2, 2,  1, 1, 1,50,  8, 8, 8, 8, 8, 8, 8, 8, 4500, /*Emerald      */
 8,  2, 2, 2, 2,  1, 1, 1,50,  8, 8, 8, 8, 8, 8, 8, 8, 4500, /*Pearl        */
 8,  2, 2, 2, 2,  1, 1, 1,50,  8, 8, 8, 8, 8, 8, 8, 8, 4500  /*LapisLazuli  */
};

void print_price(void){
	printf("Price  : %d\n",equip_props[equip][5]*mat_props[material][17]/150+card_price());
}

void material_init(void){
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
	if(BOW&&(witch==first||witch==second||witch==third)&&
		(raven==first||raven==second||raven==third)&&
		(wolf==first||wolf==second||wolf==third)){
		plunge1=Magical_Shot;
	}
	if((RING||PENDANT)&&Auto_Revive==special){
		if(phoenix==hidden||
		(phoenix!=first&&phoenix!=second&&phoenix!=third))
			{special=No_Effect;}
	}
}

void print_attack(void){
	int esgc=mat_props[material][0]+ESSTOTAL;
	int denom=mat_props[material][0]*128;
	if(WEAPON){
		printf("%d",(sharp*equip_props[equip][0]+
			heavy*equip_props[equip][1]+
			force*equip_props[equip][2]+
			tech*equip_props[equip][3])*esgc/denom);
	} else { /* armor */
		printf("%d %d %d %d",strike*equip_props[equip][0]/64,
			slash*equip_props[equip][1]/64,
			thrust*equip_props[equip][2]/64,
			magic*equip_props[equip][3]/64);
	}
	printf("\n");
}

void print_attack_long(void){
	if(WEAPON){
		printf("( %d*%d + %d*%d + %d*%d + %d*%d )*( %d + %d )/%d/128\n",
		sharp,equip_props[equip][0],heavy,equip_props[equip][1],
		force,equip_props[equip][2],tech,equip_props[equip][3],
		mat_props[material][0],ESSTOTAL,mat_props[material][0]);
	} else { /* armor */
		printf("%d*%d/64 %d*%d/64 %d*%d/64 %d*%d/64\n",
		strike,equip_props[equip][0],slash,equip_props[equip][1],
		thrust,equip_props[equip][2],magic,equip_props[equip][3]);
	}
}

char *mat_word[56]={
"No Material","MenosBronze","ForsenaIron","GranzSteel","LorantSilver",
"WendelSilver","VizelGold","IshePlatinum","LorimarIron","AltenaAlloy",
"MaiaLead","Orihalcon","OakWood","HollyWood","BaobabWood","EbonyWood",
"MapleWood","DiorWood","AshWood","FossilWood","Marble","Obsidian",
"PedanStone","Gaeus'sTears","AnimalHide","GatorSkin","CentaurHide",
"DragonSkin","FishScales","LizardScales","SnakeScales","DragonScales",
"AnimalBone","Ivory","CursedBone","Fossil","ToppleCotton","Sultan'sSilk",
"JuddHemp","AltenaFelt","JacobiniRock","HalleyRock","AnkhRock","VinekRock",
"TuttleRock","NemesisRock","BiellaRock","SwifteRock","Adamantite",
"Fullmetal","Coral","TortoiseShell","Shell","Emerald","Pearl","LapisLazuli"
};

void print_material(void){
	printf("\n%s ",mat_word[material]);
}

char *equip_word[24]={
"No Wep","Knife","Sword","Axe","2H Sword","2H Axe","Hammer","Spear",
"Staff","Glove","Flail","Bow","Shield","Helm","Hat","Hauberk","Robe",
"Gauntlet","Ring","Boots","Shoes","Armor","Mantle","Pendant"
};

void print_equipment(void){
	printf("%s : ",equip_word[equip]);
}

void material_code(void){
	if(WOOD){
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
	} else if(AEROLITE){
		decrease(SALA);
	}
}

void perc150(int *num){
        *num=*num*3/2;
        if(*num>255){*num=255;}
}
void perc125(int *num){
        *num=*num*5/4;
        if(*num>255){*num=255;}
}
void perc75(int *num){
        *num=*num/4*3;
}
void perc50(int *num){
        *num=*num/2;
}
