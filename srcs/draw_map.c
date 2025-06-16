/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:09:48 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/06/16 20:59:41 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define TILE_SIZE 20

void	draw_tile(mlx_image_t *image, int map_x, int map_y, uint32_t color)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= TILE_SIZE)
	{
		x = -1;
		while (++x <= TILE_SIZE)
			mlx_put_pixel(image, (map_x * TILE_SIZE) + x, (map_y * TILE_SIZE) + y, color);
	}
}

void	draw_map(mlx_t *mlx, t_map map)
{
	int	x;
	int	y;
	mlx_image_t	*image = mlx_new_image(mlx, WIDTH, HEIGHT);

	y = -1;
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
		{
			if (map.map[y][x] == '1')
				draw_tile(image, x, y, 0xFFFFFFFF);
			else if (map.map[y][x] == '0')
				draw_tile(image, x, y, 0x000000FF);
			else if (map.map[y][x] == 'N')
				draw_tile(image, x, y, 0x000FFFFF);
		}
	}
	mlx_image_to_window(mlx, image, 0, 0);
}