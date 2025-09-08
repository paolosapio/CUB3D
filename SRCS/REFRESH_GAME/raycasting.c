#include "refresh_game.h"
#include <math.h>

/* // !informacion que tenemos!
		posicion del jugador
		angulo de direcion
		punto final forzado que nos permite tener la perndiente

	  !informacion a buscar::
	en el eje Y: 
	  	lado adiacente _ (se calcula punto de partida - punto de partida casteado en int)
	  	lado opposite | (se calcula con la pen diente m = )

	en el eje X:
	  	lado en eje x |
	  	lado en eje y (pendiente m) _

*/

//🏆
float	hipotenuseitor_no_root(t_segment adiacente,t_segment opposite)
{
	float	hipo_size;

	hipo_size = adiacente.size * adiacente.size + opposite.size * opposite.size;
	return (hipo_size);
}

t_coor true_raycasting(mlx_image_t *image, t_coor start, t_map map, t_coor end)
{
	t_coor colision_point;

	return (colision_point);
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
	{
		check_point = triangle_y.hypotenuse.end;
		if (map.array[(int)triangle_y.hypotenuse.end.y][(int)triangle_y.hypotenuse.end.x] == '0')
			check_point = true_raycasting(image, check_point, map, end);
	}
	if (triangle_x.hypotenuse.size <= triangle_y.hypotenuse.size)
	{
		check_point = triangle_x.hypotenuse.end;
		if (map.array[(int)triangle_x.hypotenuse.end.y][(int)triangle_x.hypotenuse.end.x] == '0')
			check_point = true_raycasting(image, check_point, map, end);
	}
	// printf("triangle_x.hypotenuse.size: %f\n", triangle_x.hypotenuse.size);
	// printf("triangle_y.hypotenuse.size: %f\n", triangle_y.hypotenuse.size);
	bresenham_algorithm(image, triangle_y.adjacent.start, triangle_y.adjacent.end, color(150, 0, 0, 255));
	bresenham_algorithm(image, triangle_y.opposite.start, triangle_y.opposite.end, color(255, 0, 0, 255));
	bresenham_algorithm(image, triangle_x.adjacent.start, triangle_x.adjacent.end, color(0, 0, 150, 255));
	bresenham_algorithm(image, triangle_x.opposite.start, triangle_x.opposite.end, color(0, 0, 255, 255));
	return (check_point);
}