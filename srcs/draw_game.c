/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:09:48 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/06/23 17:46:13 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// #define TILE_SIZE 19

void	draw_tile(mlx_image_t *image, int map_x, int map_y, uint32_t color, int len_map_w)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y <= 640/len_map_w)
	{
		x = -1;
		while (++x <= 640/len_map_w)
			mlx_put_pixel(image, (map_x * (640/len_map_w)) + x, (map_y * (640/len_map_w)) + y, color);
	}
}
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	int len_map_w = map->longest_line;

	mlx_image_t	*img_minimap = mlx_new_image(mlx, WIDTH, HEIGHT);
	y = -1;
	while (map->map_array[++y])
	{
		x = -1;
		while (map->map_array[y][++x])
		{
			if (map->map_array[y][x] == '1')
				draw_tile(img_minimap, x, y, 0xFFFFFF55, len_map_w);
			else if (map->map_array[y][x] == '0')
				draw_tile(img_minimap, x, y, 0x00000055, len_map_w);
			else if (map->map_array[y][x] == 'N')
				draw_tile(img_minimap, x, y, 0x000FFF55, len_map_w);
		}
	}
	return (img_minimap);
}


mlx_image_t	*create_sky(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	(void)map;
	mlx_image_t	*img_sky = mlx_new_image(mlx, 640, 480 / 2);
	
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img_sky, x, y, 0x6D8196FF);
		}
	}
	return (img_sky);
}

mlx_image_t	*create_floor(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	mlx_image_t	*img_floor = mlx_new_image(mlx, 640, 480 / 2);
	(void)map;
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img_floor, x, y, 0x968C6E);
		}
	}
	return (img_floor);
}

void	draw_game(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.minimap, 0, 0);
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
}