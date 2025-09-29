#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "../DRAW_GAME/draw_game.h"
# include "../FUNKY_DESTROY/funky_destroy.h"
# include "../PARSER/parser.h"
# include "../RENDER/render.h"
# include "../TOOLS_GENERICS/tools_generics.h"
# include "t_game.h"

// init_game.c
void	init_game(t_game *game, t_parser_map *parser_map);
void	init_images(mlx_t *mlx, t_map *map, t_images *images,
			t_parser_map *parser_map);

// init_texture.c
void	init_texture(mlx_t *mlx, t_images *images, t_parser_map *parser_map);

#endif