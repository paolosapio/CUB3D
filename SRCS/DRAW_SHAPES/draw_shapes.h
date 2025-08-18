#ifndef DRAW_SHAPES_H
# define DRAW_SHAPES_H

# include "../../MLX42/include/MLX42/MLX42.h"

void	paint_tile(mlx_image_t	*img_minimap, float x_map, float y_map, int32_t color);
void	bresenham_algorithm(mlx_image_t *player, float x1, float y1, float x2, float y2);


#endif
