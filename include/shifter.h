

#ifndef __SHIFTER_H__
#define __SHIFTER_H__

#include "shifter_cfg.h"

int shifter_init (void);

enum shifter_type {
	SHIFTER_TYPE_SEQUENCIAL,
	SHIFTER_TYPE_MANUAL
};


struct shifter_cfg {
	struct shifter_pin_gear;
	uint8_t is_a_clutch;
};


int shifter_init (struct shifter_cfg *cfg);

int shifter_process (void);

int shifter_set_shifter_type (enum shifter_type type);

int shifter_get_current_gear (uint8_t *current_gear);

#endif /* __SHIFT_KNOB_H__ */
