#include "animations.h"

void	switch_fauna(int tv_sec, t_images *images)
{
	if (tv_sec % 2 == 0)
	{
		images->fauna[0]->enabled = true;
		images->fauna[1]->enabled = false;
	}
	else
	{
		images->fauna[0]->enabled = false;
		images->fauna[1]->enabled = true;
	}
}
