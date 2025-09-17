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

unsigned int color_picker(t_coor pixel_texture_porcent, mlx_texture_t *texture)
{
unsigned int	x_in_texture;
unsigned int	y_in_texture;
unsigned char	*pixel_pos;
unsigned int	color_pixel;

x_in_texture = texture->width * pixel_texture_porcent.x;	//140
y_in_texture = pixel_texture_porcent.y;	//199

					//percentual donde me encountro el color;
// printf("(y_in_texture: %d\n", y_in_texture);
// printf("(x_in_texture: %d\n", x_in_texture);
// printf("(y_in_texture * texture->width) + x_in_texture: %d\n", (y_in_texture * texture->width) + x_in_texture);
pixel_pos = &texture->pixels[((y_in_texture * texture->width) + x_in_texture) * texture->bytes_per_pixel]; // el pixel es 111440
// printf("red   %d\n  ", *(pixel_pos + 0));
// printf("green %d\n  ", *(pixel_pos + 1));
// printf("blue  %d\n  ", *(pixel_pos + 2));
// printf("alfa  %d\n\n", *(pixel_pos + 3));
color_pixel = color(*(pixel_pos), *(pixel_pos + 1), *(pixel_pos + 2), *(pixel_pos + 3));
return (color_pixel);
}

#define SCREEN_LIMIT_Y 0

// TODO tenemos que calcular qual es el pixel de la 
// TODO textura y su posiocion en la pantalla y porsupuesto
// TODO pintarlo, y seguir hasta el siguente de la miama columna

float	y_start_pos(t_ray ray)
{
	float	y_start_to_paint;

	y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2);
	return (y_start_to_paint);
}

void	to_3d(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
{
	float			x_pos_texture;
	float			y_pos_texture;
	float			pixel_little_jump;
	unsigned int	color_pixel;
	float			y_start_to_paint;
	float			end_screen;

	ray.vertical_line = HEIGHT / ray.colision_len;	//!! float longitud de la linea!! lo que se tiene qeu pintar con pixeles de la textura!!
	x_pos_texture = ray.colision_point.x - (int)ray.colision_point.x;
	//y_start_to_paint = y_start_pos(ray);
	pixel_little_jump = texture->height / ray.vertical_line;
	// printf("pixel_little_jump: %f\n", pixel_little_jump);
	// printf("y_pos_texture: %f\n", y_pos_texture);

	if (ray.vertical_line > HEIGHT)
	{
		//printf("asdasdasdasdda: %f\n", ((ray.vertical_line - HEIGHT) / 2));
		y_pos_texture = texture->width * ((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line;
		end_screen = texture->height - y_pos_texture;
		printf("----> end_screen: %f\n", end_screen);
		y_start_to_paint = 0;
	}
	else
	{
		y_pos_texture = 0.0;
		end_screen = texture->height;
		y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2);
	}
	// printf("ray.vertical_line: %f\n", ray.vertical_line);
	// printf("ññññññññññññññññññy_pos_texture: %f\n", y_pos_texture);
	
	//TODO REVISAR ESTO Y APAÑARLO MEJOR
	while (y_pos_texture < end_screen) 
	{
		// if (texture->height > HEIGHT)>>
		// printf("y_pos_texture: %f\n", y_pos_texture);

		// printf("y_pos_texture: %f\n", y_pos_texture);
		// printf("end_screen: %f\n", end_screen);
		// printf("y_start_to_paint: %f\n", y_start_to_paint);
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
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
