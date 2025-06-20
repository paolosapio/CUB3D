/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:22:58 by anfi              #+#    #+#             */
/*   Updated: 2025/06/20 21:45:47 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//ponemos la texture en map_info[NORTH_TEXTURE]

#define OK 0
#define ERROR 1

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

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(" \n", line[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}
int	one_to_one_line_checkeitor(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
			break ;
	}

	if (line[i] && line[i] == '1')
	{
		while (line[i])
			i++;
		if (line[i - 1] == '1')
			return (OK);
		else
			return (ERROR);
	}
	return (ERROR);
}

int	line_checkeitor(char *line_map_to_check, t_map *map, int *fd)
{
	int	map_len;

	map_len = 0;

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
		printf("aaaa\n");
		map_len = 0;
		line_map_to_check = get_next_line(*fd);
		while (line_map_to_check)
		{
			map_len++;
			free(line_map_to_check);
			line_map_to_check = get_next_line(*fd);
			printf("-> %s", line_map_to_check);
		}
		printf("map_len =) %d\n", map_len);

		// if (one_to_one_line_checkeitor(line_map_to_check) == OK)
		// 	map_len++;
		return (0);
	}
}

void check_map(char *arg_map, t_map *map)
{
	char *line_map_to_check;
	int  fd;

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
		if (line_checkeitor(line_map_to_check, map, &fd) == ERROR)
		{
			printf("invalid line: %s", line_map_to_check);
			free(line_map_to_check);
			break ;
		}
		printf("💩%s", line_map_to_check);
		free(line_map_to_check);
	}
	printf("%s", map->map_info_north_texture);
	exit(0);
}