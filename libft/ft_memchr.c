/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:05:30 by psapio            #+#    #+#             */
/*   Updated: 2025/02/27 21:23:18 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		character;
	const unsigned char	*sentence;

	character = c;
	sentence = s;
	i = 0;
	while (i < n)
	{
		if (sentence[i] == character)
			return ((void *)&sentence[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	words[] = "cacca";
	int		character;
	size_t	size;
	char	*result;

	character = ',';
	size = 30;
	result = ft_memchr(words, character, size);
	printf("%s\n", result);
}*/
