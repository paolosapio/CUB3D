#include "cub3d.h"

void init_game_struct(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", true);
	init_images(game->mlx, &game->map, &game->images);
}
