/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:26:04 by psapio            #+#    #+#             */
/*   Updated: 2024/11/21 19:27:09 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	ii;
	size_t	longstr;
	char	*string3;

	i = 0;
	longstr = ft_strlen(s1) + ft_strlen(s2);
	string3 = malloc(longstr +1);
	if (string3 == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		string3[i] = s1[i];
		i++;
	}
	ii = 0;
	while (s2 && s2[ii] != '\0')
	{
		string3[i] = s2[ii];
		i++;
		ii++;
	}
	string3[i] = '\0';
	return (string3);
}
/*
int	main (void)
{
	char const	string1 [] = "viva ";
	char const	string2 [] = "la vida";

	printf("%s\n", ft_strjoin(string1, string2));
}*/
