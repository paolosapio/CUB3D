/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:13:37 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:53:41 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	set_greco_icon(mlx_t *mlx, t_images *imgs)
{
	imgs->greco_texture = load_n_check_texture(mlx, imgs, "PNG/greco.png");
	mlx_set_icon(mlx, imgs->greco_texture);
	mlx_delete_texture(imgs->greco_texture);
}

void	load_textures(mlx_t *mlx, t_images *imgs, t_parser_map *parser_map)
{
	set_greco_icon(mlx, imgs);
	imgs->map_texture_n = load_n_check_texture(mlx, imgs, parser_map->path_s);
	imgs->map_texture_s = load_n_check_texture(mlx, imgs, parser_map->path_n);
	imgs->map_texture_e = load_n_check_texture(mlx, imgs, parser_map->path_w);
	imgs->map_texture_w = load_n_check_texture(mlx, imgs, parser_map->path_e);
}
