/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/10/06 16:23:19 by psapio           ###   ########.fr       */
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
	exit(1);
}

t_errok	is_around_space_ok(t_map *map, int x, int y)
{
	if (y == 0 || x > (int)ft_strlen(map->array[y - 1])
		|| ft_strchr(FLOOR "" WALL "" PLAYER, map->array[y - 1][x]) == NULL)
	{
		return (ERROR);
	}
	if (map->array[y][x + 1] != '\0' && ft_strchr(FLOOR "" WALL "" PLAYER,
			map->array[y][x + 1]) == NULL)
	{
		return (ERROR);
	}
	if (y + 1 == map->map_len || x > (int)ft_strlen(map->array[y + 1])
		|| ft_strchr(FLOOR "" WALL "" PLAYER, map->array[y + 1][x]) == NULL)
	{
		return (ERROR);
	}
	if (x > 0 && ft_strchr(FLOOR "" WALL "" PLAYER, map->array[y][x
			- 1]) == NULL)
		return (ERROR);
	return (OK);
}

void	collisions_movements(t_map *map, t_coor pos, int vision_angle,
			t_greco_dir dir)
{
	map->player_pointer->vision_angle = vision_angle;
	map->player_pointer->greco_map_dir = dir;
	map->player_pointer->end.x = pos.x + CENTER_PLAYER;
	map->player_pointer->end.y = pos.y + CENTER_PLAYER - LIMIT_FOV;
}

void	check_player(t_parser_map *parser_map, t_map *map, int x, int y)
{
	if (map->player_pointer->pos.x != 0)
		error_exit_invalid_map(parser_map, map, TOO_MANY_PLAYERS);
	if (is_around_space_ok(map, x, y) == ERROR)
		error_exit_invalid_map(parser_map, map, INVALID_PLAYER_POSITION);
	map->player_pointer->pos.x = x + CENTER_PLAYER;
	map->player_pointer->pos.y = y + CENTER_PLAYER;
	if (map->array[y][x] == 'N')
		collisions_movements(map, (t_coor){x, y}, 90, N_);
	else if (map->array[y][x] == 'E')
		collisions_movements(map, (t_coor){x, y}, 0, E_);
	else if (map->array[y][x] == 'S')
		collisions_movements(map, (t_coor){x, y}, 270, S_);
	else if (map->array[y][x] == 'W')
		collisions_movements(map, (t_coor){x, y}, 180, W_);
}

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
