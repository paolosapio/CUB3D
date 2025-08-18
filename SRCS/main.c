
#include "cub3d.h"
#define RGBA_SIZE 4

void	clean_image(mlx_image_t		*image)
{
	memset(image->pixels, 0, image->width * image->height * RGBA_SIZE);
}

void	paint_move_player(mlx_image_t		*map_player, t_player *player)
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
	paint_tile(map_player, player->pos.x, player->pos.y, 0xFF6600FF);
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
		if(game->map.player_pointer->vision_angle == 0)
			game->map.player_pointer->vision_angle = 360;
		game->map.player_pointer->vision_angle--;
	}
	else if (mouse_x > first_step_x)
	{
		if(game->map.player_pointer->vision_angle == 360)
			game->map.player_pointer->vision_angle = 0;
		game->map.player_pointer->vision_angle++;
	}

	game->player.end.x = game->player.pos.x + cos((game->player.vision_angle / 180.0) * 3.14) * LIMIT_FOV;
	game->player.end.y = game->player.pos.y + sin((game->player.vision_angle / 180.0) * 3.14) * LIMIT_FOV;

	first_step_x = mouse_x;
	paint_move_player(game->images.map_player, &game->player);
}

void	change_player_rotation(t_player *player, int new_vision_angle)
{
	if(new_vision_angle == 0)
		new_vision_angle = 360;
	else if (new_vision_angle == 360)
		new_vision_angle = 0;
	
	player->vision_angle = new_vision_angle;

	printf("PLAYER POSITION: x: %d, y: %d\n", player->pos.x, player->pos.y);
	printf("ANGLE_VISION: %d - %f\n", player->vision_angle, (player->vision_angle / 180.0) * 3.14);
	printf("pos_y = %d, pos_x = %d. cos(angle) = %f | %d, sin(angle) = %f | %d\n", player->end.y,
		player->end.x,
		cos((player->vision_angle / 180.0) * 3.14) * LIMIT_FOV,
		(int)(cos((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV), 
		sin((player->vision_angle / 180.0) * 3.14) * LIMIT_FOV,
		(int)(sin((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV));

	printf("La suma gigantérrima de x da: %d\n", player->pos.x + (int)(-cos((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV));
	printf("La suma gigantérrima de y da: %d\n", player->pos.y + (int)(-sin((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV));
	player->end.x = player->pos.x + (int)(-cos((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV);
	player->end.y = player->pos.y + (int)(-sin((player->vision_angle / 180.0) * M_PI) * LIMIT_FOV);
	printf("-->> pos_y = %d, pos_x = %d\n", player->end.y,
		player->end.x);
}

void	player_movements(void *params)
{
	t_game *game;
	game = (t_game *)params;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player.pos.y--;
		game->player.end.y--;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.pos.y++;
		game->player.end.y++;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.pos.x++;
		game->player.end.x++;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.pos.x--;
		game->player.end.x--;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		change_player_rotation(&game->player, game->player.vision_angle + 1);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		change_player_rotation(&game->player, game->player.vision_angle - 1);
	}
	paint_move_player(game->images.map_player, &game->player);
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
	init_game_struct(game, parser_map);
	draw_game(game);
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_loop_hook(game->mlx, &player_movements, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);
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