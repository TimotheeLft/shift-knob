

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#include "shifter_hw.h"
//#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx.h"


int shifter_hw_init(struct shifter_gear_association *gear_assoc) {
	int ret = 0;
	GPIO_InitTypeDef init_structure;
	if (gear_assoc == NULL) {
		ret = EINVAL;
		goto out;
	}

	init_structure.Mode = GPIO_MODE_INPUT;
	init_structure.Pull = GPIO_PULLUP;

	for (unsigned int i = 0; i<= CONFIG_SHIFTER_MAX_NB_GEAR; i++) {
		init_structure.Pin = gear_assoc[i].shifter_gear_pin;
		HAL_GPIO_Init((GPIO_TypeDef *)gear_assoc[i].shifter_gear_port, &init_structure);
	}
out:
	return ret;
}


int shifter_hw_gear_read(uint32_t gear_port, uint32_t gear_pin, uint8_t *pin_value) {
	int ret = 0;

	if (pin_value == NULL) {
		ret = EINVAL;
	}

	*pin_value = (uint8_t)HAL_GPIO_ReadPin((GPIO_TypeDef *)gear_port, gear_pin);

	return ret;
}
