/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:31:06 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 20:56:34 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"
#include "../MOVEMENTS/movements.h"
#include "../RENDER/render.h"
#include "libft.h"

#define SENSITIVITY 10

void	mouse_movements(double mouse_x, double mouse_y, void *params)
{
	float			move;
	t_game			*game;
	static double	first_step_x = WIDTH / 2;

	(void)mouse_y;
	game = (t_game *)params;
	if (mouse_x < first_step_x)
	{
		move = ((first_step_x - mouse_x) / SENSITIVITY);
		carousel(game->images.fauna, CAROUSEL_LEFT_MOVEMENT + move);
		carousel_reverse(game->images.ambient, CAROUSEL_LEFT_MOVEMENT);
		change_player_rotation(&game->player, game->player.vision_angle - move);
	}
	else if (mouse_x > first_step_x)
	{
		move = ((mouse_x - first_step_x) / SENSITIVITY) + 1;
		carousel(game->images.fauna, CAROUSEL_RIGHT_MOVEMENT - move);
		carousel_reverse(game->images.ambient, CAROUSEL_RIGHT_MOVEMENT);
		change_player_rotation(&game->player, game->player.vision_angle + move);
	}
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

void	draw_bubble(mlx_t *mlx, mlx_image_t **bubble_array, bool *animation_switch)
{
	static int	bubble_frame = 0;

	(void)mlx;
	bubble_array[bubble_frame]->enabled = false;
	bubble_frame++;
	bubble_array[bubble_frame]->enabled = true;
	if (bubble_frame == 19)
	{
		bubble_frame = 0;
		*animation_switch = false;
	}
}
void	switch_fauna(int tv_sec, t_images *images)
{
	
	if (tv_sec % 2 == 0)
	{
		images->fauna[0]->enabled = true;
		images->fauna[1]->enabled = false;
	}
	else
	{
		images->fauna[0]->enabled = false;
		images->fauna[1]->enabled = true;
	}
}


void	animations(void *params)
{
	struct timeval	current_time;
	t_game			*game;
	static bool		animation_switch = false;

	game = (t_game *)params;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec % 100 == 0)
		animation_switch = true;
	if (animation_switch == true)
		draw_bubble(game->mlx, game->images.bubble_array, &animation_switch);
	if (current_time.tv_usec % 5 == 0 && game->images.start_cover[0]->enabled == true)
		game->images.start_cover[1]->enabled = !game->images.start_cover[1]->enabled;
	if (game->images.start_cover[0]->enabled == false && game->images.start_cover[1]->instances->y < HEIGHT)
	{
		game->images.start_cover[1]->instances->y += 1;
		game->images.start_cover[1]->instances->x += 1;
		if (mlx_resize_image(game->images.start_cover[1], game->images.start_cover[1]->width - 2, game->images.start_cover[1]->height - 2) == false)
			game->images.start_cover[1]->enabled = false;
	}
	switch_fauna(current_time.tv_sec, &game->images);
	carousel(game->images.fauna, CAROUSEL_NORMAL_MOVEMENT);
	carousel_reverse(game->images.ambient, -CAROUSEL_NORMAL_MOVEMENT);
}

void	await_user_input(t_game *game)
{
	mlx_mouse_hook(game->mlx, &mouse_buttons, game);
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);
	mlx_loop_hook(game->mlx, &movements_player, game);
	mlx_loop_hook(game->mlx, &animations, game);
	mlx_loop(game->mlx);
}
