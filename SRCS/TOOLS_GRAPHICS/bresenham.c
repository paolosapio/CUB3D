#include "tools_graphics.h"
#include <stdio.h>
#include <math.h>

/**
 * This function implements the bresenham algorithm to draw lines
 */

void	bresenham_algorithm(mlx_image_t *image, t_segment s, uint32_t color, int tile_size)
{
	// printf("s.start.x = %f s.start.y = %f\n", p1.x, s.start.y);
	// printf("p2.x = %f p2.y = %f\n", p2.x, p2.y);
	if (s.end.x < 0 || s.end.x == INFINITY)
		s.end.x = 0;
	if (s.end.y < 0 || s.end.y == INFINITY)
		s.end.y = 0;
	s.start.x =(int)(s.start.x * tile_size);
	s.start.y = (int)(s.start.y * tile_size);
	s.end.x = (int)(s.end.x * tile_size);
	s.end.y = (int)(s.end.y * tile_size);
	int dx = (int)fabsf(s.end.x - s.start.x);
	int dy = (int)fabsf(s.end.y - s.start.y);

	int sx = (s.start.x < s.end.x) ? 1 : -1;
	int sy = (s.start.y < s.end.y) ? 1 : -1;

	int err = dx - dy;
	int e2;

	int x = s.start.x;
	int y = s.start.y;

	while (1)
	{
		if (x >= 0 && y >= 0 && x < (int)image->width && y < (int)image->height)
			mlx_put_pixel(image, x, y, color);
		if ((x == s.end.x && y == s.end.y) || x < 0 || y < 0 || x > (int)image->width || y > (int)image->height)
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
	}
}

/*

ENTRAMOS A BRESENHAMªªªª
s.start.x = 485.000000 ->  s.end.x = 486.000000
p1y = 385.000000 -> s.end.y = 286.000000

dy = -99.000000, dx = 1.000000

avances inclinados:
inc_x_i = 1.000000, inc_y_i = -1.000000
updated: dy = 99.000000, dx = 1.000000

avances rectos:
inc_x_r = 0.000000, inc_y_r -1.000000
reupdated: dy = 1.000000, dx = 99.000000

avanceR = 2.000000, avance -97.000000, avanceI 2.000000

*/