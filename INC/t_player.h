#ifndef PLAYER_H
# define PLAYER_H

# include "t_coordinate.h"
# include <stdbool.h>
# include "t_player_movements.h"

#define PLAYER_MAP_COLOR 0xFF6600FF //naranja
#define CENTER_PLAYER 0.5 //FACTOR DE DESPLAZAMIENTO DE LA CASILLA EN EL CENTRO EDL JUGADOR PARA QUE NO SEA LA EZQUINA ARRIBA A LA EZQUERDA

typedef struct			s_player
{
	//t_vector	pos;
	t_coor				pos;
	t_coor				end;
	float				vision_angle;
	float				speed;
//	bool				key_w_is_released;
//	bool				key_a_is_released;
//	bool				key_s_is_released;
//	bool				key_d_is_released;
//	bool				key_left_is_released;
//	bool				key_right_is_released;
	t_player_movements	movements;
	
}						t_player;

#endif