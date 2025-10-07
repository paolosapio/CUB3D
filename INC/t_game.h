#ifndef T_GAME_H
# define T_GAME_H

# include "t_player.h"
# include <sys/time.h>
# include "../SRCS/FUNKY_DESTROY/funky_destroy.h"
# include "../MLX42/include/MLX42/MLX42.h"

/* SCREEN RESOLUTION */

# define WIDTH 640
# define HEIGHT 480

/**
 * @param images t_images
 * @param map t_map
 * @param player t_player
 * @param mlx mlx_t: A pointer to an mlx connection started with mlx_init().
 * @param tile_size int: The size on pixels of each tile on the minimap
 * based on the map size.
 * @param map_is_closed bool: Wether the user opened or closed the map.
*/
typedef struct	s_game
{
	t_images	images;
	t_map		map;
	t_player	player;
	mlx_t		*mlx;
	int			tile_size;
	bool		map_is_closed;
	bool		new_frame;
}				t_game;

#endif
