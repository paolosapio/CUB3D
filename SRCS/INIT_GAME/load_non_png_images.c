/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_non_png_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:00:11 by psapio            #+#    #+#             */
/*   Updated: 2025/10/12 10:39:27 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#define N_COLORS 3
#define COLOR_ERROR -1

/**
 * @brief Checks and casts the color received inside the .cub file
 * @param color_str The color as the string.
 * @return The color transformed into an int, or -1 in case the color was not
 * valid.
 */
int	extract_color_from_str(char *color_str)
{
	int			rgba_array[N_COLORS];
	char		**rgba_strings;
	uint32_t	color;
	int			i;

	i = 0;
	rgba_strings = ft_split(color_str, ',');
	if (ft_arraylen((const char **)rgba_strings) != N_COLORS)
		return (free_double_pointer(rgba_strings), COLOR_ERROR);
	while (rgba_strings[i] != NULL)
	{
		if (ft_isdigit_str(rgba_strings[i]) == false)
			return (free_double_pointer(rgba_strings), COLOR_ERROR);
		rgba_array[i] = ft_atoi(rgba_strings[i]);
		if ((rgba_array[i] > 255) || (rgba_array[i] < 0))
			return (free_double_pointer(rgba_strings), COLOR_ERROR);
		i++;
	}
	color = ft_color(rgba_array[0], rgba_array[1], rgba_array[2], 255);
	free_double_pointer(rgba_strings);
	return (color);
}

/**
 * @brief Creates all the game imgs that don't use a png but rather have to be
 * painted pixel by pixel based on the map information, such as:
 * 
 * - Sky and Floor with the specified color
 * 
 * - The minimap.
 * 
 * - The 3D game itself with the raycasting based on the players position and
 * map info.
 */
void	load_non_png_images(mlx_t *mlx, t_map *map, t_images *imgs,
			t_parser_map *p_map)
{
	int	color;

	imgs->background_map = create_background_map(mlx);
	imgs->gradient_bgr = create_gradient_bgr(mlx);
	color = extract_color_from_str(p_map->info_sky);
	if (color == COLOR_ERROR)
	{
		destroy_parser_map(p_map);
		sayonara_baby(mlx, imgs, map);
		exit(1);
	}
	imgs->sky = create_half_screen_rectangle(mlx, color);
	color = extract_color_from_str(p_map->info_floor);
	if (color == COLOR_ERROR)
	{
		destroy_parser_map(p_map);
		sayonara_baby(mlx, imgs, map);
		exit(1);
	}
	imgs->floor = create_half_screen_rectangle(mlx, color);
	imgs->tridy = create_empty_img(mlx, WIDTH, HEIGHT);
	imgs->map_ray = create_empty_img(mlx, map->longest_line * map->tile_size,
			map->map_len * map->tile_size);
}
