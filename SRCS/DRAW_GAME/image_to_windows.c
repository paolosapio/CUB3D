#include "draw_game.h"

void	transparentator(int value_of_trasparence, mlx_image_t *image)
{
	int i;

	i = 3;
	while (i < image->width * image->height * 4)
	{
		printf("caca");
		image->pixels[i] = value_of_trasparence;
 		i += 4;
	}
		
}
void	minimap_images_to_window(mlx_t *mlx, t_map *map, t_images *images)
{
	int			x;
	int			y;
	int			slider = 0;

	mlx_resize_image(images->map_sand, g_size_tile, g_size_tile);
	mlx_resize_image(images->map_rock, g_size_tile, g_size_tile);

	transparentator(200, images->map_sand);
	transparentator(200, images->map_rock);

	y = -1;
	while (map->array[++y])
	{
		slider++;
		x = -1;
		while (map->array[y][++x])
		{
			// coor_map.x = x;
			// coor_map.y = y;
			if (map->array[y][x] == '1')
			{
				mlx_image_to_window(mlx, images->map_rock, map->map_draw_offset.x + x * g_size_tile, map->map_draw_offset.y + y * g_size_tile);
			}
			else if (ft_strchr("NSWE0", map->array[y][x]) != NULL)
			{
				mlx_image_to_window(mlx, images->map_sand, map->map_draw_offset.x + x * g_size_tile, map->map_draw_offset.y + y * g_size_tile);
			}
		}
	}
	mlx_image_to_window(mlx, images->minimap, map->map_draw_offset.x, map->map_draw_offset.y);
	mlx_image_to_window(mlx, images->map_ray, map->map_draw_offset.x, map->map_draw_offset.y);
}

void	images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.tridy, 0, 0);
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
	mlx_image_to_window(game->mlx, game->images.background_map, 0, 0);
	minimap_images_to_window(game->mlx, &game->map, &game->images);
	mlx_resize_image(game->images.map_greco, g_size_tile, g_size_tile);
	mlx_image_to_window(game->mlx, game->images.map_greco, 0, 0);

	//image_print_ordereneitor(&game->images);
}