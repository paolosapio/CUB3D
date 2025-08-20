#ifndef PLAYER_H
# define PLAYER_H

# include "t_coordinate.h"
# include <stdbool.h>

#define PLAYER_MAP_COLOR 0xFF6600FF //naranja

typedef struct			s_player
{
	//t_vector	pos;
	t_coor				pos;
	t_coor				end;
	float				vision_angle;
	float				speed;
	bool				key_is_released;
}						t_player;

#endif