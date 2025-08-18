#ifndef INPUT_KEYS_H
# define INPUT_KEYS_H

# include "t_game.h"
# include "../DRAW_SHAPES/draw_shapes.h"
# include <math.h>

# define SLOW 0.07
# define NORMAL 0.1
# define TURBO 0.3

# define M_PI 3.14159265358979323846

# define LIMIT_FOV 10

# define RGBA_SIZE 4


void await_user_input(t_game *game);

#endif