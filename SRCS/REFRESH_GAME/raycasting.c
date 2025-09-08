#include "refresh_game.h"
#include <math.h>











t_coor true_raycasting(mlx_image_t *image, t_triangle triangle_y, t_triangle triangle_x, t_coor start, char **map_array)
{
	t_coor	colision;
	t_coor		aux_coor;
	int			dir_x;
	int			dir_y;
	int			col_deg;

	col_deg = 255;
	if (triangle_y.adjacent.size < 0)
		dir_x = -1;
	else
		dir_x = 1;

	if (triangle_y.opposite.size < 0)
		dir_y = -1;
	else
		dir_y = 1;

	colision = start;

	while (map_array[(int)colision.y][(int)colision.x] && map_array[(int)colision.y][(int)colision.x] == '0')
	{
		printf("dir_x = %f, triangle_y.m = %f\n", dir_x, triangle_y.m);
		if (triangle_y.hypotenuse.size < triangle_x.hypotenuse.size)
		{
			triangle_morpheitor(&triangle_y, dir_x, dir_y);
			bresenham_algorithm(image, triangle_y.hypotenuse.start, triangle_y.hypotenuse.end, color(255, 0, 0, 255));
			printf("aaaaaaaaaaa\n");
		}
		else
		{
			triangle_morpheitor(&triangle_x, dir_x, dir_y);
			bresenham_algorithm(image, triangle_y.hypotenuse.start, triangle_y.hypotenuse.end, color(255, 0, 255, 255));
			printf("bbbbbbbbbbbb\n");
		}
		if (triangle_y.hypotenuse.size < triangle_x.hypotenuse.size)
			colision = triangle_y.hypotenuse.end;
		else
			colision = triangle_x.hypotenuse.end;
	}
	bresenham_algorithm(image, start, colision, color(0, 255, 255, 255));

	return (colision);
}










t_coor	raycasting(mlx_image_t *image, t_player player, t_map map, t_coor end)
{
	t_triangle	triangle_y;
	t_triangle	triangle_x;
	t_coor	 	check_point;

	triangle_y = collision_triangulator_y(player.pos, end);
	triangle_y.hypotenuse.start = triangle_y.adjacent.start;
	triangle_y.hypotenuse.end = triangle_y.opposite.end;
	
	triangle_x = collision_triangulator_x(player.pos, end);
	triangle_x.hypotenuse.start = triangle_x.adjacent.start;
	triangle_x.hypotenuse.end = triangle_x.opposite.end;

	//comparar las hipos, ver la mas pequena si colisiona, si hay colision medir distancias y linea en pantalla
	if (triangle_y.hypotenuse.size < triangle_x.hypotenuse.size)
		check_point = triangle_y.hypotenuse.end;
	if (triangle_x.hypotenuse.size <= triangle_y.hypotenuse.size)
		check_point = triangle_x.hypotenuse.end;
	check_point = true_raycasting(image, triangle_y, triangle_x, check_point, map.array);

	bresenham_algorithm(image, triangle_y.adjacent.start, triangle_y.adjacent.end, color(150, 0, 0, 255));
	bresenham_algorithm(image, triangle_y.opposite.start, triangle_y.opposite.end, color(255, 0, 0, 255));
	bresenham_algorithm(image, triangle_x.adjacent.start, triangle_x.adjacent.end, color(0, 0, 150, 255));
	bresenham_algorithm(image, triangle_x.opposite.start, triangle_x.opposite.end, color(0, 0, 255, 255));
	return (check_point);
}