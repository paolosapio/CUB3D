/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:57:29 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 15:42:25 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"
#include "../RENDER/render.h"
#include "libft.h"

void	keys_kelas(mlx_key_data_t keydata, t_game *game)
{
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

void	keys_wasd(mlx_key_data_t keydata, t_game *game)
{
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
}

void	keys_arrows(mlx_key_data_t keydata, t_game *game)
{
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

void	keys_enter_shift(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ENTER)
	{
		game->images.start[0]->enabled = false;
		game->images.start[1]->enabled = true;
		game->player.speed = NORMAL * (game->tile_size * 0.04);
	}
	if (keydata.key == MLX_KEY_LEFT_SHIFT)
	{
		game->player.speed = TURBO * (game->tile_size * 0.04);
		if (keydata.action == MLX_RELEASE)
			game->player.speed = NORMAL * (game->tile_size * 0.04);
	}
}

void	special_keys(mlx_key_data_t keydata, void *params)
{
	t_game	*game;

	game = (t_game *)params;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_TAB) == true)
	{
		game->images.minimap->enabled -= 1;
		game->images.map_greco->enabled -= 1;
		game->images.map_ray->enabled -= 1;
		game->images.background_map->enabled -= 1;
		game->images.map_sand->enabled -= 1;
		game->images.map_rock->enabled -= 1;
	}
	keys_wasd(keydata, game);
	keys_arrows(keydata, game);
	keys_enter_shift(keydata, game);
	keys_kelas(keydata, game);
}
