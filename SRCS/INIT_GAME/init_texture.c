#include "init_game.h"

void 	init_texture(mlx_t* mlx, t_images *images, t_parser_map *parser_map)
{
	mlx_texture_t	*mirilla;
	mlx_texture_t	*greco;
	mlx_texture_t	*map_sand;
	mlx_texture_t	*map_rock;

	mlx_texture_t	*wall_alga_N;
	mlx_texture_t	*wall_alga_S;
	mlx_texture_t	*wall_alga_E;
	mlx_texture_t	*wall_alga_W;

	mirilla = mlx_load_png("PNG/mirilla.png");
	greco = mlx_load_png("PNG/greco.png");
	map_sand = mlx_load_png("PNG/map_sand.png");
	map_rock = mlx_load_png("PNG/map_rock.png");

	wall_alga_N = mlx_load_png(parser_map->info_north_texture);
	wall_alga_S = mlx_load_png(parser_map->info_south_texture);
	wall_alga_E = mlx_load_png(parser_map->info_east_texture);
	wall_alga_W = mlx_load_png(parser_map->info_west_texture);

	mlx_set_icon(mlx, greco);
	//!TODO: Comprobar que las texturas se hayan cargado bien!!!!

	images->mirilla = mlx_texture_to_image(mlx, mirilla);
	images->map_greco = mlx_texture_to_image(mlx, greco);
	images->map_sand = mlx_texture_to_image(mlx, map_sand);
	images->map_rock = mlx_texture_to_image(mlx, map_rock);
	
	mlx_delete_texture(mirilla);
	mlx_delete_texture(greco);
	mlx_delete_texture(map_sand);
	mlx_delete_texture(map_rock);
	images->map_texture_N = wall_alga_N;
	images->map_texture_S = wall_alga_S;
	images->map_texture_E = wall_alga_E;
	images->map_texture_W = wall_alga_W;
}
