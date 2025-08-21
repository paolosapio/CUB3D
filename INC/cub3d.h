#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "t_map.h"
#include "t_player.h"
#include "t_game.h"
#include "../SRCS/INIT_GAME/init_game.h"
#include "../SRCS/INPUT_KEYS/input_keys.h"



/*   COLORS PRINTF  */

#define STD "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[0;35m"
#define BLUE "\033[1;36m"
#define ORANG "\033[1;33m"
#define WHITE "\033[1;37m"


//create_images.c

mlx_image_t	*create_sky(mlx_t *mlx, t_map *map);
mlx_image_t	*create_floor(mlx_t *mlx, t_map *map);
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_player_minimap(mlx_t *mlx, t_map *map);
mlx_image_t	*create_pinocchio_nose(mlx_t *mlx, t_map *map);
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


//FUNKY_DESTROY
void	destroy_images(mlx_t *mlx, t_images *images);

//bresenham.c
void	bresenham_algorithm(mlx_image_t *player, float x1, float y1, float x2, float y2);


#endif