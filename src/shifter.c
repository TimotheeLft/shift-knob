

#include "shifter_hw.h"
#include "shifter.h"
#include "errno.h"

#include <stdlib.h>


struct shifter_ctx {
	enum shifter_type type;
	uint8_t current_gear;
	uint8_t is_int:1;

};

struct shifter_ctx ctx;

/* Private function */

static int shifter_manage (void) {
	int ret = 0;

out:
	return ret;
}

/* user function */

int shifter_init (struct shifter_cfg *cfg) {
	int ret = 0;

	if (cfg == NULL) {
		ret = EINVAL;
		goto out;
	}

out:
	return ret;
}

int shifter_process (void) {
	int ret = 0;

out:
	return ret;
}

int shifter_set_shifter_type (enum shifter_type type) {
	int ret = 0;

	if (type != SHIFTER_TYPE_SEQUENCIAL
			|| type != SHIFTER_TYPE_MANUAL) {
		ret = EINVAL;
		goto out;
	}

out:
	return ret;
}

int shifter_get_current_gear (uint8_t *current_gear) {
	int ret = 0;

	if (current_gear == NULL) {
		ret = EINVAL;
		goto out;
	}

out:
	return ret;
}

