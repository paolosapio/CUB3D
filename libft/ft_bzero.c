/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:16:48 by psapio            #+#    #+#             */
/*   Updated: 2025/02/27 21:04:50 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	a;

	a = 0;
	while (n != 0)
	{
		((char *)s)[a] = '\0';
		n--;
		a++;
	}
}
/*
int main(void)
{
//	char array[20]="hola estrella";
	int array_int[7]= {-1,5,200,13,1,11,10};
	size_t numberof;
	int i;

	numberof = 5;
	ft_bzero(array, numberof);
	ft_bzero(array_int, 1);	
	i = 0;
	while (i < 7)
	{
		printf("[%d]\n", array_int[i]);
		i++;
	}
}
*/
