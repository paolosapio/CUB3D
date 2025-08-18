
#include "input_keys.h"
#include "libft.h"

void	clean_image(mlx_image_t		*image)
{
	ft_memset(image->pixels, 0, image->width * image->height * RGBA_SIZE);
}

void	paint_direction_player(mlx_image_t *map_player, t_player *player, int size_of_tile)
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

#define MOUSE_LIMIT_RANGE 50
void mouse_movements(double mouse_x, double mouse_y, void *params)
{
	t_game *game;
	static double first_step_x = 0;

	(void)mouse_y;
	game = (t_game *)params;
	if (mouse_x > WIDTH - MOUSE_LIMIT_RANGE)
		mlx_set_mouse_pos(game->mlx, 51, HEIGHT / 2);
	else if (mouse_x <= MOUSE_LIMIT_RANGE)
		mlx_set_mouse_pos(game->mlx, WIDTH - 51, HEIGHT / 2);
	if (mouse_y <= MOUSE_LIMIT_RANGE || mouse_y >= HEIGHT - MOUSE_LIMIT_RANGE)
		mlx_set_mouse_pos(game->mlx, mouse_x, HEIGHT / 2);

	// printf("CENTER: %d-%d || MOUSEX: %f, MOUSEY: %f\n",WIDTH / 2, HEIGHT / 2, mouse_x, mouse_y);
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
	paint_direction_player(game->images.map_player, &game->player, game->map.size_of_tile);
}

void	player_movements(void *params)
{
	t_game *game;
	game = (t_game *)params;
	float	speed;

	speed = SLOW;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		speed = TURBO;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player.pos.y-=speed;
		game->player.end.y-=speed;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.pos.y+=speed;
		game->player.end.y+=speed;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.pos.x+=speed;
		game->player.end.x+=speed;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.pos.x-=speed;
		game->player.end.x-=speed;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		change_player_rotation(&game->player, game->player.vision_angle - 1);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		change_player_rotation(&game->player, game->player.vision_angle + 1);
	}
	paint_direction_player(game->images.map_player, &game->player, game->map.size_of_tile);
}

void await_user_input(t_game *game)
{
	mlx_key_hook(game->mlx, &special_keys, game);
	mlx_cursor_hook(game->mlx, &mouse_movements, game);
	mlx_loop_hook(game->mlx, &player_movements, game);
	mlx_loop(game->mlx);
}