/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:48:33 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 13:26:23 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "t_coordinate.h"
# include <stdbool.h>
# include "t_player_movements.h"

# define CENTER_PLAYER 0.5

/**
 * @brief We added the greco's rotation in the minimap, but since rotating an
 * image is not something easy to do, we have 8 frames for 8 positions, and this
 * enum is used to keep track of which direction greco is looking at.
 */
typedef enum e_greco_dir
{
	W_,
	NW,
	N_,
	NE,
	E_,
	SE,
	S_,
	SW,
}		t_greco_dir;

typedef struct s_player
{
	t_coor				pos;
	t_coor				end;
	float				vision_angle;
	float				speed;
	t_player_movements	movements;
	t_greco_dir			greco_map_dir;
	int					view;
}				t_player;

#endif