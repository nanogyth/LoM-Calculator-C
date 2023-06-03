int equip;
char *equip_list;
int equip_props[24][4];
int sharp,heavy,force,tech,strike,slash,thrust,magic;

int material;
char *material_list;
int mat_props[56][17];
int wiR,shR,drR,auR,saR,gnR,jiR,unR;

typedef enum { NO_MAT,METAL,WOOD,STONE,HIDE,SCALE,BONE,FABRIC,AEROLITE } MATERIAL;
MATERIAL mat_type[56];

void mat_code(MATERIAL);
void perc150(int *);
void perc125(int *);
void perc75(int *);
void perc50(int *);