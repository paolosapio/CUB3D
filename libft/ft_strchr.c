/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:09:41 by psapio            #+#    #+#             */
/*   Updated: 2025/07/30 14:57:11 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;

	character = (char)c;
	i = 0;
	if (character == '\0')
	{
		while (s[i] != '\0')
		{
			i++;
		}
		return ((char *)&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*string;
	int	charvalaue;

	string = "life is beautiful";
	charvalaue = '\0';
	printf("%p\n", ft_strchr(string, charvalaue));
	printf("%p\n", strchr(string, charvalaue));
}*/
