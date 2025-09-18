
#include "movements.h"
#include "../RENDER/render.h"

#define		COLLITIONS "1"

void	move_line_direction(t_player *player, float sen, float cos)
{
	if (sen != 0.0)
		player->end.y += sen * player->speed;
	if (cos != 0.0)
		player->end.x += cos * player->speed;
}

void	move_player(t_player *player, t_map *map, float sen, float cos)
{
	t_coor		new_player_pos;
	t_int_coor	tile;

	new_player_pos.y = player->pos.y + sen * player->speed;
	new_player_pos.x = player->pos.x + cos * player->speed;
	tile.y = (int)new_player_pos.y;
	tile.x = (int)new_player_pos.x;
	if ((map->array[(int)player->pos.y][tile.x] && !ft_strchr(COLLITIONS, map->array[(int)player->pos.y][tile.x])))
	{
		player->pos.x = new_player_pos.x;
		move_line_direction(player, 0, cos);
	}
	if ((map->array[tile.y][(int)player->pos.x] && !ft_strchr(COLLITIONS, map->array[tile.y][(int)player->pos.x])))
	{
		player->pos.y = new_player_pos.y;
		move_line_direction(player, sen, 0);
	}
}

void	change_player_rotation(t_player *player, int new_vision_angle)
{
	if(new_vision_angle == 0)
		new_vision_angle = 360;
	else if (new_vision_angle == 360)
		new_vision_angle = 0;
	
	player->vision_angle = new_vision_angle;
	player->end.x = player->pos.x - cos(to_radians(player->vision_angle)) * LIMIT_FOV;
	player->end.y = player->pos.y - sin(to_radians(player->vision_angle)) * LIMIT_FOV;
}

void angulator_move(float vision_angle, int g_size_tile, t_game *game)
{
	t_trig_angle trig_angle;

	trig_angle.angle = vision_angle;
	trig_angle.s1n = sin(to_radians(vision_angle)) / g_size_tile;
	trig_angle.c0s = cos(to_radians(vision_angle)) / g_size_tile;
	move_player(&game->player, &game->map, -trig_angle.s1n, -trig_angle.c0s);
}

void	movements_player(void *params)
{
	t_game *game;

	game = (t_game *)params;

	if (game->player.movements == PLAYER_W)
	{
		angulator_move(game->player.vision_angle + 0, g_size_tile, game);
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) == false && mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) == false)
		{
			clean_game_images(&game->images);
			init_camera(game, game->player.pos, game->player.vision_angle);
		}
	}
	if (game->player.movements == PLAYER_D)
	{
		angulator_move(game->player.vision_angle + 90, g_size_tile, game);
		clean_game_images(&game->images);
		init_camera(game, game->player.pos, game->player.vision_angle);
	}
	if (game->player.movements == PLAYER_S)
	{
		angulator_move(game->player.vision_angle + 180, g_size_tile, game);
		clean_game_images(&game->images);
		init_camera(game, game->player.pos, game->player.vision_angle);
	}
	if (game->player.movements == PLAYER_A)
	{
		angulator_move(game->player.vision_angle + 270, g_size_tile, game);
		clean_game_images(&game->images);
		init_camera(game, game->player.pos, game->player.vision_angle);
	}
	if (game->player.movements == PLAYER_LEFT)
	{
		change_player_rotation(&game->player, game->player.vision_angle - 1);
		clean_game_images(&game->images);
		init_camera(game, game->player.pos, game->player.vision_angle);
	}
	if (game->player.movements == PLAYER_RIGHT)
	{
		change_player_rotation(&game->player, game->player.vision_angle + 1);
		clean_game_images(&game->images);
		init_camera(game, game->player.pos, game->player.vision_angle);
	}
	refresh_draw_greco(game->images.map_greco, &game->player, &game->map);
}
