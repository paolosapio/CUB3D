/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:25:21 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 20:01:55 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define MARGIN_BASE 0.0001
#define SCREEN_LIMIT_Y 0

unsigned int	color_picker(t_coor pixel_texture_porcent,
		mlx_texture_t *texture, float darkener)
{
	unsigned int	x_in_texture;
	unsigned int	y_in_texture;
	unsigned char	*pixel_pos;
	unsigned int	color_pixel;
	float			green;

	green = darkener * 1.5;
	if (green > 1)
		green = 1;
	x_in_texture = texture->width * pixel_texture_porcent.x;
	y_in_texture = (int)pixel_texture_porcent.y * texture->width;
	pixel_pos = &texture->pixels[((y_in_texture) + x_in_texture)
		* texture->bytes_per_pixel];
	color_pixel = ft_color(*(pixel_pos) * darkener, *(pixel_pos + 1)
			* green, *(pixel_pos + 2) * darkener, *(pixel_pos + 3));
	return (color_pixel);
}

void	to_3d_north(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture, t_player player)
{
	float			x_pos_texture;
	float			y_pos_texture;
	float			pixel_little_jump;
	unsigned int	color_pixel;
	float			y_start_to_paint;
	float			end_screen;

	ray.vertical_line = HEIGHT / ray.colision_len;
	x_pos_texture = ray.colision_point.x - (int)ray.colision_point.x;
	pixel_little_jump = texture->height / ray.vertical_line;
	if (ray.vertical_line > HEIGHT)
	{
		y_pos_texture = (texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line)) + player.view;
		if (y_pos_texture < 0)
			y_pos_texture = 0;
		y_start_to_paint = 0.0;
		end_screen = texture->height - y_pos_texture;
	}
	else
	{
		y_pos_texture = 0.0;
		y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2) + player.view;
		if (y_start_to_paint < 0)
			y_start_to_paint = 0;
		end_screen = texture->height;
	}
	while (y_pos_texture < end_screen) 
	{
		if (y_start_to_paint > HEIGHT)
			break ;
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
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
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
}

float	get_x_pos_texture(t_texture_dir dir, t_coor colision_point)
{
	float	x;

	if (dir == SOUTH)
		x = ((int)(colision_point.x + 1) - colision_point.x) - 0.001;//???
	else if (dir == WEST)
		x = ((int)(colision_point.y + 1) - colision_point.y) - 0.001;
	else if (dir == EAST)
		x = colision_point.y - (int)colision_point.y;
	else if (dir == NORTH)
		x = colision_point.x - (int)colision_point.x;
	return (x);
}

void	to_3d_east(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture, t_texture_dir dir)
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
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
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
		color_pixel = color_picker((t_coor){x_pos_texture, y_pos_texture}, texture, ray.darkener_percent);
		mlx_put_pixel(image, ray_index, y_start_to_paint, color_pixel);
		y_start_to_paint++;
		y_pos_texture += pixel_little_jump;
	}
}


void	draw_texture_line(mlx_image_t *image, t_ray ray, int ray_index, mlx_texture_t *texture, t_texture_dir dir)
{
	t_coor	texture_coor;
	float	pixel_little_jump;
	float	screen_coor_y;
	float	end_screen_coor;
	float	color_pixel;

	texture_coor.x = get_x_pos_texture(dir, ray.colision_point);
	pixel_little_jump = texture->height / ray.vertical_line;
	if (ray.vertical_line > HEIGHT)
	{
		texture_coor.y = texture->height * ((int)((ray.vertical_line - HEIGHT) / 2) / ray.vertical_line);
		screen_coor_y = 0.0;
		if (dir == NORTH || dir == SOUTH)
			end_screen_coor = texture->height - texture_coor.y;
		else if (dir == WEST || dir == EAST)
			end_screen_coor = texture->height - texture_coor.x;
	}
	else
	{
		texture_coor.y = 0.0;
		screen_coor_y = (HEIGHT / 2) - (ray.vertical_line / 2);
		end_screen_coor = texture->height;
	}
	while (screen_coor_y < end_screen_coor)
	{
		if (screen_coor_y > HEIGHT)
			break ;
		color_pixel = color_picker(texture_coor, texture, ray.darkener_percent);
		mlx_put_pixel(image, ray_index, screen_coor_y, color_pixel);
		screen_coor_y++;
		texture_coor.y += pixel_little_jump;
	}
	
}

void	check_wall_texture(t_ray ray, t_player player, t_images *images, float ray_index)
{
	float			x_rounded;
	float			y_rounded;
	void			*img_texture[2];

	img_texture[0] = images->tridy;
	x_rounded = roundf(ray.colision_point.x);
	y_rounded = roundf(ray.colision_point.y);
	// if (ray.colision_point.x >=  (x_rounded - MARGIN_BASE) && ray.colision_point.x <= (x_rounded + MARGIN_BASE) &&
	// 	ray.colision_point.y >= (y_rounded - MARGIN_BASE) && ray.colision_point.y <= (y_rounded + MARGIN_BASE))
	// 	return (last_color);
	ray.darkener_percent = 4 / ray.colision_len;
	if (ray.darkener_percent > 1)
		ray.darkener_percent = 1;
	if (ray.colision_point.x >=  (x_rounded - MARGIN_BASE) && ray.colision_point.x <= (x_rounded + MARGIN_BASE))
	{
		if (player.pos.x < ray.colision_point.x) //* Este
		{
			img_texture[1] = images->map_texture_E;
			to_3d_east(images->tridy, ray, ray_index, images->map_texture_E);
		}
		else //* Oeste
			to_3d_west(images->tridy, ray, ray_index, images->map_texture_W);
	}
	if (ray.colision_point.y >= (y_rounded - MARGIN_BASE) && ray.colision_point.y <= (y_rounded + MARGIN_BASE))
	{
		if (player.pos.y < ray.colision_point.y) //*Sur
			to_3d_south(images->tridy, ray, ray_index, images->map_texture_S);
		else									//*Norte
			to_3d_north(images->tridy, ray, ray_index, images->map_texture_N, player);
	}
}
