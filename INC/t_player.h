/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:48:33 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:49:25 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "t_coordinate.h"
# include <stdbool.h>
# include "t_player_movements.h"

# define CENTER_PLAYER 0.5

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