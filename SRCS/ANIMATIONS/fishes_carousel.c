/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fishes_carousel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:51:20 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:42:31 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

void	carousel(mlx_image_t **image, const float movement)
{
	static float	current_movement = 0.0;

	current_movement += movement;
	if (image[0]->instances->x < -(int)image[0]->width)
	{
		image[0]->instances->x = WIDTH;
		image[1]->instances->x = WIDTH;
	}
	if (image[0]->instances->x > WIDTH)
	{
		image[0]->instances->x = -(int)image[0]->width;
		image[1]->instances->x = -(int)image[1]->width;
	}
	image[0]->instances->x += (int)current_movement;
	image[1]->instances->x += (int)current_movement;
	if (current_movement > 1 || current_movement < -1)
		current_movement = 0;
}

void	carousel_reverse(mlx_image_t *image, const float movement)
{
	static float	current_movement = 0.0;

	current_movement -= movement;
	if (image->instances->x < -(int)image->width)
	{
		image->instances->x = WIDTH;
	}
	if (image->instances->x > WIDTH)
	{
		image->instances->x = -(int)image->width;
	}
	image->instances->x -= (int)current_movement;
	if (current_movement > 1 || current_movement < -1)
		current_movement = 0;
}

void	sun_in_waves(mlx_image_t **image, const float movement)
{
	static float	current_movement = 0.0;
	static int		sign_conversion = -1;

	current_movement += movement;
	image[0]->instances->x += (int)current_movement * sign_conversion;
	image[1]->instances->x -= (int)current_movement * sign_conversion;
	image[0]->pixels[3] += (int)current_movement * sign_conversion;
	if (image[0]->instances->x == -800)
		sign_conversion = -1;
	if (image[0]->instances->x == -300)
		sign_conversion = +1;
	if (current_movement > 1 || current_movement < -1)
		current_movement = 0;
}
