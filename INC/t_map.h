#ifndef T_MAP_H
# define T_MAP_H

# include "t_player.h"

typedef struct	s_map
{
	int			longest_line;
	int			map_len;
	char		**array;
	t_player	*player_pointer;
	t_coor		draw_offset;
	int			tile_size;
}				t_map;

#endif