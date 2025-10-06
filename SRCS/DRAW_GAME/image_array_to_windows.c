/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_array_to_windows.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:19:45 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 15:30:32 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

void	array_to_win(mlx_t *mlx, mlx_image_t **array_imgs, int frames_times)
{
	int	i;

	i = 0;
	while (i < frames_times)
	{
		mlx_image_to_window(mlx, array_imgs[i], 0, 0);
		array_imgs[i]->enabled = false;
		++i;
	}
}
