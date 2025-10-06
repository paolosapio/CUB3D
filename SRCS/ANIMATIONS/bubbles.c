/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:31:28 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 15:31:36 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

#define BUBBLE_FREQUENCY 5000
#define BUBBLE_FRAME_SPEED 55

void	bubble_loop(unsigned long current_time, mlx_image_t **bubble_array)
{
	static unsigned long	last_bubble_loop;
	static unsigned long	last_bubble_frame;
	static int				bubble_frame = 0;

	if (!last_bubble_loop)
		last_bubble_loop = current_time;
	if (current_time - last_bubble_loop >= BUBBLE_FREQUENCY)
	{
		if (current_time - last_bubble_frame >= BUBBLE_FRAME_SPEED)
		{
			bubble_array[bubble_frame]->enabled = false;
			bubble_frame++;
			bubble_array[bubble_frame]->enabled = true;
			if (bubble_frame == 19)
			{
				bubble_frame = 0;
				last_bubble_loop = current_time;
			}
			last_bubble_frame = current_time;
		}
	}
}
