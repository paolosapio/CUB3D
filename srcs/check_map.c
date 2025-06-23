/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:22:58 by anfi              #+#    #+#             */
/*   Updated: 2025/06/23 16:38:18 by ymunoz-m         ###   ########.fr       */
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

void str_map_encasketeitor(t_map *map, int fd)
{
	char	*line;
	int		map_line_index;

	fd = open(map->arg_map_fd, O_RDONLY);
	map_line_index = 0;
	while (map->line_that_start_map-- > 0)
		free(get_next_line(fd));
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) > map->longest_line)
			map->longest_line = ft_strlen(line);
		map->map_array[map_line_index] = line;
		map_line_index++;
	}

	printf("IMPRESION FINAL DEL MAPA\n\n");
	for (int i = 0; map->map_array[i]; i++)
		printf("%s", map->map_array[i]);
}

int	line_checkeitor(char *line_map_to_check, t_map *map, int fd)
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
		map_len = 0;
		line_map_to_check = get_next_line(fd);
		printf("-- %d\n", map->line_that_start_map);
		while (line_map_to_check)
		{
			map_len++;
			free(line_map_to_check);
			line_map_to_check = get_next_line(fd);
			printf("-> %s", line_map_to_check);
		}
		// close(fd);
		map->map_array = malloc((map_len + 2) * sizeof(char *));
		map->map_array[map_len + 1] = NULL;
		str_map_encasketeitor(map, fd);
		// if (one_to_one_line_checkeitor(line_map_to_check) == OK)
		// 	map_len++;
		return (0);
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