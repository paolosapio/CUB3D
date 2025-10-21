/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:30:01 by psapio            #+#    #+#             */
/*   Updated: 2025/10/21 23:06:43 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include <stdio.h>
# include "t_coordinate.h"
# include "../LOAD_GAME/load_game.h"
# include "../TOOLS_GENERICS/tools_generics.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"

# define SCREEN 1.2
# define HALF_SCREEN 0.6
# define DISTANCE_SCREEN 0.5

// FOV : FIELD OF VIEW (campo visual, lo que vemos en pantalla)
// distancia de la pantalla del jugador y tamaño de la pantalla varian la vista

typedef t_coor		t_hypo2_len;
typedef t_coor		t_ray_len;
typedef t_int_coor	t_dir;

typedef enum e_texture_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}			t_texture_dir;

typedef struct s_texture_line
{
	t_texture_dir	dir;
	t_coor			texture_coor;
	t_coor			screen_coor;
	mlx_texture_t	*texture;
	float			screen_wall_height;
}				t_texture_line;

/**
 * dir: The direction on the y and x axys. Either 1 or -1.
 * hypo_unitary: How much does the hypothenuse increase when you move one unit
 * 				 in each axys.
 */
typedef struct s_ray
{
	t_coor		colision_point;
	float		colision_len;
	float		vertical_line;
	float		darkener_percent;
	t_dir		dir;
	t_ray_len	hypo_unitary;
	t_ray_len	hypo_supreme;
}				t_ray;

/**
 * @brief 
 * 
 * @param middle_screen_point (t_coor)
 * The point inside the player's dir vector that is at DISTANCE_SCREEN.
 * We will draw a new vector with -90° dir at HALF_SCREEN distance which will
 * be the start of the camera plane -> l_screen_point.
 * @param l_screen_point (t_coor)
 * The start of the camera plane.
 * @param pixel_offset_cos (float)
 * the x offset of the camera plane for each new ray (1 ray per screen pixel).
 * @param pixel_offset_sin (float)
 * the y offset of the camera plane for each new ray (1 ray per screen pixel).
 * @param ray (t_ray)
 * the ray we are launching each time with all it's information needed to draw
 * the pseudo 3d game.
 * @param x_pos_in_screen (int)
 * The x coordinate inside the screen, which equals to the ray index.
 * @param player_to_camera_len (float) the hipothenuse formed between the player
 * and l_screen_point, used to fix the fish eye.
 */
typedef struct s_camera
{
	t_coor		middle_screen_point;
	t_coor		l_screen_point;
	float		pixel_offset_cos;
	float		pixel_offset_sen;
	t_ray		ray;
	int			x_pos_in_screen;
	float		player_to_camera_len;
}		t_camera;

// draw_wall_texture.c
void	to_3d(t_ray ray, t_game *game, float ray_index);
void	draw_texture_line(mlx_image_t *img, t_ray ray, t_texture_line t);

// check_wall_texture.c
void	check_north_south(t_ray ray, t_game *game, float ray_i, t_coor rounded);
void	check_east_west(t_ray ray, t_game *game, float ray_i, t_coor rounded);

void	minimap_closer(t_game *game, bool info_img_state);

void	init_camera(t_game *game, t_coor player_coor,
			float player_vision_angle);
t_ray	raycasting(t_coor start_pos, t_coor end_pos, t_map map);

//raycasting_utils.c

void	gradienteitor(t_ray_len sides, t_ray *ray);
void	set_collision_point(t_ray *ray, t_coor start);

#endif
