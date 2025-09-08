#include "camera.h"
#include <math.h>
#include "t_game.h"
#include "../REFRESH_GAME/refresh_game.h"
#include "../TOOLS_GRAPHICS/tools_graphics.h"


float	pixeleitor(void)
{
	float pixel_size;

	pixel_size = 1.0 / g_size_tile;
	return (pixel_size);
}


void init_camera(t_game *game, t_coor player_coor, float player_vision_angle)
{
	// t_camera	camera;
	(void)game;
	t_coor			middle_screen_point;
	t_coor			l_screen_point;
	t_coor		photon_final_destination;
	t_coor		collision_point;
	float			pixel_offset_cos;
	float			pixel_offset_sen;
	unsigned int	i;

	middle_screen_point.x = player_coor.x - cos(to_radians(player_vision_angle)) * DISTANCE_SCREEN;
	middle_screen_point.y = player_coor.y - sin(to_radians(player_vision_angle)) * DISTANCE_SCREEN;

	pixel_offset_cos = cos(to_radians(player_vision_angle - 90)) / g_size_tile;
	pixel_offset_sen = sin(to_radians(player_vision_angle - 90)) / g_size_tile;

	l_screen_point.x = (middle_screen_point.x - cos(to_radians(player_vision_angle - 90)) * HALF_SCREEN);
	l_screen_point.y = (middle_screen_point.y - sin(to_radians(player_vision_angle - 90)) * HALF_SCREEN);

	bresenham_algorithm(game->images.map_ray, player_coor, game->player.end, color(255, 255, 255, 255));
	// bresenham_algorithm(game->images.map_ray, player_coor, l_screen_point, color(0, 255, 0, 255));
	
	photon_final_destination.x = l_screen_point.x - cos(to_radians(player_vision_angle)) * 7;
	photon_final_destination.y = l_screen_point.y - sin(to_radians(player_vision_angle)) * 7;
	
	collision_point = raycasting(game->images.map_ray, game->player, game->map, l_screen_point);
	// bresenham_algorithm(game->images.map_ray, player_coor, collision_point, color(0, 255, 0, 255));

	i = 0;
	while (i < g_size_tile * SCREEN)
	{
		// bresenham_algorithm(game->images.map_ray, l_screen_point, player_coor, color(255, 0, 0, 100));
		//bresenham_algorithm(game->images.map_ray, photon_final_destination, l_screen_point, color(0, 255, 0, 100));

			l_screen_point.x += pixel_offset_cos;
			l_screen_point.y += pixel_offset_sen;
			photon_final_destination.x += pixel_offset_cos;
			photon_final_destination.y += pixel_offset_sen;
		i++;
	}
}