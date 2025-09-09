#include "refresh_game.h"
#include <math.h>

typedef t_coor t_hypo2_len;
typedef t_coor t_ray_len;

t_coor raycasting(mlx_image_t *image, t_coor start_pos, t_coor end_pos, t_map map)
{
	// bresenham_algorithm(image, start_pos, end_pos, color(0, 255, 0, 255));

	t_hypo2_len	hypo_uninary;
	t_int_coor	map_coor;
	t_hypo2_len	hypo_supreme;
	int			dir_x;
	int			dir_y;
	t_ray_len	sides;

	sides.x = end_pos.x - start_pos.x;
	sides.y = end_pos.y - start_pos.y;
    

	printf("sides.x: %f\n", sides.x);	
	printf("sides.y: %f\n", sides.y);
	//sqrt(x² + y²)
	// hypo_uninary.x = sqrt(1 + (sides.y / sides.x) * (sides.y / sides.x));
	// hypo_uninary.y = sqrt(1 + (sides.x / sides.y) * (sides.x / sides.y));

    // float deltaDistX = sqrtf(1.0f + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x));
    // float deltaDistY = sqrtf(1.0f + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y));

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
    printf("first intersection: %f %f\n", hypo_supreme.x, hypo_supreme.y);
    
	float	collision_ray_length;

	while (map.array[map_coor.y][map_coor.x] != '1')
	{

		if (hypo_supreme.x < hypo_supreme.y)
		{
            map_coor.x += dir_x;
			collision_ray_length = hypo_supreme.x;
			hypo_supreme.x += hypo_uninary.x;
		}
		else
		{
            map_coor.y += dir_y;
			collision_ray_length = hypo_supreme.y;
			hypo_supreme.y += hypo_uninary.y;
		}
	}
    float new_x = collision_ray_length / hypo_uninary.x;
    float new_y = collision_ray_length / hypo_uninary.y;
    printf("new_x = %f\n", new_x);
    printf("new_y = %f\n", new_y);

	end_pos.x = start_pos.x + dir_x * new_x;
    printf("collision_ray_length: %f\n", collision_ray_length);
	end_pos.y = start_pos.y + dir_y * new_y;
	printf("start_pos.x = %f\n", start_pos.x);
	printf("start_pos.y = %f\n", start_pos.y);
	printf("dir_x * collision_ray_length = %f\n", dir_x * collision_ray_length);
	printf("dir_y * collision_ray_length = %f\n\n", dir_y * collision_ray_length);
	printf("END_POS.X = %f\n", end_pos.x);
	printf("END_POS.y = %f\n", end_pos.y);
    
	bresenham_algorithm(image, start_pos, end_pos, color(255, 0, 0, 255));
	
	//con pitagora hacemos el calculo de las hipotenusas
    
    
    mlx_put_pixel(image, start_pos.x, start_pos.y, color(0, 0, 0, 255));
}
