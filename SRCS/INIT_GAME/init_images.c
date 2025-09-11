#include "init_game.h"

void	init_images(mlx_t* mlx, t_map *map, t_images *images)
{
	images->minimap = create_minimap(mlx, map);
	images->background_map = create_background_map(mlx, map);
	images->floor = create_floor(mlx, map);
	images->tridy = create_tridy(mlx);
	images->sky = create_sky(mlx, map);
	images->map_ray = create_ray_minimap(mlx, map);
	images->minimap->enabled = true;
	images->map_ray->enabled = true;
	images->map_greco->enabled = true;
	//images->map_rock->enabled = false;
	images->map_sand->enabled = true;
}
