/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meta_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:22:58 by anfi              #+#    #+#             */
/*   Updated: 2025/07/24 19:34:22 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	save_map_info(char *line_map_to_check, char **map_info)
{
	char **splitted;

	if (*map_info)
		return (ERROR);
	splitted = ft_split(line_map_to_check, ' ');
	printf("holaaa %zu\n", ft_arraylen((const char **)splitted));
	printf("|_%s - %s_|\n", splitted[0], splitted[1]);
	if ((ft_arraylen((const char **)splitted) == 2 && splitted[1][0] != '\n')||
		(ft_arraylen((const char **)splitted) == 3 && splitted[2][0] == '\n'))
	{
		*map_info = ft_strdup(splitted[1]);
		free_double_pointer(splitted);
		return (OK);
	}
	free_double_pointer(splitted);
	return (ERROR);
}

void	allocate_map_size(char *line_map_to_check, t_map *map, int fd)
{
	int	map_len;

	map_len = 0;

	line_map_to_check = get_next_line(fd);
	while (line_map_to_check)
	{
		printf("line_map_to_check: %s\n", line_map_to_check);
		map_len++;
		free(line_map_to_check);
		line_map_to_check = get_next_line(fd);
	}
	map->map_array = malloc((map_len + 2) * sizeof(char *));
	map->map_array[map_len + 1] = NULL;
}

void	check_textures_path(t_map *map)
{
	if(map->map_info_north_texture == NULL ||
		map->map_info_east_texture == NULL ||
		map->map_info_south_texture == NULL ||
		map->map_info_west_texture == NULL ||
		map->map_info_floor == NULL ||
		map->map_info_sky == NULL)
	{	
		printf("salida por path null\n");
		exit(0);
	}
}

int	line_checkeitor(char *line_map_to_check, t_map *map, int fd)
{
	if (is_empty_line(line_map_to_check) == true)
		return (printf("empty_line\n"), 0);
	if (ft_strncmp(line_map_to_check, "NO ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_north_texture));
	if (ft_strncmp(line_map_to_check, "WE ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_west_texture));
	if (ft_strncmp(line_map_to_check, "EA ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_east_texture));
	if (ft_strncmp(line_map_to_check, "SO ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_south_texture));
	if (ft_strncmp(line_map_to_check, "F ", 2) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_floor));
	if (ft_strncmp(line_map_to_check, "C ", 2) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_sky));
	else // When we arrive here we suppose it is the start of the map array.
	{
		check_textures_path(map);
		if (check_first_line_map(line_map_to_check) == ERROR)
			return (ERROR);
		allocate_map_size(line_map_to_check, map, fd);
		return (str_map_encasketeitor(map, fd));
	}
}

