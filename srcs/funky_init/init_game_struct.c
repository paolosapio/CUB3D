#include "cub3d.h"

#include <math.h>


// Returns the biggest number.
int	max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

void	draw_line(t_game *game, int p1_x, int p1_y, int p2_x, int p2_y)
{
	mlx_image_t *linea = mlx_new_image(game->mlx, WIDTH, HEIGHT);

	int i = 0;
	int dx = p2_x - p1_x; // Longitud del cateto en el lado x (base)
	int dy = p2_y - p1_y; // longitud del cateto en el lado y (altura)

	int biggest_side = max(abs(dx), abs(dy)); // biggest_side almacena el cateto mayor.

	int step_x;
	int step_y;

	if (biggest_side != 0)
	{
		//biggest_side es dx o dy en positivo. por tanto una de estas variables será 1 o -1.
		// Y la otra será el gradiente positivo o negativo.
		step_x = dx / biggest_side; // -1
		step_y = dy / biggest_side; // 0.59
	}
	while (i < biggest_side)
	{

		mlx_put_pixel(linea, round(p1_x + i * step_x), i , 0xFFFFFFFF);
		i++;
	}
	mlx_image_to_window(game->mlx, linea, 0, 0);
}

void init_game_struct(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", true);

	draw_line(game, 400, 300, 0, 20);
	//init_images(game->mlx, &game->map, &game->images);
}
