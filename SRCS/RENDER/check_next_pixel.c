#include "render.h"

#define MARGIN_BASE 0.0001

// int	check_side_pixel(t_ray ray, t_player player, mlx_image_t *image)
// {
// 	image.
// }

t_coor f()
{
	float a = 4;
	float b = 4;
	return ((t_coor){.x = a, .y = b});
}

typedef struct s_o_3d
{
	mlx_texture_t *texture;
	
	/* data */
} t_o_3d;


//esta funcon se va a convertir en check side texture que devuelve mlx_texture_t
int	check_side_pixel(t_ray ray, t_player player)
{
	static uint32_t	last_color;
	float			x_rounded;
	float			y_rounded;

	x_rounded = roundf(ray.colision_point.x);
	y_rounded = roundf(ray.colision_point.y);

	if (ray.colision_point.x >=  (x_rounded - MARGIN_BASE) && ray.colision_point.x <= (x_rounded + MARGIN_BASE) &&
		ray.colision_point.y >= (y_rounded - MARGIN_BASE) && ray.colision_point.y <= (y_rounded + MARGIN_BASE))
		return (last_color);

	if (ray.colision_point.x >=  (x_rounded - MARGIN_BASE) && ray.colision_point.x <= (x_rounded + MARGIN_BASE))
	{
		if (player.pos.x < ray.colision_point.x) //* Este
			last_color = color(255, 0, 0, 255);
		else									//* Oeste
			last_color = color(0, 50, 255, 255); 
		return (last_color);
	}

	if (ray.colision_point.y >=  (y_rounded - MARGIN_BASE) && ray.colision_point.y <= (y_rounded + MARGIN_BASE))
	{
		if (player.pos.y < ray.colision_point.y) //*Sur
			last_color = color(255, 255, 0, 255);
		else									//*Norte
			last_color = color(0, 255, 0, 255);
		return (last_color);
	}
	last_color = color(255, 0, 0, 255);
	return (last_color);
}
