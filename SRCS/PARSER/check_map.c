/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/10/01 22:17:11 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	fd_open_or_exit(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
	{
		perror(path_map);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	check_map(char *path_map, t_parser_map *parser_map, t_map *map)
{
	char	*line_map_to_check;
	int		fd;

	parser_map->arg_map_fd = path_map;
	fd = fd_open_or_exit(path_map);
	while (1)
	{
		line_map_to_check = get_next_line(fd);
		if (line_map_to_check == NULL)
			break ;
		if (check_line(line_map_to_check, map, parser_map, fd) == ERROR)
		{
			printf("invalid line: %s\n", line_map_to_check);
			free(line_map_to_check);
			destroy_parser_map(parser_map);
			destroy_map(map);
			close(fd);
			exit(1);
		}
		parser_map->line_that_start_map++;
		free(line_map_to_check);
	}
	check_valid_map(parser_map, map);
	if (map->player_pointer->pos.x == 0)
		error_exit_invalid_map(parser_map, map, NO_PLAYER);
}
