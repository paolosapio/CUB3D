#include "tools_graphics.h"

#include <stdio.h>

/**
 * This function implements the bresenham algorithm to draw lines
 */

void bresenham_algorithm(mlx_image_t *player, int x1, int y1, int x2, int y2)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;

	int err = dx - dy;
	int e2;

	int x = x1;
	int y = y1;

	int color = 0xFF0000FF;  // Rojo con alfa

	while (1)
	{
		if (x >= 0 && y >= 0 && x < (int)player->width && y < (int)player->height)
			mlx_put_pixel(player, x, y, color);

		if (x == x2 && y == y2)
			break;

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
	}
}

/*

ENTRAMOS A BRESENHAMªªªª
x1 = 485.000000 ->  x2 = 486.000000
y1 = 385.000000 -> y2 = 286.000000

dy = -99.000000, dx = 1.000000

avances inclinados:
inc_x_i = 1.000000, inc_y_i = -1.000000
updated: dy = 99.000000, dx = 1.000000

avances rectos:
inc_x_r = 0.000000, inc_y_r -1.000000
reupdated: dy = 1.000000, dx = 99.000000

avanceR = 2.000000, avance -97.000000, avanceI 2.000000

*/