#include "parser.h"

void	parser(char *map_path, t_map *map)
{
	t_parser_map	parser_map;
	
	if (check_file_extension(map_path) == ERROR)
	{
		printf("ERROR FILE NAME\n");
		return (2);
	}
	check_map(map_path, &parser_map, map);
}