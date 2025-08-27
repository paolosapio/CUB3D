
#ifndef REFRESH_GAME_H
# define REFRESH_GAME_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "t_player.h"
# include "t_game.h"
# include "libft.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"


# define RGBA_SIZE 4

void	refresh_draw_greco(mlx_image_t *map_greco, t_player *player, t_map *map);
void	refresh_draw_ray(mlx_image_t *map_player, t_player *player, int tile_size);

#endif
