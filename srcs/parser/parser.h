#ifndef PARSER_H
# define PARSER_H

//open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
 
# include <stdio.h>
# include "libft.h"
# include "map.h"


# define LIMIT_FOV 50 //!TEMPORAL


/*   Errors    */
typedef enum	e_staterror
{
	INVALID_CHAR = 1,
	NOT_ENCLOSED_MAP,
	TOO_MANY_PLAYERS,
	INVALID_PLAYER_POSITION,
	NO_PLAYER,
	EMPTY_MAP,
}				t_staterror;

typedef struct	s_parser_player
{
	int	player_x;
	int	player_y;
	int	vision_angle;
}				t_parser_player;

typedef struct	s_parser_map
{
	int				line_that_start_map;
	char			*arg_map_fd;
	char			*info_north_texture;
	char			*info_east_texture;
	char			*info_south_texture;
	char			*info_west_texture;
	char			*info_floor;
	char			*info_sky;
	t_parser_player	*parser_player;
}				t_parser_map;

typedef enum	e_error_ok
{
	OK,
	ERROR,
}				t_errok;

/*   map chars   */
#define FLOOR "0"
#define WALL "1"
#define PLAYER "NEWS"
#define SPACE " "

//#define VALID_CHARS "10NSEW \n"
#define VALID_CHARS WALL FLOOR PLAYER SPACE "\n"


//get_map_info.c
void	get_map_info(t_map map);

//check_meta_map.c
int	line_checkeitor(char *line_map_to_check, t_map *map, t_parser_map *parser_map, int fd);
void	allocate_map_size(char *line_map_to_check, t_map *map, int fd);

// check_map.c
void	check_map(char *path_map, t_parser_map *parser_map, t_map *map);
//check_line.c
t_errok	is_empty_line(char *line);
int		is_valid_line(char **map, int current);
t_errok	check_first_line_map(char *line_map_to_check);

//check_file.c
t_errok	check_file_extension(char *path_map);

#endif