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

#include "cub3d.h"

void	paint_direction_player(mlx_image_t *map_player, t_player *player, int size_of_tile)
{
	clean_image(map_player);
	bresenham_algorithm(map_player, 
		//LA DIRECION:
		//p1_player
		player->pos.x * (size_of_tile) + (size_of_tile / 2),
		player->pos.y * (size_of_tile) + (size_of_tile / 2),

		//p2_player
		player->end.x * size_of_tile + (size_of_tile / 2) + 1,
		player->end.y * size_of_tile + (size_of_tile / 2) + 1);
	// rescrivir con las nuevas coordinadas:
	paint_player(map_player, player->pos.x, player->pos.y, PLAYER_MAP_COLOR);
	
}