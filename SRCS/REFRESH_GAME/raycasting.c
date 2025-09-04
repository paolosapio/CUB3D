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

void	raycasting(mlx_image_t *image, t_player player, t_map map, t_coor end)
{


	t_triangle	triangle_y;
	t_triangle	triangle_x;
	t_coor	 	point_of_view;
	(void)map;
	triangle_y = collision_triangulator_y(player.pos, end);
	triangle_y.hypotenuse.start = triangle_y.adjacent.start;
	triangle_y.hypotenuse.end = triangle_y.opposite.end;
	
	triangle_x = collision_triangulator_x(player.pos, end);
	triangle_x.hypotenuse.start = triangle_x.adjacent.start;
	triangle_x.hypotenuse.end = triangle_x.opposite.end;

	//comparar las hipos, ver la mas pequena si colisiona, si hay colision medir distancias y linea en pantalla
	if (triangle_y.hypotenuse.size < triangle_x.hypotenuse.size)
	{
		if (map.array[(int)triangle_y.hypotenuse.end.y][(int)triangle_y.hypotenuse.end.x] == '1')
		{	
			printf("veo pared\n");
			point_of_view = triangle_y.hypotenuse.end;
		}
		else
		printf("veo via libre\n");
	printf("%d\n", (int)triangle_x.hypotenuse.end.x);
	printf("%d\n\n", (int)triangle_x.hypotenuse.end.y);
	}

	bresenham_algorithm(image, triangle_y.adjacent.start, triangle_y.adjacent.end, color(150, 0, 0, 255));
	bresenham_algorithm(image, triangle_y.opposite.start, triangle_y.opposite.end, color(255, 0, 0, 255));
	bresenham_algorithm(image, triangle_x.adjacent.start, triangle_x.adjacent.end, color(0, 0, 150, 255));
	bresenham_algorithm(image, triangle_x.opposite.start, triangle_x.opposite.end, color(0, 0, 255, 255));
	bresenham_algorithm(image, player.pos, point_of_view, color(0, 255, 0, 255));


}