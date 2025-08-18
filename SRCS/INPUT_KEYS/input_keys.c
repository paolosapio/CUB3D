#include "cub3d.h"

void await_user_input()
{
	mlx_key_hook(game->mlx, &specia
	.l_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);

	mlx_loop_hook(game->mlx, &player_movements, game);
	mlx_loop(game->mlx);
}