/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:19:54 by psapio            #+#    #+#             */
/*   Updated: 2025/10/03 18:05:49 by psapio           ###   ########.fr       */
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
	init_game(&game, &parser_map);
	await_user_input(&game);
	sayonara_baby(game.mlx, &game.images, &game.map);
}

	// game.map.player_pointer = &game.player; //!REVISAR QUE ERA ESTOOOOO
//! POR ARREGLAR: cuando le das a f y luego a tab y luego a esc sale cangro en el juego
/*
cc main.c MLX42/build/libmlx42.a -ldl -lglfw 

int	leak_main(void)
{
	mlx_t	*mlx = NULL;
	
	mlx = mlx_init(500, 500, "hola", false);
	mlx_close_window(mlx);
	mlx_terminate(mlx);
	return (0);
} */