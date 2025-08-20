

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include <math.h>
# include "t_game.h"
# include "../DRAW_GAME/draw_game.h"

# define M_PI 3.14159265358979323846

# define LIMIT_FOV 10

# define SLOW 0.5
# define NORMAL 1
# define TURBO 2

typedef enum	e_player_movements
{
	PLAYER_STOP_RIGHT,
	PLAYER_LEFT,
	PLAYER_RIGHT,
	PLAYER_UP,
	PLAYER_DOWN,
	PLAYER_STOP_LEFT,
	PLAYER_STOP_UP,
	PLAYER_STOP_DOWN,
}				t_player_movements;

//movements_player.c

void	move_line_direction(t_player *player);
void	move_player(t_player *player, t_map *map);
void	change_player_rotation(t_player *player, int new_vision_angle);
void	movements_player(void *params);

bool	antennas_north(t_player player, t_map map);
bool	antennas_south(t_player player, t_map map);
bool	antennas_left(t_player player, t_map map);
bool	antennas_right(t_player player, t_map map);

#endif