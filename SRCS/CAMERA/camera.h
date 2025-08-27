#ifndef CAMERA_H
# define CAMERA_H

#include "t_coordinate.h"
#include "../TOOLS_GENERICS/tools_generics.h"

// FOV : FIELD OF VIEW (campo visual, lo que vemos en pantalla)
	// distancia de la pantalla del jugador y tamaño de la pantalla varian la vision


// definir la pantalla
typedef struct	s_camera
{
	unsigned int	screen;
	unsigned int	distance_of_player;
	float			angle_of_view;
}				t_camera;

#endif