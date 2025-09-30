/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_draw_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:09:48 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/09/30 21:49:01 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "refresh_game.h"

void	refresh_draw_greco(mlx_image_t *map_greco, t_player *player, t_map *map)
{
	map_greco->instances->x = ((player->pos.x * map->tile_size) - (map->tile_size / 2)) + map->map_draw_offset.x;
	map_greco->instances->y = ((player->pos.y * map->tile_size) - (map->tile_size / 2)) + map->map_draw_offset.y;
}

void	clean_game_images(t_images *images)
{
	clean_image(images->map_ray);
	clean_image(images->tridy);
}

