/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/07/24 19:56:27 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_valid_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_array[y])
	{
		x = 0;
		while(map->map_array[y][x])
		{
			if (map->map_array[y][x] == ' ')
				printf("HOLA SPACE\n");
			x++;
		}
		y++;
	}
	// is_around_space_ok();
}

void check_map(char *path_map, t_map *map)
{
	char *line_map_to_check;
	int  fd;

	map->arg_map_fd = path_map;
	fd = open(path_map, O_RDONLY);
	if (fd == -1)
	{
		perror(path_map);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line_map_to_check = get_next_line(fd);
		if (line_map_to_check == NULL)
			break ;
		if (line_checkeitor(line_map_to_check, map, fd) == ERROR)
		{
			printf("invalid line: %s\n", line_map_to_check);
			free(line_map_to_check);
			destroy_map(map);
			close(fd);
			exit (1);
		}
		map->line_that_start_map++;
		free(line_map_to_check);
	}
	check_valid_map(map);
}
