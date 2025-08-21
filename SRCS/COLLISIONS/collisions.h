
#ifndef COLLISION_H
# define COLLISION_H

# include "t_coordinate.h"


typedef  t_coor t_antenna;

bool	is_there_collision(t_player player, t_map map, t_coor *new_player_pos);

#endif