#include "render.h"
#include <math.h>

typedef t_coor t_hypo2_len;
typedef t_coor t_ray_len;

void print_center_line(mlx_image_t *image, float ray_len, int x_axis, int color)
{
	float middle_screen;
	float half_ray;
	int i = 0;

	half_ray = ray_len / 2;
	middle_screen = HEIGHT / 2;

	if (middle_screen - half_ray >= 0)
	{
		while(i <= half_ray)
		{
			mlx_put_pixel(image, x_axis, middle_screen - i, color);
			mlx_put_pixel(image, x_axis, middle_screen + i, color);
			i++;
		}
	}
	else
	{
		while(i <= HEIGHT)
		{
			mlx_put_pixel(image, x_axis, i, color);
			i++;
		}
	}
}

void	to_3d(mlx_image_t *image, t_ray ray, int x_axis, t_player player)
{
	float	vertical_line;
	int color;

	vertical_line = HEIGHT / ray.colision_len;
	color = check_side_pixel(ray, player);
	print_center_line(image, vertical_line, x_axis, color);
}

t_ray	raycasting(t_coor start_pos, t_coor end_pos, t_map map)
{
	t_ray		ray;
	t_hypo2_len	hypo_uninary;
	t_int_coor	map_coor;
	t_hypo2_len	hypo_supreme;
	int			dir_x;
	int			dir_y;
	t_ray_len	sides;

	sides.x = end_pos.x - start_pos.x;
	sides.y = end_pos.y - start_pos.y;

	hypo_uninary.x = (float)sqrt(1 + (sides.y / sides.x) * (sides.y / sides.x));
	hypo_uninary.y = (float)sqrt(1 + (sides.x / sides.y) * (sides.x / sides.y));
	map_coor.x = (int)start_pos.x;
	map_coor.y = (int)start_pos.y;
	if (sides.x < 0)
	{
        dir_x = -1;
		hypo_supreme.x = (start_pos.x - (float)map_coor.x) * hypo_uninary.x;
	}
	else
	{
        dir_x = 1;
		hypo_supreme.x = ((float)(map_coor.x + 1) - start_pos.x) * hypo_uninary.x;
	}
    
	if (sides.y < 0)
	{
        dir_y = -1;
		hypo_supreme.y = (start_pos.y - (float)map_coor.y) * hypo_uninary.y;
	}
	else
	{
        dir_y = 1;
		hypo_supreme.y = ((float)(map_coor.y + 1) - start_pos.y) * hypo_uninary.y;
	}
	while (map.array[map_coor.y][map_coor.x] != '1')
	{

		if (hypo_supreme.x < hypo_supreme.y)
		{
            map_coor.x += dir_x;
			ray.colision_len = hypo_supreme.x;
			hypo_supreme.x += hypo_uninary.x;
		}
		else
		{
            map_coor.y += dir_y;
			ray.colision_len = hypo_supreme.y;
			hypo_supreme.y += hypo_uninary.y;
		}
	}
    float new_x = ray.colision_len / hypo_uninary.x;
    float new_y = ray.colision_len / hypo_uninary.y;
	end_pos.x = start_pos.x + dir_x * new_x;
	end_pos.y = start_pos.y + dir_y * new_y;
	ray.colision_point = end_pos;
	// si es <= casilla player es W si es > de casilla player es E
	return (ray);
}
