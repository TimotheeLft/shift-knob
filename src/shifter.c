

#include "shifter_hw.h"
#include "shifter.h"
#include "errno.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>



struct shifter_ctx {
	struct shifter_cfg cfg;
	enum shifter_type type;
	enum shifter_gear current_gear;
	bool is_init_done:1;

};

struct shifter_ctx ctx;

/* Private function */

static int shifter_manage_sequential (void) {
	int ret = ENOSYS;

	return ret;
}

static int shifter_manage_manual (uint8_t clutch_status) {
	int ret = 0;
	uint8_t clutch_engage;
	uint8_t pin_value;

	if (ctx.cfg.is_a_clutch) {
		if (clutch_status) {
			ctx.current_gear = SHIFTER_GEAR_NEUTRAL;
		}
	} else {
		clutch_engage = true;
	}

	if (clutch_engage) {
		for (unsigned int i = 0; i <= CONFIG_SHIFTER_MAX_NB_GEAR; i++) {
			ret = shifter_hw_gear_read(ctx.cfg.gear_assiociation[i].shifter_gear_port,
					ctx.cfg.gear_assiociation[i].shifter_gear_pin,
					&pin_value);
			if (ret != 0) {
				goto out;
			}
			if (pin_value == 1) {
				ctx.current_gear = ctx.cfg.gear_assiociation[i].gear;
				break;
			}
		}
		if (pin_value == 0) {
			ctx.current_gear = SHIFTER_GEAR_NEUTRAL;
		}
	}


out:
	return ret;
}

/* user function */

int shifter_init (struct shifter_cfg *cfg) {
	int ret = 0;

	if (cfg == NULL) {
		ret = EINVAL;
		ctx.is_init_done = false;
		goto out;
	}

	memcpy(&ctx.cfg.gear_assiociation, cfg->gear_assiociation,
			sizeof(ctx.cfg.gear_assiociation));
	ctx.cfg.is_a_clutch = cfg->is_a_clutch;

	/* by default shifter type is manual */
	ctx.type = SHIFTER_TYPE_MANUAL;
	ctx.current_gear = SHIFTER_GEAR_NEUTRAL;

	ret = shifter_hw_init(ctx.cfg.gear_assiociation);
	if (ret != 0) {
		goto out;
	}

	ctx.is_init_done = true;

out:
	return ret;
}

int shifter_process (uint8_t clutch_status) {
	int ret = 0;

	if (!ctx.is_init_done) {
		ret = EACCES;
		goto out;
	}
	if (ctx.type == SHIFTER_TYPE_MANUAL) {
		ret = shifter_manage_manual(clutch_status);
	} else {
		ret = shifter_manage_sequential();
	}
out:
	return ret;
}

int shifter_set_shifter_type (enum shifter_type type) {
	int ret = 0;

	if ((type != SHIFTER_TYPE_SEQUENCIAL)
			|| (type != SHIFTER_TYPE_MANUAL)) {
		ret = EINVAL;
		goto out;
	}

	ctx.type = type;

out:
	return ret;
}

int shifter_get_current_gear (enum shifter_gear *current_gear) {
	int ret = 0;

	if (current_gear == NULL) {
		ret = EINVAL;
		goto out;
	}

	*current_gear = ctx.current_gear;

out:
	return ret;
}

