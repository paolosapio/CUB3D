/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:27:57 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/06/16 19:28:15 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*gnl_strdup(char *s1, int n)
{
	char	*s2;
	int		i;

	if (!s1 || n <= 0)
		return (NULL);
	s2 = ft_calloc((n + 1), sizeof(char));
	if (!s2)
		return (NULL);
	i = -1;
	while (++i < n && s1[i])
		s2[i] = s1[i];
	return (s2);
}