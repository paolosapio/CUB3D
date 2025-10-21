/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/10/18 14:21:14 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief Is called whenever the player or a floor tile is found to check if the
 * map is properly enclosed. It checks the orthogonally adjacent tiles, the four
 * of them need to be another floor tile (0), a wall tile (1) or the player tile
 * (N,S,E,O). If it finds a space, the map is not enclosed. Invalid map.
 * 
 * @param map
 * @param x,y Tile coordinates
 */
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

/**
 * @brief Initialices the player's information.
 * 
 * @param map The map, holding a pointer to the player's struct.
 * @param pos  the player's coordinates.
 * @param vision_angle E->0, N->90, W->180, S->270.
 * @param dir t_greco_dir.
 */
static void	collisions_movements(t_map *map, t_coor pos, int vision_angle,
			t_greco_dir dir)
{
	map->player_pointer->vision_angle = vision_angle;
	map->player_pointer->greco_map_dir = dir;
	map->player_pointer->end.x = pos.x + CENTER_PLAYER;
	map->player_pointer->end.y = pos.y + CENTER_PLAYER - LIMIT_FOV;
}

/**
 * @brief Checks that the map has a valid player initial position, that being
 * having only one and it being around floor or walls and initialices
 * some values inside the player's struct.
 */
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
