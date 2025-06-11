/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:05:45 by psapio            #+#    #+#             */
/*   Updated: 2024/11/21 19:27:13 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*int main(void)
{
	int result;
	const char string[]="Paolo";
	result = ft_strlen(string);
	printf("%zu\n",ft_strlen(string));
	printf("%zu\n",ft_strlen("CASA ··"));
	printf("%zu\n",ft_strlen("0"));
	printf("%zu\n",ft_strlen(""));
	return (0);
}*/
