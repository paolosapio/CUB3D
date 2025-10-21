/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/10/18 13:38:14 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief Checks if the line has only spaces and or \\n to stop further
 * comprobations.
 */
bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(SPACES, line[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief A very lovely function that checks that the characters inside the
 * first map line are only valid characters.
 */
t_errok	check_first_line_map(char *line_map_to_check)
{
	int	i;

	i = 0;
	while (line_map_to_check[i] != '\0' && line_map_to_check[i] != '\n')
	{
		if (line_map_to_check[i] != '1' && line_map_to_check[i] != ' ')
			return (ERROR);
		i++;
	}
	return (OK);
}
