
#ifndef DRAW_GAME_H
# define DRAW_GAME_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "t_player.h"
#include "libft.h"

# define RGBA_SIZE 4

void	draw_greco(mlx_image_t *map_greco, t_player *player, int size_of_tile);
void	draw_ray(mlx_image_t *map_player, t_player *player, int size_of_tile);
void	paint_player(int size_of_tile, mlx_image_t	*img_minimap, t_coor player, int32_t color);
void	paint_tile(int size_of_tile, mlx_image_t *img_minimap, t_int_coor coor, int32_t color);
void	bresenham_algorithm(mlx_image_t *player, float x1, float y1, float x2, float y2);
void	clean_image(mlx_image_t *image);

#endif
