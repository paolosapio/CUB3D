/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:03:39 by psapio            #+#    #+#             */
/*   Updated: 2025/10/07 13:25:04 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
