#include <stdio.h>
#include "calc.h"

void pretty_print(void){
	printf("\n");
	print_material(); printf(" ");
	print_equipment();printf(" : ");
	print_attack();   printf("\n");
	printf("Essence:");print_essences(); printf("\n");
	printf("Markers:");print_markers();  printf("\n");
	printf("Stats  :");  print_stats();    printf("\n");
	print_immunity();
	printf("Last Item: "); print_item();     printf("\n");
	printf("Cards:");  print_cards();    printf("\n");
	print_special();  printf("\n");
}

int main(void){

	init_essences();
	init_cards();
	init_stats();

	get_equipment();
	get_material();

	init_special();

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
		print_essences(); printf("\n");
	}
	return 0;
}
