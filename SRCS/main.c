/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:19:54 by psapio            #+#    #+#             */
/*   Updated: 2025/10/21 23:53:32 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parser_map	parser_map;
	t_game			game;

	ft_memset(&game, 0, sizeof(t_game));
	game.map.player_pointer = &game.player;
	if (argc != 2)
	{
		ft_putendl_fd(USAGE, 2);
		return (1);
	}
	parser_map = parser(argv[1], &game.map);
	if (game.map.map_len > 240)
	{
		printf("\n\nSAYONARA BABYYYY 🐠🐡🌊\n");
		destroy_map(&game.map);
		exit(1);
	}
	load_game(&game, &parser_map);
	await_user_input(&game);
	sayonara_baby(game.mlx, &game.images, &game.map);
	return (0);
}

// cc main.c MLX42/build/libmlx42.a -ldl -lglfw 

// int	main(void)
// {
// 	mlx_t	*mlx = NULL;

// 	mlx_set_setting(MLX_FULLSCREEN, true);
// 	mlx = mlx_init(500,500, "hola", false);
// 	mlx_close_window(mlx);
// 	mlx_terminate(mlx);
// 	//exit(3);
// }

// mas mapas
// https://github.com/angiebm4/42-cub3d/tree/main/tests/maps