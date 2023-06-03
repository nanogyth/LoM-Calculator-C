/* from cards.c */
void init_cards(void);
void sub_init_cards(void);
void set_active_world_card(void);
void push_cards(void);
void activate_cards(void);
void print_cards(void);

/* from essence.c */
void init_essences(void);
void increase_essences(void);
void print_essences(void);
void print_resists(void);

/* from items.c */
void init_item(void);
void get_item(void);
void item_energy(void);
void item_code(void);
void print_item(void);

/* from material.c */
void get_equipment(void);
void get_material(void);
void material_init(void);
void material_code(void);
void print_material(void);
void print_equipment(void);
void print_attack(void);
void print_attack_long(void);
void print_markers(void);
void print_price(void);

/* from stats.c */
void init_stats(void);
void init_stat_limits(void);
void calculate_stats(void);
void print_stats(void);

/* from special.c */
void init_special(void);
void print_immunity(void);
void print_special(void);
