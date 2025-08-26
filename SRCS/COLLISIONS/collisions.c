#include "../MOVEMENTS/movements.h"
#include "collisions.h"

bool	check_diagonal_collision(char mask)
{
	if ((mask & UPWARDS_DIAGONAL) == UPWARDS_DIAGONAL)
		return (true);
	if ((mask & DOWNWARDS_DIAGONAL) == DOWNWARDS_DIAGONAL)
		return (true);
	return (false);
}

t_antenas activate_antennas(float speed, t_coor new_pos, float tile_size)
{
	const float	half_tile = 1.0 / tile_size * speed;
	t_antenas	antenas;

	antenas.up_left.x = new_pos.x - half_tile;
	antenas.up_left.y = new_pos.y - half_tile;
	antenas.up_right.x = new_pos.x + half_tile;
	antenas.up_right.y = new_pos.y - half_tile;
	antenas.down_left.x = new_pos.x - half_tile;
	antenas.down_left.y = new_pos.y + half_tile;
	antenas.down_right.x = new_pos.x + half_tile;
	antenas.down_right.y = new_pos.y + half_tile;

	return (antenas);
}

bool collision_antenas(float speed, t_coor new_player_pos, t_map *map)
{
	unsigned char	mask;
	t_antenas		antenas;

	antenas = activate_antennas(speed, new_player_pos, map->tile_size);
	mask = 0;

	//printf("%b -> mask\n", mask);
	if (map->array[antenas.up_left.y][antenas.up_left.x] == WALL)
		mask |= UP_LEFT_ANTENNA;
	if (map->array[antenas.up_right.y][antenas.up_right.x] == WALL)
		mask |= UP_RIGHT_ANTENNA;
	if (map->array[antenas.down_left.y][antenas.down_left.x] == WALL)
		mask |= DOWN_LEFT_ANTENNA;
	if (map->array[antenas.down_right.y][antenas.down_right.x] == WALL)
		mask |= DOWN_RIGHT_ANTENNA;
	if (check_diagonal_collision(mask))
		return (true);
	return (false);
}
