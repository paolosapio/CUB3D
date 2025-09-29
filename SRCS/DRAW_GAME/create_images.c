#include "draw_game.h"

// TODO: Crear una única función para las imáenes en que solo creamos una imagen base
mlx_image_t	*create_ray_minimap(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*map_ray;

	map_ray = mlx_new_image(mlx, map->longest_line * g_size_tile, map->map_len
			* g_size_tile);
	return (map_ray);
}

mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*img_minimap;

	img_minimap = mlx_new_image(mlx, map->longest_line * g_size_tile,
			map->map_len * g_size_tile);
	return (img_minimap);
}

mlx_image_t	*create_background_map(mlx_t *mlx, t_map *map)
{
	int			x;
	int			y;
	mlx_image_t	*img_sky;

	(void)map;
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

mlx_image_t	*create_tridy(mlx_t *mlx)
{
	mlx_image_t *tridy;

	tridy = mlx_new_image(mlx, WIDTH, HEIGHT);
	return (tridy);
}