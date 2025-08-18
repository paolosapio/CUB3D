#ifndef PLAYER_H
# define PLAYER_H

# include "t_coordinate.h"
# include "t_player_movements.h"

#define PLAYER_MAP_COLOR 0xFF6600FF //naranja

typedef struct			s_player
{
	//t_vector	pos;
	t_coor				pos;
	t_coor				end;
	float				vision_angle;
	t_player_movements	movement;
}						t_player;

#endif