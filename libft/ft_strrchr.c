/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:01:53 by psapio            #+#    #+#             */
/*   Updated: 2025/02/27 21:26:06 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*
   int main(void)
   {
   const char *string="viva la vida Paolo";
   int alert_word;

   alert_word = 'P';
   printf ("%s\n", ft_strrchr(string, alert_word));
   printf ("%s\n", strrchr(string, alert_word));
}*/
