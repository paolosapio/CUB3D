
#ifndef REFRESH_GAME_H
# define REFRESH_GAME_H

# include <math.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include "t_player.h"
# include "t_game.h"
# include "libft.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"

// typedef struct	s_triangle
// {
// 	t_segment	hypotenuse;
// 	t_segment	adjacent;
// 	t_segment	opposite;
// 	float		m;
// 	float		dir_x;
// 	float		dir_y;
// }			t_triangle;

# define RGBA_SIZE 4

void	refresh_draw_greco(mlx_image_t *map_greco, t_player *player, t_map *map);
void	clean_game_images(t_images *images);

#endif
