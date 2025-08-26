#include "init_game.h"

// mlx_image_t	*create_greco_minimap(mlx_t *mlx, t_map *map)
// {
// 	mlx_image_t	*map_greco;

// 	map_greco = mlx_new_image(mlx, map->longest_line * map->tile_size, map->map_len * map->tile_size);
// 	paint_player(map->tile_size, map_greco, map->player_pointer->pos, PLAYER_MAP_COLOR);
// 	return (map_greco);
// }

mlx_image_t	*create_ray_minimap(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*map_ray;

	map_ray = mlx_new_image(mlx, map->longest_line * map->tile_size, map->map_len * map->tile_size);
	bresenham_algorithm(map_ray, 
	//LA DIRECION:
		//p1_player
		map->player_pointer->pos.x * (map->tile_size) + (map->tile_size / 2),
		map->player_pointer->pos.y * (map->tile_size) + (map->tile_size / 2),

		//p2_player
		map->player_pointer->end.x * map->tile_size + (map->tile_size / 2) + 1,
		map->player_pointer->end.y * map->tile_size + (map->tile_size / 2) + 1);
	return (map_ray);
}


mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	int slider = 0;
	t_int_coor coor_map;

	mlx_image_t	*img_minimap;

	img_minimap = mlx_new_image(mlx, map->longest_line * map->tile_size, map->map_len * map->tile_size);
	y = -1;
	while (map->array[++y])
	{
		slider++;
		x = -1;
		while (map->array[y][++x])
		{
			coor_map.x = x;
			coor_map.y = y;
			if (map->array[y][x] == '1')
				paint_tile(map->tile_size, img_minimap, coor_map, 0xFFFFFF99);
			else if (ft_strchr("NSWE0", map->array[y][x]) != NULL)
				paint_tile(map->tile_size, img_minimap, coor_map, 0x00000099);
		}
	}
	return (img_minimap);
}

mlx_image_t	*create_sky(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	(void)map;
	mlx_image_t	*img_sky = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	
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
	
	mlx_image_t	*img_floor = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
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