
#ifndef REFRESH_GAME_H
# define REFRESH_GAME_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "t_player.h"
# include "t_game.h"
# include "libft.h"
# include "../TOOLS_GRAPHICS/tools_graphics.h"

typedef struct	s_triangle
{
	t_segment	hypotenuse;
	t_segment	adjacent;
	t_segment	opposite;
	float		m;
}			t_triangle;

# define RGBA_SIZE 4

void	refresh_draw_greco(mlx_image_t *map_greco, t_player *player, t_map *map);
void	refresh_draw_ray(mlx_image_t *map_player, t_player *player, int g_size_tile);
void	raycasting(mlx_image_t *image, t_player player, t_map map, t_coor end);


float	hipotenuseitor_no_root(t_segment adiacente,t_segment opposite);
void	raycasting(mlx_image_t *image, t_player player, t_map map, t_coor end);
// float	gradienteitor(t_coor start, t_coor end);

t_triangle  collision_triangulator_y(t_coor start, t_coor end);
t_triangle  collision_triangulator_x(t_coor start, t_coor end);

#endif
