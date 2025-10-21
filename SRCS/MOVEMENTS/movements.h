/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:43:18 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 21:23:09 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include "../DRAW_CREATE_IMAGES/draw_create_images.h"
# include "../REFRESH_GAME/refresh_game.h"
# include "../TOOLS_GENERICS/tools_generics.h"
# include "t_game.h"
# include "t_player_movements.h"
# include "../ANIMATIONS/animations.h"
# include "../RENDER/render.h"

# include <math.h>

# define LIMIT_FOV 1.5

# define SLOW 0.5
# define NORMAL 1
# define TURBO 2

# define COLLITIONS "1"
# define DISTANCE_COLLISION 1

typedef struct s_trig_angle
{
	float	angle;
	float	s1n;
	float	c0s;
}			t_trig_angle;

// movements_player.c
void		move_line_direction(t_player *player, float sen, float cos);
void		move_player(t_player *player, t_map *map, float sen, float cos);
void		change_player_rotation(t_player *player, int new_vision_angle);
void		movements_player(void *params);
void		movement_wasd(t_game	*game);

#endif