/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:13:37 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 21:38:23 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_game.h"

/**
 * @brief Sets the greco icon. Nothing more, nothing else.
 */
void	set_greco_icon(mlx_t *mlx, t_images *imgs)
{
	imgs->greco_texture = load_n_check_texture(mlx, imgs, "PNG/greco.png");
	mlx_set_icon(mlx, imgs->greco_texture);
	mlx_delete_texture(imgs->greco_texture);
}

/**
 * @brief Loads the mlx_texture_t images (basically the wall textures received
 * in the .cub file) and since is something that needs a texture and not an
 * image, this function also sets the greco icon :D
 */
void	load_textures(mlx_t *mlx, t_images *imgs, t_parser_map *parser_map)
{
	set_greco_icon(mlx, imgs);
	imgs->map_texture_n = load_n_check_texture(mlx, imgs, parser_map->path_s);
	imgs->map_texture_s = load_n_check_texture(mlx, imgs, parser_map->path_n);
	imgs->map_texture_e = load_n_check_texture(mlx, imgs, parser_map->path_w);
	imgs->map_texture_w = load_n_check_texture(mlx, imgs, parser_map->path_e);
}
