#include "draw_game.h"

mlx_image_t	*create_ray_minimap(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*map_ray;

	map_ray = mlx_new_image(mlx, map->longest_line * g_size_tile, map->map_len * g_size_tile);
	return (map_ray);
}

mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map, t_images *image)
{
	int			x;
	int			y;
	int			slider = 0;
	t_int_coor	coor_map;
	mlx_image_t	*img_minimap;
	
	mlx_resize_image(image->map_sand, g_size_tile, g_size_tile);
	img_minimap = mlx_new_image(mlx, map->longest_line * g_size_tile, map->map_len * g_size_tile);
	y = -1;
	while (map->array[++y])
	{
		slider++;
		x = -1;
		while (map->array[y][++x])
		{
			coor_map.x = x;
			coor_map.y = y;
			if (map->array[y][x] == '1')
				paint_tile(g_size_tile, img_minimap, coor_map, color(50,70,50,255));
			else if (ft_strchr("NSWE0", map->array[y][x]) != NULL)
				mlx_image_to_window(mlx, image->map_sand, map->map_draw_offset.x + x * g_size_tile, map->map_draw_offset.y + y * g_size_tile);
		}
	}
	return (img_minimap);
}

mlx_image_t	*create_sky(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	(void)map;
	mlx_image_t	*img_sky = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img_sky, x, y, 0x6D8196FF);
		}
	}
	return (img_sky);
}

mlx_image_t	*create_background_map(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	(void)map;
	mlx_image_t	*img_sky = mlx_new_image(mlx, WIDTH, HEIGHT);
	
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

mlx_image_t	*create_floor(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;
	
	mlx_image_t	*img_floor = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
	(void)map;
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(img_floor, x, y, 0x968C6E);
		}
	}
	return (img_floor);
}