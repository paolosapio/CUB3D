/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:18:48 by psapio            #+#    #+#             */
/*   Updated: 2025/10/21 23:53:17 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_create_images.h"

/**
 * @brief changes the transparency of an mlx_image_t pixel by pixel.
 */
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

/**
 * @brief resizes all the greco images to fit tile_size.
 */
void	greco_minimap_resizeitor(t_images *images, int tile_size, int n_images)
{
	int	i;

	i = 0;
	while (i < n_images)
	{
		mlx_resize_image(images->greco_map[i], tile_size, tile_size);
		i++;
	}
}

/**
 * @brief Hides some of the images that were put on screen but that are not
 * supposed to be seen right at the start.
 */
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

/**
 * @brief puts on the window and hides an array of images. Used to load all the
 * animation frames.
 */
void	array_to_win(mlx_t *mlx, mlx_image_t **array_imgs, int frames_times)
{
	int	i;

	i = 0;
	while (i < frames_times)
	{
		mlx_image_to_window(mlx, array_imgs[i], 0, 0);
		array_imgs[i]->enabled = false;
		++i;
	}
}
