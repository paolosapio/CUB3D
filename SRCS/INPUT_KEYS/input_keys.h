/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:29:30 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 20:56:01 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_KEYS_H
# define INPUT_KEYS_H

# include <sys/time.h>

# include "../DRAW_GAME/draw_game.h"
# include "t_game.h"
# include "../ANIMATIONS/animations.h"

void	await_user_input(t_game *game);
void	special_keys(mlx_key_data_t keydata, void *params);

#endif