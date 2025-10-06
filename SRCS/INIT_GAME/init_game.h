/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:59:50 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 16:14:14 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "../DRAW_GAME/draw_game.h"
# include "../FUNKY_DESTROY/funky_destroy.h"
# include "../PARSER/parser.h"
# include "../RENDER/render.h"
# include "../TOOLS_GENERICS/tools_generics.h"
# include "t_game.h"

// init_game.c

void			init_map_foundations(t_map *map, t_game *game);
void			init_game(t_game *game, t_parser_map *parser_map);

// load_non_png_images.c

void			load_non_png_images(mlx_t *mlx, t_map *map, t_images *imgs,
					t_parser_map *p_map);

// load_images_utils.c

mlx_texture_t	*load_n_check_texture(mlx_t *mlx, t_images *images,
					char *texture_path);
mlx_image_t		*load_n_check_image(mlx_t *mlx, t_images *imgs,
					char *texture_path);

// load_images.c

void			load_kelas_images(mlx_t *mlx, t_images *imgs);
void			load_frame_images(mlx_t *mlx, t_images *imgs);
void			load_map_greco(mlx_t *mlx, t_images *imgs);
void			load_bubbles(mlx_t *mlx, mlx_image_t **bubble_array,
					t_images *images);
void			load_images(mlx_t *mlx, t_images *imgs);

// load_textures.c

void			load_textures(mlx_t *mlx, t_images *imgs,
					t_parser_map *parser_map);
void			set_greco_icon(mlx_t *mlx, t_images *imgs);

#endif