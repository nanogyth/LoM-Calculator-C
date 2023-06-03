#include <stdio.h>
#include "calc.h"

void pretty_print(void){
	print_material();
	print_equipment();
	print_attack();
	print_attack_long();
	print_resists();
	printf("Essence:");print_essences();printf("\n");
	print_markers();
	print_stats();
	print_immunity();
	print_item();
	print_cards();
	print_special();
	print_price();
}

int main(void){

	get_equipment();
	get_material();

	init_essences();
	init_cards();
	init_stats();
	init_item();
	init_special();
	init_stat_limits();
	sub_init_cards();
	material_init();

	while(0==0){

		get_item();
		init_stat_limits();
		sub_init_cards();
		material_init();
		set_active_world_card();
		item_energy();
		material_code();
		item_code();
		push_cards();
		activate_cards();
		increase_essences();
		calculate_stats();
		print_essences();
		printf(" : ");
		print_attack();
	}
	return 0;
}
