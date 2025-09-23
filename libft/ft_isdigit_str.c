/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42madrid.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:32:53 by psapio            #+#    #+#             */
/*   Updated: 2023/11/20 16:11:32 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

bool	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		++i;
	}
	return (true);
}