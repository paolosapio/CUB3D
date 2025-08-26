
#include "movements.h"

#define		COLLITIONS "1"

float	to_radians(float degrees)
{
	return ((degrees / 180) * M_PI);
}

void	move_line_direction(t_player *player, float sen, float cos)
{
	printf("vision_angle: [%f]\n", player->vision_angle);
	if (sen != 0.0)
		player->end.y += sen * player->speed;
	if (cos != 0.0)
		player->end.x += cos * player->speed;
}
	
	//!CON FISH MAP PETA PORQUE COMPRUEBA POSICIONES QUE NO PUEDE
bool collision_antenas(float speed, t_coor new_player_pos, t_map *map)
{

	const float	half_tile = 0.1 * speed;
	char		mask = 0;
	t_int_coor	antena_7;
	t_int_coor	antena_9;
	t_int_coor	antena_1;
	t_int_coor	antena_3;


	antena_7.x = new_player_pos.x - half_tile;
	antena_7.y = new_player_pos.y - half_tile;

	antena_9.x = new_player_pos.x + half_tile;
	antena_9.y = new_player_pos.y - half_tile;

	antena_1.x = new_player_pos.x - half_tile;
	antena_1.y = new_player_pos.y + half_tile;

	antena_3.x = new_player_pos.x + half_tile;
	antena_3.y = new_player_pos.y + half_tile;

	if (map->array[antena_7.y][antena_7.x] == '1')
	{
		printf("777777777777777777777\n");
		mask |= 0b1;
	}
	if (map->array[antena_9.y][antena_9.x] == '1')
	{
		printf("999999999999999999999\n");
		mask |= 0b10;
	}
	if (map->array[antena_1.y][antena_1.x] == '1')
	{
		printf("111111111111111111111\n");
		mask |= 0b100;
	}
	if (map->array[antena_3.y][antena_3.x] == '1')
	{
		printf("333333333333333333333\n");
		mask |= 0b1000;
	}
	printf("%b -> mask\n", mask);
	if ((mask & 0b110) == 0b110)
	{
		printf("CHOQUEEEEEEEEEEEEEEEE\n");
		return (true);
	}
	if ((mask & 0b1001) == 0b1001)
	{
		printf("CHOQUEEEEEEEEEEEEEEEE\n");
		return (true);
	}
	return (false);
}


void	move_player(t_player *player, t_map *map, float sen, float cos)
{
	t_coor		new_player_pos;
	t_int_coor	tile;





	new_player_pos.y = player->pos.y + sen * player->speed;
	new_player_pos.x = player->pos.x + cos * player->speed;
	tile.y = (int)new_player_pos.y;
	tile.x = (int)new_player_pos.x;

	if (collision_antenas(player->speed, new_player_pos, map) == true)
		return ;

	if (ft_strchr(COLLITIONS, map->array[tile.y][tile.x]))
	{
		printf("\n---------------------------------------------\n");
		printf("tile.y = %d player->pos.y = %d\n", tile.y, (int)player->pos.y);
		printf("tile.x = %d player->pos.x = %d\n", tile.x, (int)player->pos.x);
		printf("angle_vision %% 90 al detectar colisión: %d\n", ((int)player->vision_angle % 90));
		printf("\n---------------------------------------------\n");
		
		if (tile.y != (int)player->pos.y && (map->array[(int)player->pos.y][tile.x] && !ft_strchr(COLLITIONS, map->array[(int)player->pos.y][tile.x])))
		{
			player->pos.x = new_player_pos.x;
			move_line_direction(player, 0, cos);
		}
		else if (tile.x != (int)player->pos.x && (map->array[tile.y][(int)player->pos.x] && !ft_strchr(COLLITIONS, map->array[tile.y][(int)player->pos.x])))
		{
			player->pos.y = new_player_pos.y;
			move_line_direction(player, sen, 0);
		}
		return ;
	}
	if (map->array[tile.y][tile.x])
	{

	}
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
		seno = sin(to_radians(game->player.vision_angle + 0)) / game->map.size_of_tile;
		coseno = cos(to_radians(game->player.vision_angle + 0)) / game->map.size_of_tile;
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		seno = sin(to_radians(game->player.vision_angle + 90)) / game->map.size_of_tile;
		coseno = cos(to_radians(game->player.vision_angle + 90)) / game->map.size_of_tile;
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		seno = sin(to_radians(game->player.vision_angle + 180)) / game->map.size_of_tile;
		coseno = cos(to_radians(game->player.vision_angle + 180)) / game->map.size_of_tile;
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		seno = sin(to_radians(game->player.vision_angle + 270)) / game->map.size_of_tile;
		coseno = cos(to_radians(game->player.vision_angle + 270)) / game->map.size_of_tile;
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
	refresh_draw_greco(game->images.map_greco, &game->player, game->map.size_of_tile);
	refresh_draw_ray(game->images.map_ray, &game->player, game->map.size_of_tile);
}
