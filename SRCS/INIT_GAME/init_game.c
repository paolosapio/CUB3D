#include "init_game.h"


// init_map_foundations nombre provvisional de una funcion que crea datos para que el mapa sea ok
void	init_map_foundations(t_map *map) 
{
	map->tile_size = tile_size_calculator(map->map_len, map->longest_line);

	map->map_draw_offset.x = (WIDTH - map->longest_line * map->tile_size) / 2;
	map->map_draw_offset.y = (HEIGHT - map->map_len * map->tile_size) / 2;
	printf("tile_size = %d\n", map->tile_size);
}
void	init_game(t_game *game, t_parser_map *parser_map)
{
	init_map_foundations(&game->map);
	game->mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", false);
	init_texture(game->mlx, &game->images);
	init_images(game->mlx, &game->map, &game->images);
	destroy_parser_map(parser_map);
	images_to_window(game);
}

