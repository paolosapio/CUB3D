/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:13:57 by anfi              #+#    #+#             */
/*   Updated: 2025/10/07 21:50:04 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define FLOAT_ERROR_MARGIN 0.0001

/**
 * @brief Checks wether the collision happened on a north or south wall based on
 * the collision axys.
 * 
 * @param ray 
 * @param game 
 * @param ray_i 
 * @param rounded 
 */
void	check_north_south(t_ray ray, t_game *game, float ray_i, t_coor rounded)
{
	if (ray.colision_point.y >= (rounded.y - FLOAT_ERROR_MARGIN)
		&& ray.colision_point.y <= (rounded.y + FLOAT_ERROR_MARGIN))
	{
		if (game->player.pos.y < ray.colision_point.y)
		{
			draw_texture_line(game->images.tridy, ray,
				(t_texture_line){
				.dir = SOUTH,
				.screen_coor = {.x = ray_i},
				.texture = game->images.map_texture_S
			});
		}
		else
		{
			draw_texture_line(game->images.tridy, ray,
				(t_texture_line){
				.dir = NORTH,
				.screen_coor = {.x = ray_i},
				.texture = game->images.map_texture_N
			});
		}
	}
}

void	check_east_west(t_ray ray, t_game *game, float ray_i, t_coor rounded)
{
	if (ray.colision_point.x >= (rounded.x - FLOAT_ERROR_MARGIN)
		&& ray.colision_point.x <= (rounded.x + FLOAT_ERROR_MARGIN))
	{
		if (game->player.pos.x < ray.colision_point.x)
		{
			draw_texture_line(game->images.tridy, ray,
				(t_texture_line){
				.dir = EAST,
				.screen_coor = {.x = ray_i},
				.texture = game->images.map_texture_E
			});
		}
		else
		{
			draw_texture_line(game->images.tridy, ray,
				(t_texture_line){
				.dir = WEST,
				.screen_coor = {.x = ray_i},
				.texture = game->images.map_texture_W
			});
		}
	}
}
