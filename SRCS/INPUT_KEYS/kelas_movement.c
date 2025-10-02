/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kelas_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:31:49 by anfi              #+#    #+#             */
/*   Updated: 2025/10/02 15:54:23 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"

void	kelas_movement(t_game *game)
{
	game->images.kelas_open->enabled = false;
	game->images.kelas_dx->enabled = false;
	game->images.kelas_sx->enabled = false;
	game->images.kelas_closed->enabled = false;
	printf(" e: %d\n", game->player.movements.key_e_is_down);
	printf("->: %d\n", game->player.movements.key_mouse_right_down);
	if ((game->player.movements.key_q_is_down == true
			&& game->player.movements.key_e_is_down == true)
		|| (game->player.movements.key_mouse_left_down == true
			&& game->player.movements.key_mouse_right_down == true))
		game->images.kelas_closed->enabled = true;
	else if ((game->player.movements.key_q_is_down == false
			&& game->player.movements.key_e_is_down == false)
		|| (game->player.movements.key_mouse_left_down == false
			&& game->player.movements.key_mouse_right_down == false))
		game->images.kelas_open->enabled = true;
	else if ((game->player.movements.key_e_is_down == true
		|| game->player.movements.key_mouse_right_down == true))
	{
		printf("ñeñeñeñeñeñe\n");
		game->images.kelas_dx->enabled = true;
	}
	else if ((game->player.movements.key_q_is_down == true
		|| game->player.movements.key_mouse_left_down == true))
		game->images.kelas_sx->enabled = true;
}
