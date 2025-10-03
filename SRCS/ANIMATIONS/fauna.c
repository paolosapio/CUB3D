#include "animations.h"

#define FAUNA_SWITCH_RATE 1000

void	switch_fauna(unsigned long current_time,  mlx_image_t **fauna)
{
	static unsigned long	last_fauna_switch;

	if (current_time - last_fauna_switch >= FAUNA_SWITCH_RATE)
	{
		if (fauna[0]->enabled == false && fauna[1]->enabled == false)
			fauna[0]->enabled = true;
		fauna[0]->enabled = !fauna[0]->enabled;
		fauna[1]->enabled = !fauna[1]->enabled;
		last_fauna_switch = current_time;
	}
}
