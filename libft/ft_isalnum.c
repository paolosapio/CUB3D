/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:45:39 by psapio            #+#    #+#             */
/*   Updated: 2025/02/27 21:05:08 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (((c >= 'a') && (c <= 'z'))
		|| ((c >= 'A') && (c <= 'Z'))
		|| ((c >= '0') && (c <= '9')));
}
/*
int	main(void)
{
	char	value;

	value = 'F';
	printf("%d\n", ft_isalnum(value));
}
devuelve 1 si es el caaracter o digito
*/