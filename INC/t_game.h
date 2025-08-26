#ifndef T_GAME_H
# define T_GAME_H

# include "t_map.h"
# include "t_player.h"
# include "t_images.h"
# include "../MLX42/include/MLX42/MLX42.h"

/* SCREEN RESOLUTION */

// # define WIDTH 1600
// # define HEIGHT 900

# define WIDTH 800
# define HEIGHT 600

typedef struct	s_game
{
	t_images	images;
	t_map		map;
	t_player	player;
	mlx_t		*mlx;
	int			screen_width;
	int			screen_height;
}				t_game;

#endif
