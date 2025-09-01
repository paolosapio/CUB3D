#include "draw_game.h"

void	image_print_ordereneitor(t_images *images)
{
	//mlx_set_instance_depth(images-> , 1);
	//mlx_set_instance_depth(images-> , 2);
	mlx_set_instance_depth(images->sky->instances, 0);
	mlx_set_instance_depth(images->floor->instances, 0);
	mlx_set_instance_depth(images->mirilla->instances, 1);

	mlx_set_instance_depth(images->background_map->instances, 1);
	mlx_set_instance_depth(images->minimap->instances , 3);
	mlx_set_instance_depth(images->map_sand->instances, 3);
	mlx_set_instance_depth(images->map_rock->instances, 3);
	// mlx_set_instance_depth(images->map_ray->instances , 9);
	// mlx_set_instance_depth(images->map_greco->instances, 5);
}

void	images_to_window(t_game *game)
{
	t_int_coor start_to_paint;

	start_to_paint.x = game->map.map_draw_offset.x;
	start_to_paint.y = game->map.map_draw_offset.y;

	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
	mlx_image_to_window(game->mlx, game->images.background_map, 0, 0);
	mlx_image_to_window(game->mlx, game->images.minimap, start_to_paint.x, start_to_paint.y);
	mlx_image_to_window(game->mlx, game->images.map_ray, start_to_paint.x, start_to_paint.y);
	mlx_resize_image(game->images.map_greco, g_size_tile, g_size_tile);
	mlx_image_to_window(game->mlx, game->images.map_greco, 0, 0);

	image_print_ordereneitor(&game->images);
}