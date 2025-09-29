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
	mlx_delete_image(mlx, images->minimap);
	try_to_delete_texture(images->map_texture_N);
	try_to_delete_texture(images->map_texture_S);
	try_to_delete_texture(images->map_texture_E);
	try_to_delete_texture(images->map_texture_W);
}
