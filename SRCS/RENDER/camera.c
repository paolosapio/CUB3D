/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:23:38 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 22:24:53 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include "t_game.h"
#include "../REFRESH_GAME/refresh_game.h"
#include "../TOOLS_GRAPHICS/tools_graphics.h"

void	init_camera(t_game *game, t_coor player_coor, float player_vision_angle)
{
	t_coor		middle_screen_point;
	t_coor		l_screen_point;
	float		pixel_offset_cos;
	float		pixel_offset_sen;
	t_ray		ray;
	int			x_pos_in_screen;
	const float	x_pos_in_screen_aux = (float)(SCREEN * game->tile_size) / WIDTH;
	float		r;

	middle_screen_point.x = player_coor.x - cos(to_radians(player_vision_angle)) * DISTANCE_SCREEN;
	middle_screen_point.y = player_coor.y - sin(to_radians(player_vision_angle)) * DISTANCE_SCREEN;
	pixel_offset_cos = cos(to_radians(player_vision_angle - 90)) / WIDTH * SCREEN;
	pixel_offset_sen = sin(to_radians(player_vision_angle - 90)) / WIDTH * SCREEN;
	l_screen_point.x = (middle_screen_point.x - cos(to_radians(player_vision_angle - 90)) * HALF_SCREEN);
	l_screen_point.y = (middle_screen_point.y - sin(to_radians(player_vision_angle - 90)) * HALF_SCREEN);
	x_pos_in_screen = x_pos_in_screen_aux;
	while (x_pos_in_screen < WIDTH)
	{
		ray = raycasting(game->player.pos, l_screen_point, game->map);
		if (x_pos_in_screen % 5 == 0)
			bresenham_algorithm(game->images.map_ray, (t_segment){player_coor, ray.colision_point, 0}, ft_color(0, 0, 255, 100), game->tile_size);
		l_screen_point.x += pixel_offset_cos;
		l_screen_point.y += pixel_offset_sen;
		r = sqrtf((l_screen_point.x - player_coor.x) * (l_screen_point.x - player_coor.x) + (l_screen_point.y - player_coor.y) * (l_screen_point.y - player_coor.y));
		ray.colision_len /= r;
		check_wall_texture(ray, game->player, &game->images, x_pos_in_screen);
		x_pos_in_screen++;
	}
	bresenham_algorithm(game->images.map_ray, (t_segment){player_coor, game->player.end, 0}, ft_color(255, 255, 255, 255), game->tile_size);
}
