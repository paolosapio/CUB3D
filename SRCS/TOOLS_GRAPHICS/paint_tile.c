#include "tools_graphics.h"
#include <stdio.h>

void	paint_tile(int tile_size, mlx_image_t *img_minimap, t_int_coor coor, int32_t color)
{
	int	x;
	int	y;


	y = -1;
	if (coor.x < 0 || coor.y < 0)
		return ;
	while (++y < tile_size)
	{
		x = -1;
		while (++x < tile_size)
		{
			if (y == 0 || x == 0 || x == tile_size || y == tile_size)
				mlx_put_pixel(img_minimap, x + (coor.x * tile_size), y + (coor.y* tile_size), 0xFFFF0011);
			else
				mlx_put_pixel(img_minimap, x + (coor.x * tile_size), y + (coor.y* tile_size), color);
		}
	}
}