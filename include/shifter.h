

#ifndef __SHIFTER_H__
#define __SHIFTER_H__

#include "shifter_cfg.h"


enum shifter_type {
	SHIFTER_TYPE_SEQUENCIAL,
	SHIFTER_TYPE_MANUAL
};

enum shifter_gear {
	SHIFTER_GEAR_REVERSE,
	SHIFTER_GEAR_NEUTRAL,
	SHIFTER_GEAR_1,
	SHIFTER_GEAR_2,
	SHIFTER_GEAR_3,
	SHIFTER_GEAR_4,
	SHIFTER_GEAR_5,
	SHIFTER_GEAR_6,
	SHIFTER_GEAR_7,
};

struct shifter_gear_association {
	uint32_t shifter_gear_port;
	uint32_t shifter_gear_pin;
	enum shifter_gear gear;
};

struct shifter_cfg {
	struct shifter_gear_association gear_assiociation[CONFIG_SHIFTER_MAX_NB_GEAR];
	uint8_t is_a_clutch;
};


int shifter_init (struct shifter_cfg *cfg);

int shifter_process (uint8_t clutch_status);

int shifter_set_shifter_type (enum shifter_type type);

int shifter_get_current_gear (uint8_t *current_gear);

#endif /* __SHIFT_KNOB_H__ */
