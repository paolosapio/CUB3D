/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funky_destroy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:42:44 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 19:42:45 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNKY_DESTROY_H
# define FUNKY_DESTROY_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "t_map.h"
# include "t_images.h"
# include "t_game.h"
# include "libft.h"

void	destroy_map(t_map *map);
void	destroy_images(mlx_t *mlx, t_images *images);
void	sayonara_baby(mlx_t *mlx, t_images *images, t_map *map);

#endif
