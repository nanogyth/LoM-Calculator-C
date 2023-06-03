int energy;

/* essence levels */
int wi,sh,dr,au,sa,gn,ji,un;

/* level raise */
int drLR,auLR,saLR,gnLR,jiLR,unLR;

#define ESSTOTAL (wi+sh+dr+au+sa+gn+ji+un)

typedef enum { WISP,SHADE,DRYAD,AURA,SALA,GNOME,JINN,UNDINE } ESSENCE;
void taint(ESSENCE);
void decrease(ESSENCE);
void increase(ESSENCE);
