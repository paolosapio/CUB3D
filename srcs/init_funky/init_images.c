#include "cub3d.h"

t_images *init_images(mlx_t*	mlx)
{
	t_images		*images;
	mlx_texture_t	*texture;

	images = malloc(sizeof(t_images));
	texture = mlx_load_png("PNG/mirilla.png");
	images->mirilla = mlx_texture_to_image(mlx, texture);
	//mlx_delete_texture(texture);
	return (images);
}