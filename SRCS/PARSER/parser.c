/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:03:39 by psapio            #+#    #+#             */
/*   Updated: 2025/10/12 12:32:23 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief 
 * 
 * @param map_path The path to the .cub file.
 * @param map The empty map struct.
 * @return t_parser_map A struct containing information only needed before the
 * mlx hooks and the game itself are started.
 */
t_parser_map	parser(char *map_path, t_map *map)
{
	t_parser_map	parser_map;

	ft_memset(&parser_map, 0, sizeof(t_parser_map));
	if (check_file_extension(map_path) == ERROR)
	{
		(void)write(2, "ERROR FILE NAME\n", 16);
		exit(1);
	}
	check_map(map_path, &parser_map, map);
	return (parser_map);
}
