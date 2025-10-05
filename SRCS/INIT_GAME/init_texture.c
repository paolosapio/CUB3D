/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:13:37 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 18:22:36 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

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

void	init_bubbles(mlx_t *mlx, mlx_image_t **bubble_array, t_images *images)
{
	bubble_array[0] = load_n_check_image(mlx, images, "PNG/bubble/b0.png");
	bubble_array[1] = load_n_check_image(mlx, images, "PNG/bubble/b1.png");
	bubble_array[2] = load_n_check_image(mlx, images, "PNG/bubble/b2.png");
	bubble_array[3] = load_n_check_image(mlx, images, "PNG/bubble/b3.png");
	bubble_array[4] = load_n_check_image(mlx, images, "PNG/bubble/b4.png");
	bubble_array[5] = load_n_check_image(mlx, images, "PNG/bubble/b5.png");
	bubble_array[6] = load_n_check_image(mlx, images, "PNG/bubble/b6.png");
	bubble_array[7] = load_n_check_image(mlx, images, "PNG/bubble/b7.png");
	bubble_array[8] = load_n_check_image(mlx, images, "PNG/bubble/b8.png");
	bubble_array[9] = load_n_check_image(mlx, images, "PNG/bubble/b9.png");
	bubble_array[10] = load_n_check_image(mlx, images, "PNG/bubble/b10.png");
	bubble_array[11] = load_n_check_image(mlx, images, "PNG/bubble/b11.png");
	bubble_array[12] = load_n_check_image(mlx, images, "PNG/bubble/b12.png");
	bubble_array[13] = load_n_check_image(mlx, images, "PNG/bubble/b13.png");
	bubble_array[14] = load_n_check_image(mlx, images, "PNG/bubble/b14.png");
	bubble_array[15] = load_n_check_image(mlx, images, "PNG/bubble/b15.png");
	bubble_array[16] = load_n_check_image(mlx, images, "PNG/bubble/b16.png");
	bubble_array[17] = load_n_check_image(mlx, images, "PNG/bubble/b17.png");
	bubble_array[18] = load_n_check_image(mlx, images, "PNG/bubble/b18.png");
	bubble_array[19] = load_n_check_image(mlx, images, "PNG/bubble/b19.png");
}

void	init_frame_textures(mlx_t *mlx, t_images *imgs)
{
	imgs->frame[0] = load_n_check_image(mlx, imgs, "PNG/frame/0.png");
	imgs->frame[1] = load_n_check_image(mlx, imgs, "PNG/frame/1.png");
	imgs->frame[2] = load_n_check_image(mlx, imgs, "PNG/frame/2.png");
	imgs->frame[3] = load_n_check_image(mlx, imgs, "PNG/frame/3.png");
	imgs->frame[4] = load_n_check_image(mlx, imgs, "PNG/frame/4.png");
	imgs->frame[5] = load_n_check_image(mlx, imgs, "PNG/frame/5.png");
}

void	init_map_greco(mlx_t *mlx, t_images *imgs)
{
	imgs->greco_map[W_] = load_n_check_image(mlx, imgs, "PNG/greco_map/W.png");
	imgs->greco_map[NW] = load_n_check_image(mlx, imgs, "PNG/greco_map/NW.png");
	imgs->greco_map[N_] = load_n_check_image(mlx, imgs, "PNG/greco_map/N.png");
	imgs->greco_map[NE] = load_n_check_image(mlx, imgs, "PNG/greco_map/NE.png");
	imgs->greco_map[E_] = load_n_check_image(mlx, imgs, "PNG/greco_map/E.png");
	imgs->greco_map[SE] = load_n_check_image(mlx, imgs, "PNG/greco_map/SE.png");
	imgs->greco_map[S_] = load_n_check_image(mlx, imgs, "PNG/greco_map/S.png");
	imgs->greco_map[SW] = load_n_check_image(mlx, imgs, "PNG/greco_map/SW.png");
}

void	init_texture(mlx_t *mlx, t_images *imgs, t_parser_map *parser_map)
{
	imgs->mirilla = load_n_check_image(mlx, imgs, "PNG/mirilla.png");
	imgs->greco_texture = load_n_check_texture(mlx, imgs, "PNG/greco.png");
	mlx_set_icon(mlx, imgs->greco_texture);
	mlx_delete_texture(imgs->greco_texture);
	init_frame_textures(mlx, imgs);
	imgs->map_sand = load_n_check_image(mlx, imgs, "PNG/map_sand.png");
	imgs->map_rock = load_n_check_image(mlx, imgs, "PNG/map_rock.png");
	imgs->kelas_open = load_n_check_image(mlx, imgs, "PNG/kelas_open.png");
	imgs->kelas_closed = load_n_check_image(mlx, imgs, "PNG/kelas_closed.png");
	imgs->kelas_sx = load_n_check_image(mlx, imgs, "PNG/kelas_sx.png");
	imgs->kelas_dx = load_n_check_image(mlx, imgs, "PNG/kelas_dx.png");
	imgs->kelas_up[0] = load_n_check_image(mlx, imgs, "PNG/kelas_up0.png");
	imgs->kelas_up[1] = load_n_check_image(mlx, imgs, "PNG/kelas_up1.png");
	imgs->map_greco = load_n_check_image(mlx, imgs, "PNG/greco.png");
	init_map_greco(mlx, imgs);
	imgs->map_texture_N = load_n_check_texture(mlx, imgs, parser_map->path_s);
	imgs->map_texture_S = load_n_check_texture(mlx, imgs, parser_map->path_n);
	imgs->map_texture_E = load_n_check_texture(mlx, imgs, parser_map->path_w);
	imgs->map_texture_W = load_n_check_texture(mlx, imgs, parser_map->path_e);
	init_bubbles(mlx, imgs->bubble_array, imgs);
	imgs->start[0] = load_n_check_image(mlx, imgs, "PNG/start/0.png");
	imgs->start[1] = load_n_check_image(mlx, imgs, "PNG/start/1.png");
	imgs->fauna[0] = load_n_check_image(mlx, imgs, "PNG/fauna0.png");
	imgs->fauna[1] = load_n_check_image(mlx, imgs, "PNG/fauna1.png");
	imgs->ambient = load_n_check_image(mlx, imgs, "PNG/ambient.png");
	imgs->info = load_n_check_image(mlx, imgs, "PNG/info.png");
}
