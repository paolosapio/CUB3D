#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{

	int		longest_line;
	int		map_len;


	char	**array;
	t_player	player[1];
}				t_map;

#endif