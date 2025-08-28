#include "camera.h"
#include <math.h>
#include "t_game.h"
#include "../TOOLS_GRAPHICS/tools_graphics.h"


float	pixeleitor(t_game *game)
{
	float pixel_size;

	pixel_size = 1 / game->map.tile_size;
	return (pixel_size);
}

void init_camera(t_game *game, t_coor player_coor, float player_vision_angle)
{
	// t_camera	camera;

	t_coor			middle_screen_point;
	t_coor			l_screen_point;
	t_coor			r_screen_point;
	float			pixel_offset_cos;
	float			pixel_offset_sen;

	// static float 	new_position_point;

	middle_screen_point.x = player_coor.x - cos(to_radians(player_vision_angle)) * DISTANCE_SCREEN;
	middle_screen_point.y = player_coor.y - sin(to_radians(player_vision_angle)) * DISTANCE_SCREEN;


	// middle_screen_point.x = (player_coor.x - pixel_size_anchura);
	// middle_screen_point.y = (player_coor.y - new_position_y);

	// new_position_y = new_position_y + pixel_size_altura;

	pixel_offset_cos = cos(to_radians(player_vision_angle - 90)) / game->map.tile_size;
	pixel_offset_sen = sin(to_radians(player_vision_angle - 90)) / game->map.tile_size;

	printf("pixel_offset_cos = %f\n", pixel_offset_cos);
	printf("pixel_offset_sen = %f\n", pixel_offset_sen);

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


	int i = 0;
	while (i < game->map.tile_size * SCREEN)
	{
		bresenham_algorithm(game->images.map_ray,
							(l_screen_point.x + pixel_offset_cos) * game->map.tile_size,
							(l_screen_point.y + pixel_offset_sen) * game->map.tile_size,
							player_coor.x * game->map.tile_size,
							player_coor.y * game->map.tile_size)
		;
		printf("l_screen_point.x %f | %f\n", l_screen_point.x, r_screen_point.x);
		printf("l_screen_point.y %f | %f\n", l_screen_point.y, r_screen_point.y);
		// if (l_screen_point.x != r_screen_point.x)
			l_screen_point.x += pixel_offset_cos;
		// if (l_screen_point.y != r_screen_point.y)
			l_screen_point.y += pixel_offset_sen;
		i++;
	}

	bresenham_algorithm(game->images.map_ray,
		player_coor.x * game->map.tile_size,
		player_coor.y * game->map.tile_size,
		r_screen_point.x * game->map.tile_size,
		r_screen_point.y * game->map.tile_size)
	;
	printf("r_screen_point.x:[%f]\n", r_screen_point.x);
}