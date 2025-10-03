/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:33:21 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 20:23:56 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

#define FRAME_FLIKER 352

void	frame_loop(unsigned long current_time, mlx_image_t **frame_array)
{
	static unsigned long	last_frame_frame = 0;
	static int				frame_frame = 0;

	if (current_time - last_frame_frame >= FRAME_FLIKER)
	{
		frame_array[frame_frame]->enabled = true;
		if (frame_frame != 0)
		{
			frame_array[frame_frame - 1]->enabled = false;
			printf("CACA\n");
		}
		if (frame_frame == 0)
		{
			frame_array[5]->enabled = false;
			printf("CACA2\n");

		}
		frame_frame++;
		last_frame_frame = current_time;
		if (frame_frame == 6)
		{
			frame_frame = 0;
		}
	}
}