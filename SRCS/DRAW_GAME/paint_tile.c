#include "draw_game.h"
#include <stdio.h>

void	paint_tile(mlx_image_t	*img_minimap, float x_map, float y_map, int32_t color)
{
	int	x;
	int	y;

	y = -1;
	if (x_map < 0 || y_map < 0)
		return ;
	while (++y < 30)
	{
		x = -1;
		while (++x < 30)
		{
			if (y == 0 || x == 0 || x == 29 || y == 29)
				mlx_put_pixel(img_minimap, x + (x_map * 30), y + (y_map* 30), 0xFFFF0011);
			else
				mlx_put_pixel(img_minimap, x + (x_map * 30), y + (y_map* 30), color);
		}
	}
}

void	paint_player(mlx_image_t	*img_minimap, float x_map, float y_map, int32_t color)
{
	int	x;
	int	y;

	y = -1;
	if (x_map < 0 || y_map < 0)
		return ;
	while (++y < 30)
	{
		x = -1;
		while (++x < 30)
		{
			mlx_put_pixel(img_minimap, x + (x_map * 30), y + (y_map* 30), color);
		}
	}
	mlx_put_pixel(img_minimap, x_map * 30, y_map* 30, 0xFF0000ff);
	mlx_put_pixel(img_minimap, 29 + x_map * 30, y_map* 30, 0xFF0000ff);
}