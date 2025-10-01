/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_encasketeitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:03:30 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 22:03:31 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	reopen_map(char *map_path, int fd)
{
	close(fd);
	fd = open(map_path, O_RDONLY);
}

void	skip_lines(t_parser_map *map, int fd)
{
	while (map->line_that_start_map-- > 0)
		free(get_next_line(fd));
}

int	line_len(int size_line, int old_bigger_line)
{
	if (size_line > old_bigger_line)
		return (size_line);
	return (old_bigger_line);
}

int	str_map_encasketeitor(t_parser_map *parser_map, t_map *map, int fd)
{
	char	*line;
	char	*aux_line;
	int		map_line_index;

	map_line_index = 0;
	reopen_map(parser_map->arg_map_fd, fd);
	skip_lines(parser_map, fd);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		aux_line = ft_strtrim(line, "\n");
		map->longest_line = line_len(ft_strlen(aux_line), map->longest_line);
		free(aux_line);
		map->array[map_line_index] = line;
		map_line_index++;
	}
	map->map_len = map_line_index;
	if (ft_strcmp(map->array[map->map_len - 1], "\n") == 0)
		return (ERROR);
	return (OK);
}
