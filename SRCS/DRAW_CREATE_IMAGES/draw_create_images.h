/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_create_images.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:56:33 by psapio            #+#    #+#             */
/*   Updated: 2025/10/21 23:54:22 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_CREATE_IMAGES_H
# define DRAW_CREATE_IMAGES_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"
# include "libft.h"
# include "t_game.h"
# include "t_player.h"

# define SKY 1
# define SAND 0

// create_images.c

mlx_image_t	*create_empty_img(mlx_t *mlx, int width, int height);
mlx_image_t	*create_background_map(mlx_t *mlx);

// draw_game_utils.c

void		transparentator(int value_of_trasparence, mlx_image_t *image);
void		hide_images(t_images *image);
void		greco_minimap_resizeitor(t_images *images, int tile_size,
				int n_images);

// image_array_to_windows.c

void		array_to_win(mlx_t *mlx, mlx_image_t **array_imgs,
				int frames_times);

// image_to_windows.c

void		tridy_images_to_window(t_game *game);
void		kelas_images_to_window(t_game *game);
void		images_to_window(t_game *game);

// minimap_to_windows.c

void		sand_rock_to_win(mlx_t *mlx, t_map *map, t_images *images);
void		minimap_images_to_window(mlx_t *mlx, t_map *map, t_images *images);

// sky_and_floor_create.c

mlx_image_t	*create_half_screen_rectangle(mlx_t *mlx, int color);
mlx_image_t	*create_gradient_bgr(mlx_t *mlx);

#endif
