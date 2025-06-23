/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:39:47 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/06/23 22:04:56 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_empty_line(char *line)
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


int	is_valid_line(char **map, int current)
{
	int	prev;
	int	i;

	prev = current - 1;
	i = 0;
	while (map[current][i])
	{
		printf("%c", map[current][i]);
		if (!ft_strchr(VALID_CHARS, map[current][i]))
		{
			printf("FOUND INVALID CHAR IN LINE %d\n", current);
			return (ERROR);
		}
		if (map[current][i] == '0') //añadir las posiciones iniciales del personaje.
		{
			if ((map[current - 1][i] && ft_strchr("\n ",map[current - 1][i])) ||
				(map[current][i + 1] && ft_strchr("\n ",map[current][i + 1])))
				return (ERROR);
		}
		i++;
	}
	return (OK);
}

int	one_to_one_line_checkeitor(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
			break ;
	}

	if (line[i] && line[i] == '1')
	{
		while (line[i])
			i++;
		if (line[i - 1] == '1')
			return (OK);
		else
			return (ERROR);
	}
	return (ERROR);
}