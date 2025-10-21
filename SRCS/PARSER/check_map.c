/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/10/18 20:21:34 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief Tries to open the map and exits the program in case the file
 * was not found or an error ocured during the process.
 * 
 * @param path_map 
 * @return The file fd.
 */
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

/**
 * @brief An error printing function, that also liberates memory and exits the
 * program.
 */
void	error_exit_invalid_map(t_parser_map *parser_map, t_map *map, int error)
{
	destroy_parser_map(parser_map);
	destroy_map(map);
	write(2, "ERROR: ", 7);
	if (error == INVALID_CHAR)
		write(2, "Found an invalid char inside the map\n", 37);
	else if (error == NOT_ENCLOSED_MAP)
		write(2, "The map is not fully enclosed\n", 30);
	else if (error == TOO_MANY_PLAYERS)
		write(2, "More than one player initial position\n", 38);
	else if (error == INVALID_PLAYER_POSITION)
		write(2, "The player initial position is invalid\n", 39);
	else if (error == NO_PLAYER)
		write(2, "No player initial position\n", 27);
	else if (error == EMPTY_MAP)
		write(2, "The map is empty\n", 17);
	else
		write(2, "Undefined error\n", 16);
	exit(1);
}

/**
 * @brief Iterates over the map array, checks that there is no invalid character
 * inside and calls the corresponding function for each valid character.
 */
void	check_valid_map(t_parser_map *parser_map, t_map *map)
{
	int	x;
	int	y;

	if (!map->array)
		error_exit_invalid_map(parser_map, map, EMPTY_MAP);
	y = 0;
	while (map->array[y])
	{
		x = 0;
		while (map->array[y][x])
		{
			if (ft_strchr(VALID_CHARS, map->array[y][x]) == NULL)
				error_exit_invalid_map(parser_map, map, INVALID_CHAR);
			if (ft_strchr(PLAYER, map->array[y][x]) != NULL)
				check_player(parser_map, map, x, y);
			if (ft_strchr(FLOOR, map->array[y][x]) != NULL)
			{
				if (is_around_space_ok(map, x, y) == ERROR)
					error_exit_invalid_map(parser_map, map, NOT_ENCLOSED_MAP);
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Once the extension has been verified, we check the map content.
 * 
 * We check the map exists, read it all (twice) with gnl, make sure the images
 * textures and color codes are all inside, and that it is indeed a valid map
 * with it's initial player's position and being all enclosed by walls and no
 * unexpected character inside.
 */
void	check_map(char *path_map, t_parser_map *parser_map, t_map *map)
{
	char	*line_map_to_check;
	int		fd;

	parser_map->map_path = path_map;
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
