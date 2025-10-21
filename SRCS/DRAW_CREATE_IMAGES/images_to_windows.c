/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:57:14 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 23:11:21 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_create_images.h"

/**
 * @brief Loads on screen some of the images that belong to the 3d part of the
 * game. Mainly the ones that only have 1 or 2 frames.
 * @param game 
 */
void	tridy_images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.fauna[0], 0, 0);
	mlx_image_to_window(game->mlx, game->images.fauna[1], 0, 0);
	mlx_image_to_window(game->mlx, game->images.ambient, 0, 0);
	mlx_image_to_window(game->mlx, game->images.gradient_bgr, 0, 0);
	mlx_image_to_window(game->mlx, game->images.tridy, 0, 0);
}

/**
 * @brief puts on screen the kelas images.
 */
void	kelas_images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images.kelas_open, 0, 0);
	mlx_image_to_window(game->mlx, game->images.kelas_closed, 0, 0);
	mlx_image_to_window(game->mlx, game->images.kelas_sx, 0, 0);
	mlx_image_to_window(game->mlx, game->images.kelas_dx, 0, 0);
	mlx_image_to_window(game->mlx, game->images.kelas_up[0], 0, 0);
	mlx_image_to_window(game->mlx, game->images.kelas_up[1], 0, 0);
}

/**
 * @brief Puts every single image onto the screen. Hides some of then, resizes
 * others... layer by layer it visually creates the game.
 */
void	images_to_window(t_game *game)
{
	tridy_images_to_window(game);
	array_to_win(game->mlx, game->images.bubble_array, 20);
	kelas_images_to_window(game);
	mlx_image_to_window(game->mlx, game->images.mirilla,
		WIDTH / 2 - 10, HEIGHT / 2 - 10);
	mlx_image_to_window(game->mlx, game->images.waves[0], -400, 0);
	mlx_image_to_window(game->mlx, game->images.waves[1], -800, 0);
	minimap_images_to_window(game->mlx, &game->map, &game->images);
	array_to_win(game->mlx, game->images.greco_map, 8);
	mlx_image_to_window(game->mlx, game->images.info, 0, 0);
	hide_images(&game->images);
	array_to_win(game->mlx, game->images.frame, 6);
	mlx_image_to_window(game->mlx, game->images.start[0], 0, 0);
	mlx_image_to_window(game->mlx, game->images.start[1], 0, 0);
}
