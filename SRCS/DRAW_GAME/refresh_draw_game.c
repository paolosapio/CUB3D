/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:09:48 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/08/20 19:35:47 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

void	refresh_draw_greco(mlx_image_t *map_greco, t_player *player, t_map *map)
{
	map_greco->instances->x = ((player->pos.x * map->tile_size) - (map->tile_size / 2)) + map->map_draw_offset.x;
	map_greco->instances->y = ((player->pos.y * map->tile_size) - (map->tile_size / 2)) + map->map_draw_offset.y;

	// map_greco->instances->x = (player->pos.x * tile_size) - tile_size / 2;
	// map_greco->instances->y = (player->pos.y * tile_size) - tile_size / 2;

	// rescrivir con las nuevas coordinadas:

}

void	refresh_draw_ray(mlx_image_t *map_player, t_player *player, int tile_size)
{
	clean_image(map_player);
	bresenham_algorithm(map_player, 
		//LA DIRECION:
		//p1_player
		player->pos.x * (tile_size),
		player->pos.y * (tile_size),

		//p2_player
		player->end.x * tile_size + 1,
		player->end.y * tile_size + 1);
	// rescrivir con las nuevas coordinadas:
}