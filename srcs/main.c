#include "cub3d.h"


void	handle_hook(mlx_key_data_t keydata, void *params)
{
	t_game *game = (t_game *)params;
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_M)
	{
		game->images.minimap->enabled = !(game->images.minimap->enabled);
	}
	
}

void	sayonara_baby(t_game *game)
{
	destroy_map(&game->map);
	destroy_images(game->mlx, &game->images);
	mlx_terminate(game->mlx);
}

void	init_mlx_connection(t_game *game)
{
	init_game_struct(game);
	draw_game(game);
	mlx_key_hook(game->mlx, &handle_hook, game);
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
	while (1)
	{
		usleep(1);
		game.map.player->pos[X]++;
	}
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