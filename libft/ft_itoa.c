/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:14 by psapio            #+#    #+#             */
/*   Updated: 2025/02/27 22:01:36 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_itoa(int n)
// {
// 	char		*array;
// 	size_t		counter;
// 	long int	n_twin;

// 	n_twin = (long int)n;
// 	counter = 0;
// 	if ((long int)n <= 0)
// 		counter++;
// 	while ((n_twin != 0) && (counter++ >= 0))
// 		n_twin = n_twin / 10;
// 	array = ft_calloc(counter + 1, sizeof(char));
// 	if (array == NULL)
// 		return (NULL);
// 	n_twin = (long int)n;
// 	if ((long int)n < 0)
// 		(n_twin = (long int)n * -1);
// 	while (counter-- != 0)
// 	{
// 		array[counter] = n_twin % 10 + '0';
// 		n_twin = n_twin / 10;
// 	}
// 	if ((long int)n < 0)
// 		array[0] = '-';
// 	return (array);
// }

char	*write_chars(int n, int len, char *str)
{
	int	n2;

	n2 = n;
	if (n2 == -2147483648)
		n--;
	while (len > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	if (n2 == -2147483648)
		str[10] = '8';
	return (str);
}

char	check_sign(int n)
{
	if (n < 0)
		return ('-');
	return ('+');
}

size_t	get_len(int n)
{
	unsigned int	len;

	len = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;
	char			sign;

	len = get_len(n);
	sign = check_sign(n);
	if (sign == '-' && len != 0)
		str = ft_calloc((len + 2), sizeof(char));
	else if (sign == '+' && len != 0)
		str = ft_calloc((len + 1), sizeof(char));
	else
		return (ft_strdup(""));
	if (str != NULL)
	{
		if (sign == '-')
		{
			str = write_chars(n * -1, len + 1, str);
			str[0] = '-';
		}
		else
			str = write_chars(n, len, str);
		return (str);
	}
	return (0);
}
