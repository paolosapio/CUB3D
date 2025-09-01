#include "refresh_game.h"
#include <math.h>

typedef t_coor t_gradient; // (m) || pendiente
typedef t_coor t_hipotenuse;

t_gradient	gradienteitor(t_coor start, t_coor end)
{
	t_gradient m;

	m.x = (end.y - start.y) / (end.x - start.x);
	m.y = (end.x - start.x) / (end.y - start.y);

	return (m);
}

t_hipotenuse hipotenuseitor(t_gradient m)
{
	t_hipotenuse h;

	//h = sqrt(x² + y²);
	h.x = sqrt(1 + (m.y * m.y));
	h.y = sqrt((m.x * m.x) + 1);

	return (h);
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
	
	if (end.x - start.x < 0)
	{
		map_coor.x = start.x;
		ray_x_length = (start.x - (float)map_coor.x) * m.x;
	}
	else
	{
		map_coor.x = start.x + 1;
		ray_x_length = ((float)map_coor.x - start.x) * m.x;
	}
	if (end.y - start.y < 0)
	{
		map_coor.y = start.y;
		ray_y_length = (start.y - (float)map_coor.y) * m.y;
	}
	else
	{
		map_coor.y = start.y + 1;
		ray_y_length = ((float)map_coor.y - start.y) * m.y;
	}
	// if (ray_x_length < ray_y_length)
	// {
	// 	mlx_put_pixel(image, map_coor.x * g_size_tile, );
	// }



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