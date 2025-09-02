#include "refresh_game.h"
#include <math.h>

typedef t_coor t_gradient; // (m) || pendiente
typedef t_coor t_hipotenuse;

t_gradient	gradienteitor(t_coor start, t_coor end)
{
	t_gradient m;

	m.x = (end.y - start.y) / (end.x - start.x);
	m.y = (end.x - start.x) / (end.y - start.y);

	// printf("\nGRADIENTES: m.x = %f. m.y = %f\n", m.x, m.y);
	// printf(". start.x %f - start.y %f\n", start.x, start.y);
	// printf("... end.x %f -   end.y %f\n\n", end.x, end.y);
	return (m);
}

t_hipotenuse hipotenuseitor(t_gradient m)
{
	t_hipotenuse h;

	//*h = sqrt(x² + y²);
	h.x = sqrt(1 + (m.y * m.y));
	h.y = sqrt((m.x * m.x) + 1);

	return (h);
}

float	smallest_ray(float n1, float n2)
{
	float	original_n1_sign;
	float	original_n2_sign;

	if (n1 < 0)
	{
		n1 *= -1;
		original_n1_sign = -1;
	}
	else
		original_n1_sign = 1;

	if (n2 < 0)
	{
		n2 *= -1;
		original_n2_sign = -1;
	}
	else
		original_n2_sign = 1;

	if (n1 < n2)
		return (n1 * original_n1_sign);
	return (n2 * original_n2_sign);
}

void	quadriculeitor_aligner(mlx_image_t *image, t_coor start, t_coor end, t_gradient m, t_map map)
{
	float		ray_x_length;
	float		ray_y_length;
	(void)image;
	(void)map;
	t_coor		raycast_start_point;
	raycast_start_point.x = 0.0;
	raycast_start_point.y = 0.0;

	t_int_coor	map_coor;
	map_coor.x = start.x;
	map_coor.y = start.y;
	
	printf("start.x = %f, end.x = %f\n", start.x, end.x);
	printf(">>>> end.x - start.x = %f\n", end.x - start.x);
	if (end.x - start.x < 0)
	{
		map_coor.x = start.x;
		ray_x_length = ((float)map_coor.x - start.x) * m.x;
	}
	else
	{
		map_coor.x = start.x + 1;
		ray_x_length = (start.x - (float)map_coor.x) * m.x;
	}
	printf("start.y = %f, end.y = %f\n", start.y, end.y);
	printf(">>>> end.y - start.y = %f\n", end.y - start.y);
	if (end.y - start.y < 0)
	{
		map_coor.y = start.y;
		ray_y_length = ((float)map_coor.y - start.y) * m.y;
	}
	else
	{
		map_coor.y = start.y + 1;
		ray_y_length = (start.y - (float)map_coor.y) * m.y;
	}
	printf("ray_x_length = %f - gradient.x: %f\n", ray_x_length, m.x);
	printf("ray_y_length = %f - gradient.y: %f\n\n", ray_y_length, m.y);
	if (smallest_ray(ray_y_length, ray_x_length) == ray_y_length)
	{
		printf("entré aquí\n\n");
		mlx_put_pixel(
			image,
			(start.x + ray_y_length) * g_size_tile,
			map_coor.y * g_size_tile,
			color(255, 255, 255, 255)
		);
	}
	else
	{
		mlx_put_pixel(
			image,
			map_coor.x * g_size_tile,
			(start.y + ray_x_length) * g_size_tile,
			color(255, 255, 255, 255)
		);
	}



}

void	raycasting(mlx_image_t *image, t_coor start, t_coor end, t_map map)
{
	(void)map;
	t_gradient m;
	t_hipotenuse h;

	m = gradienteitor(start, end);
	h = hipotenuseitor(m);
	quadriculeitor_aligner(image, start, end, m, map);

}