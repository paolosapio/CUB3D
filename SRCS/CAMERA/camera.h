#ifndef CAMERA_H
# define CAMERA_H

# include "t_coordinate.h"
# include "../TOOLS_GENERICS/tools_generics.h"

# define SCREEN 3 //!celdas!
# define HALF_SCREEN  SCREEN / 2//!celdas!
# define DISTANCE_SCREEN 1.5 //!celdas!

// FOV : FIELD OF VIEW (campo visual, lo que vemos en pantalla)
	// distancia de la pantalla del jugador y tamaño de la pantalla varian la vision


// definir la pantalla
typedef struct	s_camera
{
	// unsigned int	screen;
	// unsigned int	distance_of_player;
	float			angle_of_view;
}				t_camera;


void	init_camera(t_game *game, t_coor player_coor, float player_vision_angle);
void	photoneitor(t_game *game, t_coor l_screen_point, t_coor r_screen_point, float player_vision_angle);


#endif
