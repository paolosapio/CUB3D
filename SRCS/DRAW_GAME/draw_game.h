
#ifndef DRAW_GAME_H
# define DRAW_GAME_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "t_player.h"
#include "libft.h"

# define RGBA_SIZE 4

void	paint_tile(mlx_image_t	*img_minimap, float x_map, float y_map, int32_t color);
void	paint_player(mlx_image_t *img_minimap, float x_map, float y_map, int32_t color);
void	bresenham_algorithm(mlx_image_t *player, float x1, float y1, float x2, float y2);
void	paint_direction_player(mlx_image_t *map_player, t_player *player, int size_of_tile);
void	clean_image(mlx_image_t *image);

#endif
