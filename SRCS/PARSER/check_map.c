/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/08/18 11:47:08 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	exit (1);
}

t_errok is_around_space_ok(t_map *map, int x, int y)
{
	if (y == 0 || x > (int)ft_strlen(map->array[y - 1]) ||
		ft_strchr(FLOOR""WALL""PLAYER, map->array[y - 1][x]) == NULL)
	{
		return (ERROR);
	}
	if (map->array[y][x + 1] != '\0' &&
		ft_strchr(FLOOR""WALL""PLAYER, map->array[y][x + 1]) == NULL)
	{
		return (ERROR);
	}
	if (y + 1 == map->map_len || x > (int)ft_strlen(map->array[y + 1]) ||
		ft_strchr(FLOOR""WALL""PLAYER, map->array[y + 1][x]) == NULL)
	{
		return (ERROR);
	}
	if (x > 0 && ft_strchr(FLOOR""WALL""PLAYER, map->array[y][x - 1]) == NULL)
		return (ERROR);
	return (OK);
}

void	check_player(t_parser_map *parser_map, t_map *map, int x, int y)
{
	if (map->player_pointer->pos.x != 0)
		error_exit_invalid_map(parser_map, map, TOO_MANY_PLAYERS);
	if (is_around_space_ok(map, x, y) == ERROR)
		error_exit_invalid_map(parser_map, map, INVALID_PLAYER_POSITION);
	map->player_pointer->pos.x = x;
	map->player_pointer->pos.y = y;
	if (map->array[y][x] == 'N')
	{
		map->player_pointer->vision_angle = 90;
		map->player_pointer->end.x = x;
		map->player_pointer->end.y = y - LIMIT_FOV;
	}
	else if (map->array[y][x] == 'E')
	{
		map->player_pointer->vision_angle = 0;
		map->player_pointer->end.x = x + LIMIT_FOV;
		map->player_pointer->end.y = y;
	}
	else if (map->array[y][x] == 'S')
	{
		map->player_pointer->vision_angle = 270;
		map->player_pointer->end.x = x;
		map->player_pointer->end.y = y + LIMIT_FOV;
	}
	else if (map->array[y][x] == 'W')
	{
		map->player_pointer->vision_angle = 180;
		map->player_pointer->end.x = x - LIMIT_FOV;
		map->player_pointer->end.y = y;
	}
}

void check_valid_map(t_parser_map *parser_map, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	if (!map->array)
	{
		error_exit_invalid_map(parser_map, map, EMPTY_MAP);
	}
	while (map->array[y])
	{
		x = 0;
		while(map->array[y][x])
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

void	check_map(char *path_map, t_parser_map *parser_map, t_map *map)
{
	char *line_map_to_check;
	int	fd;

	parser_map->arg_map_fd = path_map;
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
		if (line_checkeitor(line_map_to_check, map, parser_map, fd) == ERROR)
		{
			printf("invalid line: %s\n", line_map_to_check);
			free(line_map_to_check);
			destroy_parser_map(parser_map);
			destroy_map(map);
			close(fd);
			exit (1);
		}
		parser_map->line_that_start_map++;
		free(line_map_to_check);
	}
	check_valid_map(parser_map, map);
	if (map->player_pointer->pos.x == 0)
		error_exit_invalid_map(parser_map, map, NO_PLAYER);
}
