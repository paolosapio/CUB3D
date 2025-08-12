#include "parser.h"

t_parser_map	parser(char *map_path, t_map *map)
{
	t_parser_map	parser_map;
	ft_memset(&parser_map, 0, sizeof(t_parser_map));

	if (check_file_extension(map_path) == ERROR)
	{
		printf("ERROR FILE NAME\n");
		exit(1);
	}
	check_map(map_path, &parser_map, map);
	return (parser_map);
}