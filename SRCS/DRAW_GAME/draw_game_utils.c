/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:18:48 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 16:19:10 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

void	transparentator(int value_of_trasparence, mlx_image_t *image)
{
	unsigned int	i;

	i = 3;
	while (i < image->width * image->height * 4)
	{
		if (image->pixels[i] > value_of_trasparence)
			image->pixels[i] = value_of_trasparence;
		i += 4;
	}
}

void	images_resizeitor(t_images *images, int tile_size, int n_images)
{
	int	i;

	i = 0;
	while (i < n_images)
	{
		mlx_resize_image(images->greco_map[i], tile_size, tile_size);
		i++;
	}
}

void	hide_images(t_images *image)
{
	image->kelas_open->enabled = true;
	image->kelas_closed->enabled = false;
	image->kelas_sx->enabled = false;
	image->kelas_dx->enabled = false;
	image->kelas_up[0]->enabled = false;
	image->kelas_up[1]->enabled = false;
	image->info->enabled = false;
	image->background_map->enabled = false;
	image->map_rock->enabled = false;
	image->map_sand->enabled = false;
	image->map_ray->enabled = false;
}
