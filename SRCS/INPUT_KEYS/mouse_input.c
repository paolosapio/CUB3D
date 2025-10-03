/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:31:06 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 21:15:52 by psapio           ###   ########.fr       */
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
	printf("button: %d\n", button);
	kelas_movement(game);
}
