/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sayonara_baby.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:42:31 by psapio            #+#    #+#             */
/*   Updated: 2025/10/21 23:03:34 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funky_destroy.h"

void	sayonara_baby(mlx_t *mlx, t_images *images, t_map *map)
{
	printf("\n\nSAYONARA BABYYYY 🐠🐡🌊\n");
	destroy_map(map);
	destroy_images(mlx, images);
	mlx_close_window(mlx);
	mlx_terminate(mlx);
}
