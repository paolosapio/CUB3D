#include "cub3d.h"

void	bresenham_algorithm(mlx_image_t *player, float x1, float y1, float x2, float y2)
{
	//printf("ENTRAMOS A BRESENHAMªªªª\n");
	//printf("x1 = %f - y1 = %f || x2 = %f - y2 = %f\n", x1, y1, x2, y2);
	float dy = y2 - y1;
	float dx = x2 - x1;
	//printf("dy = %f, dx = %f\n", dy, dx);

	//avance inclinado
	float inc_y_i;
	float inc_x_i;

	//avance recto
	float inc_y_r;
	float inc_x_r;

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
	//printf("avances inclinados: inc_x_i = %f, inc_y_i = %f\n", inc_x_i, inc_y_i);
	//printf("updated: dy = %f, dx = %f\n", dy, dx);


	if (dx >= dy)
	{
		inc_y_r = 0;
		inc_x_r = inc_x_i;
	}
	else
	{
		inc_x_r = 0;
		inc_y_r = inc_y_i;
		float aux = dx; dx = dy; dy = aux;
	}
	//printf("avances rectos: inc_x_r = %f, inc_y_r %f\n", inc_x_r, inc_y_r);
	//printf("reupdated: dy = %f, dx = %f\n", dy, dx);

	float x = x1;
	float y = y1;

	float avanceR = (2 * dy);
	float avance = (avanceR - dx);
	float avanceI = (avance - dx);
	int color = 0xFF0000FF;
	//int red = 0x01010000;

	//printf("avanceR = %f, avance %f, avanceI %f\n", avanceR, avance, avanceR);
	//printf("----------------------------------------\n");
	while (x != x2 || y != y2)
	{
		if (x < 0 || y < 0 || x >= player->width || y >= player->height)
		{
			//printf("hora de salir del bucle mi pana\n");
			break;
		}
		mlx_put_pixel(player, x, y, color);
		//printf("x = %f, y = %f\n", x, y);
		//printf("avance = %f, avanceR = %f, avanceI = %f\n", avance, avanceR, avanceR);
		//printf("inc_x_r = %f, inc_y_r = %f, inc_x_i = %f, inc_y_i = %f\n", inc_x_r, inc_y_r, inc_x_i, inc_y_i);
		if (avance >= 0)
		{
			//printf("avance >= 0\n\n");
			x = x + inc_x_i;
			y = y + inc_y_i;
			avance = avance + avanceI;
		}
		else
		{
			//printf("En el else......\n\n");
			x = x + inc_x_r;
			y = y + inc_y_r;
			avance = avance + avanceR;
		}
		//printf("----------------------------------------\n");
	}
	//printf("\n\n");
	//exit (99);
}
