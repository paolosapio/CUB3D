/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:57:14 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 17:47:18 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

void	bouble_to_windws(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 20)
	{
		mlx_image_to_window(game->mlx, game->images.bubble_array[i], 0, 0);
		game->images.bubble_array[i]->enabled = false;
	}
}
