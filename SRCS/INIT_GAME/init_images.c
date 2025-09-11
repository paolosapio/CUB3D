#include "init_game.h"

void	init_images(mlx_t* mlx, t_map *map, t_images *images)
{
	images->minimap = create_minimap(mlx, map);
	images->background_map = create_background_map(mlx, map);
	images->floor = create_floor(mlx, map);
	images->tridy = create_tridy(mlx);
	images->sky = create_sky(mlx, map);
	images->map_ray = create_ray_minimap(mlx, map);
	images->minimap->enabled = false;
	images->map_ray->enabled = false;
	images->map_greco->enabled = false;
	images->map_rock->enabled = false;
	images->map_sand->enabled = false;
	images->background_map->enabled = false;
}
