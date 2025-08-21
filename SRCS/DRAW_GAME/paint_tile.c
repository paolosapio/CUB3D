#include "draw_game.h"
#include <stdio.h>

void	paint_tile(int size_of_tile, mlx_image_t *img_minimap, t_int_coor coor, int32_t color)
{
	int	x;
	int	y;

	y = -1;
	if (coor.x < 0 || coor.y < 0)
		return ;
	while (++y < size_of_tile)
	{
		x = -1;
		while (++x < size_of_tile)
		{
			if (y == 0 || x == 0 || x == 29 || y == 29)
				mlx_put_pixel(img_minimap, x + (coor.x * size_of_tile), y + (coor.y* size_of_tile), 0xFFFF0011);
			else
				mlx_put_pixel(img_minimap, x + (coor.x * size_of_tile), y + (coor.y* size_of_tile), color);
		}
	}
}

void	paint_player(int size_of_tile, mlx_image_t	*img_minimap, t_coor player, int32_t color)
{
	int	x;
	int	y;

	y = -1 - CENTER_PLAYER * size_of_tile;
	if (player.x < 0 || player.y < 0)
		return ;
	while (++y < size_of_tile - CENTER_PLAYER * size_of_tile)
	{
		x = -1 - CENTER_PLAYER * size_of_tile;
		while (++x < size_of_tile - CENTER_PLAYER * size_of_tile)
		{
			mlx_put_pixel(img_minimap, x + (player.x * size_of_tile), y + (player.y* size_of_tile), color);
		}
	}
}