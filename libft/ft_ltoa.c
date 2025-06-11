/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:56:55 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/02/27 21:27:17 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long n)
{
	char		*array;
	int			counter;
	long int	n_twin;

	n_twin = (long int)n;
	counter = 0;
	if ((long int)n <= 0)
		counter++;
	while ((n_twin != 0) && counter++ >= 0)
		n_twin = n_twin / 10;
	array = ft_calloc(counter + 1, sizeof(char));
	if (array == NULL)
		return (NULL);
	n_twin = (long int)n;
	if ((long int)n < 0)
		(n_twin = (long int)n * -1);
	while (counter-- != 0)
	{
		array[counter] = n_twin % 10 + '0';
		n_twin = n_twin / 10;
	}
	if ((long int)n < 0)
		array[0] = '-';
	return (array);
}
