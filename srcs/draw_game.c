/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:09:48 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/06/23 20:47:34 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;

	mlx_image_t	*img_minimap = mlx_new_image(mlx, map->longest_line, map->map_len);
	y = -1;
	while (map->map_array[++y])
	{
		x = -1;
		while (map->map_array[y][++x])
		{
			if (map->map_array[y][x] == '1')
				mlx_put_pixel(img_minimap, x, y, 0xFFFFFF99);
			else if (map->map_array[y][x] == '0')
				mlx_put_pixel(img_minimap, x, y, 0x00000099);
			else if (map->map_array[y][x] == 'N')
				// mlx_put_pixel(img_minimap, x, y, 0xFF000099);
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
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
	printf("width: %u height: %u\n", game->images.minimap->width, game->images.minimap->height);
	mlx_resize_image(game->images.minimap, WIDTH, HEIGHT);
	printf("width: %u height: %u\n", game->images.minimap->width, game->images.minimap->height);
	mlx_image_to_window(game->mlx, game->images.minimap,
		WIDTH / 2 - (WIDTH / 2),
		HEIGHT / 2 - (HEIGHT / 2));  //? celda x == y
	// mlx_image_to_window(game->mlx, game->images.minimap, 0, 0); //?  celda x != y 
}