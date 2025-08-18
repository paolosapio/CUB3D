
#include "cub3d.h"
#define RGBA_SIZE 4

void	clean_image(mlx_image_t		*image)
{
	memset(image->pixels, 0, image->width * image->height * RGBA_SIZE);
}

void	paint_direction_player(mlx_image_t *map_player, t_player *player)
{
	clean_image(map_player);
	bresenham_algorithm(map_player, 
		//LA DIRECION:
		//p1_player
		player->pos.x * (size_of_tile) + (size_of_tile / 2),
		player->pos.y * (size_of_tile) + (size_of_tile / 2),

		//p2_player
		player->end.x * size_of_tile + (size_of_tile / 2) + 1,
		player->end.y * size_of_tile + (size_of_tile / 2) + 1);
	// rescrivir con las nuevas coordinadas:
	paint_tile(map_player, player->pos.x, player->pos.y, PLAYER_MAP_COLOR);
}

void	change_player_rotation(t_player *player, int new_vision_angle)
{
	if(new_vision_angle == 0)
		new_vision_angle = 360;
	else if (new_vision_angle == 360)
		new_vision_angle = 0;
	
	player->vision_angle = new_vision_angle;
	player->end.x = player->pos.x - cos((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV;
	player->end.y = player->pos.y - sin((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV;
}

void mouse_movements(double mouse_x, double mouse_y, void *params)
{
	t_game *game;
	static double first_step_x = 0;

	(void)mouse_y;
	game = (t_game *)params;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	if (mouse_x < first_step_x)
	{
		change_player_rotation(&game->player, game->player.vision_angle - 1);
	}
	else if (mouse_x > first_step_x)
	{
		change_player_rotation(&game->player, game->player.vision_angle + 1);
	}
	first_step_x = mouse_x;
	paint_direction_player(game->images.map_player, &game->player);
}


void	player_movements(void *params)
{
	t_game *game;
	game = (t_game *)params;
	float	turbo;

	turbo = OFF;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		turbo =  ON;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		printf("game->player.pos.y:[%f]\n", game->player.pos.y);
		game->player.pos.y-=turbo;
		printf("game->player.pos.y:[%f]\n", game->player.pos.y);
		game->player.end.y-=turbo;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.pos.y+=turbo;
		game->player.end.y+=turbo;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.pos.x+=turbo;
		game->player.end.x+=turbo;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.pos.x-=turbo;
		game->player.end.x-=turbo;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		change_player_rotation(&game->player, game->player.vision_angle - 1);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		change_player_rotation(&game->player, game->player.vision_angle + 1);
	}
	paint_direction_player(game->images.map_player, &game->player);
}

void	special_keys(mlx_key_data_t keydata, void *params)
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
	//INIT_GAME
	init_game_struct(game, parser_map);
	draw_game(game);

	//USER_INPUT
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);

	mlx_loop_hook(game->mlx, &player_movements, game);
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