/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:04:17 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 22:18:17 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// open
# include "../../INC/t_map.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

# define LIMIT_FOV 1.5 //! TEMPORAL

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

/*
typedef struct s_parser_map
{
	int		line_that_start_map;  // parseo
	char*	arg_map_fd;         // parseo
	char*	path_n; // parseo + imagen
	char*	path_e;  // parseo + imagen
	char*	path_s; // parseo + imagen
	char*	path_w;  // parseo + imagen
	char*	info_floor;         // parseo + imagen
	char*	info_sky;           // parseo + imagen
}				t_parser_map;

*/

typedef struct s_parser_map
{
	int		line_that_start_map;
	char	*arg_map_fd;
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

//#define VALID_CHARS "10NSEW \n"
# define VALID_CHARS "10NEWS \n"

// parser.c
t_parser_map	parser(char *map_path, t_map *map);

// get_map_info.c

void			get_map_info(t_map map);

// check_meta_map.c

int				check_line(char *line_map_to_check, t_map *map,
					t_parser_map *parser_map, int fd);
void			allocate_map_size(char *line_map_to_check, t_map *map, int fd);

// check_map.c

void			check_map(char *path_map, t_parser_map *parser_map, t_map *map);
void			check_valid_map(t_parser_map *parser_map, t_map *map);

// check_line.c

t_errok			is_empty_line(char *line);
int				is_valid_line(char **map, int current);
t_errok			check_first_line_map(char *line_map_to_check);

// check_file.c

t_errok			check_file_extension(char *path_map);

// destroy_parser_map.c

void			destroy_parser_map(t_parser_map *parser_map);
void			destroy_map(t_map *map);

// map_encasketeitor.c

int				str_map_encasketeitor(t_parser_map *parser_map, t_map *map,
					int fd);
// check_map.c
void			error_exit_invalid_map(t_parser_map *parser_map, t_map *map,
					int error);

#endif