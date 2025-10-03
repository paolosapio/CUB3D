/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:23:38 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 00:26:08 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include "t_game.h"
#include "../REFRESH_GAME/refresh_game.h"
#include "../TOOLS_GRAPHICS/tools_graphics.h"

// player_v_angle : player_vision_angle

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

void	init_camera(t_game *game, t_coor player_coor, float player_v_angle)
{
	const float	x_pos_in_screen_aux = (float)(SCREEN * game->tile_size) / WIDTH;
	t_camera	c;

	init_struct_camera(&c, player_coor, x_pos_in_screen_aux, player_v_angle);
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
		check_wall_texture(c.ray, game->player,
			&game->images, c.x_pos_in_screen);
		c.x_pos_in_screen++;
	}
	bresenham_algorithm(game->images.map_ray,
		(t_segment){player_coor, game->player.end, 0},
		ft_color(255, 255, 255, 255), game->tile_size);
}
