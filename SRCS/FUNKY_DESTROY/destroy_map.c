#include "funky_destroy.h"

void	destroy_map(t_map *map)
{
	if (map && map->array)
		free_double_pointer(map->array);
}