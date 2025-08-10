#include "cub3d.h"

void	bresenham_algorithm(mlx_image_t *player, int x1, int y1, int x2, int y2)
{

	int dy = y2 - y1;
	int dx = x2 - x1;

	//avance inclinado
	int inc_y_i;
	int inc_x_i;

	//avance recto
	int inc_y_r;
	int inc_x_r;

	if (dy >= 0)
		inc_y_i = 1;
	else
	{
		dy = -dy;
		inc_y_i = -1;
	}

	if (dx >= 0)
		inc_x_i = 1;
	else
	{
		dx = -dx;
		inc_x_i = -1;
	}

	if (dx >= dy)
	{
		inc_y_r = 0;
		inc_x_r = inc_x_i;
	}
	else
	{
		inc_x_r = 0;
		inc_y_r = inc_y_i;
		int aux = dx; dx = dy; dy = aux;
	}

	int x = x1;
	int y = y1;

	int avanceR = (2 * dy);
	int avance = (avanceR - dx);
	int avanceI = (avance - dx);
	int color = 0xFF0000FF;
	//int red = 0x01010000;
	printf("EN BRESENHAM!!! x = %d, x2 = %d, y = %d, y2 = %d\n", x, x2, y, y2);
	while (x != x2 && y != y2)
	{
		if (x < 0 || y < 0)
			break;
		mlx_put_pixel(player, x, y, color);
		printf("x = %d, y = %d\n", x, y);
		printf("avance = %d, avanceR = %d, avanceI = %d\n", avance, avanceR, avanceR);
		printf("inc_x_r = %d, inc_y_r = %d, inc_x_i = %d, inc_y_i = %d\n", inc_x_r, inc_y_r, inc_x_i, inc_y_i);
		if (avance >= 0)
		{
			printf("avance >= 0\n\n");
			x = x + inc_x_i;
			y = y + inc_y_i;
			avance = avance + avanceI;
		}
		else
		{
			printf("En el else......\n\n");
			x = x + inc_x_r;
			y = y + inc_y_r;
			avance = avance + avanceR;
		}
	}
}
