/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/08/11 20:19:38 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_errok	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(" \n", line[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

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
