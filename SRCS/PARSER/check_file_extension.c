/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/10/12 12:33:25 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief Checks that the map has the .cub extension.
 */
t_errok	check_file_extension(char *path_map)
{
	char	*last_slash;
	char	*last_dot;

	if (ft_strcmp(path_map, ".cub") == 0)
		return (ERROR);
	last_slash = ft_strrchr(path_map, '/');
	if (last_slash != NULL && (ft_strcmp(last_slash, "/.cub") == 0))
		return (ERROR);
	last_dot = ft_strrchr(path_map, '.');
	if (last_dot == NULL)
		return (ERROR);
	if (ft_strcmp(last_dot, ".cub") != 0)
		return (ERROR);
	return (OK);
}
