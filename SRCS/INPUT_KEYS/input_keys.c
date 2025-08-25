
#include "input_keys.h"
#include "libft.h"
#include "../MOVEMENTS/movements.h"

void	special_keys(mlx_key_data_t keydata, void *params)
{
	t_game *game;
	(void)keydata;
	game = (t_game *)params;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_M) == true)
	{
		game->images.minimap->enabled -= 1;
		game->images.map_greco->enabled -= 1;
		game->images.map_ray->enabled -= 1;
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		{
			game->player.key_is_released = true;
		}
}

#define MOUSE_LIMIT_RANGE 50
void mouse_movements(double mouse_x, double mouse_y, void *params)
{
	t_game *game;
	static double first_step_x = 0;

	(void)mouse_y;
	game = (t_game *)params;
	// if (mouse_x > WIDTH - MOUSE_LIMIT_RANGE)
	// 	mlx_set_mouse_pos(game->mlx, 51, HEIGHT / 2);
	// else if (mouse_x <= MOUSE_LIMIT_RANGE)
	// 	mlx_set_mouse_pos(game->mlx, WIDTH - 51, HEIGHT / 2);
	// if (mouse_y <= MOUSE_LIMIT_RANGE || mouse_y >= HEIGHT - MOUSE_LIMIT_RANGE)
	// 	mlx_set_mouse_pos(game->mlx, mouse_x, HEIGHT / 2);
	// mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	if (mouse_x < first_step_x)
	{
		change_player_rotation(&game->player, game->player.vision_angle - 1);
	}
	else if (mouse_x > first_step_x)
	{
		change_player_rotation(&game->player, game->player.vision_angle + 1);
	}
	first_step_x = mouse_x;
	refresh_draw_ray(game->images.map_ray, &game->player, game->map.size_of_tile);
}


void await_user_input(t_game *game)
{
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);
	mlx_loop_hook(game->mlx, &movements_player, game);
	mlx_loop(game->mlx);
}