#include "tools_graphics.h"
#include <stdio.h>

void	paint_tile(int g_size_tile, mlx_image_t *img_minimap, t_coor coor, int32_t color)
{
	int	x;
	int	y;


	y = -1;
	if (coor.x < 0 || coor.y < 0)
		return ;
	while (++y < g_size_tile)
	{
		x = -1;
		while (++x < g_size_tile)
		{
			if (y == 0 || x == 0 || x == g_size_tile || y == g_size_tile)
				mlx_put_pixel(img_minimap, x + (coor.x * g_size_tile), y + (coor.y* g_size_tile), 0xFFFF0011);
			else
				mlx_put_pixel(img_minimap, x + (coor.x * g_size_tile), y + (coor.y* g_size_tile), color);
		}
	}
}