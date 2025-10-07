/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:23:38 by psapio            #+#    #+#             */
/*   Updated: 2025/10/07 21:51:02 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include "t_game.h"
#include "../REFRESH_GAME/refresh_game.h"
#include "../TOOLS_GRAPHICS/tools_graphics.h"

void	init_struct_camera(t_camera *c, t_coor player_coor,
		float x_pos_in_screen_aux, float player_v_angle)
{
	c->middle_screen_point.x = player_coor.x
		- cos(to_radians(player_v_angle)) * DISTANCE_SCREEN;
	c->middle_screen_point.y = player_coor.y
		- sin(to_radians(player_v_angle)) * DISTANCE_SCREEN;
	c->pixel_offset_cos = cos(to_radians(player_v_angle - 90)) / WIDTH * SCREEN;
	c->pixel_offset_sen = sin(to_radians(player_v_angle - 90)) / WIDTH * SCREEN;
	c->l_screen_point.x = (c->middle_screen_point.x
			- cos(to_radians(player_v_angle - 90)) * HALF_SCREEN);
	c->l_screen_point.y = (c->middle_screen_point.y
			- sin(to_radians(player_v_angle - 90)) * HALF_SCREEN);
	c->x_pos_in_screen = x_pos_in_screen_aux;
}

#define N_FRAMES 16 // 360 / N_FRAMES; (22.5)

void	cangro_map_rotation(t_game	*game, float player_v_angle)
{
	const float	step = 360 / N_FRAMES;

	game->images.greco_map[game->player.greco_map_dir]->enabled = false;
	if (game->images.background_map->enabled == false)
		return ;
	if (player_v_angle >= 360.0 - step && player_v_angle <= 360)
		game->player.greco_map_dir = W_;
	else if (player_v_angle >= 0.0 && player_v_angle <= 0 + step)
		game->player.greco_map_dir = W_;
	else if (player_v_angle >= 45.0 - step && player_v_angle <= 45.0 + step)
		game->player.greco_map_dir = NW;
	else if (player_v_angle >= 90.0 - step && player_v_angle <= 90.0 + step)
		game->player.greco_map_dir = N_;
	else if (player_v_angle >= 135.0 - step && player_v_angle <= 135.0 + step)
		game->player.greco_map_dir = NE;
	else if (player_v_angle >= 180.0 - step && player_v_angle <= 180.0 + step)
		game->player.greco_map_dir = E_;
	else if (player_v_angle >= 225.0 - step && player_v_angle <= 225.0 + step)
		game->player.greco_map_dir = SE;
	else if (player_v_angle >= 270.0 - step && player_v_angle <= 270.0 + step)
		game->player.greco_map_dir = S_;
	else if (player_v_angle >= 315.0 - step && player_v_angle <= 315.0 + step)
		game->player.greco_map_dir = SW;
	game->images.greco_map[game->player.greco_map_dir]->enabled = true;
}

void	init_camera(t_game *game, t_coor player_coor, float player_v_angle)
{
	const float	x_pos_in_screen_aux = (float)(SCREEN * game->tile_size) / WIDTH;
	t_camera	c;

	init_struct_camera(&c, player_coor, x_pos_in_screen_aux, player_v_angle);
	cangro_map_rotation(game, player_v_angle);
	while (c.x_pos_in_screen < WIDTH)
	{
		c.ray = raycasting(game->player.pos, c.l_screen_point, game->map);
		if (c.x_pos_in_screen % 5 == 0)
			bresenham_algorithm(game->images.map_ray,
				(t_segment){player_coor, c.ray.colision_point, 0},
				ft_color(0, 0, 255, 100), game->tile_size);
		c.l_screen_point.x += c.pixel_offset_cos;
		c.l_screen_point.y += c.pixel_offset_sen;
		c.r = sqrtf((c.l_screen_point.x - player_coor.x)
				* (c.l_screen_point.x - player_coor.x)
				+ (c.l_screen_point.y - player_coor.y)
				* (c.l_screen_point.y - player_coor.y));
		c.ray.colision_len /= c.r;
		c.ray.vertical_line = HEIGHT / c.ray.colision_len;
		to_3d(c.ray, game, c.x_pos_in_screen);
		c.x_pos_in_screen++;
	}
}
