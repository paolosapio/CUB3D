#include "../MOVEMENTS/movements.h"
#include "collisions.h"

#define 	ACTIVATED '1'

float	degrees_to_radius(float degrees)
{
	return ((degrees / 180) * M_PI);
}


bool	is_there_collision(t_player player, t_map map, t_coor *new_player_pos)
{
	int x;
	int y;
	t_coor position_plus_radius;

	new_player_pos->y = player.pos.y;
	new_player_pos->x = player.pos.x;
	
	new_player_pos->y -= (sin((player.vision_angle / 180) * M_PI) / 10) * player.speed;
	new_player_pos->x -= (cos((player.vision_angle / 180) * M_PI) / 10) * player.speed;
	
	position_plus_radius
	x = (int)new_player_pos->x;
	y = (int)new_player_pos->y;
	if (map.array[y][x] == ACTIVATED)
	{
		return (true);
	}
	return (false);
}

