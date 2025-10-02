/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:16:33 by anfi              #+#    #+#             */
/*   Updated: 2025/10/02 15:16:44 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_keys.h"

void	await_user_input(t_game *game)
{
	mlx_mouse_hook(game->mlx, &mouse_buttons, game);
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);
	mlx_loop_hook(game->mlx, &movements_player, game);
	mlx_loop_hook(game->mlx, &animations, game);
	mlx_loop(game->mlx);
}
