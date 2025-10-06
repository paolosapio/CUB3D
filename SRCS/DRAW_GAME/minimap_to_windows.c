/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_to_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:21:07 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 16:20:19 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

void	sand_rock_to_win(mlx_t *mlx, t_map *map, t_images *images, int slider)
{
	int	x;
	int	y;

	y = -1;
	while (map->array[++y])
	{
		slider++;
		x = -1;
		while (map->array[y][++x])
		{
			if (map->array[y][x] == '1')
			{
				mlx_image_to_window(mlx, images->map_rock,
					map->draw_offset.x + x * map->tile_size,
					map->draw_offset.y + y * map->tile_size);
			}
			else if (ft_strchr("NSWE0", map->array[y][x]) != NULL)
			{
				mlx_image_to_window(mlx, images->map_sand,
					map->draw_offset.x + x * map->tile_size,
					map->draw_offset.y + y * map->tile_size);
			}
		}
	}
}

void	minimap_images_to_window(mlx_t *mlx, t_map *map, t_images *images)
{
	int	slider;

	slider = 0;
	mlx_resize_image(images->map_sand, map->tile_size, map->tile_size);
	mlx_resize_image(images->map_rock, map->tile_size, map->tile_size);
	transparentator(127, images->map_sand);
	transparentator(127, images->map_rock);
	transparentator(100, images->mirilla);
	mlx_image_to_window(mlx, images->background_map, 0, 0);
	sand_rock_to_win(mlx, map, images, slider);
	mlx_image_to_window(mlx, images->map_ray, map->draw_offset.x,
		map->draw_offset.y);
	images_resizeitor(images, map->tile_size, 8);
}
