/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_movements.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:49:31 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:49:40 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_MOVEMENTS_H
# define T_PLAYER_MOVEMENTS_H

typedef struct s_player_movements
{
	bool	key_w_is_down;
	bool	key_q_is_down;
	bool	key_e_is_down;
	bool	key_a_is_down;
	bool	key_s_is_down;
	bool	key_d_is_down;
	bool	key_left_is_down;
	bool	key_right_is_down;
	bool	key_mouse_left_down;
	bool	key_mouse_right_down;

}			t_player_movements;

#endif
