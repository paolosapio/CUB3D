#include "../MOVEMENTS/movements.h"
#include "collisions.h"

#define 	ACTIVATED '1'
#define		EMPTY '\0'




// bool	is_there_collision(t_player player, t_map map, t_coor *new_player_pos)
// {
// 	int x;
// 	int y;



// 	printf("\n---------------\n");
// 	printf("angulo: %f\n", player.vision_angle);
// 	printf("1. SIN CAMBIOS: x: %f y: %f\n", new_player_pos->x, new_player_pos->y);
	
// 	 -= (sin((player.vision_angle / 180) * M_PI) / 10) * player.speed;
// 	new_player_pos->x -= (cos((player.vision_angle / 180) * M_PI) / 10) * player.speed;
	
// 	printf("2.  COORDENADA A MOVERSE: x: %f y: %f\n", new_player_pos->x, new_player_pos->y);
// 	position_plus_radius.x = new_player_pos->x;
// 	position_plus_radius.y = new_player_pos->y;

// 	x = (int)position_plus_radius.x;
// 	y = (int)position_plus_radius.y;
// 	printf("_%c_\n", map.array[y][x]);

// 	return (false);
// }

