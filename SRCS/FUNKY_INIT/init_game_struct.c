#include "cub3d.h"

#include <math.h>


void init_game_struct(t_game *game, t_parser_map *parser_map)
{
//	t_player *player;

//	player = game->map.player;
	game->mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", false);

	//for (int i = -50; i < 50; i++)
	// bresenham_algorithm(game, player->pos.x * size_of_tile, player->pos.y * size_of_tile,
	// 	player->end.x * size_of_tile, player->end.y * size_of_tile);

	init_images(game->mlx, &game->map, &game->images);
	destroy_parser_map(parser_map);
}

// https://youtu.be/CceepU1vIKo?si=_or3vLnpKW5_1CRX&t=555