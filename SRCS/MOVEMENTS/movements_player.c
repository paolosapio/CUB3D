
#include "movements.h"

#define		COLLITIONS "1"

float	to_radians(float degrees)
{
	return ((degrees / 180) * M_PI);
}

void	move_line_direction(t_player *player, float sen, float cos)
{
	printf("vision_angle: [%f]\n", player->vision_angle);
	printf("sen = %f - cos = %f\n", sen, cos);
	if (sen != 0.0)
		player->end.y += sen * player->speed;
	if (cos != 0.0)
		player->end.x += cos * player->speed;
}

//!CON FISH MAP PETA PORQUE COMPRUEBA POSICIONES QUE NO PUEDE
void collision_antenas(t_player *player, t_coor new_player_pos, t_map *map, float sen, float cos)
{
	const float	half_tile = 0.1 * player->speed;
	char		mask = 0;

	// t_int_coor	antena_7;
	// t_int_coor	antena_9;
	// t_int_coor	antena_1;
	// t_int_coor	antena_3;

	// antena_7.x = new_player_pos.x - half_tile;
	// antena_7.y = new_player_pos.y - half_tile;

	// antena_9.x = new_player_pos.x + half_tile;
	// antena_9.y = new_player_pos.y - half_tile;

	// antena_1.x = new_player_pos.x - half_tile;
	// antena_1.y = new_player_pos.y + half_tile;

	// antena_3.x = new_player_pos.x + half_tile;
	// antena_3.y = new_player_pos.y + half_tile;

	t_int_coor	antena_8;
	t_int_coor	antena_6;
	t_int_coor	antena_2;
	t_int_coor	antena_4;

	bool up_switch;
	bool right_switch;
	bool down_switch;
	bool left_switch;

	antena_8.x = new_player_pos.x;
	antena_8.y = new_player_pos.y - half_tile;

	antena_6.x = new_player_pos.x + half_tile;
	antena_6.y = new_player_pos.y;

	antena_2.x = new_player_pos.x;
	antena_2.y = new_player_pos.y + half_tile;

	antena_4.x = new_player_pos.x - half_tile;
	antena_4.y = new_player_pos.y;


	if (map->array[antena_8.y][antena_8.x] == '1')
		up_switch = true;
	if (map->array[antena_6.y][antena_6.x] == '1')
		right_switch = true;
	if (map->array[antena_2.y][antena_2.x] == '1')
		down_switch = true;
	if (map->array[antena_4.y][antena_4.x] == '1')
		left_switch = true;
	
	if (up_switch || up_switch && left_switch || up_switch && right_switch)
		printf("STOP!!!!!!!!\n");


}


void	move_player(t_player *player, t_map *map, float sen, float cos)
{
	static int i= 0;
	printf("\n\n-------------------%d------------------\n", i++);
	t_coor		new_player_pos;
	t_int_coor	tile;

	new_player_pos.y = player->pos.y + sen * player->speed;
	new_player_pos.x = player->pos.x + cos * player->speed;
	printf("new_player_pos.y = %f, player->pos.y = %f\n", new_player_pos.y, player->pos.y);
	printf("new_player_pos.x = %f, player->pos.x = %f\n", new_player_pos.x, player->pos.x);
	tile.y = (int)new_player_pos.y;
	tile.x = (int)new_player_pos.x;

	collision_antenas(player, new_player_pos, map, sen, cos);

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
		seno = sin(to_radians(game->player.vision_angle + 0)) / (game->map.size_of_tile / 2);
		coseno = cos(to_radians(game->player.vision_angle + 0)) / (game->map.size_of_tile / 2);
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		seno = sin(to_radians(game->player.vision_angle + 90)) / (game->map.size_of_tile / 2);
		coseno = cos(to_radians(game->player.vision_angle + 90)) / (game->map.size_of_tile / 2);
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		seno = sin(to_radians(game->player.vision_angle + 180)) / (game->map.size_of_tile / 2);
		coseno = cos(to_radians(game->player.vision_angle + 180)) / (game->map.size_of_tile / 2);
		move_player(&game->player, &game->map, -seno, -coseno);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		seno = sin(to_radians(game->player.vision_angle + 270)) / (game->map.size_of_tile / 2);
		coseno = cos(to_radians(game->player.vision_angle + 270)) / (game->map.size_of_tile / 2);
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
