#include "parser.h"

void	destroy_parser_map(t_parser_map *parser_map)
{
	free(parser_map->info_north_texture);
	free(parser_map->info_east_texture);
	free(parser_map->info_south_texture);
	free(parser_map->info_west_texture);
	free(parser_map->info_floor);
	free(parser_map->info_sky);
}