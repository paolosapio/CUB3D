/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:41:54 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:53:41 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funky_destroy.h"

void	try_to_delete_texture(mlx_texture_t *texture)
{
	if (texture)
		mlx_delete_texture(texture);
}

void	destroy_images(mlx_t *mlx, t_images *images)
{
	mlx_delete_image(mlx, images->sky);
	mlx_delete_image(mlx, images->floor);
	mlx_delete_image(mlx, images->mirilla);
	try_to_delete_texture(images->map_texture_n);
	try_to_delete_texture(images->map_texture_s);
	try_to_delete_texture(images->map_texture_e);
	try_to_delete_texture(images->map_texture_w);
}
