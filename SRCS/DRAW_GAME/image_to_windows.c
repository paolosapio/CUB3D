#include "draw_game.h"

void	minimap_images_to_window(mlx_t *mlx, t_map *map, t_images *images)
{
	int			x;
	int			y;
	int			slider = 0;

	mlx_resize_image(images->map_sand, g_size_tile, g_size_tile);
	mlx_resize_image(images->map_rock, g_size_tile, g_size_tile);

	y = -1;
	while (map->array[++y])
	{
		slider++;
		x = -1;
		while (map->array[y][++x])
		{
			// coor_map.x = x;
			// coor_map.y = y;
			if (map->array[y][x] == '1')
			{
				mlx_image_to_window(mlx, images->map_rock, map->map_draw_offset.x + x * g_size_tile, map->map_draw_offset.y + y * g_size_tile);
				printf("MAP_ROCK: %ld\n", images->map_rock->count);
				printf("-> %d\n", images->map_rock->instances[images->map_rock->count - 1].z);
			}
			else if (ft_strchr("NSWE0", map->array[y][x]) != NULL)
			{
				mlx_image_to_window(mlx, images->map_sand, map->map_draw_offset.x + x * g_size_tile, map->map_draw_offset.y + y * g_size_tile);
				//printf("MAP_SAND: %d\n", image->map_sand->instances->z);
			}
		}
	}

	mlx_image_to_window(mlx, images->minimap, map->map_draw_offset.x, map->map_draw_offset.y);
	mlx_image_to_window(mlx, images->map_ray, map->map_draw_offset.x, map->map_draw_offset.y);
}

void	image_print_ordereneitor(t_images *images)
{
	//mlx_set_instance_depth(images-> , 1);
	//mlx_set_instance_depth(images-> , 2);

	mlx_set_instance_depth(images->sky->instances, 0);
	mlx_set_instance_depth(images->floor->instances, 0);
	//mlx_set_instance_depth(images->mirilla->instances, 1);
	mlx_set_instance_depth(images->tridy->instances, 1);
	mlx_set_instance_depth(images->background_map->instances, 1);
	mlx_set_instance_depth(images->minimap->instances , 3);
	mlx_set_instance_depth(images->map_sand->instances, 3);
	mlx_set_instance_depth(images->map_rock->instances, 3);
	// mlx_set_instance_depth(images->map_ray->instances , 9);
	// mlx_set_instance_depth(images->map_greco->instances, 5);
}

void	images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
	mlx_image_to_window(game->mlx, game->images.tridy, 0, 0);
	mlx_image_to_window(game->mlx, game->images.background_map, 0, 0);
	minimap_images_to_window(game->mlx, &game->map, &game->images);

	mlx_resize_image(game->images.map_greco, g_size_tile, g_size_tile);
	mlx_image_to_window(game->mlx, game->images.map_greco, 0, 0);

	//image_print_ordereneitor(&game->images);


}