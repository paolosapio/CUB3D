/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_encasketeitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:03:30 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 20:21:34 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief Since we finished reading the map inside allocate_map_size(), we need
 * to reopen it to be able to read it again.
 */
static void	reopen_map(char *map_path, int fd)
{
	close(fd);
	fd = open(map_path, O_RDONLY);
}

/**
 * @brief skips the lines that we already checked while saving all the images
 * textures to start working with the map.
 */
static void	skip_lines(t_parser_map *map, int fd)
{
	while (map->line_that_start_map-- > 0)
		free(get_next_line(fd));
}

/**
 * @brief We want to keep track of which s the longest line inside the map. This
 * function only checks if the new read line is longer than our current
 * longest line. Easy peasy.
 */
static int	line_len(int size_line, int old_bigger_line)
{
	if (size_line > old_bigger_line)
		return (size_line);
	return (old_bigger_line);
}

/**
 * @brief Saves the map array inside the map structure. The only comprobation
 * it makes is that the map doesn't end with more than one empty line, since
 * this affects the way the map is viewed inside the game.
 */
int	str_map_encasketeitor(t_parser_map *parser_map, t_map *map, int fd)
{
	char	*line;
	char	*aux_line;
	int		map_line_index;

	map_line_index = 0;
	reopen_map(parser_map->map_path, fd);
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
	if (is_empty_line(map->array[map->map_len - 1]) == true
		&& is_empty_line(map->array[map->map_len - 2]) == true)
		return (ERROR);
	return (OK);
}
