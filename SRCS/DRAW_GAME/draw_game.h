/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:56:33 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 20:15:30 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_GAME_H
# define DRAW_GAME_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"
# include "libft.h"
# include "t_game.h"
# include "t_player.h"

# define SKY 1
# define SAND 0

void		images_to_window(t_game *game);
mlx_image_t	*create_half_screen_rectangle(mlx_t *mlx, int color);
mlx_image_t	*create_background_map(mlx_t *mlx, t_map *map);
void		images_to_window(t_game *game);
mlx_image_t	*create_empty_img(mlx_t *mlx, int width, int height);
mlx_image_t	*create_gradient_bgr(mlx_t *mlx);
void		bouble_to_windws(t_game *game);
void		frame_to_windows(t_game *game);
void		array_to_win(mlx_t *mlx, mlx_image_t **array_imgs, int frames_times);

#endif
