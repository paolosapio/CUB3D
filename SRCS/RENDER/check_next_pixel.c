#include "render.h"

int	check_side_pixel(t_ray ray, t_player player)
{
	float	x_rounded;
	float	y_rounded;

	x_rounded = roundf(ray.colision_point.x);
	y_rounded = roundf(ray.colision_point.y);

	if (ray.colision_point.x >=  (x_rounded - 0.001) && ray.colision_point.x <= (x_rounded + 0.001) &&
		ray.colision_point.y >= (y_rounded - 0.001) && ray.colision_point.y <= (y_rounded + 0.001))
		return (color(0, 0, 0, 255));
	if (ray.colision_point.x >=  (x_rounded - 0.0001) && ray.colision_point.x <= (x_rounded + 0.0001))
	{
		if (player.pos.x < ray.colision_point.x)
			return (color(0, 255, 0, 255));
		return (color(255, 255, 0, 255));

	}
	if (ray.colision_point.y >= (y_rounded - 0.0001) && ray.colision_point.y <= (y_rounded + 0.0001))
	{
		if (player.pos.y < ray.colision_point.y)
			return (color(0, 0, 255, 255));
		return (color(255, 0, 0, 255));
	}
	return (color(0, 255, 0, 255));
}
