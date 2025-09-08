#include "refresh_game.h"
#include <math.h>

static t_segment	init_opposite_a(float m, t_coor start, float size_adiacente)
{
	t_segment opposite;

	opposite.start = start;
	opposite.end.y = start.y;

	opposite.size = size_adiacente * m;
	opposite.end.x = opposite.size + start.x;
	return (opposite);
}

static t_segment	init_adjacent_a(t_coor start, t_coor end)
{
	t_segment adjacent;

	adjacent.start.x = start.x;
	adjacent.start.y = start.y;
	if(start.y - end.y < 0)
		adjacent.end.y = ((int)start.y + 1);
	if(start.y - end.y >= 0)
		adjacent.end.y = (int)start.y;
	adjacent.end.x = start.x;
	adjacent.size = adjacent.end.y - start.y;
	return (adjacent);
}

static float	gradienteitor(t_coor start, t_coor end)
{
	float adjacent_long;
	float opposite_long;

	adjacent_long = end.y - start.y;
	opposite_long = end.x - start.x;
	return (opposite_long / adjacent_long);
}

t_triangle  collision_triangulator_x(t_coor start, t_coor end)
{
	t_triangle	sides;	
	
	sides.adjacent = init_adjacent_a(start, end);
	sides.m = gradienteitor(start, end);
	sides.opposite = init_opposite_a(sides.m, sides.adjacent.end, sides.adjacent.size);
	sides.hypotenuse.size = hipotenuseitor_no_root(sides.adjacent, sides.opposite);
	return (sides);
}