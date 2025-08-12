#include "cub3d.h"

void	destroy_images(mlx_t *mlx, t_images *images)
{
	mlx_delete_image(mlx, images->sky);
	mlx_delete_image(mlx, images->floor);
	mlx_delete_image(mlx, images->mirilla);
	mlx_delete_image(mlx, images->minimap);
	mlx_delete_image(mlx, images->map_texture_N);
	mlx_delete_image(mlx, images->map_texture_S);
	mlx_delete_image(mlx, images->map_texture_E);
	mlx_delete_image(mlx, images->map_texture_O);
}