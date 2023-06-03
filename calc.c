#include "calc.h"

int main(void){

	init_essences();
	init_cards();

	get_equipment();
	get_material();

	while(0==0){

		get_item();
		sub_init_cards();
		material_init();
		set_active_world_card();
		item_energy();
		material_code();
		item_code();
		push_cards();
		activate_cards();
		increase_essences();

		printf("\n");
		print_material(); printf(" ");
		print_equipment();printf(" : ");
		print_attack();   printf("\n");
		print_essences(); printf("\n");
		print_item();     printf("\n");
		print_cards();
	}
	return 0;
}
