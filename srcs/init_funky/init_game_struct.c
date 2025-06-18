#include "cub3d.h"

t_game init_game_struct(t_map *map)
{
	t_game game;

	game.mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", true);
	game.images = init_images(game.mlx);
	game.map = map;
	return (game);
}
