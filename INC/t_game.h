#ifndef T_GAME_H
# define T_GAME_H

# include "t_player.h"
# include <sys/time.h>
# include "../SRCS/FUNKY_DESTROY/funky_destroy.h"
# include "../MLX42/include/MLX42/MLX42.h"

/* SCREEN RESOLUTION */

// # define WIDTH 1500
// # define HEIGHT 1000

# define WIDTH 640
# define HEIGHT 480

typedef struct	s_game
{
	t_images		images;
	t_map			map;
	t_player		player;
	mlx_t			*mlx;
	//struct timeval	init_time;
	int				tile_size;
}				t_game;

#endif
