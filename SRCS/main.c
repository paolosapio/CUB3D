/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:19:54 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 12:25:02 by psapio           ###   ########.fr       */
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
//! ARREGLLADOOOOOO:  LOS COLRES DEL MAPA IVAN EN OVERFLOW! ARREGLADOOOOO