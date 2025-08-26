
#ifndef COLLISION_H
# define COLLISION_H

# include "t_coordinate.h"

# define UP_LEFT_ANTENNA 0b1
# define UP_RIGHT_ANTENNA 0b10
# define DOWN_LEFT_ANTENNA 0b100
# define DOWN_RIGHT_ANTENNA 0b1000

# define UPWARDS_DIAGONAL 0b110 // DOWN_LEFT_ANTENNA | UP_RIGHT_ANTENNA
# define DOWNWARDS_DIAGONAL 0b1001 //UP_LEFT_ANTENNA | DOWN_RIGHT_ANTENNA

# define WALL '1'

typedef struct	s_antenas
{
	t_int_coor	up_left;
	t_int_coor	up_right;
	t_int_coor	down_left;
	t_int_coor	down_right;
}				t_antenas;

// colisions.c
bool collision_antenas(float speed, t_coor new_player_pos, t_map *map);

#endif