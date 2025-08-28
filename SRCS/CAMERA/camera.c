#include "camera.h"
#include <math.h>
#include "t_game.h"
#include "../TOOLS_GRAPHICS/tools_graphics.h"




void init_camera(t_game *game, t_coor player_coor, float player_vision_angle)
{
	// t_camera	camera;

	t_coor		middle_screen_point;
	t_coor		l_screen_point;
	t_coor		r_screen_point;

	middle_screen_point.x = (player_coor.x - (cos(to_radians(player_vision_angle)) * DISTANCE_SCREEN));
	middle_screen_point.y = (player_coor.y - (sin(to_radians(player_vision_angle)) * DISTANCE_SCREEN));

	l_screen_point.x = (middle_screen_point.x - cos(to_radians(player_vision_angle - 90)) * HALF_SCREEN);
	l_screen_point.y = (middle_screen_point.y - sin(to_radians(player_vision_angle - 90)) * HALF_SCREEN);

	r_screen_point.x = (middle_screen_point.x - cos(to_radians(player_vision_angle + 90)) * HALF_SCREEN);
	r_screen_point.y = (middle_screen_point.y - sin(to_radians(player_vision_angle + 90)) * HALF_SCREEN);

	bresenham_algorithm(game->images.map_ray,
		l_screen_point.x * game->map.tile_size,
		l_screen_point.y * game->map.tile_size,
		r_screen_point.x * game->map.tile_size,
		r_screen_point.y * game->map.tile_size)
	;

	bresenham_algorithm(game->images.map_ray,
						l_screen_point.x++ * game->map.tile_size,
						l_screen_point.y * game->map.tile_size,
						player_coor.x * game->map.tile_size,
						player_coor.y * game->map.tile_size)
	;

	bresenham_algorithm(game->images.map_ray,
		player_coor.x * game->map.tile_size,
		player_coor.y * game->map.tile_size,
		r_screen_point.x * game->map.tile_size,
		r_screen_point.y * game->map.tile_size)
	;
	printf("r_screen_point.x:[%f]\n", r_screen_point.x);

}