
#include "cub3d.h"

void movimineto_personaje(void *params)
{
	t_game *game;
	game = (t_game *)params;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->images.map_player->instances->y--;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->images.map_player->instances->y++;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->images.map_player->instances->x++;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->images.map_player->instances->x--;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		if(game->map.player_pointer->vision_angle == 360)
			game->map.player_pointer->vision_angle = 0;
		game->map.player_pointer->vision_angle++;
		printf("ANGLE VISION TO LEFT: %d\n", game->map.player_pointer->vision_angle);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		if(game->map.player_pointer->vision_angle == 0)
			game->map.player_pointer->vision_angle = 360;
		game->map.player_pointer->vision_angle--;
		printf("ANGLE VISION TO LEFT: %d\n", game->map.player_pointer->vision_angle);
	}
	int mouse_x = 0;
	int mouse_y = 0;
	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	printf("mouse_x %d, mouse_y %d\n", mouse_x, mouse_y);
}

void	handle_hook(mlx_key_data_t keydata, void *params)
{
	t_game *game;
	(void)keydata;
	game = (t_game *)params;
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == true)
		mlx_close_window(game->mlx);
	if(mlx_is_key_down(game->mlx, MLX_KEY_M) == true)
	{
		game->images.minimap->enabled -= 1;
		game->images.map_player->enabled -= 1;
	}
}

void	sayonara_baby(t_game *game)
{
	printf("\n\nSAYONARA BABYYYY 🐠🐡🌊\n");
	destroy_map(&game->map);
	destroy_images(game->mlx, &game->images);
	mlx_terminate(game->mlx);
}

void	init_mlx_connection(t_game *game, t_parser_map *parser_map)
{
	init_game_struct(game, parser_map);
	draw_game(game);
	mlx_key_hook(game->mlx, &handle_hook, game);
	mlx_loop_hook(game->mlx, &movimineto_personaje, game);
	mlx_loop(game->mlx);
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
	init_mlx_connection(&game, &parser_map);
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