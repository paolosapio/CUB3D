/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:32:24 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 15:32:36 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

#define START_SCREEN_FREQUENCY 500
#define RESIZE_SPEED 8

void	resize_start_screen(mlx_image_t *start_img)
{
	bool	resize_result;

	start_img->instances->y += RESIZE_SPEED / 2;
	start_img->instances->x += RESIZE_SPEED / 2;
	resize_result = mlx_resize_image(start_img,
			start_img->width - RESIZE_SPEED, start_img->height - RESIZE_SPEED);
	if (resize_result == false)
		start_img->enabled = false;
}

void	start_screen_loop(unsigned long current_time, mlx_image_t **img)
{
	static unsigned long	last_animation_loop;

	if (current_time - last_animation_loop > START_SCREEN_FREQUENCY)
	{
		img[1]->enabled = !img[1]->enabled;
		last_animation_loop = current_time;
	}
}
