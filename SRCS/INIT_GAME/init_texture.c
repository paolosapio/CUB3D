#include "init_game.h"

void 	init_texture(mlx_t* mlx, t_images *images)
{
	mlx_texture_t	*mirilla;
	mlx_texture_t	*greco;
	mlx_texture_t	*map_sand;
	mlx_texture_t	*map_rock;

	mirilla = mlx_load_png("PNG/mirilla.png");
	greco = mlx_load_png("PNG/greco.png");
	map_sand = mlx_load_png("PNG/map_sand.png");
	map_rock = mlx_load_png("PNG/map_rock.png");

	

	images->mirilla = mlx_texture_to_image(mlx, mirilla);
	images->map_greco = mlx_texture_to_image(mlx, greco);
	images->map_sand = mlx_texture_to_image(mlx, map_sand);
	images->map_rock = mlx_texture_to_image(mlx, map_rock);
	
	mlx_delete_texture(mirilla);
	mlx_delete_texture(greco);
	mlx_delete_texture(map_sand);
	mlx_delete_texture(map_rock);
}
