#ifndef CAMERA_H
# define CAMERA_H

# include <stdio.h>
# include "t_coordinate.h"
# include "../TOOLS_GENERICS/tools_generics.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"

# define SCREEN 10 //!celdas!
# define HALF_SCREEN  SCREEN / 2//!celdas!
# define DISTANCE_SCREEN 10 //!celdas!

// FOV : FIELD OF VIEW (campo visual, lo que vemos en pantalla)
	// distancia de la pantalla del jugador y tamaño de la pantalla varian la vision


// definir la pantalla
typedef struct	s_camera
{
	// unsigned int	screen;
	// unsigned int	distance_of_player;
	float			angle_of_view;
}				t_camera;

typedef struct	s_ray
{
	t_coor	colision_point;
	float	colision_len;
}				t_ray;

void	init_camera(t_game *game, t_coor player_coor, float player_vision_angle);
t_ray	raycasting(t_coor start_pos, t_coor end_pos, t_map map);
void	to_3d(mlx_image_t *image, float ray_len, int x_axis);

#endif
