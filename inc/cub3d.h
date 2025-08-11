#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../MLX42/include/MLX42/MLX42.h"
#include "libft.h"

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

//habria que ponerlo en otra estrucutra!
#define size_of_tile 10

typedef enum	e_player_movements
{
	PLAYER_STOP_RIGHT,
	PLAYER_LEFT,
	PLAYER_RIGHT,
	PLAYER_UP,
	PLAYER_DOWN,
	PLAYER_STOP_LEFT,
	PLAYER_STOP_UP,
	PLAYER_STOP_DOWN,
}				t_player_movements;



// typedef enum	e_error_ok
// {
// 	OK,
// 	ERROR,
// }				t_errok;

#define LIMIT_FOV 50

/*   STRUCTURAS   */

typedef struct	s_coor
{
	int x;
	int y;
}				t_coor;

typedef  t_coor t_vector;

typedef struct	s_segment
{
	t_coor	start;
	t_coor	end;
}				t_segment;


typedef struct	s_player
{
	//t_vector	pos;
	t_coor	pos;
	t_coor	end;
	int		vision_angle;
	t_player_movements movement;
}				t_player;


typedef struct	s_map
{

	int		longest_line;
	int		map_len;


	char	**map_array;
	t_player	player[1];
}				t_map;

typedef struct	s_images
{
	mlx_image_t		*nose;
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
	//t_player player.
	t_images	images;
	t_map		map;
	mlx_t		*mlx;
}				t_game;
//create_images.c

void		draw_game(t_game *game);
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
void	init_game_struct(t_game *game);
void	init_images(mlx_t* mlx, t_map *map, t_images *images);
t_map	init_map(void);


//FUNKy_DESTROY
void	destroy_map(t_map *map);
void	destroy_images(mlx_t *mlx, t_images *images);

//get_map_info.c
void	get_map_info(t_map map);

//check_meta_map.c
int	line_checkeitor(char *line_map_to_check, t_map *map, int fd);

// check_map.c
void	check_map(char *arg_map, t_map *map);

//check_line.c
t_errok	is_empty_line(char *line);
int		is_valid_line(char **map, int current);
t_errok	check_first_line_map(char *line_map_to_check);

//check_file.c
t_errok	check_file(char *path_map);


//map_encasketeitor.c
int	str_map_encasketeitor(t_map *map, int fd);

//bresenham.c
void	bresenham_algorithm(mlx_image_t *player, int x1, int y1, int x2, int y2);

#endif