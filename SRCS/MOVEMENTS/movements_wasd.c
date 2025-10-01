/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:55:46 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 21:56:29 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../RENDER/render.h"
#include "movements.h"

void	angulator_move(float vision_angle, int tile_size, t_game *game)
{
	t_trig_angle	trig_angle;

	trig_angle.angle = vision_angle;
	trig_angle.s1n = sin(to_radians(vision_angle)) / tile_size;
	trig_angle.c0s = cos(to_radians(vision_angle)) / tile_size;
	move_player(&game->player, &game->map, -trig_angle.s1n, -trig_angle.c0s);
}

void	grade_movement_change(t_game *game, int grade)
{
	angulator_move(game->player.vision_angle + grade, game->tile_size, game);
	clean_game_images(&game->images);
	init_camera(game, game->player.pos, game->player.vision_angle);
}

void	movement_wasd(t_game	*game)
{
	if (game->player.movements.key_w_is_down == true)
	{
		angulator_move(game->player.vision_angle + 0, game->tile_size, game);
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) == false
			&& mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) == false)
		{
			clean_game_images(&game->images);
			init_camera(game, game->player.pos, game->player.vision_angle);
		}
	}
	if (game->player.movements.key_d_is_down == true)
		grade_movement_change(game, 90);
	if (game->player.movements.key_s_is_down == true)
		grade_movement_change(game, 180);
	if (game->player.movements.key_a_is_down == true)
		grade_movement_change(game, 270);
}
