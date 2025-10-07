/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:42:51 by psapio            #+#    #+#             */
/*   Updated: 2025/10/07 23:18:26 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	move_line_direction(t_player *player, float sen, float cos)
{
	if (sen != 0.0)
		player->end.y += sen * player->speed;
	if (cos != 0.0)
		player->end.x += cos * player->speed;
}

void	move_player(t_player *player, t_map *map, float sen, float cos)
{
	t_coor			new_player_pos;
	t_int_coor		tile;
	const t_coor	stop_collision = {.y = (sen * DISTANCE_COLLISION), .x = (cos
			* DISTANCE_COLLISION)};

	new_player_pos.y = (player->pos.y + sen * player->speed);
	new_player_pos.x = (player->pos.x + cos * player->speed);
	tile.y = (int)(new_player_pos.y + stop_collision.y);
	tile.x = (int)(new_player_pos.x + stop_collision.x);
	if ((map->array[(int)player->pos.y][tile.x] && !ft_strchr(COLLITIONS,
			map->array[(int)player->pos.y][tile.x])))
	{
		player->pos.x = new_player_pos.x;
		move_line_direction(player, 0, cos);
	}
	if ((map->array[tile.y][(int)player->pos.x] && !ft_strchr(COLLITIONS,
			map->array[tile.y][(int)player->pos.x])))
	{
		player->pos.y = new_player_pos.y;
		move_line_direction(player, sen, 0);
	}
}

void	change_player_rotation(t_player *player, int new_vision_angle)
{
	if (new_vision_angle <= 0)
		new_vision_angle = 360;
	else if (new_vision_angle >= 360)
		new_vision_angle = 0;
	player->vision_angle = new_vision_angle;
	player->end.x = player->pos.x - cos(to_radians(player->vision_angle))
		* LIMIT_FOV;
	player->end.y = player->pos.y - sin(to_radians(player->vision_angle))
		* LIMIT_FOV;
}

void	movements_player(void *params)
{
	t_game	*game;

	game = (t_game *)params;
	movement_wasd(game);
	if (game->player.movements.key_left_is_down == true)
	{
		carousel(game->images.fauna, CAROUSEL_LEFT_MOVEMENT);
		carousel_reverse(game->images.ambient, CAROUSEL_LEFT_MOVEMENT);
		change_player_rotation(&game->player, game->player.vision_angle - 1);
		clean_game_images(&game->images);
		init_camera(game, game->player.pos, game->player.vision_angle);
	}
	if (game->player.movements.key_right_is_down == true)
	{
		carousel(game->images.fauna, CAROUSEL_RIGHT_MOVEMENT);
		carousel_reverse(game->images.ambient, CAROUSEL_RIGHT_MOVEMENT);
		change_player_rotation(&game->player, game->player.vision_angle + 1);
		clean_game_images(&game->images);
		init_camera(game, game->player.pos, game->player.vision_angle);
	}
	refresh_draw_greco(game->images.greco_map[game->player.greco_map_dir],
		&game->player, &game->map);
}
