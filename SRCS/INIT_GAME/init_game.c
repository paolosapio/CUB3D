#include "init_game.h"

//TODO: Hacer que no se deforme la imagen con mapas muy largos o anchos.
//* Usar la misma relación que el mapa pero si es muy grande mostrar solo
//* la parte en la que se encuentre el usuario y que se adapte en base a su posición.
void	put_images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images.sky, 0, 0);
	mlx_image_to_window(game->mlx, game->images.floor, 0, HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->images.mirilla, WIDTH / 2 - 10, HEIGHT / 2 - 10);
	mlx_image_to_window(game->mlx, game->images.minimap, 0, 0);
	mlx_image_to_window(game->mlx, game->images.map_player, 0, 0);
}
//!tenemos qeu separar rao desde el personaje para poder texturizarlo en el minimapa!
void	init_images(mlx_t* mlx, t_map *map, t_images *images)
{
	mlx_texture_t	*mirilla;

	map->size_of_tile = 10;
	mirilla = mlx_load_png("PNG/mirilla.png");
	images->mirilla = mlx_texture_to_image(mlx, mirilla);
	images->map_greco = create_player_minimap(mlx, map);
	images->minimap = create_minimap(mlx, map);
	images->floor = create_floor(mlx, map);
	images->sky = create_sky(mlx, map);
	images->map_player = create_player_minimap(mlx, map);
	images->minimap->enabled = true;
	images->map_player->enabled = true;
	mlx_delete_texture(mirilla);

}

void	init_game(t_game *game, t_parser_map *parser_map)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", false);
	init_images(game->mlx, &game->map, &game->images);
	destroy_parser_map(parser_map);
	put_images_to_window(game);
}

