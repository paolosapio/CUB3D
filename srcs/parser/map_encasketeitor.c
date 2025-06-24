#include "cub3d.h"

void	reopen_map(char *map_path, int fd)
{
	close(fd);
	fd = open(map_path, O_RDONLY);
}

void	skip_lines(t_map *map, int fd)
{
	while (map->line_that_start_map-- > 0)
		free(get_next_line(fd));
}

int	line_len_meter(int size_line, int old_bigger_line)
{
	if (size_line > old_bigger_line)
		return (size_line);
	return (old_bigger_line);
}

int	str_map_encasketeitor(t_map *map, int fd)
{
	char	*line;
	int		map_line_index;

	map_line_index = 0;
	reopen_map(map->arg_map_fd, fd);
	skip_lines(map, fd);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->longest_line = line_len_meter(ft_strlen(line), map->longest_line);
		map->map_array[map_line_index] = line;
		map_line_index++;
	}
	map->map_len = map_line_index;
	if (map->longest_line >= map->map_len)
		map->tile_size = WIDTH/map->longest_line;
	else
		map->tile_size = HEIGHT/(map->map_len - 2);
	printf("tile_size = %d, y = %d, x = %d\n", map->tile_size, map->map_len, map->longest_line);
	printf("IMPRESION FINAL DEL MAPA\n\n");
	for (int i = 0; map->map_array[i]; i++)
		printf("%s", map->map_array[i]);
	return (OK);
}