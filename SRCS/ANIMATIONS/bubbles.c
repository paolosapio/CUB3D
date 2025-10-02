#include "animations.h"

void	draw_bubble(mlx_t *mlx, mlx_image_t **bubble_array,
		bool *animation_switch)
{
	static int	bubble_frame = 0;

	(void)mlx;
	bubble_array[bubble_frame]->enabled = false;
	bubble_frame++;
	bubble_array[bubble_frame]->enabled = true;
	if (bubble_frame == 19)
	{
		bubble_frame = 0;
		*animation_switch = false;
	}
}