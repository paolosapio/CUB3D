#include "tools_graphics.h"
#include <stdio.h>

/**
 * This function implements the bresenham algorithm to draw lines
 */

void bresenham_algorithm(mlx_image_t *image, t_coor p1, t_coor p2, uint32_t color)
{
	p1.x =(int)(p1.x * g_size_tile);
	p1.y = (int)(p1.y * g_size_tile);
	p2.x = (int)(p2.x * g_size_tile);
	p2.y = (int)(p2.y * g_size_tile);
	int dx = abs(p2.x - p1.x);
	int dy = abs(p2.y - p1.y);

	int sx = (p1.x < p2.x) ? 1 : -1;
	int sy = (p1.y < p2.y) ? 1 : -1;

	int err = dx - dy;
	int e2;

	int x = p1.x;
	int y = p1.y;

	while (1)
	{
		if (x >= 0 && y >= 0 && x < (int)image->width && y < (int)image->height)
			mlx_put_pixel(image, x, y, color);

		if (x == p2.x && y == p2.y)
			break ;

		e2 = 2 * err;

		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}

		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
		// printf("GRRRRRRRRRRRR\n");
	}
}

/*

ENTRAMOS A BRESENHAMªªªª
p1.x = 485.000000 ->  p2.x = 486.000000
p1y = 385.000000 -> p2.y = 286.000000

dy = -99.000000, dx = 1.000000

avances inclinados:
inc_x_i = 1.000000, inc_y_i = -1.000000
updated: dy = 99.000000, dx = 1.000000

avances rectos:
inc_x_r = 0.000000, inc_y_r -1.000000
reupdated: dy = 1.000000, dx = 99.000000

avanceR = 2.000000, avance -97.000000, avanceI 2.000000

*/