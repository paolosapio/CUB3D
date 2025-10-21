/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_to_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:21:07 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 23:07:56 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_create_images.h"

/**
 * @brief Draws the minimap. Once the sand and rock images have been loaded, we
 * iterate over the map array, put on screen a one of the images,
 * taking into consideration the x and y coordinates and the tile_size.
 */
void	sand_rock_to_win(mlx_t *mlx, t_map *map, t_images *images)
{
	int	x;
	int	y;

	y = -1;
	while (map->array[++y])
	{
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

/**
 * @brief Makes the minimap, loading tile by tile, image by image.
 * Many z instances.
 */
void	minimap_images_to_window(mlx_t *mlx, t_map *map, t_images *images)
{
	mlx_resize_image(images->map_sand, map->tile_size, map->tile_size);
	mlx_resize_image(images->map_rock, map->tile_size, map->tile_size);
	transparentator(127, images->map_sand);
	transparentator(127, images->map_rock);
	transparentator(100, images->mirilla);
	mlx_image_to_window(mlx, images->background_map, 0, 0);
	sand_rock_to_win(mlx, map, images);
	mlx_image_to_window(mlx, images->map_ray, map->draw_offset.x,
		map->draw_offset.y);
	greco_minimap_resizeitor(images, map->tile_size, 8);
}
