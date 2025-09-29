
#ifndef DRAW_GAME_H
# define DRAW_GAME_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"
# include "libft.h"
# include "t_game.h"
# include "t_player.h"

# define SKY 1
# define SAND 0

void		images_to_window(t_game *game);
mlx_image_t	*create_ray_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_half_screen_rectangle(mlx_t *mlx, int color);
mlx_image_t	*create_background_map(mlx_t *mlx, t_map *map);
void		images_to_window(t_game *game);
mlx_image_t	*create_tridy(mlx_t *mlx);
mlx_image_t	*create_gradient_bgr(mlx_t *mlx);

#endif
