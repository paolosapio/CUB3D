/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:25:21 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 21:51:44 by psapio           ###   ########.fr       */
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


/**
 * @brief This function calculates the x position of the texture we are facing
 * based on which direction we are looking at and the colision_point.
 */
float	get_x_pos_texture(t_texture_dir dir, t_coor colision_point)
{
	float	x;

	x = 0;
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


typedef struct	s_texture_line
{
	t_texture_dir	dir;
	t_coor			texture_coor;
	t_coor			screen_coor;
	mlx_texture_t	*texture;
	float			screen_wall_height;
}				t_texture_line;

/**
 * @brief This function will init the values neede for draw_texture_line()
 * based on wether the whole texture fits inside the screen, or if the character
 * is so close to the wall only a part of it fits on screen.
 * 
 * @param wall_height The walls height in pixels.
 * @param t A struct containing much needed information in a norminette friendly
 * format.
 */
void	init_texture_drawer_values(float wall_height, t_texture_line *t)
{
	if (wall_height > HEIGHT)
	{
		t->texture_coor.y = t->texture->height * 
			((int)((wall_height - HEIGHT) / 2) / wall_height);
		// es equivalente a: t->texture_coor.y = t->texture->height * (0.5 - HEIGHT / (2 * wall_height));
		t->screen_coor.y = 0.0;
		if (t->dir == NORTH || t->dir == SOUTH)
			t->screen_wall_height = t->texture->height - t->texture_coor.y;
		else if (t->dir == WEST || t->dir == EAST)
			t->screen_wall_height = t->texture->height - t->texture_coor.x;
	}
	else
	{
		t->texture_coor.y = 0.0;
		t->screen_coor.y = (HEIGHT / 2) - (wall_height / 2);
		t->screen_wall_height = t->texture->height;
	}
}

void	draw_texture_line(mlx_image_t *img, t_ray ray, t_texture_line t)
{
	float		pixel_little_jump;
	uint32_t	color_pixel;

	t.texture_coor.x = get_x_pos_texture(t.dir, ray.colision_point);
	pixel_little_jump = t.texture->height / ray.vertical_line;
	init_texture_drawer_values(ray.vertical_line, &t);
	while (t.texture_coor.y < t.screen_wall_height)
	{
		if (t.screen_coor.y > HEIGHT)
			break ;
		color_pixel = color_picker(t.texture_coor, t.texture, ray.darkener_percent);
		mlx_put_pixel(img, t.screen_coor.x, t.screen_coor.y, color_pixel);
		t.screen_coor.y++;
		t.texture_coor.y += pixel_little_jump;
	}
}

void	check_wall_texture(t_ray ray, t_player player, t_images *images, float ray_index)
{
	float			x_rounded;
	float			y_rounded;
	// void			*img_texture[2];

	// img_texture[0] = images->tridy;
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
			draw_texture_line(images->tridy, ray,(t_texture_line){.dir=EAST,
				.screen_coor={.x=ray_index}, .texture=images->map_texture_E});
		}
		else
		{
			draw_texture_line(images->tridy, ray,(t_texture_line){.dir=WEST,
				.screen_coor={.x=ray_index}, .texture=images->map_texture_W});
		}
	}
	if (ray.colision_point.y >= (y_rounded - MARGIN_BASE) && ray.colision_point.y <= (y_rounded + MARGIN_BASE))
	{
		if (player.pos.y < ray.colision_point.y) //* SUR
		{
			draw_texture_line(images->tridy, ray,(t_texture_line){.dir=SOUTH,
				.screen_coor={.x=ray_index}, .texture=images->map_texture_S});
		}
		else // NORTE
		{
			draw_texture_line(images->tridy, ray,(t_texture_line){.dir=NORTH,
				.screen_coor={.x=ray_index}, .texture=images->map_texture_N});
		}
	}
}
