#include "IRModule.h"

void ir_init(void) {
	gpio_set_mode(P_IR_1, Input);
	gpio_set_mode(P_IR_2, Input);
	
}

int ir_get(Pin pin) {
	return !gpio_get(pin);
}
