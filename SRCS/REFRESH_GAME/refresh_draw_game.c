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

#include "refresh_game.h"

void	refresh_draw_greco(mlx_image_t *map_greco, t_player *player, t_map *map)
{
	map_greco->instances->x = ((player->pos.x * g_size_tile) - (g_size_tile / 2)) + map->map_draw_offset.x;
	map_greco->instances->y = ((player->pos.y * g_size_tile) - (g_size_tile / 2)) + map->map_draw_offset.y;
}

void	refresh_draw_ray(mlx_image_t *map_player, t_player *player, int g_size_tile)
{
	(void)player;
	(void)g_size_tile;
	clean_image(map_player);
	// rescrivir con las nuevas coordinadas:
}

