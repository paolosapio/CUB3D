/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_leys_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:21:25 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 16:21:53 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"

void	minimap_closer(t_game *game, bool info_img_state)
{
	game->images.greco_map[game->player.greco_map_dir]->enabled = false;
	game->images.map_ray->enabled = false;
	game->images.background_map->enabled = false;
	game->images.map_sand->enabled = false;
	game->images.map_rock->enabled = false;
	game->images.info->enabled = info_img_state;
}

void	tab_mapeitor(t_game	*game)
{
	game->images.info->enabled = false;
	game->images.greco_map[game->player.greco_map_dir]->enabled -= 1;
	game->map_is_closed -= 1;
	game->images.map_ray->enabled -= 1;
	game->images.background_map->enabled -= 1;
	game->images.map_sand->enabled -= 1;
	game->images.map_rock->enabled -= 1;
}
