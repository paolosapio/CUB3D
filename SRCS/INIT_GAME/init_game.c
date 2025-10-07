/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:43:49 by psapio            #+#    #+#             */
/*   Updated: 2025/10/07 22:38:54 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

// init_map_foundations nombre provvisional
// de una funcion que crea datos para que el mapa sea ok

void	init_map_foundations(t_map *map, t_game *game)
{
	game->tile_size = tile_size_calculator(map->map_len, map->longest_line);
	map->tile_size = game->tile_size;
	map->draw_offset.x = (WIDTH - map->longest_line * game->tile_size) / 2;
	map->draw_offset.y = (HEIGHT - map->map_len * game->tile_size) / 2.0;
}

void	init_game(t_game *game, t_parser_map *parser_map)
{
	game->map_is_closed = true;
	init_map_foundations(&game->map, game);
	//mlx_set_setting(MLX_FULLSCREEN, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", false);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	load_non_png_images(game->mlx, &game->map, &game->images, parser_map);
	load_textures(game->mlx, &game->images, parser_map);
	load_images(game->mlx, &game->images);
	destroy_parser_map(parser_map);
	images_to_window(game);
	init_camera(game, game->player.pos, game->player.vision_angle);
}

// 29 - mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED); 
//?Poner en un boton opcional