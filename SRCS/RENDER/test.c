// #include "render.h"

// void	to_3d_north(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture, t_player player)
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
// 		y_pos_texture = (texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line)) + player.view;
// 		if (y_pos_texture < 0)
// 			y_pos_texture = 0;
// 		y_start_to_paint = 0.0;
// 		end_screen = texture->height - y_pos_texture;
// 	}
// 	else
// 	{
// 		y_pos_texture = 0.0;
// 		y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2) + player.view;
// 		if (y_start_to_paint < 0)
// 			y_start_to_paint = 0;
// 		end_screen = texture->height;
// 	}
// 	while (y_pos_texture < end_screen) 
// 	{
// 		if (y_start_to_paint > HEIGHT)
// 			break ;
// 		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
// 		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
// 		y_start_to_paint++;
// 		y_pos_texture += pixel_little_jump;
// 	}
// }

// void	to_3d_south(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
// {
// 	float			x_pos_texture;
// 	float			y_pos_texture;
// 	float			pixel_little_jump;
// 	unsigned int	color_pixel;
// 	float			y_start_to_paint;
// 	float			end_screen;

	
// 	x_pos_texture = ((int)(ray.colision_point.x + 1) - ray.colision_point.x) - 0.001;
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
// 		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
// 		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
// 		y_start_to_paint++;
// 		y_pos_texture += pixel_little_jump;
// 	}
// }

// void	to_3d_east(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture, t_texture_dir dir)
// {
// 	float			x_pos_texture;
// 	float			y_pos_texture;
// 	float			pixel_little_jump;
// 	unsigned int	color_pixel;
// 	float			y_start_to_paint;
// 	float			end_screen;

// 	ray.vertical_line = HEIGHT / ray.colision_len;
// 	x_pos_texture = ray.colision_point.y - (int)ray.colision_point.y;
// 	pixel_little_jump = texture->height / ray.vertical_line;
// 	if (ray.vertical_line > HEIGHT)
// 	{
// 		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
// 		y_start_to_paint = 0.0;
// 		end_screen = texture->height - x_pos_texture;
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
// 		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
// 		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
// 		y_start_to_paint++;
// 		y_pos_texture += pixel_little_jump;
// 	}
// }

// void	to_3d_west(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture)
// {
// 	float			x_pos_texture;
// 	float			y_pos_texture;
// 	float			pixel_little_jump;
// 	unsigned int	color_pixel;
// 	float			y_start_to_paint;
// 	float			end_screen;

// 	ray.vertical_line = HEIGHT / ray.colision_len;
// 	x_pos_texture = ((int)(ray.colision_point.y + 1) - ray.colision_point.y) - 0.001;
// 	pixel_little_jump = texture->height / ray.vertical_line;
// 	if (ray.vertical_line > HEIGHT)
// 	{
// 		y_pos_texture = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
// 		y_start_to_paint = 0.0;
// 		end_screen = texture->height - x_pos_texture;
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
// 		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
// 		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
// 		y_start_to_paint++;
// 		y_pos_texture += pixel_little_jump;
// 	}
// }