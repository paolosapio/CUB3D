#include "animations.h"

void	animations(void *params)
{
	struct timeval	current_time;
	t_game			*game;
	static bool		animation_switch = false;

	game = (t_game *)params;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec % 100 == 0)
		animation_switch = true;
	if (animation_switch == true)
		draw_bubble(game->mlx, game->images.bubble_array, &animation_switch);
	if (current_time.tv_usec % 5 == 0 && game->images.start[0]->enabled == true)
		game->images.start[1]->enabled = !game->images.start[1]->enabled;
	if (game->images.start[0]->enabled == false
		&& game->images.start[1]->instances->y < HEIGHT)
	{
		game->images.start[1]->instances->y += 1;
		game->images.start[1]->instances->x += 1;
		if (mlx_resize_image(game->images.start[1],
				game->images.start[1]->width - 2,
				game->images.start[1]->height - 2) == false)
			game->images.start[1]->enabled = false;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		if (current_time.tv_sec % 2 == 0)
		{
			game->images.kelas_up[0]->enabled = true;
			game->images.kelas_up[1]->enabled = false;
		}
		else
		{
			game->images.kelas_up[0]->enabled = false;
			game->images.kelas_up[1]->enabled = true;
		}
	}
	
	switch_fauna(current_time.tv_sec, &game->images);
	carousel(game->images.fauna, CAROUSEL_NORMAL_MOVEMENT);
	carousel_reverse(game->images.ambient, -CAROUSEL_NORMAL_MOVEMENT);
}