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

#define TILE_SIZE 4

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
void	draw_minimap(mlx_t *mlx, t_map map)
{
	int	x;
	int	y;
	t_player	player;
	
	mlx_image_t	*img_minimap = mlx_new_image(mlx, WIDTH, HEIGHT);
	y = -1;
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
		{
			if (map.map[y][x] == '1')
				draw_tile(img_minimap, x, y, 0xFFFFFF55);
				else if (map.map[y][x] == '0')
				draw_tile(img_minimap, x, y, 0x00000055);
				else if (map.map[y][x] == 'N')
				{
					player.pos.start[X] = x;
					player.pos.start[Y] = y;
					player.pos.end[X] = x;
					player.pos.end[Y] = y - 10;
					draw_tile(img_minimap, x, y, 0x000FFF55);
					mlx_put_pixel(img_minimap, player.pos.start[X] * TILE_SIZE, player.pos.start[Y] * TILE_SIZE, 0xFF0000FF);
					mlx_put_pixel(img_minimap, player.pos.end[X] * TILE_SIZE, player.pos.end[Y] * TILE_SIZE, 0xFF0000FF);
				}
		}
	}
	mlx_image_to_window(mlx, img_minimap, 10, 10);
}


void	draw_reticle(mlx_t *mlx, mlx_image_t *mirilla)
{
	// int a = 20;
	// int b = 20;

	// mlx_resize_image(mirilla, a, b);
	printf("mirilla? %p\n", mirilla);
	mlx_image_to_window(mlx, mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
}

void draw_sky(mlx_t *mlx, t_map map)
{
	int	x;
	int	y;
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
	mlx_image_to_window(mlx, img_sky, 0, 0);
}

void draw_floor(mlx_t *mlx, t_map map)
{
	int	x;
	int	y;
	mlx_image_t	*img_floor = mlx_new_image(mlx, 640, 480 / 2);
	
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img_floor, x, y, 0x968C6E);
		}
	}
	mlx_image_to_window(mlx, img_floor, 0, HEIGHT / 2);
}

void	draw_game(mlx_t *mlx, t_map map, t_images images)
{
	draw_sky(mlx, map);
	draw_floor(mlx, map);
	draw_minimap(mlx, map);
	draw_reticle(mlx, images.mirilla);
}