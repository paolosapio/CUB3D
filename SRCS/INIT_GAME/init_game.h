#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "t_game.h"
# include "../PARSER/parser.h"
# include "../DRAW_SHAPES/draw_shapes.h"


//Create_images.c

mlx_image_t	*create_player_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_sky(mlx_t *mlx, t_map *map);
mlx_image_t	*create_floor(mlx_t *mlx, t_map *map);

// init_game.c

void	init_game(t_game *game, t_parser_map *parser_map);
void	init_images(mlx_t* mlx, t_map *map, t_images *images);
void	put_images_to_window(t_game *game);

#endif