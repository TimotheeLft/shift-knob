

#ifndef __SHIFTER_CFG_H__
#define __SHIFTER_CFG_H__

/* delete this error after include the config file in the project */
#error "delete tpl argument in file when put it in config project"

/* back gear isn't counted in this config */
#define SHIFTER_GEAR_NUMBER 7

/* Back Gear is counted there */
#define SHIFTER_MAX_NB_GEAR 8

struct shifter_pin_gear {
	uint32_t shifter_back_gear;
	uint32_t shifter_gear_1;
	uint32_t shifter_gear_2;
	uint32_t shifter_gear_3;
	uint32_t shifter_gear_4;
	uint32_t shifter_gear_5;
	uint32_t shifter_gear_6;
	uint32_t shifter_gear_7;
};


#endif /* __SHIFTER_CFG_H__ */
