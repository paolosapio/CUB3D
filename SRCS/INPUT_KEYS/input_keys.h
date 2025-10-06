/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:29:30 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 15:54:34 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_KEYS_H
# define INPUT_KEYS_H

# include <sys/time.h>

# include "../DRAW_GAME/draw_game.h"
# include "t_game.h"
# include "../ANIMATIONS/animations.h"
# include "../MOVEMENTS/movements.h"

//hooks.c

void	await_user_input(t_game *game);

//special_keys.c

void	special_keys(mlx_key_data_t keydata, void *params);

//mouse_input.c

void	mouse_movements(double mouse_x, double mouse_y, void *params);
void	mouse_buttons(mouse_key_t button,
			action_t action, modifier_key_t mods, void *param);

//kelas_movement.c

void	kelas_movement(t_game *game);
void	keys_kelas(mlx_key_data_t keydata, t_game *game);

#endif