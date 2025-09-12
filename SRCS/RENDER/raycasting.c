#include "render.h"
#include <math.h>

typedef t_coor t_hypo2_len;
typedef t_coor t_ray_len;

/* void print_center_line_neon(mlx_image_t *image, float ray_len, int x_axis, int _color)
{
	float middle_screen;
	float half_ray;
	int i = 0;

	half_ray = ray_len / 2;
	middle_screen = HEIGHT / 2;

	if (middle_screen - half_ray >= 0)
	{
		mlx_put_pixel(image, x_axis, middle_screen - half_ray, _color);
		mlx_put_pixel(image, x_axis, middle_screen + half_ray, _color);
		i++;
	}
	i = middle_screen - half_ray;
	if (i > 0 && _color == (int)color(0, 0, 0, 255))
	{	
		while(i <= middle_screen + half_ray)
		{
			mlx_put_pixel(image, x_axis, i, _color);
			i++;
		}
	}
} */


#define SCREEN_LIMIT_Y 0 
int	color_texture_extractor(float x_decimal, float y_not_yet_decimal, mlx_texture_t *wall)
{
	int		x_pixels_pos;
	int		y_pixels_pos;
	uint8_t	image_pixel_goal;

	int		colorK;

	x_pixels_pos = wall->width * x_decimal; //80px de 200px
	y_pixels_pos = wall->height * y_not_yet_decimal; //de momento primer pixel y

	image_pixel_goal = wall->pixels[((y_pixels_pos * wall->width) + x_pixels_pos) * wall->bytes_per_pixel];

	printf("asdasdasdad\n");
	printf("%d - %d - %d - %d\n", wall->pixels[image_pixel_goal], wall->pixels[image_pixel_goal + 1], wall->pixels[image_pixel_goal + 2], wall->pixels[image_pixel_goal + 3]);
	colorK = color(wall->pixels[image_pixel_goal], wall->pixels[image_pixel_goal + 1], wall->pixels[image_pixel_goal + 2], wall->pixels[image_pixel_goal + 3]);
	printf("colorK = %x\n", colorK);
	return (colorK);
}

void print_centered_line(mlx_image_t *screen, t_ray ray, int x_step, mlx_texture_t *wall)
{
	float middle_screen;
	float half_ray;
	int y_pos = 0;
	float	point_x_temp;
	int	texture_color;

	point_x_temp = ray.colision_point.x - (int)ray.colision_point.x;
	half_ray = ray.vertical_line / 2;
	middle_screen = HEIGHT / 2;


	
	if (middle_screen - half_ray >= SCREEN_LIMIT_Y)
	{
		while(y_pos)
		{

			texture_color = color_texture_extractor(point_x_temp, (float)y_pos, wall);
			mlx_put_pixel(screen, x_step, middle_screen - y_pos, texture_color);
			mlx_put_pixel(screen, x_step, middle_screen + y_pos, texture_color);
			y_pos++;
		}
	}
	else
	{
		while(y_pos <= HEIGHT)
		{
			mlx_put_pixel(screen, x_step, y_pos, color(0,0,0,255));
			y_pos++;
		}
	}
}


void	to_3d(mlx_image_t *image, t_ray ray, int x_step, t_player player, mlx_texture_t *texture)
{
	//int color;
	(void)player;
	ray.vertical_line = HEIGHT / ray.colision_len;
	// color = check_side_pixel(ray, player);
	print_centered_line(image, ray, x_step, texture);
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
