#include <stdio.h>
#include "special.h"
/*PRICE*/

typedef enum { Thrust, Shot, Caduceus, Chaotic_Avenger,
    Green_Princess, Gungnir, Magical_Shot, Phoenix_Falling,
    Solar_Flare, Spear_of_Light, Trident } PLUNGE1;

typedef enum { Uppercut, Double_Shot, Dragonslayer, Elven_Archer,
    Flame_Tongue, Game_of_Death, Hand_of_Midas, Lunar_Shot,
    Poison_Blade, Quick_Blade, Sunlight, Vampsword } PLUNGE2;

typedef enum { Jump, Demonicide, Electrosceptre, Golden_Touch,
    Magma_Hammer, Mjolnir, Moonlight, Quake_Hammer, Ragnarok,
    Red_Dream, Sinister_Blade, Sledge_Hammer, Treefeller,
    Woodchopper} PLUNGE3;

typedef enum { No_Effect, No_Regen, No_Revive, Auto_Revive,
    Fast_Revive, Extra_Exp, Extra_Lucre, Stare_Immunity,
    Share_Exp, Move_Regen } SPECIAL;

typedef enum { Sleep=1, Poison=2, Paralysis=4, Confusion=8,
    Darkness=16, Petrify=32, Flameburst=64, Freeze=128 } IMMUNITY;

PLUNGE1 plunge1;
PLUNGE2 plunge2;
PLUNGE3 plunge3;
SPECIAL special;
int immunity;

void init_special(void){
	special=No_Effect;
	immunity=0;
	plunge1=Thrust;
	plunge2=Uppercut;
	plunge3=Jump;
	if(BOW){
		plunge1=Shot;
		plunge2=Double_Shot;
	}
}

void print_special(void){
	if(ARMOR){
		switch(special){
		case No_Effect:break;
		case No_Regen:printf("Special Effect: No Regen");break;
		case No_Revive:printf("Special Effect: Move Regen, No Revive");break;
		case Auto_Revive:printf("Special Effect: Auto Revive");break;
		case Fast_Revive:printf("Special Effect: Fast Revive");break;
		case Extra_Exp:printf("Special Effect: Extra Exp");break;
		case Extra_Lucre:printf("Special Effect: Extra Lucre");break;
		case Stare_Immunity:printf("Special Effect: Stare immunity");break;
		case Share_Exp:printf("Special Effect: Share Exp");break;
		case Move_Regen:printf("Special Effect: Move Regen");break;
		}
	}else{
		printf("Plunges:\n");
		switch(plunge1){
		case Thrust:         printf("\tThrust");break;
		case Shot:           printf("\tShot");break;
		case Caduceus:       printf("\tCaduceus");break;
		case Chaotic_Avenger:printf("\tChaotic Avenger");break;
		case Green_Princess: printf("\tGreen Princess");break;
		case Gungnir:        printf("\tGungnir");break;
		case Magical_Shot:   printf("\tMagical Shot");break;
		case Phoenix_Falling:printf("\tPhoenix Falling");break;
		case Solar_Flare:    printf("\tSolar Flare");break;
		case Spear_of_Light: printf("\tSpear of Light");break;
		case Trident:        printf("\tTrident");break;
		}
		printf("\n");
		switch(plunge2){
		case Uppercut:     printf("\tUppercut");break;
		case Double_Shot:  printf("\tDouble Shot");break;
		case Dragonslayer: printf("\tDragonslayer");break;
		case Elven_Archer: printf("\tElven Archer");break;
		case Flame_Tongue: printf("\tFlame Tongue");break;
		case Game_of_Death:printf("\tGame of Death");break;
		case Hand_of_Midas:printf("\tHand of Midas");break;
		case Lunar_Shot:   printf("\tLunar Shot");break;
		case Poison_Blade: printf("\tPoison Blade");break;
		case Quick_Blade:  printf("\tQuick Blade");break;
		case Sunlight:     printf("\tSunlight");break;
		case Vampsword:    printf("\tThrust");break;
		}
		printf("\n");
		switch(plunge3){
		case Jump:          printf("\tJump");break;
		case Demonicide:    printf("\tDemonicide");break;
		case Electrosceptre:printf("\tElectrosceptre");break;
		case Golden_Touch:  printf("\tGolden Touch");break;
		case Magma_Hammer:  printf("\tMagma Hammer");break;
		case Mjolnir:       printf("\tMjolnir");break;
		case Moonlight:     printf("\tMoonlight");break;
		case Quake_Hammer:  printf("\tQuake Hammer");break;
		case Ragnarok:      printf("\tRagnarok");break;
		case Red_Dream:     printf("\tRed Dream");break;
		case Sinister_Blade:printf("\tSinister Blade");break;
		case Sledge_Hammer: printf("\tSledge Hammer");break;
		case Treefeller:    printf("\tTreefeller");break;
		case Woodchopper:   printf("\tWoodchopper");break;
		}
	}
}
void print_immunity(void){
	if(ARMOR){
	printf("Immunity ");
	if(immunity&Sleep)     {printf("Sl ");}else{printf("   ");}
	if(immunity&Poison)    {printf("Po ");}else{printf("   ");}
	if(immunity&Paralysis) {printf("Pa ");}else{printf("   ");}
	if(immunity&Confusion) {printf("Co ");}else{printf("   ");}
	if(immunity&Darkness)  {printf("Da ");}else{printf("   ");}
	if(immunity&Petrify)   {printf("Pe ");}else{printf("   ");}
	if(immunity&Flameburst){printf("Fl ");}else{printf("   ");}
	if(immunity&Freeze)    {printf("Fr");}else{printf("  ");}
	printf("\n");
	}
}