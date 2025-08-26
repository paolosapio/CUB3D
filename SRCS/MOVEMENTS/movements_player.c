
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
		mask |= 0b1;
	if (map->array[antena_9.y][antena_9.x] == '1')
		mask |= 0b10;
	if (map->array[antena_1.y][antena_1.x] == '1')
		mask |= 0b100;
	if (map->array[antena_3.y][antena_3.x] == '1')
		mask |= 0b1000;

	printf("%b -> mask\n", mask);

	if (mask == 0b0000) //NO COLISIONES
	{
		player->pos.y = new_player_pos.y;
		player->pos.x = new_player_pos.x;
		move_line_direction(player, sen, cos);
	}
	else if (mask == 0b11 || mask == 0b1100) // COLISIONES ARRIBA O ABAJO
	{
		player->pos.x = new_player_pos.x;
		move_line_direction(player, 0, cos);
	}
	else if (mask == 0b101 || mask == 0b1010 ) // COLISIONES LATERALES
	{
		printf("COLISION LATERAL\n");
		player->pos.y = new_player_pos.y;
		move_line_direction(player, sen, 0);
	}
	else if ((mask & 0b110) == 0b110 || (mask & 0b1001) == 0b1001) // COLISIONES DIAGONALES
	{
		printf("COLISIONES DIAGONALES!!!!\n");
		return ;
	}
	else // solo colisiona una esquina creo
	{
		printf("Solo colisiona una esquina pareciera ser\n");

		player->pos.y = new_player_pos.y;
		player->pos.x = new_player_pos.x;
		move_line_direction(player, sen, cos);
	}
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
