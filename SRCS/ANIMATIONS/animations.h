#ifndef ANIMATIONS_H
# define ANIMATIONS_H

# include "t_game.h"

# define CAROUSEL_NORMAL_MOVEMENT -0.4
# define CAROUSEL_LEFT_MOVEMENT 7.0
# define CAROUSEL_RIGHT_MOVEMENT -7.0

void	carousel(mlx_image_t **image, const float movement);
void	carousel_reverse(mlx_image_t *image, const float movement);


#endif

