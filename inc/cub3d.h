#ifndef CUB3D_H
# define CUB3D_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../MLX42/include/MLX42/MLX42.h"
#include "libft.h"

#define WIDTH 640
#define HEIGHT 480

// GNL BUFFER SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*   COLORS   */

#define STD "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[0;35m"
#define BLUE "\033[1;36m"
#define ORANG "\033[1;33m"
#define WHITE "\033[1;37m"


/*   test vectores   */
#define X 1
#define Y 0

typedef double t_coor;


typedef struct	s_vector
{
	t_coor	start[2];
	t_coor	end[2];
}				t_vector;

typedef struct	s_player
{
	t_vector	pos;

}				t_player;


/*   STRUCTURAS   */

typedef struct	s_map
{
	int		map_fd;
	char	*map_line;
	char	*map_line_buf;
	char	**map_array;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}				t_map;

typedef struct	s_images
{
	mlx_image_t		*mirilla;
	mlx_image_t		*map_texture_N;
	mlx_image_t		*map_texture_S;
	mlx_image_t		*map_texture_E;
	mlx_image_t		*map_texture_O;
}				t_images;

typedef struct	s_game
{
	t_images	*images;
	t_map		*map;
	mlx_t		*mlx;
}				t_game;
//draw_map.c

void	draw_game(t_game game);
void	draw_sky(mlx_t *mlx, t_map *map);
void	draw_floor(mlx_t *mlx, t_map *map);


//get_next_line.c

char			*get_next_line(int fd);
char			*ft_read(int fd, char *remain);
char			*clean_remain(char *remain);
int				ft_find_end_line(char *line);
char			*gnl_strnjoin(char *s1, char *s2, int n);

//get_next_line_utils.c

void			ft_free(char **str);
char			*gnl_strdup(char *s1, int n);


//INIT FUNKY
t_game init_game_struct(t_map *map);
t_images *init_images(mlx_t*	mlx);
t_map	init_map(void);