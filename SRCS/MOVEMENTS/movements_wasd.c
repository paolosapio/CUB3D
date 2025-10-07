/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:55:46 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 00:08:08 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../RENDER/render.h"
#include "movements.h"

/**
 * @brief will calculare the sin and cos based on the player's vision angle
 * and the direction it is going, which is it's own vision angle modified by
 * 0, 90, 180 or 270 depending on wich key was pressed.
 * 
 * The resulting sin and cos will be the variation on the x and y axys *on
 * cell scale*. So for example, if sin turns out to be 0.04, it is relative to
 * a 0-1 scale rather than pixels.
 */
void	angulator_move(float vision_angle, int tile_size, t_game *game)
{
	t_trig_angle	trig_angle;

	trig_angle.angle = vision_angle;
	trig_angle.s1n = sin(to_radians(vision_angle)) / tile_size;
	trig_angle.c0s = cos(to_radians(vision_angle)) / tile_size;
	move_player(&game->player, &game->map, -trig_angle.s1n, -trig_angle.c0s);
}

/**
 * @brief This function is an intermediate function neede for the norminette.
 * I'm not quite sure what its name means, but anyways, it calls angulator_move
 * and renders the game.
 */
void	grade_movement_change(t_game *game, int grade)
{
	angulator_move(game->player.vision_angle + grade, game->tile_size, game);
	clean_game_images(&game->images);
	init_camera(game, game->player.pos, game->player.vision_angle);
}

/**
 * @brief Will check if any WASD key was pressed and act accordingly trying to
 * move the character in said direction by calling grade_movement_change.
 */
void	movement_wasd(t_game *game)
{
	if (game->player.movements.key_w_is_down == true)
		grade_movement_change(game, 0);
	if (game->player.movements.key_d_is_down == true)
		grade_movement_change(game, 90);
	if (game->player.movements.key_s_is_down == true)
		grade_movement_change(game, 180);
	if (game->player.movements.key_a_is_down == true)
		grade_movement_change(game, 270);
}
