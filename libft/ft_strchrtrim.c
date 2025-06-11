/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:24:39 by ymunoz-m          #+#    #+#             */
/*   Updated: 2025/02/27 21:25:29 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * BEWARE: This function frees the original str you send it
 */
char	*ft_strchrtrim(char	*str, char c)
{
	char	*new_string;
	int		i;
	int		j;
	int		new_string_len;

	i = -1;
	new_string_len = 0;
	while (str[++i])
	{
		if (str[i] != c)
			new_string_len++;
	}
	new_string = ft_calloc(new_string_len + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			new_string[j++] = str[i++];
	}
	free(str);
	return (new_string);
}
