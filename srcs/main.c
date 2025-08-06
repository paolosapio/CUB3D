#include "cub3d.h"


/* void	handle_hook(mlx_key_data_t keydata, void *params)
{
	t_game *game;
	(void)keydata;
	game = (t_game *)params;
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->mlx);
} */

void movimineto_personaje(void *params)
{
	t_game *game;
	game = (t_game *)params;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->images.map_player->instances->y--;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->images.map_player->instances->y++;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->images.map_player->instances->x++;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->images.map_player->instances->x--;
}


void	handle_hook(mlx_key_data_t keydata, void *params)
{
	t_game *game;
	(void)keydata;
	game = (t_game *)params;
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->mlx);
}

void	sayonara_baby(t_game *game)
{
	printf("ññññññññññññññññññ\n");
	destroy_map(&game->map);
	destroy_images(game->mlx, &game->images);
	mlx_terminate(game->mlx);
}

void	init_mlx_connection(t_game *game)
{
	init_game_struct(game);
	draw_game(game);
	mlx_key_hook(game->mlx, &handle_hook, game);
	mlx_loop_hook(game->mlx, &movimineto_personaje, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		printf(RED"ERROR: Invalid arguments\n"STD"  → Usage: ./cub3D maps/map.cub\n\n");
		printf(PURPLE"You can find different maps inside the map folder\n"STD);
		return (1);
	}
	if (check_file(argv[1]) == ERROR)
	{
		printf("ERROR FILE NAME\n");
		return (2);
	}
	check_map(argv[1], &game.map);
	init_mlx_connection(&game);
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