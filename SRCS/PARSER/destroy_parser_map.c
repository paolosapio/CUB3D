/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_parser_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:02:18 by psapio            #+#    #+#             */
/*   Updated: 2025/10/18 21:49:45 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief After every image has been loaded, parser_map is destroyed.
*/
void	destroy_parser_map(t_parser_map *parser_map)
{
	free(parser_map->path_n);
	free(parser_map->path_e);
	free(parser_map->path_s);
	free(parser_map->path_w);
	free(parser_map->info_floor);
	free(parser_map->info_sky);
}
