#include "cub3d.h"

//ponemos la texture en map_info[NORTH_TEXTURE]

#define OK 0
#define ERROR 1

int	save_map_info(char *line_map_to_check, char **map_info)
{
	char **splitted;

	if (*map_info)
		return (ERROR);
	splitted = ft_split(line_map_to_check, ' ');
	if (ft_arraylen((const char **)splitted) != 2)
	{
		free_double_pointer(splitted);
		return (ERROR);
	}
	*map_info = ft_strdup(splitted[1]);
	free_double_pointer(splitted);
	return (OK);
}


int	line_checkeitor(char *line_map_to_check, t_map *map)
{
	if (ft_strncmp(line_map_to_check, "NO ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_north_texture));
	else if (ft_strncmp(line_map_to_check, "WE ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_west_texture));
	else if (ft_strncmp(line_map_to_check, "EA ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_east_texture));
	else if (ft_strncmp(line_map_to_check, "SO ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_south_texture));
	else if (ft_strncmp(line_map_to_check, "F ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_north_texture));
	else if (ft_strncmp(line_map_to_check, "C ", 3) == 0)
		return (save_map_info(line_map_to_check,&map->map_info_north_texture));
	else
		


}

void check_map(char *arg_map, t_map *map)
{
	char *line_map_to_check;
	int  fd;

	fd = open(arg_map, O_RDONLY);
	if (fd == -1)
	{
		perror(arg_map);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line_map_to_check = get_next_line(fd);
		if (line_map_to_check == NULL)
			break ;
		line_checkeitor(line_map_to_check, map);
		free(line_map_to_check);
	}
	printf("%s", map->map_info_north_texture);
	exit(0);
}