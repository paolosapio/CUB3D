/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:33:06 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 15:33:25 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

/**A function that returns in *milliseconds* the elapsed time since the last
 * time the loop_hook animation 
 */
unsigned long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	animations(void *params)
{
	unsigned long			current_time;
	t_game					*game;

	game = (t_game *)params;
	current_time = get_time();
	frame_loop(current_time, game->images.frame);
	bubble_loop(current_time, game->images.bubble_array);
	if (game->images.start[0]->enabled == true)
		start_screen_loop(current_time, game->images.start);
	else if (game->images.start[1]->enabled == true)
		resize_start_screen(game->images.start[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT)
		&& game->images.info->enabled == false)
		shift_kelas_loop(current_time, game->images.kelas_up);
	switch_fauna(current_time, game->images.fauna);
	carousel(game->images.fauna, CAROUSEL_NORMAL_MOVEMENT);
	carousel_reverse(game->images.ambient, -CAROUSEL_NORMAL_MOVEMENT);
	sun_in_waves(game->images.waves, CAROUSEL_NORMAL_MOVEMENT);
}
