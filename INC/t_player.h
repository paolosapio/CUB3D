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
	t_player_movements	movements;
	int					view;

	
}						t_player;

#endif