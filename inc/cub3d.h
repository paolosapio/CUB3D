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

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_map
{
	int		map_fd;
	char	*map_line;
	char	*map_line_buf;
	char	**map;
	t_img	map_texture[4];
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	mlx_image_t		*image_mirilla;
}				t_map;


//draw_map.c

void	draw_map(mlx_t *mlx, t_map map);
void	draw_sky(mlx_t *mlx, t_map map);
void	draw_floor(mlx_t *mlx, t_map map);


//get_next_line.c

char			*get_next_line(int fd);
char			*ft_read(int fd, char *remain);
char			*clean_remain(char *remain);
int				ft_find_end_line(char *line);
char			*gnl_strnjoin(char *s1, char *s2, int n);

//get_next_line_utils.c

void			ft_free(char **str);
char			*gnl_strdup(char *s1, int n);
