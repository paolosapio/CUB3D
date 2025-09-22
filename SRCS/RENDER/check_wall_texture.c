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

typedef enum e_texture_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}			t_texture_dir;

unsigned int color_picker(t_coor pixel_texture_porcent, mlx_texture_t *texture, float ray_len)
{
	unsigned int	x_in_texture;
	unsigned int	y_in_texture;
	unsigned char	*pixel_pos;
	unsigned int	color_pixel;
	unsigned int	texture_darkener;
	// if (direction == NORTH || direction == SOUTH)
	// {
		x_in_texture = texture->width * pixel_texture_porcent.x;
		y_in_texture = (int)pixel_texture_porcent.y * texture->width;
	// }
	// else
	// {
	// 	x_in_texture = pixel_texture_porcent.x;
	// 	y_in_texture = texture->width * pixel_texture_porcent.y;
	// }
	pixel_pos = &texture->pixels[((y_in_texture) + x_in_texture) * texture->bytes_per_pixel];

	texture_darkener = ray_len * 5;
	if ((*(pixel_pos) - *(pixel_pos) == 0))
		*(pixel_pos) = 0;
	color_pixel = color(*(pixel_pos), *(pixel_pos + 1), *(pixel_pos + 2), *(pixel_pos + 3));
	return (color_pixel);
}

// void	to_3d(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
// {
// 	float			x_pos_texture;
// 	float			y_pos_texture;
// 	float			pixel_little_jump;
// 	unsigned int	color_pixel;
// 	float			y_start_to_paint;
// 	float			end_screen;
// 	ray.vertical_line = HEIGHT / ray.colision_len;

// 	x_pos_texture = ray.colision_point.x - (int)ray.colision_point.x;
// 	pixel_little_jump = texture->height / ray.vertical_line;
// 	if (ray.vertical_line > HEIGHT)
// 	{
// 		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
// 		y_start_to_paint = 0.0;
// 		end_screen = texture->height - y_pos_texture;
// 	}
// 	else
// 	{
// 		y_pos_texture = 0.0;
// 		y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2);
// 		end_screen = texture->height;
// 	}
// 	while (y_pos_texture < end_screen) 
// 	{
// 		if (y_start_to_paint > HEIGHT)
// 			break ;
// 		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture);
// 		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
// 		y_start_to_paint++;
// 		y_pos_texture += pixel_little_jump;
// 	}
// }


// void	draw_texture_line(mlx_image_t *image, t_coor texture_coor, mlx_texture_t *texture)
// {
// 	unsigned int	color_pixel;

// 	while (texture_pos < end_screen)
// 	{
// 		if (screen_pos > HEIGHT)
// 			break ;
// 		color_pixel = color_picker(texture_coor, texture);
// 		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
// 		y_start_to_paint++;
// 		y_pos_texture += pixel_little_jump;
// 	}
// }

void	to_3d_north(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
{
	float			x_pos_texture; //cacular el percentual de la linea en el eje x
	float			y_pos_texture; //cacular el percentual de la linea en el eje y
	float			pixel_little_jump;
	unsigned int	color_pixel;
	float			y_start_to_paint;
	float			end_screen;
	ray.vertical_line = HEIGHT / ray.colision_len;

	x_pos_texture = ray.colision_point.x - (int)ray.colision_point.x;
	pixel_little_jump = texture->height / ray.vertical_line;

	if (ray.vertical_line > HEIGHT)
	{
		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
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
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.colision_len);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
}

void	to_3d_south(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
{
	float			x_pos_texture;
	float			y_pos_texture;
	float			pixel_little_jump;
	unsigned int	color_pixel;
	float			y_start_to_paint;
	float			end_screen;
	ray.vertical_line = HEIGHT / ray.colision_len;

	x_pos_texture = ((int)(ray.colision_point.x + 1) - ray.colision_point.x) - 0.001;
	pixel_little_jump = texture->height / ray.vertical_line;

	if (ray.vertical_line > HEIGHT)
	{
		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
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
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.colision_len);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
}

void	to_3d_east(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
{
	float			x_pos_texture;
	float			y_pos_texture;
	float			pixel_little_jump;
	unsigned int	color_pixel;
	float			y_start_to_paint;
	float			end_screen;
	ray.vertical_line = HEIGHT / ray.colision_len;

	x_pos_texture = ray.colision_point.y - (int)ray.colision_point.y;
	pixel_little_jump = texture->height / ray.vertical_line;
	if (ray.vertical_line > HEIGHT)
	{
		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
		y_start_to_paint = 0.0;
		end_screen = texture->height - x_pos_texture;
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
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.colision_len);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
}

void	to_3d_west(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
{
	float			x_pos_texture;
	float			y_pos_texture;
	float			pixel_little_jump;
	unsigned int	color_pixel;
	float			y_start_to_paint;
	float			end_screen;
	ray.vertical_line = HEIGHT / ray.colision_len;

	x_pos_texture = ((int)(ray.colision_point.y + 1) - ray.colision_point.y) - 0.001;
	pixel_little_jump = texture->height / ray.vertical_line;
	if (ray.vertical_line > HEIGHT)
	{
		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
		y_start_to_paint = 0.0;
		end_screen = texture->height - x_pos_texture;
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
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.colision_len);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
}

//esta funcon se va a convertir en check side texture que devuelve mlx_texture_t
void	check_wall_texture(t_ray ray, t_player player, t_images *images, float ray_index)
{
	float			x_rounded;
	float			y_rounded;

	x_rounded = roundf(ray.colision_point.x);
	y_rounded = roundf(ray.colision_point.y);

	// if (ray.colision_point.x >=  (x_rounded - MARGIN_BASE) && ray.colision_point.x <= (x_rounded + MARGIN_BASE) &&
	// 	ray.colision_point.y >= (y_rounded - MARGIN_BASE) && ray.colision_point.y <= (y_rounded + MARGIN_BASE))
	// 	return (last_color);

	if (ray.colision_point.x >=  (x_rounded - MARGIN_BASE) && ray.colision_point.x <= (x_rounded + MARGIN_BASE))
	{
		if (player.pos.x < ray.colision_point.x) //* Este
			to_3d_east(images->tridy, ray, ray_index, images->map_texture_E);
		else //* Este
			to_3d_west(images->tridy, ray, ray_index, images->map_texture_W);
	}

	if (ray.colision_point.y >=  (y_rounded - MARGIN_BASE) && ray.colision_point.y <= (y_rounded + MARGIN_BASE))
	{
		if (player.pos.y < ray.colision_point.y) //*Sur
			to_3d_south(images->tridy, ray, ray_index, images->map_texture_S);
		else									//*Norte
			to_3d_north(images->tridy, ray, ray_index, images->map_texture_N);
	}
}
