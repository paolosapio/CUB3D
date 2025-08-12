
#ifndef MAP_H
# define MAP_H

# include "player.h"

typedef struct	s_map
{
	int			longest_line;
	int			map_len;
	char		**array;
	t_player	*player_pointer;
}				t_map;

#endif