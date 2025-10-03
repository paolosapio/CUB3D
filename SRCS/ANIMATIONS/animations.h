/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:52:49 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 01:37:38 by anfi             ###   ########.fr       */
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

void	switch_fauna(unsigned long current_time,  mlx_image_t **fauna);


//bubbles.c

void	bubble_loop(unsigned long current_time, mlx_image_t **bubble_array);


//animations_hook.c

void	animations(void *params);

//start_screen_loop.c

void	start_screen_loop(unsigned long current_time, mlx_image_t **img);
void	resize_start_screen(mlx_image_t *start_img);

//kelas_loop.c

void	shift_kelas_loop(unsigned long current_time, mlx_image_t **kelas_up);

#endif
