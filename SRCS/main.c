
#include "cub3d.h"

void	sayonara_baby(t_game *game)
{
	printf("\n\nSAYONARA BABYYYY 🐠🐡🌊\n");
	destroy_map(&game->map);
	destroy_images(game->mlx, &game->images);
	mlx_terminate(game->mlx);
}


int	main(int argc, char **argv)
{
	t_parser_map parser_map;
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));

	game.map.player_pointer = &game.player;
	if (argc != 2)
	{
		printf(RED"ERROR: Invalid arguments\n"STD"  → Usage: ./cub3D maps/map.cub\n\n");
		printf(PURPLE"You can find different maps inside the map folder\n"STD);
		return (1);
	}
	parser_map = parser(argv[1], &game.map);
	init_game(&game, &parser_map);
	await_user_input(&game);
	sayonara_baby(&game);
}

// todo 2025.07.24

/*	tareas pequeas:
		minimapa personaje
		que se vean los rayos en el minimapa tipo embudo

personaje movinientos:
	w adelante 
	a paso del cangrejo ez
	s atras
	d paso del cangrejo dr
	< gira ez
	> gira dr

*/
/*	tareas grandes:
		ray casting
		toda la parte grafica
 */