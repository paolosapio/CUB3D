#include "init_game.h"
#define N_COLORS 3

int	extract_color_from_str(char *color_str)
{
	int			rgba_array[N_COLORS];
	char		**rgba_strings;
	uint32_t	color;
	int			i;

	i = 0;
	rgba_strings = ft_split(color_str, ',');
	if (ft_arraylen((const char **)rgba_strings) != N_COLORS)
	{
		write(2, "Invalid color received\n", 23);
		free_double_pointer(rgba_strings);
		exit(1);
	}
	while (rgba_strings[i] != NULL)
	{
		if (ft_isdigit_str(rgba_strings[i]) == false)
		{
			write(2, "Invalid color received\n", 23);
			free_double_pointer(rgba_strings);
			exit(1);
		}
		rgba_array[i] = ft_atoi(rgba_strings[i]);
		i++;
	}
	color = ft_color(rgba_array[0], rgba_array[1], rgba_array[2], 255);
	free_double_pointer(rgba_strings);
	return (color);
}

void	init_images(mlx_t *mlx, t_map *map, t_images *images, t_parser_map *parser_map)
{
	int	color;

	images->minimap = create_empty_img(mlx, map->longest_line * map->tile_size , map->map_len * map->tile_size);
	images->background_map = create_background_map(mlx, map);
	images->gradient_bgr = create_gradient_bgr(mlx);
	color = extract_color_from_str(parser_map->info_sky);
	images->sky = create_half_screen_rectangle(mlx, color);
	color = extract_color_from_str(parser_map->info_floor);
	images->floor = create_half_screen_rectangle(mlx, color);
	images->tridy = create_empty_img(mlx, WIDTH, HEIGHT);
	images->map_ray = create_empty_img(mlx, map->longest_line * map->tile_size , map->map_len * map->tile_size);
	images->minimap->enabled = false;
	images->map_ray->enabled = false;
	images->map_greco->enabled = false;
	images->map_rock->enabled = false;
	images->map_sand->enabled = false;
	images->background_map->enabled = false;
}
