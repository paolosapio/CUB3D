
#include "tools_generics.h"

int	tile_size_calculator(int map_height, int map_width)
{
	if (map_width >= map_height)
	{
		if (HEIGHT < (WIDTH / map_width) * map_height)
			return (HEIGHT / map_height);
		return (WIDTH / map_width);
	}
	return (HEIGHT / map_height);
}

float	to_radians(float degrees)
{
	return ((degrees / 180) * M_PI);
}