#include "cub3d.h"

void	init_images(mlx_t* mlx, t_map *map, t_images *images)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("PNG/mirilla.png");
	images->mirilla = mlx_texture_to_image(mlx, texture);
	images->minimap = create_minimap(mlx, map);
	images->floor = create_floor(mlx, map);
	images->sky = create_sky(mlx, map);
	mlx_delete_texture(texture);
}