
#ifndef GRAPHIC_TOOLS_H
# define GRAPHIC_TOOLS_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "t_player.h"
# include "t_game.h"
#include "libft.h"

# define RGBA_SIZE 4

void			paint_tile(int g_size_tile, mlx_image_t *img_minimap, t_coor coor, int32_t color);
void			bresenham_algorithm(mlx_image_t *image, t_segment s, uint32_t color, int tile_size);
void			clean_image(mlx_image_t *image);
unsigned int	ft_color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);

#endif
