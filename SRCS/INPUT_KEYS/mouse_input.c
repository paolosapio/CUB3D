/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:31:06 by psapio            #+#    #+#             */
/*   Updated: 2025/10/07 23:21:03 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"
#include "../MOVEMENTS/movements.h"
#include "../RENDER/render.h"
#include "libft.h"

#define SENSITIVITY 10
#define MOUSE_MOVEMENT_TIME_MARGIN 5
/**
 * @brief The mouse hook to control the mouse position and rotate the character
 * 
 * @param mouse_x the x mouse position after it changed.
 * @param mouse_y the y mouse position after it changed.
 * @param params the game struct as a void *.
 */
void	mouse_movements(double mouse_x, double mouse_y, void *params)
{
	float			move;
	t_game			*game;
	static double			first_step_x;
	static unsigned long	last_frame;

	(void)mouse_y;
	game = (t_game *)params;
	if (!last_frame)
	{
		first_step_x = mouse_x;
		last_frame = get_time();
	}
	if (get_time() - last_frame < MOUSE_MOVEMENT_TIME_MARGIN)
	{
		printf("------------------\n");
		return ;
	}
	else
		printf("++++++++++++++++\n");
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
	last_frame = get_time();
}

/**
 * @brief the mouse hook to control which mouse button was pressed or released.
 * 
 * @param button which button called the hook.
 * @param action The astion that called the hook.
 * @param mods not used.
 * @param param the game struct as a void *.
 */
void	mouse_buttons(mouse_key_t button,
		action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;

	(void)mods;
	game = (t_game *)param;
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
	kelas_movement(game);
}
