/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:22:58 by anfi              #+#    #+#             */
/*   Updated: 2025/06/23 21:52:26 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	save_map_info(char *line_map_to_check, char **map_info)
{
	char **splitted;

	if (*map_info)
		return (ERROR);
	splitted = ft_split(line_map_to_check, ' ');
	if (ft_arraylen((const char **)splitted) == 2 ||
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
		map_len++;
		free(line_map_to_check);
		line_map_to_check = get_next_line(fd);
	}
	map->map_array = malloc((map_len + 2) * sizeof(char *));
	map->map_array[map_len + 1] = NULL;
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
	else
	{
		allocate_map_size(line_map_to_check, map, fd);
		return (str_map_encasketeitor(map, fd));
	}
}

void check_map(char *arg_map, t_map *map)
{
	char *line_map_to_check;
	int  fd;

	map->arg_map_fd = arg_map;
	fd = open(arg_map, O_RDONLY);
	if (fd == -1)
	{
		perror(arg_map);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line_map_to_check = get_next_line(fd);
		if (line_map_to_check == NULL)
			break ;
		if (line_checkeitor(line_map_to_check, map, fd) == ERROR)
		{
			printf("invalid line: %s", line_map_to_check);
			free(line_map_to_check);
			break ;
		}
		map->line_that_start_map++;
		free(line_map_to_check);
	}
}