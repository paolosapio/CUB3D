/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:44:47 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 21:34:09 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_game.h"

/**
 * @brief loads a png file into an mlx_texture_t and in case it failed, frees
 * the memory and exits the program.
 */
mlx_texture_t	*load_n_check_texture(mlx_t *mlx, t_images *images,
		char *texture_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(texture_path);
	if (!texture)
	{
		write(2, "ERROR:NOT VALID TEXTURE: ", 25);
		ft_putendl_fd(texture_path, 2);
		sayonara_baby(mlx, images, NULL);
		exit(1);
	}
	return (texture);
}

/**
 * @brief loads a png file into an mlx_image_t and in case it failed, frees
 * the memory and exits the program.
 */
mlx_image_t	*load_n_check_image(mlx_t *mlx, t_images *imgs, char *texture_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(texture_path);
	if (!texture)
	{
		write(2, "ERROR:NOT VALID TEXTURE: ", 25);
		ft_putendl_fd(texture_path, 2);
		sayonara_baby(mlx, imgs, NULL);
		exit(1);
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}
