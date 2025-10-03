#include "animations.h"

#define KELAS_WIGGLE_FREQUENCY 100

void	shift_kelas_loop(unsigned long current_time, mlx_image_t **kelas_up)
{
	static unsigned long	last_wiggle_loop;

	if (current_time - last_wiggle_loop >= KELAS_WIGGLE_FREQUENCY)
	{
		if (kelas_up[0]->enabled == false && kelas_up[1]->enabled == false)
			kelas_up[0]->enabled = true;
		kelas_up[0]->enabled = !kelas_up[0]->enabled;
		kelas_up[1]->enabled = !kelas_up[1]->enabled;
		last_wiggle_loop = current_time;
	}
}