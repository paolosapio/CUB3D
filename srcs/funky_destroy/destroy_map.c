#include "cub3d.h"

void	destroy_map(t_map *map)
{

	free(map->map_info_north_texture);
	free(map->map_info_east_texture);
	free(map->map_info_south_texture);
	free(map->map_info_west_texture);
	free(map->map_info_floor);
	free(map->map_info_sky);

	free_double_pointer(map->map_array);
}