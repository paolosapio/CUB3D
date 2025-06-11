/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:23:50 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/02/27 21:24:04 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nstrchr(const char *s, int c)
{
	int		i;
	char	character;

	character = (char)c;
	i = 0;
	if (character == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
