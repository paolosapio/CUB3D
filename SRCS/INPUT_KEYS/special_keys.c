/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:57:29 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 16:21:45 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"
#include "../RENDER/render.h"
#include "libft.h"

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

void	keys_enter_shift(mlx_key_data_t keydata, t_game *g)
{
	if (keydata.key == MLX_KEY_ENTER)
	{
		g->images.start[0]->enabled = false;
		g->images.start[1]->enabled = true;
		g->player.speed = NORMAL * (g->tile_size * 0.04);
	}
	if (keydata.key == MLX_KEY_LEFT_SHIFT && g->images.info->enabled == false)
	{
		g->player.movements.key_w_is_down = true;
		g->player.speed = TURBO * (g->tile_size * 0.04);
		if (keydata.action == MLX_RELEASE)
		{
			g->player.movements.key_w_is_down = false;
			g->player.speed = NORMAL * (g->tile_size * 0.04);
			g->images.kelas_up[0]->enabled = false;
			g->images.kelas_up[1]->enabled = false;
		}
		else
		{
			g->images.kelas_open->enabled = false;
			g->images.kelas_closed->enabled = false;
			g->images.kelas_dx->enabled = false;
			g->images.kelas_sx->enabled = false;
		}
	}
}

void	special_keys(mlx_key_data_t keydata, void *params)
{
	t_game	*game;

	game = (t_game *)params;
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
	{
		minimap_closer(game, game->images.info->enabled - 1);
		game->images.kelas_open->enabled = false;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == true)
	{
		if (game->images.info->enabled == true
			|| game->images.background_map->enabled == true)
		{
			minimap_closer(game, false);
		}
		else
			mlx_close_window(game->mlx);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_TAB) == true)
		tab_mapeitor(game);
	keys_wasd(keydata, game);
	keys_arrows(keydata, game);
	keys_enter_shift(keydata, game);
	keys_kelas(keydata, game);
}
