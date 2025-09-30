/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:52:49 by psapio            #+#    #+#             */
/*   Updated: 2025/09/30 20:53:09 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H
# define ANIMATIONS_H

# include "t_game.h"

# define CAROUSEL_NORMAL_MOVEMENT -0.4
# define CAROUSEL_LEFT_MOVEMENT 7.0
# define CAROUSEL_RIGHT_MOVEMENT -7.0

void	carousel(mlx_image_t **image, const float movement);
void	carousel_reverse(mlx_image_t *image, const float movement);

#endif
