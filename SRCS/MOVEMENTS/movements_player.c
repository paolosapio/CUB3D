
#include "movements.h"

#define		COLLITIONS "1\n "

float	to_radians(float degrees)
{
	return ((degrees / 180) * M_PI);
}

void	move_line_direction(t_player *player, float sen, float cos)
{
	if (sen == 0.0 || cos == 0.0)
	{

		return ;
	}
	player->end.y += sen * player->speed;
	player->end.x += cos * player->speed;
}

void	move_player(t_player *player, t_map *map, float sen, float cos)
{
	t_coor		new_player_pos;
	t_int_coor	tile;

	printf("x: %f y: %f\n", player->pos.x, player->pos.y);
	new_player_pos.y = player->pos.y + sen;
	new_player_pos.x = player->pos.x + cos;
	printf("seno: %f, coseno: %f\n", sen, cos);
	printf("x: %f y: %f\n", new_player_pos.x, new_player_pos.y);
	tile.y = (int)new_player_pos.y;
	tile.x = (int)new_player_pos.x;

	if (map->array[tile.y][tile.x] == '\0' || ft_strchr(COLLITIONS, map->array[tile.y][tile.x]))
	{
		printf("\n---------------------------------------------\n");
		printf("tile.y = %d player->pos.y = %d\n", tile.y, (int)player->pos.y);
		printf("tile.x = %d player->pos.x = %d\n", tile.x, (int)player->pos.x);
		printf("angle_vision %% 90 al detectar colisión: %d\n", ((int)player->vision_angle % 90));
		printf("\n---------------------------------------------\n");
		if (tile.y != (int)player->pos.y)
		{
			player->pos.x = new_player_pos.x;
			move_line_direction(player, 0, cos);
		}
		else if (tile.x != (int)player->pos.x)
		{
			player->pos.y = new_player_pos.y;
			move_line_direction(player, sen, 0);
		}
		return ;
	}
	// if (map->array[tile.y][tile.x] == '\0' || ft_strchr(COLLITIONS, map->array[tile.y][tile.x]))
	// {
	// 	printf("\n---------------------------------------------\n");
	// 	printf("tile.y = %d player->pos.y = %d\n", tile.y, (int)player->pos.y);
	// 	printf("tile.x = %d player->pos.x = %d\n", tile.x, (int)player->pos.x);
	// 	printf("angle_vision %% 90 al detectar colisión: %d\n", ((int)player->vision_angle % 90));
	// 	printf("\n---------------------------------------------\n");
	// 	player->pos.y = new_player_pos.y;
	// 	move_line_direction(player, 0, sen);
	// 	return ;
	// }
	player->pos.y = new_player_pos.y;
	player->pos.x = new_player_pos.x;
	move_line_direction(player, sen, cos);
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
	t_game *game;
	game = (t_game *)params;
	game->player.speed = NORMAL;
	float	seno;
	float	coseno;

	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		game->player.speed = TURBO;
	}

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		seno = sin(to_radians(game->player.vision_angle + 0)) / game->map.size_of_tile * game->player.speed;
		coseno = cos(to_radians(game->player.vision_angle + 0)) / game->map.size_of_tile * game->player.speed;
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		seno = sin(to_radians(game->player.vision_angle + 90)) / game->map.size_of_tile * game->player.speed;
		coseno = cos(to_radians(game->player.vision_angle + 90)) / game->map.size_of_tile * game->player.speed;
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		seno = sin(to_radians(game->player.vision_angle + 180)) / game->map.size_of_tile * game->player.speed;
		coseno = cos(to_radians(game->player.vision_angle + 180)) / game->map.size_of_tile * game->player.speed;
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		seno = sin(to_radians(game->player.vision_angle + 270)) / game->map.size_of_tile * game->player.speed;
		coseno = cos(to_radians(game->player.vision_angle + 270)) / game->map.size_of_tile * game->player.speed;
		move_player(&game->player, &game->map, -seno, -coseno);
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
