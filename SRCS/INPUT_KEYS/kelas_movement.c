/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kelas_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:31:49 by anfi              #+#    #+#             */
/*   Updated: 2025/10/06 15:54:05 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"

void	keys_kelas(mlx_key_data_t keydata, t_game *game)
{
	if (game->images.info->enabled == true
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT) == true)
		return ;
	if (keydata.key == MLX_KEY_Q)
	{
		game->player.movements.key_q_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_q_is_down = false;
	}
	if (keydata.key == MLX_KEY_E)
	{
		game->player.movements.key_e_is_down = true;
		if (keydata.action == MLX_RELEASE)
			game->player.movements.key_e_is_down = false;
	}
	kelas_movement(game);
}

void	kelas_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT) == true)
		return ;
	game->images.kelas_open->enabled = false;
	game->images.kelas_dx->enabled = false;
	game->images.kelas_sx->enabled = false;
	game->images.kelas_closed->enabled = false;
	if ((game->player.movements.key_q_is_down == true
			&& game->player.movements.key_e_is_down == true)
		|| (game->player.movements.key_mouse_left_down == true
			&& game->player.movements.key_mouse_right_down == true))
		game->images.kelas_closed->enabled = true;
	else if ((game->player.movements.key_q_is_down == false
			&& game->player.movements.key_e_is_down == false)
		&& (game->player.movements.key_mouse_left_down == false
			&& game->player.movements.key_mouse_right_down == false))
		game->images.kelas_open->enabled = true;
	else if ((game->player.movements.key_e_is_down == true
			|| game->player.movements.key_mouse_right_down == true))
		game->images.kelas_dx->enabled = true;
	else if ((game->player.movements.key_q_is_down == true
			|| game->player.movements.key_mouse_left_down == true))
		game->images.kelas_sx->enabled = true;
}
