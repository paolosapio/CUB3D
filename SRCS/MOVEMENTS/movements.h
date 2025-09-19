

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include <math.h>
# include "t_game.h"
# include "../DRAW_GAME/draw_game.h"
# include "../REFRESH_GAME/refresh_game.h"
# include "../TOOLS_GENERICS/tools_generics.h"
# include "t_player_movements.h"

# define LIMIT_FOV 1.5

# define SLOW 0.5
# define NORMAL 1
# define TURBO 2

typedef struct	s_trig_angle
{
	float	angle;
	float	s1n;
	float	c0s;
}			t_trig_angle;


//movements_player.c

void	move_line_direction(t_player *player, float sen, float cos);
void	move_player(t_player *player, t_map *map, float sen, float cos);
void	change_player_rotation(t_player *player, int new_vision_angle);
void	movements_player(void *params);

bool	antennas_north(t_player player, t_map map);
bool	antennas_south(t_player player, t_map map);
bool	antennas_left(t_player player, t_map map);
bool	antennas_right(t_player player, t_map map);

#endif