/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:53:42 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 21:22:41 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_create_images.h"

/**
 * @brief Creates an an img with the specified color that covers half the screen
 * Used for the sky and the floor.
 */
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

/**
 * @brief Creates and returns an empty mlx_image_t with the specified measures
 * 
 * @param mlx the mlx instance needed to call mlx_new_image.
 * @param width the width of the new image.
 * @param height the height of the new image.
 */
mlx_image_t	*create_empty_img(mlx_t *mlx, int width, int height)
{
	mlx_image_t	*map_ray;

	map_ray = mlx_new_image(mlx, width + 1, height + 1);
	return (map_ray);
}

/**
 * @brief Creates the minimap background, a semi transparent black background
 * that covers all the screen.
 */
mlx_image_t	*create_background_map(mlx_t *mlx)
{
	int			x;
	int			y;
	mlx_image_t	*img_sky;

	img_sky = mlx_new_image(mlx, WIDTH, HEIGHT);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img_sky, x, y, 0x00000099);
		}
	}
	return (img_sky);
}
