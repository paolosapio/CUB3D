/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:04:17 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 20:31:02 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../INC/t_map.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

# define LIMIT_FOV 1.5

/*   Errors    */
typedef enum e_staterror
{
	INVALID_CHAR = 1,
	NOT_ENCLOSED_MAP,
	TOO_MANY_PLAYERS,
	INVALID_PLAYER_POSITION,
	NO_PLAYER,
	EMPTY_MAP,
}				t_staterror;

/**
 * @brief Keeps information that is only needed before starting the game loop.
 * Once each texture image has already been loaded as an mlx_image_t,
 * it's path is no longer needed so all that kind of information is stored in 
 * this sruct that will be freed and forgotten.
 * 
 * - line_that_start_map: the line index where the map array starts after the
 * texture's paths and the color codes. Used when reopening the .cub file.
 *
 * - map_path: The path to the map.
 * 
 * - path_?: The path to each texture.
 * 
 * - info_floor / info_sky: The color code.
 */
typedef struct s_parser_map
{
	int		line_that_start_map;
	char	*map_path;
	char	*path_n;
	char	*path_e;
	char	*path_s;
	char	*path_w;
	char	*info_floor;
	char	*info_sky;
}				t_parser_map;

typedef enum e_error_ok
{
	OK,
	ERROR,
}				t_errok;

/*   map chars   */
# define FLOOR "0"
# define WALL "1"
# define PLAYER "NEWS"
# define SPACE " "

# define VALID_CHARS "10NEWS \n"
# define SPACES " \f\n\r\t\v"

/* parser.c */

t_parser_map	parser(char *map_path, t_map *map);

/* check_file_extension.c */

t_errok			check_file_extension(char *path_map);

/* check_map.c */

void			check_map(char *path_map, t_parser_map *parser_map, t_map *map);
int				fd_open_or_exit(char *path_map);
void			check_valid_map(t_parser_map *parser_map, t_map *map);
void			error_exit_invalid_map(t_parser_map *parser_map, t_map *map,
					int error);

/* check_meta_map.c */

int				check_line(char *line_map_to_check, t_map *map,
					t_parser_map *parser_map, int fd);
int				save_map_info(char *line_map_to_check, char **map_info);
void			check_textures_path(t_parser_map *map);
void			allocate_map_size(char *line_map_to_check, t_map *map, int fd);

/* check_line_utils.c */

bool			is_empty_line(char *line);
t_errok			check_first_line_map(char *line_map_to_check);

/* map_encasketeitor.c */

int				str_map_encasketeitor(t_parser_map *parser_map, t_map *map,
					int fd);

/* check_tile.c */
void			check_player(t_parser_map *parser_map, t_map *map,
					int x, int y);
t_errok			is_around_space_ok(t_map *map, int x, int y);

/* destroy_parser_map.c */

void			destroy_parser_map(t_parser_map *parser_map);
void			destroy_map(t_map *map);

#endif