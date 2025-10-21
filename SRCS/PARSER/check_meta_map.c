/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meta_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:22:58 by anfi              #+#    #+#             */
/*   Updated: 2025/10/18 14:21:06 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief Saves the color or texture path read from the .cub into parser_map.
 * Doesn't check the texture or the color are valid, only checks it's format.

 * @param line_map_to_check A correct line should look something  like:
 	"NO ./file.png". An invalid one: "NO" or "NO ./file.png something_else"
 * @param map_info The pointer to the char * that will hold the path or the
 	color.
 */
int	save_map_info(char *line_map_to_check, char **map_info)
{
	char	**splitted;

	if (*map_info)
		return (ERROR);
	splitted = ft_split(line_map_to_check, ' ');
	if ((ft_arraylen((const char **)splitted) == 2 && splitted[1][0] != '\n') ||
		(ft_arraylen((const char **)splitted) == 3 && splitted[2][0] == '\n'))
	{
		*map_info = ft_strtrim(splitted[1], "\n");
		free_double_pointer(splitted);
		return (OK);
	}
	free_double_pointer(splitted);
	return (ERROR);
}

/**
 * @brief Reads the remaining file to know how big the map is in order to
 * allocate the array for it.
 */
void	allocate_map_size(char *line_map_to_check, t_map *map, int fd)
{
	int	map_len;

	map_len = 0;
	line_map_to_check = get_next_line(fd);
	while (line_map_to_check)
	{
		map_len++;
		free(line_map_to_check);
		line_map_to_check = get_next_line(fd);
	}
	map->array = malloc((map_len + 2) * sizeof(char *));
	map->array[map_len + 1] = NULL;
}

/**
 * @brief Checks that all the information needed for the game to work was inside
 * the .cub file. If any of these char * inside the parser_map is NULL means
 * there was no line containing the information for it.
  */
void	check_textures_path(t_parser_map *map)
{
	if (map->path_n == NULL
		|| map->path_e == NULL
		|| map->path_s == NULL
		|| map->path_w == NULL
		|| map->info_floor == NULL
		|| map->info_sky == NULL)
	{
		write(2, "INVALID PATH\n", 14);
		exit(0);
	}
}

/**
 * @brief This function is called for each line gnl reads from the .cub file.
 * It enters the specified `if` to save inside the map structure the information
 * relative to the textures path or the color code.
 * If some other information is found it will return ERROR leading the program
 * to end.
 * 
 * Once all information has been saved, str_map_encasketeitor will start to
 * save the map array.
 * @param line_map_to_check the line read with gnl.
 * @param map the map struct
 * @param p_map
 * @param fd
 * @return int
 */
int	check_line(char *line_map_to_check, t_map *map, t_parser_map *p_map, int fd)
{
	if (is_empty_line(line_map_to_check) == true)
		return (OK);
	if (ft_strncmp(line_map_to_check, "NO ", 3) == 0)
		return (save_map_info(line_map_to_check, &p_map->path_n));
	if (ft_strncmp(line_map_to_check, "WE ", 3) == 0)
		return (save_map_info(line_map_to_check, &p_map->path_w));
	if (ft_strncmp(line_map_to_check, "EA ", 3) == 0)
		return (save_map_info(line_map_to_check, &p_map->path_e));
	if (ft_strncmp(line_map_to_check, "SO ", 3) == 0)
		return (save_map_info(line_map_to_check, &p_map->path_s));
	if (ft_strncmp(line_map_to_check, "F ", 2) == 0)
		return (save_map_info(line_map_to_check, &p_map->info_floor));
	if (ft_strncmp(line_map_to_check, "C ", 2) == 0)
		return (save_map_info(line_map_to_check, &p_map->info_sky));
	else
	{
		check_textures_path(p_map);
		if (check_first_line_map(line_map_to_check) == ERROR)
			return (ERROR);
		allocate_map_size(line_map_to_check, map, fd);
		return (str_map_encasketeitor(p_map, map, fd));
	}
}
