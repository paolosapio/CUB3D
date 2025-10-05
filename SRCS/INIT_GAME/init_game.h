/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:59:50 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 19:59:56 by psapio           ###   ########.fr       */
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

typedef enum e_greco_map_dir
{
	W_,
	NW,
	N_,
	NE,
	E_,
	SE,
	S_,
	SW,
}		t_greco_map_dir;

// init_game.c
void	init_game(t_game *game, t_parser_map *parser_map);
void	init_images(mlx_t *mlx, t_map *map, t_images *images,
			t_parser_map *parser_map);

// init_texture.c
void	init_texture(mlx_t *mlx, t_images *images, t_parser_map *parser_map);

#endif