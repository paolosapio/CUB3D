/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:09:48 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/08/11 23:00:28 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void	paint_direction(mlx_image_t	*img_minimap, int x_map, int y_map, int32_t color)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (y++ <= size_of_tile)
// 	{
// 		x = -1;

// 		mlx_put_pixel(img_minimap, x + (size_of_tile / 2) + (x_map * size_of_tile), y - size_of_tile + (y_map * size_of_tile), color);
// 	}
// }

void	paint_tile(mlx_image_t	*img_minimap, int x_map, int y_map, int32_t color)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= size_of_tile)
	{
		x = -1;
		while (++x <= size_of_tile)
		{
			mlx_put_pixel(img_minimap, x + (x_map* size_of_tile), y + (y_map* size_of_tile), color);
		}
	}
}

mlx_image_t	*create_player_minimap(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*map_player;

	map_player = mlx_new_image(mlx, map->longest_line * size_of_tile, map->map_len * size_of_tile);
	paint_tile(map_player, map->player_pointer->pos.x, map->player_pointer->pos.y, 0xFF6600FF);
	bresenham_algorithm(map_player, 
	//LA DIRECION:
		//p1_player
		map->player_pointer->pos.x * (size_of_tile) + (size_of_tile / 2),
		map->player_pointer->pos.y * (size_of_tile) + (size_of_tile / 2),

		//p2_player
		map->player_pointer->end.x * size_of_tile + (size_of_tile / 2) + 1,
		map->player_pointer->end.y * size_of_tile + (size_of_tile / 2) + 1);
	return (map_player);
}


mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	int slider = 0;

	mlx_image_t	*img_minimap;

	img_minimap = mlx_new_image(mlx, map->longest_line * size_of_tile, map->map_len * size_of_tile);
	y = -1;
	while (map->array[++y])
	{
		slider++;
		x = -1;
		while (map->array[y][++x])
		{
			if (map->array[y][x] == '1')
			{
				paint_tile(img_minimap, x, y, 0xFFFFFF99);
			}
			else if (ft_strchr("NSWE0", map->array[y][x]) != NULL)
				paint_tile(img_minimap, x, y, 0x00000099);
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

//TODO: Hacer que no se deforme la imagen con mapas muy largos o anchos.
//* Usar la misma relación que el mapa pero si es muy grande mostrar solo
//* la parte en la que se encuentre el usuario y que se adapte en base a su posición.
void	draw_game(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
	mlx_image_to_window(game->mlx, game->images.minimap, 0, 0);
	mlx_image_to_window(game->mlx, game->images.map_player, 0, 0);
}