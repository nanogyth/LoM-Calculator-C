#include "stdio.h"

/* from essence.c */
int energy;

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;
void taint(ESSENCE);


/* from material.c */
int sharp,heavy,force,tech,strike,slash,thrust,magic;

int wiR,shR,drR,auR,saR,gnR,jiR,unR;

int equip;
#define ROBE (16==equip)

void perc150(int *);
void perc125(int *);
void perc75(int *);
void perc50(int *);