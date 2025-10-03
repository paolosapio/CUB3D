/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:00:11 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 20:54:39 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#define N_COLORS 3

void	error_color_exit(char **rgba_strings)
{
	write(2, "Invalid color received\n", 23);
	free_double_pointer(rgba_strings);
	exit(EXIT_FAILURE);
}

int	extract_color_from_str(char *color_str)
{
	int			rgba_array[N_COLORS];
	char		**rgba_strings;
	uint32_t	color;
	int			i;

	i = 0;
	rgba_strings = ft_split(color_str, ',');
	if (ft_arraylen((const char **)rgba_strings) != N_COLORS)
		error_color_exit(rgba_strings);
	while (rgba_strings[i] != NULL)
	{
		if (ft_isdigit_str(rgba_strings[i]) == false)
			error_color_exit(rgba_strings);
		rgba_array[i] = ft_atoi(rgba_strings[i]);
		if ((rgba_array[i] > 255) || (rgba_array[i] < 0))
			error_color_exit(rgba_strings);
		i++;
	}
	color = ft_color(rgba_array[0], rgba_array[1], rgba_array[2], 255);
	free_double_pointer(rgba_strings);
	return (color);
}

void	init_images(mlx_t *mlx, t_map *map, t_images *imgs, t_parser_map *p_map)
{
	int	color;

	imgs->background_map = create_background_map(mlx, map);
	imgs->gradient_bgr = create_gradient_bgr(mlx);
	color = extract_color_from_str(p_map->info_sky);
	imgs->sky = create_half_screen_rectangle(mlx, color);
	color = extract_color_from_str(p_map->info_floor);
	imgs->floor = create_half_screen_rectangle(mlx, color);
	imgs->tridy = create_empty_img(mlx, WIDTH, HEIGHT);
	imgs->map_ray = create_empty_img(mlx, map->longest_line * map->tile_size,
			map->map_len * map->tile_size);
	imgs->map_ray->enabled = false;
	imgs->map_greco->enabled = false;
	imgs->map_rock->enabled = false;
	imgs->map_sand->enabled = false;
	imgs->background_map->enabled = false;
}
