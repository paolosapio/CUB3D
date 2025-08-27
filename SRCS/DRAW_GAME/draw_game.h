
#ifndef DRAW_GAME_H
# define DRAW_GAME_H

# include "../../MLX42/include/MLX42/MLX42.h"
#include "../TOOLS_GRAPHICS/tools_graphics.h"
# include "t_player.h"
# include "t_game.h"
#include "libft.h"

void		images_to_window(t_game *game);
mlx_image_t	*create_ray_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map, t_images *image);
mlx_image_t	*create_sky(mlx_t *mlx, t_map *map);
mlx_image_t	*create_background_map(mlx_t *mlx, t_map *map);
mlx_image_t	*create_floor(mlx_t *mlx, t_map *map);
void		images_to_window(t_game *game);


#endif
