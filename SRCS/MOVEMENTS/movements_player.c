
#include "movements.h"


void	move_line_direction(t_player *player)
{
	player->end.y -= (sin((player->vision_angle / 180) * M_PI) / 10) * player->speed;
	player->end.x -= (cos((player->vision_angle / 180) * M_PI) / 10) * player->speed;
}


// void	move_player(t_player *player)
// {		
// 	player->pos.y -= (sin((player->vision_angle / 180) * M_PI) / 10) * player->speed;
// 	player->pos.x -= (cos((player->vision_angle / 180) * M_PI) / 10) * player->speed;
// 	move_line_direction(player);

// }

//// Spawnear el personaje en el centro de la casilla?

void	move_player(t_player *player, t_map *map)
{
	t_coor	new_player_pos;

	if (is_there_collision(*player, *map, &new_player_pos) == true)
		return ;
	
	player->pos.y = new_player_pos.y;
	player->pos.x = new_player_pos.x;
	move_line_direction(player);
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

void	movements_player(void *params)
{
	// static float	tire = 1;
	t_game *game;
	game = (t_game *)params;
	game->player.speed = SLOW;
	// if (game->player.key_is_released == true)
	// {
	// 	tire = tire - 0.09;
	// 	game->player.speed = NORMAL + tire;
	// 	if (antennas_north(game->player, game->map) == true)
	// 		move_player(&game->player);
	// 	if(tire < 0)
	// 	{
	// 		game->player.key_is_released = false;
	// 		tire = 1;
	// 	}
	// }
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		game->player.speed = TURBO;
	}

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		 //if (antennas_north(game->player, game->map) == true)
			move_player(&game->player, &game->map);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		// if (antennas_south(game->player, game->map) == true)
		// {
			game->player.pos.y += (sin((game->player.vision_angle / 180) * M_PI) / 10) * game->player.speed;
			game->player.pos.x += (cos((game->player.vision_angle / 180) * M_PI) / 10) * game->player.speed;

			game->player.end.y += (sin((game->player.vision_angle / 180) * M_PI) / 10) * game->player.speed;
			game->player.end.x += (cos((game->player.vision_angle / 180) * M_PI) / 10) * game->player.speed;
		// }
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		// if (antennas_right(game->player, game->map) == true)
		// {
			game->player.pos.y += (sin(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;
			game->player.pos.x += (cos(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;

			game->player.end.y += (sin(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;
			game->player.end.x += (cos(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;
		// }
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		// if (antennas_left(game->player, game->map) == true)
		// {
			game->player.pos.y -= (sin(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;
			game->player.pos.x -= (cos(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;

			game->player.end.y -= (sin(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;
			game->player.end.x -= (cos(((game->player.vision_angle - 90) / 180) * M_PI) / 10) * game->player.speed;
		// }
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		change_player_rotation(&game->player, game->player.vision_angle - 1);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		change_player_rotation(&game->player, game->player.vision_angle + 1);
	}
	draw_player_and_ray(game->images.map_player, &game->player, game->map.size_of_tile);
}
