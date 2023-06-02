#include "calc.h"

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


/* growth control[1], weapon stats[4], armor stats[4], resistances[8], {cost[1]} */

int mat_props[56][17]={
 0,  0, 0, 0, 0,  0, 0, 0, 0,  1, 1, 1, 1, 1, 1, 1, 1, /*No Material  */
18, 10,10,10,10, 10,10,10,10,  8, 8, 8, 8, 8, 8, 8, 8, /*MenosBronze  */
20, 15,15,15,15, 15,15,15,15,  9, 9, 9, 9, 9, 9, 9, 9, /*ForsenaIron  */
24, 20,20,20,20, 20,20,20,20,  9, 9, 9, 9, 9, 9, 9, 9, /*GranzSteel   */
12, 25,25,25,25, 25,25,25,25,  8, 6, 7, 7, 7, 7, 7, 7, /*LorantSilver */
16, 30,30,30,30, 30,30,30,30,  9, 7, 8, 8, 8, 8, 8, 8, /*WendelSilver */
16, 35,35,35,35, 35,35,35,35,  7, 9, 9, 9, 9, 9, 9, 9, /*VizelGold    */
16, 40,40,40,40, 40,40,40,40,  7, 7, 8, 8, 8, 8, 8, 8, /*IshePlatinum */
16, 45,45,45,45, 45,45,45,45,  7, 9, 9, 9, 9, 9, 9, 9, /*LorimarIron  */
18, 50,50,50,50, 50,50,50,50, 10,10,10,10,10,10,10,10, /*AltenaAlloy  */
48, 36, 3,68,18,  3,18,36,36, 32,32,32,32,32,32,32,32, /*MaiaLead     */
12, 28,28,28,28, 28,28,28,28,  8, 8, 7,10, 7, 9, 6, 8, /*Orihalcon    */
16, 10, 6,14, 4, 16, 5, 7, 9,  7, 8, 6, 9,10, 7, 7, 7, /*OakWood      */
14, 15, 9,21, 6, 24, 7,10,13,  7, 8, 6, 9,10, 7, 7, 7, /*HollyWood    */
24, 20,12,28, 8, 32,10,14,18,  7, 8, 6, 9,10, 7, 7, 7, /*BaobabWood   */
24, 25,15,35,10, 40,12,17,22,  7, 8, 6, 9,10, 7, 7, 7, /*EbonyWood    */
12, 35,21,49,14, 56,17,24,31,  7, 8, 6, 9,10, 7, 7, 7, /*MapleWood    */
10, 50,30,70,20, 80,25,35,45,  7, 8, 5, 9,10, 7, 7, 7, /*DiorWood     */
11, 30,18,42,12, 48,15,21,27,  7, 8, 6, 9,10, 7, 7, 7, /*AshWood      */
22, 40,24,56,16, 64,20,28,36,  7, 6, 6, 9,10, 6, 7, 7, /*FossilWood   */
28, 12, 2,21,16,  7, 9,12,15,  7, 8, 9, 7, 7, 6,10, 7, /*Marble       */
32, 24, 4,43,33, 14,18,24,30,  8, 6, 9, 7, 7, 6,10, 8, /*Obsidian     */
24, 36, 7,64,50, 21,27,36,45,  7, 8, 9, 7, 7, 7,11, 7, /*PedanStone   */
20, 48, 9,86,67, 28,36,48,60,  8, 8, 9, 7,10, 6,10, 6, /*Gaeus'sTears */
 8, 10, 1, 1, 1, 20, 8,12,10,  8, 8, 7, 9, 9, 7, 7, 7, /*AnimalHide   */
12, 18, 1, 1, 1, 36,14,21,18,  8, 8, 7, 9, 9, 8, 8, 6, /*GatorSkin    */
20, 26, 1, 1, 1, 52,20,31,26,  8, 8, 9, 7, 8, 7, 8, 8, /*CentaurHide  */
20, 35, 1, 1, 1, 70,28,42,35,  8, 8, 7, 9, 5,10, 5,10, /*DragonSkin   */
20,  8, 8, 7, 7,  9, 9, 8, 4,  8, 8, 8, 8, 8, 8, 8, 6, /*FishScales   */
20, 16,17,14,14, 19,19,16, 8,  7, 9, 8, 8, 7, 8, 8, 9, /*LizardScales */
20, 24,26,21,21, 28,28,24,12,  9, 7, 8, 8, 8, 7, 8, 7, /*SnakeScales  */
14, 60,66,54,54, 72,72,60,30,  7, 7, 7, 7, 6, 7, 7, 7, /*DragonScales */
20, 14,10,12,12,  9,15, 6, 9,  9, 6, 8, 8, 8, 8, 8, 8, /*AnimalBone   */
20, 28,21,24,24, 18,30,12,18,  7, 6, 7, 7, 8, 6, 7, 7, /*Ivory        */
20, 43,32,36,36, 27,45,18,27,  9, 5, 9, 7, 9, 7, 9, 7, /*CursedBone   */
20, 57,43,48,48, 36,60,24,36,  9, 6, 8, 8,10, 6,10, 6, /*Fossil       */
10, 18, 1, 1, 1,  9, 9, 9, 9,  6, 8, 6,10,10, 7, 7, 6, /*ToppleCotton */
10, 28, 1, 1, 1, 14,14,14,14,  6, 8, 6,10,10, 7, 7, 6, /*Sultan'sSilk */
10, 38, 1, 1, 1, 19,19,19,19, 10, 6, 6,10,10, 7, 7, 6, /*JuddHemp     */
10, 48, 1, 1, 1, 24,24,24,24,  7, 7, 7, 9,10, 7, 7, 6, /*AltenaFelt   */
16, 15,11,22,24, 15,13,18,24,  7, 8,10, 7, 7, 8, 9, 8, /*JacobiniRock */
16, 20,15,30,32, 20,18,24,32,  7, 8,10, 7, 7, 8, 9, 8, /*HalleyRock   */
16, 25,18,37,40, 25,22,30,40,  7, 8,10, 7, 7, 8, 9, 8, /*AnkhRock     */
16, 30,22,45,48, 30,27,36,48,  7, 8,10, 7, 7, 8, 9, 8, /*VinekRock    */
16, 35,26,52,56, 35,31,42,56,  7, 8,10, 7, 7, 8, 9, 8, /*TuttleRock   */
16, 40,30,60,64, 40,36,48,64,  7, 8,10, 7, 7, 8, 9, 8, /*NemesisRock  */
16, 45,33,67,72, 45,40,54,72,  7, 8,10, 7, 7, 8, 9, 8, /*BiellaRock   */
16, 50,37,75,80, 50,45,60,80,  7, 8,10, 7, 7, 8, 9, 8, /*SwifteRock   */
20, 62,46,93,99, 62,31,93,62,  8, 8, 8, 8, 8, 8, 8, 8, /*Adamantite   */
20, 55,41,68,66, 44,27,99,27,  8, 8, 8, 8, 8, 8, 8, 8, /*Fullmetal    */
12, 18,21,14,12, 23, 9,32, 9,  9, 6, 7, 7, 9, 7, 9, 5, /*Coral        */
20, 26,31,20,18, 33,13,46,13,  8, 8, 9, 7, 9, 8, 9, 7, /*TortoiseShell*/
14, 20,24,16,14, 26,10,36,10,  8, 7, 9, 8, 9, 7, 9, 6, /*Shell        */
 8,  2, 2, 2, 2,  1, 1, 1,50,  8, 8, 8, 8, 8, 8, 8, 8, /*Emerald      */
 8,  2, 2, 2, 2,  1, 1, 1,50,  8, 8, 8, 8, 8, 8, 8, 8, /*Pearl        */
 8,  2, 2, 2, 2,  1, 1, 1,50,  8, 8, 8, 8, 8, 8, 8, 8  /*LapisLazuli  */
};

MATERIAL mat_type[56]={
NO_MAT,
METAL, /*11*/
METAL,
METAL,
METAL,
METAL,
METAL,
METAL,
METAL,
METAL,
METAL,
METAL,
WOOD, /*8*/
WOOD,
WOOD,
WOOD,
WOOD,
WOOD,
WOOD,
WOOD,
STONE, /*4*/
STONE,
STONE,
STONE,
HIDE, /*4*/
HIDE,
HIDE,
HIDE,
SCALE, /*4*/
SCALE,
SCALE,
SCALE,
BONE, /*4*/
BONE,
BONE,
BONE,
FABRIC,/*4*/
FABRIC,
FABRIC,
FABRIC,
AEROLITE, /*8*/
AEROLITE,
AEROLITE,
AEROLITE,
AEROLITE,
AEROLITE,
AEROLITE,
AEROLITE,
NONE, /*8*/
NONE,
NONE,
NONE,
NONE,
NONE,
NONE,
NONE
};

void mat_code(MATERIAL mat){
	switch(mat){
	case WOOD:
		taint(DRYAD);
		if(energy>=8){prehidden=dryad;}
		break;
	case AEROLITE:
		decrease(SALA);
		break;
	}
}

char *weapon_list=
" 1 Knife   \n 2 Sword   \n 3 Axe     \n 4 2H Sword\n"
" 5 2H Axe  \n 6 Hammer  \n 7 Spear   \n 8 Staff   \n"
" 9 Glove   \n10 Flail   \n11 Bow     \n";

int weapon[11][4]={
44,16,12,48, /*Knife   */
32,32,32,32, /*Sword   */
28,36,48,16, /*Axe     */
40,40,40,40, /*2H Sword*/
40,40,64,16, /*2H Axe  */
 8,72,64,16, /*Hammer  */
52,20,24,48, /*Spear   */
 4,44,16,32, /*Staff   */
 0,32,24,56, /*Glove   */
 0,40,28,44, /*Flail   */
40, 4,20,40  /*Bow     */
};

int armor[12][4]={
 8, 8, 8, 4, /*Shield  */
 8, 7, 6, 2, /*Helm    */
 4, 2, 2, 4, /*Hat     */
12,16,16, 2, /*Hauberk */
 6, 6, 6, 8, /*Robe    */
 7, 6, 8, 2, /*Gauntlet*/
 1, 1, 1,16, /*Ring    */
 6, 8, 7, 2, /*Boots   */
 2, 4, 2, 4, /*Sandals */
26,26,26, 4, /*Armor   */
 4, 4, 4,12, /*Mantle  */
 0, 0, 0,24  /*Pendant */
};