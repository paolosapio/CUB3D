#include "cub3d.h"


void	handle_hook(mlx_key_data_t keydata, void *params)
{
	t_game *game = params;
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);

	if (keydata.key == MLX_KEY_M)
	{

		game->images.minimap->enabled = !(game->images.minimap->enabled);
	}
	
}

void	init_mlx_connection(t_game *game)
{

	init_game_struct(game);
	draw_game(game);
//	mlx_loop_hook(game.mlx, &handle_hook, &game);
	mlx_key_hook(game->mlx, &handle_hook, &game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

/* t_map	open_map(const char *map_path)
{
	//TODO validate map_path extension;
	t_map	map;

	map = init_map();
	map.map_fd = open(map_path, O_RDONLY);
	if (map.map_fd == -1)
	{
		perror(map_path);
		exit(1);
	}
	while (map.map_line_buf)
	{
		map.map_line_buf = get_next_line(map.map_fd);
		if (!(map.map_line_buf))
		{
			//TODO separar mejor, meter en el map.map_array solo el mapa y no toda la información de este.
			map.map_array = ft_split(map.map_line, '\n');
			get_map_info(map);
			for (int i = 0; map.map_array[i]; i++)
				printf("%s\n", map.map_array[i]);
			free(map.map_line);
			return (map);
		}
		else
		{
			map.map_line = gnl_strnjoin(map.map_line, map.map_line_buf,
					ft_strlen(map.map_line) + ft_strlen(map.map_line_buf));
			free(map.map_line_buf);
			map.map_line_buf = "";
		}
	}
	//TODO map validation;
	return (map);
} */



int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		printf(RED"ERROR: Invalid arguments\n"STD"  → Usage: ./cub3D maps/map.cub\n\n");
		printf(PURPLE"You can find different maps inside the map folder\n"STD);
		exit(1);
	}
	check_map(argv[1], &game.map);
	init_mlx_connection(&game);
}
