#include "refresh_game.h"
#include <math.h>

//🏆
static t_segment	init_opposite_b(float m, t_coor start, float size_adiacente)
{
	t_segment opposite;

	opposite.start = start;
	opposite.end.x = start.x;
	opposite.size = size_adiacente * m;
	opposite.end.y = opposite.size + start.y;
	return (opposite);
}

//🏆
static t_segment	init_adiacente_b(t_coor start, t_coor end)
{
	t_segment adiacente;

	adiacente.start = start;
	if(start.x - end.x < 0)
		adiacente.end.x = ((int)start.x + 1);
	if(start.x - end.x >= 0)
		adiacente.end.x = (int)start.x;
	adiacente.end.y = start.y;
	adiacente.size = adiacente.end.x - start.x;
	return (adiacente);
}

static float	gradienteitor(t_coor start, t_coor end)
{
	float adjacent_long;
	float opposite_long;

	adjacent_long = end.x - start.x;
	opposite_long = end.y - start.y;
	return (opposite_long / adjacent_long);
}

t_triangle  collision_triangulator_y(t_coor start, t_coor end)
{
	t_triangle	sides;	
	
	// calculo colision een ejee y:
	sides.adjacent = init_adiacente_b(start, end);
	sides.m = gradienteitor(start, end);
	sides.opposite = init_opposite_b(sides.m, sides.adjacent.end, sides.adjacent.size);
	
	sides.hypotenuse.size = hipotenuseitor_no_root(sides.adjacent, sides.opposite);
	return (sides);
}