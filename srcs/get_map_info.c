#include "cub3d.h"

#define NORTH_TEXTURE 0
#define EAST_TEXTURE 1
#define SOUTH_TEXTURE 2
#define WEST_TEXTURE 3
#define FLOOR 4
#define SKY 5






#define MAP_VALUES 6

/* int	add_map_value(char *line, char *path)
{
	char	**splitted_line;

	splitted_line = ft_split(line, ' ');
	if (ft_arraylen((const char**)splitted_line) > 2) //???????????? no sé si funciona.
	{
		path = ft_strdup(splitted_line[1]);
		free_double_pointer(splitted_line);
		return (-1);
	}
	path = ft_strdup(splitted_line[1]);
	free_double_pointer(splitted_line);
	return (1);
} */

/* int	find_map_values(t_map map, char *trimmed_line)
{
	static int values_changed = 0;

	if (!ft_strncmp("NO ", trimmed_line, 3))
		values_changed += add_map_value(trimmed_line, map.map_info[NORTH_TEXTURE]);
	else if (!ft_strncmp("SO ", trimmed_line, 3))
		values_changed += add_map_value(trimmed_line, map.map_info[SOUTH_TEXTURE]);
	else if (!ft_strncmp("WE ", trimmed_line, 3))
		values_changed += add_map_value(trimmed_line, map.map_info[WEST_TEXTURE]);
	else if (!ft_strncmp("EA ", trimmed_line, 3))
		values_changed += add_map_value(trimmed_line, map.map_info[EAST_TEXTURE]);
	else if (!ft_strncmp("F ", trimmed_line, 2))
		values_changed += add_map_value(trimmed_line, map.map_info[FLOOR]);
	else if (!ft_strncmp("C ", trimmed_line, 2))
		values_changed += add_map_value(trimmed_line, map.map_info[SKY]);
	else
	{
		printf("values_changed = %d\n", values_changed);
		if (values_changed == MAP_VALUES)
			printf("valid map\n"); //trim_map;
		else
			printf("Invalid map\n"); //free all, invalid map;
	}
	return (0);
}
 */
/* void	get_map_info(t_map map)
{
	int		i;
	char	**map_array;
	char	*trimmed_line;

	i = -1;
	map_array = map.map_array;
	for (int j = 0; map_array[j]; j++)
		printf("%s\n", map_array[j]);
	while (map_array[++i])
	{
		trimmed_line = ft_strtrim(map_array[i], " ");
		printf("trimmed_line: %s\n", trimmed_line);
		if (trimmed_line[0])
			continue;
		find_map_values(map, trimmed_line);
		free(trimmed_line);
	}
} */
