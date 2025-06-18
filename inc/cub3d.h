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

/*   COLORS   */

#define STD "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[0;35m"
#define BLUE "\033[1;36m"
#define ORANG "\033[1;33m"
#define WHITE "\033[1;37m"

/* MAP INFO */

#define NORTH_TEXTURE 0
#define EAST_TEXTURE 1
#define SOUTH_TEXTURE 2
#define WEST_TEXTURE 3
#define FLOOR 4
#define SKY 5

/*   test vectores   */

#define X 1
#define Y 0

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

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
	char	*map_info_north_texture;
	char	*map_info_east_texture;
	char	*map_info_south_texture;
	char	*map_info_west_texture;
	char	*map_info_floor;
	char	*map_info_sky;

	char	**map_array;

	unsigned int	floor_color;
	unsigned int	sky_color;
}				t_map;

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
}				t_images;

typedef struct	s_game
{
	t_images	images;
	t_map		map;
	mlx_t		*mlx;
}				t_game;
//draw_map.c

void		draw_game(t_game *game);
mlx_image_t	*create_sky(mlx_t *mlx, t_map *map);
mlx_image_t	*create_floor(mlx_t *mlx, t_map *map);
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map);

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
void init_game_struct(t_game *game);
void	init_images(mlx_t* mlx, t_map *map, t_images *images);
t_map	init_map(void);

//get_map_info.c
void	get_map_info(t_map map);


// check_map.c
void check_map(char *arg_map, t_map *map);