/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_array_to_windows.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:57:14 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 20:17:48 by psapio           ###   ########.fr       */
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