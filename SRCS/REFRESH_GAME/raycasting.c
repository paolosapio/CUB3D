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


t_vector	y_collision(t_coor start, t_int_coor map_coor, t_gradient m, mlx_image_t *image, float ray_length)
{

}

t_vector	x_collision(t_coor start, t_int_coor map_coor, t_gradient m, mlx_image_t *image)
{
	
}



t_coor	hipotenusitor_no_root(t_gradient m, t_int_coor map_coor, t_coor start, t_vector ray_length, mlx_image_t *image)
{
	
}

typedef	struct	s_collision
{
	float	x_vector;
	float	y_vector; //gradient
	float	hipotenuse;
	t_coor	collision_coor;
}				t_collision;

void	bresenham_prekit(mlx_image_t *image, float coor1_x, float coor1_y, float coor2_x, float coor2_y)
{
	t_coor coor1;
	t_coor coor2;

	coor1.x = coor1_x;
	coor1.y = coor1_y;
	coor2.x = coor2_x;
	coor2.y = coor2_y;
	bresenham_algorithm(image, coor1, coor2, color(255, 0, 0, 255));
}
void	quadriculeitor_aligner(mlx_image_t *image, t_coor start, t_coor end, t_gradient m, t_map map)
{
	t_collision y_collision;
	t_collision x_collision;

	if (end.x - start.x < 0)
	{
		y_collision.x_vector = (int)start.x - start.x;
	}
	else
	{
		y_collision.x_vector = (int)(start.x + 1) - (start.x);
	}

	bresenham_prekit(image, start.x, start.y, start.x + y_collision.x_vector, start.y);

	if (end.y - start.y < 0)
	{
		x_collision.y_vector = (int)start.y - start.y;
	}
	else
	{
		x_collision.y_vector = (int)(start.y + 1) - (start.y);
	}
	bresenham_prekit(image, start.x, start.y, start.x, start.y + x_collision.y_vector);

}

void	raycasting(mlx_image_t *image, t_coor start, t_coor end, t_map map)
{
	t_gradient m;

	m = gradienteitor(start, end);
	quadriculeitor_aligner(image, start, end, m, map);

}