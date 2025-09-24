#ifndef T_GAME_H
# define T_GAME_H

# include "t_player.h"
# include "../SRCS/FUNKY_DESTROY/funky_destroy.h"
# include "../MLX42/include/MLX42/MLX42.h"

/* SCREEN RESOLUTION */

# define WIDTH 640
# define HEIGHT 480

// # define WIDTH 640
// # define HEIGHT 480

extern unsigned int g_size_tile;

typedef struct	s_game
{
	t_images	images;
	t_map		map;
	t_player	player;
	mlx_t		*mlx;
}				t_game;

#endif
