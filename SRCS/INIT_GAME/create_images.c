#include "init_game.h"

mlx_image_t	*create_player_minimap(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*map_player;

	map_player = mlx_new_image(mlx, map->longest_line * map->size_of_tile, map->map_len * map->size_of_tile);
	paint_player(map_player, map->player_pointer->pos.x, map->player_pointer->pos.y, PLAYER_MAP_COLOR);
	bresenham_algorithm(map_player, 
	//LA DIRECION:
		//p1_player
		map->player_pointer->pos.x * (map->size_of_tile) + (map->size_of_tile / 2),
		map->player_pointer->pos.y * (map->size_of_tile) + (map->size_of_tile / 2),

		//p2_player
		map->player_pointer->end.x * map->size_of_tile + (map->size_of_tile / 2) + 1,
		map->player_pointer->end.y * map->size_of_tile + (map->size_of_tile / 2) + 1);
	return (map_player);
}


mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	int slider = 0;

	mlx_image_t	*img_minimap;

	img_minimap = mlx_new_image(mlx, map->longest_line * map->size_of_tile, map->map_len * map->size_of_tile);
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