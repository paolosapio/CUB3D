#include "funky_destroy.h"

void	sayonara_baby(mlx_t *mlx, t_images *images, t_map *map)
{
	printf("\n\nSAYONARA BABYYYY 🐠🐡🌊\n");
	destroy_map(map);
	destroy_images(mlx, images);
	mlx_terminate(mlx);
}