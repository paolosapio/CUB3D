#include "render.h"

#define MARGIN_BASE 0.0001
#define SCREEN_LIMIT_Y 0
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

unsigned int color_picker(t_coor pixel_texture_porcent, mlx_texture_t *texture)
{
	unsigned int	x_in_texture;
	unsigned int	y_in_texture;
	unsigned char	*pixel_pos;
	unsigned int	color_pixel;

	x_in_texture = texture->width * pixel_texture_porcent.x;
	y_in_texture = pixel_texture_porcent.y;
	pixel_pos = &texture->pixels[((y_in_texture * texture->width) + x_in_texture) * texture->bytes_per_pixel];
	color_pixel = color(*(pixel_pos), *(pixel_pos + 1), *(pixel_pos + 2), *(pixel_pos + 3));
	return (color_pixel);
}

void	to_3d(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
{
	float			x_pos_texture;
	float			y_pos_texture;
	float			pixel_little_jump;
	unsigned int	color_pixel;
	float			y_start_to_paint;
	float			end_screen;
	ray.vertical_line = HEIGHT / ray.colision_len;
	// if (ray.vertical_line > 100000)
	// 	ray.vertical_line = 100000;
	// printf("ray.colision_len: %f10\n", ray.colision_len);
	// printf("ray.vertical_line: %f10\n", ray.vertical_line);
	x_pos_texture = ray.colision_point.x - (int)ray.colision_point.x;
	pixel_little_jump = texture->height / ray.vertical_line;
	if (ray.vertical_line > HEIGHT)
	{
		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
		// printf("y_pos_texture: %f\n", y_pos_texture);
		//if (y_pos_texture > texture->height)
		y_start_to_paint = 0.0;
		end_screen = texture->height - y_pos_texture;
	}
	else
	{
		y_pos_texture = 0.0;
		y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2);
		end_screen = texture->height;
	}
	while (y_pos_texture < end_screen) 
	{
		if (y_start_to_paint > HEIGHT)
			break ;
		//printf("")
		
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
}

//esta funcon se va a convertir en check side texture que devuelve mlx_texture_t
int	check_wall_texture(t_ray ray, t_player player)
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
