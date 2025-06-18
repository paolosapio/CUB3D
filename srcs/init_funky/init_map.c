#include "cub3d.h"

t_map	init_map()
{
	t_map	map;

	map.map_fd = 0;
	map.map_line = NULL;
	map.map_line_buf = "";
	return (map);
}