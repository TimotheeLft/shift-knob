/*
 * shifter_hw.h
 *
 *  Created on: Feb 4, 2024
 *      Author: timot
 */

#ifndef ___SHIFTER_HW_H__
#define ___SHIFTER_HW_H__

#include "shifter.h"

int shifter_hw_init(struct shifter_gear_association *gear_assoc);

int shifter_hw_gear_read(uint32_t gear_port, uint32_t gear_pin, uint8_t *pin_value);



#endif /* ___SHIFTER_HW_H__ */
