#include "init_game.h"

//TODO: Hacer que no se deforme la imagen con mapas muy largos o anchos.
//* Usar la misma relación que el mapa pero si es muy grande mostrar solo
//* la parte en la que se encuentre el usuario y que se adapte en base a su posición.
void	put_images_to_window(t_game *game)
{
		t_int_coor start_to_paint;

	start_to_paint.x = (WIDTH - game->map.longest_line *game->map.tile_size) / 2;
	start_to_paint.y = (HEIGHT - game->map.map_len * game->map.tile_size) / 2;
	game->map.map_draw_offset.x = start_to_paint.x;
	game->map.map_draw_offset.y = start_to_paint.y;

	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
	mlx_image_to_window(game->mlx, game->images.background_map, 0, 0);
	mlx_image_to_window(game->mlx, game->images.minimap, start_to_paint.x, start_to_paint.y);
	mlx_image_to_window(game->mlx, game->images.map_ray, start_to_paint.x, start_to_paint.y);
	mlx_resize_image(game->images.map_greco, game->map.tile_size, game->map.tile_size);
	mlx_image_to_window(game->mlx, game->images.map_greco, 0, 0);
}

int	tile_size_calculator(int map_height, int map_width)
{
	printf("long line:%d\n", map_width);
	printf("map_len:%d\n", map_height);
	if (map_width >= map_height)
	{
		if (HEIGHT < (WIDTH / map_width) * map_height)
			return (HEIGHT / map_height);
		return (WIDTH / map_width);
	}
	return (HEIGHT / map_height);

}
void	init_colors(t_colors *colors)
{
	colors->red = 255;
	colors->green = 255;
	colors->blue = 255;
	colors->alpha = 255;
}

void	init_images(mlx_t* mlx, t_map *map, t_images *images)
{
	mlx_texture_t	*mirilla;
	mlx_texture_t	*greco;
	
	map->tile_size = tile_size_calculator(map->map_len, map->longest_line);
	printf("tile_size = %d\n", map->tile_size);
	mirilla = mlx_load_png("PNG/mirilla.png");
	greco = mlx_load_png("PNG/greco.png");

	images->mirilla = mlx_texture_to_image(mlx, mirilla);
	images->map_greco = mlx_texture_to_image(mlx, greco);
	images->minimap = create_minimap(mlx, map);
	images->background_map = create_background_map(mlx, map);
	images->floor = create_floor(mlx, map);
	images->sky = create_sky(mlx, map);
	images->map_ray = create_ray_minimap(mlx, map);
	images->minimap->enabled = true;
	images->map_ray->enabled = true;
	// images->map_greco->enabled = false;
	mlx_delete_texture(mirilla);
	mlx_delete_texture(greco);
}

void	init_game(t_game *game, t_parser_map *parser_map)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", false);
	init_images(game->mlx, &game->map, &game->images);
	destroy_parser_map(parser_map);
	put_images_to_window(game);
}

