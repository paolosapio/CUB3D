/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sayonara_baby.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:42:31 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 17:59:43 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funky_destroy.h"

void	sayonara_baby(mlx_t *mlx, t_images *images, t_map *map)
{
	printf("\n\nSAYONARA BABYYYY 🐠🐡🌊\n");
	destroy_map(map);
	printf("asdasd\n");
	destroy_images(mlx, images);
	printf("asdasd\n");
	mlx_close_window(mlx);
	mlx_terminate(mlx);
}
