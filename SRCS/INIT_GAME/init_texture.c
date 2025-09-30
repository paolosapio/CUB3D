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

mlx_image_t	*load_n_check_image(mlx_t *mlx, t_images *images, char *texture_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(texture_path);
	if (!texture)
	{
		write(2, "ERROR:NOT VALID TEXTURE: ", 25);
		ft_putendl_fd(texture_path, 2);
		sayonara_baby(mlx, images, NULL);
		exit(1);
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	// TODO: mlx_set_icon(mlx, greco);
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

void	init_texture(mlx_t *mlx, t_images *images, t_parser_map *parser_map)
{
	images->mirilla = load_n_check_image(mlx, images, "PNG/mirilla.png");
	images->greco_texture = load_n_check_texture(mlx, images, "PNG/greco.png");
	mlx_set_icon(mlx, images->greco_texture);
	mlx_delete_texture(images->greco_texture);
	images->map_greco = load_n_check_image(mlx, images, "PNG/greco.png");
	images->map_sand = load_n_check_image(mlx, images, "PNG/map_sand.png");
	images->map_rock = load_n_check_image(mlx, images, "PNG/map_rock.png");
	images->kelas_open = load_n_check_image(mlx, images, "PNG/kelas_open.png");
	images->kelas_closed = load_n_check_image(mlx, images, "PNG/kelas_closed.png");
	images->kelas_sx = load_n_check_image(mlx, images, "PNG/kelas_sx.png");
	images->kelas_dx = load_n_check_image(mlx, images, "PNG/kelas_dx.png");
	images->frame = load_n_check_image(mlx, images, "PNG/frame.png");
	images->map_texture_N = load_n_check_texture(mlx, images, parser_map->info_north_texture);
	images->map_texture_S = load_n_check_texture(mlx, images, parser_map->info_south_texture);
	images->map_texture_E = load_n_check_texture(mlx, images, parser_map->info_east_texture);
	images->map_texture_W = load_n_check_texture(mlx, images, parser_map->info_west_texture);
	init_bubbles(mlx, images->bubble_array, images);
	images->start_cover[0] = load_n_check_image(mlx, images, "PNG/start/start0.png");
	images->start_cover[1] = load_n_check_image(mlx, images, "PNG/start/start1.png");
	images->fauna[0] = load_n_check_image(mlx, images, "PNG/fauna0.png");
	images->fauna[1] = load_n_check_image(mlx, images, "PNG/fauna1.png");
	images->ambient = load_n_check_image(mlx, images, "PNG/ambient.png");
}
