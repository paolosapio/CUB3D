/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:51:46 by psapio            #+#    #+#             */
/*   Updated: 2025/10/12 10:35:55 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_game.h"

mlx_image_t	*create_half_screen_rectangle(mlx_t *mlx, int color)
{
	int			x;
	int			y;
	mlx_image_t	*half_rectangle;

	half_rectangle = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(half_rectangle, x, y, color);
		}
	}
	return (half_rectangle);
}

/**
 * @brief adds or substracts the gradient_color based on wether we are halfway
 * through the screen.
 */
void	condition_little_jump(int y, float *gradient_color)
{
	const float	little_jump = 255.0 / (HEIGHT / 2.0);

	if (y < HEIGHT / 2)
		*gradient_color += little_jump;
	else
		*gradient_color -= little_jump;
}

/**
 * @brief Creates the background gradient, a part of our "trampantojo" to
 * emulate the darkening of the world the farther away you are to a wall.
 */
mlx_image_t	*create_gradient_bgr(mlx_t *mlx)
{
	mlx_image_t	*gradient_bgr;
	float		gradient_color;
	int			x;
	int			y;

	gradient_bgr = mlx_new_image(mlx, WIDTH, HEIGHT);
	y = -1;
	gradient_color = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(gradient_bgr, x, y, ft_color(0, 50, 40,
						gradient_color));
			else
				mlx_put_pixel(gradient_bgr, x, y, ft_color(0, 0, 0,
						gradient_color));
		}
		condition_little_jump(y, &gradient_color);
	}
	return (gradient_bgr);
}
