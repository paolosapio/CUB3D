#include "refresh_game.h"

t_coor	triangle_morpheitor(t_triangle *triangle, int dir_x, int dir_y)
{
	triangle->adjacent.end.x += dir_x;
	triangle->opposite.start = triangle->adjacent.end;
	triangle->opposite.end.x += dir_x;
	triangle->opposite.end.y += fabs(triangle->m) * dir_y;
	triangle->hypotenuse.end = triangle->opposite.end;
	triangle->hypotenuse.size += hipotenuseitor_no_root(triangle->adjacent, triangle->opposite);
	return (triangle->hypotenuse.end);
}

//🏆
float	hipotenuseitor_no_root(t_segment adjacent,t_segment opposite)
{
	float	hipo_size;

	hipo_size = adjacent.size * adjacent.size + opposite.size * opposite.size;
	return (hipo_size);
}