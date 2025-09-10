#include "render.h"
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
	t_coor		middle_screen_point;
	t_coor		l_screen_point;
	float		pixel_offset_cos;
	float		pixel_offset_sen;
	t_ray		ray;
	int			ray_to_screen;
	const float	ray_to_screen_aux = (float)(SCREEN * g_size_tile) / WIDTH;

	middle_screen_point.x = player_coor.x - cos(to_radians(player_vision_angle)) * DISTANCE_SCREEN;
	middle_screen_point.y = player_coor.y - sin(to_radians(player_vision_angle)) * DISTANCE_SCREEN;
	pixel_offset_cos = cos(to_radians(player_vision_angle - 90)) / WIDTH * SCREEN;
	pixel_offset_sen = sin(to_radians(player_vision_angle - 90)) / WIDTH * SCREEN;
	l_screen_point.x = (middle_screen_point.x - cos(to_radians(player_vision_angle - 90)) * HALF_SCREEN);
	l_screen_point.y = (middle_screen_point.y - sin(to_radians(player_vision_angle - 90)) * HALF_SCREEN);	
	ray_to_screen = ray_to_screen_aux;

	while (ray_to_screen < WIDTH)
	{
		ray = raycasting(game->player.pos, l_screen_point, game->map);
		if (ray_to_screen % 5 == 0)
		{
			bresenham_algorithm(game->images.map_ray, player_coor, ray.colision_point, color(0, 0, 255, 100));
			bresenham_algorithm(game->images.map_ray, l_screen_point, player_coor, color(0, 0, 0, 0));
		}
		l_screen_point.x += pixel_offset_cos;
		l_screen_point.y += pixel_offset_sen;
		ray_to_screen++;
		to_3d(game->images.tridy, ray.colision_len, ray_to_screen);
	}
	bresenham_algorithm(game->images.map_ray, player_coor, game->player.end, color(255, 255, 255, 255));
}