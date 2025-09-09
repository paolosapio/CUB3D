#include "init_game.h"

mlx_image_t	*create_cuadricula(mlx_t *mlx)
{
	mlx_image_t *image = mlx_new_image(mlx, WIDTH, HEIGHT);

	for (int y = 0; y < WIDTH; y++)
	{
		for (int x = 0; x < HEIGHT; x++)
		{
			if (y % g_size_tile  == 0 || x % g_size_tile  == 0)
			{
				mlx_put_pixel(image, y, x, color(0,0,0,70));
			}
		}
	}

	return (image);
}

void	init_images(mlx_t* mlx, t_map *map, t_images *images)
{
	images->minimap = create_minimap(mlx, map, images); //hola paolo del futuro
	images->background_map = create_background_map(mlx, map);
	images->floor = create_floor(mlx, map);
	images->sky = create_sky(mlx, map);
	images->map_ray = create_ray_minimap(mlx, map);
	images->cuadricula = create_cuadricula(mlx);
	mlx_image_to_window(mlx, images->cuadricula, map->map_draw_offset.x, map->map_draw_offset.y);
	images->minimap->enabled = true;
	images->map_ray->enabled = true;
	images->map_greco->enabled = true;
	//images->map_rock->enabled = false;
	images->map_sand->enabled = true;
}
