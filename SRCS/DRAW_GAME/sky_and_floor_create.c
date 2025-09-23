#include "draw_game.h"

mlx_image_t	*create_half_screen_rectangle(mlx_t *mlx, int color)
{
	int	x;
	int	y;


	mlx_image_t	*half_rectangle = mlx_new_image(mlx, WIDTH, HEIGHT / 2);

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


mlx_image_t	*create_gradient_bgr(mlx_t *mlx)
{
	mlx_image_t	*gradient_bgr;
	const float	little_jump = (float)(HEIGHT / 2) / 255;
	float		gradient_color;
	int			x;
	int			y;

	gradient_bgr = mlx_new_image(mlx, WIDTH, HEIGHT);
	y = 0;
	gradient_color = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(gradient_bgr, x, y, ft_color(0, 50, 40, gradient_color));
			else
				mlx_put_pixel(gradient_bgr, x, y, ft_color(0, 0, 0, gradient_color));

			++x;
		}
		++y;
		if (y < HEIGHT / 2)
			gradient_color += little_jump;
		else
			gradient_color -= little_jump;

	}
	return (gradient_bgr);
}
