
#include "../MOVEMENTS/movements.h"
#include "../RENDER/render.h"
#include "input_keys.h"
#include "libft.h"

void	special_keys(mlx_key_data_t keydata, void *params)
{
	t_game	*game;

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

	if (keydata.key == MLX_KEY_ENTER)
	{
		game->images.start_cover[0]->enabled = false;
		game->images.start_cover[1]->enabled = true;
	}

	if (keydata.key == MLX_KEY_LEFT_SHIFT)
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

#define SENSITIVITY 10

void	mouse_movements(double mouse_x, double mouse_y, void *params)
{
	t_game			*game;
	static double	first_step_x = WIDTH / 2;

	(void)mouse_y;
	game = (t_game *)params;
	if (mouse_x < first_step_x)
		change_player_rotation(&game->player, game->player.vision_angle
			- ((first_step_x - mouse_x) / SENSITIVITY));
	else if (mouse_x > first_step_x)
		change_player_rotation(&game->player, game->player.vision_angle
			+ ((mouse_x - first_step_x) / SENSITIVITY) + 1);
	else
		return ;
	clean_game_images(&game->images);
	init_camera(game, game->player.pos, game->player.vision_angle);
	first_step_x = mouse_x;
}

// MLX_RELEASE = 0,
// MLX_PRESS	= 1,
// MLX_MOUSE_BUTTON_LEFT	= 0,
// MLX_MOUSE_BUTTON_RIGHT	= 1,
void	mouse_buttons(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;
	(void)mods;
	game = (t_game *)param;
	printf("BUTTON %d %d\n", button, action);
	game->images.kelas_open->enabled = false;
	game->images.kelas_dx->enabled = false;
	game->images.kelas_sx->enabled = false;
	game->images.kelas_closed->enabled = false;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		game->player.movements.key_mouse_left_down = true;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE)
		game->player.movements.key_mouse_left_down = false;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
		game->player.movements.key_mouse_right_down = true;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_RELEASE)
		game->player.movements.key_mouse_right_down = false;
	if (button == MLX_MOUSE_BUTTON_MIDDLE && action == MLX_PRESS)
	{
		game->player.movements.key_mouse_right_down = true;
		game->player.movements.key_mouse_left_down = true;
	}
	if (button == MLX_MOUSE_BUTTON_MIDDLE && action == MLX_RELEASE)
	{
		game->player.movements.key_mouse_right_down = false;
		game->player.movements.key_mouse_left_down = false;
	}
	if (game->player.movements.key_mouse_right_down == true
		&& game->player.movements.key_mouse_left_down == true)
		game->images.kelas_closed->enabled = true;
	else if (game->player.movements.key_mouse_right_down == false
		&& game->player.movements.key_mouse_left_down == false)
		game->images.kelas_open->enabled = true;
	else if (game->player.movements.key_mouse_right_down == true)
		game->images.kelas_dx->enabled = true;
	else if (game->player.movements.key_mouse_left_down == true)
		game->images.kelas_sx->enabled = true;
}

// void	wave_eitor(mlx_image_t *image1, mlx_image_t *image2)
// {

// }

// #define FRAME_RATE 1
// void waves_maker(void *param)
// {
// 	t_game		*game;
// 	game = (t_game *)param;

// 	static int	i;
// 	if (i % FRAME_RATE == 0)
// 	{
// 		wave_eitor(game->images.waves[0], game->images.waves[1]);
// 	}
// 	++i;
// }

#define FRAME_RATE 5
//! revisar ell comportamineto de las burbujas!
void	draw_bubble(mlx_t *mlx, mlx_image_t **bubble_array, bool *animation_switch)
{
	(void)mlx;

	static int	bubble_frame = 0;

	bubble_array[bubble_frame]->enabled = false;
	bubble_frame++;
	bubble_array[bubble_frame]->enabled = true;
	if (bubble_frame == 19)
	{
		bubble_frame = 0;
		*animation_switch = false;
	}
}

void	animations(void *params)
{
	t_game		*game;
	static bool	animation_switch = false;
	static float		little_jump = 0.0;

	game = (t_game*)params;
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec % 100 == 0)
		animation_switch = true;
	if (animation_switch == true)
		draw_bubble(game->mlx,  game->images.bubble_array, &animation_switch);
	if (current_time.tv_usec % 5 == 0  && game->images.start_cover[0]->enabled == true)
		game->images.start_cover[1]->enabled = !game->images.start_cover[1]->enabled;
	if (game->images.start_cover[0]->enabled == false && game->images.start_cover[1]->instances->y < HEIGHT)
	{
		game->images.start_cover[1]->instances->y += 2;
		game->images.start_cover[1]->instances->x += 2;
		mlx_resize_image(game->images.start_cover[1], game->images.start_cover[1]->width - 4, game->images.start_cover[1]->height - 4);
		if (game->images.start_cover[1]->height == 4)
			game->images.start_cover[1]->enabled = false;
	}
	if (game->images.fauna->instances->x == -(int)game->images.fauna->width)
	{
		game->images.fauna->instances->x = WIDTH;
	}
	printf("game->images.fauna->instances->x %d\n", game->images.fauna->instances->x);
	printf("-(int)game->images.fauna->width %d\n\n\n", -(int)game->images.fauna->width);
	game->images.fauna->instances->x = little_jump;
	little_jump -= 0.3;
}

void	await_user_input(t_game *game)
{
	mlx_mouse_hook(game->mlx, &mouse_buttons, game);
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);
	mlx_loop_hook(game->mlx, &movements_player, game);
	mlx_loop_hook(game->mlx, &animations, game);
	// mlx_loop_hook(game->mlx, &waves_maker, game);
	mlx_loop(game->mlx);
}