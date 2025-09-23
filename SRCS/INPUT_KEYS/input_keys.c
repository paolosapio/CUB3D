
#include "input_keys.h"
#include "libft.h"
#include "../MOVEMENTS/movements.h"
#include "../RENDER/render.h"

void	special_keys(mlx_key_data_t keydata, void *params)
{
	t_game *game;
	
	game = (t_game *)params;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_M) == true)
	{
		game->images.minimap->enabled -= 1;
		game->images.map_greco->enabled -= 1;
		game->images.map_ray->enabled -= 1;
		game->images.background_map->enabled -= 1;
		game->images.map_sand->enabled -= 1;
		game->images.map_rock->enabled -= 1;
	}
	game->player.speed = NORMAL * (g_size_tile * 0.04);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		game->player.speed = TURBO * (g_size_tile * 0.04);
	if (keydata.key == MLX_KEY_W)
	{
		game->player.movements.key_w_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_w_is_down = false;
	}
	if (keydata.key == MLX_KEY_A)
	{
		game->player.movements.key_a_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_a_is_down = false;
	}
	if (keydata.key == MLX_KEY_S)
	{
		game->player.movements.key_s_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_s_is_down = false;
	}
	if (keydata.key == MLX_KEY_D)
	{
		game->player.movements.key_d_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_d_is_down = false;
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		game->player.movements.key_left_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_left_is_down = false;
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		game->player.movements.key_right_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_right_is_down = false;
	}

}

#define MOUSE_LIMIT_RANGE 50
void mouse_movements(double mouse_x, double mouse_y, void *params)
{
	t_game *game;
	static double first_step_x = 0;

	(void)mouse_y;
	game = (t_game *)params;
		// mlx_set_mouse_pos(game->mlx, mouse_x, HEIGHT / 2);
	// mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	if (mouse_x < first_step_x)
		change_player_rotation(&game->player, game->player.vision_angle - 1);
	else if (mouse_x > first_step_x)
		change_player_rotation(&game->player, game->player.vision_angle + 1);
	clean_game_images(&game->images);
	init_camera(game, game->player.pos, game->player.vision_angle);
	first_step_x = mouse_x;

}

void await_user_input(t_game *game)
{
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);
	mlx_loop_hook(game->mlx, &movements_player, game);
	mlx_loop(game->mlx);
}