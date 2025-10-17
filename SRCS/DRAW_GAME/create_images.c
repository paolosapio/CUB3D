/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:53:42 by psapio            #+#    #+#             */
/*   Updated: 2025/10/12 10:28:44 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

/**
 * @brief Creates and returns an empty mlx_image_t with the specified measures
 * 
 * @param mlx the mlx instance needed to call mlx_new_image.
 * @param width the width of the new image.
 * @param height the height of the new image.
 */
mlx_image_t	*create_empty_img(mlx_t *mlx, int width, int height)
{
	mlx_image_t	*map_ray;

	map_ray = mlx_new_image(mlx, width + 1, height + 1);
	return (map_ray);
}

/**
 * @brief Creates the minimap background, a semi transparent black background
 * that covers all the screen.
 */
mlx_image_t	*create_background_map(mlx_t *mlx)
{
	int			x;
	int			y;
	mlx_image_t	*img_sky;

	img_sky = mlx_new_image(mlx, WIDTH, HEIGHT);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img_sky, x, y, 0x00000099);
		}
	}
	return (img_sky);
}
