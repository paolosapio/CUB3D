#include "cub3d.h"


void	handle_hook(void *params)
{
	mlx_t *mlx = params;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}
	
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}
}



void	init_mlx_connection(t_map map)
{
	mlx_t*	mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "ALGO-ALGA", true);

	draw_sky(mlx, map);
	draw_floor(mlx, map);
	draw_map(mlx, map);
	mlx_loop_hook(mlx, &handle_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_double_pointer(map.map);
}

t_map	init_map()
{
	t_map	map;

	map.map_fd = 0;
	map.map_line = NULL;
	map.map_line_buf = "";
	return (map);
}

t_map	open_map(const char *map_path)
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
			//TODO separar mejor, meter en el map.map solo el mapa y no toda la información de este.
			map.map = ft_split(map.map_line, '\n');
			for (int i = 0; map.map[i]; i++)
				printf("%s\n", map.map[i]);
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
}



int	main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
	{
		printf(RED"ERROR: Invalid arguments\n"STD"  → Usage: ./cub3D maps/map.cub\n\n");
		printf(PURPLE"You can find different maps inside the map folder\n"STD);
		exit(1);
	}
	map = open_map(argv[1]);
	init_mlx_connection(map);
}