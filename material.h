typedef enum { NO_MAT,METAL,WOOD,STONE,HIDE,SCALE,BONE,FABRIC,AEROLITE } MATERIAL;

char *material_list;
int mat_props[56][17];
MATERIAL mat_type[56];
void mat_code(MATERIAL);
