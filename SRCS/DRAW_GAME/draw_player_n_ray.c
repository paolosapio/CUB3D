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

void	draw_player_and_ray(mlx_image_t *map_player, t_player *player, int size_of_tile)
{
	clean_image(map_player);
	bresenham_algorithm(map_player, 
		//LA DIRECION:
		//p1_player
		player->pos.x * (size_of_tile),
		player->pos.y * (size_of_tile),

		//p2_player
		player->end.x * size_of_tile + 1,
		player->end.y * size_of_tile + 1);
	// rescrivir con las nuevas coordinadas:
	paint_player(size_of_tile, map_player, player->pos, PLAYER_MAP_COLOR);
}