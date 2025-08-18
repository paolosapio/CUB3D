#include "draw_shapes.h"
#include <stdio.h>

void	paint_tile(mlx_image_t	*img_minimap, float x_map, float y_map, int32_t color)
{
	int	x;
	int	y;

	y = -1;
	if (x_map < 0 || y_map < 0)
		return ;
	while (++y <= 10)
	{
		x = -1;
		while (++x <= 10)
		{
			mlx_put_pixel(img_minimap, x + (x_map * 10), y + (y_map* 10), color);
		}
	}
}