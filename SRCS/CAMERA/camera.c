#include "camera.h"
#include <math.h>

t_camera init_camera(t_coor player_coor, float player_vision_angle)
{
	t_coor middle_screen_point;
	t_coor left_screen_point;
	t_camera	camera;

	camera.distance_of_player = 150;
	camera.screen = 150;
	middle_screen_point.x = player_coor.x + (cos(to_ra));


}