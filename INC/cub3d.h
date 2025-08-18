#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "../MLX42/include/MLX42/MLX42.h"
#include "libft.h"
#include "map.h"
#include "player.h"
#include "../SRCS/PARSER/parser.h"

#define WIDTH 640
#define HEIGHT 480

/*   COLORS PRINTF  */

#define STD "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[0;35m"
#define BLUE "\033[1;36m"
#define ORANG "\033[1;33m"
#define WHITE "\033[1;37m"


#define PLAYER_MAP_COLOR 0xFF6600FF //naranja

#define OFF 0.1
#define ON 0.3
//habria que ponerlo en otra estrucutra!
#define size_of_tile 10

#define M_PI 3.14159265358979323846

// typedef enum	e_error_ok
// {
// 	OK,
// 	ERROR,
// }				t_errok;

#define LIMIT_FOV 10

/*   STRUCTURAS   */


typedef struct	s_images
{
	mlx_image_t		*sky;
	mlx_image_t		*floor;
	mlx_image_t		*mirilla;
	mlx_image_t		*minimap;
	mlx_image_t		*map_texture_N;
	mlx_image_t		*map_texture_S;
	mlx_image_t		*map_texture_E;
	mlx_image_t		*map_texture_O;
	mlx_image_t		*map_player;
}				t_images;

typedef struct	s_game
{
	t_images	images; 
	t_map		map;
	t_player	player;
	mlx_t		*mlx;
}				t_game;



//create_images.c

void		draw_game(t_game *game);
mlx_image_t	*create_sky(mlx_t *mlx, t_map *map);
mlx_image_t	*create_floor(mlx_t *mlx, t_map *map);
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_player_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_pinocchio_nose(mlx_t *mlx, t_map *map);
void	paint_tile(mlx_image_t	*img_minimap, float x_map, float y_map, int32_t color);
//get_next_line.c

char			*get_next_line(int fd);
char			*ft_read(int fd, char *remain);
char			*clean_remain(char *remain);
int				ft_find_end_line(char *line);
char			*gnl_strnjoin(char *s1, char *s2, int n);

//get_next_line_utils.c

void			ft_free(char **str);
char			*gnl_strdup(char *s1, int n);


//FUNKY INIT
void init_game_struct(t_game *game, t_parser_map *parser_map);
void	init_images(mlx_t* mlx, t_map *map, t_images *images);
t_map	init_map(void);


//FUNKy_DESTROY
void	destroy_images(mlx_t *mlx, t_images *images);

//bresenham.c
void	bresenham_algorithm(mlx_image_t *player, float x1, float y1, float x2, float y2);


#endif