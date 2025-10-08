/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_images.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:49:47 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:54:39 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMAGES_H
# define T_IMAGES_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_images
{
	mlx_image_t		*sky;
	mlx_image_t		*floor;
	mlx_image_t		*gradient_bgr;
	mlx_image_t		*mirilla;
	mlx_image_t		*background_map;
	mlx_image_t		*map_ray;
	mlx_image_t		*greco_map[8];
	mlx_image_t		*map_greco;
	mlx_image_t		*map_sand;
	mlx_image_t		*map_rock;
	mlx_image_t		*cuadricula;
	mlx_image_t		*tridy;
	mlx_image_t		*bubble_array[20];
	mlx_image_t		*start[2];
	mlx_image_t		*fauna[2];
	mlx_image_t		*ambient;
	mlx_image_t		*info;
	mlx_image_t		*waves[2];
	mlx_image_t		*frame[6];
	mlx_image_t		*kelas_open;
	mlx_image_t		*kelas_closed;
	mlx_image_t		*kelas_sx;
	mlx_image_t		*kelas_dx;
	mlx_image_t		*kelas_up[2];
	mlx_texture_t	*wall_alga;
	mlx_texture_t	*map_texture_n;
	mlx_texture_t	*map_texture_s;
	mlx_texture_t	*map_texture_e;
	mlx_texture_t	*map_texture_w;
	mlx_texture_t	*greco_texture;
}				t_images;

#endif