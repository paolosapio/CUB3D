/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 23:00:30 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/08/11 23:08:51 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef enum e_player_movements t_player_movements;
typedef struct	s_coor t_coor;

typedef struct	s_player
{
	//t_vector	pos;
	t_coor	pos;
	t_coor	end;
	int		vision_angle;
	t_player_movements movement;
}				t_player;

#endif