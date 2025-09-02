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

// t_hipotenuse hipotenuseitor(t_gradient m)
// {
// 	t_hipotenuse h;

// 	//*h = sqrt(x² + y²);
// 	h.x = sqrt(1 + (m.y * m.y));
// 	h.y = sqrt((m.x * m.x) + 1);

// 	return (h);
// }

// float	smallest_ray(float n1, float n2)
// {
// 	float	original_n1_sign;
// 	float	original_n2_sign;

// 	if (n1 < 0)
// 	{
// 		n1 *= -1;
// 		original_n1_sign = -1;
// 	}
// 	else
// 		original_n1_sign = 1;
	
// 	if (n2 < 0)
// 	{
// 		n2 *= -1;
// 		original_n2_sign = -1;
// 	}
// 	else
// 		original_n2_sign = 1;

// 	if (n1 < n2)
// 		return (n1 * original_n1_sign);
// 	return (n2 * original_n2_sign);
// }

t_vector	y_collision(t_coor start, t_int_coor map_coor, t_gradient m, mlx_image_t *image)
{
	t_vector	double_side_len;
	t_coor		collision_coor_1;
	t_coor		collision_coor_2;

	double_side_len.x = start.x - map_coor.x;
	double_side_len.y = (start.y - map_coor.y) * m.y;

	collision_coor_1.x = start.x - double_side_len.x;
	collision_coor_1.y = start.y;
	bresenham_algorithm(image, start, collision_coor_1, color(255, 0, 0, 255));
	collision_coor_2.x = collision_coor_1.x;
	collision_coor_2.y = collision_coor_1.y + (-double_side_len.y);
	bresenham_algorithm(image, collision_coor_1, collision_coor_2, color(255, 0, 0, 255));
	return (double_side_len);
}

t_vector	x_collision(t_coor start, t_int_coor map_coor, t_gradient m, mlx_image_t *image)
{
	t_vector	double_side_len;

	double_side_len.y = start.y - map_coor.y;
	double_side_len.x = (start.x - map_coor.x) * m.x;
	return (double_side_len);
}



t_coor	hipotenusitor_no_root(t_gradient m, t_int_coor map_coor, t_coor start, mlx_image_t *image)
{
	t_vector		collision_vector_x;
	t_vector		collision_vector_y;
	t_hipotenuse	hipo_no_root;

	collision_vector_x = x_collision(start, map_coor, m, image);
	collision_vector_y = y_collision(start, map_coor, m, image);

	hipo_no_root.x = (collision_vector_x.y * collision_vector_x.y) + (collision_vector_x.x * collision_vector_x.x);
	hipo_no_root.y = (collision_vector_y.x * collision_vector_y.x) + (collision_vector_y.y * collision_vector_y.y);
	
	if (hipo_no_root.x < hipo_no_root.y)
	{
		start.x += collision_vector_x.x; 
		start.y += collision_vector_x.y; 
		return (start);
	}
	start.x -= collision_vector_y.x; 
	start.y -= collision_vector_y.y; 
	return (start);
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
		ray_x_length = ((float)map_coor.x - start.x) * m.x;
	}
	else
	{
		map_coor.x = start.x + 1;
		ray_x_length = -(start.x - (float)map_coor.x) * m.x;
	}

	if (end.y - start.y < 0)
	{
		map_coor.y = start.y;
		ray_y_length = ((float)map_coor.y - start.y) * m.y;
	}
	else
	{
		map_coor.y = start.y + 1;
		ray_y_length = -(start.y - (float)map_coor.y) * m.y;
	}

	raycast_start_point = hipotenusitor_no_root(m, map_coor, start, image);

	// if (smallest_ray(ray_y_length, ray_x_length) == ray_y_length)
	// {
	// 	printf("entré aquí\n\n");
	// 	mlx_put_pixel(
	// 		image,
	// 		(start.x + ray_y_length) * g_size_tile,
	// 		map_coor.y * g_size_tile,
	// 		color(255, 255, 255, 255)
	// 	);
	// }
	
	mlx_put_pixel(
		image, raycast_start_point.x * g_size_tile, raycast_start_point.y * g_size_tile, color(255, 255, 255, 255));
}

void	raycasting(mlx_image_t *image, t_coor start, t_coor end, t_map map)
{
	t_gradient m;

	m = gradienteitor(start, end);
	quadriculeitor_aligner(image, start, end, m, map);

}