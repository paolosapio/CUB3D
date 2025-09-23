#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "t_game.h"
# include "../PARSER/parser.h"
# include "../DRAW_GAME/draw_game.h"
# include "../TOOLS_GENERICS/tools_generics.h"
# include "../RENDER/render.h"


// init_game.c
void	init_game(t_game *game, t_parser_map *parser_map);
void	init_images(mlx_t* mlx, t_map *map, t_images *images, t_parser_map *parser_map);

// init_texture.c
void 	init_texture(mlx_t* mlx, t_images *images, t_parser_map *parser_map);


#endif