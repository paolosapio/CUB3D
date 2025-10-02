/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_graphics.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:14:40 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 12:17:33 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_GRAPHICS_H
# define TOOLS_GRAPHICS_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "t_player.h"
# include "t_game.h"
# include "libft.h"

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x;
	int	y;
}		t_bresenham;

# define RGBA_SIZE 4

void		paint_tile(int size_tile, mlx_image_t *img_minimap,
				t_coor coor, int32_t color);
void		bresenham_algorithm(mlx_image_t *image, t_segment s,
				uint32_t color, int tile_size);
void		clean_image(mlx_image_t *image);
uint32_t	ft_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

#endif
