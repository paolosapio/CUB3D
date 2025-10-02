/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:52:49 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 15:12:22 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H
# define ANIMATIONS_H

# include "t_game.h"

# define CAROUSEL_NORMAL_MOVEMENT -0.4
# define CAROUSEL_LEFT_MOVEMENT 7.0
# define CAROUSEL_RIGHT_MOVEMENT -7.0

//carousel.c

void	carousel(mlx_image_t **image, const float movement);
void	carousel_reverse(mlx_image_t *image, const float movement);

//fauna.c

void	switch_fauna(int tv_sec, t_images *images);

//bubbles.c

void	draw_bubble(mlx_t *mlx, mlx_image_t **bubble_array,
		bool *animation_switch);

//animations_hook.c

void	animations(void *params);

#endif
