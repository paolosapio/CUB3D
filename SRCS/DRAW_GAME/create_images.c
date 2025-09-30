/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:53:42 by psapio            #+#    #+#             */
/*   Updated: 2025/09/30 21:43:30 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

mlx_image_t	*create_empty_img(mlx_t *mlx, int width, int height)
{
	mlx_image_t	*map_ray;

	map_ray = mlx_new_image(mlx, width, height);
	return (map_ray);
}

mlx_image_t	*create_background_map(mlx_t *mlx, t_map *map)
{
	int			x;
	int			y;
	mlx_image_t	*img_sky;

	(void)map;
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
