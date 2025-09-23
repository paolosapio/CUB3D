#ifndef FUNKY_DESTROY_H
# define FUNKY_DESTROY_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "t_map.h"
# include "t_images.h"
# include "t_game.h"
# include "libft.h"

void	destroy_map(t_map *map);
void	destroy_images(mlx_t *mlx, t_images *images);
void	sayonara_baby(mlx_t* mlx, t_images *images, t_map *map);




#endif
